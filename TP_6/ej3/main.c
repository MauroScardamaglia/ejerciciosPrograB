#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
3. Escribir un programa que lea desde un archivo un texto que contiene una cantidad desconocida
de palabras (una en cada línea) y genere una lista ordenada de todas las palabras existentes en
el texto con su frecuencia de aparición.
*/

typedef char st20[21];

typedef struct nodo{
  st20 palabra;
  int frequencia;
  struct nodo * sig; } nodo;

typedef nodo * TLista;

void cargaListaStrings(TLista * l);
void mostrarLista (TLista l);

int main()
{
  TLista l;
  cargaListaStrings(&l);
  mostrarLista(l);
  return 0;
}

void mostrarLista (TLista l){
  while (l){
    printf("%s  %d \n",l->palabra,l->frequencia);
    l = l->sig;
  }
  printf("\n \n");
}

void cargaListaStrings(TLista *l ){
  FILE * arch;
  TLista act,ant,nuevo;
  st20 dato;
  *l = NULL;
  arch = fopen("strings.txt","rt");
  if (!arch)
    printf("El archivo no pudo abrirse \n");
  else{
    while (!feof(arch)){
      fscanf(arch,"%s",dato);
      if (!*l || strcmp(dato,(*l)->palabra) < 0){ // ! y * misma precedencia; asociatividad derecha a izquierda == !(*l)      *l --> !
        nuevo = (TLista) malloc (sizeof(nodo)); // es mejor usar < > = 0 en el strcmp porque no todas las implementaciones usan -1,0,1
        strcpy(nuevo->palabra,dato);
        nuevo->frequencia = 1;
        nuevo->sig = *l;
        *l = nuevo;
      }
      else{ // no se modifica la cabecera
        ant = *l;
        act = (*l)->sig;
        while (act && strcmp(dato,act->palabra) > 0){
          ant = act;
          act = act->sig;
        }
        if (act && strcmp(dato,act->palabra) == 0) // 3er caso, la palabra ya existe
          act->frequencia ++;
        else{
          nuevo = (TLista) malloc (sizeof(nodo));
          strcpy(nuevo->palabra,dato);
          nuevo->frequencia = 1;
          nuevo->sig = ant->sig;
          ant->sig = nuevo;
        }
      } // cierra rama no se modifica la cabecera
    } // cierra while(!feof(arch))
    fclose(arch);
  } // cierra rama (arch)
} // cierra procedimiento
