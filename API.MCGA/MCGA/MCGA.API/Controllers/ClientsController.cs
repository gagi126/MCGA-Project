using MCGA.Data;
using MCGA.Shared;
using MCGA.Shared.Commands;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace MCGA.API.Controllers
{
    [Authorize]
    [Route("api/[controller]")]
    [ApiController]
    public class ClientsController : ControllerBase
    {
        private readonly APIMCGAContext _context;
        private readonly ILogger<ClientsController> _logger;
        public ClientsController (APIMCGAContext context, ILogger<ClientsController> logger )
        {
            _context = context;
            _logger = logger;
        }
        [HttpGet]
        public async Task<IEnumerable<Client>> Get()
        {
            _logger.LogWarning("Fetching all clients");
            return await _context.Clients.ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<IActionResult> GetDetailsById(int id)
        {
            _logger.LogWarning("Fetching client details by ID: {ClientId}", id);
            var client = await _context.Clients.FirstOrDefaultAsync(c => c.Id == id);

            if (client == null)
            {
                _logger.LogWarning("Client with ID {ClientId} not found", id);
                return NotFound();
            }

            return Ok(client);
        }

        [HttpPost]
        public async Task<IActionResult> Post(CreateClientCommand createClientCommand)
        {
            try
            {
                if (createClientCommand == null)
                {
                    _logger.LogWarning("The CreateClientCommand object is null");
                    return BadRequest("The received object is null");
                }

                var client = new Client
                {
                    FirstName = createClientCommand.FirstName,
                    LastName = createClientCommand.LastName,
                    BirthDate = createClientCommand.BirthDate,
                    Phone = createClientCommand.Phone,
                    Address = createClientCommand.Address
                };

                await _context.Clients.AddAsync(client);
                await _context.SaveChangesAsync();

                _logger.LogWarning("Client created successfully. ID: {ClientId}", client.Id);

                return CreatedAtAction(nameof(GetDetailsById), new { id = client.Id }, client);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error in the controller while creating a client");
                return StatusCode(500, "Error interno en el servidor intentando crear el cliente");
            }
        }

        [HttpPut]
        public async Task<IActionResult> Put(Client client)
        {
            _logger.LogWarning("Updating client with ID: {ClientId}", client.Id);
            _context.Clients.Update(client);
            await _context.SaveChangesAsync();
            return NoContent();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            _logger.LogWarning("Deleting client with ID: {ClientId}", id);
            var client = await _context.Clients.FindAsync(id);

            if (client == null)
            {
                _logger.LogWarning("Client with ID {ClientId} not found", id);
                return NotFound();
            }

            _context.Clients.Remove(client);
            await _context.SaveChangesAsync();
            return NoContent();
        }

    }
}
