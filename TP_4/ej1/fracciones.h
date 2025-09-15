/*
1. Realizar un TDA para n�meros fraccionarios, es decir aquellos que se expresan como el
cociente de dos n�meros enteros. Las operaciones que deber� soportar el TDA son:
- crear(entero numerador, entero denominador) retorna fracci�n.
- numerador(fracci�n f) retorna entero.
- denominador(fracci�n f) retorna entero.
- sumar(fracci�n f1, fracci�n f2) retorna fracci�n.
- restar(fracci�n f1, fracci�n f2) retorna fracci�n.
- multiplicar(fracci�n f1, fracci�n f2) retorna fracci�n.
- dividir(fracci�n f1, fracci�n f2) retorna fracci�n.
- simplificar(fracci�n f) retorna fracci�n simplificada.
- iguales(fracci�n f1, fracci�n f2) retorna verdadero o falso.
*/

typedef struct {
  int numerador, denominador;
} TFracc;

TFracc crear(int num,int denom);
int numerador(TFracc fraccion);
int denominador(TFracc fraccion);
TFracc sumar(TFracc fraccion1,TFracc fraccion2);
TFracc restar(TFracc fraccion1,TFracc fraccion2);
TFracc multiplicar(TFracc fraccion1,TFracc fraccion2);
TFracc dividir(TFracc fraccion1,TFracc fraccion2);
TFracc simplificar(TFracc fraccion);
int iguales(TFracc fraccion1,TFracc fraccion2);
void mostrar(TFracc fraccion);
