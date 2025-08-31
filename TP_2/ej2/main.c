#include <stdio.h>
#include <stdlib.h>

void ordenadas(int *x,int *y);

int main()
{
    int a,b;
    printf("Ingrese a y b\n");
    scanf("%d %d",&a,&b);
    printf("a=%d , b=%d \n",a,b);
    ordenadas(&a,&b);
    printf("valor de a %d\t valor de b %d\n",a,b);
    return 0;
}
void ordenadas(int *x,int *y){
  int aux;
  if (x>y){
    aux=*x;
    *x=*y;
    *y=aux
    ;
  }
}
