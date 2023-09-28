#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<ctype.h>
#include<stdlib.h>


void colores(int , int );
void colores(int x, int y)
  {
    textcolor(x);
    textbackground(y);
  }

void pos(int , int );
void pos(int x, int y)
  {
    gotoxy(y,x);
  }

char op;
   void cuadro(int fil1, int fil2, int col1, int col2)
	     {
	     int i;
	     for(i=col1+1;i<=col2;i++)
	     {
	     gotoxy(i,fil1);cprintf("Í");
	     gotoxy(i,fil2);cprintf("Í");
	     }
	     for(i=fil1+1;i<=fil2;i++)
	     {
	     gotoxy(col1,i);cprintf("º");
	     gotoxy(col2,i);cprintf("º");
	     delay(10);
	     }
	     gotoxy(col1,fil1);cprintf("É");
	     gotoxy(col1,fil2);cprintf("È");
	     gotoxy(col2,fil2);cprintf("¼");
	     gotoxy(col2,fil1);cprintf("»");
	     delay(10);
	     }

      void menu_principal()
      {

      gotoxy(22,3);cprintf(" CORPORACION UNIVERSITARIA DE SANTANDER ");
      gotoxy(38,4);cprintf(" U D E S ");
      gotoxy(32,5);cprintf("INGENIERIA DE SISTEMAS");
      gotoxy(41,6);cprintf("S2A");
      gotoxy(32,7);cprintf(" V A L L E D U P A R ");
      gotoxy(32,11);cprintf("1        CREAR ");
      gotoxy(32,12);cprintf("2      CONSULTAR");
      gotoxy(32,13);cprintf("3      MODIFICAR");
      gotoxy(32,14);cprintf("4      ELIMINAR");
      gotoxy(32,15);cprintf("5        EXIT   ");
      gotoxy(32,16);cprintf("ELIGA UNA OPCION:[ ]");

      }

       void Crear()
       {
       clrscr();
       cuadro(1,24,1,80);//cuadro grande//
       pos(12,30);printf("ESTA ES LA OPCION CREAR ");
       getch();
       }
       void Consultar()
       {
       clrscr();
       cuadro(1,24,1,80);//cuadro grande//
       pos(12,30);printf("ESTA ES LA OPCION CONSULTAR");
       getch();
       }
       void Modificar()
       {
       clrscr();
       cuadro(1,24,1,80);//cuadro grande//
       pos(12,30);printf("ESTA ES LA OPCION MODIFICAR");
       getch();
       }
       void Eliminar()
       {
       clrscr();
       cuadro(1,24,1,80);//cuadro grande//
       pos(12,30);printf("ESTA ES LA OPCION ELIMINAR");
       getch();
       }
       void main()
       {
	 while (1)
	 {
	   clrscr();
	   colores(10,13);
	   cuadro(1,24,1,80);//cuadro grande//
	   cuadro(10,17,29,55);//cuadro central//
	   cuadro(2,8,21,62); //cuadro udes//
	   menu_principal();
	   pos(16,50);op=getchar();
	   switch(op)
	   {
	    case '1':Crear();break;
	    case '2':Consultar();break;
	    case '3':Modificar();break;
	    case '4':Eliminar();break;
	    case '5':exit(0);
	   }
	 }
       }
