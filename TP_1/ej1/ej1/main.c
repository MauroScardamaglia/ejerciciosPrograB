#include <stdio.h>
#include <stdlib.h>

int main(){
  char caracter='a';
  int entero=8;
  long int enteroLargo=99999;
  unsigned int enteroPositivo=278;
  float real=13.476;
  double doble=17.981923;

  printf("caracter: %C , cantidad de bytes: %d \n" , caracter, sizeof(char)); // %d,c,f, etc funciona con mayúscula tmb
  printf("entero: %d , cantidad de bytes: %d \n" , entero, sizeof(int));
  printf("long int: %d , cantidad de bytes: %d \n" , enteroLargo, sizeof(long int));
  printf("unsigned int: %u , cantidad de bytes: %d \n" , enteroPositivo, sizeof(unsigned int));
  printf("real: %f , cantidad de bytes: %d \n" , real, sizeof(float));
  printf("double: %f , cantidad de bytes: %d \n" , doble, sizeof(double));

  printf("gracias vuelvas prontos \n \n");
  printf("dale andate");
  return 0;
}
