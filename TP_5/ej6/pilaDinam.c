#include <stdio.h>
#include <stdlib.h>
#include "pilaDinam.h"
// por más que TPila sea un puntero, al modficar su valor se pasa por referencia. Por eso el "doble puntero"


void iniciaP(TPila * p){ // si no lo pasara por referencia modificaria el valor de un puntero local y el puntero del parametro no se modificaría
  *p = NULL;
}

void poneP(TPila * p,TElementoP x){
  TPila aux;

  aux = (TPila)malloc(sizeof(nodoP));
  aux->dato = x;
  aux->sig = *p;
  *p = aux;
}

void sacaP(TPila *p,TElementoP *x){
  TPila aux;
  if (!vaciaP(*p))
  aux = *p;
  *x = aux->dato;
  *p = aux->sig;
  free(aux);
}

TElementoP consultaP(TPila p){
  if (!vaciaP(p))
    return p->dato;
}

int vaciaP(TPila p){
  return p == NULL;
}
