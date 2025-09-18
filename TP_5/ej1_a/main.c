#include <stdio.h>
#include <stdlib.h>
#include "pilaEst.h"

int main()
{
  char res='s';
  TPila p;
  int x;
  TElementoP k; // el llamado a una funcion de tda es con el tipo de elemento del tda,
  iniciaP(&p);  // se puede leer en el main como int (o el dato primitivo) y asignarle a un telementop ese valor
  while (res=='s'){
    printf("Ingrese numero \n");
    scanf("%d",&x);
    k=x;
    poneP(&p,k);
    printf("Desea guardar otro dato? (s/n) \n");
    scanf(" %c",&res);
  }
  res='s';
  while (res=='s' && !vaciaP(p)){
    sacaP(&p,&k);
    printf("%d \n",k);
    printf("Desea sacar otro dato? (s/n) \n");
    scanf(" %c",&res);
  }
  if (vaciaP(p))
    printf("Pila vacia \n");
  return 0;
}
