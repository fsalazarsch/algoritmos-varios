
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/**************************************************************************/
  void metodo_burbuja();
  void insercion();
  void seleccion();
  void shell_sort();
  void quit_sort();
  void menu();
/*******************************************************/
  void menu()
{
int z,y;
{char op;



  do{ 
   clrscr();
 textcolor(4);
  textbackground(0);

    gotoxy (30,2); printf("MENU ORDENAMIENTOS");
    gotoxy (33,8); printf("1.BURBUJA");
    gotoxy (33,9); printf("2.INSERCION");
    gotoxy (33,10); printf("3.SELECCION");
    gotoxy (33,11); printf("4.SHELL_SORT");
    gotoxy (33,12); printf("5.QUIT_SORT");
    gotoxy (33,13); printf("6.SALIR DEL MENU ");
    gotoxy(24,21);printf(" DIGITE LA OPCION Y PULSE ENTER ");
    gotoxy(33,17);printf("[ ] OPCION ");gotoxy(34,17);printf("");
    scanf("%d",&op);


    switch (op)
    {
     case 1:clrscr();metodo_burbuja(); break;
     case 2:clrscr();insercion(); break;
     case 3:clrscr();seleccion(); break;
     case 4:clrscr();shell_sort(); break;
     case 5:clrscr();quit_sort();break;
     case 6: exit(0);
      
    }
   } while (op!=6);

}		    
/****************************************************************************/
			 
void metodo_burbuja()
{
int x[20];
int i,j,aux,n;
     clrscr();
       printf("DIGITE RANGO DEL VECTOR:: ");
       scanf("%d",&n);
	 for(i=0;i<n;i++){
       printf("DIGITE EL #: ");
       scanf("%d",&x[i]);
       }
	for(i=0;i<n;i++)
	  for(j=0;j<n-1;j++)
	    if(x[j] > x[j+1]){
	     aux=x[j];
	     x[j]=x[j+1];
	     x[j+1]=aux;}
	  for(j=0;j<n;j++){
	  printf("%d\t",x[j]);}
getche();
}
/***************************************************************************/
		     
void insercion()
{
 int n,i,tempo,j,aux,v[20];
  clrscr();
  gotoxy(2,3);  printf("RANGO DEL VECTOR::  ");
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
     for(i=1;i<n+1;i++){
     printf("%d\t",v[i]);}
getch();
}

/***************************************************************************/
void seleccion()
{
int n,i,j,aux,v[10];
clrscr();
gotoxy(2,3);  printf("RANGO DEL VECTOR...:  ");
scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
   textcolor(6);
   for(i=0;i<n-1;i++)
   {
       for(j=i+1;j<n;j++)
	{
	  if(v[i]>v[j])
	  {
	    aux=v[i];
	    v[i]=v[j];
	    v[j]=aux;
	  }
       }
    }
    for ( j=0;j<n;j++)
    {
  
     printf("%d \t",v[j]);
    }
getch();
}

/**************************************************************************/
	

void shell_sort(){
int j,i,n,k=0,intervalo,aux,vec[20];
gotoxy(2,3);  printf("RANGO DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }
	intervalo=n/2;
	while(intervalo>0){
	    for(i=intervalo;i<n;i++){
	      j=i-intervalo;
	      while(j>=0){
	      k=j+intervalo;
		 if(vec[j]<=vec[k]){
		    j=0;
		      }
		   else
		   {
		   aux=vec[j];
		   vec[j]=vec[k];
		   vec[k]=aux;
		   }
		  j=j-intervalo;
		  }
		}
	      intervalo/=2;
	     }
	 printf("\n\nVECTOR ORDENADO\n\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);
		     }

getch();
}


 
/***************************************************************************/
	
void quit_sort()
{
 int sw=0,i,n,x,j,tempo,aux,indice=1,tempi,tempj,izq[20],der[20],v[20];
clrscr();
gotoxy(2,3);  printf("RANGO DEL VECTOR::  ");
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


}