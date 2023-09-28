//*******************VECTORES************************


# include <iostream.h>
# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <time.h>
# include <iomanip.h>
# include <math.h>
# include <string.h>
# include <dos.h>

void MARCO();
int MENU();
void PANTALLAZO();
int SUBMENU();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);

void main(void)
{
 int I=0,SW,J,SUB,K=10;
 char LINEA[10],OPCION,NOMBRE[10][30],CAP;
 long CEDULA[10],TIEMPO[10],CED;
 float VTAS[10],SB[10],PRIMA,COMISION,SN;
 OPCION='S';
 while(OPCION == 'S')
 {
  MARCO();
  textcolor(RED);
  textbackground(WHITE);
  SW=MENU();
  CAP='S';
  SUB=1;
  switch(SW){
   case 1:
    while((I<10)&&(CAP == 'S'))
    {
     MARCO();
     PANTALLAZO();
     gotoxy(30,6);cout<<"<<<CAPTURA DE DATOS>>>";
     gotoxy(40,9);cin>>CEDULA[I];
     gotoxy(40,10);gets(NOMBRE[I]);
     gotoxy(40,11);cin>>TIEMPO[I];
     gotoxy(40,12);cin>>SB[I];
     LINEA[I]=LINEA_VENTA();
     gotoxy(40,14);cin>>VTAS[I];
     I++;
     do {
	 gotoxy(23,18);cout<<"DESEA CONTINUAR CAPTURANDO -S/N-";
	 CAP=getch();
	 CAP=toupper(CAP);
	 } while((CAP != 'S')&&(CAP != 'N'));
    }
  break;
  case 2:
   while(SUB != 3)
   {
    MARCO();
    SUB=SUBMENU();
    switch(SUB){
     case 1:
      MARCO();
      gotoxy(30,6);cout<<"CONSULTA POR EMPLEADO";
      gotoxy(15,9);cout<<"C‚dula     :[           ]";
      gotoxy(28,9);cin>>CED;
      gotoxy(15,9);cout<<"                         ";
      for(J=0;J<K;J++)
      {
       if(CED == CEDULA[J])
	break;
      }
      PANTALLAZO();
      gotoxy(40,9);cout<<CEDULA[J];
      gotoxy(40,10);cout<<NOMBRE[J];
      gotoxy(40,11);cout<<TIEMPO[J];
      gotoxy(40,12);cout<<SB[J];
      gotoxy(40,13);cout<<LINEA[J];
      gotoxy(40,14);cout<<VTAS[J];
      gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
      getch();
      break;
     case 2:
      for(J=0;J<I;J++)
      {
       MARCO();
       gotoxy(24,6);cout<<"<<<CONSULTA TODOS LOS EMPLEADOS>>>";
       PANTALLAZO();
       gotoxy(40,9);cout<<CEDULA[J];
       gotoxy(40,10);cout<<NOMBRE[J];
       gotoxy(40,11);cout<<TIEMPO[J];
       gotoxy(40,12);cout<<SB[J];
       gotoxy(40,13);cout<<LINEA[J];
       gotoxy(40,14);cout<<VTAS[J];
       gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
       getch();
       }
       break;
      }
     }
    break;
   case 3:
    MARCO();
    PANTALLAZO();
    gotoxy(32,6);cout<<"<<<LIQUIDACION>>>";
	for(J=0;J<I;J++)
	{
	 gotoxy(40,9);cout<<CEDULA[J];
	 gotoxy(40,10);cout<<NOMBRE[J];
	 gotoxy(40,11);cout<<TIEMPO[J];
	 gotoxy(40,12);cout<<SB[J];
	 gotoxy(40,13);cout<<LINEA[J];
	 gotoxy(40,14);cout<<VTAS[J];
	 PRIMA=SB[J]*TIEMPO[J]/100;
	 switch(LINEA[J]){
	  case 'T':
	   COMISION=LINEA_TV(VTAS[J]);
	   break;
	  case 'C':
	   COMISION=VTAS[J]*0.1;
	   break;
	  case 'E':
	   if(VTAS[J]>3000000)
	     COMISION=VTAS[J]*0.13;
	    else
	     COMISION=0;
	   break;
	  case 'M':
	   COMISION=LINEA_MUEBLES(VTAS[J]);
	   break;
	  case 'A':
	   COMISION=VTAS[J]*0.17;
	   break;
	 }
      SN=SB[J]+PRIMA+COMISION;
      gotoxy(32,16);cout<<"VALORES LIQUIDADOS";
      gotoxy(30,18);cout<<"PRIMA        ="<<setw(9)<<PRIMA;
      gotoxy(30,19);cout<<"COMISION     ="<<setw(9)<<COMISION;
      gotoxy(30,20);cout<<"SALARIO NETO ="<<setw(9)<<SN;
      gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
      getch();
      }
    break;
   case 4:
    OPCION='N';
    break;
    }
  }
}

int MENU()
{
 int OP;
 gotoxy(33,8);cout<<"<<<M E N U>>> ";
 gotoxy(30,11);cout<<"1 - CAPTURA DE DATOS ";
 gotoxy(30,12);cout<<"2 - CONSULTA DE DATOS ";
 gotoxy(30,13);cout<<"3 - LIQUIDACION";
 gotoxy(30,15);cout<<"4 - SALIR DEL MENU ";
 do{
    gotoxy(23,18);cout<<"Seleccione una de las opciones [  ]";
    gotoxy(55,18);cin>>OP;
    } while((OP<1)||(OP>4));
 return OP;
 }

void PANTALLAZO()
{
 gotoxy(17,9); cout<<"CEDULA               :[          ] ";
 gotoxy(17,10);cout<<"NOMBRES Y APELLIDOS  :[                                ]";
 gotoxy(17,11);cout<<"TIEMPO SERVICIO(A¥OS):[  ]";
 gotoxy(17,12);cout<<"ASIGNACION BµSICA    :[          ]";
 gotoxy(17,13);cout<<"LINEA DE ARTÖCULO    :[  ]";
 gotoxy(17,14);cout<<"VALOR DE LAS VENTAS  :[          ]";
 }

int SUBMENU()
{
 int OP;
 gotoxy(32,8);cout<<"<<<CONSULTA>>>";
 gotoxy(28,11);cout<<"1 - INDIVIDUAL POR EMPLEADO";
 gotoxy(28,12);cout<<"2 - TODOS LOS EMPLEADOS";
 gotoxy(28,14);cout<<"3 - SALIR DEL SUBMENU";
 do{
    gotoxy(23,16);cout<<"Seleccione una de las opciones [  ]";
    gotoxy(55,16);cin>>OP;
    } while((OP<1)||(OP>3));
 return OP;
 }

char LINEA_VENTA()
{
 char LINEA;
 do{
    gotoxy(7,22);cout<<"T->TV,C->COMPUTADORAS,E->ESTUFAS,M->MUEBLES,A->ADORNOS";
    gotoxy(40,13);cin>>LINEA;
    LINEA=toupper(LINEA);
    gotoxy(7,22);cout<<"                                                      ";
    } while((LINEA != 'T')&&(LINEA != 'C')&&(LINEA != 'E')&&(LINEA != 'A')&&(LINEA != 'M'));
  return LINEA;
}

float LINEA_TV(float VTAS)
{
 float COMISION;
 if(VTAS<4000000)
   COMISION=0;
  else
   if(VTAS<8000000)
     COMISION=VTAS*0.06;
    else
   if(VTAS<20000000)
     COMISION=VTAS*0.1;
    else
     COMISION=VTAS*0.15;
  return COMISION;
 }

float LINEA_MUEBLES(float VTAS)
{
 float COMISION;
 if(VTAS<7000000)
   COMISION=0;
  else
   if(VTAS<=9000000)
     COMISION=VTAS*0.09;
    else
     COMISION=VTAS*0.12;
  return COMISION;
 }

void MARCO()
{
  int x,y;
  clrscr();
  for(x=2;x<=79;x++)
  {
   gotoxy(x,2);cout<<"Û";
   gotoxy(x,24);cout<<"Û";
   delay(5);
  }
  for(y=2;y<=24;y++)
  {
   gotoxy(2,y);cout<<"Û";
   gotoxy(79,y);cout<<"Û";
   delay(5);
  }
}