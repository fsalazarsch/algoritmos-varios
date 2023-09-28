#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>
#include <graphics.h>
#include <process.h>
#include <iostream.h>



class grafo
{
  struct arbol
  { int info;
    struct arbol *izq,*der;
  };

 public:
  xy(int x, int y);
  void extr(int x,char vector[2]);
  grafo(struct arbol *c);
  void imprimir(struct arbol *a);
  void imprime_arbin(struct arbol *a,int x1,int y1, int n, int j);
  void calcula_pos(int q, int w, int *e, int *r);
  void rec_preorden(struct arbol *aux);
  void rec_posorden(struct arbol *aux);
  void rec_inorden(struct arbol *aux);
  void introducir();
  void consultar();
  void grafos();
  void eliminar();
  void menut();
  void pinta (int piso,int color);
  void ref1(int n,int piso,int color,char s[]);
  void ref2(int n,int piso,int color,char s[]);
  void marco(int a,int b,int c,int d);
  void marco2(int a,int b,int c,int d);
  void fondo(int a,int c,int color);
  void piso_color(int piso,int color);
  void menu1();
  void escribe_menu2();
  void escribe_menu4();
  void menu3();
  void ayuda();
  void salir();



  char ve[3];
    
  struct arbol *cabeza,*nn,*p;

};

char op2[6][20]={" ","Recorrido Inorden","Recorrido Preorden","Recorrido Posorden","Visualizar Arbol"};
int sw2,i,j,st,lon;




//--------------------------------------------------------------------------------


void grafo::escribe_menu2()
   {
    int i;
    clrscr();
    textbackground(15);textcolor(1);
    for(i=1; i<=2000; i++)
    {
     cprintf("ฐ");
    }
    window(1,1,80,25);
    gotoxy(1,1);
    fondo(2,81,LIGHTGRAY);
    piso_color(10,RED);
    gotoxy(8,1);
    cprintf("ADICIONAR");
    piso_color(WHITE,RED);
    gotoxy(20,1);
    cprintf("CONSULTAR");
    gotoxy(32,1);
    cprintf("ELIMINAR");
    gotoxy(46,1);
    cprintf("VISUALIZAR");
    gotoxy(60,1);
    cprintf("AYUDA");
    gotoxy(70,1);
    cprintf("SALIR");
    piso_color(BLACK,WHITE);
    marco(2,3,78,22);
    gotoxy(1,24);
    fondo(1,159,LIGHTGRAY);
    piso_color(5,YELLOW);
    gotoxy(2,24);
    cprintf(" En este comando usted podra tener la  facilidad   de poder adicionar         ");
    gotoxy(2,25);
    cprintf(" un nodo en el arbol.                                                         ");
    gotoxy(8,1);

}


//--------------------------------------------------------------------------------
void grafo::fondo(int a,int c,int color)
{
  int i;
  textcolor(color);
  for(i=a;i<=c;i++)
    {
     cprintf("%c",219);
    }
}


//--------------------------------------------------------------------------------
void grafo::marco(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'ฺ');
   for (i=a;i<=c;i++ )
     {
       cprintf("%c",'ฤ');
     }
   cprintf("%c",'ฟ');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'ณ');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
    {
      cprintf("%c",'ฤ');
    }
  cprintf("%c",'ู');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'ณ');
  }
}


//--------------------------------------------------------------------------------
void grafo::marco2(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'ฺ');
   for (i=a;i<=c;i++ )
      {
       cprintf("%c",'ฤ');
      }
   cprintf("%c",'ฟ');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'ณ');

   }              
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
    {
     cprintf("%c",'ฤ');
    }
  cprintf("%c",'ู');
  for (i=b;i<=d;i++ )
   {
     gotoxy(a-1,i);
     cprintf("%c",'ณ');
   }
  window(a,b,c,d);
}


//--------------------------------------------------------------------------------
void grafo::ref1(int n,int piso,int color,char s[])
{
   gotoxy(n,1);
   piso_color(piso,color);
   cprintf("%s",s);
}


//--------------------------------------------------------------------------------
void grafo::ref2(int n,int piso,int color,char s[])
{
  gotoxy(n,1);
  piso_color(piso,color);
  cprintf("%s",s);
  gotoxy(n,1);
}


//--------------------------------------------------------------------------------
void grafo::piso_color(int piso,int color)
{
   textbackground(piso);
   textcolor(color);
}


//--------------------------------------------------------------------------------
void grafo:: menu3()
{
     char c;
     piso_color(1,WHITE);
     escribe_menu4();
     c = getch();

     while (c !=27)
     {
	   switch (c)
	   {
	     case 80 : 
		       {
			  piso_color (1,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 4)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	     case 72 : 
		       {
			  piso_color(1,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 1) gotoxy (3,4);
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
		 case 1:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 piso_color(1,WHITE);
			 window(3,3,78,22);
			 rec_inorden(cabeza);
			 getch();
			 clrscr();
			 escribe_menu4();
			 break;
			}

		case 2:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 piso_color(1,WHITE);
			 window(3,3,78,22);
			 rec_preorden(cabeza);
			 getch();
			 clrscr();
			 escribe_menu4();
			 getch();
			 break;
		       }

		case 3:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 piso_color(1,WHITE);
			 window(3,3,78,22);
			 rec_posorden(cabeza);
			 getch();
			 clrscr();
			 escribe_menu4();
			 break;
		       }

	       case 4:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 imprimir(cabeza);
			 piso_color(1,WHITE);
			 window(3,3,78,22);
			 clrscr();
			 escribe_menu2();
			 escribe_menu4();
			 break;
		       }
		 }
	   }
     }
}


//--------------------------------------------------------------------------------
void grafo::escribe_menu4()
{
     marco2(42,3,62,6);
     for(j=3; j<=6; j++)
     {
      for(i=42;i<=62;i++)
      {
       textcolor(0);textbackground(1);
       gotoxy(i,j);cprintf(" ");
      }
     }
     piso_color(1,WHITE);
     for(i=2;i<=5;i++)
      {
       gotoxy (3,i);
       cprintf("%s ",op2[i]);
      }
     piso_color (WHITE,1);
     gotoxy (3,1);
     cprintf("%s",op2[1]);
     gotoxy (3,1);
}


//--------------------------------------------------------------------------------


void grafo::ayuda()
{
   for(j=3; j<=12; j++)
    {
     for(i=45;i<=75;i++)
     {    
      textcolor(0);textbackground(1);
      gotoxy(i,j);cprintf(" ");
     }
    }
   piso_color(1,WHITE);
   marco2(45,3,75,12);
   cprintf("%c Desplazamiento hacia arriba  ",24);
   cprintf("%c Desplazamiento hacia abajo   ",25);
   cprintf("%c Desplazamiento a la izquierda",27);
   cprintf("%c Desplazamiento a la derecha  ",26);
   cprintf("ENTER para entrar a los menus. ");
   cprintf("colgantes.                     ");
   cprintf("ENTER en cada opcion ingresa a ");
   cprintf("el desarrollo de esta.         ");
   cprintf("ESC para salir de cada menu.   ");
   getch();
}


//--------------------------------------------------------------------------------
void grafo::salir()
{
  sw2=1;
}

void grafo::grafos()
{

textcolor(10); textbackground(0);
gotoxy(12,4); cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
gotoxy(12,5); cprintf("บ                                                         บ");
gotoxy(12,6); cprintf("บ                                                         บ");
gotoxy(12,7); cprintf("บ                                                         บ");
gotoxy(12,8); cprintf("บ                                                         บ");
gotoxy(12,9); cprintf("บ                                                         บ");
gotoxy(12,10);cprintf("บ                                                         บ");
gotoxy(12,11);cprintf("บ                                                         บ");
gotoxy(12,12);cprintf("บ                                                         บ");
gotoxy(12,13);cprintf("บ                                                         บ");
gotoxy(12,14);cprintf("บ                                                         บ");
gotoxy(12,15);cprintf("บ                                                         บ");
gotoxy(12,16);cprintf("บ                                                         บ");
gotoxy(12,17);cprintf("บ                                                         บ");
gotoxy(12,18);cprintf("บ                                                         บ");
gotoxy(12,19);cprintf("บ                                                         บ");
gotoxy(12,20);cprintf("บ                                                         บ");
gotoxy(12,21);cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
textcolor(15+128); textbackground(0);
gotoxy(26,20);cprintf("<< Esc para salir o terminar >>");
textcolor(13); textbackground(0);
}


//--------------------------------------------------------------------------------
void grafo::introducir()
{ char op,inform[3];
  int info,i;      
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
   i=0;
  gotoxy(18,8);printf("DIGITE NUMERO ADICIONAR[0..99]:");
  do
  { gotoxy(i+52,8);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=2;
    else 
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<2);
  inform[i]='\0';
  info=atoi(inform);
  p=nn=cabeza;i=1;
  while((info!=p->info)&&(nn!=NULL)&&(i<=6))
  { p=nn;
    if(info<p->info)
      nn=p->izq;
    else
      nn=p->der;
    i++;
  }
  if(info==p->info)
    {
     piso_color(1,WHITE);
     window(3,3,78,22);
     clrscr();
     gotoxy(22,8);printf("ESTE NUMERO YA EXISTE");
     getch();
    }
  else
   if(i==6)
     {
      getch();
     }
   else
   { nn=new arbol;
     nn->info=info;
     nn->izq=NULL;
     nn->der=NULL;
     if(cabeza==NULL)
      {
       cabeza=nn;
      }
     else
     { if(info<p->info)
	p->izq=nn;
       else
	p->der=nn;
     }
   }
   do
   { clrscr();gotoxy(24,8);printf("DESEA CONTINUAR [S/N]: ");
     gotoxy(18,52);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') introducir();
}

//--------------------------------------------------------------------------------
void grafo::consultar()
{
  struct arbol *q,*q1,*q2;
  char op,inform[3];
  int info,i;      
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
   i=0;
  gotoxy(18,8);printf("DIGITE NUMERO A CONSULTAR[0..99]:");
  do
  { gotoxy(i+52,8);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=2;
    else 
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<2);
  inform[i]='\0';
  info=atoi(inform);
  p=cabeza;
  nn=cabeza;i=1;
  while((info!=p->info)&&(nn!=NULL)&&(i<=6))
  { p=nn;
    if(info<p->info)
      nn=p->izq;
    else
      nn=p->der;
    i++;
  }
  if(info==p->info)
    {
     piso_color(1,WHITE);
     window(3,3,78,22);
     clrscr();
     q->info=p->info;
     gotoxy(22,8);printf("ESTE NUMERO %d EXISTE EN EL ARBOL",q->info);
     getch();
    }
  else
   if(i==6)
     {
      getch();
     }
   else
   {
     clrscr();
     gotoxy(24,8);printf("ESTE NUMERO NO EXISTE");
     getch();
   }
   do
   { clrscr();gotoxy(24,8);printf("DESEA CONTINUAR [S/N]: ");
     gotoxy(18,52);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') consultar();
}


//--------------------------------------------------------------------------------
void grafo::rec_inorden(struct arbol *aux)
{
 if(aux!=NULL)
  {
   rec_inorden(aux->izq);
   printf("%d\t",aux->info);
   rec_inorden(aux->der);
  }
}


//--------------------------------------------------------------------------------
void grafo::rec_preorden(struct arbol *aux)
{
  if(aux!=NULL)
   { 
    printf("%d\t",aux->info);
    rec_preorden(aux->izq);
    rec_preorden(aux->der);
   }
}


//--------------------------------------------------------------------------------
void grafo::rec_posorden(struct arbol *aux)
{
  if(aux!=NULL)
  { rec_posorden(aux->izq);
    rec_posorden(aux->der);
    printf("%d\t",aux->info);
  } 
}


//--------------------------------------------------------------------------------
void grafo::eliminar()
{ char op,inform[3];
  int info,i;      
  struct arbol *q,*s,*f;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
  i=0;
  gotoxy(18,8);
  printf("DIGITE NUMERO A ELIMINAR[0..99]: ");
  do
  { gotoxy(i+52,8);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=2;
    else 
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<2);
  inform[i]='\0';
  info=atoi(inform);
  f=NULL;
  p=nn=cabeza;
  while((info!=p->info)&&(nn!=NULL))
  { f=p;
    p=nn;
    if(info<p->info)
      nn=p->izq;
    else
      nn=p->der;
  }
  if(info!=p->info)
   {
    piso_color(1,WHITE);
    window(3,3,78,22);
    clrscr();
    gotoxy(20,8);
    printf("EL NUMERO A ELIMINAR NO EXISTE");
    getch();
   }
  else
  { if(p->izq==NULL)
      nn=p->der;
    else
      if(p->der==NULL)
	nn=p->izq;
      else
      { q=p;
	nn=q->der;
	s=nn->izq;
	while(s!=NULL)
	{ q=nn;
	  nn=s;
	  s=nn->izq;
	}
	if(q!=p)
	{ q->izq=nn->der;
	  nn->der=p->der;
	}
	nn->izq=p->izq;
      }
      if(f==NULL)
	cabeza=nn;
      else
	{ if(p==f->izq) f->izq=nn;
	  else f->der=nn;
	}
    p->izq=p->der=NULL;
    free(p);
    clrscr();
    gotoxy(20,8);
    printf("EL NUMERO HA SIDO ELIMINADO");
    getch();
  }
 

 do{
     clrscr();
     gotoxy(24,8);
     printf("DESEA CONTINUAR  [S/N]: ");
     gotoxy(18,52);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') eliminar();
}



//--------------------------------------------------------------------------------
grafo::xy(int x, int y)
  {
    int k;
     if (y==0)
       return(1);
     else
       {
	 for (k=1; k<y; k++)
	   x=x*2;
	 return(x);
       }
  }


//--------------------------------------------------------------------------------
void grafo::calcula_pos(int q, int w, int *e, int *r)
  {
    if (q==4)
       if (w % 2 != 0)
	  *e=2 + (w / 2 ) * 10;
       else
	  *e=8 + (w / 2 - 1) * 10;
    else
       *e=80 / xy(2,q+1)+(w-1)*2*(80 / xy(2,q+1));
    *r=q*4+2;
  }



//--------------------------------------------------------------------------------
void grafo::imprime_arbin(struct arbol *a,int x1,int y1, int n, int j)
  { int nn,jj;
    calcula_pos(n, j, &nn, &jj);
     if (a!=NULL)
       { if((x1!=0)&&(y1!=0))
	 line((x1+.3)*7.9875,(y1+.75)*19.16,nn*7.9875,(jj-.75)*19.16);
	 circle((nn+.3)*7.9875,jj*19.16,14);
	 extr(a->info,ve);
	 if(strlen(ve)==1)
	  {
	   outtextxy((nn-.1)*7.9875,(jj-.15)*19.16,ve);
	  }
	 else
	  {
	   outtextxy((nn-.47)*7.9875,(jj-.15)*19.16,ve);
	  }
	 x1=nn;y1=jj;
	 imprime_arbin(a->izq,x1,y1,n+1,j*2-1);
	 imprime_arbin(a->der,x1,y1,n+1,j*2);
       }
   }


//--------------------------------------------------------------------------------
void grafo::imprimir(struct arbol *a)
  { 
    
    int z,zz;
    int gdriver = DETECT, gmode, errorcode; 
    initgraph(&gdriver, &gmode, "..\\bgi");
    setcolor(getmaxcolor());
    
    z=0;
    zz=1;


    imprime_arbin(a,0,0,z,zz);
    getch();
    closegraph();
    piso_color(1,WHITE);
    window(3,3,78,22);
  }


//--------------------------------------------------------------------------------
void grafo::extr(int x,char vector[3])
{ int as;
 if(x>9)
  { as=(x/10);
    vector[0]=as+'0';
    as=(x%10);
    vector[1]=as+'0';
    vector[2]='\0';
  }
 else
  { vector[0]=x+'0';
    vector[1]='\0';
  }
}	 



//--------------------------------------------------------------------------------
grafo::grafo(struct arbol *c)
 { cabeza=c; }


//--------------------------------------------------------------------------------

void grafo::menut()
{
 char d;
 textcolor(15);textbackground(1);
 escribe_menu2();
 grafos();
 gotoxy(1,24);
 fondo(1,159,LIGHTGRAY);
 piso_color(5,YELLOW);
 gotoxy(2,24);
 cprintf(" En este comando usted podra tener la  facilidad   de poder adicionar        ");
 gotoxy(2,25);
 cprintf(" NODO en el arbol.                                                           ");
 gotoxy(8,1);

    sw2=0;
    d=getch();
    gotoxy(8,1);
    while ((d!=27)&&(sw2!=1))
    {
	  switch(d)
	  {
	     case 77:
		     {

		      switch(wherex())
			{
		      case 8:
			     {
			       ref1(8,WHITE,RED,"ADICIONAR");
			       ref2(20,10,RED,"CONSULTAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener la facilidad de poder consultar           ");
			       gotoxy(2,25);
			       cprintf(" o verificar si existe este nodo en el arbol.                                ");
			       gotoxy(18,1);
			       break;
			     }

		     case 18:
			     {
			       ref1(20,WHITE,RED,"CONSULTAR");
			       ref2(32,10,RED,"ELIMINAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando existe la opciขn de poder eliminar un nodo cualquiera       ");
			       gotoxy(2,25);
			       cprintf(" siempre y cuando exista en el arbol.                                        ");
			       gotoxy(32,1);
			       break;
			     }

		     case 32:
			     {
			       ref1(32,WHITE,RED,"ELIMINAR");
			       ref2(46,10,RED,"VISUALIZAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando existen las opciones que le permitiran al usuario poder     ");
			       gotoxy(2,25);
			       cprintf(" visualizar los nodos y aristas existentes y tambien visualizar el GRAFO.    ");
			       gotoxy(46,1);
			       break;
			     }

		     case 46:
			     {
			       ref1(46,WHITE,RED,"VISUALIZAR");
			       ref2(60,10,RED,"AYUDA");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando le mostrara un pequeคo resumen de como poder manejar los    ");
			       gotoxy(2,25);
			       cprintf(" menus colgantes y como escoger una opciขn en cualquiera de ellos.           ");
			       gotoxy(60,1);
			       break;
			     }

		    case 60:
			     {
			       ref1(60,WHITE,RED,"AYUDA");
			       ref2(70,10,RED,"SALIR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" Copyrigth (c) 1997 UDES   Valledupar.   Derechos reservados del Autor       ");
			       gotoxy(2,25);
			       cprintf(" Unica Versiขn  Diseคo: NILSON LAJUD IRIARTE Cod: 96131061 Ing de Sistemas ");
			       gotoxy(70,1);
			       break;
			     }

		    case 70:
			     {
			       ref1(70,WHITE,RED,"SALIR");
			       ref2(8,10,RED,"ADICIONAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
			       gotoxy(2,25);                                                                   
			       cprintf(" consultar, modificar, eliminar, grado interno y externo de un NODO.         ");
			       gotoxy(8,1);
			       break;
			     }
			      
			}

		     break;

		     }

	     case 75:
		      {
			switch(wherex())

			{
		      case 8:
			     {
			       ref1(8,WHITE,RED,"ADICIONAR");
			       ref2(70,10,RED,"SALIR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" Copyrigth (c) 1997 UDES   Valledupar.   Derechos reservados del Autor       ");
			       gotoxy(2,25);
			       cprintf(" Unica Versiขn  Diseคo: NILSON LAJUD IRIARTE Cod: 96131061 Ing de Sistemas ");
			       gotoxy(70,1);
			       break;
			     }

		     case 18:
			     {
			       ref1(20,WHITE,RED,"CONSULTAR");
			       ref2(8,10,RED,"ADICIONAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener la  facilidad   de poder adicionar        ");
			       gotoxy(2,25);
			       cprintf(" NODO en el arbol.                                                           ");
			       gotoxy(8,1);
			       break;
			     }

		     case 32:{
			       ref1(32,WHITE,RED,"ELIMINAR");
			       ref2(20,10,RED,"CONSULTAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener la facilidad de poder consultar           ");
			       gotoxy(2,25);
			       cprintf(" o verificar si existe este nodo en el arbol.                                ");
			       gotoxy(18,1);
			       break;
			     }

		     case 46:
			     {
			       ref1(46,WHITE,RED,"VISUALIZAR");
			       ref2(32,10,RED,"ELIMINAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando existe la opciขn de poder eliminar un nodo cualquiera       ");
			       gotoxy(2,25);
			       cprintf(" siempre y cuando exista en el arbol.                                        ");
			       gotoxy(32,1);
			       break;
			     }

		    case 60:
			     {
			       ref1(60,WHITE,RED,"AYUDA");
			       ref2(46,10,RED,"VISUALIZAR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando existen los diferentes metodos de recorrido de un arbol     ");
			       gotoxy(2,25);
			       cprintf(" y la visualizaciขn del mismo.                                               ");
			       gotoxy(46,1);
			       break;
			     }

		    case 70:
			     {
			       ref1(70,WHITE,RED,"SALIR");
			       ref2(60,10,RED,"AYUDA");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(5,YELLOW);
			       gotoxy(2,24);
			       cprintf(" En este comando le mostrara un pequeคo resumen de como poder manejar los    ");
			       gotoxy(2,25);                                                                        
			       cprintf(" menus colgantes y como escoger una opciขn en cualquiera de ellos.           ");
			       gotoxy(60,1);
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
		 case 8:
			 {
			   introducir();
			   window(1,1,80,25);
			   clrscr();
			   escribe_menu2();
			   break;
			 }

		 case 18:
			 {
			  consultar();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

		case 32:
			{
			  eliminar();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

	       case 46:
			{
			  menu3();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

	       case 60:
			{
			  ayuda();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

		case 70:{
			  salir();
			  break;
			}

		 }

	  }

    }

}


//--------------------------------------------------------------------------------


void main()
{
 _setcursortype(_NOCURSOR);
 grafo obj(NULL);
 obj.menut();
}