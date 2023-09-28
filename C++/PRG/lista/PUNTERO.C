#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include"math.h"
#include"string.h"
#include"process.h"
#include"stdlib.h"
#include"ctype.h"

int *nec;
int we[10];
int i,j,n;
void shell_sorts(int n, int salto);


void menu();

void burbuja();
int val_num(int cont);
void insercion();
void quick_sort();
void shell();
void shell_sorts(int n, int salto);
void seleccion();
void insercion_2();

//int val_num(int cont);

/************************************************************/
void marcar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {
	  case 1: fondo=176; break;

	  case 2: fondo= 177;break;

	  case 3: fondo= 178;break;

	  case 4: fondo= 32;break;

	    default:
			fondo= 32;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }

void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ß");
    gotoxy(i,y2); cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("Û");
    gotoxy(x2,i); cprintf("Û");
  }

}

/**************************PINTURA******************************/

/*************************************************************/
void main()
{
 menu();
 }


/*****************************MENU GENERAL************************/

void menu()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"BURBUJA         ");
 strcpy(opciones[12],"INSERCION       ");
 strcpy(opciones[13],"QUICK_SORT      ");
 strcpy(opciones[14],"SHELL SORT      ");
 strcpy(opciones[15],"SELECCION       ");
 strcpy(opciones[16],"INSERCION_2     ");
 strcpy(opciones[17],"REGRESAR        ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(14,4); textcolor(15); textbackground(1);
 cprintf(" O R D E N A M I E N T O  P O R  P U N T E R O S  ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=17;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=17)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=17;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: burbuja(); break;
 case 12: insercion(); break;
 case 13: quick_sort(); break;
 case 14: shell(); break;
 case 15: seleccion();break;
 case 16: insercion_2();break;
 case 17: default: printf("FINAL");

}
}
 while(f!=17);
}


/*//////////////////menu archivo///////////////////////**/

void insercion()
{
 int n,i,cont,j;
 int *v;
 char op;
    do{
  clrscr();

   gotoxy(22,2);printf("ORDENAMIENTO POR INSERCION");

  gotoxy(5,5);printf("LONGITUD DEL VECTOR:");
  scanf("%d",&n);
  v=(int *) malloc(n);
  for(i=1;i<n+1;i++)
  {
gotoxy(5,7);printf("INGRESO DE ELEMENTOS:");
gotoxy(24+i*2,7);scanf("%d",&v[i]);
   }
   v[0]=-32767;
   i=2;
   while(i<=n)
      {
     j=i-1;
     cont=v[i];
     while(cont<v[j])
	 {
     v[j+1]=v[j];
     j=j-1;
	 }
     v[j+1]=cont;
      i++;

    }
     for(i=1;i<n+1;i++)
  {
gotoxy(15+i*2,10);printf("%d",v[i]);
     }
    gotoxy(20,22);printf("DESEA ORDENAR OTRO VECTOR [S/N]");
    op=toupper(getch());
    }while(op!='N');
    }

	       
void shell_sorts(int n,int veto){
int i,j,salir,tempo,aux;

    while(j<=n-1)
   {
      i=j-veto;
      tempo=nec[j];
      salir=0;
      while(i>0 && !salir)
      {
	 if(tempo>=nec[i])
	 {
	    salir=1;
	  }
	 else
	 {
	 nec[i+veto] = nec[i];
	 i=i-veto;
	 }
	
       }

       nec[i+veto]=tempo;
       j++;
     }

   }


void shell(){
int i,n,k=0,talwe[]={5,3,1};
int *nec;
  char op;
    do{
clrscr();
gotoxy(22,2);printf("ORDENAMIENTO POR SHELL_SORTS");
gotoxy(2,5);  printf("LONGITUD DEL VECTOR:  ");
  scanf("%d",&n);
  nec=(int *) malloc(n);
  for(i=0;i<n;i++)
  {
gotoxy(2,7);printf("INGRESE LOS ELEMENTOS:");
gotoxy(26+i*2,7);scanf("%d",&nec[i]);
   }

  for(i=0;i<=2;i++)
    shell_sorts(n,talwe[i]);
     

	 for(k=0;k< n;k++)
		   {
    gotoxy(15+k*2,10);printf("%d",nec[k]);
     
		    }

       gotoxy(20,22);printf("DESEA ORDENAR OTRO VECTOR [S/N]");
    op=toupper(getch());
    }while(op!='N');
    }


     
    
    

/////////////////////////////////////////////////////////////////////////////
void quick_sort()
{
int niche=1;
int n, izq[20],der[20],i,j;
int *v,sw,aux,x;
int tempi,tempj;
char op;
    do{

 clrscr();
gotoxy(22,2);printf("ORDENAMIENTO POR QUICK_SORT:");

gotoxy(5,5);  printf("DIGITE LA LONGITUD DEL VECTOR:");
  scanf("%d",&n);
  v=(int *)malloc(n);
  for(i=0;i<n;i++)
  {

    
gotoxy(5,7);printf("INGRESE LOS ELEMENTOS:");
gotoxy(28+i*2,7);scanf("%d",&v[i]);
   }
   izq[niche]=0;
   der[niche]=n-1;
   do{
     i=izq[niche];
     j=der[niche];
     niche--;
     tempi=i;
     tempj=j;
     x=v[(i+j)/2];

       sw=0;
       do{
	 for(;x>v[i];i++)
	  {
	     ;
	  }
	   for(;x < v[j];j--)
	  {
	     ;
	  }
       if(i<j)
       {
	  aux=v[i]; 
	  v[i]=v[j];
	  v[j]=aux;
	  i++;
	  j--;
       }
       if(i>=j)
	 sw=1;
       }while(sw!=1);
       if(i==j)
       {
	 if(x < v[i])
	 {
	   j--;
	  }
	   else
	   {
	     i++;
	   }
	 }
       if((tempj -i+1)>1)
       {
	   niche++;
	   izq[niche]=i;
	   der[niche]=tempj;
	}
	else
	{
	  if(v[i] > v[tempj])
	  {
	  aux=v[i]; 
	  v[i]=v[tempj];
	  v[tempj]=aux;
	  }
	}
	if((j-tempi+1) > 1)
	{
	    niche++;
	    izq[niche]=tempi;
	    der[niche]=j;
	}
	else
	{
	  if(v[tempi] > v[j])
	  {
	    aux=v[tempi]; 
	    v[tempi]=v[j];
	    v[j]=aux;
	   }
	}
   }while(niche != 0);
   for(i=0;i<n;i++)
		   {
   gotoxy(15+i*2,10);printf("%d",v[i]);
		     }
 gotoxy(20,22);printf("DESEA ORDENAR OTRO VECTOR [S/N]");
    op=toupper(getch());
    }while(op!='N');
    }

  
////////////////////////////////////////////////////////////////////////////////
int val_num(int cont)
  {int i,lon,op;
   char valido,valorn[9];
	  _setcursortype(_SOLIDCURSOR);
	  do
	  {
	  valido='n';
	  if(cont==2){
	   clreol();
	  scanf("\n"); gets(valorn);
	  }
	  if(cont==1){
	  gotoxy(34,19);
	  clreol();
	  scanf("\n");
	  gets(valorn);
	  }
	  lon = strlen(valorn);
	  for(i=0;i<=lon-1; i++)
	   {

	     if(!(isdigit(valorn[i])) && valorn[i]!='-')
	     {
	      valido='m';
	      break;
	    }

	   }
	 }while(valido=='m');
	op=atoi(valorn);
 return(op);
}
/******************seleccion*********************/
void seleccion(){
int i,j,aux,n;
int *vec;
clrscr();

 gotoxy(3,19);printf("LONGITUD DEL VECTOR:>");
   n=val_num(1);
    vec=(int *) malloc(n);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(3,19);cprintf("%s %d %s ", "ESCRIBA EN LA POSICION [",i+1,"]:");
      vec[i]=val_num(1);
	  }

  clrscr();
  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",vec[i]);
  }
  printf("\n\n");

	  for(i=0;i<=n-1;i++)
	   for(j=i+1;j<=(n-1);j++)
		   if(vec[i]>vec[j]){
		     aux=vec[i];
		     vec[i]=vec[j];
		     vec[j]=aux;
		     }


       gotoxy(2,13);
       printf("VECTOR ORDENADO ");
      printf("\n\n");
       for(i=0;i<n;i++)
       {
    printf("%d\t",vec[i]);
       }

	getch();

     }




 


///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
void burbuja()
{
int aux=0;
int *ww;
char op;
    do{

clrscr();
  gotoxy(22,2);printf("ORDENAMIENTO POR BURBUJA");

     gotoxy(5,8);printf("DINENCION DEL VECTOR :");
 scanf("%d",&n);
 ww=(int *) malloc(n);
     for(i=1;i<=n;i++)
     {
   gotoxy(7,9);printf("digite los elementos :");
gotoxy(28+i*2,9);   scanf("%d",&ww[i]);
   }

 clrscr();

 for(i=1;i<=n;i++)
     {
   for(j=i+1;j<=n;j++)
     {
    if(ww[j]<ww[i])
    {
    aux=ww[i];
    ww[i]=ww[j];
    ww[j]=aux;
     }
    }
 }


 gotoxy(14,14);printf("vector de menor a mayor");

    for(i=1;i<=n;i++)
     {
   gotoxy(37+i*2,14);printf("%d",ww[i]);
     }

    gotoxy(20,22);printf("DESEA ORDENAR OTRO VECTOR [S/N]");
    op=toupper(getch());
    }while(op!='N');
    }
   


//////////////////////////////////////////////////////////////////
void insercion_2()
{
 int k,n,temp,p;
 int *a;
 char op;
    do{

 clrscr();
  gotoxy(22,2);printf("ORDENAMIENTO POR INSERCION");
  gotoxy(5,8);printf("DINENCION DEL VECTOR :");
	 scanf("%d",&n);
	a=(int *) malloc(n);
 for(k=1;k<=n;k++)
  {				
    gotoxy(7,9);printf("digite los elementos :");
gotoxy(28+k*2,9);scanf("%d",&a[k]);
   }

 for(k=2;k<=n;k++)
   {
   temp=a[k];
   p=k-1;
 while(temp<a[p])
   {
 a[p+1]=a[p];
   p=p-1;
 }
 a[p+1]=temp;
}

for(k=1;k<=n;k++)
   {
   printf("%d\t",a[k]);
    }
   gotoxy(20,22);printf("DESEA ORDENAR OTRO VECTOR [S/N]");
   op=toupper(getch());
   }while(op!='N');
  }


































