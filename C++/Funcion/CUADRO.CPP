/*fi,ff=donde comienza horizontal  ci,cf= vertical*/
#include <iostream.h>
#include <conio.h>
#include <dos.h>

#define S  cout<<

void  cuadro();
void cuadro(int ci, int cf, int fi, int ff)
{
int o;
delay(100);
for(o=ci; o<=cf; o++)
{
delay(50);
gotoxy(o,fi); S"�";
gotoxy(o,ff); S"�";
}
for(o=fi; o<=ff; o++)
{
delay(50);
gotoxy(ci,o);S"�";
gotoxy(cf,o);S"�";
}
gotoxy(ci,fi); S"�";
gotoxy(cf,fi); S"�";
gotoxy(ci,ff); S"�";
gotoxy(cf,ff); S"�";

}

void main()
{
clrscr();
textcolor(13);textbackground(10);
cuadro(22,58,3,5);
gotoxy(32,4); S"ALVARO C. A.";
cuadro(14,66,6,19);
gotoxy(32,9); S"ALVARO C. A.";cin.get();
}









 