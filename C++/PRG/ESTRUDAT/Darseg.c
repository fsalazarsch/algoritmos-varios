#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


 struct
  {
   char nombre[20];
   long  cedula;
   char apellido[20];
   int sexo;
   float sueldo;
  }empresa[300];

  void cuadro(int i,int j);
  void listado_general();
  void ordenar();
  int con=0,sw,j,i,lon;
  char nombre[20],apellido[20];;
  long cedula; float sueldo;
  int sexo;
/***************************************************************************/

void agregar()
 {
  char op,suel[10],sex[2];
  char valido,ced[20];
  long auxced; int st;
   do
    {
     clrscr();
    cuadro(80,23);
  do
     {
      clrscr();
      cuadro(80,23);
      valido='n';
      gotoxy(25,5);printf("DIGITE CEDULA:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	  {
	    valido='m';
	    break;
	  }
	}
    auxced=atol(ced);
    for (i=0;i<con;i++)
     {
     if(empresa[i].cedula==auxced)
       {
	gotoxy(15,10);
	printf("ESTA CEDULA YA EXISTE");
	valido='m';
	sw=2;
	getch();
       }
     }
     if(sw==1)
     {
      valido='m';
     }
    }while(valido=='m');
    empresa[i].cedula=auxced;
      do
       {
	valido='n';
	gotoxy(39,6);
	printf("               ");
	gotoxy(25,6);printf("DIGITE NOMBRE:");
	scanf("\n"); gets(empresa[con].nombre);
	lon = strlen(empresa[con].nombre);
	for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(empresa[con].nombre[i])))
	    {
	     valido='m';
	     break;
	    }
	  }
       }while(valido=='m');

    do
      {
       valido='n';
       gotoxy(41,7);
       printf("             ");
       gotoxy(25,7);printf("DIGITE APELLIDO:");
       scanf("\n"); gets(empresa[con].apellido);
       lon = strlen(empresa[con].apellido);
       for(i=0;i<=lon-1; i++)
	{
	 if(!(isalpha(empresa[con].apellido[i])))
	  {
	    valido='m';
	     break;
	   }
	}
       }while(valido=='m');

     gotoxy(25,8);printf("DIGITE SUELDO  :");scanf("\n");gets(suel);
    empresa[con].sueldo=atof(suel);
    while (empresa[con].sueldo==0)
     {
     gotoxy(25,8);
     clreol();
     gotoxy(25,8);
     printf("DIGITE SUELDO:");scanf("\n");gets(suel);
     empresa[con].sueldo=atof(suel);
     }
    gotoxy(25,9);printf("DIGITE SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
    empresa[con].sexo=atoi(sex);
    while ((empresa[con].sexo!=1)&&(empresa[con].sexo!=2))
    {
     gotoxy(25,9);
     clreol();
     gotoxy(25,9);
     printf("DIGITE SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
     empresa[con].sexo=atoi(sex);
    }
   con++;
   gotoxy(25,12);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
 }while(op!='N');
}

/*****************************************************************************/

void consultar()
 {
  char op,ced[20],valido;
  long aux;
  do
   {
    clrscr();
    cuadro(80,23);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("             ");
      gotoxy(25,5);printf("DIGITE CEDULA:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	  {
	    valido='m';
	    break;
	  }
	}
     }while(valido=='m');
    aux=atol(ced);
    for (i=0;i<con;i++)
     {
     if(empresa[i].cedula==aux)
       {
	gotoxy(25,10);printf("EL NOMBRE ES  :%s",empresa[i].nombre);
	gotoxy(25,11);printf("EL APELLIDO ES:%s",empresa[i].apellido);
	gotoxy(25,12);printf("LA CEDULA ES  :%ld",empresa[i].cedula);
	gotoxy(25,13);printf("EL SEXO ES    :%d",empresa[i].sexo);
	gotoxy(25,14);printf("EL SUELDO ES  :%.2f",empresa[i].sueldo);
	sw=2;
       }
     }
    if(sw==1)
     {
      gotoxy(20,12);printf("< NO EXISTE ESTA CEDULA >");
     }
    gotoxy(25,20);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
    op=toupper(getch());
  }while(op!='N');
}
/**************************************************************************/
void ordenar_nombre()
  {

   for(j=0;j<=con-1;j++)
    {
     for(i=0;i<con-1;i++)
      {
	if(strcmp(empresa[i].nombre,empresa[i+1].nombre)>0)
	 {
	  strcpy(nombre,empresa[i].nombre);
	  strcpy(apellido,empresa[i].apellido);
	  cedula=empresa[i].cedula;
	  sexo=empresa[i].sexo;
	  sueldo=empresa[i].sueldo;

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  empresa[i].cedula=empresa[i+1].cedula;
	  empresa[i].sueldo=empresa[i+1].sueldo;
	  empresa[i].sexo=empresa[i+1].sexo;

	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  empresa[i+1].cedula=cedula;
	  empresa[i+1].sueldo=sueldo;
	  empresa[i+1].sexo=sexo;
	}
       }
     }
    listado_general();
 }
/**************************************************************************/
void ordenar_apellido()
  {
    int i,j;
    char nombre[20],apellido[20];
    long cedula;
    for(j=0;j<=con-1;j++)
     {
     for(i=0;i<con-1;i++)
       {
	if(strcmp(empresa[i].apellido,empresa[i+1].apellido)>0)
	 {
	  strcpy(nombre,empresa[i].nombre);
	  strcpy(apellido,empresa[i].apellido);
	  cedula=empresa[i].cedula;
	  sexo=empresa[i].sexo;
	  sueldo=empresa[i].sueldo;

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  empresa[i].cedula=empresa[i+1].cedula;
	  empresa[i].sueldo=empresa[i+1].sueldo;
	  empresa[i].sexo=empresa[i+1].sexo;

	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  empresa[i+1].cedula=cedula;
	  empresa[i+1].sueldo=sueldo;
	  empresa[i+1].sexo=sexo;
	 }
	}
       }
     listado_general();
 }

/**************************************************************************/
void ordenar_cedula()
  {
    for(j=0; j<=con-1; j++)
    {
    for(i=0;i<con-1;i++)
     {
	if(empresa[i].cedula>empresa[i+1].cedula)
	 {
	  strcpy(nombre,empresa[i].nombre);
	  strcpy(apellido,empresa[i].apellido);
	  cedula=empresa[i].cedula;
	  sexo=empresa[i].sexo;
	  sueldo=empresa[i].sueldo;

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  empresa[i].cedula=empresa[i+1].cedula;
	  empresa[i].sueldo=empresa[i+1].sueldo;
	  empresa[i].sexo=empresa[i+1].sexo;

	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  empresa[i+1].cedula=cedula;
	  empresa[i+1].sueldo=sueldo;
	  empresa[i+1].sexo=sexo;
	 }
     }
    }
   listado_general();
 }

/**************************************************************************/
void modificar()
 {
  char ced[20],op,valido;
  char suel[10],sex[2];
  long aux;
  do
   {
    clrscr();
    cuadro(80,23);
    sw=1;
    do
     {
      valido='n';
      gotoxy(34,4);
      printf("             ");
      gotoxy(20,4);printf("DIGITE CEDULA:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	   {
	     valido='m';
	     break;
	   }
	}
     }while(valido=='m');
     aux=atol(ced);
    for(i=0;i<con;i++)
    {
    if(empresa[i].cedula==aux)
      {
       do
	{
	  valido='n';
	  gotoxy(40,6);
	  printf("               ");
	  gotoxy(20,6);printf("DIGITE NUEVO NOMBRE:");
	  scanf("\n"); gets(empresa[i].nombre);
	  lon = strlen(empresa[i].nombre);
	  for(j=0;j<=lon-1; j++)
	   {
	    if(!(isalpha(empresa[i].nombre[j])))
	     {
	      valido='m';
	      break;
	     }
	    }
	 }while(valido=='m');
      do
       {
	valido='n';
	gotoxy(42,7);
	printf("             ");
	gotoxy(20,7);printf("DIGITE NUEVO APELLIDO:");
	scanf("\n"); gets(empresa[i].apellido);
	lon = strlen(empresa[i].apellido);
	for(j=0;j<=lon-1; j++)
	  {
	   if(!(isalpha(empresa[i].apellido[j])))
	    {
	     valido='m';
	     break;
	    }
	   }
       }while(valido=='m');
     do
      {
       valido='n';
       gotoxy(40,8);
       printf("             ");
       gotoxy(20,8);printf("DIGITE NUEVA CEDULA:");
       scanf("\n"); gets(ced);
       lon = strlen(ced);
       for(j=0;j<=lon-1; j++)
	{
	 if(!(isdigit(ced[j])))
	   {
	     valido='m';
	     break;
	    }
	}
     }while(valido=='m');
     empresa[i].cedula=atoi(ced);
     gotoxy(20,9);printf("DIGITE NUEVO SUELDO    :");scanf("\n");gets(suel);
     empresa[i].sueldo=atof(suel);
     while (empresa[i].sueldo==0)
      {
       gotoxy(20,9);
       clreol();
       gotoxy(20,9);
       printf("DIGITE NUEVO SUELDO:");scanf("\n");gets(suel);
       empresa[i].sueldo=atof(suel);
      }
     gotoxy(20,10);printf("DIGITE NUEVO SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
     empresa[i].sexo=atoi(sex);
     while ((empresa[i].sexo!=1)&&(empresa[i].sexo!=2))
      {
       gotoxy(25,9);
       clreol();
       gotoxy(25,9);
       printf("DIGITE NUEVO SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
       empresa[i].sexo=atoi(sex);
      }
     sw=2;
    }
   }
   if (sw==1)
    {
    gotoxy(20,13);printf("< NO EXISTE ESTA CEDULA >");
    getch();
    }
   gotoxy(25,20);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
  }while(op!='N');
}

/*****************************************************************************/

void eliminar()
 {
  int k;
  char ced[20],valido,op;
  long aux;
  do
   {
    clrscr();
    cuadro(80,23);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("               ");
      gotoxy(25,5);printf("DIGITE CEDULA:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	   {
	     valido='m';
	     break;
	   }
	 }
      }while(valido=='m');
      aux=atol(ced);
      for(i=0;i<con;i++)
       {
	if(empresa[i].cedula==aux)
	  {
	   k=i+1;
	   sw=2;
	   for(j=i;j<=con-1;j++)
	      {
	       empresa[j]=empresa[k];
	       k++;
	      }
	   gotoxy(25,10);
	   printf("EMPLEADO ELIMINADO");
	   getch();
	   con--;
	  }
	}
      if(sw==1)
       {
	gotoxy(20,13); printf("< ESTA CEDULA NO EXISTE >");
	getch();
       }
      gotoxy(25,20);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
      op=toupper(getch());
     }while(op!='N');
   }

/******************************************************************************/
void ordenar()
 {
 char op;
  textcolor(14);
  textbackground(20);
  do
   {
    cuadro(80,23);
    gotoxy (31,5);printf("< MENU DE ORDENAR >\n");
    gotoxy (25,9); printf("1:POR NOMBRE \n");
    gotoxy (25,10);  printf("2:POR APELLIDO\n");
    gotoxy (25,11);  printf("3:POR CEDULA\n");
    gotoxy (25,12);  printf("4:SALIR\n");
    gotoxy (25,14);  printf("DIGITE OPCION:");op=getch();
    switch(op)
     {
      case'1':ordenar_nombre();break;
      case'2':ordenar_apellido();break;
      case'3':ordenar_cedula();break;
     }
   }while(op!='4');
 }
 /*****************************************************************************/

 void listado_general()
  {
   int c;c=6;
   clrscr();
   cuadro(80,23);
   gotoxy (12,5);printf("NOMBRE           APELLIDO         CEDULA    SUELDO    SEXO\n");
   for(i=0;i<con;i++)
     {
      gotoxy(12,c);printf("%s",empresa[i].nombre);
      gotoxy(29,c);printf("%s",empresa[i].apellido);
      gotoxy(46,c);printf("%ld",empresa[i].cedula);
      gotoxy(56,c);printf("%.2f",empresa[i].sueldo);
      gotoxy(68,c);printf("%d",empresa[i].sexo);
      c++;
     }
   getch();
 }

/*****************************************************************************/

void listado_femenino()
 {
  int c; c=6; sw=1;
  clrscr();
  cuadro(80,23);
  gotoxy(12,5);printf ("NOMBRE           APELLIDO        CEDULA   SUELDO    SEXO\n");
  for(i=0;i<con;i++)
   {
    if((empresa[i].sexo==2)&&(empresa[i].sueldo<=200000))
     {
      sw=2;
      gotoxy(12,c);printf("%s",empresa[i].nombre);
      gotoxy(29,c);printf("%s",empresa[i].apellido);
      gotoxy(45,c);printf("%ld",empresa[i].cedula);
      gotoxy(54,c);printf("%.2f",empresa[i].sueldo);
      gotoxy(66,c);printf("%d",empresa[i].sexo);
      c++;
     }
   }
  if(sw==1)
   {
   gotoxy (20,13);printf("< NO HAY MUJERES QUE GANEN MENOS DE 200000 >");
   }
  getch();
 }

/*****************************************************************************/

void listado_masculino()
 {
  int c; c=6;sw=1;
  clrscr();
  cuadro(80,23);
  gotoxy (12,5);printf("NOMBRE            APELLIDO        CEDULA    SUELDO    SEXO\n");
  for(i=0;i<con;i++)
   {
    if(empresa[i].sexo==1)
     {
      if(empresa[i].sueldo==300000)
       {
	sw=2;
	gotoxy(12,c);printf("%s",empresa[i].nombre);
	gotoxy(30,c);printf("%s",empresa[i].apellido);
	gotoxy(46,c);printf("%ld",empresa[i].cedula);
	gotoxy(56,c);printf("%.2f",empresa[i].sueldo);
	gotoxy(68,c);printf("%d",empresa[i].sexo);
	c++;
       }
     }
    }
  if(sw==1)
   {
    gotoxy (20,13);printf("< NO HAY HOMBRES CON SUELDO DE 300000 >");
   }
  getch();
 }

/***************************************************************************/

void main()
 {
  char op;
  textcolor(14);
  textbackground(20);
  do
   {
    cuadro(80,23);
    gotoxy (31,5);printf("< MENU PRINCIPAL >\n");
    gotoxy (25,9); printf("1:AGREGAR REGISTRO\n");
    gotoxy (25,10);  printf("2:CONSULTAR REGISTRO\n");
    gotoxy (25,11);  printf("3:MODIFICAR REGISTRO\n");
    gotoxy (25,12);  printf("4:ELIMINAR REGISTRO\n");
    gotoxy (25,13);  printf("5:LISTADO GENERAL\n");
    gotoxy (25,14);  printf("6:MUJERES QUE GANAN MENOS DE 200000\n");
    gotoxy (25,15);  printf("7:HOMBRES QUE GANAN 300000\n");
    gotoxy (25,16);  printf("8:FORMAS DE ORDENAR\n");
    gotoxy (25,17);  printf("9:SALIR                          \n");
    gotoxy (25,19); printf("DIGITE OPCION:"); op=getch();
    switch(op)
     {
      case'1':agregar();break;
      case'2':consultar();break;
      case'3':modificar();break;
      case'4':eliminar();break;
      case'5':listado_general();break;
      case'6':listado_femenino();break;
      case'7':listado_masculino();break;
      case'8':ordenar();break;
     }
   }while(op!='9');
 }

/***************************************************************************/

void cuadro(int i,int j)
  {
   clrscr();
   gotoxy(10,3);cprintf("±"); /** ALT 177 **/
   gotoxy(70,3);cprintf("±");
   gotoxy(10,23);cprintf("±"); /** ALT 177 **/
   gotoxy(70,23);cprintf("±"); /** ALT 177 **/
   for(i=10;i<=70;i++)
     {
      gotoxy(i,2);
      textcolor(14);
      cprintf("±"); /** ALT  **/
      gotoxy(i,24);cprintf("±"); /** ALT 177**/
      gotoxy(15,11);
      textcolor(14);
      j=i-8;
      if (j<=23)
       {
	gotoxy(10,j);cprintf("±");  /** ALT 177**/
	gotoxy(70,j);cprintf("±");  /** ALT 177 **/
       }
     }
  }
