// pila estatica
#define MAX 100

typedef int TElementoP;

typedef struct {
  int datos[MAX];
  int tope; } TPila;

 void iniciaP(TPila *p);
 void poneP(TPila *p,TElementoP dato);
 void sacaP(TPila *p,TElementoP * dato);
 TElementoP consultaP(TPila p);
 int vaciaP(TPila p);
