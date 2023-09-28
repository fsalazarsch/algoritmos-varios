#include <conio.h>   
#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>
#include <stdlib.h>
#include <setjmp.h>

/********ESTRUCTURAS********/

struct alumno
{ 
   char cod[45];
   char nom[45];
   char apel[45];
   char sex;
   struct alumno *sig;
   struct notas *ady;
};

struct notas
 {
  float nota;
  struct notas *sig;
 };

/********FUNCIONES********/
void cuadros1(int x1,int x2,int y1,int y2);
void cuadros1(int x1,int x2,int y1,int y2);
void clave();
void leer_datos();
void mostrar();
void consulta_codigo();
void modificar();
void mujeres_ganaron();
void alumnos_perdieron();
void hombres_ganaron();
void prom_mayor_trescinco();
void borrar();
void cargar();
void ordenar();
void piso_color();
void ref1();
void ref2();
void marco();
void marco2();
void fondo();
void menu1();
void menu2();
void escribe_menu();
void escribe_menu2();
void escribe_menu3();
void ayuda();
void salir();


char op2[7][30]={" ","Listado General          ","Mujeres que ganaron materia",
		      "Hombres que ganaron materia","Alumnos perdieron materia",
		      "Promedios mayores a 3.5","Salir                    "};
char op[6][10]={" ","Adicionar","Consultar","Eliminar ","Modificar","Salir    "};

char nombre[40],apellido[40],opcion,sexo;
char codigo[40];


int n,con,sw2,i,sw,c,st;
float la_nota[4];
struct alumno *ptr=NULL,*auxalumn;

 void cuadro(int x1,int x2,int y1,int y2)
{
    int j,i,k;
     textcolor(WHITE);textbackground(0);
     for(j=x1;j<=x2;j++)
       { delay(10);
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { delay(10);
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
    textcolor(WHITE);textbackground(0);

}

 void cuadros1(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(WHITE);textbackground(0);
     for(j=x1;j<=x2;j++)
       { delay (10);
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { delay(10);
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
     textcolor(WHITE);textbackground(0);

}

void clave()
{
 char cl[12],ceci[12],activa;
  int i,x,j ;
  textcolor(WHITE);textbackground(0);
  activa='n';
  strcpy(ceci,"9810402667");
  x=1;

  while((x<=3) && (activa=='n'))
  {
    j=45;
     clrscr();cuadros1(1,79,1,24);cuadros1(15,59,3,5);cuadros1(21,55,11,13);
     gotoxy(20,4);printf("OPCION:CLAVE DE ACCESO AL SISTEMA");
     gotoxy(22,12); printf("DIGITE CLAVE DE ACCESO:");
      for(i=0;i<10;i++)
	{
	 gotoxy(j,12);cl[i]=getch();gotoxy(j,12);printf("*");
	  j++;
	}
	 cl[i]='\0';
	if(strcmp(cl,ceci)==0)
	  {
	    activa='s';
	    clrscr();
	    cuadros1(1,79,1,24);cuadros1(15,59,3,5);
	    gotoxy(20,4);printf("OPCION:CLAVE DE ACCESO AL SISTEMA");
	    gotoxy(29,12);printf("<<clave correcta>>");
	    gotoxy(15,23);printf("PULSE UNA TECLA PARA CONTINUAR.....");getch();
	
     }
     else
      {clrscr();
	    cuadros1(1,79,1,24);
	    cuadros1(28,49,11,13);
	    textcolor(WHITE+128);textbackground(0);
	    gotoxy(29,12);cprintf("<<clave incorrecta>>");
	    getch();
	    textcolor(WHITE);textbackground(0);
       }
     x++;
     }
      if(activa=='n')
      { clrscr();
      gotoxy(18,10);printf("    LA CLAVE NO FUE LA CORRECTA     ");
       gotoxy(15,23);printf(" PULSE UNA TECLA PARA CONTINUAR.....");
       getch();
       exit(1);
      }
  }


   void escribe_menu2()
   {
    textbackground(BLACK);
    clrscr();
    window(1,1,80,25);
    gotoxy(1,1);
    fondo(2,81,LIGHTGRAY);
    piso_color(3,BLACK);
    gotoxy(8,1);
    cprintf("Estudiante");
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
    cprintf("Copyrigth (c) 1997 UDES   Valledupar.   Derechos reservados del Autor ");
    gotoxy(2,25);
    cprintf("Unica Versi¢n 2 de Abril 1997 Dise¤o: Heyner A. Aroca Araujo Cod: 95131119");
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
	   c=getch();
	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 cargar();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
			}
		case 2:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 consulta_codigo();
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
			  if (wherey() == 6)
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
			  if (wherey() == 1) gotoxy (3,6);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }
	   c=getch();
	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 ordenar();
			 mostrar();
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
			 ordenar();
			 mujeres_ganaron();
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
			 ordenar();
			 hombres_ganaron();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
		case 4:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 ordenar();
			 alumnos_perdieron();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
		case 5:{
			 piso_color(BLACK,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 ordenar();
			 prom_mayor_trescinco();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
		case 6:{
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
     marco2(16,3,47,8);
     piso_color(BLACK,WHITE);
     for(i=2;i<=6;i++)
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

void prom_mayor_trescinco()
{
  struct alumno *auxalum2;
  struct notas *auxnota1,*auxnota2,*auxnotas;
  int  j,c,st;
  float prom;
  j=0;
  c=2;st=1;
  window(3,3,78,22);
  piso_color(BLACK,WHITE);
  clrscr();
  if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  }
  else
  {
  printf("CODIGO  NOMBRE  APELLIDO   SEXO   NT1   NT2   NT3   NT4    DEF\n");
  auxalum2=ptr;
  while(auxalum2!=NULL)
  {
   sw=1;
   auxnota2=auxalum2->ady;
    while(auxnota2!=NULL)
    { auxnotas=auxnota2;
      auxnota2=auxnota2->sig;
    }
     if(auxnotas->nota>3.5)
     {
     sw=2;
     }
    if(sw==2)
      {
	gotoxy(1,c);printf("%s",auxalum2->cod);
	gotoxy(8,c);printf("%s",auxalum2->nom);
	gotoxy(18,c);printf("%s",auxalum2->apel);
	gotoxy(30,c);printf("%c",auxalum2->sex);
	st=2;
	auxnota1=auxalum2->ady;
	j=35;
	while(auxnota1!=NULL)
	{
	  gotoxy(j,c);printf("%.2f",auxnota1->nota);
	  auxnota1=auxnota1->sig;
	  j=j+8;
	}
	c++;
      }
      auxalum2=auxalum2->sig;
       }
    if(st==1)
    {
    gotoxy(1,2);  printf("NO EXISTEN ALUMNOS CON PROMEDIOS MAYOR QUE 3.5");
    }
    }
    getch();
}

void cargar()
{
   struct alumno *nn1; char opcion;
   struct notas *nn2,*auxnotas,*auxnot;
   float prom; 
   do
    {
	window(3,3,78,22);
	piso_color(BLACK,WHITE);
	clrscr();
	leer_datos();
	nn1=malloc(sizeof(struct alumno));
	strcpy(nn1->nom,nombre);
	strcpy(nn1->apel,apellido);
	strcpy(nn1->cod,codigo);
	nn1->sex=sexo;
	nn1->sig=NULL;
	nn1->ady=NULL;
	if(ptr==NULL)
	   {
	    ptr=nn1;
	    auxalumn=ptr;
	    sw=1; con=0; prom=0;
	    for(i=0; i<=4; i++)
	      {
		nn2=malloc(sizeof(struct notas));
		if (i<4)
		  {
		   nn2->nota=la_nota[i];
		   nn2->sig=NULL;
		   if(auxalumn->ady==NULL)
		     {
		     auxalumn->ady=nn2;
		     }
		   else
		     {
		      auxnotas=auxalumn->ady;
		      while(auxnotas->sig!=NULL)
			{ 
			 auxnotas=auxnotas->sig;
			}
		      auxnotas->sig=nn2;
		     }
		   }
		else
		  {
		   auxnot=auxalumn->ady;
		   while(auxnot!=NULL)
		     {
		      prom=prom + auxnot->nota;
		      auxnot=auxnot->sig;
		     }
		   nn2->nota=prom/4;
		   nn2->sig=NULL;
		   auxnotas=auxalumn->ady;
		   while(auxnotas->sig!=NULL)
		     {
		      auxnotas=auxnotas->sig;
		     }
		   auxnotas->sig=nn2;
		  }
	      } 
	  }
      
	else
	   {
	    auxalumn->sig=nn1;
	    auxalumn=nn1;
	    sw=1; con=0; prom=0;
	    for(i=0; i<=4; i++)
	       {
		nn2=malloc(sizeof(struct notas));
		if (i<4)
		   {
		    nn2->nota=la_nota[i];
		    nn2->sig=NULL;
		    if(auxalumn->ady==NULL)
		       {
			auxalumn->ady=nn2;
		       }
		    else
		      {
		       auxnotas=auxalumn->ady;
		       while(auxnotas->sig!=NULL)
			   {
			   auxnotas=auxnotas->sig;
			   }
		       auxnotas->sig=nn2;
		      }
		    }
		else
		  {
		   auxnot=auxalumn->ady;
		   while(auxnot!=NULL)
		     {
		      prom=prom + auxnot->nota;
		      auxnot=auxnot->sig;
		      }
		   nn2->nota=prom/4;
		   nn2->sig=NULL;
		   auxnotas=auxalumn->ady;
		   while(auxnotas->sig!=NULL)
		     {
		      auxnotas=auxnotas->sig;
		     }
		   auxnotas->sig=nn2;
		  }
		}
	       }

	do
	 {
	  clrscr();
	  printf("DESEA ADICCIONAR OTRO EN LA LISTA (y/n):");
	  opcion=getche();
	  opcion=toupper(opcion);
	 } while((opcion!='N')&&(opcion!='Y'));
     }while((opcion!='N')&&(opcion=='Y'));
    
}


void leer_datos()
  {
      struct alumno *auxalumn2;
      int j,ppp,lon,encon,dr[20];
      char not[10],valido;
      sw=1;  
      while(sw==1)
      {
      gotoxy(1,1);printf("POR FAVOR DIGITE EL CODIGO:");
      scanf("\n");gets(codigo);
	 st=1;
	 lon = strlen(codigo);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(codigo[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL CODIGO !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	 }

      if(st==2)
      {
      gotoxy(28,1);printf("                ");
      }
      else
      {
      auxalumn2=ptr;
      encon=2;
      while(auxalumn2!=NULL)
      {
      if(strcmp(auxalumn2->cod,codigo)==0)
       {
       encon=1;
       }
	auxalumn2=auxalumn2->sig;
      }
      if(encon==1)
       {
       gotoxy(10,10);printf("ERROR EL CODIGO YA EXISTE!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	    gotoxy(28,1);printf("              ");
       }
      else
       {
	sw=2;
       }
      }
      }
      sw=1;
      while(sw==1)
      {
      gotoxy(28,2);
      printf("                 ");
      gotoxy(1,2); printf("POR FAVOR DIGITE EL NOMBRE:");
      scanf("\n"); gets(nombre); 
	 st=1;
	 lon = strlen(nombre);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isalpha(nombre[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL NOMBRE..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	   }
	   if(st==2)
	   {
	   sw=1;
	   }
	   else
	   {
	   sw=2;
	   }
	   }
      sw=1;
      while(sw==1)
      {
      gotoxy(30,3);
      printf("                 ");
      gotoxy(1,3); printf("POR FAVOR DIGITE EL APELLIDO:");
      scanf("\n"); gets(apellido); 
	 st=1;
	 lon = strlen(apellido);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isalpha(apellido[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL APELLIDO..!");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	   }
	   if(st==2)
	   {
	   sw=1;
	   }
	   else
	   {
	   sw=2;
	   }
	   }

      sw=1;
      while(sw==1)
      {
      gotoxy(1,4); printf("DIGA CUAL ES EL SEXO SI ES (f/m):");
      scanf("%c",&sexo); sexo=toupper(sexo);
      if((sexo!='F')&&(sexo!='M'))
      {
      gotoxy(10,10);printf("ERROR AL DIGITAR EL SEXO..!");
	 delay(700);
	 gotoxy(10,10);
	 clreol();
      gotoxy(33,4);
      printf("                ");
      }
      else
      {
      sw=2;
      }
      }
    do
     {
      valido='n';
      j=0;
      gotoxy(22,5);
      printf("             ");
      gotoxy(1,5);printf("ESCRIBA PRIMERA NOTA:");
      scanf("\n"); gets(not);
      lon = strlen(not);
      st=1;
      for(i=0;i<=lon-1; i++)
	{
	  if(st==1)
	  {
	  if(not[i]=='.')
	   {
	   i=i+1;
	   st=2;
	   }
	  }
	 if(!(isdigit(not[i])))
	  {
	    valido='m';
	    gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();

	    break;
	  }
	}
	la_nota[j]=atof(not);
	if((la_nota[j]<0)||(la_nota[j]>5))
      {
      valido='m';
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }

     }while(valido=='m');
    do
     {
      valido='n';
      j=1;
      gotoxy(22,6);
      printf("             ");
      gotoxy(1,6);printf("ESCRIBA SEGUNDA NOTA:");
      scanf("\n"); gets(not);
      lon = strlen(not);
      st=1;
      for(i=0;i<=lon-1; i++)
	{
	  if(st==1)
	  {
	  if(not[i]=='.')
	   {
	   i=i+1;
	   st=2;
	   }
	  }
	 if(!(isdigit(not[i])))
	  {
	    valido='m';
	    gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();

	    break;
	  }
	}
	la_nota[j]=atof(not);
	if((la_nota[j]<0)||(la_nota[j]>5))
      {
      valido='m';
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }

     }while(valido=='m');
     do
     {
      valido='n';
      j=2;
      gotoxy(22,7);
      printf("             ");
      gotoxy(1,7);printf("ESCRIBA TERCERA NOTA:");
      scanf("\n"); gets(not);
      lon = strlen(not);
      st=1;
      for(i=0;i<=lon-1; i++)
	{
	  if(st==1)
	  {
	  if(not[i]=='.')
	   {
	   i=i+1;
	   st=2;
	   }
	  }
	 if(!(isdigit(not[i])))
	  {
	    valido='m';
	    gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();

	    break;
	  }
	}
	la_nota[j]=atof(not);
	if((la_nota[j]<0)||(la_nota[j]>5))
      {
      valido='m';
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }

     }while(valido=='m');

     do
     {
      valido='n';
      j=3;
      gotoxy(21,8);
      printf("             ");
      gotoxy(1,8);printf("ESCRIBA CUARTA NOTA:");
      scanf("\n"); gets(not);
      lon = strlen(not);
      st=1;
      for(i=0;i<=lon-1; i++)
	{
	  if(st==1)
	  {
	  if(not[i]=='.')
	   {
	   i=i+1;
	   st=2;
	   }
	  }
	 if(!(isdigit(not[i])))
	  {
	    valido='m';
	    gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();

	    break;
	  }
	}
	la_nota[j]=atof(not);
	if((la_nota[j]<0)||(la_nota[j]>5))
      {
      valido='m';
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }

     }while(valido=='m');


  }


void mostrar()
  {
    struct alumno *auxalum2;
    struct notas *auxnota2;
    auxalum2=ptr; sw=1;
    window(3,3,78,22);
    piso_color(BLACK,WHITE);
    clrscr();
    if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  }
  else
  {
    printf("COD       NOMB         APELL        SEX    NOT1  NOT2  NOT3   NOT4  DEF\n");
    i=2;
    textcolor(WHITE);
    if(auxalum2==NULL)
    {
    sw=2;
    }
    while(auxalum2!=NULL)
     {
      gotoxy(1,i);
      printf("%s",auxalum2->cod);
      gotoxy(11,i);
      printf("%s",auxalum2->nom);
      gotoxy(24,i);
      printf("%s",auxalum2->apel);
      gotoxy(38,i);
      printf("%c",auxalum2->sex);
      auxnota2=auxalum2->ady;
      c=45;
      while(auxnota2!=NULL)
       {
       gotoxy(c,i);
       printf("%.2f",auxnota2->nota);
       c=c+6;
       auxnota2=auxnota2->sig;
       }
      auxalum2=auxalum2->sig;
      i++;
      }
      if(sw==2)
      {
      clrscr();
      printf("NO EXISTE INFORMACION DE ALUMNOS");
      }
      }
    getch();
  }


void consulta_codigo()
 {
    struct alumno *auxalum2;
    struct notas *auxnota2;
    int lon,encon; 
    do
     {
      encon=1;
      auxalum2=ptr;
      window(3,3,78,22);
      piso_color(BLACK,WHITE);
      clrscr();
      if(ptr==NULL)
       {
	 clrscr();
	 printf("NO EXISTE INFORMACION EN LA LISTA..!");
	 getch();
       }
     else
      {
     while(encon==1)
      {
      st=1;
      gotoxy(1,1);
      printf("DIGITE EL CODIGO QUE DESEA CONSULTAR:");
      scanf("\n"); gets(codigo);
       lon = strlen(codigo);
     for( i=0;i<=lon-1; i++)
	{ if(!(isdigit(codigo[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL CODIGO !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	 }
	if(st==1)
	{
	encon=2;
	}
	else
	{
	gotoxy(38,1);printf("                  ");
	}
	}
      sw=1;  i=2;
      while(auxalum2!=NULL)
       {
	if(strcmp(codigo,auxalum2->cod)==0)
	 { 
	  sw=2;
	  clrscr();
	  printf("COD       NOMB         APELL        SEX    NOT1   NOT2   NOT3   NOT4   DEF\n");
	  gotoxy(1,i);
	  printf("%s",auxalum2->cod);
	  gotoxy(11,i);
	  printf("%s",auxalum2->nom);
	  gotoxy(24,i);
	  printf("%s",auxalum2->apel);
	  gotoxy(38,i);
	  printf("%c",auxalum2->sex);
	  c=46;
	  auxnota2=auxalum2->ady;
	  while(auxnota2!=NULL)
	   {
	    gotoxy(c,i);
	    printf("%.2f",auxnota2->nota);
	    auxnota2=auxnota2->sig;
	    c=c+6;
	    }
	 }
	 auxalum2=auxalum2->sig;
	  }
     if(sw==1)
      {
       clrscr();
       printf("VERIFIQUE BIEN SU CODIGO QUE NO EXISTE EN LISTA\n");
       getch();
      }
      else
      {
      getch();
      }
      }
     do
      {
       clrscr();
       printf("DESEA CONTINUAR, DIGITE (y/n):");
       opcion=toupper(getch());
      }while((opcion!='Y')&&(opcion!='N'));
   }while((opcion!='N')&&(opcion=='Y'));
  }


void modificar()
  {
   struct notas *auxnotas,*auxnota1,*auxnota2;
   struct alumno *auxalum2;
   int j,lon,suma,encon,enc,con;
   float fl,auxnot,tt,prom;
   int cc,ppp;
   char not[5],au,op1,op2,op3,auxi[40];
   do
    {
      encon=1;
      auxalum2=ptr;
      window(3,3,78,22);
      piso_color(BLACK,WHITE);
      clrscr();
      if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  getch();
  }
  else
  {
      while(encon==1)
      {
      st=1;
      gotoxy(1,1);
      printf("DIGITE EL CODIGO QUE DESEA MODIFICAR:");
      scanf("\n"); gets(codigo);
       lon = strlen(codigo);
     for( i=0;i<=lon-1; i++)
	{ if(!(isdigit(codigo[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL CODIGO !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	 }
	if(st==1)
	{
	encon=2;
	}
	else
	{
	gotoxy(38,1);printf("                  ");
	}
	}
      sw=1; st=1; 
      while(auxalum2!=NULL)
       {

	if(strcmp(codigo,auxalum2->cod)==0)
	 {
	 sw=2;
	 do
	 {
	 clrscr();
  gotoxy(2,3);printf("1: DATOS DEL ESTUDIANTE");
  gotoxy(28,3);printf("2: NOTAS DEL ESTUDIANTE");
  gotoxy(55,3);printf("3: SALIR");
  gotoxy(2,4);printf("ESCOJA OPCION:");scanf("%c",&op1);
	   if(op1=='1')
	   {
   do
   {
   clrscr();
  gotoxy(2,3); printf("1: NOMBRE");
  gotoxy(15,3);printf("2: APELLIDOS");
  gotoxy(30,3);printf("3: SEXO");
  gotoxy(2,4);printf("ESCOJA OPCION:");scanf("%c",&op2);
	   if(op2=='1')
	   {
	   gotoxy(2,5);
	   printf("DIGITE NOMBRE :");scanf("\n"); gets(auxi);
	   strcpy(auxalum2->nom,auxi);
	   }
	   if(op2=='2')
	   {
	   gotoxy(2,5);
	   printf("DIGITE APELLIDOS:");scanf("\n");gets(auxi);
	   strcpy(auxalum2->apel,auxi);
	   }
	   if(op2=='3')
	   {
	   gotoxy(2,5);
	   printf("DIGITE SEXO (f/m):");scanf("\n");scanf("%c",&au);
	   au=toupper(au);
	   while((au!='F')&&(au!='M'))
	   {
	   gotoxy(20,5);
	   printf("         ");
	   printf("DIGITE SEXO (f/m):");scanf("\n");scanf("%c",&au);
	   au=toupper(au);
	   }
	   auxalum2->sex=au;  
	   }
 }while((op2!='1')&&(op2!='2')&&(op2!='3'));
    }
    if (op1=='2')
      {
	 ppp=1;
      while(ppp==1)
      {
      clrscr();
      gotoxy(32,1);
      printf("         ");
      gotoxy(1,1);
      printf("DIGITE NOTA A MODIFICAR [1..4]:");
      scanf("\n");gets(not);
	 st=1;
	 lon = strlen(not);
     for( i=0;i<=lon-1; i++)
	{ 
	if(!(isdigit(not[i])))
	   { gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     break;

	      }
	      }
      if(st==1)
      {
      cc=atoi(not);
      if((cc<1)||(cc>4))
      {
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }
      else
      {   
      i=2;
      clrscr();
	  printf("COD       NOMB         APELL        SEX      NOT1  NOT2  NOT3  NOT4  DEF\n");
	  gotoxy(1,i);
	  printf("%s",auxalum2->cod);
	  gotoxy(11,i);
	  printf("%s",auxalum2->nom);
	  gotoxy(24,i);
	  printf("%s",auxalum2->apel);
	  gotoxy(38,i);
	  printf("%c",auxalum2->sex);
	  c=46;
	  auxnota2=auxalum2->ady;
	  while(auxnota2!=NULL)
	   {
	    gotoxy(c,i);
	    printf("%.2f",auxnota2->nota);
	    auxnota2=auxnota2->sig;
	    c=c+6;
	    }
      if(cc==1)
      {
      ppp=1;
      while(ppp==1)
      {
      j=0;
      gotoxy(45,2);
      printf("      ");
      gotoxy(46,2);
      scanf("\n");gets(not);
      la_nota[j]=atof(not);
      if(la_nota[j]==0)
      {
      ppp=1;
      gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
      }
      else
      {
      if((la_nota[j]<0)||(la_nota[j]>5))
      {
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }
      else
      {
      con=1;
      auxnotas=auxalum2->ady;
      while(con<cc)
      {
      auxnotas=auxnotas->sig;
      con++;
      }
      auxnotas->nota=la_nota[j];
      ppp=2;
      }
      }
      }
      }
      if(cc==2)
      {
      ppp=1;
      while(ppp==1)
      {
      j=1;
      gotoxy(50,2);
      printf("      ");
      gotoxy(51,2);
      scanf("\n");gets(not);
      la_nota[j]=atof(not);
      if(la_nota[j]==0)
      {
      ppp=1;
      gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
      }
      else
      {
      if((la_nota[j]<0)||(la_nota[j]>5))
      {
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }
      else
      {
      con=1;
      auxnotas=auxalum2->ady;
      while(con<cc)
      {
      auxnotas=auxnotas->sig;
      con++;
      }
      auxnotas->nota=la_nota[j];
      ppp=2;
      }
      }
      }

      }
      if(cc==3)
      {
      ppp=1;
      while(ppp==1)
      {
      j=2;
      gotoxy(56,2);
      printf("      ");
      gotoxy(57,2);
      scanf("\n");gets(not);
      la_nota[j]=atof(not);
      if(la_nota[j]==0)
      {
      ppp=1;
      gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
      }
      else
      {
      if((la_nota[j]<0)||(la_nota[j]>5))
      {
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }
      else
      {
      con=1;
      auxnotas=auxalum2->ady;
      while(con<cc)
      {
      auxnotas=auxnotas->sig;
      con++;
      }
      auxnotas->nota=la_nota[j];
      ppp=2;
      }
      }
      }

      }
      if(cc==4)
      {
      ppp=1;
      while(ppp==1)
      {
      j=3;
      gotoxy(63,2);
      printf("      ");
      gotoxy(64,2);
      scanf("\n");gets(not);
      la_nota[j]=atof(not);
      if(la_nota[j]==0)
      {
      ppp=1;
      gotoxy(10,10);printf("NOTA INEXISTENTE... !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
      }
      else
      {
      if((la_nota[j]<0)||(la_nota[j]>5))
      {
      gotoxy(10,10);printf("NOTA FUERA DE RANGO... !");
      delay(1500);
      gotoxy(10,10);
      clreol();
      }
      else
      {
      con=1;
      auxnotas=auxalum2->ady;
      while(con<cc)
      {
      auxnotas=auxnotas->sig;
      con++;
      }
      auxnotas->nota=la_nota[j];
      ppp=2;
      }
      }
      }
      }
      auxnotas=auxalum2->ady;
      con=0; prom=0;
      while(con<4)
      {
      prom=prom+auxnotas->nota;
      auxnotas=auxnotas->sig;
      con++;
      }
      prom=prom/4;
      auxnotas=auxalum2->ady;
      while(auxnotas->sig!=NULL)
      {
      auxnotas=auxnotas->sig;
      }
      auxnotas->nota=prom;
      }
      }
      }
      }
      }while((op1!='1')&&(op1!='2')&&(op1!='3'));
      }
      auxalum2=auxalum2->sig; 
      }
      if(sw==1)
	{
	clrscr();
	printf("NO EXISTE ESTE CODIGO EN LISTA");
	getch();
       }
       }
     do
      {
       clrscr();
       printf("DESEA CONTINUAR, DIGITE (y/n):");
       opcion=toupper(getch());
      } while((opcion!='Y')&&(opcion!='N'));
   } while((opcion!='N')&&(opcion=='Y'));
 }


void ordenar()
  { 
    float aux_de_nota[5];
    struct alumno *auxalum2,*auxalum3;
    struct notas *auxnotas,*auxnota2;
    int i,j;
    for(i=n-1;i>=1;i--)
     {
      auxalum2=ptr;
      auxalum3=auxalum2->sig;
      for(j=1;j<=i;j++)
       {
	auxalum2=auxalum2;
	auxalum3=auxalum3;
	if(strcmp(auxalum2->cod,auxalum3->cod)>0)
	 {
	  strcpy(codigo,auxalum2->cod);
	  strcpy(nombre,auxalum2->nom);
	  strcpy(apellido,auxalum2->apel);
	  sexo=auxalum2->sex;
	  auxnotas=auxalum2->ady;
	  while(auxnotas!=NULL)
	   {
	    for(i=1; i<=5; i++)
	     {
	      aux_de_nota[i]=auxnotas->nota;
	     }
	    auxnotas=auxnotas->sig;
	   }
	  strcpy(auxalum2->cod,auxalum3->cod);
	  strcpy(auxalum2->nom,auxalum3->nom);
	  strcpy(auxalum2->apel,auxalum3->apel);
	  auxalum2->sex=auxalum3->sex;
	  auxnota2=auxalum3->ady;
	  auxnotas=auxalum2->ady;
	  while((auxnota2->sig!=NULL)&&(auxnotas->sig!=NULL))
	   {
	    auxnotas->nota=auxnota2->nota;
	    auxnotas=auxnotas->sig;
	    auxnota2=auxnota2->sig;
	   }
	  strcpy(auxalum3->cod,codigo);
	  strcpy(auxalum3->nom,nombre);
	  strcpy(auxalum3->apel,apellido);
	  auxalum3->sex=sexo;
	  auxnota2=auxalum3->ady;
	  i=1;
	  while(auxnota2->sig!=NULL)
	   {
	    auxnota2->nota=aux_de_nota[i];
	    auxnota2=auxnota2->sig;
	   }
	}
	auxalum2=auxalum2->sig;
	auxalum3=auxalum2->sig;
      }
   }
}

void mujeres_ganaron()
  {
    int j;
    struct alumno *auxalum2;
    struct notas *auxnotas,*auxnota2,*auxn1;
    auxalum2=ptr;  sw=1;
    window(3,3,78,22);
    piso_color(BLACK,WHITE);
    clrscr();
    textcolor(WHITE);
    c=2;
    if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  }
  else
  {
    cprintf("COD    NOMBRE    APELLIDO    SEXO   NOT 1   NOT 2   NOT 3   NOT 4   DEF\n");
    while(auxalum2!=NULL)
     {
      auxnotas=auxalum2->ady;
      while(auxnotas->sig!=NULL)
       {
	auxn1=auxnotas;
	auxnotas=auxnotas->sig;
	}
	if((auxn1->nota>=3)&&(auxalum2->sex=='F'))
	 {
	  sw=2;
	  textcolor(WHITE);
	  gotoxy(1,c);
	  printf("%s",auxalum2->cod);
	  gotoxy(8,c);
	  printf("%s",auxalum2->nom);
	  gotoxy(18,c);
	  printf("%s",auxalum2->apel);
	  gotoxy(30,c);
	  printf("%c",auxalum2->sex);
	  j=37;
	  auxnota2=auxalum2->ady;
	  while(auxnota2!=NULL)
	   {
	    gotoxy(j,c);
	    printf("%.2f",auxnota2->nota);
	    auxnota2=auxnota2->sig;
	    j=j+7;
	   }
	  }
	  c++;
       
       auxalum2=auxalum2->sig;
      }
     if(sw==1)
      {
       clrscr();
       printf("NO HAY MUJERES QUE GANARON LA MATERIA");
      }
      }
    getch();
  }


void alumnos_perdieron()
 {
    struct alumno *auxalum2;
    struct notas *auxnotas,*auxnota2,*auxn1;
    int j;
    auxalum2=ptr;
    window(3,3,78,22);
    piso_color(BLACK,WHITE);
    clrscr();
    textcolor(WHITE);
    c=2; sw=1;
    if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  }
  else
  {
    cprintf("COD    NOMBRE    APELLIDO    SEXO   NOT 1   NOT 2   NOT 3   NOT 4   DEF\n");
    while(auxalum2!=NULL)
    {
    auxnotas=auxalum2->ady;
    while(auxnotas!=NULL)
    {
     auxn1=auxnotas;
     auxnotas=auxnotas->sig;
     }
       if(auxn1->nota<3)
       {
	   sw=2;
	   textcolor(WHITE);
	   gotoxy(1,c);
	   printf("%s",auxalum2->cod);
	   gotoxy(8,c);
	   printf("%s",auxalum2->nom);
	   gotoxy(18,c);
	   printf("%s",auxalum2->apel);
	   gotoxy(30,c);
	   printf("%c",auxalum2->sex);
	   j=37;
	   auxnota2=auxalum2->ady;
	   while(auxnota2!=NULL)
	   {
	   gotoxy(j,c);
	   printf("%.2f",auxnota2->nota);
	   auxnota2=auxnota2->sig;
	   j=j+7;
	   }
	   c++;
	 } 
		 
       auxalum2=auxalum2->sig;
    }
    if(sw==1)
    {
       clrscr();
       printf("NO HAY ALUMNOS QUE PERDIERON LA MATERIA");
    }
    }
    getch();
}

void hombres_ganaron()
  {
    int j;
    struct alumno *auxalum2;
    struct notas *auxnotas,*auxnota2,*auxn1;
    auxalum2=ptr;
    window(3,3,78,22);
    piso_color(BLACK,WHITE);
    clrscr();
    textcolor(WHITE);
    c=2;
    if(ptr==NULL)
  {
  clrscr();
  printf("NO EXISTE INFORMACION EN LA LISTA..!");
  }
  else
  {
    cprintf("COD    NOMBRE    APELLIDO    SEXO   NOT 1   NOT 2   NOT 3   NOT 4   DEF\n");
    while(auxalum2!=NULL)
     {
      auxnotas=auxalum2->ady;
      while(auxnotas!=NULL)
       {
	auxn1=auxnotas;
	auxnotas=auxnotas->sig;
	}
	if((auxn1->nota>3)&&(auxalum2->sex=='M'))
	 {
	  sw=2;
	  textcolor(WHITE);
	  gotoxy(1,c);
	  printf("%s",auxalum2->cod);
	  gotoxy(8,c);
	  printf("%s",auxalum2->nom);
	  gotoxy(18,c);
	  printf("%s",auxalum2->apel);
	  gotoxy(30,c);
	  printf("%c",auxalum2->sex);
	  j=36;
	  auxnota2=auxalum2->ady;
	  while(auxnota2!=NULL)
	   {
	    gotoxy(j,c);
	    printf("%.2f",auxnota2->nota);
	    auxnota2=auxnota2->sig;
	    j=j+6;
	   }
	   i++;
	  }
	  
       
       auxalum2=auxalum2->sig;
      }
     if(sw==1)
      {
       clrscr();
       printf("NO HAY HOMBRES QUE GANARON LA MATERIA");
      }
      }
    getch();
  }


void borrar()
{
   struct alumno *auxalum2,*auxp,*auxalum3;
   struct notas *auxnotas,*auxnota2;
   int lon,encon,j;
   st=1;
   do
    {
      window(3,3,78,22);
      piso_color(BLACK,WHITE);
      clrscr();
      if(ptr==NULL)
      {
      clrscr();
      printf("NO EXISTE INFORMACION EN LA LISTA..!");
      getch();
      }
      else
      {
      encon=1;
      while(encon==1)
      {
      gotoxy(1,1);
      printf("DIGA CUAL ES EL CODIGO QUE DESEA BORRAR:");
      scanf("\n"); gets(codigo);
      encon=1;
       lon = strlen(codigo);
     for( i=0;i<=lon-1; i++)
	{ if(!(isdigit(codigo[i])))
	   { gotoxy(10,10);printf("ERROR AL DIGITAR EL CODIGO !");
	    delay(1500);
	    gotoxy(10,10);
	    clreol();
	     encon=3;
	     break;

	    }
	 }
	if(encon==3)
	{
	encon=1;
	gotoxy(41,1);printf("                  ");
	}
	else
	{
	encon=2;
	}
	}
 auxalum2=ptr;
      auxalum3=ptr->sig;
       if( (strcmp(ptr->cod,codigo)==0))
	 {
	  st=2;
	  ptr=auxalum3;                                      
	  auxnota2=auxalum2->ady;
	  auxnotas=auxalum2->ady;
	  while(auxnota2!=NULL)
	   {
	    auxnota2=auxnota2->sig;
	    free(auxnotas);
	    auxnotas=auxnota2;
	   }
	  free(auxalum2);
	  clrscr();
	  printf("ESTUDIANTE ELIMINADO DE LA LISTA...\n");
	  getch();
	 }
	else
	  {
	  while(auxalum3!=NULL)
	  {
	  if(strcmp(codigo,auxalum3->cod)==0)
	      {
	      st=2;
	     auxp=ptr;
	     while(auxp!=NULL)
	      {
	       if(auxp->sig==auxalum3)
		 {
		   if(auxp->sig==auxalumn)
		    {
		    auxalumn=auxp;
		    }
		   auxp->sig=auxalum3->sig;
		   auxnotas=auxalum3->ady;
		   auxnota2=auxalum3->ady;
		   while(auxnota2!=NULL)
		    {
		    auxnota2=auxnota2->sig;
		    free(auxnotas);
		    auxnotas=auxnota2;
		    }
		   free(auxalum3);
		   clrscr();
		   printf("YA EL ESTUDIANTE FUE ELIMINADO...\n");
		 }
		auxp=auxp->sig;
	      }
	     }
	     auxalum3=auxalum3->sig;
	     }
	     }
	     if(st==1)
	     {
	     clrscr();
	     printf("EL CODIGO NO EXISTE EN LISTA");
	     getch();
	     }
	     }
	     
      do
      {
	  clrscr();
	  printf("DESEA CONTINUAR, DIGITE (y/n):");
	  opcion=getche();
	  opcion=toupper(opcion);
      }
      while((opcion!='Y')&&(opcion!='N'));
   }
   while((opcion!='N')&&(opcion=='Y'));
}

void main()
{
char d;
clave();
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
			       ref1(8,WHITE,BLACK,"Estudiante");
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
			       ref2(8,3,BLACK,"Estudiante");
			       break;
			     }
			}
		     break;
		     }
	     case 75:{
			switch(wherex())
			{
		      case 8:{
			       ref1(8,WHITE,BLACK,"Estudiante");
			       ref2(63,3,BLACK,"Salir");
			       break;
			     }
		     case 26:{
			       ref1(26,WHITE,BLACK,"Listados");
			       ref2(8,3,BLACK,"Estudiante");
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





		