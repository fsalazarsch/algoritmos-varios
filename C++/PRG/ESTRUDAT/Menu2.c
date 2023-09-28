#include<stdio.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<io.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

/********** DEFINICION DEL REGISTRO DEL ARCHIVO FACTURA.DAT  **************/
// struct  
//{
// long num_fac;
// char clase_fac;
// float iva_fac;
// float valor_fac;
// float desc_fac;
//}factura;
 
/****************  REGISTRO PARA EL ARCHIVO DE ABONOS  ********************/
//struct 
//{
// long num_fac;
// float abono_fac;
//}aporte;

//struct factura registro1;
//struct aporte registro2;

char valido,cod[20];
int i;
int lon,st;
int sw,aux,aux2;
int ld1,ld2; /*******  Descriptores de archivo  *******/
long num;
float valor; 

/**************************************************************************/
/****************  DECLARACION  DE  FUNCIONES *****************************/
/**************************************************************************/  
void consultar();
void adicionar();
void visualizar();
void eliminar();
void buscar();
void elemento_mayor();
void menu();
void main()
{
  menu();
}
/**************************************************************************/
/*********************  M E N U     P R I N C I P A L *********************/
/**************************************************************************/
void menu()
{
 int op,i;
 char SALIR,tecla;
 do
 {
  SALIR='N';
  for(i=1;i<25;i++)
  {                       
   textcolor(15);                                                                         
   gotoxy(1,i);cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"); /** ALT 219 **/
  }
  textbackground(9);
  window(4,3,79,5);
  clrscr();
  textbackground(RED);
  window(2,2,77,4);
  clrscr();
  textcolor(15);
  gotoxy(24,2);cprintf("M E N U     P R I N C I P A L");
  textbackground(9);
  window(4,22,79,24);
  clrscr();
  textbackground(RED);
  window(2,21,77,23);
  clrscr();
  gotoxy(12,2);printf("UTILICE LAS TECLAS (%c%c) DEL CURSOR Y PRESIONE Ў ENTER Џ ",24,25);  
  textbackground(9);
  window(24,9,59,18);
  clrscr();
  textbackground(RED);
  window(22,8,57,17);
  clrscr();
  gotoxy(4,3);cprintf("1. CREAR ARCHIVO DE FACTURA");
  gotoxy(4,4);cprintf("2. CREAR ARCHIVO DE APORTE");
  gotoxy(4,5);cprintf("3. ELABORAR FACTURA ");
  gotoxy(4,6);cprintf("4. ASIGNAR APORTES");
  gotoxy(4,7);cprintf("5. CONSULTAR FACTURAS");
  gotoxy(4,8);cprintf("6. CONSULTAR APORTES");
  gotoxy(4,9);cprintf("7. SALIR DEL MENU");
  textcolor(15);
  gotoxy(2,3);cprintf("%c",2);
  gotoxy(2,3);
  do
  {
   tecla=getch();
   if(tecla==72)
   {
    printf("  ");
    if(wherey()==3)
    {
     gotoxy(2,wherey()+6);
     cprintf("%c",2);
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()-1);cprintf("%c",2);
     gotoxy(2,wherey());
    }
   }
   if(tecla==80)
   {
    printf("  ");
    if(wherey()==9)
    {
     gotoxy(2,wherey()-6);cprintf("%c",2);
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()+1);
     cprintf("%c",2);
     gotoxy(2,wherey());
    }
   }
  } while(tecla!=13);

  op=wherey();
  if(op==9)
  {
   SALIR='S';
  }
  else
  {
   switch(op)
   {
    //case 1:{adicionar();break;}
    //case 2:{eliminar();break; }
    //case 3:{visualizar();break;}
    //case 4:{consultar();break;}
    //case 5:{elemento_mayor();break;}
      case 7:exit(0);break;
   }
  }
 } while(SALIR!='S');
}



