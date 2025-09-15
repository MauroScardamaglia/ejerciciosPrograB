#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"

/*
1. Realizar un TDA para números fraccionarios, es decir aquellos que se expresan como el
cociente de dos números enteros. Las operaciones que deberá soportar el TDA son:
- crear(entero numerador, entero denominador) retorna fracción.
- numerador(fracción f) retorna entero.
- denominador(fracción f) retorna entero.
- sumar(fracción f1, fracción f2) retorna fracción.
- restar(fracción f1, fracción f2) retorna fracción.
- multiplicar(fracción f1, fracción f2) retorna fracción.
- dividir(fracción f1, fracción f2) retorna fracción.
- simplificar(fracción f) retorna fracción simplificada.
- iguales(fracción f1, fracción f2) retorna verdadero o falso.
*/

int main()
{
  TFracc fraccion1,fraccion2,fraccion3;
  int num,den;

  printf("Ingrese numerador y denominador distinto de 0 \n");
  scanf("%d %d",&num,&den);
  fraccion1=crear(num,den);

  printf("Ingrese numerador y denominador distinto de 0 \n");
  scanf("%d %d",&num,&den);
  fraccion2=crear(num,den);

  mostrar(fraccion1);
  mostrar(fraccion2);

  printf("El numerador de fraccion1 es %d \n",numerador(fraccion1));
  printf("El denominador de fraccion2 es %d \n",denominador(fraccion2));

  fraccion3=sumar(fraccion1,fraccion2);
  printf("la suma es ");
  mostrar(fraccion3);
  fraccion3=simplificar(fraccion3);

  printf("La resta es ");
  mostrar(simplificar(restar(fraccion1,fraccion2))); // esto es una banda jajaja

  printf("La multiplicacion es ");
  mostrar(simplificar(multiplicar(fraccion1,fraccion2)));

  if (denominador(fraccion2)==0)
    printf("Division por cero \n");
  else{
    printf("La division es ");
    mostrar(simplificar(dividir(fraccion1,fraccion2)));
  }

  if (iguales(fraccion1,fraccion2))
    printf("Fracciones equivalentes \n");
  else
    printf("Fracciones no equivalentes \n");


  return 0;
}
