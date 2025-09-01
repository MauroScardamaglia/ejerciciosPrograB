#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
26. Declarar un tipo struct para almacenar nombre, matrícula y promedio de un alumno.
Desarrollar una función que realice lectura de una variable del tipo creado.
*/

typedef struct {
  char nombre[21];
  int matricula;
  float prom; } TReg;

void leerRegistro(TReg *reg);
int main()
{
  TReg reg;
  leerRegistro(&reg);
  printf("\n nombre: %s \n matricula: %d \n Promedio: %6.2f \n",reg.nombre,reg.matricula,reg.prom);
  return 0;
}

void leerRegistro(TReg *reg){
  printf("Ingrese nombre \n");
  scanf("%s",(*reg).nombre);
  printf("Ingrese matricula \n");
  scanf("%d",&reg->matricula);
  printf("Ingrese promedio \n");
  scanf("%f",&(*reg).prom);
}
