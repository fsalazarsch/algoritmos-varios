#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


struct
{
  char codigo[25];
  char telefono[25];
  char nombre[40];
  char apellido[40];
  char direccion[25];
  char  fecha[25];
  int valor;

}empresa[300];

  int valor;
  void listado_general();
  int  i,j,con=0,lon,sw,st;
  char nombre[40],apellido[40],codigo[25];
  char direccion[25],fecha[25],telefono[25];  


void cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(4);textbackground(18);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     textcolor(4);textbackground(18);
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");

}

void agregar()
 {
  char op;
  char valido,cod[20];
  int st;
   do
    {
     clrscr();
    cuadros(1,79,1,24);
  do
     {
      clrscr();
      cuadros(1,79,1,24);
      valido='n';
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(cod);
      lon = strlen(cod);
      for(j=0;j<=lon-1; j++)
	{
	 if(!(isdigit(cod[j])))
	  {
	    valido='m';
	    break;
	  }
	}
    for (j=0;j<con;j++)
     {
     if(strcmp(empresa[j].codigo,cod)==0)
       {
	gotoxy(15,10);
	printf("ESTE CODIGO YA EXISTE");
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
    strcpy(empresa[con].codigo,cod);
    gotoxy(25,6);printf("DIGITE NOMBRE:");
    scanf("\n"); gets(empresa[con].nombre);
    gotoxy(25,7);printf("DIGITE APELLIDO:");
    scanf("\n"); gets(empresa[con].apellido);
    gotoxy(25,8);printf("DIGITE TELEFONO:");
    scanf("\n"); gets(empresa[con].telefono);
    
    gotoxy(25,9);printf("DIGITE DIRECCION :");
    scanf("\n");gets(empresa[con].direccion);
    gotoxy(25,10);printf("FECHA DE CONSUMO:");
    scanf("\n");gets(empresa[con].fecha);
    gotoxy(25,11);printf("DIGITE CONSUMO :");
    scanf("\n");
    scanf("%d",&empresa[con].valor);
   con++;
   gotoxy(25,12);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
 }while(op!='N');
}

void consultar()
 {
  char op,cod[20],valido;
  long aux;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("             ");
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(cod);
      lon = strlen(cod);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(cod[i])))
	  {

	    valido='m';
	    break;
	  }
	}
     }while(valido=='m');
    for (i=0;i<con;i++)
     {
     if(strcmp(empresa[i].codigo,cod)==0)
       {
	gotoxy(25,10);printf("EL NOMBRE DEL USUARIO ES  :%s",empresa[i].nombre);
	gotoxy(25,11);printf("EL APELLIDO DEL USUARIO ES:%s",empresa[i].apellido);
	gotoxy(25,12);printf("LA CODIGO DEL USUARIO ES  :%s",empresa[i].codigo);
	gotoxy(25,13);printf("EL TELEFONO DEL USUARIO ES:%s",empresa[i].telefono);
	gotoxy(25,14);printf("DIRECCION DEL USUARIO ES  :%s",empresa[i].direccion);
	gotoxy(25,15);printf("EL VALOR DEL CONSUMO FUE  :%.2d",empresa[i].valor);
	gotoxy(25,16);printf("LA FECHA DE CONSUMO  FUE  :%s",empresa[i].fecha);
	sw=2;
       }
     }
    if(sw==1)
     {
      gotoxy(20,12);printf("< NO EXISTE ESTE CODIGO  >");
     }
    gotoxy(25,20);printf("DESEA CONSULTAR OTRO REGISTRO (S/N):");
    op=toupper(getch());
  }while(op!='N');
}


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
	  strcpy(direccion,empresa[i].direccion);
	  strcpy(codigo,empresa[i].codigo);
	  valor=empresa[i].valor;
	  strcpy(telefono,empresa[i].telefono);
	  strcpy(fecha,empresa[i].fecha);

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  strcpy(empresa[i].direccion,empresa[i+1].direccion);
	  strcpy(empresa[i].codigo,empresa[i+1].codigo);
	  empresa[i].valor=empresa[i+1].valor;
	  strcpy(empresa[i].telefono,empresa[i+1].telefono);
	  strcpy(empresa[i].fecha,empresa[i+1].fecha);


	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  strcpy(empresa[i+1].direccion,direccion);
	  strcpy(empresa[i+1].codigo,codigo);
	  empresa[i+1].valor=valor;
	  strcpy(empresa[i+1].telefono,telefono);
	  strcpy(empresa[i+1].fecha,fecha);
	 
	}
       }
     }

    listado_general();
 }


void ordenar_apellido()
  {
    int i,j;
    for(j=0;j<=con-1;j++)
     {
     for(i=0;i<con-1;i++)
       {
	if(strcmp(empresa[i].apellido,empresa[i+1].apellido)>0)
	 {
	  strcpy(nombre,empresa[i].nombre);
	  strcpy(apellido,empresa[i].apellido);
	  strcpy(direccion,empresa[i].direccion);
	  strcpy(codigo,empresa[i].codigo);
	  valor=empresa[i].valor;
	  strcpy(telefono,empresa[i].telefono);
	  strcpy(fecha,empresa[i].fecha);

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  strcpy(empresa[i].direccion,empresa[i+1].direccion);
	  strcpy(empresa[i].codigo,empresa[i+1].codigo);
	  empresa[i].valor=empresa[i+1].valor;
	  strcpy(empresa[i].telefono,empresa[i+1].telefono);
	  strcpy(empresa[i].fecha,empresa[i+1].fecha);


	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  strcpy(empresa[i+1].direccion,direccion);
	  strcpy(empresa[i+1].codigo,codigo);
	  empresa[i+1].valor=valor;
	  strcpy(empresa[i+1].telefono,telefono);
	  strcpy(empresa[i+1].fecha,fecha);
     
	 }
	}
       }
     listado_general();
 }


void ordenar_codigo()
  {
   int i,j;
    for(j=0; j<=con-1; j++)
    {
    for(i=0;i<con-1;i++)
     {
	if(strcmp(empresa[i].codigo,empresa[i+1].codigo)>0)
	 {
	  strcpy(nombre,empresa[i].nombre);
	  strcpy(apellido,empresa[i].apellido);
	  strcpy(direccion,empresa[i].direccion);
	  strcpy(codigo,empresa[i].codigo);
	  valor=empresa[i].valor;
	  strcpy(telefono,empresa[i].telefono);
	  strcpy(fecha,empresa[i].fecha);

	  strcpy(empresa[i].nombre,empresa[i+1].nombre);
	  strcpy(empresa[i].apellido,empresa[i+1].apellido);
	  strcpy(empresa[i].direccion,empresa[i+1].direccion);
	  strcpy(empresa[i].codigo,empresa[i+1].codigo);
	  empresa[i].valor=empresa[i+1].valor;
	  strcpy(empresa[i].telefono,empresa[i+1].telefono);
	  strcpy(empresa[i].fecha,empresa[i+1].fecha);


	  strcpy(empresa[i+1].nombre,nombre);
	  strcpy(empresa[i+1].apellido,apellido);
	  strcpy(empresa[i+1].direccion,direccion);
	  strcpy(empresa[i+1].codigo,codigo);
	  empresa[i+1].valor=valor;
	  strcpy(empresa[i+1].telefono,telefono);
	  strcpy(empresa[i+1].fecha,fecha);
	  
	 }
     }
    
    }
   listado_general();
 }


void modificar()
 {
  char cod[20],op,op1,valido;
  long aux;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(34,4);
      printf("             ");
      gotoxy(20,4);printf("DIGITE CODIGO:");
      scanf("\n"); gets(cod);
      lon = strlen(cod);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(cod[i])))
	   {
	     valido='m';
	     break;
	   }
	}
     }while(valido=='m');
    for(i=0;i<con;i++)
    {
    if(strcmp(empresa[i].codigo,cod)==0)
      {
	clrscr();
	gotoxy(25,10);printf("NUEVO NOMBRE DEL USUARIO ES   :");scanf("\n");gets(empresa[i].nombre);
	gotoxy(25,11);printf("NUEVO APELLIDO DEL USUARIO ES :");scanf("\n");gets(empresa[i].apellido);
	gotoxy(25,12);printf("NUEVO TELEFONO DEL USUARIO ES :");scanf("\n");gets(empresa[i].telefono);
	gotoxy(25,13);printf("NUEVA DIRECCION DEL USUARIO ES:");scanf("\n");gets(empresa[i].direccion);
	gotoxy(25,14);printf("NUEVO VALOR DEL CONSUMO FUE   :");scanf("\n");scanf("%d",&empresa[i].valor);
	gotoxy(25,15);printf("NUEVA FECHA DE CONSUMO  FUE   :");scanf("\n");gets(empresa[i].fecha);


     sw=2;
    }
   }
   if (sw==1)
    {
    gotoxy(20,13);printf("< NO EXISTE ESTE CODIGO >");
    getch();
    }
   gotoxy(25,20);printf("DESEA MODIFICAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
  }while(op!='N');
}


void eliminar()
 {
  int k;
  char cod[25],valido,op;
  long aux;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("               ");
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(cod);
      lon = strlen(cod);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(cod[i])))
	   {
	     valido='m';
	     break;
	   }
	 }
      }while(valido=='m');
      for(i=0;i<con;i++)
       {
	if(strcmp(empresa[i].codigo,cod)==0)
	  {
	   k=i+1;
	   sw=2;
	   for(j=i;j<=con-1;j++)
	      {
	       empresa[j]=empresa[k];
	       k++;
	      }
	   gotoxy(25,10);
	   printf("ELIMINADO EL USUARIO");
	   getch();
	   con--;
	  }
	}
      if(sw==1)
       {
	gotoxy(20,13); printf("< ESTE CODIGO NO EXISTE >");
	getch();
       }
      gotoxy(25,20);printf("DESEA ELIMINAR OTRO REGISTRO (S/N):");
      op=toupper(getch());
     }while(op!='N');
   }



void ordenar()
 {
 char op;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    gotoxy (31,5);printf("< MENU DE ORDENAR >\n");
    gotoxy (25,9); printf("1: NOMBRE \n");
    gotoxy (25,10);  printf("2: APELLIDO\n");
    gotoxy (25,11);  printf("3: CEDULA\n");
    gotoxy (25,12);  printf("4: SALIR\n");
    gotoxy (25,14);  printf("OPCION:");op=getch();
    switch(op)
     {
      case'1':ordenar_nombre();break;
      case'2':ordenar_apellido();break;
      case'3':ordenar_codigo();break;
     }
   }while(op!='4');
 }
 /*****************************************************************************/

 void listado_general()
  {
   int c;c=6;
   clrscr();
   cuadros(1,79,1,24);
   gotoxy (10,5);printf("NOMBRE   APELLIDO    CODIGO   TELEFONO  CONSUMO      FECHA\n");
   for(i=0;i<con;i++)
     {
      gotoxy(10,c);printf("%s",empresa[i].nombre);
      gotoxy(19,c);printf("%s",empresa[i].apellido);
      gotoxy(31,c);printf("%s",empresa[i].codigo);
      gotoxy(40,c);printf("%s",empresa[i].telefono);
      gotoxy(50,c);printf("%d",empresa[i].valor);
      gotoxy(59,c);printf("%s",empresa[i].fecha);
      c++;
     }
   getch();
 }

void menu()
{
 int tecla;
  int f;

  char opciones[27][70];

  do{
  textcolor(4);textbackground(18);
  strcpy(opciones[8],  " ADICCIONAR ");
  strcpy(opciones[9],  " ELIMINAR   ");
  strcpy(opciones[10], " MODIFICAR  ");
  strcpy(opciones[11], " LISTADOS   ");
  strcpy(opciones[12], " CONSULTAR  ");
  strcpy(opciones[13], " ORDENAR    ");
  strcpy(opciones[14], "   SALIR    ");
  clrscr();
  gotoxy(14,21);printf("CORPORACION UNIVERSITARIA DE SANTANDER");
  gotoxy(19,22);printf("EUCARDO FABIAN PE¥ALOZA PEREA");
  gotoxy(28,23);printf("96132053");
  gotoxy(31,24);printf("S2A");
	 textcolor(4);textbackground(18);
	cuadros(23,38,7,15);
	textcolor(3);textbackground(9);
	for(f=8;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=8;
	  textcolor(1);textbackground(3);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(4);textbackground(18);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(4);textbackground(18);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(1); textbackground(3);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(4);textbackground(18);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=8;
	      textcolor(1);textbackground(3);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(4);textbackground(18);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(4);textbackground(18);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=8)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(1);textbackground(3);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(4);textbackground(18);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(1);textbackground(3);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(4);textbackground(18);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   8 :agregar();  break;
		      case   9 :eliminar();  break;
		      case   10:modificar();  break;
		      case   11:listado_general();  break;
		      case   12:consultar();  break;
		      case   13:ordenar();  break;
		     }
	   }while(f !=14);
  }
 void main()
 {
 menu();
 }
 


   









      
     
 


