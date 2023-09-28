#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include "fcntl.h"
#include "io.h"
#include "iostream.h"

/**********************************************************************/

#define CPR(x) cprintf (" %s",x)
#define cpr1(x){ piscol(15,0); window(1,25,80,25);clrscr(); gotoxy(1,1); CPR(x); }
#define si 218 //201
#define sd 191 //187  
#define ii 192 //200 
#define id 217 //188
#define lv 179 //186
#define lh 196 //205

/**********************************************************************/

char *help1[]={ "Ingresa un estudiante al sistema                         [Esc] desactivar menu",
		"Introduce las notas del estudiante                       [Esc] desactivar menu"
		};

char *help2[]={ "Visualiza los estudiantes por codigo                     [Esc] desactivar menu",
		"Visualiza todos los estudiantes                          [Esc] desactivar menu",
		"Visualiza los alumnos que ganaron                        [Esc] desactivar menu",
		"Visualiza los alumnos que perdieron                      [Esc] desactivar menu",
		"Visualiza las mujeres que ganaron                        [Esc] desactivar menu",
		"Visualiza los hombres que ganaron                        [Esc] desactivar menu",
		"Visualiza los alumnos con promedio mayor a 3.5           [Esc] desactivar menu"
	      };

char *help3[]={ "Modifica los datos personales del estudiante             [Esc] desactivar menu",
		"Modifica las notas del estudiante                        [Esc] desactivar menu"
		 };                                                        

char *help4[]={ "Elimina un estudiante de el sistema                      [Esc] desactivar menu"
	      };                                                                        
char *help5[]={ "terminar el programa                                     [Esc] desactivar menu"
	      };
char *help6[]={ "press [alt] y la [tecla] para activar menu      [F1] Autores      [Esc]  salir"
	      };
char *help7[]={ "Pulse << ENTER >> para mas informacion de Argemiro      [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Ismael        [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Nicolas       [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Edwin         [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Roberto       [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Jose          [Esc] desactivar menu",
		"Pulse << ENTER >> para mas informacion de Yolkin        [Esc] desactivar menu"     
	      };


char *ArchivoUno [] =
      {
	"Adicionar estudiante ",
	"Adicionar notas      "
      };

char *ArchivoDos [] =
     {
	"Listado por codigo    ",
	"Listado general       ",
	"Alumnos que ganaron   ",
	"Alumnos que perdieron ",
	"Mujeres que ganaron   ",
	"Hombres que ganaron   ",
	"Al. promedio > 3.5    "
     };

char *ArchivoTres  [] =
       {
	 "Datos personales ",
	 "Notas            "
       };


char *ArchivoCuatro   [] =
       {
	 "Estudiante       "
       };

char *termina [] =
      {
	" Terminar ",
	" ESC      "
       };

char *ArchivoSeis [] =
     {
	"Argemiro J. Arrollo C. ",
	"Ismael E. Badillo P.   ",
	"Nicolas A. Cordoba Q.  ",
	"Edwin J. diaz B.       ",
	"Roberto E. quiroz M.   ",
	"Jose E. Sauri S.       ",
	"Yolkin de J. Vega M.   "
     };

char w[4096];
char z[4096];

/**********************************************************************/
void esc(char c,int veces);
void ir_a(int i,int j);
void reset();

class edwin
{
struct nodo1
{ float not;
  struct nodo1 *sig_not;
};
struct nodo

{  char cod[9],nom[15],ape[15],sex;
   struct nodo *enlace;
   struct nodo1 *enla_not;
};

public:
nodo *nn,*ptr,*p;
nodo1 *nn1,*p1;
char cod[9],nom[15],ape[15],sex,op;
int sw,i;
int da,db,dc,dd,km,h;
float not[6];
edwin(struct nodo *f);
void intro();
void vis();
int clave();
void int_not();
void vis_gen();
void vis_muj_gan();
void vis_hom_gan();
void vis_al_gan();
void vis_al_per();
void vis_al_3_5();
void mod_not();
void eliminar();
void clav();
void mod_nom();
void lee_cod(int x,int y,char *cod);
void lee_nom(int x,int y,char *nom);
void ordenar();
void val_cod();
void mensaje(int x,int y,int opK,char *p);
void repetir(int i,char *p);
char lee_sex(int x,int y,char F,char M);
float lee_not(int x1,int y1 );
void escribir(int x1, int n, int p, int op);
void cuad_pres(int x1, int y1, int x2, int y2, int op);
void cuad(int x1,int y1,int x2,int y2);
void PoP_PoP ();
void piscol(int,int);
void marcoDos(int,int,int,int);
void udes();
void ref1 (int  ,int ,int ,char  *);
void marco(int,int,int,int);
EscribaMenuUno (int n,char *a[],struct text_info *P,int *Tecla);
EscribaMenuDos (int n,char *a[],struct text_info *P,int *Tecla);
EscribaMenuTres (int n,char *a[],struct text_info *P,int *Tecla);
EscribaMenuCuatro (int n,char *a[],struct text_info *P,int *Tecla);
EscribaMenuCinco (int n,char *a[],struct text_info *P,int *Tecla);
EscribaMenuSeis (int n,char *a[],struct text_info *P,int *Tecla);
};

/**********************************************************************/

void edwin::cuad(int x1,int y1,int x2,int y2)
{ int i; window(1,1,80,25);
  gotoxy(x1, y1); printf("%c",201); //…
  gotoxy(x2, y1); printf("%c",187); //ª
  gotoxy(x1, y2); printf("%c",200); //»
  gotoxy(x2, y2); printf("%c",188); //º
       for(i=(x1+1);i<=(x2-1);i++)
       { gotoxy(i, y1);printf("%c",205);//Õ
	 gotoxy(i, y2);printf("%c",205);}
    for(i=(y1+1);i<=(y2-1);i++)
     { gotoxy(x1, i);printf("%c",186); //∫
       gotoxy(x2, i);printf("%c",186);} 
 }

/**********************************************************************/

void edwin::cuad_pres(int x1, int y1, int x2, int y2, int op)
{int i;
 textbackground(3);textcolor(1);
 window(x1,y1,x2,y2);clrscr();
 cuad(x1,y1,x2,y2);
 for(i=x1;i<=x2;i++)
 { gotoxy(i,y1+2);
   if(i==x1)printf("Ã");else
   if(i==x2)printf("π");else
   printf("Õ");
 }
 for(i=y1;i<=y2;i++){
  if(i==y1)escribir(x1,203,i,op);else
  if(i==y2)escribir(x1,202,i,op);else
  if(i==y1+2)escribir(x1,206,i,op);else
  escribir(x1,186,i,op);}
 if(op==1){
 gotoxy(x1+3,y1+1);printf("CODIGO");
 gotoxy(x1+17,y1+1);printf("NOMBRE");
 gotoxy(x1+34,y1+1);printf("APELLIDO");
 gotoxy(x1+48,y1+1);printf("SEX");
 }
 if(op==2)
 {  gotoxy(x1+2,y1+1);printf("CODIGO");
    gotoxy(x1+14,y1+1);printf(" NOMBRE");
    gotoxy(x1+29,y1+1);printf(" APELLIDO");
    gotoxy(x1+43,y1+1);printf("SEX");
    gotoxy(x1+48,y1+1);printf(" P.1");
    gotoxy(x1+54,y1+1);printf(" P.2");
    gotoxy(x1+60,y1+1);printf(" P.3");
    gotoxy(x1+66,y1+1);printf(" P.4");
    gotoxy(x1+73,y1+1);printf("DEF");}
  }

/**********************************************************************/

void edwin::escribir(int x1, int n, int p, int op)
{ if(op==1){
  gotoxy(x1+11,p);printf("%c",n);
  gotoxy(x1+29,p);printf("%c",n);
  gotoxy(x1+46,p);printf("%c",n);
 }
 if(op==2)
 { gotoxy(x1+10,p);printf("%c",n);
   gotoxy(x1+26,p);printf("%c",n);
   gotoxy(x1+42,p);printf("%c",n);
   gotoxy(x1+47,p);printf("%c",n);
   gotoxy(x1+53,p);printf("%c",n);
   gotoxy(x1+59,p);printf("%c",n);
   gotoxy(x1+65,p);printf("%c",n);
   gotoxy(x1+71,p);printf("%c",n);
 }
}

/**********************************************************************/

void edwin::PoP_PoP ()
{ int u,sw;
	int c,d,x1,x2,y1,y2;
	struct text_info p;
	textmode(2);
	piscol(15,0);
	window(1,1,80,25);clrscr();
   for (u=2;u<25;u++)
   { gotoxy(1,u);
     textcolor(1);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
	piscol(15,0);
	window(1,1,80,1);clreol();
	window(1,1,80,25);
	piscol (15,0);
	gotoxy(4,1); CPR(" Adicionar");
	gotoxy (21,1); CPR(" Listados ");
	gotoxy (36,1); CPR(" Modificar ");
	gotoxy (52,1);  CPR(" Eliminar ");
	gotoxy (68,1);  CPR(" Terminar ");
	textcolor(4);
	gotoxy(4,1); cprintf("  A");
	gotoxy (21,1); cprintf("  L");
	gotoxy (36,1); cprintf("  M");
	gotoxy (52,1); cprintf("  E");
	gotoxy (68,1); cprintf("  T");

     do{
	sw=0;
	cpr1(help6[0]);
	do
	{ c=getch();
	 if(c==0)   c=getch();
	  if((c==0x1e)||(c==0x26)||(c==0x32)||(c==0x12)||(c==0x14)||(c==27)||(c==59)) sw=1;
	}while(sw==0);
	if(c!=27) 
	{ switch(c){ case 0x1e :EscribaMenuUno(3,ArchivoUno,&p,&c); break;
		     case 0x26 :EscribaMenuDos(8,ArchivoDos,&p,&c); break;
		     case 0x32 :EscribaMenuTres(3,ArchivoTres ,&p,&c); break;
/*  68	*/	     case 0x12 :EscribaMenuCuatro(2,ArchivoCuatro  ,&p,&c); break;
		     case 0x14 :EscribaMenuCinco(2,termina,&p,&c); break;
		     case 59 :EscribaMenuSeis(8,ArchivoSeis,&p,&c);break;
		   }
     do{
	if(c==75||c==77) 
	 {	switch (c) {
			case 77 :  	switch (p.winleft) {
					case 4:  puttext(3,1,29,5,w);
						 EscribaMenuDos(8,ArchivoDos,&p,&c);
						 break;
					case 21: puttext(20,1,48,10,w);
						 EscribaMenuTres(3,ArchivoTres ,&p,&c);
						 break;
					case 36: puttext(35,1,57,5,w);
						 EscribaMenuCuatro(2,ArchivoCuatro  ,&p,&c);
						 break;
					case 52: puttext(51,1,72,4,w);
						 EscribaMenuCinco(2,termina,&p,&c);
						 break;
					case 68: puttext(67,1,79,4,w);
						 EscribaMenuUno(3,ArchivoUno,&p,&c);
						 break;
				  }
				  break;
			case 75 :       switch (p.winleft) {
					case 4:  puttext(3,1,29,5,w);
						 EscribaMenuCinco(2,termina,&p,&c);
						 break;
					case 21: puttext(20,1,48,10,w);
						 EscribaMenuUno(3,ArchivoUno,&p,&c);
						 break;
					case 36: puttext(35,1,57,5,w);
						 EscribaMenuDos(8,ArchivoDos,&p,&c);
						 break;
					case 52: puttext(51,1,72,4,w);
						 EscribaMenuTres(3,ArchivoTres ,&p,&c);
						 break;
					case 68: puttext(67,1,79,4,w);
						 EscribaMenuCuatro(2,ArchivoCuatro,&p,&c);
						 break;
				  }
		}
		if (c==27) { c=getch(); break; }
	   }
   else { c=getch(); break; }
  }while(c!=27);
}
}while(c!=27);
piscol(0,15);
gettext(21,11,58,14,w);
window(21,11,58,14);clrscr();
cuad(21,11,58,14);
gotoxy(23,12); printf("GRACIAS POR USAR NUESTROS PRODUCTO");
gotoxy(23,13); printf("      ESPERE UNOS SEGUNDOS");
delay(2500);
puttext(21,11,58,14,w);
gotoxy(80,25);
delay(1000);
exit(0);
}

/**********************************************************************/

void edwin::ref1 (int n,int piso,int color,char *s) {
	window (1,1,80,25);
	gotoxy (n,1);
	piscol (piso,color);
	CPR(s);
	gotoxy (n,1);
	textcolor(4);
	cprintf("  %c",s[1]);
}       

/**********************************************************************/

void edwin::piscol (int piso,int color)
      {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
      }

/**********************************************************************/

 edwin::EscribaMenuUno (int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
      gettext(3,1,29,5,w);
      ref1(4,10,0," Adicionar ");
      piscol (15,0);
      window(3,2,29,5);clrscr();
      marco (4,3,28,4);
      piscol (15,0);
	for (i=1; i < n-1; i++)
	  {  gotoxy (2,i+1);
	     CPR(a[i]);
	  }
	piscol (10,0);
	gotoxy (2,1); CPR (a [0]);
	cpr1(help1[0]);
	window(4,3,28,5);
	gotoxy (2,1); *Tecla = getch();
	while (*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (2,1);
			 else
			    gotoxy (2,wherey() + 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help1[h-1]);
			 window(4,3,28,4);
			 gotoxy (2,h);
			 break;
		case 72: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (2,n-1);
			 else
			    gotoxy (2,wherey() - 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help1[h-1]);
			 window(4,3,28,4);
			 gotoxy (2,h);
			 break;
		case 77: break;
		case 75: break;

	     }
		if (*Tecla == 77 || *Tecla == 75)
		{  break; }
	 } 
	 if(*Tecla==27) { puttext(3,1,29,5,w); cpr1(help6[0]); }
	 if(*Tecla=='\r')
	 { switch(wherey())
	   { case 1: {
		       intro();
		       PoP_PoP();
		     }break;
	     case 2: {
		       int_not();
		       PoP_PoP();
		     }break;
	     case 3: {
		     exit(1);
		     }break;
	       }
	  }
	gettextinfo(P);
	return(0);
}

/**********************************************************************/

 edwin::EscribaMenuDos (int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
      gettext(20,1,48,10,w);
      ref1(21,10,0," Listados ");
      piscol (15,0);
      window(20,2,48,10);clrscr();
      marco (21,3,47,9);
      piscol (15,0);
	for (i=1; i < n-1; i++)
	  {  gotoxy (2,i+1);
	     CPR(a[i]);
	  }
	piscol (10,0);
	gotoxy (2,1); CPR (a [0]);
	cpr1(help2[0]);
	window(21,3,47,9);
	gotoxy (2,1); *Tecla = getch();
	while (*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (2,1);
			 else
			    gotoxy (2,wherey() + 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help2[h-1]);
			 window(21,3,47,9);
			 gotoxy (2,h);
			 break;
		case 72: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (2,n-1);
			 else
			    gotoxy (2,wherey() - 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help2[h-1]);
			 window(21,3,47,9);
			 gotoxy (2,h);
			 break;
		case 77: break;
		case 75: break;

	     }
		if (*Tecla == 77 || *Tecla == 75)
		{  break; }
	 }
	 if(*Tecla==27){ puttext(20,1,48,10,w); cpr1(help6[0]); }
	 if(*Tecla=='\r')
	 {switch(wherey())
	   {
	     case 1: {
		      vis();
		      PoP_PoP();
		     }break;
	     case 2: {
		      vis_gen();
		      PoP_PoP();
		     }break;
	    case 3:  {
		      vis_al_gan();
		      PoP_PoP();
		     }break;
	    case 4:  {
		      vis_al_per();
		      PoP_PoP();
		     }break;
	     case 5: {
		      vis_muj_gan();
		      PoP_PoP();
		     }break;
	     case 6: {
		      vis_hom_gan();
		      PoP_PoP();
		     }break;
	     case 7: {
		      vis_al_3_5();
		      PoP_PoP();
		     }break;

	    case 8: break;

	       }
	  }
	gettextinfo(P);
	return(0);
}

/**********************************************************************/

 edwin::EscribaMenuTres (int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
      gettext(35,1,57,5,w);
      ref1(36,10,0," Modificar ");
      piscol (15,0);
      window(35,2,57,5);clrscr();
      marco (36,3,56,4);
      piscol (15,0);
	for (i=1; i < n-1; i++)
	  {  gotoxy (2,i+1);
	     CPR(a[i]);
	  }
	piscol (10,0);
	gotoxy (2,1); CPR (a [0]);
	cpr1(help3[0]);
	window(36,3,56,4);
	gotoxy (2,1); *Tecla = getch();
	while (*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (2,1);
			 else
			    gotoxy (2,wherey() + 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help3[h-1]);
			 window(36,3,56,4);
			 gotoxy (2,h);
			 break;
		case 72: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (2,n-1);
			 else
			    gotoxy (2,wherey() - 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help3[h-1]);
			 window(36,3,56,4);
			 gotoxy (2,h);
			 break;
		case 77: break;
		case 75: break;

	     }
		if (*Tecla == 77 || *Tecla == 75)
		{  break; }
	 }
	 if(*Tecla==27){ puttext(35,1,57,5,w); cpr1(help6[0]); }
	 if(*Tecla=='\r')
	 {switch(wherey())
	   {
	     case 1: {
		      mod_nom();
		      PoP_PoP();
		     }break;
	     case 2: {
		      mod_not();
		      PoP_PoP();
		     } break;
	     case 3: {
		     exit(1);
		     }break;
	       }
	  }
	gettextinfo(P);
	return(0);
}

/**********************************************************************/

 edwin::EscribaMenuCuatro (int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
      gettext(51,1,72,4,w);
      ref1(52,10,0," Eliminar ");
      piscol (15,0);
      window(51,2,72,4);clrscr();
      marco (52,3,71,3);
      piscol (15,0);
	for (i=1; i < n-1; i++)
	  {  gotoxy (2,i+1);
	     CPR(a[i]);
	  }
	piscol (10,0);
	gotoxy (2,1); CPR (a [0]);
	cpr1(help4[0]);
	window(52,3,71,3);
	gotoxy (2,1); *Tecla = getch();
	while (*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (2,1);
			 else
			    gotoxy (2,wherey() + 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help4[h-1]);
			 window(52,3,71,3);
			 gotoxy (2,h);
			 break;
		case 72: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (2,n-1);
			 else
			    gotoxy (2,wherey() - 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help4[h-1]);
			 window(52,3,71,3);
			 gotoxy (2,h);
			 break;
		case 77: break;
		case 75: break;

	     }
		if (*Tecla == 77 || *Tecla == 75)
		{  break; }
	 }
	 if(*Tecla==27){ puttext(51,1,72,4,w); cpr1(help6[0]); }
	 if(*Tecla=='\r')
	 {switch(wherey())
	   {
	     case 1: {
		       eliminar();
		       PoP_PoP();
		     }break;
	     case 2: {
		     exit(1);
		     }break;
	       }
	  }
	gettextinfo(P);
	return(0);
}

/**********************************************************************/

 edwin::EscribaMenuCinco (int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
      gettext(67,1,79,4,w);
      ref1(68,10,0," Terminar ");
      piscol (15,0);
      window(67,2,79,4);clrscr();
      marco(68,3,78,3);
      piscol (15,0);
	for (i=1; i <n-1; i++)
	  {  gotoxy (1,i+1);
	     cprintf("%s",a[i]);
	  }
	piscol (10,0);
	gotoxy (1,1); cprintf("%s",a[0]);
	cpr1(help5[0]);
	window(68,3,78,3);
	gotoxy (1,1); *Tecla = getch();
	while(*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 cprintf("%s",a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (1,1);
			 else
			    gotoxy (1,wherey() + 1);
			 cprintf("%s",a [wherey() - 1]);
			 h=wherey();
			 cpr1(help5[h-1]);
			 window(68,3,78,3);
			 gotoxy (1,h);
			 break;
		case 72: piscol (15,0);
			 cprintf("%s",a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (1,n-1);
			 else
			    gotoxy (1,wherey() - 1);
			 cprintf("%s",a [wherey() - 1]);
			 h=wherey();
			 cpr1(help5[h-1]);
			 window(68,3,78,3);
			 gotoxy (1,h);
			 break;
		case 77: break;
		case 75: break;

	     }
		if (*Tecla == 77 || *Tecla == 75)
		{  break; }
	 }
	 if(*Tecla==27){ puttext(67,1,79,4,w); cpr1(help6[0]); }
       if(*Tecla=='\r')
	{switch(wherey())
	   {
	     case 1: {
		      piscol(0,15);
		      gettext(21,11,58,14,w);
		      window(21,11,58,14);clrscr();
		      cuad(21,11,58,14);
		      gotoxy(23,12); printf("GRACIAS POR USAR NUESTROS PRODUCTO");
		      gotoxy(23,13); printf("      ESPERE UNOS SEGUNDOS");
		      delay(2500);
		      puttext(21,11,58,14,w);
		      gotoxy(80,25);
		      delay(1000);
		      exit(0);
		     }break;
		  }
	     }
	gettextinfo(P);
	return(0);
     }

/**********************************************************************/

 edwin::EscribaMenuSeis(int n,char *a[],struct text_info *P,int *Tecla)
  {   int i,j,d;
do{
      gettext(20,5,55,19,w);
      piscol (15,0);
      window(29,7,51,7);clrscr();
      marco(29,7,51,7);
      printf(" AUTORES DEL SOFTWARE");
      window(26,11,54,18);clrscr();
      marco (27,11,53,17);
      piscol (15,0);
	for (i=1; i < n-1; i++)
	  {  gotoxy (2,i+1);
	     CPR(a[i]);
	  }
	piscol (10,0);
	gotoxy (2,1); CPR (a [0]);
	cpr1(help7[0]);
	window(27,11,53,17);
	gotoxy (2,1); *Tecla = getch();
	while (*Tecla!='\r'&&*Tecla!=27)
	  { *Tecla = getch();
	    switch (*Tecla)
	     {  case 80: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == n-1)
			    gotoxy (2,1);
			 else
			    gotoxy (2,wherey() + 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help7[h-1]);
			 window(27,11,53,17);
			 gotoxy (2,h);
			 break;
		case 72: piscol (15,0);
			 CPR (a [wherey() - 1]);
			 piscol (10,0);
			 if (wherey() == 1)
			    gotoxy (2,n-1);
			 else
			    gotoxy (2,wherey() - 1);
			 CPR (a [wherey() - 1]);
			 h=wherey();
			 cpr1(help7[h-1]);
			 window(27,11,53,17);
			 gotoxy (2,h);
			 break;
	
	     }
	 }
	 puttext(20,5,55,18,w); 
	 if(*Tecla==27) cpr1(help6[0]); 
	 if(*Tecla=='\r')
	 {cpr1("                     ...Press Any key to continue...");
	  switch(wherey())
	   {
	     case 1: {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	     case 2: {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	    case 3:  {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	    case 4:  {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	     case 5: {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	     case 6: {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;
	     case 7: {
		      gettext(10,4,71,19,z);
		      piscol(1,1);
		      window(11,5,71,19);
		      clrscr();
		      piscol(3,1);
		      window(10,4,70,18);
		      clrscr();
		      cuad(10,4,70,18);
		      getche();
		      puttext(10,4,71,19,z);
		     }break;

	    case 8: break;

	       }
	  }
}while(*Tecla!=27);
gettextinfo(P);
return(0);
}

/**********************************************************************/

void edwin::mensaje(int x,int y,int opK,char *p)
{  
   if(opK==1||opK==3){ textbackground(3);  textcolor(1); }
   else { textbackground(3);  textcolor(1+BLINK); }
   window(16,15,62,17);clrscr();
   gotoxy(x,y);
   printf("%s",p);
   if(opK==3) op=lee_sex(strlen(p)+19,16,'S','N');
}

/**********************************************************************/

void edwin::repetir(int i,char *p)
{  textbackground(3);
   textcolor(1);
   window(5,24,75,24);clrscr();
   gotoxy(15,1);
   cprintf("%s",p);
   if(i==1)
   { delay(1000);
     textbackground(0);
     textcolor(15);
     clrscr();
     printf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   else
   { if(i==2) op=lee_sex(strlen(p)+19,24,'S','N');
     else if(i==3) getche(); 
     textbackground(0);
     window(4,23,76,25);clrscr();
   }
}

/**********************************************************************/

void edwin::lee_cod(int x,int y,char *cod)
{ int i=0;
  textbackground(1);
  textcolor(15);
  window(x,y,x+7,y);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    cod[i]=getche();
    if(cod[i]=='\b'&&i>0) i-=2;
    else if(!isdigit(cod[i])) i--;
    i++;
  }while(i<8);
 cod[i]='\0';
}

/**********************************************************************/

void edwin::lee_nom(int x,int y,char *nom)
{ int i=0;
  textbackground(1);
  textcolor(15);
  window(x,y,x+13,y);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    nom[i]=getche();
    if(nom[i]=='\b'&&i>0) i-=2;
    else
    {  if(nom[i]=='\r'&&i>0) break;
       if(nom[i]==' '&&i>0) i++; 
       if(!isalnum(nom[i])) i--;
    }
    i++;
  }while(i<14);
 nom[i]='\0';
}

/**********************************************************************/

void edwin::val_cod()
{  p=ptr; sw=0;
   while(p!=NULL)
     { if(!strcmp(cod,p->cod)) { sw=1; break; }
       p=p->enlace;
     }
}

/**********************************************************************/

char edwin::lee_sex(int x,int y,char F,char M)
{  char a;
   textbackground(1);
   textcolor(15);
   window(x,y,x,y);clrscr();
   do{
       gotoxy(x,y);clreol();a=toupper(getche());
     }while(a!=F&&a!=M); 
   textbackground(3);
   textcolor(1);
   return(a);
}


/**********************************************************************/

float edwin::lee_not(int x1,int y1 )
 { int i,n;
   char nota[6];
   float not;
 do
 {
  do
   { textbackground(1);
     textcolor(15);i=0;sw=0;
     window(x1,y1,x1+4,y1);clrscr();
     do
     { gotoxy(i+1,1); clreol();
       nota[i]=getche();
       if(nota[i]=='\b'&&i>0) i-=2;
       else
       { if(nota[i]=='\r'&&i>0) break;
	 if(nota[i]!='.') 
	  if(!isdigit(nota[i])) i--;
       }
       i++;
     }while(i<5);
     nota[i]='\0';
    if(isdigit(nota[0])==0) sw=1;
    else 
      { if((nota[1]!='.')&&((n=strlen(nota)-1)>0)) sw=1;
	else                                    
	 { n=strlen(nota);
	   if(n>1)
	    { for(i=2;i<n;i++)
	       if(isdigit(nota[i])==0) sw=1;
	    }
	 }
      }
   if(sw==1) repetir(1,"     !!! NOTA ERRADA !!!");
   }while(sw==1);
  not=atof(nota);
    if((not>5)||(not<0))
    { sw=1; repetir(1,"    !!! NOTA FUERA DE RANGO !!!"); }
   }while(sw==1);
return(not);
}

/**********************************************************************/

void edwin::ordenar()
{
 if(ptr->enlace!=NULL)
 { nodo1 *aux1;
   nodo *aux;
   p=ptr;
   while(p!=NULL)
   { nn=p->enlace;
     while(nn!=NULL)
     { if((strcmp(nn->ape,p->ape)<0) || ((strcmp(nn->ape,p->ape)==0)&&(strcmp(nn->nom,p->nom)<=0)))
       { strcpy(aux->nom,nn->nom);
	 strcpy(aux->cod,nn->cod);
	 strcpy(aux->ape,nn->ape);
	 aux->sex=nn->sex;

	 strcpy(nn->nom,p->nom);
	 strcpy(nn->cod,p->cod);
	 strcpy(nn->ape,p->ape);
	 nn->sex=p->sex;

	 strcpy(p->nom,aux->nom);
	 strcpy(p->cod,aux->cod);
	 strcpy(p->ape,aux->ape);
	 p->sex=aux->sex;

	 aux1=nn->enla_not;
	 nn->enla_not=p->enla_not;
	 p->enla_not=aux1;
       }
       nn=nn->enlace;
     }
     p=p->enlace;
   }
 }
}

/**********************************************************************/

void edwin::vis_gen()
{ int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"     !!! no hay informacion !!!");
   else
   while(p!=NULL)
     { window(2,2,79,20);
       gotoxy(2,k); printf("%s",p->cod);
       gotoxy(12,k); printf("%s",p->nom);
       gotoxy(28,k); printf("%s",p->ape);
       gotoxy(46,k); printf("%c",p->sex);
       p1=p->enla_not;
       if(p1!=NULL)
       { u=49;
	 while(p1!=NULL)
	 { gotoxy(u,k);
	   printf("%.2f",p1->not);
	   p1=p1->sig_not;
	   u+=6;
	 }
       }
       p=p->enlace;
       k++;
     }
   repetir(3,"...Press Any key to continue...");
}

/**********************************************************************/

void edwin::vis_muj_gan()
{  int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"     !!! no hay informacion !!!");
   else
   while(p!=NULL)
     { p1=p->enla_not;
       if(p1!=NULL)
       { while(p1->sig_not!=NULL) p1=p1->sig_not;
	 if((p1->not>=3)&&(p->sex=='F'))
	 { window(2,2,79,20);
	   gotoxy(2,k); printf("%s",p->cod);
	   gotoxy(12,k); printf("%s",p->nom);
	   gotoxy(28,k); printf("%s",p->ape);
	   gotoxy(46,k); printf("%c",p->sex);
	   p1=p->enla_not;
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,k);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   sw=1;
	   k++;
	 }
       }p=p->enlace;
     }
   if(sw==0)repetir(1,"     no hay informacion");
   repetir(3,"...Press Any key to continue...");
}

/**********************************************************************/

void edwin::vis_hom_gan()
{  int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"     !!! no hay informacion !!!");
   else
   while(p!=NULL)
     { p1=p->enla_not;
       if(p1!=NULL)
       { while(p1->sig_not!=NULL) p1=p1->sig_not;
	 if((p1->not>=3)&&(p->sex=='M'))
	 { window(2,2,79,20);
	   gotoxy(2,k); printf("%s",p->cod);
	   gotoxy(12,k); printf("%s",p->nom);
	   gotoxy(28,k); printf("%s",p->ape);
	   gotoxy(46,k); printf("%c",p->sex);
	   p1=p->enla_not;
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,k);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   sw=1;
	   k++;
	 }
       }p=p->enlace;
     }
   if(sw==0)repetir(1,"    no hay informacion");
   repetir(3,"...Press Any key to continue...");
}

/**********************************************************************/

void edwin::vis_al_gan()
{  int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"    !!! no hay informacion !!!");
   else
   while(p!=NULL)
     { p1=p->enla_not;
       if(p1!=NULL)
       { while(p1->sig_not!=NULL) p1=p1->sig_not;
	 if(p1->not>=3)
	 { window(2,2,79,20);
	   gotoxy(2,k); printf("%s",p->cod);
	   gotoxy(12,k); printf("%s",p->nom);
	   gotoxy(28,k); printf("%s",p->ape);
	   gotoxy(46,k); printf("%c",p->sex);
	   p1=p->enla_not;
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,k);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   sw=1;
	   k++;
	 }
       }p=p->enlace;
     }
   if(sw==0)repetir(1,"    no hay informacion");
   repetir(3,"...Press Any key to continue...");
}
/**********************************************************************/

void edwin::vis_al_per()
{  int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"!!! no hay informacion !!!");
   else
   while(p!=NULL)
     { p1=p->enla_not;
       if(p1!=NULL)
       { while(p1->sig_not!=NULL) p1=p1->sig_not;
	 if(p1->not<3)
	 { window(2,2,79,20);
	   gotoxy(2,k); printf("%s",p->cod);
	   gotoxy(12,k); printf("%s",p->nom);
	   gotoxy(28,k); printf("%s",p->ape);
	   gotoxy(46,k); printf("%c",p->sex);
	   p1=p->enla_not;
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,k);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   sw=1;
	   k++;
	 }
       }p=p->enlace;
     }
   if(sw==0)repetir(1,"no hay informacion");
   repetir(3,"...Press Any key to continue...");
}
/**********************************************************************/

void edwin::vis_al_3_5()
{  int u,k;
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    cuad_pres(2,3,79,20,2);
   p=ptr; k=5;
   if(p==NULL) repetir(1,"!!! no hay informacion !!!");
   else
   while(p!=NULL)
     { p1=p->enla_not;
       if(p1!=NULL)
       { while(p1->sig_not!=NULL) p1=p1->sig_not;
	 if(p1->not>=3.5)
	 { window(2,2,79,20);
	   gotoxy(2,k); printf("%s",p->cod);
	   gotoxy(12,k); printf("%s",p->nom);
	   gotoxy(28,k); printf("%s",p->ape);
	   gotoxy(46,k); printf("%c",p->sex);
	   p1=p->enla_not;
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,k);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   sw=1;
	   k++;
	 }
       }p=p->enlace;
     }
   if(sw==0)repetir(1,"no hay informacion");
   repetir(3,"...Press Any key to continue...");
}
/**********************************************************************/

void edwin::vis()
{ int u; 
 do{
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(3,5,78,11);clrscr();
    cuad_pres(2,4,79,10,2);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
    val_cod();
    if(sw==0) mensaje(9,2,2,"!!! no existe el codigo !!!");
   else{ window(2,4,79,10);
	 gotoxy(2,5); printf("%s",p->cod);
	 gotoxy(12,5); printf("%s",p->nom);
	 gotoxy(28,5); printf("%s",p->ape);
	 gotoxy(46,5); printf("%c",p->sex);
	 p1=p->enla_not;
	 if(p1==NULL) mensaje(9,2,2,"!!! no hay notas !!!"); 
	 else
	 { window(2,4,79,10);
	   u=49;
	   while(p1!=NULL)
	   { gotoxy(u,5);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   mensaje(9,2,2,"!!! VISUALIZACION TERMINADA !!!");
	 }
       }
   repetir(2,"Desea visualizar otro estudiante [S/N]: ");
  }while(op=='S');
}

/**********************************************************************/

void edwin::intro()
{ int u;
  do{
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(15,5,67,11);clrscr();
    cuad_pres(13,4,65,10,1);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
     val_cod();
     if(sw==1) mensaje(10,2,2,"!!! EL CODIGO YA EXISTE !!!");
     else
     { window(13,4,65,10);
       gotoxy(3,5); printf("%s",cod);
       mensaje(4,2,1,"digite su nombre: ");
       lee_nom(40,16,nom);
       window(13,4,65,10);
       gotoxy(14,5); printf("%s",nom);
       mensaje(4,2,1,"digite su apellido: ");
       lee_nom(40,16,ape);
       window(13,4,65,10);
       gotoxy(32,5); printf("%s",ape);
       mensaje(4,2,1,"digite su sexo [M/F]: ");
       sex=lee_sex(42,16,'F','M');
       window(13,4,65,10);
       gotoxy(50,5); printf("%c",sex);
       mensaje(10,2,2,"!!!  REGISTRO EXITOSO !!! ");
       nn=new nodo;
       strcpy(nn->cod,cod);
       strcpy(nn->nom,nom);
       strcpy(nn->ape,ape);
       nn->sex=sex;      
       nn->enlace=NULL; 
       nn->enla_not=NULL;
       if(ptr==NULL)
	{
	 ptr=nn;
	 p=nn;
	}
	else
	{ nn->enlace=ptr;
	  ptr=nn;
	}
       ordenar();
     }
   repetir(2,"DESEA ADICIONAR OTRO NODO [S/N]: ");
  }while(op=='S');
}
/**********************************************************************/

void edwin::int_not()
{ int u;
  do{
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(3,5,78,11);clrscr();
    cuad_pres(2,4,79,10,2);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
     val_cod();
     if(sw==0) mensaje(9,2,2,"!!! no existe el codigo !!!");
 else{ window(2,4,79,10);
       gotoxy(2,5); printf("%s",p->cod);
       gotoxy(13,5); printf("%s",p->nom);
       gotoxy(29,5); printf("%s",p->ape);
       gotoxy(46,5); printf("%c",p->sex);
       if(p->enla_not!=NULL)
       {   u=49;
           p1=p->enla_not;
	   while(p1!=NULL)
	   { gotoxy(u,5);
	     printf("%.2f",p1->not);
	     p1=p1->sig_not;
	     u+=6;
	   }
	   mensaje(9,2,2,"!!! ya existen las notas !!!");
       }
       else{
       mensaje(4,2,1,"digite nota 1:");
	not[1]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(49,5); printf("%.2f",not[1]);
       mensaje(4,2,1,"digite nota 2:"); 
	not[2]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(55,5); printf("%.2f",not[2]);
       mensaje(4,2,1,"digite nota 3:"); 
	not[3]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(61,5); printf("%.2f",not[3]);
       mensaje(4,2,1,"digite nota 4:"); 
	not[4]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(67,5); printf("%.2f",not[4]);
	not[5]=not[1]*.25+not[2]*.25+not[3]*.2+not[4]*.3;
	gotoxy(73,5); printf("%.2f",not[5]);
       mensaje(10,2,2,"!!!  REGISTRO EXITOSO !!! ");
       nn1=new nodo1;
       nn1->not=not[1];
       nn1->sig_not=NULL;
       p->enla_not=nn1;
       p1=nn1;
       for(i=2;i<=5;i++)
	{  nn1=new nodo1;
	 nn1->not=not[i];
	 nn1->sig_not=NULL;
	 p1->sig_not=nn1;
	 p1=nn1;
       }
     }}
   repetir(2,"Desea adicionar otra nota [S/N]: ");
   }while(op=='S');
}

/**********************************************************************/

void edwin::mod_nom()
{ int u;
  do{
    piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(15,5,67,11);clrscr();
    cuad_pres(13,4,65,10,1);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
    val_cod();
    if(sw==0) mensaje(10,2,2,"no existe ese codigo");
  else
  {  window(13,4,65,10);
     gotoxy(2,5); printf("%s",p->cod);
     gotoxy(14,5); printf("%s",p->nom);
     gotoxy(32,5); printf("%s",p->ape);
     gotoxy(50,5); printf("%c",p->sex);
     mensaje(4,2,3,"esta seguro de cambiar esos datos [S/N]: ");
    if(op=='S')
    { window(13,4,65,10);
      gotoxy(14,5); clreol();
      printf("                ∫                ∫     ∫");
      mensaje(4,2,1,"digite su nombre: ");
      lee_nom(40,16,nom);
      window(13,4,65,10);
      gotoxy(14,5); printf("%s",nom);
      mensaje(4,2,1,"digite su apellido: ");
      lee_nom(40,16,ape);
      window(13,4,65,10);
      gotoxy(32,5); printf("%s",ape);
      mensaje(4,2,1,"digite su sexo: [M/F]: ");
      sex=lee_sex(42,16,'F','M');
      window(13,4,65,10);
      gotoxy(50,5); printf("%c",sex);
      mensaje(10,2,2,"!!! MODIFICACION  EXITOSA !!! ");
      strcpy(p->nom,nom);
      strcpy(p->ape,ape);
      p->sex=sex;
      ordenar();
    }
  }
  repetir(2,"Desea modificar otro nombre [S/N]: ");
  }while(op=='S');
}
	 
/**********************************************************************/
  
void edwin::mod_not()
{ int u;
  do{
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(3,5,78,11);clrscr();
    cuad_pres(2,4,79,10,2);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
  val_cod();
  if(sw==0) mensaje(10,2,2,"no existe ese codigo");
  else
  { window(2,4,79,10);
    gotoxy(2,5); printf("%s",p->cod);
    gotoxy(13,5); printf("%s",p->nom);
    gotoxy(29,5); printf("%s",p->ape);
    gotoxy(46,5); printf("%c",p->sex);
    p1=p->enla_not;
    if(p1==NULL) mensaje(10,2,2,"no existen las notas ");
    else
    { window(2,4,79,10);
      u=49;
     }
      while(p1!=NULL)
      { gotoxy(u,5);
	printf("%.2f",p1->not);
	p1=p1->sig_not;
	u+=6;
      
      mensaje(4,2,3,"esta seguro de cambiar esas notas [S/N]: ");
      if(op=='S')
      { window(2,4,79,10);
	gotoxy(49,5);clreol();
	printf("     ∫     ∫     ∫     ∫     ∫");    
       mensaje(4,2,1,"digite nota 1:"); 
	not[1]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(49,5); printf("%.2f",not[1]);
       mensaje(4,2,1,"digite nota 2:"); 
	not[2]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(55,5); printf("%.2f",not[2]);
       mensaje(4,2,1,"digite nota 3:"); 
	not[3]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(61,5); printf("%.2f",not[3]);
       mensaje(4,2,1,"digite nota 4:"); 
	not[4]=lee_not(40,16);
	window(2,4,79,10);
	gotoxy(67,5); printf("%.2f",not[4]);
	not[5]=not[1]*.25+not[2]*.25+not[3]*.2+not[4]*.3;
	gotoxy(73,5); printf("%.2f",not[5]);
	mensaje(10,2,2,"!!! MODIFICACION  EXITOSA !!! ");
	p1=p->enla_not; i=1;
	while(p1!=NULL)
	{ p1->not=not[i];
	  p1=p1->sig_not;
	  i++;
	}
      }	  
    }
  }
  repetir(2,"Desea modificar otra nota [S/N]: ");
  }while(op=='S');
}

/**********************************************************************/

void edwin::eliminar()
{ int u;
  do{
   piscol(0,15);
   window(1,1,80,25);clrscr();
   for (u=1;u<22;u++)
   { gotoxy(2,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   }
   for (u=23;u<25;u++)
   { gotoxy(5,u);
     textcolor(15);
     cprintf("∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞");
   } 
    cuad(4,23,76,25);
    cuad(1,1,80,22);
    textbackground(1);window(3,5,78,11);clrscr();
    cuad_pres(2,4,79,10,2);
    textbackground(1);window(18,16,64,18);clrscr();
    textbackground(3);window(16,15,62,17);clrscr();
    gotoxy(4,2);
    cprintf("Digite el codigo: ");
     lee_cod(40,16,cod);
  val_cod();
  if(sw==0) mensaje(10,2,2,"no existe ese codigo");
  else
  { window(2,4,79,10);
    gotoxy(2,5); printf("%s",p->cod);
    gotoxy(13,5); printf("%s",p->nom);
    gotoxy(29,5); printf("%s",p->ape);
    gotoxy(46,5); printf("%c",p->sex);
    p1=p->enla_not;
    if(p1==NULL)
     { mensaje(4,2,3,"esta seguro de eliminar [S/N]: ");
     }
    else
    { window(2,4,79,10);
      u=49;
      while(p1!=NULL)
      { gotoxy(u,5);
	printf("%.2f",p1->not);
	p1=p1->sig_not;
	u+=6;
      }
      mensaje(4,2,3,"esta seguro de eliminar [S/N]: ");
      if(op=='S')
       do{ p1=p->enla_not;
	   nn1=p1->sig_not;
	   delete(p1);
	   p->enla_not=nn1;
	 }while(p->enla_not!=NULL);
    }
    window(2,4,79,10);
    gotoxy(2,5); clreol();
    printf("         ∫               ∫               ∫    ∫     ∫     ∫     ∫     ∫     ∫∫"); 
   if((ptr->enlace==NULL)&&(op=='S')) { delete(ptr);ptr=NULL; }
    else
       if((!strcmp(cod,ptr->cod))&&(op=='S'))
       { ptr=ptr->enlace;
	 delete(p);
       }else if(op=='S')
	     { p=ptr;
	       while(p!=NULL)
	       { if(!strcmp(cod,p->cod))
		 { nn->enlace=p->enlace;
		   delete(p);
		   break;        
		 }
		   nn=p;
		   p=p->enlace;
	       }
	     }
  mensaje(10,2,2,"!!! ELIMINACION  EXITOSA !!! ");
  }
  repetir(2,"Desea eliminar otro estudiante [S/N]: ");
  }while(op=='S');
}

/**********************************************************************/

void ir_a(int i,int j) {
	union REGS r;

	r.h.ah = 2;
	r.h.dh = j-1;
	r.h.dl = i-1;
	r.h.bh = 0;
	int86 (0x10,&r,&r);
}

/**********************************************************************/

void esc(char c,int veces) {
	union REGS r;

	r.h.ah = 0xa;
	r.h.al = c;
	r.h.bh = 0;
	r.x.cx = veces;
	int86 (0x10,&r,&r);
}

/**********************************************************************/

void edwin::marco (int a,int b,int c, int d) {
	int i,j;
	void ir_a(int,int);
	void esc (char ,int );
	window (1,1,80,25);
	ir_a (a-1,b-1);
	esc (si,1);
	ir_a(a,b-1);
	esc(lh,c-a+1);
	ir_a (c+1,b-1);
	esc (sd,1);
	for (i=b; i <= d; i++ ) {
		ir_a (c+1,i);
		esc (lv,1);
	}
	ir_a (c+1,d+1);
	esc(id,1);
	ir_a (a-1,d+1);
	esc (ii,1);
	ir_a (a,d+1);
	esc(lh,c-a+1);
	for (i=b; i <= d; i++ ) {
		ir_a (a-1,i);
		esc (lv,1);
	}
	window (a,b,c,d);
	gotoxy (1,1);

}

/**********************************************************************/

int edwin::clave()
      { char Key,Letras[10];
	  int  c,Conteo=0,Swiche=0;
	  c=22;
	  do{   Conteo++;
	  gotoxy(c,3);Key=tolower(getch());textcolor(0);cprintf("*");
	  if(Conteo==1 && Key=='l')Swiche++;
	  if(Conteo==2 && Key=='u')Swiche++;
	  if(Conteo==3 && Key=='i')Swiche++;
	  if(Conteo==4 && Key=='s')Swiche++;
	  if(Conteo==5 && Key=='a')Swiche++;
	  if(Conteo==6 && Key=='2')Swiche++;
	  c++;                   	
	  }while(Conteo<=10 && Swiche<=5);
	  return(Swiche);
      }


void reset()
{union REGS nt,salida;
int86(0X19,&nt,&salida);
}
void edwin::clav()
{   int cont=0;
  do{window(1,1,80,25);textbackground(0);
  cont++;
       clrscr();
       
       window(20,10,60,15);textbackground(1);clrscr();
       window(20,11,60,15);textbackground(7);clrscr();
       textcolor(0);
       gotoxy(10,10);gotoxy(5,3);cprintf("CLAVE DE ACCESO:[          ]");
       gotoxy(27,10);
 if(clave()==6)
		{ udes();
		  PoP_PoP();
		  cont=7;
		}
       else{ 
	     window(20,10,60,15);textbackground(1);clrscr();
	     window(20,11,60,15);textbackground(7);clrscr();
	     gotoxy(2,3);
	     textcolor(0);
	     cprintf("<<<ACCESO DENEGADO CLAVE INCORRECTA>>>");
	     delay(1500);
	  }
  }while(cont<3);  
reset();
}

void edwin::udes()
{int m=10,k;window(1,1,80,25);textbackground(0);clrscr(); 
for(k=1;k<4;k++){
int i,a,b,c,d,e,f; a=21;b=22;c=23;d=24;e=25;
textcolor(m+3);
clrscr();
for(i=10;i<18;i++)
{
gotoxy(i,a);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");       
gotoxy(i,b);cprintf(" ≥€€€¿ƒƒŸ€€€≥ ≥€€€   €€≥");        
gotoxy(i,c);cprintf(" ≥€€€€€€€€€€≥ ≥€€€€€€ﬂﬂ≥");        
gotoxy(i,d);cprintf(" ¿ƒƒƒƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒƒŸ"); 
gotoxy(i,e);cprintf("                       ");
a--;b--;c--;d--;e--;delay(20);
}


a=3;b=4;c=5;d=6;e=7;f=8;
for(i=47;i>=42;i--)
{
gotoxy(i,a);cprintf("                    ");
gotoxy(i,b);cprintf("⁄ƒƒƒƒƒƒƒø ⁄ƒƒƒƒƒƒƒø ");
gotoxy(i,c);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");
gotoxy(i,d);cprintf("≥€€€⁄ƒƒƒŸ ≥€€€⁄ƒƒƒŸ "); 
gotoxy(i,e);cprintf("≥€€€¿ƒƒƒø ≥€€€¿ƒƒƒø "); 
gotoxy(i,f);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");  

a++;b++;c++;d++,e++;f++;                 
delay(20);
}
a=19;b=20;c=21;d=22;e=23;f=24;
for(i=47;i>=42;i--)
{
gotoxy(i,a);cprintf("≥€€€⁄ƒƒƒŸ ¿ƒƒƒø€€€≥ "); 
gotoxy(i,b);cprintf("≥€€€¿ƒƒƒø ⁄ƒƒƒŸ€€€≥ ");   
gotoxy(i,c);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");    
gotoxy(i,d);cprintf("¿ƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒŸ ");
gotoxy(i,e);cprintf("                    ");
a--;b--;c--;d--;e--;delay(20);
}
a=1;b=2;c=3;d=4;e=5;f=6;
for(i=10;i<18;i++)
{
gotoxy(i,a);cprintf("                        ");
gotoxy(i,b);cprintf(" ⁄ƒƒƒø  ⁄ƒƒƒø ⁄ƒƒƒƒƒƒƒƒø");  
gotoxy(i,c);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€€€€‹‹≥"); 
gotoxy(i,d);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€  ﬂ€€≥");    
gotoxy(i,e);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");    
gotoxy(i,f);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");
a++;b++;c++;d++,e++;f++;                 
delay(20);    
}
m++;
}
gotoxy(27,20);printf("Press any key to continue");
gotoxy(26,15);
getche();
}


edwin::edwin(struct nodo *f)
{ptr=f;
}
void main()
{edwin objeto(NULL); 
 objeto.clav();
}

