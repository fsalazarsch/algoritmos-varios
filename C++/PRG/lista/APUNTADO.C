 # include "stdio.h"
 # include "conio.h"
 # include "dos.h"
 #include "alloc.h"
 #define MAXIMO 100
/**********************DECLARACION DE VARIABLES**************************/
  int n,i,j,x;
  int aux;
  int *v;    //  *v[MAXIMO];
  int paola(int x, int y);
  void hilda(char m[25]);
 /****************************FUNCIONES**********************************/
 void insercion();
 void seleccion();
 void quick_sort();
 void burbuja();
 void menu_2();
 void shell_sort();
/**********************************MARCOS*********************************/
void cuadro(int x1,int x2,int y1,int y2)
{
     textcolor(12);

     for(j=x1;j<=x2;j++)
       {


       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
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
/*******************************LLENAR***********************************/
void burbuja()
{
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=paola(41,7);
   v=(int *) malloc(n);
   v=MAXIMO;
   if(n>MAXIMO)
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
      v[i]=paola(50,13);

     }
   clrscr();
   }

  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
  printf("\n\n");
  for(i=0;i<n;i++)
  {
   for(j=(i+1);j<n;j++)
    if (v[i]>v[j])
    {
      aux=v[i];
      v[i]=v[j];
       v[j]=aux;
     }
  }
       gotoxy(2,13);
       printf("VECTOR ORDENADO ");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       delay(200);
       sound((i*950)/3);
       printf("%d\t",v[i]);
       }
	nosound();
	getch();
}
/********************************MENU************************************/
void menu()
{
 char op;
 textbackground(0);
     textmode(2);
 do{

_setcursortype(_NOCURSOR);


      clrscr();
     cuadro(1,79,1,25);//PRIMER CUADRO.
     cuadro(7,73,3,23);//SEGUNDO CUADRO.
     cuadro(14,66,6,20);//TERCER CUADRO.
     textbackground(0);
     gotoxy(15,8);
     cprintf("***************************************************");
     gotoxy(15,9);
     textcolor(15);
     cprintf("       CORPORACION UNIVESITARIA DE SANTANDER       ");
     textcolor(14);
     gotoxy(15,10);
     textcolor(2);
     cprintf("***************************************************");
     textcolor(15);
     gotoxy(15,11);
     cprintf("                  MENU PRINCIPAL                   ");
     textcolor(14);
     gotoxy(15,12);
     textcolor(2);
     cprintf("***************************************************");
     textcolor(14);
    gotoxy(15,13);
    cprintf(" 1. METODOS DE ORDENAMIENTO                        ");
    gotoxy(15,14);

    cprintf(" 2. SALIR                                          ");
    gotoxy(15,16);
    textcolor(2);
    cprintf("***************************************************");
    gotoxy(15,17);
    textcolor(14);
    cprintf("                  ELIJA UNA OPCION::>              ");
    gotoxy(15,18);
    cprintf("                                                   ");
    gotoxy(53,17);
    scanf("%c",&op);
    switch(op)
    {
    case '1': textbackground(0); clrscr();

		menu_2();
		break;

    case '2': textbackground(0);clrscr();exit(0);
		break;

  }
  }while(op!=2);
  }
/*****************************MAIN*****************************************/
void main()
{
  clrscr();
  menu ();
  getche();
}
/*************************************************************************/
void menu_2()
{
 char op;
 textbackground(0);
 do{
_setcursortype(_NOCURSOR);

    clrscr();
     cuadro(1,79,1,25);//PRIMER CUADRO.
     cuadro(7,73,3,23);//SEGUNDO CUADRO.

     textbackground(0);
     gotoxy(15,7);
     cprintf("***************************************************");
     gotoxy(15,8);
     textcolor(15);
     cprintf("       CORPORACION UNIVESITARIA DE SANTANDER       ");
     textcolor(14);
     gotoxy(15,9);
     textcolor(2);
     cprintf("***************************************************");
     textcolor(15);
     gotoxy(15,10);
     cprintf("              MENU DE ORDENAMIENTOS                ");
     textcolor(14);
     gotoxy(15,11);
     textcolor(2);
     cprintf("***************************************************");
     textcolor(14);
    gotoxy(15,12);
    cprintf(" 1. BURBUJA                                        ");
    gotoxy(15,13);
    cprintf(" 2. QUICK SORT                                     ");
    gotoxy(15,14);
    cprintf(" 3. INSERCION                                      ");
    gotoxy(15,15);
    cprintf(" 4. SELECCION                                      ");
    gotoxy(15,16);
    cprintf(" 5. SHELL SORT                                     ");
    gotoxy(15,17);
    cprintf(" 6. REGRESAR AL PROGRAMA                           ");
    gotoxy(15,18);
    textcolor(2);
    cprintf("***************************************************");
    gotoxy(15,19);
    textcolor(14);
    cprintf("                  ELIJA UNA OPCION::>              ");
    gotoxy(16,20);
    cprintf("                                                   ");
    gotoxy(53,19);
    scanf("%c",&op);
    switch(op)
    {
    case '1': textbackground(0); clrscr();
		burbuja();
		break;
    case '2': textbackground(0);clrscr();
		quick_sort();
		break;
    case '3': textbackground(0);clrscr();
	       insercion();
		break;
    case '4': textbackground(0);clrscr();
		seleccion();
		break;
    case '5': textbackground(0);clrscr();shell_sort();break;
    case '6': textbackground(0);clrscr();menu();
		break;
  }
  }while(op!=6);
  }
//********************************SHELL_SORT*****************************//
   void shell_sort(){
  int j,i,n,k=0,intervalo,aux,*vec;
gotoxy(2,3);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  v=(int *)malloc(n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
   }

    printf("\n\nVECTOR NORMAL\n\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);

		     }
	intervalo=n/2;
	while(intervalo>0){
	    for(i=intervalo;i<n;i++){
	      j=i-intervalo;
	      while(j>=0){
	      k=j+intervalo;
		 if(vec[j]<=vec[k]){
		    j=0;
		      }
		   else
		   {
		   aux=vec[j];
		   vec[j]=vec[k];
		   vec[k]=aux;
		   }
		  j=j-intervalo;
		  }
		}
	      intervalo/=2;
	     }
	       printf("\n\nVECTOR ORDENADO\n\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);
		     }

     gotoxy(15,25);
     printf("­*** PULCE <<ENTER>> PARA REGREZAR ***!");
	   getch();
	   }



/******************************VALIDACIONES**********************************/

int paola(int x,int y)
{ int num,i,sw;


  char cad[20];
  _setcursortype(_SOLIDCURSOR);
  textcolor(4);
  textbackground(0);
  do
  { gotoxy(x,y); clreol();
  gotoxy(x,y);
    scanf("\n");
    gets(cad); sw=0;
    num=strlen(cad);
    for(i=0;i<num;i++)
     {
      if(!isdigit(cad[i])||(cad[i]=='¤'||cad[i]=='¥'))
      { hilda("DEBE DIGITAR UN NUMERO");
	sw=1;
       break;}}
  }while(sw==1);
   return(atoi(cad));
   }

/**********funci¢n para el mensaje de error************/
void hilda(char m[25])
{
   window(3,22,70,22);
   clrscr();textcolor(4);
   gotoxy(25,1);cprintf("%s",m);getch();
   clrscr();
   window(1,1,80,25); textcolor(4);

}
/**************************INSERCION*********************************************/
void insercion(){
   int k,sw=0;
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=paola(41,7);
   v=(int*)malloc(n);
   v=MAXIMO;
   if(n>MAXIMO)
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
      v[i]=paola(50,13);

     }
   clrscr();
   }

  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
  printf("\n\n");
for(i=1;i<=n-1;i++){
     aux=v[i];
     k=i-1;
     sw=0;
     while(!sw && k>=0){
       if(aux<v[k]){
       v[k+1]=v[k];
       k--;
       }
       else
       sw=1;
       }
       v[k+1]=aux;
       }

 printf("%s\n","VECTOR ORDENADO");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
 getch();
 }
/***********************************QUICK_SORT*************************************/
void quick_sort(){
   int sw=0,indice,tempj,tempi,x,der[MAXIMO],izq[MAXIMO];
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=paola(41,7);
   v=(int*)malloc(n);
   v=MAXIMO;
   if(n>MAXIMO)
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
      v[i]=paola(50,13);

     }
   clrscr();
   }

  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
  printf("\n\n");
   indice=1;
  izq[indice-1]=0;
  der[indice-1]=n-1;

  do{
  i=izq[indice-1];
  j=der[indice-1];
  indice--;
  tempi=i;
  tempj=j;
  x=v[(i+j)/2];
    do{
      while(x>v[i])
      i++;
      while(x<v[j])
      j--;
      if(i<j){
      aux=v[i];
      v[i]=v[j];
      v[j]=aux;
      i++;
      j--;
      }
     if(i>=j)
	sw=1;
   }while(sw!=1);
   if((tempj-(i+1))>=1){
   indice++;
   izq[indice-1]=i;
   der[indice-1]=tempj;
   }else{
   if(v[i]>v[tempj]){
      aux=v[i];
      v[i]=v[tempj];
      v[tempj]=aux;
   }
   }
  if((j-(tempi+1))>=1){
   indice++;
   izq[indice-1]=tempi;
   der[indice-1]=j;
   }else{
   if(v[tempi]>v[j]){
      aux=v[tempi];
      v[tempi]=v[j];
      v[j]=aux;
   }
   }

   }while(indice!=0);
  printf("%s\n","VECTOR ORDENADO");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
 getch();
   }
/*********************************SELECCION***************************************/
void seleccion(){
  int k;
 gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=paola(41,7);
   v=(int*)malloc(n);
   v=MAXIMO;
   if(n>MAXIMO)
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
      v[i]=paola(50,13);

     }
   clrscr();
   }
  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",v[i]);
  }
  printf("\n\n");
for (i=0;i<=n-1;i++)
{
aux= v[i];
k=i;
	for (j=i+1;j<n;j++)
	{
	if ( v[j]<aux )
	{
	aux=v[j];
	k=j;
	 }
	 }
	v[k]=v[i];
	v[i]=aux;
}
  printf("%s\n","VECTOR NORMAL");
 for(i=0;i<n;i++)
 {
    printf("%d\t",v[i]);
  }
getch();
}
