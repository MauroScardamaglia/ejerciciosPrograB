/*
3. Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y teléfono. Los contactos deben estar ordenados alfabéticamente. El TDA debe contar
con los siguientes operadores: iniciar agenda, agregar contacto, listar agenda, buscar por
nombre (búsqueda lineal).
Se solicitan dos implementaciones diferentes: una con arreglos paralelos y otra con arreglo de
registros.
Mejorar el operador buscar por nombre, recodificándolo como búsqueda binaria.
*/

#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

void cargaAgenda(TAgenda * agenda);

int main()
{
  TAgenda agenda;
  char nombre[MAX_CHAR], telefono[MAX_CHAR];

  iniciar(&agenda);
  cargaAgenda(&agenda);
  listar(&agenda);

  printf("Ingrese nombre y telefono \n");
  scanf("%s %s",nombre,telefono);
  agregar(&agenda,nombre,telefono);
  listar(&agenda);

  printf("Ingrese nombre \n");
  scanf("%s",nombre);
  buscar(agenda,nombre,telefono);
  printf("el telefono de %s es %s \n",nombre,telefono);

  return 0;
}

void cargaAgenda(TAgenda * agenda){
  FILE * arch;
  int n,i;

  arch=fopen("contactos.txt","rt");
  if (arch==NULL)
    printf("NO se pudo abrir el archivo \n");
  else{
    fscanf(arch,"%d",&n);
    for (i=0;i<n;i++)
      fscanf(arch,"%s %s",agenda->contactos[i].nombre,agenda->contactos[i].telefono);
    agenda->n=n-1;
    fclose(arch);
  }
}
