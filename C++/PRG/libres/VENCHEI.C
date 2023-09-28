#include<stdio.h>
#include<conio.h>
#include<dos.h>
void colores(int,int);
void cuadro();
void inicializar();
void capturar();
void imprimir();
void salir();
float ventas[13],valor,total;
int mes,i;
void cuadro()
{
 int  i;
 colores(15,25);
 clrscr();
 for(i=2;i<=79;++i)
  {
   gotoxy(i,1);printf("%c",(205));
   gotoxy(i,24);printf("%c",(205));
  }
  for(i=2;i<=23;++i)
   {
    gotoxy(1,i);printf("%c",(186));
    gotoxy(80,i);printf("%c",(186));
   }
    gotoxy(1,1);printf("%c",(201));
    gotoxy(1,24);printf("%c",(200));
    gotoxy(80,1);printf("%c",(187));
    gotoxy(80,24);printf("%c",(188));
}
void colores(int a,int b)
{
  textcolor(a);
  textbackground(b);
}
void inicializar()
{
  for(i=1;i<=12;i++)
  ventas[i]=0;
}
void capturar()
{
  while(1)
  {
    cuadro();
    gotoxy(5,3);
    printf("DIGITE MES...:");scanf("%d",& mes);
    if(mes==0)break;
    if((mes<1)||(mes>12))
    {
     gotoxy(10,12);printf("**MES ERRADO,INTENTE DE NUEVO**");
     getch();
     continue;//devuelve al inicio del ciclo.
     }
     gotoxy(5,4);
     printf("DIGITE VALOR....:");scanf("%f",& valor);
     getch();
     ventas[mes]+=valor;//ventas[mes]=ventas[mes]=ventas[mes]+valor.
    }
  }
void imprimir()
{
  cuadro();
  gotoxy(32,3);printf("VENTAS DE CHEILA");
  gotoxy(5,5);printf("MES------------VENTAS");
  gotoxy(5,6);printf("---------------------");
  gotoxy(5,7);printf("ENERO...............:");
  gotoxy(5,8);printf("FEBRERO.............:");
  gotoxy(5,9);printf("MARZO...............:");
  gotoxy(5,10);printf("ABRIL..............:");
  gotoxy(5,11);printf("MAYO...............:");
  gotoxy(5,12);printf("JUNIO..............:");
  gotoxy(5,13);printf("JULIO..............:");
  gotoxy(5,14);printf("AGOSTO.............:");
  gotoxy(5,15);printf("SEPTIEMBRE.........:");
  gotoxy(5,16);printf("OCTUBRE............:");
  gotoxy(5,17);printf("NOVIEMBRE..........:");
  gotoxy(5,18);printf("DICIEMBRE..........:");
  gotoxy(5,19);printf("--------------------");
  gotoxy(5,20);printf("TOTAL...............");
   for(i=1;i<=12;i++)
   {
	total=total+ventas[i];
	gotoxy(19,6+i);printf("%f",ventas[i]);
   }
    gotoxy(19,20);printf("%f",total);
    getch();
}
void salir()
{
 cuadro();
 gotoxy(17,12);
 printf("GRACIAS POR UTILIZAR EL PROGRAMA DE VENTAS DE CHEILA");
 delay(2000);
}
void main()
{
  colores(15,25);
  cuadro();
  inicializar();
  capturar();
  imprimir();
  salir();
}
