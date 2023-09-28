
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>

struct
  {
  char cedula[15];
  char nombre[40];
  char apellido[40];
  char sexo;
  long int sueldo;
  }emp[300];


void menu ();
void llenar ();
void adicionar();
void modificar();
void eliminar();
void ordenar();
void listar();
void listf();
void listm();
void consultar1();
void consultar2();
void consultar3();
void listg();
void consultar();
void ordenar_cedula();
void ordenar_nombre();
void ordenar_apellido();

 int i,t,k=1;


void marcar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {
	  case 1: fondo=176; break;

	  case 2: fondo= 177;break;

	  case 3: fondo= 178;break;

	  case 4: fondo= 32;break;

	    default:
			fondo= 32;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }



void marco(ci,cf,fi,ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Í");
  delay(4); gotoxy(i,ff); printf("Í");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("º");
  delay(4); gotoxy(cf,i); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(0);
 }


 void cuadro1()
 {int i;
  textcolor(YELLOW);
 i=19;
 gotoxy(i,5);
 for(i=19;i<=59;i++)
 {
 textcolor(YELLOW);

   cprintf("%c",176);

 }

 i=20;
 gotoxy(i,19);
 for(i=20;i<=58;i++)
 {
   textcolor(YELLOW);


  cprintf("%c",177);

 }



 for(i=6;i<=19;i++)
 {
  textcolor(YELLOW);


  cprintf("%c",177);
  gotoxy(19,i);

 }

 for(i=6;i<=19;i++)
 {
    textcolor(YELLOW);


    cprintf("%c",177);
  gotoxy(59,i);
 }

 }





void main()
{
clrscr();
menu();
getche();
}
///////////////////////////////////////////////////////////////////
void menu()
{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[12],"LLENAR                     ");
 strcpy(opciones[13],"LISTAR                     ");
 strcpy(opciones[14],"ELIMINAR                   ");
 strcpy(opciones[15],"MODIFICAR                  ");
 strcpy(opciones[16],"ORDENAR                    ");
 strcpy(opciones[17],"CONSULTAR                  ");
 strcpy(opciones[18],"ADICIONAR                  ");
 strcpy(opciones[19],"SALIR                      ");
   do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(14,4); textcolor(11); textbackground(1);
 printf("M   E   N   U       P   R   I   N   C   I   P   A  L");
 textcolor(14);textbackground(1);
 gotoxy(30,7); textcolor(12); textbackground(3);
 printf("REGISTRO EMPRESA");
 marcar(8,8,70,20,0);
 marco(18,52,11,20);
 marco(2,78,2,24);
 textcolor(12); textbackground(8);
 for(f=12; f<=19;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=19)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=19;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 12: llenar(); break;
 case 13: listar(); break;
 case 14: eliminar(); break;
 case 15: modificar(); break;
 case 16: ordenar(); break;
 case 17: consultar(); break;
 case 18: adicionar(); break;
 case 19: default: printf("FINAL");
 }

}
 while(f!=19);
}

///////////////////////////////////////////////////////////////

void llenar()
{ char ced[15];

     int s,l,i,sw_1,r;
     clrscr();
     textcolor(14); textbackground(1);
     marcar(2,2,78,24,1);
     marco(2,78,2,24);
     textcolor(11); textbackground(1);
     gotoxy(32,4);printf("REGISTRO LLENAR ");
     gotoxy(25,7);printf("CUANTOS REGISTROS DESEA LLENAR ");
     gotoxy(37,15);printf("No.#");scanf("%d",&t);gotoxy(26,20);printf("PRESIONE ENTER PARA CONTINUAR ");
     if(t>300)
     { printf(" *** DESBORDAMIENTO  *** ");}
       else
       {
	sound(200);delay(500);nosound();

	for(i=1;i<=t;i++)
	{
	  clrscr();
	  marco(2,78,2,24);
	  gotoxy(28,4); printf("INGRESE LOS DATOS AL REGISTRO ");
	  textcolor(12); textbackground(3);
	  marcar(3,6,77,23,0);
	  textcolor(12); textbackground(8);
	  do{
	  gotoxy(20,10);clreol();
	  textcolor(12); textbackground(3);
	  printf("DIGITE LA  CEDULA:   ");
      do{
	  sw_1=0;
	  gotoxy(39,10);
	  clreol();
	  scanf("\n");
	  gets(ced);
	  r=strlen(ced);
	}while((r>15)||(r<1));
	  for(l=0;l<r;l++)
	  if(isdigit(ced[l])==0)
	  sw_1=1;
	}while(sw_1==1);

	       strcpy(emp[i].cedula,ced);
	       gotoxy(20,12);printf("DIGITE EL NOMBRE  :    ");scanf("\n"); gets(emp[i].nombre);
	       gotoxy(20,14);printf("DIGITE EL APELLIDO:    ");scanf("\n");gets(emp[i].apellido);

	       do{
		  gotoxy(20,16);clreol();
		  printf("SEXO [0PCION SUELDOS (0=FEM)||(1=MASC)]:    ");
		  scanf("\n");
		  emp[i].sexo=getchar();
		 }while(emp[i].sexo!='0' && emp[i].sexo!='1');
	      gotoxy(20,18); printf("DIGITE EL SUELDO:    "); scanf("%ld",&emp[i].sueldo);
	      gotoxy(26,20);printf("PRESIONE ENTER PARA CONTINUAR ");

   }getch();
}
}
///////////////////////////////////////////////////////////////////

void adicionar()
{char op,ced[15];
  int r,sw_1,l;
  do{
  clrscr();
  if(t==300)
  {clrscr();
   gotoxy(5,10); printf("NO SE PUEDE ADICIONAR EL VECTOR ESTA LLENO");

  }
   else
  { t++;
      do{
	  
	  marco(2,78,2,24);
	  gotoxy(28,4); printf("INGRESE LOS DATOS AL REGISTRO ");
	  textcolor(8); textbackground(2);
	  marcar(3,6,77,23,0);
	  textcolor(8); textbackground(2);
	  gotoxy(20,10);clreol();
	  printf("DIGITE SU CEDULA:  ");
       do{
	  sw_1=0;
	  gotoxy(39,10);
	  clreol();
	  scanf("\n");
	  gets(ced);
	  r=strlen(ced);
       }while((r>15)||(r<1));
	  for(l=0;l<r;l++)
	  if(isdigit(ced[l])==0)
	  sw_1=1;
      }while(sw_1==1);

       strcpy(emp[t].cedula,ced);
       gotoxy(20,12); printf("DIGITE SU NOMBRE:  ");
       scanf("\n"); gets(emp[t].nombre);
       gotoxy(20,14); printf("DIGITE SU APELLIDO:  ");
       scanf("\n"); gets(emp[t].apellido);
       do{
	 gotoxy(20,16);clreol();
	 printf("SEXO [0PCION SUELDOS (0=FEM)||(1=MASC)]:    ");
	 scanf("\n");
	 emp[i].sexo=getchar();
       }while(emp[i].sexo!='0' && emp[i].sexo!='1');
       gotoxy(20,18); printf("DIGITE SU SUELDO:  ");
       scanf("%ld",&emp[t].sueldo);
     }
      gotoxy(18,22);printf("DESEA AGREGAR OTRO REGISTRO S/N ");
      op=toupper(getch());
    }while(op!='N');


}



void listar()
{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[12],"LISTADO FEMENINO           ");
 strcpy(opciones[13],"LISTADO MASCULINO          ");
 strcpy(opciones[14],"LISTADO GENERAL            ");
 strcpy(opciones[15],"MENU PRINCIPAL             ");
do
 {
 textcolor(14); textbackground(15);
 clrscr();
 textcolor(14);textbackground(15);
 gotoxy(14,4); textcolor(12); textbackground(15);
 printf("M   E   N   U       L   I   S   T   A   D   O   S  ");
 textcolor(14);textbackground(1);
 gotoxy(30,7); textcolor(12); textbackground(2);
 printf("REGISTRO EMPRESA");

 marcar(8,8,70,20,0);
 marco(18,52,11,18);
 marco(2,78,2,24);
 textcolor(12); textbackground(8);
 for(f=12; f<=15;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 12: listf(); break;
 case 13: listm(); break;
 case 14: listg(); break;
 case 15: menu ();  break;
 }

}
 while(f!=15);
}




/////////////////////////////////////////////////////////////////////
 void listf()
 {
  int i,cont;

  clrscr();
  marco(2,78,22,24);
  marcar(1,22,79,24,1);
  gotoxy(22,23);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");

  marco(2,78,1,25);
  gotoxy(30,2); printf("LISTADO FEMENINO ");
  textcolor(1); textbackground(14);
  marco(2,20,3,25);
  gotoxy(8,6); printf("CEDULA");
  marco(2,39,3,25);
  gotoxy(27,6); printf("NOMBRE");
  marco(2,59,3,25);
  gotoxy(46,6);  printf("APELLIDO");
  marco(2,78,3,25);
  gotoxy(66,6);  printf("SUELDO");

  cont=7;
  for(i=1;i<=t;i++)
  {
  if(emp[i].sexo== '0')
  {if(emp[i].sueldo<200000)
  {

  gotoxy(8,cont);  puts(emp[i].cedula);
  gotoxy(27,cont); puts(emp[i].nombre);
  gotoxy(46,cont); puts(emp[i].apellido);
  gotoxy(66,cont); printf("%ld",emp[i].sueldo);

  cont++;
  }
  }getch();
  }

 }
/////////////////////////////////////////////////
void listm()
 {int i,cont;

  clrscr();
  marco(2,78,22,24);
  marcar(1,22,79,24,1);
  gotoxy(22,23);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");

  marco(2,78,1,25);
  gotoxy(30,2); printf("LISTADO MASCULINO ");
  textcolor(11); textbackground(3);
  marco(2,20,3,25);
  gotoxy(8,6); printf("CEDULA");
  marco(2,39,3,25);
  gotoxy(27,6); printf("NOMBRE");
  marco(2,59,3,25);
  gotoxy(46,6);  printf("APELLIDO");
  marco(2,78,3,25);
  gotoxy(66,6);  printf("SUELDO");
  cont=7;
  for(i=1;i<=t;i++)
  {
  if(emp[i].sexo=='1')
  {if(emp[i].sueldo>=300000)
  {
  gotoxy(8,cont);puts(emp[i].cedula);
  gotoxy(27,cont);puts(emp[i].nombre);
  gotoxy(46,cont);puts(emp[i].apellido);
  gotoxy(66,cont);printf("%ld",emp[i].sueldo);



  cont++;
  }
  }getch();
  }

 }

/////////////////////////////////////////////////////////////

void listg()
 {
  int i,cont;
  clrscr();
  marco(2,78,22,24);
  marcar(1,22,79,24,1);
  gotoxy(22,23);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");

  marco(1,79,1,24);
  gotoxy(30,2); printf("LISTADO GENERAL"); textcolor(11); textbackground(3);
   marco(2,20,3,22);
  gotoxy(8,6); printf("CEDULA");
  marco(2,39,3,22);
  gotoxy(27,6); printf("NOMBRE");;
  marco(2,59,3,22);
  gotoxy(46,6);  printf("APELLIDO");
  marco(2,78,3,22);
  gotoxy(66,6);  printf("SUELDO");
  cont=7;
  for(i=1;i<=t;i++)
  {
  gotoxy(8,cont); puts(emp[i].cedula);
  gotoxy(27,cont); puts(emp[i].nombre);
  gotoxy(46,cont);  puts(emp[i].apellido);
  gotoxy(66,cont);  printf("%ld",emp[i].sueldo);


  cont++;
  } getche();
}

///////////////////////////////////////////////////////////////////
void eliminar()
{int i,j,sw=1,r,l;
  char op;
  char cedula[15];
   clrscr();

   marco(2,78,1,25);
    textcolor(14); textbackground(1);
    marcar(18,18,60,22,1);
    marco(18,60,18,22);
    gotoxy(22,20);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");
    textcolor(14); textbackground(1);
    marcar(8,13,73,17,1);
    marco(8,73,13,17);
    gotoxy(24,15); printf("AL DIGITAR EL NUMERO DE TU CEDULA. ");
    gotoxy(28,16); printf("TU REGISTRO SERA ELIMINADO. ");
    gotoxy(30,2); printf("REGISTRO ELIMINAR");

   gotoxy(20,8);printf(" DIGITE LA CEDULA A ELIMINAR   : ");scanf("\n"); gets(cedula);

  for(i=1;i<=t;i++)
  {if(strcmp(emp[i].cedula,cedula)==0)
   { sw=0;
    for(j=i;j<=t;j++)
	{emp[j]=emp[j+1];
       }
       t--;
    }
   }
   if(sw==1)
   { clrscr();
    marco(1,76,1,24);
    textcolor(14); textbackground(3);
    marcar(20,8,48,12,1);
    marco(20,48,8,12);
    gotoxy(20,3); printf(" R E G I S T R O  E L I M I N A R ");
    gotoxy(22,10); printf("!!! LA CEDULA ERRADA !!!");
    sound(200);delay(500);nosound();
    sound(400);delay(600);nosound();
    gotoxy(22,20);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");
   } getch();
}





void ordenar()
{

 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[12],"ORDENAR POR CEDULA          ");
 strcpy(opciones[13],"ORDENAR POR NOMBRE          ");
 strcpy(opciones[14],"ORDENAR POR APELLIDO        ");
 strcpy(opciones[15],"MENU PRINCIPAL              ");
   do
 {
 textcolor(14); textbackground(1);
 clrscr();
 textcolor(14);textbackground(1);
  gotoxy(14,4); textcolor(10); textbackground(2);
 printf("M   E   N   U       O   R   D   E   N   A   R");
 textcolor(14);textbackground(1);
 gotoxy(30,7); textcolor(12); textbackground(16);
 printf("REGISTRO EMPRESA");
 marcar(8,8,70,20,0);
 marco(18,52,11,18);
 marco(2,78,2,24);
 textcolor(12); textbackground(8);
 for(f=12; f<=15;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
   case 12 :ordenar_cedula(); break;

   case 13 :ordenar_nombre();break;

   case 14 :ordenar_apellido();break;

   case 15 :menu();break;



 }

}
 while(f!=15);
}


/////////////////////////////////////////////////////////////////////
void modificar()
{ int s=0,i,t,sw_1,r,l;
  char cedula[15];

    clrscr();
    marco(2,78,1,25);
    marcar(18,18,60,22,1);
    marco(18,60,18,22);
    gotoxy(22,20);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");
    marcar(8,13,73,17,1);
    marco(8,73,13,17);
    gotoxy(15,15); printf("AL DIGITAR EL NUMERO DE TU CEDULA ANTERIOR APARECERA     ");
    gotoxy(22,16); printf("OTRA PANTALLA CON LOS DATOS A MODIFICAR. ");
    gotoxy(28,4);printf("INGRESE LOS DATOS AL REGISTRO ");

    gotoxy(20,10);printf(" DIGITE SU CEDULA    : ");scanf("\n"); gets(cedula);

    for(i=1;i<=300;i++)
    if((emp[i].cedula[0]!='\0')&&(!strcmp(cedula,emp[i].cedula)))
    { s=1; break; }
    if(s==0)
    {
     clrscr();
	 gotoxy(28,15);printf("  SU CEDULA NO EXISTE \n "); }
    else
   {
      marco(2,78,22,24);
      marcar(1,22,78,24,1);
      clrscr();
      marco(2,78,2,24);
      gotoxy(28,4);printf("  MODIFIQUE SUS DATOS ");
      gotoxy(22,23);printf("!!!!! ENTER PARA CONTINUAR !!!!! ");

      gotoxy(20,10);printf(" DIGITE LA  NUEVA CEDULA : "); scanf("\n");
      gets(emp[i].cedula);
      gotoxy(20,12);printf(" DIGITE EL NUEVO NOMBRE    : "); scanf("\n");
      gets(emp[i].nombre);
      gotoxy(20,14);printf(" DIGITE EL NUEVO APELLIDO  : ");scanf("\n");
      gets(emp[i].apellido);
      gotoxy(20,16);printf("DIGITE SU NUEVO SEXO : "); gotoxy(45,16); printf(" [0=FEM]||[1=MASC] :");
      emp[i].sexo=getchar();
      gotoxy(20,18);printf(" DIGITE EL NUEVO SUELDO    : ");
      scanf("%ld",&emp[i].sueldo);
    }
     getch();
 }

///////////////////////////////////////////////////////////////////
 void ordenar_cedula()
{
 int k,i;
  char cedula[15];
  char nombre[40];
  char apellido[40];
  char sexo;
  long int sueldo;


 clrscr();

   for (k=1;k<=t-1;k++)
      {
      for (i=1;i<=t-k;i++)
	  {
	  if (strcmp(emp[i].cedula,emp[i+1].cedula)>0)
	      {

		  strcpy(cedula,emp[i].cedula);
		  strcpy(nombre,emp[i].nombre);
		  strcpy(apellido,emp[i].apellido);
		  sexo=emp[i].sexo;
		  sueldo=emp[i].sueldo;
		  strcpy(emp[i].cedula,emp[i+1].cedula);
		  strcpy(emp[i].nombre,emp[i+1].nombre);
		  strcpy(emp[i].apellido,emp[i+1].apellido);
		  emp[i].sexo=emp[i+1].sexo;
		  emp[i].sueldo=emp[i+1].sueldo;
		  strcpy(emp[i+1].cedula,cedula);
		  strcpy(emp[i+1].nombre,nombre);
		  strcpy(emp[i+1].apellido,apellido);
		  emp[i+1].sexo=sexo;
		  emp[i+1].sueldo=sueldo;

	       }
    }
    }listg();
 }


void ordenar_nombre()

{ int k,i;

  char cedula[15];
  char nombre[40];
  char apellido[40];
  char sexo;
  long int sueldo;


   for (k=1;k<=t-1;k++)
      {
      for (i=1;i<=t-k;i++)
	  {

  if (strcmp(emp[i].nombre ,emp[i+1].nombre)>0)
	      {
		  strcpy(cedula,emp[i].cedula);
		  strcpy(nombre,emp[i].nombre);
		  strcpy(apellido,emp[i].apellido);
		  sexo=emp[i].sexo;
		  sueldo=emp[i].sueldo;
		  strcpy(emp[i].cedula,emp[i+1].cedula);
		  strcpy(emp[i].nombre,emp[i+1].nombre);
		  strcpy(emp[i].apellido,emp[i+1].apellido);
		  emp[i].sexo=emp[i+1].sexo;
		  emp[i].sueldo=emp[i+1].sueldo;
		  strcpy(emp[i+1].cedula,cedula);
		  strcpy(emp[i+1].nombre,nombre);
		  strcpy(emp[i+1].apellido,apellido);
		  emp[i+1].sexo=sexo;
		  emp[i+1].sueldo=sueldo;

	       }
	 }

   }listg();
}

void ordenar_apellido()
{  int k,i;

  char cedula[15];
  char nombre[40];
  char apellido[40];
  char sexo;
  long int sueldo;



 clrscr();
   for (k=1;k<=t-1;k++)
      {
      for (i=1;i<=t-k;i++)
	  {

  if (strcmp(emp[i].apellido ,emp[i+1].apellido)>0)
	      {
		  strcpy(cedula,emp[i].cedula);
		  strcpy(nombre,emp[i].nombre);
		  strcpy(apellido,emp[i].apellido);
		  sexo=emp[i].sexo;
		  sueldo=emp[i].sueldo;
		  strcpy(emp[i].cedula,emp[i+1].cedula);
		  strcpy(emp[i].nombre,emp[i+1].nombre);
		  strcpy(emp[i].apellido,emp[i+1].apellido);
		  emp[i].sexo=emp[i+1].sexo;
		  emp[i].sueldo=emp[i+1].sueldo;
		  strcpy(emp[i+1].cedula,cedula);
		  strcpy(emp[i+1].nombre,nombre);
		  strcpy(emp[i+1].apellido,apellido);
		  emp[i+1].sexo=sexo;
		  emp[i+1].sueldo=sueldo;

	       }
	 }
    }listg();
}


void consultar()
{

 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[12],"CONSULTAR POR CEDULA        ");
 strcpy(opciones[13],"CONSULTAR POR NOMBRE        ");
 strcpy(opciones[14],"CONSULTAR POR APELLIDO      ");
 strcpy(opciones[15],"MENU PRINCIPAL              ");
   do
 {
 textcolor(14); textbackground(1);
 clrscr();
 textcolor(14);textbackground(1);
 gotoxy(14,4); textcolor(10); textbackground(15);
 printf("M   E   N   U       C   O   S   U   L   T   A   R" );
 textcolor(14);textbackground(1);
 gotoxy(30,7); textcolor(12); textbackground(15);
 printf("REGISTRO EMPRESA");
 marcar(8,8,70,20,0);
 marco(18,52,11,18);
 marco(2,78,2,24);
 textcolor(12); textbackground(8);
 for(f=12; f<=15;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
   case 12 :consultar1(); break;

   case 13 :consultar2();break;

   case 14 :consultar3();break;

   case 15 :menu();break;



 }

}
 while(f!=15);
}


void consultar1()
{ char cedula[15];
  int sw=1;
  clrscr();
  gotoxy(5,15);printf("DIGITE LA CEDULA  A CONSULTAR :");
  scanf("\n"); gets(cedula);
  for(i=1;i<=t;i++)
  { if(strcmp(cedula,emp[i].cedula)==0)
   { clrscr();
    sw=0;
    gotoxy(10,5);printf("CEDULA   :");
    gotoxy(10,7);printf("NOMBRE   :");
    gotoxy(10,9);printf("APELLIDO :");
    gotoxy(10,11);printf("SEXO     :");
    gotoxy(10,13);printf("SUELDO   :");
    gotoxy(25,5);printf("%s",emp[i].cedula);
    gotoxy(25,7);printf("%s",emp[i].nombre);
    gotoxy(25,9);printf("%s",emp[i].apellido);
    gotoxy(25,11);printf("%s",emp[i].sexo);
    gotoxy(25,13);printf("%ld",emp[i].sueldo);
    }

    }
    if(sw==1)
    {clrscr();
     gotoxy(5,15);printf("LA CEDULA NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}


/*/******************************************************************/

void consultar2()
{ char nombre[40];
  int sw=1;
  clrscr();
  gotoxy(5,15);printf("DIGITE EL NOMBRE A CONSULTAR :");
  scanf("\n"); gets(nombre);
  for(i=1;i<=t;i++)
  { if(strcmp(nombre,emp[i].nombre)==0)
   { clrscr();
    sw=0;
    gotoxy(10,5);printf("CEDULA   :");
    gotoxy(10,7);printf("NOMBRE   :");
    gotoxy(10,9);printf("APELLIDO :");
    gotoxy(10,11);printf("SEXO     :");
    gotoxy(10,13);printf("SUELDO   :");
    gotoxy(25,5);printf("%s",emp[i].cedula);
    gotoxy(25,7);printf("%s",emp[i].nombre);
    gotoxy(25,9);printf("%s",emp[i].apellido);
    gotoxy(25,11);printf("%s",emp[i].sexo);
    gotoxy(25,13);printf("%ld",emp[i].sueldo);
    }

    }
    if(sw==1)
    {clrscr();
     gotoxy(5,15);printf("EL NOMBRE NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}

void consultar3()
{ char apellido[40];
  int sw=1;
  clrscr();
  gotoxy(5,15);printf("DIGITE EL APELLIDO A CONSULTAR :");
  scanf("\n"); gets(apellido);
  for(i=1;i<=t;i++)
  { if(strcmp(apellido,emp[i].apellido)==0)
   { clrscr();
    sw=0;
    gotoxy(10,5);printf("CEDULA   :");
    gotoxy(10,7);printf("NOMBRE   :");
    gotoxy(10,9);printf("APELLIDO :");
    gotoxy(10,11);printf("SEXO     :");
    gotoxy(10,13);printf("SUELDO   :");
    gotoxy(25,5);printf("%s",emp[i].cedula);
    gotoxy(25,7);printf("%s",emp[i].nombre);
    gotoxy(25,9);printf("%s",emp[i].apellido);
    gotoxy(25,11);printf("%s",emp[i].sexo);
    gotoxy(25,13);printf("%ld",emp[i].sueldo);
    }

    }
    if(sw==1)
    {clrscr();
     gotoxy(5,15);printf("EL APELLIDO NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}





