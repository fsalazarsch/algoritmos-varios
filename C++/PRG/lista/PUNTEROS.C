/***************************************************************************/
		  //METODOS DE ORDENAMIENTOS CON PUNTEROS
/***************************************************************************/
  #include "stdio.h"
  #include "conio.h"
  #include "dos.h"
/***************************************************************************/

  char op;
  void menu();
  void cuadro(int w,int x,int y,int z);
  void burbuja();
  void insercion();
  void seleccion();
  void shell_sort();
  void quick_sort();

  void main()
  {
    menu();
   }
/***************************************************************************/
			 //METODO DE BURBUJA
/***************************************************************************/    

  void burbuja()
  {
   int *vect;
   int i,j,aux,num;
     clrscr();
       gotoxy(7,3);
       printf(">>>>>>>>>>  ORDENA UN VECTOR POR EL METODO DE BURBUJA  <<<<<<<<<<");
       gotoxy(29,23);textcolor(14);printf("#####<<< ENTER >>>#####");
       gotoxy(6,6);
       printf("INGRESE EXTENSION DEL VECTOR...: ");
	scanf("%d",&num);
	vect=(int*) malloc(num);      
 
	  for(i=0;i<num;i++)
	  {
	   gotoxy(6,9+i);
	   printf("DIGITE EL NUMERO [%d]...: ",i);
	    scanf("%d",&vect[i]);
	 }
	  for(i=0;i<num;i++)
	   for(j=0;j<num-1;j++)
	    if(vect[j] > vect[j+1])
	    {
		   aux=vect[j];
	       vect[j]=vect[j+1];
	     vect[j+1]=aux;
	   }
	   clrscr();
	   gotoxy(14,3);
	   printf("###### VECTOR ORDENADO POR EL METODO DE BURBUJA ######");
	     for(j=0;j<num;j++){
	     delay(500);gotoxy(15+j*7,7);printf(" %d\t",vect[j]);
	     gotoxy(18,23);
	     printf("********** ENTER PARA REGRESAR AL MENU **********");

	  }
	  getche();
	}
			      
/**************************************************************************/
			   //METODO DE INSERCION
/***************************************************************************/

  void insercion()
  { 
   int *vector,num,i,j,tem,aux;
   clrscr();
   gotoxy(7,3);
   printf(">>>>>>>>>>  ORDENA UN VECTOR POR EL METODO DE INSERCION  <<<<<<<<<<");
   gotoxy(29,23);textcolor(14);printf("#####<<< ENTER >>>#####");
   gotoxy(6,6);
   printf("INGRESE LA CAPACIDAD DEL VECTOR...:  ");
   scanf("%d",&num);
   vector=(int*) malloc(num);
 
    for(i=1;i<num+1;i++)
    {
     gotoxy(6,9+i);
     printf("DIGITE ELEMENTO DEL VECTOR ...:  ",i);
      scanf("%d",&vector[i]);
   }
     vector[0]=-32767;
	i=2;
     while(i<=num)
     {
	    j=i-1;
	tem=vector[i];
       while(tem<vector[j])
       {
	vector[j+1]=vector[j];
	     j=j-1;
       }
	vector[j+1]=tem;
	i++;
    }

     clrscr();
     for(i=1;i<num+1;i++)
     {
       gotoxy(14,3);
       printf("###### VECTOR ORDENADO POR EL METODO DE INSERCION ######");
       delay(500);gotoxy(15+i*7,7);printf("%d\t",vector[i]);
       gotoxy(18,23);
       printf("********** ENTER PARA REGRESAR AL MENU **********");

     }
       getch();
    }


/**************************************************************************/
			//METODO DE SELECCION
/**************************************************************************/

  void seleccion()
  {
   int *vect,aux,num,i,j;
   clrscr();
   {
    gotoxy(7,3);
    printf(">>>>>>>>>>  ORDENA UN VECTOR POR EL METODO DE SELECCION  <<<<<<<<<<");
    gotoxy(29,23);textcolor(14);printf("#####<<< ENTER >>>#####");
    gotoxy(6,6);
    printf ("INGRESE CAPACIDAD DEL VECTOR...: ");
      scanf("%d",&num);
      vect=(int*) malloc(num);
 
      for(i=0;i<num;i++)
      {
       gotoxy(6,9+i);
       printf("DIGITE ELEMENTO [%d] DEL VECTOR...: ",i+1);
	scanf("%d",&vect[i]);
     }
       for(i=0;i<num-1;i++)
       {
	for(j=i+0;j<num;j++)
	{
	 if(vect[i]>vect[j])
	 {
	    aux=vect[i];
	vect[i]=vect[j];
	vect[j]=aux;
    }
  }
 }
      clrscr();
      gotoxy(14,3);
      printf("###### VECTOR ORDENADO POR EL METODO DE SELECCION ######");
	 for(i=0;i<num;i++)
	 {
	  delay(200);gotoxy(15+i*7,7);printf(" %d\t",vect[i]);
	  gotoxy(18,23);
	  printf("********** ENTER PARA REGRESAR AL MENU **********");

 }
     getch();
  }
}
/**************************************************************************/  
			//METODO DE SHELL-SORT
/***************************************************************************/
 void shell_sort()
 {
   int *vector,j,i,num,Q=0,inter,aux;
   clrscr();
   gotoxy(7,3);
   printf(">>>>>>>>>>  ORDENA UN VECTOR POR EL METODO DE SHELL-SORT  <<<<<<<<<<");
   gotoxy(29,23);textcolor(14);printf("#####<<< ENTER >>>#####");
   gotoxy(6,6);
   printf("INGRESE CAPACIDAD DEL VECTOR...:  ");
    scanf("%d",&num);
    vector=(int*) malloc(num);
 
    for(i=0;i<num;i++)
    {
    gotoxy(6,9+i);
    printf("DIGITE ELEMENTO [%d] DEL VECTOR...: ",i+1);
     scanf("%d",&vector[i]);
    }
     clrscr();
     gotoxy(14,3);
     printf("###### VECTOR ORDENADO POR EL METODO DE QUICK-SORT ######");
	gotoxy(20,7);
	printf(">>>>#### VECTOR INGRESADO NORMALMENTE ####<<<<");
	for(Q=0;Q<num;Q++)
	{
	 delay(500);
	 gotoxy(15+Q*10,10);
	 printf("%d\t",vector[Q]);
	}
	inter=num/2;
	while(inter>0)
	{
	 for(i=inter;i<num;i++)
	 {
	     j=i-inter;
	     while(j>=0)
	     {
	     Q=j+inter;
	      if(vector[j]<=vector[Q])
	      {
	       j=0;
	      }
	       else
	       {
		   aux=vector[j];
	       vector[j]=vector[Q];
	       vector[Q]=aux;
	      }
		     j=j-inter;
	    }
	 }
	    inter/=2;
	  }    
	       gotoxy(13,15);
	       printf("!!!!! VECTOR ORDENADO YA POR EL METODO DE SHELL-SORT !!!!!");
	       for(Q=0;Q<num;Q++)
	       {
		delay(500);
		gotoxy(15+Q*10,18);printf("%d\t",vector[Q]);
		gotoxy(18,23);
		printf("********** ENTER PARA REGRESAR AL MENU **********");

	       }
	     getch();
}

/***************************************************************************/
			 //METODO DE QUICK-SORT
/***************************************************************************/

  void quick_sort()
  {
  int sw=0,aux,ind=1,TEMi,TEMj;
  int Num,Y,i,j,nort[20],sur[20],*vector;
  clrscr();
  gotoxy(7,3);
  printf(">>>>>>>>>>  ORDENA UN VECTOR POR EL METODO DE QUICK-SORT  <<<<<<<<<<");
  gotoxy(29,23);textcolor(14);printf("#####<<< ENTER >>>#####");
  gotoxy(6,6);
  printf("INGRESE CAPACIDAD DEL VECTOR...:  ");
   scanf("%d",&Num);
   vector=(int*) malloc(Num);
 
     for(i=0;i<Num;i++)
     {
     gotoxy(6,9+i);
     printf("DIGITE ELEMENTO [%d] DEL VECTOR...: ",i+1);
      scanf("%d",&vector[i]);
    }
      nort[ind]=0;
       sur[ind]=Num-1;
	 do{
	      i=nort[ind];
	      j=sur[ind];
		   ind--;
	   TEMi=i;
	   TEMj=j;
	      Y=vector[(i+j)/2];

	     sw=0;
	 do{
	    for(;Y>vector[i];i++)
	    {
	      ;
	    }
	     for(;Y<vector[j];j--)
	     { 
	       ;
	     }
	      if(i<j)
	      {
		  aux=vector[i];        //aparece cambio
	    vector[i]=vector[j];
	    vector[j]=aux;
	      i++;
	      j--;
	    }
	      if(i>=j)
		 sw=1;

	    }while(sw!=1);
	       if(i==j)
	       {
		if(Y<vector[i])
		{
		 j--;
		}
		 else
		 {
		   i++;
		 }
	   }
	       if((TEMj -i+1)>1)
	       {
		 ind++;
		 nort[ind]=i;
		  sur[ind]=TEMj;
	}
		else
		{
		 if(vector[i] > vector[TEMj])
		 {
			aux=vector[i];           //cuando aparece cambio
		  vector[i]=vector[TEMj];
	       vector[TEMj]=aux;
	       }
	}
		if((j-TEMi+1) > 1)
		{
		  ind++;
		nort[ind]=TEMi;
		 sur[ind]=j;
	     }
	       else
	       {
		if(vector[TEMi]>vector[j])
	       {
		       aux=vector[TEMi];     // cuando aparece cambio
	      vector[TEMi]=vector[j];
		 vector[j]=aux;
	    }
	}
       }while(ind!= 0);
	clrscr();
	gotoxy(14,3);
	printf("!!!!! VECTOR ORDENADO YA POR EL METODO DE QUICK-SORT !!!!!");
	for(i=0;i<Num;i++)
	{
	delay(400);
	gotoxy(15+i*10,8);printf("%d\t",vector[i]);
	gotoxy(18,23);
	printf("********** ENTER PARA REGRESAR AL MENU **********");

      }
      getch();
  }

/***************************************************************************/
  void menu()
  {
  char op;
  do{
    textcolor(10);
    clrscr();
    cuadro(20,5,63,19);
   textbackground(0);
   gotoxy(29,7);printf(">>>>> MENU PRINCIPAL <<<<<");
   gotoxy(24,9);printf("METODOS DE ORDENAMIENTOS CON PUNTERO");
   gotoxy(35,11);printf("1. BURBUJA");
   gotoxy(35,12);printf("2. INSERCION");
   gotoxy(35,13);printf("3. SELECCION");
   gotoxy(35,14);printf("4. SHELL_SORT");
   gotoxy(35,15);printf("5. QUICK_SORT");
   gotoxy(23,18);printf("TECLA<< ESC >> PARA SALIR DEL SISTEMA");
   cuadro(24,20,59,22);
   gotoxy(25,21);
   cprintf("DIGITE EL METODO QUE DESEE..:");
   op=getch();

   switch(op)
   {
       case '1':
	       burbuja();
	       break;
       case '2':
	       insercion();
	       break;
       case '3':
	       seleccion();
	       break;
       case '4':
	       shell_sort();
	       break;
      case '5':
	       quick_sort();
	       break;

      case 27:
	      break;

     default:clrscr();
		gotoxy(30,30);
		cprintf(">>>>> Opcion Errada Verifique <<<<<");
		getch();
		break;

  }
    } while(op!=27);

}
 void cuadro(int w,int x,int y,int z)
 {
 int q;
 for(q=w;q<=y;q++)
     {
      gotoxy(q,x);cprintf("%c",196);
      gotoxy(q,z);cprintf("%c",196);
     }
      for(q=x;q<=z;q++)
      {
       gotoxy(w,q);cprintf("%c",179);
       gotoxy(y,q);cprintf("%c",179);
     }
       gotoxy(w,x); cprintf("%c",218);
       gotoxy(w,z); cprintf("%c",192);
       gotoxy(y,x); cprintf("%c",191);
       gotoxy(y,z); cprintf("%c",217);
  }


/***************************************************************************/
	     //CORPORACION UNIVERSITARIA DE SANTANDER <<UDES>>
		    //FACULTAD  INGENIERIA DE SISTEMA
	    //DALILA MICHELA BRACHO ACOSTA  COD.96132018  S3A
		    //VALLEDUPAR 28 DE AGOSTO DE 1998
/***************************************************************************/
