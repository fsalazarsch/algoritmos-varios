#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<io.h>
# define memo (struct nodo*)malloc(sizeof(struct nodo));

struct nodo{
   int info;
   char nombre[45];
   struct nodo*ant;
   struct nodo*sig;
   };
	struct nodo*cab,*q,*p,*q2,*nn,*c;

/**************************************************************************/
char nom[45];
char nomb[45];
void menu_principal();
void menu_2();
void menu_3();   
void menu_4();
void menu_5();
void menu_6();
void menu_7();
//void menu_8();
void menu_9();
void creacion();
void eli_fi();
void eli_princi();
void nodo_dado();
void visualizar();
void inser_entre();
void inser_princi();
void inser_final();
void creacion2();
void eli_fi2();
void eli_princi2();
void nodo_dado2();
void visualizar2();
void inser_entre2();
void inser_princi2();
void inser_final2();
void inicializar();
/****************CUADRO**************************/


void cuadro(int x1,int x2,int y1,int y2)
 {  
 int j,i,k;
 clrscr();
 for(j=x1;j<=x2;j++)
 {
 gotoxy(j,y1);cprintf("Í");
 gotoxy(j,y2);cprintf("Í");
 }
 for(i=y1;i<=y2;i++)
 {
 gotoxy(x1,i);cprintf("º");
 gotoxy(x2,i);cprintf("º");
 }
 gotoxy(x1,y1);cprintf("É");
 gotoxy(x2,y1);cprintf("»");
 gotoxy(x1,y2);cprintf("È");
 gotoxy(x2,y2);cprintf("¼");
 }
void inicializar()
{
  cab=NULL;
 // p=NULL;
}


void main(){
void inicializar();
menu_principal();
 }

void creacion()
{
 int i,val;
 char op;

      window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);


 gotoxy(25,1);printf("CREACION DE LA LISTA");

do{

	  gotoxy(25,3); printf("DIGITE LA REFERENCIA: ");
	  scanf("%d",&val);

	  gotoxy(25,5); printf("DIGITE EL NOMBRE DEL ARTICULO: ");
	  scanf("\n");	gets(nom);

	  if(cab==NULL)
	  {
		 q=memo;
		 q->info=val;
		 strcpy(q->nombre,nom);
		 q->sig=NULL;
		 q->ant=NULL;
		 p=q;
		 cab=q;
	  }
	  else
	  {
	  nn=memo
	  nn->info=val;
	  strcpy(nn->nombre,nom);
	  p->sig=nn;
	  nn->ant=p;
	  nn->sig=NULL;
	  p=nn;


	  }
	 clrscr();
	 gotoxy(15,20); printf("DESEA INGRESAR OTRO ");
	 op=toupper(getche());
	  }
	  while(op=='S');



}
void eli_fi()
{

    window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

    if(cab==NULL)
    {
      printf("NO SE PUEDE ELIMINAR LISTA VACIA");
      }
      else{

    q2=cab->sig;
    p=cab;


    while(q2!=NULL)
    {
     if(q2==NULL)
     {
       q2->ant=NULL;
       free(q2);
       p->sig=NULL;
     }
	p=p->sig;
	q2=q2->sig;
     }
  }
}
/*******************************************************/
void eli_princi()
{
  char op;
  window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);


  p=cab;

  gotoxy(10,3);printf("AQUI SE ELIMINA LA CABEZA ");

do{
    gotoxy(2,7);printf("DESEA ELIMINAR LA CABEZA DE LA LISTA (S/N) ");
    gotoxy(45,7);op=toupper(getch());
    gotoxy(45,7);clreol();
 }while((op!='N')&&(op!='S'));
    if (op=='S')
    {
      cab=cab->sig;
      p->sig=NULL;
      free(p);
     }


}

/*******************************************************************/
void nodo_dado()
{

   char op,sw=0;
   int eli,dato;
   window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

   p=cab;
   q=p;
   gotoxy(13,1); printf("E L I M I N A C I O N   D E  U N   N O D O   D A D O  ");
   textcolor(4);
   gotoxy(10,7); printf("DIGITE LA REFERENCIA DEL NODO QUE DESEA ELIMINAR:  ");
    scanf("%d",&eli);
    if(q->info==eli)
    {
      cab=q->sig;
      p=q->sig;
      free(q);
      sw=1;
      //break;
      }
      else
      {

	 if (p->sig==NULL)
	 {
	   gotoxy(10,9); printf("NO SE PUEDE ELIMINAR");
	 }
	 else
	 //si esta al final
		{
		  p=cab;
		  q=p->sig;
			while(p != NULL)
			{   p=p->sig;
				q=p->sig;
			}
			if(p->info==eli)
		 {

		 p->sig=NULL;
		 q->ant=NULL;
		 free(p);
		 sw=1;
		 //break;
		 }

		  p=cab;
		  q=p->sig;
		  while(p->sig!=NULL)
			{
		if(q->info==eli)
		 {
		 p->sig=q->sig;
		 q2=q->sig;
		 q2->ant=p;
		 free(q);
		 sw=1;
		 break;
		 }
		 p=p->sig;
		 q=p->sig;
	      }
	   }
     }
  if(sw==0)
  {
   textcolor(3);
   gotoxy(10,10); printf("LA REFERENCIA DIGITADO NO EXISTE");
  }
   getch();


}

/**************************************************************************/
void visualizar()
{
  window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

  gotoxy(10,5); printf("DATOS GUARDADOS EN LA LISTA");
  q=cab;
  if(q==NULL)
  {
   gotoxy(20,15);printf("NO EXISTEN DATOS");
  }
    else
     {           clrscr();
		 while(q!=NULL)
		  {

		  gotoxy(8,10);printf("REFERENCIA :%d",q->info);
		  gotoxy(8,12);printf("NOMBRE :%s",q->nombre);

			  q=q->sig;
		  getche();clrscr();
		 }
	}

}
void inser_entre()
{
  char op,sw=0;
   int eli,dato;
   window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

   p=cab;
   q2=cab->sig;
   q=p;
   gotoxy(13,1); printf("I N S E R C I O N  D E  U N   N O D O   D A D O  ");
   textcolor(4);
   gotoxy(10,7); printf("DIGITE LA REFERENCIA GUIA:  ");
    scanf("%d",&eli);
    clrscr();
    gotoxy(15,2);printf("DATOS DEL NUEVO NODO");
    gotoxy(10,7); printf("DIGITE LA REFERENCIA:  ");
    scanf("%d",&dato);
    gotoxy(10,9); printf("DIGITE EL NOMBRE:  ");
    scanf("\n");gets(nom);

    nn=memo;
		 nn->info=dato;
		 strcpy(nn->nombre,nom);
	       //	 nn->sig=NULL;
		// nn->ant=NULL;

		  //CABEZA

    if(q->info==eli)
    {
      nn->sig=cab->sig;
      cab->sig=nn;
      nn->ant=cab;
      q2->ant=nn;

      }
      else
      {

	 if (cab==NULL)
	 {
	   gotoxy(10,9); printf("NO SE PUEDE INSERTAR");
	 }
	 else
	 //si esta al final
		{
		  p=cab;
		  q2=p->sig;
			while(p != NULL)
			{   p=p->sig;
				q2=p->sig;
			}
			if(q2->info==eli)
			{

			  q2->sig=nn;
			  nn->ant=q2;
			  nn->sig=NULL;
			  sw=1;
			}
		  // else{
		  p=cab;
		  q2=p->sig;
		  while(p->sig!=NULL)
			{
		if(q2->info==eli)
		 {
		 nn->sig=q2->sig;
		 q2->sig=nn;
		 nn->ant=q2;
		 p=q2->sig;
		 p->ant=nn;

		 sw=1;
		 break;
		 }
		 p=p->sig;
		 q2=p->sig;
	      }
	   }
     }
  if(sw==0)
  {
   textcolor(3);
   gotoxy(10,10); printf("EL NODO QUIA NO EXISTE");
  }
   getch();




}

/*************************************************************************/
void inser_princi()
{
   int valor;
 char op;
  window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

 gotoxy(25,1);printf("INSERCION DE UN NODO AL PRINCIPIO DE LA LISTA");

 if(p==NULL)
 printf("NO SE PUEDE INSERTAR");
 else
 {
 do{
    gotoxy(5,4); printf("DIGITE EL VALOR A INGRESAR A LA LISTA:  ");
	  scanf("%d",&valor);

     if(cab==NULL)
     {
	 q=memo;
	 q->info=valor;
	 q->sig=NULL;
	 q->ant=NULL;
	 q=cab;
	 p=q;
     }

      else{
      q=memo;
      q->info=valor;
		q->sig=cab;
		cab->ant=q;
		cab=q;
		//q->sig=p;
	  // cab=q;
	  }


     clrscr();
    gotoxy(15,20); printf("DESEA INGRESAR OTRO  AL PRINCIPIO");
										 op=toupper(getche());
	  }while(op=='S');
 }

}

/*****************************************************************/
void inser_final()
{
    int valor;
    char op;
     window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

    gotoxy(25,1);printf("INSERCION DE UN NODO AL FINAL DE LA LISTA");
    p=cab;

    do{

	gotoxy(5,4); printf("DIGITE EL VALOR A INGRESAR A LA LISTA:  ");
	scanf("%d",&valor);

	  q=memo;
	  q->info=valor;
	  q->sig=NULL;
	  q->ant=NULL;

		 if(cab==NULL)
		 {
		cab->sig=q;
		q->ant=cab;
		}

		 else
		 {
			 p=cab;
			 while(p->sig!=NULL)
			 {
			  p=p->sig;  }

			  p->sig=q;
			  q->ant=p;
			  q->sig=NULL;
		  }

	   clrscr();
	   gotoxy(15,20); printf("DESEA INGRESAR OTRO NODO AL FINAL ");
										 op=toupper(getche());
    }while(op=='S');


 }









/*************************listas dobles circulares****************/
void creacion2()
{
  //struct nodo*cab2,*q2,*p2,*q3,*nn2,*c2;
 int i,val;
 char op;

 window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

 gotoxy(25,1);printf("CREACION DE LA LISTA");

do{

	gotoxy(25,3);  printf("DIGITE LA REFERENCIA: ");
	  scanf("%d",&val);
	gotoxy(25,5); printf("DIGITE EL NOMBRE DEL ARTICULO: ");
	scanf("\n");gets(nomb);

	  if(cab==NULL)
	  {
		 cab=memo;
		 cab->info=val;
		 strcpy(cab->nombre,nomb);
		 cab->sig=cab;
		 cab->ant=cab;
		 p=cab;
		// cab=q;
	  }
	  else
	  {
	  nn=memo
	  nn->info=val;
	  strcpy(nn->nombre,nomb);
	  p->sig=nn;
	  nn->ant=p;
	  nn->sig=cab;
	  cab->ant=nn;
	  p=nn;


	  }
	 clrscr();
    gotoxy(15,20); printf("DESEA INGRESAR OTRO ");
	 op=toupper(getche());
	  }
	  while(op=='S');


}
void eli_fi2()
{
}
void eli_princi2()
{
   char op;
   window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);


  p=cab;
  c=cab;
  clrscr();
  gotoxy(10,3);printf("AQUI SE ELIMINA LA CABEZA ");

do{
    gotoxy(2,7);printf("DESEA ELIMINAR LA CABEZA DE LA LISTA (S/N) ");
    gotoxy(45,7);op=toupper(getch());
    gotoxy(45,7);clreol();
 }while((op!='N')&&(op!='S'));
    if (op=='S')
    {
      cab=cab->sig;
      p->sig=cab;
      cab->ant=p;
      free(c);
     }


}
/*********************************************************/
void nodo_dado2()
{
    char op,sw=0;
   int eli,dato;
   window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

   c=cab;
   q=c;

   gotoxy(13,1); printf("E L I M I N A C I O N   D E  U N   N O D O   D A D O  ");
   textcolor(4);
   gotoxy(10,7); printf("DIGITE LA REFERENCIA QUE DESEA ELIMINAR:  ");
    scanf("%d",&eli);
    if(q->info==eli)
    {
      cab=q->sig;
      c=q->sig;
      p->sig=cab;
      cab->ant=p;
      free(q);
      sw=1;
      }
      else
      {

	 if (cab==NULL)
	 {
	   gotoxy(10,9); printf("NO SE PUEDE ELIMINAR");
	 }
	 else
	 //si esta al final
		{
		  c=cab;
		  q=c->sig;
			while(c != p)
			{
			   c=c->sig;
			}
			if(p->info==eli)
		   {

		      c->sig=NULL;
		      p->ant=NULL;
		     free(p);
		     c=p;
		     sw=1;
		   }

		  c=cab;
		  q=c->sig;
		  while(c->sig!=p)
			{
			p=cab;
		if(q->info==eli)
		 {
		 c->sig=q->sig;
		 q2=q->sig;
		 q2->ant=c;
		 free(q);
		 sw=1;
		 }
		 c=c->sig;
		 q=c->sig;
	      }
	   }
     }
  if(sw==0)
  {
   textcolor(3);
   gotoxy(10,10); printf("EL NODO DIGITADO NO EXISTE");
  }
   getch();



}
void visualizar2()
{
   window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

   gotoxy(10,5); printf("DATOS GUARDADOS EN LA LISTA");
 q=cab;
 if(cab==NULL)
  {
   gotoxy(20,15);printf("NO EXISTEN DATOS");
  }
    else
     {
	   while(p->sig!=cab){
	  p=p->sig;}

		 while(q != p)
		  { // printf("\n");
		       gotoxy(10,8);printf(" REFERENCIA: %d \n ",q->info);
		       gotoxy(10,10);printf(" NOMBRE: %s \n ",q->nombre);
			  q=q->sig;
			  p=cab;
			getche();clrscr();
		 }
	}



}
void inser_entre2()
{
}
void inser_princi2()
{
   int valor;
 char op;

 window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);


 gotoxy(25,1);printf("INSERCION DE UN NODO AL PRINCIPIO DE LA LISTA");

 if(p==NULL)
 printf("NO SE PUEDE INSERTAR");
 else
 {
 do{
    gotoxy(5,4); printf("DIGITE LA REFERENCIA:  ");
	  scanf("%d",&valor);
    gotoxy(5,6); printf("DIGITE EL NOMBRE:  ");
       scanf("\n");gets(nomb);

     if(cab==NULL)
     {
	 q=memo;
	 q->info=valor;
	 strcpy(q->nombre,nomb);
	 q->sig=cab;
	 q->ant=cab;
	 q=cab;
	// p=cab;
     }

      else{
      q=memo;
      q->info=valor;
      strcpy(q->nombre,nomb);
		q->sig=cab;
		cab->ant=q;
		cab=q;
		p->sig=cab;
		q->ant=p;
		//q->sig=p;
	  // cab=q;
	  }


     clrscr();
    gotoxy(15,20); printf("DESEA INGRESAR OTRO  AL PRINCIPIO");
										 op=toupper(getche());
	  }while(op=='S');
 }


}
void inser_final2()
{
      int valor;
    char op;
    window(1,1,80,25);
	 clrscr();
	 textattr(BLUE);
	 textbackground(BLUE);
	 textcolor(14);

    gotoxy(25,1);printf("INSERCION DE UN NODO AL FINAL DE LA LISTA");
    p=cab;

    do{

	gotoxy(5,4); printf("DIGITE EL VALOR A INGRESAR A LA LISTA:  ");
	scanf("%d",&valor);

	  q=memo;
	  q->info=valor;
	  q->sig=NULL;
	  q->ant=NULL;

		 if(cab==NULL)
		 {
		cab->sig=q;
		q->ant=cab;
		}

		 else
		 {
			 p=cab;
			 while(p->sig!=NULL)
			 {
			  p=p->sig;  }

			  p->sig=q;
			  q->ant=p;
			  q->sig=NULL;
		  }

	   clrscr();
	   gotoxy(15,20); printf("DESEA INGRESAR OTRO NODO AL FINAL ");
										 op=toupper(getche());
    }while(op=='S');


}
void menu_principal()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr();	textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(8,1);cprintf("MENU  PRINCIPAL");
 gotoxy(5,3);cprintf("1. LISTAS DOBLES");
 gotoxy(5,4);cprintf("2. LISTAS CIRCULARES");
 gotoxy(5,5);cprintf("5. COLAS ");
 gotoxy(5,6);cprintf("6. FINALIZAR");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();
 if(tecla==72)
 {
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); menu_2(); break; }
 case 4: { textcolor(14);textbackground(BLUE); menu_5(); break;}
 case 5: { textcolor(14);textbackground(BLUE); menu_9(); break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 }
/***************************************************************************/
void menu_2()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf(" LISTAS DOBLES ");
 gotoxy(5,3);cprintf("1. CREACION");
 gotoxy(5,4);cprintf("2. ELIMINACION");
 gotoxy(5,5);cprintf("3. VISUALIZAR ");
 gotoxy(5,6);cprintf("5. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); menu_3(); break; }
 case 4: { textcolor(14);textbackground(BLUE); menu_4(); break;}
 case 5: { textcolor(14);textbackground(BLUE); visualizar();break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 } 
/*********************************************/
void menu_3()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf(" LISTAS DOBLES: CREACION ");
 gotoxy(5,3);cprintf("1. CREACION");
 gotoxy(5,4);cprintf("2. INSERCION AL PRINCIPIO");
 gotoxy(5,5);cprintf("3. INSERCION AL FINAL ");
 gotoxy(5,6);cprintf("5. INSERCION ENTRE ");
 gotoxy(5,7);cprintf("6. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+4); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==7)
 {
 gotoxy(3,wherey()-4); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==7) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); creacion(); break; }
 case 4: { textcolor(14);textbackground(BLUE); inser_princi(); break;}
 case 5: { textcolor(14);textbackground(BLUE); inser_final(); break;}
 case 6: { textcolor(14);textbackground(BLUE); inser_entre();break; } 
 case 7: exit(0);
 }
 }
 } while(SALIR!='S');
 } 
/*************************************************************************/
void menu_4()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf(" LISTAS DOBLES: ELIMINACION ");
 gotoxy(5,3);cprintf("1. ELIMINAR AL PRINCIPIO");
 gotoxy(5,4);cprintf("2. ELIMINAR AL FINAL");
 gotoxy(5,5);cprintf("3. ELIMINAR UN NODO DADO");
 gotoxy(5,6);cprintf("4. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); eli_princi();break; }
 case 4: { textcolor(14);textbackground(BLUE); eli_fi();break; }
 case 5: { textcolor(14);textbackground(BLUE); nodo_dado();break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 }
/**************************************************************************/  
void menu_5()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf(" LISTAS CIRCULARES ");
 gotoxy(5,3);cprintf("1. CREACION");
 gotoxy(5,4);cprintf("2. ELIMINACION");
 gotoxy(5,5);cprintf("3. VISUALIZAR ");
 gotoxy(5,6);cprintf("5. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); menu_6(); break; }
 case 4: { textcolor(14);textbackground(BLUE); menu_7(); break;}
 case 5: { textcolor(14);textbackground(BLUE); visualizar2();break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 } 
/*********************************************/
void menu_6()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf("LISTAS CIRCULAERES: CREACION");
 gotoxy(5,3);cprintf("1. CREACION");
 gotoxy(5,4);cprintf("2. INSERCION AL PRINCIPIO");
 gotoxy(5,5);cprintf("3. INSERCION AL FINAL ");
 gotoxy(5,6);cprintf("5. INSERCION ENTRE ");
 gotoxy(5,7);cprintf("6. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+4); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==7)
 {
 gotoxy(3,wherey()-4); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==7) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); creacion2(); break; }
 case 4: { textcolor(14);textbackground(BLUE); inser_princi2(); break;}
 case 5: { textcolor(14);textbackground(BLUE); inser_final2(); break;}
 case 6: { textcolor(14);textbackground(BLUE); inser_entre2();break; } 
 case 7: exit(0);
 }
 }
 } while(SALIR!='S');
 } 
/*************************************************************************/
void menu_7()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf("LISTAS CIRCULARES: ELIMINACION");
 gotoxy(5,3);cprintf("1. ELIMINAR AL PRINCIPIO");
 gotoxy(5,4);cprintf("2. ELIMINAR AL FINAL");
 gotoxy(5,5);cprintf("3. ELIMINAR UN NODO DADO");
 gotoxy(5,6);cprintf("4. SALIR ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE); eli_princi2();break; }
 case 4: { textcolor(14);textbackground(BLUE); eli_fi2();break; }
 case 5: { textcolor(14);textbackground(BLUE); nodo_dado2();break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 } 
/*************************************************************************/
/*void menu_8()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf("  PILAS  ");
 gotoxy(5,3);cprintf("1. ");
 gotoxy(5,4);cprintf("2. ");
 gotoxy(5,5);cprintf("3. ");
 gotoxy(5,6);cprintf("5. ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE);  break; }
 case 4: { textcolor(14);textbackground(BLUE);  break;}
 case 5: { textcolor(14);textbackground(BLUE);  break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 } */

/*************************************************************************/
void menu_9()
{
  int f,op,i,c;
 char tecla,SALIR;
 do{
 _setcursortype(_NOCURSOR);clrscr();
 clrscr();window(1,2,80,25);textbackground(BLUE);
 for(i=0;i<1920;i++) { textcolor(14); cprintf("±"); }
 window(26,8,57,16); clrscr();textbackground(BLUE);  //ventana de menu
 SALIR='N';
 clrscr(); textbackground(BLUE);textcolor(14);cuadro(1,31,1,9);
 gotoxy(2,1);cprintf("  COLAS ");
 gotoxy(5,3);cprintf("1. ");
 gotoxy(5,4);cprintf("2. ");
 gotoxy(5,5);cprintf("3. ");
 gotoxy(5,6);cprintf("5. ");
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);
 do{
 tecla=getch();

 if(tecla==72)
 { 
 cprintf(" ");
 if(wherey()==3)
 {
 gotoxy(3,wherey()+3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()-1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 if(tecla==80)
 {
 cprintf(" ");
 if(wherey()==6)
 {
 gotoxy(3,wherey()-3); cprintf("%c",2);
 gotoxy(3,wherey());
 }
 else{
 gotoxy(3,wherey()+1);cprintf("%c",2);
 gotoxy(3,wherey());
 }
 }
 } while(tecla!=13);
 op=wherey();
 if(op==6) { SALIR='S'; }
 else{
 switch(op)
 {
 case 3: { textcolor(14);textbackground(BLUE);  break; }
 case 4: { textcolor(14);textbackground(BLUE);  break;}
 case 5: { textcolor(14);textbackground(BLUE);  break; }
 case 6: exit(0);
 }
 }
 } while(SALIR!='S');
 } 


