#include <stdio.h>
#include <stdlib.h>
#include <string.h>
   //               CON PUNTERO SIMPLE (USANDO UN ARREGLO DE PUNTEROS)
//const int cantidad= 5;
const int max=15; // valor estimativo de espacio de memoria del nombre

int main(){
   // char *buff[5]; //declarado como arreglo de puntero porque en este caso conozco la cantidad
    //char *nombre[5];
    int longitud, cantidad;
    printf("ingrese la cantidad de nombres\n");
    scanf("%d", &cantidad);
    char *buff[cantidad];   // aca creo el arreglo de punteros segun la cantidad ingresada. por ej: 2
    char *nombre[cantidad];
    for (int i = 0; i < cantidad; i++)
    {
        buff[i]= (char*) malloc(sizeof(char)*max); // creo cada espacio espacio de memoria para cada uno de los punteros del arreglo de punteros. ej: la cantidad es 2, asi que 1 tendra un espacio de 15 y 2 tendra un espacio de 15
        printf("ingrese nombre\n");
        scanf("%s", buff[i]);
        longitud=strlen(buff[i]) + 1; //obtengo la longitud le sumo 1 para añadir el "\0"
        nombre[i]=(char*) malloc(sizeof(char)*longitud); // creo el espacio de memoria con la cantidad exacta de memoria
        strcpy(nombre[i],buff[i]); 
    }
    for (int j = 0; j < cantidad; j++)
    {
        printf("nombre %d: %s\n", j+1, nombre[j]);
    }
    
    
    return 0;
}
//  ----------------CON PUNTERO DOBLE--------------------------------
/*
const int max=100;
int main(){
    char **buff;
    char **nombre;
    int longitud=0, filas;
    printf("ingrese la cantidad de nombres que desea ingresar\n");
    scanf("%d", &filas);

    buff=(char**)malloc(sizeof(char)*filas); // creamos el espacio de memoria para cada puntero simple, cada 1 de esos 5(las filas) sera un puntero simple, uso buff para luego poder asignar correctamente
    nombre=(char**)malloc(sizeof(char)*filas);
    for (int i = 0; i < filas; i++)
    {
        buff[i]=(char*)malloc(sizeof(char)*max); // a cada puntero simple, le asigna un espacio de memoria donde almacenaremos los datos
        printf("ingrese nombre:\n");
        fflush(stdin);
        gets(buff[i]); 
        //scanf("%s", buff[i]);
        longitud=strlen(buff[i])+1;
        nombre[i]=(char*)malloc(sizeof(char)*longitud);
        strcpy(nombre[i],buff[i]);
    }
    printf("LOS NOMBRES INGRESADOS SON:\n");
    for (int i = 0; i < filas; i++)
    {
        printf("%s\n", nombre[i]);
    }
    //liberamos la memoria
    for (int i = 0; i < filas; i++)
    {
        free(buff[i]);  // liberamos la memoria de cada fila creada (liberamos las columnas, el malloc dentro del for)
        free(nombre[i]);
    }
    free(buff);  // liberamos la memoria de las filas en general (liberamos las filas, el mallor fuera del for)
    free(nombre);
    return 0;
}
*/