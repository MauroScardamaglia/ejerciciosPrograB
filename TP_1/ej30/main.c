/*
30. Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo (ANU7: alfanumérico de 7 caracteres), velocidad
registrada (entero positivo), velocidad máxima permitida (entero positivo), fecha y hora de la
medición (ANU16, formato aaaa/mm/dd hh:nn). Cada dato está separado por un espacio. El
programa debe generar un archivo binario con los registros donde la velocidad registrada
supere en más de un 20% a la velocidad máxima. Cada registro del archivo binario contiene los
mismos datos que el archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones
procesadas y la cantidad de registros generados en el archivo binario.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char patente[7]; // abc123 + '\o'
  unsigned int vel,velMax;
  char fecha[17]; // 16+'\0'
  } TReg;

void procesar();

int main()
{
    procesar();
    return 0;
}

void procesar(){
  FILE *arText,*arBinario;
  TReg reg;
  char patente[7], fecha[17];
  unsigned int vel,velMax,nText=0,nBinario=0;

  arText=fopen("radar.txt","rt");
  if (arText==NULL)
    printf("no se pudo abrir el archivo de texto");
  else{
    arBinario=fopen("multas.dat","wb");
    if (arBinario==NULL)
      printf("no se pudo abrir el archivo binario");
    else{
      while (!feof(arText)){
      fscanf(arText,"%s %u %u %s",patente,&vel,&velMax,fecha);
      nText++;
      if (vel>velMax*1.2){
        nBinario++;
        reg.vel=vel;
        reg.velMax=velMax;
        strcpy(reg.fecha,fecha);
        strcpy(reg.patente,patente);
        fwrite(&reg,sizeof(reg),1,arBinario);
      }
      }
      printf("Cantidad de mediciones total: %u \n Cantidad de mediciones grabadas %u",nText,nBinario);
    }
  }
}
