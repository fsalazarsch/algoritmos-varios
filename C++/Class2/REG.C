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
  float prom;
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
void promedio();
int lee_clave();

 int i,t,k=1;


 /****************************************************************************/

int lee_clave()
{
 char tecla,cad[10];
 int  k=0,sw=0;  
 do
 {  
  k++;  
  tecla=tolower(getch());putchar('*');
  if(k==1 && tecla=='t')sw++;
  if(k==2 && tecla=='e')sw++;
  if(k==3 && tecla=='r')sw++;
  if(k==4 && tecla=='e')sw++;
  if(k==5 && tecla=='s')sw++;
  if(k==6 && tecla=='a')sw++;
  if(k==7 && tecla=='g')sw++;
 }while(k<=7 && sw<=6);
 return(sw);
}




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

void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ß");
    gotoxy(i,y2); cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("Û");
    gotoxy(x2,i); cprintf("Û");
  }

}

/**************************PINTURA******************************/
void marco2(ci,cf,fi,ff)
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


void main()
{
 char op;
 int cont;
 int u;
 cont=0;
 clrscr();
do
 { 
  textcolor(15);
  marcar(20,8,57,15,0);
  cont++;
  cuadros(20,9,57,15);
  marco(22,55,11,13);
  gotoxy(23,12);cprintf("ENTER CURRENT  PASSWORD[       ]");

   gotoxy(47,12);
  if(lee_clave()==7)
  {
   cont=7;
  }
   
   else
  {
   clrscr();

   textcolor(0);
   gotoxy(21,14);textcolor(13);cprintf("CLAVE EQUIVOCADA   ");
   gotoxy(21,15);textcolor(13);cprintf("INTENTELO DE NUEVO ");
   delay(1500);
  }
 }while(cont<3);  

menu();
getche();
}
///////////////////////////////////////////////////////////////////
void menu()
{
 int tecla,f,i,j;
 char opciones[25][45];


 strcpy(opciones[7]," LLENAR     ");
 strcpy(opciones[8]," LISTAR     ");
 strcpy(opciones[9]," ELIMINAR   ");
 strcpy(opciones[10]," MODIFICAR  ");
 strcpy(opciones[11]," ORDENAR    ");
 strcpy(opciones[12]," CONSULTAR  ");
 strcpy(opciones[13]," ADICIONAR  ");
 strcpy(opciones[14]," SALIR      ");
   do
 {
 textcolor(15); textbackground(0);
 clrscr();
  marco(2,79,2,24);
  textcolor(14); textbackground(0);
  marcar(3,3,19,5,3);
  marcar(3,16,19,23,3);
  marco2(2,20,2,24);
  marco2(21,78,3,5);
 textbackground(1);
 marco(3,19,3,5);
  marco2(3,19,6,15);

 for (i=22;i<=78;i++)
  {
   for (j=6;j<=23;j++)
   {
    gotoxy(i,j);textbackground(3);cprintf(" ");
   }
  }


 for (i=23;i<=31;i++)
  {
   for (j=7;j<=9;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

 for (i=69;i<=77;i++)
  {
   for (j=7;j<=9;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

  gotoxy(42,4);textcolor(15);cprintf(" MENU PRINCIPAL ");

 for(f=7; f<=14;f++)
 {
  gotoxy(6,f); cprintf(opciones[f]);
  }
  f=7;
  textcolor(0); textbackground(15);
  gotoxy(6,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(6,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=7;

    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(6,f);cprintf(opciones[f]);
   if(f!=7)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 7: llenar(); break;
 case 8: listar(); break;
 case 9: eliminar(); break;
 case 10: modificar(); break;
 case 11: ordenar(); break;
 case 12: consultar(); break;
 case 13: adicionar(); break;
 case 14: default: printf("FINAL");
 }

}
 while(f!=14);
}

///////////////////////////////////////////////////////////////
void llenar()
{ char op,ced[15];

     int s,l,i,sw_1,r,m,h,j;
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
             gotoxy(22,3);textcolor(252);cprintf("  L   L   E   N   A   R    D  A  T  O  S   ");
             marco(2,79,5,24);
             marco(2,79,2,4);
             marco(14,56,6,21);

              for (i=15;i<=55;i++)
               {
                for (j=7;j<=20;j++)
                 {
                 gotoxy(i,j);textbackground(3);cprintf(" ");
                  }
                     }

	       gotoxy(20,8);
	       printf("DIGITE LA CEDULA  :"); scanf("\n");gets(ced);
               strcpy(emp[t].cedula,ced);
	       gotoxy(20,10);printf("DIGITE EL NOMBRE  :");scanf("\n"); gets(emp[t].nombre);
	       gotoxy(20,12);printf("DIGITE EL APELLIDO:");scanf("\n");gets(emp[t].apellido);
	     do{
		gotoxy(38,14);printf("         ");
		gotoxy(20,14);printf("SEXO OPC[F=0][M=1]:");scanf("\n");
		emp[t].sexo=getchar();
	      }while(emp[i].sexo!='0'&& emp[i].sexo!='1');
               gotoxy(20,16); printf("DIGITE EL SUELDO:    "); scanf("%ld",&emp[t].sueldo);
	       gotoxy(25,22);textcolor(252);cprintf(" PULSE ENTER PARA CONTINUAR ");
              } getch();
       }
   }


///////////////////////////////////////////////////////////////////
void adicionar()
{char op,ced[15];
  int r,sw_1,l,j;
  do{
  clrscr();
  if(t==300)
  {clrscr();
   gotoxy(5,10); printf("NO SE PUEDE ADICIONAR EL VECTOR ESTA LLENO");

  }
   else
  { t++;

             gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    A  D  I  C  I   O   N  A   R  ");
             marco(2,79,5,24);
             marco(2,79,2,4);
             marco(14,56,6,21);

              for (i=15;i<=55;i++)
               {
                for (j=7;j<=20;j++)
                 {
                 gotoxy(i,j);textbackground(15);cprintf(" ");
                  }
                     }
          
	     
  gotoxy(20,9);printf("DIGITE SU CEDULA:  ");scanf("\n");gets(ced);

       strcpy(emp[t].cedula,ced);
       gotoxy(20,11); printf("DIGITE SU NOMBRE  :");scanf("\n"); gets(emp[t].nombre);
       gotoxy(20,13); printf("DIGITE SU APELLIDO:");scanf("\n"); gets(emp[t].apellido);
       do{
	 gotoxy(38,15);printf("             ");
	 gotoxy(20,15);printf("SEXO 0PC[F=0][M=1]:"); scanf("\n");
	 emp[i].sexo=getchar();
       }while(emp[i].sexo!='0'&& emp[i].sexo!='1');
       gotoxy(20,17); printf("DIGITE SU SUELDO  :");
       scanf("%ld",&emp[t].sueldo);
     }
      gotoxy(18,22);printf("DESEA AGREGAR OTRO REGISTRO S/N ");
      op=toupper(getch());
    }while(op!='N');


}

//////////////////////////////////////////////////////////////////
void listar()
{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11],"LISTADO FEMENINO  ");
 strcpy(opciones[12],"LISTADO MASCULINO ");
 strcpy(opciones[13],"LISTADO GENERAL   ");
 strcpy(opciones[14],"PROMEDIO          ");
 strcpy(opciones[15],"MENU PRINCIPAL    ");
do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU LISTADOS ");


 marco2(39,58,10,16);
 for(f=11; f<=15;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11: listf(); break;
 case 12: listm(); break;
 case 13: listg(); break;
 case 14: promedio(); break;
 case 15: menu ();  break;
 }

}
 while(f!=15);
}


 void promedio()
{
int conta=0,sum=0;
int prom,i=1;
 clrscr();
 marco2(2,78,2,24);

 if(t==300)
  { printf(" *** DESBORDAMIENTO  *** ");}
   else
    {

    for(i=1;i<=t;i++)
     {if(emp[i].sexo=='0')
      {
	 conta++; sum=(sum+emp[i].sueldo);
	 prom==(sum/conta);
     }
   }
      gotoxy(32,4);textcolor(15);cprintf("PROMEDIO:");
      gotoxy(41,4);printf(" %ld",emp[i].prom);

 }getch();

}

////////////////////////////////////////////////////////////////////
 void listf()
 {
  int i,cont,j;

  clrscr();


 

 for (i=3;i<=77;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(0);cprintf(" ");
   }
  }
  marco(2,79,2,24);
  marco(3,21,4,14);
  marco(22,40,4,14);
  marco(41,58,4,14);
  marco(59,78,4,14);
  delay(50);
  gotoxy(32,3);textcolor(15);cprintf(" LISTADO FEMENINO");
  delay(150);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

  gotoxy(9,5); textcolor(15);cprintf("CEDULA");
  gotoxy(28,5); textcolor(15);cprintf("NOMBRE");
  gotoxy(45,5); textcolor(15);cprintf("APELLIDO");
  gotoxy(67,5); textcolor(15);cprintf("SUELDO");

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
 {int i,cont,j;

  clrscr();
 for (i=3;i<=77;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(11);cprintf(" ");
   }
  }
  marco(2,79,2,24);
  marco(3,21,4,14);
  marco(22,40,4,14);
  marco(41,58,4,14);
  marco(59,78,4,14);
  delay(50);
  gotoxy(32,3);textcolor(15);cprintf(" LISTADO MASCULINO");
  delay(150);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

  gotoxy(9,5); textcolor(15);cprintf("CEDULA");
  gotoxy(28,5); textcolor(15);cprintf("NOMBRE");
  gotoxy(45,5); textcolor(15);cprintf("APELLIDO");
  gotoxy(67,5); textcolor(15);cprintf("SUELDO");


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
  int i,cont,j;
  clrscr();
    for (i=3;i<=77;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(5);cprintf(" ");
   }
  }
  marco(2,79,2,24);
  marco(3,21,4,14);
  marco(22,40,4,14);
  marco(41,58,4,14);
  marco(59,78,4,14);
  delay(50);
  gotoxy(32,3);textcolor(15);cprintf(" LISTADO GENERAL");
  delay(150);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

  gotoxy(9,5); textcolor(15);cprintf("CEDULA");
  gotoxy(28,5); textcolor(15);cprintf("NOMBRE");
  gotoxy(45,5); textcolor(15);cprintf("APELLIDO");
  gotoxy(67,5); textcolor(15);cprintf("SUELDO");


 
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
  

             gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    E  L  I  M  I  N  A  R ");
             marco(2,79,5,24);
             marco(2,79,2,4);
             marco(12,60,6,10);

              for (i=13;i<=59;i++)
               {
                for (j=7;j<=9;j++)
                 {
                 gotoxy(i,j);textbackground(0);cprintf(" ");
                  }
                     }
     gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");
      gotoxy(20,8);printf(" DIGITE LA CEDULA A ELIMINAR   : ");scanf("\n"); gets(cedula);

  for(i=1;i<=t;i++)
  {if(strcmp(emp[i].cedula,cedula)==0)
   { sw=0;
    for(j=i;j<=t;j++)
	{emp[j]=emp[j+1];
       }
       t--;
    marco(24,34,13,15);
    gotoxy(25,14);textcolor(15);cprintf(" EXITOS..");

     }
   }
   if(sw==1)
   { 
  delay(150);
   marco(21,47,11,13);
   gotoxy(22,12);textcolor(15);cprintf("ESTA CEDULA NO EXISTE ...");
    
   } getch();
}





void ordenar()
{

 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11],"ORDENAR POR CEDULA   ");
 strcpy(opciones[12],"ORDENAR POR NOMBRE   ");
 strcpy(opciones[13],"ORDENAR POR APELLIDO ");
 strcpy(opciones[14],"MENU PRINCIPAL       ");
   do
 {

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU ORDENAR ");

 marco2(39,61,10,15);
 for(f=11; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
   case 11 :ordenar_cedula(); break;

   case 12 :ordenar_nombre();break;

   case 13 :ordenar_apellido();break;

   case 14 :menu();break;



 }

}
 while(f!=14);
}


/////////////////////////////////////////////////////////////////////
void modificar()
{ int s=0,i,t,sw_1,r,l,j;
  char cedula[15];

    clrscr();
    gotoxy(15,3);textcolor(252);cprintf("  M   O   D   I   F   I   C   A   R       D  A  T  O  S    ");
    marco(2,79,5,24);
    marco(2,79,2,4);
    marco(19,56,8,12);
      for (i=20;i<=55;i++)
               {
                for (j=9;j<=11;j++)
                 {
                 gotoxy(i,j);textbackground(0);cprintf(" ");
                  }
                     }

    
    gotoxy(20,10);printf(" DIGITE SU CEDULA    : ");scanf("\n"); gets(cedula);
    gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

    for(i=1;i<=300;i++)
    if((emp[i].cedula[0]!='\0')&&(!strcmp(cedula,emp[i].cedula)))
    { s=1; break; }
    if(s==0)
    {
     clrscr();
    gotoxy(20,3);textcolor(252);cprintf(" ACTUALIZACION DE DATOS    ");
    marco(2,79,5,24);
    marco(2,79,2,4);
    marco(14,56,6,21);
      for (i=15;i<=55;i++)
               {
                for (j=7;j<=20;j++)
                 {
                 gotoxy(i,j);textbackground(0);cprintf(" ");
                  }
                     }

     gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

	 gotoxy(28,15);printf("  SU CEDULA NO EXISTE \n "); }
    else
   {
      clrscr();
      marco(2,78,2,24);
      gotoxy(28,4);printf("  MODIFIQUE SUS DATOS ");
      gotoxy(20,10);printf(" DIGITE LA  NUEVA CEDULA   : "); scanf("\n");
      gets(emp[i].cedula);
      gotoxy(20,12);printf(" DIGITE EL NUEVO NOMBRE    : "); scanf("\n");
      gets(emp[i].nombre);
      gotoxy(20,14);printf(" DIGITE EL NUEVO APELLIDO  : ");scanf("\n");
      gets(emp[i].apellido);
      gotoxy(20,16);printf(" DIGITE SU NUEVO SEXO : "); gotoxy(45,16); printf(" [0=FEM]||[1=MASC] :");
      emp[i].sexo=getchar();
      gotoxy(20,18);printf(" DIGITE EL NUEVO SUELDO    : ");
      scanf("%ld",&emp[i].sueldo);
      gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

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


 strcpy(opciones[11],"CONSULTAR POR CEDULA  ");
 strcpy(opciones[12],"CONSULTAR POR NOMBRE  ");
 strcpy(opciones[13],"CONSULTAR POR APELLIDO");
 strcpy(opciones[14],"MENU PRINCIPAL        ");
   do
 {

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU CONSULTAR ");


  marco2(39,62,10,15);
  for(f=11; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
   case 11 :consultar1(); break;

   case 12 :consultar2();break;

   case 13 :consultar3();break;

   case 14 :menu();break;



 }

}
 while(f!=14);
}


void consultar1()
{ char cedula[15];
  int sw=1;
  clrscr();

   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
   marco(4,46,9,11);

          
  textcolor(15);
  gotoxy(5,10);cprintf("DIGITE LA CEDULA  A CONSULTAR :");
  scanf("\n"); gets(cedula);
   gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");


  for(i=1;i<=t;i++)
   { if(strcmp(cedula,emp[i].cedula)==0)
   { clrscr();
   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
 
sw=0;
    textcolor(15);
    gotoxy(10,7);cprintf("CEDULA   :");
    gotoxy(10,9);cprintf("NOMBRE   :");
    gotoxy(10,11);cprintf("APELLIDO :");
    gotoxy(10,13);cprintf("SEXO     :");
    gotoxy(10,15);cprintf("SUELDO   :");
    gotoxy(25,7);cprintf("%s",emp[i].cedula);
    gotoxy(25,9);cprintf("%s",emp[i].nombre);
    gotoxy(25,11);cprintf("%s",emp[i].apellido);
    gotoxy(25,13);cprintf("%c",emp[i].sexo);
    gotoxy(25,15);cprintf("%ld",emp[i].sueldo);
    }
    gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

    }
    if(sw==1)
    {clrscr();
     marco(2,79,2,4);
    textcolor(15);
    gotoxy(8,16);cprintf("LA CEDULA NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}


/*/******************************************************************/

void consultar2()
{ char nombre[40];
  int sw=1;
  clrscr();
  
   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
   marco(4,46,9,11);
  textcolor(15);
  gotoxy(5,10);cprintf("DIGITE EL NOMBRE A CONSULTAR :");
  scanf("\n"); gets(nombre);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

  for(i=1;i<=t;i++)
  { if(strcmp(nombre,emp[i].nombre)==0)
   { clrscr();
   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
   
   sw=0;
   textcolor(15);
    gotoxy(10,7);cprintf("CEDULA   :");
    gotoxy(10,9);cprintf("NOMBRE   :");
    gotoxy(10,11);cprintf("APELLIDO :");
    gotoxy(10,13);cprintf("SEXO     :");
    gotoxy(10,15);cprintf("SUELDO   :");
    gotoxy(25,7);cprintf("%s",emp[i].cedula);
    gotoxy(25,9);cprintf("%s",emp[i].nombre);
    gotoxy(25,11);cprintf("%s",emp[i].apellido);
    gotoxy(25,13);cprintf("%c",emp[i].sexo);
    gotoxy(25,15);cprintf("%ld",emp[i].sueldo);
    }
     gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

    }
    if(sw==1)
    {clrscr();
     marco(2,79,2,4);
     textcolor(15);
     gotoxy(5,15);cprintf("EL NOMBRE NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}

void consultar3()
{ char apellido[40];
  int sw=1;
  clrscr();
  gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
   marco(4,46,9,11);

 textcolor(15);        
 gotoxy(5,10);cprintf("DIGITE EL APELLIDO A CONSULTAR :");
  scanf("\n"); gets(apellido);
  for(i=1;i<=t;i++)
  { if(strcmp(apellido,emp[i].apellido)==0)
   { clrscr();
    sw=0;
   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
   marco(2,79,5,24);
   marco(2,79,2,4);
    textcolor(15);
    gotoxy(10,7);cprintf("CEDULA   :");
    gotoxy(10,9);cprintf("NOMBRE   :");
    gotoxy(10,11);cprintf("APELLIDO :");
    gotoxy(10,13);cprintf("SEXO     :");
    gotoxy(10,15);cprintf("SUELDO   :");
    gotoxy(25,7);cprintf("%s",emp[i].cedula);
    gotoxy(25,9);cprintf("%s",emp[i].nombre);
    gotoxy(25,11);cprintf("%s",emp[i].apellido);
    gotoxy(25,13);cprintf("%c",emp[i].sexo);
    gotoxy(25,15);cprintf("%ld",emp[i].sueldo);
    }

    }
    if(sw==1)
    {clrscr();
      marco(2,79,2,4);
 
    textcolor(15);
     gotoxy(5,18);cprintf("EL APELLIDO NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}






