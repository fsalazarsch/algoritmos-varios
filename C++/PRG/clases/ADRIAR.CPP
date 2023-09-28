#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <string.h>
#include <iomanip.h>

int j;

class arbol
{
    struct nodo{
	   char codigo[10];
	   char nombre[45];
	   char apellido[45];
	   float nota_1;
	   float nota_2;
	   float nota_3;
	   float nota_4;
	   struct nodo *izq;
	   struct nodo *der;
	   };
	      struct nodo *raiz,*nn,*p,*q;
	   struct LIFO{
	       int t;
	       struct nodo *vec[100];   
	   };

     public:
		 void mayor();

		 void inicializar_pila(struct LIFO *);
		 int pila_vacia(struct LIFO *);
		 void incertar_pila(struct LIFO *,struct nodo *);
		 void sacar_pila(struct LIFO *,struct nodo **);
		 void inicializar_arbol();
		 void adicionar();
		 void eliminar();
		 void busqueda();
		 void ordenar();
		 void consulta();
		 void modificar();
		 void inorden(struct nodo *);
		 void preorden(struct nodo *);
		 void postorden(struct nodo *);
                 void pantalla();
                 void ins_der(struct nodo *p , char[]);
                 void ins_izq(struct nodo *p , char[]);
		 void captura(char cod_para[],int t,int x,int y);
		 void captura1(char cod_para[],int t,int x,int y);
		 void marco(int x1,int y1,int x2,int y2);
		 void cuadro(int a,int b,int c,int d);
		 void pintura();
				
};


void arbol::inicializar_pila(struct LIFO *r)
{
  r->t=0;
}


int arbol::pila_vacia(struct LIFO *r)
{
  return(!r->t);

}


void arbol::incertar_pila(struct LIFO *r,struct nodo *s)
{
  if(r->t==100)
     cout<<"DESBORDAMIENTO";
  else{
       r->t++;
       r->vec[r->t-1]=s;
  }
}




void arbol::sacar_pila(struct LIFO *r,struct nodo **s)
{
   if(pila_vacia(r))
   {
      cout<<"LA PILA ESTA VACIA";
      *s=NULL;
   }
   else{
	*s=r->vec[r->t-1];
	r->t--;
   }
}





void arbol::inicializar_arbol()
{
  raiz=NULL;
}




void arbol::adicionar()
{
  char cod[10],nom[45],ape[45],op;
  char nt_1[3],nt_2[3],nt_3[3],nt_4[3];
  float nt1,nt2,nt3,nt4;
  int sw;
  clrscr();
 do
 {
    clrscr();
    textcolor(1);
    textbackground(3);
    window(1,1,80,25);
    clrscr();
    pintura();
    cuadro(2,2,79,23);       
    textbackground(0);
    window(13,4,70,22);
    clrscr();
    textbackground(15);
    window(12,3,69,21);
    clrscr();
    gotoxy(17,3);textcolor(128+15);cprintf("!! A D I C I O N A N D O !!");
    textcolor(1);
    if(raiz==NULL)
    {
	gotoxy(4,7);cout<<"CODIGO  : ";
	textcolor(15);
        captura(cod,10,13,7);
	textcolor(1);
	gotoxy(23,8);cout<<"NOMBRE    : ";
	gotoxy(23,9);cout<<"APELLIDO  : ";
	gotoxy(23,10);cout<<"NOTA_1    : ";
	gotoxy(23,11);cout<<"NOTA_2    : ";
	gotoxy(23,12);cout<<"NOTA_3    : ";
	gotoxy(23,13);cout<<"NOTA_4    : ";
	textcolor(15);
	captura1(nom,45,34,8);
	captura1(ape,45,34,9);
	do{
	    captura(nt_1,3,34,10);
	    nt1=atof(nt_1);
	    if(nt1>5)
	    {
		gotoxy(34,10);clreol();
	    }
	}while(nt1>5);
	do{
	    captura(nt_2,3,34,11);
	    nt2=atof(nt_2);
	    if(nt2>5)
	    {
		gotoxy(34,11);clreol();
	    }
	}while(nt2>5);
	do{
	    captura(nt_3,3,34,12);
	    nt3=atof(nt_3);
	    if(nt3>5)
	    {
		gotoxy(34,12);clreol();
	    }
	}while(nt3>5);
	do{
	    captura(nt_4,3,34,13);
	    nt4=atof(nt_4);
	    if(nt4>5)
	    {
		gotoxy(34,13);clreol();
	    }
	}while(nt4>5);
	nt1=atof(nt_1);
	nt2=atof(nt_2);
	nt3=atof(nt_3);
	nt4=atof(nt_4);
	raiz=new nodo;       
	strcpy(raiz->codigo,cod);   
	strcpy(raiz->nombre,nom);
	strcpy(raiz->apellido,ape);
	raiz->nota_1=nt1;
	raiz->nota_2=nt2;
	raiz->nota_3=nt3;
	raiz->nota_4=nt4; 
        raiz->izq=NULL;
        raiz->der=NULL;
    }
    else
    {
      do{
         sw=0;
         gotoxy(4,7);cout<<"CODIGO  : ";
	 textcolor(15);
         gotoxy(13,7);
	 clreol();
         captura(cod,10,13,7);
         p=q=raiz;
	 while(q !=NULL && strcmp(p->codigo,cod)!=0)
	 {
		p=q;
		if (strcmp(cod,p->codigo)<0)
		   q = q->izq;
		else
		  q = q->der;
	       
	 }
         if (strcmp(cod,p->codigo)==0)
	 {
             textcolor(1);
	     cuadro(19,16,43,16);
	     gotoxy(20,16);
	     printf("EL ESTUDIANTE YA EXISTE");delay(1500);
	     gotoxy(18,16);
	     clreol();
	     gotoxy(18,15);
	     clreol();
	     gotoxy(18,17);
	     clreol();
             sw=1;
         }
         if(sw==0)
	 {
	      if (strcmp(cod,p->codigo)<0)
		 ins_izq(p,cod);
	      else
		 ins_der(p,cod);
         }
       }while(sw==1);   
    }         
	do{
            textbackground(1);
            window(24,18,54,18);
            clrscr();
            gotoxy(25,19);cout<<"DESEA INGRESAR OTRO NODO S/N ";
            op=toupper(getche());sound(300);delay(100);nosound();
            if((op != 'S') && (op != 'N'))
            {
	        gotoxy(52,19);
	        clreol();
            }
          }while ((op != 'S') && (op != 'N'));
}while (op!='N');
}


void arbol::ins_der(struct nodo *p , char cod[])
{
   char nom[45],ape[45],op;
   char nt_1[3],nt_2[3],nt_3[3],nt_4[3];
   float nt1,nt2,nt3,nt4;
   nn = new nodo;
   strcpy(nn->codigo,cod);
   gotoxy(23,8);cout<<"NOMBRE    : ";
   gotoxy(23,9);cout<<"APELLIDO  : ";
   gotoxy(23,10);cout<<"NOTA_1    : ";
   gotoxy(23,11);cout<<"NOTA_2    : ";
   gotoxy(23,12);cout<<"NOTA_3    : ";
   gotoxy(23,13);cout<<"NOTA_4    : ";
   textcolor(15);
   captura1(nom,45,34,8);
   captura1(ape,45,34,9);
   do{
       captura(nt_1,3,34,10);
       nt1=atof(nt_1);
       if(nt1>5)
       {
	gotoxy(34,10);clreol();
       }
   }while(nt1>5);
   do{
       captura(nt_2,3,34,11);
       nt2=atof(nt_2);
       if(nt2>5)
       {
	gotoxy(34,11);clreol();
       }
   }while(nt2>5);
   do{
       captura(nt_3,3,34,12);
       nt3=atof(nt_3);
       if(nt3>5)
       {
	gotoxy(34,12);clreol();
       }
   }while(nt3>5);
   do{
       captura(nt_4,3,34,13);
       nt4=atof(nt_4);
       if(nt4>5)
       {
	gotoxy(34,13);clreol();
       }
   }while(nt4>5);
   nt1=atof(nt_1);
   nt2=atof(nt_2);
   nt3=atof(nt_3);
   nt4=atof(nt_4);
   strcpy(nn->codigo,cod);   
   strcpy(nn->nombre,nom);
   strcpy(nn->apellido,ape);
   nn->nota_1=nt1;
   nn->nota_2=nt2;
   nn->nota_3=nt3;
   nn->nota_4=nt4; 
   nn->izq=NULL;
   nn->der=NULL;
   p->der =nn;

}



void arbol::ins_izq(struct nodo *p , char cod[])
{
   char nom[45],ape[45],op;
   char nt_1[3],nt_2[3],nt_3[3],nt_4[3];
   float nt1,nt2,nt3,nt4;
   nn = new nodo;
   strcpy(nn->codigo,cod);
   gotoxy(23,8);cout<<"NOMBRE    : ";
   gotoxy(23,9);cout<<"APELLIDO  : ";
   gotoxy(23,10);cout<<"NOTA_1    : ";
   gotoxy(23,11);cout<<"NOTA_2    : ";
   gotoxy(23,12);cout<<"NOTA_3    : ";
   gotoxy(23,13);cout<<"NOTA_4    : ";
   textcolor(15);
   captura1(nom,45,34,8);
   captura1(ape,45,34,9);
   do{
       captura(nt_1,3,34,10);
       nt1=atof(nt_1);
       if(nt1>5)
       {
	gotoxy(34,10);clreol();
       }
   }while(nt1>5);
   do{
       captura(nt_2,3,34,11);
       nt2=atof(nt_2);
       if(nt2>5)
       {
	gotoxy(34,11);clreol();
       }
   }while(nt2>5);
   do{
       captura(nt_3,3,34,12);
       nt3=atof(nt_3);
       if(nt3>5)
       {
	gotoxy(34,12);clreol();
       }
   }while(nt3>5);
   do{
       captura(nt_4,3,34,13);
       nt4=atof(nt_4);
       if(nt4>5)
       {
	gotoxy(34,13);clreol();
       }
   }while(nt4>5);
   nt1=atof(nt_1);
   nt2=atof(nt_2);
   nt3=atof(nt_3);
   nt4=atof(nt_4);
   strcpy(nn->codigo,cod);   
   strcpy(nn->nombre,nom);
   strcpy(nn->apellido,ape);
   nn->nota_1=nt1;
   nn->nota_2=nt2;
   nn->nota_3=nt3;
   nn->nota_4=nt4; 
   nn->izq=NULL;
   nn->der=NULL;
   p->izq =nn;

}






void arbol::eliminar()
{
    float final;
    char cod[10],op,op1;
    struct nodo *sw,*u,*nuevo;
    clrscr();
    textcolor(1);
    textbackground(3);
    window(1,1,80,25);
    clrscr();
    pintura();
    cuadro(2,2,79,23);       
    textbackground(0);
    window(13,4,70,22);
    clrscr();
    textbackground(15);
    window(12,3,69,21);
    clrscr();
    if(raiz==NULL)
    {
       textbackground(4);
       window(30,9,50,10);
       clrscr();
       gotoxy(3,1);textcolor(128+15);cprintf("   LO SIENTO ");
       gotoxy(3,2);textcolor(128+15);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
       getch();
    }
  else
  {
    gotoxy(17,3);textcolor(128+15);cprintf("!! E L I M I N A N D O !!");
    textcolor(1);
    gotoxy(4,7);cout<<"CODIGO  : ";
    textcolor(15);
    captura(cod,10,13,7);
    gotoxy(17,5);textcolor(1);cprintf("BUSCANDO ALUMNO");
    delay(2000);
    u=NULL;
    p=nuevo=raiz;
    while(strcmp(cod,p->codigo)!=0&&(nuevo!=NULL))
    {
       u=p;
       p=nuevo;
       if(strcmp(cod,p->codigo)<0)
           nuevo=p->izq;
       else
           nuevo=p->der;
     }
     if(strcmp(cod,p->codigo)!=0)
     {
           clrscr();
           gotoxy(17,3);textcolor(128+15);cprintf("!! E L I M I N A N D O !!");
           textcolor(15);
           textbackground(1);
           window(25,9,61,10);
           clrscr();
           sound(300);delay(100);
           sound(400);delay(200);
           sound(300);delay(100);
           nosound();
           gotoxy(15,1);textcolor(128+15);cout<<"LO SIENTO";
           gotoxy(2,2);textcolor(128+15);
           textcolor(1);
           cout<<"EL CODIGO BUSCADO NO FUE ENCONTRADO";sound(300);delay(100);nosound();
     }
  else
  { 
    textcolor(15);
    textbackground(1);
    window(25,7,58,7);
    clrscr();
    gotoxy(2,1);cout<<"ESTE ES EL REGISTRO A ELIMINAR"<<endl;
    sound(300);delay(100);
    sound(400);delay(200);
    sound(300);delay(100);
    nosound();
    textbackground(1);
    window(30,10,57,18);
    clrscr();
    gotoxy(2,2);cout<<" NOMBRE........";
    gotoxy(2,3);cout<<" APELLIDO......";
    gotoxy(2,4);cout<<" NOTA_1........";
    gotoxy(2,5);cout<<" NOTA_2........";
    gotoxy(2,6);cout<<" NOTA_3........";
    gotoxy(2,7);cout<<" NOTA_4........";
    gotoxy(2,8);cout<<" FINAL.........";
    gotoxy(16,2);
    cout<<p->nombre;
    gotoxy(16,3);
    cout<<p->apellido;
    gotoxy(16,4);
    cout<<setprecision(2)<<p->nota_1;
    gotoxy(16,5);
    cout<<setprecision(2)<<p->nota_2;
    gotoxy(16,6);
    cout<<setprecision(2)<<p->nota_3;
    gotoxy(16,7);
    cout<<setprecision(2)<<p->nota_4;
    final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
    gotoxy(16,8);
    cout<<setprecision(2)<<final;
    do{
            textbackground(1);
            window(24,20,54,20);
            clrscr();
            gotoxy(25,21);cout<<"DESEA ELIMINARLO S/N ";
            op=toupper(getche());sound(300);delay(100);nosound();
            if((op != 'S') && (op != 'N'))
            {
	        gotoxy(52,19);
	        clreol();
            }
      }while ((op != 'S') && (op != 'N'));
    if(op=='S')
    {
       clrscr();
       if(p->izq==NULL)
          nuevo=p->der;
       else
          if(p->der==NULL)
             nuevo=p->izq;
          else
          { 
             q=p;
	     nuevo=q->der;
	     sw=nuevo->izq;
	     while(sw!=NULL)
	     { 
                q=nuevo;
	        nuevo=sw;
	        sw=nuevo->izq;
	     }
	     if(q!=p)
	     { 
                q->izq=nuevo->der;
	        nuevo->der=p->der;
	     }
	        nuevo->izq=p->izq;
          }
          if(u==NULL)
	      raiz=nuevo;
          else
	  { 
              if(p==u->izq) u->izq=nuevo;
	      else u->der=nuevo;
	  }
          //p->izq=p->der=NULL;
          free(p);
          textbackground(15);
          window(12,7,69,21);
          clrscr();
          textbackground(1);
          window(25,9,61,10);
          gotoxy(7,7);textcolor(128+15);
          cout<<"FUE ELIMINADO";sound(300);delay(100);nosound();
          sound(300);delay(100);
          sound(400);delay(200);
          sound(300);delay(100);
          nosound();
          
    }

  }
  do{
      textcolor(15);
      textbackground(1);
      window(24,20,54,20);
      clrscr();
      gotoxy(25,21);cout<<"DESEA SEGUIR ELIMINANDO S/N ";
      op1=toupper(getche());sound(300);delay(100);nosound();
      if((op1 != 'S') && (op1 != 'N'))
      {
         gotoxy(52,19);
         clreol();
      }
     }while ((op1 != 'S') && (op1 != 'N'));

   if(op1=='S')
    eliminar();
 }
}

void arbol::busqueda()
{
  char cod[10],op1;
  float final;
  int sw=0;
  clrscr();
  textcolor(1);
  textbackground(3);
  window(1,1,80,25);
  clrscr();
  pintura();
  cuadro(2,2,79,23);       
  textbackground(0);
  window(13,4,70,22);
  clrscr();
  textbackground(15);
  window(12,3,69,21);
  clrscr();
  if(raiz==NULL)
    {
       textbackground(4);
       window(30,9,50,10);
       clrscr();
       gotoxy(3,1);textcolor(128+15);cprintf("   LO SIENTO ");
       gotoxy(3,2);textcolor(128+15);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
       getch();
    }
  else
  {

  gotoxy(2,12);cout<<"CODIGO : ";
  textcolor(15);
  captura(cod,10,10,12);
  gotoxy(17,3);textcolor(128+15);cprintf("!!   B U S C A N D O   !!");
  delay(1000);
  textcolor(15);
  p=raiz;
  q=raiz;
  while(q !=NULL && strcmp(p->codigo,cod)!=0)
  {
  	p=q;
	if (strcmp(cod,p->codigo)<0)
	   q = q->izq;
	else
	  q = q->der;
  }
  if (strcmp(cod,p->codigo)==0)
  {
      textbackground(1);
      window(25,7,58,7);
      clrscr();
      gotoxy(2,1);cout<<"EL CODIGO BUSCADO FUE ENCONTRADO"<<endl;
      sound(300);delay(100);
      sound(400);delay(200);
      sound(300);delay(100);
      nosound();
      textbackground(1);
      window(30,10,57,18);
      clrscr();
      gotoxy(2,2);cout<<" NOMBRE........";
      gotoxy(2,3);cout<<" APELLIDO......";
      gotoxy(2,4);cout<<" NOTA_1........";
      gotoxy(2,5);cout<<" NOTA_2........";
      gotoxy(2,6);cout<<" NOTA_3........";
      gotoxy(2,7);cout<<" NOTA_4........";
      gotoxy(2,8);cout<<" FINAL.........";
      gotoxy(16,2);
      cout<<p->nombre;
      gotoxy(16,3);
      cout<<p->apellido;
      gotoxy(16,4);
      cout<<setprecision(2)<<p->nota_1;
      gotoxy(16,5);
      cout<<setprecision(2)<<p->nota_2;
      gotoxy(16,6);
      cout<<setprecision(2)<<p->nota_3;
      gotoxy(16,7);
      cout<<setprecision(2)<<p->nota_4;
      final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
      gotoxy(16,8);
      cout<<setprecision(2)<<final;
      sw=1;
  }
  if(sw==0)
  {
      textbackground(1);
      window(25,9,61,10);
      clrscr();
      sound(300);delay(100);
      sound(400);delay(200);
      sound(300);delay(100);
      nosound();
      gotoxy(15,1);textcolor(128+15);cout<<"LO SIENTO";
      gotoxy(2,2);textcolor(128+15);
      cout<<"EL CODIGO BUSCADO NO FUE ENCONTRADO";sound(300);delay(100);nosound();
  }
  do{
      textcolor(15);
      textbackground(1);
      window(24,20,54,20);
      clrscr();
      gotoxy(25,21);cout<<"DESEA SEGUIR BUSCANDO S/N ";
      op1=toupper(getche());sound(300);delay(100);nosound();
      if((op1 != 'S') && (op1 != 'N'))
      {
         gotoxy(52,19);
         clreol();
      }
     }while ((op1 != 'S') && (op1 != 'N'));

   if(op1=='S')
     busqueda();
  }
   
}

void arbol::ordenar()
{
   if(raiz==NULL)
    {
       clrscr();
       textcolor(1);
       textbackground(3);
       window(1,1,80,25);
       clrscr();
       pintura();
       cuadro(2,2,79,23);       
       textbackground(0);
       window(13,4,70,22);
       clrscr();
       textbackground(15);
       window(12,3,69,21);
       clrscr();
       textbackground(4);
       window(30,9,50,10);
       clrscr();
       gotoxy(3,1);textcolor(128+15);cprintf("   LO SIENTO ");
       gotoxy(3,2);textcolor(128+15);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
       getch();
    }
  else
  {

   j=5;
   pantalla();
   inorden(raiz);
   getch();
  }
}


void arbol::preorden(struct nodo *p)
{
  float final;
  struct LIFO pila;
  inicializar_pila(&pila);
  while(p)
  {
    gotoxy(3,j);
    cout<<p->codigo;
    gotoxy(12,j);
    cout<<p->nombre;
    gotoxy(22,j);
    cout<<p->apellido;
    gotoxy(34,j);
    cout<<setprecision(2)<<p->nota_1;
    gotoxy(43,j);
    cout<<setprecision(2)<<p->nota_2;
    gotoxy(53,j);
    cout<<setprecision(2)<<p->nota_3;
    gotoxy(63,j);
    cout<<setprecision(2)<<p->nota_4;
    final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
    gotoxy(75,j);
    cout<<setprecision(2)<<final;  
    j=j+1;
    incertar_pila(&pila,p);
    p=p->izq;
  }
  while(!pila_vacia(&pila))
  {
     sacar_pila(&pila,&p);
     p=p->der;
     while(p)
     {
	gotoxy(3,j);
	cout<<p->codigo;
	gotoxy(12,j);
	cout<<p->nombre;
	gotoxy(22,j);
	cout<<p->apellido;
	gotoxy(34,j);
	cout<<setprecision(2)<<p->nota_1;
	gotoxy(43,j);
	cout<<setprecision(2)<<p->nota_2;
	gotoxy(53,j);
	cout<<setprecision(2)<<p->nota_3;
	gotoxy(63,j);
	cout<<setprecision(2)<<p->nota_4;
	final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
	gotoxy(75,j);
	cout<<setprecision(2)<<final;  
	j=j+1;
	incertar_pila(&pila,p);
	p=p->izq;
     }
  }
}   



void arbol::postorden(struct nodo *p)
{
   float final;
   if(p!=NULL)
   {
    postorden(p->izq);
    postorden(p->der);
    gotoxy(3,j);
    cout<<p->codigo;
    gotoxy(12,j);
    cout<<p->nombre;
    gotoxy(22,j);
    cout<<p->apellido;
    gotoxy(34,j);
    cout<<setprecision(2)<<p->nota_1;
    gotoxy(43,j);
    cout<<setprecision(2)<<p->nota_2;
    gotoxy(53,j);
    cout<<setprecision(2)<<p->nota_3;
    gotoxy(63,j);
    cout<<setprecision(2)<<p->nota_4;
    final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
    gotoxy(75,j);
    cout<<setprecision(2)<<final;  
    j=j+1;
    }
}



void arbol::inorden(struct nodo *p)
{
    float final;
    struct LIFO pila;
    inicializar_pila(&pila);
    while(p)
    {
	 incertar_pila(&pila,p);
	 p=p->izq;
    }
    while(!pila_vacia(&pila))
    {
	sacar_pila(&pila,&p);
	gotoxy(3,j);
	cout<<p->codigo;
	gotoxy(12,j);
	cout<<p->nombre;
	gotoxy(22,j);
	cout<<p->apellido;
	gotoxy(34,j);
	cout<<setprecision(2)<<p->nota_1;
	gotoxy(43,j);
	cout<<setprecision(2)<<p->nota_2;
	gotoxy(53,j);
	cout<<setprecision(2)<<p->nota_3;
	gotoxy(63,j);
	cout<<setprecision(2)<<p->nota_4;
	final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
	gotoxy(75,j);
	cout<<setprecision(2)<<final;  
	j=j+1;
	p=p->der;
	while(p)
	{
	    incertar_pila(&pila,p);
	    p=p->izq;
	}
    }
}


void arbol::consulta()
{
 char op;
 clrscr();
 textbackground(3);
 window(1,1,80,25);
 clrscr();
 pintura();
 cuadro(2,2,79,23);       
 textbackground(0);
 window(26,4,58,7);
 clrscr();
 textbackground(15);
 window(25,3,57,6);
 clrscr();         
 cuadro(3,2,31,3);
 gotoxy(5,2);textcolor(128+15);cprintf("‘‘ R E C O R R I D O S ‘‘");
 textcolor(1);
 if(raiz==NULL)
 {
       textbackground(4);
       window(30,9,50,10);
       clrscr();
       gotoxy(3,1);textcolor(128+15);cprintf("   LO SIENTO ");
       gotoxy(3,2);textcolor(128+15);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
       getch();
 }
 else
 {


 do{
    clrscr();
    textcolor(1);
    textbackground(3);
    window(1,1,80,25);
    clrscr();
    pintura();
    cuadro(2,2,79,23);       
    textbackground(0);
    window(26,4,58,7);
    clrscr();
    textbackground(15);
    window(25,3,57,6);
    clrscr();         
    cuadro(3,2,31,3);
    gotoxy(5,2);textcolor(128+15);cprintf("‘‘ R E C O R R I D O S ‘‘");
    textcolor(1);
    textbackground(0);
    window(26,10,58,19);
    clrscr();
    textbackground(15);
    window(25,9,57,18);
    clrscr();
    cuadro(3,2,31,9);
    gotoxy(5,2);
    cprintf("    õõ====MENU====õõ");
    gotoxy (3,4);
    cprintf(" 1.RECORRIDO PREORDEN \n");
    gotoxy (3,5);
    cprintf(" 2.RECORRIDO INORDEN \n");
    gotoxy (3,6);
    cprintf(" 3.RECORRIDO POSTORDEN\n");
    gotoxy (3,7);
    cprintf(" 4.SALIR\n");
    gotoxy (3,9);
    cprintf("  SELECCIONE OPCION===> ");
    gotoxy (28,9);
    printf ("[");
    gotoxy (30,9);
    printf ("]");
    gotoxy (29,9);
    op=getch();sound(300);delay(100);nosound();
    switch (op)
    {
       case'1':
               j=5;
               pantalla();
	       preorden(raiz);
               getch();
               break;
       case'2':
               j=5;
               pantalla();
               inorden(raiz);
               getch();
               break;
       case'3':
               j=5;
               pantalla();
               postorden(raiz);
               getch();
               break;
       case'4':
         	break;
	 } 

  }while(op!='4');
  clrscr();
 }
}


void arbol::pantalla()
{
               clrscr();
               textcolor(1);
               textbackground(3);
               window(1,1,80,25);
               clrscr();
               cuadro(2,2,79,23);       
               gotoxy(2,3);cout<<"CODIGO";
	       gotoxy(12,3);cout<<"NOMBRE";
	       gotoxy(22,3);cout<<"APELLIDO";
	       gotoxy(34,3);cout<<"NOTA_1";
	       gotoxy(43,3);cout<<"NOTA_2";
	       gotoxy(53,3);cout<<"NOTA_3";
	       gotoxy(63,3);cout<<"NOTA_4";
	       gotoxy(75,3);cout<<"FINAL";
}



void arbol::modificar()
{
  char cod[10],nom[45],ape[45],op1,op;
  char nt_1[3],nt_2[3],nt_3[3],nt_4[3];
  float final,nt1,nt2,nt3,nt4;
  int sw=0;
  clrscr();
  textcolor(1);
  textbackground(3);
  window(1,1,80,25);
  clrscr();
  pintura();
  cuadro(2,2,79,23);       
  textbackground(0);
  window(13,4,70,22);
  clrscr();
  textbackground(15);
  window(12,3,69,21);
  clrscr();
  gotoxy(15,3);textcolor(128+15);cprintf("!!   M O D I F I C A N D O   !!");
  textcolor(1);
  if(raiz==NULL)
    {
       textbackground(4);
       window(30,9,50,10);
       clrscr();
       gotoxy(3,1);textcolor(128+15);cprintf("   LO SIENTO ");
       gotoxy(3,2);textcolor(128+15);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
       getch();
    }
  else
  {
  gotoxy(2,12);cout<<"CODIGO : ";
  textcolor(15);
  captura(cod,10,10,12);
  delay(1000);
  textcolor(15);
  p=raiz;
  q=raiz;
  while(q !=NULL && strcmp(p->codigo,cod)!=0)
  {
  	p=q;
	if (strcmp(cod,p->codigo)<0)
	   q = q->izq;
	else
	  q = q->der;
  }
  if (strcmp(cod,p->codigo)==0)
  {
      textbackground(1);
      window(25,7,58,7);
      clrscr();
      gotoxy(2,1);cout<<"EL CODIGO BUSCADO FUE ENCONTRADO"<<endl;
      sound(300);delay(100);
      sound(400);delay(200);
      sound(300);delay(100);
      nosound();
      textbackground(1);
      window(30,10,57,18);
      clrscr();
      gotoxy(2,2);cout<<" NOMBRE........";
      gotoxy(2,3);cout<<" APELLIDO......";
      gotoxy(2,4);cout<<" NOTA_1........";
      gotoxy(2,5);cout<<" NOTA_2........";
      gotoxy(2,6);cout<<" NOTA_3........";
      gotoxy(2,7);cout<<" NOTA_4........";
      gotoxy(2,8);cout<<" FINAL.........";
      gotoxy(16,2);
      cout<<p->nombre;
      gotoxy(16,3);
      cout<<p->apellido;
      gotoxy(16,4);
      cout<<setprecision(2)<<p->nota_1;
      gotoxy(16,5);
      cout<<setprecision(2)<<p->nota_2;
      gotoxy(16,6);
      cout<<setprecision(2)<<p->nota_3;
      gotoxy(16,7);
      cout<<setprecision(2)<<p->nota_4;
      final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
      gotoxy(16,8);
      cout<<setprecision(2)<<final;
      sw=1;
  }
  if(sw==0)
  {
      textbackground(1);
      window(25,9,61,10);
      clrscr();
      sound(300);delay(100);
      sound(400);delay(200);
      sound(300);delay(100);
      nosound();
      gotoxy(15,1);textcolor(128+15);cout<<"LO SIENTO";
      gotoxy(2,2);textcolor(128+15);
      cout<<"EL CODIGO BUSCADO NO FUE ENCONTRADO";sound(300);delay(100);nosound();
  }
  if(sw==1)
  {
   do{
      textcolor(15);
      textbackground(1);
      window(24,20,54,20);
      clrscr();
      gotoxy(25,21);cout<<"   DESEA MODIFICARLO S/N ";
      op1=toupper(getche());sound(300);delay(100);nosound();
      if((op1 != 'S') && (op1 != 'N'))
      {
         gotoxy(52,19);
         clreol();
      }
     }while ((op1 != 'S') && (op1 != 'N'));
  }
   if(op1=='S')
   {
      
      textcolor(15);
      textbackground(1);
      window(30,10,57,18);
      clrscr();
      gotoxy(2,2);cout<<" NOMBRE........";
      gotoxy(2,3);cout<<" APELLIDO......";
      gotoxy(2,4);cout<<" NOTA_1........";
      gotoxy(2,5);cout<<" NOTA_2........";
      gotoxy(2,6);cout<<" NOTA_3........";
      gotoxy(2,7);cout<<" NOTA_4........";
      captura1(nom,45,17,2);
      captura1(ape,45,17,3);
      do{
	  captura(nt_1,3,17,4);
	  nt1=atof(nt_1);
	  if(nt1>5)
	  {
	gotoxy(17,4);clreol();
	  }
      }while(nt1>5);
      do{
	  captura(nt_2,3,17,5);
	  nt2=atof(nt_2);
	  if(nt2>5)
	  {
	gotoxy(17,5);clreol();
	  }
      }while(nt2>5);
      do{
	  captura(nt_3,3,17,6);
	  nt3=atof(nt_3);
	  if(nt3>5)
	  {
	gotoxy(17,6);clreol();
	  }
      }while(nt3>5);
      do{
	  captura(nt_4,3,17,7);
	  nt4=atof(nt_4);
	  if(nt4>5)
	  {
	gotoxy(17,7);clreol();
	  }
      }while(nt4>5);
      nt1=atof(nt_1);
      nt2=atof(nt_2);
      nt3=atof(nt_3);
      nt4=atof(nt_4);
      strcpy(p->codigo,cod);
      strcpy(p->nombre,nom);
      strcpy(p->apellido,ape);
      p->nota_1=nt1;
      p->nota_2=nt2;
      p->nota_3=nt3;
      p->nota_4=nt4; 
    }
    do{
      textcolor(15);
      textbackground(1);
      window(24,20,54,20);
      clrscr();
      gotoxy(25,21);cout<<"DESEA SEGUIR MODIFICANDO S/N ";
      op=toupper(getche());sound(300);delay(100);nosound();
      if((op != 'S') && (op != 'N'))
      {
         gotoxy(52,19);
         clreol();
      }
     }while ((op != 'S') && (op != 'N'));
    if(op=='S')
    {
      modificar();
    }

  }
  
}




void arbol::captura(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);

           while(c!='\r' && n_caracteres<t)
	   {
	     c=getche();
             a++;
	     if(c=='\r'&& n_caracteres==0)
	     {
		c=' ';
		n_caracteres=0;
	     }
	     if(!isdigit(c) && !ispunct(c))
	     {
	     gotoxy(a,y);
	     clreol();
	     a--;
	     }
	      else
	      {
	      cod_para[n_caracteres]=c;
	      n_caracteres++;
	      }
	    }
	    cod_para[n_caracteres]='\0';
	    
}


/******************** VALIDACION LETRAS ***************************/

void arbol::captura1(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);
	   while(c!='\r' && n_caracteres<t)
	   {
	     c=getche();
	     a++;
	     if(c=='\r'&& n_caracteres==0)
	     {
		c=' ';
		n_caracteres=0;
	     }

	     if(!isalpha(c) )
	     {
	     gotoxy(a,y);
	     clreol();
	     a--;
	     }
	      else
	      {
	      cod_para[n_caracteres]=c;
	      n_caracteres++;
	      }
	    }
	    cod_para[n_caracteres]='\0';
	    
}


void arbol::cuadro(int a,int b,int c,int d)
{
	      int f;
	     gotoxy(a-1,b-1);
	    cprintf("É");
	    for(f=a;f<=c;f++)
	      cprintf("Í");
	       cprintf("»");
	       for(f=b;f<=d;f++){
	       gotoxy(c+1,f);
	       cprintf("º");}
	       gotoxy(a-1,d+1);
	       cprintf("È");
	     for(f=a;f<=c;f++)
	       cprintf("Í");
	       cprintf("¼");
	      for(f=b;f<=d;f++){
	      gotoxy(a-1,f);
	      cprintf("º");}
}


void arbol::marco(int x1,int y1,int x2,int y2)
{
  int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);}
}

void arbol::pintura()
{
  int u;
  for (u=1;u<26;u++)
  {             
  gotoxy(1,u);
  cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

  }
}


void arbol::mayor()
{
    clrscr();
    char cod[10];
    int j=5;
    float final;
    struct LIFO pila;
    clrscr();
    textcolor(1);
    textbackground(3);
    window(1,1,80,25);
    clrscr();
    cuadro(2,2,79,23);
    gotoxy(5,5);
    cout<<"DIGITE CODIGO";
    captura(cod,10,19,5);
    clrscr();
    pantalla();
	      
    /************************/
    inicializar_pila(&pila);
    p=raiz;
    while(p)
    {
	 incertar_pila(&pila,p);
	 p=p->izq;
    }
    while(!pila_vacia(&pila))
    {
	sacar_pila(&pila,&p);
	if(strcmp(p->codigo,cod)>0)
	{
	  gotoxy(3,j);
	  cout<<p->codigo;
	  gotoxy(12,j);
	  cout<<p->nombre;
	  gotoxy(22,j);
	  cout<<p->apellido;
	  gotoxy(34,j);
	  cout<<setprecision(2)<<p->nota_1;
	  gotoxy(43,j);
	  cout<<setprecision(2)<<p->nota_2;
	  gotoxy(53,j);
	  cout<<setprecision(2)<<p->nota_3;
	  gotoxy(63,j);
	  cout<<setprecision(2)<<p->nota_4;
	  final=(((p->nota_1)*0.25)+((p->nota_2)*0.25)+((p->nota_3)*0.20)+((p->nota_4)*0.30));
	  gotoxy(75,j);
	  cout<<setprecision(2)<<final;
	  j=j+1;
	}
	delay(300);
	p=p->der;
	while(p)
	{
	    incertar_pila(&pila,p);
	    p=p->izq;
	}
}
getch();



}





void main()
{
arbol obj;
obj.inicializar_arbol();
char op;
do
{
clrscr();
textcolor(1);
 do
 {
    clrscr();
    textbackground(3);
    window(1,1,80,25);
    clrscr();
    obj.pintura();
    textbackground(0);
    window(3,3,79,7);
    clrscr();
    textbackground(15);
    window(2,2,78,6);
    clrscr();
    obj.cuadro(3,2,75,4);
    gotoxy(3,2);
    cprintf("COPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy(46,2);
    cprintf("PROF: ALFONSO QUINTERO");
    gotoxy(46,3);
    cprintf("ALUN: YEISON BENAVIDES NAVARRO");
    gotoxy(3,3);
    cprintf("PROGRAMA CON ARBOLES BINARIOS ");
    gotoxy(3,4);
    cprintf("       VALLEDUPAR 1997");
    gotoxy(46,4);
    cprintf("COD : 96132558");
    textbackground(0);
    window(26,10,58,22);
    clrscr();
    textbackground(15);
    window(25,9,57,21);
    clrscr();
    obj.cuadro(3,2,31,12);
    gotoxy(5,2);
    cprintf("    õõ====MENU====õõ");
    gotoxy (3,4);
    cprintf(" 1.ADICIONAR ELEMENTOS      \n");
    gotoxy (3,5);
    cprintf(" 2.ELIMINAR REGISTRO \n");
    gotoxy (3,6);
    cprintf(" 3.BUSQUEDA DE UN ESTUDIANTE\n");
    gotoxy (3,7);
    cprintf(" 4.ORDENAR LA LISTA         \n");
    gotoxy (3,8);
    cprintf(" 5.MODIFICAR \n");
    gotoxy (3,9);
    cprintf(" 6.RECORRIDOS  \n");
    gotoxy (3,10);
    cprintf(" 7.MAYOR                    \n");
    gotoxy (3,11);
    cprintf(" 8.SALIR                    \n");

    gotoxy (3,12);
    cprintf("  SELECCIONE OPCION===> ");
    gotoxy (28,12);
    printf ("[");
    gotoxy (30,12);
    printf ("]");
    gotoxy (29,12);
    op=getch();sound(300);delay(100);nosound();
 }while ((op>'7')||(op<'1'));
 switch (op)
 {
 case'1':
	 obj.adicionar();
	 break;
 case'2':
	 obj.eliminar();
	 break;
 case'3':
	 obj.busqueda();
	 break;
 case'4':
	 obj.ordenar();
	 break;
 case '5':
	 obj.modificar();
	 break;

 case '6':
	 obj.consulta();
	  break;

 case '7':
	  obj.mayor();break;
 case '8':
	  break;


 }
}while (op!='8');
clrscr();
}

  
