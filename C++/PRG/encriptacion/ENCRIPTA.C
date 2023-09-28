
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <bios.h>
#define MAXWORDLEN 10
#define NUL ((char)0)
#define SPACE ((char)0x20)

char *menu[]={"   ENCRIPTAR",
	      "  DESENCRIPTAR ",
	      "      CAPTURA ",
	      "        SALIR  " };

void editar();
void code();
void vali();
void vali1();
void cursor();
void decode();
void apagar();
void vete();
void main();
char line1 [100];
int h;
char aux [134];
int k=0;
int j=0;



void main()/*CIFRADO POR MANIPULACION DE BITS*/
{
 int wordlimit;

 editar();


}

void editar()


{

 int fila,col,no=4,j=0,m;
 int opcion=0;
 char tecla,start;
 int salir=0;


  textbackground(11);
  clrscr();
  m=((80-no*strlen(menu[1]))/(no+1));
  textbackground(0); textcolor(15);
  for (j=0;j<no;j++)
    {
     gotoxy(((m+strlen(menu[j]))*j+m),1);
     cprintf(menu[j]);
    }
  textbackground(5); textcolor(15);
  gotoxy(m,1); cprintf(menu[0]);
    apagar();

  while(!salir)
   {
        tecla=getch();
	if (tecla==13)
         {
          switch(opcion) {
	     case 0: {windows();code(line1 ,"a:texto1.txt"); break; }
	     case 1: {windows();decode("a:texto1.txt","a:texto2.txt"); break; }
	     case 2: {vali();  getch(); editar(); break;}
	     case 3: {exit(0); break; }
           }
        }
        else{
	textbackground(0); textcolor(15);
	gotoxy(((m+strlen(menu[opcion]))*opcion+m),1);
        cprintf(menu[opcion]);}
        if (tecla==0)
         {
          tecla=getch();
            if (tecla==75)
               if (opcion==0)
		   opcion=3;
               else
                 opcion--;
            else
              if (tecla==77)
		 if (opcion==3)
                     opcion=0;
                 else
                    opcion++;
        textbackground(5); textcolor(15);
	gotoxy(((m+strlen(menu[opcion]))*opcion+m),1);
        cprintf(menu[opcion]);
      }
     else
     {
      textbackground(5);textcolor(15);
      gotoxy(((m+strlen(menu[opcion]))*opcion+m),1);
      cprintf(menu[opcion]);
     }
   }

}

windows(){
textbackground(13);
textcolor(9+BLINK);
gotoxy(12,18);
cprintf("ENCRIPTADO EN PROCESO");
}
void apagar()
{
union REGS r;
r.h.ah=1;
r.h.ch=32;
int86(0x10,&r,&r);
}
void cursor()
{
union REGS r;
r.h.ah=1;
r.h.cl=2;
r.h.ch=7;
int86(0x10,&r,&r);
}
void vete(int x,int y )
{
union REGS r;
r.h.ah=2;
r.h.dl=y;
r.h.dh=x;
r.h.bh=0;
int86(0x10, &r,&r);
}

/************************************************************************/

void code(texto,output)
char *texto, *output;
{
  int ch;
  FILE *fp1, *fp2;

  if((fp1=fopen(texto, "r"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE ENTRADA\n");
    getch();
    exit();
  }
  if((fp2=fopen(output, "w"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE SALIDA\n");
    getch();
    exit();
  }
  do {
    ch=getc(fp1);
    ch=~ch;
    putc(ch,fp2);
    if(feof(fp1)) break;
  }while(!ferror(fp1) && !ferror(fp2) && !feof(fp1) && !feof(fp2));
  fclose(fp1); fclose(fp2);
  cursor();
}
/**************************************************************************/
void decode(texto,output)
char *texto, *output;
{
  int ch;
  FILE *fp1, *fp2;

  if((fp1=fopen(texto, "r"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE ENTRADA\n");
    exit();
  }
  if((fp2=fopen(output, "w"))==NULL)
  {
    printf("NO PUEDO ABRIR ARCHIVO DE SALIDA\n");
    exit();
  }
  do {
    ch=getc(fp1);
    ch=~ch;
    putc(ch,fp2);
    if(feof(fp2)) break;
  }while(!ferror(fp1) && !ferror(fp2) && !feof(fp1) && !feof(fp2));
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
/* Advance to the first non-space. */
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
  FILE	*infile;        /* Input file. */
  char	linebfr[1000],  /* Input line buffer, very long for safety. */
        *wordptr;       /* Pointer to next word in linebfr. */
  int     i;            /* Scratch variable. */
  static int	wordlencnt[MAXWORDLEN],
                        /* Word lengths are counted in elements 1 to
                         MAXWORDLEN. Element 0 isn't used. The array is
                         static so that the elements need not be set to
                         zero at run time. */
	        overlencnt;     /* Overlength words are counted here. */


  vete(15,19);
  cursor();
  textcolor(10);
  printf( "ENTRE LA UNIDAD Y EL NOMBRE DEL ARCHIVO : " );
  gets(linebfr);
  strcpy (line1,linebfr);
  while (linebfr[k] !='.' && linebfr[k] != '\0')
  {
  aux [j]=linebfr[k];
  k++;
  j++;
  }
  aux [j]='\0';
  h=strlen(aux);
  if(h>8) printf("NO PUDE DIGITAR UN ARCHIVO CON MAS DE 8 CARACTERES /n");

  if ( !strlen(linebfr) ) {
  printf("NO DIGITO EL NOMBRE DEL ARCHIVO");getch();
    editar();
   /* return(1);*/

  }

  infile = fopen( linebfr, "r" );
  if ( !infile ) {
    printf( "Can't open input file!\n" );
   /* return(0);*/
  }

  while (   fgets( linebfr, sizeof(linebfr), infile )   )   {
    printf("%s\n",linebfr);
    /* Check for buffer overflow & remove the trailing newline. */
    i = strlen(linebfr);
    if ( linebfr[i-1] != '\n' ){
      printf( "    ", linebfr );

      getch();
      editar(); }
    else
      linebfr[i-1] = NUL;

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
