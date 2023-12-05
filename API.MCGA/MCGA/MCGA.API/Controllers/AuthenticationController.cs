using MCGA.API.Configuration;
using MCGA.Shared.DTOs;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Options;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Http.Features;
using Microsoft.AspNetCore.Identity.UI.Services;
using Microsoft.AspNetCore.WebUtilities;
using Microsoft.EntityFrameworkCore;
using Microsoft.IdentityModel.Tokens;
using System;
using System.IdentityModel.Tokens.Jwt;
using System.Runtime.CompilerServices;
using System.Security.Claims;
using System.Text;
using System.Text.Encodings.Web;
using Microsoft.AspNetCore.Mvc.ModelBinding;
using Microsoft.AspNetCore.Http;
using System;
using MCGA.Shared.Auth;
using MCGA.Data;
using MCGA.Shared;
using MCGA.Shared.Common;
using System.Net.Mail;

namespace MCGA.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class AuthenticationController : ControllerBase
    {
        private readonly UserManager<IdentityUser> _userManager;
        private readonly JwtConfig _jwtConfig;
        private readonly IEmailSender _emailSender;
        private readonly APIMCGAContext _context;
        private readonly TokenValidationParameters _tokenValidationParameters;
        private readonly ILogger<AuthenticationController> _logger;
        public AuthenticationController(UserManager<IdentityUser> userManager, IOptions<JwtConfig> jwtConfig, IEmailSender emailSender, APIMCGAContext context, TokenValidationParameters tokenValidationParameters , ILogger<AuthenticationController> logger)
        {
            _userManager = userManager;
            _jwtConfig = jwtConfig.Value;
            _emailSender = emailSender;
            _context = context;
            _tokenValidationParameters = tokenValidationParameters;
            _logger = logger;
        }

        [HttpPost("Register")]
        public async Task<IActionResult> Register([FromBody] UserRegistrationRequestDTO request)
        {
            try
            {
                _logger.LogInformation("A user is trying to register with email: {Email}", request.Email);

                if (!ModelState.IsValid)
                {
                    _logger.LogWarning("Invalid model state during registration. Request: {@Request}", request);
                    return BadRequest();
                }

                // Verificar si el correo electrónico ya existe
                var emailExists = await _userManager.FindByEmailAsync(request.Email);

                if (emailExists != null)
                {
                    _logger.LogWarning("Registration failed. Email already exists: {Email}", request.Email);
                    return BadRequest(new AuthResult
                    {
                        Result = false,
                        Errors = new List<string> { "Email already exists" }
                    });
                }

                // Crear usuario
                var user = new IdentityUser
                {
                    Email = request.Email,
                    UserName = request.Email,
                    EmailConfirmed = false
                };

                var isCreated = await _userManager.CreateAsync(user, request.Password);

                if (isCreated.Succeeded)
                {
                    await SendVerificationMail(user);

                    _logger.LogInformation("User registration successful for email: {Email}", request.Email);
                    return Ok(new AuthResult { Result = true });
                }
                else
                {
                    var errors = new List<string>();
                    foreach (var err in isCreated.Errors)
                    {
                        errors.Add(err.Description);
                        _logger.LogError("User registration error: {ErrorDescription}", err.Description);
                    }

                    _logger.LogWarning("Registration failed for email: {Email}. Errors: {@Errors}", request.Email, errors);

                    return BadRequest(new AuthResult
                    {
                        Result = false,
                        Errors = errors
                    });
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during user registration.");
                return BadRequest(new AuthResult
                {
                    Result = false,
                    Errors = new List<string> { "An unexpected error occurred" }
                });
            }
        }

        [HttpPost("RefreshToken")]
        public async Task<IActionResult> RefreshToken([FromBody] TokenRequestDTO tokenRequest)
        {
            try
            {
                _logger.LogInformation("Refreshing token for user");

                if (!ModelState.IsValid)
                {
                    _logger.LogWarning("Invalid parameters during token refresh. Request: {@Request}", tokenRequest);

                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "Invalid parameters" },
                        Result = false
                    });
                }

                var result = await VerifyAndGenerateToken(tokenRequest);

                if (result == null)
                {
                    _logger.LogWarning("Token refresh failed. Invalid token for user ");

                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "Invalid token" },
                        Result = false
                    });
                }

                _logger.LogInformation("Token refresh successful for user");

                return Ok(result);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during token refresh.");
                return BadRequest(new AuthResult
                {
                    Result = false,
                    Errors = new List<string> { "An unexpected error occurred" }
                });
            }
        }

        [HttpGet("ConfirmEmail")]
        public async Task<IActionResult> ConfirmEmail(string userId, string code)
        {
            try
            {
                _logger.LogInformation("Attempting to confirm email for user with ID: {UserId}", userId);

                if (string.IsNullOrWhiteSpace(userId) || string.IsNullOrWhiteSpace(code))
                {
                    _logger.LogWarning("Invalid email confirmation URL. User ID: {UserId}", userId);

                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "Invalid email confirmation URL" },
                        Result = false
                    });
                }

                var user = await _userManager.FindByIdAsync(userId);

                if (user == null)
                {
                    _logger.LogWarning("Unable to load user with ID: {UserId}", userId);

                    return NotFound($"Unable to load user with ID '{_userManager.GetUserId(User)}'.");
                }

                code = Encoding.UTF8.GetString(WebEncoders.Base64UrlDecode(code));

                var result = await _userManager.ConfirmEmailAsync(user, code);

                var status = result.Succeeded ? "Thank you for confirming your email." : "Error confirming your email.";

                _logger.LogInformation("Email confirmation status for user with ID {UserId}: {Status}", userId, status);

                return Ok(status);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during email confirmation.");
                return BadRequest(new AuthResult
                {
                    Result = false,
                    Errors = new List<string> { "An unexpected error occurred" }
                });
            }
        }


        private async Task<AuthResult> GenerateTokenAsync(IdentityUser user)
        {
            try
            {
                _logger.LogInformation("Generating tokens for user with ID: {UserId}", user.Id);

                var jwtTokenHandler = new JwtSecurityTokenHandler();
                var key = Encoding.UTF8.GetBytes(_jwtConfig.Secret);

                var claims = new[]
                {
            new Claim("Id", user.Id),
            new Claim(JwtRegisteredClaimNames.Sub, user.Email),
            new Claim(JwtRegisteredClaimNames.Email, user.Email),
            new Claim(JwtRegisteredClaimNames.Jti, Guid.NewGuid().ToString()),
            new Claim(JwtRegisteredClaimNames.Iat, DateTime.Now.ToUniversalTime().ToString())
        };

                var tokenDescriptor = new SecurityTokenDescriptor
                {
                    Subject = new ClaimsIdentity(claims),
                    Expires = DateTime.UtcNow.Add(_jwtConfig.ExpiryTime),
                    SigningCredentials = new SigningCredentials(new SymmetricSecurityKey(key), SecurityAlgorithms.HmacSha256)
                };

                var token = jwtTokenHandler.CreateToken(tokenDescriptor);

                var jwtToken = jwtTokenHandler.WriteToken(token);

                var refreshToken = new RefreshToken
                {
                    Id = token.Id,
                    JwtId = token.Id,
                    Token = RandomGenerator.GenerateRandomString(23),
                    AddedDate = DateTime.UtcNow,
                    ExpiryDate = DateTime.UtcNow.AddMonths(6),
                    IsRevoked = false,
                    IsUsed = false,
                    UserId = user.Id
                };

                await _context.RefreshTokens.AddAsync(refreshToken);
                await _context.SaveChangesAsync();

                _logger.LogInformation("Tokens generated successfully for user with ID: {UserId}", user.Id);

                return new AuthResult
                {
                    Token = jwtToken,
                    RefreshToken = refreshToken.Token,
                    Result = true
                };
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during token generation for user with ID: {UserId}", user.Id);
                throw; // Re-lanzar la excepción para que el llamador pueda manejarla según sea necesario.
            }
        }

        private async Task SendVerificationMail(IdentityUser user)
        {
            try
            {
                _logger.LogInformation("Sending email verification mail to user with ID: {UserId}, Email: {UserEmail}", user.Id, user.Email);

                var verificationCode = await _userManager.GenerateEmailConfirmationTokenAsync(user);
                verificationCode = WebEncoders.Base64UrlEncode(Encoding.UTF8.GetBytes(verificationCode));

                var callbackUrl = $@"{Request.Scheme}://{Request.Host}{Url.Action("ConfirmEmail", controller: "Authentication",
                                    new { userId = user.Id, code = verificationCode })}";
                _logger.LogWarning("Email link generated:" + callbackUrl);
                var emailBody = $@"Please confirm your account by <a href='{HtmlEncoder.Default.Encode(callbackUrl)}'>clicking here</a>.";

                var sendEmailTask = _emailSender.SendEmailAsync(user.Email, "Confirm your email", emailBody);

                // Configurar un tiempo de espera de 30 segundos
                var timeoutTask = Task.Delay(TimeSpan.FromSeconds(30));

                // Usar Task.WhenAny para esperar la finalización de cualquiera de las tareas (envío de correo o tiempo de espera)
                var completedTask = await Task.WhenAny(sendEmailTask, timeoutTask);

                if (completedTask == timeoutTask)
                {
                    // El tiempo de espera ha expirado
                    _logger.LogError("Email verification mail sending timed out for user with ID: {UserId}, Email: {UserEmail}", user.Id, user.Email);
                    // Puedes manejar el tiempo de espera excedido según sea necesario
                }
                else
                {
                    // El envío de correo electrónico se completó antes del tiempo de espera
                    _logger.LogInformation("Email verification mail sent successfully to user with ID: {UserId}, Email: {UserEmail}", user.Id, user.Email);
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred while sending email verification mail to user with ID: {UserId}, Email: {UserEmail}", user.Id, user.Email);
                throw; // Re-lanzar la excepción para que el llamador pueda manejarla según sea necesario.
            }
        }


        private async Task<AuthResult> VerifyAndGenerateToken(TokenRequestDTO tokenRequest)
        {
            try
            {
                _logger.LogInformation("Verifying and generating token for user with Token: {Token}, RefreshToken: {RefreshToken}", tokenRequest.Token, tokenRequest.RefreshToken);

                var jwtTokenHandler = new JwtSecurityTokenHandler();
                _tokenValidationParameters.ValidateLifetime = false;

                var tokenInVerification = jwtTokenHandler.ValidateToken(tokenRequest.Token, _tokenValidationParameters, out var validatedToken);

                if (validatedToken is JwtSecurityToken jwtSecurityToken)
                {
                    var result = jwtSecurityToken.Header.Alg.Equals(SecurityAlgorithms.HmacSha256, StringComparison.InvariantCultureIgnoreCase);

                    if (!result || tokenInVerification == null)
                    {
                        _logger.LogError("Invalid Token");
                        throw new Exception("Invalid Token");
                    }
                }

                var utcExpiryDate = long.Parse(tokenInVerification.Claims.FirstOrDefault(x => x.Type == JwtRegisteredClaimNames.Exp).Value);
                var expiryDate = DateTimeOffset.FromUnixTimeSeconds(utcExpiryDate);

                if (expiryDate < DateTime.UtcNow)
                {
                    _logger.LogError("Token Expired");
                    throw new Exception("Token Expired");
                }

                var storedRefreshToken = await _context.RefreshTokens.FirstOrDefaultAsync(x => x.Token == tokenRequest.RefreshToken);

                if (storedRefreshToken == null)
                {
                    _logger.LogError("Invalid Token");
                    throw new Exception("Invalid Token");
                }

                if (storedRefreshToken.IsUsed || storedRefreshToken.IsRevoked)
                {
                    _logger.LogError("Token has expired, user needs to relogin");
                    throw new Exception("Token has expired, user needs to relogin");
                }

                var jti = tokenInVerification.Claims.FirstOrDefault(x => x.Type == JwtRegisteredClaimNames.Jti).Value;

                if (jti != storedRefreshToken.JwtId)
                {
                    _logger.LogError("Invalid Token");
                    throw new Exception("Invalid Token");
                }

                storedRefreshToken.IsUsed = true;
                _context.RefreshTokens.Update(storedRefreshToken);
                await _context.SaveChangesAsync();

                var dbUser = await _userManager.FindByIdAsync(storedRefreshToken.UserId);
                var authResult = await GenerateTokenAsync(dbUser);

                _logger.LogInformation("Token verification and generation successful for user with Token: {Token}, RefreshToken: {RefreshToken}", tokenRequest.Token, tokenRequest.RefreshToken);

                return authResult;
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during token verification and generation");
                var message = ex.Message == "Invalid Token" || ex.Message == "Token Expired" ? ex.Message : "Internal server error";

                return new AuthResult()
                {
                    Errors = new List<string> { message },
                    Result = false
                };
            }
        }


        [HttpPost("Login")]
        public async Task<IActionResult> Login([FromBody] UserLoginRequestDTO request)
        {
            try
            {
                _logger.LogInformation("User attempting to log in with email: {Email}", request.Email);

                if (!ModelState.IsValid)
                {
                    _logger.LogWarning("Invalid model state during login attempt. Request: {@Request}", request);
                    return BadRequest();
                }

                // Verificar si el usuario existe
                var existingUser = await _userManager.FindByEmailAsync(request.Email);

                if (existingUser == null)
                {
                    _logger.LogWarning("Login failed. User with email {Email} not found", request.Email);
                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "Invalid Payload" },
                        Result = false
                    });
                }

                if (!existingUser.EmailConfirmed)
                {
                    _logger.LogWarning("Login failed. Email for user with ID {UserId} needs to be confirmed.", existingUser.Id);
                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "El correo electronico debe ser confirmado" },
                        Result = false
                    });
                }

                var checkUserAndPass = await _userManager.CheckPasswordAsync(existingUser, request.Password);

                if (!checkUserAndPass)
                {
                    _logger.LogWarning("Login failed. Invalid credentials for user with email: {Email}", request.Email);
                    return BadRequest(new AuthResult
                    {
                        Errors = new List<string> { "Credenciales invalidas" },
                        Result = false
                    });
                }

                var token = await GenerateTokenAsync(existingUser);

                _logger.LogInformation("User successfully logged in with email: {Email}", request.Email);

                return Ok(token);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "An unexpected error occurred during user login.");
                return BadRequest(new AuthResult
                {
                    Result = false,
                    Errors = new List<string> { "An unexpected error occurred" }
                });
            }
        }

    }

}
