#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1,b=2,c=3,d=4;
    printf("%d\n", a+b*c/d);
    printf("%d\n",(a+b)*c%d);

    d--;
    if (d<65 && 3==d)
        printf("yes");
    else
      printf("nop");


    return 0;
}
