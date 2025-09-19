#include <stdio.h>
#include <stdlib.h>
#include "pilaDinam.h"
/*
2. Ingresar en una pila los caracteres almacenados (uno por l�nea) en un archivo de texto. Mostrar
el contenido de la pila.
a. Utilizar la implementaci�n est�tica.
b. Utilizar la implementaci�n din�mica.
c. Mantener la informaci�n en la pila.
*/    // uso la implementaci�n din�mica, copio la hecha y le cambio el TElementoP de int a char
      // tiene la ventaja de que se no llena
void cargarPila(TPila * p);
void mostrarPilaPerderla(TPila * p);
void mostrarPilaNoPerderla(TPila * p);

int main()
{
  TPila p;
  char opcion;
  cargarPila(&p);
  printf("Desea perder la pila? (s/n) \n \n");
  scanf("%c",&opcion);
  if (opcion == 's')
    mostrarPilaPerderla(&p);
  else{
    mostrarPilaNoPerderla(&p);
    printf("\n \n");
    mostrarPilaPerderla(&p);
  }
  return 0;
}

void cargarPila(TPila * p){
  FILE * arch;
  TElementoP dato;

  arch = fopen("caracteres.txt","rt");
  if (arch == NULL)
    printf("no se pudo abrir el txt \n");
  else{
    iniciaP(p);
    fscanf(arch,"%c",&dato);
    while (!feof(arch)){
      poneP(p,dato);
      fscanf(arch,"%c",&dato);
    }
    fclose(arch);
  }
}

void mostrarPilaPerderla(TPila * p){
  TElementoP dato;
  while (!vaciaP(*p)){
    sacaP(p,&dato);
    printf("%c",dato);
  }
  printf("\n \n");
}

void mostrarPilaNoPerderla(TPila * p){
  TPila aux;
  TElementoP dato;
  while (!vaciaP(*p)){
    sacaP(p,&dato);
    printf("%c",dato);
    poneP(&aux,dato);
  }
  printf("\n \n");
  while (!vaciaP(aux)){
    sacaP(&aux,&dato);
    poneP(p,dato);
  }
}
