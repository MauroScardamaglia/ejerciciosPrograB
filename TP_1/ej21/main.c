#include <stdio.h>
#include <stdlib.h>
#define MAX 30
/*
21. Desarrollar un programa que lea un vector y, mediante opciones de un menú, calcule e imprima)
lo siguiente:
a) los elementos en posiciones impares 1,3,5 o sea segundo, cuarto, sexto...
b) genere otro vector con los elementos divisibles por k (k dato). Muestre el nuevo vector con
otra función
c) busca la posición de un valor x (puede no existir)
*/
typedef int TVec[MAX];

void cargaVec(TVec vec,short int n);
void muestraVec(TVec vec,short int n);

void recorrerImpar(TVec vec,short int n); // a)
void generarVecK(TVec vec,short int n,TVec vecK,short int *cantVecK,int k); // b)
short int posValorX(TVec vec,short int n,int x); // c)

int main()
{
    TVec vec,vecK;
    int k,x;
    short int pos,n,cantVecK;
    char opcion;

    printf("Ingrese cantidad de elementos del vector \n");
    scanf("%d",&n);
    cargaVec(vec,n);
    printf("\n");
    muestraVec(vec,n);
    printf("\n");

    printf("Que operacion desea realizar? \n a-> imprimir elementos en posiciones impares \n b-> generar otro vector divisible por k \n c-> buscar la posicion de un valor x \n");
    scanf(" %c",&opcion);
    switch (opcion){
    case 'a': recorrerImpar(vec,n);
      break;
    case 'b': printf("Ingrese valor k (<>0) \n");
      scanf("%d",&k);
      generarVecK(vec,n,vecK,&cantVecK,k);
      muestraVec(vecK,cantVecK);
      break;
    case 'c': printf("Ingrese valor x \n");
      scanf("%d",&x);
      pos=posValorX(vec,n,x);
      if (pos==-1)
        printf("El valor x no figura en el vector\n");
      else
        printf("El valor %d se encuentra en la posicion %d",x,pos);
      break;
    }
    return 0;
}

void cargaVec(TVec vec,short int n){
  int i;
  for (i=0;i<n;i++)
    scanf("%d",&vec[i]);
}

void muestraVec(TVec vec,short int n){
  int i;
  for (i=0;i<n;i++)
    printf("%d \t",vec[i]);
  printf("\n");
}

void recorrerImpar(TVec vec,short int n){ // a
  int i;
  for (i=1;i<n;i+=2)
    printf("%d \t",vec[i]);
  printf("\n");
}

void generarVecK(TVec vec,short int n,TVec vecK,short int *cantVecK,int k){ // b)
  int i;
  *cantVecK=0;
  for(i=0;i<n;i++){
    if ((vec[i])%k==0){
      vecK[*cantVecK]=vec[i];
      (*cantVecK)++; // habia puesto *cantVecK++ y como el * tiene precedencia al ++ sumaba valor al puntero, no a su contenido; me re rompía el código; *cantVecK pasaba a valer n (calculo que son punteros contiguos
    }
  }
}

short int posValorX(TVec vec,short int n,int x){ // c)
  int i=0;
  while (vec[i]!=x && i<n)
    i++;
  if (i>=n)
    return -1;
  else
    return i;
}
