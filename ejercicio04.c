#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *tipos[]={"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct producto
{
    int productoId;
    int cantidad;
    char **tipoProducto;
    float precio
} typedef  producto;

struct cliente
{
    int clienteId;
    char *nombreCliente;
    int cantidadPedida; //cantidad de productos (hasta 10)
    producto *productos; // puntero porque depende de la cantidad de productos a cargar
} typedef cliente;;

void cargarCliente(cliente *cliente, int cantidad);
void cargarProductos(producto *prod, int contadorProductos);
void mostrarTodo(cliente *clte, int cantCliente);
float calcularCostoProducto(producto *prod);
int main(){
    srand(time(NULL));
    int cantidadClientes;
    cliente *estrucCliente;
    do{
    printf("ingrese la cantidad de clientes a cargar 1/5\n");
    scanf("%d", &cantidadClientes);
    }while(cantidadClientes>5);
    estrucCliente= (cliente*)malloc(sizeof(estrucCliente)*cantidadClientes);
    cargarCliente(estrucCliente, cantidadClientes);
    mostrarTodo(estrucCliente, cantidadClientes);
    
    return 0;
}
void cargarCliente(cliente *cliente, int cantidad){
    char aux[100];
    int  longitud;
    for (int i = 0; i < cantidad; i++)
    { 
        printf("--------------cliente: %d-----------\n", i+1);
        cliente[i].clienteId=i+1;
        printf("ingrese nombre de cliente\n");
        fflush(stdin);
        gets(aux);
        longitud=strlen(aux)+1;
        cliente[i].nombreCliente= (char*)malloc(sizeof(char)*longitud); //no uso operador flecha porque esta el [i]
        strcpy(cliente[i].nombreCliente, aux);
        cliente[i].cantidadPedida=(rand()%5)+1; 
        cliente[i].productos=(producto*)malloc(sizeof(producto)*cliente[i].cantidadPedida);//creo el arreglo de estructura segun la cantidad de prodctos
        cargarProductos(cliente[i].productos, cliente[i].cantidadPedida); //envio la estructura y tambien envio la cantidad de productos a cargar
    }
    
}

void cargarProductos(producto *prod, int contadorProductos)
{
    int aux;
    
    for (int i = 0; i < contadorProductos; i++)
    {
        prod[i].productoId= i+1;
        do
        {
            printf("ingrese cantidad: \n");
            scanf("%d",&prod[i].cantidad);
        } while (prod[i].cantidad>10);
        do
        {
            printf("ingrese tipo producto 1:galletas, 2:snak, 3:cigarros, 4:caramelos, 5:bebidas\n");
            scanf("%d",&aux);
            prod[i].tipoProducto=&tipos[aux-1]; //como tipos es un arreglo de punteros a arreglo de cadenas puedo usar esta notacion ya que el puntero doble apunta a otro puntero, en este caso estoy haciendo que este puntero doble apunte al otro puntero(*tipos[])
        } while (aux>5);
        printf("ingrese precio\n");
        scanf("%f",&prod[i].precio);
        

    }
}
void mostrarTodo(cliente *clte, int cantCliente){
    float aux;
    for (int i = 0; i < cantCliente; i++)
    {   printf("----------------CLIENTE %d-------------------------\n",i+1);
        printf("\n");
        printf("cliente id: %d\n", clte[i].clienteId);
        printf("nombre cliente: %s\n", clte[i].nombreCliente);
        printf("cantidad de prodctos aleatorios: %d\n", clte[i].cantidadPedida);
        for (int j = 0; j < clte[i].cantidadPedida; j++)
        {
            
            printf("- - - - - - - producto n°: %d - - - - - - - - - \n", j+1);
            printf("producto id: %d\n", clte[i].productos[j].productoId);
            printf("cantidad: %d\n", clte[i].productos[j].cantidad);
            printf("tipo: %s\n", *(clte[i].productos[j].tipoProducto)); // i y j ya me dan la direccion de memoria con * accedo al dato, es necesario el * por ser puntero doble, si fuera puntero simple no haria falta el *. si fuera un scanf tambien usaria *(clte[i].prodcutos[j].tipoProducto). Siempre que sea puntero doble a arreglo debo usar *(variable) para printf o scanf. si es puntero doble a un tipo comun (ej char): prinft usa **variable y scanf usa (*variable)
            printf("precio: %.2f \n", clte[i].productos[j].precio);
            aux=calcularCostoProducto(&(clte[i].productos[j])); //como la funcion trabaja con un puntero tengo que enviar la direccion de memoria sin el & estaria enviando el dato
            printf("producto: %s cantidad: %d precio total: %.2f\n",*(clte[i].productos[j].tipoProducto),clte[i].productos[j].cantidad, aux);
        }   
    }
}

float calcularCostoProducto(producto *prod)
{
    float aux;
    aux= prod->precio * prod->cantidad;
    return aux;
}
