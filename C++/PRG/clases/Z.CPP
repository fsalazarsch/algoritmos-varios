#include "stdlib.h"
#include "dos.h"
#include "string.h"
#include "ctype.h"
#include "iostream.h"
#include "conio.h"
#include "stdio.h"
typedef struct NODO;
//Estructura de la Lista.
struct NODO {
     long codigo;
     char nombre[20];
     char apelli[30];
     float cedula;
     int curso;
//Declaro un Apuntador para siguiente.
     NODO *sig;
};
//Constructor para declarar los apuntadores.
class ESTUD {
      struct NODO *cab, *p, *q, *r, *nuevo;
//Funciones Miembros.
public:
      ESTUD(){cab=p=q=NULL;}
      void crear();
      void inserin();
      void inserfin();
      void eliminar();
      void consultar();
      void imprimir();
     // ~ESTUD();
};
void cuadro(int x1, int y1, int x2, int y2);
// Procedimiento para Crear o iniciar la lista.
void ESTUD::crear() {
    int codigo, curso;
    float cedula;
    char nombre[20], apelli[30];
      clrscr();
      gotoxy(2,4);cout<<"Digite Codigo"<<endl;
      gotoxy(20,4);cin>>codigo;
      gotoxy(2,6);cout<<"Digite Nombre"<<endl;
      gotoxy(20,6);cin>>nombre;
      gotoxy(2,8);cout<<"Digite Apellido"<<endl;
      gotoxy(20,8);cin>>apelli;
      gotoxy(2,10);cout<<"Digite Cedula"<<endl;
      gotoxy(20,10);cin>>cedula;
      gotoxy(2,12);cout<<"Digite Curso"<<endl;
      gotoxy(20,12);cin>>curso;
      p=new NODO;
      p->codigo=codigo;
      strcpy(p->nombre,nombre);
      strcpy(p->apelli,apelli);
      p->cedula=cedula;
      p->curso=curso;
       p->sig=NULL;

	if (cab==NULL)
	{  cab=p;
	   cab->sig=NULL;
	}
	else
	{  q=cab;
	    while (q->sig!=NULL)
	      q=q->sig;
	      q->sig=p;
	      q=p;
	 }
	  getch();
  }
// Procedimiento para Insertar Nodo al inicio de la lista.
void ESTUD::inserin() {
     char nombre[20], apelli[30];
     int codigo, curso;
     float cedula;
     char res= 's';
     do {
     p = cab;
     clrscr();
     while (p != NULL){
       gotoxy(2,4);cout<<"Digite el Codigo a Insertar"<<endl;
       gotoxy(35,4);cin>>codigo;
       gotoxy(2,6);cout<<"Nombre"<<endl;
       gotoxy(15,6);cin>>nombre;
       gotoxy(2,8);cout<<"Apellido"<<endl;
       gotoxy(15,8);cin>>apelli;
       gotoxy(2,10);cout<<"Cedula"<<endl;
       gotoxy(15,10);cin>>cedula;
       gotoxy(2,12);cout<<"Curso"<<endl;
       gotoxy(15,12);cin>>curso;

       p->codigo=codigo;
      strcpy(p->nombre,nombre);
      strcpy(p->apelli,apelli);
      p->cedula=cedula;
      p->curso=curso;

     }
      nuevo = new NODO;
      nuevo->sig = cab;
      cab = nuevo;
       cout<<"Desea Continuar Insertando al Inicio? s/n";
      fflush(stdin);
      res=toupper(getch());
      } while (res=='s');
 }
 //Procedimiento que Permite Imprimir la Lista Creada.
void ESTUD::imprimir(){
   int b=4;
   clrscr();
   q=cab;
   clrscr();
   while(q!=NULL)
   {
      gotoxy(2,2);cout<<"Codigo      Nombre      Apellido      Cedula      Curso ";
      gotoxy(2,b);cout<<q->codigo;
      gotoxy(16,b);cout<<q->nombre;
      gotoxy(30,b);cout<<q->apelli;
      gotoxy(49,b);cout<<q->cedula;
      gotoxy(60,b);cout<<q->curso;
       q=q->sig;
       b++;
     }
};
 //Eliminar un Nodo dado.
/* void ESTUD::eliminar(){
       q = cab;
       while (p->sig != NULL){
	 cout<<"Digite Codigo del Nodo a Eliminar";
	 cin>>p->codigo;

     }
 }
   cout<<"No Existe el Codigo a Eliminar";
    }*/

void main ()
    {
     ESTUD ob; char op;
do
 {
  clrscr();
  cuadro(30,4,60,12);
  gotoxy(33,5);cout<<" MENU PRINCIPAL";
  gotoxy(35,7);cout<<" 1: CREAR..........."<<endl;
  gotoxy(35,8);cout<<" 2: INSERIN........."<<endl;
  gotoxy(35,9);cout<<" 3: INSERFIN........"<<endl;
  gotoxy(35,10);cout<<"4: ELIMINAR........"<<endl;
  gotoxy(35,11);cout<<"5: CONSULTAR......."<<endl;
  gotoxy(35,12);cout<<"6: IMPRIMIR........"<<endl;
  gotoxy(35,13);cout<<"7: SALIR..........."<<endl;
  gotoxy(35,20);cout<<"DIGITE OPCION......";
  op=getch();
  switch(op)
  {
     case '1':ob.crear();break;
     case '2':ob.inserin();break;
     case '3':ob.inserfin();break;
     case '4':ob.eliminar();break;
     case '5':ob.consultar();break;
     case '6':ob.imprimir();break;
  }
 } while(op!=7);
   }
 void cuadro(int x1, int   y1, int x2, int y2)
 {
   int i;
   for(i=x1;i<=x2;i++)
   {
    gotoxy(i,y1);cout<<"ß";
    gotoxy(i,y2);cout<<"Ü";
    delay(5);
   }
   for(i=y1;i<=y2;i++)
   {
    gotoxy(x1,i);cout<<"Û";
    gotoxy(x2,i);cout<<"Û";
    delay(5);
   }
}





