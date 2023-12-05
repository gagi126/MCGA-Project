using MCGA.Shared.Models;

namespace MCGA.Client.Services
{
    public interface IClientService
    {
        Task<IEnumerable<MCGA.Shared.Client>> GetClients();
        Task<MCGA.Shared.Client> GetClientDetails(int id);
        Task UpdateClient(MCGA.Shared.Client client);
        Task CreateClient(MCGA.Shared.Client client);
        Task DeleteClient(int clientId);
    }
}