#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <string.h>
#include <iomanip.h>
/*********************DEFINICION DE LA CLASE*********************/
class lista
{
    struct nodo{
	   char codigo[10];
	   char nombre[45];
	   char apellido[45];
	   float nota_1;
	   float nota_2;
	   float nota_3;
	   float nota_4;
	   struct nodo *ant;
	   struct nodo *sig;
	   };
	   struct nodo *ptr,*p,*nn,*q,*e,*k;
	   
     public:
	    void adicionar();
	    void eliminar();
	    void busqueda();
	    void ordenar();
	    void consulta();
	    void visualizar();
            void inicializar();
	    void captura(char cod_para[],int t,int x,int y);
            void captura1(char cod_para[],int t,int x,int y);
	    void marco(int x1,int y1,int x2,int y2);
	    void cuadro(int a,int b,int c,int d);
	    void pintura();
	    //void presentacion();
            
};


void lista::inicializar()
{
  ptr=NULL;
}
void lista::adicionar()
{
  char cod[10],nom[45],ape[45],op;
  char nt_1[3],nt_2[3],nt_3[3],nt_4[3];
  float nt1,nt2,nt3,nt4;
  int sw;
  clrscr();
 do
 {
  do
  {
    clrscr();
    sw=0;
    gotoxy(25,9);cout<<"CODIGO......: ";captura(cod,10,39,9);    //cin>>nom;
    q=ptr;                      
    while(q!=NULL)
    {
      if(strcmp(q->codigo,cod)==0){
	  marco(24,12,60,16);
	  marco(25,13,59,15);
	  gotoxy(31,14);
	  printf("EL ELEMENTO YA EXISTE");delay(1500);
	  sw=1;
	  }
       q=q->sig;
    }
    
  }while(sw==1);
  gotoxy(25,10);cout<<"NOMBRE......: ";captura1(nom,45,39,10);
  gotoxy(25,11);cout<<"APELLIDO....: ";captura1(ape,45,39,11);
  do{
      gotoxy(25,12);cout<<"NOTA_1......: ";captura(nt_1,3,39,12);
      nt1=atof(nt_1);
      if(nt1>5)
      {
	 gotoxy(39,12);clreol();
      }
     }while(nt1>5);
  do{
      gotoxy(25,13);cout<<"NOTA_2......: ";captura(nt_2,3,39,13);
      nt2=atof(nt_2);
      if(nt2>5)
      {
	 gotoxy(39,13);clreol();
      }
     }while(nt2>5);
  do{
      gotoxy(25,14);cout<<"NOTA_3......: ";captura(nt_3,3,39,14);
      nt3=atof(nt_3);
      if(nt3>5)
      {
	 gotoxy(39,14);clreol();
      }
     }while(nt3>5);
  do{
      gotoxy(25,15);cout<<"NOTA_4......: ";captura(nt_4,3,39,15);
      nt4=atof(nt_4);
      if(nt4>5)
      {
	 gotoxy(39,15);clreol();
      }
     }while(nt4>5);
  nt1=atof(nt_1);
  nt2=atof(nt_2);
  nt3=atof(nt_3);
  nt4=atof(nt_4);
  nn=new nodo;       
  strcpy(nn->codigo,cod);   
  strcpy(nn->nombre,nom);
  strcpy(nn->apellido,ape);
  nn->nota_1=nt1;
  nn->nota_2=nt2;
  nn->nota_3=nt3;
  nn->nota_4=nt4; 
  nn->ant=NULL;
  nn->sig=NULL;
  if (ptr==NULL){
     ptr=nn;
     }
  else{
       p=ptr;
       ptr=nn;
       ptr->sig=p;
       }
  gotoxy(30,17);cout<<"DESEA INGRESAR OTRO NODO S/N ";
  do{
      op=toupper(getche());sound(300);delay(100);nosound();
      if((op != 'S') && (op != 'N')){
	  gotoxy(59,16);
	  clreol();
      }
     }while ((op != 'S') && (op != 'N'));
}while (op!='N');
}



void lista::eliminar()
{
clrscr();
marco(24,12,60,16);
marco(25,13,59,15);
if (ptr==NULL){
    textcolor(128+9);
    gotoxy(35,14);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();}
else{
    e=ptr;
    ptr=ptr->sig;
    ptr->ant=NULL;
    free(e);
    gotoxy(26,14);cout<<"EL PRIMER ELEMENTO FUE ELIMINADO";sound(300);delay(100);nosound();}
getche();
}


void lista::busqueda()
{
  int sw=0;
  char cod[8];
  float final;
  clrscr();
  pintura();
  cuadro(2,2,79,23);
  marco(4,3,77,22);
  marco(3,2,78,23);
  q=ptr;
  if(q==NULL){
     marco(24,12,60,16);
     marco(25,13,59,15);
     textcolor(128+9);
     gotoxy(35,14);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();}
  else{
      textcolor(1);
      marco(22,5,61,9);
      q=ptr;
      gotoxy(23,6);cout<<"DIGITE EL CODIGO QUE DESEA BUSCAR     \n";
      gotoxy(23,8);cout<<"                                      ";
      gotoxy(23,7);
      cout<<"CODIGO =                              ";
      captura(cod,8,31,7);
      while(q!=NULL)
      {
	 if(strcmp(q->codigo,cod)==0){
	   gotoxy(25,8);
	   cout<<"EL CODIGO BUSCADO FUE ENCONTRADO"<<endl;
	   marco(22,11,61,20);
	   sw=1;
	   sound(300);delay(100);
	   sound(400);delay(200);
	   sound(300);delay(100);
	   nosound();
	   gotoxy(23,12);cout<<"       CODIGO..............           ";
	   gotoxy(23,13);cout<<"       NOMBRE..............           ";
	   gotoxy(23,14);cout<<"       APELLIDO............           ";
	   gotoxy(23,15);cout<<"       NOTA_1..............           ";
	   gotoxy(23,16);cout<<"       NOTA_2..............           ";
	   gotoxy(23,17);cout<<"       NOTA_3..............           ";
	   gotoxy(23,18);cout<<"       NOTA_4..............           ";
	   gotoxy(23,19);cout<<"       FINAL...............           ";
	   gotoxy(49,12);
	   cout<<q->codigo;
	   gotoxy(49,13);
	   cout<<q->nombre;
	   gotoxy(49,14);
	   cout<<q->apellido;
	   gotoxy(49,15);
	   cout<<setprecision(2)<<q->nota_1;
	   gotoxy(49,16);
	   cout<<setprecision(2)<<q->nota_2;
	   gotoxy(49,17);
	   cout<<setprecision(2)<<q->nota_3;
	   gotoxy(49,18);
	   cout<<setprecision(2)<<q->nota_4;
	   final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
	   gotoxy(49,19);
	   cout<<setprecision(2)<<final;
	   }
       q=q->sig;
      }
   
   if (sw==0){
   gotoxy(23,8);
   cout<<"EL CODIGO BUSCADO NO FUE ENCONTRADO";sound(300);delay(100);nosound();}
   }
   getche();

}


void lista::ordenar()
{
clrscr();
char t_codigo[10],t_nombre[45],t_apellido[45];
float t_nt1,t_nt2,t_nt3,t_nt4;
q=ptr;
if(q==NULL){
     marco(24,12,60,16);
     marco(25,13,59,15);
     textcolor(128+9);
     gotoxy(35,14);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
     getch();
     }
else{
	      e=ptr;
	      while(e->sig!=NULL){
		 e=e->sig;
	      }
	      k=ptr;
	      while(k!=e){
		q=k->sig;
		while(q!=NULL){
		 if(strcmp(q->codigo,k->codigo)<0)
		 {
		   strcpy (t_codigo,k->codigo);
		   strcpy (t_nombre,k->nombre);
		   strcpy (t_apellido,k->apellido);
		   t_nt1=k->nota_1;
		   t_nt2=k->nota_2;
		   t_nt3=k->nota_3;
		   t_nt4=k->nota_4;
		   strcpy (k->codigo,q->codigo);
		   strcpy (k->nombre,q->nombre);
		   strcpy (k->apellido,q->apellido);
		   k->nota_1=q->nota_1;
		   k->nota_2=q->nota_2;
		   k->nota_3=q->nota_3;
		   k->nota_4=q->nota_4;
		   strcpy (q->codigo,t_codigo);  
		   strcpy (q->nombre,t_nombre);
		   strcpy (q->apellido,t_apellido);
		   q->nota_1=t_nt1;
		   q->nota_2=t_nt2;
		   q->nota_3=t_nt3;
		   q->nota_4=t_nt4;
		  }
		 q=q->sig;	
		}
	      k=k->sig;
	      }
	      visualizar();
    }

}


void lista::consulta()
{
char op;
int j=5,exis=0,exis_1=0,exis_2=0;
float final;
clrscr();
  q=ptr;
  if(q==NULL)
  {
     marco(24,12,60,16);
     marco(25,13,59,15);
     textcolor(128+9);
     gotoxy(35,14);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();
  }
 else{
     clrscr();
     do{
	clrscr();
	pintura();
        cuadro(2,2,79,23);
        cuadro(20,6,62,18);
        marco(4,3,77,22);
        marco(3,2,78,23);
        marco(20,15,62,18);
        marco(20,6,62,14);
        textcolor(15);
        gotoxy(21,7);cprintf("           õõ====MENU====õõ              ");
        gotoxy(21,8);cprintf("                                         ");
        gotoxy(21,9);cprintf(" 1. ESTUDIANTES QUE GANARON DEFINITIVA   ");
        gotoxy(21,10);cprintf(" 2. ESTUDIANTES QUE PERDIERON DOS NOTAS  ");
        gotoxy(21,11);cprintf(" 3. ESTUDIANTES QUE PERDIERON DEFINITIVA "); 
        gotoxy(21,12);cprintf(" 4. EXAMEN                               ");
        gotoxy(21,13);cprintf(" 5. SALIR                                ");  
        gotoxy(21,17);cprintf("                                         ");
        gotoxy(21,16);cprintf("          ELIJA UNA OPCION               ");
        textcolor (1);
        gotoxy (48,16);
        printf ("[");
        gotoxy (50,16);
        printf ("]");
        gotoxy (49,16);
	op=getch();sound(300);delay(100);nosound();
	switch(op){
	  case '1':
		    clrscr();
		    gotoxy(25,1);cout<<"ESTUDIANTES QUE GANARON DEFINITIVA";
		    q=ptr;
		    j=5;
		    while(q!=NULL)
		    {
			 final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
			 if(final>=3)
			 {
                               exis=1;
			       gotoxy(2,3);cout<<"CODIGO";
			       gotoxy(12,3);cout<<"NOMBRE";
			       gotoxy(22,3);cout<<"APELLIDO";
			       gotoxy(34,3);cout<<"NOTA_1";
			       gotoxy(43,3);cout<<"NOTA_2";
			       gotoxy(53,3);cout<<"NOTA_3";
			       gotoxy(63,3);cout<<"NOTA_4";
			       gotoxy(75,3);cout<<"FINAL";
			       gotoxy(3,j);
			       cout<<q->codigo;
			       gotoxy(12,j);
			       cout<<q->nombre;
			       gotoxy(22,j);
			       cout<<q->apellido;
			       gotoxy(34,j);
			       cout<<setprecision(2)<<q->nota_1;
			       gotoxy(43,j);
			       cout<<setprecision(2)<<q->nota_2;
			       gotoxy(53,j);
			       cout<<setprecision(2)<<q->nota_3;
			       gotoxy(63,j);
			       cout<<setprecision(2)<<q->nota_4;
			       final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
			       gotoxy(75,j);
			       cout<<setprecision(2)<<final;  
			       j=j+1;
			 }
			    q=q->sig;
		    }
                    if(exis==0)
                    {
                        marco(24,12,60,16);
			marco(25,13,59,15);
			gotoxy(35,14);cprintf("NO    EXISTEN ");sound(300);delay(100);nosound();
                    }
		    getch();
		    break;
	       
	  case '2':
		    clrscr();
		    gotoxy(18,1);cout<<"ESTUDIANTES QUE PERDIERON A LO MAS DOS NOTAS";
		    j=5;
		    int per=0;
		    q=ptr;
		    while(q!=NULL)
		    {
                         per=0;
			 if(q->nota_1<3){per=per+1;}
			 if(q->nota_2<3){per=per+1;}
			 if(q->nota_3<3){per=per+1;}
			 if(q->nota_4<3){per=per+1;}
			 if((per>=1)&&(per<=2))
			 {
                               exis_1=1;
			       gotoxy(2,3);cout<<"CODIGO";
			       gotoxy(12,3);cout<<"NOMBRE";
			       gotoxy(22,3);cout<<"APELLIDO";
			       gotoxy(34,3);cout<<"NOTA_1";
			       gotoxy(43,3);cout<<"NOTA_2";
			       gotoxy(53,3);cout<<"NOTA_3";
			       gotoxy(63,3);cout<<"NOTA_4";
			       gotoxy(75,3);cout<<"FINAL";
			       gotoxy(3,j);
			       cout<<q->codigo;
			       gotoxy(12,j);
			       cout<<q->nombre;
			       gotoxy(22,j);
			       cout<<q->apellido;
			       gotoxy(34,j);
			       cout<<setprecision(2)<<q->nota_1;
			       gotoxy(43,j);
			       cout<<setprecision(2)<<q->nota_2;
			       gotoxy(53,j);
			       cout<<setprecision(2)<<q->nota_3;
			       gotoxy(63,j);
			       cout<<setprecision(2)<<q->nota_4;
			       final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
			       gotoxy(75,j);
			       cout<<setprecision(2)<<final;  
			       j=j+1;
			 }
			    q=q->sig;
		    }
                    if(exis_1==0)
                    {
                        marco(24,12,60,16);
			marco(25,13,59,15);
			gotoxy(35,14);cprintf("NO    EXISTEN ");sound(300);delay(100);nosound();
                    }
		    
		    getch();
		    break;

	  case '3':
		    clrscr();
		    gotoxy(25,1);cout<<"ESTUDIANTES QUE PERDIERON DEFINITIVA";
		    j=5;
		    q=ptr;
		    while(q!=NULL)
		    {
			 final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
			 if(final<3)
			 {
                               exis_2=1;
			       gotoxy(2,3);cout<<"CODIGO";
			       gotoxy(12,3);cout<<"NOMBRE";
			       gotoxy(22,3);cout<<"APELLIDO";
			       gotoxy(34,3);cout<<"NOTA_1";
			       gotoxy(43,3);cout<<"NOTA_2";
			       gotoxy(53,3);cout<<"NOTA_3";
			       gotoxy(63,3);cout<<"NOTA_4";
			       gotoxy(75,3);cout<<"FINAL";
			       gotoxy(3,j);
			       cout<<q->codigo;
			       gotoxy(12,j);
			       cout<<q->nombre;
			       gotoxy(22,j);
			       cout<<q->apellido;
			       gotoxy(34,j);
			       cout<<setprecision(2)<<q->nota_1;
			       gotoxy(43,j);
			       cout<<setprecision(2)<<q->nota_2;
			       gotoxy(53,j);
			       cout<<setprecision(2)<<q->nota_3;
			       gotoxy(63,j);
			       cout<<setprecision(2)<<q->nota_4;
			       final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
			       gotoxy(75,j);
			       cout<<setprecision(2)<<final;  
			       j=j+1;
			 }
			    q=q->sig;
		    }
                    if(exis_2==0)
                    {
                        marco(24,12,60,16);
			marco(25,13,59,15);
			gotoxy(35,14);cprintf("NO    EXISTEN ");sound(300);delay(100);nosound();
                    }

		    getch();
		    break;
	  case '4':break;
	  case '5':break;
	    }
  }while(op!='5');
 }
  clrscr();

}
void lista::visualizar()
{
  int j=4;
  float final;
  clrscr();
  marco(1,1,80,24);
  q=ptr;
  if(q==NULL){
     marco(24,12,60,16);
     marco(25,13,59,15);
     textcolor(128+9);
     gotoxy(35,14);cprintf("NO EXISTE LISTA");sound(300);delay(100);nosound();}
     else{
       gotoxy(2,2);cout<<"CODIGO";
       gotoxy(12,2);cout<<"NOMBRE";
       gotoxy(22,2);cout<<"APELLIDO";
       gotoxy(34,2);cout<<"NOTA_1";
       gotoxy(43,2);cout<<"NOTA_2";
       gotoxy(53,2);cout<<"NOTA_3";
       gotoxy(63,2);cout<<"NOTA_4";
       gotoxy(75,2);cout<<"FINAL";
       while (q!=NULL)
       {
           gotoxy(2,j);
           cout<<q->codigo;
           gotoxy(12,j);
           cout<<q->nombre;
           gotoxy(22,j);
           cout<<q->apellido;
           gotoxy(34,j);
	   cout<<setprecision(2)<<q->nota_1;
	   gotoxy(43,j);
	   cout<<setprecision(2)<<q->nota_2;
	   gotoxy(53,j);
	   cout<<setprecision(2)<<q->nota_3;
	   gotoxy(63,j);
	   cout<<setprecision(2)<<q->nota_4;
	   final=(((q->nota_1)*0.25)+((q->nota_2)*0.25)+((q->nota_3)*0.20)+((q->nota_4)*0.30));
	   gotoxy(75,j);
	   cout<<setprecision(2)<<final;  
	   q=q->sig;
	   j=j+1;
       }
   }
   getche();
}
void lista::captura(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);
	   while(c!='\r' && n_caracteres<t)
	   {
	     c=getche();
	     a++;
	     if(!isdigit(c) && c!='\r'&& !ispunct(c))
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

void lista::captura1(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);
	   while(c!='\r' && n_caracteres<t)
	   {
	     c=getche();
	     a++;
	     if(!isalpha(c) && c!='\r')
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


void lista::marco(int x1,int y1,int x2,int y2)
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


void lista::cuadro(int a,int b,int c,int d)
{
	      int f;
	     //textcolor(10);
	    // window(1,1,80,25);
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


void lista::pintura()
{
  int u;
  //textcolor(1);
  for (u=2;u<26;u++)
  {
  /* delay (2000);*/
  gotoxy(2,u);
  cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

  }
}


void main()
{
lista obj;
obj.inicializar();
char op;
do
{
textbackground (16);
clrscr();
 do
 {
    textbackground (3);
    clrscr();
    obj.pintura();
    obj.marco(1,6,80,24);
    obj.marco(3,7,78,23);
    obj.marco(28,11,57,19);
    obj.cuadro(2,2,79,4);
    textcolor (15);
    gotoxy(2,2);
    cprintf("COPORACION UNIVERSITARIA DE SANTANDER           ");
    gotoxy(48,2);
    cprintf("PROF: ALFONSO QUINTERO          ");
    gotoxy(48,3);
    cprintf("ALUN: YEISON BENAVIDES NAVARRO  ");
    gotoxy(2,3);
    cprintf("PROGRAMA CON LISTAS  DOBLEMENTE ENLAZADAS     ");
    gotoxy(2,4);
    cprintf("           VALLEDUPAR 1997                   ");
    gotoxy(13,5);
    gotoxy(47,4);
    cprintf(" COD : 96132558                  ");
    gotoxy(28,10);
    cprintf("       õõ====MENU====õõ       ");
    gotoxy (29,12);
    cprintf(" 1.ADICIONAR ELEMENTOS      \n");
    gotoxy (29,13);
    cprintf(" 2.ELIMINAR PRIMER ELEMENTO \n");
    gotoxy (29,14);
    cprintf(" 3.BUSQUEDA DE UN ESTUDIANTE\n");
    gotoxy (29,15);
    cprintf(" 4.ORDENAR LA LISTA         \n");
    gotoxy (29,16);
    cprintf(" 5.VISUALIZAR LOS ELEMENTOS \n");
    gotoxy (29,17);
    cprintf(" 6.OTRAS CONSULTAS          \n");
    gotoxy (29,18);
    cprintf(" 7.SALIR                    \n");
    gotoxy (28,20);
    cprintf("  SELECCIONE OPCION===>       ");
    textcolor (1);
    obj.cuadro(28,10,57,20);
    gotoxy (51,20);
    printf ("[");
    gotoxy (53,20);
    printf ("]");
    gotoxy (52,20);
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
	  obj.visualizar();
	 break;

 case '6':
	  obj.consulta();
	  break;

 case '7':
	  break;


 }
}while (op!='7');
clrscr();
}
/*void datos::ordenar()
{
 char nom[40],ape[40],cod[23];
 float n1,n2,n3,n4;


 p=cab;
 while(p->sig !=NULL)
 {
   p=p->sig;

 }

 ult=cab;

 while(ult !=p)
 {
  q=ult->sig;

   while(q!=NULL)
   {
    if(strcmp(q->codigo,ult->codigo)<0)
      {
	strcpy(cod,ult->codigo);
	strcpy(ult->codigo,q->codigo);
	strcpy(q->codigo,cod);

	strcpy(nom,ult->nombre);
	strcpy(ult->nombre,q->nombre);
	strcpy(q->nombre,nom);

	strcpy(ape,ult->apellido);
	strcpy(ult->apellido,q->apellido);
	strcpy(q->apellido,ape);

	   n1=ult->nota1;
	   ult->nota1=q->nota1;
	    q->nota1= n1;

	   n2=ult->nota2;
	   ult->nota2=q->nota2;
	    q->nota2= n2;

	    n3=ult->nota3;
	   ult->nota3=q->nota3 ;
	    q->nota3= n3;
	      
	    n4=ult->nota4;
	   ult->nota4=q->nota4;
	    q->nota4= n4;



      }
       q=q->sig;
   }
    ult=ult->sig;
 }
  visualizar();


} */
