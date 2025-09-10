#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// 5. Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es
// simétrica (aij = aji) con respecto a su diagonal.

typedef int TMat[MAX][MAX];

void cargaMat(TMat mat,int *n);

int simetrica(TMat mat,int i,int j);

int main()
{
  int n;
  TMat mat;
  cargaMat(mat,&n);

  if (simetrica(mat,n-2,n-1)) // insertar parametros
    printf("La matriz es simetrica \n");
  else
    printf("La matriz no es simetrica (asimetrica) \n");

  return 0;
}

void cargaMat(TMat mat,int *n){
  int i,j;
  FILE * arch;
  arch=fopen("matriz.txt","rt");
  if (arch==NULL)
    printf("No se pudo abrir el archivo \n");
  else{
    fscanf(arch,"%d",n);
    for (i=0;i<*n;i++)
      for (j=0;j<*n;j++)
        fscanf(arch,"%d",&mat[i][j]);
    fclose(arch);
  }

  for (i=0;i<*n;i++){
    for (j=0;j<*n;j++)
      printf("%d \t",mat[i][j]);
    printf("\n");
  }
  printf("\n");
}

int simetrica(TMat mat,int i,int j){
  if (j==0)
    return 1;
  else
    if (i==-1)
      return simetrica(mat,j-2,j-1);
    else
      if (mat[i][j]==mat[j][i])
        return simetrica(mat,i-1,j);
      else
        return 0;
}
