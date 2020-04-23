#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int ProductoID;
    int Cantidad;
    char * TipoProducto;
    float PrecioUnitario;
}Producto;

typedef struct {
    int ClienteID;
    char * NombreCliente;
    int CantidadProductosAPedir;
    Producto * Productos; 
}Cliente;

char * TiposProductos [] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebibas"};

//Prototipo de Funciones

float costoProducto(Producto productos);
void mostrar(Cliente ** clientela, int cantidadClientes);
Producto cargarProducto ();

int main () 
{
    srand(time(NULL));
    int cantClientes;
    char nombre[20];
    int cantProducto;
    float costoParcial;
    printf("Digite la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    Cliente * puntCliente = (Cliente *)malloc(sizeof(Cliente)*cantClientes);

    for (int i=0; i<cantClientes; i++) {

        //Datos del Cliente
        puntCliente[i].ClienteID = i;
        printf("Nombre Cliente: ");
        scanf("%s", &nombre);
        fflush(stdin);
        int tamaNombre = strlen(nombre);
        puntCliente[i].NombreCliente = (char *)malloc(sizeof(tamaNombre));
        strcpy(puntCliente[i].NombreCliente, nombre);
        puntCliente[i].CantidadProductosAPedir = 1 + rand()%5;

        //Datos del Producto
        puntCliente[i].Productos = (Producto *)malloc(sizeof(Producto)*puntCliente[i].CantidadProductosAPedir);
        for(int j=0; j<puntCliente[i].CantidadProductosAPedir;j++) {
            (puntCliente[i].Productos)[j] = cargarProducto();
            costoParcial = costoProducto(((puntCliente[i].Productos)[j]));
        }
    }
    mostrar(&puntCliente, cantClientes);
    getchar();
    return 0;
}

//Calcula el costo de cada producto
float costoProducto(Producto productos) {
    float Total= 0;
     return Total = (productos.PrecioUnitario * productos.Cantidad);
}

void mostrar(Cliente ** clientela, int cantidadClientes) {
    Cliente * cliente = * clientela;
    float costoParcial;
    float suma;
    for(int i=0; i<cantidadClientes;i++) {
        printf("\nID Cliente: %d\n", cliente[i].ClienteID);
        printf("Nombre del Cliente: %s\n", cliente[i].NombreCliente);
        printf("Cantidad de Productos a Pedir: %d\n\n", cliente[i].CantidadProductosAPedir);
            for(int j=0; j<cliente[i].CantidadProductosAPedir;j++) {
                printf("ID Producto: %d\n", (cliente[i].Productos)[j].ProductoID);
                printf("Cantidad a Pedir: %d\n", (cliente[i].Productos)[j].Cantidad);
                printf("Tipo Producto: %s\n", (cliente[i].Productos)[j].TipoProducto);
                printf("Precio Unitario: %.2f\n", (cliente[i].Productos)[j].PrecioUnitario);
                costoParcial = costoProducto(((cliente[i].Productos)[j]));
                printf("Costo del Producto: %.2f\n\n", costoParcial);
                suma = suma + ((cliente[i].Productos)[j].PrecioUnitario * (cliente[i].Productos)[j].Cantidad);
            }
    }
    printf("Total a Pagar: %.2f", suma);
}

Producto cargarProducto () {
    
    Producto nuevoProducto;
    nuevoProducto.ProductoID = rand()%5;
    nuevoProducto.Cantidad = 1 + rand()%9;
    int cantCaractProd = strlen(TiposProductos[nuevoProducto.ProductoID]);
    nuevoProducto.TipoProducto = (char *)malloc(sizeof(char)*cantCaractProd);
    strcpy(nuevoProducto.TipoProducto, TiposProductos[nuevoProducto.ProductoID]);
    nuevoProducto.PrecioUnitario = 1+rand()%99;

    return nuevoProducto;
}