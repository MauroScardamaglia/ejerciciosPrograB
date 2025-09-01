#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
/*
25. Leer el nombre y la edad de N personas, calcular e imprimir:
a) el listado de nombres de las personas de más de X años (X es dato).
b) el porcentaje de las personas mayores de edad (sobre el total).
*/
typedef char st20[21];
typedef st20 TVec[MAX];
void procesar(int N, int x,TVec vec,int *n,float *porcAdultos);
void muestraVec(TVec vec,int n);

int main()
{
  int N,x,n;
  TVec vec;
  float porcAdultos;
  printf("Ingrese cantidad de personas (N) y cantidad de anios a pasar (x) \n");
  scanf("%d %d",&N,&x);
  procesar(N,x,vec,&n,&porcAdultos);
  printf("a) \n El listado de personas mayores de %d anios es \n",x);
  muestraVec(vec,n);
  printf("b) \n");
  printf("El porcentaje de las personas mayores de edad (>=18) es %6.2f %% \n",porcAdultos);
  return 0;
}

void procesar(int N, int x,TVec vec,int *n,float *porcAdultos){
  int i, cantAdultos=0, edad;
  char nombre[21];
  *n=0;

  for (i=1;i<=N;i++){
    printf("Ingrese nombre y edad \n");
    scanf("%s",nombre);                 // uso scanf porque, a pesar de que no toma multiples palabras (el espacio lo toma como \n, solo necesito nombre por lo tanto me basta
    scanf("%d",&edad);                  // quise usar gets y no me andaba xd
    if (edad>=18)
      cantAdultos++;
    if (edad>=x){ // interpreto mayor a una edad x a tener esa edad o tener mas años
      strcpy(vec[*n],nombre);
      (*n)++;
    }
  }
  if (N==0) // por las dudas xd
    *porcAdultos=0;
  else
    *porcAdultos=100*(float)cantAdultos/N;
}

void muestraVec(TVec vec,int n){
  int i=0;
  for (;i<n;i++)
    printf("[%d]=\"%s\"\n",i,vec[i]);
}
