using MCGA.Client.Services;
using MCGA.Client.Shared;
using Microsoft.AspNetCore.Components.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Hosting;
using MCGA.Client;

var builder = WebAssemblyHostBuilder.CreateDefault(args);
builder.RootComponents.Add<App>("#app");
builder.RootComponents.Add<HeadOutlet>("head::after");
builder.Services.AddScoped<IAlertService, AlertService>();
builder.Services.AddScoped<IUserService, UserService>();
builder.Services.AddScoped<IClientService, ClientService>();
builder.Services.AddScoped<ILocalStorageService, LocalStorageService>();
builder.Services.AddHttpClient("WebApi", client =>
{
    client.BaseAddress = new Uri("https://mcga-api.azurewebsites.net");
});
builder.Services.AddScoped(x => {
    var apiUrl = new Uri("https://mcga-api.azurewebsites.net");
    return new HttpClient() {BaseAddress = apiUrl};
});
builder.Services.AddSingleton<PageHistoryState>();
//builder.Services.AddScoped(sp => new HttpClient { BaseAddress = new Uri(builder.HostEnvironment.BaseAddress) });
await builder.Build().RunAsync();
