#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
/*
5. Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario  */

typedef struct nodo{
  int dato;
  struct nodo *izq, *der; } nodo;
typedef nodo * arbol;

typedef struct nodoCad{
  char cad[MAX];
  struct nodoCad *izq, *der; } nodoCad;
typedef nodoCad * arbolCad;

void addNodo(arbol * a,int x);
void carga(arbol *a);
void addNodoCad(arbolCad *a,char cad[]);
void cargaCad(arbolCad *aux);

void profundidad(arbol a,int * max,int nivel); // a)
void longestWord(arbolCad a,int * max); // b)
void cantHijosDer(arbol a,int * cant); // c) arbol numerico
void cantHijosDerCad(arbolCad a,int * cant); // c) arbol cadenas

int main()
{
  arbol a;
  arbolCad aCad;
  int maxNivel=0, maxLongitud = -1, cant=0, cantCad=0;

  carga(&a);
  cargaCad(&aCad);

  profundidad(a,&maxNivel,0);
  printf("Profundidad del arbol (nivel maximo): %d \n\n",maxNivel);
  printf("\n\n\n");

  longestWord(aCad,&maxLongitud);
  printf("\nEl string con mayor longitud tiene %d letras \n \n",maxLongitud);

  cantHijosDer(a,&cant);
  cantHijosDerCad(aCad,&cantCad);
  printf("\n\nCantidad de hijos derechos del arbol binario numerico: %d \n",cant);
  printf("Cantidad de hijos derechos del arbol binario de cadenas: %d \n",cantCad);

  return 0;
}

void addNodo(arbol * a,int x){
  *a = (arbol) malloc (sizeof(nodo));
  (*a)->dato = x;
  (*a)->izq = (*a)->der = NULL;
}

void addNodoCad(arbolCad *a,char cad[]){
  *a = (arbolCad) malloc (sizeof(nodoCad));
  strcpy((*a)->cad,cad);
  (*a)->izq = (*a)->der = NULL;

}

void carga(arbol * a){
  addNodo(a, 5);
  addNodo(&(*a)->izq, 8);
  addNodo(&(*a)->izq->izq, 3);
  addNodo(&(*a)->izq->der, 6);

  addNodo(&(*a)->der, 4);
  addNodo(&(*a)->der->izq, 1);
  addNodo(&(*a)->der->izq->der, 2);
// addNodo(&(*a)->der->izq->der->der, 15);
}

void cargaCad(arbolCad * aux){
  arbolCad a;
  addNodoCad(&a,"shingekiNoKyojin");
  addNodoCad(&a->izq,"Makima");
  addNodoCad(&a->izq->izq,"KendrickLamar");
  addNodoCad(&a->der,"aufWiedersehen");
  addNodoCad(&a->der->izq,"kaffee");
  addNodoCad(&a->izq->izq->der,"Duckworth");
  addNodoCad(&a->der->der,"tDagger");
  addNodoCad(&a->der->der->der,"tecnoBSucks");
  addNodoCad(&a->izq->der,"esteStringEsBastanteLargo");
  *aux = a;
}

void profundidad(arbol a,int * max,int nivel){ // a)
  if (a){
    nivel +=1;
    if (nivel > *max)
      *max = nivel;
    printf("%d  ",a->dato);
    profundidad(a->izq,max,nivel);
    profundidad(a->der,max,nivel);
  }
}

void longestWord(arbolCad a,int * max){ // b)
  if (a){
    int len = strlen(a->cad);
    printf("%s\n",a->cad);
    printf("%d\n",strlen(a->cad));

    if (len > *max) // si lo hacía sin variable auxiliar no cambiaba nunca el valor, por comparar distintos tipos (int y size_t) el int lo pasaba a unsigned int y hacía stack overflow (-1 --> 31239) entonces nunca un numero chiquito pasaba ese valor
      *max = strlen(a->cad);
    longestWord(a->izq,max);
    longestWord(a->der,max);
  }
}

void cantHijosDer(arbol a,int * cant){ // c) arbol numerico
  if (a){
    printf("%d\n",a->dato);
    cantHijosDer(a->izq,cant);
    if (a->der){
      *cant += 1;
      cantHijosDer(a->der,cant);
    }
  }
}

void cantHijosDerCad(arbolCad a,int * cant){ // c) arbol cadenas
    if (a){
    printf("%s\n",a->cad);
    cantHijosDerCad(a->izq,cant);
    if (a->der){
      *cant += 1;
      cantHijosDerCad(a->der,cant);
    }
  }


}
