#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

float matriz[15][15];
int filas,columnas;
//void cuadros(int x1,int x2,int y1,int y2);
void menu();
void cuadro(int i,int j);
void crear();
void resultados();
void resultados2();

/***************************************************/
void crear()
{
    int i,j;
    clrscr();//marco(1,1,79,24);
    gotoxy(5,4);cprintf("Digite Valores a la Matriz");
    gotoxy(7,6);cprintf("Ene");
    gotoxy(13,6);cprintf("Feb");
    gotoxy(19,6);cprintf("Mar");
    gotoxy(25,6);cprintf("Abr");
    gotoxy(31,6);cprintf("May");
    gotoxy(37,6);cprintf("Jun");
    gotoxy(43,6);cprintf("Jul");
    gotoxy(49,6);cprintf("Ago");
    gotoxy(55,6);cprintf("Sep");
    gotoxy(61,6);cprintf("Oct");
    gotoxy(67,6);cprintf("Nov");
    gotoxy(73,6);cprintf("Dic");
    gotoxy(2,7);cprintf("Pr1");
    gotoxy(2,8);cprintf("Pr2");
    gotoxy(2,9);cprintf("Pr3");
    gotoxy(2,10);cprintf("Pr4");
    gotoxy(2,11);cprintf("Pr5");
    gotoxy(2,12);cprintf("Pr6");
    gotoxy(2,13);cprintf("Pr7");
    gotoxy(2,14);cprintf("Pr8");
    gotoxy(2,15);cprintf("Pr9");
    gotoxy(2,16);cprintf("Pr10");
    gotoxy(2,17);cprintf("Pr11");
    gotoxy(2,18);cprintf("Pr12");
    for(i=0;i<12;i++)
      for(j=0;j<12;j++)
      {
	gotoxy(7+j*6,7+i);cscanf("%f",&matriz[i][j]);
      }
    gotoxy(40,23);cprintf("Matriz Guardada");getch();
}


void resultados()
{
   int i,j;
   float suma;
   clrscr();gotoxy(5,3);cprintf("Resultados del Ejercicio");
   for(i=0;i<12;i++)
   {
     suma=0;
     for(j=0;j<12;j++)
     {
	suma=suma+matriz[i][j];
     }
     gotoxy(3,6+i);cprintf("Total del Producto %d: %.1f",i+1,suma);
   }

   for(i=0;i<12;i++)
   {
     suma=0;
     for(j=0;j<12;j++)
     {
	suma=suma+matriz[j][i];
     }
     gotoxy(40,6+i);cprintf("Total del Mes %d es: %.1f",i+1,suma);
   }
   getch();
}

void resultados2()
{
   int i,j;
   float temp;
   clrscr();gotoxy(5,3);cprintf("Resultados de productos mas vendidos");
   for(i=0;i<12;i++)
   {
     temp=0;
     for(j=0;j<12;j++)
     {
	if(temp<matriz[j][i])
	  temp=matriz[j][i];
     }
     gotoxy(4,6+i);cprintf("El Producto mas vendido en el mes %d es: %.1f",i+1,temp);
   }
   getch();
}
//******************************************************************

void main()
 {
  char op;   int i,j;
  textcolor(15);
  textbackground(0);
  do
   {
       cuadro(80,24);
    textcolor(15);
    gotoxy (19,4);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (19,9);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (19,5);  cprintf("±");gotoxy (19,7);  cprintf("±");gotoxy (19,9);  cprintf("±");
    gotoxy (19,6);  cprintf("±");gotoxy (19,8);  cprintf("±");
    gotoxy (59,4);  cprintf("±"); gotoxy (59,5);  cprintf("±");gotoxy (59,6);  cprintf("±");
    gotoxy (59,7);  cprintf("±");gotoxy (59,8);  cprintf("±");gotoxy (59,9);  cprintf("±");
    gotoxy (20,6);  cprintf("CORPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy (25,7);  cprintf("DARWIN HELMUTHS LEON PEREZ");
    gotoxy (30,8);  cprintf("COD 96132068 S2B");
    gotoxy (25,23);  cprintf("*******************************");
    gotoxy (24,13);  cprintf("±");gotoxy (24,14);  cprintf("±");gotoxy (24,16);  cprintf("±");
    gotoxy (24,15);  cprintf("±");gotoxy (24,17);  cprintf("±");gotoxy (24,18);  cprintf("±");
    gotoxy (24,19);  cprintf("±");
    gotoxy (24,12);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (24,20);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");

    gotoxy (24,20);  cprintf("±");
    gotoxy (54,20);  cprintf("±");
    gotoxy (54,13);  cprintf("±");gotoxy (54,16);  cprintf("±");gotoxy (54,17);  cprintf("±");
    gotoxy (54,14);  cprintf("±");gotoxy (54,15);  cprintf("±");gotoxy (54,18);  cprintf("±");
    gotoxy (54,19);  cprintf("±");
    gotoxy (29,11); cprintf("<< MENU PRINCIPAL >>");
    gotoxy (28,13); cprintf("A:CREAR ARCHIVO DE FACTURA\n");
    gotoxy (28,14); cprintf("B:CREAR ARCHIVO DE APORTES\n");
    gotoxy (28,15); cprintf("C:ELABORAR FACTURA\n");
    gotoxy (28,16); cprintf("D:SALIR\n");
    gotoxy (28,22); cprintf("DIGITE OPCION:");
    op=toupper(getche());
    switch(op)
	  {

	 case 'A':{crear();break;}
	  case 'B':{resultados();break;}
	  case 'C':{resultados2();break;}
	  case 'D':return;

     }
     }while(op!='D');
 }

     
//***********************CUADRO*********************************************
void cuadro(int i,int j)
  {
   int st,con;
   clrscr();
   textcolor(4);
   gotoxy(10,3);cprintf("±"); /** ALT 177 **/
   gotoxy(70,3);cprintf("±");
   gotoxy(10,23);cprintf("±"); /** ALT 177 **/
   gotoxy(70,23);cprintf("±"); /** ALT 177 **/
   st=1;  con=0;
   while((st==1)&&(con<=3))
   {
   con++;
    for(j=10; j<=70; j++)
     {
     //textcolor(0);
     textcolor(4);
     }
     for(i=70; i>=10; i--)
      {
      delay(5);
      j=i;
      gotoxy(i,2);
      textcolor(4);//textcolor(j-1);
      textcolor(4);//textcolor(i);
      cprintf("±"); /** ALT  **/
      gotoxy(i,24);cprintf("±"); /** ALT 177**/
      gotoxy(15,11);
      textcolor(4);//textcolor(j-1);
      textcolor(4);//textcolor(i);
      j=i-8;
      if (j<=23)
       {
	gotoxy(10,j);cprintf("±");  /** ALT 177**/
	gotoxy(70,j);cprintf("±");  /** ALT 177 **/
       }
      }
     }
    }

