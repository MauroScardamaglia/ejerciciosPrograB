/*
4. Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  unsigned int n; // me dijo el profe Marco que es mejor que las variables sean claras (si necesitan ser largas que lo sean)
  float * punt; // no usar variables con nombres solo con mayusculas
  printf("Ingrese cantidad de floats a ingresar (numeros reales) \n");
  scanf("%u",&n);
  punt=(float *)malloc(sizeof(float)*n); // en este caso no asigno la funcion malloc en la declaracion porque necesito el valor de n primero, y es mejor declarar todo al principio
  // lectura del vector
  for (i=0;i<n;i++)
    scanf("%f",punt+i); // i suma NO la cantidad de bytes, sino la cantidad de bytes multiplicado por el tipo de puntero
  // mostrar aquellos positivos
  for (i=0;i<n;i++)
    if (*(punt+i)>0)
      printf("[%u]= %6.2f \n",i,*(punt+i));
  // libero la memoria dinámica
  free(punt);

  return 0;
}
