#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<dos.h>

/***************************************************************************/
void uno();
void dos();
void tres();
void cuatro ();
void cinco ();
void seis ();
void siete();
void cuadro(int,int,int,int);
void menu();

/***************************************************************************/
//DEFINE UNO

 void uno()
 {
  int i,j,n,cont,Rf=40,l=30,vect[20];
  clrscr();

  gotoxy(20,3);
  printf(">>>> PROGRAMA  QUE  INVIERTE  UN  VECTOR <<<<");
  gotoxy(6,7); 
  printf("DIMENCION DEL VECTOR....: "); 
   scanf("%d",&n);
  gotoxy(6,12);  
  printf("ELEMENTOS DEL VECTOR CARGADO....:  "); 
      for (i=1;i<=n;i++)
    {
    gotoxy(Rf,12); 
     scanf("%d",&vect[i]);
     Rf+=5;
    }
    j=n;
    for (i=1;i<=(n/2);i++)
    {
      cont=("%d",vect[i]);
   vect[i]=("%d",vect[j]);
   vect[j]=cont;
	 j=j-1;
    }
  
  gotoxy(6,16); 
  printf("VECTOR INVERTIDO.....:");
  for (i=1;i<=n;i++)
  {
  delay(202);
  gotoxy(l,16); 
  printf("%d",vect[i]);
     l+=5;

  gotoxy(18,24);
  printf("********** ENTER PARA REGRESAR AL MENU **********");

  }
  
  getch();
  }

			   //Invierte un vector

/***************************************************************************/

  void dos() 
  {
  char cadena[20], cadena1[20],cadena2[20];
  int j;
  int sw=0;
  int lon;
  clrscr();
  gotoxy(15,3);
  printf(">>>> PROGRAMA  QUE  LEE  UNA  PALABRA  PALINDROME <<<<");
  gotoxy(6,8);
  printf("DIGITE UNA FRASE POR FAVOR...: ");
  gets(cadena);                  //lee desde el teclado una cadena de caracteres
  lon=strlen(cadena);           //calcula la long de la cadena de caracteres
  strcpy (cadena1,cadena);        //copia una cadena de caracteres en otra
  strrev(cadena1);           //invierte una cadena de caracteres

	 for(j=0;j<=lon-1;j++)
	 {
	    if(cadena[j]==cadena1[j])
	    {
	       cadena2[j]=cadena1[j];
	       }
	       else
	       {
		if(cadena[j]==cadena[j+1])
		{
		   cadena2[j]=cadena[j]; 
		   }
		   
		    else
		    {
		      if(cadena[j]==cadena1[j+2])
		      {
			cadena2[j]=cadena[j]; 
			}
			 
			 else
			 {
			   cadena2[j]=' ';
			   }
			 }
		       }
	 }
		  
		  for(j=0;j<=lon-1;j++)
		  {
		   if(cadena[j]==cadena2[j])
		   {
		     sw=1;
		    }           
		      else
		      {
		      sw=0;
		      }    
		   }

		     if(sw == 1)
		     {
		      gotoxy(24,15);
		      printf("#####  PALABRA  PALINDROME  #####");}
		      else 
		      {
		      gotoxy(24,15);
		      printf("#####  PALABRA NO PALINDROME  #####");
		      }
		      gotoxy(18,22);
		      printf("********** ENTER PARA REGRESAR AL MENU **********");
		      getch();
	       }	       

			  //Palabra palindrome
	     
		       
//DEFINE DOS
/***************************************************************************/

  void tres()
  {

  int vect[20];
  int n,m,a,b,may,men,num,pos,i,sum,prom=0;
  clrscr();                  		

  gotoxy(22,3);
  printf(">>>>>>>>>>  ORDENA  UN  VECTOR  <<<<<<<<<<");
  gotoxy(6,6);
  printf("INGRESE LA CAPACIDAD DEL VECTOR...: ");
   scanf("%d",&a);
     for(n=0;n<a;n++)
     {
     gotoxy(6,8+n);
     printf("DIGITE EL ELEMENTO [%d]...: ",n+1);
      scanf("%d",&vect[n]);
     }
      clrscr();
      gotoxy(22,3);
      printf("##########  VECTOR  ORDENADO  ##########");
      gotoxy(4,8);
      printf("EL VECTOR QUE USTED HA INGRESADO ES::::::> ");
	 for(n=0;n<a;n++)
	 {
	  printf("%d\t",vect[n]);
	  sum=sum+vect[n];
	 }
	  for(n=0;n<a-1;n++)
	    for(b=n+1;b<a;b++)
	     if(vect[n]<vect[b]){
		m=vect[n];
	     vect[n]=vect[b];
	     vect[b]=m;
	 }
	  gotoxy(4,13);
	  printf("EL VECTOR ORDENADO  DESCENDENTEMENTE ES:::> ");

	     for(n=0;n<a;n++)
	  printf("%d\t",vect[n]);
	      for(n=0;n<a-1;n++)
	       for(b=n+1;b<a;b++)
		if(vect[n]>vect[b]){
		   m=vect[n];
		vect[n]=vect[b];
		vect[b]=m;
	     }
	  gotoxy(4,18);
	  printf("EL VECTOR ORDENADO ASCENDENTEMENTE ES:::> ");

	     for(n=0;n<a;n++)
	  printf("%d\t",vect[n]);
	      may=vect[n];
	      pos=0; 
	     for(n=0;n<=a-1;n++)
	      if(vect[n]>may)
	       may=vect[n];
	       pos=n;

	  gotoxy(18,23);
	  printf("********** ENTER PARA REGRESAR AL MENU **********");
		
	 getch();
       }

			     //Ordena un vector


//DEFINE TRES
/***************************************************************************/

  void cuatro()
  {
   int num,j,i,vector;
   int prom;
   char vec[10]; 
   clrscr();
   vector=0;
   gotoxy(22,3);
   printf(">>>>>>>>>> SUMA  DE  UN  VECTORES <<<<<<<<<<");
   gotoxy(6,6);
   printf("EXTENCION DEL VECTOR...: ");
    scanf("%d",&num); 
		
     for(i=1;i<=num;i++)
     {
     gotoxy(4,9+i);
     printf("DIGITE EL VECTOR A SUMAR [%d]...: ",i);
      scanf("%d",&vec[i]);
	vector=vector+vec[i];
     }
     gotoxy(29,20);
     printf("LA SUMA DEL VECTOR ES:::::> ",vector);
     printf("%d",vector);

     gotoxy(18,24);
     printf("********** ENTER PARA REGRESAR AL MENU **********");
		
      getch();
     }

			    //Suma de un vector


//DEFINE CUATRO
/***************************************************************************/
								      
  void cinco()
  {
  int i,j,aux,num;
  int alx[6],dul[6],raf[6][6];
  clrscr();
   gotoxy(22,3);
   printf(">>>>> VECTORES  IGUALES  O  DIFERENTES <<<<<");
   gotoxy(6,6);
   printf("INGRESE ELEMENTOS DEL VECTOR...:  ");
    scanf("%d",&num);

     for(i=0;i<num;i++)
     {
     gotoxy(6,8+i);
     printf("INGRESE UN NUMERO AL VECTOR [A]:  ");
      scanf("%d",&alx[i]);
     }
      for(i=0;i<num;i++)
      {
      gotoxy(6,15+i);
      printf("INGRESE UN NUMERO AL VECTOR [B]:  ");
       scanf("%d",&dul[i]);
      }
	aux=1;
	  i=0;

	while(i<num && aux==1)
	{
	   if(alx[i]!=dul[i])
	   {
	     aux=0; 
	 }
	     i++;
	}
	    if( aux==1)
	    {
	      gotoxy(5,22);
	      printf("LOS ELEMENTOS DEL VECTOR [A] SON IGUALES A LOS ELEMENTOS DEL VECTOR [B]\n");
	    }
	      if( aux==0)
	      {
		gotoxy(5,22);
		printf("LOS ELEMENTOS DEL VECTOR [A] SON DIFERENTES A LOS ELEMENTOS DEL VECTOR [B]\n");
	      }
		gotoxy(18,24);
		printf("********** ENTER PARA REGRESAR AL MENU **********");
		
		getch();
	      }


		       //Comparacion de dos vectores


//DEFINE CINCO
/***************************************************************************/

  void seis()
  {
   int vet[5],dal[5],raf[5],j,num=5;
   clrscr();
    gotoxy(22,3);
    printf(">>>>>>>>>> SUMA  DE  DOS  VECTORES <<<<<<<<<<");
  
    gotoxy(6,6);
    printf("VECTOR NUMERO [1] ::::::>\n");

       for(j=0;j<num;j++)
       {
	scanf("%d",&vet[j]);

       }
   gotoxy(6,8+j);
   printf("VECTOR NUMERO [2] ::::::>\n");
   
      for(j=0;j<num;j++)
      { 
	scanf("%d",&dal[j]);
      }

   gotoxy(22,20);
   printf("######  SUMA DE LOS DOS VECTORES  ######\n\n");

      for(j=0;j<num;j++)
      {
       raf[j]= vet[j]+dal[j];
       printf("%d\t",raf[j]);
      }
	gotoxy(18,24);
	printf("********** ENTER PARA REGRESAR AL MENU **********");
	
       getche();
    }

			   //Suma de dos vectores


//DEFINE SEIS
/***************************************************************************/

  void siete()
  {
   int num,j,i,sum;
   int prom;
   char vec[6];
   clrscr();

   sum=0;
   gotoxy(12,3);
   printf(">>>>>> POSICION  DE  LOS  NUMEROS  PARES  E  IMPARES <<<<<<");
   gotoxy(6,6);
   printf("EXTENCION DEL VECTOR...: ");
    scanf("%d",&num); 

      for(i=1;i<=num;i++)
      {
       gotoxy(6,8+i);
       printf("ELEMENTO DEL VECTOR [%d]...: ",i);
	scanf("%d",&vec[i]);
      } 
      for(i=1;i<=num;i++)
       if(vec[i]%2==0)
       {
	printf("     HAY UN NUMERO   PAR  EN  LA POSICION: [%d]\n",i);
       }

       else
       {
	
	printf("     HAY UN NUMERO IMPAR  EN  LA POSICION: [%d]\n",i);
       }

        gotoxy(18,24);
	printf("********** ENTER PARA REGRESAR AL MENU **********");
	getch();
       }


		   //Posicion de los n£meros pares e impares

		       

//DEFINE SIETE
/*********************************cuadro************************************/

 void cuadro(int x1,int x2,int y1,int y2)
 {
  int j,i,k;
     for(j=x1;j<=x2;j++)
       {
       gotoxy(j,y1);printf("Í");
       gotoxy(j,y2);printf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       {
       gotoxy(x1,i);printf("º");
       gotoxy(x2,i);printf("º");
       }
     gotoxy(x1,y1);printf("É");
     gotoxy(x2,y1);printf("»");
     gotoxy(x1,y2);printf("È");
     gotoxy(x2,y2);printf("¼");
}


/**********************************menu*************************************/

 void menu()
 {
 char op;
 do{ 
 clrscr();
		 //PROGRAMA QUE REALIZA TODO LOS PROGRAMAS
 textcolor(15);
 textbackground(9);
 cuadro(7,73,2,23);        
 gotoxy(16,4);printf("CORPORACION UNIVERSITARIA DE SANTANDER >>> UDES <<<");
 gotoxy(34,6);printf("VALLEDUPAR 1998");
 gotoxy(16,8);printf("****************  MENU  PRINCIPAL  *****************");
 gotoxy(15,10);printf( ">>>>> DIGITE UN NUMERO PARA INGRESAR AL SISTEMA <<<<<");
 gotoxy(21,13);printf( "[ 1.]  INVERTIR UN NUMERO  ");
 gotoxy(21,14);printf( "[ 2.]  PALABRA  PALINDROME ");
 gotoxy(21,15);printf( "[ 3.]  ORDENAR UN VECTOR   ");
 gotoxy(21,16);printf("[ 4.]  SUMA DE UN VECTOR   ");
 gotoxy(21,17);printf("[ 5.]  COMPARACION DE DOS VECTORES");
 gotoxy(21,18);printf("[ 6.]  SUMA DE DOS VECTORES    ");
 gotoxy(21,19);printf("[ 7.]  POSICION DE LOS NUMEROS PARES E IMPARES ");
 gotoxy(11,21);printf("#####  DIGITE LA TECLA ESC PARA SALIR DEL SISTEMA  #####");                             
 gotoxy(7,24); printf ("DIGITE SU OPCION ...[  ]");
 gotoxy(28,24);op=getch();

 switch(op)
 {
	   case '1'   : uno();break;
	   case '2'   : dos();break;
	   case '3'   : tres();break;
	   case '4'   : cuatro();break;
	   case '5'   : cinco();break;
	   case '6'   : seis();break;
	   case '7'   : siete();break;
	   case 27    : break;

	   default:clrscr();
		cprintf("Opcion Invalida Verifique");
		getch();
		break;
	    }  
	    } while(op!=27);

  }
				       
/***************************************************************************/

  void main()
  { 

  clrscr();
  menu();
 }

/***************************************************************************/

	      //CORPORACION UNIVERSITARIA DE SANTANDER (UDES)
		    //FACULTAD  INGENIERIA DE SISTEMA
	       //DALILA MICHELA BRACHO ACOSTA COD 96132018
		      //VALLEDUPAR AGOSTO 14 DE 1998
				//S3A

/***************************************************************************/