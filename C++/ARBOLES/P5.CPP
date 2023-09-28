#include "conio.h"
#include "stdio.h"
#include"stdlib.h"
#include"alloc.h"
#include"string.h"
#include"ctype.h"
#include"graphics.h"
#include"dos.h"
typedef struct ARBOL ARBOL;
/*************************************************************************/
struct ARBOL {
	int info;
	char nombre[50];
	char apellido[50];
	ARBOL *izq;
	ARBOL *der;
      };
/*************************************************************************/
 ARBOL *raiz;
 void menu();
 void pisos();
 void pantalla();
 char vector[3];
 int elimine_arbol (int);
 int xy(int x,int y);
 int ingrese_arbol (int);
 void menu_recorridos();
 void inorden(ARBOL *);
 void preorden(ARBOL *);
 void postorden(ARBOL *);
 void comv(int x,char dalila[3]);
 void elimina_nodo (ARBOL *,ARBOL *);
 void graficar_arbol(ARBOL *arco);
 void ventana(int X1,int Y1,int X2,int Y2);
 void espacio(int q,int w,int *e,int *r);
 void crear();void visualizar();void eliminar();
 void dibujar_ramas( ARBOL *arco,int x1,int y1,int n,int j);
/****************************************************************************/
  void crear()
  {
   char Inf[3],op;
   int i=0,info,sw=0;
   do
   {
    clrscr();textcolor(15);ventana(5,3,76,24);
    gotoxy(26,5);printf(">>>>> DATOS  PERSONALES <<<<<");
    i=0;
    gotoxy(8,8);cprintf("No. DE CODIGO:  ");
    do
    {
     gotoxy(i+23,8);clreol();Inf[i]=getche();
      if(Inf[i]=='\b'&&i>0) i-=2;
       else
       {
	if(Inf[i]=='\r'&&i>0) break;
	 if(!isdigit(Inf[i])) i--;
       }
	 i++;
    }while(i<2);
      Inf[i]='\0';
      info=atoi(Inf);
      if(info>=0&&info<=99)
      {
       if(ingrese_arbol(info)==-1)
       {
	textcolor(14+128);gotoxy(30,18);cprintf("­­­­­ YA EXISTE ­­­­­");
	 getche();
       }
	else
	{
	 gotoxy(19,15);printf(">>>> DATOS INGRESADOS  ¯ PRESS ENTER ®  <<<<");
	 getche();
	}
     }
     do
     {
      sw=0;
      gotoxy(27,23);printf("DESEA INGRESAR OTRO DATO [S/N]: ");
      op=toupper(getch());
      if(op=='N'||op=='S')
      {
       sw=1;putchar(op);delay(500);
      }
     }while(sw!=1);
  }while(op!='N');
}
/****************************************************************************/
  ARBOL *buscar_arbol(int n,ARBOL *p,ARBOL *q) 
  {
   if(p==NULL)
   return q;
   if(n<p->info)
   {
    q=p;
    q=buscar_arbol(n,p->izq,q);
    return q;
   }
    else
     if(n>p->info)
     {
      q=p;
      q=buscar_arbol(n,p->der,q);
      return q;
     }
     else
     return NULL;
  }
/*************************************************************************/
  int ingrese_arbol(int n) 
  {
   ARBOL *q;ARBOL *nuevo;
   char nombre[50];
   char apellido[50];
   gotoxy(8,10);cprintf("INGRESE EL NOMBRE: ");
   scanf("\n");gets(nombre);
   gotoxy(8,12);cprintf("INGRESE EL APELLIDO: ");
   scanf("\n");gets(apellido);
   if(raiz==NULL)
   {
     raiz=(struct ARBOL * )malloc(sizeof(ARBOL));
     raiz->info=n;
     strcpy(raiz->nombre,nombre);
     strcpy(raiz->apellido,apellido);
     raiz->izq=raiz->der = NULL;
     return 0;
   }
     q=buscar_arbol(n,raiz,NULL);
     if(q==NULL)
      return -1;
      nuevo=(struct ARBOL * )malloc(sizeof(ARBOL));
      nuevo->info=n;
      strcpy(nuevo->nombre,nombre);
      strcpy(nuevo->apellido,apellido);
      nuevo->izq=nuevo->der=NULL;
      if(n<q->info)
       q->izq=nuevo;
       else 
       q->der=nuevo;
       return 0;
  }
/*************************************************************************/
  void elimina_nodo (ARBOL *q,ARBOL *p) 
  {
   ARBOL *r,*s,*t;
   if(p->izq==NULL)
    r=p->der;
    else
    if(p->der==NULL)
     r=p->izq;
     else
     {
      s=p; r=p->der; t=r->izq;
      while(t!=NULL)
      {
	s=r; r=t; t=t->izq;
      }
      if(p!=s)
      {
	s->izq=r->der;
	r->der=p->der;
      }
	r->izq=p->izq;
    }
     if(q==NULL)
      raiz=r;
      else
       if(p==q->izq)
       q->izq=r;
       else
       q->der=r;
       free(p);
  } 
/*************************************************************************/
  ARBOL *buscar(int n,ARBOL **p,ARBOL *q) 
  {
   if(*p==NULL)
   return NULL;
    if(n<(*p)->info)
    {
     q=*p; *p=(*p)->izq; q=buscar(n,p,q);
      return q;
    }
     else
     if(n>(*p)->info)
     {
      q=*p; *p=(*p)->der;
      q=buscar(n,p,q);
      return q;
     }
      else
       return q;
  }
/*************************************************************************/
  int elimine_arbol (int n) 
  {
   ARBOL *q,*p=raiz;
   q=buscar(n,&p,NULL);
   if(p==NULL)
    return -1;
    elimina_nodo(q,p);
    return 0;
  }
/*************************************************************************/
  void eliminar()
  { 
   char Inf[3],op;
   int i=0,sw=0,info;
   do
   {
    clrscr();textcolor(15);ventana(5,3,76,24);
    gotoxy(24,5);printf(">>>>> DATOS  PERSONALES  A  ELIMINAR <<<<<");
    gotoxy(8,10);cprintf( "INGRESE No. DE CODIGO: ");
    i=0;
    do
    {
     gotoxy(i+31,10);clreol();
     Inf[i]=getche();
     if(Inf[i]=='\b'&&i>0) i-=2;
     else 
     {
      if(Inf[i]=='\r'&&i>0) break;
       if(!isdigit(Inf[i])) i--;
     }
       i++;
   }while(i<2);
    Inf[i]='\0'; info=atoi(Inf);
     if(info>=0&&info<=99)
     {
      if(elimine_arbol(info)==-1)
      {
      textcolor(14+128);gotoxy(30,18);cprintf("!!!!! NO EXISTE !!!!!");
       getch();
     }
     else
     {
      gotoxy(25,15);cprintf(">>>>> CODIGO ELIMINADO <<<<<");
      getch();
     }
   }
    do
    {
     sw=0;gotoxy(27,23);printf("DESEA ELIMINAR OTRO DATO [S/N]: ");
     op=toupper(getch());
     if(op=='N'||op=='S')
     {
      sw=1;putchar(op);delay(500);
     }
    }while(sw!=1);
  } while(op!='N');
 }
/*************************************************************************/
  void inorden(ARBOL *p) 
  {
   int fill;
   if(p!=NULL)
   {
    textcolor(15);ventana(5,3,76,24);
    gotoxy(23,8);printf("No. CODIGO      NOMBRE      APELLIDO");
    fill=10;
    inorden(p->izq);
    gotoxy(27,fill);printf("%d\n",p->info,p->info);
    gotoxy(39,fill);printf("%s\t\n",p->nombre,p->nombre);
    gotoxy(51,fill);printf("%s\t\n",p->apellido,p->apellido);
    textcolor(14+128);gotoxy(32,23);cprintf("###### ENTER ######");
    getch();
    inorden (p->der);
    fill++;
     }
 } 
/*************************************************************************/
  void preorden(ARBOL *p) 
  {
   int fill;
   if(p!=NULL)
   {
    textcolor(15);ventana(5,3,76,24);
    gotoxy(23,8);printf("No. CODIGO      NOMBRE      APELLIDO");
    fill=10;
    gotoxy(27,fill);printf("%d\n",p->info,p->info);
    gotoxy(39,fill);printf("%s\t\n",p->nombre,p->nombre);
    gotoxy(51,fill);printf("%s\t\n",p->apellido,p->apellido);
    textcolor(14+128);gotoxy(32,23);cprintf("###### ENTER ######");
    getch();
    fill++;
    preorden(p->izq);
    preorden(p->der);
     }
 }
/*************************************************************************/
  void postorden(ARBOL *p) 
  {
   int fill;
   if(p!=NULL)
   {
    textcolor(15);ventana(5,3,76,24);
    gotoxy(23,8);printf("No. CODIGO      NOMBRE      APELLIDO");
    fill=10;
    postorden(p->izq);
    postorden(p->der);
    gotoxy(27,fill);printf("%d\n",p->info,p->info);
    gotoxy(39,fill);printf("%s\t\n",p->nombre,p->nombre);
    gotoxy(51,fill);printf("%s\t\n",p->apellido,p->apellido);
    textcolor(14+128);gotoxy(32,23);cprintf("###### ENTER ######");
    getch();
    fill++;
     }
 }
/*************************************************************************/
  int xy(int x, int y)
  {
   int k;
   if(y==0)
   return(1);
   else{
   for(k=1;k<y;k++)
    x=x*2;return(x);
   }
 }
/**************************POSECIONA EL NUMERO******************************/
  void espacio(int q,int w,int *e,int *r)
  {
   if(q==4)
   if(w%2!=0)
    *e=2+(w/2)*10;
    else
    *e=8+(w/2-1)*10;
    else
    *e=80/xy(2,q+1)+(w-1)*2*(80/xy(2,q+1));
    *r=q*4+2;
  }
/*******************************DIBUJA EL RABOL*****************************/
  void dibujar_rama(ARBOL *arco,int x1,int y1,int n,int j)
  {
   char ve[3];
   int nn,jj,as;
   espacio(n,j,&nn,&jj);
   setcolor(3);
   outtextxy(100,450,"       G R A F I C A   D E L   A R B O L       ");
   ventana(1,1,78,25);
   if(arco!=NULL)
   {
    if((x1!=0)&&(y1!=0))
    line((x1+.3)*7.9875,(y1+.75)*19.16,nn*7.9875,(jj-.75)*19.16);
    circle((nn+.3)*7.9875,jj*19.16,14);
    comv(arco->info,vector);
    if(strlen(vector)==1)
    outtextxy((nn-.1)*7.9875,(jj-.15)*19.16,vector);
    else
    outtextxy((nn-.47)*7.9875,(jj-.15)*19.16,vector);
    x1=nn;y1=jj;
    dibujar_rama(arco->izq,x1,y1,n+1,j*2-1);
    dibujar_rama(arco->der,x1,y1,n+1,j*2);
   }
  }
/******************************DIBUJA EL ARBOL******************************/
  void graficar_arbol(ARBOL *arco)
  {
   int s,e;
   int gdriver=DETECT,gmode,errorcode; 
   initgraph(&gdriver,&gmode,"..\\bgi");
   s=0; e=1; 
   dibujar_rama(arco,0,0,s,e);
   getch();
   closegraph();
 }
/*************************************************************************/
  void comv(int x,char dalila[3])
  {
   int as;
   if(x>9){
   as=(x/10);
   dalila[0]=as+'0';
   as=(x%10);
   dalila[1]=as+'0';
   dalila[2]='\0';
  }
   else{
   dalila[0]=x+'0';
   dalila[1]='\0';
  }
}	 
/*************************************************************************/
  void piso()
  {
  int u;
  for(u=4;u<22;u++)
  {
   gotoxy(3,u);textcolor(15);
   textbackground(1);
   cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²ÛÛÛÛÛÛÛÛÛÛÛÛ");
   gotoxy(u,4);
   cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
   gotoxy(4,21);
   cprintf("ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ");
  }
}
/**************************************************************************/
  void menu_recorridos()
  {
   char op;
   do{
      clrscr();ventana(3,4,78,20);piso();
		 gotoxy(27,8);printf("    MENU RECORRIDOS    ");
		 gotoxy(34,10);printf(" 1.IN_ORDEN      ");
		 gotoxy(34,11);printf(" 2.POST_ORDEN    ");
		 gotoxy(34,12);printf(" 3.PRE_ORDEN     ");
		 gotoxy(34,13);printf(" 4.VOLVER AL MENU");
		 gotoxy(33,16);cprintf(" DIGITE OPCION [ ] ");
		 gotoxy(49,16); op=getch();
		 switch (op){
       case '1':{clrscr();ventana(25,4,55,6);gotoxy(30,5);printf("RECORRIDO  IN_INORDE");
		 inorden(raiz);getch();break;
      }
       case '2':{clrscr();ventana(25,4,55,6);gotoxy(30,5);printf("RECORRIDO  POST_ORDEN");
		 postorden(raiz);getch();break;
	       }
      case '3':{clrscr();ventana(25,4,55,6);gotoxy(30,5);printf("RECORRIDO  PRE_ORDEN");
		 preorden(raiz);getch();break;
	       }
	   }
      }while(op!='4');
   }
/****************************************************************************/
  void visualizar()
  {
   graficar_arbol(raiz);
  }
/***************************************************************************/
  void main() 
  {
   menu();
  }
/****************************************************************************/
  void ventana(int X1,int Y1,int X2,int Y2)
  {
   int i;
    for(i=X1+1;i<X2;i++){
     gotoxy(i,Y1);printf("Í"); 
     gotoxy(i,Y2);printf("Í");} 
    for(i=Y1+1;i<Y2;i++){
     gotoxy(X1,i);printf("º");   
     gotoxy(X2,i);printf("º");}  
     gotoxy(X1,Y1);printf("É");
     gotoxy(X1,Y2);printf("È");
     gotoxy(X2,Y1);printf("»");
     gotoxy(X2,Y2);printf("¼");
  }
/****************************************************************************/
   void pantalla()
   { 
    textcolor(13);delay(40);ventana(1,3,80,22);
   }
/****************************************************************************/
   void menu()
   {
    pantalla();
    clrscr();
    ventana(28,6,50,15);pisos();
    int n,j,tecla,f;
    char opciones[35][45];
    char helpline[35][45];
    clrscr();textbackground(1); 
    strcpy(opciones[10],"  CREAR  ARBOL        ");
    strcpy(opciones[11],"  VISUALIZAR ARBOL    ");
    strcpy(opciones[12],"  ELIMINAR ARBOL      ");
    strcpy(opciones[13],"  RECORRIDOS DEL ARBOL");
    strcpy(opciones[14],"  SALIR DEL SISTEMA  ");
    strcpy(helpline[10],"          CREAR INFORMACION       ");
    strcpy(helpline[11],"     VISUALIZA INFOR. EN EL ARBOL   ");
    strcpy(helpline[12],"          ELIMINA INFORMACION       ");
    strcpy(helpline[13],"         RECORRIDOS DEL ARBOL     ");
    strcpy(helpline[14],"         SALIR  DEL  SISTEMA      ");
    do
    {
     pisos();
     for(f=10;f<=14;f++)
     {
       textcolor(15);gotoxy(28,f);cprintf(opciones[f]);
     }
      f=10;textcolor(15);textbackground(1); 
		    gotoxy(28,f);cprintf(opciones[f]);
		    textcolor(15); textbackground(1);
     do
     { gotoxy(17,24);cprintf(helpline[f]);
      _setcursortype(_NOCURSOR);
     do
     {
      tecla=getch(); 
     }while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
     if(tecla==80)
     {
      gotoxy(17,24);cprintf(helpline[f]);
      _setcursortype(_NOCURSOR);
      textcolor(15);textbackground(1);
      gotoxy(28,f);cprintf(opciones[f]);
      if(f!=14)
      f=f+1;
      else
       f=10;
	textcolor(0);textbackground(11);
	gotoxy(28,f);cprintf(opciones[f]);
	textcolor(15);textbackground(1);
   }
      if(tecla==72)
      {
       textcolor(15);textbackground(1);
       gotoxy(28,f);cprintf(opciones[f]);
       gotoxy(17,24);cprintf(helpline[f]);
       textcolor(15);_setcursortype(_NOCURSOR);
       if(f!=10)
	f=f-1;
	else
	 f=14;
	textcolor(15);textbackground(1);gotoxy(28,f);cprintf(opciones[f]);
	textcolor(15);textbackground(1);
      }
   }while(tecla!=13);
     switch(f)
     {
       case 10:_setcursortype(_SOLIDCURSOR);
		      crear();pisos();break;
       case 11:_setcursortype(_SOLIDCURSOR);
		visualizar();pisos(); break;
       case 12:_setcursortype(_SOLIDCURSOR);
		  eliminar();pisos(); break;
       case 13:_setcursortype(_SOLIDCURSOR);
	    menu_recorridos();pisos();break;
       case 14:_setcursortype(_SOLIDCURSOR);break;
   }
 }while(f!=14);
} 
/****************************************************************************/
   void marco(int x1,int y1,int x2,int y2)
   {
    int n;
    textcolor(15);gotoxy(x1,y1);cprintf("%c",201); 
     gotoxy(x2,y1);cprintf("%c",187);   
     gotoxy(x1,y2);cprintf("%c",200);  
     gotoxy(x2,y2);cprintf("%c",188); 
   for(n=(x1+1);n<=(x2-1);n++)
   {
    gotoxy(n,y1);cprintf("%c",205);
    gotoxy(n,y2);cprintf("%c",205);
   } 
  for(n=(y1+1);n<=(y2-1);n++)
  {
    gotoxy(x1,n);cprintf("%c",186);
    gotoxy(x2, n);cprintf("%c",186);
 } 
}
/****************************************************************************/
   void pisos()
   { 
     int n,j;
     clrscr();
     textbackground(1);clrscr();
     for(n=2;n<=24;n++)
      gotoxy(20,4);textcolor(15);
      cprintf("        A R B O L E S        ");
      gotoxy(28,8);textcolor(15);cprintf(" MENU PRINCIPAL ");
      gotoxy(28,9);textcolor(15);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
      textcolor(14+128);gotoxy(14,19);
      cprintf("UTILICE LAS TECLAS DEL CURSOR  Y  PRESIONE ® ENTER ¯ ");  
      marco(26,7,53,16);marco(5,2,75,22);marco(9,5,70,20);marco(13,23,65,25);
   }
/****************************************************************************/
	

