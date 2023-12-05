using MCGA.Client.Shared;
using MCGA.Shared;
using MCGA.Shared.Commands;
using MCGA.Shared.Models;
using Microsoft.AspNetCore.Components;
using Newtonsoft.Json;
using System.Net.Http.Headers;
using System.Net.Http.Json;
using System.Text;
using System.Text.Json;

namespace MCGA.Client.Services
{
    public class ClientService: IClientService
    {
        private readonly HttpClient _httpClient;
        private readonly ILocalStorageService _localStorageService;

        public ClientService(HttpClient httpClient, ILocalStorageService localStorageService)
        {
            _httpClient = httpClient;
            _localStorageService = localStorageService;
        }

        public async Task<IEnumerable<MCGA.Shared.Client>> GetClients()
        {
            try
            {
                UserDTO user = await _localStorageService.GetItem<UserDTO>("user");
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", user.Token);
                var clients = await _httpClient.GetFromJsonAsync<List<MCGA.Shared.Client>>("api/Clients");

                if (clients != null)
                {
                    return clients;
                }
                else
                {
                    Console.WriteLine("La respuesta no contiene contenido JSON válido.");
                    return null;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error al obtener clientes: {ex.Message}");
                return null;
            }
        }

        public async Task<MCGA.Shared.Client> GetClientDetails(int id)
        {
            try
            {
                UserDTO user = await _localStorageService.GetItem<UserDTO>("user");
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", user.Token);
                var clients = await _httpClient.GetFromJsonAsync<MCGA.Shared.Client>($"api/Clients/{id}");

                if (clients != null)
                {
                    return clients;
                }
                else
                {
                    Console.WriteLine("La respuesta no contiene contenido JSON válido.");
                    return null;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error al obtener clientes: {ex.Message}");
                return null;
            }
        }

        public async Task DeleteClient(int clientId)
        {
            try
            {
                UserDTO user = await _localStorageService.GetItem<UserDTO>("user");
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", user.Token);

                var response = await _httpClient.DeleteAsync($"api/Clients/{clientId}");

                response.EnsureSuccessStatusCode();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error al eliminar cliente: {ex.Message}");
            }
        }

        public async Task CreateClient(MCGA.Shared.Client client)
        {
            try
            {
                UserDTO user = await _localStorageService.GetItem<UserDTO>("user");
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", user.Token);

            var createClientCommand = new CreateClientCommand
            {
                    FirstName = client.FirstName,
                    LastName = client.LastName,
                    BirthDate = client.BirthDate,
                    Phone = client.Phone,
                    Address = client.Address
                };
                var response = await _httpClient.PostAsJsonAsync("api/Clients", createClientCommand);

                response.EnsureSuccessStatusCode();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error al crear cliente: {ex.Message}");
            }
        }
        public async Task UpdateClient(MCGA.Shared.Client client)
        {
            try
            {
                UserDTO user = await _localStorageService.GetItem<UserDTO>("user");
                _httpClient.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", user.Token);
                var clients = await _httpClient.PutAsJsonAsync<MCGA.Shared.Client>($"api/Clients", client);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error al actualizar cliente: {ex.Message}");
            }
        }

       
    }
}