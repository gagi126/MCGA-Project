using MCGA.Client.Shared;
using MCGA.Shared.Auth;
using MCGA.Shared.DTOs;
using MCGA.Shared.Models;
using Microsoft.AspNetCore.Components;
using Newtonsoft.Json;
using System.Net.Http;
using System.Security.Claims;
using System.Text;

namespace MCGA.Client.Services
{
    public class UserService: IUserService
    {
        private ILocalStorageService _localStorageService;
        private NavigationManager _navigationManager;
        private readonly IHttpClientFactory _httpClientFactory;
        private readonly IAlertService _alertService;
        private string _userKey = "user";

        public UserDTO User {get; private set;}

        public UserService( ILocalStorageService localStorageService, NavigationManager navigationManager, IHttpClientFactory httpClientFactory , IAlertService alertService)
        {
            _localStorageService = localStorageService;
            _navigationManager = navigationManager;
            _httpClientFactory = httpClientFactory;
            _alertService = alertService;
        }

        public async Task Initialize()
        {
            User = await _localStorageService.GetItem<UserDTO>(_userKey);
        }

        public async Task<bool> Login(UserLoginRequestDTO model)
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient("WebApi");
                var json = JsonConvert.SerializeObject(model);
                var content = new StringContent(json, Encoding.UTF8, "application/json");
                var response = await httpClient.PostAsync("/api/Authentication/Login", content);

                if (response.IsSuccessStatusCode)
                {
                    var responseData = await response.Content.ReadAsStringAsync();
                    var result = JsonConvert.DeserializeObject<UserDTO>(responseData);
                    User = result;
                    var claims = new[]
                    {
                        new Claim(ClaimTypes.Hash, User.Token),
                        new Claim("Id", User.Id.ToString()),
                        new Claim("Token", User.Token)
                    };
                    var claimsIdentity = new ClaimsIdentity(claims, "serverAuth");
                    var claimsPrincipal = new ClaimsPrincipal(claimsIdentity);
                    await _localStorageService.SetItem(_userKey, User);

                    return true; // Indicador de login exitoso
                }
                else
                {
                    var errorResponse = await response.Content.ReadAsStringAsync();
                    var authResult = JsonConvert.DeserializeObject<AuthResult>(errorResponse);

                    if (authResult.Errors != null && authResult.Errors.Any())
                    {
                        foreach (var error in authResult.Errors)
                        {
                            // Mostrar mensajes de error usando AlertService 
                            _alertService.Error(error);
                        }
                    }

                    return false; // Indicador de fallo en el login
                }
            }
            catch (Exception ex)
            {
                // Manejar excepciones
                _alertService.Error(ex.Message);
                throw;
            }
        }

        public async Task<bool> Register(UserRegistrationRequestDTO model)
        {
            try
            {
                var httpClient = _httpClientFactory.CreateClient("WebApi");
                var json = JsonConvert.SerializeObject(model);
                var content = new StringContent(json, Encoding.UTF8, "application/json");
                var response = await httpClient.PostAsync("/api/Authentication/Register", content);

                if (response.IsSuccessStatusCode)
                {
                    return true; // Indicador de registro exitoso
                }
                else
                {
                    var errorResponse = await response.Content.ReadAsStringAsync();
                    var authResult = JsonConvert.DeserializeObject<AuthResult>(errorResponse);

                    if (authResult.Errors != null && authResult.Errors.Any())
                    {
                        foreach (var error in authResult.Errors)
                        {
                            // Mostrar mensajes de error usando AlertService 
                            _alertService.Error(error);
                        }
                    }

                    return false; // Indicador de fallo en el login
                }
            }
            catch (Exception ex)
            {
                // Manejar excepciones
                _alertService.Error(ex.Message);
                throw;
            }
        }

        public async Task Logout()
        {
            User = null;
            await _localStorageService.RemoveItem(_userKey);
            _navigationManager.NavigateTo("/user/login");
        }

    }
}