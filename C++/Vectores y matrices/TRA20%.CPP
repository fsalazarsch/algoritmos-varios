#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<iomanip.h>
#include<dos.h>
void MARCO();
int MENU();
void PANTALLAZO();
int SUBMENU();
int menu3();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);
void ORDEN();
void ORDEN2();
void main(void)
{
int I = 0, SW, J, SUB,F,ap,i,j;
char LINEA[15],OPCION,NOMBRE[15][30],CAP,SUICHE;
long CEDULA[15],TIEMPO[15],CED;
float VTAS[15],SB[15],PRIMA,COMISION,SN,PRIMA2[15],COMISION2[15],SN2[15];
OPCION='S';
while (OPCION == 'S')
 {

 MARCO();
 SW = MENU();
 CAP = 'S';
 SUB = 1;
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
	     gotoxy(20,13);cout<<"EL EMPLEADO NO HA SIDO RESE¥ADO AUN";
	     getch();
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
	    gotoxy(46,F);cout<<SB[J];
	    gotoxy(63,F);cout<<LINEA[J];
	    gotoxy(68,F);cout<<VTAS[J];
	    }
	    gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch();

	   break;
	  }
	 }
	break ;
	case 3:
	MARCO();
	ap=1;
	while (ap!=3)
	 {
	 ap=menu3();
	 switch (ap) {
	  case 1 :
	   MARCO();
	   gotoxy(23,6);cout<<"PROCESO DE LIQUIDACION INDIVIDUAL";
	  gotoxy(19,12);cout<<"Digite la cedula del empleado  [          ]";
	  gotoxy(52,12);cin>>CED;
	  gotoxy(19,12);cout<<"                                           ";
	  for (J=0;J<I;J++)
	  if (CED==CEDULA[J])
	      {
	      SUICHE='S';
	      break;
	      }
	      if (SUICHE=='S')
		 {
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
	      break ;
	     }
	     SN =SB[J] +PRIMA+COMISION;
	      PANTALLAZO();
	     gotoxy(45,9);cout<<CEDULA[J];
	     gotoxy(45,10);cout<<NOMBRE[J];
	     gotoxy(45,11);cout<<TIEMPO[J];
	     gotoxy(45,12);cout<<SB[J];
	     gotoxy(45,13);cout<<LINEA[J];
	     gotoxy(45,14);cout<<VTAS[J];
	     gotoxy(16,15);cout<<"PRIMA                    : [         ]";
	     gotoxy(16,16);cout<<"COMISION                 : [            ]";
	     gotoxy(16,17);cout<<"SALARIO NETO             : [             ]";

	     gotoxy(45,15);cout<<PRIMA;
	     gotoxy(45,16);cout<<COMISION;
	     gotoxy(45,17);cout<<SN;
	     gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch();

	    }
	    else
	    {
	    gotoxy(27,15);cout<<"EMPLEADO NO DETERMINADO";
	    gotoxy(19,19);cout<<"PRESIONE CUALQUIER TECLA PARA REINICIAR";
	    getch();
	    }
	  MARCO();   
	  break;
	  case 2 :
	  MARCO();
	  ORDEN2();
	  gotoxy(29,6);cout<<"LIQUIDACION GENERAL";
	  for(J = 0,F=11; J < I;F++, J++)
	  {
	  PRIMA2[J] = SB[J] * TIEMPO[J] / 100;
	  switch ( LINEA[J] ) {
	    case 'T':
	      COMISION2[J] = LINEA_TV(VTAS[J]);
	      break;
	    case 'C':
	      COMISION2[J] = VTAS[J] * 0.10;
	      break;
	    case 'E':
	      if ( VTAS[J] > 3000000)
		COMISION2[J] = VTAS[J] * 0.13;
	      else
		COMISION2[J] = 0;
		break;
	    case 'M':
	      COMISION2[J] = LINEA_MUEBLES(VTAS[J]);
	      break;
	    case 'A':
	      COMISION2[J] = VTAS[J] * 0.17;
	      break ;
	     }
	  SN2[J]=SB[J]+COMISION2[J]+PRIMA2[J];
	  gotoxy(5,F);cout<<CEDULA[J];
	  gotoxy(14,F);cout<<(NOMBRE[J]);
	  gotoxy(38,F);cout<<SB[J];
	  gotoxy(48,F);cout<<PRIMA2[J];
	  gotoxy(57,F);cout<<COMISION2[J];
	  gotoxy(66,F);cout<<SN2[J];
	  if (F>18)
	  {
	  F=9;
	  MARCO();
	  ORDEN2();
	  gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch(); 
	} 
       }	  

          gotoxy(21,23);cout<<"Pulse Cualquier Tecla Para Continuar ";getch();
	 
	 MARCO();

	 }
	
      }
      break;

     case 4 :
     OPCION ='N';
     break ;
      }
      }
    
    }
    int MENU()
       {
       int OP,i;
       textcolor(RED);
       gotoxy(27,8);cprintf("M E N U  P R I N C I P A L");
       textcolor(WHITE);
       gotoxy(30,11);cout<<"1. CAPTURA DE DATOS";
       gotoxy(30,12);cout<<"2. CONSULTA DE DATOS";
       gotoxy(30,13);cout<<"3. LIQUIDACION";
       gotoxy(30,14);cout<<"4. SALIR DEL PROGRAMA";
       	for (i=7;i<=16;i++)
	{
	gotoxy(25,i);cout<<"³";
	gotoxy(54,i);cout<<"³";
	}
	for (i=25;i<=54;i++)
	{
	gotoxy(i,7);cout<<"Ä";
	gotoxy(i,9);cout<<"Ä";
	gotoxy(i,16);cout<<"Ä";
	}
	gotoxy(54,16);cout<<"Ù";
	gotoxy(25,16);cout<<"À";
	gotoxy(54,7);cout<<"¿";
	gotoxy(25,7);cout<<"Ú";
	gotoxy(25,9);cout<<"Ã";
	gotoxy(54,9);cout<<"´";
	
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
       int OP,i;
       gotoxy(31,8);cout<<"C O N S U L T A";
       gotoxy(26,11);cout<<"1. INDIVIDUAL POR EMPLEADO";
       gotoxy(26,12);cout<<"2. TODOS LOS EMPLEADOS";
       gotoxy(26,13);cout<<"3. SALIR DEL SUB-MENU";
       for (i=7;i<=16;i++)
	{
	gotoxy(25,i);cout<<"³";
	gotoxy(54,i);cout<<"³";
	}
	for (i=25;i<=54;i++)
	{
	gotoxy(i,7);cout<<"Ä";
	gotoxy(i,9);cout<<"Ä";
	gotoxy(i,16);cout<<"Ä";
	}
	gotoxy(54,16);cout<<"Ù";
	gotoxy(25,16);cout<<"À";
	gotoxy(54,7);cout<<"¿";
	gotoxy(25,7);cout<<"Ú";
	gotoxy(25,9);cout<<"Ã";
	gotoxy(54,9);cout<<"´";
	
       do {
	 gotoxy(23,19);cout<<"Seleccione una de las Opciones  : ";
	 gotoxy(57,19);cin>> OP;
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
      clrscr();
      textcolor(WHITE);
      textbackground(BLUE);
       gotoxy(32,4);cout<<"ALMACEN LA TRAMPA";
       gotoxy(24,5);cout<<"proceso de liquidacion de nomina";
	for (I = 2; I <= 79; I++)
	 {
	 gotoxy(I,2);cout<<"õ";
	 gotoxy(I,24);cout<<"õ";
	 delay(5);
	 }
	for (I = 3; I <= 23; I++)
	 {
	 gotoxy(2,I);cout<<"õ";
	 gotoxy(78,I);cout<<" õ";
	 delay(5);
	 }
       }
    void ORDEN()
       {
       int j;
       gotoxy(4,8); cout<<"CEDULA";
       gotoxy(15,8);cout<<"NOMBRE Y APELLIDOS";
       gotoxy(35,8);cout<<"TIEMPO";
       gotoxy(45,8);cout<<"SALARIO BASE";
       gotoxy(60,8);cout<<"LINEA";
       gotoxy(68,8);cout<<"VALOR VTAS";
       	 for (j=8;j<=22;j++)
       {
       gotoxy(3,j);cout<<"º";
       gotoxy(13,j);cout<<"º";
       gotoxy(32,j);cout<<"º";
       gotoxy(44,j);cout<<"º";
       gotoxy(59,j);cout<<"º";
       gotoxy(67,j);cout<<"º";
       gotoxy(78,j);cout<<"º";
       }
       for (j=3;j<=78;j++)
       {
       gotoxy(j,7);cout<<"Í";
       gotoxy(j,22);cout<<"Í";
       }
       gotoxy(78,7);cout<<"»";
       gotoxy(3,7);cout<<"É";
       gotoxy(3,22);cout<<"È";
       gotoxy(78,22);cout<<"¼";
       gotoxy(13,7);cout<<"Ë";
       gotoxy(32,7);cout<<"Ë";
       gotoxy(44,7);cout<<"Ë";
       gotoxy(59,7);cout<<"Ë";
       gotoxy(67,7);cout<<"Ë";
       gotoxy(13,22);cout<<"Ê";
       gotoxy(32,22);cout<<"Ê";
       gotoxy(44,22);cout<<"Ê";
       gotoxy(59,22);cout<<"Ê";
       gotoxy(67,22);cout<<"Ê";
       
       }

     int menu3()
      {
      int ap;
      gotoxy(25,10);cout<<"1 - LIQUIDACION INDIVIDUAL";
      gotoxy(25,11);cout<<"2 - LIQUIDACION GENERAL";
      gotoxy(25,12);cout<<"3 - SALIR DE ESTE TERCER MENU";
       do {
	    gotoxy(20,18);cout<<"Seleccione una de las alternativas";
	    gotoxy(59,18);cin>>ap;
	    } while((ap < 1)||(ap > 3));
	 return ap;

       }
    void ORDEN2()
       {
       int j;
       gotoxy(4,9); cout<<"CEDULA";
       gotoxy(18,9);cout<<"NOMBRES";

       gotoxy(35,9);cout<<"SALARIO B.";
       gotoxy(48,9);cout<<"PRIMA";
       gotoxy(57,9);cout<<"COMISION";
       gotoxy(66,9);cout<<"SALARIO NETO";
	 for (j=8;j<=22;j++)
       {
       gotoxy(3,j);cout<<"º";
       gotoxy(13,j);cout<<"º";
       gotoxy(34,j);cout<<"º";
       gotoxy(46,j);cout<<"º";
       gotoxy(56,j);cout<<"º";
       gotoxy(65,j);cout<<"º";
       gotoxy(78,j);cout<<"º";
       }
       for (j=3;j<=78;j++)
       {
       gotoxy(j,7);cout<<"Í";
       gotoxy(j,22);cout<<"Í";
       }
       gotoxy(78,7);cout<<"»";
       gotoxy(3,7);cout<<"É";
       gotoxy(3,22);cout<<"È";
       gotoxy(78,22);cout<<"¼";
       gotoxy(13,7);cout<<"Ë";
       gotoxy(34,7);cout<<"Ë";
       gotoxy(46,7);cout<<"Ë";
       gotoxy(56,7);cout<<"Ë";
       gotoxy(65,7);cout<<"Ë";
       gotoxy(13,22);cout<<"Ê";
       gotoxy(34,22);cout<<"Ê";
       gotoxy(46,22);cout<<"Ê";
       gotoxy(56,22);cout<<"Ê";
       gotoxy(65,22);cout<<"Ê";
       }
