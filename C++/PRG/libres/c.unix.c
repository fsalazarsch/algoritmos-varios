#include<stdio.h>
#define freno scanf("%c",&cap)
#define freno scanf("%c",&cap)
#define freno scanf("%c",&cap)
#define freno scanf("%c",&cap)
#define freno  scanf("%c",&cap)
#define clrscr printf("%c",26)
#define gotoxy(x,y) printf("%c%c%c%c",27,61,(31+x),(31+y))
int f,c,i,tirar,l,tem,v[5],j,acu,a,q,u,m,t,h,w,k,sum,sub,opc,n,g,f,cancelar,iva;
char cap;
main()
{
clrscr;
cuadro();
gotoxy(7,27);printf("BIENVENIDO AL PROGRAMA");
gotoxy(11,27);printf("ALEXANDER BARRERA Y CONSTANZA GONZALEZ");
gotoxy(12,33);printf("CODIGOS:4962005 Y 4962014");
gotoxy(18,27);printf("PRESION ENTER PARA CONTINUAR:   ");
freno;
menu();
}
menu()
{
cuadro();
gotoxy(5,30);printf("MENU PRINCIPAL");
gotoxy(8,15);printf("       1:GENERRE LOS NUMEROS PRIMOS HASTA N TERMINOS");
gotoxy(9,15);printf("       2:EVALUAR EL NETO A PAGAR DE UNA NOMINA");
gotoxy(10,15);printf("       3:LEER UN VECTOR , INVERTIRLO E IMPRIMIRLO");
gotoxy(11,15);printf("       4:EVALUAR UNA FACTURA");  
gotoxy(12,15);printf("       5:REALIZAR EL JUEGO DE LA PIRINOLA");
gotoxy(13,15);printf("       6:ESCRIBIR UNA MATRIZ EN FORMA DE CARACOL");;
gotoxy(14,15);printf("       7:SALIR");;
gotoxy(22,15);printf("TOME SU OPCION FAVORITA Y PRESIONE <ENTER>");
gotoxy(22,60);scanf("%d",&opc);
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
default:
error();
}
}
error()
{
cuadro();
gotoxy(10,30);printf("NUMERO NO VALIDO");
gotoxy(13,15);printf("DIGITE CUALQUIER TECLA PARA IR AL MENU PRINCIPAL");
freno;
menu();
}
salir()
{
char t;
gotoxy(10,30);printf("FIN DEL PROGRAMA");
gotoxy(13,15);printf("PRESIONE <n> PARA CONTINUAR O <s> PARA CANCELAR\n");
gotoxy(13,70);scanf("%c",&t);
if(t=='s'||t=='S')
{
freno;
exit(0);
}
else
{
menu();
}
}
cuadro()
{
clrscr;
f=1;
c=1;
for(f==1;f<=23;f++)
{
    gotoxy(f,1);printf("&&");
    gotoxy(f,75);printf("&&");
}
for (c==1;c<=75;c++)
{
gotoxy(1,c);printf("&&");
gotoxy(23,c);printf("&&");
}
}
pirino()
{
clrscr;
cuadro();
for (i=0;i<=6;i++){
gotoxy(12,15);scanf("%d",&tirar);
if(tirar==1)
printf("PON  UNO\n");
if(tirar==2)
printf("PON DOS");
else
if(tirar==3)
printf("TODOS PONEN");
else
if(tirar==4)
printf("TOMA UNO");
else
if(tirar==5)
printf("TOMA DOS");
else
if(tirar==6)
printf("TOMA TODO");
else
if(tirar>6)
{
gotoxy(18,15);printf("TIRE UNA VEZ MAS\n");
}
}
}
nomina()
{
}
vecin()
{
}
caracol()
{
clrscr;
cuadro();
gotoxy(12,40);printf("@ @");
gotoxy(13,43);printf("*");
gotoxy(14,42);printf("@");
gotoxy(14,40);printf("@");
gotoxy(14,38);printf("@");
gotoxy(13,38);printf("*");
gotoxy(12,38);printf("*");
gotoxy(11,38);printf("*");
gotoxy(10,38);printf("@");
gotoxy(10,40);printf("@ @ @");
gotoxy(11,44);printf("*");
gotoxy(12,44);printf("*");
gotoxy(13,44);printf("*");
gotoxy(14,44);printf("*");
gotoxy(15,44);printf("*");
gotoxy(16,44);printf("@");
gotoxy(16,42);printf("@");
gotoxy(16,40);printf("@");
gotoxy(16,38);printf("@");
gotoxy(16,36);printf("@");
gotoxy(15,36);printf("*");
gotoxy(14,36);printf("*");
gotoxy(13,36);printf("*");
gotoxy(12,36);printf("*");
gotoxy(11,36);printf("*");
gotoxy(10,36);printf("*");
gotoxy(9,36);printf("*");
gotoxy(8,36);printf("@ @ @ @ @ @");
gotoxy(9,46);printf("*");
gotoxy(10,46);printf("*");
gotoxy(11,46);printf("*");
gotoxy(12,46);printf("*");
gotoxy(13,46);printf("*");
gotoxy(14,46);printf("*");
gotoxy(15,46);printf("*");
gotoxy(16,46);printf("*");
gotoxy(17,46);printf("*");
gotoxy(18,46);printf("@");
gotoxy(18,44);printf("@");
gotoxy(18,42);printf("@");
gotoxy(18,40);printf("@");
gotoxy(18,38);printf("@");
gotoxy(18,36);printf("@");
gotoxy(18,34);printf("@");
gotoxy(17,34);printf("*");
gotoxy(16,34);printf("*");
gotoxy(15,34);printf("*");
gotoxy(14,34);printf("*");
gotoxy(13,34);printf("*");
gotoxy(12,34);printf("*");
gotoxy(11,34);printf("*");
gotoxy(10,34);printf("*");
gotoxy(9,34);printf("*");
gotoxy(8,34);printf("*");
gotoxy(7,34);printf("*");
gotoxy(6,34);printf("@ @ @ @ @ @ @ @ @");
freno;
}
clave()
{
}
inver()
{
clrscr;
cuadro();
gotoxy(10,10);printf("DIGITE LOS NUMEROS");
l=12;
 for(i=0;i<=4;i++)
 {
 gotoxy(12,l);scanf("%d",&v[i]);
l=l+2;
}
for(i=0;i<=3;i++)
{
for(j=0;j<=4;j++)
{
tem=v[i];
v[i]=v[j];
v[j]=tem;
}
}
l=12;
 for(i=0;i<=3;i++)
 {
freno;
gotoxy(12,l);printf("%d",v[i]);
l=l+2;
}
freno;
}
primos()
{
clrscr;
cuadro();
acu=0;
gotoxy(10,12);scanf("%d",&n);
for(i=1;i<=n;i++)
{
for (a=1;a<=i;a++)
{
q=i%a;
if(q==0)
{
acu++;
}
}
if(acu<=2)
{
printf("%4d",i);
}
acu=0;
}
freno;
freno;
}
factu()
{
char e[35];
c=0,u=0,m=14,t=0,g,h=0,w,k=0,sum=0,sub=0,f;
clrscr;
cuadro();
gotoxy(4,28);printf(" FACTURA MES DE MAYO\n");
gotoxy(6,15);printf("BOTTI ALEXCONY S.A ");
gotoxy(9,15);printf("FECHA:         ");
gotoxy(9,21);scanf("%d",&a);
gotoxy(9,35);printf("CIUDAD:SANTAFE DE BOGOTA D.C");
gotoxy(12,15);printf("CODIGO");
gotoxy(12,24);printf("CANTIDAD");
gotoxy(12,35);printf("DETALLES");
gotoxy(12,46);printf("V/R UNITARIO");
gotoxy(12,59);printf("V/R TOTAL\n");
for(f=0;f<=2;f++)
{
gotoxy(l,18);scanf("%d",&c);
gotoxy(l,27);scanf("%d",&u);
gotoxy(l,36);scanf("%s",&e[w]);
gotoxy(l,46);scanf("%d",&h);
t=u*h;
gotoxy(l,59);printf("%d",t);
gotoxy(19,59);printf("%d",sum);
m=m+1;
sum=sum+t;
}
freno;
gotoxy(19,35);printf("SUBTOTAL");
gotoxy(20,35);printf("IVA 16%");
iva=sum*0.16;
gotoxy(20,59);printf("%d",iva);
gotoxy(21,35);printf("TOTAL A PAGAR");
cancelar=sum+iva;
gotoxy(21,59);printf("%d",cancelar);
freno;
}


