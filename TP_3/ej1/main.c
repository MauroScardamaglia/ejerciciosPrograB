/*
1. Desarrollar funciones (algunas pueden ser void) para:
a) calcular el producto de dos números enteros positivos a partir de sumas sucesivas.
b) calcular cociente y resto entre dos números enteros positivos a partir de restas sucesivas
c) hallar el máximo elemento de un vector de enteros (realizar una versión void y otra int)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TVec[MAX];

unsigned int producto(unsigned int  a,unsigned int b);

void division(unsigned int a, unsigned int b, unsigned int * cociente, unsigned int * resto);

void cargaVec(TVec vec,unsigned short int * n);

unsigned short int funcionMaxElemVector(TVec vec,unsigned short int n); // aunque vec sea un puntero, como no se modifica se puede considerar como parámetro de valor y hacer funcion en vez de procedimiento
void procedimientoMaxElemVector(TVec vec,unsigned short int i,unsigned short int * max);
// en este caso no se puede hacer sobrecarga de funciones ya que son de <> tipo

int main(){
  unsigned int a,b, res, cociente, resto;
  TVec vec;
  unsigned short int n,max;


  printf("Ingrese a y b \n");
  scanf("%u %u",&a,&b);

  // a)
  if (a>b)
    res=producto(a,b);
  else
    res=producto(b,a);
  printf("El producto entre %u y %u es %u \n",a,b,res);

  // b)
  cociente=0;
  division(a,b,&cociente,&resto);
  printf("La division entre %u y %u deja como cociente %u y como resto %u \n",a,b,cociente,resto);
  printf("\n\n");

//  printf("%u",sizeof(unsigned short int));  --> 2 <--

  // c)
  cargaVec(vec,&n);
  max=n-1; // necesita un valor inicial para comparar, puedo darle un valor limite tipo -99999 pero me parece mejor así y la función recursiva se ahorra un llamado
  max=funcionMaxElemVector(vec,n-2);
  printf("El componente [%u]= %d es el componente con el valor maximo \n \n",max,vec[max]);

  max=n-1;
  procedimientoMaxElemVector(vec,n-2,&max);
  printf("El componente [%u]= %d es el componente con el valor maximo \n \n",max,vec[max]);

  return 0;
}

unsigned int producto(unsigned int a, unsigned int b){
  if (b==0)
    return 0;
  else
    return a + producto(a,b-1);
}

void division(unsigned int a, unsigned int b, unsigned int * cociente, unsigned int * resto){
  if (a<b)
    *resto=a;
  else
    if (a==b){
      *resto=0;
      (*cociente)++;
    }
    else{ // a>b
      (*cociente)++;
      division(a-b,b,cociente,resto);
    }
}

void cargaVec(TVec vec,unsigned short int * n){
  unsigned short int i;
  printf("Ingrese cantidad de componentes del vector \n");
  scanf("%u",n);
  for (i=0;i<*n;i++){
    printf("[%u]= ",i);
    scanf("%u",vec+i); // aritmética de punteros, es menos legible, pero por variar un poco
  }
}

unsigned short int funcionMaxElemVector(TVec vec,unsigned short int i){ // un parametro más no ocupa tanto (2 bytes por llamada en este caso), entonces podría usar un parametro
  unsigned short int aux;                                        // que fuera la posición inicial del vector (i=0); pero me parece bastante en vano
  if (i==0)
    return i; // <-> 0 (equivale a 0)
  else{
    aux=funcionMaxElemVector(vec,i-1);
    if (vec[i]>vec[aux])
      return i;
    else
      return aux; // compara a la vuelta
  }
}

void procedimientoMaxElemVector(TVec vec,unsigned short int i, unsigned short int * max){ // este procedimiento (void) compara a la ida
  if (i>=0){ // caso base implicito, si i<0 no hace nada el procedimiento
    if (vec[i]>vec[*max])
      *max=i;
  }             // la verdad que esta funcion (prodecimiento) es bastante más compacta
}
