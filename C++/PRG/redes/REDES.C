#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>
#include <fcntl.h>
#define g gotoxy
#define c cprintf

void alarma();
void alarma1();
void abre_archivos();
void crea_archivos();
void coloca_menu();
void desencriptar();
void encriptar();
void presenta ();
void menu();


FILE *p,*q;
char *menu1[5]={"ENCRIPTAR",
		"DESENCRIPTAR",
		"CREAR ARCHIVO",
		"LEER ARCHIVO",
		"TERMINAR"
		};




void alarma()
{

  double i;
   for(i=3000;i>100;i=i-300)
   {
    sound(i);
    delay(100);
    nosound();
   }
 }



void alarma1()
 {
  double i;
  for(i=3000;i>100;i=i-300)
   {
    sound(i);
    delay(100);
    nosound();
   }
 }


void abre_archivos()
{
 char nom[10],nom1[10];
 textbackground(15);
 textcolor(0);
 clrscr();
 g(29,8);
 c("** ENCRIPCION DE TEXTOS **");
 g(15,10);
 c("Nombre del archivo fuente:  ");
 cscanf("%s",&nom);
 p=fopen(&nom,"r");
   if(p==NULL)
    {
      g(20,16);
      c("ERROR EN EL ARCHIVO DE ENTRADA");
      getch();
      menu();
    }
  g(15,11);
  c("Nombre del Archivo destino:  ");
  cscanf("%s",&nom1);
  q=fopen(&nom1,"w");
 if(q==NULL)
  {
   g(20,16);
   c("ERROR EN EL ARCHIVO DE SALIDA");
   getch();
   menu();
  }
}


void crea_archivos()
{
 char nom2[10],c;
 textbackground(15);
 textcolor(0);
 clrscr();
 g(23,7);
 printf("** CREAR ARCHIVO **\n");
 g(23,10);
 printf("Nombre del archivo destino");
 cscanf("%s",&nom2);
 p=fopen(&nom2,"w");
   if(p==NULL)
  {
   g(20,16);
   printf("ERROR EN EL ARCHIVO DE ENTRADA");
   getch();
   menu();
  }
  clrscr();
  textbackground(0);
  textcolor(15);
  g(20,2);
  printf("** DIGITE EL TEXTO DEL ARCHIVO **\n");
  g(1,3);
  while((c=getch())!='@')
	{
	 putc(c,p);

	 printf("%c",c);
	}
	fclose(p);
	clrscr();
	textbackground(15);
	textcolor(0);
	menu();
  }



void coloca_menu()
{
 int i;
 textbackground(15);
 textcolor(0);
 clrscr();
 for(i=0;i<5;i++)
  {
   gotoxy(i*15+7,1);
   cprintf("%s", menu1[i]);
  }
   gotoxy(20,25);
   cprintf("           UNIVERSIDAD ANTONIO NARI¥O      ");
   textbackground(4);
   textcolor(15);
   gotoxy(7,1);
   cprintf("%s", menu1[0]);
}

void desencriptar()
{
 char ch;
 int j,start=0;
 abre_archivos();
 g(18,14);
 c("   CLAVE  (solo caracteres alfabeticos):   ");

 do
 {
  putchar(7);
  g(18,15); textcolor(1);
  c("      D I G I T E   L A   C L A V E      ");
  delay(800);
  g(20,15);
  c("                                      ");
  start=getch();
  start=tolower(start);
 }while((start < 'a') || (start > 'z'));
  g(20,15);
  c("      C L A V E   A C E P T A D A  ");
  g(20,16); textcolor(14);
  c("      D E S E N C R I P T A N D O....");
  start=start-'a';
  g(12,17);
  j=0;

  do
  {
    if(j==55)
    {
     g(12,17);
     c("                                       ");
     j=0;
    }

  delay(10);
  g(12+j++,17);
  c("²");

      ch=fgetc(p);
      ch=tolower(ch);
      if(isalpha(ch))
	{
	 ch=ch-start;
	 if(ch<'a')
	  ch=ch+26;
	}

 fputc(ch,q);
 if(feof(p)) break;
}while((!ferror (p)) && (!ferror(q)));

 g(15,19);
 alarma1();
 c("    DESENCRIPCION EXITOSA.!    Presione ENTER");
 fclose(p);
 fclose(q);
 getch();
 menu();
}

void lee_archivos()
{
char nom2[10],c;
 textbackground(15);
 textcolor(0);
 clrscr();
 g(23,7);
 printf("** LEER  ARCHIVO **\n");
 g(23,10);
 printf("Nombre del archivo de entrada");
 cscanf("%s",&nom2);
 p=fopen(&nom2,"rb");
   if(p==NULL)
  {
   g(20,16);
   printf("ERROR EN EL ARCHIVO DE ENTRADA");
   getch();
   menu();
  }
  clrscr();
  textbackground(0);
  textcolor(15);
  g(20,2);
  printf("** CONTENIDO DEL  ARCHIVO **\n");
  g(1,3);
	do
	 {
	 c=fgetc(p);
	 printf("%c",c);
	}while(c!=EOF);
	delay(1000);
	 fclose(p);
	getch();
	clrscr();
	textbackground(15);
	textcolor(0);
	menu();
  }

/* if(feof(p)) break;
}while((!ferror (p)) && (!ferror(q)));*/




void encriptar()
{
 char ch;
 int j,start=0;
 abre_archivos();
 g(18,14);
 c("   CLAVE  (solo caracteres alfabeticos):   ");

 do
 {
  putchar(7);
  g(18,15); textcolor(1);
  c("      D I G I T E   L A   C L A V E      ");
  delay(800);
  g(20,15);
  c("                                      ");
  start=getch();
  start=tolower(start);
 }while((start < 'a') || (start > 'z'));
  g(20,15);
  c("      C L A V E   A C E P T A D A  ");
  g(20,16); textcolor(14);
  c("       E N C R I P T A N D O....");
  start=start-'a';
  g(12,17);
  j=0;

  do
  {
    if(j==55)
    {
     g(12,17);
     c("                                       ");
     j=0;
    }

  delay(10);
  g(12+j++,17);
  c("²");

      ch=fgetc(p);
      ch=tolower(ch);
      if(isalpha(ch));
	{
	 ch=ch+start;
	 if(ch>'z')
	  ch=ch-26;
	}

fputc(ch,q);
if(feof(p)) break;
}while((!ferror (p)) && (!ferror(q)));
 g(15,19);
 alarma1();
 c("    ENCRIPCION EXITOSA.!    Presione ENTER");
 fclose(p);
 fclose(q);
 getch();
 menu();
 }





void menu()
{
 int salir=0,tecla=0,i,j;
 union REGS r,r1;
 char cadena [100],a,t;
 coloca_menu();
 i=0;
 while(!salir)
 {
  tecla=getch();
  if(tecla==0)
  {
  gotoxy(i*15+7,1);
  textbackground(7);
  textcolor(0);
  cprintf("%s",menu1[i]);
  tecla=getch();
  if(tecla==77)
  if(i==4)
  i=0;
  else
   i++;
   else
    if(tecla==75)
    if(i==0)
    i=4;
    else
      i--;
      else
       putchar(7);
       textcolor(15);
       textbackground(4);
       gotoxy (i*15+7,1);
       cprintf("%s",menu1[i]);
  }
   else
     if(tecla==13)
     {
      switch(i)
      {
	case 0: encriptar();break;
	case 1: desencriptar();break;
	case 2: crea_archivos();break;
	case 3: lee_archivos();break;
	case 4: exit(1);
	default:putchar(7);
      }
     }
  }
 }

void main()
{
 textbackground(15);
 clrscr();
 menu();
 textbackground(0);
clrscr();
}
