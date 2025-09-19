#include <stdio.h>
#include <stdlib.h>
#include "pilaDinam.h"
/*
3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
a. en orden inverso, comenzando por el último votante.
b. en el orden que sufragaron.
*/

void cargaPila (TPila * p);
void mostrarOrdenInverso (TPila * p,int n);
void mostrarOrdenOriginal (TPila * p,int n);
int main()
{
  TPila p;
  int n;
  cargaPila(&p);
  printf("Ingrese cantidad de ultimos votantes \n");
  scanf("%d",&n);

  printf("3. Ingresar los numeros de DNI de los votantes de una mesa a medida que van votando y mostrar los últimos N (es dato) votantes \n");
  printf("\n a. en orden inverso, comenzando por el ultimo votante. \n");
  mostrarOrdenInverso(&p,n);
  printf("\n b. en el orden que sufragaron. \n "); // hice que no se perdieran la info en ambos procedimientos
  mostrarOrdenOriginal(&p,n);
  printf("\n \n \n a) para asegurar que no se pierda la info \n");
  mostrarOrdenInverso(&p,n);
  return 0;
}

void cargaPila(TPila * p){
  FILE * arch;
  TElementoP dato;

  arch= fopen("DNIs.txt","rt");
  if (arch == NULL)
    printf("no se pudo abrir el archivo de texto \n");
  else{
    iniciaP(p);
    while (!feof(arch)){
      fscanf(arch,"%d",&dato);
      poneP(p,dato);
    }
    fclose(arch);
  }
}

void mostrarOrdenInverso(TPila * p,int n){
  TPila aux;
  int i=1;
  TElementoP dato;

  iniciaP(&aux);
  while (i<=n && !vaciaP(*p)){
    sacaP(p,&dato);
    printf("%d \t",dato);
    poneP(&aux,dato);
    i++;
  }
  i=1;
  while (i<=n && !vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
    i++;
  }
  printf("\n \n \n");
}

void mostrarOrdenOriginal (TPila *p,int n){
  TPila aux;
  int i=1;
  TElementoP dato;

  iniciaP(&aux);
  while (i<=n && !vaciaP(*p)){
    sacaP(p,&dato);
    poneP(&aux,dato);
    i++;
  }
  i=1;
  while (i<=n && !vaciaP(aux)){
    sacaP(&aux,&dato);
    printf("%d \t",dato);
    poneP(p,dato);
    i++;
  }
  printf("\n \n \n");
}
