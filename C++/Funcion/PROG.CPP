#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <stdio.h>

void main(void)
{
 int tec;
 textcolor(0);
 textbackground(7);
 clrscr();
 _setcursortype(_NOCURSOR);
 textbackground(6);window(1,23,80,25);clrscr();
 gotoxy(3,2);textcolor(0);cprintf("INICIO");
 tec=getch();
 if (tec==13){
   textbackground(7);window(2,24,9,24);clrscr();
   gotoxy(2,1);textcolor(0);cprintf("INICIO");
   textbackground(6);window(2,12,10,22);clrscr();}
 getch();
}
