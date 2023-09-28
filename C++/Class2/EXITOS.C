#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include<string.h>
#include<process.h>
#include<io.h>
#include<ctype.h>
/****************************************/


/**************************************/
struct datos  
{
char nom[10];
long cod;
long sem;
char dir[8];
long tel;
}datos;

int fil,i,x,da1,dc,con,b,c;
int v[50][50];
int d[50][50];
int r[50][50];
long s;
int l,da,n,m,j,z,y,f;   
char desea;
struct datos reg1;



void cuadro();
void menu1();
void menu2();
void menu3();
void llenarm();
void visualizarm(); 
void multm(); 
void visualizartm(); 
void crear(); 
void adicionar();
void consulta();


void main()
{ 
 menu1();
 }
 

 void cuadro(int ci,int cf,int fi,int ff)
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
    gotoxy(cf,ff); printf("¼");        
    textcolor(14); textbackground(1);
   }

/*****************************MENU GENERAL************************/
void menu1()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"MATRICES        ");
 strcpy(opciones[12],"ARCHIVOS        ");
 strcpy(opciones[13],"SALIR           ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(26,6); textcolor(11); textbackground(1);
 printf(" M E N U   P R I N C I P A L  ");
 textcolor(0);textbackground(5);
 cuadro(15,65,5,15); textcolor(14); textbackground(1);

 for(f=11; f<=13;f++)
 {
   gotoxy(20,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=13)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=13;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11: menu2(); break;
 case 12: menu3(); break;
 case 13: default:  printf(" USTED HA TERMINADO ");
}
}
 while(f!=13);
}

/*-------------------------menu matrices------------------------------------*/
void menu2()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"LLENAR        ");
 strcpy(opciones[12],"VISUALIZAR1   ");
 strcpy(opciones[13],"MULTIPLICAR   ");
 strcpy(opciones[14],"VISUALIZAR2   ");
 strcpy(opciones[15],"REGRESAR      ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(24,6); textcolor(11); textbackground(1);
 printf(" M E N U   M A T R I  C E S  ");

 textcolor(0);textbackground(5);
 cuadro(19,55,9,18);
 textcolor(14); textbackground(1);

 for(f=11; f<=15;f++)
 {
   gotoxy(20,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=15)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=11)
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
 case 11: llenarm(); break;
 case 12: visualizarm(); break;
 case 13: multm(); break;
 case 14: visualizartm(); break;
 case 15: menu1();  printf(" USTED HA TERMINADO ");
}
}
 while(f!=15);
}


/*//////////////////menu archivo///////////////////////**/

void menu3()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"CREAR        ");
 strcpy(opciones[12],"ADICIONAR    ");
 strcpy(opciones[13],"CONSULTAR   ");
 strcpy(opciones[14],"REGRESAR    ");
 
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(25,6); textcolor(11); textbackground(1);
 printf(" M E N U  A R C H I V O S  ");

 textcolor(0);textbackground(5);
 cuadro(19,55,9,18);
 textcolor(14); textbackground(1);

 for(f=11; f<=14;f++)
 {
   gotoxy(20,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=14)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=11)   
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11: crear(); break;
 case 12: adicionar(); break;
 case 13: consulta(); break;
 case 14: menu1(); 
}
}
 while(f!=14);
}
//////////////////////////////////////////////////////////////////////
void llenarm()
{
clrscr();

gotoxy(10,5);printf("digite la dimencion de n:");
scanf("%d",&n);
gotoxy(10,6);printf("digite la dimencion de m:");
scanf("%d",&m);
clrscr();	    
 for(i=1;i<=n;i++)
 {  
 
  for(j=1;j<=m;j++)
  {            
   gotoxy(15,9);printf("DIGITE LOS ELEMENTOS ");
   scanf("%d",&v[i][j]);
   gotoxy(35,9);printf("        ");
     } 
 } 

 gotoxy(15,17);printf("PULSE ENTER PARA VOLVER  ");

 getche();
}

////////////////////////////////////////////////////////////////////
void visualizarm() 
{
clrscr();
  f=5;    
 for(i=1;i<=n;i++)
  {
  c=5;

 for(j=1;j<=m;j++)
  {         
   gotoxy(16+c,5+f);
   
printf("%d",v[i][j]);

printf("\n");
    c=c+4;
    }
     f=f+2;
  }  
   gotoxy(15,17);printf("PULSE ENTER PARA VOLVER  ");
 getche();

}

/////////////////////////////////////////////////////////////////
void multm() 
{

clrscr();

gotoxy(10,5);printf("digite la dimencion m1 filas");
scanf("%d",&n);
gotoxy(10,6);printf("digite la dimencion m1 colomnas");   	
scanf("%d",&m);
gotoxy(10,8);printf("digite la dimencion m2 filas");
scanf("%d",&z);
gotoxy(10,9);printf("digite la dimencion  m2 colomnas");   	
scanf("%d",&y);
   clrscr();
   for(i=1;i<=n;i++)
    {  
 
       for(j=1;j<=m;j++)
	{            
	 gotoxy(15,11);printf("LLENAR LA MATRIZ m1:");
	 scanf("%d",&v[i][j]);
	 gotoxy(35,11);printf("                    ");
	} 
     } 
     
     for(i=1;i<=z;i++)
       {  
	for(j=1;j<=y;j++)
	  {            
	    gotoxy(15,13);printf("LLENAR LA MATRIZ m2:");
	    scanf("%d",&d[i][j]);
	    gotoxy(35,13);printf("                    ");  
	  } 
       }
   clrscr();
   for (i=1;i<=n;i++)
   {
       for (j=1;j<=y;j++)
       {
	s=0;
	 for (l=1;l<=m;l++)
	 {
	   s=v[i][l]*d[l][j]+s;
	 }
	 r[i][j]=s;
	   gotoxy(15,15);printf("PULSE ENTER PARA VOLVER");
	   getche();
	   

       }

    }

  }

     
////////////////////////////////////////////////////////////////////
void visualizartm() 
{
clrscr();
  f=5;    
 for(i=1;i<=m;i++)
  {
  c=5;

 for(j=1;j<=z;j++)
  {         
   gotoxy(16+c,5+f);
   
printf("%d",r[i][j]);

printf("\n");
    c=c+4;
    }
     f=f+2;
  }  
   gotoxy(15,17);printf("PULSE ENTER PARA VOLVER  ");
 getche();


 }

//////////////////////////////////////////////////////////////////

      
void crear() 
   {
     char op;

   clrscr();
   if((da=_open("A:\datos.DAT",1))!=-1)
    {  gotoxy(15,12); printf("YA EXISTE EL ARCHIVO"); printf("\n");
       gotoxy(15,14); printf("ESPERE UN MOMENTO NO SE ASUSTE");
       for (i=1;i<=2;i++)
	{
       sound(700+i);
       delay(300);
       sound(900+i);
       delay(300);
       nosound();
	}
	_close(da);
       clrscr();
       gotoxy(20,10);  printf("DESEA CREAR UN NUEVO ARCHIVO PARA DATOS");
       textcolor(128+7); gotoxy(30,12);  cprintf("* RECUERDE * ");
       gotoxy(20,13);  printf(" LA INFORMACION ALMACENADA SE PERDERµ");
       gotoxy(20,15);  printf(" DIGITE S à N SEGéN DESEE  ");
       op=getch();
       if ((op=='s') || (op=='S'))
	  {
	    clrscr();   da=_creat("A:\DATOS.dat",0);
	    gotoxy(20,10);printf("ESPERE MIENTRAS SE CREA EL ARCHIVO ");
	    gotoxy(20,12); printf("PULSE ENTER PARA SALIR");
	    _close(da);
	  }
       }
       else
       {
       da=_creat("A:\DATOS.dat",0);
       clrscr();
       gotoxy(20,10); printf("ESPERE MIENTRAS SE CREA EL ARCHIVO");
       gotoxy(22,10); printf("PULSE ENTER PARA SALIR");
      _close(da);

       }


      getch();
    }
      

///////////////////////////////////////////////////////////////////
void adicionar()
{
  char d,desea;
  int c,b,cont;
  long cod;

  if((da=_open("A:\\datos.DAT",4))==-1)
   {
    clrscr();
    printf("ERROR DE APERTURA**"); getch();
    exit(1);
   }
/*  do
   { */
  clrscr();
  gotoxy(15,15); printf("DIGITE EL CODIGO QUE DESEA AGREGAR");
  scanf("%ld",&cod);
  c=0;
   while((b=_read(da,&datos,sizeof(datos)))!=0)
    {
      if(b!=sizeof(datos))
      {
       clrscr();
       printf("ERROR DE LECTURA");
       getch(); exit(1);
       }
   if(cod==datos.cod)
   { c=1; }

   }
   if(c==1)
    {
    clrscr();
    gotoxy(15,16); printf("EL CODIGO YA EXISTE NO SE PUEDE REPETIR");
     getche();
    }
   if(c==0)
   {

    /*RECORRO EL ARCHIVO SOCIOS HASTA EL FINAL Y CAPTURO LOS DATOS*/
    while(_read(da,&datos,sizeof(datos))!=0);

	     clrscr();
	     //cuadro(10,70,5,20);
	     gotoxy(12,8); printf("CODIGO");    gotoxy(30,8);  scanf("%ld",&datos.cod);
	     gotoxy(12,10); printf("NOMBRE");   gotoxy(30,10); scanf("\n"); gets(datos.nom);
	     gotoxy(12,12); printf("DIRECCION");gotoxy(30,12); scanf("\n"); gets(datos.dir);
	     gotoxy(12,14); printf("SEMESTRE"); gotoxy(30,14); scanf("ld",&datos.sem);
	     gotoxy(12,16); printf("TELEFONO"); gotoxy(30,16); scanf("ld",&datos.tel);
	      





	     /* LO GRABO EN EL ARCHIVO*/
	    if(((b=_write(da,&datos,sizeof(datos)))!=sizeof(datos)))
		{
		   clrscr();
		   printf("ERROR DE GRABACION ");
		   getch();
		    exit(1);
		}
	    }
       /*	    cuadro(5,75,18,21);
	    gotoxy(20,17);  printf("DESEA CONTINUAR S/N  ");
	    desea=getchar();  desea=toupper(desea);
	 } while(desea!='N');*/
  _close(da);

}/*fin agregar*/
 
 
  
//////////////////////////////////////////////////////////////////////
void consulta()
{ 
   long  cod;
 int sw=0;
 clrscr();
 cuadro(10,70,10,15);
 gotoxy(15,13);
  printf(" DIGITE EL CODIGO  A CONSULTAR : ");
 scanf("%ld",&cod);
  if((da=_open("A:\\datos.DAT",1))==-1)
     {
	clrscr();
	printf("ERROR DE APERTURA\n");
	perror("_open");getch();
	exit(1);
      }

  while((b=_read(da,&datos,sizeof(datos)))!=0)
     {
	if(b!=sizeof(datos))
	 {
	  clrscr();
	  printf("ERROR DE LECTURA DE ARCHIVO ");
	  getch();
	 }
	if((cod==datos.cod))
	  {   sw=1;
	  lseek(da,sizeof(datos),SEEK_CUR);
	  clrscr();
	  cuadro(10,65,5,21);
	  gotoxy(12,8); printf(" CODIGO ");
	  gotoxy(12,10);printf(" NOMBRE ");
	  gotoxy(12,12);printf(" DIRECCION");
	  gotoxy(12,14);printf(" SEMESTRE");
	  gotoxy(12,16);printf(" TELEFONO");
	  gotoxy(20,19); printf(" PULSE ENTER PARA SALIR ***");
	  gotoxy(12,6); printf(" SE ENCUENTRA USTED EN LA OPCION CONSULTAS ");
	  gotoxy(30,8);printf("%ld",datos.cod);
	  gotoxy(30,10);printf("%s",datos.nom);
	  gotoxy(30,12);printf("%s",datos.dir);
	  gotoxy(30,14);printf("%ld",datos.sem);
	  gotoxy(30,16);printf("%ld",datos.tel);
	  getche();
	  }
	       }
      

    if(sw==0)
    {
    clrscr();
    cuadro(10,60,10,15);
    gotoxy(11,12); printf(" EL CODIGO NO SE ENCUENTRA EN NINGUN REGISTRO ");
    gotoxy(11,13); printf(" DEL ARCHIVO  *PULSE ENTER PARA SALIR*  ");
    getch();
    }
 _close(da);

}
///////////////////////////////////////////////////////////////////////

