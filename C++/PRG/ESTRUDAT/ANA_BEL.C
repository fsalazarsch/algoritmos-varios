void quit_sort()
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
	   indice++;
	   izq[indice]=i;
	   der[indice]=tempj;
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
	    indice++;
	    izq[indice]=tempi;
	    der[indice]=j;
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
   }while(indice != 0);
   for(i=0;i<n;i++)
{
printf("%d\t",v[i]);
}
getch();
		    

}

#include"stdio.h"
#include"conio.h"
#include <ctype.h>

/*************************************************************************/
  void main();
  void burbuja();
  int val_num(int cont);
  void quick_sort();
  void insercion();
  void shell_sort();
  void partir(int *,int,int);
int vec[100];

/*************************************************************************/
void main()
{
int x,y;
char op;

  do{
  clrscr();
 textcolor(12);
 textbackground(15);
  gotoxy(1,1);
 cprintf("É");
 for(x=1;x<=78;x++)
 {
    gotoxy(x,78);
   cprintf("Í");
   delay(15);
  }
   gotoxy(1,74);
   cprintf("»");
   for(y=2;y<=24;y++)
      {
     gotoxy(1,y);
     cprintf("º");
     delay(15);
   }
    gotoxy(1,25);
    cprintf("È");
   for(x=1;x<=78;x++)
   {
    gotoxy(x,79);
    cprintf("Í");
    delay(15);
   }
    gotoxy(79,25);
    cprintf("¼");
   for(y=2;y<=24;y++)
   {
    gotoxy(79,y);
    cprintf("º");
    delay(15);
   }
    gotoxy (30,5); cprintf("MENU ORDENAMIENTO");
    gotoxy (33,8); cprintf("1.BURBUJA");
    gotoxy (33,10); cprintf("2.QUICK_SORT");
    gotoxy (33,12); cprintf("3.POR INSERCION");
    gotoxy (33,14); cprintf("4.SHELL_SORT");
    gotoxy (33,16); cprintf("5.SALIR");
    gotoxy (24,21); cprintf(" DIGITE LA OPCION Y PULSE ENTER ");
    gotoxy (33,19); cprintf("[ ] OPCION ");gotoxy(34,19);printf("");
    op=getche();
    switch (op)
    {
     case '1':clrscr();burbuja();break;
     case '2':clrscr();quick_sort();break;
     case '3':clrscr();insercion();break;
    case '4': clrscr();shell_sort();break;

    }
   } while (op!='5');


}

/*************************************************************************/
void burbuja()
{
int i,j,n,aux;
int op;
clrscr();

   gotoxy(10,7);
   printf("%s","DIGITE EL RANGO DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      gotoxy(10,8);
      clrscr();
      _setcursortype(_NOCURSOR);
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL NUMERO DE LA POSICION [",i+2,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }

  clrscr();
  gotoxy(2,10);
   printf("%s\n"," VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",vec[i]);
  }
  printf("\n\n");
  for(i=0;i<(n-1);i++)
  {
   for(j=(i+1);j<n;j++)
    if (vec[i]>vec[j])
    {
      aux=vec[i];
      vec[i]=vec[j];
       vec[j]=aux;
     }
  }
       gotoxy(2,13);
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();
}
int val_num(int cont)
  {int i,lon,op;
   char valido,valorn[9];
	  _setcursortype(_SOLIDCURSOR);
	  do
	  {
	  valido='n';
	  if(cont==2){
	  //printf("%s",op);
	  clreol();
	  scanf("\n"); gets(valorn);//strupr(valorn);
	  }
	  if(cont==1){
	  gotoxy(34,19);
	  clreol();
	  scanf("\n");
	  gets(valorn);//strupr(valorn);
	  }
	  lon = strlen(valorn);
	  for(i=0;i<=lon-1; i++)
	   {

	     if(!(isdigit(valorn[i])) && valorn[i]!='-')
	     //|| valorn[i]=='¤' )
	     {
	      valido='m';
	      break;
	    }

	   }
	 }while(valido=='m');
	op=atoi(valorn);
 return(op);
}
/******************shell_sort*********************/
void shell_sort(){
int i,j,aux,n;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
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
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();

     }

/******************insercion*********************/

void insercion(){
int i,n,aux,p,u,c,k;
int j;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
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

for(i=1;i<n;i++){
aux=vec[i];
p=0;
u=i-1;
  for(;p<=u;){
  c=(p+u)/2;
  if(aux<vec[c])
   u=c-1;
  else
  p=c+1;
  }
for(k=i-1;k>=p;k--){
  vec[k+1]=vec[k];
  }
  vec[p]=aux;
  }
       gotoxy(2,13);
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();
  }
/********************Quick Sort****************************/
void quit_sort()
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
	   indice++;
	   izq[indice]=i;
	   der[indice]=tempj;
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
	    indice++;
	    izq[indice]=tempi;
	    der[indice]=j;
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
   }while(indice != 0);
   for(i=0;i<n;i++)
{
printf("%d\t",v[i]);
}
getch();
		    
}
      