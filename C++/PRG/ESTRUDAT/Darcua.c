

#include<stdio.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<io.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>


struct  factura
{
  long num_fac;
  char tipo_fac;
  float iva_fac;
  float valor_fac;
  float descu_fac;

};


struct  aporte
{
  long num_fac;
  float abono_fac;
};


struct factura reg1;
struct aporte reg2;

  char valido,cadena[20];
  int i,lon,sw,aux,aux2,st,da1,da2;
  long num;
  float valor;

/***************************************************************************/
//***********************CUADRO*********************************************
void cuadro(int i,int j)
  {
   int st,con;
   clrscr();
   textcolor(4);
   gotoxy(10,3);cprintf("±"); /** ALT 177 **/
   gotoxy(70,3);cprintf("±");
   gotoxy(10,23);cprintf("±"); /** ALT 177 **/
   gotoxy(70,23);cprintf("±"); /** ALT 177 **/
   st=1;  con=0;
   while((st==1)&&(con<=3))
   {
   con++;
    for(j=10; j<=70; j++)
     {
     //textcolor(0);
     textcolor(4);
     }
     for(i=70; i>=10; i--)
      {
      delay(5);
      j=i;
      gotoxy(i,2);
      textcolor(4);//textcolor(j-1);
      textcolor(4);//textcolor(i);
      cprintf("±"); /** ALT  **/
      gotoxy(i,24);cprintf("±"); /** ALT 177**/
      gotoxy(15,11);
      textcolor(4);//textcolor(j-1);
      textcolor(4);//textcolor(i);
      j=i-8;
      if (j<=23)
       {
	gotoxy(10,j);cprintf("±");  /** ALT 177**/
	gotoxy(70,j);cprintf("±");  /** ALT 177 **/
       }
      }
     }
    }

//*****************************************************************************
//********************* ELABORAR FACTURA**************************************
 agregar_factura()
  { 
    char continuar,control;
    int con;

     clrscr();


      do
     {

     	do
	{
	 clrscr();
	 valido='n';
	 gotoxy(47,6);
	 //printf("               ");
	 cuadro(80,23);
	 cuadros(18,64,5,20);
	 gotoxy(21,6);cprintf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
	    {
	     gotoxy(23,14);
	     gotoxy(23,14);printf("<< DIGITO MAL EL NUMERO ¢ MAS DE 5 >>");
	     sound(1000);
	     delay(1500);
	     nosound();
	     delay(1500);
	     gotoxy(23,14);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cadena);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  //clrscr();
	  gotoxy(23,14);
	  printf("<< NO SE PUDO ABRIR LA FACTURA >>");
	  sound(1000);
		 delay(1500);
		 nosound();
	  getch();exit(1);
	 }

       control='N';


       while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(control=='N'))
	 {
	   if (aux!=sizeof(reg1))
	      {
	       gotoxy(23,14);
	       printf("<< NO SE PUDO LEER EN FACTURA >>");
	       sound(1000);
		 delay(1500);
		 nosound();
	       getch();exit(1);
	      }
		      
	   if (reg1.num_fac==num)
	       control='S';
	 }
       if (control=='S'){
	   gotoxy(23,14);
	   printf("<< ESTA FACTURA YA EXISTE >>"); 
	   sound(1000);
		 delay(1500);
		 nosound();}

       else
	  {
	   reg1.num_fac=num;

	   st=1;

	   while(st==1)
	    {
	     gotoxy(31,8);
	     printf("               ");
	     gotoxy(21,7);
	     printf("DIGITE TIPO DE FACTURA [D] : [C] :");scanf("%c",&reg1.tipo_fac);
	     reg1.tipo_fac=toupper(reg1.tipo_fac);
	     if((reg1.tipo_fac=='D')||(reg1.tipo_fac=='C'))
	      {
	       st=2;
	      }
	     
	    }

	  do
	  {
	   valido='n';
	   gotoxy(25,9);
	   printf("               ");
	   gotoxy(21,8);printf("DIGITE EL INCREMENTO DEL IVA:");
	   scanf("\n"); gets(cadena);
	   lon = strlen(cadena);
	   st=1;
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cadena[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cadena[i])))
	     {
	      //cuadros(18,64,5,20);
	      gotoxy(21,15);
	      gotoxy(23,14);printf("<< ERROR AL DIGITAR NUMERO >>");
	      sound(1000);
		 delay(1500);
		 nosound();
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	     }
	  }
	 }while(valido=='m');

	 reg1.iva_fac=atof(cadena);

         do
	  {
	   valido='n';
	   gotoxy(29,10);
	   printf("               ");

	   gotoxy(21,9);printf("DIGITE VALOR DE LA FACTURA:");
	   scanf("\n"); gets(cadena);
	   st=1;
	   lon = strlen(cadena);
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cadena[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cadena[i])))
	     {
	      //cuadros(18,64,5,20);
	      gotoxy(23,14);printf("<< ERROR AL DIGITAR NUMERO >>");
	      sound(1000);
		 delay(1500);
		 nosound();
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	     }
	  }
	 }while(valido=='m');

	 reg1.valor_fac=atof(cadena);

	 reg1.valor_fac=reg1.valor_fac+reg1.valor_fac*reg1.iva_fac;


	 do
	  {
	   valido='n';
	   gotoxy(32,11);
	   printf("               ");
	   gotoxy(21,10);printf("DIGITE DESCUENTO DE LA FACTURA:");
	   scanf("\n"); gets(cadena);
	   st=1;
	   lon = strlen(cadena);
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cadena[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cadena[i])))
	     {
	       //cuadro(80,23);
	       //cuadros(18,64,5,20);
	       gotoxy(23,14);
	      printf("<< ERROR AL DIGITAR NUMERO >>");
	      sound(1000);
		 delay(1500);
		 nosound();
	      delay(1500);
	      gotoxy(23,14);
	      clreol();
	      valido='m';
	      break;
	     }

	  }

	  

	 }while(valido=='m');
	 con=2;
	 reg1.descu_fac=atof(cadena);
	     if( reg1.descu_fac > reg1.valor_fac )
	      {
		 con=1;
		 //cuadro(80,23);
		 //cuadros(18,64,5,20);
		 gotoxy(21,14);

		 gotoxy(23,14);printf("<< VALOR DE DESCUENTO MAYOR QUE PRECIO >>");
		 sound(1000);
		 delay(1500);
		 nosound();
		 gotoxy(10,20);
		 //clreol();
		 gotoxy(21,15);printf("<< REGISTRO NO VALIDO >>");
		 sound(1000);
		 delay(1500);
		 nosound();

	      }


	    if(con==2)

	     {

	   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
	      {gotoxy(23,14);
		cuadro(80,23);
		cuadros(18,64,5,20);

	       printf("<< NO SE PUDO GRABAR EN FACTURA >>");
	       sound(1000);
		 delay(1500);
		 nosound();
	       getch();exit(1);
	      }

	      }
	     }

	close(da1);
	gotoxy(25,22);printf("DESEA AGREGAR OTRA (S/N): ");
	continuar=toupper(getch());
      }while(continuar!='N');
   return(0);
 }


/***********************************************************************/
///****************** CREAR ARCHIVO DE FACTURA**************************
 crear_factura()
   {
    char control1;
      clrscr();
	control1='S';
	  if ((da1=_open("a:factura.dat",1))!=-1)
	    {
	    cuadro(80,23);
	    cuadros(24,56,9,14);
	    gotoxy(25,10);printf("ARCHIVO DE FACTURA CREADO");
	    gotoxy(25,13);printf("DESEA ELIMINARLO (S/N) ");
	    control1=toupper(getch());
	    }  
	   else
	    {
	      if ((da1=_creat("a:factura.dat",0))==-1)
	       {
		//cuadro(80,23);
		//cuadros(18,64,5,20);
		gotoxy(23,14);
		printf("<< NO SE PUDO CREAR FACTURA >>");
		sound(1000);
		 delay(1500);
		 nosound();
		getch();exit(1);
	       }
	    } 

	 if(control1!='N')
	   {
	    if ((da1=_creat("a:factura.dat",0))==-1)
	     {
	    //cuadro(80,23);
	    //cuadros(18,64,5,20);
	      gotoxy(23,14);
	      gotoxy(23,14);printf("<< NO SE PUDO CREAR FACTURA >>");
	      sound(1000);
		 delay(1500);
		 nosound();
	      getch();exit(1);
	     }
	   }
	  return(0);
    }

//*********************************************************************************
//*********************** ASIGNAR APORTES*************************************
 agregar_aporte()
  {
   char control,continuar;
   int aux,costo,cont,ls;

       do
       {
	ls=1;
	clrscr();
	do
	{
	 valido='n';
	 gotoxy(30,7);
	 printf("               ");
	 cuadro(80,23);
	    cuadros(18,64,5,20);
	 gotoxy(21,6);printf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
	    {
	     //cuadro(80,23);
	    //cuadros(18,64,5,20);
	     gotoxy(23,14);printf("<< MAL DIGITADO EL NUMERO ¢ MAS DE 5 >>");
	     sound(1000);
		 delay(1500);
		 nosound();
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cadena);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  clrscr();
	  gotoxy(23,14);
	  //cuadro(80,23);
	    //cuadros(18,64,5,20);
       
	  printf("<< NO SE PUDO ABRIR LA FACTURA >>");
	  sound(1000);
		 delay(1500);
		 nosound();
	  getch();exit(1);
	 }

       control='N'; cont=0; aux=0;
	     while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(control=='N'))
	       {
		 if (aux!=sizeof(reg1))
		   {
		    gotoxy(23,14);
		    //cuadro(80,23);
	    //cuadros(18,64,5,20);
		    printf("<< NO SE PUDO LEER LA FACTURA >>");
		    sound(1000);
		 delay(1500);
		 nosound();
		    getch();exit(1);
		   }
		   cont=cont+1;

		   if (reg1.num_fac==num)
		    {
		     control='S';
		     sw=1;
		     if(reg1.tipo_fac=='C')
		      {
		       do
			{
			 valido='n';
			 gotoxy(24,8);
			 printf("               ");
			 gotoxy(21,8);printf("INGRESE ABONO FACTURA :");
			 scanf("\n"); gets(cadena);
			 lon = strlen(cadena);
			 st=1;
			 for(i=0;i<=lon-1; i++)
			 {
			  if(st==1)
			   {
			    if(cadena[i]=='.')
			     {
			      st=2;
			      i++;
			     }
			   }
			  if(!(isdigit(cadena[i])))
			  {
			   gotoxy(23,14);printf("<< NO SE PUDO INGRESAR ABONO >>");
			   sound(1000);
			   delay(1500);
			   nosound();
			   delay(1500);
			   gotoxy(10,20);
			   clreol();
			   valido='m';
			   break;
			  }
			}
		       }while(valido=='m');
		       valor=atof(cadena);
		       if( valor > reg1.valor_fac)
			  {
			   gotoxy(23,14);
			  //cuadro(80,23);
			   //cuadros(18,64,5,20);
			   printf("<< NO SE PUEDE HACER ESTE ABONO >>");
			  sound(1000);
		 delay(1500);
		 nosound();
			  }
			else
			  {
			   st=1; ls=2;
			   reg1.valor_fac=reg1.valor_fac-valor;
			   lseek(da1,(long)((cont-1)*(sizeof(reg1))),0);
			   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
			     {
			      //cuadro(80,23);
			      //cuadros(18,64,5,20);
			      gotoxy(23,14);

			      printf("<< NO SE PUDO GRABAR EN FACTURA >>");

			      sound(1000);
			      delay(1500);
			      nosound();
		 getch();exit(1);
			     }
			   }
		       }
		       else
		       {
			      //cuadro(80,23);
			      //cuadros(18,64,5,20);
			      gotoxy(23,14);

		       printf("<< LA FACTURA FUE PAGADA DE CONTADO >>");
		       sound(1000);
		       delay(1500);
		       nosound();
		       }
		      }
	      }
	      if ((st==0)&&(sw==0))
	       {
		   //cuadro(80,23);
		   //cuadros(18,64,5,20);
		   gotoxy(23,14);

		printf("<< ESTE NUMERO DE FACTURA NO EXISTE >>");
	       sound(1000);
	       delay(1500);
	      nosound();
	       }
		else
		  { 

		     if((da2=_open("a:empleado.dat",4))==-1)
		       { clrscr();
			      //cuadro(80,23);
			      //cuadros(18,64,5,20);
			      gotoxy(23,14);

			 printf("<< NO SE PUDO ABRIR EL APORTE >>");
			 sound(1000);
		 delay(1500);
		 nosound();
			 getch();exit(1);
		       }
		      while ((aux2=_read(da2,&reg2,sizeof(reg2)))!=0)
		       {
			 if (aux2!=sizeof(reg2))
			  { 
			      //cuadro(80,23);
			      //cuadros(18,64,5,20);
			      gotoxy(23,14);

			  printf("<< NOSE PUDO LEER EN APORTE >>");
			    sound(1000);
		 delay(1500);
		 nosound();
			    getch();exit(1);
			  }
		       }
		      reg2.abono_fac=atof(cadena);
		      reg2.num_fac=num;
		      if(ls==2)
		      {
		      if ((aux2=_write(da2,&reg2,sizeof(reg2)))!=(sizeof(reg2)))
			      {
			       //cuadro(80,23);
			      //cuadros(18,64,5,20);
			      gotoxy(23,14);

			       printf("<< NO SE PUDO GRABAR EN APORTE >>");
			       sound(1000);
			       delay(1500);
			       nosound();
			       getch();exit(1);
			      }
		      }
		   }
		   close(da2);
		 close(da1);
	  gotoxy(25,22);printf("DESEA AGREGAR OTRO APORTE (S/N): ");
	  continuar=toupper(getch());
	} while(continuar!='N');
   return(0);
 }


//*******************************************************************************
//*************************CREAR ARCHIVO DE APOTES***************************
 crear_aporte()
  {
   char control1;
   int aux;

   clrscr();
   control1='S';
    if ((da2=_open("a:empleado.dat",1))!=-1)
       {
       cuadro(80,23);
       cuadros(24,56,9,14);       gotoxy(25,10);
       printf("ARCHIVO DE APORTE CREADO");
       gotoxy(25,13);printf("DESEA ELIMINARLO (S/N) ");
       control1=toupper(getch());
       }
    else
      { 
       if ((da2=_creat("a:empleado.dat",0))==-1)
	      {   //cuadro(80,23);
		  //cuadros(18,64,5,20);
		  gotoxy(23,14);

	       printf("<< NO SE PUDO CREAR APORTE >>");
	       sound(1000);
	       delay(1500);
	       nosound();
	       getch();exit(1);
	      }
	    }  

	   if(control1!='N')
	    {
	     if ((da2=_creat("a:empleado.dat",0))==-1)
	      { 
		 //cuadro(80,23);
		 //cuadros(18,64,5,20);
		 gotoxy(23,14);

	      printf("<< NO SE PUDO CREAR APORTE >>");
	       getch();exit(1);
	      }
	    }
    return(0);

  }


//********************************************************************************************
//************************** CUADRO2*****************************************
cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(15);//textbackground(5);

     for(j=x1;j<=x2;j++)
       { 
       
       gotoxy(j,y1);cprintf("±");
       gotoxy(j,y2);cprintf("±");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("±");
       gotoxy(x2,i);cprintf("±");
       }
     gotoxy(x1,y1);cprintf("±±");
     gotoxy(x2,y1);cprintf("±");
     gotoxy(x1,y2);cprintf("±");
     gotoxy(x2,y2);cprintf("±");
   return(0);
}
/***********************************************************************/
//*****************CONSULTAR FACTURA****************************************
buscar_factura()
   {
    char segir,encontro;
    int x ;
     float total;
     do{
       clrscr();
	do
	{
	 valido='n';
	 gotoxy(30,7);
	 printf("               ");
	 cuadro(80,23);
	 cuadros(18,64,5,20);
	 gotoxy(23,14);
	 gotoxy(21,6);printf("INGRESE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
	    {
	     //cuadro(80,23);
	    //cuadros(18,64,5,20);
	    gotoxy(23,14);
	     gotoxy(23,14);printf("<< DIGITO MAL EL NUMERO ¢ MAS DE 5 >>");
	     sound(1000);
	     delay(1500);
	     nosound();
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cadena);

	if((da1=_open("a:factura.dat",1))==-1)
	  {
	 //cuadro(80,23);
	   //cuadros(18,64,5,20);
	   gotoxy(25,14);
	  printf("<< ERROR DE APERTURA >>");getch();exit(1);
	   sound(1000);
	   delay(1500);
	   nosound();
	   }encontro='n';
	    while(((x=_read(da1,&reg1,sizeof(reg1)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(reg1))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if(reg1.num_fac==num)
		   {encontro='s';
		
		gotoxy(21,8);printf("No DE  FACTURA   : %ld\n",reg1.num_fac); 
		gotoxy(21,9);printf("TIPO FACTURA     : %c\n",reg1.tipo_fac); 
		gotoxy(21,10);printf("INCREMENTO IVA   : %.2f\n",reg1.iva_fac);  
		gotoxy(21,11);printf("VALOR FACTURA    : %.2f\n",reg1.valor_fac);  
		gotoxy(21,12);printf("DESCUENTO DE FAC : %.2f\n",reg1.descu_fac); 

	       //total=(reg1.iva_fac+reg1.valor_fac-reg1.descu_fac);
		//gotoxy(21,13);printf("TOTAL VALOR FAC  : %.2f\n",reg1.total_fac); 
		  }
	       
	       }
	   if(encontro=='n')
	    {
	    gotoxy(23,14);
	      printf("<< NO EXISTE NUMERO DE FACTURA >>");
	      sound(1000);
	      delay(1500);
	      nosound();
	      getch();
	     }
	     close(da1);
	     gotoxy(25,22);printf("DESEA CONSULTAR OTRA (S/N):");
	     segir=toupper(getch());
	     }while(segir=='S');
      return(0);	     
     }
//*****************************************************************************
//****************************CONSULTAR APORTE*************************************************
buscar_aporte()
 {
  char encontro,segir;
  int x;
  do{
  clrscr();
	do
	  {
	  valido='n';
	  gotoxy(27,7);
	  printf("               ");
	  cuadro(80,23);
	    cuadros(18,64,5,20);
	    gotoxy(21,6);printf("INGRESE NUMERO DE FACTURA:");
	  scanf("\n"); gets(cadena);
	  lon = strlen(cadena);
	  for(i=0;i<=lon-1; i++)
	   {
	    if((!(isdigit(cadena[i])))||(lon>5))
	     {
	      //cuadro(80,23);
	    //cuadros(18,64,5,20);
	    gotoxy(23,14);
	      printf("<< DIGITO MAL EL NUMERO ¢ MAS DE 5 >>");
	      sound(1000);
	      delay(1500);
	      nosound();
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
	 num=atol(cadena);

	if((da2=_open("a:empleado.dat",1))==-1)
	  {
	  cuadro(80,23);
	    //cuadros(18,64,5,20);
	    //gotoxy(23,14);
	  printf("<< ERROR DE APERTURA >>");getch();exit(1);
	   sound(1000);
	   delay(1500);
	   nosound();
	   }encontro='n';
	    while(((x=_read(da2,&reg2,sizeof(reg2)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(reg2))
	       {
	       cuadro(80,23);
	    cuadros(18,64,5,20);
	    gotoxy(23,14);
	       printf("<< ERROR DE LECTURA >>");getch();exit(1);
		sound(1000);
		 delay(1500);
		nosound();
		getche();
		}
		 if(reg2.num_fac==num)
		   {encontro='s';
		  gotoxy(21,10); printf("No De FACTURA: %ld\n",reg2.num_fac);   
		  gotoxy(21,11); printf("SE ABONO     : %.2f\n",reg2.abono_fac);
		  }
	      }
	   if(encontro=='n')
	    {
	    gotoxy(23,14);
	      printf("<< NO EXISTEN APORTES >>");
	      sound(1000);
	      delay(1500);
	       nosound();
	      getch();
	     }
	     close(da2);
	     gotoxy(25,22);printf("DESEA CONSULTAR OTRA (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }

//*************************MENU PRINCIPAL**********************************************
//****************************************************************************
void main()
 {
  char op;   int i,j;
  textcolor(15);
  textbackground(0);
  do
   {
       cuadro(80,24);
    textcolor(15);
    gotoxy (19,4);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (19,9);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (19,5);  cprintf("±");gotoxy (19,7);  cprintf("±");gotoxy (19,9);  cprintf("±");
    gotoxy (19,6);  cprintf("±");gotoxy (19,8);  cprintf("±");
    gotoxy (59,4);  cprintf("±"); gotoxy (59,5);  cprintf("±");gotoxy (59,6);  cprintf("±");
    gotoxy (59,7);  cprintf("±");gotoxy (59,8);  cprintf("±");gotoxy (59,9);  cprintf("±");
    gotoxy (20,6);  cprintf("CORPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy (25,7);  cprintf("DARWIN HELMUTHS LEON PEREZ");
    gotoxy (30,8);  cprintf("COD 96132068 S2B");
    gotoxy (25,23);  cprintf("*******************************");
    gotoxy (24,13);  cprintf("±");gotoxy (24,14);  cprintf("±");gotoxy (24,16);  cprintf("±");
    gotoxy (24,15);  cprintf("±");gotoxy (24,17);  cprintf("±");gotoxy (24,18);  cprintf("±");
    gotoxy (24,19);  cprintf("±");
    gotoxy (24,12);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
    gotoxy (24,20);  cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");

    gotoxy (24,20);  cprintf("±");
    gotoxy (54,20);  cprintf("±");
    gotoxy (54,13);  cprintf("±");gotoxy (54,16);  cprintf("±");gotoxy (54,17);  cprintf("±");
    gotoxy (54,14);  cprintf("±");gotoxy (54,15);  cprintf("±");gotoxy (54,18);  cprintf("±");
    gotoxy (54,19);  cprintf("±");
    gotoxy (29,11); cprintf("<< MENU PRINCIPAL >>");
    gotoxy (28,13); cprintf("A:CREAR ARCHIVO DE FACTURA\n");
    gotoxy (28,14); cprintf("B:CREAR ARCHIVO DE APORTES\n");
    gotoxy (28,15); cprintf("C:ELABORAR FACTURA\n");
    gotoxy (28,16); cprintf("D:ASIGNAR APORTES\n");
    gotoxy (28,17); cprintf("E:CONSULTAR FACTURAS\n");
    gotoxy (28,18); cprintf("F:CONSULTAR APORTES\n");
    gotoxy (28,19); cprintf("O:SALIR              \n");
    gotoxy (28,22); cprintf("DIGITE OPCION:");
    op=toupper(getche());
    switch(op)
	  {

      case'A':crear_factura();break;
      case'B':crear_aporte();break;
      case'C':agregar_factura();break;
      case'D':agregar_aporte();break;
      case'E':buscar_factura();break;
      case'F':buscar_aporte();break;
     }
     }while(op!='O');
 }

//********************************************************************************
  //************************************FINAL*****************************************


