using FluentValidation;

namespace MCGA.Shared.Models
{
    public class ClientValidator : AbstractValidator<MCGA.Shared.Client>
    {
        public ClientValidator()
        {
            CascadeMode = CascadeMode.Stop;

            RuleFor(client => client.FirstName).NotEmpty().WithMessage("Campo Nombre es un campo requerido.")
                .Length(3, 50).WithMessage("El campo Nombre debe tener entre 3 y 50 caracteres");
            RuleFor(client => client.LastName).NotEmpty().WithMessage("Campo Apellido es un campo requerido.")
                .Length(3, 50).WithMessage("El campo Apellido debe tener entre 3 y 50 caracteres");
            RuleFor(client => client.Phone).NotEmpty().WithMessage("Campo Telefono es un campo requerido.")
                .Length(5, 50).WithMessage("El campo Telefono debe tener entre 3 y 50 caracteres");
            RuleFor(client => client.Address).NotEmpty().WithMessage("Campo Direccion es un campo requerido.")
                .Length(3, 50).WithMessage("El campo Direccion debe tener entre 3 y 50 caracteres");
            RuleFor(client => client.BirthDate).NotEmpty().WithMessage("Campo Fecha de nacimiento es un campo requerido.");
            
        }
    }
}