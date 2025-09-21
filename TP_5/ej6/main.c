#include <stdio.h>
#include <stdlib.h>
#include "pilaDinam.h"
/*
6. Desarrollar subprogramas (con estructuras iterativas) que trabajando sobre una pila de
enteros:
a. cuente la cantidad de ceros que contiene.
b. obtenga el valor promedio (sin perder la información de la pila)
c. calcule los valores máximo y mínimo de la pila (sin perder la información de la pila)
d. quite todos los valores mayores al último.
*/

void cargaPila (TPila * p); // ninguna de las funciones pierde la información de la pila
void mostrarPila (TPila * p);

void cerosPila (TPila * p,int * cant); //a)
void promedioPila (TPila * p,float * promedio); // b)
void minMaxPila (TPila * p,int * min, int * max); // c)
void removeLargerThanLastPila (TPila * p); // d)


int main()
{
  TPila p;
  int cantCeros, max, min;
  float promedio;

  cargaPila(&p);
  mostrarPila(&p);

  cerosPila(&p,&cantCeros);
  promedioPila(&p,&promedio);
  minMaxPila(&p,&min,&max);
  removeLargerThanLastPila(&p);

  printf("Cantidad de ceros: %d \nPromedio: %6.2f \nMin: %d \nMax: %d \n \n",cantCeros,promedio,min,max);
  mostrarPila(&p);

  return 0;
}

void cargaPila(TPila * p){
  FILE * arch;
  TElementoP dato;

  arch = fopen("enteros.txt","rt");
  if (arch == NULL)
    printf("no se pudo abrir el archivo \n");
  else{
    iniciaP(p);
    while (!feof(arch)){
      fscanf(arch,"%d",&dato);
      poneP(p,dato);
    }
    fclose(arch);
  }
}

void mostrarPila(TPila * p){
  TPila aux;
  TElementoP dato;

  iniciaP(&aux);
  while (!vaciaP(*p)){
    sacaP(p,&dato);
    printf("%d   ",dato);
    poneP(&aux,dato);
  }
  printf("\n\n");
  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
  }
}

void cerosPila(TPila * p,int * cant){
  TElementoP dato;
  TPila aux;

  *cant=0;
  iniciaP(&aux);
  while (!vaciaP(*p)){
    sacaP(p,&dato);
    *cant += dato == 0; // *cant += !dato
    poneP(&aux,dato);
  }

  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
  }
}

void promedioPila(TPila * p, float * promedio){
  TPila aux;
  TElementoP dato;

  int acum=0, cont=0;
  iniciaP(&aux);

  while (!vaciaP(*p)){
    sacaP(p,&dato);
    poneP(&aux,dato);
    cont++;
    acum += dato;
  }
  if (cont)
    *promedio = (float)(acum)/cont;
  else
    *promedio = 0;

  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
  }
}

void minMaxPila(TPila * p, int * min, int * max){
  TPila aux;
  TElementoP dato;
  iniciaP(&aux);

  *min = 9999;
  *max = -9999;

  while (!vaciaP(*p)){
    sacaP(p,&dato);
    poneP(&aux,dato);
    *min = (dato < *min)? dato : *min; // esto es bastante ineficiente porque me obliga a asignar algo en la rama negativa
    *max = (dato > *max)? dato : *max; // pero lo quería probar xD
  }

  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
  }
}

void removeLargerThanLastPila(TPila * p){
  TPila aux;
  TElementoP dato;
  int last;
  iniciaP(&aux);

  while (!vaciaP(*p)){
    sacaP(p,&dato);
    poneP(&aux,dato);
    last = dato;
  }

  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    if (!(dato>last)) // es lo mismo poner (dato <= last ; pero así se entiende mejor que si dato > last no se guarda   (o por lo menos yo lo entiendo mejor)
      poneP(p,dato);
  }
}
