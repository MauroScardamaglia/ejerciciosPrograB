#include <stdio.h>
#include <stdlib.h>
#include "pilaEst.h"

void iniciaP(TPila * p){
  p->tope = -1;
}

void poneP(TPila * p,TElementoP dato){
  if (p->tope != MAX - 1)
    p->datos[++ p->tope] = dato;
}

void sacaP(TPila * p,TElementoP * dato){
  // if (p->tope != -1) // !vacia
  if (!vaciaP(*p))
    *dato = p->datos[p->tope--];
}

TElementoP consultaP(TPila p){
  if (p.tope != -1)
    return p.datos[p.tope]; // warning: control reaches end of non-void function
}                           // no hay rama negativa, pero en este caso está bien

int vaciaP(TPila p){
  return p.tope == -1;
}
