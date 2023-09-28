#include <stdio.h>
#define clrscr printf("%c",26)
#define gotoxy(x,y) printf("%c%c%c%c",27,61,(31+x),(31+y))
#define freno scanf("%c",&cap)
#define mio scanf("%c",&cap)
char cap,prod;
int d[4],a,b,f,aux,m,l,i,j,n,s,w,con,col,fil,p,q,r[4][4];
int x,y,fecha,cod,can,van,vtol,c,tolfac,iva,stol,sum,net;
main()
{
clrscr;
cuadro();
gotoxy(6,27); printf("   BIENVENIDOS AL PROGRAMA   ");
gotoxy(12,27); printf("   AUTOR: DIANA RODRIGUEZ   ");
gotoxy(13,27); printf("      CODIGO: 4962026     ");
gotoxy(20,24); printf(" PRESIONE UNA TECLA PARA CONTINUAR ");
freno;
menu();
}
menu()
{
int opc;
clrscr;
cuadro();
gotoxy(4,34); printf("MENU PRINCIPAL");
gotoxy(8,15); printf("MENU 1. GENERE LOS NUMEROS PRIMOS HASTA N TERMINOS");
gotoxy(9,15); printf("MENU 2. EVALUAR EL NETO A PAGAR  EN UNA NOMINA");
gotoxy(10,15); printf("MENU 3. LEER UN VECTOR E INVERTIRLO");
gotoxy(11,15); printf("MENU 4. EVALUAR UNA FACTURA");
gotoxy(12,15); printf("MENU 5. REALIZAR EL JUEGO DE LA PIRINOLA");
gotoxy(13,15); printf("MENU 6. ESCRIBIR UNA MATRIZ EN FORMA DE CARACOL");
gotoxy(14,15); printf("MENU 7. SALIR");
gotoxy(20,18); printf("ELIJA SU OPCION FAVORITA, PRESIONE <ENTER>");
gotoxy(22,26); scanf("%d",&opc);
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
      fact();
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
freno;
}
error()
{
cuadro();
gotoxy(8,30);printf("NUMERO NO VALIDO");
gotoxy(20,20);printf("DIGITE CUALQUIER TECLA PARA REGRESAR");
freno;
menu();
}
salir()
{
char t;
gotoxy(16,30); printf("FIN DEL PROGRAMA");
gotoxy(13,15); printf("PRESIONE <S> PARA CONTINUAR, O <N> PARA CANCELAR");
gotoxy(13,70); scanf("%c",&t);
if (t=='S')
{
exit (0);
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
  gotoxy(x,1); printf("@!");
  gotoxy(x,80); printf("!@");
 }
 for (y=1;y<=80;y++)
 {
  gotoxy(1,y); printf("*&");
  gotoxy(23,y); printf("&*");
 }
}
primos()
{
clrscr;
cuadro();
con=0;
gotoxy(6,34); printf("NUMEROS PRIMOS\n");
gotoxy(12,8); scanf("%d",&n);
for(s=1;s<=n;s++)
{
 for(w=1;w<=s;w++)
 {
  c=s%w;
   if(c==0)
   {
   con++;
 }
}
if(con<=2)
{
 printf("%4d",s);
}
con=0;
}
freno;
freno;
}
nomina()
{
clrscr;
cuadro();
 }
vecin()
{
clrscr;
cuadro();
 gotoxy(6,34); printf("INVERTIR UN VECTOR");
 a=32;
 for(f=0;f<=3;f++)
 {
  gotoxy(10,10); printf("DIGITE LOS NUMERO");
  gotoxy(12,a); scanf("%d",&d[f]);
  a=a+3;
 }
 for (f=0;f<=2;f++)
 {
  for (b=f+1;b<=3;b++)
  {
   aux=d[f];
   d[f]=d[b];
   d[b]=aux;
  }
}
 a=32;
 for (f=0;f<=3;f++)
 {
  gotoxy(14,10); printf("VEC.INVERTIDO");
  gotoxy(16,a); printf("%d",d[f]);
  a=a+3;
freno;
}
}
fact()
{
l=15;
clrscr;
cuadro();
gotoxy(4,38); printf("FACTURA");
gotoxy(6,32); printf("SUPERMERCADO CAFAM");
gotoxy(10,4); printf("FECHA");
gotoxy(14,4); printf("CODIGO");
gotoxy(14,18); printf("CANTIDAD");
gotoxy(14,28); printf("PRODUCTO");
gotoxy(14,38); printf("VALOR/UNI");
gotoxy(14,48); printf("VALOR/TOTAL");
gotoxy(20,12); printf("SUB/TOTAL");
gotoxy(21,12); printf("IVA");
for(i=0;i<=4;i++)
{
gotoxy(l,4); scanf("%d",&cod);
gotoxy(1,18); scanf("%d",&can);
gotoxy(l,28); scanf("%d",&prod);
gotoxy(l,38); scanf("%d",&van);
gotoxy(l,48); scanf("%d",&vtol);
vtol=can*van;
gotoxy(l,14); printf("%d",vtol);
gotoxy(l,12); scanf("%d",&sum);
l=l+2;
sum=sum+vtol;
gotoxy(20,12); printf("%d",stol);
gotoxy(21,12); printf("%d",iva); 
iva=sum*0.16;
net=sum+iva;
gotoxy(22,12); printf("%d",net);
}
mio;
}
pirino()
{
clrscr;
cuadro();
gotoxy(4,24); printf("JUEGO DE LA PIRINOLA");
for (c=0;c<=7;c++)
{
gotoxy(14,20); scanf("%d",&c);
{
if(c==1)
printf("PON UNO\n");
else
if(c==2)
printf("PON DOS\n");
else
if(c==3)
printf("TOMA UNO\n");
else
if(c==4)
printf("TOMA DOS\n");
else
if(c==5)
printf("TOMA TODO\n");
else
if(c==6)
printf("TODOS PONEN\n");
else
if(c>6)
printf("ERROR,VUELVE A JUGAR\n");
}
freno;
}
}
caracol()
{
clrscr;
cuadro();
q=0;
col=36;
for(p=0;p<=3;p++)
{
 gotoxy(8,col); scanf("%d",&r[q][p]);
 col=col+3;
}
p=3;
fil=10;
for(q=1;q<=3;q++)
{
 gotoxy(fil,42); scanf("%d",&r[q][p]);
 fil=fil+2;
}
q=3;
col=42;
for(p=2;p>=0;p--)
{
 gotoxy(14,col); scanf("%d",&r[q][p]);
 col=col-3;
}
p=0;
fil=12;
for(p=2;p>=1;p--)
{
 gotoxy(fil,36); scanf("%d",&r[p][q]);
 fil=fil-2;
}
q=1;
col=39;
for(p=1;p<=2;p++)
{
 gotoxy(10,col); scanf("%d",&r[p][q]);
 col=col+3;
}
col=42;
q=2;
for(p=2;p>=1;p--)
{
 gotoxy(12,col); scanf("%d",&r[p][q]);
 col=col-3;
}
freno;
}
