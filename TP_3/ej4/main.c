#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// 4. Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A
// (realizar una versión void y otra int)

typedef float TMat[MAX][MAX];

void cargaMat(TMat mat, int * n, int * m);

int cantX(TMat mat,int i,int j,int n,float x);

void procedCantX(TMat mat,int i,int j,int n,float x,int *cant);


int main()
{
  int n,m;
  TMat mat;
  float x;
  int aux=0;;

  cargaMat(mat,&n,&m);
  printf("Ingrese valor x \n");
  scanf("%f",&x);

  printf("a) Version funcion int \n");
  printf("El valor %6.2f aparece %d veces en la matriz \n",x,cantX(mat,n-1,m-1,n-1,x));

  printf("b) Version procedimiento void \n");
  procedCantX(mat,n-1,m-1,n-1,x,&aux);
  printf("El valor %6.2f aparece %d veces en la matriz \n",x,aux);


  return 0;
}

void cargaMat(TMat mat, int * n, int * m){
  int i, j;
  printf("Ingrese cantidad de filas y columnas \n");
  scanf("%d",n);
  printf("\n");
  scanf("%d",m);
 // scanf("%u",m); // estuve usando unsigned short int para n,m,i y j; pero se me re rompía el scanf del n y el m, me tomaba el n, y después de tomarme el m me cambiaba el n a 0; así que estoy usando en todos int como por defecto

  for (i=0;i<*n;i++)
    for (j=0;j<*m;j++){
      printf("[%u][%u]= ",i,j);
      scanf("%f",&mat[i][j]);
    }
  printf("\n");

  for (i=0;i<*n;i++){
    for (j=0;j<*m;j++)
      printf("%6.2f \t ",mat[i][j]);
    printf("\n");
  }
  printf("\n");
}


int cantX(TMat mat,int i,int j,int n,float x){
  if (i==0)
    if (j==0)
      return mat[0][0]==x;
    else
      return cantX(mat,n,j-1,n,x) + (mat[i][j]==x); // estuve como 1 hora buscando porque no funcionaba el código, me faltaba poner paréntesis alrededor de la verificación sobre el
  else                                              // valor de la componente actual (si es x)
    return cantX(mat,i-1,j,n,x) + (mat[i][j]==x);  // el + tiene mayor precedencia (se toma antes) que el ==
}


void procedCantX(TMat mat,int i,int j,int n,float x,int *cant){
  if (j>=0) // caso base implicito
    if (i==-1) // me caigo de la columna
      procedCantX(mat,n,j-1,n,x,cant);
    else{
      *cant+=mat[i][j]==x;
      procedCantX(mat,i-1,j,n,x,cant);
    }
}
