/*
1. Dada una lista simplemente enlazada de caracteres, escribir una función void que:
a) muestre su contenido.
b) devuelva la cantidad de nodos que poseen vocales.
c) indique si la lista está ordenada.
d) elimine el elemento ubicado en una posición P (entero) pasada como parámetro.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo {
  char dato;
  struct nodo * sig; } nodo;

typedef nodo * TLista;

void cargarLista (TLista * l); // inciso 0)

void mostrarLista (TLista l); // a)
int cantVocales (TLista l); // b)
int listaEstaOrdenada (TLista l); // c)
void eliminarElementoP (TLista * l,int p); // d)

int main (){
  TLista l;
  int p;

  cargarLista(&l);
  mostrarLista(l);
  printf("La cantidad de vocales de la lista es %d \n",cantVocales(l));
  printf("La lista esta ordenada? (1 si, 0 no) %d \n",listaEstaOrdenada(l));
  printf("Ingrese posicion >= 0 \n");
  scanf("%d",&p);
  eliminarElementoP(&l,p);
  mostrarLista(l);

  return 0;
}

void cargarLista (TLista * l){
  FILE * arch; // chars.txt
  char c;  // podria usar una lista auxiliar // y lo hago // y luego darle la dirección de memoria de esta a la lista del parámetro, pero voy a probar con la misma lista de parámetro
  TLista aux, nodoAux;

  *l = NULL; // si no se abre el archivo la lista queda apuntando a null
  arch = fopen("chars.txt","rt");
  if (!arch)
    printf("No se pudo abrir el archivo \n");
  else{

    aux = NULL;
    fscanf(arch,"%c",&c);
    while (!feof(arch)){
      nodoAux = (TLista)malloc(sizeof(nodo));
      nodoAux->dato = c;
      nodoAux->sig = aux;
      aux = nodoAux;
      fscanf(arch,"%c",&c);
    }
    *l = aux;
    fclose(arch);
  }
}

void mostrarLista(TLista l){
  char c;

  while (l){
    c = l->dato;
    printf("%c",c);
    l = l->sig;
  }
  printf(". \n");
}

int cantVocales(TLista l){
  int cant = 0;
  char aux;
  while (l){
    aux = l->dato;
    aux = toupper(aux);
    cant += aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U';
    l = l->sig;
  }
  return cant;
}

int listaEstaOrdenada(TLista l){ // el parámetro de orden es por ascendencia
  int aux = 1;
  char datoAnt;
  if (l){
    datoAnt = l->dato;
    l = l->sig;
  }
  while (l && aux){
    aux = l->dato > datoAnt;
    l = l->sig;
  }
  return aux;
}

void eliminarElementoP(TLista * l,int p){ // tomo como posiciones de la lista [0, 1, 2, 3, ...]
  TLista act, ant;
  int i=0;
  act = *l;
  if (act && p==0){
    ant = act;
    act = act ->sig;
    free(ant);
    *l = act;
  }
  else{
    while (act && i < p){
      ant = act;
      act = act->sig;
      i++;
    }
    if (act){ // llegó a p
      ant->sig = act->sig;
      free(act);
    }
  }
}
