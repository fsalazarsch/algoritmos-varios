


#include<stdio.h>
#include<conio.h>
#include<string.h>

struct
  {
  char cedula[15];
  char nombre[15];
  char apellido[15];
  char sexo[15];
  long int sueldo;
  }emp[300];


void menu ();
void llenar ();
void modificar();
void eliminar();
void ordenar();
void consultar();
void listf();
void listm();
void listg();

 int k=1;
void marco(ci,cf,fi,ff)
{
 int i;
 textcolor(0);textbackground(15);
 for(i=ci;i<=cf;i++)
 {
   gotoxy(i,fi); printf("Í");
   gotoxy(i,ff); printf("Í");
  }
 for(i=fi;i<=ff;i++)
 {
   gotoxy(ci,i); printf("º");
   gotoxy(cf,i); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(1);
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

 }/*for*/

 i=20;
 gotoxy(i,19);
 for(i=20;i<=58;i++)
 {
   textcolor(YELLOW);


  cprintf("%c",177);

 }/*for*/



 for(i=6;i<=19;i++)
 {
  textcolor(YELLOW);


  cprintf("%c",177);
  gotoxy(19,i);

 }/*for*/

 for(i=6;i<=19;i++)
 {
    textcolor(YELLOW);


    cprintf("%c",177);
  gotoxy(59,i);
 }/*for*/

 }
 getch();






void main()
{
clrscr();
menu();
getche();
}
void menu()
{
char op;
  do{
clrscr();
 textbackground(9);

      cuadro1 ();
      marco(2,78,1,25);
	gotoxy(10,23); cprintf("INGENIERO DE SISTEMAS\n");
	gotoxy(50,23); cprintf("FRANCISCO CARDENAS  \n");
	gotoxy(30,2);printf(" MENU PRINCIPAL");
	gotoxy(30,9);printf("[1] LLENAR");
	gotoxy(30,10);printf("[2] MODIFICAR");
	gotoxy(30,11);printf("[3] ELIMINAR");
	gotoxy(30,12);printf("[4] CONSULTAR");
	gotoxy(30,13);printf("[5] ORDENAR");
	gotoxy(30,14);printf("[0] SALIR");
	gotoxy(24,21);printf(" DIGITE LA OPCION Y PULCE ENTER ");
	gotoxy(30,17);printf("SU OPCION [ ]");  gotoxy(41,17);printf("");
	scanf("%d",&op);


	switch(op)


  {
   case 1 :  llenar(); break;

   case 2 :modificar();break;

   case 3 :eliminar();break;

   case 4 :consultar();break;

   case 5 :ordenar();break;

   case 0 :exit(0);



  }
       }while(op!=0);
   }

 pos()
{ int i;
  for(i=0;i<300;i++)
  if(emp[i].cedula[0]=='\0') break;
  if(i==299) return -1;
  return i;
}





void llenar()
{ char ced[15],op;

   int t,p,sw,l,r,i,sw_1;
   int s=0;
   clrscr();

   marco(2,78,1,25);
     gotoxy(32,4);printf("REGISTRO LLENAR ");
     gotoxy(25,7);printf("CUANTOS REGISTROS DESEA LLENAR ");
     gotoxy(37,15);printf("No.#");scanf("%d",&t);  gotoxy(26,20);printf("PRESIONE ENTER PARA CONTINUAR ");
     sound(200);delay(500);nosound();
     getch();

   clrscr();
   marco(2,78,1,25);

     gotoxy(28,4);printf("INGRES LOS DATOS AL REGISTRO ");
     sw=pos();
     if(sw==-1)
     {
     gotoxy(30,8);printf("REGISTRO LLENO ");
     }
     else
  { gotoxy(20,10);printf(" DIGITE SU CEDULA    : ");scanf("\n");
    gets(ced);
    r=strlen(ced);
      while(r<8 || r>8)
      {
       clrscr();
       printf(" DIGITE SU CEDULA    : ");scanf("\n");
       gotoxy(26,1);clreol();gets(ced); r=strlen(ced);
       }
      do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) l=1;
	if(l==1) {clrscr();
	printf(" DIGITE SU CEDULA    : ");
	clreol(); }
    }while(l==1);

   for(i=0;i<300;i++)
     if((emp[i].cedula[0]!='\0')&&(!strcmp(ced,emp[i].cedula)))
     { s=1; break; }
     if(s==1)
     {
     gotoxy(18,14);printf("LA CEDULA YA EXISTE\n");
     }
   else
    { strcpy(emp[sw].cedula,ced);
     gotoxy(20,12);printf(" DIGITE EL NOMBRE    : ");scanf("\n"); gets(emp[sw].nombre);
     gotoxy(20,14);printf(" DIGITE EL APELLIDO  : ");scanf("\n");gets(emp[sw].apellido);
     gotoxy(20,16);printf(" DIGITE SU SEXO: [m=1,f=2]: ");scanf("\n");gets(emp[sw].sexo);
     gotoxy(20,18); printf(" DIGITE EL SUELDO  : "); scanf("%ld",&emp[sw].sueldo);

  }
}
     gotoxy(20,20);cprintf("DESEA LLENAR OTRO DATO   S/N ");
     op=toupper(getch());

  }


void consultar()
{char op;
  do{
clrscr();
 textbackground(9);

      cuadro1 ();
      marco(2,78,1,25);
	gotoxy(10,23); cprintf("INGENIERO DE SISTEMAS\n");
	gotoxy(50,23); cprintf("FRANCISCO CARDENAS  \n");
	gotoxy(30,2);printf(" MENU CONSULTAR");
	gotoxy(30,7);printf("[1] LISTADO FEMENINO");
	gotoxy(30,9);printf("[2] LISTADO MASCULINO");
	gotoxy(30,11);printf("[3] LISTADO GENERAL");
	gotoxy(30,13);printf("[4] MENU PRINCIPAL");
	gotoxy(30,15);printf("[0] SALIR");
	gotoxy(24,21);printf(" DIGITE LA OPCION Y PULCE ENTER ");
	gotoxy(30,17);printf("SU OPCION [ ]");  gotoxy(41,17);printf("");
	scanf("%d",&op);


	switch(op)


  {
   case 1 :listf(); break;

   case 2 :listm();break;

   case 3 :listg();break;

   case 4 :menu();break;

   case 0 :exit(0);

  }
       }while(op!=0);
   }



 void listf()
 {
  }

void listm()
 {
  }

void listg()
 {
  int i,t=1;
  clrscr();
  marco(2,78,1,25);
  marco(2,20,1,25);
  gotoxy(8,5); printf("CEDULA");
  marco(2,39,1,25);
  gotoxy(27,5); printf("NOMBRE");
  marco(2,59,1,25);
  gotoxy(46,5);  printf("APELLIDO");
  marco(2,78,1,25);
  gotoxy(66,5);  printf("SUELDO");

  for(i=0;i<=k;i++){

   {
     gotoxy(8,5+t);printf("%s",emp[i].cedula);
     gotoxy(27,5+t);printf("%s",emp[i].nombre);
     gotoxy(46,5+t);printf("%s",emp[i].apellido);
     gotoxy(66,5+t);printf("%ld",emp[i].sueldo);
     t++;
     getche();
   }
  }


}










void eliminar()
{int si,i;
  char op;
  char cedula[9];
  window(1,1,80,25);clrscr(); si=0;
  printf(" DIGITE SU CEDULA    : ");scanf("\n");
  gets(cedula);
  for(i=0;i<300;i++)
   if((emp[i].cedula[0]!='\0')&&(!strcmp(cedula,emp[i].cedula)))
   { si=1; break; }



  if(si==0) printf("... no existe ...\n");
    else
    { emp[i].cedula[0]='\0';
      printf("... empleado eliminado ...\n ");
    }
cprintf("Desea eliminar otro dato ");
op=toupper(getch());



}





void ordenar()
{

}
void modificar()
{
}