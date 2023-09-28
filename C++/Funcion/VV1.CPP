#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<alvaro.h>




main()
{
int k,m;
textbackground(BLACK);
clrscr();
//******************FONDO******************************
 for(k = 1; k <= 24; k++)
   for(m = 1; m <= 80; m++)
   {
      textmode(2);
      textbackground(15);//blanco
      textcolor(1);//azul
      gotoxy(m,k);cprintf("°");
    }
//*********************************************          
	window(1,1,80,1);clreol();
	window(1,1,80,25); //las cordenadas del cuadro grande 
	textcolor(0);
	gotoxy(4,1); PS("Adicionar");
	gotoxy (21,1);PS(" Listados ");
	gotoxy (36,1);PS(" Modificar ");
	gotoxy (52,1);PS(" Eliminar ");
	gotoxy (68,1);PS(" Terminar ");
	textcolor(4);
	gotoxy(4,1); cprintf(" A");
	gotoxy (21,1); cprintf(" L");
	gotoxy (36,1); cprintf(" M");
	gotoxy (52,1); cprintf(" E");
	gotoxy (68,1); cprintf(" T");
//*********************************************    
	window(1,25,80,25);clreol();
	window(1,1,80,25); //las cordenadas del cuadro grande 
	textcolor(0);
	gotoxy(4,25); PS(" Alvaro");
	gotoxy (21,25);PS(" Alvaro ");
	gotoxy (36,25);PS(" Alvaro ");
	gotoxy (52,25);PS(" Alvaro ");
	gotoxy (68,25);PS(" Alvaro ");
    getch();
 }



