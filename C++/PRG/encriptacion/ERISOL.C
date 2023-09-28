#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>
#include <graphics.h>
#define MAXWORDLEN 10
#define NUL  ((char)0)
#define SPACE ((char)0x20)
#define MAX 14
void code(), decode();
void cursor();
void apagar();
void vali();
void vali1();
void main();
int menu();
void captura_numero();
char line1 [100];
char aux [10];
char aix[5];
int k,j;
int m=0;
int h=0;
int cadena2=0;
/**********************************************************************/
int cuadro(int x1,int y1, int x2,int y2)
{
   int i;
   for (i=x1;i<=x2;i++){
   /* sound(700);
    delay(100); */
    gotoxy (i,y1);
    printf ("Í");
    gotoxy (i,y2);
    printf ("Í");

   }

for (i=y1;i<=y2;i++){
   /* sound(350);
    delay(100);*/
    gotoxy(x1,i);
    printf ("º");
    gotoxy(x2,i);
    printf ("º");
 }
    gotoxy(10,5);
    printf("É");
    gotoxy(60,5);
    printf("»");
    gotoxy(10,22);
    printf("È");
    gotoxy(60,22);
    printf("¼");
  return(0);

}
/***********************************************************************/
int menu()
 {
 int color=0;
 clrscr();
 cuadro(10,5,60,22);
 for (color=0;color<=13;color++){
 textcolor(color);
 gotoxy (22,6); cprintf ("UNIVERSIDAD ANTONIO NARI¥O");
 gotoxy(24,7);  cprintf ("  ENCRIP. POR SUSTITUCION ");
 gotoxy(25,8); cprintf ("     MENU PRINCIPAL      ");
 gotoxy(15,10); cprintf("1. CAPTURAR ARCHIVO");
 gotoxy(15,12); cprintf("2. ENCRIPTAR");
 gotoxy(15,14); cprintf("3. DESENCRIPTAR");
 gotoxy(15,16); cprintf("4. IMPRIMIR");
 gotoxy(15,18); cprintf("5. SALIR ");
 delay(300);
 textcolor(6);
 }
 return(1);
 }
 /***********************************************************************/

 void main()
 {
 clrscr();
 menu();
 captura_numero();
 }
 /**********************************************************************/
 void captura_numero()
 {
  char start;
  int c=0;
 while (c!=5){
   gotoxy(20,20);
   cprintf ("DIGITE OPCION DEL 1 AL 5:  ");
   cursor();
   c=getche();
      switch (c)
      {
      case 49 :clrscr(); printf("V");vali(); break;
      case 50 :clrscr();  printf("E"); windows();start=getch();
	       printf("ENCRIPTANDO ARCHIVO");apagar(); code("a:texto1.txt","a:texto2.txt",start);
	       menu(); break;
      case 51 :clrscr();  printf("D"); windows();start=getch();printf("DESENCRIPCION EN PROCESO");
	       apagar(); decode("a:texto2.txt","a:text.txt",start);menu(); break;
      case 52 :clrscr(); imprime();menu();break;
      case 53 : clrscr(); exit(0); menu(); printf("S");
      default:{gotoxy(24,23); printf ("NO EXISTE ESTA OPCION "); break;}

       }

      }
   }

/*********************************************************************/
 windows()
{
clrscr();
textbackground(16);
textcolor(13);
gotoxy(13,13);
cprintf("DIGITE LA CLAVE \n");
cursor();

}
/***********************************************************************/
#include<fcntl.h>
imprime()
{
 char b;
 char archivo[16];
 FILE *fp1;
 clrscr();
 gotoxy(15,15);
 printf("DIGITE ARCHIVO QUE DESEA IMPRIMIR: ");
 scanf("%s",&archivo);
 cursor();
 clrscr();
 if((fp1=fopen(archivo,"r"))==NULL)
 {
   apagar();
   window(15,15,60,15);
   textbackground(9);
   clrscr();
   gotoxy(18,18);
   printf("    NO PUEDO ABRIR EL ARCHIVO DE ENTRADA\n ");getch();
   exit(1);
 }
 b=fgetc(fp1);
 while(!feof(fp1))
 {
    biosprint(0,b,0);
    b=fgetc(fp1);
 }
  biosprint(0,'\n',0);
  fclose(fp1);
return;
}
/**********************************************************************/

void apagar()
{
union REGS r;
r.h.ah=1;
r.h.ch=32;
int86(0x10,&r,&r);
}
/************************************************************************/
void cursor()
{
union REGS r;
r.h.ah=1;
r.h.cl=2;
r.h.ch=7;
int86(0x10,&r,&r);
}

/************************************************************************/

void code(input,output,start)
char *input, *output;
char start;
{
  int ch;
  FILE *fp1, *fp2;

  if((fp1=fopen(input, "r"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE ENTRADA\n");
    exit(1);
  }

   if((fp2=fopen(output, "w"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE SALIDA\n");
    exit(1);
  }
  start=tolower(start);
  start=start-'a';
  do {
    ch=getc(fp1);
    ch=tolower(ch);
    if(isalpha(ch))
    {
      ch+=start;
      if(ch>'z') ch-=26;
    }

    putc(ch,fp2);
    if(feof(fp1)) break;
  }while(!ferror(fp1) && !ferror(fp2));
  fclose(fp1); fclose(fp2);
  cursor();
}
/**************************************************************************/
void decode(input,output,start)
char *input, *output;
char start;
{
  int ch;
  FILE *fp1, *fp2;

  if((fp1=fopen(input, "r"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE ENTRADA\n");
    exit(1);
  }

   if((fp2=fopen(output, "w"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE SALIDA\n");
    exit(1);
  }
  start=tolower(start);
  start=start-'a';
  do {
    ch=getc(fp1);
    ch=tolower(ch);
    if(isalpha(ch))
    {
      ch-=start;
      if(ch<'a') ch+=26;
    }

    putc(ch,fp2);
    if(feof(fp1)) break;
  }while(!ferror(fp1) && !ferror(fp2));
  fclose(fp1); fclose(fp2);
  cursor();
}
/**************************************************************************/


void vali1()
{
 void vali();
 }
char *nextword(char *wordptr)
{
/* avance si el primero no es espacio. */
  while ( *wordptr==SPACE )
    wordptr++;
    return(wordptr);
}


int wordlen(char *wordptr)
{
  char *wordlimit;
  wordlimit = wordptr;
  while ( *wordlimit & *wordlimit!=SPACE )
    wordlimit++;
  return( wordlimit-wordptr );
}


void vali(void)
{
  FILE	*infile;        /* entra archivo. */
  char	linebfr[1000],  /* Input line buffer, very long for safety. */
	*wordptr;       /* apuntador a la siguiente palabra a la linea del buffer. */
  int     i;            /* Scratch variable. */
  static int	wordlencnt[MAXWORDLEN],
			/* Word lengths are counted in elements 1 to
			 MAXWORDLEN. Element 0 isn't used. The array is
			 static so that the elements need not be set to
			 zero at run time. */
		overlencnt;     /* Overlength words are counted here. */
  gotoxy(5,5);
  textcolor(3);
  printf("ATENCION: ESTE ES UN EJEMPLO DE UN PROGRAMA PARA LA PRACTICA.\n");
  gotoxy(5,6);
  printf("EN ESTA APLICACION,EL USUARRIO INTRODUCE EL NOMBRE DEL ARCHIVO\n");
  gotoxy(5,7);
  printf("QUE DESEA MIRAR PARA ENCRIPTAR.\n");
  gotoxy(5,8);
  printf("PARA SU DESARROLLO ADEMAS DEBE DAR TAMBIEN EL DRIVE DONDE SE\n");
  gotoxy(5,9);
  printf(" ENCUENTRA EL ARCHIVO.\n\n");

  gotoxy(15,15);
  cursor();
  textcolor(10);
  printf( "DIGITE EL NOMBRE DEL ARCHIVO: " );
  gets(linebfr);
  strcpy (line1,linebfr);
  k=j=0;
  while(line1[k]!=46 && line1[k]!= '\0')
  {
  aux [j]=line1[k];
  k++;
  j++;
  }
  aux [j]='\0';
  h=strlen(aux);
  if(h>8) printf("NO PUEDE DIGITAR UN ARCHIVO CON MAS DE 8 CARACTERES \n");
  j=0;
  k++;
  while (linebfr[k]!='.' && linebfr[k]!='\0')
  {
  aix[j]=linebfr[k];
  k++;
  j++;
  }
  aix[j]='\0';
  m=strlen(aix);

  if (m>3) printf("NO PUEDE ACEPTAR UN EXTENSION DE + DE3 CA");
  getch();

  if ( !strlen(linebfr) ) {
  printf("NO DIGITO EL NOMBRE DEL ARCHIVO");getch();
    menu();captura_numero();
   /* return(1);*/

  }

  infile = fopen( linebfr, "r" );
  if ( !infile ) {
    printf( "NO PUEDE ABRIR ARCHIVO!\n" );
    clrscr();menu();captura_numero();
   /* return(0);*/
  }

  while (   fgets( linebfr, sizeof(linebfr), infile )   )   {
    printf("%s\n",linebfr);
    /* Check for buffer overflow & remove the trailing newline. */
    i = strlen(linebfr);
    if ( linebfr[i-1] != '\n' ){
       clrscr(); menu(); captura_numero();}
    else
      linebfr[i-1] = NUL;menu(); captura_numero();

    /* lineptr points to the 1st word in linebfr (past leading spaces). */
    wordptr = nextword(linebfr);

    /* Each loop processes one word. The loop ends when [nextword]
       returns NULL, indicating there are no more words. */
    while (*wordptr) {
    /* Find the length of this word, increment the proper element of the
       length count array, & point to the space following the word. */
      i = wordlen(wordptr);
      if ( i > MAXWORDLEN )
	overlencnt++;
      else
      ;
      wordlencnt[i]++;
    wordptr += i;

      /* Find the next word (if any). */
      wordptr = nextword(wordptr);
    }
  }

/* Print the word length counts. Each loop prints one. */
  printf(  "  Length Count\n" );
  for ( i=1; i<MAXWORDLEN; i++ )
    printf( "  %5d %5d\n", i, wordlencnt[i] );
  printf( "Greater %5d\n", overlencnt );

/* Close the file & quit. */
  fclose(infile);


}
/************************************************************************/
