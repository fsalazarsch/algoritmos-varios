#include"stdio.h"
#include"conio.h"
#include"ctype.h"
#include"string.h"
#include"iostream.h"
typedef struct ahorrador;

struct ahorrador{/*declaracion de la estructura*/
	      int cuenta;
	      int cedula;
	      char nombre[20];
	      char apellido[15];
	      char direccion[15];
	      char telefono[10];
	      struct ahorrador *sig;
	      };


class ahorra{
      struct ahorrador *cab, *p, *q;
      public:
	    void cosntrucc();
	    void crear();
	    void listar();
	    void modificar();
	    void eliminar();
	    void insertar();
	    };

void ahorra::cosntrucc(){cab=p=q=NULL;}
void ahorra::crear()
{int cuenta1,cedula1;
 char nombres[20], apellido1[15], direccion1[15], telefono1[10],resp;
  do{
      clrscr();
      gotoxy(20,6);cout<< "DIGITE No. DE CUENTA \n  ";
      gotoxy(20,7);cout<< " DIGITE CEDULA DEL AHORRADOR  \n ";
      gotoxy(20,8);cout<< "DIGITE NOMBRE DEL AHORRADOR  \n ";
      gotoxy(20,9);cout<< " DIGITE APELLIDO DEL AHORRADOR  \n";
      gotoxy(20,10);cout<< "DIGITE DIRECCION DEL AHORRADOR  \n " ;
      gotoxy(20,11);cout<<"DIGITE TELEFONO DEL AHORRADOR \n ";
      gotoxy(60,6);cin >> cuenta1;
      gotoxy(60,7);cin >> cedula1;
      gotoxy(60,8);gets(nombres);
      gotoxy(60,9);gets(apellido1);
      gotoxy(60,10);gets(direccion1);
      gotoxy(60,11);gets(telefono1);
      p= new ahorrador;
      p-> cuenta=cuenta1;
      p->cedula=cedula1;
      strcpy(p->nombre,nombres);
      strcpy(p-> apellido,apellido1);
      strcpy(p-> direccion,direccion1);
      strcpy(p-> telefono,telefono1);
      p->sig=NULL;
      if(cab==NULL){cab=p; cab->sig=NULL;}
      else{q=cab;cab=p;cab->sig=q;}
      gotoxy(30,22);cout<<"DESEA CONTINUAR S/N";
      cin>> resp;
    }while (resp!='n');
//	    getch();
}


void ahorra::listar(){int x=5;
  q=cab;
  clrscr();
  while (q!=NULL)
  {
     gotoxy(2,4);cout<<"cuenta    cedula     nombre     apellido     direccion    telefono ";
     gotoxy(2,x);cout<<q->cuenta;
     gotoxy(12,x);cout<<q->cedula;
     gotoxy(23,x);cout<<q->nombre;
     gotoxy(35,x);cout<<q->apellido;
     gotoxy(45,x);cout<<q->direccion;
     gotoxy(55,x);cout<<q->telefono;
     gotoxy(20,10);cout<<"PRESIONE <<ENTER>>...";
     q=q->sig;
     x++;
  }
getch();
}
void ahorra::modificar()
{int cuenta1,cedula1,cuenta,cedula;
 char nombres[20], apellido1[15], direccion1[15], telefono1[10];
   clrscr();
   cout<<"DIGITE CUENTA A MODIFICAR";
   cin>> cuenta1;
   q = cab;
   while (q!=NULL)
   {
     if (q->cuenta ==cuenta1)
      {clrscr();
       gotoxy(20,4);cout <<"cuenta   " << p->cuenta << "\n";
       gotoxy(20,5);cout <<"cedula   " << p->cedula << "\n";
       gotoxy(20,6);cout <<"nombre   " << p->nombre << "\n";
       gotoxy(20,7);cout <<"apellido "<< p->apellido<< "\n";
       gotoxy(20,8);cout <<"direccion"<< p->direccion<<"\n";
       gotoxy(20,9);cout <<"telefono " <<p->telefono << "\n";
       gotoxy(29,5);cin >> cedula;
       gotoxy(29,6);gets(nombres);
       gotoxy(29,7);gets(apellido1);
       gotoxy(29,8);gets(direccion1);
       gotoxy(29,9); gets(telefono1);
       p->cedula=cedula1;
       strcpy(p->nombre,nombres);
       strcpy(p-> apellido,apellido1);
       strcpy(p-> direccion,direccion1);
       strcpy(p-> telefono,telefono1);
      }
      else
      {
       clrscr();
       gotoxy(20,4);cout <<"ELEMENTO NO EXISTENTE";
      }
      q = q->sig;
   }
getch();
}
      main(){ char op;
	do{
	    ahorra  Gina; // Declaracion del objeto "Gina"
	    clrscr();
	  gotoxy(15,4); cout<< "C E N T R O S I S T E M A S  \n ";
	  gotoxy(15,5); cout<< "GINA R. GOMEZ  \n ";
	  gotoxy(15,6);  cout<<"MENU PRINCIPAL \n ";
	  gotoxy(20,7);  cout<<"1. crear \n ";
	  gotoxy(20,8);  cout<<"2. listar \n ";
	  gotoxy(20,9);  cout<<"3. modificar \n ";
	  gotoxy(20,10); cout<<"4. eliminar \n ";
	  gotoxy(20,11); cout<<"5. insertar \n ";
	  gotoxy(20,12); cout<<"6.salir  \n  ";
	  gotoxy(20,13); cout<< "Digite Opcion   ";
	  gotoxy(20,31); cin>> op;
	    switch(op){
	    {case '1': Gina.crear();break;}
	    {case '2': Gina.listar();break;}
	    {case '3': Gina.modificar();break;}
	  /*{case': Gina.eliminar();break;}
	    {case': Gina.insertar();break;}*/
		  }
	 }while(op != '6');
//getch();
return 0;
}















