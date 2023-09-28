#include "stdio.h"
#include "conio.h"
#include "varios.h"
#include "string.h"

struct datos
{
   char cod[10];
   char nom[30];
   char dir[40];
   float venta;
}  dat1[10],tem;
float venta2;
int numreq=1;
int reg;
int numreq2[10];
char codi;  
void menu()
  
{
  clrscr();
  pos(4,1);rayas(79,'_');
  centrar("UNIVERSIDAD ANTONIO NARIÑO",5);
  centrar("FACULTAD DE INGENIERIA DE SISTEMAS",6);
  centrar("CICLO 4",7);
  pos(8,1);rayas(79,'_');
  centrar("1. CAPTURAR",10);
  centrar("2. CONSULTAR POR REGISTRO",12);
  centrar("3. CONSULTAR POR CODIGO",14);
  centrar("4. IMPRIMIR",16);
  centrar("5. TERMINAR",18);
  centrar("6. ORDENAR",20);
  centrar("7. ORDENAR2",22);
  pos(24,1);rayas(79,'_');
  centrar("ELIJA UNA OPCION: [ ]",26);
}  
void capturar()
{
   
   while(1)
    {
     clrscr();
     int i;
     
     pos(4,4);printf("  Digite Código:");
     pos(2,34);printf("No. de Reg.", numreq);
     pos(6,4);printf("  Digite Nombre: ");
     pos(8,4);printf("  Digite Dirección: ");
     pos(10,4);printf("  Digite venta  :");
     pos(4,36);printf("%6d",numreq);
     pos(4,24);scanf("\n");gets(dat1[numreq].cod);
    
     if(dat1[numreq].cod[0]=='*')break;
     {
      pos(6,24);gets(dat1[numreq].nom);
      pos(8,24);gets(dat1[numreq].dir);
      pos(10,24);scanf("%f",&dat1[numreq].venta);
      numreq2[numreq]=numreq;
      
      numreq++;
     }
    
   }
}

void imprimir()
{
  float temp=0;
  float tem2;
  int i;
  clrscr();
  float venta2=0;
  centrar("TALLER DE PROGRAMACION", 2);
  pos(3,1);rayas(79,'=');
  pos(4,4);printf("CODIGO\n\n");
  pos(4,20);printf("NOMBRÉ\n\n");
  pos(4,50);printf("DIRECCION\n\n");
  pos(4,70);printf("VENTAS\n\n");
  pos(20,4);printf("TOTAL VENTAS");
  pos(5,1);rayas(79,'=');
  pos(25,1);rayas(79,'=');
  for (i=1;i<numreq;i++)
  {
    pos(8+i,4);puts(dat1[i].cod);
    pos(8+i,20);puts(dat1[i].nom);
    pos(8+i,50);puts(dat1[i].dir);
    pos(8+i,68);printf("%7.2f",dat1[i].venta);
    
    venta2=venta2+dat1[i].venta;
    pos(20,70);printf("%7.2f",venta2);
    
  
    if (dat1[i].venta>tem2)
    
    
     tem2=dat1[i].venta;
    //if (strcpy(dat1[i].cod,tem2);
    
  }     


  
  getch();
//  clrscr();
  pos(22,40);printf(" LA MAYOR VENTA ES DE:----.>  $ %7.2f",tem2);

  //pos(14,15);puts(tem2);
  getch();
 

}

void consultar1()
{
  int i;
  clrscr();
  pos(4,1);rayas(79,'_');                   

  centrar("UNIVERSIDAD ANTONIO NARIÑO",5);
  centrar("FACULTAD DE INGENIERIA DE SISTEMAS",6);
  centrar("CICLO 4",7);
  pos(8,1);rayas(79,'_');
  pos(28,1);rayas(79,'_');

  pos(14,10); printf("CODIGO");
  pos(14,35); printf("NOMBRE");
  pos(14,55); printf("DIRECCION");
  pos(14,70); printf("VENTA");
  pos(12,20); printf("DIGITE NUMERO DE REGISTRO (1-10)");
  scanf("%d",&reg);

  for (i=0;i<numreq;i++)
  {
     if (reg==numreq2[i])
     {
        pos(16,10); puts(dat1[i].cod);
        pos(16,35); puts(dat1[i].nom);
        pos(16,55); puts(dat1[i].dir);
        pos(16,70); printf("%7.2f",dat1[i].venta);
	getch();break;

     }
  }
          
     if (numreq2[i]!=reg)
     {
       clrscr();
       pos(20,10);printf("ESTE REGISTRO NO CORRESPONDE");
       getch();
     }
}
 

void consultar2()
{
 int i=0; char codi[10];
 clrscr();

 pos(4,1); rayas(79,'*');
 centrar("UNIVERSIDAD ANTONIO NARINO",5);
 centrar("FACULTAD DE INGENIERIA DE SISTEMAS",6);
 centrar("ciclo 4",7);
 pos(8,1); rayas(79,'*');
 pos(28,1); rayas(79,'*');

 centrar(" TALLER DE PROGRAMACION  ",9);
 pos(10,1); rayas(79,'*');
 pos(14,10); printf("CODIGO");
 pos(14,35); printf("NOMBRE");
 pos(14,55); printf("DIRECCION");
 pos(14,70); printf("VENTA");
 pos(12,20); printf("DIGITE EL CODIGO A CONSULTAR----->");
 scanf("\n"); gets(codi);

 for (i=0;i<numreq;i++)
 {
   if (strcmp(codi,dat1[i].cod)==0)
   {
     pos(16,10); puts(dat1[i].cod);
     pos(16,35); puts(dat1[i].nom);
     pos(16,55); puts(dat1[i].dir);
     pos(16,70); printf("%7.2f",dat1[i].venta);break;
   }
 }
   if (strcmp(codi,dat1[i].cod)!=0)
     {
       clrscr();
       pos(20,10);printf(" CODIGO  ERRADO ");
       
     }
getch();
}

void ordenacod()

{
 int i,j;
 for (i=0;i<numreq;i++)
 {
   for(j=i+1;j<numreq;j++)
   {
    if(strcmp(dat1[i].cod,dat1[j].cod)>0)
    {
      tem=dat1[i];
      dat1[i]=dat1[j];
      dat1[j]=tem;
    }
 } }
}

void ordenanom()
{
 
 int i,j;
 
 for (i=0;i<numreq;i++)
 {
   for(j=i+1;j<numreq;j++)
   {
    if(strcmp(dat1[i].nom,dat1[j].nom)<0)
    {
      tem=dat1[i];
      dat1[i]=dat1[j];
      dat1[j]=tem;
    }
 } }
}

void main()
{
  int i;
  clrscr();
  int op=0;
  char clave1[6];
  char clave2[]="NUEVE";
  for (i=1;i<=3;i++)
  {
    clrscr();
    pos(8,10);printf("DIGITE CLAVE DE ACCESO---->");
    pos(8,40);scanf("\n");gets(clave1);

    if (strcmp(clave1,clave2)==0)break;

    else
    {
     clrscr();
     pos(8,10) ;printf("DIGITE NUEVAMENTE  CLAVE DE ACCESO");
     pos(10,10);printf("  *** PULSE CUALQUIER TECLA ***");
     getch();
    }
    if (i==3)
    {
      clrscr();
      pos(10,10);printf("  ***  ACCESO  DENEGADO  ***");
      return;
    }
  }

    
  while(1)
  {
        
    menu();
    pos(26,48);scanf("%d",& op);
    if(op>7)
    
    {
      clrscr();
      centrar("OPCION FUERA DE RANGO",13);
      getch();
          
    }

    switch(op)
    {
     case 1: capturar();break;
     case 2: consultar1();break;
     case 3: consultar2();break;
     case 4: imprimir();break;
     case 5: 
     {
      clrscr();
      centrar("ESTE PROGRAMA HA TERMINADO.  GRACIAS!!!",10);
      centrar("REALIZADO  POR  NUBIA E. VELASQUEZ",14);
      getch();
      menu();
      return;
    case 6:  ordenacod();break;
    case 7:  ordenanom();break;

     
     }

    }
  }
}
