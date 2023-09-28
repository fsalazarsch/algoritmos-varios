#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
/********************************************************************/
#define salir '3'
#define tamano 100
/********************************************************************/
int a[tamano],j,i,num,n,m,max,aux;
/********************************************************************/
int validar(int x,int y,int ancho)
{
  int sw=0,r,n,contn,swl;
  char num[30];
  contn=0;
  do
 {
  do
 {
  sw=0;
  gotoxy(x,y);
  clreol();

  gets(num);
  r=strlen(num);
 }
  while(r<=ancho-2);
  swl=0;
  for(n=0;n<r;n++)
 {
  if(isdigit(num[n])==0)

 {
  if(num[n]=='-')
 {
  contn=contn+1;
  if(contn>1)
     swl=1;
  else
  if(contn<1)
     swl=0;
  }
  else
  swl=1;
 }
 }
  if(swl==1)
 {
   gotoxy(20,10+i);printf("ERROR INTENTELO DE NUEVO");delay(600);
    sw=1;
    gotoxy(20,10+i);clreol();
    }
    else
    if(swl==0)
     sw=0;
 }
 while(sw==1);
 return (atoi(num));
 }
//********************************************************************v
void Menu_principal();

void Ordenamiento();
void Burbuja();
void Quick_sort();
void Insercion();
void Seleccion();

void Busqueda();
void Secuencial();
void Binario();
void fondo();
void cuadro(int x1,int x2,int y1,int y2);
int validar(int x,int y,int ancho);
/********************************************************************/
void cuadro(int x1,int x2,int y1,int y2)
{
  int j,i,k;
  textcolor(15);

  for(j=x1;j<=x2;j++)
 {
   textcolor(15);
   gotoxy(j,y1);cprintf("Í");
   gotoxy(j,y2);cprintf("Í");
 }
   for(i=y1;i<=y2-1;i++)
 {
   textcolor(15);
   gotoxy(x1,i);cprintf("º");
   gotoxy(x2,i);cprintf("º");
 }
   textcolor(15);
   gotoxy(x1,y1);cprintf("É");
   gotoxy(x2,y1);cprintf("»");
   gotoxy(x1,y2);cprintf("È");
   gotoxy(x2,y2);cprintf("¼");

}
/****************************INICIALIZACON DEL PROGRAMA****************/
void Menu_principal();
/*********************************************************************/
void Menu_principal()
{
  char op;
  while(1)
 {
   clrscr();
   cuadro(2,78,2,24);
   cuadro(10,70,9,19);
   gotoxy(33,5);textcolor(15+128);cprintf ("MENU PRINCIPAL\n");
   gotoxy(16,10);textcolor(15);cprintf ("1. M E T O D O S  D E  O R D E N A M I E N T O ");
   gotoxy(16,13);textcolor(15);cprintf ("2. M E T O D O S  D E  B U S Q U E D A\n  ");
   gotoxy(45,18);textcolor(15);cprintf ("DIGITE UNA OPCION:[ ]");
   gotoxy(16,15);textcolor(14);cprintf ("3_ S A L I R\n");
   gotoxy (64,18);op=getchar();op=toupper(op);
   switch(op)
 {
   case '1':
	 Ordenamiento();
	 break;
   case '2':
	 Busqueda();
	 break;
   case  salir: exit(0);
 }
 }
}
/**************M E T O D O S  D E  O R D E N A M I E N T O*************/
void Ordenamiento()
{
  char res,op;
  res='R';
  while(res=='R')
 {
   clrscr();
    _setcursortype(_NOCURSOR);

   cuadro(20,60,6,20);
   gotoxy(33,5);textcolor(15+128);cprintf("MENU ORDENAMIENTO\n");
   gotoxy(30,8);textcolor(15);cprintf("1. BURBUJA\n");
   gotoxy(30,10);textcolor(15);cprintf("2. QUICK SORT\n ");
   gotoxy(30,12);textcolor(15);cprintf("3. INSERCION\n");
   gotoxy(30,14);textcolor(15);cprintf("4. SELECCION\n");
   gotoxy(30,16);textcolor(14);cprintf("5. R E T O R N A R\n");
   gotoxy(35,19);textcolor(15);cprintf("DIGITE UNA OPCION:[ ] ");
   gotoxy(54,19);op=getchar();
   switch(op)
 {
   case '1':Burbuja();
	    break;
   case '2':Quick_sort();
	    break;
   case '3':Insercion();
	    break;
   case '4':Seleccion();
	    break;
   case '5':
	    Menu_principal();
	    break;
 }
 }
}
/*********************** B U R B U J A *****************************/
void Burbuja()
{
  char res;
  int op,aux,cas;

  max=100;
  clrscr();
  res='S';
  while(res=='S')
 {
   clrscr();
   textcolor(15);
   gotoxy(10,4);cprintf("DIGITE LA POSICION DE NUMEROS: ");
   n=validar(47,4,2);
   if(n>0)
 {
   if(n>max)
 {
   textcolor(15);
   gotoxy(20,10);cprintf("SE DESBORDA LA POSICION DEL VECTOR");
   textcolor(15);
   gotoxy(20,14);cprintf("MODIFIQUE LA DIMENSION DEL VECTOR S/N [  ]");
   gotoxy(60,14);res=getche();res=toupper(res);
   if(res=='N')
 {
   textcolor(15);
   gotoxy(30,21);cprintf("DESEA ABANDONAR EL PROGRAMA ");
   gotoxy(38,22);cprintf(" [  ] ");
   gotoxy(40,22);op=getche();op=toupper(op);
   getch();
   if(op=='S')
      res='N';
   else
      res='S';
 }
 }
   cas=1;
}
   if(n<0)
 {
   gotoxy(20,11);printf("ERROR EN DIGITAR EL NUMERO DEBE SER POSITIVO");
   delay(1500);
   gotoxy(20,15);cprintf("MODIFIQUE LA DIMENSION DEL VECTOR S/N [  ]");
   gotoxy(60,15);res=getche();res=toupper(res);
   if(res=='N')
 {
   gotoxy(30,21);cprintf("DESEA ABANDONAR EL PROGRAMA ");
   gotoxy(38,22);cprintf(" [  ] ");
   gotoxy(40,22);op=getche();op=toupper(op);
   getch();
   if(op=='S')
      res='N';
   else
      res='S';
 }
   cas=-1;
 }
   else
   if(n<=max)
      res='N';
}//FIN DEL WHILE
   if(n<=max&&n>cas)
 {
   clrscr();
   gotoxy(30,3);printf("LLENAR EL VECTOR");
   for(i=1;i<=n;i++)
 {
   gotoxy(10,5+i);printf("EL VECTOR EN LA POS [%d] ES :",i);
   num=validar(40,5+i,2);
   a[i]=num;
 }
   gotoxy(20,23);printf("DIGITE UNA TECLA PARA CONTINUAR...");
   getch();
     for(i=1;i<=n-1;i++)
     for(j=1;j<=n-i;j++)
   if(a[j]>a[j+1])
 {
   aux=a[j];
   a[j]=a[j+1];
   a[j+1]=aux;
 }
   clrscr();
   gotoxy(30,2);printf("EL VECTOR ORDENADO");delay(500);
   for(j=1;j<=n;j++)
 {
   gotoxy(10,5+j);printf("LA POS [%d] ES: [ %d ]",j,a[j]);
   delay(300);
 }
   gotoxy(20,24);printf("DIGITE CUALQUIER TECLA");
   getch();
 }
   clrscr();
   gotoxy(10,12);printf("DIGITE UNA TECLA PARA RETORNAR AL MENU...");
   getch();
}

/****************  I N S E R C I O N  *****************************/
void Insercion()
{
  int k,op,sw=0;
//  burbuja( );
  clrscr();
  gotoxy(10,7);
  printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
  n=validar(41,7,2);
  if(n>tamano)
 {
   gotoxy(10,10);
   printf("SE DESBORDA LA POSICION DEL VECTOR\n");
   clreol();
   getch();
   return;
 }
   else
 {
   for(i=0;i<n;i++)
 {
   gotoxy(10,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
   gotoxy(49,13);printf("::>");
   a[i]=validar(50,13,2);
 }
   clrscr();
 }
   gotoxy(2,10);
   printf("%s\n","VECTOR NORMAL");
   for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
   printf("\n\n");
   for(i=1;i<=n-1;i++){
       aux=a[i];
       k=i-1;
       sw=0;
   while(!sw && k>=0){
    if(aux<a[k]){
       a[k+1]=a[k];
       k--;
 }
   else
    sw=1;
 }
   a[k+1]=aux;
 }
   printf("%s\n","VECTOR ORDENADO");
   for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
   getch();
}
/***************  Q U I C K S O R T ********************/
void Quick_sort()
{
  int sw=0,indice,tempj,tempi,x,der[tamano],izq[tamano];
  clrscr();
  gotoxy(10,7);
  printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
  n=validar(41,7,2);
  if(n>tamano)
 {
   gotoxy(10,10);
   printf("DESBORDAMIENTO LIMITE DEL VECTOR \n");
   getch();
   return;
 }
   else
 {
   for(i=0;i<n;i++)
 {
   gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
   gotoxy(49,13);printf("::>");
   a[i]=validar(50,13,2);
 }
   clrscr();
 }
   gotoxy(2,10);
   printf("%s\n","VECTOR NORMAL");
   for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
   printf("\n\n");
   indice=1;
   izq[indice-1]=0;
   der[indice-1]=n-1;

  do
 {
   i=izq[indice-1];
   j=der[indice-1];
   indice--;
   tempi=i;
   tempj=j;
   x=a[(i+j)/2];
  do
 {
   for(;x>a[i];i++)
       {;}
   for(;x<a[j];j--)
       {;}
   if(i<j){
      aux=a[i];
      a[i]=a[j];
      a[j]=aux;
      i++;
      j--;
 }
   if(i>=j)
      sw=1;
 }
   while(sw!=1);
   if((tempj-(i+1))>=1){
       indice++;
       izq[indice-1]=i;
       der[indice-1]=tempj;
 }
   else
 {
   if(a[i]>a[tempj]){
      aux=a[i];
      a[i]=a[tempj];
      a[tempj]=aux;
 }
 }
   if((j-(tempi+1))>=1){
       indice++;
       izq[indice-1]=tempi;
       der[indice-1]=j;
 }
   else
 {
   if(a[tempi]>a[j])
 {
      aux=a[tempi];
      a[tempi]=a[j];
      a[j]=aux;
 }
 }
}
   while(indice!=0);
   printf("%s\n","VECTOR ORDENADO");
   for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
 }
   getch();
}
/***************  S E L E C C I O N  *************************/
void Seleccion()
{
   int k;
   clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=validar(41,7,2);
   if(n>tamano)
  {
    gotoxy(10,10);
    printf("DESBORDAMIENTO LIMITE DEL VECTOR \n");
    getch();
    exit(0);
  }
    else
  {
    for(i=0;i<n;i++)
  {
    gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
    gotoxy(49,13);printf("::>");
    a[i]=validar(50,13,2);
  }
    clrscr();
  }
    gotoxy(2,10);
    printf("\nVECTOR NORMAL");
    for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
    printf("\n\n");
    for (i=0;i<=n-1;i++)
  {
    aux= a[i];
    k=i;
    for (j=i+1;j<n;j++)
  {
    if ( a[j]<aux )
  {
    aux=a[j];
    k=j;
  }
  }
    a[k]=a[i];
    a[i]=aux;
  }
    printf("\nVECTOR ORDENADO ");
    for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
    getch();
}
/*************************  S E C U E N C I A L *******************/
void Secuencial()
{
   int k;
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=validar(41,7,2);
   if(n>tamano)
  {
    gotoxy(10,10);
    printf("DESBORDAMIENTO LIMITE DEL VECTOR \n");
    getch();
    return;
  }
    else
  {
    for(i=0;i<n;i++)
  {
    gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
    gotoxy(49,13);printf("::>");
    a[i]=validar(50,13,2);
  }
    clrscr();
  }
    gotoxy(10,7);
    printf("%s","DIGITE EL NUMERO A BUSCAR:>");
    k=validar(41,7,2);
    i=0;
    while(a[i]!=k && i<n)
    {i++;}
    if(a[i]==k)
    printf("\n\nEl Numero Esta En El Vector");
    else
    printf("\n\nEl Numero No Esta En El Vector");
    getch();
}
/******************************  B I N A R I O *********************/
void Binario()
{
  int bajo,alto,encontrado=0,central;
  int k;
  gotoxy(10,7);
  printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
  n=validar(41,7,2);
  if(n>tamano)
 {
   gotoxy(10,10);
   printf("SE DESBORDA LA POSICION DEL VECTOR \n");
   getch();
   exit(0);
 }
   else
 {
   for(i=0;i<n;i++)
 {
   gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
   gotoxy(49,13);printf("::>");
   a[i]=validar(50,13,2);
 }
   clrscr();
 }
   for(i=0;i<n;i++)
 {
   for(j=(i+1);j<n;j++)
   if (a[i]>a[j])
 {
   aux=a[i];
   a[i]=a[j];
   a[j]=aux;
 }
 }
   gotoxy(10,7);
   printf("%s","DIGITE EL NUMERO A BUSCAR:>");
   k=validar(41,7,2);
   bajo=0;
   alto=n-1;

   while(!encontrado && bajo<=alto){
	 central=(bajo+alto)/2;
   if(a[central]==k)
      encontrado=1;
   else
    if(a[central]>k)
       alto=central-1;
   else
      bajo=central+1;
 }
   if(encontrado)
      printf("\n\nEL NUMERO ESTA EN EL VECTOR");
   else
      printf("\n\nEL NUMERO NO ESTA EN EN VECTOR");
      getch();
}

/********  M E T O D O S  D E  B U S Q U E D A ********************/
void Busqueda()
{
  char op;

 do
 {
   _setcursortype(_NOCURSOR);
   clrscr();
   cuadro(14,66,6,20);
   textcolor(15+128);
   gotoxy(32,3);cprintf("MENU DE BUSQUEDA");
   textcolor(15);gotoxy(27,10);cprintf(" 1.  S E C U E N C I A L ");
   gotoxy(27,12);cprintf(" 2.  B I N A R I A");
   textcolor(14);gotoxy(27,14);cprintf(" 3.  VOLVER AL MENU PRINCIPAL");
   gotoxy(35,19);textcolor(15);cprintf("DIGITE UNA OPCION:[ ] ");
   gotoxy(54,19);
   scanf("%c",&op);
   switch(op)
 {
   case '1': clrscr();
	     Secuencial();
	     break;
   case '2': clrscr();
	     Binario();
	     break;
   case '3': clrscr(); Menu_principal();
	     break;
 }
 }
  while(op!=3);
}
void main()
{
 clrscr();
 Menu_principal();
}
