# include <iostream.h>
# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <time.h>
# include <iomanip.h>
# include <math.h>
# include <string.h>
# include <dos.h>
void PANTALLAZO();
void CUADRO();
void PRES();
void main(void)
{
 textcolor(2);
 textbackground(1);
 PANTALLAZO();
 CUADRO();
 PRES();
}
 void PANTALLAZO()
 {
  int X,Y,J=80,K=24,T=0,L=2,M=79,H=24;
  clrscr();
  gotoxy(32,13);cout<<"PRESENTACION";
  while(T<12)
  {
   --J;
   for(X=2;X<=J;X++)   
   {
    gotoxy(X,L);cout<<"²";
    gotoxy(X,H);cout<<"²";
    delay(10);
    }
   --K;
   for(Y=2;Y<=K;Y++)
   {
    gotoxy(L,Y);cout<<"²";
    gotoxy(M,Y);cout<<"²";
    delay(10);
    }
   delay(10);
   ++T,++L,--M,--H;
   }
   clrscr();
 }
void CUADRO()
{
  int x,y;
  for(x=2;x<=79;x++)
  {
   gotoxy(x,2);cout<<"Û";
   gotoxy(x,24);cout<<"Û";
   delay(30);
  }
  for(y=2;y<=24;y++)
  {
   gotoxy(2,y);cout<<"Û";
   gotoxy(79,y);cout<<"Û";
   delay(30);
  }
}
void PRES()
{ 
 gotoxy(26,5);cout<<"PARCIAL FINAL DE PROGRAMACION";
 gotoxy(22,8);cout<<"Profesor: CARLOS EMILIANO O¥ATE GOMEZ";
 gotoxy(22,10);cout<<"Presentado por:";
 gotoxy(26,12);cout<<"ALVARO ALFONSO CARRILLO ARAUJO";
 gotoxy(26,13);cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXX";
 gotoxy(30,15);cout<<"­ FUTUROS INGENIEROS !";
 gotoxy(32,22);cout<<"NOTA PARCIAL = 20%";
 delay(10000);
}	     