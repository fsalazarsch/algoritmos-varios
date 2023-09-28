#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip.h>
#include<dos.h>

long fact(int n);
void CUADRO(int ci, int cf, int fi, int ff);
main(){
 long f;
 int n,CONT=0;
 clrscr();
 CUADRO(1,80,1,24);
 gotoxy(30,4);cout<<"FACTORIAL DE UN NUMERO";
 gotoxy(20,10);cout<<"Digite un numero  ";cin>>n;
 f = fact(n);
  gotoxy(30,15);cprintf("²²²²²²²²²²²²²²²²²²²²²");
	      for(int h = 30; h <= 50; h++)
	      {
	      gotoxy(56,15),cout<<"%";
	      gotoxy(53,15);cout<<CONT;
	      textbackground(BLUE);
	      gotoxy(h,15);cprintf(" ");
	      textbackground(0);
	      delay(70);
	      CONT+=5;
	      }
 gotoxy(20,22);cout<<"El factorial del numero es  "<<f;
 getch();
}

long fact(int n)
{
 int fat,i;
     fat = 1;
     for (i = 1;i<=n; i++)
      {
	fat = fat * i;
	}
	return(fat);
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
