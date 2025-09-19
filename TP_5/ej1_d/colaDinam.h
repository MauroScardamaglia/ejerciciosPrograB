typedef int TElementoC;

typedef struct nodo{
  TElementoC dato;
  struct nodo *sig;
} nodo;

typedef struct{
  nodo * pri, * ult;
} TCola;


void iniciaC(TCola * c);

void poneC(TCola * c,TElementoC x);

void sacaC(TCola * c,TElementoC * x);

TElementoC consultaC(TCola c);

int vaciaC(TCola c);
