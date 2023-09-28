//*************ARCHIVOS*************************


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>
int MENU();
int SUBMENU();
void MARCO();
void PANTALLAZO();
void DETALLE();
void CAPTURA();
void CONSULTA();
void CONTOTAL();
struct ARCHIVO {
   long CEDULA;
   char NOMBRES[30];
   long TEL;
   char DIRECCION[30];
   } EMPLEADO;

void main(void)
{
 char opcion ='S';
 int am;
 while( opcion=='S')
 {

 MARCO();
 am=MENU();

  switch (am) {
   case 1:
    CAPTURA();
    break;
   case 2:
   CONSULTA();
    break;
   case 3:
    opcion='N';
    break;
  } //cierra switch

} //CIERRA EL WHILE
} //CIERRA EL VOID
/***********************/
//funciones*/

int MENU()
{

 int OP;
 gotoxy(36,8);cout<<"M E N U";
 gotoxy(30,11);cout<<"1. CAPTURA DE DATOS";
 gotoxy(30,12);cout<<"2. CONSULTA DE DATOS";
 gotoxy(30,13);cout<<"3. salir del menu";
  do{
  gotoxy(23,18);cout<< "seleccione una de las opciones :  ";
  gotoxy(57,18);cin>>OP;
  OP=toupper(OP);
  } while ((OP<1)||(OP>3));
  return OP;

}//CIERRA VOID FUNCION
/****************************************/
void MARCO()
{
int I;
textcolor(BLUE);
textbackground(WHITE);
clrscr();
gotoxy(33,4);cout<<"ALMACEN AMAURY";
gotoxy(35,5);cout<<"registros";
for(I=2;I<=79;I++)
{
gotoxy(I,2);cout<<"Ü ";
gotoxy(I,24);cout<<"Ü";
}//CIERRA FOR
for(I=3;I<=23;I++)
{
gotoxy(2,I);cout<<"ÜÜ";
gotoxy(78,I);cout<<"ÜÜ";
}//CIERRA FOR
}//CIERRA FUN MARCO
/*******************************/
void CAPTURA()
{
char OPCION='S';
   ofstream DATOS("c:\DATO.DAT",ios::app);       // ABRIR UN ARCHIVO PARA CREARLO

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
     do{
	 gotoxy(26,20);cout<<" desea continuar S/N :";
	 gotoxy(48,20);cin>>OPCION;
	 OPCION = toupper(OPCION);
	}while ((OPCION!='S')&&(OPCION!='N'));
     } //CIERRA WHILE
DATOS.close();
}
/*******************************/
void CONSULTA()
  {
  long CEDULA;
  char C;
  int F,SUB = 1;
  ifstream DATOS("c:\DATO.DAT");
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
	    ifstream DATOS("c:\DATO.DAT");
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
void CONTOTAL()
{
int F=10;
MARCO();
gotoxy(26,6);cout<<"CONSULTA TODOS LOS EMPLEADOS";
DETALLE();
ifstream DATOS("c:\DATO.DAT"); //abre el archivo
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
} // cierra void consulta
/***********************************************/
int SUBMENU()
   {
   MARCO();
   int i;
   gotoxy(30,6); cout <<"   S U B M E N U  ";
   gotoxy(28,12); cout << "1. INDIVIDUAL POR EMPLEADO";
   gotoxy(28,13); cout << "2. TODOS LOS EMPLEDOS";
   gotoxy(28,14); cout << "3. SALIR DEL SUBMENU";
   do {
      gotoxy(23,18); cout << "seleccione una de las opciones :  ";
      gotoxy(57,18);cin >> i;
      } while ((i<1)||(i>3));
   return i;
  }
/*********************************************/
void DETALLE()
{
 gotoxy(9,8);cout<<"² CEDULA ² NOMRES Y APELLIDOS ²TELEFONO²     DIRECCION      ²";
}
/***************************************/
 void PANTALLAZO()
   {
   gotoxy(13,10); cout<<  " CEDULA              : ";
   gotoxy(13,11); cout<< " NOMBRES Y APELLIDOS : ";
   gotoxy(13,12); cout<< " TELEFONO            : ";
   gotoxy(13,13); cout<< " DIRECCION           : ";

   } // cierra fun pantallazo;

