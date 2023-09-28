#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<io.h>
/*************************************************************************/
int vect[20];
void shell_sorts();
void shell_sorts2();
void burbuja();
void burbuja2();
void insercion();
void insercion2();
void quit_sort();
void quit_sort2();
void radixf_sort();
void seleccion();
void seleccion2();
/**********************************************************************/


void marco(int x1,int y1,int x2,int y2);
void marco(int x1,int y1,int x2,int y2)
{            int i;

    gotoxy (x1,y1) ; cprintf("±");
    gotoxy (x2,y1) ; cprintf("±");
     gotoxy (x1,y2) ; cprintf("±");
     gotoxy (x2,y2) ; cprintf("±");
	 for(i=(x1+1);i<=(x2-1);i++)
	    {
	    delay(15);
	     gotoxy (i,y1) ; cprintf("±");
	      gotoxy (i,y2) ; cprintf("±");
		 }
			 for(i=(y1+1);i<=(y2-1);i++)
			    {
			    delay(15);

			       gotoxy (x1,i) ; cprintf("±");
				gotoxy (x2,i) ; cprintf("±");
				}

}

/****************BURBUJA ESTATICAMENTE************************************************/


void burbuja()
{
  int n,i,j,aux,v[10];
  clrscr();
gotoxy(17,2);  printf("METODO DE ORDENAMIENTO BURBUJA ESTATICAMENTE ");
gotoxy(3,4);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
   gotoxy(17,2);  printf("METODO DE ORDENAMIENTO BURBUJA ...ESTATICAMENTE ");
    textcolor(6);
   gotoxy(18,9);printf("VECTOR SIN ORDENAR");
   gotoxy(18,10);
   for ( i=0;i<n;i++)
    {
     printf("%d \t",v[i]);
    }

   for(i=0;i<n;i++)
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
    gotoxy(18,15);printf("EL VECTOR ORDENADO POR EL METODO DE BURBUJA ES");
    gotoxy(18,16);
    for ( j=0;j<n;j++)
    {

     printf("%d \t",v[j]);
    }
    textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
getch();
}
/*******************INSERCION ESTATICAMENTE*********************************/
void insercion()
{
 int n,i,tempo,j,aux,v[20];
  clrscr();
  gotoxy(19,3);  printf("ORDENACION POR INSECION...'ESTATICAMENTE' ");
  gotoxy(4,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=1;i<n+1;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
   gotoxy(19,3);  printf("ORDENACION POR INSECION... 'ESTATICAMENTE' ");
   gotoxy(4,6);  printf("VECTOR SIN ORDENAR==>:  ");
   for(i=1;i<n+1;i++)
  {
     printf("%d \t",v[i]);    
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
     gotoxy(4,10);  printf("VECTOR ORDENADO POR EL METODO DE INSECION ESTATICAMENTE ==>:\n  ");
     for(i=1;i<n+1;i++)
  {
     printf("%d \t",v[i]);
     }
     textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
    getch();
    }

/********************insercion dinamicamente****************/
void insercion2()
{
 int n,i,tempo,j,aux,*v;
  clrscr();
  gotoxy(18,3);  printf("METODO DE ORDENAMIENTO POR INSERCION DINAMICAMENTE ");
  gotoxy(3,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  v=(int *)malloc(n);
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
     textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
    getch();
}




/***********************SHELL_SORTS ESTATICAMENTE************************/
void shell_sorts()
{
  int vec[20],k,i,j,salir,n,tempo,aux,intervalo;
  gotoxy(18,3);printf("ORDENAMIENTO POR EL METODO SHELL_SORTS ESTATICAMENTE ");
  gotoxy(4,6);printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }
   clrscr();
   gotoxy(18,3);printf("ORDENAMIENTO POR EL METODO SHELL_SORTS...'ESTATICAMENTE' ");
  gotoxy(4,7); printf("VECTOR SIN ORDENAR");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);

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
		}	      intervalo/=2;
	     }
	      gotoxy(4,12); printf("VECTOR ORDENADO POR EL METODO DE SHELL_SORTS... 'ESTATICAMENTE'\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);
		     }
	   textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
	   getch();
	   }
/************************shell_sort en forma dinamica**********************/
void shell_sorts2()
{
  

  int *vec,k,i,j,salir,n,tempo,aux,intervalo;
  textcolor(9);
  gotoxy(19,3);cprintf("METODO DE ORDENAMIENTO SHELL_SORT DINAMICAMENTE ");
  textcolor(8);
  gotoxy(2,5);  
 cprintf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
	 vec=(int *)malloc(n);
  for(i=0;i<n;i++)
  {
    gotoxy(12,8+i);
    printf("DIGITE LOS VALORES DEL VECTOR [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }
   clrscr();
   gotoxy(12,3);
   printf("VECTOR NORMAL SIN ORDENAR \n\n");
	 for(k=0;k<n;k++)
		   {
		   
		   printf("%d \t",vec[k]);
		   
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
		}	      intervalo/=2;
	     }
		gotoxy(8,8);
	       printf("VECTOR ORDENADO POR EL METODO DE SHELL SORT DINAMICAMENTE\n\n");
	 for(k=0;k<n;k++)

		   {
		   
		   printf("%d\t",vec[k]);
		     }
   textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
  getch();
}

/************************QUIT_SORT ESTATICO***********************************************/

void quit_sort()
{
int sw=0,i,n,x,j,tempo,aux,indice=0,tempi,tempj,izq[20],der[20],v[20];
gotoxy(17,3);  printf("ORDENAMIENTO POR EL METODO QUIT_SORT ESTATICAMENTE ");
gotoxy(5,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
   gotoxy(17,3);  printf("ORDENAMIENTO POR EL METODO QUIT_SORT ESTATICAMENTE ");
   gotoxy(5,6);  printf("VECTOR SIN ORDENAR\n");
   for(i=0;i<n;i++)
  {
    printf("%d\t",v[i]);
  }

   izq[indice]=0;
   der[indice]=n-1;
   do{
     i=izq[indice];
     j=der[indice];
     indice--;
     tempi=i,
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
   gotoxy(5,12);  printf("VECTOR ORDENADO POR EL METODO DE QUIT_SORT ESTATICAMENTE\n ");
   for(i=0;i<n;i++)
		   {
		   printf("%d\t",v[i]);
		     }
    textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
    getch();

}
/***********************quit_sort dinamico*****************************/
void quit_sort2()
{
int sw=0,i,n,x,j,tempo,aux,indice=0,tempi,tempj,izq[20],der[20],*v;
gotoxy(20,3);printf("ORDENAMIENTO POR EL METODO DE QUIT_SORT DINAMICAMENTE");
gotoxy(4,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  v=(int *)malloc(n);
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
     tempi=i,
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
       if((tempj -i+1)>2)
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
  gotoxy(3,15); printf("EL VECTOR ORDENADO ES\n");
   for(i=0;i<n;i++)
		   {
		   printf("%d\t",v[i]);
		     }
    textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
    getch();

}








void radixf_sort()
{


}
/***************************BURBUJA DINAMICO**********************/
void burbuja2()

{
  int n,i,j,aux,*v;
  clrscr();
  gotoxy(18,3);  printf("METODO DE ORDENACION BURBUJA DINAMICAMENTE ");
gotoxy(4,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  v=(int *)malloc(n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
    textcolor(6);
   gotoxy(18,9);printf("VECTOR SIN ORDENAR");
   gotoxy(18,10);
   for ( i=0;i<n;i++)
    {
     printf("%d \t",v[i]);
    }

   for(i=0;i<n;i++)
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
    gotoxy(22,2);cprintf("þþþ EL METODO DE BURBUJA DINAMICAMENTEþþþ");
    gotoxy(18,15);printf("EL VECTOR ORDENADO POR EL METODO DE BURBUJA ES");
    gotoxy(18,16);
    for ( j=0;j<n;j++)
    {
  
     printf("%d \t",v[j]);
    }
    textcolor(4+BLINK);                                    
      gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR.....*   ");
    textcolor(4);
getch();
}


/****************************MENU PRINCIPAL*****************************/
 void main()
{
 char op;
 clrscr();
  while(1)
  {
      clrscr();
      marco(2,1,79,25);
      textcolor(15);textbackground(3);
      gotoxy(24,2);cprintf( "  M E N U   P R I N C I P A L     ");
      gotoxy(19,3);cprintf( "  **********************************     ");
      gotoxy(14,4);cprintf( "  M E T O D O S   D E   O R D E N A M I E M T O ");
      textcolor(12);
      gotoxy(18,6);cprintf( "metodos de insercion en forma estatica");
      gotoxy(30,7);cprintf (" A... BURBUJA      ");
      gotoxy(30,8);cprintf (" B... INSERCION   ");
      gotoxy(30,9);cprintf (" C... SHELL_SORT  ");
      gotoxy(30,10);cprintf(" D... QUIT SORT   ");
      gotoxy(30,11);cprintf(" E... SELECCION  ");
      textcolor(8);
      gotoxy(11,13);cprintf(" ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ");
      textcolor(9);
      gotoxy(17,16);cprintf(" metodos de ordenamiento con apuntadores  ");
      gotoxy(30,17);cprintf(" F... BURBUJA  ");
      gotoxy(30,18);cprintf(" G... SELECCION   ");
      gotoxy(30,19);cprintf(" H... SHELL_SORT  ");
      gotoxy(30,20);cprintf(" I... QUIT_SORT  ");
      gotoxy(30,21);cprintf(" J... INSERCION  ");
      textcolor(4+BLINK);  
      gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL PROGRAMA.....*   ");
      op=getche();     
       textcolor(4);  
      switch(op)
      {  case 'a':{clrscr(); burbuja();sound(440);delay(500);nosound();break;}
	 case 'A':{clrscr(); burbuja();sound(440);delay(500);nosound();break;}
	 case 'b':{clrscr(); insercion();sound(440);delay(500);nosound();break;}
	 case 'B':{clrscr(); insercion();sound(440);delay(500);nosound();break;}
	 case 'c':{clrscr(); shell_sorts(); sound(440);delay(500);nosound();break;}
	 case 'C':{clrscr(); shell_sorts();sound(440);delay(500);nosound();break;}
	 case 'd':{clrscr(); quit_sort();sound(440);delay(500);nosound();break;}
	 case 'D':{clrscr(); quit_sort();sound(440);delay(500);nosound();break;}
	 case 'e':{clrscr(); seleccion();sound(440);delay(500);nosound();break;}
	 case 'E':{clrscr(); seleccion();sound(440);delay(500);nosound();break;}
	 case 'f':{clrscr(); burbuja2();sound(440);delay(500);nosound();break;}
	 case 'F':{clrscr(); burbuja2();sound(440);delay(500);nosound();break;}
	 case 'g':{clrscr(); seleccion2();sound(440);delay(500);nosound();break;}
	 case 'G':{clrscr(); seleccion2();sound(440);delay(500);nosound();break;}
	 case 'h':{clrscr(); shell_sorts2();sound(440);delay(500);nosound();break;}
	 case 'H':{clrscr(); shell_sorts2();sound(440);delay(500);nosound();break;}
	 case 'i':{clrscr(); quit_sort2();sound(440);delay(500);nosound();getch();break;}	 
	 case 'I':{clrscr(); quit_sort2();sound(440);delay(500);nosound();break;}
	 case 'j':{clrscr(); clrscr(); insercion2();sound(440);delay(500);nosound();break;}
	 case 'J':{clrscr(); insercion2();sound(440);delay(500);nosound();break;}
	 case  27:  sound(440);delay(300);nosound();  exit(0);
       }
   }

  }
/********************SELECCION ESTATICA**********************************************/
void seleccion()
  {
  int k,aux1, n,i,j,aux,vec[20];
  clrscr();
  gotoxy(18,3);printf("METODO DE ORDENACION POR SELECCION...'ESTATICAMENTE' ");
gotoxy(3,6);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   gotoxy(2,7+i); 
   printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }
   clrscr();
    textcolor(6);
   gotoxy(18,3);printf("METODO DE ORDENACION POR SELECCION...'ESTATICAMENTE' ");
   gotoxy(18,9);printf("VECTOR SIN ORDENAR");
   printf("\n\n");
   gotoxy(18,10);
   for ( i=0;i<n;i++)
    {
     printf("%d \t",vec[i]);
    }

  i=1;
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
      gotoxy(6,20);printf("EL VECTOR ORDENADO  POR EL METODO DE SELECCION ES\n ");
      printf("\n\n");
       for(i=1;i<=n;i++)
       { printf("%d \t",vec[i]); }
	printf("\n");
	textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
	getch();
}

/**********************SELECCION DINAMICA**********************************************/
void seleccion2()
  {
  int k,aux1, n,i,j,aux,*vec;
  clrscr();
  
  gotoxy(15,3);  printf("METODO DE ORDENACION POR SELECCION EN FORMA DINAMICA  ");
gotoxy(2,5);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  vec=(int *)malloc(n);
 
  for(i=0;i<n;i++)
  {
    // gotoxy(2,6+i);
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }
  i=1;
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
      gotoxy(10,15);printf("EL VECTOR ORDENADO EN FORMA ESTATICA ES ");
       printf("\n\n");
       for(i=1;i<=n;i++){ 
       printf("\t%d",vec[i]); }
	printf("\n");
	textcolor(4+BLINK);  
    gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL MENU.....*   ");
    textcolor(4);  
	getch();
}






