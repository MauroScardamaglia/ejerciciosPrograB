/*
31. El ranking de una asociación de tenistas es registrada en un archivo binario. Para cada jugador
se registra apellido y nombre, nacionalidad y puntaje. Realizar un subprograma que muestre los
datos del jugador ubicado en una posición recibida como parámetro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMBRE 25
#define MAX_NACIONALIDAD 20


typedef struct{
  char nombre[MAX_NOMBRE];
  char nacionalidad[MAX_NACIONALIDAD];
  unsigned int puntaje; } TReg;

void cargaBinaria();
void lecturaBinariaPosX(unsigned int x);

int main(){
  unsigned int x;
  // TReg reg;
  // printf("treg %u \n reg %u \n \n",sizeof(TReg),sizeof(reg)); // estaba probando algo
  printf("Que posicion desea obtener? \n");
  scanf("%u",&x);
  cargaBinaria();
  lecturaBinariaPosX(x);
  return 0;
}

void cargaBinaria(){
  FILE *arText, *arBinario;
  TReg reg;
  char nombre[MAX_NOMBRE], nacionalidad[MAX_NACIONALIDAD];
  unsigned int puntaje;

  arText=fopen("tenistas.txt","rt");
  if (arText==NULL)
    printf("No se pudo abrir el archivo de texto \n");
  else{
    arBinario=fopen("tenistas.dat","wb");
    if (arBinario==NULL)
      printf("No se pudo abrir el archivo binario \n");
    else{
      while (!feof(arText)){
        fscanf(arText,"%s %s %u",nombre,nacionalidad,&puntaje);
        strcpy(reg.nombre,nombre);
        strcpy(reg.nacionalidad,nacionalidad);
        reg.puntaje=puntaje;
        fwrite(&reg,sizeof(TReg),1,arBinario);
      }
      fclose(arBinario);
    }
  fclose(arText);
  }
}

void lecturaBinariaPosX(unsigned int x){
  FILE * arBinario;
  TReg reg;

  arBinario=fopen("tenistas.dat","rb");
  if (arBinario==NULL)
    printf("No se pudo abrir el archivo binario \n");
  else{
    fseek(arBinario,x*sizeof(TReg),SEEK_SET); // SEEK_SET -->0
    fread(&reg,sizeof(TReg),1,arBinario);
    printf("Jugador %u: %s \n nacionalidad: %s \n Puntaje: %d \n",x,reg.nombre,reg.nacionalidad,reg.puntaje);
    fclose(arBinario);
  }
}
