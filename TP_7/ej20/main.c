#include <stdio.h>
#include <stdlib.h>

/*
20. Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original.
d) determinar el grado del árbol original.
*/

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;
typedef nodo * arbol;

void addNodo(arbol * a,int x);
void carga(arbol *a);

int cantNodosNivelImpar(arbol a, int nivel); // a)
int grado(arbol a);
void promedioClavesGradoK(arbol a,int k,int * acum,int * cont); // b)
int alturaArbolOriginal(arbol a); // c)
void gradoArbolOriginal(arbol a,int * gradoMax); // d)



int main() {
  arbol a;
  carga(&a);

  int k, acum = 0, cont = 0, gradoMax = 0;

  printf("a) Cantidad de nodos en niveles impares: %d \n\n",cantNodosNivelImpar(a,1));

  printf("b) \nIngrese grado (>=0) \n");
  scanf("%d",&k);
  promedioClavesGradoK(a,k,&acum,&cont);
  if (cont)
    printf("El promedio de los datos que tienen grado %d es %6.2f \n\n",k,1.0 * acum / cont);
  else
    printf("No hay datos que tengan grado %d \n\n",k);

  printf("c) La altura del arbol original es %d \n\n",alturaArbolOriginal(a));

  printf("d) \n");
  gradoArbolOriginal(a,&gradoMax);
  printf("El grado del arbol original es: %d \n",gradoMax);

  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void carga(arbol *a){

  arbol aux;

  addNodo(a,22);
  aux = *a;

  addNodo(&aux->izq,13);
  addNodo(&aux->izq->izq,18);
  addNodo(&aux->izq->izq->der,19);
  addNodo(&aux->izq->izq->der->der,21);

  addNodo(&aux->izq->der,25);

  addNodo(&aux->izq->der->der,27);
  addNodo(&aux->izq->der->der->izq,3);
  addNodo(&aux->izq->der->der->izq->der,7);

  addNodo(&aux->izq->der->der->der,41);
  addNodo(&aux->izq->der->der->der->izq,40);
  addNodo(&aux->izq->der->der->der->izq->der,45);
  addNodo(&aux->izq->der->der->der->izq->der->izq,50);
  addNodo(&aux->izq->der->der->der->izq->der->izq->der,51);
  addNodo(&aux->izq->der->der->der->izq->der->izq->der->der,52);
  /*
  addNodo(&aux->izq->der->der->der->izq->der->izq->der->der->der,53);
  addNodo(&aux->izq->der->der->der->izq->der->izq->der->der->der->der,54);
  */
}

int grado(arbol a){
  int aux = 0;

  a = a->izq;
  while (a){
    aux++;
    a = a->der;
  }
  return aux;
}

// a) hallar la cantidad de nodos que habia en niveles impares.
int cantNodosNivelImpar(arbol a, int nivel){
  if (a)
    return cantNodosNivelImpar(a->izq,nivel + 1) + cantNodosNivelImpar(a->der,nivel) + (nivel % 2 == 1); // % precede a + y + precede a ==
  else
    return 0;
}

// b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
void promedioClavesGradoK(arbol a,int k,int * acum,int * cont){
  if (a){
    if (grado(a) == k){
      *cont +=1;
      *acum += a->dato;
    }
    promedioClavesGradoK(a->izq,k,acum,cont);
    promedioClavesGradoK(a->der,k,acum,cont);
  }
}

// c) obtener la altura del árbol original.
int alturaArbolOriginal(arbol a){
  int nivelIzq, nivelDer;
  if (a){
    nivelIzq = alturaArbolOriginal(a->izq) + 1;
    nivelDer = alturaArbolOriginal(a->der);
    return (nivelIzq > nivelDer) ? nivelIzq : nivelDer;
  }
  else
    return 0;
}

// d) determinar el grado del árbol original.
void gradoArbolOriginal(arbol a,int * gradoMax){
  int aux;
  if (a){
    aux = grado(a);
    if (aux > *gradoMax)
      *gradoMax = aux;
    gradoArbolOriginal(a->izq,gradoMax);
    gradoArbolOriginal(a->der,gradoMax);
  }
}
