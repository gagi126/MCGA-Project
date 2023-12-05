
#  Proyecto Final - MODELOS COMPUTACIONALES DE GESTIÓN ADMINISTRATIVA
¡Bienvenido al repositorio del Proyecto Final para la materia MODELOS COMPUTACIONALES DE GESTIÓN ADMINISTRATIVA! En este proyecto, he desarrollado un sistema completo con un frontend y un backend, ambos alojados en Azure y utilizando una base de datos SQLite. A continuación, se detalla la estructura del proyecto y las tecnologías utilizadas.

Proyecto Frontend
El frontend está desarrollado utilizando Blazor WebAssembly, aprovechando la potencia de .NET 7.0.

Tecnologías Utilizadas:
Blazor WebAssembly: Framework para la construcción de aplicaciones web interactivas en el navegador.
.NET 7.0: Plataforma de desarrollo para la creación de aplicaciones multiplataforma.
Funcionalidades
Visualización de Datos Públicos:

Ruta pública que muestra datos provenientes del backend.
Autenticación y Autorización:

Ruta pública de login con validaciones de usuario y contraseña.
Ruta privada accesible solo con inicio de sesión.
CRUD y Base de Datos:

Ruta privada con operaciones CRUD en datos almacenados en la base de datos.
Cambios en el CRUD afectan directamente los datos mostrados en la pantalla pública.
Seguridad:

Endpoints privados solo accesibles con un token válido.
Logout:

Funcionalidad para cerrar sesión con redirección al inicio.
Proyecto Backend
El backend se ha desarrollado utilizando ASP.NET Core 7.0, con una base de datos SQLite.

Tecnologías Utilizadas:
ASP.NET Core 7.0: Framework para la construcción de aplicaciones web y servicios.
SQLite: Base de datos relacional ligera y autónoma.
Funcionalidades
API RESTful:

Implementación de una API REST para la comunicación con el frontend.
Seguridad:

Autenticación mediante tokens para endpoints privados.
Base de Datos en la Nube:

Utilización de SQLite como base de datos, con el archivo almacenado en la nube.
Cloud Hosting
Ambos proyectos están alojados en Azure para garantizar su accesibilidad.

Frontend Hosting: Azure. [Enlace al FrontEnd](https://mcga-project.azurewebsites.net/)
Backend Hosting: Azure. [Enlace al BackEnd](https://mcga-api.azurewebsites.net/)
