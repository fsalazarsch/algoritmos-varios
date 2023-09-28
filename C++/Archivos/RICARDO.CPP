//***************ARCHIVOS********************



#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<fstream.h>
#include<dos.h>
#include<iomanip.h>

int MENU();
int SUBMENU();
void CAPTURA();
void CONSULTA();
void TOTALAPRO();
void TOTALREPRO();
void MARCO();
void PANTALLAZO();
void ORDEN();


struct REGISTRO{
   long CODIGO;
   char NOMBRE[20];
   char ASIGNATURA[15];
   float NOTA1;
   float NOTA2;
   float FINAL;
   }ESTU;


void main(void)
  {
  char OPCION ='S';
  int SA;
  while(OPCION=='S')
    {
    MARCO();
    SA=MENU();

    switch (SA){

       case 1:
	 CAPTURA();
       break;

       case 2:
	 CONSULTA();
       break;

       case 3:
	 OPCION='N';
       break;

       }
     }
  }

  int MENU()
  {
  int i;
  gotoxy(32,6); cout << "   M E N U  ";
  gotoxy(30,12); cout << "1 - CAPTURA DE DATOS";
  gotoxy(30,13); cout << "2 - CONSULTA DE DATOS";
  gotoxy(30,14); cout << "3 - SALIR DEL PROGRAMA";
  do {
     gotoxy(28,22); cout << "SELECIONE UNA OPCION  :"; cin >> i;
     }while ((i<1)||(i>3));
  return i;
 }




void CAPTURA()

  {

  char OP='S';

  ofstream ARCHIVO("DATE.DAT",ios::app);

  while(OP=='S')
  {

  MARCO();
  PANTALLAZO();

  gotoxy(20,6);cout<<"CAPTURA DE DATOS";

  gotoxy(45,10);cin>>ESTU.CODIGO;
  gotoxy(45,11);gets(ESTU.NOMBRE);
  gotoxy(45,12);gets(ESTU.ASIGNATURA);
  gotoxy(45,13);cin>>ESTU.NOTA1;
  gotoxy(45,14);cin>>ESTU.NOTA2;
  gotoxy(45,15);cin>>ESTU.FINAL;

  ARCHIVO.write((char *) &ESTU, sizeof(REGISTRO));

  do {

     gotoxy(22,22);cout<<"DESEA CONTINUAR S/N: ";
     gotoxy(41,22);OP=getch();
     OP= toupper(OP);
     }while((OP!='S')&&(OP!='N'));
   }

  ARCHIVO.close();
 }


  void PANTALLAZO()

   {

   gotoxy(30,10);cout<<"CODIGO......:[        ] ";
   gotoxy(30,11);cout<<"NOMBRE......:[                     ] ";
   gotoxy(30,12);cout<<"ASIGNATURA  :[                ] ";
   gotoxy(30,13);cout<<"PRIMERA NOTA:[   ] ";
   gotoxy(30,14);cout<<"SEGUNDA NOTA:[   ] ";
   gotoxy(30,15);cout<<"EXAMEN FINAL:[   ] ";


   }

   void CONSULTA()

  {
  long COD;
  int F,SUB = 1;
  ifstream ARCHIVO("DATE.DAT");
  if (ARCHIVO.fail())
    {
    MARCO();
    gotoxy(24,12); cout << "NO EXISTE NINGUN ARCHIVO.....OJO"; getch();
    SUB = 4;
    }
    ARCHIVO.close();

   while (SUB != 4)
      {
       SUB=SUBMENU();
      switch ( SUB ) {
	 case 1:
	   ifstream ARCHIVO("DATE.DAT");
	  MARCO();
	  gotoxy(30,6); cout << "CONSULTA POR EMPLEADO";
	  gotoxy(15,9); cout << "CODIGO                :[       ]";
	  gotoxy(40,9); cin >> COD;
	  while (! ARCHIVO.eof() )
	       {
	       ARCHIVO.read((char *) &ESTU, sizeof(REGISTRO));
	       if (COD== ESTU.CODIGO)
		  {
                   MARCO();
		   PANTALLAZO();
		   gotoxy(45,10); cout << ESTU.CODIGO;
		   gotoxy(45,11); cout << ESTU.NOMBRE;
		   gotoxy(45,12); cout << ESTU.ASIGNATURA;
		   gotoxy(45,13); cout << ESTU.NOTA1;
		   gotoxy(45,14); cout << ESTU.NOTA2;
		   gotoxy(45,15); cout << ESTU.FINAL;
		   gotoxy(21,22); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
		   break;
		   }
		   }
		if (ARCHIVO.eof())
		   {
		   gotoxy(16,12); cout <<"ESTE EMPLEADO NO EXISTE.....POR FAVOR VERIFIQUE";
		   getch();
		   }
		   ARCHIVO.close();
		   break;
		 case 2:
		     TOTALAPRO();
		 break;
		 case 3:
		   TOTALREPRO();
		 break;
		}
	       }
	     }

  void TOTALAPRO()
   {
   int F=10;
   float DEF;
   MARCO();
   gotoxy(26,6); cout << "CONSULTA TODOS APROBADOS";
   ORDEN();
   ifstream ARCHIVO("DATE.DAT");
   while (! ARCHIVO.eof())
     {
     ARCHIVO.read((char *) &ESTU, sizeof(REGISTRO));
     if ( ARCHIVO.eof())
     break;

     DEF=((ESTU.NOTA1 * 0.3)+(ESTU.NOTA2 * 0.3)+(ESTU.FINAL * 0.4));

     if(DEF>=3)
     {
     gotoxy(5,F);cout<<setw(9)<<ESTU.CODIGO;
     gotoxy(17,F); cout << ESTU.NOMBRE;
     gotoxy(27,F); cout << ESTU.ASIGNATURA;
     gotoxy(39,F); cout << setw(5) << ESTU.NOTA1;
     gotoxy(48,F); cout << setw(5)<<ESTU.NOTA2;
     gotoxy(59,F); cout << setw(5) << ESTU.FINAL;
     gotoxy(68,F);cout<<DEF;

     if( F <= 20 )
     F++;
     else
	{
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
	MARCO();
	ORDEN();
	F=10;
	}
	{
	}
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
       }
       }
     }



  void TOTALREPRO()
   {
   int F=10;
   float DEF;
   MARCO();
   gotoxy(26,6); cout << "CONSULTA TODOS REPROBADOS";
   ORDEN();
   ifstream ARCHIVO("DATE.DAT");
   while (! ARCHIVO.eof())
     {
     ARCHIVO.read((char *) &ESTU, sizeof(REGISTRO));
     if ( ARCHIVO.eof())
     break;

     DEF=(ESTU.NOTA1 * 0.3)+(ESTU.NOTA2 * 0.3)+(ESTU.FINAL * 0.4);
     if (DEF<3)
     {
     gotoxy(5,F);cout<<setw(9)<<ESTU.CODIGO;
     gotoxy(17,F); cout << ESTU.NOMBRE;
     gotoxy(27,F); cout << ESTU.ASIGNATURA;
     gotoxy(39,F); cout << setw(5) << ESTU.NOTA1;
     gotoxy(48,F); cout << setw(5)<<ESTU.NOTA2;
     gotoxy(59,F); cout << setw(5) << ESTU.FINAL;
     gotoxy(68,F);cout<<DEF;

     if( F <= 20 )
     F++;
     else
	{
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
	MARCO();
	ORDEN();
	F=10;
	}
	{
	}
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
      }
       }
     }



void ORDEN()
{
gotoxy(6,8); cout<<"CODIGO     NOMBRES   ASIGNATURA    NOTA1   NOTA2    EXAMEN   DEFINITIVA";
}
int SUBMENU()
   {
   MARCO();
   int i;
   gotoxy(28,6); cout <<"   S U B M E N U  ";
   gotoxy(26,12); cout << "1 - INDIVIDUAL ";
   gotoxy(26,13); cout << "2 - TOTAL APROBADOS";
   gotoxy(26,14); cout << "3 - TOTAL REPROBADOS";
   gotoxy(26,15); cout << "4 - SALIR DEL SUBMENU";
   do {
      gotoxy(28,22); cout << "SALECCIONE UNA OPCION  :";
      cin >> i;
      } while ((i<1)||(i>4));
   return i;
  }


 void MARCO()
{
int i;
textcolor(YELLOW);
textbackground(MAGENTA);
clrscr();
textcolor(WHITE+128);
gotoxy(25,4); cprintf("UNIVERSIDAD POPULAR DEL CESAR");
gotoxy(33,5); cprintf("PREMATRICULAS");
textcolor(YELLOW);
for (i=2;i<=79;i++)
{
gotoxy(i,2); cout<<"õ";
gotoxy(i,24); cout<<"õ";
delay(15);
}
for (i=3;i<=23;i++)
{
gotoxy(2,i); cout<<"õõ";       
gotoxy(78,i); cout<<"õõ";
delay(10);
}
}
