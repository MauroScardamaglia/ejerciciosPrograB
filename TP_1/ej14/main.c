#include <stdio.h>
#include <stdlib.h>

void funcSquare(unsigned int n);

int main(){
  unsigned int n;
  printf("Ingrese numero de numerales por lado \n");
  scanf("%d",&n);
  printf("\n");
  funcSquare(n);
  return 0;
}

void funcSquare(unsigned n){
  unsigned int i,j;
  for (i=1;i<=n;i++)//{
  if (i==1 || i==n){
    for (j=1;j<=n;j++)
      printf("#");
    printf("\n");
  }
  else{
    printf("#");
    for (j=2;j<n;j++)
        printf(" ");
    printf("#");
    printf("\n");
  }
  //}
  }



