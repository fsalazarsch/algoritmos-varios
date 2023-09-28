#include <conio.h>   
#include <graphics.h>
#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>


void main()
 {
  int a,b,c,d,e,f,g,h,p;
  b=25; h=25; c=25; d=25; e=25; f=25; g=25; p=8000;
  clrscr();
  textcolor(15);textbackground(1);
  for(a=22; a>=5; a=a-2)
  {
   sound(p);
   gotoxy(30,a);printf("    ADVERTENCIA    ");

   if(a<=22)
   {
    gotoxy(5,b);printf("Este progama fue dise¤ado por el preingeniero: UBALDO MURGAS GRANADOS ");
    b=b-2;
   }

   if(a<=20)
   {
    gotoxy(5,c);printf(", con el fin obtener una muy buena nota en el tercer parcial  de ");
    c=c-2;
    }

   if(a<=18)
   {
    gotoxy(5,d);printf("de GRAFOS y a su vez prohibe la reproducci¢n y copia  del  mismo , como ");
    d=d-2;
    } 

   if(a<=16)
   {
    gotoxy(5,e);printf("seguridad tiene una clave de acceso que brinda tres oportunidades para ");
    e=e-2;
    }  

   if(a<=14)
   {
    gotoxy(5,f);printf("poder ingresar y aprovechar de su servicio , en caso de no  digitar la ");
    f=f-2;
    } 

   if(a<=12)
   {
    gotoxy(5,g);printf("clave correcta el programa automaticamente lo sacara del sistema y  lo ");
    g=g-2;
    }

   if(a<=10)
   {
    gotoxy(5,h);printf("mandara hacia la parte teor¡ca del programa. ");
    h=h-2;
    }   

  if(a>6)
  {
   delay(1000); 
   clrscr();
  }

  p=p+500;

  }
  nosound();
  getch();
}


//------------------------------------------------------------------------------
