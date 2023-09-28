#include<graphics.h>
#include "fcntl.h"
#include<process.h>
#include "iostream.h"
#include "io.h"
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<dos.h>

class YURLIS_SUGEU
	  {
		struct arbol
				 {
				 int Ruta;
				 char costo[5];
				 char X_Kmtr[5];
				 char Tiempo[4];
				 struct arbol *izq,*der;
  };

 public:
  struct arbol *raiz,*nn,*p;
  char ve[3];
  char costo[9],X_Kmtr[10],Tiempo[10],op;
  int sw;
  xy(int x, int y);
  void lista();
  void MENUCITO();
  void INFO();
  void eliminar();
  void consultar();
  void comv(int x,char vector[2]);
  YURLIS(struct arbol *c);
  void vis_preorden(struct arbol *I);
  void vis_posorden(struct arbol *I);
  void vis_inorden(struct arbol *I);
  void VISU(struct arbol *a);
  void VISU_arbin(struct arbol *a,int x1,int y1, int n, int j);
  void DETERMINA(int I, int w, int *e, int *r);

};

void main()
{

	 YURLIS_SUGEU SUGE;
	 SUGE.MENUCITO();
}


YURLIS_SUGEU::xy(int x, int y)
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


void YURLIS_SUGEU::DETERMINA(int I, int w, int *e, int *r)
  {
	 if (I==4)
		 if (w % 2 != 0)
	  *e=2 + (w / 2 ) * 10;
		 else
	  *e=8 + (w / 2 - 1) * 10;
	 else
		 *e=80 / xy(2,I+1)+(w-1)*2*(80 / xy(2,I+1));
	 *r=I*4+2;
  }

/**********************************************************************/

void YURLIS_SUGEU::VISU_arbin(struct arbol *a,int x1,int y1, int n, int j)
  { int nn,jj;
	;
	 DETERMINA(n, j, &nn, &jj);
	  if (a!=NULL)
		 { if((x1!=0)&&(y1!=0))
	 line((x1+.3)*7.9875,(y1+.75)*19.16,nn*7.9875,(jj-.75)*19.16);
	  setcolor(RED);
	 circle((nn+.3)*7.9875,jj*19.16,14);
	 floodfill((nn+.3)*7.9875,jj*19.16,RED);
	 comv(a->Ruta,ve);
	 if(strlen(ve)==1)
	  outtextxy((nn-.1)*7.9875,(jj-.15)*19.16,ve);
	 else
	  outtextxy((nn-.47)*7.9875,(jj-.15)*19.16,ve);
	 x1=nn;y1=jj;
	 VISU_arbin(a->izq,x1,y1,n+1,j*2-1);
	 VISU_arbin(a->der,x1,y1,n+1,j*2);
		 }
	}


/**********************************************************************/

void YURLIS_SUGEU::VISU(struct arbol *a)
  { int z,zz;
	 int gdriver = DETECT, gmode, errorcode;
	 initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
		z=0;
		zz=1;
	 VISU_arbin(a,0,0,z,zz);

	 getch();
	 closegraph();

  }

/**********************************************************************/

void YURLIS_SUGEU::comv(int x,char vector[3])
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

/**********************************************************************/
void YURLIS_SUGEU::MENUCITO()
{
  op;
 int n,i;
clrscr();
do{
clrscr();

gotoxy(28,7); printf("MENU PRINCIPAL");
gotoxy(29,9); printf("1. TABLA DE INFO");
gotoxy(29,10);printf("2. ADICION ");
gotoxy(29,11);printf("3. RECORRIDO PRE_ORDEN");
gotoxy(29,12);printf("4. RECORRIDO IN_ORDEN");
gotoxy(29,13);printf("5. RECORRIDO POS_ORDEN");
gotoxy(29,14);printf("6. VISUALIZACION ");
gotoxy(29,15);printf("7. CONSULTA");
gotoxy(29,16);printf("8. ELIMINACION ");
gotoxy(29,17);printf("9. ¨ EXIT... ?");
gotoxy(20,18);printf(" DIGITE OPCION :  ");
  do
  {
  op=getch();
  }while((op>'9') ||(op<'1'));
	switch(op){
	case'1':lista();break;
	case'2':clrscr();INFO();break;
	case'3':clrscr(); vis_preorden(raiz); getche(); break;
	case'4':clrscr(); vis_inorden(raiz); getche(); break;
	case'5':clrscr(); vis_posorden(raiz); getche(); break;
	case'6':clrscr(); VISU(raiz); break;
	case'7':clrscr(); consultar();getche(); break;
	case'8':eliminar();break;
	case'9':exit(0);
  }
}while(op!='9');
}
YURLIS_SUGEU::YURLIS(struct arbol *c)
  {
	raiz=c;
		}


/*****************************/

void YURLIS_SUGEU::lista()
{
 clrscr();
 gotoxy(28,5);printf("LISTAS DE MUNICIPIOS\n");
gotoxy(28,8);printf("0.VALLEDUPAR\n");
gotoxy(28,9);printf("1.LA PAZ\n");
gotoxy(28,10);printf("2.MANAURE\n ");
gotoxy(28,11);printf("3.SAN DIEGO\n ");
gotoxy(28,12);printf("4.CODAZZI \n");
gotoxy(28,13);printf("5.BECERRIL \n");
gotoxy(28,14);printf("6.LA JAGUA\n");
gotoxy(28,15);printf("7.CHIRIGUANA\n");
gotoxy(28,16);printf("8.CURUMANI\n ");
gotoxy(28,17);printf("9.CHIMICHAGUA\n ");
gotoxy(28,18);printf("10.GONZALES\n");
gotoxy(28,19);printf("11.EL BURRO \n");
gotoxy(28,20);printf("12.LA GLORIA\n");
gotoxy(28,21);printf("13.PAILITAS \n");
gotoxy(28,22);printf("14.BOSCONIA\n");
gotoxy(28,23);printf("15.PUEBLO BELLO\n");
gotoxy(28,24);printf("16.RIO DE ORO\n");
gotoxy(28,25);printf("17.SAN ALBERTO\n");
getch();

}
/**********************************************************************/


void YURLIS_SUGEU::INFO()
	 {
	 int Ruta,i,a,b,c;
	 char costo[5];
	 char X_Kmtr[5];
	 char Tiempo[4];
	 char op,inform[3];

  clrscr();
  a=0;
  b=0;
  c=0;
  i=0;
  gotoxy(10,10);printf("Digite El Codigo   [1...17] : ");
  do
  {
	 inform[i]=getche();
	 if(inform[i]=='\b'&&i>0) i-=2;
	 else
	  { if(inform[i]=='\r'&&i>0) break;
		 if(!isdigit(inform[i])) i--;
	  }
	 i++;
  }while(i<2);
  inform[i]='\0';
  Ruta=atoi(inform);
  p=nn=raiz;
  i=1;
  while((Ruta!=p->Ruta)&&(nn!=NULL)&&(i<=6))
  { p=nn;
	 if(Ruta<p->Ruta)
		nn=p->izq;
	 else
		nn=p->der;
	 i++;
  }
  if(Ruta==p->Ruta)
	 {
	 gotoxy(20,12);printf(" CODIGO EXISTE ");}
  else


	if(i==6)
	  {gotoxy(14,12);printf("EL CODIGO NO SE PUEDE INTRODUCIR ");}

	else
	{

  gotoxy(10,12);printf("DIGITE COSTO: ");
  do
  {
	 costo[a]=getche();
	 if(costo[a]=='\b'&&a>0) a-=1;
	 else if(!isdigit(costo[a])) a--;
	 a++;
  }while(a<5);
 costo[a]='\0';
 gotoxy(10,14);printf("DIGITE DISTANCIA: ");
  do
  {
	 X_Kmtr[b]=getche();
	 if(X_Kmtr[b]=='\b'&&b>0) b-=1;
	 else if(!isdigit(X_Kmtr[b])) b--;
	 b++;
  }while(b<3);
 X_Kmtr[b]='\0';

  gotoxy(10,16);printf("DIGITE TIEMPO: ");
  do
  {
	 Tiempo[c]=getche();
	 if(Tiempo[c]=='\b'&&c>0) c-=1;
	 else if(!isdigit(Tiempo[c])) c--;
	 c++;
  }while(c<1);
 Tiempo[c]='\0';

	  nn=new arbol;
	  nn->Ruta=Ruta;
	  strcpy(nn->costo,costo);
	  strcpy(nn->X_Kmtr,X_Kmtr);
	  strcpy(nn->Tiempo,Tiempo);
	  nn->izq=nn->der=NULL;
	  if(raiz==NULL)
		 raiz=nn;
	  else
	  { if(Ruta<p->Ruta)
	p->izq=nn;
		 else
	p->der=nn;
	  }
	}
 gotoxy(17,21);printf("DESEA INGRESAR OTRO CODIGO [S/N]: ");
 do{
	op=toupper(getche());
	}while(op!='S'&&op!='N');
 if(op=='S')
 INFO();
}
/****************************/

void YURLIS_SUGEU::vis_inorden(struct arbol *I)

{
if(I!=NULL)
  { vis_inorden(I->izq);
	 printf("%d\t",I->Ruta);
	 vis_inorden(I->der);
  }
}

/******************************/

void YURLIS_SUGEU::vis_preorden(struct arbol *I)
{
if(I!=NULL)
  {
	 printf("%d\t",I->Ruta);
	 vis_preorden(I->izq);
	 vis_preorden(I->der);
  }
}
/*************************************/

void YURLIS_SUGEU::vis_posorden(struct arbol *I)
{
if(I!=NULL)
  { vis_posorden(I->izq);
	 vis_posorden(I->der);
	 printf("%d\t",I->Ruta);
  }
}
/********************************/

void YURLIS_SUGEU::consultar()
{
 char op,inform[3];
  int Ruta,i;
  struct arbol *I,*s,*f;
	clrscr();
  i=0;
  printf("INGRESE EL CODIGO A CONSULTAR [1...9]: ");
  do
  {
	 inform[i]=getche();
	 if(inform[i]=='\b'&&i>0) i-=1;
	 else
	  { if(inform[i]=='\r'&&i>0) break;
		 if(!isdigit(inform[i])) i--;
	  }
	 i++;
  }while(i<1);
  inform[i]='\0';
  Ruta=atoi(inform);
  p=nn=raiz;
  while((Ruta!=p->Ruta)&&(nn!=NULL))
  {
	 p=nn;
	 if(Ruta<p->Ruta)
		nn=p->izq;
	 else
		nn=p->der;
  }
  if(Ruta!=p->Ruta)
	 printf("\n NO EXISTE ");
  else
  {
	  gotoxy(2,5);printf("%s",p->Ruta);
	  gotoxy(14,5);printf("%s",p->costo);
	  gotoxy(32,5);printf("%s",p->X_Kmtr);
	  gotoxy(50,5);printf("%s",p->Tiempo);
	 }
 gotoxy(17,21);printf("QUIERE CONSULTAR OTRO CODIGO [S/N]: ");
 do{
	  op=toupper(getche());
	}while(op!='S'&&op!='N');
 if(op=='S')
 consultar();
}
/***************************/

void YURLIS_SUGEU::eliminar()
{
  char op,inform[3];
  int Ruta,i;
  struct arbol *I,*s,*f;
  clrscr();
  i=0;
  printf("DIGITE EL CODIGO A ELIMINAR[1...17]: ");
  do
  {
	 inform[i]=getche();
	 if(inform[i]=='\b'&&i>0) i-=1;
	 else
	  { if(inform[i]=='\r'&&i>0) break;
		 if(!isdigit(inform[i])) i--;
	  }
	 i++;
  }while(i<1);
  inform[i]='\0';
  Ruta=atoi(inform);
  f=NULL;
  p=nn=raiz;
  while((Ruta!=p->Ruta)&&(nn!=NULL))
  { f=p;
	 p=nn;
	 if(Ruta<p->Ruta)
		nn=p->izq;
	 else
		nn=p->der;
  }
  if(Ruta!=p->Ruta)
	 printf("\nNO EXISTE ");
  else
  {
	if(p->izq==NULL)
		nn=p->der;
	 else
		if(p->der==NULL)
	nn=p->izq;
		else
		{ I=p;
	nn=I->der;
	s=nn->izq;
	while(s!=NULL)
	{ I=nn;
	  nn=s;
	  s=nn->izq;
	}
	if(I!=p)
	{ I->izq=nn->der;
	  nn->der=p->der;
	}

	nn->izq=p->izq;
		}
		if(f==0)
	raiz=nn;
		else
	{ if(p==f->izq) f->izq=nn;
	  else f->der=nn;
	}
	 p->izq=p->der=0;
	 free(p);
 gotoxy(10,17);printf("ELIMINADO !  ");
  }
 gotoxy(17,21);printf("DESEA ELIMINAR OTRO CODIGO [S/N]: ");
 do{
	  op=toupper(getche());
	}while(op!='S'&&op!='N');
 if(op=='S') eliminar();
}


