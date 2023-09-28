//*************VECTORES**********************


#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<iomanip.h>//Necesario para que funcione el setw()
#include<dos.h>
void MARCO();
int MENU();
void PANTALLAZO();
int SUBMENU();
int SUBMENU1();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);
void ORDEN();
void ORDEN2();
void main(void)
{
int I = 0, SW, J, SUB,SUB1,F;
char LINEA[15],OPCION,NOMBRE[15][25],CAP,SUICHE;
long CEDULA[15],TIEMPO[15],CED;
float VTAS[15],SB[15],PRIMA,COMISION,SN;
OPCION='S';
while (OPCION == 'S')
 {
 MARCO();
 SW = MENU();
 CAP = 'S';
 SUB = 1;
 SUB1 = 1;
 switch (SW) {
  case 1:
      while((I < 15)&&(CAP == 'S'))
      {
      MARCO();
      PANTALLAZO();
      gotoxy(32,6);cout<<"CAPTURA DE DATOS";
      gotoxy(44,9);cin>>CEDULA[I];
      gotoxy(44,10);gets(NOMBRE[I]);
      gotoxy(44,11);cin>>TIEMPO[I];
      gotoxy(44,12);cin>>SB[I];
      LINEA[I] = LINEA_VENTA();
      gotoxy(44,14);cin>>VTAS[I];
      I++;
      do {
	gotoxy(23,18);cout<<"Desea Continuar Capturando S/N : ";
	gotoxy(58,18);CAP=getch();
	CAP=toupper(CAP);
	} while((CAP!='S')&&(CAP!='N'));
      }
      break;
  case 2:
      while ( SUB != 3 )
      {
      MARCO();
      SUB = SUBMENU();
       switch (SUB ) {
	case 1:
	  MARCO();
	  gotoxy(30,6);cout<<"CONSULTA POR EMPLEADO";
	  gotoxy(15,9);cout<<"CEDULA                :[          ]";
	  gotoxy(40,9);cin>>CED;
	  SUICHE = 'N';
	   for (J = 0; J < I; J++)
	   if( CED == CEDULA[J])
	     {
	     SUICHE = 'S';
	     break;
	     }
	   if (SUICHE == 'S')
	     {
	     PANTALLAZO();
	     gotoxy(45,9);cout<<CEDULA[J];
	     gotoxy(45,10);cout<<NOMBRE[J];
	     gotoxy(45,11);cout<<TIEMPO[J];
	     gotoxy(45,12);cout<<SB[J];
	     gotoxy(45,13);cout<<LINEA[J];
	     gotoxy(45,14);cout<<VTAS[J];
	     gotoxy(21,22);cout<<"Pulse Cualquier Tecla Para Continuar";getch();
	     }
	     else
	     {
	     gotoxy(20,13);cout<< "EL EMPLEADO NO EXISTE...JO ..JO...JI..JI";getch();
	     }
	     break;

	case 2:
	  MARCO();
	  gotoxy(25,6);cout<<"CONSULTA DE TODOS LOS EMPLEADOS";
	  ORDEN();
	   for (J = 0,F=10; J < I;F++, J++)
	    {
	    gotoxy(4,F);cout<<CEDULA[J];
	    gotoxy(15,F);cout<<(NOMBRE[J]);
	    gotoxy(37,F);cout<<TIEMPO[J];
	    gotoxy(45,F);cout<<SB[J];
	    gotoxy(63,F);cout<<LINEA[J];
	    gotoxy(68,F);cout<<VTAS[J];

	    if(F==19)
	     {
	     gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch();
	     MARCO();
	     ORDEN();
	     F=10;
	     }
	      }
	      gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch();

	   break;
	    }
	}
	break;
	case 3:
	SUB1=1;
	while ( SUB1 != 3 )
	{
	MARCO();
	SUB1 = SUBMENU1();
	switch (SUB1) {
	case 1:
	  MARCO();
	  gotoxy(30,6);cout<<"LIQUIDACION POR EMPLEADO";
	  gotoxy(15,9);cout<<"CEDULA                :[          ]";
	  gotoxy(40,9);cin>>CED;
	  SUICHE = 'N';
	   for (J = 0; J < I; J++)
	   if( CED == CEDULA[J])
	     {
	     SUICHE = 'S';
	     break;
	     }
	   if (SUICHE == 'S')
	     {
	     PANTALLAZO();
	     gotoxy(45,9);cout<<CEDULA[J];
	     gotoxy(45,10);cout<<NOMBRE[J];
	     gotoxy(45,11);cout<<TIEMPO[J];
	     gotoxy(45,12);cout<<SB[J];
	     gotoxy(45,13);cout<<LINEA[J];
	     gotoxy(45,14);cout<<VTAS[J];
	     PRIMA = SB[J] * TIEMPO[J] / 100;
	  switch ( LINEA[J] ) {
	    case 'T':
	      COMISION = LINEA_TV(VTAS[J]);
	      break;
	    case 'C':
	      COMISION = VTAS[J] * 0.10;
	      break;
	    case 'E':
	      if ( VTAS[J] > 3000000)
		COMISION = VTAS[J] * 0.13;
	      else
		COMISION = 0;
		break;
	    case 'M':
	      COMISION = LINEA_MUEBLES(VTAS[J]);
	      break;
	    case 'A':
	      COMISION = VTAS[J] * 0.17;
	      break;
	    }

	  SN = SB[J] + PRIMA + COMISION;
	  gotoxy(32,16);cout<<"VALORES LIQUIDADOS";
	  gotoxy(30,18);cout<<"Prima        = "<<setw(9)<<PRIMA;
	  gotoxy(30,19);cout<<"Comision     = "<<setw(9)<<COMISION;
	  gotoxy(30,20);cout<<"Salario Neto = "<<setw(9)<<SN;
	  gotoxy(21,22);cout<<"Pulse Cualquier Tecla Para Continuar";getch();
	       }
	  else
	     {
	     gotoxy(20,13);cout<< "EL EMPLEADO NO EXISTE...JO ..JO...JI..JI";getch();
	     }
	    break;
	case 2:
	  MARCO();
	  gotoxy(25,6);cout<<"LIQUIDACION DE TODOS LOS EMPLEADOS";
	  ORDEN2();
	  for (J = 0,F=10; J < I;F++, J++)
	    {

	  switch ( LINEA[J] ) {
	    case 'T':
	      COMISION = LINEA_TV(VTAS[J]);
	      break;
	    case 'C':
	      COMISION = VTAS[J] * 0.10;
	      break;
	    case 'E':
	      if ( VTAS[J] > 3000000)
		COMISION = VTAS[J] * 0.13;
	      else
		COMISION = 0;
		break;
	    case 'M':
	      COMISION = LINEA_MUEBLES(VTAS[J]);
	      break;
	    case 'A':
	      COMISION = VTAS[J] * 0.17;
	      break;
	    }
	  PRIMA = SB[J] * TIEMPO[J] / 100;
	  SN = SB[J] + PRIMA + COMISION;

	    gotoxy(4,F);cout<<CEDULA[J];
	    gotoxy(15,F);cout<<(NOMBRE[J]);
	    gotoxy(39,F);cout<<COMISION;
	    gotoxy(52,F);cout<<PRIMA;
	    gotoxy(62,F);cout<<SN;

	    if(F==19)
	    {
	    gotoxy(21,22);cout<<"Pulse Cualquier Tecla Para Continuar";getch();
	    MARCO();
	    ORDEN2();
	    F=10;
	    }
	     }
	   gotoxy(21,22);cout<<"Pulse Cualquier Tecla Para Continuar";getch();
	       }
	  }
	  break;
	 case 4:
	  OPCION = 'N';
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
       gotoxy(30,14);cout<<"4. SALIR DEL MENU";
	do {
	 gotoxy(23,18);cout<<"Seleccione cualquiera de las opciones :  ";
	 gotoxy(64,18);cin>>OP;
	 } while ((OP < 1 )||(OP > 4 ));
	return OP;
	}
     void PANTALLAZO()
       {
       gotoxy(15,9); cout<<" CEDULA                   : [          ]";
       gotoxy(15,10);cout<<" NOMBRE Y APELLIDOS       : [                             ] ";
       gotoxy(15,11);cout<<" TIEMPO DE SERVICIO (A¥OS): [  ]";
       gotoxy(15,12);cout<<" ASIGNACION BASICA        : [          ]";
       gotoxy(15,13);cout<<" LINEA DE ARTICULO        : [  ]";
       gotoxy(15,14);cout<<" VALOR EN LAS VENTAS      : [          ] ";
       }
    int SUBMENU()
       {
       int OP;
       gotoxy(33,8);cout<<"C O N S U L T A";
       gotoxy(28,11);cout<<"1. INDIVIDUAL POR EMPLEADO";
       gotoxy(28,12);cout<<"2. TODOS LOS EMPLEADOS";
       gotoxy(28,13);cout<<"3. SALIR DEL SUB-MENU";
       do {
	 gotoxy(23,16);cout<<"Seleccione una de las Opciones  : ";
	 gotoxy(57,16);cin>> OP;
	 } while((OP < 1 )||(OP > 3));
	return OP;
       }
    char LINEA_VENTA()
       {
       char LINEA;
	do {
	 gotoxy(5,22);cout<<"t -> TV, C -> Computador, E -> Estufas, M -> Muebles, A -> Adornos";
	 gotoxy(45,13);cin>> LINEA;
	 LINEA = toupper(LINEA);
	 gotoxy(5,22);cout<<"                                                                   ";
	 } while((LINEA != 'T') && (LINEA != 'C') && (LINEA != 'A') && (LINEA != 'E') && (LINEA != 'M'));
	 return LINEA;
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
	    if ( VTAS <= 2000000)
	       COMISION = VTAS * 0.10;
	     else
	       COMISION = VTAS * 0.15;
	return COMISION;
	}
    float LINEA_MUEBLES( float VTAS)
      {
      float COMISION;
      if ( VTAS < 7000000)
	 COMISION = 0;
       else
	 if ( VTAS <= 9000000)
	    COMISION = VTAS * 0.09;
	  else
	    COMISION = VTAS * 0.12;
	return COMISION;
	}
    void MARCO()
      {
      int I;
      
      textcolor(YELLOW);
      textbackground(MAGENTA);
       clrscr();
       gotoxy(26,4);cout<<"DISTRIBUIDORA SURTIUPAR LTDA.";
       gotoxy(24,5);cout<<"proceso de liquidacion de nomina";
	for (I = 2; I <= 79; I++)
	 {
	 gotoxy(I,2);cout<<"õ";
	 gotoxy(I,24);cout<<"õ";
	 delay(20);
	 }
	for (I = 3; I <= 23; I++)
	 {
	 gotoxy(2,I);cout<<"õ";
	 gotoxy(78,I);cout<<" õ";
	 delay(20);
	 }
       }
    void ORDEN()
       {
       gotoxy(4,8); cout<<"CEDULA";
       gotoxy(15,8);cout<<"NOMBRE Y APELLIDOS";
       gotoxy(35,8);cout<<"TIEMPO";
       gotoxy(45,8);cout<<"SALARIO BASE";
       gotoxy(60,8);cout<<"LINEA";
       gotoxy(68,8);cout<<"VALOR VTAS";
       }

    int SUBMENU1()
       {
       int OP;
       gotoxy(33,8);cout<<"L I Q U I D A C I O N";
       gotoxy(28,11);cout<<"1. LIQUIDACION POR EMPLEADO";
       gotoxy(28,12);cout<<"2. LIQUIDACION TOTAL";
       gotoxy(28,13);cout<<"3. SALIR DEL SUB-MENU";
       do {
	 gotoxy(23,16);cout<<"Seleccione una de las Opciones  : ";
	 gotoxy(57,16);cin>> OP;
	 } while((OP < 1 )||(OP > 3));
	return OP;
       }

	 void ORDEN2()
       {
       gotoxy(4,8); cout<<"CEDULA";
       gotoxy(15,8);cout<<"NOMBRE Y APELLIDOS";
       gotoxy(39,8);cout<<"COMISION";
       gotoxy(52,8);cout<<"PRIMA";
       gotoxy(62,8);cout<<"SALARIO NETO";
       
       }





