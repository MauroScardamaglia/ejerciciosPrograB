#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

void iniciar(TAgenda * agenda){
  agenda->n=-1; // <-> (*agenda).n = -1;
}

void agregar(TAgenda * agenda,char nombre[MAX_CHAR],char telefono[MAX_CHAR]){
  if (agenda->n < MAX_CONTAC -1){
    agenda->n ++;
    strcpy(agenda->contactos[agenda->n].nombre,nombre);
    strcpy(agenda->contactos[agenda->n].telefono,telefono);
  }
  else
    printf("Agenda de contactos llena \n");
}

void listar(TAgenda * agenda){
  int i;
  for (i=0;i<= agenda->n;i++)
    printf("%s \n %s \n \n",agenda->contactos[i].nombre,agenda->contactos[i].telefono);
  printf("\n \n");
}

void buscar(TAgenda agenda,char nombre[MAX_CHAR],char telefono[MAX_CHAR]){
  int i=0;
  while (strcmp(agenda.contactos[i].nombre,nombre) && i<=agenda.n)
    i++;
  if (i<= agenda.n)
    strcpy(telefono,agenda.contactos[i].telefono);
  else
    printf("No se encontro el nombre ingresado \n");
}
