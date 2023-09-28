#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<io.h>
#include<fcntl.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<time.h>
#define color(x,y)textcolor(x);textbackground(y)
  

  struct
{  char CODIG[9];
   char MAR_BUS[40];               
   char NOMB[40];
   char SEX;              
   char INGRES[3];
}
  DATOS ;
  
struct 
{
  unsigned char  ti_min;
  unsigned char  ti_hour;
  unsigned char  ti_hund;
  unsigned char  ti_sec;
}
  t;
 
int DES_ARC;
char PAREC[15];
char aux[20][80],aux2[20][80],aux3[20][80];
int sw,N,X,X1,Y,i,I,j;
char op;
void menu();
void menu2();
void menu3();
void CREAR2();
void CREAR();
void MODIFICAR2();
void CONSULTAR_COD2();
void ELIMINAR_DAT2();
void MODIFICAR();
void CONSULTAR_COD();
void ELIMINAR_DAT();

void sirena();
void clave();

void cuadro(int col1, int lin1, int col2, int lin2)
{
  int k;
  for(k=col1+1;k<=col2-1;k++)
  {
    gotoxy(k,lin1); cprintf("Ä");
    gotoxy(k,lin2); cprintf("Ä");
  }

  for(k=lin1+1;k<=lin2-1;k++)
  {
    gotoxy(col1,k); cprintf("³");
    gotoxy(col2,k); cprintf("³");
  }
 gotoxy(col1,lin1); cprintf("Ú");
 gotoxy(col1,lin2); cprintf("À");
 gotoxy(col2,lin1); cprintf("¿");
 gotoxy(col2,lin2); cprintf("Ù");
}
 void tiempo(int x,int y)
{    time_t t;
      time(&t);gotoxy(x,y);
      cprintf("%s",ctime(&t));

}


void linea(int n1,int n2,int n3)
{     int i;
      for(i=n1+1;i<=n2-1;i++){gotoxy(i,n3);putchar(205);}
      gotoxy(n2,n3);putchar('¹');
      gotoxy(n1,n3);putchar('Ì');
}
void pantalla(x1,x2,y1,y2)
int x1,y1,x2,y2;
{
     int i,j;
     cuadro(1,80,2,24);
     for(i=3;i<=78;i++)
	 for(j=3;j<=22;j++)
	 if((i<x1 || i>x2) || (j<y1 || j>y2))
	      {gotoxy(i,j);putchar('°');}

}

void menu()
{
  char informe[25][50];
  char flecha;
  int  p;

  textbackground(0);
  clrscr();
  strcpy(informe[7], "              MENU PRINCIPAL            ");
  strcpy(informe[9], "               CONDUCTORES              ");
  strcpy(informe[10],"                  BUSES                 ");
  strcpy(informe[11],"                  SALIR                 ");

  do
     {
       textbackground(0);
       clrscr();
       cuadro(1,1,80,24);
       cuadro(2,2,79,23);
       cuadro(20,6,61,13);
       textcolor(2); textbackground(0);
       for (p=9;p<=11;p++)
	{
	  gotoxy(21,p); cprintf(informe[p]);
	}
       p=9;
       textcolor(4);
       textbackground(0);
       gotoxy(21,7);
       cprintf("%s",informe[7]);
       textcolor(14);
       textbackground(0);
       gotoxy(21,p);
       cprintf("%s",informe[p]);
       do
	 {
	   flecha=getch();

	   if (flecha==80)
	     {
		textcolor(2);
		textbackground(0);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p<11)
		  p++;
		else
		  p=9;
		textcolor(14);    textbackground(0);
		gotoxy(21,p);     cprintf("%s",informe[p]);
	     }
	   if (flecha==72)
	     {
		textcolor(2);
		textbackground(0);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p!=9)
		   p--;
		else
		   p=11;
		textcolor(14);
		textbackground(0);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
	     }
	 }
       while (flecha!=13);

       switch (p)
	{
	  case  9: menu2(); break;
	  case  10:menu3(); break;



	}
      }
  while (p!=11);
}

void menu2()
{
  char informe[25][50];
  char flecha;
  int  p;

  textbackground(0);
  clrscr();
  strcpy(informe[7], "             MENU CONDUCTORES           ");
  strcpy(informe[8], "                                        ");
  strcpy(informe[9], "                ADICIONAR               ");
  strcpy(informe[10],"                CONSULTAR               ");
  strcpy(informe[11],"                ELIMINAR                ");
  strcpy(informe[12],"                 SALIR..                ");

  do
     {
       textbackground(0);
       clrscr();
       cuadro(1,1,80,24);
       cuadro(2,2,79,23);
       cuadro(20,6,61,13);
       textcolor(2); textbackground(0);
       for (p=9;p<=12;p++)
	{
	  gotoxy(21,p); cprintf(informe[p]);
	}
       p=9;
       textcolor(4);
       textbackground(1);
       gotoxy(21,7);
       cprintf("%s",informe[7]);
       textcolor(14);
       textbackground(1);
       gotoxy(21,p);
       cprintf("%s",informe[p]);
       do
	 {
	   flecha=getch();

	   if (flecha==80)
	     {
		textcolor(2);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p<12)
		  p++;
		else
		  p=9;
		textcolor(14);    textbackground(1);
		gotoxy(21,p);     cprintf("%s",informe[p]);
	     }
	   if (flecha==72)
	     {
		textcolor(2);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p!=9)
		   p--;
		else
		   p=12;
		textcolor(14);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
	     }
	 }
       while (flecha!=13);

       switch (p)
	{

	  case  9: CREAR(); break;
	  case 10: /*CONSULTAR_COD();*/break;
	  case 11:/* ELIMINAR_DAT();*/break;

	}
      }
  while (p!=12);
}
/******************************************************************/
void CREAR()
{
   int da;


    clrscr();
     if((da=_creat("C:\\conductores.dat",0))==-1)
       {   gotoxy(20,12);printf("...NO PUDO CREAR EL ARCHIVO...");
	 textmode(4);
	 textcolor(17);gotoxy(25,10);printf("....ERROR AL INTENTAR CREAR EL ARCHIVO....");
	 getch();exit(1);
       }
    else
	 if((da=_open("C:\\conductores.dat",4))==-1)
	 {
	  textcolor(17);gotoxy(23,9);printf("...YA EXISTE EL ARCHIVO...");exit(1);
	 }
	 else
	 {
	      color(14,1);
	      clrscr();cuadro(2,2,78,2);
	      gotoxy(23,10);printf("NUMERO DE CONDUCTORES A INGRESAR : ");scanf("%d",&X);

	      if (X>20)
		 {
		  gotoxy(23,14);printf("SOBRE PASA EL RANGO DESIGNADO A INGRESAR");
		  gotoxy(23,19);printf(" PULSE ENTER PARA REGRESAR ");
		      getch();
		 }
	      else
		 {

		      gotoxy(3,2);printf("INFORMACION DE DATOS PERSONALES DE LOS CONDUCTORES\n\n");
		      for(i=1;i<=X;i++)
			 {   clrscr();
			     cuadro(2,2,78,22);

			   gotoxy(20,9);printf( " CODIGO DEL CONDUCTOR   : ");scanf("\n");gets(DATOS.CODIG);

			   gotoxy(20,12);printf("NOMBRE DEL CONDUCTOR    : ");scanf("\n");gets(DATOS.NOMB);
			     _write(da,&DATOS,sizeof(DATOS));getch();

			}

		       _close(da);

	       }

	 }

}

void menu3()
{
  char informe[25][50];
  char flecha;
  int  p;

  textbackground(0);
  clrscr();
  strcpy(informe[7], "               MENU BUSES               ");
  strcpy(informe[8], "               ADICIONAR                ");
  strcpy(informe[9], "               CONSULTAR                ");
  strcpy(informe[10],"             MODIFICAR BUS              ");
  strcpy(informe[11],"               ELIMINAR                 ");
  strcpy(informe[12],"                SALIR..                 ");

  do
     {
       textbackground(0);
       clrscr();
       cuadro(1,1,80,24);
       cuadro(2,2,79,23);
       cuadro(20,6,61,13);
       textcolor(2); textbackground(1);
       for (p=8;p<=12;p++)
	{
	  gotoxy(21,p); cprintf(informe[p]);
	}
       p=8;
       textcolor(4);
       textbackground(1);
       gotoxy(21,7);
       cprintf("%s",informe[7]);
       textcolor(14);
       textbackground(1);
       gotoxy(21,p);
       cprintf("%s",informe[p]);
       do
	 {
	   flecha=getch();

	   if (flecha==80)
	     {
		textcolor(2);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p<12)
		  p++;
		else
		  p=8;
		textcolor(14);    textbackground(1);
		gotoxy(21,p);     cprintf("%s",informe[p]);
	     }
	   if (flecha==72)
	     {
		textcolor(2);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
		if (p!=8)
		   p--;
		else
		   p=12;
		textcolor(14);
		textbackground(1);
		gotoxy(21,p);
		cprintf("%s",informe[p]);
	     }
	 }
       while (flecha!=13);

       switch (p)
	{
	  case  8: CREAR2(); break;
	  case  9: CONSULTAR_COD2(); break;
	  case 10: MODIFICAR2();break;
	  case 11: ELIMINAR_DAT2();break;

	}
      }
  while (p!=12);
}

/***********************************************************************/
void CREAR2()
{
   int d1a;


    clrscr();
     if((d1a=_creat("C:\\conductores.dat",0))==-1)
       {   gotoxy(20,12);printf("...NO PUDO CREAR EL ARCHIVO...");
	 textmode(4);
	 textcolor(17);gotoxy(25,10);printf("....ERROR AL INTENTAR CREAR EL ARCHIVO....");
	 getch();exit(1);
       }
    else
	 if((d1a=_open("C:\\conductores.dat",4))==-1)
	 {
	  textcolor(17);gotoxy(23,9);printf("...YA EXISTE EL ARCHIVO...");exit(1);
	 }
	 else
	 {
	      color(14,1);
	      clrscr();cuadro(2,2,78,2);
	      gotoxy(23,10);printf("NUMERO DE CONDUCTORES A INGRESAR : ");scanf("%d",&X1);

	      if (X1>20)
		 {
		  gotoxy(23,14);printf("SOBRE PASA EL RANGO DESIGNADO A INGRESAR");
		  gotoxy(23,19);printf(" PULSE ENTER PARA REGRESAR ");
		      getch();
		 }
	      else
		 {

		      gotoxy(3,2);printf("INFORMACION DE DATOS PERSONALES DE LOS CONDUCTORES\n\n");
		      for(i=1;i<=X1;i++)
			 {   clrscr();
			     cuadro(2,2,78,22);
			   gotoxy(20,8);printf(" CODIGO DEL BUS          : ");scanf("\n");gets(DATOS.NOMB);
			   gotoxy(20,9);printf( " MARCA DEL BUS          : ");scanf("\n");gets(DATOS.MAR_BUS);
			   gotoxy(20,10);printf("NUMERO DE PUESTOS       : ");scanf("\n");gets(DATOS.INGRES);
			   gotoxy(20,12);printf("CODIGO DEL CONDUCTOR    : ");scanf("\n");gets(DATOS.CODIG);
			     _write(d1a,&DATOS,sizeof(DATOS));getch();

			}

		       _close(d1a);

	       }

	 }

}

void MODIFICAR2()
{
 int cont,b,sw;
 char res,st;
 char LLAVE[15];
 color(14,1);

do{ sw=0;clrscr();
  cuadro(2,2,78,22);
   gotoxy(22,2);printf(" M O D I F I C A R   R E G I S T R O ");

 if((DES_ARC=_open("C:\\conductores.dat",4))==-1)
 {
 gotoxy(20,20);printf("ERROR DE APERTURA DEL ARCHIVO");
 getch();exit(1);
 }
   gotoxy(20,5);printf(" CODIGO  A  MODIFICAR : ");scanf ("\n");gets(LLAVE);
    cont=0;st='N';
    while ((b=_read(DES_ARC,&DATOS,sizeof(DATOS)))!=0)
 {
    if(b!=sizeof(DATOS))
    { gotoxy(20,20);printf(" ERROR DE LECTURA");
     getch();exit(1);
    }

       cont++;
       if (strcmp(DATOS.CODIG,LLAVE)==0 && sw<=1)
	{sw++;

	  cuadro(1,79,4,20);
	  gotoxy(20,7);printf("NUEVO CODIGO                : ");scanf("\n");gets(DATOS.CODIG);
	  gotoxy(20,8);printf("MAR_BUSIDO DEL EMPLEADO       : ");scanf("\n");gets(DATOS.MAR_BUS);
	  gotoxy(20,9);printf("NOMBRE DEL EMPLEADO         : ");scanf("\n");gets(DATOS.NOMB);

	 gotoxy(20,11);printf("INGRESOS DEL CONDUCTOR       : ");scanf("%f",&DATOS.INGRES);
	  lseek(DES_ARC,((long)(cont-1)*(sizeof(DATOS))),0);
	  st='S';
	  if((_write(DES_ARC,&DATOS,sizeof(DATOS)))==-1)
	    {
	      gotoxy(20,20);printf("ERROR DE ESCRITURA");getch();exit(1);
	    }
	 }
	 if(sw==0)
	 {
	  gotoxy(25,20);printf("NO EXISTE EL CODIGO");
	  }
	}
	close(DES_ARC);
	if(st=='N')
	  {
	  gotoxy(25,21);printf("DESEA MODIFICAR OTRO REGISTRO S/N ");
	  }

	    res=toupper(getch());

	}
	 while(res=='S');
}

void CONSULTAR_COD2()
{
 char res1,st1,LLAVE1[9];
    int x1,sw1;
  color(14,1);

  do{sw1=0; clrscr(); cuadro(2,2,78,22);
       gotoxy(22,2);printf(" C O N S U L T A    R E G I S T R O ");

      gotoxy(24,9);printf(" CODIGO  A  CONSULTAR : ");scanf("\n");gets(LLAVE1);

      if((DES_ARC=_open("C:\\conductores.dat",1))==-1)
	 { gotoxy(25,17);printf("....ERROR DE APERTURA....");
	   getch();exit(1);
	 }
      st1='N';
      while(((x1=_read(DES_ARC,&DATOS,sizeof(DATOS)))!=0))
	   {
	      if(x1!=sizeof(DATOS))
		{
		  gotoxy(25,11);printf("....ERROR DE LECTURA....");
		     getch();exit(1);
		}
	       if(strcmp(DATOS.CODIG,LLAVE1)==0 && sw1<=1)
		     {sw1++;

			{
			   gotoxy(20,8);printf(" CODIGO DEL BUS               : %s\n",DATOS.NOMB);
			   gotoxy(20,9);printf( " MARCA DEL BUS               : %s\n",DATOS.MAR_BUS);
			   gotoxy(20,10);printf(" NUMERO DE PUESTOS           : %s\n",DATOS.INGRES);

			   gotoxy(20,15);printf(" CODIGO DEL CONDUCTOR        : %s\n",DATOS.CODIG);

			 getch();
		      }

		   }
		   if(sw1==0)
		    {
		    gotoxy(25,20);printf("NO EXISTE EL CODIGO");
		    }

	 }	   _close(DES_ARC);
		       if(st1=='N')
			{
			 gotoxy(25,21);printf("DESEA CONSULTAR MAS S/N ");

			}

		       res1=toupper(getch());

	 }      while(res1!='N');

}
/*************************************************************************/

void ELIMINAR_DAT2()
{ char  res1,st1,LLAVE1[9];
  int daux1,sw1,b1;
  char encon1;

  do{sw1=0;  clrscr();
       cuadro(2,2,78,22);
       gotoxy(22,2);printf(" B O R R A R   R E G I S T R O ");
       gotoxy(25,10);cprintf(" CODIGO  A  BORRAR : ");scanf("\n");gets(LLAVE1);

       if((daux1=_creat("C:\\AUXILIAR.DAT",0))==-1)
	       {gotoxy(25,11);printf("ERROR AL CREAR ARCHIVO AUXILIAR.DAT");
		getch();exit(1);
	       }
       if((DES_ARC=_open("C:\\conductor.dat",1))==-1)
	       { gotoxy(25,11);printf("ERROR DE APERTURA DEL ARCHIVO CONDUCTOR.DAT");
		 getch();exit(1);
	       }
	    if((daux1=_open("C:\\AUXILIAR.DAT",2))==-1)
	       {gotoxy(25,11);printf("ERROR DE APERTURA");getch();exit(1);}
		  st1='N';
		 while( (b1=_read(DES_ARC,&DATOS,sizeof(DATOS)))!=0)
		  {
		    if(b1!=sizeof(DATOS))
		      { gotoxy(25,13);printf("ERROR DE LECTURA");
		       getch();exit(1);
		      }
		   if(strcmp(DATOS.CODIG,LLAVE1)==0 && sw<=1)
		    {sw1++;

		      strcpy(DATOS.NOMB,"aux.nomb");
		      strcpy(DATOS.MAR_BUS,"aux.mar_bus");
		      strcpy(DATOS.INGRES,"aux.ingres");
		      strcpy("DATOS.CODIG","aux.codig");
		     if(_write(daux1,&aux,sizeof(aux))!=sizeof(aux))
		     {{gotoxy(25,11);printf("ERROR DE ESCRITURA");getch();exit(1);}}

		   }
		   if(sw1==0)
		     {
		      gotoxy(25,20);printf("NO EXISTE EL CODIGO");
		      }
		    _close(daux1);
		}   _close(DES_ARC);

	       if(st1=='N')
		{
		  gotoxy(25,21);printf("DESEA BORRA OTRO REGISTRO S/N ");
		}
		unlink("C:\\conductor.dat");
		rename("C:\\AUXILIAR.DAT","C:\\conductor.dat");

	       res1=toupper(getch());



	 } while(res1=='S');
	 if(res1=='S')
	 { for(i=1;i<=X1;i++)
	    {X1--;}
	 }
}
/**************************************************************************/


int lee_clave()
{     char tecla,cad[10];
      int  k=0,sw=0;
      do{   k++;
	  tecla=tolower(getch());putchar('*');
	  if(k==1 && tecla=='b')sw++;
	  if(k==2 && tecla=='e')sw++;
	  if(k==3 && tecla=='a')sw++;
	  if(k==4 && tecla=='t')sw++;
	  if(k==5 && tecla=='r')sw++;
	  if(k==6 && tecla=='i')sw++;
	  if(k==7 && tecla=='z')sw++;
      }while(k<=7 && sw<=6);
      return(sw);
}
void sirena()
{
   int I,J;

   for(I=1;I<=5;I++)
   {   delay(500);
       if(I%2==0)
	 {sound(100);gotoxy(28,10);printf(" !  CLAVE CORRECTA  ­ ");}
	else
	 {  clrscr();
	   sound(423);
	   for(J=1;J<=8;J++)
	     {delay(200);
	       if(J%2==0) sound(423);
	       else
		sound(100);
   }	     }
   }nosound();
}
void main()
{  int cont;
  _setcursortype(_NOCURSOR);
  textbackground(1);
  textcolor(15);
  clrscr();

  // cont=0;

/* do{  cont++;
       clrscr();
       textcolor(6);
       cuadro(2,2,79,23);
       pantalla(23,62,10,14);
       tiempo(30,20);
       gotoxy(25,12);printf("DIGITE CLAVE DE ACCESO : [         ]");
       gotoxy(52,12);

       if(lee_clave()==7)
	   {
	     sirena(); */
	     menu();
	     //cont=7;
	  // }
       /*else{
	     gotoxy(24,12);printf(" ACCESO DENEGADO  :  CLAVE INCORRECTA ");
	      delay(1500);
	  }
  }while(cont<3); */

 clrscr();
}
