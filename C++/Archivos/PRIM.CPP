//**************ARCHIVOS***************************

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdio.h>

int MENU();void MARCO(); void PANTALLAZO();void CAPTURA();
void CONSULTA();void LIQUIDACION();void DETALLE();
void DETALLE_SN();char LINEA_VENTA();float LINEA_TV(float VTAS);
int SUBMENU();float LINEA_MUEBLES(float VTAS);

struct REGISTRO{
   long CEDULA;
   char NOM[30];
   float SB;
   int TIEMPO;
   char LINEA;
   float VTAS;
   } EMP;

void main(void)
{
 char OP='S';
 int SW;
 textcolor(1);
 textbackground(2);
 while(OP == 'S')
 {
  MARCO();
  SW=MENU();
  switch(SW){
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
     OP='N';
     break;
   }
 }
}

int MENU()
{
 int OP;
 gotoxy(36,8);cout<<"M E N U";
 gotoxy(30,11);cout<<"1- CAPTURA DE DATOS";
 gotoxy(30,12);cout<<"2- CONSULTA DE DATOS";
 gotoxy(30,13);cout<<"3- LIQUIDACION";
 gotoxy(30,15);cout<<"4- Salir del Menu";
 do{
    gotoxy(23,18);cout<<"Seleccione una de las opciones  :[ ]";
    gotoxy(57,18);cin>>OP;
    }while((OP<1)||(OP>4));
 return OP;
 }

void PANTALLAZO()
{
 gotoxy(14,9);cout<< "CEDULA                  :[        ]";
 gotoxy(14,10);cout<<"NOMBRES Y APELLIDOS     :[                             ]";
 gotoxy(14,11);cout<<"TIEMPO DE SERVICIO(A¥OS):[  ]";
 gotoxy(14,12);cout<<"ASIGNACION BASICA       :[        ]";
 gotoxy(14,13);cout<<"LINEA DE ARTICULO       :[  ]";
 gotoxy(14,14);cout<<"VALOR DE LAS VENTAS     :[        ]";
 }

int SUBMENU()
{
 int OP;
 gotoxy(33,8);cout<<"C O N S U L T A";
 gotoxy(28,11);cout<<"1- INDIVIDUAL POR EMPLEADO";
 gotoxy(28,12);cout<<"2- TODOS LOS EMPLEADOS";
 gotoxy(28,13);cout<<"3- Salir del Sub-Menu";
 do{
    gotoxy(23,16);cout<<"Seleccione una de las opciones:[ ]";
    gotoxy(55,16);cin>>OP;
    }while((OP<1)||(OP>3));
 return OP;
 }

void MARCO()
{
 int I;
 clrscr();
 sound(1000);
 delay(100);
 nosound();
 textcolor(4);
 textbackground(7);
 gotoxy(32,4);cout<<"ALMACEN LA TRAMPA";
 gotoxy(24,5);cout<<"Proceso de Liquidaci¢n N¢mina";
 for(I=2;I<=79;I++)
 {
  gotoxy(I,2);cout<<"Î";
  gotoxy(I,24);cout<<"Î";
  delay(10);
 }
 for(I=2;I<=24;I++)
 {
  gotoxy(2,I);cout<<"Î";
  gotoxy(79,I);cout<<"Î";
  delay(10);
 }
}

void CAPTURA()
{ 
 char CAP='S';
 ofstream ARCHIVO("C:\VENDEDOR.DAT",ios::app);
 while(CAP == 'S')
 {
  MARCO();
  PANTALLAZO();
  gotoxy(32,6);cout<<"CAPTURA DE DATOS";
  gotoxy(40,9);cin>>EMP.CEDULA;
  gotoxy(40,10);gets(EMP.NOM);
  gotoxy(40,11);cin>>EMP.TIEMPO;
  gotoxy(40,12);cin>>EMP.SB;
  EMP.LINEA=LINEA_VENTA();
  gotoxy(40,14);cin>>EMP.VTAS;
  ARCHIVO.write((char *)&EMP,sizeof(REGISTRO));
  do{
    gotoxy(23,18);cout<<"DESEA SEGUIR CAPTURANDO -S/N- [ ]";
    gotoxy(54,18);cin>>CAP;
    CAP=toupper(CAP);
    }while((CAP!='S')&&(CAP!='N'));
  }
  ARCHIVO.close();
 }

char LINEA_VENTA()
{
 char LINEA;
 do{
    gotoxy(7,22);cout<<"T->Televisores,C->Computadoras,E->Estufas,M->Muebles,A->Adornos";
    gotoxy(40,13);cin>>LINEA;
    LINEA=toupper(LINEA);
    gotoxy(7,22);cout<<"                                                               ";
    }while((LINEA!='T')&&(LINEA!='C')&&(LINEA!='E')&&(LINEA!='A')&&(LINEA!='M'));
  return LINEA;
  }

void DETALLE()
{
 gotoxy(4,8);cout<<" CEDULA      NOMBRES  Y  APELLIDOS     TIEMPO    BASICO  LINEA     VENTAS";
 }

void DETALLE_SN()
{ 
 gotoxy(3,8);cout<<" CEDULA   NOMBRES Y APELLIDOS      BASICO    PRIMA    COMISION      NETO";
 }

void CONSULTA()
{
 long CED;
 int F,SUB=1;
 MARCO();
 ifstream ARCHIVO("C:\VENDEDOR.DAT");
 if(ARCHIVO.fail())
 {
  gotoxy(26,12);cout<<"ARCHIVO NO EXISTE......OJO";
  getch();
  SUB=3;
  }
 while(SUB != 3)
 {
  MARCO();
  SUB=SUBMENU();
  switch(SUB){
   case 1:
    MARCO();
    if(ARCHIVO.eof())
     {
      ifstream ARCHIVO("C:\VENDEDOR.DAT");
      }
    gotoxy(30,6);cout<<"CONSULTA POR EMPLEADO";
    gotoxy(15,9);cout<<"CEDULA                :[         ]";
    gotoxy(39,9);cin>>CED;
    while(! ARCHIVO.eof())
    {
     ARCHIVO.read((char *) &EMP,sizeof(REGISTRO));
     if(CED == EMP.CEDULA)
      {
       PANTALLAZO();
       gotoxy(40,9);cout<<EMP.CEDULA;
       gotoxy(40,10);cout<<EMP.NOM;
       gotoxy(40,11);cout<<EMP.TIEMPO;
       gotoxy(40,12);cout<<EMP.SB;
       gotoxy(40,13);cout<<EMP.LINEA;
       gotoxy(40,14);cout<<EMP.VTAS;
       gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
       getch();
       break;
       }
     } 
    break;
   case 2:
    MARCO();
    gotoxy(26,6);cout<<"CONSULTA TODOS LOS EMPLEADOS";
    DETALLE();
    F=10;
    while(! ARCHIVO.eof())
    {
     ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
     gotoxy(4,F);cout<<setw(8)<<EMP.CEDULA;
     gotoxy(18,F);cout<<EMP.NOM;
     gotoxy(45,F);cout<<setw(2)<<EMP.TIEMPO;
     gotoxy(51,F);cout<<setw(8)<<EMP.SB;
     gotoxy(63,F);cout<<EMP.LINEA;
     gotoxy(68,F);cout<<setw(10)<<EMP.VTAS;
     if(F<=20)
       F++;
      else
       {
	gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
	getch();
	MARCO();
	DETALLE();
	F=10;
	}
     }
   gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
   getch();
   break;
  }
 }
 ARCHIVO.close();
}

void LIQUIDACION()
{
 int F;
 char SW='S';
 float PRIMA,COM,SN;
 ifstream ARCHIVO("C:\VENDEDOR.DAT");
 MARCO();
 if(ARCHIVO.fail())
   {
    gotoxy(26,12);cout<<"ARCHIVO NO EXISTE......OJO"; 
    getch();
    SW='N';
    }
  else
   {
    gotoxy(35,6);cout<<"LIQUIDACION";
    F=10;
    DETALLE_SN();
    }
  while(! ARCHIVO.eof() && (SW !='N'))
    {
     ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
     if(ARCHIVO.eof()) break;
     gotoxy(3,F);cout<<EMP.CEDULA;
     gotoxy(13,F);cout<<EMP.NOM;
     PRIMA=EMP.SB*EMP.TIEMPO/100;
     switch(EMP.LINEA){
      case 'T':
       COM=LINEA_TV(EMP.VTAS);
       break;
      case 'C':
       COM=EMP.VTAS*0.1;
       break;
      case 'E':
       if(EMP.VTAS>3000000)
	 COM=EMP.VTAS*0.13;
	else
	 COM=0;
       break;
      case 'M':
       COM=LINEA_MUEBLES(EMP.VTAS);
       break;
      case 'A':
       COM=EMP.VTAS*0.17;
       break;
      }
   SN=EMP.SB+PRIMA+COM;
   gotoxy(36,F);cout<<setw(8)<<EMP.SB;
   gotoxy(48,F);cout<<setw(6)<<PRIMA;
   gotoxy(56,F);cout<<setw(8)<<COM;
   gotoxy(67,F);cout<<setw(8)<<SN;
   if(F>=20)
     F++;
    else
     {
       gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
       getch();
       MARCO();
       DETALLE();
       F=10;
       }
    }
  gotoxy(21,22);cout<<"Pulse cualquier tecla para continuar...";
  getch();
  ARCHIVO.close();
 }

float LINEA_TV(float VTAS)
{
 float COM;
 if(VTAS<4000000)
   COM=0;
  else
   if(VTAS<8000000)
     COM=VTAS*0.06;
    else
     if(VTAS<=20000000)
       COM=VTAS*0.1;
      else
       COM=VTAS*0.15;
  return COM;
 }

float LINEA_MUEBLES(float VTAS)
{
 float COM;
 if(VTAS<7000000)
   COM=0;
  else
   if(VTAS<=9000000)
     COM=VTAS*0.09;
    else
     COM=VTAS*0.12;
  return COM;
 }


 


    

    
 