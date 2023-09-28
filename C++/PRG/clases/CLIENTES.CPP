#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
#define go {gotoxy(1,24);}
#define enter 13
struct cliente
{int codigo;
 char nombre[20];
 char apellido[20];
 char direccion[20];
 char telefono[10];
 };
struct  cliente agenda[50];
void boli (int f1,int f2, int col1,int col2);
void crear();
salir();
void consultar();
void modificar();
void individual();
void general();
void borrar();
void cuad(int ci,int fi,int cf,int ff);
void cuadro3(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[],char a7[],char a8[],char a9[],char a10[]);
buscar(int codi);
void validar(int fil,int col);
menu();
void pantalla(int fila, int columna);
char vec[5][13],cad[30];
char nombre,apellido,direccion,telefono,tel[10],dir[20],nom[30],ape[30];
int d,res,e,max=0,q,op,n,sto,r,x;
int i=0,j=0,g,codigo,cod,opcion,s,k=0;
char tecla;
static char MODIFICAR[5][12]={"Nombre    ","Apellido  ","Direcci¢n ","Tel‚fono  ","Salir     "};
static char CONSULTAR[3][12]={"GENERAL   ","INDIVIDUAL","SALIR     "};
int menuVertical(int col,int fi ,char v[][12], int t);

/*------------------------------------------*/
int h,h2;
int menuVertical(int col,int fi ,char v[][12], int t)
{
 int i,j=0;
  char tecla;
  do
  {
   textbackground(7);
   for(i=0;i<t;i++)
     { if (i==j)
      { textcolor(0);
	textbackground(10);
	gotoxy(col,fi+i);cprintf("%s",v[i]);
	}
      else
	{ textcolor(0);textbackground(11);
	  gotoxy(col,fi+i);cprintf("%s",v[i]);}
	  }

	 tecla=getch();
	if (tecla==80)
	{  if (j<t-1)
	    j++;
	   else
	    j=0;
	}
	 if (tecla==72)
	   { if (j!=0)
	      j--;
	     else
	      j=t-1;
	   }

  }while (tecla!=13);
  textbackground(7);return(j);
}

void main()
{ clrscr();
do{
clrscr();
cuad(1,3,80,22);
textbackground(7);
strcpy(vec[0],"   ADICION  ");
strcpy(vec[1],"MODIFICACION");
strcpy(vec[2],"  CONSULTA  ");
strcpy(vec[3],"  BORRAR    ");
strcpy(vec[4],"   SALIR    ");
opcion=menu();
    if (opcion==0)
    { crear();}
      if (opcion==1)
      {modificar();}
	if (opcion==2)
	{ do{
		 boli(4,18,20,76);
		 boli(4,10,35,47);
		 cuad(37,4,48,8);h2=menuVertical(38,5,CONSULTAR,3);//cuad(2,5,80,22);
		  if (h2== 0)
		 {boli(4,8,37,49); general();
		 }
		 if (h2==1)
		 {boli(4,8,37,49); individual();
		 }
	      }while(h2!=2);

	   }
	if(opcion==3)
	{borrar();}
}while (opcion!=4);
normvideo();
}
/*---------------------------------------------*/
void cuadro3(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[],char a7[],char a8[],char a9[], char a10[])
{
  int p;
  for(p=x1;p<=x2;p++)
  {
    gotoxy(y1,p);cprintf(a1);
    gotoxy(y2,p);cprintf(a1);
    gotoxy(9,p);cprintf(a1);
  }
  for(p=y1;p<=y2;p++)
  {
      gotoxy(p,x1);cprintf(a2);
      gotoxy(p,x2);cprintf(a2);
      gotoxy(p,21);cprintf(a2);
      gotoxy(p,3);cprintf(a2);
  }
      gotoxy(y1,x1);cprintf(a3);
      gotoxy(y2,x2);cprintf(a4);
      gotoxy(y2,x1);cprintf(a5);
      gotoxy(y1,x2);cprintf(a6);
      gotoxy(1,21);cprintf(a7);
      gotoxy(80,21);cprintf(a8);
      gotoxy(1,3);cprintf(a7);
      gotoxy(80,3);cprintf(a7);
      gotoxy(9,3);cprintf(a9);
      gotoxy(9,1);cprintf(a10);
}

/*---------------------------------------------*/
void cuad(int ci,int fi,int cf,int ff)
 {  int i;
   i=ci;
   textcolor(0);
   for (i=ci;i<=cf;i++)
   {
    gotoxy(i,fi);cprintf("Í");
    gotoxy(i,ff);cprintf("Í");
   }
   i=fi;
   for (fi=i;i<=ff;i++)
   {
     gotoxy(ci,i);cprintf("º");
     gotoxy(cf,i);cprintf("º");
   }
    gotoxy(ci,fi);cprintf("É");
    gotoxy(cf,fi);cprintf("»");
    gotoxy(ci,ff);cprintf("È");
    gotoxy(cf,ff);cprintf("¼");
 }

void pantalla (int fila, int columna)
{boli(49,5,75,9);
  textcolor(0);
 gotoxy(columna,fila);cprintf  ("C¢digo   :");
 gotoxy(columna,fila+1);cprintf("Nombre   :");
 gotoxy(columna,fila+2);cprintf("Apellido :");
 gotoxy(columna,fila+3);cprintf("Direcci¢n:");
 gotoxy(columna,fila+4);cprintf("Tel‚fono :");
}
/*---------------------------------------------*/

void crear()
{do
 { cuad(3,4,35,10);
  pantalla(5,4);
  boli(5,9,16,34);
  textcolor(15);
  gotoxy(16,5);scanf("%d",&cod);
  if (buscar(cod)==0)
  {
   validar(16,6);
   strcpy(nom,cad);
   fflush(stdin);
   validar(16,7);
   strcpy(ape,cad);
   gotoxy(16,8);gets(dir);
   gotoxy(16,9);gets(tel);
   agenda[j].codigo=cod;
   strcpy(agenda[j].nombre,nom);
   strcpy(agenda[j].apellido,ape);
   strcpy(agenda[j].direccion,dir);
   strcpy(agenda[j].telefono,tel);
  }
  else
 { boli(5,5,16,34);
   gotoxy(16,5);printf("%d",agenda[max].codigo);
   gotoxy(16,6);printf("%s",agenda[max].nombre);
   gotoxy(16,7);printf("%s",agenda[max].apellido);
   gotoxy(16,8);printf("%s",agenda[max].direccion);
   gotoxy(16,9);printf("%s",agenda[max].telefono);
   gotoxy(14,20);textcolor(0);cprintf("ESTE CODIGO YA SE ENCUENTRA << ENTER PARA CONTINUAR >>");
   getch();
   boli(20,20,14,70);
 }
  j++;
  max=0;
   gotoxy(28,20);textcolor(0);cprintf("DESEA CONTINUAR S/N [ ]");
   gotoxy(49,20);res=getch();

  res=toupper(res);

  }while (res!='N');
}

/*---------------------------------------------------*/

 menu()
{
do
 {r=2;
  textcolor(0);
  textbackground(4);
  for (i=0;i<5;i++)
   {if (i==k)
    {textcolor(0);
     textbackground(5);
     gotoxy(2+r,2);cprintf("%s",vec[i]);
     }
     else
      {textcolor(15);textbackground(3);
       gotoxy(2+r,2);cprintf("%s",vec[i]);}
       r+=15;
       textcolor(0);
       textbackground(7);
       switch(k)
       {case 0:go;gotoxy(1,24);cprintf("                      Modulo para la adici•n de clientes                      ");
	textbackground(7);	break;
	case 1:go;cprintf("                                                                   ");
	gotoxy(20,24);cprintf("Modulo para la modificaci•n de clientes");
	       break;
	case 2:go; gotoxy(20,24);cprintf("Modulo para la consulta de clientes    ");
	       break;
	case 3:go; gotoxy(20,24);cprintf("Modulo para el borrado de clientes    ");
	       break;
	case 4:go; gotoxy(20,24);cprintf("Moduo para salir de la aplicai•n       ");
	       break;
       }
      }
      tecla=getch();
       if(tecla==77)
       {if (k<4)
	 k++;
	 else
	 k=0;
       }
       if (tecla==75)
	{if (k!=0)
	 k--;
	 else
	  k=4;
	}
 }
 while (tecla!=13);
 return(k);
 }


/*---------------------------------------------*/

buscar(int codi)
{int sw=0;
  while (sw==0 && max<j)
   {if (codi==agenda[max].codigo)
     sw=1;
     else
       max++;
    }

    return(sw);

}

/*----------------------------------------------*/


void boli (int f1, int f2, int col1, int col2)
{int i, j;
 {for (i=f1;i<=f2;i++)
   for (j=col1;j<col2;j++)
    {gotoxy(j,i);cprintf(" ");
    }
  }
}

/*------------------------------------------------*/

void validar(int fil,int col)
{ int i=0;
 cad[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+i,col);res=getch();
      if ((res>='a' && res<='z')||(res>='A' && res<='Z')||(res==' '))
	{
	    cad[i++]=res;
	    gotoxy(fil-1+i,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cad[0] == ' ');
 cad[i]='\0';
 }

/*----------------------------------------------*/

void consultar()
{
 }
 void general()
 { char tecla;
 do {
   boli(23,23,5,78);
   boli(4,10,39,59);
   boli(23,23,4,78);
   boli(4,11,9,24);
   gotoxy(21,5);cprintf("codigo");
   gotoxy(35,5);cprintf("nombre");
   cuad(20,4,75,18);


   for (n=0;n<=j;n++)
  { if (x<=3)
    {gotoxy(21,x+7);printf("%d",agenda[n].codigo);
      gotoxy(37,x+7);printf("%s",agenda[n].nombre);
      x++;

     }
     else
     {gotoxy(20,22);printf("DESEA CONTINUAR S/N");
      gotoxy(40,22);sto=getch();
      if (sto=='n')
       {n=j;
       }
       else
       {getch();
	x=0;
       }
      }
      }
      gotoxy(45,20);printf("DESEA CONTINUAR S/N  ");
   gotoxy(66,20);res=getch();
  res=toupper(res);
  }while (res!='N');
  }

void individual(){
do {
   boli(4,6,35,46);
   cuad(35,4,66,10);
   pantalla(5,36);
   gotoxy(49,5);scanf("%d",&cod);

  if (buscar(cod)!=0)
  {boli(5,5,49,65);
   gotoxy(49,5);printf("%d",agenda[max].codigo);
   gotoxy(49,6);printf("%s",agenda[max].nombre);
   gotoxy(49,7);printf("%s",agenda[max].apellido);
   gotoxy(49,8);printf("%s",agenda[max].direccion);
   gotoxy(49,9);printf("%s",agenda[max].telefono);
   gotoxy(13,20);printf("ESTOS SON SUS DATOS << ENTER PARA CONTINUAR >>");
   getch();boli(20,20,10,70);
 }
   else
  {gotoxy(11,20);printf("ESTE CODIGO NO EXISTE << ENTER PARA CONTINUAR >>");
    getch();boli(20,20,7,70);
  }
  +
    max=0;

   gotoxy(30,20);printf("DESEA CONTINUAR S/N [ ]    ");
   gotoxy(66,20);res=getch();
  res=toupper(res);
  }while (res!='N');
 }
/*----------------------------------------------------*/


void borrar()
{do
 {
   boli(23,23,4,79);
   cuad(48,4,75,10);
   pantalla(5,49);
   boli(5,9,60,74);
   gotoxy(60,5);scanf("%d",&cod);
   if (buscar(cod)!=0)
    {
     boli(5,5,60,75);
     gotoxy(60,5);printf("%d",agenda[max].codigo);
     gotoxy(60,6);printf("%s",agenda[max].nombre);
     gotoxy(60,7);printf("%s",agenda[max].apellido);
     gotoxy(60,8);printf("%s",agenda[max].direccion);
     gotoxy(60,9);printf("%s",agenda[max].telefono);
     gotoxy(22,20);textcolor(0);cprintf("SON DATOS QUE DESEA BORRAR S/N [ ]");
     gotoxy(54,20);e=getch();boli(20,20,22,65);
     e=toupper(e);
     if (e=='S')
     { if (max==j-1)
       {j--;
       }
       else
       {
	  for (s=max;s<j-1;s++)
	   agenda[s]=agenda[s+1];
	   j--;
	}
	  boli(23,23,4,79);
	  gotoxy(16,20);textcolor(0);cprintf("DATOS ELIMINANDO << ENTER PARA CONTINUAR >>");
	  getch(); boli(20,20,24,79);
     }
      else
     {
       boli(23,23,4,79);
       gotoxy(10,20);textcolor(0);cprintf("ESTOS DATOS NO HAN SIDO BORRADO << ENTER PARA CONTINUAR >>");
       getch();boli(20,20,14,70);
     }
   }
  else
   {
     boli(23,23,4,79);
     gotoxy(16,20);textcolor(0);cprintf("ESTE CODIGO NO EXISTE << ENTER PARA CONTINUAR >>");
     getch();  boli(20,20,30,70);
  }
    boli(20,20,4,79);
    max=0;
    gotoxy(24,20);textcolor(0);cprintf("DESEA CONTINUAR BORRANDO S/N [ ]");
    gotoxy(54,20);res=getch(); boli(20,20,24,70);

   res=toupper(res);

  }
   while (res!='N');
}


/*------------------------------------------------------*/
void modificar()
{int cod;
 do
{boli(5,9,32,49);
 boli(4,9,52,69);
 cuad(19,11,50,17);
 pantalla(12,20);
 gotoxy(32,12);scanf("%d",&cod);
 if (buscar(cod)!=0)
 {fflush(stdin);
 do
 {gotoxy(32,13);puts (agenda[max].nombre);
  gotoxy(32,14);puts(agenda[max].apellido);
  gotoxy(32,15);puts(agenda[max].direccion);
  gotoxy(32,16);puts(agenda[max].telefono);
  cuad(19,3,30,9);
  h=menuVertical(20,4,MODIFICAR,5);
     switch(h)
     {
   {case 0:{boli(13,13,32,45);validar(32,13); strcpy(nom,cad);
   strcpy(agenda[max].nombre,nom);}break;}
   {case 1:{boli(14,14,32,49);validar(32,14); strcpy(ape,cad);
    strcpy(agenda[max].apellido,ape);}break;}
   {case 2:{boli(15,15,32,49);gotoxy(32,15);gets(dir); strcpy(agenda[max].direccion,dir);
    }break;}
   {case 3:{boli(16,16,32,49);gotoxy(32,16);gets(tel);strcpy(agenda[max].telefono,tel);
    }break;}
   }

    gotoxy(19,20);textcolor(0);printf("DESEA CONTINUAR EN EL MISMO REGISTRO  S/N");
    gotoxy(61,20);g=getch();
    g=toupper(g);
    boli(20,20,19,62);
   }while (g!='N');
  }
 else
 {
  gotoxy(13,20);printf("CODIGO NO EXISTE << Enter para continuar >>");
   getch();
   gotoxy(13,20);printf("                                           ");
  }
 gotoxy(14,20);printf("DESEA CONTINUAR EN  OTRO REGISTRO S/N [ ]");
 gotoxy(53,20);sto=getch();
  sto=toupper(sto); boli(20,20,14,54);
} while (sto!='N');
}




