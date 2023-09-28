#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "iomanip.h"
#include "conio.h"
#include "io.h"
#include "dos.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#define escribir(i){cprintf("%s",vec[i]);}
#define mensa(men){printf("%s",men);};
#define go {gotoxy(1,24);}
#define ENTER 13
inline void colores(int x, int y){textcolor(x);textbackground(y);}
inline void pos (int x,int y){gotoxy(y,x);}
static char vec[6][13]={"Û","COLAS","BICOLAS","DOBLES","CIRCULAR","SALIR"};
char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È";
/*********************************************************************************/
int rr;
class listas
{
 struct info {
  long codigo;
  char nombre[20];
  struct info *d;
  struct info *i;
 };
 public:
  info  *pl,*pco,*pc,*fc,*pb,*fb,*nn,*p,*q,*r,*fn;
  long cod1,cod_alumno;
  int i,x,f2,x2,f,f1,c,n,sw;
  int existe,u,k,r1;
  char opcion,seguir,elimina,adiciona,elim;
  char opciones[20][55],tecla,nombre[20],vec[5][22];
  void cuadro(int x1, int y1, int x2, int y2, char a1[20],char a2[20],char a3[20],char a4[20],char a5[20],char a6[20]);
  void boli(int fi,int ff,int ci,int cf);
  void centraM(char men[],int f);
  void piso();
  void menu1();
  int menu2();
  void mensaje(char men[45]);
  long valcod(int x,int y,int z,int a);
  void valdatos(int x,int y,int z,char nom[20], int a);
  void proc_listas_dobles();
  void inicializar();
  void inicio();
  void proc_colas();
  void proc_bicolas();
  void proc_listas_circulares();
  listas()
  {
  pl=NULL;
  pl->d=NULL;
  pl->i=NULL;
  pco=NULL;
  pco->d=NULL;
  pco->i=NULL;
  pc=NULL;
  pc->d=NULL;
  pc->i=NULL;
  fc=NULL;
  fc->d=NULL;
  fc->i=NULL;
  fb=NULL;
  fb->d=NULL;
  fb->i=NULL;
  pb=NULL;
  pb->d=NULL;
  pb->i=NULL;
  k=0;
 };
};
//*****************************************************************
//INICILAIZAR PUNTEROS
void listas::inicializar()
{
 k=0;
}
//*****************************************************************
//CUADROS
/*void parcial::cuadro(int C1,int F1,int C2,int F2)
{
 for(i=C1+1;i<C2;i++){
 gotoxy(i,F1);cprintf("Í");delay(1.8);gotoxy(i,F2);cprintf("Í");delay(1.8);}
 for(i=F1+1;i<F2;i++){
 gotoxy(C1,i);cprintf("º");delay(1.8); gotoxy(C2,i);cprintf("º");delay(1.8);}
 gotoxy(C1,F1);cprintf("É");
 gotoxy(C1,F2);cprintf("È");
 gotoxy(C2,F1);cprintf("»");
 gotoxy(C2,F2);cprintf("¼");
} */
//*****************************************************************
//MENSAJE MENU
menuH(int f)
{
 int i, r,j1=f;
 char tecla;
 do
 {
  r=2;
  textbackground(0);
  for(i=0;i<6;i++)
  {
   if (i==j1)
   {
    textcolor(1);
    textbackground(7);
    gotoxy(2+r,4);escribir(i);
   }
   else
   {
    textcolor(0);textbackground(11);
    gotoxy(2+r,4);escribir(i);}
    r+=13;
    textcolor(3);
   }
   switch(j1)
   {
    case 0:go;mensa("                                                   ");
	   go;mensa("OPCION DEL MENU PRINCIPAL");
		 break;
    case 1:go;mensa("                                                   ");
    go;mensa("MODULO PROCEDIMIENTO MANEJO DE COLAS");
		 break;
    case 2: go;mensa("                                                   ");
    go;mensa("MODULO PROCEDIMIENTO MANEJO BICOLA");
		 break;
    case 3:go;mensa("                                                   ");
    go;mensa("MODULO PROCEDIMIENTO MANEJO LISTAS DOBLES");
		 break;
    case 4:go;mensa("                                                   ");
    go;mensa("MODULO PROCEDIMIENTO MANEJO LISTAS CIRCULARES");
		 break;
    case 5:go;mensa("                                                   ");
    go;mensa("SALIR DEL PROGRAMA");
		 break;
   }
   tecla=getch();
   if (tecla==77 )
   {
    if (j1<5)  j1++;
    else j1=0;
   }
   if (tecla==75)
   {
    if (j1!=0) j1--;
    else j1=5;
   }
  }while (tecla!=ENTER);
  return(j1);
 }
//*****************************************************************
//MENSAJE PROCEDIMIENTOS
void listas::mensaje(char men[45])
{
 textbackground(0);window(1,1,80,25);
 window(15,23,65,23);textbackground(0);clrscr();
 cout<<men;
 textbackground(0);window(1,1,80,25);
}
//*****************************************************************
void listas::valdatos(int x,int y,int z,char nom[20],int a)
{
 do
 {
  textbackground(1);window(x,y,z,y);
  if (a==0) clreol();
  gets(nom);
  for (i=0; i<strlen(nom); i++)
  {
   nom[i] = toupper(nom[i]);
  }
  n=strlen(nom);
  if((n=strlen(nom))>20)
  {
   mensaje("DIGITE NOMBRE DE LA CIUDA MAX 20 CARCATERES");
  }
  if ((n=strlen(nom))==0)
  {
   if (a==0)
   {
    mensaje("DIGITE LA INFORMACION SOLICITADA");
    n=25;
   }else break;
  }
 }while(n>20);
 if ((a==1)&&(n==0)) strcpy(nombre,p->nombre);
}
//VALIDA CODIGO ALUMNO
long listas::valcod(int x,int y,int z,int a)
{
 char cod[8];
 n=0;i=0;
 do
 {
  do
  {
   textbackground(1);window(x,y,z,y);
   if (a==0) clreol();
   gets(cod);n=strlen(cod);
   if ((n<=0)||(n>8))
   {
    mensaje("CODIGO INVALIDO! INGRESE VALORES 8 CARACTERES");
   }
  }while((n<=0)||(n>8));sw=0;
  for(i=0;i<n;i++) if(isdigit(cod[i])==0) sw=1;
  if(sw==1)
  {
   mensaje("CODIGO INVALIDO! DIGITE VALORES NUMERICOS");
  }
  else
  {
   cod_alumno=atol(cod);
   if (cod_alumno==0)
   {
    sw=1;
    mensaje("POR FAVOR DIGITE EL DATO SOLICITADO");
   }
  }
 }while(sw==1);
 return(cod_alumno);
}
//PROCEDIMIENTO LISTAS DOBLEMENTE ENLAZADAS
void listas::proc_listas_dobles()
{
 do
 {
  window(11,7,60,15);textcolor(15);
  textbackground(0); clrscr();
  mensaje("CODIGO DEL ALUMNO");
  gotoxy(15,8);cprintf("CODIGO ALUMNO    :");
  window(37,8,44,8);textbackground(1);clrscr();cod1=valcod(37,8,44,0);
  textbackground(0);window(1,1,80,25);
  //VALIDAR EXISTENCIA CODIGO
  q=NULL;
  p=pl;
  while (p!=NULL)
  {
   if (cod1==p->codigo) {break;}
   q=p;
   p=p->d;
  }
  if (cod1==p->codigo)
  {
   existe=0;
   gotoxy(15,10);cprintf("NOMBRE           :");
   window(37,10,57,10);textbackground(1);clrscr();cout<<p->nombre;
   //validar
   mensaje("SI DESEA MODIFIQUE EL NOMBRE Y OPRIMA ENTER");
   window(37,10,57,10);textbackground(1);valdatos(37,10,57,nombre,1);
   textbackground(0);window(1,1,80,25);
  }
  else
  {
    window(11,7,60,15);
   existe=1;
   mensaje("NOMBRE DEL ALUMNO");
   gotoxy(15,10);cprintf("NOMBRE           :");
   window(37,10,57,10);textbackground(1);clrscr();valdatos(37,10,57,nombre,0);
   textbackground(0);window(1,1,80,25);
  }
  //MENU OPEACIONES
  if (existe==1)
  {
   window(11,7,60,15);
   textcolor(10);gotoxy(2,8);
   cprintf("[1] GRABAR   [2] SALIR");
   textcolor(15);
   mensaje("ESCOJA UNA OPCIONCORRECTA");
   do
   {
    window(11,7,60,15);
    opcion=getche();
    //ADICONAR UNNODO A LA LISTA DOBLE
    if (opcion=='1')
    {
     nn=new info;
     nn->d=NULL;
     nn->i=NULL;
     p=pl;
     if(pl==NULL)
     {
      pl=nn;
      p=pl;
     }
     else
     {
      if (cod1<pl->codigo)
      {
       nn->d=pl;
       pl->i=nn;
       pl=nn;
       p=pl;
      }
      else
      {
       while ((cod1>p->codigo)&&(p->d!=NULL))
       {
	q=p;
	p=p->d;
       }
       if (cod1<p->codigo)
       {
	nn->d=p;
	p->i=nn;
	q->d=nn;
	nn->i=q;
	p=nn;
       }
       else
       {
	p->d=nn;
	nn->i=p;
	p=p->d;
       }
      }
     }
     nn->codigo=cod1;
     strcpy(nn->nombre,nombre);
     mensaje("UN MOMENTO .....");
     delay(2000);opcion='2';seguir='N';
    }
    else
    {
     if (opcion=='2')
     {
      seguir='N';
     }
     else
     {
      mensaje("ESCOJA UNA OPCION");
     }
    }
   }while (opcion!='2');
  }
  else
  {
   window(11,7,60,15);
   textcolor(10);gotoxy(2,8);
   cprintf("[1] GRABAR  [2] ELIMINAR [3] SALIR");
   textcolor(15);
   mensaje("ESCOJA UNA DE LAS OPCIONES");
   do
   {
    opcion=getche();
    //MODIFICANOMBRE DELALUMNO
    if (opcion=='1')
    {
     strcpy(p->nombre,nombre);
     mensaje("UN MOMENTO.....");
     delay(2000);opcion='3';seguir='S';
    }
    else
    {
     //ELIMINAR UNAINFORMACIONDE LA LISTA DOBLE
     if (opcion=='2')
     {
      mensaje("DESEA ELIMINAR EL REGISTRO S/N");
      elimina=toupper(getche());
      if (elimina=='S')
      {
       if (q==NULL)
       {
	pl=NULL;
       }
       else
       {
	r=p->d;
	r->i=q;
	q->d=r;
	p->d=NULL;
	p->i=NULL;
       }
       delete (p);
       mensaje("UN MOMENTO . . . . ");
       delay(2500);
      }
      opcion='3';seguir='N';
     }
     else
     {
      if (opcion=='3')
      {
       seguir='N';
      }
      else
      {
       mensaje("ESCOJA UNA OPCION CORRECTA");
      }
     }
    }
   }while (opcion!='3');
  }
 }while (seguir!='N');
 clrscr();window(1,1,80,25);textbackground(0);clrscr();
}
//LISTAS ENLAZADAS CIRCULARES
void listas::proc_listas_circulares()
{
 do
 {
  window(11,7,60,15);textcolor(15);
  textbackground(0); clrscr();
  mensaje("CODIGO DEL ALUMNO");
  gotoxy(15,8);cprintf("CODIGO ALUMNO    :");
  window(37,8,44,8);textbackground(1);clrscr();cod1=valcod(37,8,44,0);
  textbackground(0);window(1,1,80,25);
  //VALIDAR EXISTENCIA CODIGO
  q=NULL;
  p=pc;
  while (p->d!=pc)
  {
   if (cod1==p->codigo) {break;}
   q=p;
   p=p->d;
  }
  if (cod1==p->codigo)
  {
   existe=0;
   gotoxy(15,10);cprintf("NOMBRE           :");
   window(37,10,57,10);textbackground(1);clrscr();cout<<p->nombre;
   //validar
   mensaje("SI DESEA MODIFIQUE EL NOMBRE Y OPRIMA ENTER");
   window(37,10,57,10);textbackground(1);valdatos(37,10,57,nombre,1);
   textbackground(0);window(1,1,80,25);
  }
  else
  {
   existe=1;
   mensaje("NOMBRE DEL ALUMNO");
   gotoxy(15,10);cprintf("NOMBRE           :");
   window(37,10,57,10);textbackground(1);clrscr();valdatos(37,10,57,nombre,0);
   textbackground(0);window(1,1,80,25);
  }
  //MENU OPEACIONES
  window(11,7,60,15);
  if (existe==1)
  {
   window(11,7,60,15);
   textcolor(10);gotoxy(2,8);
   cprintf("[1] GRABAR  [2] SALIR ");
   textcolor(15);
   mensaje("ESCOJA UNA OPCION");
   do
   {
    window(11,7,60,15);
    opcion=getche();
    if (opcion=='1')
    {
     nn=new info;
     nn->d=NULL;
     nn->i=NULL;
     p=pc;
     if(pc==NULL)
     {
      pc=nn;
      pc->d=pc;
      pc->i=pc;
      p=pc;
      fn=pc;
     }
     else
     {
      if (cod1<pc->codigo)
      {
       if(fn==pc)
       {
	pc->d=nn;
	nn->i=pc;
	nn->d=pc;
	fn->i=nn;
	pc=nn;
       }
       else
       {
	nn->d=pc;
	nn->i=fn;
	fn->d=nn;
	pc->i=nn;
	pc=nn;
       }
      }
      else
      {
       while ((cod1>p->codigo)&&(p->d!=pc))
       {
	q=p;
	p=p->d;
       }
       if (cod1<p->codigo)
       {
	nn->d=p;
	p->i=nn;
	q->d=nn;
	nn->i=q;
	p=nn;
       }
       else
       {
	p->d=nn;
	nn->i=p;
	nn->d=pc;
	pc->i=nn;
	fn=nn;
       }
      }
     }
     nn->codigo=cod1;
     strcpy(nn->nombre,nombre);
     mensaje("UN MOMENTO .....");
     delay(2000);opcion='2';seguir='N';
    }
    else
    {
     if (opcion=='2')
     {
      seguir='N';
     }
     else
     {
      mensaje("ESCOJA UNA OPCION CORRECTA");
     }
    }
   }while (opcion!='2');
  }
  else
  {
    window(11,7,60,15);
   textcolor(10);gotoxy(2,8);
   cprintf("[1]GRABAR  [2] ELIMINAR  [3] SALIR");
   textcolor(15);
   mensaje("ESCOJA UNA DE LAS OPCIONES");
   do
   {
    opcion=getche();
    if (opcion=='1')
    {
     strcpy(p->nombre,nombre);
     mensaje("UN MOMENTO .....");
     delay(2000);opcion='3';seguir='N';
    }
    else
    {
     if (opcion=='2')
     {
      mensaje("DESEA ELIMINAR EL REGISTRO S/N");
      elimina=toupper(getche());
      if (elimina=='S')
      {
       if (q==NULL)
       {
	if(pc==fn)
	{
	 p->d=NULL;
	 p->i=NULL;
	}
	else
	{
	 r=pc->d;
	 fn->d=r;
	 r->i=fn;
	 pc=r;
	 p->d=NULL;
	 p->i=NULL;
	}
       }
       else
       {
	r=p->d;
	r->i=q;
	q->d=r;
	p->d=NULL;
	p->i=NULL;
       }
       delete (p);
       mensaje("UN MOMENTO . . . . ");
       delay(2500);
      }
      opcion='3';seguir='N';
     }
     else
     {
      if (opcion=='3')
      {
       seguir='N';
      }
      else
      {
       mensaje("ESCOJA UNA OPCION");
      }
     }
    }
   }while (opcion!='3');
  }
 }while (seguir!='N');
 clrscr();window(1,1,80,25);textbackground(0);clrscr();
}
//MANEJO DE COLAS
void listas::proc_colas()
{
 do
 {
  window(11,7,60,15);textcolor(15);
  textbackground(0); clrscr();
  existe=-1;
  textcolor(15);gotoxy(2,8);
  cprintf("   [1] INSERTAR    [2] ELIMINAR ");
  textcolor(15);
  mensaje("ESCOJA UN OPCION");
  do
  {
   window(11,7,60,15);
   gotoxy(2,20);opcion=getche();
   if (opcion=='1')
   {
    gotoxy(70,22);cout<<"  ";
    existe=0;
    mensaje("CODIGO DEL ALUMNO");
    gotoxy(15,8);cprintf("CODIGO ALUMNO    :");
    window(37,8,44,8);textbackground(1);clrscr();cod1=valcod(37,8,44,0);
    textbackground(0);window(1,1,80,25);
    mensaje("NOMBRE DEL ALUMNO");
    gotoxy(15,10);cprintf("NOMBRE           :");
    window(37,10,57,10);textbackground(1);clrscr();valdatos(37,10,57,nombre,0);
    textbackground(0);window(1,1,80,25);
   }
   else
   {
    if (opcion=='2')
    {
     gotoxy(70,22);cout<<"  ";
     if (pco==NULL)
     {
      mensaje("NO SE PUEDE ELIMINAR");
      existe=3;
     }
     else
     {
      existe=1;
      textbackground(0);window(1,1,80,25);
      gotoxy(15,8);cprintf("CODIGO A ELIMINAR :");
      window(37,8,44,8);textbackground(1);clrscr();cout<<fc->codigo;
      textbackground(0);window(1,1,80,25);
      gotoxy(15,10);cprintf("NOMBRE           :");
      window(37,10,57,10);textbackground(1);clrscr();cout<<fc->nombre;
     }
    }
    else
    {
     gotoxy(70,22);cout<<"  ";
     mensaje("ESCOJA LA OPCION CORRECTA");
     opcion='3';seguir='S';
    }
   }
   //MENU OPEACIONES
   if (existe==0)
   {
    nn=new info;
    nn->d=NULL;
    nn->i=NULL;
    if(pco==NULL)
    {
     pco=nn;
     fc=pco;
    }
    else
    {
     nn->d=pco;
     pco->i=nn;
     pco=nn;
    }
    nn->codigo=cod1;
    strcpy(nn->nombre,nombre);
    mensaje("UN MOMENTO .....");
    delay(2000);seguir='N';opcion='3';
   }
   else
   {
    if (existe==1)
    {
     mensaje("DESEA ELIMINAR DE LA COLA S/N");
     elimina=toupper(getche());
     if (elimina=='S')
     {
      if (pco==fc)
      {
       p=pco;
       pco=NULL;
       fc=NULL;
      }
      else
      {
       p=fc;
       fc=fc->i;
       fc->d=NULL;
      }
      delete (p);
      mensaje("UN MOMENTO . . . . ");
      delay(2500);
     }
     seguir='N';opcion='3';
    }
   }
  }while (opcion!='3');
 }while (seguir!='N');
 clrscr();window(1,1,80,25);textbackground(0);clrscr();
}
//MANEJO DE BICOLAS
void listas::proc_bicolas()
{
 do
 {
  window(11,7,60,15);textcolor(15);
  textbackground(0); clrscr();
  existe=-1;
  textcolor(15);gotoxy(2,8);
  cprintf("   [1] INSERTAR    [2] ELIMINAR ");
  textcolor(15);
  mensaje("ESCOJA UN OPCION");
  do
  {
   window(11,7,60,15);
   gotoxy(70,22);opcion=getche();
   if (opcion=='1')
   {
    gotoxy(70,22);cout<<"  ";
    existe=0;
    mensaje("CODIGO DEL ALUMNO");
    gotoxy(15,8);cprintf("CODIGO ALUMNO    :");
    window(37,8,44,8);textbackground(1);clrscr();cod1=valcod(37,8,44,0);
    textbackground(0);window(1,1,80,25);
    mensaje("NOMBRE DEL ALUMNO");
    gotoxy(15,10);cprintf("NOMBRE           :");
    window(37,10,57,10);textbackground(1);clrscr();valdatos(37,10,57,nombre,0);
    textbackground(0);window(1,1,80,25);
   }
   else
   {
    if (opcion=='2')
    {
     gotoxy(70,22);cout<<"  ";
     if (pb==NULL)
     {
      mensaje("NO HAY INFORMACION PARA ELIMINAR");
      existe=3;
     }
     else
     {
      existe=1;
      sw=0;
      do
      {
       mensaje("DESEA ELIMINAR  I:INICIO F:FINAL?");
       elim=toupper(getche());
       if (elim=='I')
       {
	textbackground(0);window(1,1,80,25);
	gotoxy(15,8);cprintf("CODIGO A ELIMINAR :");
	window(37,8,44,8);textbackground(1);clrscr();cout<<pb->codigo;
	textbackground(0);window(1,1,80,25);
	gotoxy(15,10);cprintf("NOMBRE           :");
	window(37,10,57,10);textbackground(1);clrscr();cout<<pb->nombre;
	sw=1;
       }
       else
       {
	if (elim=='F')
	{
	 textbackground(0);window(1,1,80,25);
	 gotoxy(15,8);cprintf("CODIGO A ELIMINAR :");
	 window(37,8,44,8);textbackground(1);clrscr();cout<<fb->codigo;
	 textbackground(0);window(1,1,80,25);
	 gotoxy(15,10);cprintf("NOMBRE           :");
	 window(37,10,57,10);textbackground(1);clrscr();cout<<fb->nombre;
	 sw=1;
	}
	else
	{
	 mensaje("ESCOJA ELIMINAR I:INICIO  F:FINAL ?");
	}
       }
      }while(sw!=1);
     }
    }
    else
    {
     if (opcion=='3')
     {
      seguir='N';
     }
     else
     {
      gotoxy(70,22);cout<<"  ";
      mensaje("ESCOJA UNA OPCION");
      opcion='3';seguir='N';
     }
    }
   }
   //MENU OPEACIONES
   if (existe==0)
   {
    nn=new info;
    nn->d=NULL;
    nn->i=NULL;
    if(pb==NULL)
    {
     pb=nn;
     fb=pb;
    }
    else
    {
     sw=0;
     do
     {
      mensaje("DESEA INSERTAR  I:INICIO F:FINAL?");
      adiciona=toupper(getche());
      if (adiciona=='I')
      {
       nn->d=pb;
       pb->i=nn;
       pb=nn;
       sw=1;
      }
      else
      {
       if (adiciona=='F')
       {
	nn->i=fb;
	fb->d=nn;
	fb=nn;
	sw=1;
       }
       else
       {
	mensaje("ADICIONAR I:INICIO  F:FINAL ?");
       }
      }
     }while(sw!=1);
    }
    nn->codigo=cod1;
    strcpy(nn->nombre,nombre);
    mensaje("UN MOMENTO .....");
    delay(2000);seguir='N';opcion='3';
   }
   else
   {
    if (existe==1)
    {
     mensaje("DESEA ELIMINAR DE LA COLA S/N");
     elimina=toupper(getche());
     if (elimina=='S')
     {
      if (pb==fb)
      {
       p=pb;
       pb=NULL;
       fb=NULL;
      }
      else
      {
       if (elim=='I')
       {
	p=pb;
	pb=pb->d;
	pb->i=NULL;
       }
       else
       {
	if (elim=='F')
	{
	 p=fb;
	 fb=fb->i;
	 fb->d=NULL;
	}
       }
      }
      delete (p);
      mensaje("UN MOMENTO . . . . ");
      delay(2500);
     }
     seguir='N';opcion='3';
    }
   }
  }while (opcion!='3');
 }while (seguir!='N');
 clrscr();window(1,1,80,25);textbackground(0);clrscr();
}
//***************************************************
void listas::boli(int fi,int ff,int ci,int cf)
{ int i,j;
  for(i=fi;i<=ff;i++)
  { for(j=ci;j<=cf;j++)
   { gotoxy(j,i);cprintf(" ");}}
}
//***************************************************
void listas::centraM(char men[],int f)
{ int lon,col;
  lon=strlen(men);
  col=(80-lon)/2;
  gotoxy(col,f);cprintf("%s",men);
}
//***************************************************
void listas::cuadro(int x1, int y1, int x2, int y2, char a1[20],char a2[20],char a3[20],char a4[20],char a5[20],char a6[20])
{
 int i;
   for(i=x1;i<=x2;i++)
     { gotoxy(y1,i);cprintf(a1);
       gotoxy(y2,i);cprintf(a1);}
     for(i=y1;i<=y2;i++)
     { gotoxy(i,x1);cprintf(a2);
       gotoxy(i,x2);cprintf(a2);}
       gotoxy(y1,x1);cprintf(a3);
       gotoxy(y2,x2);cprintf(a4);
       gotoxy(y2,x1);cprintf(a5);
       gotoxy(y1,x2);cprintf(a6);
}
//***************************************************
void listas::piso()
{ int u;
  for (u=5;u<23;u++)
   { gotoxy(3,u);
     textcolor(1);
     cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   }
}
//***************************************************
void listas::inicio()
{
 do
 { clrscr();
  textcolor(5);
  cuadro(3,1,23,80,a1,a2,a3,a4,a5,a6);
  textbackground(11);
  textcolor(9);
  boli(1,1,1,80);
  centraM("CORPORACION UNIVERSITARIA DE SANTANDER",1);
  textbackground(4);
  boli(2,2,1,80);
  centraM("20%ESTRUCTURA DE DATOS -MANEJO DE LISTAS",2);
  textbackground(4);
  boli(24,24,1,80);
  textbackground(11);
  boli(4,4,2,79);
  piso();
 rr=menuH(0);
   switch(rr){
     case 0:break;
     case 1:proc_colas();break;
     case 2:proc_bicolas();break;
     case 3:proc_listas_dobles();break;
     case 4:proc_listas_circulares();break;
     case 5:break;
    }
 } while (rr!=5);
}
//***************************************************
void main()
{
 listas obj;
 obj.inicio();
}
