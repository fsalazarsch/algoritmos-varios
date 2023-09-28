#include"conio.h"
#include"stdio.h"
#include"dos.h"
/****************************************/


/**************************************/
struct datos  
{
char nom[10];
char cod[15];
long sem;
char dir[8];
long tel;
  }datos;
int fil,i,x,da1,dc,con,b,c;
int v[50][50];
int d[50][50];
int r[50][50];
long s;
int l,i,da,n,m,j,t,z,y,f,c;   
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
 

 void cuadro(ci,cf,fi,ff)
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
 gotoxy(30,6); textcolor(11); textbackground(1);
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
 gotoxy(30,6); textcolor(11); textbackground(1);
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
	   s=v[i][l]*d[l][j] +s;
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
    char neutro1;
      clrscr();
	neutro1='S';
	  if ((da1=_open("a:datos.dat",1))!=-1)
	    {
	    gotoxy(25,10); printf("  DESEA  CREAR UN ARCHIVO "); printf("\n");
	    gotoxy(25,14); printf("  ESPERE UN MOMENTO NO SE ASUSTE ");
	    gotoxy(25,20);printf("   DESEA ELIMINARLO (S/N)     ");
	    neutro1=toupper(getch());
	    }
	   else
	    {
	      if ((da1=_creat("a:datos.dat",0))==-1)
	       {
		gotoxy(25,18);printf(" ESTA FACTURA NO PUEDE SER CREADA  ");
		gotoxy(25,20);printf(" ACERQUESE A NUESTRAS OFICINA MAS CERCANAS  ");
		getch();exit(1);
	       }
	    }

	 if(neutro1!='N')
	   {
	    if ((da1=_creat("a:datos.dat",0))==-1)
	     {

	      gotoxy(25,18);printf(" ESTA FACTURA NO PUDO SER CREADA  ");
	      gotoxy(25,20);printf(" ACERQUESE A NUESTRA OFICINA  MAS CERCANA ");
	      getch();exit(1);
	     }
	   }
    }
      

///////////////////////////////////////////////////////////////////
void adicionar()

{char   cod[15],op;
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
	   //  marco(2,79,5,24);
	   //  marco(2,79,2,4);
	   //  marco(14,56,6,21);

              for (i=15;i<=55;i++)
               {
                for (j=7;j<=20;j++)
                 {
                 gotoxy(i,j);textbackground(15);cprintf(" ");
                  }
                     }
		 
 gotoxy(20,11); printf("DIGITE EL NOMBRE  :");scanf("\n"); gets(datos.nom);
 gotoxy(20,13); printf("DIGITE EL CODIGO:");scanf("\n");gets(datos.cod);
 gotoxy(20,15); printf("DIGITE EL DIRECCION:");scanf("\n"); gets(datos.dir);
 gotoxy(20,17); printf("DIGITE EL SEMESTRE:");scanf("%ld",&datos.sem);
 gotoxy(20,19); printf("DIGITE EL TELEFONO:");scanf("%ld",&datos.tel);


  
	 gotoxy(38,15);printf("             ");
}
     gotoxy(20,22);printf("DESEA AGREGAR OTRO REGISTRO S/N ");
	 op=toupper(getch());
    }while(op!='N');
   
   
  }
///////////////////////////////////////////////////////////////////
void consulta()
{ char cod[15];
  int sw=1;
  clrscr();

   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
 //  marco(2,79,5,24);
//   marco(2,79,2,4);
 //  marco(4,46,9,11);

          
  textcolor(15);
  gotoxy(5,10);cprintf("DIGITE EL CODIGO CONSULTAR :");
  scanf("\n"); gets(cod);
   gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");


  for(i=1;i<=t;i++)
   { if(strcmp(cod,datos.cod)==0)
   { clrscr();
   gotoxy(10,3);textcolor(252);cprintf("  R  E  G  I  S  T  R  O    C   O   N   S   U   L   T   A   R ");
  // marco(2,79,5,24);
  // marco(2,79,2,4);
 
sw=0;
    textcolor(15);
    gotoxy(10,7);cprintf("CODIGO   :");
    gotoxy(10,9);cprintf("NOMBRE   :");
    gotoxy(10,11);cprintf("DIRECCION:");
    gotoxy(10,13);cprintf("SEMESTRE:");
    gotoxy(10,15);cprintf("TELEFONO :");
    gotoxy(25,7);cprintf("%s",datos.cod);
    gotoxy(25,9);cprintf("%s",datos.nom);
    gotoxy(25,11);cprintf("%ld",datos.sem);
    gotoxy(25,13);cprintf("%s",datos.dir);
    gotoxy(25,15);cprintf("%ld",datos.tel);
    
    }
    gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

    }
    if(sw==1)
    {clrscr();
   //  marco(2,79,2,4);
    textcolor(15);
    gotoxy(8,16);cprintf("EL CODIGO NO SE ENCUENTRA EN NINGUN REGISTRO ");
     }
    getch();

}












     
	     
  
  
  












































