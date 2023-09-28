/* la clave es mmmm             programa menu */
#include<stdio.h>
#define freno scanf("%c",&cap)
#define gotoxy(x,y) printf("%c%c%c%c",27,61,(31+x),(31+y))
#define clrscr printf("%c",26)
#define pare scanf("%c",&cap)
char cap,stop;
int x,y,t,f,c;
main()
{
clrscr;
cuadro();
gotoxy(6,27);printf("BIENVENIDOS AL PROGRAMA");
gotoxy(11,27);printf("AUTOR :ANA DINA LAZARO");
gotoxy(12,27);printf("CODOGO:4961025");
gotoxy(15,27);("PRESIONE CUALQUIER TECLA PARA CONTINUAR:"); 
freno;
clave();
menu();
}
menu()
{
int opc;
clrscr;
cuadro();
gotoxy(5,30);printf("MENU PRINCIPAL");
gotoxy(8,15);printf("1.GENERA LOS NUMEROS PRIMOS HASTA N TERMINO");
gotoxy(9,15);printf("2.EVALUAR EL NETO A PAGAR EN UNA NOMINA");
gotoxy(10,15);printf("3.LEE UN VECTOR Y LO INVIERTE");
gotoxy(11,15);printf("4.EVALUAR UNA FACTURA");
gotoxy(12,15);printf("5.REALIZAR EL JUEGO DE LA PIRINOLA");
gotoxy(13,15);printf("6.ESCRIBIR UNA MATRIZ EN FORMA DE CARACOL");
gotoxy(14,15);printf("7.SALIR");
gotoxy(22,15);printf("TOMA SU OPCION FAVORITA,PRESIONE <ENTER>");
gotoxy(22,58);scanf("%d",&opc);
switch(opc)
{
case 1:
       primos();
       menu();
case 2:
       nomina();
       menu();
case 3: 
       vecin();
       menu();
case 4:
       factu();
       menu();
case 5:
       pirino();
       menu();
case 6:
       caracol();
       menu();
case 7:
       salir();
       menu();
default:
       clrscr; 
       error();
}
}
error()
{
cuadro();
gotoxy(10,30);printf("NUMERO NO VALIDO");
gotoxy(13,15);printf("PRESINE UNA TECLA PARA IR AL MENU PRINCIPAL");
freno;
menu();
}
salir()
{
char t;
gotoxy(10,30);printf("FIN DEL PROGRAMA");
gotoxy(13,15);printf("PRESIONE <S> PARA CONTINUAR <N> PAR CANCELAR");
gotoxy(13,70);scanf("%c",&t);
if(t=='s'||t=='S')
{
exit(0);
}
else
{
menu();
}
}
cuadro()
{
for (f=2;f<=23;f++)
{
gotoxy(f,5);printf("*");
gotoxy(f,75);printf("*");
}
for (c=5;c<=75;c++)
{
gotoxy(2,c);printf("*");
gotoxy(23,c);printf("*");
}
}
clave()
{
char he[4],ta[4]={'d','i','n','a'};
int a,j,co,m;
if(m!=4)
{ 
co=35;
gotoxy(20,20);printf("DIGITE LA CLAVE EN MINUSCULA");
gotoxy(20,55);scanf("%c",&m);
for(a=0;a<=4;a++)
{
gotoxy(co,22);
he[a]=freno;
printf("*");
co=co++;
}
for(j=0;j<=4;j++)
{
if(he[j]==ta[j])
{
gotoxy(27,12);printf("LA CLAVE ES CORRECTA");
}
menu();
}
}
else
{
gotoxy(23,8);printf("LA CLAVE ES INCORRECTA");
m++;
gotoxy(20,20);printf("PRESIONE <ENTER> PARA OTRA OPORTUNIDAD");
}
}
primos()
{
int p,i,n,cont,v;
clrscr;
cuadro();
cont=0;
gotoxy(8,20);printf("HASTA QUE NUMERO DESEA LOS PRIMOS");
gotoxy(10,35);scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(v=1;v<=i;v++)
{
p=i%v;
if(p==0) 
{
cont++;
} 
}
if(cont<=2)
{
printf("%4d",i);
}
cont=0;
}
pare;
freno;
}
nomina()
{
int net=0,ho,dev,des,ni,dt,codd,coo,ne,sal,s=0,su=0,i,j,p;
char nomb[15],apell[15],carg[15];
clrscr;
cuadro();
gotoxy(4,30);printf("PROGRAMA NOMINA");
gotoxy(5,25);printf("CUANTAS NOMINAS VA A DIGITAR: ");
gotoxy(5,53);scanf("%d",&p);
for(i=0;i<=p;i++)
{
gotoxy(8,20);printf("NOMBRE: ");
gotoxy(9,20);printf("APELLIDO:  ");
gotoxy(10,21);printf("CARGO: ");
gotoxy(15,12);printf("SALARIO");
gotoxy(15,5);printf("NIT");
gotoxy(15,27);printf("DIAS TRABAJADOS");
gotoxy(15,32);printf("HORAS");
gotoxy(11,20);printf("CODIGO: ");
gotoxy(15,35);printf("DEVENGADO");
gotoxy(15,39);printf("CODO");
gotoxy(15,48);printf("DESCUENTO");
gotoxy(22,52);printf("NETO");
c=27;
for(j=0;j<=14;j++)
{
gotoxy(8,c);scanf("%c",&nomb[j]);
c=c+1;
}
c=27;
for(j=0;j<=14;j++)
{
gotoxy(9,c);scanf("%c",&apell[j]);
c+1;
}
c=27;
for(j=0;j<=14;j++)
{
gotoxy(10,c);scanf("%c",&carg[j]);
c=c+1;
}
gotoxy(16,12);scanf("%d",&sal);
gotoxy(16,32);scanf("%d",&ho);
gotoxy(11,24);scanf("%d",&codd);
gotoxy(16,5);scanf("%d",&ni);
gotoxy(16,15);scanf("%d",&dt);
gotoxy(16,35);scanf("%d",&dev);
gotoxy(16,39);scanf("%d",&coo);
gotoxy(16,48);scanf("%d",&des);
gotoxy(22,52);scanf("%d",&net);
s = s + dev;
gotoxy(16,35);scanf("%d",&s);
su = su + des;
gotoxy(16,48);scanf("%d",&su);
net = s - su;
gotoxy(22,52);scanf("%d",&net);
}
pare;
}
vecin()
{
int vector[10],mi,i,var,j;
clrscr;
cuadro();
gotoxy(5,25);printf("PROGRAMA QUE INVIERTE UN VECTOR");
gotoxy(8,25);printf("DIGITE LOS VALORES PARA EL VECTOR");
mi=20;
for(i=0;i<=9;i++)
{
gotoxy(11,mi);scanf("%d",&vector[i]);
mi=mi+3;
}
for(i=0;i<=8;i++)
{
for(j=i+1;j<=9;j++)
{
var=vector[i];
vector[i]=vector[j];
vector[j]=var;
}
gotoxy(15,25);printf("VECTOR INVERTIDO");
mi=20;
}
for(i=0;i<=9;i++)
{
gotoxy(18,mi);printf("%d",vector[i]);
mi=mi+3;
}
pare;
freno;
}
factu()
{
}
pirino()
{
int giro,i;
clrscr;
cuadro();
gotoxy(5,30);printf("JUEGO DE LA PIRINOLA");
gotoxy(6,30);printf("JUGAMOS PIRINOLA?");
gotoxy(8,30);printf("DIGITE UN NUMERO MENOR A 7");
for(i=0;i<=6;i++)
{
gotoxy(10,30);scanf("%d",&giro);
if(giro==1)
printf("PON UNO");
else
if(giro==2)
printf("PON DOS");
else
if(giro==3)
printf("TODOS PONEN");
else
if(giro==4)
printf("TOMA UNO");
else
if(giro==5)
printf("TOMA DOS");
else
if(giro==6)
printf("TOMA TODO");
if(giro>6)
printf("ERROR ,DIGITE NUMERO MENOR A 7");
}
}
caracol()
{
int ma[4][4],n,b,c,f;
clrscr;
cuadro();
gotoxy(6,25);printf("MATRIZ ESCRITA EN FORMA DE CARACOL");
gotoxy(7,25);printf("DIGITE LOS VALORES PARA LA MATRIZ");
n=0;
c=35;
for(b=0;b<=3;b++)
{
gotoxy(8,c);scanf("%d",&ma[n][b]);
c=c+3;
}
b=3;
f=10;
for(n=1;n<=3;n++)
{
gotoxy(f,44);scanf("%d",&ma[n][b]);
f=f+2;
}
n=3;
c=41;
for(b=2;b>=0;b--)
{
gotoxy(14,c);scanf("%d",&ma[n][b]);
c=c-3;
}
b=0;
f=12;
for(n=2;n>=1;n--)
{
gotoxy(f,35);scanf("%d",&ma[n][b]);
f=f-2;
}
n=1;
c=38;
for(b=1;b<=2;b++)
{
gotoxy(10,c);scanf("%d",&ma[n][b]);
c=c+3;
}
c=41;
n=2;
for(b=2;b>=1;b--)
{
gotoxy(12,c);scanf("%d",&ma[n][b]);
c=c-3;
}
pare;
freno;
 }
