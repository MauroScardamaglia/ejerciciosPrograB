#include <stdio.h>
#include <stdlib.h>

/*
2. Generar una lista simplemente enlazada a partir del contenido de un arreglo de N enteros no
ordenados:
a) invirtiendo el orden de sus elementos (no se permite recorrer el arreglo comenzando por el
último elemento)
b) manteniendo el orden de sus elementos.
c) de forma ordenada */

typedef int TVec[20];

typedef struct nodo{
  int dato;
  struct nodo * sig; } nodo;

typedef nodo * TLista;

void cargaVec(TVec vec,int * n);
void mostrarLista(TLista l);

void cargaInvertida(TVec vec, int n, TLista * l);
void cargaOrdenOriginal(TVec vec, int n, TLista * l);
void cargaOrdenada(TVec vec, int n, TLista * l);

int main()
{
  TVec vec;
  int n;
  TLista lista1,lista2,lista3;

  cargaVec(vec,&n);

  printf("a) Invertido \n");
  cargaInvertida(vec,n,&lista1);
  mostrarLista(lista1);

  printf("b) Orden original \n");
  cargaOrdenOriginal(vec,n,&lista2);
  mostrarLista(lista2);

  printf("c) Ordenado \n");
  cargaOrdenada(vec,n,&lista3);
  mostrarLista(lista3);
  printf("\n");

  return 0;
}

void cargaVec(TVec vec,int * n){
  int i=0,num;
  FILE * arch;
  arch = fopen("enteros.txt","rt");
  if (!arch)
    printf("No se abrio el txt \n");
  else{
    fscanf(arch,"%d",n);
    for (;i< *n; i++){
      fscanf(arch,"%d",&num);
      vec[i] = num;
    }
    fclose(arch);
  }
}

void mostrarLista (TLista l){
  while (l){
    printf("%d  ",l->dato);
    l = l->sig;
  }
  printf("\n \n");
}

void cargaInvertida(TVec vec, int n,TLista * l){
  int i;
  TLista aux,act;

  act = NULL;
  i = 0;
  while (i<n){ // me acabo de dar cuenta que esto es un for xd
    aux = (TLista)malloc(sizeof(nodo));
    aux->dato = vec[i];
    aux->sig = act; // si es el primer elemento va a apuntar a null
    act = aux;
    i++;
  }
  *l = aux;
}

void cargaOrdenOriginal(TVec vec,int n,TLista * l){
  int i;
  TLista aux, ant;

  *l = NULL;
  for (i=0; i<n; i++){
    aux = (TLista) malloc (sizeof(nodo));
    aux->dato = vec[i];
    aux->sig = NULL;
    if (i==0)
      *l = aux;
    else
      ant->sig = aux;
    ant = aux;
  }
}

void cargaOrdenada(TVec vec, int n, TLista *l){
  TLista ant, act, nuevo; // podría solo usar ant y hacer nuevo->sig = ant->sig; + ant->sig= nuevo // y moverme con ant->sig
  int i;

  *l = NULL;
  for (i=0; i<n; i++){
    nuevo = (TLista) malloc (sizeof(nodo));
    nuevo->dato = vec[i];
    if (!(*l) || l && nuevo->dato < (*l)->dato){ // 1° caso) va al principio de la lista    ----  funcionara con l->->dato ?? --> claro que no -> es el campo de la variable a la que apunta el puntero (lo probé igual)
      nuevo->sig = *l;   // en el if habia puesto (!l || ...) y no andaba, así como está ahora funciona osea que aunque && tenga > precedencia a l || igual analiza primero el lado izq del OR
      *l = nuevo;
    }
    else{ // no va al principio (&& la lista no está vacia)
      ant = *l;
      act = (*l)->sig;
      while (act && nuevo->dato > act->dato){ // no me caiga de la lista y siga siendo menor
        ant = act;
        act = act->sig;
      }
      nuevo->sig = act;
      ant->sig = nuevo;
    }
  }
}
