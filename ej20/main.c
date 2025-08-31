#include <stdio.h>
#include <stdlib.h>
#define N 32 // longint (el int por defecto según este compilador) usa 4 bytes, osea que con 32 componentes está sobrado

// 20. Realizar un programa iterativo que calcule e imprima el equivalente binario de un número
// entero positivo dado.

int main()
{
  unsigned short int vec[N]; // n elementos del vector, vec 0 y 1
  short int n=-1;
  unsigned int x,aux;
    printf("Ingrese numero no negativo \n");
    scanf("%u",&x);
    aux=x;
    while (aux!=0){
      // n++;
      vec[++n]=aux%2;  // vec[++n]=aux%2;
      aux/=2;
    }
    printf("El equivalente binario de %u es \n",x);
    for (;n>=0;n--)
      printf("%u",vec[n]);
    if (x==0)
      printf("0");
    printf("\n");

    return 0;
}
