#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>
#include <ctype.h>
#include <dos.h>
/******************************************************************/
void menu_orden();
void menu();
void menu_busqueda();
void burbuja();
//void presentacion();
void quickS(int li,int ls,int *a);
void quicksort();
void Secuencial();
void Binario();
void Seleccion();
void Porbase();
void cuadros(int x1, int y1, int x2, int y2);
void marco(int ci,int cf,int fi,int ff);

/*********************************************************************/
int v[20],b,n,i,j,k;
int sw_=1,sw_1=0;

/***************************************************************/
void quicksort(){
int i,m,n;
int max=100;
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENCION QUE DESEA DEL VECTOR........:");
  //m=val_int(54,3);
  scanf("%d",&m);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 quicksort();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);//scanf("%d\n",&n);
      //n=val_int(28,5);
      scanf("%d",&n);
      v[i]=n;
	  }
quickS(0,m-1,v);
clrscr();
for(i=0;i<=m-1;i++)
printf("%d\t",v[i]);
getch();

}
void quickS(int li,int ls,int *a)

{
 int i=li,j=ls,x,y;
 x=a[(li+ls)/2];
 do{
   while(a[i]<x)i++;
    while(x<a[j])j--;
    if(i<=j)
    {y=a[i];a[i]=a[j];a[j]=y;
    i++;j--;
    }
    }
   while(i<j);
    if (li<j)
     quickS(li,j,a);
    if(li<ls)
      quickS(i,ls,a);
      }
/***************************************************************/
void Secuencial(){
int i,m,n;
int max=100,sw=0;
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENSION QUE DESEA DEL VECTOR........:");
  //m=val_int(54,3);
  scanf("%d",&m);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 Secuencial();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);//scanf("%d\n",&n);
      //n=val_int(28,5);
      scanf("%d",&n);
      v[i]=n;
	  }
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE EL NUMERO  QUE DESEA BUSCAR............:");
  //n=val_int(54,3);
  scanf("%d",&n);
  i=0;
  while(i<m && !sw)
  {
  if(v[i]==n)
  sw=1;
  else
  i++;
  }
  clrscr();
  if(sw)
  printf("\nEl Numero Esta En El Vector\n");
  else
  printf("\nEl Numero No Esta En El Vector\n");
  getch();
  }
/****************************************************************/
void Binario(){
int i,m,n;
int alto,bajo,sw=0,central;
int max=100;
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENSION QUE DESEA DEL VECTOR........:");
  //m=val_int(54,3);
  scanf("%d",&m);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 Binario();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);//scanf("%d\n",&n);
      //n=val_int(28,5);
      scanf("%d",&n);
      v[i]=n;
	  }
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE EL NUMERO  QUE DESEA BUSCAR............:");
  //n=val_int(54,3);
  scanf("%d",&n);
  i=0;
quickS(0,m-1,v);
bajo=0;
alto=m-1;
while(!sw && bajo<=alto)
{
central=(bajo+alto)/2;
   if(v[central]==n)
     sw=1;
    else
      if(v[central]>n)
      alto=central-1;
      else
      bajo=central+1;
    }
   clrscr();
  if(sw)
  printf("\nEl Numero Esta En El Vector\n");
  else
  printf("\nEl Numero No Esta En El Vector\n");
  getch();
  }
/*********************************************************************/
void Seleccion(){
int i,m,n;
int max=100;
int aux,k,j;
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENSION QUE DESEA DEL VECTOR........:");
  //m=val_int(54,3);
  scanf("%d",&m);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 Seleccion();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);//scanf("%d\n",&n);
      //n=val_int(28,5);
      scanf("%d",&n);
      v[i]=n;
	  }
       for(i=0;i<m;i++){
	   aux=v[i];
	   k=i;
	   for(j=i+1;j<m;j++)
	   {
	   if(v[j]<aux){
	   aux=v[j];
	   k=j;
	   }
	   }
	   v[k]=v[i];
	   v[i]=aux;
	   }

clrscr();
for(i=0;i<=m-1;i++)
printf("%d\t",v[i]);
getch();
 }
/*******************************************************************/
void Porbase(){
int i,m,n;
int max=100;
int aux,k,j,c,u,p;
  clrscr();
  gotoxy(5,3);
  printf ("DIGITE LA DIMENSION QUE DESEA DEL VECTOR........:");
  //m=val_int(54,3);
  scanf("%d",&m);
  if(m>=max)
	 {
	 textcolor(3);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");getch();
	 Seleccion();
	 }
for(i=0;i<=m-1;i++){
 gotoxy(5,5);printf("DIGITE LA POSICION %d : ",i);//scanf("%d\n",&n);
      //n=val_int(28,5);
      scanf("%d",&n);
      v[i]=n;
	  }
for(i=1;i<m;i++)
   {
   aux=v[i];
   p=0;
   u=i-1;
   while(p<=u){
    c=(p+u)/2;
    if(aux<v[c])
    u=c-1;
    else
    p=c+1;
    }
    for(k=i-1;k>=p;k--)
    {
    v[k+1]=v[k];
    }
    v[p]=aux;
    }
clrscr();
for(i=0;i<=m-1;i++)
printf("%d\t",v[i]);
getch();
 }
/********************************/

/*************************************************************/
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


/*********************************ESTRUCTURA CUADRO*************************/

void marco(int ci,int cf,int fi,int ff)
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
 /******************************************************************/
 void main()
{
clrscr();
//presentacion();
menu();
getch();
}
/******************************************************************************/
void menu()
{
  //clrscr();
  int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[14],"METODOS DE ORDENAMIENTO    ");
 strcpy(opciones[15],"METODOS DE BURBUJA         ");
 strcpy(opciones[16],"SALIR                        ");
 do
 {
 clrscr();
 textcolor(14); textbackground(3);
 
 textcolor(14);textbackground(3);
 textcolor(14); textbackground(15);
 
 textcolor(14);textbackground(15);
 cuadros(2,2,79,24);
 marco(2,79,2,24);
 cuadros(2,2,79,8);
 marco(2,79,2,8);

textcolor(14);
delay(500);
textcolor(15);
gotoxy(16,3);cprintf("U N I V E R S I D A D    D E    S A N T A N D E R ");
delay(150);
gotoxy(30,4);cprintf("ESTRUCTURA DE DATOS");
delay(150);
gotoxy(29,5);cprintf("YELENA MOLINA LOZANO");
delay(150);
gotoxy(31,6);cprintf("CODIGO 96132041");
delay(50);
textcolor(128+15);
gotoxy(26,23);cprintf(" PRESIONE CUALQUIER TECLA...");
gotoxy(21,22);printf(" PRESENTADO AL ING. ROBERTO FERNANDEZ..");

textcolor(14);textbackground(3);

 textcolor(14); textbackground(1);
 //marcar(2,2,78,24,1);
 gotoxy(22,10); textcolor(14); textbackground(0);
 cprintf("M E N U  P R I N C I P A L   ");
 textcolor(14);textbackground(0);
 gotoxy(30,7); textcolor(14); textbackground(0);
 marco(18,52,11,20); //18,52
 //marco(2,78,2,24);
 textcolor(11); textbackground(1);
 for(f=14; f<=16;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=14;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
   textcolor(14); textbackground(1);
 //presentacion();
 do
 {
  do
  { tecla=getch(); }

     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {

     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);

     if(f!=16)
     f=f+1;
     else

    f=14;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {

   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=14)
   f=f-1;
   else

    f=16;
    textcolor(0); textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 14:menu_orden();break;
 case 15:menu_busqueda();break;
 case 16: break;
 }

}
 while(f!=16);
}


/**************************************************************************/
void menu_orden()
{


 int tecla,f,i;
 char opciones[25][45];

 strcpy(opciones[14],"BURBUJA            ");
 strcpy(opciones[15],"METODO DE INSERCION");
 strcpy(opciones[16],"QUICK SORT         ");
 strcpy(opciones[17],"METODO DE SHELL    ");
 strcpy(opciones[18],"RETORNAR    ");
 do
 {

 textcolor(14); textbackground(3);
 clrscr();
 gotoxy(30,7); textcolor(14); textbackground(1);
 //marcar(2,2,78,24,1);
 gotoxy(12,4); textcolor(14); textbackground(4);
 cprintf("M E T O D O  D E   O R D E N A M I E N T O      ");
 marco(18,52,11,20);
 marco(2,78,2,24);
 
 //marco(18,52,11,20);
 textcolor(11); textbackground(1);
 for(f=14; f<=18;f++)
 {
  gotoxy(25,f); cprintf(opciones[f]);
  }
  f=14;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(25,f);cprintf(opciones[f]);
     if(f!=18)
     f=f+1;
     else

    f=14;


    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=14)
   f=f-1;
   else

    f=18;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 14: burbuja(); break;
 case 15: quicksort(); break;
 //case 16: chell();break;
 case 17: Seleccion(); break;
 case 18:break;


 }

}
 while(f!=18);

 }
/***********************************************************/
void burbuja()
{
int max=100;
char res;
int op,aux,cas,sw=0,temp;
char opcion=' ';
textcolor(0);
textbackground(3);
do{
clrscr();
gotoxy(5,3);
//textcolor(0);
//textbackground(7);
printf ("DIGITE LA DIMENCION QUE DESEA DEL VECTOR........:");
//n=val_int(54,3);
for(i=1;i<=n;i++){
   if(n<0)
	{
	 gotoxy(6,20);printf("ERROR DIGITE EN LA DIMENSION SOLO NUMERO POSITIVO ");
	 //delay(1500);
		 }

   if(n>max)
	 {

	 textcolor(124+4);
	 gotoxy(15,20);cprintf("DESBORDAMIENTO DEL VECTOR");delay(800);
	 textcolor(4);
	 gotoxy(15,17);cprintf("ESCRIBA UN RANGO DEL [1-99] ");
	 //sonido();
	 burbuja();

	 }
	  



  gotoxy(5,5); printf("IMPRIMA EL VECTOR [%d]......:",i);
  //v[i]=val_int(34,5);
  }
  gotoxy(5,7);printf("VECTOR DESORDENADO\n");
for(i=1;i<=n;i++)
{
gotoxy(5+i*6,8);  printf("[%d]", v[i]);

  }
  //getch();

  for(i=1;i<=n-1;i++)
  {
   for(j=1;j<=n-i;j++)
    {
    if (v[j] > v[j+1])
    {
     temp=v[j];
     v[j]=v[j+1];
     v[j+1]=temp;
    }
  }
   }
gotoxy(5,12);printf("VECTOR ORDENADO");
for(i=1;i<=n;i++)
{

  gotoxy(34,12+i);printf("[%d]", v[i]);
  delay(500);
}




   gotoxy(20,22);
   cprintf("Desea Continuar Con El Metodo Burbuja S/N::>");
   do{
   opcion=toupper(getch());
    if(opcion=='N'||opcion=='S'){
      sw=1;
      putchar(opcion);
      delay(300);
      }
      else
      sw=0;
      }while(sw!=1);
   } while(opcion!='N');
 }	
 


   

void menu_busqueda()
{
int tecla,f,i;
 char opciones[25][45];
	 strcpy(opciones[14],"BUSQUEDA BINARIA    ");
	 strcpy(opciones[15],"BUSQUEDA SECUENCIAL ");
	 
	 
 do      
 {

 textcolor(14); textbackground(3);

 clrscr();

 printf("M E T O D O  D E   B U S Q U E D A      ");
 gotoxy(30,7); textcolor(14); textbackground(1);

 //marcar(2,2,78,24,1);

 gotoxy(14,4); textcolor(14); textbackground(4);


 marco(18,52,11,20);
 marco(2,78,2,24);
 textcolor(11); textbackground(1);
 for(f=14; f<=15;f++)
 {
  gotoxy(25,f); cprintf(opciones[f]);
  }
  f=14;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(25,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=14;

    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=14)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 14: Binario(); break;
 case 15: Secuencial(); break;

 }

}
 while(f!=15);
}




