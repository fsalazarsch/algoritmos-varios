/* Maneja un cursor lista simple en disco duro, cuando la informacion
	de cada registro es de tipo INFO */

#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "ctype.h"
#define MAXIMO 30
#define LON sizeof (BUFFER)
#define grabar(id,a)  _write (id,(char *)&a,LON)
#define lea(id,a)  _read (id,(char *)&a,LON)
#define ubicar(id,a)  lseek (id,a * LON, SEEK_SET)
typedef struct BUFFER BUFFER;
typedef struct CARCEL CARCEL;
/**** definicion de la plantilla para el archivo*****/
struct CARCEL {
		 long  cod;
		 char nombre [30];
};
/**** definicion de la plantilla para el cursor lista*****/

struct BUFFER {
	CARCEL carcel;/* apuntador para la pantilla CARCEL*/
	long sig;/* apuntador para el siguiente cursor lista */
};

class CURSOR {
 int global_id;
 public:

CURSOR(){ global_id=init_archivo();};/* constructor de la clase */
~CURSOR(){ unlink("lista"); };/* destructor de la clase*/
/* definicion de las funciones para el cursor lista en el programa**/
int pulsar(){ return global_id;};
void Global_id(int ident){global_id=ident;};
void copie (BUFFER *q,BUFFER p); /*copia q en p*/
void escribir1 (); /* muestra  toda la carcelrmacion del cursor lista*/
void liberar (int id,int p, BUFFER pc, BUFFER *r0);/* elimina un registro del cursor lista*/
long disp (int id, BUFFER *r0);/* indica que lugar que esta disponible dentro del archivo con manejos de cursores */
int modificar(int id,BUFFER n);/* permite modificar carcelrmacion del cursor lista  */
long ValidarNumero();
int ValidarCadena(char String[]);
void lea1 (BUFFER *p);
void escribir (int id );/* lista carcel del cursor lista*/
int retirar (int id,long n);/*Esta funcion busca un codigo para luego liberarlo del cursor lista*/
int  init_archivo ();/*inicializa el archivo*/
int insertar(int id,BUFFER n);
};
  int sw=0;
  long n1;
  char c;
  BUFFER n;
  CURSOR cursor;
void menu();
void marco(int x1,int y1,int x2,int y2);
void color();
void CURSOR::lea1 (BUFFER *p)
{
		  gotoxy(10,5);
		  printf("Inserte Codigo Del Recluso  ");
		  p->carcel.cod = ValidarNumero();
		  gotoxy(10,7);
		  printf ("Inserte Nombre Y Apellido Del Recluso  ");
		  scanf("\n");
		  gets(p->carcel.nombre);
}

long CURSOR::ValidarNumero(){

			 char a[20];
			 int z,p;
			  do{
			  z=0;p=0;
			  gotoxy(45,(wherey()-1)+1);
			  clreol();
			  gets(a);

			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) p=-1;
			 z++;
			 }


		       }while(p==-1);

			return(atol(a));
			 }



int CURSOR::ValidarCadena(char String[]) {
	int LongitudCadena=strlen(String),i=0,sw=0;
	while(i<=LongitudCadena-1) {
	if(String[i]>='0'&&String[i]<='9'){
		 sw=1;
	}
		i++;
		}
	 if(sw==1)
	 return 1;
	 else
	 return -1;
  }


void CURSOR::escribir (int id )
{
	long i;

	BUFFER a;

	ubicar (id,0);
	lea (id,a);
	i = a.carcel.cod;
	while (i != 0) {
		ubicar (id,i);
		lea (id,a);
		printf ("%ld %s\n ",a.carcel.cod,a.carcel.nombre);
		i = a.sig;
	}
  Global_id(id);
}

int CURSOR::retirar (int id,long n)
{
	long p;
	long q,enc,prox;
	BUFFER pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.carcel.cod;
	q = enc = 0;
	while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n > pc.carcel.cod) {
			q =(int)p;
			copie (&qc,pc);
			p = pc.sig;
		}
		else enc = 1;
	}


	if (enc == 1)
		if (pc.carcel.cod != n)
			return (-1); /* No existe */



	if (q == 0)
		r0.carcel.cod = pc.sig;
	else {
		qc.sig = pc.sig;
		ubicar (id,q);
		grabar (id,qc);
	}
	liberar (id,p,pc,&r0);

	ubicar (id,0);
	grabar (id,r0);
	Global_id(id);
return(id);
}

int CURSOR::modificar(int id,BUFFER n)
{
	long p;
	int enc,prox;
	BUFFER pc,qc,r0,proxc;

	ubicar (id,0);
	lea (id,r0);
	p = r0.carcel.cod;
	 enc = 0;
		  while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n.carcel.cod > pc.carcel.cod) {
			copie (&qc,pc);
			p =pc.sig;
		}
		else enc = 1;
	}

	if (enc == 1){
		if (pc.carcel.cod == n.carcel.cod)
			{
					strcpy (pc.carcel.nombre,n.carcel.nombre);
					ubicar(id,p);
					grabar (id,pc);
		     
	
			       }else{
				       return -1;
       }

      }	ubicar (id,0);
	grabar (id,r0);
	Global_id(id);
 return(0);
}



long  CURSOR::disp (int id, BUFFER *r0)
{
	long i;
	

	BUFFER r1;
	i = r0->sig;
	if (i==0)
		return (-1);
	else  {
			ubicar (id,i);
			lea (id,r1);
			r0->sig = r1.sig;
			return (i);
	}
}


void CURSOR::liberar (int id,int p, BUFFER pc, BUFFER *r0)
{
	pc.sig = r0->sig;
	ubicar (id,p);
	grabar (id,pc);
	r0->sig = p;
}
void CURSOR::escribir1 ()
{
	int id,i=2;
	BUFFER a;
	 clrscr();
	id = _open ("lista",O_RDONLY);
	while (lea (id,a) != 0){
		printf ("%ld %s %d \n",a.carcel.cod,a.carcel.nombre,a.sig);
		if(i==23)
		   getch();
		   i++;        }
	getch();
	close (id);
}
void CURSOR::copie (BUFFER *q,BUFFER p)
{
		  q->carcel.cod = p.carcel.cod;
		  strcpy (q->carcel.nombre, p.carcel.nombre);
		  q->sig = p.sig;
}


int CURSOR::init_archivo ()
{
	long i;
	int id;
	BUFFER a;

	id = _creat ("lista",32);
	close (id);
	id = _open ("lista",O_RDWR);
	a.carcel.cod = 0;
		  strcpy (a.carcel.nombre,"        ");
	for (i=0; i<MAXIMO ; i++) {
		a.sig = i+1;
		grabar (id,a);
	}
	a.sig = 0;
	grabar (id,a);
	return(id);
}

int CURSOR::insertar (int id,BUFFER n)
{
	long p;
	int q,enc,prox;
	BUFFER pc,qc,r0,proxc;
	ubicar (id,0);
	lea (id,r0);
	p = r0.carcel.cod;
	q = enc = 0;
		  while (p != 0 && !enc) {
		ubicar (id,p);
		lea (id,pc);
		if (n.carcel.cod > pc.carcel.cod) {
			q =p;
			copie (&qc,pc);
			p =pc.sig;
		}
		else enc = 1;
	}

	if (enc == 1)
		if (pc.carcel.cod == n.carcel.cod)
			return (-1); /* Ya existe en el archivo */

	prox = disp(id,&r0);
	if (prox != -1) {
		proxc.carcel.cod = n.carcel.cod;
		strcpy (proxc.carcel.nombre,n.carcel.nombre);
		proxc.sig = p;
		ubicar (id,prox);
		grabar (id,proxc);
		if (q == 0)
			r0.carcel.cod = prox;
		else {
			qc.sig = prox;
			ubicar (id,q);
			grabar (id,qc);
		}
	}
	else {
		printf ("Archivo lleno. Se debe ampliar el archivo..\n");
		getch();
		exit (1);
	}
	ubicar (id,0);
	grabar (id,r0);
	Global_id(id);
 return(0);
}

void adicionar(){
cursor.Global_id(_open ("lista",O_RDWR));
do{
		clrscr();
		cursor.lea1 (&n);
		if (cursor.insertar (cursor.pulsar(),n) == -1)
			printf ("\nrepetido\n");
		else    printf ("\ninsertado....%ld\n",n);

		gotoxy(10,12);
		printf ("Desea continuar? (s/n)\n");
		do{
		   c = toupper(getch());
		   if(c=='S'||c=='N')
		      sw=1;
		      else
		      sw=0;
		 }while(sw!=1);

	

}while(c!='N');
}
void modificar(){
do{
		clrscr();
		cursor.lea1 (&n);
		if (cursor.modificar(cursor.pulsar(),n) == -1)
			printf ("\nrepetido\n");
		else    printf ("\ninsertado....%ld\n",n);

		gotoxy(10,12);
		printf ("Desea continuar? (s/n)\n");
		do{
		   c = toupper(getch());
		   if(c=='S'||c=='N')
		      sw=1;
		      else
		      sw=0;
		 }while(sw!=1);

	

}while(c!='N');

}
void eliminar(){
do{
		clrscr();
	
		gotoxy(10,8);
		printf("Digite El Codigo A Eliminar::> ");
		n1=cursor.ValidarNumero();
		if (cursor.retirar (cursor.pulsar(),n1) == -1)
			printf ("\nno existe...\n");
		else printf ("\nretirado ....%ld\n",n1);

		gotoxy(10,12);
		printf ("Desea continuar? (s/n)\n");
		do{
		   c = toupper(getch());
		   if(c=='S'||c=='N')
		      sw=1;
		      else
		      sw=0;
		 }while(sw!=1);

	

}while(c!='N');

}



void main ()
{
cursor.Global_id(_open ("lista",O_RDWR));
menu();
close(cursor.pulsar());

}	
	

void menu()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
 char helpline[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"INSERTAR               ");
 strcpy(opciones[10],"MODIFICAR              ");
 strcpy(opciones[11],"ELIMINAR               ");
 strcpy(opciones[12],"VISUALIZAR             ");
 strcpy(opciones[13],"NUEVO PROCEDIMIENTO    ");
 strcpy(opciones[14],"SALIR                  ");
 strcpy(helpline[9], "INSERTAR PRESO A LA CARCEL                 ");
 strcpy(helpline[10],"MODIFICAR INFORMACION DE LA LISTA          ");
 strcpy(helpline[11],"PERMITE LA SALIDA DE UN PRESO DE LA CARCEL ");
 strcpy(helpline[12],"VISUALIZAR LOS PRESOS DE LA CARCEL         ");
 strcpy(helpline[13],"NUEVO PROCEDIMIENTO                        ");
 strcpy(helpline[14],"SALIR DE LA APLICACION                     ");

   do{
   color();
   for(f=9; f<=14;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,25);
cprintf(helpline[f]);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  { 
  tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(11);  //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 :  _setcursortype(_SOLIDCURSOR);adicionar();color(); break;
 case 10:_setcursortype(_SOLIDCURSOR);modificar();color(); break;
 case 11:_setcursortype(_SOLIDCURSOR);eliminar();color(); break;
 case 12:_setcursortype(_SOLIDCURSOR);clrscr();cursor.escribir(cursor.pulsar());getch();color(); break;
 case 13:_setcursortype(_SOLIDCURSOR); break;
 
 }

}
 while(f!=14);
}
void marco(int x1,int y1,int x2,int y2)
{ int n;
  textcolor(0);
  gotoxy(x1, y1); cprintf("%c",201); //É
  gotoxy(x2, y1); cprintf("%c",187); //»  
  gotoxy(x1, y2); cprintf("%c",200); //È 
  gotoxy(x2, y2); cprintf("%c",188); //¼
       for(n=(x1+1);n<=(x2-1);n++){
       gotoxy(n, y1);cprintf("%c",205);//Í
       gotoxy(n, y2);cprintf("%c",205);} 
    for(n=(y1+1);n<=(y2-1);n++){
       gotoxy(x1, n);cprintf("%c",186); //º
       gotoxy(x2, n);cprintf("%c",186);} 
  }
void color()
{
int n,j;
window(1,1,80,25);
clrscr();
textbackground(15);
  window(1,1,80,25);
  clrscr();

 for(n=2;n<=24;n++)
     for(j=1;j<=80;j++)
	{
	textcolor(RED);
	gotoxy(j,n);
	cprintf("Û");
	}
 gotoxy(12,1);
 cprintf(" C  U  R  S  O  R     L I S T A   E N   C  P  P");

   marco(26,7,53,16);
 }


