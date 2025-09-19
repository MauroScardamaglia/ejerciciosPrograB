#include <stdio.h>
#include <stdlib.h>
#include "colaDinam.h"

int main()
{
  TCola c;
  TElementoC dato;
  // int nro;
  char res='s', opcion;

  iniciaC(&c);
  while (res=='s'){
    printf("Que opcion desea hacer? (c -> consulta, s-> sacar p-> poner) \n");
    scanf(" %c",&opcion); // scanf("opcion",&opcion); había puesto esto xd, estoy re quemado
    switch (opcion) {
    case 'c':
      if (!vaciaC(c)){
        dato = consultaC(c);
        printf("%d \n",dato);
      }
      else
        printf("Cola vacia\n");
    break;
    case 's':
      if (!vaciaC(c)){
        sacaC(&c,&dato);
        printf("%d \n",dato);
      }
      else
        printf("cola vacia \n");
    break;
    case 'p':
      printf("Ingrese numero \n");
      scanf("%d",&dato);
      poneC(&c,dato);
    break;
    default:
      printf("Opcion indeterminada \n");
    }
    printf("Desea continuar (s/n)? \n");
    scanf(" %c",&res);
  }

  return 0;
}
