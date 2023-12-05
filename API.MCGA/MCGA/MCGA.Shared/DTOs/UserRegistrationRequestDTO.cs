using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MCGA.Shared.DTOs
{
    public class UserRegistrationRequestDTO
    {
        [Required]
        public string Name { get; set; }
        [Required]
        [EmailAddress(ErrorMessage = "Por favor, proporciona una dirección de correo electrónico válida.")]
        public string Email { get; set; }
        [Required]
        public string Password { get; set; }
    }
}
