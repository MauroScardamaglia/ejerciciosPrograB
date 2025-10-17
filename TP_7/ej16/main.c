#include <stdio.h>
#include <stdlib.h>

/*
16. Implementar una función iterativa que inserte --- un  (1 solo) ---- elemento en un ABB.
*/

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;

typedef nodo * arbol;

void addNodo(arbol * a,int x);
void carga(arbol * a);
void insertarABB(arbol * a,int num);
void mostrarArbolInorden(arbol a);
void insertarABBRecur(arbol * a, int x);

int main(){
  arbol a;
  carga(&a);
  char res = 's',opcion;
  int num;

  mostrarArbolInorden(a);
  printf("\n\n");

  while (res == 's'){
    printf("Ingrese numero a insertar en el ABB:  ");
    scanf("%d",&num);
    insertarABB(&a,num);
    printf("Desea ver el arbol? (s/n)  ");
    scanf(" %c",&opcion);
    if (opcion == 's')
      mostrarArbolInorden(a);
    printf("\n");
    printf("Desea ingresar otro numero? (s/n) ");
    scanf(" %c",&res);
  }
  mostrarArbolInorden(a);

  res ='s';
  printf("\n\n RECURSVIDAD \n");
  while (res == 's'){
    printf("Ingrese numero a insertar en el ABB:  ");
    scanf("%d",&num);
    insertarABBRecur(&a,num);
    printf("Desea ver el arbol? (s/n)  ");
    scanf(" %c",&opcion);
    if (opcion == 's')
      mostrarArbolInorden(a);
    printf("\n");
    printf("Desea ingresar otro numero? (s/n) ");
    scanf(" %c",&res);
  }

  mostrarArbolInorden(a);
  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void carga(arbol *a){

  arbol aux;

  addNodo(a,10);
  aux = *a;

  addNodo(&aux->izq,5);
  addNodo(&aux->izq->izq,2);
  addNodo(&aux->izq->der,7);
  addNodo(&aux->izq->izq->izq,1);
  addNodo(&aux->izq->izq->der,4);
  addNodo(&aux->izq->der->izq,6);
  addNodo(&aux->izq->der->der,8);
  addNodo(&aux->izq->der->der->der,9);

  addNodo(&aux->der,15);
  addNodo(&aux->der->izq,12);
  addNodo(&aux->der->der,17);
  addNodo(&aux->der->der->izq,16);
  addNodo(&aux->der->der->der,19);
  addNodo(&aux->der->der->der->der,21);
  addNodo(&aux->der->der->der->der->der,25);
}

void mostrarArbolInorden(arbol a){
  if (a){
    mostrarArbolInorden(a->izq);
    printf("%d  ",a->dato);
    mostrarArbolInorden(a->der);
  }
}


void insertarABB(arbol * a,int num) { // iterativo
  arbol * aux = a;

  while (*aux){
    if ((*aux)->dato > num)
      aux = &(*aux)->izq;
    else
      aux = &(*aux)->der;
  }
  addNodo(aux,num);
 /* *aux = (arbol) malloc (sizeof(nodo));
  (*aux)->dato = num;
  (*aux)->izq = (*aux)->der = NULL;
  */
}

void insertarABBRecur(arbol *a, int x){ // funcion recursiva, no lo pedía el ejercicio
  if (*a == NULL)
    addNodo(a,x);
  else{
    if ((*a)->dato > x)
      insertarABBRecur(&(*a)->izq, x);
    else
      insertarABBRecur(&(*a)->der, x);
  }
}
