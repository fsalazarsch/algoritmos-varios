#include "dos.h"
#include "ctype.h"
#include "iostream.h"
#include "conio.h"
void fib();
void CUADRO(int ci, int cf, int fi, int ff);
main()
{
 char op = 's';
 while ( op== 's')
  {
   window(1,1,80,25);
   clrscr();
   gotoxy(32,3);cout<<"LA SERIE FIBONACCI";
   CUADRO(1,80,1,24);
   fib();
   do {
   gotoxy(24,22);cout<<"DESEA CONTINUAR S/N [ ] ";
   gotoxy(45,22);
   op= getch();
   op = tolower(op);
   }while((op!='s')&&(op != 'n'));
  }
return(0);
}
//**********************************************************

void fib()
{
  long n,i,a =0,b = 1,suma = 0;int CONT=0;
  gotoxy(24,8);cout<<"digite un numero para la serie: ";
  cin>>n; 
    gotoxy(30,22);cprintf("²²²²²²²²²²²²²²²²²²²²²");
	      for(int h = 30; h <= 50; h++)
	      {
	      gotoxy(56,22),cout<<"%";
	      gotoxy(53,22);cout<<CONT;
	      textbackground(BLUE);
	      gotoxy(h,22);cprintf(" ");
	      textbackground(0);
	      delay(70);
	      CONT+=5;
	      }
	    gotoxy(30,22);clreol();CUADRO(1,80,1,24);
  gotoxy(7,12);cout<<"Esta es la serie: ";
  gotoxy(7,15);
  cout<< b;
   for (i=1; i < n;i++)
   {
    suma = a+b;
    a = b;
    b = suma;
    delay(150);cout<<" "<<suma<<" ";
    }
 }

void CUADRO(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Í";
gotoxy(o,ff); cout<<"Í";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"º";
gotoxy(cf,o); cout<<"º";
}
gotoxy(ci,fi); cout<<"É";
gotoxy(cf,fi); cout<<"»";
gotoxy(ci,ff); cout<<"È";
gotoxy(cf,ff); cout<<"¼";

}
