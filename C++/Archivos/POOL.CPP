//******************ARCHIVOS***********************


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>
#include<dos.h>
int MENU();
int SUBMENU();
void MARCO();
void DATOS();
void CAPTURA();
void CONSULTA();
struct registro {
       long cod;
       char nom[30];
       char asig[30];
       double n1;
       double n2;
       double n3;
       } alumno;
void main(void)
{
char op='S';
int sw;
while(op=='S')
{
MARCO();
sw=MENU();
switch (sw) {
       case 1:
       CAPTURA();
       break;
       case 2:
       CONSULTA();
       break;
       case 3:
       op='N';
       break;
       }
  }
}
			   //FUNCIONES
/***************************************************************************/
int MENU()
{
int op;
gotoxy(37,6);cout<<"U.P.C";
gotoxy(32,8);cout<<"REGISTRO DE NOTAS";
gotoxy(38,10);cout<<"MENU";
gotoxy(20,12);cout<<"1.CAPTURA";
gotoxy(20,13);cout<<"2.CONSULTA";
gotoxy(20,14);cout<<"3.SALIR";
do {
    gotoxy(29,20);cout<<"DIGITE UNA OPCION [_]";
    gotoxy(48,20);cin>>op;
    } while ((op<1)||(op>3));
return op;
}
/***************************************************************************/
void MARCO()
{
clrscr();
int i;
for(i=2;i<=22;i++)
{
gotoxy(2,i);cout<<"Û";
gotoxy(78,i);cout<<"Û";
//delay(5);
}
for(i=2;i<=78;i++)
{
gotoxy(i,2);cout<<"Û";
gotoxy(i,22);cout<<"Û";
//delay(5);
}
}
/****************************************************************************/
void DATOS()
{
gotoxy(37,6);cout<<"U.P.C";
gotoxy(32,8);cout<<"REGISTRO DE NOTAS";
gotoxy(36,9);cout<<"CAPTURA";
gotoxy(15,10);cout<<"      CODIGO:";
gotoxy(15,11);cout<<"      NOMBRE:";
gotoxy(15,12);cout<<"  ASIGNATURA:";
gotoxy(15,13);cout<<"PRIMERA NOTA:";
gotoxy(15,14);cout<<"SEGUNDA NOTA:";
gotoxy(15,15);cout<<"EXAMEN FINAL:";
}
int SUBMENU()
{
int op;
MARCO();
gotoxy(37,6);cout<<"U.P.C";
gotoxy(32,8);cout<<"REGISTRO DE NOTAS";
gotoxy(36,9);cout<<"CONSULTA";
gotoxy(15,11);cout<<"1.INDIVIDUAL";
gotoxy(15,12);cout<<"2.TOTAL APROBADOS";
gotoxy(15,13);cout<<"3.TOTAL REPROBADOS";
do {
    gotoxy(29,20);cout<<"DIGITE UNA OPCION [_]";
    gotoxy(48,20);cin>>op;
    } while ((op!=1)&&(op!=2)&&(op!=3));
return op;
}
/**************************************************************************/
void CAPTURA()
{
char op='S';
ofstream ARCHIVO("DATOS.DAT",ios::app);
//MARCO();
if(!ARCHIVO.fail())
 //{
//MARCO();
//DATOS();
while(op=='S')
{
MARCO();
DATOS();
gotoxy(28,10);cin>>alumno.cod;
gotoxy(28,11);gets(alumno.nom);
gotoxy(28,12);gets(alumno.asig);
gotoxy(28,13);cin>>alumno.n1;
gotoxy(28,14);cin>>alumno.n2;
gotoxy(28,15);cin>>alumno.n3;
ARCHIVO.write((char*)&alumno,sizeof(registro));
do {
   gotoxy(26,20);cout<<"DESEA SEGUIR CAPTURANDO S/N:";
   //gotoxy(55,20);cin>>op;
   op=getch();op=toupper(op);
   } while((op!='S')&&(op!='N'));
 }
 else
 {
 gotoxy(26,12);cout<<"NO SE PUDO ABRIR EL ARCHIVO";
 getch();
 }
 ARCHIVO.close();
}
/***************************************************************************/
 void CONSULTA()
  {
  long cod;
  char op='S';
  int F,SUB = 1;
  ifstream ARCHIVO("DATOS.DAT");
  if (ARCHIVO.fail())
    {
    gotoxy(26,12); cout << "Este archivo no existe."; getch();
    SUB = 3;
    }
    //ARCHIVO.close();
  while (SUB != 3)
      {
	ifstream ARCHIVO("DATOS.DAT");
	MARCO();
       SUB=SUBMENU();
      switch ( SUB ) {
	 case 1:
	    op='S';
	    MARCO();
	    gotoxy(37,6);cout<<"U.P.C";
	    gotoxy(32,8);cout<<"REGISTRO DE NOTAS";
	    gotoxy(30,9);cout<<"CONSULTA INDIVIDUAL" ;
	    gotoxy(14,11); cout << "CODIGO:";
	    gotoxy(21,11); cin >> cod;
	    gotoxy(13,11);cout<<"             ";
	    while ((! ARCHIVO.eof() )&&(op=='S'))
	       {
	       ARCHIVO.read((char *) &alumno, sizeof(registro));

	       if (cod == alumno.cod)
		    op='N';
		    if (ARCHIVO.eof())
		   {
		   gotoxy(16,12); cout <<"Este empleado no existe.....por favor verifique";
		   getch();
		   }

		   else
		   {
		   DATOS();
		   gotoxy(14,10);cout<<"   ";
		   gotoxy(30,9);cout<<"CONSULTA INDIVIDUAL" ;
		   gotoxy(10,10);cout<<"       ";
		   gotoxy(28,10);cout<<alumno.cod;
		   gotoxy(28,11); cout <<alumno .nom;
		   gotoxy(28,12); cout << alumno.asig;
		   gotoxy(28,13); cout << alumno.n1;
		   gotoxy(28,14);cout<<alumno.n2;
		   gotoxy(28,15);cout<<alumno.n3;
		   gotoxy(22,19);cout<<"pulse cualquier tecla para continuar";getch();
		   }
		   }


		   break;
	 case 2:
		 MARCO();
		 getch();
		 break;
	    }
	  }
	 }













































 /*      void CAPTURA()
{
char OPCION='S';
   ofstream DATOS("A:DATO.DAT",ios::app);       // ABRIR UN ARCHIVO PARA CREARLO

   while (OPCION== 'S')
     {

     MARCO();
     PANTALLAZO();
     gotoxy(32,8);cout<<" C A P T U R A ";
     gotoxy(36,10); cin>> EMPLEADO.CEDULA;
     gotoxy(36,11);gets(EMPLEADO.NOMBRES);
     gotoxy(36,12); cin>> EMPLEADO.TEL;
     gotoxy(36,13); gets(EMPLEADO.DIRECCION);

     DATOS.write(( char * ) &EMPLEADO,sizeof(ARCHIVO));   // ALMACENAR EN EL ARCHIVO
   /*  ofstream archivo("A:EMPLEADO.DAT", ios::app);
     archivo.write(( char * ) &EMPLEADO,sizeof(ARCHIVO));   // ALMACENAR EN EL ARCHIVO
     archivo.close();*/
   /*  do{
	 gotoxy(26,20);cout<<" desea continuar S/N :";
	 gotoxy(48,20);cin>>OPCION;
	 OPCION = toupper(OPCION);
	}while ((OPCION!='S')&&(OPCION!='N'));
     } //CIERRA WHILE
DATOS.close();
}
/*******************************/
/*void CONSULTA()
  {
  long CEDULA;
  char C;
  int F,SUB = 1;
  ifstream DATOS("A:DATO.DAT");
  if (DATOS.fail())
    {
    gotoxy(26,12); cout << "Este archivo no existe."; getch();
    SUB = 3;
    }
    DATOS.close();
  while (SUB != 3)
      {
       SUB=SUBMENU();
      switch ( SUB ) {
	 case 1:
	   do{
	    ifstream DATOS("A:DATO.DAT");
	    MARCO();
	    gotoxy(30,6); cout << "CONSULTA POR EMPLEADO";
	    gotoxy(14,9); cout << "CEDULA              :";
	    gotoxy(40,9); cin >> CEDULA;
	    while (! DATOS.eof() )
	       {
	       DATOS.read((char *) &EMPLEADO, sizeof(ARCHIVO));
	       if (CEDULA == EMPLEADO.CEDULA)
		  {

		   PANTALLAZO();
		   gotoxy(13,10); cout <<"                             ";
		   gotoxy(40,11); cout << EMPLEADO.NOMBRES;
		   gotoxy(40,12); cout << EMPLEADO.TEL;
		   gotoxy(40,13); cout << EMPLEADO.DIRECCION;


		   break;
		   }
		   }
		if (DATOS.eof())
		   {
		   gotoxy(16,12); cout <<"Este empleado no existe.....por favor verifique";
		   getch();
		   }
		   DATOS.close();
		   do{
		   gotoxy(21,22); cout << "desea continuar consultando S/N : ";
		   cin>>C;
		   C=toupper(C);
		   } while ((C!='S')&&(C!='N'));
		   } while(C=='S');
		   break;
		 case 2:
		     CONTOTAL();
		 break;
		}
	       }
	     }
/****************************/
/*void CONTOTAL()
{
int F=10;
MARCO();
gotoxy(26,6);cout<<"CONSULTA TODOS LOS EMPLEADOS";
DETALLE();
ifstream DATOS("A:DATO.DAT"); //abre el archivo
if(DATOS.fail())
   {
     gotoxy(10,14); cout <<"ARCHIVO NO EXISTE";
     getch();
   }
    else
      {
	do
	{
	  DATOS.read((char*) &EMPLEADO, sizeof(ARCHIVO));//LEO ARCHIVO
	  if(DATOS.eof()) break;
	  gotoxy(10,F);cout<<EMPLEADO.CEDULA;
	  gotoxy(19,F);cout<<EMPLEADO.NOMBRES;
	  gotoxy(40,F);cout<<EMPLEADO.TEL;
	  gotoxy(49,F);cout<<EMPLEADO.DIRECCION;
	  if(F<=20)
	    F++;
	    else
		{
		 gotoxy(21,22);cout<<"presione cualquier tecla para continuar:";getch();
		 MARCO();
		 DETALLE();
		 F=10;
		}//cierra else                                                            4

 }while(!DATOS.eof()); //cierra while
  gotoxy(21,22);cout<<"presione cualquier tecla para continuar:";getch();

 DATOS.close(); // cierra archivo
}
} // cierra void consulta*/