#include<stdio.h>
#include<ctype.h>
#include<conio.h>
 
class serie
{
 int i,a,b,c,n;

 public:
 void fibonaci();
 void visualizar();
};

void serie::fibonaci()
{
  i=1;a=0;b=1;c=0;
  char op=0;
 do
 {
  clrscr();
  textbackground(1);
  window(8,8,68,17);
  clrscr();
  textcolor(14);textbackground(3);
  gotoxy(2,2);printf("CANTIDAD DE NUMEROS A GENERAR DE LA SERIE : ");
  gotoxy(46,2);scanf("%d",&n);
  gotoxy(2,4);printf("SERIE DE FIBONACCI : ");
  if(n==1)
  {
   gotoxy(22,4);printf("%d",0);
  }
  else
  if(n==2)
  {
   gotoxy(22,4);printf("%d  %d",0,  1);
  }
  else
  {
   gotoxy(22,4);printf("  %d\t",c);
   while(i<n)
  {
   i=i+1;
   a=a+b;
   b=c;
   c=a;
   printf("%d\t",c);
  }
 }
  gotoxy(2,6);printf("DESEA CONSULTAR OTROS NUMEROS DE LA SERIE (S/N) : ");
  op=toupper(getche());
 }while(op!='N');
}

void serie::visualizar()
{
 {
  getche();
 }
}

void main()
{
 serie obj;
 obj.fibonaci();
 obj.visualizar();
}



