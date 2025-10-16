#include <stdio.h>
#include <stdlib.h>
/*
3. Desarrollar funciones para:
a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
b) retornar la cantidad de hojas de un árbol binario.
c) informar si un valor recibido como parámetro se encuentra en un árbol binario.

*/

typedef struct nodo{
  int dato;
  struct nodo * izq, * der; } nodo;

typedef nodo * arbol;

void addNodo(arbol * a,int x);

void sumaMultiplos3(arbol a,int * suma); // a)
void cantHojas(arbol a,int * cant); // b)
int encontrarX(arbol a,int x,int *cantNodos); // c) --- Acabo de cometer un atentado contra la programación estructurada,
// me siento un ser libre (estaba probando algo nomás xd)


int main()
{
  arbol a;
  int suma = 0,cant = 0,valor,cantNodos = 0;

  addNodo(&a,5);
  addNodo(&a->izq,8);
  addNodo(&a->der,4);
  addNodo(&a->izq->izq,3);
  addNodo(&a->izq->der,6);
  addNodo(&a->der->izq,1);
  addNodo(&a->der->izq->der,2);
/*
  addNodo(&a->izq->der->der,12);
  addNodo(&a->der->izq->der->der,-6);
  addNodo(&a->der->izq->izq,3);
*/

  printf("a) \n");
  sumaMultiplos3(a,&suma);
  printf("La suma de los multiplos de 3 es %d \n\n",suma);

  printf("b) \n");
  cantHojas(a,&cant);
  printf("La cantidad de hojas del arbol es %d \n\n",cant);

  printf("c)\n");
  printf("Ingrese valor entero \n");
  scanf("%d",&valor);
  printf("El valor %d ",valor);
  if (encontrarX(a,valor,&cantNodos))
    printf("Se encuentra \n");
  else
    printf("No se encuentra \n");
  printf("Nodos recorridos: %d \n",cantNodos);
  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void sumaMultiplos3(arbol a,int * suma){ // a)
  if (a){
    if (a->dato % 3 == 0)
      *suma += a->dato;
    sumaMultiplos3(a->izq,suma);
    sumaMultiplos3(a->der,suma);
  }
}

void cantHojas(arbol a,int * cant){ // b)
  if (a)
    if (a->izq == NULL && a->der == NULL) // sandra prefiere esta forma en vez de !a->izq && !a->der
      *cant += 1;
    else { // uso += para no usar (*cant)++
      cantHojas(a->izq,cant);
      cantHojas(a->der,cant);
    }
}

int encontrarX(arbol a,int x,int * cantNodos){ // c)
  if (a){
    *cantNodos += 1;
    return a->dato == x || encontrarX(a->izq,x,cantNodos) || encontrarX(a->der,x,cantNodos) ;
  }
  else
    return 0;
}

