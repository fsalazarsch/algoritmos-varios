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


struct  arch_1
{
  long num_fac;
  char tipo_fac;
  float iva_fac;
  float valor_fac;
  float descu_fac;

};


struct  arch_2
{
  long num_fac;
  float abono_fac;
};

struct arch_1 reg1;
struct arch_2 reg2;

  char valido,cadena[20];
  int i,lon,sw,aux,aux2,st,da1,da2;
  long num;
  float valor;


//*****************************************************************************


 adicionar_archivo_1()
  { 
    char continuar,control;

     clrscr();

   do
     {
       clrscr();
	do
	{
	 valido='n';
	 gotoxy(30,7);
	 printf("               ");
	 gotoxy(2,7);printf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
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

	num=atol(cadena);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  clrscr();
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO 1");
	  getch();exit(1);
	 }

       control='N';


       while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(control=='N'))
	 {
	   if (aux!=sizeof(reg1))
	      {
	       printf(" ERROR DE LECTURA EN ARCHIVO 1"); 
	       getch();exit(1);
	      }
		      
	   if (reg1.num_fac==num)
	       control='S';
	 }
       if (control=='S')
	   printf("ESTE NUMERO DE FACTURA YA EXISTE");
       else
	  {
	   reg1.num_fac=num;

	   st=1;

	   while(st==1)
	    {
	     gotoxy(34,8);
	     printf("               ");
	     gotoxy(2,8);
	     printf("DIGITE TIPO DE FACTURA ( D o C):");scanf("%c",&reg1.tipo_fac);
	     reg1.tipo_fac=toupper(reg1.tipo_fac);
	     if((reg1.tipo_fac=='D')||(reg1.tipo_fac=='C'))
	      {
	       st=2;
	      }
	     
	    }

	  do
	  {
	   valido='n';
	   gotoxy(30,9);
	   printf("               ");
	   gotoxy(2,9);printf("DIGITE IVA EN PORCENTAJE (%):");
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
	      gotoxy(10,20);printf("ERROR AL DIGITAR NUMERO !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	     }
	  }
	 }while(valido=='m');

	 reg1.iva_fac=atof(cadena);
	 reg1.iva_fac=reg1.iva_fac/100;

         do
	  {
	   valido='n';
	   gotoxy(29,10);
	   printf("               ");
	   gotoxy(2,10);printf("DIGITE VALOR DE LA FACTURA:");
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
	      gotoxy(10,20);printf("ERROR AL DIGITAR NUMERO !");
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
	   gotoxy(2,11);printf("DIGITE DESCUENTO DE LA FACTURA:");
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
	      gotoxy(10,20);printf("ERROR AL DIGITAR NUMERO !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	     }
	  }

	  

	 }while(valido=='m');

	 
	 reg1.descu_fac=atof(cadena);
	     
	     if(reg1.valor_fac < reg1.descu_fac)
	      {
	       
		 gotoxy(10,20);printf("ERROR VALOR DE DESCUENTO MAYOR QUE PRECIO");
		 delay(1500);
		 gotoxy(10,20);
		 clreol();
		 gotoxy(10,20);printf("ESTE REGISTRO NO SERA GUARDADO");
		 delay(1500);
		 gotoxy(10,20);
		 clreol();

	      }


	    else

	     {

	 reg1.valor_fac=reg1.valor_fac - reg1.descu_fac;


	   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
	      {
	       printf("ERROR AL INTENTAR GRABAR EN ARCHIVO 1");
	       getch();exit(1);
	      }

	     }
	  }
	close(da1);
	printf("\nDESEA ADICIONAR (S/N): ");
	continuar=toupper(getch());
      }while(continuar!='N');

   return(0);
 }



 crear_archivo_1()
   {
    char control1;
      clrscr();
	control1='S';
	  if ((da1=_open("a:factura.dat",1))!=-1)
	    {
	    gotoxy(2,5);printf("CUIDADO ESTE ARCHIVO YA EXISTE");
	    gotoxy(2,7);printf("DESEA BORRARLO (S/N) ");
	    control1=toupper(getch());
	    }  
	   else
	    {
	      if ((da1=_creat("a:factura.dat",0))==-1)
	       {
		printf(" ERROR AL INTENTAR CREAR ARCHIVO 1");
		getch();exit(1);
	       }
	    } 

	 if(control1!='N')
	   {
	    if ((da1=_creat("a:factura.dat",0))==-1)
	     {
	      printf(" ERROR AL INTENTAR CREAR ARCHIVO 1");
	      getch();exit(1);
	     }
	   adicionar_archivo_1(); 
	   }
	  return(0);
    }

//*********************************************************************************


 adicionar_archivo_2()
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
	 gotoxy(2,7);printf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
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

	num=atol(cadena);

       if ((da1=_open("a:factura.dat",4))==-1)
	 { 
	  clrscr();
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO 1");
	  getch();exit(1);
	 }

       control='N'; cont=0; aux=0;
	     while(((aux=_read(da1,&reg1,sizeof(reg1)))!=0)&&(control=='N'))
	       {
		 if (aux!=sizeof(reg1))
		   {
		    printf(" ERROR DE LECTURA EN ARCHIVO 1");
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
			 gotoxy(2,8);printf("DIGITE ABONO FACTURA :");
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
			   gotoxy(10,20);printf("ERROR AL DIGITAR ABONO !");
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
			   printf("\n NO SE DEBE HACER ESTE ABONO");
			  }
			else
			  {
			   st=1; ls=2;
			   reg1.valor_fac=reg1.valor_fac-valor;
			   lseek(da1,(long)((cont-1)*(sizeof(reg1))),0);
			   if ((aux=_write(da1,&reg1,sizeof(reg1)))!=(sizeof(reg1)))
			     {
			      printf("ERROR AL INTENTAR GRABAR EN ARCHIVO 1");
			      getch();exit(1);
			     }
			   }
		       }
		       else
		       {
		       printf("\nLA FACTURA FUE PAGADA DE CONTADO");
		       }
		      }
	      }
	      if ((st==0)&&(sw==0))
	       {
		printf("ESTE NUMERO DE FACTURA NO EXISTE");
	       }
		else
		  { 

		     if((da2=_open("a:empleado.dat",4))==-1)
		       { clrscr();
			 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO 2");
			 getch();exit(1);
		       }
		      while ((aux2=_read(da2,&reg2,sizeof(reg2)))!=0)
		       {
			 if (aux2!=sizeof(reg2))
			  { printf(" ERROR DE LECTURA EN ARCHIVO 2");
			    getch();exit(1);
			  }
		       }
		      reg2.abono_fac=atof(cadena);
		      reg2.num_fac=num;
		      if(ls==2)
		      {
		      if ((aux2=_write(da2,&reg2,sizeof(reg2)))!=(sizeof(reg2)))
			      {
			       printf("ERROR AL INTENTAR GRABAR EN ARCHIVO 2");
			       getch();exit(1);
			      }
		      }
		   }
		   close(da2);
		 close(da1);
	  printf("\nDESEA ADICIONAR OTRO APORTE (S/N): ");
	  continuar=toupper(getch());
	} while(continuar!='N');
   return(0);
 }


//*******************************************************************************


//********************************************************************************************
 crear_archivo_2()
  {
   char control1;
   int aux;

   clrscr();
   control1='S';
    if ((da2=_open("a:empleado.dat",1))!=-1)
       {
       gotoxy(2,5);printf("CUIDADO ESTE ARCHIVO YA EXISTE");
       gotoxy(2,7);printf("DESEA BORRARLO (S/N) ");
       control1=toupper(getch());
       }
    else
      { 
       if ((da2=_creat("a:empleado.dat",0))==-1)
	      { printf(" ERROR AL INTENTAR CREAR ARCHIVO 2");
	       getch();exit(1);
	      }
	    }  

	   if(control1!='N')
	    {
	     if ((da2=_creat("a:empleado.dat",0))==-1)
	      { printf(" ERROR AL INTENTAR CREAR ARCHIVO 2");
	       getch();exit(1);
	      }
	     adicionar_archivo_2();
	    }
    return(0);

  }


//*********************************************************************************




  imprimir_archivo_1()
   {
    int aux;

   clrscr();
     if((da1=_open("a:factura.dat",1))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO 1 ");
	 getch();exit(1);
       }


      while ((aux=_read(da1,&reg1,sizeof(reg1)))!=0)
       { if (aux!=sizeof(reg1))
	  { printf(" ERROR DE LECTURA EN ARCHIVO 1"); 
	    getch();exit(1);
	  }

	  printf("Nro Fac: %ld   Tipo Fac: %c   Iva: %.2f   Valor: %.2f   Descuento: %.2f \n\n",reg1.num_fac,
	  reg1.tipo_fac,reg1.iva_fac,reg1.valor_fac,reg1.descu_fac);
       }

  getch();
  close(da1);
  return(0);
  } 

//*******************************************************************************

 imprimir_archivo_2()
  {
   int aux;
    clrscr();

    if((da2=_open("a:empleado.dat",1))==-1)
      { clrscr();
	printf("ERROR AL INTENTAR LEER EL ARCHIVO  2 ");
	getch();exit(1);
      }
	
	 while ((aux2=_read(da2,&reg2,sizeof(reg2)))!=0)
	   { if (aux2!=sizeof(reg2))
	       { printf(" ERROR DE LECTURA EN ARCHIVO 2");
		 getch();exit(1);
		}
	    printf("Numero De Factura: %ld   Abono:%.2f \n\n",reg2.num_fac,reg2.abono_fac);
	   }
	   getch();
     close(da2);
   return(0);
 }


//******************************************************************************

cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(12);textbackground(0);
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


menu1()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10], " CREAR ARCHIVO CUENTAS ");
  strcpy(opciones[11], " CREAR ARCHIVO APORTES ");
  strcpy(opciones[12], "   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("LUIS xxxxxxx  xxxxxxx  xxxxxx");
  gotoxy(31,21);printf("CODIGO 95xxxxxx");
  gotoxy(35,22);printf("S  2  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,50,9,13);
	textcolor(10);textbackground(1);
	for(f=10;f<=12;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=12)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=12;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:crear_archivo_1() ;break;
		      case    11:crear_archivo_2() ;break;
		     }
	   }while(f !=12);
	return(0);
  }


consulta_archivo_1()
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
	 gotoxy(2,7);printf("DIGITE NUMERO DE LA FACTURA:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
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

	num=atol(cadena);

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
	     gotoxy(16,16);printf("DESEA CONSULTAR MAS (S/N):");
	     segir=toupper(getch());
	     }while(segir=='S');
      return(0);	     
     }
//*****************************************************************************

consulta_archivo_2()
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
	  gotoxy(2,7);printf("DIGITE NUMERO DE FACTURA:");
	  scanf("\n"); gets(cadena);
	  lon = strlen(cadena);
	  for(i=0;i<=lon-1; i++)
	   {
	    if((!(isdigit(cadena[i])))||(lon>5))
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
	 num=atol(cadena);

	if((da2=_open("a:empleado.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(da2,&reg2,sizeof(reg2)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(reg2))
	       {printf("ERROR DE LECTURA");getch();exit(1);
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
	     gotoxy(17,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }

//************************************************************************************


menu2()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10], " CONSULTAR ARCHIVO CUENTAS ");
  strcpy(opciones[11], " CONSULTAR ARCHIVO APORTES ");
  strcpy(opciones[12], "     SALIR O TERMINAR      ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  gotoxy(25,20);printf("LUIS xxxxxxx  xxxxxx   xxxxxx");
  gotoxy(31,21);printf("CODIGO 95xxxxxx");
  gotoxy(35,22);printf("S  2  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,54,9,13);
	textcolor(10);textbackground(1);
	for(f=10;f<=12;f++)
	  {
	  gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=12)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=12;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:consulta_archivo_1();break;
		      case    11:consulta_archivo_2();break;
		     }
	   }while(f !=12);
	return(0);
  }


//************************************************************************************


menu3()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{ 
  clrscr();                                       
  strcpy(opciones[10]," ADICIONAR ARCHIVO CUENTAS ");
  strcpy(opciones[11]," ADICIONAR ARCHIVO APORTES ");
  strcpy(opciones[12],"     SALIR O TERMINAR      ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("LUIS  xxxxxx xxxxxx  xxxxxxxx");
  gotoxy(31,21);printf("CODIGO 95xxxxxx");
  gotoxy(35,22);printf("S  2  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,54,9,13);
	textcolor(10);textbackground(1);
	for(f=10;f<=12;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=12)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=12;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:adicionar_archivo_1() ;break;
		      case    11:adicionar_archivo_2() ;break;
		     }
	   }while(f !=12);
	return(0);
  }


//************************************************************************************
menu4()
{ 
  int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{                        
  clrscr();                 
  strcpy(opciones[11]," IMPRIMIR ARCHIVO CUENTAS ");
  strcpy(opciones[12]," IMPRIMIR ARCHIVO APORTES ");
  strcpy(opciones[13],"   SALIR O TERMINAR       ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("LUIS                         ");
  gotoxy(31,21);printf("CODIGO 95      ");
  gotoxy(35,22);printf("S  2  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,52,10,14);
	textcolor(10);textbackground(1);
	for(f=11;f<=13;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=11;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=13)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=11;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=11)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=13;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    11:imprimir_archivo_1() ;break;
		      case    12:imprimir_archivo_2() ;break;
		     }
	   }while(f !=13);
	return(0);
     }


menu()
{ int tecla;
  int f;
  char opciones[35][75];
  textcolor(10);textbackground(1);

  do{ 
  clrscr();                                        
  strcpy(opciones[10], " CREAR ARCHIVOS    ");
  strcpy(opciones[11], " CONSULTAR DATOS   ");
  strcpy(opciones[12], " ADICIONAR DATOS   ");
  strcpy(opciones[13], " IMPRIMIR INFORME  ");
  strcpy(opciones[14], " TERMINAR O SALIR  ");

  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("LUIS xxxxxx  xxxxx  xxxxxxx  ");
  gotoxy(31,21);printf("CODIGO 95xxxxxx");
  gotoxy(35,22);printf("S  2  A");								
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(20,48,9,15);
	textcolor(10);textbackground(1);
	for(f=10;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   10:menu1() ;break;
		      case   11:menu2() ;break;
		      case   12:menu3() ;break;
		      case   13:menu4() ;break;
		     }
	   }while(f !=14);
	return(0);
  }

//****************************************************************************

//********************************************************************************
  void main()
   { 
    clrscr();
    textcolor(10); textbackground(1);
    menu();
   }

//************************************FINAL*****************************************


