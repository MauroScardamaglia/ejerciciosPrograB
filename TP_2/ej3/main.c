/*
3. Implementar un programa que cree dinámicamente 3 variables enteras (pint1, pint2 y pint3),
muestre su suma y su producto. No utilizar estructuras iterativas. Asegurarse de administrar
correctamente la memoria e implementar una función para evitar duplicaciones de código en la
creación y lectura de cada variable. Desarrollar en primera instancia una función que retorne
un puntero a entero. Para cumplir con el paradigma de programación estructurada, convertir
en una función void que retorne el resultado como parámetro de salida.
*/

#include <stdio.h>
#include <stdlib.h>

void creaPunteroDinamico(int ** puntDoble);
int main()
{
  int * punt1, * punt2, * punt3;
  creaPunteroDinamico(&punt1);
  creaPunteroDinamico(&punt2);
  creaPunteroDinamico(&punt3);
  printf("La suma de los 3 numeros es %d \n",*punt1 + *punt2 + *punt3);
  printf("El producto de los 3 numeros es %d \n",*punt1 * *punt2 * *punt3); // funciona los astericos juntos (multiplicacion y contenido)

  return 0;
}

void creaPunteroDinamico(int ** puntDoble){
  * puntDoble = (int *) malloc(sizeof(int)) ; // "el contenido" (a lo que apunta) punt doble se le asigna el espacio de memoria dinamica
  printf("Ingrese numero entero \n");
  scanf("%d",*puntDoble); // cuando se usa un puntero normal no se usa el ampersand porque se da la dirección de memoria de la variable a leer
}                         // que es el contenido del puntero, pero acá el puntero es doble, entonces el contenido de este es la dirección de memoria
                          // del puntero original y a su vez la dirección de memoria de la variable a leer (el entero)
