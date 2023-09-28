
//*********************PROGRAMA DE ARBOLES COMPLETOS***********************
//*************************************************************************
#include<stdio.h>
#include<io.h>
#include<time.h>
#include<math.h>
#include<dos.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#define color(x,y)textcolor(x);textbackground(y)
//*************************************************************************
class TREES
{

  struct arbol
  {
    char codigo[5],nombre[40],apellido[40];
    int dato;
    
    float nota1,nota2,nota3,nota4,df;
    struct arbol *izq,*sig;
    struct arbol *der;
  };struct arbol *raiz,*h,*d,*r,*nn,*p;

  public:
	TREES(struct arbol *a)
	  {raiz=a;}
	void ALARMA();
	void preorden (struct arbol *p);
	int lea_entero();
       int pila_vacia ();
	void turbo (struct arbol *p);
	void adicionar();
	void CUADRO2(int x1,int x2,int y1,int y2);
	void PROCED (struct arbol *p);
	void CUADRO3(int x1,int x2,int y1,int y2);
	void TIEMPO();
	void recorridos();
	void cuadros(int x1,int x2,int y1,int y2);
	float val_not(int z, int w );
	void mirar (struct PIAUX1 *p,struct arbol **s,int *i);
	void posorden (struct arbol *p);
	void inorden (struct arbol *p);
	void darwins();
	void completo();
	void menu();
	};
//*******************************CUADROS******************************************
//************************************************************************
 void TREES::cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
      delay(2); gotoxy(j,y1);cprintf("Í");
       delay(2);gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       delay(2);gotoxy(x1,i);cprintf("º");
       delay(2);gotoxy(x2,i);cprintf("º");
       }
     delay(2);gotoxy(x1,y1);cprintf("É");
     delay(2);gotoxy(x2,y1);cprintf("»");
     delay(2);gotoxy(x1,y2);cprintf("È");
     delay(2);gotoxy(x2,y2);cprintf("¼");
  //return(0);
}
//***************************MENU PRINCIPAL**********************************************
/*****************************************************/
void TREES::menu()
{ 

char op;
 do{
 clrscr();
 textcolor(1);
 textbackground(15);
 clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
  //************************
   CUADRO2(26,51,9,16);  
CUADRO3(26,51,9,17);
    textcolor(14);
    textcolor(14+128);
   delay(200); gotoxy (30,8); cprintf("<< MENU PRINCIPAL >>");
    
  delay(200);gotoxy(22,3);cout<<"CORPORACION UNIVERSITARIA DEL SANTANDER";  
  delay(200);gotoxy(29,5);cout<<"DARWIN HELMUTHS LEON PEREZ";
  delay(200);gotoxy(28,10);cout<<"[1]. ADICIONAR UN NODO";
  delay(200);gotoxy(28,11);cout<<"[2]. RECORRIDOS";
  delay(200);gotoxy(28,12);cout<<"[3]. ARBOLES COMPLETOS";
  delay(200);gotoxy(28,13);cout<<"[4]. PROCEDIMIENTO";
  delay(200);gotoxy(28,14);cout<<"[5]. SALIR DEL PROGRAMA";
  delay(200);gotoxy(32,22);cout<<"CODIGO: 96132068";
  //********************************************************
  textcolor(0);
  textbackground(15);
delay(200);gotoxy(28,10);cprintf("[1].");
  textcolor(1);
delay(200);gotoxy(28,11);cprintf("[2].");
  textcolor(4);
delay(200);gotoxy(28,12);cprintf("[3].");
  textcolor(14);
delay(200);gotoxy(28,13);cprintf("[4].");
  gotoxy(28,14);cprintf("[5].");	 
   delay(200); gotoxy (28,18); printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case '1':adicionar();break;
	 case '2':recorridos();break;
	 case '3':{if(raiz==NULL){ 
  clrscr();
  textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
  textcolor(4);
  textbackground(15);
  gotoxy (30,15);cprintf("<< NO EXISTEN NODOS >>");
  ALARMA();
  getche();
  menu();
  }
   else{completo();break; }
   }
	 //case '4':PROCED (raiz);break;
    /*
    case '6':consulta_administrativa();break;
    case '7':consulta_almacen();break;*/
    case '5':exit(0);
    getche();  
     }
	  }while(op!='5');
   
     }

//*************************************ADICIONAR************************************
/*****************************************************/
void TREES::adicionar()
  {
  char nombre[40],apellido[40];
  
  float nota1,not,nota2,nota3,nota4;  
  char op,info[3];
  int dato,i;
  clrscr(); i=0;
  char codigo[10];
  char nom[40];
  long int valor,lon[10];
  int cant;
  int depe;
  int j,sw,st;
  char valido;
  int n;
	textcolor(1);
	textbackground(15);
	clrscr();
 textcolor(1);
 textbackground(15);
 clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
//*************************************************************************
do
 {  
 
 textcolor(14);
 textcolor(14+128);
 gotoxy(30,5);printf("ADICIONAR NODO");
	  textcolor(1);
	 textbackground(15);
	 gotoxy(20,7);cout<<"DIGITE EL CODIGO :";
	  textcolor(1);
    
    textbackground(15);

    gotoxy(i+38,7);
     
     clreol();
     
    info[i]=getche();
    
	 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
    gotoxy(73,7);
    textcolor(14);textbackground(0);
    gotoxy(81,7);cprintf("º");
     gotoxy(79,7);cprintf("º");
     gotoxy(76,7);cprintf("º");
    if(info[i]=='\d'&&i>0) i-=2;
    
    else
     {
     if(info[i]=='\r'&&i>0) break;
     if(!isdigit(info[i])) i--;
     }
    i++;
  }while(i<5);
  
  info[i]='\0';
  dato=atoi(info);
  p=nn=raiz;
  i=1;     
  while((dato!=p->dato)&&(nn!=NULL)&&(i<=6))
  {
    p=nn;
    if(dato<p->dato)
      nn=p->izq;
    else

      nn=p->der;
    i++;
  }
  if(dato==p->dato)
    { 		gotoxy(22,18);
		textcolor(4+128);
		textcolor(4);
		textbackground(15);
		textcolor(4+128);
		cprintf("<< ESTE CODIGO YA EXISTE >>");
		ALARMA();
	
	   gotoxy(i+38,7);
	 }
  else
   if(i==6)
     {
	  gotoxy(14,12);cout<<"EL NUMERO  NO SE PUEDE INTRODUCIR";
	  }


//*************************************************************************   
  else
  {

    do
      {
	valido='n';
	gotoxy(38,8);
	cout<<"             ";
	gotoxy(20,8);cout<<"DIGITE EL NOMBRE :" ;
	gotoxy(38,8);gets(nombre);
	n=strlen(nombre);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nombre[j])))
	    {textcolor(1);textbackground(3);
	     gotoxy(20,17);
	     textbackground(15);
		textcolor(4+128);
	     textcolor(4);cprintf("<< PULSE SOLO LETRAS >>");
	     ALARMA();
	    
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
	
       }while(valido=='m');
//*************************************************************************
  do
      {
	valido='n';
	gotoxy(38,9);
	cout<<"             ";
	gotoxy(20,9);cout<<"DIGITE EL APELLIDO :" ;
	gotoxy(40,9);gets(apellido);
	n=strlen(apellido);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(apellido[j])))
	    {textcolor(1);textbackground(3);
	     gotoxy(20,17);
	     textbackground(15);
	     textcolor(4+128);
	     textcolor(4);cprintf("<< PULSE SOLO LETRAS >>");

	     ALARMA();
	    
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
       }while(valido=='m');
//*************************************************************************
   do{valido='n'; 
   gotoxy(20,10);cout<<"DIGITE LA NOTA1:\n";//nota1=val(17,4);     
   gotoxy(37,10);//cin>>nota1;
   textbackground(15);
   textcolor(1);
   
   nota1=val_not(37,10);     
   textcolor(1);
   gotoxy(37,10);
   //textbackground(15);
    //textbackground(15);
    
    CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
    gotoxy(73,10);
    textcolor(14);textbackground(0);
    gotoxy(81,10);cprintf("º");
     gotoxy(79,10);cprintf("º");
     gotoxy(76,10);cprintf("º");
   
  }while(nota1>5.0);  
//*************************************************************************
  do{
   gotoxy(42,10);cout<<"             ";
   
   gotoxy(20,11);cout<<"DIGITE LA NOTA2:";//nota1=val(17,4);     
   gotoxy(37,11);//cin>>nota2;
   textcolor(1);
   textbackground(15);
   nota2=val_not(37,11);     
   textbackground(15);
   textcolor(1);
   gotoxy(32,11);
    textbackground(15);
    
    CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
    gotoxy(73,11);
    textcolor(14);textbackground(0);
    gotoxy(81,11);cprintf("º");
     gotoxy(79,11);cprintf("º");
     gotoxy(76,11);cprintf("º");
  }while(nota2>5.0);  
//*************************************************************************
  do{
   gotoxy(42,12);cout<<"             ";
     
    gotoxy(73,10);
   gotoxy(20,12);cout<<"DIGITE LA NOTA3:";//nota1=val(17,4);     
   gotoxy(37,12);//cin>>nota3;
   textcolor(1);
   textbackground(15);
   nota3=val_not(37,12);     
   textbackground(15);
   textcolor(1);
   
    CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
    gotoxy(73,12);
    textcolor(14);textbackground(0);
    gotoxy(81,12);cprintf("º");
     gotoxy(79,12);cprintf("º");
     gotoxy(76,12);cprintf("º");
  }while(nota3>5.0);  
//*************************************************************************
 do{
     
    gotoxy(37,10);
   gotoxy(20,13);cout<<"DIGITE LA NOTA4:";//nota1=val(17,4);     
   gotoxy(37,13);//cin>>nota4;
   textcolor(1);
   textbackground(15);
   nota4=val_not(37,13);     
   textbackground(15);
   textcolor(1);
   gotoxy(32,13);
	 textbackground(15);
    
    CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
    gotoxy(73,13);
    textcolor(14);textbackground(0);
    gotoxy(81,13);cprintf("º");
     gotoxy(79,13);cprintf("º");
     gotoxy(76,13);cprintf("º");
  }while(nota4>5.0);  
  
//*************************************************************************
	  nn=new arbol;
     nn->dato=dato;
     strcpy(nn->nombre,nombre);  
     strcpy(nn->apellido,apellido);  
     nn->nota1=nota1;
     nn->nota2=nota2;
     nn->nota3=nota3;
     nn->nota4=nota4;

     nn->izq=NULL;
     nn->der=NULL;

     if(raiz==NULL)
       raiz=nn;
     else
     { 
     if(dato<p->dato)
	p->izq=nn;
       else
	p->der=nn;
     }    
     textcolor(4);
     textbackground(15);
     textcolor(4+128);
     gotoxy(25,15);cprintf("<< NODO INSERTADO >>");
  }     
       
 gotoxy(21,20);cout<<"DESEA INSERTAR OTRO NODO  [S/N]: ";
 do
 {
     gotoxy(54,20);op=toupper(getche());
 }while(op!='S'&&op!='N');

 if(op=='S')
 adicionar();
}
//***********************************MAIN**************************************
/*****************************************************/
main(){
clrscr();
TREES obj(NULL);
textbackground(15);
obj.darwins();
getche();
obj.menu();
getche();
}
//******************************PANTALLA*****************************
//*************************************************************************
void TREES::darwins()
{

CUADRO2(8,73,3,22);  
CUADRO3(8,73,2,23);
textcolor(14); textbackground(0);
delay(90);gotoxy(12,4); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
delay(90);gotoxy(12,5); cprintf("º                                                         º");
delay(90);gotoxy(12,6); cprintf("º                                                         º");
delay(90);gotoxy(12,7); cprintf("º                                                         º");
delay(90);gotoxy(12,8); cprintf("º                                                         º");
delay(90);gotoxy(12,9); cprintf("º                                                         º");
delay(90);gotoxy(12,10);cprintf("º                                                         º");
delay(90);gotoxy(12,11);cprintf("º                                                         º");
delay(90);gotoxy(12,12);cprintf("º                                                         º");
delay(90);gotoxy(12,13);cprintf("º                                                         º");
delay(90);gotoxy(12,14);cprintf("º                                                         º");
delay(90);gotoxy(12,15);cprintf("º                                                         º");
delay(90);gotoxy(12,16);cprintf("º                                                         º");
delay(90);gotoxy(12,17);cprintf("º                                                         º");
delay(90);gotoxy(12,18);cprintf("º                                                         º");
delay(90);gotoxy(12,19);cprintf("º                                                         º");
delay(90);gotoxy(12,20);cprintf("º                                                         º");
delay(90);gotoxy(12,21);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
textcolor(15+128); textbackground(0);
delay(90);gotoxy(22,20);cprintf("<< <ENTER> PARA IR AL MENU PRINCIPAL>>");
textcolor(14); textbackground(0);
textcolor(15+128);
delay(90);gotoxy(28,5);cprintf("<< ESTRUCTURA DE DATOS >>");
textcolor(14); textbackground(15);
delay(90);gotoxy(15,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
delay(90);gotoxy(15,7); cprintf("º                                                   º");
delay(90);gotoxy(15,8); cprintf("º  ÛÛÛÛÛÛ     ÛÛÛÛ    ÛÛÛÛÛÛÛ       ÛÛÛÛ     ÛÛ     º");
delay(90);gotoxy(15,9); cprintf("º ÛÛ    ÛÛ   ÛÛÛÛÛÛ    ÛÛ  ÛÛÛ     ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,10);cprintf("º ÛÛ    ÛÛ   ÛÛ   Û    ÛÛ  ÛÛÛÛ    ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,11);cprintf("º ÛÛ    ÛÛ   ÛÛ  ÛÛ    ÛÛ  ÛÛÛÛ    ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,12);cprintf("º ÛÛ    ÛÛ   Û   Û     ÛÛ  ÛÛÛÛ    ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,13);cprintf("º ÛÛÛÛÛÛÛÛ   ÛÛÛÛ      ÛÛÛÛÛÛÛÛ    ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,14);cprintf("º ÛÛ    ÛÛ   ÛÛ ÛÛ     ÛÛ  ÛÛÛÛ    ÛÛ  ÛÛ    ÛÛ     º");
delay(90);gotoxy(15,15);cprintf("º ÛÛ    ÛÛ   ÛÛ  ÛÛ    ÛÛ  ÛÛÛ     ÛÛ  ÛÛ    ÛÛ ÛÛ  º");
delay(90);gotoxy(15,16);cprintf("º ÛÛ    ÛÛ   ÛÛ   ÛÛ  ÛÛÛÛÛÛÛ       ÛÛÛÛ     ÛÛÛÛ   º");
delay(90);gotoxy(15,17);cprintf("º                                                   º");
delay(90);gotoxy(15,18);cprintf("º                                                   º");
delay(90);gotoxy(15,19);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");

textcolor(1);
gotoxy(17,18);cprintf("DERECHOS RESERVADOS DEL AUTOR: [DARWIN H. LEON P.]");

sleep(2);
gotoxy(17,18);cprintf("                                                  ");
gotoxy(19,18);cprintf("PROHIBIDO DARLE [F2] A ESTE PROGRAMA");
sleep(2);
gotoxy(19,18);cprintf("                                     ");
gotoxy(19,18);cprintf("DE HACERLO SE AUTODESTRUIRA SU DISKETTE");
sleep(2);
gotoxy(19,18);cprintf("                                       ");
}
//***********************VALIDACIN DE NOTAS**************************************************
//*************************************************************************
float TREES::val_not(int z, int w )
 { int i,n,sw,c=10;
   char nota[10];
   float not;
 do
 {
  do
   {
  gotoxy(z,w);
    sw=0;
    //gotoxy(37,10);
    textbackground(15);
    clreol();
    
    c=c++;
    scanf("\n");
    gets(nota);
    if(isdigit(nota[0])==0) sw=1;
    else 
      { if((nota[1]!='.')&&(( n=strlen(nota)-1) > 0 )) sw=1;
	else                                    
	 { n=strlen(nota);
	   if(n>1)
	    { for(i=2;i<n;i++)
	       if(isdigit(nota[i])==0) sw=1;
	    }
	 }
      }
   }while(sw==1);
  not=atof(nota);
    if((not>5)||(not<0))
      sw=1; 
   }while(sw==1);
return(not);
}
//*************************************************************************
//*************************************************************************

int TREES::lea_entero() {
	char aux[20];
	gets (aux);
	return atoi(aux);
}
//*************************************************************************
/*void ins_izq (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
}
//*************************************************************************
void ins_der (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
} */
//*************************************************************************
#define MAXIMO 20
struct PIAUX {
	int t;
	struct arbol *a[MAXIMO];
};
//***********************PROCED INORDEN**************************************************
//************************************************************
void TREES::inorden (struct arbol *p)
{
       int x;float df,s,end,start;
       struct PIAUX pila;
	void init_pila (struct PIAUX *p);
	int pila_vacia (struct PIAUX *p);
	void ins_pila (struct PIAUX *p, struct arbol *s);
	void retira_pila (struct PIAUX *p,struct arbol **s);
	init_pila (&pila);
	 x=7;
	clrscr();
 //textcolor(1);
 textbackground(15);
 cuadros(3,80,2,23);
 //cuadros(5,76,4,21);
 cuadros(7,77,3,5);
 cuadros(7,20,5,22);
 cuadros(20,34,5,22);
 cuadros(34,47,5,22);
 cuadros(47,54,5,22);
 cuadros(54,61,5,22);
 cuadros(61,67,5,22);
 cuadros(67,73,5,22);
 cuadros(73,77,5,22);
 CUADRO2(4,78,3,22);  
 textcolor(1);textbackground(15);
 textcolor(1);textbackground(15);
 gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(37,4);cprintf("APELLIDO");
 gotoxy(74,4);cprintf("DEF");
 gotoxy(49,4);cprintf("NOT1");
 gotoxy(55,4);cprintf("NOT2");
 gotoxy(63,4);cprintf("NOT3");
 gotoxy(68,4);cprintf("NOT4");

	init_pila (&pila);
	while (p) {
		   clock_t start, end;
		   start = clock();

		ins_pila (&pila,p);
		p = p->izq;
	}
	  
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);

  if(p->dato!=0){
  gotoxy(8,x);cout<<p->dato;
  gotoxy(21,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(49,x);cout<<p->nota1;
  gotoxy(55,x);cout<<p->nota2;
  gotoxy(62,x);cout<<p->nota3;
  gotoxy(68,x);cout<<p->nota4;
  
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(74,x);cout<<df;
	 
    x++;
  }		
  p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
		}
	}

end = clock();
   s=(end - start) / CLK_TCK;
	textcolor(4);textbackground(15);
	gotoxy(30,2);cprintf("The time was: %f\n",s);

}
//*************************************************************************
//****************************************************************************
void init_pila (struct PIAUX *p)
{
	p->t = 0;
}

int pila_vacia (struct PIAUX *p)
{
	return (!p->t);
}
//*************************************************************************
//**********************************************************
/*void mirar (struct PIAUX *p,struct arbol **s,int *i)
{        
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->dato [p->t -1].apunt;
			*i = p->dato [p->t -1].senal;
			p->dato [p->t - 1].senal = 1;
	}

}*/ 
//*************************************************************************
void ins_pila (struct PIAUX *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}
//*************************************************************************
void retira_pila (struct PIAUX *p,struct arbol **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}
//********************************POSORDEN*****************************************
#define MAXIMO 20

struct elemento {
	struct arbol *apunt;
	int senal;
};

struct PIAUX1 {
	int t;
	struct elemento a[MAXIMO];
};

//**************************************************************************
void TREES::posorden (struct arbol *p)
{
	int i,x;
	float df,s,end,start;

	void mirar (struct PIAUX1 *p,struct arbol **s,int *i);
	void init_pila1 (struct PIAUX1 *p);
	int pila_vacia1 (struct PIAUX1 *p);
	void ins_pila1 (struct PIAUX1 *p,struct arbol *s);
	void retira_pila1 (struct PIAUX1 *p,struct arbol **s);

	struct  PIAUX1 pila;
	init_pila1 (&pila);
		clrscr();
 //textcolor(1);
 textbackground(15);
 cuadros(3,80,2,23);
 //cuadros(5,76,4,21);
 cuadros(7,77,3,5);
 cuadros(7,20,5,22);
 cuadros(20,34,5,22);
 cuadros(34,47,5,22);
 cuadros(47,54,5,22);
 cuadros(54,61,5,22);
 cuadros(61,67,5,22);
 cuadros(67,73,5,22);
 cuadros(73,77,5,22);
  CUADRO2(4,78,3,22);  
   x=7;

 textcolor(1);textbackground(15);
 textcolor(1);textbackground(15);
 gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(37,4);cprintf("APELLIDO");
 gotoxy(74,4);cprintf("DEF");
 gotoxy(49,4);cprintf("NOT1");
 gotoxy(55,4);cprintf("NOT2");
 gotoxy(63,4);cprintf("NOT3");
 gotoxy(68,4);cprintf("NOT4");
 
	while (p) {
		   clock_t start, end;
		   start = clock();

		ins_pila1 (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia1 (&pila)) {
		
		mirar (&pila,&p,&i);
		
		if (i == 0)
			p = p->der;
		else p = NULL;
		if (p)
			while (p) {
				ins_pila1 (&pila,p);
				p = p->izq;
			}
		else {
            
				retira_pila1 (&pila,&p);
	if(p->dato!=0){
	textcolor(1);
  gotoxy(8,x);cout<<p->dato;
  gotoxy(21,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(49,x);cout<<p->nota1;
  gotoxy(55,x);cout<<p->nota2;
  gotoxy(62,x);cout<<p->nota3;
  gotoxy(68,x);cout<<p->nota4;
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(74,x);cout<<df;
	
       x++;
	}
	}
	}
end = clock();
   s=(end - start) / CLK_TCK;
	textcolor(4);textbackground(15);
	gotoxy(30,2);cprintf("The time was: %f\n",s);

}
//***************************************************************
void init_pila1 (struct PIAUX1 *p)
{
	p->t = 0;
}

int pila_vacia1 (struct PIAUX1 *p)
{
	return (!p->t);
}

void ins_pila1 (struct PIAUX1 *p,struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a[p->t - 1].apunt = s;
			p->a[p->t - 1].senal = 0;
	}
}

void retira_pila1 (struct PIAUX1 *p,struct arbol **s)
{
	if (pila_vacia1 (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1].apunt;
			p->t--;
	}
}
void mirar (struct PIAUX1 *p,struct arbol **s,int *i)
{
	if (pila_vacia1 (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1].apunt;
			*i = p->a [p->t -1].senal;
			p->a [p->t - 1].senal = 1;
	}
}





//*********************************PREORDEN****************************************
//************************************************************
#define MAXIMO 20


void TREES::preorden (struct arbol *p)
{
	int x; float df,s,end,start;
	struct PIAUX pila;
	void init_pila (struct PIAUX *p);
	int pila_vacia (struct PIAUX *p);
	void ins_pila (struct PIAUX *p, struct arbol *s);
	void retira_pila (struct PIAUX *p,struct arbol **s);
	init_pila (&pila);
	clrscr();
 //textcolor(1);
 textbackground(15);
 cuadros(3,80,2,23);
 //cuadros(5,76,4,21);
 cuadros(7,77,3,5);
 cuadros(7,20,5,22);
 cuadros(20,34,5,22);
 cuadros(34,47,5,22);
 cuadros(47,54,5,22);
 cuadros(54,61,5,22);
 cuadros(61,67,5,22);
 cuadros(67,73,5,22);
 cuadros(73,77,5,22);
  CUADRO2(4,78,3,22);  
   x=7;

 textcolor(1);textbackground(15);
 textcolor(1);textbackground(15);
 gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(37,4);cprintf("APELLIDO");
 gotoxy(74,4);cprintf("DEF");
 gotoxy(49,4);cprintf("NOT1");
 gotoxy(55,4);cprintf("NOT2");
 gotoxy(63,4);cprintf("NOT3");
 gotoxy(68,4);cprintf("NOT4");
	while (p) {
      clock_t start, end;
   start = clock();
   if(p->dato!=0){
 textbackground(15);
 textcolor(1);
 gotoxy(8,x);cout<<p->dato;
  gotoxy(21,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(49,x);cout<<p->nota1;
  gotoxy(55,x);cout<<p->nota2;
  gotoxy(62,x);cout<<p->nota3;
  gotoxy(68,x);cout<<p->nota4;

  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(74,x);cout<<df;
    x++;
    }
    ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		p = p->der;
		while (p) {

 if(p->dato!=0){
 textcolor(1);
  gotoxy(8,x);cout<<p->dato;
  gotoxy(21,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(49,x);cout<<p->nota1;
  gotoxy(55,x);cout<<p->nota2;
  gotoxy(62,x);cout<<p->nota3;
  gotoxy(68,x);cout<<p->nota4;

  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(74,x);cout<<df;
	 x++;			
	 }
	 ins_pila (&pila,p);
			p = p->izq;
		}
	}
end = clock();
   s=(end - start) / CLK_TCK;
	textcolor(4);textbackground(15);
	gotoxy(30,2);cprintf("The time was: %f\n",s);

}
//********************************ALARMA*****************************************
//*************************************************************************	
void TREES:: ALARMA()
{
	int i;
	for(i=1;i<4;i++){
		delay(100);
		sound(900);
		delay(190);
		sound(500);
		delay(100);
	}
	 nosound();
}
//**********************CUADRO3***************************************************
//****************************************************************
 void TREES::CUADRO3(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(5);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       delay(2);gotoxy(j,y1);cprintf("ÛÛ");
       delay(2);gotoxy(j,y2);cprintf("ÛÛ");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("");
       gotoxy(x2,i);cprintf("");
       }
     delay(2);gotoxy(x1,y1);cprintf("");
     delay(2);gotoxy(x2,y1);cprintf("");
     delay(2);gotoxy(x1,y2);cprintf("");
     delay(2);gotoxy(x2,y2);cprintf("");
  //return(0);
}
//*******************************CUADRO2******************************************
/*****************************************************/
//****************************

 void TREES::CUADRO2(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(5);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       delay(2);gotoxy(j,y1);cprintf("");
       delay(2);gotoxy(j,y2);cprintf("");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       delay(2);gotoxy(x1,i);cprintf("ÛÛ");
       delay(2);gotoxy(x2,i);cprintf("ÛÛ");
       }
     delay(2);gotoxy(x1,y1);cprintf("ÛÛ");
     delay(2);gotoxy(x2,y1);cprintf("ÛÛ");
     delay(2);gotoxy(x1,y2);cprintf("ÛÛ");
     gotoxy(x2,y2);cprintf("ÛÛ");
  //return(0);
}
//*************************************************************************
/*****************************************************/
void TREES::recorridos()
{
char op;
 do{
 clrscr();
 textcolor(1);
 textbackground(15);
 clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20); 
  //************************
   CUADRO2(26,51,9,16);  
CUADRO3(26,51,9,17);
    textcolor(14);
    textcolor(14+128);
delay(200);gotoxy (28,8); cprintf("<< MENU DE RECORRIDOS >>");
  textcolor(0);	 
  textbackground(15);
delay(200);gotoxy(28,10);cprintf("[1].REC.PREORDEN");
delay(200);gotoxy(28,11);cprintf("[2].REC.INORDEN ");
delay(200);gotoxy(28,12);cprintf("[3].REC.POSORDEN ");
delay(200);gotoxy(28,13);cprintf("[4].SALIR ");  
  //********************************************************
  textcolor(0);
  textbackground(15);
delay(200);gotoxy(28,10);cprintf("[1].");
  textcolor(1);
delay(200);gotoxy(28,11);cprintf("[2].");
  textcolor(4);
delay(200);gotoxy(28,12);cprintf("[3].");
  textcolor(14);
delay(200);gotoxy(28,13);cprintf("[4].");
    
delay(200);gotoxy (28,18); printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case'1':
{if(raiz==NULL){
    textbackground(15);
    clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
  CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
  textbackground(15);
  textcolor(1);
  gotoxy (30,15);cprintf("<< NO EXISTEN NODOS >>");
    ALARMA();
    menu();
    getche();}else{
 textbackground(15);textcolor(1);
 preorden (raiz);getche();break;}
 }
    case '2':
    {if(raiz==NULL){
    textbackground(15);
    clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
  CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
  textbackground(15);
  textcolor(1);
  gotoxy (30,15);cprintf("<< NO EXISTEN NODOS >>");
    ALARMA();
    menu();
    getche();}else{
 textbackground(15);textcolor(1);
 
 inorden(raiz);getche();break;}
    }
    case '3':
    {if(raiz==NULL){
    textbackground(15);
    clrscr();
 textcolor(1);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
  CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
  textbackground(15);
  textcolor(1);
  gotoxy (30,15);cprintf("<< NO EXISTEN NODOS >>");
    ALARMA();
    getche();}else{
 textbackground(15);textcolor(1);
 posorden (raiz);getche();break;}
  }
    
    getche();  
     }
     }while(op!='4');
   
	} 
//******************************ARBOLES COMPLETOS***********************	
//**********************************************************************	
void TREES::completo()
 {
  int i;
  p=r=d=h=raiz;
  
  while(r!=NULL)
  { 
	 p=r;
	 
	 if((p->izq==NULL)&&(p->der!=NULL))
	  {
		d=p;
		nn=new arbol;
		nn->dato=0;
		strcpy(nn->nombre,"x");  
		strcpy(nn->apellido,"x");  
		nn->nota1=0;
		nn->nota2=0;
		nn->nota3=0;
		nn->nota4=0;
		nn->izq=NULL;
		nn->der=NULL; 
		p->izq=nn;
		r=d->der;
		 if((r->izq!=NULL)&&(r->der!=NULL))
		  r=h->der;
	      //gotoxy(30,10);cprintf("EL ARBOL ASIDO COMPLETADO");

	    //getche();
	  }

	 else
	  {

		if((p->der==NULL)&&(p->izq!=NULL))
	  {
		d=p;
		nn=new arbol;
		nn->dato=0;
		strcpy(nn->nombre,"x");  
		strcpy(nn->apellido,"x");  
		nn->nota1=0;
		nn->nota2=0;
		nn->nota3=0;
		nn->nota4=0;
		nn->izq=NULL;
		nn->der=NULL; 
		p->der=nn;
		r=d->izq;
	  }
	  else
	  {
		r=r->izq;
	  }
	 }

	}
textcolor(1);
turbo(raiz);
getche();
menu();

}
  

/**********************************************************************/
/**********************************************************************/

 

 //***********************TIEMPO*****************************************
 //***********************************************************************
void TREES::TIEMPO()
{  float x;
   clock_t start, end;
   start = clock();

	delay(2000);

   end = clock();
   x=(end - start) / CLK_TCK;
	textcolor(4);textbackground(15);
	gotoxy(30,2);cprintf("The time was: %f\n",x);

  //return (0);
}
//**************************
//***********************PROCED INORDEN**************************************************
//************************************************************
void TREES::turbo (struct arbol *p)
{
       int x;float df,s,end,start;
       struct PIAUX pila;
	void init_pila (struct PIAUX *p);
	int pila_vacia (struct PIAUX *p);
	void ins_pila (struct PIAUX *p, struct arbol *s);
	void retira_pila (struct PIAUX *p,struct arbol **s);
	init_pila (&pila);
	 x=7;
	clrscr();
 //textcolor(1);
 textbackground(15);
 cuadros(3,80,2,23);
 //cuadros(5,76,4,21);
 cuadros(7,77,3,5);
 cuadros(7,20,5,22);
 cuadros(20,34,5,22);
 cuadros(34,47,5,22);
 cuadros(47,54,5,22);
 cuadros(54,61,5,22);
 cuadros(61,67,5,22);
 cuadros(67,73,5,22);
 cuadros(73,77,5,22);
 CUADRO2(4,78,3,22);  
 textcolor(1);textbackground(15);
 textcolor(1);textbackground(15);
 gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(37,4);cprintf("APELLIDO");
 gotoxy(74,4);cprintf("DEF");
 gotoxy(49,4);cprintf("NOT1");
 gotoxy(55,4);cprintf("NOT2");
 gotoxy(63,4);cprintf("NOT3");
 gotoxy(68,4);cprintf("NOT4");

	init_pila (&pila);
	while (p) {
		   clock_t start, end;
		   start = clock();

		ins_pila (&pila,p);
		p = p->izq;
	}
	  
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);

  gotoxy(8,x);cout<<p->dato;
  gotoxy(21,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(49,x);cout<<p->nota1;
  gotoxy(55,x);cout<<p->nota2;
  gotoxy(62,x);cout<<p->nota3;
  gotoxy(68,x);cout<<p->nota4;
  
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(74,x);cout<<df;
	 
    x++;
		
  p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
		}
	}

end = clock();
   s=(end - start) / CLK_TCK;
	textcolor(4);textbackground(15);
	gotoxy(30,2);cprintf("The time was: %f\n",s);


}
