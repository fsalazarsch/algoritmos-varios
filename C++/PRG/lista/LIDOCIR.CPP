//listas doblemente enlazadas
//consta de insertar borrar visualizar
#include <studio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define listavacia (listaD->princ == NULL)
typedef struct datos elemento;//tipo elemento
typedef elemento *pelemento;//tipo puntero a un elemento
struct datos //estructura de un elemento de la lista
	 {
	 char calve[12];
	 pelemento sig;
	 pelemento ant;
	 };
	 typedef struct lista listDob;
	 struct lista
	 {
	  pelemento princ; //principio de la lista
	  pelemento final; //final de la lista
	  };
//**************FUNCIONES************************************
void error(void)
      {
      error("error: insuficiente espacio de memoria");
      exit(1);
      }
pelemento NuevoElemento()
      {
      pelemento q=(pelemento)malloc(sizof(elemento));
      if (!q) error();
      return(q);
      }
void insertar(ListDob *, char []);
void borrar(ListDob *, char []);
void visualizar_lista(ListDob);
void menu(void);
//****************PROGRAMA PRINCIPAL**************************
main()
    {
     clrscr();
     ListDob listaD;
     char opcion, clave[12];

     listD.princ = listD.final = NULL; //lista vacia
     while (1)
       {
	do
	 {
	  system("cls");
	  menu();
	  opcion = toupper(getche());
	  }
	  while (opcion

