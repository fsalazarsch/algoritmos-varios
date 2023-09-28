/***************************************************************************/
/*                SEGUNDO PARCIAL DE TRANSMISION DE DATOS                  */
/***************************************************************************/



/***************************************************************************/
/* CHAPARRO CARRE¥O NELSON      CODIGO 95131035                            */
/* GIRALDO OSORIO LUIS ALFONSO  CODIGO 95131008                            */
/* FERNANDEZ RAMIREZ IVAN JESUS CODIGO 95131000                            */
/* CASTELLANOS ORDUZ ELSA       CODIGO 95131073                            */
/* S7A     20 DE MAYO  DE 1998                                             */
/***************************************************************************/



/***************************************************************************/
/*                    PROGRAMA QUE TRANSMITE ARHIVOS DE TEXTO              */
/***************************************************************************/



#include<time.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<io.h>
#include<bios.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

char buffer[4096];
#define SETTINGS ( 0x00 | 0x02 | 0x00 | 0x00)
#define COM 0
char nombre[100]="";
void clave_ser();
void DETALLES();
void CUADRO2(int x1, int y1, int x2, int y2);
void SALIR();
void puerto();
void Consulta();
void Consulta()

{
	int recibirarchivo,i,salir;
	char car;
	clock_t tini=clock();
	FILE *d;

	bioscom(0,SETTINGS,COM);		
	i=0;
	salir=0;
	clrscr();
	do
	{     
		bioscom(1,8,COM);
		if((clock()-tini)>40)
		{
			printf("\nError en la transmision");
			salir=1;
			break;
		}
	}while((bioscom(2,0,COM) & 0x7F)!=8);
	if(!salir)
	{  
		if ((bioscom(2,0,COM) & 0x7F)=='#')
		cprintf("NOMBRE: ");scanf("\n%s",nombre);
		bioscom(1,'*',COM);
		while(nombre[i]!=0)bioscom(1,nombre[i++],COM);
		bioscom(1,'$',COM);
		d=fopen(nombre,"wt");
	}
	recibirarchivo=0;
	do
	{
		car=bioscom(2,0,COM) & 0x7F;
		putchar(car);
		if(recibirarchivo)
		{
			fwrite(&car,1,1,d);    
		}
		switch(car)
		{	
			case '*':recibirarchivo=1;
						break;
			
			case '!':salir=1;
						fclose(d);
						break;
			
			case '?':salir=1;
						printf("\n Error");
									break;
		}
	}while(!salir && !kbhit());		
	getch();
}
void clave_ser()
{
 char con[10];
 int j,i,c,r,a;
 clrscr();
 r=0;a=28;
 c=3;
 for (i=0;i<11;i++)
 { con[i]='\0';
 }
  while (c>0 && r==0)
  {clrscr();
   for(j=8;j<=13;j++)
     {gotoxy(50,j);textcolor(12);cprintf("©");
      gotoxy(18,j);cprintf("©");}
   for(i=18;i<=50;i++)
     {gotoxy(i,13);cprintf("©");
      gotoxy(i,8);cprintf("©");}
   
   gotoxy (24,10);textcolor(3);cprintf("DIGITE LA CONTRASE¥A\n");
   for (i=0;i<8;i++)
    { con[i]=getch();
      gotoxy(a,11); printf("*");
      a++;
      
    } 
   con[i+1]='\0';
	if(strcmp(con,"clientes")==0)
	  {clrscr();
      r=1;
      gotoxy(12,10);printf("CLAVE FUNCIONA");
      gotoxy(10,5);printf("BIENVENIDOS A NUESTRO SERVICIO");
      getch();
		Consulta();
     }
    else
     {clrscr();a=a-7;
      gotoxy(10,5);printf("CLAVE NO VALIDA");
      if(c!=1)
       {gotoxy(10,10);printf("INTENTA DE NUEVO");}
      c--;
      if (c==1)
       {gotoxy(10,10);printf("ULTIMA OPORTUNIDAD...");
       }
     }
   getch();
  }
}




void main()
{ 

 char con[10];
 int j,i,c,r,a;
 clrscr();
 r=0;a=28;
 c=3;
 for (i=0;i<11;i++)
 { con[i]='\0';
 }
  while (c>0 && r==0)
  {clrscr();
   for(j=8;j<=13;j++)
     {gotoxy(50,j);textcolor(12);cprintf("©");
      gotoxy(18,j);cprintf("©");}
   for(i=18;i<=50;i++)
     {gotoxy(i,13);cprintf("©");
      gotoxy(i,8);cprintf("©");}
   
   gotoxy (24,10);textcolor(3);cprintf("DIGITE LA CONTRASE¥A\n");
   for (i=0;i<8;i++)
    { con[i]=getch();
      gotoxy(a,11); printf("*");
      a++;
      
    } 
   con[i+1]='\0';
   if(strcmp(con,"servidor")==0)
     {clrscr();
      r=1;
      gotoxy(12,10);printf("CLAVE FUNCIONA");
      gotoxy(10,5);printf("BIENVENIDOS A NUESTRO SERVICIO");
      getch();
      puerto();
     }
    else
     {clrscr();a=a-7;
      gotoxy(10,5);printf("CLAVE NO VALIDA");
      if(c!=1)
       {gotoxy(10,10);printf("INTENTA DE NUEVO");}
      c--;
      if (c==1)
       {gotoxy(10,10);printf("ULTIMA OPORTUNIDAD...");
       }
     }
   getch();
  }
}

void puerto()
{char menu [9][40];
  char tecla;
  int i;
  int k;
  int activa;
  strcpy(menu[1], "   DETALLES   ");
  strcpy(menu[2], "   CONSULTAR  ");
  strcpy(menu[3], "   TERMINAR   ");
  activa=1;
  do
     {
       textbackground(1);
       clrscr();
       textcolor(4);
       for (k=6; k<25; k++)
	  for (i=2; i<79; i++)
	     {
	       gotoxy(i,k);
	       cprintf("Û");
	     }
       textcolor(7);
       CUADRO2(2,1,79,25);
       CUADRO2(2,1,79,3);
       CUADRO2(2,3,79,5);
       CUADRO2(18,11,66,20);
       CUADRO2(14,9,70,22);
       textcolor(YELLOW);
       CUADRO2(12,8,72,23);
       gotoxy(9,2);
       textcolor(YELLOW);
		 cprintf("P R O G R A M A    D E    T R A N S M I S I O N   D E   D A T O S");
       gotoxy(19,12);
		 cprintf("NELSON CHAPARRO CARRE¥O         CODIGO 95131035");
		 gotoxy(19,13);
		 cprintf("LUIS  ALFONSO  GIRALDO  OSORIO  CODIGO 95131008");
		 gotoxy(19,14);
		 cprintf("IVAN JESUS FERNANDEZ RAMIREZ    CODIGO 95131000");
		 gotoxy(19,15);
		 cprintf("ELSA CASTELLANOS ORDUZ          CODIGO 95131073");
		 gotoxy(19,16);
		 cprintf("    CORPORACION UNIVERSITARIA DE SANTANDER     ");
		 gotoxy(19,17);
		 cprintf("      FACULTAD DE INGENIERIA DE SISTEMAS       ");
		 gotoxy(19,18);
		 cprintf("              VII SEMESTRE  S7A                ");
		 gotoxy(19,19);
		 cprintf("                  1 9 9  8                     ");
       textcolor(14);
		 for (i=1;i<=3;i++)
	{
	  gotoxy((i-1)*15+20,4);
	  cprintf(menu[i]);
	}
       i=activa;
       textcolor(0);
       textbackground(4);
		 gotoxy((i-1)*15+20,4);
		 cprintf("%s",menu[i]);
		 do
	 {
	   do
	     {
	      tecla=getch();
	      if (tecla==0)
		 tecla=getch();
	     }
	   while(!((tecla==77) || (tecla==75) || (tecla==13)));
	   if (tecla==77)
	     {
		textcolor(14);
		textbackground(1);
		gotoxy((i-1)*15+20,4);
		cprintf("%s",menu[i]);
		if (i<3)
		  i++;
		else
		  i=1;
		textcolor(0);
		textbackground(4);
		gotoxy((i-1)*15+20,4);
		cprintf("%s",menu[i]);
		textcolor(11);
		textbackground(1);
	     }
	   if (tecla==75)
	     {
		textcolor(14);
		textbackground(1);
		gotoxy((i-1)*15+20,4);
		cprintf("%s",menu[i]);
		if (i!=1)
		   i--;
		else
			i=3;
		textcolor(0);
		textbackground(4);
		gotoxy((i-1)*15+20,4);
		cprintf("%s",menu[i]);
		textcolor(11);
		textbackground(1);
	     }
	 }
       while (tecla!=13);
       gettext(1,1,80,25,buffer);
       switch (i)
	{
	  case  1: textbackground(1);
			DETALLES();
			break;
	  case  2: textbackground(1);
			clave_ser();
			break;
	  case  3: textbackground(1);
		   SALIR();
		   break;
	}
	puttext(1,1,80,25,buffer);
	activa=i;
      }
		while (i!=3);
      textbackground(0);
      clrscr();
      
}       
void CUADRO2(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1);
    cprintf("ß");
    gotoxy(i,y2);
    cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i);
    cprintf("Û");
    gotoxy(x2,i);
    cprintf("Û");
  }
}

void DETALLES()
{
  int i,k;
  clrscr();
  CUADRO2(1,1,80,24);
  textcolor(4);
  CUADRO2(2,2,79,23);
  textcolor(YELLOW);
  gotoxy(35,2);
  cprintf("D E T A L L E S");
  textcolor(15);
  gotoxy(17, 3);
  cprintf("LA CAMUNICACIà EN SERIE ES CUANDO LOS BITS   DE");
  gotoxy(17, 4);
  cprintf("COMUNICACION SE ENVIAN UNO DETRAS DE OTRO HASTA");
  gotoxy(17, 5);
  cprintf("COMPLETAR CADA CARACTER........................");
  gotoxy(17, 6);
  cprintf("UN FACTOR IMPORTANTE ES LA VELOCIIDAD A LA  QUE");
  gotoxy(17, 7);
  cprintf("SE ESTABLECE LA COMUNICACION.SE MIDE EN BAUDIOS");
  gotoxy(17, 8);
  cprintf("QUE ES LA FRECUENCIA DE IMPULSOS ELECTRICOS QUE");
  gotoxy(17, 9);
  cprintf("VIAJAN POR LA LINEA. PARA ESTA COMUNICACION NOS");
  gotoxy(17,10);
  cprintf("VALEMOS DE LA INTERFAZ RS232C QUE POSEE 25 CON-");
  gotoxy(17,11);
  cprintf("DUCTORES ESPIGAS  A  TRAVES  DEL CUAL PASAN LAS");
  gotoxy(17,12);
  cprintf("SE¥ALES DE CONTROL Y DE DATOS ENTRE LA TERMINAL");
  gotoxy(17,13);
  cprintf("Y EL MODEM                                     ");
  gotoxy(17,14);
  cprintf("ESTE PROGRAMA COMUNICA TRES (3)  COMPUTADORES Y");
  gotoxy(17,15);
  cprintf("TRANSMITE  ARCHIVOS  DE TEXTO  EXISTENTES EN EL");
  gotoxy(17,16);
  cprintf("SERVIDOR A  LA  TERMINAL  QUE LO ACCESE PRIMERO");
  gotoxy(17,17);
  cprintf("EL CONCEPTO DE PRIORIDAD QUE SE MANEJA EN  ESTA");
  gotoxy(17,18);
  cprintf("APLICACION  VA  DE  ACUERDO CON LA TERMINAL QUE");
  gotoxy(17,19);
  cprintf("ACCESE PRIMERO AL SERVIDOR  Y  EL OTRO TERMINAL");
  gotoxy(17,20);
  cprintf("QUEDARµ EN LINEA DE ESPERA.....................");
  gotoxy(17,22);
  textcolor(GREEN);
  cprintf("TRANSMISION DE DATOS,      Ing. ELDER RIVERO!!!");
  getch();
}


void SALIR()
{ exit(1);

}