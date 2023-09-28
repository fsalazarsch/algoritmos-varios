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

  char valido,cad[20];
  int i,lon,sw,aux,aux2,st,da1,da2;
  long num;
  float valor;

void adicionar_facturas();
void crear_factura();
void  adicionar_aportes();
void crear_aporte();
void consultar_datos();
void consultar_facturas();
void consultar_aportes();
void adicionar_datos();
void menu();


//********************************************************************************
void main()
{
textmode (2);
textcolor(1);
textbackground(1);
menu();
}
/*****************************************************************/
void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);} 
  }


//*****************************************************************************
void adicionar_facturas()
  { 
    char continuar,co;

     clrscr();

   do          {
      window(1,1,80,25);
 textbackground(3);
 clrscr();           
 window(1,1,80,25);
 clrscr();

  textbackground(1);
  window(33,6,48,8);clrscr();//marco(1,1,16,3);
  gotoxy(2,2);textcolor(10);
  cprintf("  ADICIONAR");

  textbackground(1);
  window(20,11,60,21);clrscr();//marco(1,1,33,8);
  textcolor(10);
       clrscr();
	do
	{
	 valido='n';
	 gotoxy(30,7);
	 printf("               ");
	 gotoxy(2,2);printf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cad);
	 lon = strlen(cad);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cad[i])))||(lon>5))
	    {
	     gotoxy(2,9);printf("<<< ERROR >>>... DIGITE NUEVAMENTE ");
	     delay(1500);
	     gotoxy(2,9);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cad);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  clrscr();
	  gotoxy(2,9);printf("<<< ERROR AL INTENTAR ABRIR LA FACTURA >>>");
	  gotoxy(2,9);clreol();
	  getch();exit(1);
	 }

       co='N';


       while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(co=='N'))
	 {
	   if (aux!=sizeof(reg1))
	      {
	       gotoxy(2,9);printf("<<< ERROR DE LECTURA EN LA FACTURA >>>");
	       gotoxy(2,9);clreol();
	       getch();exit(1);
	      }
		      
	   if (reg1.num_fac==num)
	       co='S';
	 }
       if (co=='S')
	{gotoxy(6,7);printf("<<< YA EXISTE FACTURA >>>");getche();}
       else
	  {
	   reg1.num_fac=num;

	   st=1;

	   while(st==1)
	    {
	     gotoxy(31,8);
	     printf("               ");
	     gotoxy(2,3);
	     printf("DIGITE TIPO DE FACTURA (D/C):");scanf("%c",&reg1.tipo_fac);
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
	   gotoxy(2,4);printf("DIGITE EL INCREMENTO DEL IVA:");
	   scanf("\n"); gets(cad);
	   lon = strlen(cad);
	   st=1;
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cad[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cad[i])))
	     {
	      gotoxy(2,9);printf("<<< ERROR >>>... DIGITE NUEVAMENTE ");
	      delay(1500);
	      gotoxy(2,9);
	      clreol();
	      valido='m';
	      break;
	     }
	  }
	 }while(valido=='m');

	 reg1.iva_fac=atof(cad);

	 do
	  {
	   valido='n';
	   gotoxy(29,10);
	   printf("               ");
	   gotoxy(2,5);printf("DIGITE VALOR DE LA FACTURA:");
	   scanf("\n"); gets(cad);
	   st=1;
	   lon = strlen(cad);
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cad[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cad[i])))
	     {
	      gotoxy(2,9);printf("<<< ERROR >>>...DIGITE NUEVAMENTE ");
	      delay(1500);
	      gotoxy(2,9);
	      clreol();
	      valido='m';
	      break;
	     }
	  }
	 }while(valido=='m');

	 reg1.valor_fac=atof(cad);

	 reg1.valor_fac=((reg1.valor_fac*reg1.iva_fac/100)+reg1.valor_fac)-reg1.descu_fac;


	 do
	  {
	   valido='n';
	   gotoxy(32,11);
	   printf("               ");
	   gotoxy(2,6);printf("DIGITE DESCUENTO DE LA FACTURA:");
	   scanf("\n"); gets(cad);
	   st=1;
	   lon = strlen(cad);
	   for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	    {
	     if(cad[i]=='.')
	      {
	       st=2;
	       i++;
	      }
	    }
	    if(!(isdigit(cad[i])))
	     {
	      gotoxy(2,9);printf("<<< ERROR >>>...DIGITE NUEVAMENTE");
	      delay(1500);
	      gotoxy(2,9);
	      clreol();
	      valido='m';
	      break;
	     }
	  }

	  

	 }while(valido=='m');

	 
	 reg1.descu_fac=atof(cad);
	     
	     if(reg1.valor_fac < reg1.descu_fac)
	      {
	       
		 gotoxy(2,8);printf("<<< ERROR >>>...DESCUENTO > VALOR FACT.");
		 delay(1500);
		 gotoxy(2,8);
		 clreol();

	      }


	    else

	     {



	   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
	      {
		gotoxy(2,9);printf("<<< ERROR AL INTENTAR GRABAR EN FACTURA >>>");
	       getch();exit(1);
	      }

	     }
	  }
	close(da1);
	 gotoxy(6,9);printf("DESEA AGREGAR OTRO (S/N): ");
	continuar=toupper(getch());
      }while(continuar!='N');

   return(0);
 }

/************************************************************/

void crear_factura()
   {
    char co1;
      clrscr();
	co1='S';
	  if ((da1=_open("a:factura.dat",1))!=-1)
	    {
 window(1,1,80,25);
 textbackground(3);
 clrscr();           
 window(1,1,80,25);
 clrscr();

  textbackground(1);
  window(33,6,48,8);clrscr();//marco(1,1,16,3);
  gotoxy(2,2);textcolor(10);
  cprintf("CREAR FACTURA");

  textbackground(1);
  window(20,11,60,21);clrscr();//marco(1,1,33,8);
  textcolor(10);
       clrscr();
	    gotoxy(2,4);printf(" YA EXISTE ESTE ARCHIVO ");
	    gotoxy(3,6);printf("DESEA ELIMINARLO (S/N) ");
	    co1=toupper(getch());
	    }  
	   else
	    {
	      if ((da1=_creat("a:factura.dat",0))==-1)
	       {
		gotoxy(2,9);printf(" <<< ERROR AL INTENTAR CREAR FACTURA >>>");
		getch();exit(1);
	       }
	    } 

	 if(co1!='N')
	   {
	    if ((da1=_creat("a:factura.dat",0))==-1)
	     {
	      gotoxy(2,9);printf("<<< ERROR AL INTENTAR CREAR FACTURA >>>");
	      getch();exit(1);
	     }
	   }
	  return(0);
    getche();
    }

//*********************************************************************************

		
void adicionar_aportes()  
{
    char control,continuar;
   int aux,sw,costo,cont,ls;
   int var=1;
    float sum,acum;
       do
       {
 window(1,1,80,25);
 textbackground(3);
 clrscr();           
 window(1,1,80,25);
 clrscr();

  textbackground(1);
  window(31,6,50,8);clrscr();//marco(1,1,20,3);
  gotoxy(2,2);textcolor(10);
  cprintf(" ADICIONAR APORTES");

  textbackground(1);
  window(20,11,60,21);clrscr();//marco(1,1,33,8);
  textcolor(10);
       clrscr();

	ls=1;
	clrscr();
	do
	{
	 valido='n';
	 gotoxy(2,4);printf("INGRESE NUMERO DE LA FACTURA:");
	 gets(cad);
	 lon = strlen(cad);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cad[i])))||(lon>5))
	    {
	     gotoxy(2,9);printf("<< ERROR AL DIGITAR EL NUMERO>>");
	     gotoxy(2,31);clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cad);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  gotoxy(2,9);
	  
	  printf("<< NO SE PUDO ABRIR LA FACTURA >>");
	  gotoxy(2,9);clreol();
	  getch();exit(1);
	 }
	 
       control='N'; cont=0; aux=0;
	     while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(control=='N'))
	       {
		 if (aux!=sizeof(reg1))
		   {
		    
		    gotoxy(23,14);
		    gotoxy(2,9);printf("<< NO SE PUDO LEER LA FACTURA >>");
		    gotoxy(2,9);clreol();
		    getch();exit(1);
		   }
		   cont=cont+1;

		   if (reg1.num_fac==num)
		    {
		     control='S';
		     if(reg1.tipo_fac=='C')
		      {
		       do
			{
			 valido='n';
			 gotoxy(2,6);printf("INGRESE ABONO FACTURA :");
			 scanf("\n"); 
			 gets(cad);
			 
			 lon = strlen(cad);
			 st=1;
			 for(i=0;i<=lon-1; i++)
			 {
			  if(st==1)
			   {
			    if(cad[i]=='.')
			     {
			      st=2;
			      i++;
			     }
			   }
			  if(!(isdigit(cad[i])))
			  {
			   gotoxy(2,9);printf("<< NO SE PUDO INGRESAR ABONO >>");
			   gotoxy(2,9);clreol();
			   valido='m';
			   break;
			  }
			}
		       }while(valido=='m');
		       valor=atof(cad);
		       if( valor > reg1.valor_fac)
			  {
			   gotoxy(2,9);printf("<< NO SE PUEDE HACER ESTE ABONO >>");
			  gotoxy(2,9);clreol();
			  gotoxy(2,9); printf("<< MAYOR QUE VALOR DE FACTURA >>");
			  gotoxy(2,9);clreol();
			  getche();
			  }
			else
			  {
			   st=1; ls=2;
			   reg1.valor_fac=reg1.valor_fac-valor;
			   lseek(da1,(long)((cont-1)*(sizeof(reg1))),0);
			   sum=valor+sum;
			  
			     
			   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
			     {
			      gotoxy(2,9);
			      printf("<< NO SE PUDO GRABAR EN FACTURA >>");
		 gotoxy(2,9);clreol();			      
		 getch();exit(1);
			     }
			   }
		       }
		       else
		       {
		      gotoxy(2,9);
		      printf("<< LA FACTURA FUE PAGADA DE CONTADO >>");
			gotoxy(2,9);clreol();
		       }
		      }  
	      }
	      if ((st==0)&&(sw==0))
	       {
		   gotoxy(2,9);

		printf("<< ESTE NUMERO DE FACTURA NO EXISTE >>");
		gotoxy(2,9);clreol();
	       st=1;
	       }
		else
		  { 

		     if((da2=_open("a:empleado.dat",4))==-1)
		       { 
			      gotoxy(2,9);

			 printf("<< NO SE PUDO ABRIR EL APORTE >>");
			  gotoxy(2,9);clreol();
			 getch();exit(1);
		       }
		      while ((aux2=_read(da2,&reg2,sizeof(reg2)))!=0)
		       {
			 if (aux2!=sizeof(reg2))
			  { 
			      gotoxy(2,9);

			  printf("<< NOSE PUDO LEER EN APORTE >>");
			     gotoxy(2,9);clreol();
			    getch();exit(1);
			  }
		       }
		      reg2.abono_fac=atof(cad);
		      reg2.num_fac=num;

		      if(ls==2)
		      {
		      if ((aux2=_write(da2,&reg2,sizeof(reg2)))!=(sizeof(reg2)))
			      {
			      gotoxy(2,9);

			       printf("<< NO SE PUDO GRABAR EN APORTE >>");
				gotoxy(2,9);clreol();
			       getch();exit(1);
			      }
		      }
		    if(reg1.num_fac!=num){
		    gotoxy(2,9);
		    printf("<< ESTE NUMERO DE FACTURA NO EXISTE >>");
		    gotoxy(2,9);clreol();
		   valido='m';
		   getche();}
		   }
		   close(da2);
		 close(da1);
	  gotoxy(3,9);printf("DESEA INGRESAR OTRO APORTE (S/N): ");
	  continuar=toupper(getch());
	} while(continuar!='N');
   return(0);
   }
 





//*******************************************************************************


void crear_aporte()
  {
   char control1;
   int aux;

   clrscr();
   control1='S';
    if ((da2=_open("a:empleado.dat",1))!=-1)
       {
 window(1,1,80,25);
 textbackground(3);
 clrscr();           
 window(1,1,80,25);
 clrscr();

  textbackground(1);
  window(33,6,48,8);clrscr();//marco(1,1,16,3);
  gotoxy(2,2);textcolor(10);
  cprintf(" CREAR APORTE");

  textbackground(1);
  window(20,11,60,21);clrscr();//marco(1,1,33,8);
  textcolor(10);
       clrscr();
       gotoxy(2,4);printf(" YA EXISTE ESTE ARCHIVO ");
       gotoxy(3,6);printf("DESEA ELIMINARLO (S/N) ");
       control1=toupper(getch());
       }
    else
      { 
       if ((da2=_creat("a:empleado.dat",0))==-1)
	      { gotoxy(2,9);printf(" <<< ERROR AL INTENTAR CREAR APORTE >>>");
	       getch();exit(1);
	      }
	    }  

	   if(control1!='N')
	    {
	     if ((da2=_creat("a:empleado.dat",0))==-1)
	      { gotoxy(2,9);printf("<<< ERROR AL INTENTAR CREAR APORTE >>>");
	       getch();exit(1);
	      }
	    }
    return(0);

  }


//********************************************************************************************

cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(15);textbackground(0);
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
   return(0);
}
/*************************************************************/

void crear_archivo()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(3);

   textcolor(10);
 
   clrscr();
   SALIR='N';
  
  gotoxy(15,25);textcolor(10);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
//  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(1);
  window(35,7,50,9);clrscr();//marco(1,1,16,3);
  
  textbackground(1);
  gotoxy(4,2);textcolor(10);
  cprintf("MENU CREAR   ");

  textbackground(1);
  
  textbackground(1);
  window(25,11,57,18);clrscr();//marco(1,1,33,8);
  textcolor(10);
  gotoxy(4,3);
  cprintf("1.CREAR FACTURA");
  gotoxy(4,4);
  cprintf("2.CREAR APORTES");
  gotoxy(4,5);
  cprintf("3.MENU PRINCIPAL");
 textcolor(10);
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==3)
	   {
	     gotoxy(3,wherey()+2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("%c",2);
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 3:crear_factura();break;
       case 4:crear_aporte();break;
      }

  }
    } while(SALIR!='S');

}
/*********************************************************/
void consultar_facturas()
   {
    char segir,encontro;
    int x;
     do{
       clrscr();
	do
	{
	 valido='n';
	 gotoxy(30,7);
	 printf("               ");
	 gotoxy(2,7);printf("INGRESE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cad);
	 lon = strlen(cad);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cad[i])))||(lon>5))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR NUMERO ¢ MAS DE 5");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	num=atol(cad);

	if((da1=_open("a:factura.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(da1,&reg1,sizeof(reg1)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(reg1))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if(reg1.num_fac==num)
		   {encontro='s';
		   clrscr();
		   printf("Nro Fac: %ld   Tipo Fac: %c   Iva: %.2f   Valor: %.2f   Descuento: %.2f \n\n",reg1.num_fac,
		   reg1.tipo_fac,reg1.iva_fac,reg1.valor_fac,reg1.descu_fac);
		  }
	      }
	   if(encontro=='n')
	    {
	      gotoxy(11,9);printf("NO EXISTE NUMERO DE FACTURA");
	      getch();
	     }
	     close(da1);
	     gotoxy(16,16);printf("DESEA CONSULTAR OTRA (S/N):");
	     segir=toupper(getch());
	     }while(segir=='S');
      return(0);	     
     }
//*****************************************************************************

void consultar_aportes()
 {
  char encontro,segir;
  int x;
  do{
  clrscr();
	do
	  {
 window(1,1,80,25);
 textbackground(3);
 clrscr();           
 window(1,1,80,25);
 clrscr();

  textbackground(1);
  window(33,6,48,8);clrscr();//marco(1,1,16,3);
  gotoxy(2,2);textcolor(10);
  cprintf("CONSULTAR APORTES");

  textbackground(1);
  window(20,11,60,21);clrscr();//marco(1,1,33,8);
  textcolor(10);
       clrscr();
	  valido='n';
	  gotoxy(27,7);
	  printf("               ");
	  gotoxy(2,7);printf("INGRESE NUMERO DE FACTURA:");
	  scanf("\n"); gets(cad);
	  lon = strlen(cad);
	  for(i=0;i<=lon-1; i++)
	   {
	    if((!(isdigit(cad[i])))||(lon>5))
	     {
	      gotoxy(2,9);printf("<<< ERROR AL DIGITAR NUMERO >>>");
	      delay(1500);
	      gotoxy(2,9);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
	 num=atol(cad);

	if((da2=_open("a:empleado.dat",1))==-1)
	  {gotoxy(2,9);printf("<<< ERROR DE APERTURA >>>");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(da2,&reg2,sizeof(reg2)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(reg2))
	       {gotoxy(2,9); printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if(reg2.num_fac==num)
		   {encontro='s';
		   clrscr();
		   printf("Numero De Factura: %ld   Abono: %.2f\n",reg2.num_fac,reg2.abono_fac);
		  }
	      }
	   if(encontro=='n')
	    {clrscr();
	      gotoxy(11,7);
	      printf("NO EXISTE ESTE NUMERO DE FACTURA");
	      getch();
	     }
	     close(da2);
	     gotoxy(17,16);printf("DESEA CONSULTAR OTRA (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }

//************************************************************************************


void consultar_datos()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(3);

   textcolor(10);
 
   clrscr();
   SALIR='N';
  
  gotoxy(15,25);textcolor(10);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
//  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(1);
  window(35,7,50,9);clrscr();//marco(1,1,16,3);
  
  textbackground(1);
  gotoxy(2,2);textcolor(10);
  cprintf("MENU CONSULTAR");

  textbackground(1);
  
  textbackground(1);
  window(25,11,57,18);clrscr();//marco(1,1,33,8);
  textcolor(10);
  gotoxy(4,3);
  cprintf("1.CONSULTAR FACTURA");
  gotoxy(4,4);
  cprintf("2.CONSULTAR APORTES");
  gotoxy(4,5);
  cprintf("3.MENU PRINCIPAL");

 textcolor(10);
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==3)
	   {
	     gotoxy(3,wherey()+2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("%c",2);
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 3:consultar_facturas();break;
       case 4:consultar_aportes();break;
      }

  }
    } while(SALIR!='S');
}

//************************************************************************************


void adicionar_datos()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(3);

   textcolor(10);
 
   clrscr();
   SALIR='N';
  
  gotoxy(15,25);textcolor(10);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
 // marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(1);
  window(35,7,50,9);clrscr();//marco(1,1,16,3);
  
  textbackground(1);
  gotoxy(2,2);textcolor(10);
  cprintf("MENU ADICIONAR");

  textbackground(1);
  
  textbackground(1);
  window(25,11,57,18);clrscr();//marco(1,1,33,8);
  textcolor(10);
  gotoxy(4,3);
  cprintf("1.ADICIONAR FACTURAS");
  gotoxy(4,4);
  cprintf("2.ADICIONAR APORTES");
  gotoxy(4,5);
  cprintf("3.MENU PRINCIPAL");

 textcolor(10);
 gotoxy(3,3);cprintf("%c",2);gotoxy(3,3);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==3)
	   {
	     gotoxy(3,wherey()+2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("%c",2);
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-2);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 3:adicionar_facturas();break;
       case 4:adicionar_aportes();break;
      }

  }
    } while(SALIR!='S');

}
//************************************************************************************

void menu()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(3);

   textcolor(10);
 
   clrscr();
   SALIR='N';
  
  gotoxy(15,25);textcolor(10);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);

  textbackground(1);
  window(35,7,50,9);clrscr();
  
  textbackground(1);
  gotoxy(2,2);textcolor(10);
  cprintf("MENU PRICIPAL");

  textbackground(1);
  
  textbackground(1);
  window(25,11,57,18);clrscr();
  textcolor(10);
  gotoxy(4,2);
  cprintf("1.ELABORAR ARCHIVO");
  gotoxy(4,3);
  cprintf("2.ADICIONAR ");
  gotoxy(4,4);
  cprintf("3.CONSULTAR ");
  gotoxy(4,5);
  cprintf("4.SALIR");
  textcolor(10);
 gotoxy(3,2);cprintf("%c",2);gotoxy(3,2);

 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(3,wherey()+3);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("%c",2);
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-3);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("%c",2);
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:{crear_archivo();break;}
       case 3:{adicionar_datos();break;}
       case 4:{consultar_datos();break;}
      }

  }
    } while(SALIR!='S');

}
