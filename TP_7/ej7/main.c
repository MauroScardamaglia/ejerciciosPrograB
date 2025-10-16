#include <stdio.h>
#include <stdlib.h>
/*
7. Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato. */

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;
typedef nodo * arbol;

void addNodo(arbol * a,int x);
void carga(arbol *a);
void sumaVerVoid(arbol a,int nivel,int x,int * suma);
int sumaVerInt(arbol a,int nivel,int x);


int main()
{
  int suma1 = 0,suma2,x;
  arbol a;

  carga(&a);

  printf("Ingrese nivel \n");
  scanf("%d",&x);
  sumaVerVoid(a,0,x,&suma1);
  suma2 = sumaVerInt(a,0,x);
  printf("Nivel dado como dato: %d \n",x);
  printf("por void --> %d\n",suma1);
  printf("por int --> %d\n",suma2);

  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void carga(arbol * a){
  addNodo(a, 5);
  addNodo(&(*a)->izq, 8);
  addNodo(&(*a)->izq->izq, 3);
  addNodo(&(*a)->izq->der, 6);
  addNodo(&(*a)->izq->der->der, 7);

  addNodo(&(*a)->der, 4);
  addNodo(&(*a)->der->izq, 1);
  addNodo(&(*a)->der->izq->der, 2);
  addNodo(&(*a)->der->izq->der->der, 15);
}

void sumaVerVoid(arbol a, int nivel, int x, int * suma){
  if (a){
    nivel ++;
    if (nivel == x && (a->izq == NULL && a->der || a->izq && a->der == NULL))
      *suma += a->dato;
    sumaVerVoid(a->izq,nivel,x,suma);
    sumaVerVoid(a->der,nivel,x,suma);
  }
}

int sumaVerInt(arbol a, int nivel, int x){
  if (!a)
    return 0;
  else{
    nivel++;
    if (nivel == x && (a->izq == NULL && a->der || a->izq && a->der == NULL))
      return a->dato + sumaVerInt(a->izq,nivel,x) + sumaVerInt(a->der,nivel,x);
    else
      return sumaVerInt(a->izq,nivel,x) + sumaVerInt(a->der,nivel,x);
  }
}
