#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,sum=0;
    do{
        printf("Ingrese numero a sumar, 0 si desea finalizar \n");
        scanf("%d",&a);
        printf("\n");
        sum+=a;
    } while (a!=0);
    printf("La suma es %d \n",sum);
    return 0;
}
