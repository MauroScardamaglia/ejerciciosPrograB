#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;
typedef nodo * arbol;

void addNodo(arbol * a,int x);
void carga(arbol *a);

/*
11. Retornar el valor mínimo de un ABB
12. Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
parámetros de entrada.
14. Desarrollar una función que compruebe que si un árbol binario es un ABB. */

int minABB(arbol a); // 11) Recursivo
int minABBIterativo(arbol a); // 11) Iterativo

void elementosIntervABB(arbol a,int A,int B,int * cant); // 12) Void
int elementosIntervABBVerInt(arbol a,int A,int B); // 12) Int

void esABBVerVoid(arbol a,int * ant,int *aux); // 14) void
int esABBVerInt(arbol a,int min,int max); // 14) int



int main(){
  arbol a;
  int A,B,cant=0,aux=1,ant=-9999;

  carga(&a);

  printf("11) \n");
  if (a){
    printf("El minimo del ABB (Arbol Binario de Busqueda) es \n");
    printf("Forma recursiva: %d \n",minABB(a));
    printf("Forma iterativa: %d \n",minABBIterativo(a));
  }
  else
    printf("Arbol vacio \n");



  printf("\n12) \nIngrese A y B enteros\n");
  scanf("%d %d",&A,&B);
  elementosIntervABB(a,A,B,&cant);
  printf("\nLa cantidad de nodos con valores mayores que %d y menores que %d es\n",A,B);
  printf("Forma void: %d\n",cant);
  printf("Forma int: %d\n\n",elementosIntervABBVerInt(a,A,B));



  printf("14)\n");

  printf("Version Void:\n");
  esABBVerVoid(a,&ant,&aux);
  if (aux)
    printf("Arbol efectivamente ABB \n");
  else
    printf("Ete arbol no e ABB loco, cuidao, vo fijate \n");

  printf("Version Int: \n");
  if (esABBVerInt(a,-9999,9999))
    printf("Si papi, es ABB el arbol \n");
  else
    printf("Uhh, la pifiaste, no es ABB ehh, ojito \n");

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

//  ------------- 11) ------------

int minABB(arbol a){ // 11) Recursivo
  if (a->izq)
    return minABB(a->izq);
  else
    return a->dato;
}

int minABBIterativo(arbol a){ // 11) Iterativo
  while (a->izq) // nunca se invoca con un arbol vacio, si lo hiciera, que tengo que devolver?? un valor imposible?
    a = a->izq;
  return a->dato;
}



// ------------  12)  -------------
/* void elementosIntervAB(arbol a,int A,int B,int * cant){   ------ Versión sencilla, no aprovecha la utilidad de ABB
  if(a){
    if (a->dato > A && a->dato < B)
      *cant +=1;
    elementosIntervAB(a->izq,A,B,cant);
    elementosIntervAB(a->der,A,B,cant);
  }
} */

/*void elementosIntervABB(arbol a,int A,int B,int *cant){  ---- Versión 1, recorre de más (aunque no todos los nodos)
  if (a){                                                  ---- al recorrer con inorden recorre todos los nodos que son menores a A
    elementosIntervABB(a->izq,A,B,cant); // a->izq
    printf("%d  ",a->dato);
    if (a->dato < B){
      if (a->dato > A)
        *cant += 1;
      elementosIntervABB(a->der,A,B,cant); // a->der
    }
  }
} */

void elementosIntervABB(arbol a,int A,int B,int *cant){ // ----- Versión 3, bastante más eficiente
  if (a){
    if (a->dato > A && a->dato < B)
      *cant += 1;
    //printf("%d  ",a->dato);
    if (a->dato > A)
      elementosIntervABB(a->izq,A,B,cant);
    if (a->dato < B)
      elementosIntervABB(a->der,A,B,cant);
  }
}

int elementosIntervABBVerInt(arbol a,int A,int B){ // ---- mismo que lo anterior pero versión int
  int aux=0;
  if (!a)
    return 0;
  else{
    //printf("%d  ",a->dato);
    if (a->dato > A)
      aux += elementosIntervABBVerInt(a->izq,A,B);
    if (a->dato < B)
      aux += elementosIntervABBVerInt(a->der,A,B);
    return aux + (a->dato > A && a->dato < B);
  }
}


// --------------------- 14) -----------

void esABBVerVoid(arbol a,int * ant,int *aux){ // version void, la más eficiente y común según gpt
  if (a){ //       RECORRO POR INORDEN
    esABBVerVoid(a->izq,ant,aux);
    if (*ant >= a->dato)
      *aux = 0;
//  printf("%d %d\n",*ant,a->dato); // para ver, en la consola, como recorre y compara c/nodo
    *ant = a->dato;
    if (*aux)
      esABBVerVoid(a->der,ant,aux);
  }
}

// esta versión se le ocurrió a gpt, la adapté a mi gusto (saqué la idea de usar min y max):
int esABBVerInt(arbol a,int min,int max){ // version int, guardo un rango y voy verificando que los valores actuales estén dentro de él
  if (a){
//  printf("min: %d  act: %d max: %d \n",min,a->dato,max); // -- sé que no es correcto printf en función int pero es para probar
    if (a->dato > min && a->dato < max)
      return esABBVerInt(a->izq,min,a->dato) && esABBVerInt(a->der,a->dato,max);
    else
      return 0;
  }
  else
    return 1;
}

// termineeeeeeeeeeeeeeé, lpm


// líneas extras para llegar a las 200 líneas xd
