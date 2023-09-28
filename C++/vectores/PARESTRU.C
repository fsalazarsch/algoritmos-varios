#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#define MAXIMO 100
/*************************************************************************/
    int i,n,j;
    long int entero(int x, int y);
    void escriba(char p[25]);
    void quickS(int li,int ls,int *a);
    void inicial();
    void menu();
    void menu_sub_dos();
    void menu_sub_tres();
    void burbuja();
    void llenar();
    void cambio(int i, int j);
    void quicksort();
    void insercion();
    void seleccion();
    int  vec[MAXIMO];
    void secuencial();
    void binaria();
/******************CREAR CUADRO*****************************************/
void inicial()
{

for(i=0;i<MAXIMO;i++)
vec[i]=0;
}
void marco(int x1,int y1,int x2,int y2);
void marco(int x1,int y1,int x2,int y2)
{

    gotoxy (x1,y1) ; cprintf("²");
    gotoxy (x2,y1) ; cprintf("²");
     gotoxy (x1,y2) ; cprintf("²");
     gotoxy (x2,y2) ; cprintf("²");
	 for(i=(x1+1);i<=(x2-1);i++)
	    {
	    delay(10);
	     gotoxy (i,y1) ; cprintf("²");
	      gotoxy (i,y2) ; cprintf("²");
		 }
			 for(i=(y1+1);i<=(y2-1);i++)
			    {
			    delay(10);

			       gotoxy (x1,i) ; cprintf("²");
				gotoxy (x2,i) ; cprintf("²");
				}

}
/**********************************************************************/
void cuadro(int x1,int y1,int x2,int y2);
void cuadro(int x1,int y1,int x2,int y2)
{

    gotoxy (x1,y1) ; cprintf("É");
    gotoxy (x2,y1) ; cprintf("»");
     gotoxy (x1,y2) ; cprintf("É");
     gotoxy (x2,y2) ; cprintf("É");
	 for(i=(x1+1);i<=(x2-1);i++)
	    {
	    delay(10);
	     gotoxy (i,y1) ; cprintf("É");
	      gotoxy (i,y2) ; cprintf("É");
		 }
			 for(i=(y1+1);i<=(y2-1);i++)
			    {
			    delay(10);

			       gotoxy (x1,i) ; cprintf("É");
				gotoxy (x2,i) ; cprintf("É");
				}

}
/**********************************************************************/


/**************MENU PRINCIPAL**********************************************/
void menu()
{

  int op;

  do{


  textcolor(9);
  textbackground(5);

    clrscr();
    marco(20,3,75,25);
    marco(22,4,73,22);
    gotoxy (30,8) ; cprintf("***MENU PRINCIPAL***");
    gotoxy (33,12); cprintf("1.**METODOS DE ORDENAMIENTOS**");
    gotoxy (33,14); cprintf("2.**METODOS DE BUSQUEDA**");
    gotoxy (33,16); cprintf("3.** SALIR**");
    gotoxy (24,21); cprintf(" DIGITE LA OPCION Y PULSE ENTER : ");
   op=entero(58,21);
   switch (op)
    {
    case 1: menu_sub_dos();  break;

    case 2: menu_sub_tres(); break;

    case 3: exit(0);

    }
   } while (op!=3);
 }
/*************************************************************************/
void main()
{
clrscr();
marco(20,3,75,25);
marco(22,4,73,22);
  textcolor(4);
  textbackground(5);


    gotoxy (24,5);  cprintf("CORPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy (30,8);  cprintf("INGENIERIA DE SISTEMAS");
    gotoxy (30,10); cprintf("LUIS EDUARDO PERTUZ SIERRA");
    gotoxy (30,12); cprintf("CURSO S3E");
    gotoxy (30,14); cprintf("CIUDAD VALLEDUPAR");
    gotoxy (30,16); cprintf("DEPARTAMENTO DE CESAR");
    gotoxy (30,18); cprintf("A¥O 1998 ");
    gotoxy (28,25); cprintf("PRESIONE CUALQUIER TECLA PARA  CONTINUAR");
      _setcursortype(_NOCURSOR);
     getch();
/************************************************************************/
 clrscr();
 menu ();
 getche();
}
/*************************************************************************/

void menu_sub_dos()
{
int op;

  do{
  textcolor(9);
  textbackground(5);

    clrscr();
     marco(20,3,75,25);
     marco(22,4,73,22);
    gotoxy (30,5);  cprintf("***MENU ORDENAMIENTOS***");
    gotoxy (33,8);  cprintf("1.**BURBUJA**");
    gotoxy (33,10); cprintf("2.**QUICK SORT**");
    gotoxy (33,12); cprintf("3.**SELECCION**");
    gotoxy (33,14); cprintf("4.**INSERCION**");
    gotoxy (33,16); cprintf("5.**RETORNAR AL MENU PRINCIPAL**");
    gotoxy (24,18); cprintf(" DIGITE LA OPCION Y PULSE ENTER : ");
    op=entero(58,18);

    switch (op)
    {
       case 1:clrscr();llenar();burbuja();  break;
       case 2:clrscr();quicksort();break;
       case 3:clrscr();llenar();seleccion();break;
       case 4:clrscr();llenar();insercion();break;
       case 5:  menu();

    }
   } while (op!=0);

}
/*************************************************************************/
void menu_sub_tres()
{
  int op;

  do{
  textcolor(9);
  textbackground(5);

    clrscr();
    marco(20,3,75,25);
    marco(22,4,73,22);
    gotoxy (35,5);  cprintf("***MENU DE BUSQUEDA***");
    gotoxy (33,10); cprintf("1.**SECUENCIAL**");
    gotoxy (33,12); cprintf("2.**BINARIA**");
    gotoxy (33,14); cprintf("3.**RETORNAR AL MENU PRINCIPAL**");
    gotoxy(25,21);  cprintf("DIGITE LA OPCION Y PULSE ENTER : ");
    op=entero(58,21);
   switch (op)
    {
     case 1: clrscr();llenar();secuencial();break;
     case 2:clrscr();llenar();binaria();break;
     case 3: menu();
    }
   } while (op!=3);

}
/***************************************************************************/
void llenar()
{
   inicial();
    clrscr();
    textcolor(9);
    textbackground(5);
     // cuadro(20,3,75,25);
     // cuadro(22,4,73,22);
       gotoxy(25,10);
    cprintf("DIGITE EL LIMITE DE ELEMENTOS DEL VECTOR====>");
    n=entero(70,10);
    if(n>MAXIMO)
   {
    gotoxy(10,10);
    printf("DESBORDAMIENTO LIMITE DEL VECTOR \n");
     getch();
     exit(0);

   }
    else
   {
    for(i=1;i<=n;i++)
     {
    gotoxy(3,3);cprintf ("%s%d%s","DIGITE EL NUMERO [",i,"]: ");
    vec[i]=entero(26,3);
   }
  getch();
}
}
/**************************************************************************/
void burbuja()
{
  int  aux=0,w=14,z=40;

  {
   clrscr();
   textcolor(9);
  textbackground(5);
  printf("\n\n");
      gotoxy(z,13);
      printf("**** VECTOR INICIAL***:> ");
  for(i=1;i<=n;i++)
  {
  gotoxy(z+24,10+i);printf("[%d]=%d",i,vec[i]);

   }

  for(i=1;i<=(n-1);i++)
  {
   for(j=1;j<=n-i;j++)
    if (vec[j]>vec[j+1])
    {
      aux=vec[j];
      vec[j]=vec[j+1];
       vec[j+1]=aux;

     }
  }
	gotoxy(2,13);
       printf("***EL VECTOR ORDENADO ES*:> ");
       printf("\n\n");
       for(i=1;i<=n;i++)
       {
       //printf("\t");
	gotoxy(w+15,10+i);printf("[%d]= %d",i,vec[i]);

       }
	getche();
}
   }
/*************************************************************************/
/*************************************************************************/
long int entero(int x,int y)
{ int sw,n,i;

  char cad[20];
  textcolor(9);

  textbackground(5);
  do
  { gotoxy(x,y); clreol();
    gotoxy(x,y);
    gets(cad); sw=0;
    n=strlen(cad);
    for(i=0;i<n;i++)
     {
      if(!isdigit(cad[i])||(cad[i]=='¤'||cad[i]=='¥'||cad[i]==0))
      { escriba("!!!  Debe ser Num‚rico !!!");
	sw=1;
       break; }}
  }while(sw==1);
  return(atoi(cad));
}
/***********************************/
void escriba(char p[25])
{
   window(3,22,70,22);
   clrscr();textcolor(14+BLINK);
   gotoxy(25,1);cprintf("%s",p);delay(3500);
   clrscr();
   window(1,1,80,25); textcolor(6);

}
/***********************************************************************/
/* void quicksort()
 {
 int aux1[MAXIMO],aux2[MAXIMO],mitad,mitadp,auxor,posi,posj,za=14,se=40;
 i=0;
 j=n;

      gotoxy(za-10,13);
      printf("**** VECTOR INICIAL***:> ");
      for(i=1;i<=n;i++)
  {
  gotoxy(za+15,10+i);printf("[%d]=%d",i,vec[i]);

   }
 if ((i+j)%2 == 0)
 {mitad=vec[(i+j)/2];
 mitadp=(i+j)/2;
 }
  else
 {mitad=vec[(i+j)/2]+1;
 mitadp=(i+j)/2+1;
 }

 while(i<=j)
 {
  while(vec[i]<=mitad)
  {
  i++;
  }
  while(vec[j]>mitad)
  {
  j--;
  }
if (vec[i]>mitad)
{
 auxor=vec[i];
 vec[i]=mitad;
 mitad=auxor;
}
else
if (i<=j)
{
 auxor=vec[i];
 vec[i]=vec[j];
 vec[j]=auxor;
 i++;
 j--;
}
}
i=0;
while(i<mitadp)
{
if(vec[mitadp]<vec[mitadp-1]&& i<mitadp)
{
 auxor=vec[mitadp];
 vec[mitadp]=vec[mitadp-1];
 vec[mitadp-1]=auxor;
 }
 mitadp--;
}
j=n;
while(mitadp<j)
{
if(vec[mitadp]>vec[mitadp+1]&& mitadp<n)
{
 auxor=vec[mitadp];
 vec[mitadp]=vec[mitadp+1];
 vec[mitadp+1]=auxor;
 }
 mitadp++;
}
 for(i=0;i<n;i++)
 {
 if(i<mitadp){
 aux1[i]=vec[i];}
 else
 {
 aux2[i]=vec[i];
 }
 }
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
   if (n<mitadp)
   {
    if (aux1[j]>aux1[j+1])
    {
      auxor=aux1[j];
      aux1[j]=aux1[j+1];
      aux1[j+1]=auxor;
    }
    }
    else
    { if (aux2[j]>aux2[j+1])
    {
      auxor=aux2[j];
      aux2[j]=aux2[j+1];
      aux2[j+1]=auxor;
    }
    }
  }

}
 for(i=0;i<n;i++)
 {
 if(i<mitad)
 {vec[i]=aux1[i];}
 else
 {vec[i]=aux2[i];}
 }
	  gotoxy(40,13);
       printf("**** VECTOR ORDENADO***:> ");
	 for(i=1;i<=n;i++)
       {

	gotoxy(se+28,10+i);printf("[%d]= %d",i,vec[i]);

       }
    getch();
} */
/*************************************************************************/
     void insercion()
      {
      int tempo,s=12,q=40;


     gotoxy(s-10,13);
      printf("**** VECTOR INICIAL***:> ");
  for(i=1;i<=n;i++)
  {
  gotoxy(s+15,10+i);printf("[%d]=%d",i,vec[i]);

   }

         i=2;
    while(i<=n)
      {
	 j=i-1;
	 tempo=vec[i];
	 while(tempo<vec[j])
	 {
	  vec[j+1]=vec[j];
	  j=j-1;

	 }
	  vec[j+1]=tempo;
	   i++;
    }
     for(i=1;i<n+1;i++)
  {     
	   gotoxy(40,13);
       printf("***EL VECTOR ORDENADO ES*:> ");
       printf("\n\n");
       for(i=1;i<=n;i++)
       {

	gotoxy(q+28,10+i);printf("[%d]= %d",i,vec[i]);

       }
	getche();

     }

    }


/**********************************************************************/
void seleccion()
  {
  int k,aux1,h=12,e=40;
  i=1;
      gotoxy(h-10,13);
      printf("**** VECTOR INICIAL***:> ");
      for(i=1;i<=n;i++)
  {
  gotoxy(h+15,10+i);printf("[%d]=%d",i,vec[i]);

   }



     for(i=0;i<n;i++)
     {
     aux1=vec[i];
     k=i;
     for(j=(i+1);j<n+1;j++)
     {
     if (vec[j]<aux1)
     {
     aux1=vec[j];
     k=j;
     }
     }
     vec[k]=vec[i];
     vec[i]= aux1;
     }

	 gotoxy(40,13);
       printf("***EL VECTOR ORDENADO ES*:> ");
       printf("\n\n");
       for(i=1;i<=n;i++)
       {

	gotoxy(e+28,10+i);printf("[%d]= %d",i,vec[i]);

       }
	getche();

     }
/************************************************************************/
void binaria()
{
int bajo,alto,ubicado=0,mitad;
int w,aux;
   for(i=0;i<n;i++)
  {
   for(j=(i+1);j<n;j++)
    if (vec[i]>vec[j])
    {
      aux=vec[i];
      vec[i]=vec[j];
       vec[j]=aux;
     }
  }
  clrscr();
gotoxy(10,7);
printf("%s","DIGITE EL NUMERO A BUSCAR:>");
w=entero(41,7);
bajo=1;
alto=n-1;
    while(!ubicado && bajo<=alto){
   mitad=(bajo+alto)/2;

   if(vec[mitad]==w)
     ubicado=1;
    else
      if(vec[mitad]>w)
	 alto=mitad-1;
      else
	bajo=mitad+1;
     }
    if(ubicado)
       printf("\nEL NUMERO ESTA EN EL VECTOR");

       else
       printf("\nEL NUMERO NO ESTA EN EL VECTOR");


    getch();
    }

/***********************************************************************/
void secuencial(){
int w;
int j;
int ubicado=0;
   clrscr();
   printf("%s","DIGITE EL VALOR A BUSCAR:>");
   w=entero(28,1);
   for(j=1;j<=n;j++)
   {

   if(vec[j]==w)
   {ubicado=1;break;}
   }
     if(ubicado==1)
     printf("EL NUMERO [%d] ESTA EN EL VECTOR",w);
     else
     printf("EL NUMERO [%d] NO ESTA EN EL VECTOR",w);
     getch();

     }
/**********************************************************************/
/*void quicksort()
{
int sw=0,x,tempo,aux,indice=0,tempi,tempj;
int izq[20],der[20],za=14,se=40;
   izq[indice]=1;
   der[indice]=n-1;

      gotoxy(za-10,13);
      printf("**** VECTOR INICIAL***:> ");
      for(i=1;i<=n;i++)
  {
  gotoxy(za+15,10+i);printf("[%d]=%d",i,vec[i]);

   }
   do{
     i=izq[indice];
     j=der[indice];
     indice--;
     tempi=i,
     tempj=j;
     x=vec[(i+j)/2];

       sw=0;
       do{
	for(;x>vec[i];i++)
	  {
	     ;
	  }
	   for(;x < vec[j];j--)
	  {
	     ;
	  }
       if(i<j)
       {
	  aux=vec[i];
	  vec[i]=vec[j];
	  vec[j]=aux;
	  i++;
	  j--;
       }
       if(i>=j)
	 sw=1;
       }while(sw!=1);
       if(i==j)
       {
	 if(x<vec[i])
	 {
	   j--;
	  }
	   else
	   {
	     i++;
	   }
	 }
       if((tempj -i+1)>2)
       {
	   indice++;
	   izq[indice]=i;
	   der[indice]=tempj;
	}
	else
	{
	  if(vec[i] > vec[tempj])
	  {
	  aux=vec[i];
	  vec[i]=vec[tempj];
	  vec[tempj]=aux;
	  }
	}
	if((j-tempi+1) > 1)
	{
	    indice++;
	    izq[indice]=tempi;
	    der[indice]=j;
	}
	else
	{
	  if(vec[tempi] > vec[j])
	  {
	    aux=vec[tempi];
	    vec[tempi]=vec[j];
	    vec[j]=aux;
	   }
	}
   }while(indice !=0);
	  gotoxy(40,13);
       printf("**** VECTOR ORDENADO***:> ");
	 for(i=1;i<=n;i++)
       {

	gotoxy(se+28,10+i);printf("[%d]= %d",i,vec[i]);

       }
    getch();

}
*/
/*********************************************************************/
void quicksort(){
int i,m,n,max=100;
  textcolor(0);
  textbackground(3);
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENCION QUE DESEA DEL VECTOR........:");
  m=entero(54,3);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 quicksort();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);
      n=entero(28,5);
      vec[i]=n;
	  }
quickS(0,m-1,vec);
clrscr();
for(i=0;i<=m-1;i++)
printf("%d\t",vec[i]);
getch();


}

void quickS(int li,int ls,int *a)

{
 int i=li,j=ls,x,y;
 x=a[(li+ls)/2];
 do{
   while(a[i]<x)i++;
    while(x<a[j])j--;
    if(i<=j)
    {y=a[i];a[i]=a[j];a[j]=y;
    i++;j--;
    }
    }
   while(i<j);
    if (li<j)
     quickS(li,j,a);
    if(li<ls)
      quickS(i,ls,a);
      }







