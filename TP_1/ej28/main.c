#include <stdio.h>
#include <stdlib.h>

/*
28. Rehacer el ejercicio 12 suponiendo que los n�meros se encuentran en un archivo de texto,
    todos en la misma l�nea. �Como modificar�a la lectura, si hubiera un valor por l�nea?
    |
    |
    --> 12. Desarrollar un programa que muestre la suma de un conjunto de n�meros naturales ingresados
            por teclado. La serie finaliza al ingresar el n�mero 0.
*/

int main() // �Como modificar�a la lectura, si hubiera un valor por l�nea?
{          // RE: No modifica nada (en este caso, con enteros)
  FILE * arch;  // hay diferencia si se agrega un " " despu�s del �ltimo valor, al hacer esto este se agrega devuelta (ej ult valor 4 suma=670-->674
  int num,acum=0;
  arch=fopen("numeros.txt","rt");
  if (arch==NULL)
    printf("No existe el archivo");
  else{
    while(!feof(arch)){  // en archivos de texto no se lee adelantado; solo para binarios
      fscanf(arch,"%d",&num);
      acum+=num;
    }
  fclose(arch);
  }
  printf("La suma de los numeros naturales dados es %d \n",acum);
  return 0;
}
