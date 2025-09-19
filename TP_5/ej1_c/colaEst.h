#define MAX 200

typedef int TElementoC;

typedef struct {
  TElementoC datos[MAX];
  int pri, ult;
 } TCola;

void iniciaC(TCola * c);
void poneC(TCola * c,TElementoC x);
void sacaC(TCola * c,TElementoC * x);
TElementoC consultaC(TCola c);
int vaciaC(TCola c);
