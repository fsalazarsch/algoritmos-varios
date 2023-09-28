#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>


struct nodo_2
{
  float nota;
  struct nodo_2 *siguiente;
}notas;
struct nodo_1
{
  char codigo[10];
  char nombre[40];
  char apellido[40];
  char sexo;
  struct nodo_2 *notas;
  struct nodo_1 *siguiente;
}alumno,*primero,*nuevo,*indice;
			   /*   inicializacion de funciones  */
int val_numeros();int val_nombres();
void menu_principal();void imprimir();
void muj_ganaron();void hom_ganaron();
void piso_color();void pro_mayor();
void perdieron_mat();void modi_notas();
void eliminar();void menu_impresion();
void adicionar();void modificar();
void exa();
void main()
{
  menu_principal();
}


void menu_principal()
{
  int op;
  clrscr();
  while (1)
  {
   clrscr();
   gotoxy(30,4);cprintf("  MENU    PRINCIPAL  ");
   gotoxy(35,6);printf("1) Adicionar alumno");
   gotoxy(35,7);printf("2) Modificar alumno");
   gotoxy(35,8);printf("3) Eliminar alumno");
   gotoxy(35,9);printf("4) Modificar notas");
   gotoxy(35,10);printf("5) Menu de impresion");
   gotoxy(35,11);printf("6) Salir del programa");
   gotoxy(35,13);printf(" Digite opcion : ");scanf("%d",&op);
   switch(op)
   {
    case 1:{
	  clrscr();
	  adicionar();
	  break;
	  }
   case 2:{
	  clrscr();
	  modificar();
	  break;
	  }
   case 3:{
	  clrscr();
	  eliminar();
	  break;
	  }
   case 4:{
	  clrscr();
	  modi_notas();
	  break;
	  }
   case 5:{
	  clrscr();
	  menu_impresion();
	  break;
	  }
   case 6:{
	  clrscr();
	  exit(0);
	  }


    }
  }
}
void menu_impresion()
{
  int op;
  int salir=0;
  while (salir!=1)
  {
    clrscr();
   gotoxy(30,4);cprintf("  MENU  DE  IMPRESION  ");
   gotoxy(35,6);printf("1) Alumnos que perdieron la materia");
   gotoxy(35,7);printf("2) Mujeres que ganaron la materia");
   gotoxy(35,8);printf("3) Hombre ganaron la materia");
   gotoxy(35,9);printf("4) Alumnos con promedio mayor que 3.5");
   gotoxy(35,10);printf("5) Listado general de alumnos");
   gotoxy(35,11);printf("6) PROMEDIO MAYOR DE LOS HOMBRES");
   gotoxy(35,12);printf("7) Volver al menu principal           ");
   gotoxy(35,14);printf(" Digite opcion : ");scanf("%d",&op);
   switch(op)
      {
  case 1:{
	  clrscr();
	  perdieron_mat();
	  break;
	  }
  case 2:{
	  clrscr();
	  muj_ganaron();
	  break;
	  }
  case 3:{
	  clrscr();
	  hom_ganaron();
	  break;
	  }
  case 4:{
	  clrscr();
	  pro_mayor();
	  break;
	  }
  case 5:{
	  clrscr();
	  imprimir();
	  break;
	  }
  case 6:{
	  clrscr();
	  exa();
	  break;
	  }
  case 7:{
	  clrscr();
	  salir=1;
	  break;
	  }


    }
  }
}



int val_nombres(char cod[50])
{ int i;int n=0;
  for (i=0;cod[i]!='\0';i++)
    if(((cod[i]>='0')&&(cod[i]<='9'))||(cod[i]=='.'))
       n=1;
  return(n);
}
int val_numeros(char cod[50])
{ int i;int n=0;
  for (i=0;cod[i]!='\0';i++)
    if(((cod[i]>='0')&&(cod[i]<='9'))||(cod[i]=='.'))
    {}
    else
       n=1;
  return(n);
}



void adicionar()
{
  char cod[10],sex,not[10],nom[40];
  float nota;
  struct nodo_1 *este=NULL;
  struct nodo_2 *ptr=NULL,*new=NULL,*esta=NULL;
  int i;
  clrscr();
  gotoxy(10,5);printf("Digite codigo : ");scanf("\n");gets(cod);
  if (val_numeros(cod)==1)
  {
    gotoxy(40,23);printf("Codigo Incorrecto");getch();return;
  }
  este=primero;
  while((strcmp(cod,este->codigo)!=0)&&(este!=NULL))
     este=este->siguiente;

  if (strcmp(cod,este->codigo)==0)
  {
    gotoxy(50,23);printf("Codigo ya existe");getch();return;
  }
  if((nuevo=malloc(sizeof(alumno)))==NULL)
  {
    gotoxy(40,23);printf("No hay memoria suficiente");getch();return;
  }
  strcpy(nuevo->codigo,cod);
  gotoxy(10,6);printf("Digite Nombres : ");scanf("\n");gets(nom);
  if (val_nombres(nom)==1)
  {
    gotoxy(40,23);printf("Nombre Incorrecto");getch();return;
  }
  strcpy(nuevo->nombre,nom);
  gotoxy(10,7);printf("Digite apellidos : ");scanf("\n");gets(nom);
  if (val_nombres(nom)==1)
  {
    gotoxy(40,23);printf("Apellidos Incorrecto");getch();return;
  }
  strcpy(nuevo->apellido,nom);
  gotoxy(10,8);printf("Digite sexo [m/f] : ");sex=getchar();
  if ((toupper(sex)!='M')&&(toupper(sex)!='F'))
  {
    gotoxy(40,23);printf("Sexo Incorrecto");getch();return;
  }
  nuevo->sexo=sex;
  for(i=0;i<4;i++)
  {
    if((new=malloc(sizeof(notas)))==NULL)
    {
      gotoxy(40,23);printf("No hay memoria suficiente");getch();return;
    }
    gotoxy(10,9+i);printf("Digite %dra nota : ",i+1);scanf("\n");gets(not);
    if(val_numeros(not)==1)
    {
      gotoxy(40,23);printf("nota Incorrecta");getch();return;
    }
    nota=atof(not);
    if ((nota<0.0)||(nota>5.0))
    {
      gotoxy(40,23);printf("nota pasada de rango");getch();return;
    }
    new->nota=nota;
    new->siguiente=NULL;
    if(ptr==NULL)
    {
      ptr=new;esta=new;
    }
    else
    {
      esta->siguiente=new;esta=new;
    }

  }
  nuevo->notas=ptr;
  nuevo->siguiente=NULL;
  if (primero==NULL)
  {
    primero=nuevo;indice=nuevo;
  }
  else
  {
    indice->siguiente=nuevo;indice=nuevo;
  }
  gotoxy(30,23);printf("Registro guardado, pulse tecla");getch();
}







void modificar()
{
  char cod[10],nom[40],sex;
  struct nodo_1 *tem=NULL;
  clrscr();
  gotoxy(10,5);printf("Digite codigo a modificar : ");scanf("\n");gets(cod);
  tem=primero;
  while((tem!=NULL)&&(strcmp(cod,tem->codigo)!=0))
     tem=tem->siguiente;
  if(strcmp(tem->codigo,cod)!=0)
  {
    gotoxy(40,23);printf("Codigo no existe");getch();return;
  }
  gotoxy(10,6);printf("Digite nuevos Nombres : ");scanf("\n");gets(nom);
  if (val_nombres(nom)==1)
  {
    gotoxy(40,23);printf("Nombre Incorrecto");getch();return;
  }
  strcpy(tem->nombre,nom);
  gotoxy(10,7);printf("Digite apellidos : ");scanf("\n");gets(nom);
  if (val_nombres(nom)==1)
  {
    gotoxy(40,23);printf("Apellidos Incorrecto");getch();return;
  }
  strcpy(tem->apellido,nom);
  gotoxy(10,8);printf("Digite sexo [m/f] : ");sex=getchar();
  if ((sex!='m')&&(sex!='f'))
  {
    gotoxy(40,23);printf("Sexo Incorrecto");getch();return;
  }
  tem->sexo=sex;
  gotoxy(30,23);printf("Registro modificado, pulse tecla");getch();
}





void eliminar()
{
  char cod[10],nom[40],sex;
  struct nodo_1 *tem=NULL,*atras=NULL;
  clrscr();
  gotoxy(10,5);printf("Digite codigo a eliminar : ");scanf("\n");gets(cod);
  tem=primero;atras=primero;
  while((tem!=NULL)&&(strcmp(cod,tem->codigo)!=0))
  {
     atras=tem;
     tem=tem->siguiente;
  }
  if(strcmp(tem->codigo,cod)!=0)
  {
    gotoxy(40,23);printf("Codigo no existe");getch();return;
  }
  if(tem==primero)
  {
    primero=tem->siguiente;
    free(tem);
    gotoxy(40,23);printf("Codigo eliminado");getch();
  }
  else
  {
    atras->siguiente=tem->siguiente;
    free(tem);
    gotoxy(40,23);
    indice=atras;
    printf("Codigo eliminado, pulse tecla");getch();
  }

}





void modi_notas()
{
  char cod[10],nom[40],sex,not[5];
  int i;float nota;
  struct nodo_2 *modi=NULL;
  struct nodo_1 *tem=NULL;
  clrscr();
  gotoxy(10,5);printf("Digite el codigo para modificar notas : ");scanf("\n");gets(cod);
  tem=primero;
  while((tem!=NULL)&&(strcmp(cod,tem->codigo)!=0))
      tem=tem->siguiente;

  if(strcmp(tem->codigo,cod)!=0)
  {
    gotoxy(40,23);printf("Codigo no existe");getch();return;
  }
  modi=tem->notas;

  for(i=0;i<4;i++)
  {
    gotoxy(10,6+i);printf("Digite %dra nota : ",i+1);scanf("\n");gets(not);
    if(val_numeros(not)==1)
    {
      gotoxy(40,23);printf("nota Incorrecta");getch();return;
    }
    nota=atof(not);
    if ((nota<0.0)||(nota>5.0))
    {
      gotoxy(40,23);printf("nota pasada de rango");getch();return;
    }
    modi->nota=nota;
    modi=modi->siguiente;
  }
  gotoxy(30,23);
  printf("Notas modificadas, pulse tecla para continuar");getch();
}






void perdieron_mat()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0,k=0;
  float suma=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");
  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    tem=ptr->notas;
    while(tem!=NULL)
    {
      suma=suma+tem->nota;
      tem=tem->siguiente;
    }
    suma=suma/4;
    if(suma<3.0)
    {
      gotoxy(4,6+j);puts(ptr->codigo);
      gotoxy(15,6+j);puts(ptr->nombre);
      gotoxy(28,6+j);puts(ptr->apellido);
      gotoxy(48,6+j);putchar(ptr->sexo);
      tem=ptr->notas;
      while(tem!=NULL)
      {
	 gotoxy(54+k,6+j);printf("%.2f  ",tem->nota);
	 tem=tem->siguiente;k=k+6;
      }
      j++;k=0;
    }
    ptr=ptr->siguiente;
    suma=0;
  }
  getch();
}





void muj_ganaron()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0,k=0;
  float suma=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");

  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    if((ptr->sexo=='F')||(ptr->sexo=='f'))
    {
       tem=ptr->notas;
       while(tem!=NULL)
       {
	 suma=suma+tem->nota;
	 tem=tem->siguiente;
       }
       suma=suma/4;
       if(suma>=3.0)
       {
	 gotoxy(4,6+j);puts(ptr->codigo);
	 gotoxy(15,6+j);puts(ptr->nombre);
	 gotoxy(28,6+j);puts(ptr->apellido);
	 gotoxy(48,6+j);putchar(ptr->sexo);
	 tem=ptr->notas;
	 while(tem!=NULL)
	 {
	    gotoxy(54+k,6+j);printf("%.2f  ",tem->nota);
	    tem=tem->siguiente;k=k+6;
	 }
	 j++;k=0;
       }
    }
    ptr=ptr->siguiente;suma=0;
  }
  getch();
}





void hom_ganaron()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0,k=0;
  float suma=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");
  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    if((ptr->sexo=='M')||(ptr->sexo=='m'))
    {
       tem=ptr->notas;
       while(tem!=NULL)
       {
	 suma=suma+tem->nota;
	 tem=tem->siguiente;
       }
       suma=suma/4;
       if(suma>=3.0)
       {
	 gotoxy(4,6+j);puts(ptr->codigo);
	 gotoxy(15,6+j);puts(ptr->nombre);
	 gotoxy(28,6+j);puts(ptr->apellido);
	 gotoxy(48,6+j);putchar(ptr->sexo);
	 tem=ptr->notas;
	 while(tem!=NULL)
	 {
	    gotoxy(54+k,6+j);printf("%.2f  ",tem->nota);
	    tem=tem->siguiente;k=k+6;
	 }
	 j++;k=0;
       }
    }
    ptr=ptr->siguiente;suma=0;
  }
  getch();
}







void pro_mayor()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0,k=0;
  float suma=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");
  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    tem=ptr->notas;
    while(tem!=NULL)
    {
      suma=suma+tem->nota;
      tem=tem->siguiente;
    }
    suma=suma/4;
    if(suma>3.5)
    {
       gotoxy(4,6+j);puts(ptr->codigo);
       gotoxy(15,6+j);puts(ptr->nombre);
       gotoxy(28,6+j);puts(ptr->apellido);
       gotoxy(48,6+j);putchar(ptr->sexo);
       tem=ptr->notas;
       while(tem!=NULL)
       {
	  gotoxy(54+k,6+j);printf("%.2f  ",tem->nota);
	  tem=tem->siguiente;k=k+6;
       }
       j++;k=0;
    }
    ptr=ptr->siguiente;suma=0;
  }
  getch();
}

void exa()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0,k=0;
  float suma=0,tempo=0,promedio=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");
  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    tem=ptr->notas;
    while(tem!=NULL)
    {
      suma=suma+tem->nota;
      tem=tem->siguiente;
    }
    suma=suma/4;
    if(suma>promedio)
    {
       tempo=promedio;
       promedio=suma;
       suma=tempo;
       gotoxy(4,6+j);puts(ptr->codigo);
       gotoxy(15,6+j);puts(ptr->nombre);
       gotoxy(28,6+j);puts(ptr->apellido);
       gotoxy(48,6+j);putchar(ptr->sexo);
       tem=ptr->notas;
       while(tem!=NULL)
       {
	  gotoxy(54+k,6+j);printf("%.2f  ",tem->nota);
	  tem=tem->siguiente;k=k+6;
       }
       j++;k=0;
    }
    ptr=ptr->siguiente;suma=0;
  }
  getch();

}


void imprimir()
{
  struct nodo_1 *ptr=NULL;
  struct nodo_2 *tem=NULL;
  int i=0,j=0;
  clrscr();
  ptr=primero;
  gotoxy(4,4);printf("Codigo");
  gotoxy(15,4);printf("Nombres");
  gotoxy(28,4);printf("Apellidos");
  gotoxy(47,4);printf("Sexo");
  gotoxy(54,4);printf("1ra");
  gotoxy(60,4);printf("2da");
  gotoxy(66,4);printf("3ra");
  gotoxy(72,4);printf("4ta");
  if(ptr==NULL)
  {
    gotoxy(50,23);printf("La lista esta vacia");getch();return;
  }
  for(i=0;ptr!=NULL;i++)
  {
    gotoxy(4,6+i);puts(ptr->codigo);
    gotoxy(15,6+i);puts(ptr->nombre);
    gotoxy(28,6+i);puts(ptr->apellido);
    gotoxy(48,6+i);putchar(ptr->sexo);
    tem=ptr->notas;
    while(tem!=NULL)
    {
      gotoxy(54+j,6+i);printf("%.2f  ",tem->nota);
      tem=tem->siguiente;j=j+6;
    }j=0;
    ptr=ptr->siguiente;
  }
  getch();
}



