//****************************ARCHIVOS************************************

/*ESTE PROGRAMA PERMITE CALCULAR LA NOMINA DEL ALMACEN NAMEGO, QUIEN
  CUENTA CON UN GRUPO DE VENDEDORES POR LINEA DE ARTICULO  QUE TIENE
  UN SALARI BASICO, PRIMA DE ANTIGUEDAD Y UNA COMISION EN LAS VENTAS.*/



#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<stdio.h>
#include<iomanip.h>
#include<fstream.h>
void MARCO();
int MENU();
void PANTALLAZO();
void CAPTURA();
void CONSULTA();
void LIQUIDACION();
int SUBMENU();
void DETALLE();
void DETALLE_SN();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);
struct REGISTRO {
   long CEDULA;
   char NOMBRE[30];
   float SB;
   int TIEMPO;
   char LINEA;
   float VTAS;
   } EMP ;
void main(void)
 {
textcolor(2);
textbackground(4);
 char OPCION = 'S';
 int SW;
 while (OPCION == 'S')
   {
   MARCO();
   SW = MENU();
    switch ( SW ) {
      case 1:
	CAPTURA();
	break;
      case 2:
	CONSULTA();
	break;
      case 3:
	LIQUIDACION();
	break;
      case 4:
	OPCION ='N';
	break;
     }
   }
 }
int MENU()
  {
  int OP;
  gotoxy(36,8);cout<<"M E N U";
  gotoxy(30,11);cout<<"1. CAPTURA DE DATOS";
  gotoxy(30,12);cout<<"2. CONSULTA DE DATOS";
  gotoxy(30,13);cout<<"3. LIQUIDACION";
  gotoxy(30,15);cout<<"4. salir del MENU";
  do {
    gotoxy(23,18);cout<<"seleccione una de las opciones  : ";
    gotoxy(57,18);cin>>OP;
    } while((OP < 1 ) || (OP > 4));
  return OP;
  }
void PANTALLAZO()
  {
   gotoxy(15,9);cout<<"CEDULA                : [        ]";
   gotoxy(15,10);cout<<"NOMBRES Y APELLIDOS   : [                           ]";
   gotoxy(15,11);cout<<"TIEMPO SERVICIO (A¥OS): [  ] ";
   gotoxy(15,12);cout<<"ASIBNACION BASICA     : [         ]";
   gotoxy(15,13);cout<<"LINEA DE ARTICULO     : [ ]";
   gotoxy(15,14);cout<<"VALOR EN LAS VENTAS   : [         ]";
   }
int SUBMENU()
   {
   int OP;
   gotoxy(33,8);cout<<"C O N S U L T A";
   gotoxy(28,11);cout<<"1. INDIVIDUAL POR EMPLEADO";
   gotoxy(28,12);cout<<"2. TODOS LOS EMPLEADOS";
   gotoxy(28,14);cout<<"3. salir del SUB_MENU";
   do {
     gotoxy(23,16);cout<<"seleccione una de las opciones  : ";
     gotoxy(57,16);cin>>OP;
      } while((OP < 1) || (OP > 3));
    return OP;
   }
void MARCO()
   {
   int I;
    clrscr();
    textcolor(WHITE);
    gotoxy(24,4);cprintf("A L M A C E N   EL   N A M E G O");
    textcolor(2);
    gotoxy(20,5);cout<<"PROCESO  DE  LIQUIDACION  DE  NOMINA";
     for (I = 2; I <= 79; I++)
      {
      gotoxy(I,2);cout<<"õ";
      gotoxy(I,24);cout<<"õ";
      delay(5);
      }
     for (I = 3; I <= 23; I++)
      {
      gotoxy(2,I);cout<<"õ";
      gotoxy(79,I);cout<<"õ";
      delay(5);
      }
   }
void CAPTURA()
   {
   char CAP = 'S';
   ofstream ARCHIVO("VENDEDOR.DAT",ios::app);  //ADEMAS DE ABRIR EL ARCHIVO, PERMITE ADICIONAR
   while( CAP =='S')				//NUEVOS REGISTOS
     {
     MARCO();
     PANTALLAZO();
     gotoxy(32,6);cout<<"CAPTURA DE DATOS";
     gotoxy(40,9);cin>>EMP.CEDULA;
     gotoxy(40,10);gets(EMP.NOMBRE);
     gotoxy(40,11);cin>>EMP.TIEMPO;
     gotoxy(40,12);cin>>EMP.SB;
     EMP.LINEA = LINEA_VENTA();
     gotoxy(40,14);cin>>EMP.VTAS;
     ARCHIVO.write((char *) &EMP, sizeof(REGISTRO));
     do {
       gotoxy(23,18);cout<<"desea continuar capturando S/N ";
       gotoxy(57,18);CAP = getch();
       CAP = toupper(CAP);
       } while((CAP != 'S') && (CAP != 'N'));
     }
   ARCHIVO.close();
   }
char LINEA_VENTA()
   {
   char LINEA;
   do {
     gotoxy(5,22);cout<<"T -> TV, C -> COMPUTADOR, E -> ESTUFA, M -> MUEBLES, A -> ADORNOS";
     gotoxy(40,13);cin>>LINEA;
     LINEA = toupper(LINEA);
     gotoxy(5,22);cout<<"                                                                 ";
     } while((LINEA != 'T') && (LINEA != 'C') && (LINEA != 'A') && (LINEA != 'M') && (LINEA != 'E'));
  return LINEA;
  }
void DETALLE()
  {
  gotoxy(6,8);cout<<"CEDULA  NOMBRES Y APELLIDOS        TIEMPO  BASICO   LINEA  VENTAS";
  }
void DETALLE_SN()
  {
  gotoxy(6,8);cout<<"CEDULA  NOMBRES Y APELLIDOS      BASICO   PRIMA  COMISION   NETO";
  }
void CONSULTA()
  {
  long CED;
  int F,SUB = 1;
  char SW = 'S';
  ifstream ARCHIVO("VENDEDOR.DAT");
  if (ARCHIVO.fail())
     {
     gotoxy(26,12);cout<<"ARCHIVO NO EXISTE.......JO..JO";getch();
     SUB = 3;
     }
     while(SUB != 3 )
	{
	MARCO();
	SUB = SUBMENU();
	switch ( SUB ) {
	 case 1:
	   MARCO();
	   gotoxy(30,6);cout<<"CONSULTA POR EMPLEADO";
	   gotoxy(15,9);cout<<"CEDULA               : [       ]";
	   gotoxy(40,9);cin>>CED;
	   while ( ! ARCHIVO.eof() && ( SW = 'S'))
	     {
	     ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
	      if (CED == EMP.CEDULA)
	       SW = 'N';
	     }
	     if (ARCHIVO.eof())
	      {
	      gotoxy(27,12);cout<<"EMPLEADO NO EXISTE.......!";getch();
	      }
	    else
	     {
	     PANTALLAZO();
	      gotoxy(40,9);cout<<EMP.CEDULA;
	      gotoxy(40,10);cout<<EMP.NOMBRE;
	      gotoxy(40,11);cout<<EMP.TIEMPO;
	      gotoxy(40,12);cout<<EMP.SB,
	      gotoxy(40,13);cout<<EMP.LINEA;
	      gotoxy(40,14);cout<<EMP.VTAS;
	      gotoxy(21,22);cout<<"pulse cualquier tecla para continuar";getch();
	      }
	    break;
	 case 2:
	  MARCO();
	  gotoxy(26,6);cout<<"CONSULTA TODOS LOS EMPLEADOS";
	  DETALLE();
	  F=10;
	    while(!ARCHIVO.eof())
	    {
	     ARCHIVO.read((char * ) &EMP,sizeof(REGISTRO));
	     if (ARCHIVO.eof()) 
	     break;
	      gotoxy(5,F);cout<<setw(8)<<EMP.CEDULA;
	      gotoxy(15,F);cout<<EMP.NOMBRE;
	      gotoxy(47,F);cout<<setw(2)<<EMP.TIEMPO;
	      gotoxy(52,F);cout<<setw(8)<<EMP.SB;
	      gotoxy(65,F);cout<<EMP.LINEA;
	      gotoxy(67,F);cout<<setw(10)<<EMP.VTAS;
	      if (F <= 20)
		F++;
	     else
	       {
	       gotoxy(21,22);cout<<"pulse cualquier tecla para continuar";getch();
	       MARCO();
	       DETALLE();
	       F = 10;
	       }
	     }
	     gotoxy(21,22);cout<<"pulse cualquier tecla para continuar";getch();
	    break;
	  }
      }
      ARCHIVO.close();
      }
void LIQUIDACION()
   {
   int F;
   char SW = 'S';
   float PRIMA=0,COMISION=0,SN=0;
   ifstream ARCHIVO("VENDEDOR.DAT");
   MARCO();
    if (ARCHIVO.fail())
     {
      gotoxy(26,12);cout<<"ARCHIVO NO EXISTE...JO..JO";getch();
      SW = 'N';
      }
    else
     {
      gotoxy(35,6);cout<<"LIQUIDACION";
      F = 10;
      DETALLE_SN();
      }
    while (( ARCHIVO.eof()) && ( SW != 'N'));
      {
	ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
	if ( ARCHIVO.eof() )   
	gotoxy(5,F);cout<<EMP.CEDULA;
	gotoxy(15,F);cout<<EMP.NOMBRE;
	PRIMA = EMP.SB * EMP.TIEMPO / 100;
	 switch (EMP.LINEA) {
	   case 'T':
	     COMISION = LINEA_TV(EMP.VTAS);
	     break;
	  case 'C':
	     COMISION = EMP.VTAS * 0.10;
	     break;
	  case 'E':
	     if (EMP.VTAS > 3000000)
	       COMISION = EMP.VTAS * 0.13;
	       else
		 COMISION = 0;
		 break;
	  case 'M':
	     COMISION = LINEA_MUEBLES(EMP.VTAS);
	     break;
	  case 'A':
	     COMISION = EMP.VTAS * 0.17;
	     break;
	 }
	 SN = EMP.SB + PRIMA + COMISION;
	  gotoxy(41,F);cout<<setw(8)<<EMP.SB;
	  gotoxy(51,F);cout<<setw(6)<<PRIMA;
	  gotoxy(59,F);cout<<setw(8)<<COMISION;
	  gotoxy(69,F);cout<<setw(8)<<SN;
	   if (F <= 20)
	     F++;
	   else
	     {
	     gotoxy(21,22);cout<<"pulse cualquier tecla para continuar";getch();
	     MARCO();
	     DETALLE();
	     F = 10;
	     }
	   }

	  gotoxy(21,22);cout<<"pulse cualquier tecla para continuar";getch();
	  ARCHIVO.close();
       }
float LINEA_TV(float VTAS)
   {
   float COMISION;
    if (VTAS < 4000000)
      COMISION = 0;
      else
       if (VTAS < 8000000)
	 COMISION = VTAS * 0.06;
	 else
	  if (VTAS <= 20000000)
	    COMISION = VTAS * 0.10;
	    else
	      COMISION = VTAS * 0.15;
     return COMISION;
  }
float LINEA_MUEBLES(float VTAS)
   {
   float COMISION;
    if (VTAS < 7000000)
      COMISION = VTAS * 0.09;
      else
	COMISION = VTAS * 0.12;
    return COMISION;
    }
