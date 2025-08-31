#include <stdio.h>
#include <stdlib.h>
#define N 30

void cargaVec(int vec[N],int *n);
void muestraVec(int vec[N],int n);
void dupPares(int vec[N],int n);

int main()
{
    int vec[N], n;
    cargaVec(vec,&n);
    muestraVec(vec,n);
    dupPares(vec,n);
    muestraVec(vec,n);
    return 0;
}

void cargaVec(int vec[N],int *n){
  int i=0;
  printf("Ingrese cantidad de elementos\n");
  scanf("%d",n);
  for(;i<*n;i++)
    scanf("%d",&vec[i]);
}

void muestraVec(int vec[N],int n){
  int i;
  for(i=0;i<n;i++)
    printf("%d\t",vec[i]);
  printf("\n");
}
/*
void dupPares(int vec[N],int n){ // alternativa for
  int i;
  for (i=0;i<n;i+=2)
    vec[i]*=2;
}

void dupPares(int vec[N],int n){ // alternativa while
  int i=0;
  while(i<n){
    vec[i]*=2;
    i+=2;
  }
}
*/
void dupPares(int vec[N],int n){ // alternativa do while
  int i=0;
  do{
    vec[i]*=2;
    i+=2;
  } while (i<n);
}
