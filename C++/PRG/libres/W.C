#include <stdio.h>
#define clrscr printf("%c",26)
#define gotoxy(x,y) printf("%c%c%c%c",27,61,(31+x),(31+y))
#define freno scanf("%c",&cap)
char cap,t; 
int x,y,j,i,m[5],o,aux,n,con,w,fac,fe,sen,dir,cod,cant,pro,vu,vt,sub,iva,tfac;
int suma,g,neto,c,f,z,og[5][5],p;
main()
{
clrscr;
cuadro();
gotoxy(5,27); printf("BIENVENIDO AL PROGRAMA");
gotoxy(9,27); printf("AUTOR:MARILUZ MONROY NINO");
gotoxy(11,27); printf("CODIGO: 4962020");
gotoxy(17,27); printf ("PRESIONE UNA TECLA PARA CONTINUAR:"); 
freno;
menu();
}
menu()
{
int opc;
clrscr;
cuadro();
gotoxy(5,30); printf("MENU PRINCIPAL");
gotoxy(8,15); printf("1.genere numeros primos hasta n terminos");
gotoxy(9,15); printf("2.evaluar el neto a pagar en una nomina");
gotoxy(10,15); printf("3.leer un vector y lo invierta");
gotoxy(11,15); printf("4.evaluar una factura");
gotoxy(12,15); printf("5.realizar el juego de la pirinola");
gotoxy(13,15); printf("6.escribir una matriz en forma de caracol");
gotoxy(14,15); printf("7.salir");
gotoxy(22,15); printf("TOME SU OPCION FAVORITA, PRESIONE <ENTER>");
gotoxy(22,58); scanf("%d",&opc);
switch (opc)
{
case 1:
       primos();
       menu();
case 2:
       nomina();
       menu();
case 3:
       vec();
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
gotoxy(10,30); printf("numero no valido");
gotoxy(13,15); printf("digite cualquier tecla para ir al menu principal");
freno;
menu();
}
salir()
{
gotoxy(16,30); printf("fin del programa");
gotoxy(13,15); printf("presione<s> para continuar o <n>para cancelar");
gotoxy(13,70); scanf("%c",&t);
if (t=='s')
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
for (x=1;x<=23;x++)
{
gotoxy(x,1); printf("*");
gotoxy(x,80); printf("*");
}
for (y=1;y<=80;y++)
{
gotoxy(1,y); printf("*");
gotoxy(23,y); printf("*");
}
freno;
}
primos()
{
 }
nomina()
{
clrscr;
cuadro();
gotoxy(5,10); printf("NOMBRE DEL EMPLEADO");
gotoxy(5,20); printf("SUELDO BASICO");
 }
vec()
{
clrscr;
cuadro();
{
con=0;
gotoxy(5,30); printf("INVERTIR EL VECTOR");
o=28;
for (i=0;i<=4;i++)
{
gotoxy(14,30); printf("digite los numeros");
gotoxy(13,o); scanf("%d",&m[i]);
o=o+4;
}
for(i=0;i<=3;i++)
{
for(j=i+1;j<=4;j++)
{
aux=m[i];
m[i]=m[j];
m[j]=aux;
}
}
o=28;
for(i=0;i<=4;i++)
{
gotoxy(14,30); printf("VECTOR INVERTIDO");
gotoxy(15,o); printf("%d",m[i]);
o=o+6;
freno;
}
}
factu()
{
clrscr;
cod=0,cant=0,vu=0,vt=0,sub=0,iva=0,tfac=0,suma=0;
g=14;
clrscr;
cuadro();
gotoxy(5,40); printf("IBERICA");
gotoxy(6,42); printf("LTDA");
gotoxy(6,46); printf("FACTURA");
gotoxy(8,10); printf("FECHA");
gotoxy(10,10); printf("SE#OR(A)");
gotoxy(10,44); printf("DIRECCION");
gotoxy(12,10); printf("CODIGO");
gotoxy(12,15); printf("CANTIDAD");
gotoxy(12,20); printf("PRODUCTO");
gotoxy(12,25); printf("VALOR UNITARIO");
gotoxy(12,30); printf("VALOR TOTAL");
gotoxy(16,20); printf("SUBTOTAL");
gotoxy(18,20); printf("IVA");
for (i=0;i<=4;i++)
{
gotoxy(g,10); scanf("%d",&cod);
gotoxy(g,15); scanf("%d",&cant);
gotoxy(g,20); scanf("%d",&pro);
gotoxy(g,25); scanf("%d",&vu);
gotoxy(g,30); scanf("%d",&vt);
vt=cant*vu;
gotoxy(12,40); printf("%d",vt);
gotoxy(g,20); scanf("%d",&suma);
g=g+2;
suma=suma+vt;
gotoxy(16,25); printf("%d",sub);
gotoxy(18,25); printf("%d",iva);
iva=suma*0.16;
neto=suma+iva;
gotoxy(18,25); printf("%d",neto);
}
freno;
}
pirino()
{
clrscr;
cuadro();
gotoxy(5,28); printf("JUEGO DE LA PIRINOLA");
for(i=0;i<=5;i++)
{
gotoxy(5,28); scanf("%d",&w);
}
if(w==1)
{
gotoxy(7,26); printf("TOMA UNO");
}
else
if(w==2)
{
gotoxy(10,26); printf("TOMA DOS");
}
else
if(w==3)
{
gotoxy(13,26); printf("TOMA TODO");
}
else
if(w==4)
{
gotoxy(16,26); printf("PON UNO");
}
else
if(w==5)
{
gotoxy(19,26); printf("PON DOS");
}
else
if(w==6)
{
gotoxy(22,26); printf("TODOS PONEN");
}
else
if(w>6)
{
gotoxy(23,26); printf("error, vuelve a empezar");
}
freno;
}
caracol()
{
clrscr;
cuadro();
gotoxy(5,30); printf("MATRIZ EN FORMA DE CARACOL");
p=0;
c=34;
for(z=0;z<=4;z++)
{
gotoxy(7,c); scanf("%d",&og[p][z]);
c=c+4;
}
z=3;
f=8;
for(p=1;p<=4;p++)
{
gotoxy(f,42); scanf("%d",&og[p][z]);
f=f+2;
}
p=3;
c=40;
for(z=2;z>=0;z--)
{
gotoxy(10,c); scanf("%d",&og[p][z]);
c=c-3;
}
z=0;
f=10;
for(p=2;p>=1;p--)
{
gotoxy(f,34); scanf("%d",&og[p][z]);
f=f-2;
}
p=1;
c=36;
for(z=1;z<=2;z++)
{
gotoxy(8,c); scanf("%d",&og[p][z]);
c=c+3;
}
c=40;
p=2;
for(z=2;z>=1;z++)
{
gotoxy(10,c); scanf("%d",&og[p][z]);
c=c-3;
}
freno;
}


