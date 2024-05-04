#include<stdio.h>
#include <stdlib.h>
#include <time.h> // para que no se repitan los valores
#define FILA 5
#define COL 12

void promedio (int matri[FILA][COL]);
void maximoMinimo(int matri[FILA][COL]);
int main(){
srand(time(NULL));
int matriz[FILA][COL], prom;

for (int i = 0; i < FILA; i++)
{
    for (int j = 0; j < COL; j++)
    {
    
       matriz[i][j]= 10000 + rand() % 40001;
    }
    
}
for (int i = 0; i < FILA; i++)
{
    for (int j = 0; j < COL; j++)
    {
        printf(" %d", matriz[i][j]);
    }
    printf("\n");   
}
    promedio(matriz);
    maximoMinimo(matriz);
    return 0;
}

void promedio(int matri[FILA][COL]){
    int suma=0, promedio=0;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            suma+=matri[i][j];
        }
        promedio=suma/12;
        printf("la suma total del año %d es: %d y el promedio es: %d\n", i+1, suma, promedio);
    }
    
}
void maximoMinimo(int matri[FILA][COL]){
    int min=0, max=0, mesMin, anioMin, mesMax, anioMax;
    for (int i = 0; i < FILA; i++)
    {
        for (int j = 0; j < COL; j++)
        {   
            if(matri[i][j]>=max){
                max=matri[i][j];
                mesMax=j+1;
                anioMax=i+1;
                min=max; //para que en el siguiente if busque un valor que este en la matriz
            }
            if (matri[i][j]<=min){
                min=matri[i][j];
                mesMin=j+1;
                anioMin=i+1;
            }
            
        }
        
    }
    printf("el valor maximo es: %d se dio en el anio: %d mes: %d\n", max, anioMax, mesMax);
    printf("el valor minimo es: %d se dio en el anio: %d mes: %d\n", min, anioMin, mesMin);
}
