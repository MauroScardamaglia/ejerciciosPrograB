/*
5. Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
  int * vecPunt[MAX];
  int i=0,n;
  FILE * arch;
  arch = fopen("enteros.txt","rt");
  if (arch==NULL)
    printf("No se pudo abrir el archivo \n");
  else{
    while (!feof(arch)){
      vecPunt[i]=malloc(sizeof(int)); // le da una direccion de memoria dinamica al componente del vector de punteros
      printf("La direccion de memoria de vecPunt[%d] es %p \n",i,vecPunt[i]);
      fscanf(arch,"%d",vecPunt[i]); // luego en esa direccion lee del archivo de texto un entero
      i++;
    }
    fclose(arch);
    n=i;
    // muestro valores positivos
    for (i=0;i<n;i++)
      if (*vecPunt[i]>0)
        printf("[%d]= %d \n",i,*vecPunt[i]);
    // libero la memoria dinamica
    for (i=0;i<n;i++)
      free(vecPunt[i]);
  }
}
