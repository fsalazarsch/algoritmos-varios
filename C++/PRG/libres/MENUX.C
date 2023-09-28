#include <stdio.h>
#include <conio.h>
#define f 2
int m,n,cont;
int y,z,x,imp,i,n;
int fila,col;
int cua;
int fila,fact,n;
int b,e,i,base,p;
int  q,penultimo,ultimo,proximo,i;
float r;
int cifra,n;
void
main()
 {
  clrscr();
  textcolor(BLUE);
  textbackground(WHITE);
  cuadro();
  clave();
 }
cuadro()
 {
 int fila,col;
 for (col=1;col<=80;col++)
  {
	for(fila=1;fila<=24;fila++)
	 {
	  gotoxy(col,1);printf ("*");
	  gotoxy(col,24);printf ("*_");
	  gotoxy(1,fila);printf("*");
	  gotoxy(80,fila);printf("*");
	 }
  }
}
clave()
{
int cont;
char n,m;
gotoxy(15,10);printf(" DIGITE SU CLAVE DE ACCESO:       ");
cont=1;
  while(cont<=3)
  {
	 gotoxy(54,10);m=getch();gotoxy(54,10);putchar(42);
	 gotoxy(55,10);n=getch();gotoxy(55,10);putchar(42);
	 if (m==118 && n==121)
	  {
		menu();
		}
	   else
	    {
	     gotoxy(26,24);printf("ERROR.  VUELVA A INTENTAR");
	     delay(2500);
	     gotoxy(26,24);printf("                         ");
	     gotoxy(54,14);printf("     ");
	    }
	   cont++;
	  }
	}
menu()
 {
 int opc;
 clrscr();
 cuadro();
 gotoxy (35,5);printf   ("MENU PRINCIPAL");
 gotoxy (20,6);printf   ("1.CUADRADO DE UN NUMERO");
 gotoxy (20,7);printf   ("2.FACTORIAL DE UN NUMERO N");
 gotoxy (20,8);printf   ("3.HALLAR DE UNA BASE N Y EXPONENTE N SU RESULTADO");
 gotoxy (20,9);printf   ("4.HALLAR N POSICIONES DE LA SECUENCIA DE FIBONACCI");
 gotoxy (20,10);printf  ("5.HALLAR SUMATORIA 1+1/2+1/3+1/4+...+1/n");
 gotoxy (20,11);printf  ("6.INVERTIR UN NUMERO N");
 gotoxy (20,12);printf  ("7.ARREGLOS");
 gotoxy (20,13);printf  ("8.SALIR");
 gotoxy (20,18);printf  ("DIGITE SU OPCION Y PRESIONE ENTER[ ]");
 gotoxy (54,18);scanf   ("%d",&opc);
 switch (opc)
 {
  case 1:
  cuadrado();
  menu();
  case 2:
  factorial();
  menu();
  case 3:
  expobase();
  menu();
  case 4:
  fibonacci ();
  menu();
  case 5:
  sumatoria ();
  menu();
  case 6:
  invertir ();
  menu();
  case 7:
  arre();
  menu();
  case 8:
  salir();
  default:
  clrscr();
  error();
  menu();
 }
}
error()
{
 clrscr();
 cuadro();
 gotoxy (30,10);printf("NUMERO NO VALIDO");
 gotoxy (20,11);printf("DIGITAR CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL");
 getch();
 menu();
}
 salir()
 {
  char t;
  clrscr();
  cuadro();
  gotoxy(30,10);printf("FIN DEL PROGRAMA");
  gotoxy(15,11);printf("PRESIONE S PARA CONTINUAR O N PARA CANCELAR [ ]");
  gotoxy(60,11);
  t=getch();
  if(t=='S'||t=='s')
  {
	exit(1);
  }
	else
	{
	 menu();
	}
  }
cuadrado()
{
 clrscr();
 cuadro();
 gotoxy(22,5);printf("CUADRADO DE UN NUMERO");
 gotoxy(15,9);printf("DIGITE NUMERO:");
 gotoxy(30,9);scanf("%d",&cua);
 cua=cua*cua;
 gotoxy(15,15);printf("EL CUADRADO DEL NUMERO ES: ");
 gotoxy(45,15);printf("%d",cua);
 getch();
 clrscr();
}
 factorial ()
 {
  clrscr ();
  cuadro();
  gotoxy(25,5);printf("FACTORIAL DE UN NUMERO");
  gotoxy(15,8);printf("HALLAR EL FACTORIAL DE:      ");
  gotoxy(40,8);scanf("%d",&n);
  fact=1;
  cont=0;
  col=15;
  while (cont<n)
	  {
		 cont++;
		 fact=fact*cont;
		 gotoxy(col,12);printf(" %d",fact);
		 col=col+2;
	  delay(500);
	  }
	getch();
 }
expobase()
{
 clrscr();
 cuadro();
 gotoxy(20,5);printf(" EXPONENCIAL");
 gotoxy(15,8);printf("DIGITE LA BASE      :   " );
 gotoxy(15,10);printf("DIGITE EL EXPONENTE :    ");
 gotoxy(40,8);scanf("%d",&b);
 gotoxy(40,10);scanf("%d",&e);
 p=b;
 base=p;
 for(i=2;i<=e;i++)
	{
	base=base*p;
	}
	gotoxy(15,12);printf("%s%d","EL RESULTADO ES     :    ",base);
	getch();
}
fibonacci()
{
 clrscr ();
 cuadro();
 gotoxy (35,5);printf("LA SERIE DE FIBONACCI");
						gotoxy (20,10);printf("DIGITE NUMERO:   ");
						scanf ("%d",&q);
								ultimo=1;
								penultimo=0;
								proximo=0;
								i=0;
								while (i<=q)
								{
								penultimo=ultimo;
								ultimo=proximo;
								proximo=penultimo+ultimo;
								i++;
								printf ("%3d",proximo);
								}
								getch();
}
sumatoria ()
{
 float d,sum,w,k;
 clrscr ();
 cuadro();
 gotoxy(25,5);printf("SUMATORIA FRACCIONARIOS");
 gotoxy(15,9);printf("DIGITE HASTA QUE NUMERO DESEA EL DENOMINADOR:     ");
 gotoxy(65,9);scanf("%f",&k);
 w=0;
 for(d=1;d<=k;d++)
	{
	sum=1/d;
	w=sum+w;
	}
	gotoxy(15,12);printf("%s%2.2f","EL RESULTADO ES:   ",w);
	getch();
}
invertir ()
{
 clrscr();
 gotoxy(20,5);printf("INVERTIR");
 gotoxy(15,9);printf("DIGITE NUMERO:  ");
 gotoxy(33,9);scanf("%d",&cifra);
 n=0;
 while(cifra>0)
	{
	r=cifra%10;
	n=n*10+r;
	cifra=cifra/10;
	}
	gotoxy(15,15);printf("%s%10d","EL NUMERO INVERSO ES:    ",n);
	getch();
}
arre()
{
int res;
clrscr();
cuadro();
gotoxy(36,8);printf("SUBMENU");
gotoxy(20,11);printf("1. VECTOR");
gotoxy(20,12);printf("2. MATRIZ");
gotoxy(20,13);printf("3. SALIR");
gotoxy(20,15);printf("DIGITE OPCION     [ ]");
gotoxy(39,15);scanf("%d",&res);
switch(res)
{
case 1:
vector();
arre();
case 2:
matriz();
arre();
case 3:
  sa();
  default:
  clrscr();
  er();
  arre();
 }
}
er()
{
 clrscr();
 cuadro();
 gotoxy (30,10);printf("NUMERO NO VALIDO");
 gotoxy (20,11);printf("DIGITAR CUALQUIER TECLA PARA VOLVER AL SUBMENU ");
 getch();
 arre();
}
 sa()
 {
  char t;
  clrscr();
  cuadro();
  gotoxy(30,10);printf("SALIR SUBMENU  ");
  gotoxy(15,11);printf("PRESIONE S PARA CONTINUAR O N PARA CANCELAR [ ]");
  gotoxy(60,11);
  t=getch();
  if(t=='S'||t=='s')
  {
	exit(menu());
  }
	else
	{
	 arre();
	}
}
vector()
{
int vec[10],nu,ne,j,aux;
clrscr();
cuadro();
gotoxy(40,5);printf(" VECTOR");
col=20;
for (i=0;i<10;i++)
{
gotoxy(col,8);scanf("%d",&vec[i]);
col=col+4;
}
		 for (i=0;i<=8;i++)
			for (j=i+1;j<=9;j++)
			 if (vec[i]>=vec[j])
			  {
			  aux=vec[i];
			  vec[i]=vec[j];
			  vec[j]=aux;
			  }
	 col=36;
	 gotoxy (4,13);printf("NUMEROS ORDENADOS ASCENDENTES:");
	 for (i=0;i<=9;i++)
	  {
	  gotoxy (col,13);printf ("%d",vec[i]);
	  col=col+4;
	  }
	  getch ();
}

matriz()
{
int fy,cy,i,j,t[f][f],d,p,cont,acum;
int b,m,min;
clrscr();
cuadro();
gotoxy(20,5);printf("MATRIZ");
gotoxy(15,8);printf(" digite los numeros :"  );
 fy=15;
 cy=25;
 for (i=0;i<f;i++)
	 {
	 for (j=0;j<f;j++)
		{
		 gotoxy(cy,fy); scanf("%d",&t[i][j]);
		 fy=fy+2;
		}
		fy=15;
		cy=cy+3;
	}
	clrscr();
	cuadro();
d=15;
p=5;
for (i=0;i<f;i++)
	 {
	 for(j=0;j<f;j++)
		  {
		  gotoxy (d,p);printf("%d",t[i][j]);
		  p=p+2;
		 }
	 d=d+4;
	 p=5;
	 }
	 getch();
min=t[0][0];
for (i=0;i<f;i++)
{
for (j=0;j<f;j++)
{
if (t[i][j]<min)
{
min=t[i][j];

}
}
}
gotoxy(25,14);printf("%s%d", "el numero menor de la matriz es:     ",min);
getch();

	 i=0;
	 j=0;
	 cont=0;
	 acum=0;
	 while (cont<f)
			 {
			 acum=acum+t[i][j];
			 j=j+1;
			 i=i+1;
			 cont=cont+1;
			 }
			 gotoxy(25,15);printf("%s%d","la suma de la diagonal \ es:      ",acum);
			 getch();
	 i=0;
	 j=1;
	 cont=0;
	 acum=0;
	 while (cont<f)
			 {
			 acum=acum+t[i][j];
			 j=j-1;
			 i=i+ 1;
			 cont=cont+1;
			 }
			 gotoxy(25,16);printf("%s%d","la suma de la diagonal / es:      ",acum);
			 getch();
	  i=0;
	  j=0;
	  acum=0;
	  cont=0;
	  while (cont<f)
			  {
			  acum=acum+t[i][j];
			  i=i+1;
			  cont=cont+1;
			  }
			  gotoxy(25,17);printf("%s%d","la suma de la primera fila es:    ",acum);
			  getch();
	 i=0;
	 j=1;
	 acum=0;
	 cont=0;
	 while (cont<f)
			 {
			 acum=acum+t[i][j];
			 i=i+1;
			 cont=cont+1;
			 }
			 gotoxy(25,18);printf("%s%d","la suma de la ultima fila es:     ",acum);
			 getch();

}