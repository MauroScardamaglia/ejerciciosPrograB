#include <stdio.h>
#include <stdlib.h>
#include "colaDinam.h"
/*
4. Ingresar en una cola los números almacenados (uno por línea) en un archivo de texto. Mostrar
el contenido de la cola.
a. Utilizar la implementación estática no circular.
b. Utilizar la implementación dinámica.
c. Mantener la información en la cola
*/ // voy a usar implementación dinámica y mostrar perdiendo y manteniendo la información

void cargarCola (TCola * c);
void mostrarColaPerdiendo (TCola * c);
void mostrarColaManteniendo (TCola * c);

int main()
{
  TCola c;
  cargarCola(&c);

  mostrarColaManteniendo(&c);
  mostrarColaPerdiendo(&c);

  printf("\n \n esta vacia?: %d \n",vaciaC(c));
  return 0;
}

void cargarCola(TCola *c){
  FILE * arch;
  TElementoC nro;
  iniciaC(c);
  arch = fopen("enteros.txt","rt");
  if (!arch)
    printf("no se pudo abrir el archivo de texto \n");
  else{
    while (!feof(arch)){
      fscanf(arch,"%d",&nro);
      poneC(c,nro);
    }
    fclose(arch);
  }
}

void mostrarColaPerdiendo(TCola * c){
  TElementoC dato;

  while (!vaciaC(*c)){
    sacaC(c,&dato);
    printf("%d\t",dato);
  }
  printf("\n\n");
}

void mostrarColaManteniendo(TCola * c){
  TElementoC dato;
  TCola aux;
  iniciaC(&aux);

  while (!vaciaC(*c)){
    sacaC(c,&dato);
    poneC(&aux,dato);
    printf("%d\t",dato);
  }
  printf("\n\n");
  while (!vaciaC(aux)){
    sacaC(&aux,&dato);
    poneC(c,dato);
  }
}
