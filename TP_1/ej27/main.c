#include <stdio.h>
#include <stdlib.h>
#define MAX 12

/*
27. Desarrollar una función que a partir de una matriz de NxM elementos enteros, devuelva en un
arreglo de structs, fila, columna y valor de las componentes de la matriz divisibles por N+M
*/
typedef int TMat[MAX][MAX];
typedef struct{
  int fila, columna, valor;} TReg;
typedef TReg TVecReg[MAX*MAX];

void cargaMat(TMat mat,int *n,int *m);
void muestraMat(TMat mat,int n,int m);
void procesamiento(TMat mat,int n,int m,TVecReg vec,int *cantVecReg);
void muestraVecReg(TVecReg vec,int cantVecReg);

int main()
{
  int n,m,cantVecReg;
  TMat mat;
  TVecReg vec;

  cargaMat(mat,&n,&m);
  muestraMat(mat,n,m);
  procesamiento(mat,n,m,vec,&cantVecReg);
  muestraVecReg(vec,cantVecReg);

  return 0;
}

void cargaMat(TMat mat,int *n,int *m){
  int i,j;
  printf("Ingrese n \n");
  scanf("%d",n);
  printf("Ingrese m \n");
  scanf("%d",m);
  for (i=0;i<*n;i++)
    for (j=0;j<*m;j++){
      printf("[%d][%d] ",i,j);
      scanf("%d",&mat[i][j]);
    }
  printf("\n");
}

void muestraMat(TMat mat,int n,int m){
  int i,j;
  for (i=0;i<n;i++){
    for (j=0;j<m;j++)
      printf("%d\t",mat[i][j]);
    printf("\n");
  }
  printf("\n");
}

void muestraVecReg(TVecReg vec,int cantVecReg){
  int i;
  for(i=0;i<cantVecReg;i++)
    printf("[%d][%d]= %d\n",vec[i].fila,vec[i].columna,vec[i].valor);
  printf("\n");
}

void procesamiento(TMat mat,int n,int m,TVecReg vec,int *cantVecReg){
  int i,j;
  *cantVecReg=0;
  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      if (mat[i][j]%(n+m)==0){
        vec[*cantVecReg].fila=i;
        vec[*cantVecReg].columna=j;
        vec[*cantVecReg].valor=mat[i][j];
        (*cantVecReg)++;
      }
}
