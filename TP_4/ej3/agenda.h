/* 3. Desarrollar una agenda de contactos mediante un TDA. Para cada contacto se almacena
nombre y tel�fono. Los contactos deben estar ordenados alfab�ticamente. El TDA debe contar
con los siguientes operadores: iniciar agenda, agregar contacto, listar agenda, buscar por
nombre (b�squeda lineal).
Se solicitan dos implementaciones diferentes: una con arreglos paralelos y otra con arreglo de
registros.
Mejorar el operador buscar por nombre, recodific�ndolo como b�squeda binaria.
*/

#define MAX_CHAR 30
#define MAX_CONTAC 150


typedef struct{
  char nombre[MAX_CHAR];
  char telefono[MAX_CHAR];
} TContacto;

typedef struct{
  TContacto contactos[MAX_CONTAC];
  int n;
} TAgenda;

void iniciar(TAgenda * agenda);

void agregar(TAgenda * agenda,char nombre[MAX_CHAR],char telefono[MAX_CHAR]);

void listar(TAgenda * agenda);

void buscar(TAgenda agenda,char nombre[MAX_CHAR],char telefono[MAX_CHAR]);


