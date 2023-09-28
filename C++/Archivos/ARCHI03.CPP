//*********archivos**********************

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <dos.h>
#include <fstream.h>
#include <iomanip.h>
void marco();
int menu();
void pantallazo();
void captura();
void consulta();
void liquidacion();
int submenu();
void detalle();
void detalle_sn();
char linea_venta();
float linea_tv(float vtas);
float linea_muebles(float vtas);
  struct REGISTRO{
   long cedula;
   char nombre[30];
   float sb;
   int tiempo;
   char linea;
   float vtas;
   }EMP;
  void main(void)
     {
     char op='S';
     int sw;
     while (op=='S')
       {
       textcolor(2);
       textbackground(9);
       marco();
       sw=menu();
       switch(sw){
	case 1 :
	  captura();
	break;
	case 2:
	  consulta();
	break;
	case 3:
	  liquidacion();
	break;
	case 4:
	  op='N';
	break;
       }
     }
    }
int menu()
{
int op;
gotoxy(36,8); cout<<"M E N U";
gotoxy(30,11); cout<<"1. CAPTURA DE DATOS";
gotoxy(30,12); cout<<"2. CONSULTA DE DATOS";
gotoxy(30,13); cout<<"3. LIQUIDACION";
gotoxy(30,15); cout<<"4. salir del menu";
do{
gotoxy(23,18); cout<<"seleccione una de las opciones : ";
gotoxy(57,18); cin>>op;
} while ((op<1)||(op>4));
return op;
}
void pantallazo()
{
gotoxy(15,9); cout<<"CEDULA                   :";
gotoxy(15,10); cout<<"NOMBRES Y APELLIDOS      :";
gotoxy(15,11); cout<<"TIEMPO DE SERVICIOS(ANOS):";
gotoxy(15,12); cout<<"ASIGNACION BASICA        :";
gotoxy(15,13); cout<<"LINEA DE ARTICULO        :";
gotoxy(15,14); cout<<"VALOR EN LAS VENTAS      :";
}
int submenu()
{
int op;
gotoxy(33,8); cout<<"C O N S U L T A";
gotoxy(28,11); cout<<"1. INDIVIDUAL POR EMPLEADO";
gotoxy(28,12); cout<<"2. TODOS LOS EMPLEADOS";
gotoxy(28,14); cout<<"3. salir del sub-menu";
do{
gotoxy(23,16); cout<<"seleccione una de las opciones : ";
gotoxy(57,16); cin>>op;
} while ((op<1)||(op>3));
return op;
}
void marco()
{
int i;
clrscr();
gotoxy(32,4); cout<<"ALMACEN LA TRAMPA";
gotoxy(24,5); cout<<"PROCESO DE LIQUIDACION DE NOMINA";
for (i=2;i<=79;i++)
{
gotoxy(i,2); cout<<"²";
gotoxy(i,24); cout<<"²";
delay(0);
}
for (i=3;i<=23;i++)
{
gotoxy(2,i); cout<<"²²";
gotoxy(78,i); cout<<"²²";
delay(0);
}
}
void captura()
{
char cap='S';
ofstream ARCHIVO("c:\VENDEDOR.DAT");
while (cap=='S')
{
marco();
pantallazo();
gotoxy(32,6); cout<<"CAPTURA DE DATOS";
gotoxy(42,9); cin>>EMP.cedula;
gotoxy(42,10); gets(EMP.nombre);
gotoxy(42,11); cin>>EMP.tiempo;
gotoxy(42,12); cin>>EMP.sb;
EMP.linea=linea_venta();
gotoxy(42,14); cin>>EMP.vtas;
ARCHIVO.write((char  *)&EMP,sizeof(REGISTRO));
do{
gotoxy(25,18); cout<<"Desea seguir capturando S/N : ";
gotoxy(57,18); cap=getch();
cap=toupper(cap);
}while ((cap!='S')&&(cap!='N'));
}
ARCHIVO.close();
}
char linea_venta()
{
char linea;
do {
gotoxy(15,22); cout<<"T->TV, C->COMPUTADOR, E->ESTUFA, M->MUEBLES, A->ADORNOS";
gotoxy(42,13); cin>>linea;
linea=toupper(linea);
gotoxy(15,22); cout<<"                                                         ";
}
while ((linea!='E')&&(linea!='T')&&(linea!='A')&&(linea!='C')&&(linea!='M'));
return linea;
}
void detalle()
{
gotoxy(6,8); cout<<"CEDULA  NOMBRES Y APELLIDOS       TIEMPO  BASICO  LINEA  VENTAS";
}
void detalle_sn()
{
gotoxy(6,8); cout<<"CEDULA  NOMBRES Y APELLIDOS     BASICO  PRIMA  COMISION    NETO";
}
void consulta()
{
long ced;
int f,sub=1;
char sw='S';
marco();
ifstream ARCHIVO("c:\VENDEDOR.DAT");
if (ARCHIVO.fail())
{
gotoxy(26,12); cout<<"El archivo no existe",getch();
sub=3;
}
while (sub!=3)
{
marco();
sub=submenu();
switch (sub){
case 1 :
marco();
gotoxy(30,6); cout<<"CONSULTA POR EMPLEADO";
gotoxy(15,8); cout<<"CEDULA           :[              ]";
gotoxy(40,8); cin>>ced;
while (!ARCHIVO.eof()&&(sw=='S'))
{
ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
if (ced==EMP.cedula)
sw='N';
}
if (!ARCHIVO.eof())
{
gotoxy(15,12); cout<<"Empleado no existe.....!";getch();

}
else
{
pantallazo();
gotoxy(42,9); cout<<EMP.cedula;
gotoxy(42,10); cout<<EMP.nombre;
gotoxy(42,11); cout<<EMP.tiempo;
gotoxy(42,12); cout<<EMP.sb;
gotoxy(42,13); cout<<EMP.linea;
gotoxy(42,14); cout<<EMP.vtas;
gotoxy(21,22); cout<<"Pulse cualquier tecla para continuar";getch();
}
break;
case 2:
marco();
gotoxy(26,6); cout<<"CONSULTA TODOS LOS EMPLEADOS";
detalle();
f=10;
while(!ARCHIVO .eof())
{
ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
if (ARCHIVO.eof()) break;
else{
gotoxy(2,f); cout<<setw(8)<<EMP.cedula;
gotoxy(15,f); cout<<EMP.nombre;
gotoxy(45,f); cout<<setw(2)<<EMP.tiempo;
gotoxy(50,f); cout<<setw(8)<<EMP.sb;
gotoxy(60,f); cout<<EMP.linea;
gotoxy(62,f); cout<<setw(10)<<EMP.vtas;
if (f<=20)
f++;
else{
gotoxy(21,22); cout<<"Pulse cualquier tecla para continuar";getch();
marco();
detalle();
f=10;
}
}
gotoxy(21,22); cout<<"Pulse cualquier tecla para continuar";getch();
break;
}
}
}
ARCHIVO.close();
}
void liquidacion()
{
int f;
char sw='S';
float prima,comision,sn;
ifstream ARCHIVO("VENDEDOR.DAT");
  marco();
if (ARCHIVO.fail())
{
gotoxy(26,12); cout<<"archivo no existe....ojo";getch();
sw='N';
}
else
{
gotoxy(35,6); cout<<"LIQUIDACION";
f=10;
detalle_sn();
}
while((!ARCHIVO.eof())&&(sw!='N'))
{
ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
if (ARCHIVO.eof()) break;
gotoxy(5,f); cout<<EMP.cedula;
gotoxy(15,f); cout<<EMP.nombre;
prima=EMP.sb*EMP.tiempo/100;
switch(EMP.linea){
case 'T':
comision=linea_tv(EMP.vtas);
break;
case 'C':
comision=EMP.vtas*0.10;
break;
case 'E':
if (EMP.vtas>3000000)
comision=EMP.vtas*0.13;
else
comision=0;
break;
case 'M':
comision=linea_muebles(EMP.vtas);
break;
case 'A':
comision=EMP.vtas*0.17;
break;
}
sn=EMP.sb+prima+comision;
gotoxy(41,f); cout<<setw(8)<<EMP.sb;
gotoxy(51,f); cout<<setw(6)<<prima;
gotoxy(59,f); cout<<setw(8)<<comision;
gotoxy(69,f); cout<<setw(8)<<sn;
if (f<=20)
f++;
else
{
gotoxy(21,22); cout<<"Pulse cualquier tecla para continuar";getch();
marco();
detalle();
f=10;
}
}
gotoxy(21,22); cout<<"Pulse cualquier tacla para continuar";getch();
ARCHIVO.close();
}
float linea_tv(float vtas)
    {
     float comision;
     if (vtas < 4000000)
	 comision=0;
      else
	if (vtas < 8000000)
	    comision =vtas*0.06;
	 else
	   if (vtas<=20000000)
	      comision=vtas*0.10;
	    else
	      comision=vtas*0.15;
     return comision;
    }
float linea_muebles(float vtas)
    {
     float comision;
     if (vtas <7000000)
	comision=0;
      else
	if (vtas<=9000000)
	   comision=vtas*0.09;
	 else
	   comision=vtas*0.12;
      return comision;
   }