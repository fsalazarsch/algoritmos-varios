#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void main()
{
 
 textbackground(0);
 portada();
 menu();
}

portada()
{
 int i,j;
 clrscr();
 textcolor(12);
 for(i=2;i<=79;i++)
    {
     textcolor(12);
     gotoxy(1,1);
     cprintf("É");
     gotoxy(1,25);
     cprintf("È");
     gotoxy(i,1);
     cprintf("Í");
     gotoxy(80,1);
     cprintf("»");
     gotoxy(i,25);
     cprintf("Í");
    }
 /* gotoxy(79,25);
 cprintf("¼");    */
 for(i=2;i<=24;i++)
    {
     textcolor(12);
     
     gotoxy(1,i);
     cprintf("º");     
     textcolor(12);
     gotoxy(80,i);
     cprintf("º"); 
         
    }
 gotoxy(13,3);
 cprintf("       CORPORACION  UNIVERSITARIA  DEL  SANTANDER");
 gotoxy(20,10);
 cprintf("ANA BELYS DIAZ  MANJARREZ Cod. 96132033");
 gotoxy(30,11);
 cprintf("Ing. ALFONSO QUINTERO");
 gotoxy(25,15);
 cprintf("  MODELOS DE PROGRAMACION II");
 gotoxy(32,17);
 cprintf("Grupo: S2 - B");
 gotoxy(28,19);
 cprintf("  22 de Mayo de 1.997");
 gotoxy(23,23);
 textcolor(128+12);
 cprintf("PRESIONE UNA TECLA PARA CONTINUAR");
 getche();

}

menu()
{
 int i;
 char op;
 clrscr();
 for(i=16;i<=54;i++)
    {
     textcolor(14);
     gotoxy(15,7);
     cprintf("É");
     gotoxy(15,20);
     cprintf("È");
     gotoxy(i,7);
     cprintf("Í");
     gotoxy(55,7);
     cprintf("»");
     gotoxy(i,20);
     cprintf("Í");
    }
 gotoxy(55,20);
 cprintf("¼");    
 for(i=8;i<=19;i++)
    {
     textcolor(14);
     
     gotoxy(15,i);
     cprintf("º");     
     textcolor(14);
     gotoxy(55,i);
     cprintf("º"); 
         
    }
 gotoxy(20,8);
 cprintf("          MENU PRINCIPAL");
 gotoxy(15,9);
 cprintf("Ì");
 gotoxy(55,9);
 cprintf("¹");
 for(i=16;i<=54;i++)
    {
     gotoxy(i,9);
     cprintf("Í");
    }
 textcolor(128+15);
 gotoxy(33,11);
 cprintf("A");
 gotoxy(33,12);
 cprintf("M");
 gotoxy(33,13); 
 cprintf("E");
 gotoxy(33,14);
 cprintf("O");
 gotoxy(33,15);
 cprintf("L");
 gotoxy(33,16);
 cprintf("S");
 textcolor(14);
 gotoxy(34,11);
 cprintf("DICIONAR");
 gotoxy(34,12);
 cprintf("ODIFICAR");
 gotoxy(34,13); 
 cprintf("LIMINAR");
 gotoxy(34,14);
 cprintf("RDENAR");
 gotoxy(34,15);
 cprintf("ISTAR");
 gotoxy(34,16);
 cprintf("ALIR");
 gotoxy(30,18);
 cprintf("DIGITE OPCION:  ");
 textcolor(15);
 op = getchar();
 switch(op) {
 case 'A': adicionar();break;
// case 'M': modificar();break;
// case 'E': eliminar();break;
// case 'O': ordenar();break;
// case 'L': listar();break;
// case 'S': exit(0);
 default: gotoxy(20,18);
	  textcolor(14+128);
	  cprintf("      !! ERROR EN OPCION !!");
	  getche();
	  menu();
 }
}
 
/***************** ESTRUCTURA PRINCIPAL **********************/
struct {
 char nom[40];
 char ape[40];
 long cedula;
 int sexo;
 float sueldo;
}par[300];

int con=0,sw,j,i,lon;
char nom[40],ape[40];;
long cedula; float sueldo;
int sexo;


/********************* ADICIONAR ***************************/
adicionar()
{
  char op,suel[10],sex[2];
  char valido,ced[20];
  long auxced; 
  do
  {
    gotoxy(33,12);
    textcolor(4); 
    cprintf("É");
    for(i=34;i<=69;i++)
    {
     gotoxy(i,12);
     cprintf("Í");
     gotoxy(i,23);
     cprintf("Í");
    }
    gotoxy(70,12);
    cprintf("»");
    gotoxy(33,23);
    cprintf("È");
    for(i=13;i<=22;i++)
     {
      gotoxy(33,i);
      clreol();
      cprintf("º");
      gotoxy(70,i);
      cprintf("º");
  
    }
    gotoxy(70,23);
    cprintf("¼");
    do
     {
/*      clrscr();*/
      gotoxy(33,12);
      textcolor(4); 
      cprintf("É");
      for(i=34;i<=69;i++)
      {
       gotoxy(i,12);
       cprintf("Í");
       gotoxy(i,23);
       cprintf("Í");
      }
      gotoxy(70,12);
      cprintf("»");
      gotoxy(33,23);
      cprintf("È");
      for(i=13;i<=22;i++)
      {
       gotoxy(33,i);
       clreol();
       cprintf("º");
       gotoxy(70,i);
       cprintf("º");
      }
      gotoxy(70,23);
      cprintf("¼");
      valido='n';
      gotoxy(36,14);printf("DIGITE CEDULA:");
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
     if(par[i].cedula==auxced)
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
   par[i].cedula=auxced;
   do
   {
      valido='n';
      gotoxy(50,15);
      printf("              ");
      gotoxy(36,15);printf("DIGITE NOMBRE:");
      scanf("\n"); gets(par[i].nom);
      lon = strlen(par[i].nom);
      for(i=0;i<=lon-1; i++)
	{
	   if(!(isalpha(par[i].nom[i])))	 
	  {
	    valido='m';
	    break;
	  }
	}
       }while(valido=='m');
    do
      {
       valido='n';
       gotoxy(41,16);
       printf("             ");
       gotoxy(25,16);printf("DIGITE APELLIDO:");
       scanf("\n"); gets(par[i].ape);
       lon = strlen(par[i].ape);
       for(i=0;i<=lon-1; i++)
	{
	 if(!(isalpha(par[i].ape[i])))
	  {
	    valido='m';
	     break;
	   }
	}
       }while(valido=='m');
     gotoxy(25,16);printf("DIGITE SUELDO  :");scanf("\n");gets(suel);
    par[i].sueldo=atof(suel);
    while (par[i].sueldo==0)
     {
     gotoxy(25,16);
     clreol();
     gotoxy(25,16);
     printf("DIGITE SUELDO:");scanf("\n");gets(suel);
     par[i].sueldo=atof(suel);
     }
    gotoxy(25,17);printf("DIGITE SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
    par[con].sexo=atoi(sex);
    while ((par[i].sexo!=1)&&(par[i].sexo!=2))
    {
     gotoxy(25,17);
     clreol();
     gotoxy(25,17);
     printf("DIGITE SEXO,1:[M] 2:[F]:");scanf("\n");gets(sex);
     par[i].sexo=atoi(sex);
    }
    i++;
     
   gotoxy(25,12);printf("DESEA AGREGAR OTRO REGISTRO S/N:");
  op=toupper(getch());
}while(op!='N');

 

}		      