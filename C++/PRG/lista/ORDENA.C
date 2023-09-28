
# include<conio.h>
# include<stdio.h>
# include<ctype.h>


int  *a[100],b[100],c[100],j,i,num,n,m,maximo;

int validar(int x,int y,int ancho)
{
 int sw=0,swn,r,n,contn;
 char num[30];
contn=0;
do
 {
  do
   {
    sw=0;
    gotoxy(x,y+i);
    clreol();  //remplaza el textcolor()
    gets(num);
    r=strlen(num);
    }
    while(r<=ancho-2);
     swn=0;
     for(n=0;n<r;n++)
       {
	if(isdigit(num[n])==0)
	 {
	  if(num[n]=='-')
	    {
	     contn=contn+1;
	       if(contn>1)
		 swn=1;
		  else
		   if(contn<1)
		     swn=0;
	      }
	      else
	       swn=1;
	 }
	}//fin del para

	if(swn==1)
	     {
	      textcolor(10);
	      gotoxy(20,6+i);cprintf(" Error: el dato debe ser numerico");  delay(1000); nosound(700);
	      sw=1;
	      normvideo();
	      gotoxy(20,6+i);
	      clreol();
	      }
	   else
	     if(swn==0)
	      sw=0;
       }//fin del while
	while(sw==1);
	return (atoi(num));
      }//fin de la funcion
void metodos_orde();
void insercion();
void burbuja();
void seleccion();
void shel();
void quit();

void fondo();
void fondo()
{
 clrscr();
 for(i=1;i<=24;i++)
  for(j=1;j<=80;j++)
  {
   textcolor(4);
   gotoxy(j,i);cprintf("±");normvideo();
   }
 }

void menuprin();
void menuprin()
{
 char op;
 while(1)
 {
  clrscr();
  textcolor(25);
  gotoxy (23,6); cprintf ("____________________________________________");textcolor(14);
  gotoxy (23,7);cprintf  ("| CORPORACION UNIVERSITARIA DE SANTANDER    | ");//textcolor(25);
  gotoxy (23,8);cprintf  ("|    FACULTAD DE INGENIERIA DE SISTEMAS     | ");
  gotoxy (23,9);cprintf  ("|               CURSO S3A                   |");
  gotoxy (23,10);cprintf ("|___________________________________________|");textcolor(25);
  gotoxy (23,11);cprintf ("|            1. METODOS DE ORDENAMIENTO     | ");textcolor(14);
  gotoxy (23,12);cprintf ("|                                           |");
  gotoxy(23,13); cprintf ("|-------------------------------------------|");
  gotoxy(23,14);cprintf  ("|            2. SALIR                       |");
  gotoxy(23,15); cprintf ("|-------------------------------------------|");
  gotoxy(23,16); cprintf ("| PROGRAMA  POR:  ING.  FABIO OLIVELLA      |");
  gotoxy (23,17);cprintf ("|___________________________________________|");
  textcolor(14);
  //rand() manda diferentes sonidos
 sound(rand());delay(100); gotoxy (23,19);cprintf ("      ***  DIGITE UNA OPCION  [ ]  ***      ");
  textcolor(18+128);
  gotoxy (20,22);cprintf("Programador: FABIO OLIVELLA");normvideo();
  gotoxy (54,19);op=getchar(); nosound();
  normvideo();
  switch(op)
  {
   case '1':metodos_orde();break;
    case '2':return;
   }
  }
}
void metodos_orde()
{
 char res,op;
 res='R';
  while(res=='R')
  {
   clrscr();
   textcolor(9);
   gotoxy(25,3);cprintf( " ESTOS SON LOS DIFERENTES TIPOS DE ORDENAMIENTOS");
   gotoxy(30,6);cprintf( "           1.   BURBUJA                         ");
   gotoxy(30,8);cprintf( "           2.   INSERCCION                      ");
   gotoxy(30,10);cprintf("           3.   SELECCION   		          ");
   gotoxy(30,12);cprintf("           4.   SHELL-S                         ");
   gotoxy(30,14);cprintf("           5.   QUIT-SORT                       ");
   textcolor(27);
   gotoxy(30,16);cprintf(" 6.   REGRESAR AL MENU PRINCIPAL ");
   textcolor(14);
   gotoxy(10,20);cprintf("ELIJA UNA OPCION  [  ] <<pulse enter>> ");
   gotoxy(29,20);op=getchar();normvideo();
    switch(op)
     {
      case '1':burbuja();break;
      case '2':insercion();break;
      case '3':seleccion();break;
      case '4':shel();break;
      case '5':quit();break;
      case '6':return;
      }
    }
  }

void seleccion()
{

int a[10],n,
 num,aux,j,i;
 clrscr();
   gotoxy(j+1,3+i);cprintf("digite la dimencion del vector  ==:> ");
   scanf("%d",&n);
   clrscr();
   for (i=0;i<n;i++)
    {
    gotoxy(j+1,5);cprintf("digite los elementos del vector..: ");
    scanf("%d",&num);
    a[i]=num;
    }
    for (i=0;i<n;i++)
       for (j=0;j<n;j++)
       if(a[i]<= a[j])
       {
	aux=a[i];
	a[i]=a[j];
	a[j]=aux;
       }

     gotoxy(25,9);
     textcolor(6);cprintf("*** VECTOR ORDENADO **");
   
    for (i=0;i<n;i++)
    {
    gotoxy(15+j,i+10);cprintf(" \n la posicion [%d] el elemento es %d",i,a[i]);
    }
    getch();   

 }

/*************************************************/

void quit()
{
 int sw=0,i,n,x,j,tempo,aux,indice=1,tempi,tempj,izq[20],der[20],v[20];
 clrscr();
gotoxy(2,3);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   izq[indice]=0;
   der[indice]=n-1;
   do{
     i=izq[indice];
     j=der[indice];
     indice--;
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
	  aux=v[i]; //esto es lo que hacemos cuando aparece cambio
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
	   indice++;
	   izq[indice]=i;
	   der[indice]=tempj;
	}
	else
	{
	  if(v[i] > v[tempj])
	  {
	  aux=v[i]; //esto es lo que hacemos cuando aparece cambio
	  v[i]=v[tempj];
	  v[tempj]=aux;
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
	  if(v[tempi] > v[j])
	  {
	    aux=v[tempi]; //esto es lo que hacemos cuando aparece cambio
	    v[tempi]=v[j];
	    v[j]=aux;
	   }
	}
   }while(indice != 0);
   for(i=0;i<n;i++)
    {
     printf("%d\t",v[i]);
      }
    getch();
 }



void shel(){
  int j,i,n,k=0,vect[320],intervalo,aux;
  clrscr();
  gotoxy(2,3);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vect[i]);
   }

    printf("\n\nVECTOR NORMAL\n\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vect[k]);

		     }
	intervalo=n/2;
	while(intervalo>0){
	    for(i=intervalo;i<n;i++){
	      j=i-intervalo;
	      while(j>=0){
	      k=j+intervalo;
		 if(vect[j]<=vect[k]){
		    j=0;
		      }
		   else
		   {
		   aux=vect[j];
		   vect[j]=vect[k];
		   vect[k]=aux;
		   }
		  j=j-intervalo;
		  }
		}
	      intervalo/=2;
	     }
	       printf("\n\nVECTOR ORDENADO\n\n");
	 for(k=0;k<n;k++)
		   {
     printf("%d\t",vect[k]);
    }
    getch();
  }



void insercion()
{
 int n,i,tempo,j,aux,v[20];
  clrscr();
  gotoxy(2,3);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=1;i<n+1;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   v[0]=-32767;
   i=2;
   while(i<=n)
      {
	 j=i-1;
	 tempo=v[i];
	 while(tempo<v[j])
	 {
	 v[j+1]=v[j];
	 j=j-1;
	 }
     v[j+1]=tempo;
    i++;
    }
     for(i=1;i<n+1;i++)
  {
     printf("%d\t",v[i]);
     }
    getch();
    }


void burbuja()
{
 char res;
 int op,aux,cas;

 maximo=100;
 clrscr();
 res='S';
 while(res=='S')
 {
  clrscr();
  textcolor(15);
  gotoxy(10,4);cprintf("DIGITE LADIMENSION DEL VECTOR --->> ");
  n=validar(47,4,2);
  if(n>0)
    {
      if(n>maximo)
	{
	 textcolor(12);
	 gotoxy(22,11);cprintf("Desbordamiento del vector");normvideo();delay(600);
	 textcolor(15);
	 gotoxy(10,18);cprintf("Desea modificar las dimensiones del vector [S/N] ===>[  ]");
	 gotoxy(64,18);res=getche();res=toupper(res);
	 if(res=='N')
	    {
	     gotoxy(22,11);clreol();gotoxy(10,18);clreol();
	     textcolor(12);
	     gotoxy(20,13);cprintf("Desea Abandonar el programa (burbuja) ");
	     gotoxy(38,15);cprintf(" [  ] ");
	     gotoxy(40,15);op=getche();op=toupper(op);
	     getch();normvideo();
	      if(op=='S')
		 res='N';
		  else
		    res='S';
	      }
	  }
	cas=1;
     }
     if(n<0)
	{
	 textcolor(12);
	 gotoxy(30,11);cprintf("Error la dimension debe ser un numero positivo");
	 delay(1500);textcolor(15);
	 gotoxy(10,15);cprintf("Desea modificar las dimensiones del vector [S/N] ===>[  ]");
	 gotoxy(64,15);res=getche();res=toupper(res);normvideo();
	 if(res=='N')
	   {
	    gotoxy(30,11);clreol();gotoxy(10,15);clreol();
	    textcolor(12);
	    gotoxy(30,13);cprintf("Desea Abandonar el programa (burbuja) ");
	    gotoxy(38,15);cprintf(" [  ] ");
	    gotoxy(40,15);op=getche();op=toupper(op);
	    getch();normvideo();
	      if(op=='S')
		 res='N';
		  else
		    res='S';
	    }
	cas=-1;
	}
	else
	  if(n<=maximo)
	    res='N';
  }//FIN DEL WHILE
     if(n<=maximo&&n>cas)
       {
	clrscr();
	textcolor(30);
	  gotoxy(30,3);cprintf("Llenar el vector");normvideo();
	   for(i=1;i<=n;i++)
	    {
	      gotoxy(10,5+i);printf("EL vector en la posici¢n [%d] contendra ---->",i);
	      num=validar(55,5,2);
	      a[i]=num;
	    }
	  gotoxy(20,23);printf("Presione cualquier tecla para continuar....");
	  getch();
	   for(i=1;i<=n-1;i++)
	    for(j=1;j<=n-i;j++)
	      if(a[j]>a[j+1])
		{
		 aux=a[j];
		 a[j]=a[j+1];
		 a[j+1]=aux;
		}
	  clrscr();
	  gotoxy(30,2);printf("EL vector ordenado");delay(500);
	   for(j=1;j<=n;j++)
	     {
	      gotoxy(10,5+j);printf("La posici¢n [%d] -----> [ %d ]",j,a[j]);
	      delay(300);
	     }
	  gotoxy(20,24);printf("Presione cualquier tecla ");getch();
	}
	   clrscr();
	   gotoxy(10,12);printf("Presione cualquier tecla para volver al menu.....");
	   getch();
}

void main()
{
 menuprin();
}



