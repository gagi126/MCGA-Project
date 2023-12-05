using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace MCGA.Shared.DTOs
{
    public class TokenRequestDTO
    {
        [Required]
        [JsonIgnore] // Excluir esta propiedad de la serialización JSON
        public string Token { get; set; }

        [Required]
        [JsonIgnore] // Excluir esta propiedad de la serialización JSON
        public string RefreshToken { get; set; }
    }
}
