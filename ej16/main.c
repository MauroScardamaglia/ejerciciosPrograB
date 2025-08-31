#include <stdio.h>
#include <stdlib.h>

void pasaje(int *horas,int *mint,int *seg);
int main(){
  int horas, min, seg;
  printf("ingrese cantidad de segundos \n");
  scanf("%d",&seg);
  pasaje(&horas,&min,&seg);
  printf("%d horas %d minutos %d segundos \n",horas,min,seg);
  return 0;
}

void pasaje(int *horas,int *min,int *seg){
  int aux;
  aux= *seg - *seg % 60;
  *seg%=60;
  aux/=60;
  *horas=(aux-aux%60)/60;
  *min=aux%60;
}
