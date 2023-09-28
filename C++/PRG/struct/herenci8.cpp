#include "stdio.h"
#include "dos.h"
#include "stdlib.h"
#include "process.h"
#include "iostream.h"
#include "conio.h"


class PADRE
      {
       char nombre[30];
       int sueldo_emple;
       int categoria;
       char cargo[15];
       public:
	     void CAP_EMPLEADO();
	     void ESCRIBA_EMPLEADO();
       };

 class DPTO_MANTE:public PADRE
	{
	 char nombre[30];
	 int sueldo_emple;
	 int categoria;
         char cargo[15];
         public:
	     void CONYUGE();
	 };

 void PADRE::CAP_EMPLEADO()
	       {
		cout << "DIGITE NOMBRE DEL EMPLEADO...";
		cin>> nombre;
		cout << "DIGITE SUELDO... ";
		cin >>sueldo_emple;
		cout << "DIGITE CATEGORIA... ";
		cin >>categoria;
		cout << "DIGITE CARGO... ";
		cin >>cargo;
	     }

 void PADRE::ESCRIBA_EMPLEADO()
	      {
	       gotoxy(12,12);cout<<"ESCRIBA NOMBRE DEL EMPLEADO..."<<nombre;
	       gotoxy(12,13);cout<<"ESCRIBA SUELDO... "<<sueldo_emple;
	       gotoxy(12,14);cout<<"ESCRIBA CATEGORIA... "<<categoria;
	       gotoxy(12,15);cout<<"ESCRIBA CARGO... "<<cargo;

	       }

 void main()
	     {
	      clrscr();
	      PADRE X,Y;
	      X.CAP_EMPLEADO();
	      Y.ESCRIBA_EMPLEADO();
              }