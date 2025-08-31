#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b)? a:b
#define alf(a) (a>='a' && a<='z' || a>='A' && a<='Z')

int main()
{
  int a,b;
  char c;
  printf("ingrese 2 numeros \n");
  scanf(" %d  %d",&a,&b);
  printf("el maximo entre %d y %d es %d \n",a,b,max(a,b));
  printf("ingrese un caracter \n");
  scanf(" %c",&c);
  if (alf(c))
    printf("caracter alfabetico\n");
  else
    printf("caracter no alfabetico \n");

    return 0;
}
