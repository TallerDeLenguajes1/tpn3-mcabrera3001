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

float costoTotal(Producto ** productos);
void mostrar(Cliente ** clientela, int cantidadClientes);
Producto * cargarProducto ();

int main () 
{
    srand(time(NULL));
    int cantClientes;
    char nombre[20];
    int cantProducto;
    int precioTotal = 0;
    printf("Digite la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    Cliente * puntCliente = (Cliente *)malloc(sizeof(Cliente)*cantClientes);

    printf("%p\n", puntCliente);

    for (int i=0; i<cantClientes; i++) {   
        
        puntCliente[i].ClienteID = i;
        printf("Nombre Cliente: ");
        scanf("%s", &nombre);
        fflush(stdin);
        int tamaNombre = strlen(nombre);
        puntCliente[i].NombreCliente = (char *)malloc(sizeof(tamaNombre));
        strcpy(puntCliente[i].NombreCliente, nombre);

        puntCliente[i].CantidadProductosAPedir = 1 + rand()%5;

        for(int j=0; j<puntCliente[i].CantidadProductosAPedir;j++) {
            puntCliente[i].Productos[j] = cargarProducto();
    
        }
        

            /*for(int j=0; j<puntCliente[i].CantidadProductosAPedir; j++) {
                Productos[j].ProductoID = rand()%5;
                Productos[j].Cantidad = 1 + rand()%10;
                int cantCaractProd = strlen(TiposProductos[Productos[j].ProductoID]);
                Productos[j].TipoProducto = (char *)malloc(sizeof(char)*cantCaractProd);
                strcpy(Productos[i].TipoProducto, TiposProductos[Productos[j].ProductoID]);
                Productos[j].PrecioUnitario = 10 + rand()%90;
            }*/
    }
    mostrar(&puntCliente, cantClientes);
    
    getchar();
    return 0;
}


float costoTotal(Producto ** productos) {
    float Total= 0;
    Producto * prod = *productos;
     return Total = (prod->Cantidad*prod->PrecioUnitario);
}

void mostrar(Cliente ** clientela, int cantidadClientes) {
    Cliente * cliente = * clientela;
    for(int i=0; i<cantidadClientes;i++) {
        srand(time(NULL));
        printf("\nID Cliente: %d\n", cliente[i].ClienteID);
        printf("Nombre del Cliente: %s\n", cliente[i].NombreCliente);
        printf("Cantidad de Productos a Pedir: %d\n\n", cliente[i].CantidadProductosAPedir);
            for(int j=0; j<cliente[i].CantidadProductosAPedir;j++) {
                printf("ID Producto: %d\n", cliente->Productos->ProductoID);
                  
            }
    }

}

Producto * cargarProducto () {
    Producto * nuevoProducto = (Producto *)malloc(sizeof(Producto));
    nuevoProducto->ProductoID = rand()%5;
    nuevoProducto->Cantidad = 1 + rand()%9;
    int cantCaractProd = strlen(TiposProductos[nuevoProducto->ProductoID]);
    nuevoProducto->TipoProducto = (char *)malloc(sizeof(char)*cantCaractProd);
    strcpy(nuevoProducto->TipoProducto, TiposProductos[nuevoProducto->ProductoID]);
    nuevoProducto->PrecioUnitario = 10 + rand()%90;

    return nuevoProducto;
}