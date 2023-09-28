
//trespa

#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include "fcntl.h"
#include<process.h>
#include "iostream.h"
#include "io.h"
void reset();

/**********************************************************************/
class base
{
  struct arbol
  { int info;
    char ruta;
    char costo[9];
    char distancia[10];
    char time[10];
    struct arbol *izquier,*derech;
  };
 public:
 int sw;
  char costo[9],distancia[10],time[10],op;
  xy(int x, int y);
  void comv(int x,char vector[2]);
  base(struct arbol *c);
  void clav();
  void cuadro_2();
  void cuadro();
  int clave();
  void lee_nom(int x,int y,char *ruta);
  void imprimir(struct arbol *a);
  void imprime_arbin(struct arbol *a,int x1,int y1, int n, int j);
  void calcula_pos(int q, int w, int *e, int *r);
  void vis_preorden(struct arbol *aux);
  void vis_posorden(struct arbol *aux);
  void vis_inorden(struct arbol *aux);
  void lee_cod(int x,int y,char *costo);
  void mensaje(int x,int y,int opK,char *p);
  void val_cod();
  void valida();
  void introducir();
  void eliminar();
  void menu();
  void consulta();
  void lindo (int piso,int color);
  char ve[3];
  //char op;
  struct arbol *cabeza,*nn,*p;

};

/**********************************************************************/
void base::cuadro_2()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
errorcode = graphresult();
if (errorcode != grOk)  /* an error
    occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error
	       code */
}
setbkcolor(7);
setcolor(YELLOW);
rectangle(getmaxx()-0,getmaxy()-0,0,0);
setcolor(RED);
rectangle(getmaxx()-1,getmaxy()-1,1,1);
setcolor(GREEN);
settextstyle(0,0,3);
outtextxy(130,35,"'SOTFWARE ARBOLES BINARIOS'");
setcolor(RED);
settextstyle(0,0,4);
outtextxy(160,235,"HILDA PAOLA MOLINA");
setcolor(MAGENTA);
settextstyle(0,0,4);
outtextxy(160,235,"HILDA PAOLA MOLINA");

}
/**********************************************************************/
void base::cuadro()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
errorcode = graphresult();
if (errorcode != grOk)  /* an error
    occurred */
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1); /* terminate with an error
	       code */
}
setbkcolor(7);
setcolor(5);
setfillstyle(9, 5);
bar(getmaxx()-20,getmaxy()-60,60,20);
setcolor(11);
setfillstyle(SOLID_FILL, 11);
bar(getmaxx()-30,getmaxy()-50,30,30);
setcolor(WHITE+5);
settextstyle(2,0,8);
outtextxy(130,35,"LISTAS DE RUTAS MUNICIPALES");

setcolor(WHITE+10);
settextstyle(0,0,0);
outtextxy(200,90, "0.VALLEDUPAR");
outtextxy(200,120,"1.LA PAZ");
outtextxy(200,150,"2.PAILITAS");
outtextxy(200,180,"3.CODAZZI");
outtextxy(200,210,"4.BOSCONIA");
outtextxy(200,240,"5.CHIMICHAGUA");
outtextxy(200,270,"6.BECERRIL");
outtextxy(200,300,"7.CHIRIGUANA");
outtextxy(200,330,"8.LA GLORIA");
outtextxy(200,360,"9.EL BURRO");
/*outtextxy(200,290,"11.GONZALES");
outtextxy(200,310,"12.PUEBLO BELLO");
outtextxy(200,330,"13.SAN DIEGO");
outtextxy(200,350,"14.CURUMANI");
outtextxy(200,370,"15.MANAURE");
outtextxy(200,390,"16.LA JAGUA");
outtextxy(200,410,"17.RIO DE ORO");*/

setfillstyle(SOLID_FILL,BLACK+8);
bar(getmaxx()-20,getmaxy()-15,40,435);
setfillstyle(SOLID_FILL,11);
bar(getmaxx()-30,getmaxy()-10,30,440);

while(!kbhit())
{
setcolor(RED);
settextstyle(3,0,2);
outtextxy(50,440,"ESCOJA EL Nø DE ACUERDO A LAS RUTAS MUNICIPALES");
delay(90);
setcolor(WHITE);
settextstyle(3,0,2);
outtextxy(50,440,"ESCOJA EL Nø DE ACUERDO A LAS RUTAS MUNICIPALES");
delay(90);

}
getch();
closegraph();

}
/**********************************************************************/

void base::lindo (int piso,int color)
      {
	textbackground (piso);
	textcolor (color);
      }

/**********************************************************************/

void base::val_cod()
{  p=cabeza;
  sw=0;
   while(p!=NULL)
     { if(!strcmp(costo,p->costo)) { sw=1; break; }
       p=p->derech;
       p=p->izquier;
     }
}


/**********************************************************************/
void base::introducir()
{
  char op,inform[3],inform1[3],inform2[3],inform3[3];
  int info,i,a,b,c;
    char ruta[15];
    char costo[9];
    char distancia[10];
    char time[10];
  lindo(4,0);
  window(1,1,80,25);
  clrscr();
  a=b=c=i=0;
  gotoxy(20,3);printf("­ INTRODUCCION DE DATOS !");

  gotoxy(10,10);printf("DIGITE EL CODIGO-RUTA[1...9] : ");
/*       mensaje(4,2,1,"digite su ruta: ");
       lee_nom(40,16,ruta);
  window(13,4,65,10);
       gotoxy(14,5); printf("%s",ruta);*/
  lindo(11,1);
  window(45,10,46,10);
  clrscr();
  do
  { gotoxy(i+1,1);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=1;
    else
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<1);
  inform[i]='\0';
  info=atoi(inform);

/*    if((info>17)||(info<0))
    {
    sw=1;
    gotoxy(i+1,1);clreol();
    gotoxy(20,20);printf(" !!! FUERA DE RANGO !!!");
    }
    clrscr();*/

  window(1,1,80,25);
  p=nn=cabeza;
  i=1;
  while((info!=p->info)&&(nn!=NULL)&&(i<=6))
  { p=nn;
    if(info<p->info)
      nn=p->izquier;
    else
      nn=p->derech;
    i++;
  }
  if(info==p->info)
    {
    gotoxy(20,12);printf(" ­0j0!..CODIGO EXISTENTE !");}
  else


   if(i==6)
     {gotoxy(14,12);printf("­ EL CODIGO DIGITADO NO SE PUEDE INTRODUCIR !");}

   else
   {

  gotoxy(10,12);printf("DIGITE COSTO RUTA: ");
  lindo(11,1);
  window(45,12,50,12);
  clrscr();
  do
  {
    gotoxy(a+1,1);clreol();
    costo[a]=getche();
    if(costo[a]=='\b'&&a>0) a-=1;
    else if(!isdigit(costo[a])) a--;
    a++;
  }while(a<5);
 costo[a]='\0';
  window(1,1,80,25);

  gotoxy(10,14);printf("DIGITE DISTANCIA[ Kmtrs ]: ");
  lindo(11,1);
  window(45,14,49,14);
  clrscr();
  do
  {
    gotoxy(a+1,1);clreol();
    distancia[b]=getche();
    if(distancia[b]=='\b'&&b>0) b-=1;
    else if(!isdigit(distancia[b])) b--;
    b++;
  }while(b<3);
 distancia[b]='\0';
  window(1,1,80,25);

  gotoxy(10,16);printf("DIGITE TIEMPO[ Horas ]: ");
  lindo(11,1);
  window(45,16,47,16);
  clrscr();
  do
  {
    gotoxy(a+1,1);clreol();
    time[c]=getche();
    if(time[c]=='\b'&&c>0) c-=1;
    else if(!isdigit(time[c])) c--;
    c++;
  }while(c<1);
 time[c]='\0';
  window(1,1,80,25);

     nn=new arbol;
     nn->info=info;
     strcpy(nn->costo,costo);
     strcpy(nn->distancia,distancia);
     strcpy(nn->time,time);
     nn->izquier=nn->derech=NULL;
     if(cabeza==NULL)
       cabeza=nn;
     else
     { if(info<p->info)
	p->izquier=nn;
       else
	p->derech=nn;
     gotoxy(20,19);printf("ADICIONADO !!");
     }
   }
 gotoxy(17,21);printf("DESEA INGRESAR OTRO CODIGO [S/N]: ");
 window(50,21,52,21);clrscr();
 do{
     gotoxy(1,1);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') introducir();
}

/**********************************************************************/

void base::vis_inorden(struct arbol *aux)

{
  lindo(4,0);

if(aux!=NULL)
  { vis_inorden(aux->izquier);
    printf("%d\t",aux->info);
    vis_inorden(aux->derech);
  }
}

/**********************************************************************/

void base::vis_preorden(struct arbol *aux)
{
  lindo(4,0);
if(aux!=NULL)
  {
    printf("%d\t",aux->info);
    vis_preorden(aux->izquier);
    vis_preorden(aux->derech);
  }
}

/**********************************************************************/

void base::vis_posorden(struct arbol *aux)
{
  lindo(4,0);
if(aux!=NULL)
  { vis_posorden(aux->izquier);
    vis_posorden(aux->derech);
    printf("%d\t",aux->info);
  }
}

/**********************************************************************/

void base::eliminar()
{
  char op,inform[3];
  int info,i;
  struct arbol *q,*s,*f;
  lindo(4,0);
  window(1,1,80,25);
  clrscr();
  i=0;
  printf("INGRESE El COD A ELIMINAR[1...9]: ");
  lindo(7,1);
  window(35,1,36,1);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=1;
    else
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<1);
  inform[i]='\0';
  info=atoi(inform);
  window(1,1,80,25);
  f=NULL;
  p=nn=cabeza;
  while((info!=p->info)&&(nn!=NULL))
  { f=p;
    p=nn;
    if(info<p->info)
      nn=p->izquier;
    else
      nn=p->derech;
  }
  if(info!=p->info)
    printf("\nEL CODIGO DIGITADO NO EXISTE !");
  else
  {
   if(p->izquier==NULL)
      nn=p->derech;
    else
      if(p->derech==NULL)
	nn=p->izquier;
      else
      { q=p;
	nn=q->derech;
	s=nn->izquier;
	while(s!=NULL)
	{ q=nn;
	  nn=s;
	  s=nn->izquier;
	}
	if(q!=p)
	{ q->izquier=nn->derech;
	  nn->derech=p->derech;
	}

	nn->izquier=p->izquier;
      }
      if(f==NULL)
	cabeza=nn;
      else
	{ if(p==f->izquier) f->izquier=nn;
	  else f->derech=nn;
	}
    p->izquier=p->derech=NULL;
    free(p);
 gotoxy(10,15);printf("!!! ELIMINACION EXITOSA !!!  ");
  }
 gotoxy(17,21);printf("DESEA ELIMINAR OTRO CODIGO [S/N]: ");
 window(50,21,52,21);clrscr();
 do{
     gotoxy(1,1);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') eliminar();
}


/**********************************************************************/
void base::consulta()
{
 char op,inform[3];
  int info,i;
  struct arbol *q,*s,*f;
  lindo(4,0);
  window(1,1,80,25);
  clrscr();
  i=0;
  printf("INGRESE El COD A CONSULTAR[1...9]: ");
  lindo(7,1);
  window(35,1,36,1);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=1;
    else
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<1);
  inform[i]='\0';
  info=atoi(inform);
  window(1,1,80,25);
  f=NULL;
  p=nn=cabeza;
  while((info!=p->info)&&(nn!=NULL))
  { f=p;
    p=nn;
    if(info<p->info)
      nn=p->izquier;
    else
      nn=p->derech;
  }
  if(info!=p->info)
    printf("\nEL CODIGO DIGITADO NO EXISTE !");
  else
  {
/*   if(p->izquier==NULL)
      nn=p->derech;
    else
      if(p->derech==NULL)
	nn=p->izquier;
      else
      { q=p;
	nn=q->derech;
	s=nn->izquier;
	while(s!=NULL)
	{ q=nn;
	  nn=s;
	  s=nn->izquier;
	}
	if(q!=p)
	{ q->izquier=nn->derech;
	  nn->derech=p->derech;
	}

	nn->izquier=p->izquier;
      }
      if(f==NULL)
	cabeza=nn;
      else
	{ if(p==f->izquier) f->izquier=nn;
	  else f->derech=nn;
	}
    p->izquier=p->derech=NULL;*/

//     window(13,4,65,10);
     gotoxy(2,5); printf("%s",p->info);
     gotoxy(14,5); printf("%s",p->costo);
     gotoxy(32,5); printf("%s",p->distancia);
     gotoxy(50,5); printf("%s",p->time);
    }
  gotoxy(15,20);printf("!!! CONSULTA EXITOSA !!!  ");
 gotoxy(17,21);printf("DESEA CONSULTAR OTRO CODIGO [S/N]: ");
 window(50,21,52,21);clrscr();
 do{
     gotoxy(1,1);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S')
 consulta();
}

/**********************************************************************/

base::xy(int x, int y)
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

/**********************************************************************/

void base::calcula_pos(int q, int w, int *e, int *r)
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

/**********************************************************************/

void base::imprime_arbin(struct arbol *a,int x1,int y1, int n, int j)
  { int nn,jj;
	 setbkcolor(YELLOW);
    calcula_pos(n, j, &nn, &jj);
     if (a!=NULL)
       { if((x1!=0)&&(y1!=0))
	 //setcolor(RED+YELLOW);
	 line((x1+.3)*7.9875,(y1+.75)*19.16,nn*7.9875,(jj-.75)*19.16);
	 setcolor(RED);
	 circle((nn+.3)*7.9875,jj*19.16,14);
	 floodfill((nn+.3)*7.9875,jj*19.16,RED);
	 comv(a->info,ve);
	 if(strlen(ve)==1)
	  outtextxy((nn-.1)*7.9875,(jj-.15)*19.16,ve);
	 else
	  outtextxy((nn-.47)*7.9875,(jj-.15)*19.16,ve);
	 x1=nn;y1=jj;
	 imprime_arbin(a->izquier,x1,y1,n+1,j*2-1);
	 imprime_arbin(a->derech,x1,y1,n+1,j*2);
       }
//	 cuadro_2();
   }


/**********************************************************************/

void base::imprimir(struct arbol *a)
  { int z,zz;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    setcolor(getmaxcolor());
    z=0;
    zz=1;
    imprime_arbin(a,0,0,z,zz);
    //cuadro_2();
    getch();
    closegraph();

  }

/**********************************************************************/

void base::comv(int x,char vector[3])
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
void base::menu()
{ char c[35],op;int n,i;

do{

 lindo(1,RED);
 window(1,1,80,25);
// cuadro_2();
 textbackground(1);clrscr();
 textcolor(14);
 strcpy(c,"               ARBOLES BINARIOS  ");
 n=strlen(c);
 for(i=0;i<n;i++){
 gotoxy(18+i,7);cprintf("%c",c[i]);delay(30);}

  textcolor(WHITE);
  delay(30);gotoxy(28,9); cprintf("1. Codigos De Las Rutas Municipales  ");
  delay(30);gotoxy(28,10);cprintf("2. Introducir Codigo_Ruta  ");
  delay(30);gotoxy(28,11);cprintf("3. Visualizacion Recorrido Pre-orden");
  delay(30);gotoxy(28,12);cprintf("4. Visualizacion Recorrido In-orden");
  delay(30);gotoxy(28,13);cprintf("5. Visualisaci¢n Recorrido Post-orden");
  delay(30);gotoxy(28,14);cprintf("6. Visualizaci¢n del  rbol");
  delay(30);gotoxy(28,15);cprintf("7. Consulta");
  delay(30);gotoxy(28,16);cprintf("8. Eliminacion Del Codigo_Ruta");
  delay(30);gotoxy(28,17);cprintf("9. ¨ Salir De La Aplicaci¢n ?");
  delay(30);gotoxy(19,19);cprintf(" DIGITE LA OPCION :  ");
  do
  {
   gotoxy(39,19);clreol(); op=getch();
  }while((op>'9') ||(op<'1'));
   switch(op){
   case'1':cuadro();break;
   case'2':introducir();break;
   case'3':clrscr(); vis_preorden(cabeza); getche(); break;
   case'4':clrscr(); vis_inorden(cabeza); getche(); break;
   case'5':clrscr(); vis_posorden(cabeza); getche(); break;
   case'6':clrscr(); imprimir(cabeza); break;
   case'7':clrscr(); consulta();getche(); break;
   case'8':eliminar();break;
   case'9':exit(0);
  }
}while(op!='9');
}

/**********************************************************************/
base::base(struct arbol *c)
{ cabeza=c; }


/**********************************************************************/

int base::clave()
      { char Key,Letras[10];
	  int  c,Conteo=0,Swiche=0;
	  c=22;
	  do{   Conteo++;
	  gotoxy(c,3);Key=tolower(getch());textcolor(YELLOW);cprintf("*");
	  if(Conteo==1 && Key=='t')Swiche++;
	  if(Conteo==2 && Key=='r')Swiche++;
	  if(Conteo==3 && Key=='e')Swiche++;
	  if(Conteo==4 && Key=='s')Swiche++;
	  if(Conteo==5 && Key=='p')Swiche++;
	  if(Conteo==6 && Key=='a')Swiche++;
	  c++;
	  }while(Conteo<=10 && Swiche<=5);
	  return(Swiche);
      }


void reset()
{union REGS nt,salida;
int86(0X19,&nt,&salida);
}
void base::clav()
{   int cont=0;
  do{window(1,1,80,25);textbackground(0);
  cont++;
       clrscr();
	//cuadro_2();
       window(20,10,60,15);textbackground(1);clrscr();
       window(20,11,60,15);textbackground(7);clrscr();
       textcolor(0);
       gotoxy(10,10);gotoxy(5,3);cprintf("P A S S W O R D:[      ]");
       gotoxy(27,10);
 if(clave()==6)
		{

		  menu();
		  //PoP_PoP();
		  cont=7;
		}
       else{
	     window(20,10,60,15);textbackground(1);clrscr();
	     window(20,11,60,15);textbackground(7);clrscr();
	     gotoxy(2,3);
	     textcolor(0);
	     cprintf("<<<ACCESO DENEGADO CLAVE INCORRECTA>>>");
	     delay(1500);
	     sound(500);
	     delay(1500);
	  }nosound();
  }while(cont<3);
reset();
}

void main()
{ base obj(NULL);
    //obj.cuadro_2();
    obj.clav();
    //obj.cuadro();
    //obj.menu();
}
