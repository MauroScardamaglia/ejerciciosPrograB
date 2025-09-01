#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define ENTER printf("\n");
/*
24. Desarrollar un programa que lea una matriz de enteros de NxM y:
a) busque la posición de un valor x (puede no existir)
b) muestre el promedio de cada columna de la matriz.
c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el promedio de la matriz
*/
typedef int TMat[MAX][MAX];

void cargaMatriz(TMat mat,int n,int m);
void muestraMatriz(TMat mat,int n,int m);
void posValorX(TMat mat,int n,int m,int *posI,int *posJ,int x); // a)
void promColMatriz(TMat mat,int n,int m); // b)
void elementosFilaPromedio(TMat mat,int n,int m); // c)

int main()
{
  TMat mat;
  int n,m,posI,posJ,x;

  printf("Ingrese n y m \n");
  scanf("%d %d",&n,&m);
  cargaMatriz(mat,n,m);
  ENTER
  muestraMatriz(mat,n,m);
  ENTER

  printf("a) \n");
  printf("Ingrese valor x \n");
  scanf("%d",&x);
  posValorX(mat,n,m,&posI,&posJ,x);
  if (posI==-1)
    printf("El valor x no se encuentra en la matriz \n");
  else
    printf("el valor x se encuentra en la posicion [%d,%d] \n",posI,posJ);
  ENTER

  printf("b) \n");
  promColMatriz(mat,n,m);
  ENTER

  printf("c) \n");
  elementosFilaPromedio(mat,n,m);

  ENTER
  return 0;
}

void cargaMatriz(TMat mat,int n,int m){
  int i=0,j=0;
  while (i<n){
    while (j<m){
      printf("[%d,%d]=",i,j);
      scanf("%d",&mat[i][j]);
      j++;
    }
    i++;
    j=0;
  }
  ENTER
}

void muestraMatriz(TMat mat,int n,int m){
  int i=0,j=0;
  while (i<n){
    while (j<m){
      printf("%d \t",mat[i][j]);
      j++;
    }
    ENTER
    i++;
    j=0;
  }
  ENTER
}

void posValorX(TMat mat,int n,int m,int *posI,int *posJ,int x){ // a)
  int i=0,j=0;
  while (mat[i][j]!=x && i<n)
    if (j==m-1){
      i++;
      j=0;
    }
    else
      j++;
  if (i==n){
    *posI=-1;
    *posJ=-1;
  }
  else{
    *posI=i;
    *posJ=j;
  }
  ENTER
}

void promColMatriz(TMat mat,int n,int m){ // b)  muestre el promedio de cada columna de la matriz.
  int i,j,acum;
  for (j=0;j<m;j++){
    acum=0;
    for(i=0;i<n;i++)
      acum+=mat[i][j];
    printf("El promedio de la columna %d es %6.2f \n",j,(float)acum/n);
  }
}

void elementosFilaPromedio(TMat mat,int n,int m){ // c) muestre para cada fila que tenga al menos un cero la cantidad de elementos que superan el promedio de la matriz
  int i,j,cant;
  float prom;
  char aux;

  prom=0;
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      prom+=mat[i][j];
  prom/=n*m;
  printf("El promedio de la matriz es %6.2f \n",prom);

  for(i=0;i<n;i++){
    aux=0;
    cant=0;
    for (j=0;j<m;j++){
      if (mat[i][j]==0)
        aux=1;
      if (mat[i][j]>prom)
        cant++;
    }
    if (aux)
      printf("La fila %d tiene %d elementos que superan el promedio \n",i,cant);
  }
  ENTER
}
