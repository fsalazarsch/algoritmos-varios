#include <conio.h>
#include <iostream.h>
#define PRS cout<<"ALVARO"
#define PSS(x) textcolor(i+125);cprintf("%s\n",x)


int main(void)
{  int i;
   clrscr();

   textmode(BW40);  //modo grafico
   i=5;
   gotoxy(10,5);PSS("ALVARO\n");
   getch();

   textmode(C40); //modo grafico en 40 columnas
   i=8;
   gotoxy(20,5);PSS("ALVARO\n");
   getch();

   textmode(BW80); //modo normal
   gotoxy(30,5); PRS;//("ALVARO");
   getch();

   textmode(C80); //modo normal
   gotoxy(40,5);PRS;//("ALVARO");
   getch();

  textmode(MONO);  //modo a blanco y negro
   gotoxy(50,5);PRS;//("ALVARO");
   getch();

   textmode(C4350);  //modo grafico peque¤o
   gotoxy(60,5);PRS;//("ALVARO");
   getch();

}
