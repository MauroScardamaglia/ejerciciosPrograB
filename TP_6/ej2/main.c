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

void cargaVec(TVec vec);

void cargaInvertida(TVec vec, int n, TLista * l);
void cargaConOrden(TVec vec, int n, TLista * l);
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

  printf("\n b) orden original \n");
  cargaConOrden(vec,n,&lista2);
  mostrarLista(lista2);

  printf("\n ordenado \n");
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
    fscanf("%d",n);
    for (;i< *n;i++)
      fscanf("%d",&num);
      vec[i] = num;
    fclose(arch);
  }
}

void cargaInvertida(TVec vec,TLista * l){
  int i;
  TLista aux,act;

  if (n){
    act = (TLista)malloc(nodo);
    act->dato = vec[0];
    act->sig = NULL;
    *l = act;
    while (act && i<n){




    }



  }


}
