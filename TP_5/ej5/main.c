// Corregir los errores en el siguiente código manualmente, el cual carga una cola y luego calcula y
// muestra la suma de sus elementos.

/*
#include <stdio.h>
#include "tdacola.h"

void leerCola(TCOLA *c);

int main(void) {
  TCOLA cola;
  TELEMENTOC n, suma;

  iniciac(cola);
  leerCola(&cola);
  suma == 0;
  while(!vaciac(*cola)) {
    sacac(cola, &n);
    suma -= n;
  }
  printf("%d", suma);
  return 0;
}

void leerCola(TCOLA *c) {
  TELEMENTOC n;
  iniciac(&c);
  while(scanf("%d", n))
    ponec(c, &n);
}
*/

#include <stdio.h>
#include "colaDinam.h"

void leerCola(TCola *c);

int main(void) {
  TCola cola;
  TElementoC n, suma;

  iniciaC(&cola);
  leerCola(&cola);
  suma = 0;
  while(!vaciaC(cola)) {
    sacaC(&cola, &n);
    suma += n;
  }
  printf("%d", suma);
  return 0;
}

void leerCola(TCola *c) {
  TElementoC n;
  iniciaC(c);
  scanf("%d", &n);
  while(n){
    poneC(c,n);
    scanf("%d",&n);
  }
}
