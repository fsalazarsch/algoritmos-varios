#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"ctype.h"
#include"stdlib.h"
#define TRUE 1
#define FALSE 0
#define MAXIMO 50
void f_l(int f,int l);
void menu();
void menu_cola();
void menu_doblecir();
void menu_doblen();
	struct NODO {
	 long codigo;
	 char nombre[50];
	 struct NODO *izq;
	 struct NODO *der;
	 };
	 int c;
	
	 struct NODO *cab,*p,*q,*nn,*cab2;
	
	 struct COLAS{
	 struct NODO COLA[MAXIMO];
	 int frente,final;
	 }cola;
	 int sw=0;
	 int colavacia(struct COLAS *pq);
	 void eliminarcola(struct COLAS *pq);
	 void insertarcola(struct COLAS *pq,long cod,char *nombre);
	 void insercola();
	 void capdoblecir();
	 void elimdoblecir();
	 void consultardoblecir();
	 void capdoble();
	 void elimdoble();
	 void consultardoble();
	 int  encontrar_doble(long cod);
	 int  encontrar_circular (long cod);
	 void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux);
	 void cuadro(int prin,int fin,int fl,int cl);
	 void cuadro1(int x1, int y1, int x2, int y2);
	 int encontrar_circular (long cod){
	  int sw=0;
	if(cab==NULL)
	return 0;
	else{
	  p=cab;
	  while(p->der!=cab && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->der;
					   }
	  if(sw==1)
	  return 1; 
		if(sw==0)
		   if(p->codigo==cod)
			return 1;
				 }
		return 0;
	}
/*********************************/
void consultardoblecir(){
 if(cab!=NULL){
 p=cab;
 while(p->der!=cab){
	clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	p=p->der;
	}
   if(p!=NULL){
   clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	}
}
	else
	{
	clrscr();
	printf("Lista Vacia........");
	getch();
	}
	}
/************************************/
 void consultardoble(){
 p=cab2;
 while(p!=NULL){
	clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	p=p->der;
	}
	if(cab2==NULL){
	clrscr();
	printf("Lista Vacia........");
	getch();
	}
   }

/**********************************/  
	void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux)
		{
		int sw=0,i,control;
		char *auxiliar;
		switch(tipo_captura){
			  case 1:{do{
			  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				 if(isdigit(auxiliar[i])==0){
				    sw=1;
				    break;
				    }

				 }while(sw!=1);
				if(sw==1){
				control=sw;
				sw=0;
				}

				}while(control!=1);
				strcpy(aux->nombre,auxiliar);
				break;
				}
			  case 2:{
				  do{
				  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				    if(isdigit(auxiliar[i])==0){
					sw=1;
					break;
					}
				 }while(sw!=0);
				if(sw==1){
				control=sw;
				sw=0;
				}
				}while(control!=0);
				aux->codigo=atol(auxiliar);
				break;
				}
			    }
			 }
/*********************************/

void elimdoblecir(){
			 char a[20];
			 int z,r,sw=0;
					long cod;
					clrscr();
   gotoxy(10,10);
    printf("Codigo  A Eliminar:");
	  do{
	  z=0;r=0;
	  gotoxy(35,10);
	  clreol();
	  gets(a);
	  while(a[z]!='\0'){
	  if(a[z]<'0'|| a[z] > '9' ) r=-1;
	  z++;
	   }
	  }while(r==-1);
	  cod=atol(a);

	  p=cab;
	  q=NULL;
	  while(p->der!=cab && sw==0)
	  if(p->codigo==cod)
	    sw=1;
	    else{
	    q=p;
	    p=p->der;
	     }
	    if(q==NULL){
	    if(p->der==cab && p->codigo==cod && sw==0)
	    cab=NULL;
	    else
	    if(p->der!=cab && p->codigo==cod && sw==1){
	    q=p->izq;
	    q->der=p->der;
	    q=q->der;
	    q->izq=p->izq;
	    cab=p->der;
	    delete(p);
	      }
     }else
     if(p->der==cab && p->codigo==cod && sw==0){
	 q->der=p->der;
	 q=q->der;
	 q->izq=p->izq;
	 delete(p);
	 }
	 else{
	 if(sw==1){
	 q->der=p->der;
	 q=q->der;
	 q->izq=p->izq;
	 delete(p);
	 }
	  }
	 char op;
   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	elimdoblecir();
			   }
/*********************************/
void capdoblecir(){
	 int sw=0;
	 clrscr();
	 nn=new NODO;

    do{
    gotoxy(10,10);
    printf("Codigo:");
	if(sw==1){
	gotoxy(10,10);
	printf("El Codigo Digitado ya Existe");
	getch();
	clreol();
	}
	 validar_datos(18,10,2,nn);
	}while((sw=encontrar_circular (nn->codigo))==1);
    gotoxy(10,12);
    printf("Nombre:");
	 validar_datos(20,12,1,nn);

	nn->izq=nn->der=NULL;
	  if(cab==NULL)
	   {
		cab=nn;
		nn->izq=cab;
		nn->der=cab;
	   }
		else{
			p=cab;
			while(p->der!=cab){
			    p=p->der;
						  }
			p->der=nn;
			nn->der=cab;
			nn->izq=p;
		    }

   char op;
   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	capdoblecir();
   }



	  int encontrar_doble(long cod){
	  int sw=0;
	if(cab2==NULL)
	return 0;
	else{
	  p=cab2;
	  while(p!=NULL && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->der;
					   }
	  if(sw==1)
	  return 1; 

			    }
		return 0;
	}

/*********************************/
  void elimdoble(){
			 char a[20];
			 int z,r,sw=0;
					long cod;
					clrscr();
   gotoxy(10,10);
   printf("Codigo A Eliminar:");
			  do{
			  z=0;r=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);

		p=cab2;
		   q=NULL;
		   while(p!=NULL && sw==0)
			  if(p->codigo==cod)
				sw=1;
				else{
				    q=p;
				    p=p->der;
				    }

				   if(q==NULL && sw==1){
					   if(p->der!=NULL){
					   q=p->der;
					   q->izq=NULL;
					   p->der=NULL;
						cab2=q;
					   delete(p);
					   }else
						cab2=NULL;
					}else
				  if(sw==1){
				  if(p->der!=NULL){
				   q->der=p->der;
				   q=p->der;
				   q->izq=p->izq;
				   delete(p);
				   }else{

				   q->der=NULL;
				   delete(p);
				   }
				   }else
				   {
				   printf("Este Codigo No Existe ");
				   getch();
				   }





			    char op;
   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	elimdoble();
			   }

/*********************************/
void capdoble(){
	 int sw=0;
	 clrscr();
	 nn=new NODO;

    do{
    gotoxy(10,10);
    printf("Codigo:");
	if(sw==1){
	gotoxy(10,10);
	printf("El Codigo Digitado ya Existe");
	getch();
	gotoxy(10,10);
	clreol();
	}
	 validar_datos(20,10,2,nn);
	}while((sw=encontrar_doble(nn->codigo))==1);
    gotoxy(10,12);
    printf("Nombre:");
	 validar_datos(20,12,1,nn);

	nn->izq=nn->der=NULL;
	  if(cab2==NULL)
	   {
		cab2=nn;
		nn->izq=NULL;
		nn->der=NULL;
	   }
		else{
			p=cab2;
			while(p->der!=NULL){
			    p=p->der;
						  }
			p->der=nn;
			nn->der=NULL;
			nn->izq=p;
		    }

   char op;
   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	capdoble();
   }
/***********************************/
	 void insercola(){
	 char a[20];
	 int z,r,sw2=0;
	 long cod;
	 char *nombre;
	 clrscr();
   gotoxy(15,5);
   printf("Codigo :");
			  do{
			  z=0;r=0;
			  gotoxy(45,5);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);
 gotoxy(15,6);printf("Nombre:");
    scanf("\n");
    gets(nombre);
    insertarcola(&cola,cod,nombre);
			char op;
   do{
   sw2=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw2=1;
  }while(sw2!=1);
   if(op=='S')
	insercola();
    }

    int colavacia(struct COLAS *pq){
    return((pq->frente==pq->final) ? TRUE : FALSE);
    }

/***********************************/
	 void eliminarcola(struct COLAS *pq){
	 if(colavacia(pq)){
	 printf("subdesborde en la cola ");
	 getch();
	 return;
	 }
	 if( pq->frente==MAXIMO-1){
	printf("Codigo Eliminado :%ld Nombre : %s ",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	  pq->frente=0;
	}
   else{
	  printf("Codigo Eliminado :%ld Nombre : %s ",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	  pq->frente++;
	  }
	  getch();
	  }

/********************************/
void insertarcola(struct COLAS *pq,long cod,char *nombre){
	  if(pq->final==MAXIMO-1)
	pq->final=0;
	  else
	pq->final++;
	pq->COLA[pq->final].codigo=cod;
	strcpy(pq->COLA[pq->final].nombre,nombre);
	}
/***********************************************************/
void menu()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10]," COLAS           ");
 strcpy(opciones[11]," DOBLE CIR       ");
 strcpy(opciones[12]," LISTAS DOBLES   ");
 strcpy(opciones[13]," SALIR           ");
 do
 { clrscr();
   cuadro(1,80,1,24);
   cuadro1(29,9,52,14);
   cuadro(27,54,8,15);
   cuadro1(20,2,60,4);
   gotoxy(32,3);printf("MENU PRINCIPAL");
   for(f=10;f<=13;f++)
	{ gotoxy(30,f);
	  cprintf("%s",opciones[f]);
	}
   f=10; c=30;
   textcolor(0);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(0);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=10;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=13;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 {   case 10 :clrscr(); menu_cola();break;
		case 11 :clrscr(); menu_doblecir();break;
		case 12 :clrscr(); menu_doblen();break;
		case 13 :clrscr();exit(0);
	 }
 } while(f !=13);
}
/********************************************/
void menu_cola()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INGRESAR ");
 strcpy(opciones[11],"  ELIMINAR ");
 strcpy(opciones[12],"  SALIR    ");
 do
 { clrscr();
   cuadro(1,80,1,24);
   cuadro1(29,9,46,13);
   cuadro(27,48,8,14);
   for(f=10;f<=12;f++)
	{ gotoxy(30,f);
	  cprintf("%s",opciones[f]);
	}
   f=10; c=30;
   textcolor(0);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(0);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=12)
	   { f++;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=10;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=12;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr();insercola();break;
	   case 11 :clrscr();eliminarcola(&cola);break;
	 }
 } while(f !=12);
}
/***************************************/
void menu_doblen()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INGRESAR ");
 strcpy(opciones[11],"  ELIMINAR ");
 strcpy(opciones[12],"  VISUALIZAR");
 strcpy(opciones[13],"  SALIR     ");
 do
 { clrscr();
   cuadro(1,80,1,24);
   cuadro1(29,9,49,14);
   cuadro(27,51,8,15);
   for(f=10;f<=13;f++)
	{ gotoxy(30,f);
	  cprintf("%s",opciones[f]);
	}
   f=10; c=30;
   textcolor(0);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(0);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=10;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=13;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 {   case 10 :clrscr(); _setcursortype(_NOCURSOR);capdoble();break;
		case 11 :clrscr(); _setcursortype(_NOCURSOR);elimdoble();break;
		case 12 :clrscr(); _setcursortype(_NOCURSOR);consultardoble();break;
	 }
 } while(f !=13);
}
/****************************************************/
void menu_doblecir()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INGRESAR  ");
 strcpy(opciones[11],"  ELIMINAR  ");
 strcpy(opciones[12],"  VISUALIZAR");
 strcpy(opciones[13],"  SALIR     ");
 do
 { clrscr();
   cuadro(1,80,1,24);
   cuadro1(29,9,46,14);
   cuadro(27,48,8,15);
   for(f=10;f<=13;f++)
	{ gotoxy(30,f);
	  cprintf("%s",opciones[f]);
	}
   f=10; c=30;
   textcolor(0);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(0);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=10;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(0);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	   else
	   { f=13;
		 textcolor(0);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(0);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr(); _setcursortype(_NOCURSOR);capdoblecir();break;
		case 11 :clrscr(); _setcursortype(_NOCURSOR);elimdoblecir();break;
		case 12 :clrscr(); _setcursortype(_NOCURSOR);consultardoblecir();break;
	 }
 } while(f !=13);
}

/****************************************************************************/
void cuadro(int prin,int fin,int fl,int cl)
{ int i=0;
  for(i=prin; i<=fin; i++)
  { gotoxy(i,fl);cprintf("Í");
	gotoxy(i,cl);cprintf("Í");
  }
  for(i=fl; i<=cl; i++)
  { gotoxy(prin,i);cprintf("º");
	gotoxy(fin,i);cprintf("º");
  }
  gotoxy(prin,fl);printf("É");
  gotoxy(fin,fl);printf("»");
  gotoxy(prin,cl);printf("È");
  gotoxy(fin,cl);printf("¼");
}
/****************************************************************************/
void cuadro1(int x1, int y1, int x2, int y2)
{ int i,y;
  for(i=x1;i<=x2;i++)
  { gotoxy(i,y1); printf("ß");
	gotoxy(i,y2); printf("Ü");
  }
  for(i=y1;i<=y2;i++)
  { gotoxy(x1,i); printf("Û");
	gotoxy(x2,i); printf("Û");

}
   }

/****************************************************************************/

void main(){
cola.frente=cola.final=MAXIMO-1;
cab2=cab=NULL;
menu();
}