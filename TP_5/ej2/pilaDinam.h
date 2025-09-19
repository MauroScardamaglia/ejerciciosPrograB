// pila dinámica (xd)

typedef char TElementoP;

typedef struct nodoP{
  TElementoP dato;
  struct nodoP * sig;
} nodoP;

typedef nodoP * TPila; // en esta implementación la pila es un puntero de por sí
                       // cuando se quiere cambiar su valor (a lo que apunta), se pasa por referencia (*TPila)
void iniciaP(TPila * p);
void poneP(TPila * p,TElementoP x);
void sacaP(TPila * p,TElementoP * x);
TElementoP consultaP(TPila p);
int vaciaP(TPila p);
