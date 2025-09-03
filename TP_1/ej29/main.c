#include <stdio.h>
#include <stdlib.h>

/*
    29. Un sensor de temperatura realiza mediciones periódicas (una cada 5 segundos). Las mismas son
    registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
    programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
    temperatura promedio, máxima y mínima.
*/
void cargaBinaria();
void lecturaBinaria();

int main()
{
  cargaBinaria();
  lecturaBinaria();
  return 0;
}

void cargaBinaria(){
  float num;
  FILE *archText, *archBinario;

  archText=fopen("temperaturas.txt","rt");
  if (archText==NULL)
    printf("No se pudo abrir archivo de texto \n");
  else{
    archBinario=fopen("temperaturas.dat","wb");
    if (archBinario==NULL)
      printf("No se pudo abrir archivo binario\n");
    else{
      while (!feof(archText)){
        fscanf(archText,"%f",&num);
        fwrite(&num,sizeof(float),1,archBinario);
      }
      fclose(archBinario);
    }
    fclose(archText);
  }
}

void lecturaBinaria(){
  FILE *archBinario;
  float num,acum=0,prom,min=5500,max=-274; //-273.15 es el cero absoluto 5500 es la temperatura de la superficie del sol
  int n=0;

  archBinario=fopen("temperaturas.dat","rb");
  if (archBinario==NULL)
    printf("No se pudo abrir el archivo binario \n");
  else{
    fread(&num,sizeof(float),1,archBinario);
    while(!feof(archBinario)){
      acum+=num;
      n++;
      if (num<min)
        min=num;
      else
        if (num>max)
          max=num;
      fread(&num,sizeof(float),1,archBinario); // lectura adelantada ya que es un archivo binario
    }
    fclose(archBinario);
    if (n==0)
      prom=0;
    else
      prom=acum/n;
    printf("El promedio de temperatura es %6.2f\n Con un minimo de %6.2f\n Un maximo de %6.2f\n se tomaron %d muestras\n",prom,min,max,n);
  }
}
