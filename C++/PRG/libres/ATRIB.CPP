#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
#define go {gotoxy(1,24);}
struct registro
{int codigo;
 char nombre[20];
 char apellido[20];
 char direccion[20];
 char telefono[20];
 int activo;
 };
 FILE *ptr;
 registro agenda;

void crear();
void listar();
abrirA();
abrirR();
int tama=sizeof(agenda);
//void nomb();
//void apel();
//void tele();
//void dire();
void boli (int f1,int f2, int col1,int col2);
//void crear();
//void modificar();
//void consult();
//void borrar();
//buscar(int codi);
//void validar(int fil,int col);
//void validarn(int fil,int col);
menu();

//submenu(int fil, int col,int max);

//void individual();
//void global();
void pantalla(int fila, int columna);
char vec[5][13];//cad[30],vec1[10][14];
char nombre,apellido,direccion,telefono;//tel[10],dir[20],nom[30],ape[30];
//int res,i=0,preg,n,r,x,pg;
int i=0,codigo,res,opcion,activo,r,o;
char tecla;
void cuadro(int x1,int y1,int x2,int y2,int co,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[]);
void lineav(int x1,int y1,int x2,int co,char a1[],char a9[],char a10[]);
void lineah(int y1,int x1,int y2,int co,char a2[],char a7[],char a8[]);
char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È",a7[]="Ì",a8[]="¹",a9[]="Ê",a10[]="Ë";
void main()
{
do{
clrscr();
cuadro(1,1,20,80,2,a1,a2,a3,a4,a5,a6);
cuadro(22,1,24,80,5,a1,a2,a3,a4,a5,a6);
lineah(1,3,80,2,a2,a7,a8);
//lineah(1,22,80,a2,a7,a8);
strcpy(vec[0],"   ADICION  ");
strcpy(vec[1],"MODIFICACION");
strcpy(vec[2],"  LISTAR    ");
strcpy(vec[3],"  BORRADO   ");
strcpy(vec[4],"   SALIR    ");
opcion=menu();
  if (opcion==0)
     crear();
     //if (opcion==1)

     if (opcion==2)
      listar();
       //if (opcion==3)
	// borrar();

}while (opcion!=4);
}




void pantalla (int fila, int columna)
{gotoxy(columna,fila);printf  ("codigo.....");
 gotoxy(columna,fila+1);printf("nombre.....");
 gotoxy(columna,fila+2);printf("apellido...");
 gotoxy(columna,fila+3);printf("direcci¢n..");
 gotoxy(columna,fila+4);printf("telefono...");
}

abrirA()
{ptr=fopen("agenda.dat","a+b");
 if(ptr==NULL)
 {printf("ERROR DE APERTURA");
 getch();
 return(0);
 }
 else
 return(1);
}
abrirR()
{ptr=fopen("agenda.dat","r+b");
 if(ptr==NULL)
 {printf("ERROR DE APERTURA");
 getch();
 return(0);
 }
 else
 return(1);
}



void crear()
{do
 {if (abrirA()==1)
  {cuadro(4,3,10,35,1,a1,a2,a3,a4,a5,a6);
  pantalla(5,4);
  boli(23,23,4,74);
  boli(23,23,4,68);
  boli(5,9,16,34);
  gotoxy(16,5);scanf("%d",&agenda.codigo);
  //if (buscar(cod)==0)
  //{
  fflush(stdin);
   gotoxy(16,6);gets(agenda.nombre);
   gotoxy(16,7);gets(agenda.apellido);
   gotoxy(16,8);gets(agenda.direccion);
   gotoxy(16,9);gets(agenda.telefono);
   agenda.activo=0;
   gotoxy(4,23);printf("DATOS CORRECTOS S/N");
   gotoxy(25,23);res=getch();
   res=toupper(res);
   if (res=='S')
   fwrite(&agenda,tama,1,ptr);
 //else
 //{ boli(5,5,16,34);
  // gotoxy(4,23);printf("ESTE CODIGO YA SE ENCUENTRA");
  // getch();
// }
  //j++;
 // l=0;
 }  boli(23,23,4,58);
   gotoxy(4,23);printf("DESEA CONTINUAR CREANDO S/N [ ]    ");
   gotoxy(33,23);res=getch();
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
     textbackground(11);
     gotoxy(2+r,2);cprintf("%s",vec[i]);
     }
     else
      {textcolor(1);textbackground(0);
       gotoxy(2+r,2);cprintf("%s",vec[i]);}
       r+=15;
       textcolor(1);
       textbackground(0);
       switch(o)
       {case 0:go;gotoxy(5,21);cprintf("Modulo para la adici•n de clientes     ");
	       break;
	case 1:go; gotoxy(5,21);cprintf("Modulo para la modificaci•n de clientes");
	       break;
	case 2:go; gotoxy(5,21);cprintf("Modulo para la consulta de clientes    ");
	       break;
	case 3:go; gotoxy(5,21);cprintf("Modulo para el borrado de clientes    ");
	       break;
	case 4:go; gotoxy(5,21);cprintf("Moduo para salir de la aplicai•n       ");
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




/*buscar(int codi)
{int sw=0;

  while (sw==0 && l<j)
   {if (codi==agenda[l].codigo)
     sw=1;
     else
       l++;
    }

    return(sw);

} */




void cuadro(int x1,int y1,int x2,int y2,int co,char a1[],char a2[],char a3[],char a4[],char a5[], char a6[])
{ int p;
  for(p=x1;p<=x2;p++)
  { textcolor(co);
    gotoxy(y1,p);cprintf(a1);
     gotoxy(y2,p);cprintf(a1);
  }
  for(p=y1;p<=y2;p++)
  {   textcolor(co);
      gotoxy(p,x1);cprintf(a2);
      gotoxy(p,x2);cprintf(a2);
   }
      textcolor(co);
      gotoxy(y1,x1);cprintf(a3);
      gotoxy(y2,x2);cprintf(a4);
      gotoxy(y2,x1);cprintf(a5);
      gotoxy(y1,x2);cprintf(a6);

}

void lineav(int x1,int y1,int x2,int co,char a1[],char a9[],char a10[])
{ int p;
  for(p=x1;p<=x2;p++)
  { textcolor(co);
    gotoxy(y1,p);cprintf(a1);

  }
    textcolor(co);
    gotoxy(y1,x1);printf(a10);
    gotoxy(y1,x2);printf(a9);
}
void lineah(int y1,int x1,int y2,int co,char a2[],char a7[],char a8[])
{ int p;
  for(p=y1;p<=y2;p++)
  { textcolor(co);
    gotoxy(p,x1);cprintf(a2);

  }
    textcolor(co);
    gotoxy(y1,x1);printf(a7);
    gotoxy(y2,x1);printf(a8);
}


void boli (int f1, int f2, int col1, int col2)
{int z, d;
 {for (z=f1;z<=f2;z++)
   for (d=col1;d<col2;d++)
    {gotoxy(d,z);cprintf(" ");
    }
  }
}



/*void validar(int fil,int col)
{ int di=0;
 cad[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+di,col);res=getch();
      if ((res>='a' && res<='z')||(res>='A' && res<='Z')||(res==' '))
	{
	    cad[di++]=res;
	    gotoxy(fil-1+di,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cad[0] == ' ');
 cad[di]='\0';
 }


void validarn(int fil,int col)
{ int ni=0;
 cad[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+ni,col);res=getch();
      if ((res>='0' && res<='9')||(res==' '))
	{
	    cad[ni++]=res;
	    gotoxy(fil-1+ni,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cad[0] == ' ');
 cad[ni]='\0';
 }




void consult()
{
do
{boli(23,23,4,78);
 boli(4,18,20,76);
 cuadro(4,9,11,23,1,a1,a2,a3,a4,a5,a6);
 lineah(9,7,23,1,a2,a7,a8);
 gotoxy(12,5);printf("SUBMENU");
 gotoxy(12,6);printf("CONSULTA");
 strcpy(vec1[0],"   GLOBAL  ");
 strcpy(vec1[1]," INDIVIDUAL");
 strcpy(vec1[2],"   SALIR   " );

 op=submenu(4,11,3);
 if (op==0)
   global();
   if (op==1)
     individual();
 }while (op!=2);
}



void global()
{x=1;
 boli(4,11,9,24);
 gotoxy(21,5);printf("CODIGO");
 gotoxy(35,5);printf("NOMBRE");
 cuadro(4,20,18,75,1,a1,a2,a3,a4,a5,a6);
 lineah(20,16,75,1,a2,a7,a8);
 lineah(20,6,75,1,a2,a7,a8);
 lineav(4,27,16,1,a1,a9,a10);
  for (n=0;n<j;n++)
  {
    if (x<=3)
    {gotoxy(21,x+7);printf("%d",agenda[n].codigo);
     gotoxy(28,x+7);printf("%s",agenda[n].nombre);
      x++;
     }
     else
     {gotoxy(23,17);printf("DESEA CONTINUAR S/N [ ]");
      gotoxy(44,17);preg=getch();
      preg=toupper(preg);
      if (preg=='N')
      {n=j;
      }
      else
      {
      boli(8,10,21,26);
      boli(8,10,28,70);
      x=1;
      n=n-1;
      }
     }
  }
   boli(17,17,23,74);
   gotoxy(23,17);printf("ESTOS SON TODOS LOS DATOS");
   getch();
}




void individual()
{do
 { boli(4,11,9,24);
   boli(5,9,49,65);
   boli(23,23,4,78);
   cuadro(4,35,10,66,1,a1,a2,a3,a4,a5,a6);
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
   gotoxy(4,23);printf("DESEA CONTINUAR CONSULTANDO INDIVIDUALMENTE S/N [ ]    ");
   gotoxy(53,23);res=getch();
   boli(23,23,4,78);
  res=toupper(res);
  }while (res!='N');
}




void borrar()
{do
 {boli(23,23,4,79);
  cuadro(4,48,10,75,1,a1,a2,a3,a4,a5,a6);
  pantalla(5,49);
  boli(5,9,60,74);
  gotoxy(60,5);scanf("%d",&cod);
  if (buscar(cod)!=0)
   { boli(5,5,60,75);
     gotoxy(60,5);printf("%d",agenda[l].codigo);
     gotoxy(60,6);printf("%s",agenda[l].nombre);
     gotoxy(60,7);printf("%s",agenda[l].apellido);
     gotoxy(60,8);printf("%s",agenda[l].direccion);
     gotoxy(60,9);printf("%s",agenda[l].telefono);
     gotoxy(4,23);printf("SON DATOS QUE DESEA BORRAR S/N [ ]");
     gotoxy(36,23);preg=getch();
     if (preg=='s')
     { if (l== j-1)
       {j--;
       }
       else
       {for (s=l;s<j-1;s++)
	    agenda[s]=agenda[s+1];
	   j--;
       }
       boli(23,23,4,79);
       gotoxy(4,23);printf("DATOS BORRADOS");
       getch();
     }
      else
     {boli(23,23,4,79);
      gotoxy(4,23);printf("ESTOS DATOS NO HAN SIDO BORRADO");
      getch();
     }
   }
  else
   {boli(23,23,4,79);
    gotoxy(4,23);printf("ESTE CODIGO NO EXISTE");
    getch();
  }
   boli(23,23,4,79);
   l=0;
   gotoxy(4,23);printf("DESEA CONTINUAR BORRANDO S/N [ ]    ");
   gotoxy(34,23);res=getch();

  res=toupper(res);
  //j++;
  }while (res!='N');
}





void modificar()
{int cod;
 do
{
 boli(4,9,52,69);
 boli(23,23,4,78);
 cuadro(4,19,10,50,1,a1,a2,a3,a4,a5,a6);
 pantalla(5,20);
 gotoxy(32,5);scanf("%d",&cod);
 if (buscar(cod)!=0)
 {fflush(stdin);
  do
 {
  gotoxy(32,6);puts(agenda[l].nombre);
  gotoxy(32,7);puts(agenda[l].apellido);
  gotoxy(32,8);puts(agenda[l].direccion);
  gotoxy(32,9);puts(agenda[l].telefono);
  cuadro(4,52,9,63,1,a1,a2,a3,a4,a5,a6);
  strcpy (vec1[0]," NOMBRE   ");
  strcpy (vec1[1],"APELLIDOS ");
  strcpy (vec1[2],"DIRECCION ");
  strcpy (vec1[3],"TELEFONO  ");
  opc=submenu(1,53,4);
  if (opc==0)
    nomb();
    if (opc==1)
      apel();
      if (opc==2)
	 dire();
       if (opc==3)
	   tele();
    boli(23,23,4,78);
    boli(23,23,4,78);
    gotoxy(4,23);printf("DESEA CONTINUAR CON EL MISMO REGISTRO [ ]");
    gotoxy(43,23);pg=getch();
    pg=toupper(pg);
   }while (pg!='N');
  }
 else
 {gotoxy(4,23);printf("ESTE CODIGO NO EXISTE");
  getch();
 }
  boli(4,10,19,51);
  boli(23,23,4,78);
  boli(23,23,4,78);
  gotoxy(4,23);printf("DESEA CONTINUAR CON OTRO REGISTRO S/N [ ]");
  gotoxy(43,23);preg=getch();
  preg=toupper(preg);
} while (preg!='N');
}


void nomb()
{  boli(4,10,52,69);
   boli(6,6,32,49);
   validar(32,6);
   strcpy(nom,cad);
   strcpy(agenda[l].nombre,nom);
}





void apel()
{ boli(4,10,52,69);
    boli(7,7,32,49);
    validar(32,7);
    strcpy(ape,cad);
    strcpy(agenda[l].apellido,ape);
}




void dire()
{ boli(4,10,52,69);
   boli(8,8,32,49);
   gotoxy(32,8);gets(dir);
   strcpy(agenda[l].direccion,dir);
}





void tele()
{ boli(4,10,52,69);
    boli(9,9,32,49);
    validarn(32,9);
    strcpy(tel,cad);
    strcpy(agenda[l].telefono,tel);
}



submenu(int fil, int col, int max)
{do
 {r=fil;

  textbackground(0);
  for (i=0;i<max;i++)
   {if (i==o)
    {textcolor(1);
     textbackground(11);
     gotoxy(col,r+4);cprintf("%s",vec1[i]);
     }
     else
      {textcolor(1);textbackground(0);
       gotoxy(col,r+4);cprintf("%s",vec1[i]);}
       r+=1;
       textcolor(1);
       textbackground(0);
       }
      tecla=getch();
       if(tecla==80)
       {if (o<max-1)
	 o++;
	 else
	 o=0;
       }
       if (tecla==72)
	{if (o!=0)
	 o--;
	 else
	  o=max-1;
	}
 }
 while (tecla!=13);
 return(o);
 }*/
 void listar()
 {if (abrirR()==1)
  {fread(&agenda,tama,1,ptr);
  while(!feof(ptr))
  {boli(5,9,16,34);
   cuadro(4,3,10,35,1,a1,a2,a3,a4,a5,a6);
   pantalla(5,4);
   gotoxy(16,5);printf("%d",&agenda.codigo);
   gotoxy(16,6);puts(agenda.nombre);
   gotoxy(16,7);puts(agenda.apellido);
   gotoxy(16,8);puts(agenda.direccion);
   gotoxy(16,9);puts(agenda.telefono);
   getch();
   }
 }
}



