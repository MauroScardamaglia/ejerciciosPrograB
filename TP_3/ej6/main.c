#include <stdio.h>
#include <stdlib.h>
#define MAX 30
/*
6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par.
*/

typedef int TMat[MAX][MAX];

void cargaMat(TMat mat,int *n,int * m);
int cumple(TMat mat,int n,int m,int i,int j,int sumaFila,int sumaFilaAnt);

int main (){
  TMat mat;
  int n,m;
  cargaMat(mat,&n,&m);
  printf("\n \n");
  if (cumple(mat,n,m,0,0,0,0))
    printf("Cumple la condicion \n");
  else
    printf("No cumple la condicion \n");

  return 0;
}

void cargaMat(TMat mat,int *n,int * m){
  int i,j;
  FILE * arch;

  arch=fopen("matriz.txt","rt");
  if (arch==NULL)
    printf("No se pudo abrir txt \n");
  else{
    fscanf(arch,"%d %d",n,m);
    for (i=0;i<*n;i++)
      for (j=0;j<*m;j++)
        fscanf(arch,"%d",&mat[i][j]);

    for (i=0;i<*n;i++){
      for (j=0;j<*m;j++)
        printf("%d \t",mat[i][j]);
      printf("\n");
    }
  }
}


/*
6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par.
*/

int cumple(TMat mat,int n,int m,int i,int j,int sumaFila,int sumaFilaAnt){
  if (i==n)
    return 1;
  else
    if (i==0 && j==n)
      if (sumaFila%2==0)
        return cumple(mat,n,m,1,0,0,sumaFila);
      else
        return 0;
    else
      if (j==n)
        if(sumaFila>sumaFilaAnt)
          return cumple(mat,n,m,i+1,0,0,sumaFila);
        else
          return 0;
      else
        return cumple(mat,n,m,i,j+1,sumaFila+mat[i][j],sumaFilaAnt);
}
