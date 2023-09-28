#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <iostream.h>
#include <ctype.h>
class binario
{
  struct NODITO
  {
    int cod;
    char nom[20];
    struct NODITO *izda;
    struct NODITO *decha;
  };
 public:
 struct NODITO *nnuevo,*POS,*PADRE,*cabeza,*aux;
 char n[3],cadena[10],nom[20];
 int num,incre,r,w,colo;
 void adicionar_nodo();
 void arbol_de_busqueda();
 void eliminar_nodo();
 void inordenarbol(struct NODITO *aux);
 void postordenarbol(struct NODITO *aux);
 void preordenarbol(struct NODITO *aux);
 void menu_principal();
 void pintar_grafico(NODITO *aux,int x,int y,int f);
 void tabla(NODITO *aux);
 void cuadro(int x1,int y1,int x2,int y2);
 void recuadro_inor();
 void recuadro_post();
 void recuadro_preor();
 void PISO_COLOR(int f,int l);
 binario(NODITO *vacio)
 { cabeza=vacio;
 }

};
/*******************************************/
void binario::arbol_de_busqueda()
{
 if(cabeza==NULL)
 {
  POS=NULL;
  PADRE=NULL;
 }
 else
 {
      if(num==cabeza->cod)
       {
	  POS=cabeza;
	  PADRE=NULL;
       }
	 else
	    {
	      if(num < cabeza->cod)
	       {
		 POS=cabeza->izda;
		 PADRE=cabeza;
	       }
		 else
		 {
		   POS=cabeza->decha;
		   PADRE=cabeza;
		  }
		   while(POS != NULL)
		    {
		       if(num==POS->cod) break;
		       if(num < POS->cod)
			 {
			      PADRE=POS;
			      POS=POS->izda;
			  }
			    else
			     {
			       PADRE=POS;
			       POS=POS->decha;
			      }
		     }
	    }
 }
}
////////////////////////////
void binario::adicionar_nodo()
{PISO_COLOR(1,15);
 char op;int i,sw,w;
 do{ clrscr();
	cuadro(2,1,79,25);
	cuadro(24,3,51,5);
	gotoxy(25,4);cout<<"++++INSERCION DE NODOS++++";
	PISO_COLOR(1,15);
	 do{
	       sw=0;
	       w=2;
	       window(4,14,70,14);clreol();window(1,1,80,25);
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
		     gotoxy(20,14); cout <<"...Numero Fuera de Rango...";
		     getch();
		   }
	 }while(sw!=0 || num < 0 || num > 99);

 arbol_de_busqueda();

 if (POS != NULL)
 {
  gotoxy(20,14); cprintf("...Ya existe el nodo....");
  getch();
 }
 else
 {

	 do
	 {  sw=0;
	       gotoxy(10,10);
	       cout<<"DIGITE EL NOMBRE: ";window(27,10,60,10);
	       clreol();window(1,1,80,25);
	       gotoxy(28,10);scanf("\n");
	       gets(nom);
		if (nom[1]=='\x0') {w=1;}
		     for (i=0;i<w;++i)
		     {	if (!isalpha(nom[i]))
			   {
			      sw=1;
			    }
		      }
	 }while(sw==1);

  nnuevo=new NODITO;
  if (PADRE==NULL)
  {
   cabeza = nnuevo;
   cabeza->cod=num;
   strcpy(cabeza->nom,nom);
   cabeza->decha=cabeza->izda=NULL;
  gotoxy(20,14); cprintf("... Registrado Exitosamente.....");
  }
  else
  {
   if (num < PADRE->cod)
   {
    PADRE->izda=nnuevo;
    POS=nnuevo;
    POS->cod=num;
   strcpy(POS->nom,nom);
    POS->decha=POS->izda=NULL;
  gotoxy(20,14); cprintf("... Registrado Exitosamente.....");
   }
   else
   {
    PADRE->decha=nnuevo;
    POS=nnuevo;
    POS->cod=num;
   strcpy(POS->nom,nom);
    POS->decha=POS->izda=NULL;
  gotoxy(20,14); cprintf("... Registrado Exitosamente.....");
   }
  }
 }

gotoxy(26,20);cout<<"DESEA CONTINUAR? [S/N]:";
	op=toupper(getche());
   }while(op=='S');
}
/////////////////////////////
void binario::eliminar_nodo()
{
 char op;
 int sw,i,w;
 PISO_COLOR(1,15);
 do{clrscr();
       cuadro(2,1,79,25);
	cuadro(2,1,79,25);
	cuadro(24,3,53,5);
	gotoxy(25,4);cout<<"----ELIMINACION DE NODOS----";
	PISO_COLOR(1,15);
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
 arbol_de_busqueda();

   if(POS==NULL)
   { gotoxy(20,14);cout <<"....No Existe El Nodo.... ";}
   else
   {

		     if(POS->izda==NULL && POS->decha==NULL)
		       {  if(PADRE==NULL)
			  cabeza=NULL;
			  else
			    { if(PADRE->decha==POS)
			      PADRE->decha=NULL;
			       else
			       PADRE->izda=NULL;
			     }
		       }
		       else
		       {  if(POS->decha!=NULL && POS->izda!=NULL)
			  { PADRE=POS; nnuevo=POS->izda;
			    while(nnuevo->decha!=NULL)
			      { PADRE=nnuevo;
				nnuevo=nnuevo->decha;
			      }
			    POS->cod=nnuevo->cod;
			    strcpy(POS->nom,nnuevo->nom);
			    gotoxy(20,14);cout <<".....Nodo Eliminado... ";
				 if(PADRE==POS)
				  { PADRE->izda=nnuevo->izda;}
				     else
				     { PADRE->decha=nnuevo->izda;}
					POS=nnuevo;
				   }
				    else
				     { if(POS->decha!=NULL)
					  { if(PADRE==NULL)
					      cabeza=POS->decha;
					     else
					      { if(POS==PADRE->decha)
						PADRE->decha=POS->decha;
						 else
						 PADRE->izda=POS->decha;
					       }
					    }
					    else
					    { if(PADRE==NULL)
						cabeza=POS->decha;
					       else
						 { if(POS==PADRE->decha)
						   PADRE->decha=POS->izda;
						   else
						   PADRE->izda=POS->izda;
						  }
					     }
				      }
				 }
				 delete(POS);
	    }
gotoxy(26,20);cout<<"DESEA CONTINUAR? [S/N]:";
	op=toupper(getche());
   }while(op=='S');
}
////////////////////////////
void binario::PISO_COLOR(int f,int l)
{  textbackground(f);
   textcolor(l);
}
////////////////////////////
void binario::tabla(NODITO *aux)
{  if (aux != NULL)
  {
   tabla(aux->izda);
   gotoxy(35,incre);cprintf("%d",aux->cod);
   gotoxy(45,incre);cprintf("%s",aux->nom);incre++;
   tabla(aux->decha);
  }
}
/////////////////////////////
void binario::inordenarbol(NODITO *aux)
{
  if (aux != NULL)
  {
   inordenarbol(aux->izda);
   setcolor(colo);
   delay(500);
   itoa(aux->cod,cadena,10);
   outtextxy(r,w,cadena);r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }

   inordenarbol(aux->decha);

  }


}
//////////////////////////////
void binario::preordenarbol(NODITO *aux)
{
 if (aux != NULL)
 {
   setcolor(15);delay(700);
   itoa(aux->cod,cadena,10);
   outtextxy(r,w,cadena);r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }
  preordenarbol(aux->izda);
  preordenarbol(aux->decha);
 }
}
////////////////////////////////////
void binario::postordenarbol(NODITO *aux)
{
 if (aux != NULL)
 {
  postordenarbol(aux->izda);
  postordenarbol(aux->decha);
   setcolor(14);delay(700);
   itoa(aux->cod,cadena,10);
   outtextxy(r,w,cadena);r+=32;
   if(r>=587)
   {
    r=12;w=458;
   }

 }
}
////////////////////////////////////
void binario::pintar_grafico(NODITO *aux,int x,int y,int f)
{

  if(aux!=NULL)
  {
     itoa(aux->cod,n,10);
     outtextxy(x-8,y-4,n);
     setcolor(4);
     circle(x,y,10);
	 setcolor(14);
     if(aux->izda!=NULL)
       line(x,y+10,x-f/2,(y+70)-10);
     if(aux->decha!=NULL)
	 line(x,y+10,x+f/2,(y+70)-10);
     f=f/2;
     pintar_grafico(aux->izda,x-f,y+70,f);
     pintar_grafico(aux->decha,x+f,y+70,f);
    }


}
/////////////////////////////////////////
void binario::cuadro(int x1,int y1,int x2,int y2)
{ int i;window(1,1,80,25);
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++)
   { gotoxy(i, y1);printf("%c",196);//Ä
	 gotoxy(i, y2);printf("%c",196);}//Ä
    for(i=(y1+1);i<=(y2-1);i++)
     { gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);}
 }
//////////////////
void binario::menu_principal()
{
  int tecla,f;
 char opciones[9][70];

 do
 {
  PISO_COLOR(1,15);
       strcpy(opciones[1], "1. INSERTAR NODO         ");
       strcpy(opciones[2], "2. BORRAR NODO           ");
       strcpy(opciones[3], "3. RECORRIDO INORDEN     ");
       strcpy(opciones[4], "4. RECORRIDO PREORDEN    ");
       strcpy(opciones[5], "5. RECORRIDO POSTORDEN   ");
       strcpy(opciones[6], "6. TABLA                 ");
       strcpy(opciones[7], "7. FINALIZAR             ");
      clrscr();
     PISO_COLOR(1,15);
	cuadro(2,1,78,24);
	cuadro(24,2,50,4);
	gotoxy(25,3);cout<<"***** M   E   N   U *****";
	cuadro(24,18,50,20);
	gotoxy(25,19);cout<<"***** M   E   N   U *****";
	cuadro(24,7,50,15);
    for(f=1;f<=7;f++) {gotoxy(25,f+7);cprintf("%s",opciones[f]);}
       f=1;   PISO_COLOR(0,15);
     gotoxy(25,f+7);cprintf("%s",opciones[f]);
	      PISO_COLOR(1,14);

  do
  {
	 do
	 {
	     tecla=getch();
	  }while((tecla==80)&&(tecla==72)&&(tecla==13));
	if(tecla==80)
	{   PISO_COLOR(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	       if (f!=7)
	      {   f++;   PISO_COLOR(0,15);
		gotoxy(25,f+7);  cprintf("%s",opciones[f]);
		PISO_COLOR(1,14);
	       }
	else
	   {
	      f=1;    PISO_COLOR(0,15);
	      gotoxy(25,f+7);cprintf("%s",opciones[f]);  PISO_COLOR(1,14);
	   }
   }

	if(tecla == 72)
	 {  PISO_COLOR(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	   if (f!=1)
	     {   f--;  PISO_COLOR(0,15);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 PISO_COLOR(1,14);
	      }
	       else
	      {  f=7;  PISO_COLOR(0,15);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 PISO_COLOR(1,14);
	       }
	  }

  }while(tecla!=13);

  switch(f)
  {
  case 1:{
	   adicionar_nodo();
	   break;
	  }
  case 2:{
	   eliminar_nodo();
	   break;
	  }
  case 3: {recuadro_inor();inordenarbol(cabeza);
	    getch();closegraph();
	     break;
	   }
   case 5:{recuadro_post();postordenarbol(cabeza);
		 getch();closegraph();
		 break;
	   }
  case 4:{ recuadro_preor();
	   preordenarbol(cabeza);
	   getch();closegraph();
	   break;
	   }
  case 6:  { incre=6;clrscr();
	   gotoxy(20,2); cout<<"<< VISUALIZACION DE LOS ELEMENTOS INORDEN >>";
	   gotoxy(33,4); cout<<"CODIGO";
	   gotoxy(30,5); cout<<"-------------";
	   gotoxy(40,4); cout<<"NOMBRE";
	   gotoxy(38,5); cout<<"-------------";
	   gotoxy(25,23); cout<<"PULSE CUALQUIER TECLA PARA SEGUIR.....";
	   textcolor(RED);
	   tabla(cabeza);getch();
	   break;
	  }

	  }
 }while(f!=7);
}
//////////////////
void binario::recuadro_inor()
{  int driver = DETECT, modo;
       initgraph(&driver,&modo,"..\\bgi");
if(cabeza!=NULL)
{
   settextstyle(1,1,1);
   setcolor(2);
   outtextxy(5,4,"RECORRIDO  IN-ORDEN");
   rectangle(1,1,638,479);
   setcolor(11);
   settextstyle(0,0,0);
   pintar_grafico(cabeza,320,20,320);
   r=12;w=458;colo=1;
}
  else
  {
   setcolor(4);
   rectangle(0,0,638,478);
   settextstyle(1,0,1);
   setcolor(2);
   outtextxy(50,100,"EL ARBOL ESTA VACIO");
   outtextxy(190,200,"EL ARBOL ESTA VACIO");
   outtextxy(240,300,"EL ARBOL ESTA VACIO");
   outtextxy(400,400,"EL ARBOL ESTA VACIO");
   setcolor(15);settextstyle(0,0,1);
   outtextxy(200,470,"PULSE [ENTER] PARA SEGUIR");
  }

}
////////////////////////////
void binario::recuadro_preor()
{  int driver = DETECT, modo;
       initgraph(&driver,&modo,"..\\bgi");
if(cabeza!=NULL)
{
   settextstyle(1,1,1);
   setcolor(2);
   outtextxy(5,4,"RECORRIDO  PRE-ORDEN");
   rectangle(1,1,638,479);
   setcolor(11);
   settextstyle(0,0,0);
       pintar_grafico(cabeza,320,20,320);
       r=12;w=458;colo=3;
}
  else
  {
   setcolor(4);
   rectangle(0,0,638,478);
   settextstyle(1,0,1);
   setcolor(2);
   outtextxy(50,100,"EL ARBOL ESTA VACIO");
   outtextxy(190,200,"EL ARBOL ESTA VACIO");
   outtextxy(240,300,"EL ARBOL ESTA VACIO");
   outtextxy(400,400,"EL ARBOL ESTA VACIO");
   setcolor(15);settextstyle(0,0,1);
   outtextxy(200,470,"PULSE [ENTER] PARA SEGUIR");
  }

}
////////////////////////////
void binario::recuadro_post()
{  int driver = DETECT, modo;
       initgraph(&driver,&modo,"..\\bgi");
if(cabeza!=NULL)
{
   settextstyle(1,1,1);
   setcolor(2);
   outtextxy(5,4,"RECORRIDO  POST-ORDEN");
   rectangle(1,1,638,479);
   setcolor(11);
   settextstyle(0,0,0);
       pintar_grafico(cabeza,320,20,320);
       r=12;w=458;colo=5;

}
  else
  {
   setcolor(4);
   rectangle(0,0,638,478);
   settextstyle(1,0,1);
   setcolor(2);
   outtextxy(50,100,"EL ARBOL ESTA VACIO");
   outtextxy(190,200,"EL ARBOL ESTA VACIO");
   outtextxy(240,300,"EL ARBOL ESTA VACIO");
   outtextxy(400,400,"EL ARBOL ESTA VACIO");
   setcolor(15);settextstyle(0,0,1);
   outtextxy(200,470,"PULSE [ENTER] PARA SEGUIR");
  }

}
void main()
{
 binario objeto(NULL);
 objeto.menu_principal();
}
