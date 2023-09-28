#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
char FL(char TEXTO[79],int LARGO, char legal[20]);
main()
{
char opc[1];
opc[0]='1';
clrscr();
gotoxy(25,18);textcolor(10);cprintf("Seleccione una de las opciones [ ]");
gotoxy(57,18);
FL(opc,1,"123");//1. el numero que entra, 2.la longitud 3.los numeros que tiene
clrscr();
gotoxy(25,18);textcolor(9);cprintf("Seleccione una de las opciones [        ]");
gotoxy(57,18);
FL(opc,7,"0123456789ABCDEF");
getch();
}
char FL(char TEXTO[79],int LARGO, char legal[20])
  {
  int POSICION ;
  char TECLA ;
  POSICION=0;
  while ((TECLA=getch())!=13)
   {                    
     switch (TECLA)
     {  case 0 : getch(); break; 
	case 27 :exit(1);
	case 8 :  if (POSICION>0) {  TEXTO[POSICION-1]=0;cout<<TECLA;cout<<" ";cout<<TECLA;POSICION--;}break;
	default :   if (((legal[0] == 0)||(strchr(legal,TECLA)!=NULL)) && ((TECLA >= ' ') && (TECLA <= '~')) && (POSICION < LARGO))
		       { TEXTO[POSICION]=TECLA; cout<<TECLA;POSICION++;}break;
      }
   }
   gotoxy(25,10);textcolor(9);cprintf("PRESIONE ECS PARA SALIR");
  TEXTO[POSICION+1]=NULL;
  return TEXTO[POSICION];
  }
