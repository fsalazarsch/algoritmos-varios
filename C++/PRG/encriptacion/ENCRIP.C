#include <stdio.h>
#include <io.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>
#include <fcntl.h>
#define g gotoxy
#define c cprintf
FILE *p,*q;
char *menu1[4]={"  ENCRIPTAR   ",
		" DESENCRIPTAR ",
		"  EMPAQUETAR  ",
		"   TERMINAR   "};


void rojo(int g1)
 {
  int i,j;
  textcolor(g1);
  for(i=12;i<=68;i++)
  for(j=7;j<=19;j++)
  {
  gotoxy(i,j);
  cprintf("Ы");
  }
	}
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


void ende()
	{
		int i;
		rojo(4);
		for(i=13;i<=21;i++)
		{
		 textcolor(7);

    g(i,7);  c("ЫЫЫЫЫЫ   ЫЫЫ    ЫЫЫ"); g(60-i,7); c("ЫЫЫЫЫ    ЫЫЫЫЫ       ");
    g(i,8);  c("ЫЫ       ЫЫЫЫЫ  ЫЫЫ"); g(60-i,8); c("ЫЫ  ЫЫ   ЫЫ          ");
    g(i,9);  c("ЫЫЫ      ЫЫ  ЫЫ ЫЫЫ"); g(60-i,9); c("ЫЫ   ЫЫ  ЫЫЫ         ");
    g(i,10); c("ЫЫ       ЫЫ   ЫЫЫЫЫ"); g(60-i,10);c("ЫЫ   ЫЫЫЫЫЫ          ");textcolor(11);
    g(i,11); c("ЫЫ       ЫЫ    ЫЫЫЫ"); g(60-i,11);c("ЫЫ   ЫЫЫЫЫЫ          ");
    g(i,12); c("ЫЫ       ЫЫ    ЫЫЫЫ"); g(60-i,12);c("ЫЫ   ЫЫ  ЫЫ          ");
    g(i,13); c("ЫЫ       ЫЫ    ЫЫЫЫ"); g(60-i,13);c("ЫЫ  ЫЫ   ЫЫ          ");
    g(i,14); c("ЫЫЫЫЫЫЫЫЫЫЫ    ЫЫЫЫ"); g(60-i,14);c("ЫЫЫЫЫ    ЫЫЫЫЫЫЫЫЫЫ  ");
    g(25,16); c("ENDE es un programa que permite");
    g(25,17); c("Encriptar, desencriptar y empaquetar");
    g(25,18); c("y desempecatar archivos,");
    g(25,19); c("                   1995");
    textbackground(1);
    g(25,22); c("PAOLA BRICEҐO    493226");
    g(25,23); c("ZORAIDA BEJARANO 493246");
    g(25,24); c("HEIVER CUESTA    492466");
    textbackground(4);
    }
 }


void abre_archivos()
{
 char nom[10],nom1[10];
 rojo(4);
 textbackground(4);
 textcolor(15);
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
   exit(1);
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
   exit(1);
  }
}

void imprimir_caracter(char t)
 {
  union REGS r;
  r.h.ah=0;
  r.h.al=t;
  r.x.dx=0;
  int86(0x17,&r,&r);

 }

void coloca_menu()
{
 int i;
 textbackground(7);
 textcolor(0);
 for(i=0;i<4;i++)
  {
   gotoxy(i*20+6,1);
   cprintf("%s", menu1[i]);
  }
   gotoxy(10,25);
   cprintf("      A Ayuda           C Cedritos      I Impresiўn");
   textbackground(4);
   textcolor(15);
   gotoxy(6,1);
   cprintf("%s", menu1[0]);
}

void empaquetar()
{}
void desencriptar()
{
 char ch;
 int j,start;
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
  c("І");

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
 rojo(4);
 ende();
}

void encriptar()
{
 char ch;
 int j,start;
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
  c("І");

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
 rojo(4);
 ende();
 }



void presenta ()
{
 int i,j;
 textbackground(1);
 clrscr();
 textcolor(7);
 for(i=1;i<=80;i++)
 {
  gotoxy(i,1);
  cprintf("Ы");
 }
 for(i=3;i<=77;i++)
 {
  gotoxy(i,25);
  cprintf("Ы");
 }
 textcolor(4);
 for(i=10;i<=70;i++)
 for(j=5;j<=20;j++)
 {
  gotoxy(i,j);
  cprintf("Ы");
 }
 textcolor(15);
 textbackground(4);
 for(j=11;j<=69;j++)
 {
  gotoxy(j,5);
  cprintf("Н");
  gotoxy(j,20);
  cprintf("Н");
 }
 for(j=6;j<=19;j++)
 {
  gotoxy(11,j);
  cprintf("є");
  gotoxy(69,j);
  cprintf("є");
 }
   gotoxy(11,5);cprintf("Й");
   gotoxy(69,5);cprintf("»");
   gotoxy(11,20);cprintf("И");
   gotoxy(69,20);cprintf("ј ");
   ende();
}

void menu()
{
 int salir=0,tecla,i,j;
 union REGS r,r1;
 char cadena [100],a,t;
 coloca_menu();
 i=0;
 while(!salir)
 {
  tecla=getch();
  if(tecla==0)
  {
  gotoxy(i*20+6,1);
  textbackground(7);
  textcolor(0);
  cprintf("%s",menu1[i]);
  tecla=getch();
  if(tecla==77)
  if(i==3)
  i=0;
  else
   i++;
   else
    if(tecla==75)
    if(i==0)
    i=3;
    else
      i--;
      else
       putchar(7);
       textcolor(15);
       textbackground(4);
       gotoxy (i*20+6,1);
       cprintf("%s",menu1[i]);
  }
   else
     if(tecla==13)
     {
      switch(i)
      {
	case 0: encriptar();break;
	case 1: desencriptar();break;
	case 2: empaquetar();break;
	case 3: salir=1; break;
	default:putchar(7);
      }
     }
     else
      if((tecla==65) || (tecla==97))
      {
       alarma();
       switch(i)
      {
       case 0:{rojo(4);
       gotoxy(35,7);
       textcolor(15);
       cprintf("ENCRIPTAR");
       g(19,9);  c("Encriptar un archivo significa tomar un   ");
       g(19,10); c("archivo de texto claro, es decir, el texto");
       g(19,11); c("fuente y general otro archivo que se llama");
       g(19,12); c("texto cifrado en el cual se almacena texto");
       g(19,13); c("oculto. Se utiliza una clave, que debe ser");
       g(19,14); c("un caracter alfabetico para iniciar la en-");
       g(19,15); c("cripciўn. Solicita el archivo fuente y el");
       g(19,16); c("archivo destino para el texto cifrado.   ");
       g(22,18); c("Presione ESPECIADORA PARA CONTINUAR...");
       getch(); break;}


       case 1: {rojo(4);
       gotoxy(35,7);
       textcolor(15);
       cprintf("DESENCRIPTAR");
	g(19,9);  c("Desencriptar un archivo significa tomar un");
	g(19,10); c("Desencriptar un archivo significa tomar un");
	g(19,11); c("Desencriptar un archivo significa tomar un");
	g(19,12); c("Desencriptar un archivo significa tomar un");
	g(19,13); c("Desencriptar un archivo significa tomar un");
	g(19,14); c("Desencriptar un archivo significa tomar un");
	g(19,15); c("Desencriptar un archivo significa tomar un");
	g(22,18); c("Presione especiadora para continuar...");

	getch();
	break;
    }

   case 2: { rojo(4);

	gotoxy(35,7);
	textcolor(15);
	cprintf("EMPAQUETAR");
	g(19,9);  c("Desencriptar un archivo significa tomar un");
	g(19,10); c("Desencriptar un archivo significa tomar un");
	g(19,11); c("Desencriptar un archivo significa tomar un");
	g(19,12); c("Desencriptar un archivo significa tomar un");
	g(19,13); c("Desencriptar un archivo significa tomar un");
	g(19,14); c("Desencriptar un archivo significa tomar un");
	g(19,15); c("Desencriptar un archivo significa tomar un");
	g(22,18); c("Presione especiadora para continuar...");
        getch();
	break;
      }

    case 3: { rojo(4);

	 gotoxy(17,6);
	 textcolor(15);
	 cprintf("UNIVERSIDAD ANTONIO NARIҐO * FACULTAD DE SISTEMAS");
	 g(19,8);   c("              ЫЫ                ");
	 g(19,9);   c("             ЫЫЫЫ    ЫЫЫЫЫЫЫЫ   ");
	 g(19,10);  c("          Ы  ЫЫЫЫ    ЫЫЫЫЫЫЫЫЫ  ");
	 g(19,11);  c("        Ы     ЫЫЫЫ        ЫЫЫ   ");
	 g(19,12);  c("     ЫЫ        ЫЫЫЫ       ЫЫ    ");
	 g(19,13);  c("    ЫЫЫ         ЫЫЫЫ     Ы      ");
	 g(19,14);  c("   ЫЫЫЫЫЫЫЫЫ     ЫЫЫЫ   Ы       ");
	 g(19,15);  c("    ЫЫЫЫЫЫЫЫ      ЫЫЫЫ          ");
	 g(19,16);  c("                   ЫЫ           ");
	 g(22,18);  c("PRESIONE ESPACIODORA PARA TERMINAR...");
	 getch();
	 exit(1);
	 break; }
    }
    alarma();
     ende();
   }

 else
      if((tecla==67) || (tecla==99))
      {
	rojo(4);
	textcolor(15);

      g(19,8);   c("           ЫЫ           UNIVERSIDAD ANTONIO NARIҐO");
      g(19,9);   c("          ЫЫЫЫ    ЫЫЫЫЫЫЫЫ FACULTAD DE SISTEMAS");
      g(19,10);  c("       Ы  ЫЫЫЫ    ЫЫЫЫЫЫЫЫЫ  ");textcolor(11);
      g(19,11);  c("     Ы     ЫЫЫЫ        ЫЫЫ PROGRAMACION AVANZADA");
      g(19,12);  c("  ЫЫ        ЫЫЫЫ       ЫЫ    "); textcolor(13);
      g(19,13);  c(" ЫЫЫ         ЫЫЫЫ     Ы   PAOLA, ZORAIDA, HEIVER");
      g(19,14);  c("ЫЫЫЫЫЫЫЫЫ     ЫЫЫЫ   Ы    493226  493246   492466");
      g(19,15);  c(" ЫЫЫЫЫЫЫЫ      ЫЫЫЫ          "); textcolor(14);
      g(19,16);  c("                ЫЫSantaf‚ de Bogot , Junio de 1995");
      alarma1();
      g(22,18); c(" PRESIONE ESPACIODORA PARA CONTINUAR...");
      getch();
      ende();
   }

     else
	if((tecla==73) || (tecla==105))
	{
	  rojo(4);
	  gotoxy(35,7);
	  textcolor(15);
	  cprintf("IMPRESION");
	  g(19,9); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,10); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,11); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,12); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,13); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,14); c("Desemcriptar es un archivo que significa tomar un");
	  g(19,15); c("Desemcriptar es un archivo que significa tomar un");
	  g(22,18); c("PRESIONE ESPACIADORA PARA CONTINUAR...");
	  getch();
	  rojo(4);
	  g(15,8);


	  textbackground(4);
	  textcolor(15);
	  r.h.ah=2;
	  r.x.dx=0;
	  int86(0x17,&r,&r1);
	  if((r1.h.ah & 0x80)==0x80)
	  {
	   g(15,8);
	   textbackground(4);
	   textcolor(15);
	   c("UNIDAD DE IMPRESORA APAGADA\n");
	  }

	 if((r1.h.ah & 0x40)==0x40)
	  {
	  g(15,8);
	  textbackground(4);
	  textcolor(15);
	  c("UNIDAD DE IMPRESORA RECONOCIDA\n");
	 }

	  if((r1.h.ah & 0x20)==0x20)
	  {
	  g(15,8);
	  textbackground(4);
	  textcolor(15);
	  c("                  Sin papel\n");
	}

	  if((r1.h.ah & 0x10)==0x10)
	  {
	  g(15,8);
	  textbackground(4);
	  textcolor(15);
	  c("Unidad de Impresora Seleccionada\n");
      }

      if((r1.h.ah & 0x08)==0x08)
	  {
	  g(15,8);
	  textbackground(4);
	  textcolor(15);
	  c("Error en Unidad E/S\n");
	  }

    if((r1.h.ah & 0x01)==0x01)
	  {
	  g(15,8);
	  textbackground(4);
	  textcolor(15);
	  c("Unidad  desconectada\n");
	  }
	 g(15,12); c("Escriba una frase para probar impresora...");
	 g(15,13); j=1;
	 textcolor(15);
	 a=getche();

	   while(a!=27)
	   {
	   imprimir_caracter(a);
	   g(15+j++,13); a=getche();

	   }
	imprimir_caracter('\0');
	rojo(4);
	alarma();
	ende();
       }
    else { putchar(7); putchar(7);}

    }
 }



void main()
{
 presenta();
 menu();
}
