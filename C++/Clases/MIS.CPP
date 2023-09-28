#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <dos.H>
#include <ctype.h>
#include <alvaro.h>

int main(void)
{
 alv calculo;
 int i,s=2000;
 textcolor(7); textbackground(BLACK);
 clrscr();
 textbackground(WHITE);
 for(i=2;i<=24;i+=2){
   calculo.MES(1,80,i);}
 for(i=2;i<=30;i+=4)  {
  calculo.MIS(2,24,i);}
 gotoxy(2,2);
 getch();window(1,1,80,24);clrscr();
}

