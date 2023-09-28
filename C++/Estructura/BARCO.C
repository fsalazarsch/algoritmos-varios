#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>


struct
{
  char   ident[20];
  int    riesgo;
  struct tm  hora;
  struct tm  fecha;
}Barco[7],riesBarco[20];

void menu();
void listar();
void modificar();
void agregar();
void consultar();
void riesgo();
void borrar();
void procesar();
void piso_color();
void ref1();
void ref2();
void marco();
void marco2();
void fondo();
void menu1();
void escribe_menu();
void escribe_menu2();
void menu2();
void escribe_menu3();
void ayuda();
void salir();


char op2[5][19]={" ","Listado General   ", "Barcos de Riesgo 9",
		     "Barcos Procesados ","Salir             "};
char op[6][10]={" ","Adicionar","Consultar","Eliminar ","Modificar","Salir    "};
int n,con,con1=0,con2=0,sw2,i,aux,aux1=0,co,j,st;
int  lon, cabeza=0,fin=0,con_barco=0;
int year, month, day;
int hour,min,sec;

void escribe_menu2()
{
    textbackground(BLACK);
    clrscr();
    window(1,1,80,25);
    gotoxy(1,1);
    fondo(2,81,LIGHTGRAY);
    piso_color(3,BLACK);
    gotoxy(8,1);
    cprintf("Barco");
    piso_color(WHITE,BLACK);
    gotoxy(26,1);
    cprintf("Listados");
    gotoxy(46,1);
    cprintf("Ayuda");
    gotoxy(63,1);
    cprintf("Salir");
    gotoxy(8,1);
    piso_color(BLACK,WHITE);
    marco(2,3,78,22);
    gotoxy(1,24);
    fondo(1,159,LIGHTGRAY);
    piso_color(WHITE,BLACK);
    gotoxy(2,24);
    cprintf("Copyrigth (c) 1997 UDES   Valledupar.   ");
    gotoxy(2,25);
    cprintf("Unica Versi¢n 2 de Abril 1997 Dise¤o ");
    gotoxy(8,1);
}
void fondo(int a,int c,int color)
{
  int i;
  textcolor(color);
  for(i=a;i<=c;i++)
     cprintf("%c",219);
}
void marco(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'Ú');
   for (i=a;i<=c;i++ )
       cprintf("%c",'Ä');
   cprintf("%c",'¿');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'³');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
      cprintf("%c",'Ä');
  cprintf("%c",'Ù');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'³');
  }
}
void marco2(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'Ú');
   for (i=a;i<=c;i++ )
       cprintf("%c",'Ä');
   cprintf("%c",'¿');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'³');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
      cprintf("%c",'Ä');
  cprintf("%c",'Ù');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'³');
  }
  window(a,b,c,d);
}
void ref1(int n,int piso,int color,char s[])
{
   gotoxy(n,1);
   piso_color(piso,color);
   cprintf("%s",s);
}
void ref2(int n,int piso,int color,char s[])
{
  gotoxy(n,1);
  piso_color(piso,color);
  cprintf("%s",s);
  gotoxy(n,1);
}
void piso_color(int piso,int color)
{
   textbackground(piso);
   textcolor(color);
}
void menu1()
{
     int sw;
     char c;
     sw=0;
     piso_color(BLACK,WHITE);
     escribe_menu();
     c = getch();
     while ((c != 27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 : {
			  piso_color (BLACK,WHITE);
			  cprintf("%s",op[wherey()]);
			  piso_color (WHITE,BLACK);
			  if (wherey() == 5)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	     case 72 : {
			  piso_color(BLACK,WHITE);
			  cprintf("%s",op[wherey()]);
			  piso_color (WHITE,BLACK);
			  if (wherey() == 1) gotoxy (3,5);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }
	   c =getch();
	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 agregar();
			 clrscr();
			 escribe_menu();
			 break;
			}
		case 2:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 consultar();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }
		case 3:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 borrar();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }
		case 4:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modificar();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }
		case 5:{
			 sw=1;
			 break;
		       }
	       }
	   }
     }
}
void escribe_menu()
{
     int i;
     marco2(4,3,16,7);
     piso_color(BLACK,WHITE);
     for(i=2;i<=5;i++)
     {
	 gotoxy (3,i);
	 cprintf("%s ",op[i]);
     }
     piso_color (WHITE,BLACK);
     gotoxy (3,1);
     cprintf("%s",op[1]);
     gotoxy (3,1);
}
void menu2()
{
     int sw;
     char c;
     sw=0;
     piso_color(BLACK,WHITE);
     escribe_menu3();
     c = getch();
     while ((c !=27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 : {
			  piso_color (BLACK,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,BLACK);
			  if (wherey() == 4)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	     case 72 : {
			  piso_color(BLACK,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,BLACK);
			  if (wherey() == 1) gotoxy (3,4);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }
	   c =getch();
	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 listar();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
			}
		case 2:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 riesgo();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
		case 3:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 procesar();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
		case 4:{
			 sw=1;
			 break;
		       }
	       }
	   }
     }
}
void escribe_menu3()
{
     int i;
     marco2(20,3,41,6);
     piso_color(BLACK,WHITE);
     for(i=2;i<=4;i++)
     {
	 gotoxy (3,i);
	 cprintf("%s ",op2[i]);
     }
     piso_color (WHITE,BLACK);
     gotoxy (3,1);
     cprintf("%s",op2[1]);
     gotoxy (3,1);
}
void ayuda()
{
   piso_color(BLACK,WHITE);
   marco2(35,3,65,12);
   cprintf("%c Desplazamiento hacia arriba  ",24);
   cprintf("%c Desplazamiento hacia abajo   ",25);
   cprintf("%c Desplazamiento a la izquierda",27);
   cprintf("-> Desplazamiento a la derecha ");
   cprintf("ENTER para entrar a los menus. ");
   cprintf("colgantes.                     ");
   cprintf("ENTER en cada opcion ingresa a ");
   cprintf("el desarrollo de esta.         ");
   cprintf("ESC para salir de cada menu.   ");
   getch();
}
void salir()
{
   char salida;
   piso_color(BLACK,WHITE);
   marco2(58,3,77,3);
   gotoxy(1,1);
   cprintf("Desea salir (Y/N):");
   salida=getche();
   salida=toupper(salida);
   if(salida=='Y')
       sw2=1;
   else
     if(salida=='N')
	sw2=0;
}

void agregar()
{ 
 char op,identif[40],op1[10]; 
 int sw,st;
 char aui[10],valido;
 window(3,3,78,22);
  piso_color(BLACK,WHITE);

  do
  {
  clrscr();
  if(con_barco==7)  
  {
    gotoxy(2,2);
    printf("LA COLA ESTA LLENA");
    getch();
  }
  else
  {
   if(con_barco==0)  
   {
     cabeza=0;  co=2;    
     fin=0;
     aux=2;
     while(aux==2)
     {
     clrscr();
     gotoxy(co,3);printf("DIGITE IDENTIFICACION DEL BARCO:");
     scanf("\n");gets(identif);
	 aux=1;
	 lon = strlen(identif);   
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(identif[i])))
	   { 
	    gotoxy(10,10);printf("ERROR AL DIGITAR IDENTIFICACION..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     aux=2;
	     break;
	      }
	 }
      }
     strcpy(Barco[con].ident,identif);   
     sw=1;
     while(sw==1)
     {
     gotoxy(26,4);
     printf("             ");
     gotoxy(co,4);printf("DIGITE EL RIESGO [1..9]:");
     scanf("\n");gets(op1);
     st=1;
     lon = strlen(op1);   
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(op1[i])))
	   { 
	    gotoxy(10,10);printf("ERROR AL DIGITAR EL RIESGO..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;
	      }
	 }
     if(st==1)
     {
     Barco[con].riesgo=atoi(op1);
     if((Barco[con].riesgo>=10)||(Barco[con].riesgo<=0))
     {
     gotoxy(10,10);printf("RIESGO FUERA DE RANGO..!");
     delay(1500);
     gotoxy(10,10);
     clreol();
     }
     else
     {
     sw=2;
     }
     }
     }
     gotoxy(co,5);printf("HORA DE LLEGADA:");
    do
     {
      valido='n';
      gotoxy(22,5);
      printf("              ");
      gotoxy(18,5);printf("Hora:");
      scanf("\n"); gets(aui);
      lon = strlen(aui);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR HORA !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  hour=atoi(aui);
	  if((hour>23)||(hour<0))
	    {
	     gotoxy(10,20);printf("ERROR HORA FUERA DE RANGO!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(37,5);
     printf("              ");
     gotoxy(29,5);printf("Minutos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MINUTOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 min=atoi(aui);
	 if((min<0)||(min>60))
	   {
	    gotoxy(10,20);printf("ERROR MINUTOS FUERA DE RANGO!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(52,5);
     printf("              ");
     gotoxy(43,5);printf("Segundos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR SEGUNDOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	sec=atoi(aui);
	if((sec<0)||(sec>60))
	 {
	  gotoxy(10,20);printf("ERROR SEGUNDOS FUERA DE RANGO!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[con].hora.tm_year = 0 ;
   Barco[con].hora.tm_mon  = 0;
   Barco[con].hora.tm_mday = 0;
   Barco[con].hora.tm_hour = hour;
   Barco[con].hora.tm_min  = min;
   Barco[con].hora.tm_sec  = sec;
   Barco[con].hora.tm_isdst = -1;

   gotoxy(18,5);
   printf("                                                      ");
   gotoxy(18,5);

   printf("%d:", Barco[con].hora.tm_hour);
   printf("%d:", Barco[con].hora.tm_min);
   printf("%d", Barco[con].hora.tm_sec);
   getch();
     gotoxy(co,6);printf("FECHA DE INGRESO:");
    do
     {
      valido='n';
      gotoxy(23,6);
      printf("              ");
      gotoxy(19,6);printf("A¤o:");
      scanf("\n"); gets(aui);
      lon = strlen(aui);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR A¥O !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  year=atoi(aui);
	  if((year>8000)||(year<=0))
	    {
	     gotoxy(10,20);printf("ERROR A¥O INEXISTENTE!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(33,6);
     printf("              ");
     gotoxy(29,6);printf("Mes:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MES !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 month=atoi(aui);
	 if((month<1)||(month>12))
	   {
	    gotoxy(10,20);printf("ERROR MES INEXISTENTE!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(42,6);
     printf("              ");
     gotoxy(38,6);printf("Dia:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR DIA !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	day=atoi(aui);
	if((day<1)||(day>31))
	 {
	  gotoxy(10,20);printf("ERROR DIA INEXISTENTE!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[con].fecha.tm_year = year ;
   Barco[con].fecha.tm_mon  = month;
   Barco[con].fecha.tm_mday = 0;
   Barco[con].fecha.tm_hour = day;
   Barco[con].fecha.tm_min  = 0;
   Barco[con].fecha.tm_sec  = 1;
   Barco[con].fecha.tm_isdst = -1;

   gotoxy(19,6);
   printf("                                                      ");
   gotoxy(19,6);

   printf("%d/", Barco[con].fecha.tm_hour);
   printf("%d/", Barco[con].fecha.tm_mon);
   printf("%d", Barco[con].fecha.tm_year);
   getch();
     con ++;
     con_barco++;
     
   }
   else          
   {
     aux=2;
     while(aux==2)   
     {
     clrscr();
     gotoxy(co,3);printf("DIGITE IDENTIFICACION DEL BARCO:");
     scanf("\n");gets(identif);
	 j=1;
	 lon = strlen(identif); 
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(identif[i])))
	   {
	    j=2;
	    gotoxy(10,10);printf("ERROR AL DIGITAR IDENTIFICACION..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	    break;
	     }
	 }
	if(j==1)
	{
	 for(i=cabeza;i<=fin;i++)
	 {
	 if(strcmp(Barco[i].ident,identif)==0)   
	 {
	 j=2;
	 }
	 if(j==2)
	 {
	 gotoxy(10,10);printf("IDENTIFICACION EXISTENTE..!");
	 delay(1500);
	 gotoxy(10,10);
	 clreol();
	 aux=2;
	 break;
	}
	else
	{
	aux=1;
	}
	}
	}
     }
     strcpy(Barco[con].ident,identif);
     sw=1;
     while(sw==1)
     {
     gotoxy(26,4);
     printf("             ");
     gotoxy(co,4);printf("DIGITE EL RIESGO [1..9]:");
     scanf("\n");gets(op1);
     st=1;
     lon = strlen(op1);   
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(op1[i])))
	   {
	    gotoxy(10,10);printf("ERROR AL DIGITAR EL RIESGO..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;
	      }
	 }
     if(st==1)
     {
     Barco[con].riesgo=atoi(op1);
     if((Barco[con].riesgo>=10)||(Barco[con].riesgo<=0))
     {
     gotoxy(10,10);printf("RIESGO FUERA DE RANGO..!");
     delay(1500);
     gotoxy(10,10);
     clreol();
     }
     else
     {
     sw=2;
     }
     }
     }
    gotoxy(co,5);printf("HORA DE LLEGADA:");
    do
     {
      valido='n';
      gotoxy(22,5);
      printf("              ");
      gotoxy(18,5);printf("Hora:");
      scanf("\n"); gets(aui);
      lon = strlen(aui);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR HORA !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  hour=atoi(aui);
	  if((hour>23)||(hour<0))
	    {
	     gotoxy(10,20);printf("ERROR HORA FUERA DE RANGO!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(37,5);
     printf("              ");
     gotoxy(29,5);printf("Minutos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MINUTOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 min=atoi(aui);
	 if((min<0)||(min>60))
	   {
	    gotoxy(10,20);printf("ERROR MINUTOS FUERA DE RANGO!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(52,5);
     printf("              ");
     gotoxy(43,5);printf("Segundos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR SEGUNDOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	sec=atoi(aui);
	if((sec<0)||(sec>60))
	 {
	  gotoxy(10,20);printf("ERROR SEGUNDOS FUERA DE RANGO!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[con].hora.tm_year = 0 ;
   Barco[con].hora.tm_mon  = 0;
   Barco[con].hora.tm_mday = 0;
   Barco[con].hora.tm_hour = hour;
   Barco[con].hora.tm_min  = min;
   Barco[con].hora.tm_sec  = sec;
   Barco[con].hora.tm_isdst = -1;

   gotoxy(18,5);
   printf("                                                      ");
   gotoxy(18,5);

   printf("%d:", Barco[con].hora.tm_hour);
   printf("%d:", Barco[con].hora.tm_min);
   printf("%d", Barco[con].hora.tm_sec);
   getch();
     gotoxy(co,6);printf("FECHA DE INGRESO:");
    do
     {
      valido='n';
      gotoxy(23,6);
      printf("              ");
      gotoxy(19,6);printf("A¤o:");
      scanf("\n"); gets(aui);
      lon = strlen(aui);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR A¥O !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  year=atoi(aui);
	  if((year>8000)||(year<=0))
	    {
	     gotoxy(10,20);printf("ERROR A¥O INEXISTENTE!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(33,6);
     printf("              ");
     gotoxy(29,6);printf("Mes:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MES !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 month=atoi(aui);
	 if((month<1)||(month>12))
	   {
	    gotoxy(10,20);printf("ERROR MES INEXISTENTE!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(42,6);
     printf("              ");
     gotoxy(38,6);printf("Dia:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR DIA !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	day=atoi(aui);
	if((day<1)||(day>31))
	 {
	  gotoxy(10,20);printf("ERROR DIA INEXISTENTE!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[con].fecha.tm_year = year ;
   Barco[con].fecha.tm_mon  = month;
   Barco[con].fecha.tm_mday = 0;
   Barco[con].fecha.tm_hour = day;
   Barco[con].fecha.tm_min  = 0;
   Barco[con].fecha.tm_sec  = 1;
   Barco[con].fecha.tm_isdst = -1;

   gotoxy(19,6);
   printf("                                                      ");
   gotoxy(19,6);

   printf("%d/", Barco[con].fecha.tm_hour);
   printf("%d/", Barco[con].fecha.tm_mon);
   printf("%d", Barco[con].fecha.tm_year);
   getch();
     con ++;
     con_barco++;
     fin++;
    }
  
  }
  gotoxy(co,7);
  printf("DESEA CONTINUAR (S/N):");
  op=toupper(getch());
  }while(op!='N');
}
void consultar()
{
  char identif[20];
  window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
 if(con_barco==0) 
 {
 gotoxy(2,2);
 printf("LA COLA ESTA VACIA");
 getch();
 }
 else
 {  aux=2;
 while(aux==2)
 {
 clrscr();
 gotoxy(2,3);
 printf("DIGITE IDENTIFICACION PARA CONSULTAR:");
 scanf("\n");gets(identif);
	 aux=1;  
	 lon = strlen(identif);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(identif[i])))
	   { 
	     aux=2;
	      }
	 }
    }

 i=cabeza;
 while((i!=fin)&&((strcmp(identif,Barco[i].ident))!=0))
  {
    i++;     
  }

 if((i==fin)&&(strcmp(identif,Barco[i].ident)!=0))
 {
  clrscr();                 
  gotoxy(2,2);                                             
  printf("NO EXISTE ESTA IDENTIFICACION");
  getch();
 }  
 else  
 {  co=4;
    gotoxy(2,3);printf("RIESGO     IDENTIFICACION   HORA DE LLEGADA   FECHA");
     gotoxy(4,co);printf("%d",Barco[i].riesgo);
     gotoxy(18,co);printf("%s",Barco[i].ident);
     gotoxy(36,co);printf("%d:",Barco[i].hora.tm_hour);
     printf("%d:",Barco[i].hora.tm_min);
     printf("%d",Barco[i].hora.tm_sec);
     gotoxy(49,co);printf("%d/", Barco[i].fecha.tm_hour);
     printf("%d/", Barco[i].fecha.tm_mon);
     printf("%d", Barco[i].fecha.tm_year);
     co++;
 }
}
getch();

}

void riesgo()
{
  int ayu;
  ayu=0; co=4;
  window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
  if(aux1==0)
  {
  gotoxy(2,2);
  printf("NO HAY BARCOS QUE HAN SIDO PROCESADOS");
  }
  else
  {
  for(i=0;i<=aux1-1; i++)
  {
     ayu=1; 
     gotoxy(2,3);printf("RIESGO     IDENTIFICACION   HORA DE LLEGADA   FECHA");
     gotoxy(4,co);printf("%d",riesBarco[i].riesgo);
     gotoxy(18,co);printf("%s",riesBarco[i].ident);
     gotoxy(36,co);printf("%d:",riesBarco[i].hora.tm_hour);
     printf("%d:", riesBarco[i].hora.tm_min);
     printf("%d", riesBarco[i].hora.tm_sec);
     gotoxy(49,co);printf("%d/",riesBarco[i].fecha.tm_hour);
     printf("%d/",riesBarco[i].fecha.tm_mon);
     printf("%d", riesBarco[i].fecha.tm_year);
     co++;
  }  
      
 if(ayu==0)
 {
  clrscr();
  gotoxy(2,2);
  printf("NO EXISTEN BARCO CON RIESGO 9"); 
 }
 }
 getch();
}




void modificar()
{
 int ries;
 int sw;
 char valido,identif[40],aui[10];
 char auxi[20],op,op1[10],op2;
 struct tm tiem;
 window(3,3,78,22);
 piso_color(BLACK,WHITE);
 do
 {
 clrscr();
 if(con_barco==0) 
 {
 gotoxy(2,2);
 printf("LA COLA ESTA VACIA");
 getch();
 }
 else
 {  aux=2;
 while(aux==2)
 {
 clrscr();
 gotoxy(2,1);
 printf("DIGITE IDENTIFICACION PARA MODIFICAR:");
 scanf("\n");gets(identif);
	 aux=1;
	 lon = strlen(identif);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(identif[i])))
	   { 
	     aux=2;
	   }
	 }
    }

 j=cabeza;
 while((j!=fin)&&(strcmp(identif,Barco[j].ident)!=0))
  {  
    j++;     
 }

 if((j==fin)&&(strcmp(identif,Barco[j].ident)!=0))
 {  
  clrscr();                 
  gotoxy(2,2);                                             
  printf("NO EXISTE ESTA IDENTIFICACION");
  getch();
 }
 else       
 {
   do
   {
   clrscr();
  gotoxy(2,3); printf("1: RIESGO\n");
  gotoxy(15,3);printf("2: HORA LLEGADA\n");
  gotoxy(32,3);printf("3: FECHA\n");
  gotoxy(2,4);printf("ESCOJA OPCION:");scanf("%c",&op2);
	   if(op2=='1')
	   {
	   sw=1;
     while(sw==1)
     {
     gotoxy(26,5);
     printf("             ");
     gotoxy(2,5);printf("DIGITE EL RIESGO [1..9]:");
     scanf("\n");gets(op1);
     st=1;
     lon = strlen(op1);
     for( i=0;i<=lon-1; i++)
	{
	if(!(isdigit(op1[i])))
	   {
	    gotoxy(10,10);printf("ERROR AL DIGITAR EL RIESGO..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;
	      }
	 }
     if(st==1)
     {
     Barco[j].riesgo=atoi(op1);
     if((Barco[j].riesgo>=10)||(Barco[j].riesgo<=0))
     {
     gotoxy(10,10);printf("RIESGO FUERA DE RANGO..!");
     delay(1500);
     gotoxy(10,10);
     clreol();
     }
     else
     {
     sw=2;
     }
     }
     }
   }
	   if(op2=='2')
	   {
	   gotoxy(2,5);
	   printf("HORA DE LLEGADA:");
	       do
     {
      valido='n';
      gotoxy(23,5);
      printf("              ");
      gotoxy(18,5);printf("Hora:");
      scanf("\n"); gets(aui);
      lon = strlen(aui);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR HORA !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  hour=atoi(aui);
	  if((hour>23)||(hour<0))
	    {
	     gotoxy(10,20);printf("ERROR HORA FUERA DE RANGO!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(37,5);
     printf("              ");
     gotoxy(29,5);printf("Minutos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MINUTOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 min=atoi(aui);
	 if((min<0)||(min>60))
	   {
	    gotoxy(10,20);printf("ERROR MINUTOS FUERA DE RANGO!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(47,6);
     printf("              ");
     gotoxy(38,5);printf("Segundos:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR SEGUNDOS !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	sec=atoi(aui);
	if((sec<0)||(sec>60))
	 {
	  gotoxy(10,20);printf("ERROR SEGUNDOS FUERA DE RANGO!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[j].hora.tm_year = 0 ;
   Barco[j].hora.tm_mon  = 0;
   Barco[j].hora.tm_mday = 0;
   Barco[j].hora.tm_hour = hour;
   Barco[j].hora.tm_min  = min;
   Barco[j].hora.tm_sec  = sec;
   Barco[j].hora.tm_isdst = -1;

   gotoxy(18,5);
   printf("                                                      ");
   gotoxy(18,5);

   printf("%d:", Barco[i].hora.tm_hour);
   printf("%d:", Barco[i].hora.tm_min);
   printf("%d", Barco[i].hora.tm_sec);
   getch();
	   }
	   if(op2=='3')
	   {
	    gotoxy(2,5);printf("FECHA DE INGRESO:");
       do
      {
       valido='n';
       gotoxy(23,5);
       printf("              ");
       gotoxy(19,5);printf("A¤o:");
       scanf("\n"); gets(aui);
       lon = strlen(aui);
       for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(aui[i])))
	   {
	    gotoxy(10,20);printf("ERROR AL DIGITAR A¥O !");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	    break;
	   }
	 }
	if (valido=='n')
	 {
	  year=atoi(aui);
	  if((year>8000)||(year<=0))
	    {
	     gotoxy(10,20);printf("ERROR A¥O INEXISTENTE!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	    }
	 }
     }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(33,5);
     printf("              ");
     gotoxy(29,5);printf("Mes:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR MES !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
	{
	 month=atoi(aui);
	 if((month<1)||(month>12))
	   {
	    gotoxy(10,20);printf("ERROR MES INEXISTENTE!");
	    delay(1500);
	    gotoxy(10,20);
	    clreol();
	    valido='m';
	   }
	}
   }while(valido=='m');

   do
    {
     valido='n';
     gotoxy(42,5);
     printf("              ");
     gotoxy(38,5);printf("Dia:");
     scanf("\n"); gets(aui);
     lon = strlen(aui);
     for(i=0;i<=lon-1; i++)
       {
	if(!(isdigit(aui[i])))
	  {
	   gotoxy(10,20);printf("ERROR AL DIGITAR DIA !");
	   delay(1500);
	   gotoxy(10,20);
	   clreol();
	   valido='m';
	   break;
	  }
	}
      if (valido=='n')
       {
	day=atoi(aui);
	if((day<1)||(day>31))
	 {
	  gotoxy(10,20);printf("ERROR DIA INEXISTENTE!");
	  delay(1500);
	  gotoxy(10,20);
	  clreol();
	  valido='m';
	 }
       }
   }while(valido=='m');
   Barco[j].fecha.tm_year = year ;
   Barco[j].fecha.tm_mon  = month;
   Barco[j].fecha.tm_mday = 0;
   Barco[j].fecha.tm_hour = day;
   Barco[j].fecha.tm_min  = 0;
   Barco[j].fecha.tm_sec  = 1;
   Barco[j].fecha.tm_isdst = -1;

   gotoxy(19,5);
   printf("                                                      ");
   gotoxy(19,5);

   printf("%d/", Barco[i].fecha.tm_hour);
   printf("%d/", Barco[i].fecha.tm_mon);
   printf("%d", Barco[i].fecha.tm_year);
   getch();

   }
 }while((op2!='1')&&(op2!='2')&&(op2!='3'));
 }
 } 
   gotoxy(2,7);
   printf("DESEA CONTINUAR (S/N):");
   op=toupper(getch());
   }while(op!='N');
  }
void borrar()
{
  window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
  if(con_barco==0)
  {                
   gotoxy(2,2);
   printf("LA COLA ESTA VACIA");
  }
  else
  {
   if(cabeza==fin)  
   {
     i=cabeza;
     if(Barco[i].riesgo==9)
       {
	strcpy(riesBarco[con1].ident,Barco[i].ident);
	riesBarco[con1].riesgo=Barco[i].riesgo;
	riesBarco[con1].fecha.tm_year=Barco[i].fecha.tm_year;
	riesBarco[con1].fecha.tm_mon=Barco[i].fecha.tm_mon;
	riesBarco[con1].fecha.tm_hour=Barco[i].fecha.tm_hour;
	riesBarco[con1].hora.tm_hour=Barco[i].hora.tm_hour;
	riesBarco[con1].hora.tm_min=Barco[i].hora.tm_min;
	riesBarco[con1].hora.tm_sec=Barco[i].hora.tm_sec;
	aux1++;
	con1++;
       }
     cabeza=cabeza-1;
     fin=fin-1;    
     con_barco=con_barco-1;
     con=con-1;
     con2++;
   }
   else        
      {
       i=cabeza;
       if(Barco[i].riesgo==9)
       {
	strcpy(riesBarco[con1].ident,Barco[i].ident);
	riesBarco[con1].riesgo=Barco[i].riesgo;
	riesBarco[con1].fecha.tm_year=Barco[i].fecha.tm_year;
	riesBarco[con1].fecha.tm_mon=Barco[i].fecha.tm_mon;
	riesBarco[con1].fecha.tm_hour=Barco[i].fecha.tm_hour;
	riesBarco[con1].hora.tm_hour=Barco[i].hora.tm_hour;
	riesBarco[con1].hora.tm_min=Barco[i].hora.tm_min;
	riesBarco[con1].hora.tm_sec=Barco[i].hora.tm_sec;
	aux1++;
	con1++;
       }
       cabeza=cabeza +1;
       con=con-1;
       con_barco=con_barco-1;
       con2++;
     }
   gotoxy(2,3);
   printf("BARCO ELIMINADO");
  }
 getch();
}



void procesar()
{
  window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
  gotoxy(2,2);
  printf("BARCOS PROCESADOS :%d",con2);
  getch();   
}


void listar()
{
 int i;
 co=4;
 window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
 if(con_barco==0)            
 {
   gotoxy(2,2);
   printf("LA COLA ESTA VACIA");
 }
 else
 {
   for(i=cabeza;i<=fin;i++)      
   {
     gotoxy(2,3);printf("RIESGO     IDENTIFICACION   HORA DE LLEGADA   FECHA");
     gotoxy(4,co);printf("%d",Barco[i].riesgo);
     gotoxy(18,co);printf("%s",Barco[i].ident);
     gotoxy(36,co);printf("%d:", Barco[i].hora.tm_hour);
     printf("%d:", Barco[i].hora.tm_min);
     printf("%d", Barco[i].hora.tm_sec);
     gotoxy(49,co);printf("%d/",Barco[i].fecha.tm_hour);
     printf("%d/", Barco[i].fecha.tm_mon);
     printf("%d", Barco[i].fecha.tm_year);
     co++;
   }
 }
 getch();
}
    
void main()
{
char d;
escribe_menu2();
    sw2=0;
    d=getch();
    gotoxy(8,1);
    while ((d!=27)&&(sw2!=1))
    {
	  switch(d)
	  {
	     case 77:{
			switch(wherex())
			{
		      case 8:{
			       ref1(8,WHITE,BLACK,"Barco");
			       ref2(26,3,BLACK,"Listados");
			       break;
			     }
		     case 26:{
			       ref1(26,WHITE,BLACK,"Listados");
			       ref2(46,3,BLACK,"Ayuda");
			       break;
			     }
		     case 46:{
			       ref1(46,WHITE,BLACK,"Ayuda");
			       ref2(63,3,BLACK,"Salir");
			       break;
			     }
		     case 63:{
			       ref1(63,WHITE,BLACK,"Salir");
			       ref2(8,3,BLACK,"Barco");
			       break;
			     }
			}
		     break;
		     }
	     case 75:{
			switch(wherex())
			{
		      case 8:{
			       ref1(8,WHITE,BLACK,"Barco");
			       ref2(63,3,BLACK,"Salir");
			       break;
			     }
		     case 26:{
			       ref1(26,WHITE,BLACK,"Listados");
			       ref2(8,3,BLACK,"Barco");
			       break;
			     }
		     case 46:{
			       ref1(46,WHITE,BLACK,"Ayuda");
			       ref2(26,3,BLACK,"Listados");
			       break;
			     }
		     case 63:{
			       ref1(63,WHITE,BLACK,"Salir");
			       ref2(46,3,BLACK,"Ayuda");
			       break;
			     }
			}
		    break;
		     }
	  }
	  d=getch();
	  if(d==13)
	  {
	       switch(wherex())
	       {
		  case 8:{
			   menu1();
			   window(1,1,80,25);			   
			   clrscr();
			   escribe_menu2();
			   break;
			 }
		 case 26:{
			  menu2();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}
		 case 46:{
			  ayuda();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}
		case 63:{
			  salir();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}
	       }
	  }
    }
}




		