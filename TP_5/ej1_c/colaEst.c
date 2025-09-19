#include <stdio.h>
#include <stdlib.h>
#include "colaEst.h"

void iniciaC(TCola * c){
  c->pri = c->ult = -1;
}

void poneC(TCola * c,TElementoC x){
  if (c->ult != MAX-1){
    if (c->pri == -1)
      c->pri = 0;
    c->datos[++ c->ult] = x;
  }
}

void sacaC(TCola * c,TElementoC * x){
  if (!vaciaC(*c))
    *x = c->datos[c->pri];
  if (c->pri == c->ult)
    iniciaC(c);
  else
    c->pri++;

}

TElementoC consultaC(TCola c){
  if (!vaciaC(c))
    return c.datos[c.pri];
}

int vaciaC(TCola c){
  return c.pri == -1;
}
