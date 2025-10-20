#include <stdio.h>
#include <stdlib.h>
/*
21. Dado un árbol binario que proviene de la transformación de un bosque,
a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).
*/

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;
typedef nodo * arbol;

void addNodo(arbol * a,int x);
void carga(arbol *a);
int grado(arbol a);
int alturaArbol(arbol a);

int cantidadArbolesAlturaK(arbol a,int k); // a)

int claveMayor(arbol a,int max);
void generarVec(arbol a,int vec[],int * n); // b)

int recorrerArbolGradoK(arbol a,int k);
int verifNodosGradoK(arbol a, int k); // c)

int main()
{
  arbol a;
  carga(&a);
  int vec[50], n, k, i;

  printf("a) \nIngrese nivel k \n");
  scanf("%d",&k);
  printf("La cantidad de arboles del bosque con altura >= a %d es %d \n\n",k,cantidadArbolesAlturaK(a,k));

  printf("b) \n");
  generarVec(a,vec,&n);
  for (i=0; i<n; i++)
    printf("Vec[%d] = %d \n",i,vec[i]);
  printf("\n");

  printf("c) Ingrese grado k \n");
  scanf("%d",&k);

  if (verifNodosGradoK(a,k))
    printf("Todos los arboles contienen al menos 1 nodo de grado %d \n",k);
  else
    printf("No todos los arboles contienen al menos 1 nodo de grado %d \n",k);

  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void carga(arbol *a){

  arbol aux;

  addNodo(a,5);
  aux = *a;

  // 1er arbol
  addNodo(&aux->izq,6);
  addNodo(&aux->izq->der,9);
  addNodo(&aux->izq->der->izq,10);
  addNodo(&aux->izq->der->izq->izq,11);

  // 2do arbol
  addNodo(&aux->der,8);
  addNodo(&aux->der->izq,7);
  addNodo(&aux->der->izq->der,11);
  addNodo(&aux->der->izq->der->der,15);
  // addNodo(&aux->der->izq->der->izq,13);

  // 3er árbol
  addNodo(&aux->der->der,10);
  // addNodo(&aux->der->der->izq,18);

  // 4to nodo
  addNodo(&aux->der->der->der,19);
  addNodo(&aux->der->der->der->izq,22);
  addNodo(&aux->der->der->der->izq->izq,23);

  // 5to nodo
  addNodo(&aux->der->der->der->der,23);
  addNodo(&aux->der->der->der->der->izq,97);
  addNodo(&aux->der->der->der->der->izq->der,0);
  addNodo(&aux->der->der->der->der->izq->der->izq,-1);
  addNodo(&aux->der->der->der->der->izq->der->izq->izq,-8);
  addNodo(&aux->der->der->der->der->izq->der->izq->izq->der,7);
  addNodo(&aux->der->der->der->der->izq->der->izq->izq->der->der,3);
  addNodo(&aux->der->der->der->der->izq->der->izq->izq->der->der->der,6);
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

int alturaArbol(arbol a){
  int nivelIzq, nivelDer;
  if (a){
    nivelIzq = alturaArbol(a->izq) + 1;
    nivelDer = alturaArbol(a->der);
    return (nivelIzq > nivelDer) ? nivelIzq : nivelDer;
  }
  else
    return 0;
}

// a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
int cantidadArbolesAlturaK(arbol a,int k){
  int aux = 0;
  while (a){
    if (alturaArbol(a->izq) + 1 >= k) // el +1 para contar el nivel de la raíz del arbol original (el nodo actual)
      aux++;
    a = a->der;
  }
  return aux;
}

// b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
int claveMayor(arbol a,int max){
  int maxIzq,maxDer;
  if (a){
    if (a->dato > max)
      max = a->dato;
    maxIzq = claveMayor(a->izq,max);
    maxDer= claveMayor(a->der,max);
    return (maxIzq > maxDer) ? maxIzq : maxDer;
  }
  else
    return max;
}

void generarVec(arbol a,int vec[],int * n){
  int aux;
  *n = -1;
  while (a){
    *n += 1;
    aux = claveMayor(a->izq,a->dato);
    vec[*n] = aux;
    a = a->der;
  }
  *n += 1;
}

// c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).
int recorrerArbolGradoK(arbol a,int k){ // muy mal nombre xd; no se me ocurre otra cosa
  if (a){
    return grado(a) == k || recorrerArbolGradoK(a->izq,k) || recorrerArbolGradoK(a->der,k);
  }
  else
    return 0;
}

int verifNodosGradoK(arbol a, int k) {
  int aux = 1;
  while (aux && a){
    if (grado(a) != k && recorrerArbolGradoK(a->izq,k) == 0)
      aux = 0;
    a = a->der;
  }
  return aux;
}
