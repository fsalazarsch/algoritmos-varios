#include <dos.h>
#include <string.h>
#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
class arbol
{
  struct nodo
  {
    int codigo;
    char nombre[20];
    struct nodo *izq;
    struct nodo *der;
  };

 public:
 char n[3],conv[10],nombre[20];
 char op;int i,sw,w;
 int num,fila;
 int r,colo;
 struct nodo *nn,*pos,*pad,*raiz,*t;
 void insertar();
 void f_l(int f,int l);
 void buscar();
 void borrar();
 void menu();
 arbol(nodo *nulo){raiz=nulo;}//constructor.
 void inorden_grafico(struct nodo *t);
 void posorden_grafico(struct nodo *t);
 void preorden_grafico(struct nodo *t);
 void mostrar(nodo *t,int x,int y,int f);
 void inorden(nodo *t);
 void cuad(int x1,int y1,int x2,int y2);
 void inicializa_inorden();
 void inicializa_postorden();
 void inicializa_preorden();
 void valida_codigo();
 char *valida_nombre();

};
////////////////////////////
void arbol::f_l(int f,int l)
{  textbackground(f);
   textcolor(l);
}
////////////////////////////
void arbol::buscar()
{
 if(raiz==NULL)//no,existe arbol
 {
  pos=NULL;
  pad=NULL;
 }
 else
 {
      if(num==raiz->codigo)
       {
	  pos=raiz;
	  pad=NULL;
       }
	 else
	    {
	      if(num < raiz->codigo)
	       {
		 pos=raiz->izq;
		 pad=raiz;
	       }
		 else
		 {
		   pos=raiz->der;
		   pad=raiz;
		  }
		   while(pos != NULL)
		    {
		       if(num==pos->codigo) break;
		       if(num < pos->codigo)
			 {
			      pad=pos;
			      pos=pos->izq;
			  }
			    else
			     {
			       pad=pos;
			       pos=pos->der;
			      }
		     }
	    }
 }
}
////////////////////////////
void arbol::insertar()
{

 do{ clrscr();
       cuad(2,1,79,25);
	window(25,4,51,6);f_l(0,14);clrscr();
	window(24,3,50,5);f_l(11,4);clrscr();
	gotoxy(1,2);cout<<"<< ADICION DE ELEMENTOS >>";
	window(1,1,80,25);
	f_l(1,14);
	valida_codigo();
 buscar();//busca el codigo dentro del arbol para saber si ya existe
 if (pos != NULL)
 {
  gotoxy(25,23);cout<<"!!! EL CODIGO YA EXISTE !!!";
  getch();
 }
 else
 {

  valida_nombre();
  nn=new nodo;
  if (pad==NULL)//es el primer nodo que se inserta
  {
   raiz = nn;
   raiz->codigo=num;
   strcpy(raiz->nombre,nombre);
   raiz->der=raiz->izq=NULL;
  gotoxy(40,8); cprintf("!!! ADICIONADO EN LA RAIZ !!!");
  }
  else
  {
   if (num < pad->codigo)
   {
    pad->izq=nn;
    pos=nn;
    pos->codigo=num;
   strcpy(pos->nombre,nombre);
    pos->der=pos->izq=NULL;
   gotoxy(40,8);cout <<"!!! ADICIONADO EN LA IZQUIERDA !!!";

   }
   else
   {
    pad->der=nn;
    pos=nn;
    pos->codigo=num;
    strcpy(pos->nombre,nombre);
    pos->der=pos->izq=NULL;
  gotoxy(40,8); cout <<"!!! ADICIONADO EN LA DERECHA !!!";
   }
  }
 }

gotoxy(16,23);cout<<"DESEA ADICIONAR OTRO ELEMENTO? [S/N]:";
	op=toupper(getche());
   }while(op=='S');
}
///////ELIMINAR//////////////////////
void arbol::borrar()
{
 char op;
 nodo *f,*rp,*s;


 do{clrscr();
       cuad(2,1,79,25);
	window(25,4,54,6);f_l(0,14);clrscr();
	window(24,3,53,5);f_l(11,4);clrscr();
	gotoxy(1,2);cout<<"<< ELIMINACION DE ELEMENTOS >>";
	window(1,1,80,25);
	f_l(1,14);
	valida_codigo();
	 buscar();

	  ////ELIMINACION////
   if(pos==NULL)
   { gotoxy(40,8);cout <<"!!!NO EXISTE ELEMENTO !!! ";}
   else
   { 	gotoxy(10,10);cout<<"NOMBRE : ";
	gotoxy(19,10);cout<<pos->nombre;
	gotoxy(40,8);cout <<"!!! ELEMENTO ELIMINADO !!! ";
		     if(pos->izq==NULL && pos->der==NULL)
		       {  if(pad==NULL)
			  raiz=NULL;
			  else
			    { if(pad->der==pos)
			      pad->der=NULL;
			       else
			       pad->izq=NULL;
			     }
		       }
		       else
		       {  if(pos->der!=NULL && pos->izq!=NULL)
			  { pad=pos; nn=pos->izq;
			    while(nn->der!=NULL)
			      { pad=nn;
				nn=nn->der;
			      }
			    pos->codigo=nn->codigo;
			    strcpy(pos->nombre,nn->nombre);
				 if(pad==pos)
				  { pad->izq=nn->izq;}
				     else
				     { pad->der=nn->izq;}
					pos=nn;
				   }
				    else
				     { if(pos->der!=NULL)
					  { if(pad==NULL)
					      raiz=pos->der;
					     else
					      { if(pos==pad->der)
						pad->der=pos->der;
						 else
						 pad->izq=pos->der;
					       }
					    }
					    else
					    { if(pad==NULL)
						raiz=pos->der;
					       else
						 { if(pos==pad->der)
						   pad->der=pos->izq;
						   else
						   pad->izq=pos->izq;
						  }
					     }
				      }
				 }
				 delete(pos);

    }
gotoxy(16,23);cout<<"DESEA ELIMINAR OTRO ELEMENTO? [S/N]:";
	op=toupper(getche());
   }while(op=='S');
}
//////////////////////////
char *arbol::valida_nombre()
{
	 do
	 {  sw=0;w=2;
	       gotoxy(10,10);
	       cout<<"DIGITE EL NOMBRE: ";window(27,10,60,10);
	       clreol();window(1,1,80,25);
	       gotoxy(28,10);scanf("\n");
	       gets(nombre);
		if (nombre[1]=='\x0') {w=1;}
		     for (i=0;i<w;++i)
		     {	if (!isalpha(nombre[i]))
			   {
			      sw=1;
			    }
		      }
	 }while(sw==1);
      return(strupr(nombre));

}
////////////////////////
void arbol::valida_codigo()
{
	 do{
	       sw=0;
	       w=2;
	       window(4,23,70,23);clreol();window(1,1,80,25);
	       gotoxy(10,8);
	       cout<<"DIGITE EL CODIGO: ";window(27,8,60,8);
	       clreol();window(1,1,80,25);
	       gotoxy(28,8);scanf("\n");
	       gets(n);
		if (n[1]=='\x0') {w=1;}
		     for (i=0;i<w;++i)
		     {	if (!isdigit(n[i]))
			   {
			      sw=1;
			    }
		      }
		num=atoi(n);
		 if (num < 0 || num >99)
		   {
		     gotoxy(25,23); cout <<"!!! CODIGO FUERA DE RANGO !!!";
		     getch();
		   }
	 }while(sw!=0 || num < 0 || num > 99);
}
////////////////////////////
void arbol::inorden(nodo *t)
{  if (t != NULL)
  {
   inorden(t->izq);
   gotoxy(35,fila);cprintf("%d",t->codigo);
   gotoxy(45,fila);cprintf("%s",t->nombre);fila++;
   inorden(t->der);
  }
}
/////////////////////////////
void arbol::inorden_grafico(nodo *t)
{ int x,y,f;
  if (t != NULL)
  {
   inorden_grafico(t->izq);
   setcolor(colo);
   delay(700);
   itoa(t->codigo,conv,10);
   outtextxy(r,w,conv);
   setcolor(GREEN);
   outtextxy(r+15,w,"/");r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }
   colo++;
   if(colo==15)colo=1;

   inorden_grafico(t->der);

  }


}
//////////////////////////////
void arbol::preorden_grafico(nodo *t)
{
 if (t != NULL)
 {
   setcolor(colo);delay(700);
   itoa(t->codigo,conv,10);
   outtextxy(r,w,conv);
   setcolor(GREEN);
   outtextxy(r+15,w,"/");r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }
   colo++;
   if(colo==15)colo=1;
  preorden_grafico(t->izq);
  preorden_grafico(t->der);
 }
}
////////////////////////////////////
void arbol::posorden_grafico(nodo *t)
{
 if (t != NULL)
 {
  posorden_grafico(t->izq);
  posorden_grafico(t->der);
   setcolor(colo);delay(700);
   itoa(t->codigo,conv,10);
   outtextxy(r,w,conv);
   setcolor(GREEN);
   outtextxy(r+15,w,"/");r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }
   colo++;
   if(colo==15)colo=1;

 }
}
////////////////////////////////////
void arbol::mostrar(nodo *t,int x,int y,int f)
{
  if(t!=NULL)
  {
     itoa(t->codigo,n,10);
     outtextxy(x-8,y-4,n);
     setcolor(5);
     circle(x,y,10);
     setcolor(15);
     if(t->izq!=NULL)
       line(x,y+10,x-f/2,(y+70)-10);
     if(t->der!=NULL)
     line(x,y+10,x+f/2,(y+70)-10);
     f=f/2;
     mostrar(t->izq,x-f,y+70,f);
     mostrar(t->der,x+f,y+70,f);
    }

}
/////////////////////////////////////////
void arbol::cuad(int x1,int y1,int x2,int y2)
{ int i;window(1,1,80,25);
  gotoxy(x1, y1); printf("%c",201); //É
  gotoxy(x2, y1); printf("%c",187); //»
  gotoxy(x1, y2); printf("%c",200); //È
  gotoxy(x2, y2); printf("%c",188); //¼
       for(i=(x1+1);i<=(x2-1);i++)
   { gotoxy(i, y1);printf("%c",205);//Í
	 gotoxy(i, y2);printf("%c",205);}//Í
    for(i=(y1+1);i<=(y2-1);i++)
     { gotoxy(x1, i);printf("%c",186); //º
       gotoxy(x2, i);printf("%c",186);}
 }
//////////////////
void arbol::menu()
{
  int tecla,f; char t1=24,t2=25;
 char opciones[9][70];

 do
 {
  f_l(1,14);
       strcpy(opciones[1], "1. ADICIONAR             ");
       strcpy(opciones[2], "2. ELIMINAR              ");
       strcpy(opciones[3], "3. INORDEN GRAFICO       ");
       strcpy(opciones[4], "4. POSTORDEN GRAFICO     ");
       strcpy(opciones[5], "5. PREORDEN GRAFICO      ");
       strcpy(opciones[6], "6. LISTADO               ");
       strcpy(opciones[7], "7. SALIR                 ");
      clrscr();
     f_l(1,14);
	window(25,3,51,5);f_l(0,14);clrscr();
	window(24,2,50,4);f_l(11,4);clrscr();
	gotoxy(4,2);cout<<"<< MENU PRINCIPAL >>";
	window(1,1,80,25);
	f_l(1,14);

	window(24,7,50,15);f_l(4,4);clrscr();
	window(1,1,80,25);
	f_l(1,14);
	cuad(11,19,70,22);
	gotoxy(13,20);
	cout<<"   Utilice las Teclas del Cursor "<<t1<<t2<<" Para Desplazarse ";
	 gotoxy(15,21);
	 cout<<"   Pulse [Enter] Para escoger la opci¢n que desee ";
	 cuad(1,1,80,24);

    for(f=1;f<=7;f++) {gotoxy(25,f+7);cprintf("%s",opciones[f]);}
       f=1;   f_l(7,5);
     gotoxy(25,f+7);cprintf("%s",opciones[f]);
	      f_l(1,14);

  do
  {
	 do
	 {
	     tecla=getch();
	  }while((tecla==80)&&(tecla==72)&&(tecla==13));
	if(tecla==80)
	{   f_l(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	       if (f!=7)
	      {   f++;   f_l(7,5);
		gotoxy(25,f+7);  cprintf("%s",opciones[f]);
		f_l(1,14);
	       }
	else
	   {
	      f=1;    f_l(7,5);
	      gotoxy(25,f+7);cprintf("%s",opciones[f]);  f_l(1,14);
	   }
   }

	if(tecla == 72)
	 {  f_l(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	   if (f!=1)
	     {   f--;  f_l(7,5);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 f_l(1,14);
	      }
	       else
	      {  f=7;  f_l(7,5);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 f_l(1,14);
	       }
	  }

  }while(tecla!=13);

  switch(f)
  {
  case 1:{
	   insertar();
	   break;
	  }
  case 2:{
	   borrar();
	   break;
	  }
  case 3: {inicializa_inorden();inorden_grafico(raiz);
	    getch();closegraph();
	     break;
	   }
   case 4:{inicializa_postorden();posorden_grafico(raiz);
		 getch();closegraph();
		 break;
	   }
  case 5:{ inicializa_preorden();
	   preorden_grafico(raiz);
	   getch();closegraph();
	   break;
	   }
  case 6:  { fila=6;clrscr();
	   gotoxy(20,2); cout<<"<< VISUALIZACION DE LOS ELEMENTOS INORDEN >>";
	   gotoxy(33,4); cout<<"CODIGO";
	   gotoxy(30,5); cout<<"-------------";
	   gotoxy(43,4); cout<<"NOMBRE";
	   gotoxy(38,5); cout<<"-------------";
	   gotoxy(25,23); cout<<"PULSE CUALQUIER TECLA PARA SEGUIR.....";
	   textcolor(RED);
	   inorden(raiz);getch();
	   break;
	  }

	  }
 }while(f!=7);
}
//////////////////
void arbol::inicializa_inorden()
{  int gdriver = DETECT, gmode, errorcode;
       initgraph(&gdriver,&gmode,"..\\bgi");

if(raiz!=NULL)
{       setcolor(9);
       rectangle(1,1,638,479);
       rectangle(1,1,270,13);
       rectangle(370,1,638,13);
       setcolor(GREEN);
       outtextxy(35,4,"VISUALIZACION  DEL  ARBOL");
       setcolor(12);
       outtextxy(415,4,"RECORRIDO  IN-ORDEN");
       setcolor(14);
       outtextxy(335,10,"RAIZ");
       setcolor(9);
       rectangle(1,445,638,479);
       rectangle(1,435,638,479);
       setcolor(11);
       outtextxy(60,437,"C¢digos que Forman Parte del Arbol Binario en su Recorrido In-Orden");
       mostrar(raiz,320,20,320);
       r=12;w=458;colo=1;
}
  else
  {setlinestyle(0,0x8001,3);
    setcolor(14);
  circle(300,240,110);
  ellipse(300,200,200,340,90,100);
  ellipse(250,200,0,360,30,20);
  ellipse(350,200,0,360,30,20);
    setcolor(11);
  rectangle(0,0,638,478);
   settextstyle(7,0,1);
    setcolor(4);
  outtextxy(190,240,"NO HAY INFORMACION");
  setcolor(15);settextstyle(0,0,1);
  outtextxy(200,420,"Press Any Key to Continue....");
  }
}
////////////////////////////
void arbol::inicializa_preorden()
{  int gdriver = DETECT, gmode, errorcode;
       initgraph(&gdriver,&gmode,"..\\bgi");
if(raiz!=NULL)
{       setcolor(9);
       rectangle(1,1,638,479);
       rectangle(1,1,270,13);
       rectangle(370,1,638,13);
       setcolor(GREEN);
       outtextxy(35,4,"VISUALIZACION  DEL  ARBOL");
       setcolor(14);
       outtextxy(335,10,"RAIZ");
       setcolor(12);
       outtextxy(415,4,"RECORRIDO  PRE-ORDEN");
       setcolor(14);
       outtextxy(335,10,"RAIZ");
       setcolor(9);
       rectangle(1,445,638,479);
       rectangle(1,435,638,479);
       setcolor(11);
       outtextxy(60,437,"C¢digos que Forman Parte del Arbol Binario en su Recorrido Pre-Orden");
       mostrar(raiz,320,20,320);
       r=12;w=458;colo=1;
}
  else
  {setlinestyle(0,0x8001,3);
    setcolor(14);
  circle(300,240,110);
  ellipse(300,200,200,340,90,100);
  ellipse(250,200,0,360,30,20);
  ellipse(350,200,0,360,30,20);
    setcolor(11);
  rectangle(0,0,638,478);
   settextstyle(7,0,1);
    setcolor(4);
  outtextxy(190,240,"NO HAY INFORMACION");
  setcolor(15);settextstyle(0,0,1);
  outtextxy(200,420,"Press Any Key to Continue....");
  }

}
////////////////////////////
void arbol::inicializa_postorden()
{  int gdriver = DETECT, gmode, errorcode;
       initgraph(&gdriver,&gmode,"..\\bgi");
if(raiz!=NULL)
{       setcolor(9);
       rectangle(1,1,638,479);
       rectangle(1,1,270,13);
       rectangle(370,1,638,13);
       setcolor(GREEN);
       outtextxy(35,4,"VISUALIZACION  DEL  ARBOL");
       setcolor(12);
       outtextxy(415,4,"RECORRIDO  POST-ORDEN");
       setcolor(9);
       rectangle(1,445,638,479);
       rectangle(1,435,638,479);
       setcolor(11);
       outtextxy(60,437,"C¢digos que Forman Parte del Arbol Binario en su Recorrido Post-Orden");
       mostrar(raiz,320,20,320);
       r=12;w=458;colo=1;
}
  else
  {setlinestyle(0,0x8001,3);
    setcolor(14);
  circle(300,240,110);
  ellipse(300,200,200,340,90,100);
  ellipse(250,200,0,360,30,20);
  ellipse(350,200,0,360,30,20);
    setcolor(11);
  rectangle(0,0,638,478);
   settextstyle(7,0,1);
    setcolor(4);
  outtextxy(190,240,"NO HAY INFORMACION");
  setcolor(15);settextstyle(0,0,1);
  outtextxy(200,420,"Press Any Key to Continue....");
  }

}
void main()
{
 arbol obj(NULL);
 obj.menu();
}
