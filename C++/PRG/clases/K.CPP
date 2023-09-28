#include "stdio.h"
#include "conio.h"
#include "io.h"
#include "fcntl.h"
#include "dos.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#define go {gotoxy(2,23);}

struct cliente
{
   int codigo;
   char nombre[20];
   char apellido[20];
   char direccion[20];
   char telefono[10];
 };
struct  cliente agenda[50];
   void clave();
   void presenta();
  void cuadro(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[],char a6[]);
  char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È",a7[]="Ì",a8[]="¹",a9[]="Ê",a10[]="Ë";;
  char vec[5][13],contra[5],cadena[30];;
  void centraM(char men[],int f);
   menu();
  void boli (int fi,int ff,int ci, int cf);
  int res,op,j,k,i=0,r,x;
  void lineav(int x1,int y1,int x2,char a1[],char a9[],char a10[]);
  void lineah(int y1,int x1,int y2,char a2[],char a7[],char a8[]);
  char tecla;
  int con=1,c=0;
  int a=0,l=0,sw=0,cod,s,n;
  void adic();
  void modif();
  void consult();
  void borrar();
  void validar(int fil,int col);
  buscar(int codi);
  void pantalla (int fila, int columna);
  char nombre,apellido,direccion,telefono,tel[10],dir[20],nom[30],ape[30];


  void main()
  {
     clrscr();
  //   clave();
      presenta();

      menu();
      do
		{

		op=menu();
		switch(op)
		{
		   case 0:adic();
			  break;
		   case 1:modif();
			  break;
		   case 2:consult();
			  break;
		   case 3:borrar();
			  break;
		   case 4:
			  break;
		 }

		 }
		 while(op!=4);
   }


     void centraM(char men[],int f)
     {
	int lon,col;
	lon=strlen(men);
	col=(80-lon)/2;
	gotoxy(col,f);cprintf("%s",men);

     }

   // getch();


  void boli (int fi,int ff,int ci, int cf)
  {
     int i,j;
     for (i=fi;i<=ff;i++)
     {
       for(j=ci;j<=cf;j++)
	{
	  gotoxy(j,i);cprintf(" ");
	}
     }
   }

   void cuadro(int x1,int y1,int x2,int y2, char a1[],char a2[],char a3[],char a4[],char a5[],char a6[])
    {
      int i;
      for(i=x1;i<=x2;i++)
      {
	 gotoxy(y1,i);cprintf(a1);
	 gotoxy(y2,i);cprintf(a1);
      }
	 for(i=y1;i<=y2;i++)
	  {
	    gotoxy(i,x1);cprintf(a2);
	    gotoxy(i,x2);cprintf(a2);
	  }
	    gotoxy(y1,x1);cprintf(a3);
	    gotoxy(y2,x2);cprintf(a4);
	    gotoxy(y2,x1);cprintf(a5);
	    gotoxy(y1,x2);cprintf(a6);

      }


void validar(int fil,int col)
{ int i=0;
 cadena[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+i,col);res=getch();
      if ((res>='a' && res<='z')||(res>='A' && res<='Z')||(res==' '))
	{
	    cadena[i++]=res;
	    gotoxy(fil-1+i,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cadena[0] == ' ');
 cadena[i]='\0';
 }



void consult()
{
 do
   {
	boli(17,17,22,78);
	boli(5,4,20,78);
	cuadro(5,9,11,23,a1,a2,a3,a4,a5,a6);
	lineah(9,7,23,a2,a7,a8);
	gotoxy(4,20);printf("ELIJA EL TIPO DE CONSULTA..");
	 gotoxy(12,6);printf("CONSULTA");
	gotoxy(10,8);printf("1.GLOBAL");
	gotoxy(10,9);printf("2.INDIVIDUAL");
	gotoxy(10,10);printf("3.SALIR");
	gotoxy(35,20);op=getch();
	boli(20,20,4,78);
	boli(5,11,9,23);

	if (op=='1')
	  {
	    boli(17,17,22,78);
	    gotoxy(6,6);printf("CODIGO");
	    gotoxy(13,6);printf("NOMBRES");
	    gotoxy(30,6);printf("APELLIDOS");
	    gotoxy(49,6);printf("DIRECCION");
	    gotoxy(65,6);printf("TELEFONO");
	    cuadro(5,5,18,75,a1,a2,a3,a4,a5,a6);
	    lineah(5,16,75,a2,a7,a8);
	    lineah(5,7,75,a2,a7,a8);
	    lineav(5,12,16,a1,a9,a10);
  for (n=0;n<=j;n++)
  {
    if (x<=3)
    {
     gotoxy(6,x+8);printf("%d",agenda[n].codigo);
     gotoxy(13,x+8);printf("%s",agenda[n].nombre);
     gotoxy(30,x+8);printf("%s",agenda[n].apellido);
     gotoxy(49,x+8);printf("%s",agenda[n].direccion);
     gotoxy(65,x+8);printf("%s",agenda[n].telefono);
      x++;
     }
     else
     {
      gotoxy(20,17);printf("DESEA CONTINUAR S/N [ ]");
      gotoxy(44,17);res=getch();
      if (res=='n')
       {
	n=j;
       }
       else
       {
	x=0;
       }
      }
      }

       gotoxy(22,17);printf("DATOS CONSULTADOS..");
       getch();
       boli(5,20,4,78);
     }


if (op=='2')
{
 do
 {
   boli(6,9,49,65);
   boli(20,20,4,78);
   cuadro(5,35,11,66,a1,a2,a3,a4,a5,a6);
   pantalla(6,36);
   gotoxy(4,20);printf("DIGITE EL CODIGO A CONSULTAR..");
   gotoxy(49,6);scanf("%d",&cod);
  if (buscar(cod)!=0)
  {
   boli(6,10,49,65);
   gotoxy(49,6);printf("%d",agenda[l].codigo);
   gotoxy(49,7);printf("%s",agenda[l].nombre);
   gotoxy(49,8);printf("%s",agenda[l].apellido);
   gotoxy(49,9);printf("%s",agenda[l].direccion);
   gotoxy(49,10);printf("%s",agenda[l].telefono);
   boli(20,20,4,78);
   gotoxy(4,20);printf(" DATOS CONSULTADOS");
   getch();
 }
   else
  {
     boli(20,20,4,78);
    gotoxy(4,20);printf("ESTE CODIGO NO EXISTE");
    getch();
  }
    l=0;
   boli(20,20,4,78);
   gotoxy(4,20);printf("DESEA CONTINUAR CONSULTANDO S/N [ ]");
   gotoxy(37,20);res=getch();
   boli(20,20,4,78);
  res=toupper(res);
  boli(5,20,4,78);
 }
  while (res!='N');
 }
 } while (op!='3');

 }



void borrar()
{
 do
  {
    boli(6,20,2,78);
     cuadro(5,48,11,75,a1,a2,a3,a4,a5,a6);
    pantalla(6,49);
    boli(20,20,4,78);
    gotoxy(4,20);printf("DIGITE EL CODIGO DEL REGISTRO A BORRAR");

    gotoxy(60,6);scanf("%d",&cod);
    if (buscar(cod)!=0)
    {
     gotoxy(60,6);printf("%d",agenda[l].codigo);
     gotoxy(60,7);printf("%s",agenda[l].nombre);
     gotoxy(60,8);printf("%s",agenda[l].apellido);
     gotoxy(60,9);printf("%s",agenda[l].direccion);
     gotoxy(60,10);printf("%s",agenda[l].telefono);
      boli(20,20,4,78);
       //boli(23,23,4,78);
     gotoxy(4,20);printf("DESEA BORRAR ESTE REGISTRO S/N [ ]" );
     gotoxy(36,20);res=getch();
     res=toupper(res);
     boli(20,20,4,78);
     if (res=='S')
     {
     if (l== --j)
       {
       j--;
       }
       else
       {
	  for (s=l;s<j;s++)
	  {
	   agenda[s].codigo=agenda[s+1].codigo;
	   strcpy(agenda[s].nombre,agenda[s+1].nombre);
	   strcpy(agenda[s].apellido,agenda[s+1].apellido);
	   strcpy(agenda[s].direccion,agenda[s+1].direccion);
	   strcpy(agenda[s].telefono,agenda[s+1].telefono);
	   n--;
	 }
       }
//       boli(23,23,4,79);
       gotoxy(4,20);printf("REGISTRO BORRADO...PULSE ENTER PARA CONTINUAR");
       getch();
     }

   }
  else
   {
    //boli(23,23,4,79);
    boli(20,20,4,78);
    gotoxy(4,20);printf("CODIGO NO EXISTE... PULSE ENTER PARA CONTINUAR");
    getch();
  }
   // boli(23,23,4,79);
    l=0;
     boli(20,20,4,78);
    gotoxy(4,20);printf("DESEA BORRAR OTRO REGISTRO S/N [ ]");
    gotoxy(36,20);res=getch();
    res=toupper(res);
    j++;
  }
   while (res!='N');
   boli(5,20,2,78);

}

void modif()
{
  int cod;
 do
{
   boli(5,20,2,79);
 cuadro(5,19,11,50,a1,a2,a3,a4,a5,a6);
 gotoxy(4,20);printf("DIGITE EL CODIGO DEL REGISTRO A MODIFICAR");
 pantalla(6,20);
 gotoxy(32,6);scanf("%d",&cod);
 boli(20,20,4,78);
 if (buscar(cod)!=0)
 {
 do
 {

  gotoxy(32,7);puts (agenda[l].nombre);
  gotoxy(32,8);puts(agenda[l].apellido);
  gotoxy(32,9);puts(agenda[l].direccion);
  gotoxy(32,10);puts(agenda[l].telefono);
  cuadro(5,52,10,69,a1,a2,a3,a4,a5,a6);

  gotoxy(53,6);printf("1..NOMBRE");
  gotoxy(53,7);printf("2..APELLIDOS");
  gotoxy(53,8);printf("3..DIRECCION");
  gotoxy(53,9);printf("4..TELEFONO");
  boli(20,20,4,78);
  gotoxy(4,20);printf("ELIJA LA OPCION A MODIFICAR [ ]");
  gotoxy(33,20);op=getch();
  if (op=='1')
   {
     boli(5,10,52,69);
     boli(7,7,32,49);
     validar(32,7);
   strcpy(nom,cadena);
   strcpy(agenda[l].nombre,nom);
   }

      if (op=='2')
   {
    boli(5,10,52,69);
    boli(8,8,32,49);
    validar(32,8);
    strcpy(ape,cadena);
    strcpy(agenda[l].apellido,ape);
    }
      if (op=='3')
   {
      boli(5,10,52,69);
      boli(9,9,32,49);
    gotoxy(32,9);gets(dir);
    strcpy(agenda[l].direccion,dir);
    }
    if (op=='4')
   {
      boli(5,10,52,69);
      boli(10,10,32,49);
    gotoxy(32,10);gets(tel);
    strcpy(agenda[l].telefono,tel);
    }
    boli(20,20,4,78);
    gotoxy(4,20);printf("DESEA MODIFICAR OTRO CAMPO DEL MISMO REGISTRO [ ]");
    gotoxy(51,20);res=getch();
    res=toupper(res);
   }while (res!='N');
  }
 else
 {
 boli(5,20,4,78);
 gotoxy(4,20);printf("ESTE CODIGO NO EXISTE..VERIFIQUELO..");
 gotoxy(45,20);printf("PRESIONE ENTER PARA CONTINUAR..");
  getch();
  }
  boli(5,20,4,78);
  boli(20,20,4,78);
  gotoxy(4,20);printf("DESEA MODIFICAR OTRO REGISTRO S/N [ ]");
  gotoxy(39,20);res=getch();
  res=toupper(res);
} while (res!='N');
  boli(20,20,4,78);
  boli(5,20,4,78);
}



void lineah(int y1,int x1,int y2,char a2[],char a7[],char a8[])
{ int p;
  for(p=y1;p<=y2;p++)
  {
    gotoxy(p,x1);cprintf(a2);

  }
    gotoxy(y1,x1);printf(a7);
    gotoxy(y2,x1);printf(a8);
}



buscar(int cod)
{
 int sw=0;
     k=0;
  while ((sw==0) && (k<j))
   {if (cod==agenda[k].codigo)
     sw=1;
     else
       k++;
    }
    return(sw);


}
void lineav(int x1,int y1,int x2,char a1[],char a9[],char a10[])
{ int p;
  for(p=x1;p<=x2;p++)
  {
    gotoxy(y1,p);cprintf(a1);

  }
    gotoxy(y1,x1);printf(a10);
    gotoxy(y1,x2);printf(a9);
}


void pantalla (int fila, int columna)
{  textcolor(12);
   gotoxy(columna,fila);cprintf("CODIGO....:");
   gotoxy(columna,fila+1);cprintf("NOMBRE....:");
   gotoxy(columna,fila+2);cprintf("APELLIDO..:");
   gotoxy(columna,fila+3);cprintf("DIRECCION.:");
   gotoxy(columna,fila+4);cprintf("TELEFONO..:");
}



void adic()
{
do
 {
    boli(7,11,24,54);
    cuadro(5,3,11,35,a1,a2,a3,a4,a5,a6);
    textcolor(12);gotoxy(4,20);cprintf("DIGITE EL CODIGO DEL REGISTRO A AGREGAR");
    pantalla(6,5);
    gotoxy(16,6);scanf("%d",&cod);
    boli(20,20,4,78);
     if (buscar(cod)==0)
       {
      validar(16,7);
      strcpy(nom,cadena);
      fflush(stdin);
      validar(16,8);
      strcpy(ape,cadena);
      gotoxy(16,9);gets(dir);
      gotoxy(16,10);gets(tel);
      agenda[j].codigo=cod;
      strcpy(agenda[j].nombre,nom);
      strcpy(agenda[j].apellido,ape);
      strcpy(agenda[j].direccion,dir);
      strcpy(agenda[j].telefono,tel);
     }
      else
	 {
	   gotoxy(16,6);printf("%d",agenda[k].codigo);
	   gotoxy(16,7);printf("%s",agenda[k].nombre);
	   gotoxy(16,8);printf("%s",agenda[k].apellido);
	   gotoxy(16,9);printf("%s",agenda[k].direccion);
	   gotoxy(16,10);printf("%s",agenda[k].telefono);
	   boli(20,20,4,78);
	   gotoxy(4,20);printf("CODIGO  YA EXISTE.. VERIFIQUELO..");
	   gotoxy(40,20);printf("PRESIONE ENTER PARA CONTINUAR..");
	   getch();
	 }
	   j++;
	   k=0;
	    boli(20,20,4,78);
	   gotoxy(4,20);printf("DESEA AGREGAR OTRO CLIENTE S/N...");
	   gotoxy(38,20);res=getch();
	   res=toupper(res);
	   boli(5,11,3,35);
	   boli(5,20,2,79);
	   boli(5,3,11,35);

	 }
	   while (res!='N');
		}


 void clave()
   {
    do
       {
	do
       {

	clrscr();
	textcolor(1);
	textbackground(0);
	cuadro(7,24,9,59,a1,a2,a3,a4,a5,a6);
	textcolor(6);
	centraM("ENTER YOUR PASSWORD ",8);
	for(i=0;i<=4;i++)
	  {
	   contra[i]=getch();
	   printf("%c",'*');
	  }
	   contra[i]='\0';
	   strcpy(contra,strupr(contra));
	     if(strcmp(contra,"ENTER")!=0)
	       {
		clrscr();
		textcolor(1);
		textbackground(0);
		cuadro(7,24,9,59,a1,a2,a3,a4,a5,a6);
		textcolor(10);
		centraM("  ACCESO DENEGADO  ",8);getch();
		con++;
	       }
	       else
		{
		 sw=1;
		}
		if (con>3)
{ fflush(stdin);
 textcolor(6);
 textbackground(0);
 cuadro(22,10,24,70,a1,a2,a3,a4,a5,a6);
  textcolor(1);
   textbackground(0);
 centraM("USUARIO NO AUTORIZADO PRESIONE ENTER PARA SALIR",23);
 getch();
 exit(1);
 }
}
   while (sw==0);
 }
    while(strcmp(contra,"ENTER")!=0);
}


     menu()
       {
	do
	{
	strcpy(vec[0],"   ADICION  ");
	strcpy(	vec[1],"MODIFICACION");
	strcpy(vec[2],"  CONSULTA  ");
	strcpy(vec[3],"  BORRADO   ");
	strcpy(vec[4],"   SALIR    ");
	textcolor(14);
	cuadro(22,1,24,80,a1,a2,a3,a4,a5,a6);

	r=2;
      textcolor(3);
      textbackground(0);
	for (i=0;i<5;i++)
	 {
	   if (i==j)
	    {
	      textcolor(4);
	      textbackground(10);
	      gotoxy(2+r,2);cprintf("%s",vec[i]);
	     }
	    else
	      {
		textcolor(2);textbackground(1);
		gotoxy(2+r,2);cprintf("%s",vec[i]);}
		r+=15;
		textcolor(2);
		textbackground(1);

		switch(j)
		{
		   case 0:centraM(" MODULO PARA LA ADICION DE CLIENTES     ",23);
			  break;
		   case 1:centraM(" MODULO PARA LA MODIFICACION DE CLIENTES",23);
			  break;
		   case 2:centraM(" MODULO PARA LA CONSULTA DE CLIENTES    ",23);
			  break;
		   case 3:centraM(" MODULO PARA EL BORRADO DE CLIENTES     ",23);
			  break;
		   case 4:centraM(" MODULO PARA SALIR DE LA APLICACION      ",23);
			  break;
		 }

	 }
	 textbackground(0);
	tecla=getch();

       if(tecla==77)
       {
	 if (j<4)
	 j++;
	 else
	 j=0;
       }
       if (tecla==75)
	{
	   if (j!=0)
	   j--;
	 else
	   j=4;
	}
    }
 while (tecla!=13);
 return(j);

}



     void presenta()
     {
	clrscr ();
	textcolor(4);
	textbackground(8);
	cuadro(1,1,3,80,a1,a2,a3,a4,a5,a6);
	textcolor(5);
	textbackground(8);
	cuadro(4,1,21,80,a1,a2,a3,a4,a5,a6);
	textcolor(4);
	textbackground(8);

	cuadro(7,24,11,54,a1,a2,a3,a4,a5,a6);
	textcolor(10);
	centraM("REALIZADO POR",8);
	centraM("ANIBAL VIDAL MANZANO",10);
     }
