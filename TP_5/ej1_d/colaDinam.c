#include <stdio.h>
#include <stdlib.h>
#include "colaDinam.h"

void iniciaC(TCola * c){
  c->pri = c->ult = NULL;
}

void poneC(TCola * c,TElementoC x){ // en la implementación dinámica no existe el caso en que esté llena la cola
  nodo * aux;
  aux = (nodo *)malloc(sizeof(nodo));
  aux->dato = x;
  aux->sig = NULL;

  if (c->pri)
    c->ult->sig = aux;
  else
    c->pri = aux;
  c->ult = aux; // en cualquiera de los 2 casos ult tiene que apuntar a aux

}

void sacaC(TCola * c,TElementoC * x){
  nodo * aux;

  if (c->pri){
    aux = c->pri;
    *x = aux->dato;
    if (c->pri == c->ult) // un solo elemento
      iniciaC(c);
    else
      c->pri = aux->sig;
  free(aux);
  }
}

TElementoC consultaC (TCola c){
  if (c.pri)
    return c.pri->dato;
}

TElementoC vaciaC(TCola c){
  return c.pri == NULL;
}
