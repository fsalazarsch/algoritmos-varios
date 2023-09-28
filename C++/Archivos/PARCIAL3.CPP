//**************ARCHIVOS************************


#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<fstream.h>
#include<dos.h>
#include<iomanip.h>

void MARCO();
void CAPTURA();
void CONSULTA();
void CONTOTAL();
void DETALLE();
int MENU();
int SUBMENU();
void PANTALLAZO();
char LINEA_VENTA(); 

   struct REGISTRO{
       long CEDULA;
       char NOMBRES[20];
       float SB;
       int TIEMPO;
       char LINEA;
       float VTAS;
       } EMPLEADO; 

 void main(void)
    {
    char OPCION='S';
    int SW;
    while(OPCION=='S')
      {
      MARCO();
      SW=MENU();
      switch (SW){
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
   char CAP='S';
   ofstream ARCHIVO("DATO.DAT",ios::app);
   while ( CAP == 'S')
      {
      MARCO();
      PANTALLAZO();
      gotoxy(32,6); cout << "CAPTURA DE DATOS";
      gotoxy(40,9); cin >> EMPLEADO.CEDULA;
      gotoxy(40,10); gets(EMPLEADO.NOMBRES);
      gotoxy(40,11); cin >> EMPLEADO.TIEMPO;
      gotoxy(40,12); cin >> EMPLEADO.SB;
      EMPLEADO.LINEA = LINEA_VENTA();
      gotoxy(40,14); cin >> EMPLEADO.VTAS;
      ARCHIVO.write((char *) &EMPLEADO, sizeof(REGISTRO));
      do {
	gotoxy(23,20); cout <<"desea continuar capturando S/N ";
	CAP=getch();
	CAP=toupper(CAP);
	} while ((CAP!='S')&&(CAP!='N'));
      }
     ARCHIVO.close();
    }
   char LINEA_VENTA()
     {
     char LINEA;
     do {
     gotoxy(5,22); cout << "T - TV, C - computador, E - estufas, M - muebles, A - adornos";
     gotoxy(40,13);LINEA=getch();
     LINEA=  toupper(LINEA);
     gotoxy(40,13);cout<<LINEA;
     gotoxy(5,22); cout << "                                                             ";
     } while ((LINEA!='T')&&(LINEA!='C')&&(LINEA!='A')&&(LINEA!='E')&&(LINEA!='M'));
     return LINEA;
   }
void PANTALLAZO()
 {
 gotoxy(15,9); cout << "CEDULA                :[             ]";
 gotoxy(15,10); cout <<"NOMBRES Y APELLIDOS   :[                      ]";
 gotoxy(15,11); cout <<"TIEMPO SERVICIO (A¥OS):[    ]";
 gotoxy(15,12); cout <<"ASIGNACION BASICA     :[        ]";
 gotoxy(15,13); cout <<"LINEA DE ARTICULO     :[    ]";
 gotoxy(15,14); cout <<"VALOR DE LAS VENTAS   :[                   ]";
 }
void MARCO()
{
int i;
textcolor(YELLOW);
textbackground(MAGENTA);
clrscr();
textcolor(7);
gotoxy(32,4); cprintf("ALMACEN LA TRAMPA");
gotoxy(24,5); cprintf("PROCESO DE LIQUIDACION DE NOMINA");
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
 void CONSULTA()

  {
  long CEDULA;
  int F,SUB = 1;
  ifstream ARCHIVO("DATO.DAT");
  if (ARCHIVO.fail())
    {
    MARCO();
    gotoxy(24,12); cout << "NO EXISTE NINGUN ARCHIVO.....OJO"; getch();
    SUB = 3;
    }
    ARCHIVO.close();
  while (SUB != 3)
      {
       SUB=SUBMENU();
      switch ( SUB ) {
	 case 1:
	   ifstream ARCHIVO("DATO.DAT");
	  MARCO();
	  gotoxy(30,6); cout << "CONSULTA POR EMPLEADO";
	  gotoxy(15,9); cout << "CEDULA                :[       ]";
	  gotoxy(40,9); cin >> CEDULA;
	  while (! ARCHIVO.eof() )
	       {
	       ARCHIVO.read((char *) &EMPLEADO, sizeof(REGISTRO));
	       if (CEDULA == EMPLEADO.CEDULA)
		  {
		   
		   PANTALLAZO();
		   gotoxy(40,9); cout << EMPLEADO.CEDULA;
		   gotoxy(40,10); cout << EMPLEADO.NOMBRES;
		   gotoxy(40,11); cout << EMPLEADO.TIEMPO;
		   gotoxy(40,12); cout << EMPLEADO.SB;
		   gotoxy(40,13); cout << EMPLEADO.LINEA;
		   gotoxy(40,14); cout << EMPLEADO.VTAS;
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
		     CONTOTAL();
		 break;
		}
	       }
	     }
void CONTOTAL()
   {
   int F=10;
   MARCO();
   gotoxy(26,6); cout << "CONSULTA TODOS LOS EMPLEADOS";
   DETALLE();
   ifstream ARCHIVO("DATO.DAT");
   while (! ARCHIVO.eof())
     {
     ARCHIVO.read((char *) &EMPLEADO, sizeof(REGISTRO));
     if ( ARCHIVO.eof())
     break;
     gotoxy(5,F);cout<<setw(9)<<EMPLEADO.CEDULA;
     gotoxy(17,F); cout << EMPLEADO.NOMBRES;
     gotoxy(41,F); cout << setw(8) << EMPLEADO.SB;
     gotoxy(52,F); cout << setw(2) << EMPLEADO.TIEMPO;
     gotoxy(63,F); cout << EMPLEADO.LINEA;
     gotoxy(66,F); cout << setw(10) << EMPLEADO.VTAS;
     if( F <= 20 )
     F++;
     else					 
	{
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
	MARCO();
	DETALLE();
	F=10;
	}
	{
	}
	gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
      // }
       }		
     }				
void DETALLE()
{
gotoxy(6,8); cout<<"CEDULA     NOMBRES Y APELLIDOS     BASICO    TIEMPO    LINEA   VENTAS";
}
int SUBMENU()
   {
   MARCO();
   int i;
   gotoxy(28,6); cout <<"   S U B M E N U  ";
   gotoxy(26,12); cout << "1 - INDIVIDUAL POR EMPLEADO";
   gotoxy(26,13); cout << "2 - TODOS LOS EMPLEDOS";
   gotoxy(26,14); cout << "3 - SALIR DEL SUBMENU";
   do {
      gotoxy(28,22); cout << "SALECCIONE UNA OPCION  :";
      cin >> i;
      } while ((i<1)||(i>3));
   return i;
  }
	     