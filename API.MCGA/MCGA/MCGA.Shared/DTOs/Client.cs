using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace MCGA.Shared
{
    public class Client
    {
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public DateTime BirthDate { get; set; }
        [Required(ErrorMessage = "El teléfono es obligatorio.")]
        [RegularExpression("^[0-9]*$", ErrorMessage = "Solo se permiten números en el teléfono.")]
        public string Phone { get; set; }

        public string Address { get; set; }
    }
}
