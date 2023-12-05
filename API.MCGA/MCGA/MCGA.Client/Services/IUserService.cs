using MCGA.Client.Shared;
using MCGA.Shared.DTOs;
using MCGA.Shared.Models;

namespace MCGA.Client.Services
{
    public interface IUserService
    {
        UserDTO User {get; }
        Task Initialize();
        Task<bool> Login(UserLoginRequestDTO model);
        Task<bool> Register(UserRegistrationRequestDTO model);
        Task Logout();
    }
}