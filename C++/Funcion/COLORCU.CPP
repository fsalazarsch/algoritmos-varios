#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
void main(void)
{

textbackground(BLACK);
clrscr();
int k,m,p;
p=100;
//******************FONDO******************************
 for(k = 1; k <= 24; k++)
   for(m = 1; m <= 80; m++)
   {
      p+=100;
      sound(p);
      delay(1);
      nosound();
      textcolor(WHITE);
      gotoxy(m,k);cprintf("²");
      delay(1);
      }
//*****************RAYAS-HORIZONTALES***************************
      for (m = 1; m <= 80; m++)
	 {
	  p+=100;
	 sound(p);
	 delay(5);
	  nosound();
	 textcolor(2);
	 gotoxy(m,1);cprintf("õ");
	 gotoxy(m,24);cprintf("õ");
	 delay(5);
	 }
//*****************RAYAS-VERTICALES***************************
	for (m = 1; m <= 24; m++)
	 {
	 p+=100;
	 sound(p);
	 delay(5);
	  nosound();
	 textcolor(2);
	 gotoxy(1,m);cprintf("õõ");
	 gotoxy(79,m);cprintf("õõ");
	 delay(5);
	 }

//*****************1.CUADRO***************************
//*****************SOMBRA***************************
       for(k = 4; k <= 8; k++)   //FILAS
	 for(m = 20; m <= 60; m++)  //COLUMNAS
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" "); 
	   }
//*****************1.CUADRO***************************
//*****************CUADRO*************************
	  for(k = 3; k <= 7; k++)
	    for(m = 18; m <= 58; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" "); 
	  }	  
//*****************2.CUADRO***************************

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

//*****************3.CUADRO***************************
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
	  getch();
      }


