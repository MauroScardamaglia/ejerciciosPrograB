#include <stdio.h>
#include <stdlib.h>
#define MAX 40

// 3. Dado un vector A de N elementos, obtener el promedio de sus elementos.
typedef int TVec[MAX];

float promedio(TVec vec,unsigned short int i,unsigned short int n);
void cargaVec(TVec vec,unsigned short int * n);

int main()
{
  TVec vec;
  unsigned short int n;

  cargaVec(vec,&n);
  printf("El promedio del vector es %6.2f \n",promedio(vec,n-1,n));

  return 0;
}

void cargaVec(TVec vec, unsigned short int * n){
  unsigned short int i;

  printf("Ingrese cantidad de elementos del vector \n");
  scanf("%u",n);
  for (i=0;i<*n;i++){
    printf("[%u]= ",i);
    scanf("%d",&vec[i]);
  }

}

float promedio(TVec vec, unsigned short int i,unsigned short int n){
  if (i==0)
    return vec[i];
  else
    if (i==n-1)
      return (promedio(vec,i-1,n) + vec[i])/n;
    else
      return promedio(vec,i-1,n) + vec[i];
}
