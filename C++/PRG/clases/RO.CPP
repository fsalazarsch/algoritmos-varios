#include "iostream.h"
#include "conio.h"
#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "dos.h"
#include "stdlib.h"
#include "alloc.h"

struct datos{ //Esta es laestructura de los datos que  contendr  la lista
      char nombres[25];
      char apellidos[25];
      int codigo;
      char curso;
      long cedula;
      datos *sig;/*Declaramos datos para que apunte a siguiente*/};

class nombres{ //Contruimos un constructor en donde declaramos los apuntador
    struct datos  *cab,*p,*q;
public: // Creacion de las funciones miembros
    nombres(){cab=NULL;}
    void crear(int co);   //Procedimiento que crea una lista y permite adiocionar datos
    void recorrer(int co);//
    void eliminar(int co);

};
void nombres::eliminar(int co){
clrscr();char R;
gotoxy(29,5);cout << "PROCEDIMIENTO ELIMINAR";
gotoxy(29,7);cout << "Esta seguro de querer liberalo S/N .. ";
cin >> R;
if (toupper(R)=='S')
{if (co==cab->codigo)
   {p=cab;
    cab=p->sig;
    free(p);
    gotoxy(29,10);cout << "Codigo Eliminado";
   }
 else
  {q=cab;p=q->sig;
   while (p->sig!=NULL){q=p;p=p->sig;}
   if (co==p->codigo)
     {q->sig=NULL;
      free(p);
      gotoxy(29,10);cout << "Codigo Eliminado";
     }
   else
   {q=cab;p=q->sig;
    while (co!=p->codigo || p==NULL){q=p;p=p->sig;}
    if (co==p->codigo)
      {q->sig=p->sig;
       free(p);
       gotoxy(29,10);cout << "Codigo Eliminado";
      }
    else
    {gotoxy(29,10);cout << "Codigo Inexistente";getch();}
   }
  }
}
getch();
}

void nombres::recorrer(int co){
clrscr();p=cab;
gotoxy(29,5);cout << "PROCEDIMIENTO RECORRER";
for (int i=1;i<=co;i++){
  gotoxy(6,i+6);
  cout <<i<<" Nombres "<<p->nombres<<", Apellidos "<<p->apellidos<<", Codigo "<<p->codigo<<", Curso "<<p->curso<<", Cedula "<<p->cedula<<"\n";
  p=p->sig;
  }
getch();

}

void nombres::crear(int co){
   clrscr();int i;
/*   gotoxy(24,2);cout << "Digite cuantos va a ingresar...";
   cin >> co;*/
for (i=1;i<=co;i++)
  {p = new /*struct*/ datos;
//   char nombres[20]; char apellidos[20];
//   int codigo; char curso; float cedula;
   clrscr();
   gotoxy(23,5);cout << "PROCEDIMIENTO DE CREAR Y ADICIONAR";
   gotoxy(28,7);cout << "Digite los Nombres...";
   cin >> p->nombres;
   gotoxy(28,8);cout << "Digite Apellidos...";
   cin >> p->apellidos;
   gotoxy(28,9);cout << "Digite un Codigo...";
   cin >> p->codigo;
   gotoxy(28,10);cout << "Digite Curso...";
   cin >> p->curso;
   gotoxy(28,11);cout << "Digite Cedula...";
   cin >> p->cedula;
   if (cab==NULL){cab=p; q=p;} else {q->sig=p; q=p;}
   clrscr();
   }

}

main (){int res;nombres X;
do{  clrscr();
     gotoxy(5,2);cout << "1. Crear y adicionar";
     gotoxy(32,2);cout << "2. Recorrer";
     gotoxy(47,2);cout << "3. Eliminar";
     gotoxy(65,2);cout << "4. Salir";

     gotoxy(23,4);cout << "Digite su opci¢n ...\n";
     gotoxy(48,4);cin >> res;
     int n;

     switch(res)
     {case 1:clrscr();
	     gotoxy(24,2);cout << "Digite cuantos va a ingresar...";
	     cin >> n;
	     X.crear(n);break;
      case 2:X.recorrer(n);break;
      case 3:clrscr();long eli;
	     gotoxy(29,7);cout << "Digite codigo a eliminar ...";
	     cin >> eli;
	     X.eliminar(eli);



     }

}while(res!=4);
}






