#include <stdio.h>
#include <stdlib.h>

int consec(int a,int b,int c);
int main(){
  int a,b,c;
  printf("ingrese 3 numeros\n");
  scanf("%d %d %d",&a,&b,&c);
  if (consec(a,b,c))
    printf("numeros consecutivos %d %d %d \n",a,b,c);
  else
    printf("numeros no consecutivos %d %d %d",a,b,c);
  return 0;
}

int consec(int a,int b,int c){
  if (b-a==1 && c-b==1)
    return 1;
  else
    return 0;
}
