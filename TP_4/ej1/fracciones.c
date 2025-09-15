#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"
/*
1. Realizar un TDA para números fraccionarios, es decir aquellos que se expresan como el
cociente de dos números enteros. Las operaciones que deberá soportar el TDA son:
- crear(entero numerador, entero denominador) retorna fracción.
- numerador(fracción f) retorna entero.
- denominador(fracción f) retorna entero.
- sumar(fracción f1, fracción f2) retorna fracción.
- restar(fracción f1, fracción f2) retorna fracción.
- multiplicar(fracción f1, fracción f2) retorna fracción.
- dividir(fracción f1, fracción f2) retorna fracción.
- simplificar(fracción f) retorna fracción simplificada.
- iguales(fracción f1, fracción f2) retorna verdadero o falso.
*/
int mcd(int a,int b);

TFracc crear(int num,int denom){
  TFracc fraccion;
  fraccion.numerador=num;
  fraccion.denominador=denom;
  return fraccion;
}

int numerador(TFracc fraccion){
  return fraccion.numerador;
}

int denominador(TFracc fraccion){
  return fraccion.denominador;
}

TFracc sumar(TFracc fraccion1,TFracc fraccion2){
  TFracc aux;
  aux.denominador= fraccion1.denominador*fraccion2.denominador;
  aux.numerador= fraccion1.numerador*fraccion2.denominador + fraccion2.numerador*fraccion1.denominador;
  return aux;
}

TFracc restar(TFracc fraccion1,TFracc fraccion2){
  TFracc aux;
  aux.denominador= fraccion1.denominador*fraccion2.denominador;
  aux.numerador= fraccion1.numerador*fraccion2.denominador - fraccion2.numerador*fraccion1.denominador;
  return aux;
}

TFracc multiplicar(TFracc fraccion1,TFracc fraccion2){
  TFracc aux;
  aux.numerador=fraccion1.numerador*fraccion2.numerador;
  aux.denominador=fraccion1.denominador*fraccion2.denominador;
  return aux;
}

TFracc dividir(TFracc fraccion1,TFracc fraccion2){
  TFracc aux;
  aux.numerador=fraccion1.numerador*fraccion2.denominador;
  aux.denominador=fraccion1.denominador*fraccion2.numerador;
  return aux;
}

int mcd(int a,int b){
  int aux;
  while (b!=0){
    aux=b;
    b=a%b;
    a=aux;
  }
  return a;
}

TFracc simplificar(TFracc fraccion){
  int aux;
  TFracc fraccAux;
  if (fraccion.denominador<0){
    fraccion.denominador*=-1;
    fraccion.numerador*=-1;
  }
  aux=mcd(abs(fraccion.numerador),abs(fraccion.denominador));
  fraccAux.numerador=fraccion.numerador/aux;
  fraccAux.denominador=fraccion.denominador/aux;
  return fraccAux;
}

int iguales(TFracc fraccion1,TFracc fraccion2){
  fraccion1=simplificar(fraccion1);
  fraccion2=simplificar(fraccion2);
  return fraccion1.numerador == fraccion2.numerador && fraccion1.denominador == fraccion2.denominador;
}

void mostrar(TFracc fraccion){
  printf("%d/%d \n \n",fraccion.numerador,fraccion.denominador);
}
