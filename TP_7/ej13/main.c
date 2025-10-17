#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <string.h> // en realidad no lo uso
/*
13. Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente */

typedef struct nodo{
  char dato;
  struct nodo *izq, *der; } nodo;

typedef nodo * arbol;

void addNodo(arbol *a, char x);
void carga(arbol *a);

void generarArreglo(arbol a,char vec[], int *n);

int main(){
  arbol a;
  char vec[MAX];
  int n = 0, i;

  carga(&a);
  generarArreglo(a,vec,&n);

  for (i=0; i<n; i++)
  printf("Char[%d]: %c \n",i,vec[i]);

  return 0;
}

void addNodo(arbol *a, char x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void carga(arbol *a){
  arbol aux;

  addNodo(&aux,'3');
  *a = aux;

  addNodo(&aux->izq,'&');
  addNodo(&aux->izq->izq,'!');
  addNodo(&aux->izq->der,'*');
  addNodo(&aux->izq->izq->izq,' ');
  addNodo(&aux->izq->izq->der,'#');
  addNodo(&aux->izq->der->der,'/');
  addNodo(&aux->izq->der->der->der,'0');

  addNodo(&aux->der,'?');
  addNodo(&aux->der->izq,'9');
  addNodo(&aux->der->izq->izq,'8');
  addNodo(&aux->der->izq->der,'=');
  addNodo(&aux->der->der,'P');
  addNodo(&aux->der->der->izq,'D');
  addNodo(&aux->der->der->izq->izq,'@');
  addNodo(&aux->der->der->izq->izq->der,'B');
  addNodo(&aux->der->der->der,'m');
  addNodo(&aux->der->der->der->izq,'^');
  addNodo(&aux->der->der->der->izq->izq,'U');
  addNodo(&aux->der->der->der->der,'t');
  addNodo(&aux->der->der->der->der->der,'}');
}

void generarArreglo(arbol a,char vec[],int *n){
  if (a){
    generarArreglo(a->der,vec,n);
    vec[*n] = a->dato;              // inorden de der a izq       invocoPorDer
    *n += 1;                        //                            proceso (n++ y añado dato actual al vector
    generarArreglo(a->izq,vec,n);   //                            invocoPorIzq
  }
}
