#include <stdio.h>
#include <stdlib.h>
#define num 15

int main()
{
 int enterito=15;

 printf("enterito en forma caracter %c \n",enterito); // no funca
 enterito += 'A';
 printf("enterito %d \n",enterito); // le suma el valor ascii

 printf("aa %d \n", num);
 printf("bb %c \n", num);

    return 0;
}
