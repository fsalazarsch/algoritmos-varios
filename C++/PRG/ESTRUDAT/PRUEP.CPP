#include<stdio.h>
#include<io.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<time.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#define color(x,y)textcolor(x);textbackground(y)



class arboles
{

  struct arbol
  {
    char codigo[5],nombre[40],apellido[40];
    int dato;
    float nota1,nota2,nota3,nota4;
    struct arbol *izq,*sig;
    struct arbol *der;
  };struct arbol *raiz,*nn,*p;

  public:
	arboles(struct arbol *a){raiz=a;}
	void adicionar();
	void cuadros(int x1,int x2,int y1,int y2);
	float val_not(int z, int w );
	void darwins();
	void menu();
	};

//************************************************************************
 void arboles::cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
  //return(0);
}

/*****************************************************/
void arboles::menu()
{ 

char op;
 do{
 clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
  
    textcolor(4);
    //normvideo;
    gotoxy (30,8); cout<<"<< MENU PRINCIPAL >>";
    
  gotoxy(22,3);cout<<"CORPORACION UNIVERSITARIA DEL SANTANDER";  
  gotoxy(29,5);cout<<"DARWIN HELMUTHS LEON PEREZ";
  gotoxy(32,22);cout<<"CODIGO: 96132068";
  gotoxy(28,10);cout<<"[1]. ADICIONAR UN NODO";
  gotoxy(28,11);cout<<"[2]. ELIMINAR UN NODO";
  gotoxy(28,12);cout<<"[3]. RECORRER LA LISTA";
  gotoxy(28,13);cout<<"[4]. CONSULTAR POR CODIGO";
  gotoxy(28,14);cout<<"[5]. CONSULTAR RECURSOS HUMANOS";
  gotoxy(28,15);cout<<"[6]. CONSULTA ADMINISTRATIVA";
  gotoxy(28,16);cout<<"[7]. CONSULTA ALMACEN";
  gotoxy(28,17);cout<<"[8]. SALIR DEL PROGRAMA..";
  
    
    gotoxy (28,18); printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case '1':adicionar();break;
    /*case '2':eliminar_nodo();break;
    case '3':recorer_lista();break;
    case '4':consultar_codigo();break;
    case '5':consultar_recursos_humanos();break;
    case '6':consulta_administrativa();break;
    case '7':consulta_almacen();break;*/
    case '8':exit(0);
    getche();  
     }
     }while(op!='8');
   
     }


/*****************************************************/
void arboles::adicionar()
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
	textcolor(4);
	textbackground(15);
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
do
 {  
 
 textcolor(4);
 gotoxy(30,5);printf("ADICIONAR NODO");
	  textcolor(4);
	 textbackground(15);
	 gotoxy(20,7);cout<<"DIGITE EL CODIGO :";//gotoxy(37,7);gets(codigo);
	  textcolor(4);
    
    textbackground(15);

    gotoxy(i+38,7);
     clreol();
     
    info[i]=getche();
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
  p=nn=raiz;i=1;     
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
		cout<<"<< ESTE CODIGO YA EXISTE >>";
		sound(500);
	    delay(1000);
	    nosound();
	   gotoxy(i+38,7);
	 }
  else
   if(i==6)
     {
	  gotoxy(14,12);cout<<"EL NUMERO  NO SE PUEDE INTRODUCIR";
	  }

/*do
     {
	textcolor(4);
	textbackground(15);
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);

	valido='n';
	textcolor(4);
	gotoxy(54,7);
      cout<<"                 ";
	gotoxy(30,5);printf("ADICIONAR NODO");
	 gotoxy(20,7);cout<<"DIGITE EL CODIGO :" ;//gets(codigo);

	gotoxy(38,7);cin>>codigo;


	n = strlen(codigo);
	for(j=0;j<=n-1; j++)
	{
	 if(n>5)
	  {
	    gotoxy(22,18);textcolor(4);
	    cout<<"<< CODIGO MAYOR DE 5 DIGITOS >>";
	    
	    sound(500);
	    delay(1000);
	    nosound();
	    
	    valido='m';
	    getch();
	    gotoxy(22,18);
      cout<<"                                   ";

	    break;
	  }

	 else
	  {
	   if(!(isdigit(codigo[j])))
	    {
	     gotoxy(22,18);
	     cout<<"<< ERROR CODIGO MAL DIGITADO >>";
	     sound(500);
	    delay(1000);
	    nosound();
	    
	     valido='m';
	     getch();
	     gotoxy(22,18);
      cout<<"                                    ";

	     break;
	    }
	   else
	    {
	     p=raiz;



	     while(p!=NULL)
	     {
	      if(strcmp(p->codigo,codigo)==0)
	       {
		gotoxy(22,18);
		cout<<"<< ESTE CODIGO YA EXISTE >>";
		sound(500);
	    delay(1000);
	    nosound();
	    
		valido='m';
		getch();
		gotoxy(22,18);
		 cout<<"                                ";

		break;
	       }
	      else{
	      if(strcmp(p->codigo,codigo)<0)
	      p=p->izq;
	      else{p=p->der;} 
	     }
	     }
	    }
	   }
	 }
    }while(valido=='m');*/

   
  else
  {

    do
      {
	valido='n';
	gotoxy(38,8);
	cout<<"             ";
	gotoxy(20,8);cout<<"DIGITE EL NOMBRE :" ;
	gotoxy(38,8);gets(nom);
	n=strlen(nom);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nom[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);cout<<"<< PULSE SOLO LETRAS >>";
	     sound(500);
	    delay(1000);
	    nosound();
	    
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
	
       }while(valido=='m');

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
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);cout<<"<< PULSE SOLO LETRAS >>";
	     sound(500);
	    delay(1000);
	    nosound();
	    
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
       }while(valido=='m');

   do{valido='n'; 
	
  
   gotoxy(20,10);cout<<"DIGITE LA NOTA1:\n";//nota1=val(17,4);     
   gotoxy(37,10);//cin>>nota1;
   textbackground(15);
   textcolor(4);
   
   nota1=val_not(37,10);     
   textcolor(4);
   gotoxy(37,10);
   //textbackground(15);
    //textbackground(15);
    gotoxy(73,10);
    textcolor(14);textbackground(0);
    gotoxy(81,10);cprintf("º");
     gotoxy(79,10);cprintf("º");
     gotoxy(76,10);cprintf("º");
   if(nota1>5.0)
   {  
    gotoxy(22,20);cout<<"<< LA NOTA ESTA FUERA DE RANGO\n >>";
    sound(500);
    delay(1000);
    nosound();
	    
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
   
  }while(nota1>5.0);  

  do{
   gotoxy(42,10);cout<<"             ";
   
   gotoxy(20,11);cout<<"DIGITE LA NOTA2:";//nota1=val(17,4);     
   gotoxy(37,11);//cin>>nota2;
   textcolor(4);
   textbackground(15);
   nota2=val_not(37,11);     
   textbackground(15);
   textcolor(4);
   gotoxy(32,11);
    textbackground(15);
    gotoxy(73,11);
    textcolor(14);textbackground(0);
    gotoxy(81,11);cprintf("º");
     gotoxy(79,11);cprintf("º");
     gotoxy(76,11);cprintf("º");
   if(nota1>5.0)
   {  
    gotoxy(22,20);cout<<"<< LA NOTA ESTA FUERA DE RANGO >>\n";
    sound(500);
    delay(1000);
    nosound();
	    
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota2>5.0);  

  do{
   gotoxy(42,12);cout<<"             ";
     
    gotoxy(73,10);
   gotoxy(20,12);cout<<"DIGITE LA NOTA3:";//nota1=val(17,4);     
   gotoxy(37,12);//cin>>nota3;
   textcolor(4);
   textbackground(15);
   nota3=val_not(37,12);     
   textbackground(15);
   textcolor(4);
   gotoxy(73,12);
    textcolor(14);textbackground(0);
    gotoxy(81,12);cprintf("º");
     gotoxy(79,12);cprintf("º");
     gotoxy(76,12);cprintf("º");
   if(nota3>5.0)
   {  
    gotoxy(22,20);cout<<"<< LA NOTA ESTA FUERA DE RANGO\n >>";
    sound(500);
    delay(1000);
    nosound();
	    
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota3>5.0);  

 do{
     
    gotoxy(37,10);
   gotoxy(20,13);cout<<"DIGITE LA NOTA4:";//nota1=val(17,4);     
   gotoxy(37,13);//cin>>nota4;
   textcolor(4);
   textbackground(15);
   nota4=val_not(37,13);     
   textbackground(15);
   textcolor(4);
   gotoxy(32,13);
	 textbackground(15);
    gotoxy(73,13);
    textcolor(14);textbackground(0);
    gotoxy(81,13);cprintf("º");
     gotoxy(79,13);cprintf("º");
     gotoxy(76,13);cprintf("º");
   if(nota4>5.0)
   {  
    gotoxy(22,20);cout<<"LA NOTA ESTA FUERA DE RANGO\n";
    sound(500);
     delay(1000);
     nosound();
	    
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota4>5.0);  
  

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
	  gotoxy(25,15);cout<<"<< NODO INSERTADO >>";
  }     
       
 gotoxy(21,20);cout<<"DESEA INSERTAR OTRO NODO  [S/N]: ";
 do
 {
     gotoxy(54,20);op=toupper(getche());
 }while(op!='S'&&op!='N');

 if(op=='S')
 adicionar();
}

/*****************************************************/
main(){
clrscr();
arboles obj(NULL);
obj.darwins();
getche();
obj.menu();
getche();
}
//***********************************************************

void arboles::darwins()
{

 cuadros(2,79,2,23);
textcolor(14); textbackground(15);
gotoxy(12,4); cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
gotoxy(12,5); cout<<"º                                                         º";
gotoxy(12,6); cout<<"º                                                         º";
gotoxy(12,7); cout<<"º                                                         º";
gotoxy(12,8); cout<<"º                                                         º";
gotoxy(12,9); cout<<"º                                                         º";
gotoxy(12,10);cout<<"º                                                         º";
gotoxy(12,11);cout<<"º                                                         º";
gotoxy(12,12);cout<<"º                                                         º";
gotoxy(12,13);cout<<"º                                                         º";
gotoxy(12,14);cout<<"º                                                         º";
gotoxy(12,15);cout<<"º                                                         º";
gotoxy(12,16);cout<<"º                                                         º";
gotoxy(12,17);cout<<"º                                                         º";
gotoxy(12,18);cout<<"º                                                         º";
gotoxy(12,19);cout<<"º                                                         º";
gotoxy(12,20);cout<<"º                                                         º";
gotoxy(12,21);cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
//textcolor(15+128); textbackground(0);
gotoxy(18,20);cout<<"<< PRESIONE ENTER PARA VER EL MENU PRINCIPAL >>";
//textcolor(13); textbackground(0);
gotoxy(25,5);cout<<"MODELOS DE PROGRAMACION II 'ARBOL'";

textcolor(4); textbackground(15);

gotoxy(15,6); cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
gotoxy(15,7); cout<<"º                                                   º";
gotoxy(15,8); cout<<"º  ÛÛÛÛÛÛ    ÛÛÛÛ   ÛÛÛÛÛÛÛÛ     ÛÛÛÛ   ÛÛ          º";
gotoxy(15,9); cout<<"º ÛÛ    ÛÛ  ÛÛÛÛÛÛ   ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,10);cout<<"º ÛÛ    ÛÛ  ÛÛ   Û   ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,11);cout<<"º ÛÛ    ÛÛ  ÛÛ  ÛÛ   ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,12);cout<<"º ÛÛ    ÛÛ  Û   Û    ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,13);cout<<"º ÛÛÛÛÛÛÛÛ  ÛÛÛÛ     ÛÛÛÛÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,14);cout<<"º ÛÛ    ÛÛ  ÛÛ ÛÛ    ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ          º";
gotoxy(15,15);cout<<"º ÛÛ    ÛÛ  ÛÛ  ÛÛ   ÛÛ  ÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ ÛÛ       º";
gotoxy(15,16);cout<<"º ÛÛ    ÛÛ  ÛÛ   ÛÛ ÛÛÛÛÛÛÛÛ     ÛÛÛÛ   ÛÛÛÛÛ       º";
gotoxy(15,17);cout<<"º                                                   º";
gotoxy(15,18);cout<<"º                                                   º";
gotoxy(15,19);cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
textcolor(0);
gotoxy(17,18);cout<<"Derechos Reservados del Autor: DARWIN H. LEON P.";
}

/////////////////////////////////////                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                not=atof(nota);
float arboles::val_not(int z, int w )
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




////////////////////////////////////////////////////////

