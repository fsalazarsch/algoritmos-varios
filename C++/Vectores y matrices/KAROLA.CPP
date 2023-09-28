//*****************VECTORES**********************

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<dos.h>
#include<iomanip.h>//Necesario para que funcione el setw()
void MARCO();
void MEJOR();
void MARCO1();
void FORMA();
void FORMA1();
void PANTALLAZO();
int MENU();
int MENU2();
int SUBMENU();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);
void main(void)
{
textcolor(2);
textbackground(4);
int i,I = 0,l=1, VAR= 1,SW, J, SUB,cont=0;
char LINEA[100],OPCION,NOMBRE[100][30],CAP,SUICHE,clave,clave1,clave2,clave3;
long CEDULA[100],TIEMPO[100],CED,VTAS[100];
float SB[100],PRIMA,COMISION,SN;
OPCION='S';
 empezar:
 clrscr();
 for(i=2;i<=24;i++)
 {
 gotoxy(2,i);cout<<"õõ";
 gotoxy(79,i);cout<<"õõ";
 sound(i*(i*1000));
 delay(5);
 nosound();
 }
 for(i=2;i<=79;i++)
 {
 gotoxy(i,2);cout<<"õ";
 gotoxy(i,24);cout<<"õ";
 sound(i*(i*1000));
 delay(5);
 nosound();
 }
  gotoxy(14,4);cout<<"<<EL PROGRAMA QUE VERA A CONTINUACION LE PERMITIRA>> ";
  gotoxy(15,5);cout<<"<<HACER UNA NOMINA DE EMPLEADO DE DICHA EMPRESA>>";
  gotoxy(22,16);cout<<"<<SI NO DIGITAS LA CLAVE CORRECTA>>";
  gotoxy(21,17);cout<<"<<NO PODRAS TRABAJAR EN EL PROGRAMA>>";
  textcolor(WHITE);
  gotoxy(24,10);cprintf("<<DIGITE LA CLAVE[        ]>>");
  textcolor(2);
  gotoxy(42,10);clave=getch();
  clave=toupper(clave);
  gotoxy(42,10);cout<<"*";
  gotoxy(43,10);clave1=getch();
  clave1=toupper(clave1);
  gotoxy(43,10);cout<<"*";
  gotoxy(44,10);clave2=getch();
  clave2=toupper(clave2);
  gotoxy(44,10);cout<<"*";
  gotoxy(45,10);clave3=getch();
  clave3=toupper(clave3);
  gotoxy(45,10);cout<<"*";
  getch();
   if (clave == 'N' && clave1 == 'E' && clave2 == 'L' && clave3 == 'A')
   {
     goto fin;
     }

     else
     cont++ ;
     if(cont==3)
      {
      gotoxy(24,10);cout<<"                               ";
      gotoxy(25,11);cout<<"<<USTED SALDRA DEL PROGRAMA>>";
      gotoxy(30,10);cout<<"<<ACCESO DENEGADO>>";
      gotoxy(22,16);cout<<"                                       ";
      gotoxy(20,17);cout<<"                                       ";
      gotoxy(20,12);cout<<"<<PRESIONE CUALQUIER TECLA PARA SALIR>>";
      getch();
      goto fin2;
      }
      else
      {
     textcolor(WHITE + 128);
     gotoxy(30,19);cprintf("<<ACCESO DENEGADO>>");
     textcolor(2);
     gotoxy(31,20);cout<<"presione <ENTER> ";
     getch();
     goto empezar;
     }
     fin:
while (OPCION == 'S')
    {
    MEJOR();
    SW = MENU();
    CAP = 'S';
    SUB = 1;
    switch (SW) {
    case 1:
       while((I < 100)&&(CAP == 'S'))
      {
      MARCO();
      PANTALLAZO();
      textcolor(WHITE);
      gotoxy(22,6);cprintf("* C A P T U R A   D E   D A T O S *");
      gotoxy(61,5);cprintf("EMPLEADO # ");
      textcolor(2);
      gotoxy(72,5);cout<<l;
      gotoxy(44,9);cin>>CEDULA[I];
      gotoxy(44,10);gets(NOMBRE[I]);
      gotoxy(44,11);cin>>TIEMPO[I];
      gotoxy(44,12);cin>>SB[I];
      LINEA[I] = LINEA_VENTA();
      gotoxy(44,14);cin>>VTAS[I];
      I++;
      l++;
      do {
	textcolor(WHITE);
	gotoxy(23,18);cprintf("Desea Continuar Capturando S/N : ");
	gotoxy(58,18);CAP=getch();
	CAP=toupper(CAP);
	textcolor(2);
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
	  char OP2,Y;
	  loop:
	  MARCO();
	  textcolor(WHITE);
	  gotoxy(17,6);cprintf("* C O N S U L T A   P O R   E M P L E A D O *");
	  textcolor(2);
	  gotoxy(15,9);cout<<"CEDULA                :";
	  gotoxy(38,9);cprintf("[          ]");
	  textcolor(2);
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
	     textcolor(WHITE);
	     gotoxy(21,22);cprintf("Pulse Cualquier Tecla Para Continuar");getch();
	     textcolor(2);
	     }
	   else
	     {
	     textcolor(WHITE+128);
	     gotoxy(19,13);cprintf("* EMPLEADO NO EXISTE... JO ..JO  ..FLiii *");
	     textcolor(2);
	      gotoxy(28,17);cout<<"DESEA CONSULTAR OTRO Y/N ";
	      gotoxy(53,17);cin>>OP2;
	      OP2=toupper(OP2);
	       if (OP2 == 'Y')
		 goto loop;
	      }
	     break;
	case 2:
	  MARCO();
	  int x,y,B,FILA,D=l-1;
	  textcolor(WHITE);
	  gotoxy(25,6);cprintf("CONSULTA DE TODOS LOS EMPLEADOS");
	  textcolor(2);
	   FORMA();
	   for (J = 0, FILA=10; J < I; J++, FILA++)
	    {

	    textcolor(WHITE);
	    gotoxy(61,5);cprintf("EXISTEN");
	    gotoxy(72,5);cprintf("TRAB.");
	    textcolor(2);
	    gotoxy(69,5);cout<<D;
	    gotoxy(5,FILA);cout<<CEDULA[J];
	    gotoxy(16,FILA);cout<<(NOMBRE[J]);
	    gotoxy(42,FILA);cout<<TIEMPO[J];
	    gotoxy(49,FILA);cout<< setw(8)<< SB[J];
	    gotoxy(64,FILA);cout<<LINEA[J];
	    gotoxy(69,FILA);cout<< setw(8)<< VTAS[J];
	    B=D-11;
	      if (FILA == 20)
	      {
		gotoxy(25,22);cout<<B;
		textcolor(WHITE);
		gotoxy(16,22);cprintf("falta(n)");
		gotoxy(27,22);cprintf("empleado por ver Pulse Cualquier Tecla ");getch();
		textcolor(2);
		FILA = 9;
		for (x=10; x<=21; x++)
		    for(y=3; y<=78; y++)
		     {
		    gotoxy(y,x); cout <<" ";
		    }
		   }
		 }
		 textcolor(WHITE);
		 gotoxy(16,22);cout<<"                                                         ";
		 gotoxy(21,22);cprintf("Pulse Cualquier Tecla Para Continuar ");getch();
		 textcolor(2);
		break;
	       }
	      }
	    break;
	case 3:
	  VAR = 1;
	  while(VAR != 3)
	  {
	  MARCO1();
	  VAR = MENU2();
	  switch (VAR) {

	    case 2:
	     int x,y,C,FILA,M=l-1;
	     MARCO();
	     textcolor(WHITE);
	     gotoxy(23,6);cprintf("LIQUIDACION DE TODOS LOS EMPLEADOS");
	     textcolor(2);
	     FORMA1();
	      for (J = 0, FILA=10; J < I; FILA++,J++)
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
		textcolor(WHITE);
		gotoxy(61,5);cprintf("EXISTEN");
		gotoxy(72,5);cprintf("TRAB.");
		textcolor(2); 
		gotoxy(69,5);cout<<M;
		PRIMA = SB[J] * TIEMPO[J] / 100;
		SN = SB[J] + PRIMA + COMISION;
		gotoxy(4,FILA);cout<<CEDULA[J];
		gotoxy(14,FILA);cout<<(NOMBRE[J]);
		gotoxy(35,FILA);cout<<SB[J];
		gotoxy(47,FILA);cout<< setw(7)<<PRIMA;
		gotoxy(57,FILA);cout<< setw(8)<<COMISION;
		gotoxy(69,FILA);cout<< setw(8)<<SN;
		C=M-11; 
		  if (FILA == 20)
		     {
		    gotoxy(25,22);cout<<C;
		    textcolor(WHITE);
		    gotoxy(16,22);cprintf("falta(n)");
		    gotoxy(27,22);cprintf("empleado por ver Pulse Cualquier Tecla ");getch();
		    textcolor(2);			
		    FILA = 9;		    
		     for (x=10; x<=21; x++)
		      for(y=3; y<=78; y++)
			{
			gotoxy(y,x); cout <<" "; 		 
			}		 
		      }
		    }
		    textcolor(WHITE);
		    gotoxy(16,22);cout<<"                                                 ";
		    gotoxy(21,22);cprintf("Pulse Cualquier Tecla Para Continuar ");getch();
		    textcolor(2);
		  break;
		  
		
		case 1:
		char OP2,Y;
		 inicio:
		 MARCO();
		 textcolor(WHITE);
		 gotoxy(26,6);cprintf("* LIQUIDACION POR EMPLEADO *");
		 textcolor(2);
		 gotoxy(15,9);cout<<"DIGITE LA CEDULA :";
		 gotoxy(34,9);cout<<"[          ]";
		 gotoxy(35,9);cin>>CED;
		 SUICHE = 'N';
		 for(J = 0; J < I; J++)
		 if(CED == CEDULA[J])
		   {
		   SUICHE ='S';
		   break;
		   }
		 if (SUICHE == 'S')
		 {
		 PANTALLAZO();
		 gotoxy(45,9);cout<<CEDULA[J];
		 gotoxy(45,10);cout<<(NOMBRE[J]);
		 gotoxy(45,11);cout<<TIEMPO[J];
		 gotoxy(45,12);cout<<SB[J];
		 gotoxy(45,13);cout<<LINEA[J];
		 gotoxy(45,14);cout<<VTAS[J];
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

	  textcolor(WHITE);
	  gotoxy(22,16);cprintf("* V A L O R E S   L I Q U I D A D O S *");
	  textcolor(2);
	  gotoxy(30,18);cout<<"Prima        = "<<setw(9)<<PRIMA;
	  gotoxy(30,19);cout<<"Comision     = "<<setw(9)<<COMISION;
	  gotoxy(30,20);cout<<"Salario Neto = "<<setw(9)<<SN;getch();
	  }
	  else
	  {
	  textcolor(WHITE + 128); 
	  gotoxy(20,15);cprintf("* E M P L E A D O   N O   E X I S T E *");
	  textcolor(2);
	  gotoxy(28,17);cout<<"DESEA CONSULTAR OTRO Y/N ";
	  gotoxy(53,17);cin>>OP2;
	  OP2=toupper(OP2);       	  
	   if (OP2 == 'Y')
	     goto inicio;	  	     
	     }	   
	  break;
	   }
	 }
	 break;
	  case 4:
	  fin2:
	  OPCION = 'N';
	  
	  break;
	 }
	 
       }   
       textbackground(BLACK);
       clrscr();
     }
     int MENU()
       {
       int OP;
       textcolor(WHITE);
       gotoxy(26,6);cprintf("M E N U   P R I N C I P A L");
       textcolor(2);
       gotoxy(29,11);cout<<"1. CAPTURA DE DATOS";
       gotoxy(29,12);cout<<"2. CONSULTA DE DATOS";
       gotoxy(29,13);cout<<"3. LIQUIDACION";
       gotoxy(29,15);cout<<"4. Salir del Menu";
	do {
	 gotoxy(56,20);cout<<"   ";
	 textcolor(WHITE);
	 gotoxy(22,20);cprintf("Seleccione una de las Opcciones :  ");
	 gotoxy(56,20);cin>>OP;
	 textcolor(2);
	 } while ((OP < 1 )||(OP > 4 ));
	return OP;
	}

     void PANTALLAZO()
       {
       gotoxy(15,9);cout<<" CEDULA                   : [          ]";
       gotoxy(15,10);cout<<" NOMBRE Y APELLIDOS       : [                             ] ";
       gotoxy(15,11);cout<<" TIEMPO DE SERVICIO (A¥OS): [  ]";
       gotoxy(15,12);cout<<" ASIGNACION BASICA        : [          ]";
       gotoxy(15,13);cout<<" LINEA DE ARTICULO        : [  ]";
       gotoxy(15,14);cout<<" VALOR EN LAS VENTAS      : [          ] ";
       }
    int SUBMENU()
       {
       int OP;
       textcolor(WHITE);
       gotoxy(31,8);cprintf("* C O N S U L T A *");
       textcolor(2);
       gotoxy(28,11);cout<<"1. INDIVIDUAL POR EMPLEADO";
       gotoxy(28,12);cout<<"2. TODOS LOS EMPLEADOS";
       gotoxy(28,14);cout<<"3. Salir del Sub-Menu";
       do {
	 gotoxy(57,21);cout<<"   ";
	 textcolor(WHITE);
	 gotoxy(22,21);cprintf("Seleccione una de las Opcciones  : ");
	 gotoxy(57,21);cin>> OP;
	 textcolor(2);
	 } while((OP < 1 )||(OP > 3));
	return OP;
       }
    char LINEA_VENTA()
       {
       char LINEA;
	do {
	 gotoxy(44,13);cout<<"  ";
	 gotoxy(7,22);cout<<"  -> TV    -> Computador,   -> Estufas,   -> Muebles,   -> Adornos";
	 textcolor(WHITE + 128);
	 gotoxy(7,22);cprintf("T");
	 gotoxy(16,22);cprintf("C");
	 gotoxy(33,22);cprintf("E");
	 gotoxy(47,22);cprintf("M");
	 gotoxy(61,22);cprintf("A");
	 gotoxy(44,13);LINEA=getch();
	 textcolor(2);
	 LINEA = toupper(LINEA);
	  gotoxy(44,13);cout<<LINEA;
	 gotoxy(5,22);cout<<"                                                                     ";
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
       textcolor(WHITE+128);
       gotoxy(24,4);cprintf("A L M A C E N   EL   N A M E G O");
       textcolor(2);
       gotoxy(20,5);cout<<"* PROCESO  DE  LIQUIDACION  DE  NOMINA *";
       
	for (I = 2; I <= 79; I++)
	 {
	 gotoxy(I,2);cout<<"²";
	 gotoxy(I,24);cout<<"²";
	 delay(5);	 
	 }
	for (I = 3; I <= 23; I++)
	 {
	 gotoxy(2,I);cout<<"²";
	 gotoxy(79,I);cout<<"²";
	 delay(5);
	 }
       }

void FORMA()
       {
       gotoxy(6,8); cout<<"CEDULA";
       gotoxy(19,8);cout<<"NOMBRE Y APELLIDO";
       gotoxy(40,8);cout<<"TIEMPO";
       gotoxy(49,8);cout<<"SUELDO/BASE";
       gotoxy(62,8);cout<<"LINEA";
       gotoxy(69,8);cout<<"VENTAS";
       }

 int MENU2()
     {
     int OP;
     textcolor(WHITE);
     gotoxy(17,7);cprintf("* P R O C E S O   DE   L I Q U I D A C I O N *");
     textcolor(2);
     gotoxy(27,10);cout<<"1. LIQUIDACION INDIVIDUAL";
     gotoxy(27,11);cout<<"2. LIQUIDACION GENERAL";
     gotoxy(27,13);cout<<"3. Salir del sub MENU";
     do {
     gotoxy(66,20);cout<<"   ";
     textcolor(WHITE);
     gotoxy(15,20);cprintf("seleccione una de las alternativas y pulse");
     textcolor(2+128);
     gotoxy(58,20);cprintf("<ENTER>");
     textcolor(2);
     gotoxy(66,20);cin>>OP;
     } while((OP < 1) || (OP > 3));
   return OP;
   }

void FORMA1()
       {
       gotoxy(4,8); cout<<"CEDULA";
       gotoxy(14,8);cout<<"NOMBRE Y APELLIDO";
       gotoxy(35,8);cout<<"S.BASICO";
       gotoxy(48,8);cout<<"PRIMA";
       gotoxy(57,8);cout<<"COMISION";
       gotoxy(69,8);cout<<"S. NETO";
       }
  void MARCO1()
      {
      int I;
      clrscr();
       textcolor(WHITE);
       gotoxy(24,4);cprintf("A L M A C E N   EL   N A M E G O");
       textcolor(2);
       gotoxy(20,5);cout<<"* PROCESO  DE  LIQUIDACION  DE  NOMINA *";
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


void MEJOR()
{
int m,k;
 textbackground(2);
 clrscr();
   for(k = 1; k <= 24; k++)
    for(m = 1; m <= 80; m++)
     {
      textcolor(WHITE);
      gotoxy(m,k);cprintf("²");
      delay(0.9);
      }
     // textcolor(RED+128);
     // gotoxy(10,9);cprintf( "ÜßßßßßÜ  Û      ÜßßÜ      ÛßÜ       Û  Ûßßßßß  Û      ÜßßÜ  ");
      //gotoxy(10,10);cprintf("Û     Û  Û     Û    Û     Û  ßÜ     Û  Û       Û     Û    Û ");
      //gotoxy(10,11);cprintf("Û     Û  Û     ÛßßßßÛ     Û    ßÜ   Û  Ûßß     Û     ÛßßßßÛ ");
      //gotoxy(10,12);cprintf("Û     Û  Û     Û    Û     Û      ßÜ Û  Û       Û     Û    Û ");
      //gotoxy(10,13);cprintf(" ßßßßß   ßßßß  ß    ß     ß        ßß  ßßßßßß  ßßßß  ß    ß ");
      //textcolor(2);
      //delay(1500);
     // textbackground(BLACK);
      //clrscr();
      //for(k = 1; k <= 24; k++)
      // for(m = 1; m <= 80; m++)
       //{
	// textcolor(WHITE);
	 //gotoxy(m,k);cprintf("²");
       //}

	for (m = 1; m <= 80; m++)
	 {
	 textcolor(2);
	 gotoxy(m,1);cprintf("õ");
	 gotoxy(m,24);cprintf("õ");
	 delay(5);
	 }
	for (m = 1; m <= 24; m++)
	 {
	 textcolor(2);
	 gotoxy(1,m);cprintf("õõ");
	 gotoxy(79,m);cprintf("õõ");
	 delay(5);
	 }
       for(k = 4; k <= 8; k++)
	 for(m = 20; m <= 60; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" "); 
	   }
	  for(k = 3; k <= 7; k++)
	    for(m = 18; m <= 58; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" "); 
	  }	  
	  for(k = 11; k <= 17; k++)
	    for(m = 25; m <= 55; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" "); 
	  }
	  for(k = 10; k <= 16; k++)
	    for(m = 23; m <= 53; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" "); 

	  }
	  for(k = 20; k <= 22; k++)
	    for(m = 20; m <= 60; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" "); 

	  }
	  for(k = 19; k <= 21; k++)
	    for(m = 18; m <= 58; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" "); 
	  }
	  textcolor(WHITE+128);
	  gotoxy(23,4);cprintf("A L M A C E N   EL   N A M E G O");
	  textcolor(2);
	  gotoxy(19,5);cout<<"* PROCESO  DE  LIQUIDACION  DE  NOMINA *";	 
      }


