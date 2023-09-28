#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"ctype.h"
#include"stdlib.h"
#define TRUE 1
#define FALSE 0
#define MAXIMO 100
    void f_l(int f,int l);
	void menu();
	void menu_cola();
	void menu_listadoblecircular();
	void menu_listadoble();
   struct NODO {
    long codigo;
    char nombre[50];
    struct NODO *izq;
    struct NODO *der;
    };
    int c;

    struct NODO *ptr,*p,*q,*nodonuevo,*ptr2;

    struct COLAS{
    struct NODO COLA[MAXIMO];
    int frente,final;
    }cola;
    int sw=0;
    int colavacia(struct COLAS *pq);
    void visualizar_cola(struct COLAS *pq);
    void eliminarcola(struct COLAS *pq);
    void insertarcola(struct COLAS *pq,long cod,char *nombre);
    void inscola();
    void cap_doble_cir();
    void elim_doble_cir();
    void visualizar_doble_circular();
    void capDoble();
    void elim_doble();
    void visualizar_doble();
    int  encontrar_doble(long cod);
    int  encontrar_circular (long cod);
    void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux);
    int encontrar_circular (long cod){
  /********************inserta elemento***************/
	  int sw=0;
	if(ptr==NULL)
	return 0;
	else{
	  p=ptr;
	  while(p->der!=ptr && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->der;
					   }
	  if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}

void visualizar_doble_circular(){
 if(ptr!=NULL){
 p=ptr;
 while(p->der!=ptr){
	clrscr();
	gotoxy(10,14);printf("Digite [ENTER] Para Seguir Visualizando...  ");_setcursortype(_NOCURSOR);
	gotoxy(10,10);printf("Codigo: %ld  \n",p->codigo);
	gotoxy(10,12);printf("Nombre: %s \n\n",p->nombre);
  getch();
	p=p->der;
	}
   if(p!=NULL){
   clrscr();
	gotoxy(10,14);printf("Digite [ENTER] Para Volver Al menu...  ");_setcursortype(_NOCURSOR);
	gotoxy(10,10);printf("Codigo: %ld \n",p->codigo);
	gotoxy(10,12);printf("Nombre: %s \n",p->nombre);
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
 void visualizar_doble(){
 p=ptr2;
 while(p!=NULL){
	clrscr();
	gotoxy(10,14);printf("Digite [ENTER] Para Seguir Visualizando...  ");_setcursortype(_NOCURSOR);
	gotoxy(10,10);printf("Codigo: %ld \n",p->codigo);
	gotoxy(10,12);printf("Nombre: %s \n",p->nombre);
		getch();
	p=p->der;
	}
   if(ptr2==NULL){
	clrscr();
	printf("LISTA VACIA  ");
	getch();
	}
   }


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


void elim_doble_cir(){
			 char a[20];
			 int z,r,sw=0;
					long cod;
					clrscr();
   gotoxy(10,10);
    printf("Codigo  A Eliminar:");
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

		p=ptr;
		   q=NULL;
		   while(p->der!=ptr && sw==0)
			  if(p->codigo==cod)
				sw=1;
				else{
				    q=p;
				    p=p->der;
				    }
		   if(q==NULL){
			   if(p->der==ptr && p->codigo==cod && sw==0)
				    ptr=NULL;
			    else
				  if(p->der!=ptr && p->codigo==cod && sw==1){
					    q=p->izq;
					    q->der=p->der;
					    q=q->der;
					    q->izq=p->izq;
					    ptr=p->der;
						  delete(p);
						  }
				  }else
					if(p->der==ptr && p->codigo==cod && sw==0){
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
						 else if(p==NULL){
						   gotoxy(10,10); printf(" EL CODIGO NO EXISTE");}

						 }

		char op;
   do{
   sw=0;
   gotoxy(15,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	elim_doble_cir();
  }

void cap_doble_cir(){
    int sw=0;
    clrscr();
    nodonuevo=new NODO;

    do{
    gotoxy(10,10);
    printf("Codigo:");
	if(sw==1){
	gotoxy(10,10);
	printf("El Codigo Digitado ya Existe");
	getch();
	clreol();
	}
    validar_datos(18,10,2,nodonuevo);
   }while((sw=encontrar_circular (nodonuevo->codigo))==1);
    gotoxy(10,12);
    printf("Nombre:");
    validar_datos(20,12,1,nodonuevo);

   nodonuevo->izq=nodonuevo->der=NULL;
	  if(ptr==NULL)
	   {
		ptr=nodonuevo;
		nodonuevo->izq=ptr;
		nodonuevo->der=ptr;
	   }
		else{
			p=ptr;
			while(p->der!=ptr){
			    p=p->der;
						  }
			p->der=nodonuevo;
			nodonuevo->der=ptr;
			nodonuevo->izq=p;
		    }

   char op;
   do{
   sw=0;
   gotoxy(15,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	cap_doble_cir();
   }



	  int encontrar_doble(long cod){
	  int sw=0;
	if(ptr2==NULL)
	return 0;
	else{
	  p=ptr2;
	  while(p!=NULL && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->der;
					   }
	  if(sw==1)
	  return 1; //existe

			    }
	   return 0; //no existe
	}


  void elimDoble(){
			 char a[20];
			 int x,y,sw=0;
					long cod;
					clrscr();
   gotoxy(10,10);printf("Codigo A Eliminar:");
			  do{
			  x=0;y=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[x]!='\0'){
			 if(a[x]<'0'|| a[x] > '9' ) y=-1;
			 x++;
			 }
			}while(y==-1);
			cod=atol(a);

		p=ptr2;
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
					   ptr2=q;
					   delete(p);
					   }else
						ptr2=NULL;
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
				    gotoxy(10,14);printf("Este Codigo No Existe ");
				   getch();
				   }





			    char op;
   do{
   sw=0;
   gotoxy(15,18);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	elimDoble();
			   }


void capDoble(){
    int sw=0;
    clrscr();
    nodonuevo=new NODO;

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
    validar_datos(20,10,2,nodonuevo);
   }while((sw=encontrar_doble(nodonuevo->codigo))==1);
    gotoxy(10,12);
    printf("Nombre:");
    validar_datos(20,12,1,nodonuevo);

   nodonuevo->izq=nodonuevo->der=NULL;
	  if(ptr2==NULL)
	   {
		ptr2=nodonuevo;
		nodonuevo->izq=NULL;
		nodonuevo->der=NULL;
	   }
		else{
			p=ptr2;
			while(p->der!=NULL){
			    p=p->der;
						  }
			p->der=nodonuevo;
			nodonuevo->der=NULL;
			nodonuevo->izq=p;
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
	capDoble();
   }

 void inscola(){
	 char a[20];
	 int x,y,sw2=0;
	 long cod;
	 char *nombre;
	 clrscr();
   gotoxy(15,5);
   printf("Codigo :");
			  do{
			  x=0;y=0;
			  gets(a);
			 while(a[x]!='\0'){
			 if(a[x]<'0'|| a[x] > '9' ) y=-1;
			 x++;
			 }
			}while(y==-1);
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
	inscola();
    }

  int colavacia(struct COLAS *pq){
    return((pq->frente==pq->final) ? TRUE : FALSE);
    }
/****************************************************/
 void eliminarcola(struct COLAS *pq){
    clrscr();
    if(colavacia(pq)){
    gotoxy(10,10);printf("subdesborde en la cola ");
    getch();
    return;
    }
    if( pq->frente==MAXIMO-1){
	gotoxy(10,14);printf("Digite [ENTER] Para Volver Al menu...  ");_setcursortype(_NOCURSOR);gotoxy(10,10);printf("Codigo Eliminado :%ld",pq->COLA[pq->frente].codigo);
	gotoxy(10,10);printf("Codigo Eliminado :%ld ",pq->COLA[pq->frente].codigo);
	gotoxy(10,12);printf("Nombre Eliminado :%s" ,pq->COLA[pq->frente].nombre);
	  pq->frente=0;
	}
   else{
		gotoxy(10,14);printf("Digite [ENTER] Para Volver Al menu...  ");_setcursortype(_NOCURSOR);
		gotoxy(10,10);printf("Codigo Eliminado :%ld ",pq->COLA[pq->frente].codigo);
		gotoxy(10,12);printf("Nombre Eliminado:%s ",pq->COLA[pq->frente].nombre);
	  pq->frente++;
	  }
	  getch();
	  }


void insertarcola(struct COLAS *pq,long cod,char *nombre){
	  if(pq->final==MAXIMO-1)
	pq->final=0;
	  else
	pq->final++;
	pq->COLA[pq->final].codigo=cod;
	strcpy(pq->COLA[pq->final].nombre,nombre);
	}

  void menu()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  COLAS                ");
 strcpy(opciones[11],"  LISTA DOBLE CIRCULAR ");
 strcpy(opciones[12],"  LISTA DOBLE          ");
 strcpy(opciones[13],"  SALIR                ");
 do
 { clrscr();
   f=10; c=30;
   textcolor(2);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(2);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=10;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=13;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr(); menu_cola();break;
	   case 11 :clrscr(); menu_listadoblecircular();break;
	   case 12 :clrscr(); menu_listadoble();break;
	   case 13 :clrscr();exit(0);
	 }
 } while(f !=13);
}
void menu_cola()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INSERTAR   ");
 strcpy(opciones[11],"  ELIMINAR     ");
 strcpy(opciones[12],"  SALIR        ");
 do
 { clrscr();
   f=10; c=30;
   textcolor(2);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(2);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=12)
	   { f++;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=10;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=12;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr();inscola();break;
	   case 11 :clrscr();eliminarcola(&cola);break;
	 }
 } while(f !=12);
}
void menu_listadoble()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INSERTAR   ");
 strcpy(opciones[11],"  ELIMINAR     ");
 strcpy(opciones[12],"  VISUALIZAR   ");
 strcpy(opciones[13],"  SALIR        ");
 do
 { clrscr();
   f=10; c=30;
   textcolor(2);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(2);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=10;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=13;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr(); _setcursortype(_NORMALCURSOR);capDoble();break;
	   case 11 :clrscr(); _setcursortype(_NORMALCURSOR);elimDoble();break;
	   case 12 :clrscr(); _setcursortype(_NORMALCURSOR);visualizar_doble();break;
	 }
 } while(f !=13);
}
void menu_listadoblecircular()
{
 char opciones[25][50];
 int f,tecla;
 strcpy(opciones[10],"  INSERTAR   ");
 strcpy(opciones[11],"  ELIMINAR     ");
 strcpy(opciones[12],"  VISUALIZAR   ");
 strcpy(opciones[13],"  SALIR        ");
 do
 { clrscr();
   f=10; c=30;
   textcolor(2);textbackground(14);
   gotoxy(c,f);cprintf("%s",opciones[f]);
   textcolor(14);textbackground(2);
   do
   {
	do
	{
	 tecla=getch();
	}
	while((tecla==80)&&(tecla==72)&&(tecla==13));
	 if(tecla==80)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=13)
	   { f++;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=10;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
	 if(tecla == 72)
	 { textcolor(14);textbackground(2);
	   gotoxy(c,f);cprintf("%s",opciones[f]);
	   if (f!=10)
	   { f--;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	   else
	   { f=13;
		 textcolor(2);textbackground(14);
		 gotoxy(c,f);cprintf("%s",opciones[f]);
		 textcolor(14);textbackground(2);
	   }
	 }
   } while(tecla!=13);
	 switch(f)
	 { case 10 :clrscr(); _setcursortype(_NORMALCURSOR);cap_doble_cir();break;
	   case 11 :clrscr(); _setcursortype(_NORMALCURSOR);elim_doble_cir();break;
	   case 12 :clrscr(); _setcursortype(_NORMALCURSOR);visualizar_doble_circular();break;
	 }
 } while(f !=13);
}


void main(){
cola.frente=cola.final=MAXIMO-1;
ptr2=ptr=NULL;
menu();
}
