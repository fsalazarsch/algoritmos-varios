#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
#define go {gotoxy(1,24);}
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
void modificar();
void consult();
void borrar();
buscar(int codi);
void validar(int fil,int col);
menu();
void pantalla(int fila, int columna);
char vec[5][13],cad[30];
char nombre,apellido,direccion,telefono,tel[10],dir[20],nom[30],ape[30];
int res,l=0,preg,op,n,k,r,x,opc,pg;
int i=0,j=0,codigo,cod,opcion,s,o=0;
char tecla;
void cuadro(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[]);
void lineav(int x1,int y1,int x2,char a1[],char a9[],char a10[]);
void lineah(int y1,int x1,int y2,char a2[],char a7[],char a8[]);
char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È",a7[]="Ì",a8[]="¹",a9[]="Ê",a10[]="Ë";
void main()
{
do{
clrscr();
cuadro(1,1,24,80,a1,a2,a3,a4,a5,a6);
lineah(1,3,80,a2,a7,a8);
lineah(1,22,80,a2,a7,a8);
strcpy(vec[0],"   ADICION  ");
strcpy(vec[1],"MODIFICACION");
strcpy(vec[2],"  CONSULTA  ");
strcpy(vec[3],"  BORRADO   ");
strcpy(vec[4],"   SALIR    ");
opcion=menu();
  if (opcion==0)
     crear();
     if (opcion==1)
       modificar();
     if (opcion==2)
       consult();
       if (opcion==3)
	 borrar();

}while (opcion!=4);
}




void pantalla (int fila, int columna)
{gotoxy(columna,fila);printf  ("CODIGO.....");
 gotoxy(columna,fila+1);printf("NOMBRE.....");
 gotoxy(columna,fila+2);printf("APELLIDO...");
 gotoxy(columna,fila+3);printf("DIRECCION..");
 gotoxy(columna,fila+4);printf("TELEFONO...");
}




void crear()
{
 do
 { cuadro(4,3,10,35,a1,a2,a3,a4,a5,a6);
  pantalla(5,4);
  boli(23,23,4,74);
  boli(23,23,4,68);
  boli(5,9,16,34);
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
   gotoxy(16,5);printf("%d",agenda[k].codigo);
   gotoxy(16,6);printf("%s",agenda[k].nombre);
   gotoxy(16,7);printf("%s",agenda[k].apellido);
   gotoxy(16,8);printf("%s",agenda[k].direccion);
   gotoxy(16,9);printf("%s",agenda[k].telefono);
   gotoxy(4,23);printf("ESTE CODIGO YA EXISTE");
   getch();
 }
  j++;
  k=0;
   gotoxy(4,23);printf("DESEA CONTINUAR  S/N [ ]    ");
   gotoxy(26,23);res=getch();

  res=toupper(res);

  }while (res!='N');
}




menu()
{do
 {r=2;
  textbackground(0);
  for (i=0;i<5;i++)
   {if (i==o)
    {textcolor(1);
     textbackground(7);
     gotoxy(2+r,2);cprintf("%s",vec[i]);
     }
     else
      {textcolor(0);textbackground(11);
       gotoxy(2+r,2);cprintf("%s",vec[i]);}
       r+=15;
       textcolor(0);
       textbackground(11);
       switch(o)
       {
	case 0:go;gotoxy(5,21);cprintf("MODULO PARA LA ADICCION DE CLIENTES    ");
	       break;
	case 1:go; gotoxy(5,21);cprintf("MODULO PARA LA MODIFICACION DE CLIENTES");
	       break;
	case 2:go; gotoxy(5,21);cprintf("MODULO PARA LA CONSULTA DE CLIENTES    ");
	       break;
	case 3:go; gotoxy(5,21);cprintf("MODULO PARA EL BORRADO DE CLIENTES    ");
	       break;
	case 4:go; gotoxy(5,21);cprintf("MODULO PARA SALIR DEL SISTEMA       ");
	       break;
       }
      }
      tecla=getch();
       if(tecla==77)
       {if (o<4)
	 o++;
	 else
	 o=0;
       }
       if (tecla==75)
	{if (o!=0)
	 o--;
	 else
	  o=4;
	}
 }
 while (tecla!=13);
 return(o);
 }



buscar(int cod)
{
 int sw=0;
     k=0;
  while ((sw==0) && (k<j))
   {if (cod==agenda[k].codigo)
     sw=1;
     else
       k++;
    }
    return(sw);
}
void cuadro(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[])
{ int p;
  for(p=x1;p<=x2;p++)
  {
    gotoxy(y1,p);cprintf(a1);
     gotoxy(y2,p);cprintf(a1);
  }
  for(p=y1;p<=y2;p++)
  {
      gotoxy(p,x1);cprintf(a2);
      gotoxy(p,x2);cprintf(a2);
   }
      gotoxy(y1,x1);cprintf(a3);
      gotoxy(y2,x2);cprintf(a4);
      gotoxy(y2,x1);cprintf(a5);
      gotoxy(y1,x2);cprintf(a6);

}

void lineav(int x1,int y1,int x2,char a1[],char a9[],char a10[])
{ int p;
  for(p=x1;p<=x2;p++)
  {
    gotoxy(y1,p);cprintf(a1);

  }
    gotoxy(y1,x1);printf(a10);
    gotoxy(y1,x2);printf(a9);
}
void lineah(int y1,int x1,int y2,char a2[],char a7[],char a8[])
{ int p;
  for(p=y1;p<=y2;p++)
  {
    gotoxy(p,x1);cprintf(a2);

  }
    gotoxy(y1,x1);printf(a7);
    gotoxy(y2,x1);printf(a8);
}


void boli (int f1, int f2, int col1, int col2)
{int i, j;
 {for (i=f1;i<=f2;i++)
   for (j=col1;j<col2;j++)
    {gotoxy(j,i);cprintf(" ");
    }
  }
}



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



void consult()
{
do
{boli(23,23,4,78);
 boli(4,18,20,76);
 cuadro(4,9,11,23,a1,a2,a3,a4,a5,a6);
 lineah(9,7,23,a2,a7,a8);
 gotoxy(4,23);printf("DIGITE LA OBCION     [ ]");
 gotoxy(12,6);printf("CONSULTA");
 gotoxy(10,8);printf("1.GLOBAL");
 gotoxy(10,9);printf("2.INDIVIDUAL");
 gotoxy(10,10);printf("3.SALIR");
 gotoxy(26,23);op=getch();
 boli(23,23,4,78);
 boli(4,11,9,24);
 if (op=='1')
 {gotoxy(21,5);printf("CODIGO");
  gotoxy(28,5);printf("NOMBRE");
  cuadro(4,20,18,75,a1,a2,a3,a4,a5,a6);
  lineah(20,16,75,a2,a7,a8);
  lineah(20,6,75,a2,a7,a8);
  lineav(4,27,16,a1,a9,a10);
  for (n=0;n<=j;n++)
  {
    if (x<=3)
    {gotoxy(21,x+7);printf("%d",agenda[n].codigo);
      gotoxy(28,x+7);printf("%s",agenda[n].nombre);
	   x++;
     }
     else
     {gotoxy(23,17);printf("DESEA CONTINUAR S/N [ ]");
      gotoxy(26,17);preg=getch();
      if (preg=='n')
       {n=j;
       }
       else
       {
	x=0;
       }
      }
     }
   boli(17,17,23,74);
   gotoxy(23,17);printf("ESTOS SON TODOS LOS DATOS");
   getch();
  }

if (op=='2')
{do
 {
   boli(5,9,49,65);
   boli(23,23,4,78);
   cuadro(4,35,10,66,a1,a2,a3,a4,a5,a6);
   pantalla(5,36);
   gotoxy(49,5);scanf("%d",&cod);
  if (buscar(cod)!=0)
  { boli(5,9,49,65);
   gotoxy(49,5);printf("%d",agenda[l].codigo);
   gotoxy(49,6);printf("%s",agenda[l].nombre);
   gotoxy(49,7);printf("%s",agenda[l].apellido);
   gotoxy(49,8);printf("%s",agenda[l].direccion);
   gotoxy(49,9);printf("%s",agenda[l].telefono);
   gotoxy(4,23);printf("ESTOS SON LOS DATOS CONSULTADOS      ");
   getch();
 }
   else
  {gotoxy(4,23);printf("ESTE CODIGO NO EXISTE");
    getch();
  }
    l=0;
   boli(23,23,4,78);
   gotoxy(4,23);printf("DESEA CONTINUAR  S/N [ ]    ");
   gotoxy(26,23);res=getch();
   boli(23,23,4,78);
  res=toupper(res);
 }while (res!='N');
 }
 } while (op!='3');
 }



void borrar()
{
do
 {
  boli(6,20,2,78);
  cuadro(4,48,10,75,a1,a2,a3,a4,a5,a6);
  pantalla(5,49);
  boli(5,9,60,74);
  gotoxy(60,5);scanf("%d",&cod);
  if (buscar(cod)!=0)
   {
     boli(5,5,60,75);
     gotoxy(60,5);printf("%d",agenda[k].codigo);
     gotoxy(60,6);printf("%s",agenda[k].nombre);
     gotoxy(60,7);printf("%s",agenda[k].apellido);
     gotoxy(60,8);printf("%s",agenda[k].direccion);
     gotoxy(60,9);printf("%s",agenda[k].telefono);
     gotoxy(4,23);printf("ESTA SEGURO DE ELIMINAR S/N [ ]");
     gotoxy(33,23);preg=getch();
     preg=toupper(preg);
      boli(23,23,4,78);
     if (preg=='S')
	{
	if (j==k-1)
	  {
	  j--;
	  }
       else
       {
	 for (s=l;s<j;s++)
	 {
	   agenda[s]=agenda[s+1];
	 //  strcpy(agenda[s].nombre,agenda[s+1].nombre);
	 //  strcpy(agenda[s].apellido,agenda[s+1].apellido);
	 //  strcpy(agenda[s].direccion,agenda[s+1].direccion);
	 //  strcpy(agenda[s].telefono,agenda[s+1].telefono);
	}
	 j--;
       }
       //boli(23,23,4,79);
       gotoxy(4,23);printf("       DATOS BORRADOS      ");
       getch();
      }
     }
  else
   {
    boli(23,23,4,79);
    gotoxy(4,23);printf("ESTE CODIGO NO EXISTE");
    getch();
  }
   //boli(23,23,4,79);
   l=0;
   gotoxy(4,23);printf("DESEA CONTINUAR BORRANDO S/N [ ]    ");
   gotoxy(34,23);res=getch();
   res=toupper(res);
  j++;
  }
   while (res!='N');
}




/*void borrar()
{
 do
  {
    boli(6,20,2,78);
     cuadro(5,48,11,75,a1,a2,a3,a4,a5,a6);
    pantalla(6,49);
    boli(20,20,4,78);
    gotoxy(4,20);printf("DIGITE EL CODIGO DEL REGISTRO A BORRAR");

    gotoxy(60,6);scanf("%d",&cod);
    if (buscar(cod)!=0)
    {
     gotoxy(60,6);printf("%d",agenda[l].codigo);
     gotoxy(60,7);printf("%s",agenda[l].nombre);
     gotoxy(60,8);printf("%s",agenda[l].apellido);
     gotoxy(60,9);printf("%s",agenda[l].direccion);
     gotoxy(60,10);printf("%s",agenda[l].telefono);
      boli(20,20,4,78);
       //boli(23,23,4,78);
     gotoxy(4,20);printf("DESEA BORRAR ESTE REGISTRO S/N [ ]" );
     gotoxy(36,20);res=getch();
     res=toupper(res);
     boli(20,20,4,78);
     if (res=='S')
     {
     if (l== --j)
       {
       j--;
       }
       else
       {
	  for (s=l;s<j;s++)
	  {
	   agenda[s].codigo=agenda[s+1].codigo;
	   strcpy(agenda[s].nombre,agenda[s+1].nombre);
	   strcpy(agenda[s].apellido,agenda[s+1].apellido);
	   strcpy(agenda[s].direccion,agenda[s+1].direccion);
	   strcpy(agenda[s].telefono,agenda[s+1].telefono);
	   n--;
	 }
       }
//       boli(23,23,4,79);
       gotoxy(4,20);printf("REGISTRO BORRADO...PULSE ENTER PARA CONTINUAR");
       getch();
     }

   }
  else
   {
    //boli(23,23,4,79);
    boli(20,20,4,78);
    gotoxy(4,20);printf("CODIGO NO EXISTE... PULSE ENTER PARA CONTINUAR");
    getch();
  }
   // boli(23,23,4,79);
    l=0;
     boli(20,20,4,78);
    gotoxy(4,20);printf("DESEA BORRAR OTRO REGISTRO S/N [ ]");
    gotoxy(36,20);res=getch();
    res=toupper(res);
    j++;
  }
   while (res!='N');
   boli(5,20,2,78);

} */


void modificar()
{int cod;
 do
{boli(5,9,32,49);
 boli(4,9,52,69);
 boli(23,23,4,78);
 cuadro(4,19,10,50,a1,a2,a3,a4,a5,a6);
 pantalla(5,20);
 gotoxy(32,5);scanf("%d",&cod);
 if (buscar(cod)!=0)
 {do
 {gotoxy(32,6);puts (agenda[l].nombre);
  gotoxy(32,7);puts(agenda[l].apellido);
  gotoxy(32,8);puts(agenda[l].direccion);
  gotoxy(32,9);puts(agenda[l].telefono);
  cuadro(4,52,9,69,a1,a2,a3,a4,a5,a6);
  gotoxy(53,5);printf("1..NOMBRE");
  gotoxy(53,6);printf("2..APELLIDOS");
  gotoxy(53,7);printf("3..DIRECCION");
  gotoxy(53,8);printf("4..TELEFONO");
  boli(23,23,4,78);
  gotoxy(4,23);printf("ESCOJA UNA OPCION [ ]");
  gotoxy(23,23);opc=getch();
  if (opc=='1')
   {  boli(4,9,52,70);
   boli(6,6,32,49);
   validar(32,6);
   strcpy(nom,cad);
   strcpy(agenda[l].nombre,nom);
   }
      if (opc=='2')
   { boli(4,9,52,70);
     boli(7,7,32,49);
     validar(32,7);
     strcpy(ape,cad);
     strcpy(agenda[l].apellido,ape);
    }
      if (opc=='3')
   { boli(4,9,52,70);
     boli(8,8,32,49);
     gotoxy(32,8);gets(dir);
     strcpy(agenda[l].direccion,dir);
    }
    if (opc=='4')
   { boli(4,9,52,70);
     boli(9,9,32,49);
     gotoxy(32,9);gets(tel);
     strcpy(agenda[l].telefono,tel);
    }
     boli(23,23,4,78);
     gotoxy(4,23);printf("DESEA CONTINUAR S/N [ ]");
     gotoxy(25,23);pg=getch();
     pg=toupper(pg);
   } while (pg!='N');
  }
 else
 {gotoxy(60,11);printf("ESTE CODIGO NO EXISTE");
  getch();
  }
  boli(5,9,53,78);
  boli(23,23,4,78);
  gotoxy(4,23);printf("DESEA CONTINUAR CON OTRO REGISTRO S/N [ ]");
  gotoxy(43,23);preg=getch();
  preg=toupper(preg);
} while (preg!='N');
}




