# include <iostream.h>
# include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
void recuadro(int x, int x2, int y, int y2,int z);
void ENTRADA(int z);
main ()
{
int x,y,p;
char esc[];
char tecla;
ENTRADA(1);
ENTRADA(2);
alva:
textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(x=1; x<=24; x++)
  for(y=1; y<=80; y++)
  {
   gotoxy(y,x);cout<<"�";
  }

//  PRIMER CUADRO
textcolor(BLACK); recuadro(3,5,5,75,2);
textcolor(BLUE); recuadro(2,4,4,74,2);
textcolor(WHITE); textbackground(BLUE);recuadro(2,4,4,74,1);
delay(500);

//SEGUNDO CUADRO
//textcolor(BLACK); recuadro(12,20,25,55,2);
textcolor(BLUE); recuadro(11,19,24,54,2);
textcolor(WHITE);textbackground(BLUE);recuadro(11,19,24,54,1);
delay(100);

/*TERCER CUADRO
textcolor(BLACK); recuadro(21,23,5,75,2);
textcolor(BLUE); recuadro(20,22,4,74,2);
textcolor(WHITE); textbackground(BLUE); recuadro(20,22,4,74,1);*/

//SEGUNDO CUADRO

//textcolor(BLACK); recuadro(11,21,20,60,2);
textcolor(BLUE); recuadro(10,20,19,59,2);
textcolor(WHITE);textbackground(BLUE);recuadro(10,20,19,59,1);
delay(100);

//textcolor(BLACK); recuadro(10,22,15,65,2);
textcolor(BLUE); recuadro(9,21,14,64,2);
textcolor(WHITE);textbackground(BLUE);recuadro(9,21,14,64,1);
delay(100);

//textcolor(BLACK); recuadro(9,23,10,70,2);
textcolor(BLUE); recuadro(8,22,9,69,2);
textcolor(WHITE);textbackground(BLUE);recuadro(8,22,9,69,1);
delay(100);

textcolor(BLACK); recuadro(8,24,5,75,2);
textcolor(BLUE); recuadro(7,23,4,74,2);
textcolor(WHITE);textbackground(BLUE);recuadro(7,23,4,74,1);
delay(100);

getch();


/*gotoxy(28,3); cprintf(" AGENDA  INGEMAS +++");
  do{
   tecla=getch();
     if(tecla==13)
     p=p+1;
     textcolor(BLACK);
   _setcursortype(_SOLIDCURSOR);
    gotoxy(5,8);cin>>p;

     }while(tecla != 27);*/

}

void recuadro(int x, int x2, int y, int y2,int z)
{
 int fila, columna;

  if(z==1)
 {
  for (columna=y; columna<=y2; columna++)
      {
	gotoxy(columna,x); cprintf("�");
	gotoxy(columna,x2); cprintf("�");
      }
  for (fila=x; fila<=x2; fila++)
      {
	gotoxy(y,fila); cprintf("�");
	gotoxy(y2,fila); cprintf("�");
      }
gotoxy(y,x); cprintf("�");
gotoxy(y2,x); cprintf("�");
gotoxy(y,x2); cprintf("�");
gotoxy(y2,x2); cprintf("�");
gotoxy(5,7);
}
 else

   for(fila=x; fila<=x2; fila++)
     for(columna=y; columna<=y2; columna++)
      {
       gotoxy(columna,fila); cprintf("�");

      }

}

void ENTRADA(int z)
{
int x,y;
textcolor(WHITE);
textbackground(BLUE);
if(z==1)
{
 for(x=1, y=20; x<8; x++,y--)
{
clrscr();
gotoxy(15,x);   cout <<"�������������������������������������������������";
gotoxy(15,x+1); cout <<"�������  ��� ����� ���� ���  ���   �����  �������";
gotoxy(15,x+2); cout <<"������ �� �� ����� ���� �� �� �� �� ��� �� ������";
gotoxy(15,x+3); cout <<"������ �� �� ����� ���� �� �� ��    ��� �� ������";
gotoxy(15,y-3); cout <<"������ �� �� ����� ���� �� �� �� � ���� �� ������";
gotoxy(15,y-2); cout <<"������ �� �� ������ �� ��� �� �� �� ��� �� ������";
gotoxy(15,y-1); cout <<"������ �� ��    ����  ���� �� �� ��� ���  �������";
gotoxy(15,y);   cout <<"�������������������������������������������������";
gotoxy(x+15,20);cprintf("INGENIERO:  ALVARO CARRILLO");
delay(100);
}
}
else
{
 for(x=1, y=55; x<17; x++,y--)
{
clrscr();
gotoxy(x,8); cout <<"�������������������������";
gotoxy(x,9); cout <<"�������  ��� ����� ���� �";
gotoxy(x,10);cout <<"������ �� �� ����� ���� �";
gotoxy(x,11);cout <<"������ �� �� ����� ���� �";
gotoxy(x,12);cout <<"������ �� �� ����� ���� �";
gotoxy(x,13);cout <<"������ �� �� ������ �� ��";
gotoxy(x,14);cout <<"������ �� ��    ����  ���";
gotoxy(x,15);cout <<"�������������������������";

gotoxy(y,8); cout <<"�������������������������";
gotoxy(y,9); cout <<"���  ���   �����  �������";
gotoxy(y,10);cout <<"�� �� �� �� ��� �� ������";
gotoxy(y,11);cout <<"�� �� ��    ��� �� ������";
gotoxy(y,12);cout <<"�� �� �� � ���� �� ������";
gotoxy(y,13);cout <<"�� �� �� �� ��� �� ������";
gotoxy(y,14);cout <<"�� �� �� ��� ���  �������";
gotoxy(y,15);cout <<"�������������������������";
gotoxy(x+15,20);cprintf("INGENIERO:  ALVARO CARRILLO");
delay(100);
}
}
getch();
}