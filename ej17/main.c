#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1[4]={3};
    int v2[5]={6};
    int v3[]={2,4,6};

    char s1[4] = {'h','o','y'};
    char s2[] = {'h','o','y'};
    char s3[4]= {'h','o','y','\0'};

    printf("1°\n%s\n",s1);
    printf("2°\n%s\n",s2);
    printf("3°\n%s\n",s3);

    return 0;
}
