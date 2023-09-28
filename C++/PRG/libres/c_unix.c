#include"stdio.h"
#define gotoxy(x,y) printf("%c%c%c%c",27,61,(31+x),(31+y))
#define clrscr printf("%c",26)
#define parada scanf("%c",&cap)
char pres,b[4],d[4],cap,nom[30],mes[10],s,art[30];
int x,y,a[10],i,l,j,aux,cod,f,c,n,dt,can,vunit,vato;
float sue,hodo,hodi,hono,hododi,atrans,reno,hodono,toreno,tohodi,tohono;
float tohodo,tohododi,tohodono,todeve,honorma,sueldo,eps,rt,prest,neapa;
float todes,fope;
main()
{
clrscr;
cuadro();
gotoxy(07,27);printf("WELLCOME THE PROGRAM^^^^^^^^^^^^^^^^^^^^");
gotoxy(11,27);printf("AUTOR:Oscar Rene Ardila R.^^^^^^^^^^^^^^");
gotoxy(13,27);printf("CODIGO:4962003^^^^^^^^^^^^^^^^^^^^^^^^^^");
gotoxy(18,27);printf("PRESS ANY KEY TO CONTINUED^^^^^^^^^^^^^^");
parada; 
/*clave();*/
menu();
}
menu()
{
int opc;
cuadro();
gotoxy(5,33);printf("MENU PRINCIPAL");
gotoxy(8,15);printf("1.----GENERE LOS NUMEROS PRIMOS HASTA N TERMINOS");
gotoxy(9,15);printf("2.----------EVALUE EL NETO A PAGAR EN UNA NOMINA");
gotoxy(10,15);printf("3.-----------------LEER UN VECTOR Y LO INVIERTA");
gotoxy(11,15);printf("4.--------------------------EVALUAR UNA FACTURA");
gotoxy(12,15);printf("5.-------------REALIZAR EL JUEGO DE LA PIRINOLA");
gotoxy(13,15);printf("6.---------HACER UNA MATRIZ EN FORMA DE CARACOL");
gotoxy(14,15);printf("7.----------------------------------------SALIR");
gotoxy(20,15);printf("-------ELIJA SU OPCION DESEADA PRESIONE <ENTER>");
gotoxy(22,58);scanf("%d",&opc);
switch (opc)
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
gotoxy(13,15);printf("DIGITE CUALQUIER TECLA PARA IR AL MENU PRINCIPAL");
parada;
menu();
}
salir()
{
char t;
gotoxy(10,30);printf("FIN DEL PROGRAMA");
gotoxy(13,15);printf("PRESIONE<s> PARA CONTINUAR O <n> PARA CANCELAR");
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
clrscr;
for (f=2;f<=24;f++)
{
gotoxy(f,5);printf("||");
gotoxy(f,75);printf("||");
}
for (c=5;c<=75;c++)
{
gotoxy(2,c);printf("=");
gotoxy(24,c);printf("=");
}
}
clave()
{
cuadro();
}
primos()
{
}
nomina()
{
clrscr;
cuadro();
gotoxy(3,32);printf("COMPANIA FUERSAS LTDA.");
gotoxy(6,6);printf("NOMBRE EMPLEADO: ");
scanf("%c",nom);
gotoxy(6,60);printf("CODIGO: ");
scanf("%d",&cod);
gotoxy(7,6);printf("PERIODO PAGO: ");
scanf("%c",&mes);
gotoxy(7,40);printf("SUELDO BASICO: ");
scanf("%f",&sue);
gotoxy(9,6);printf("DIAS TRABAJADOS:                      "); 
scanf("%f",&dt);
gotoxy(11,6);printf("CANTIDAD RECARGO NOCTURNO           : ");
scanf("%f",&reno);
gotoxy(13,6);printf("CANTIDAD HORAS EXTRAS DIURNAS       : ");
scanf("%f",&hodi);
gotoxy(15,6);printf("CANTIDAD HORAS EXTRAS NOCTURNAS     : ");
scanf("%f",&hono);
gotoxy(17,6);printf("CANTIDAD HORAS DOMINICALES          : ");
scanf("%f",&hodo);
gotoxy(19,6);printf("CANTIDAD HORAS DOMINICALES DIURNAS  : ");
scanf("%f",&hododi);
gotoxy(21,6);printf("CANTIDAD HORAS DOMINICALES NOCTURNAS: ");
scanf("%f",&hodono);
gotoxy(22,6);printf("TIENE PRESTAMOS?       (si o no)    : ");
scanf("%c",&pres);
parada;
clrscr;
cuadro();
sueldo=(sue * dt)/30;
if (sue==344010)
{
atrans=(17250 * dt)/30;
}
honorma=(sue/240);
toreno=(honorma * 1,35 * reno);
tohodi=(honorma * 1,25 * hodi);
tohono=(honorma * 1,75 * hono);
tohodo=(honorma * 2 * hodo);
tohododi=(honorma * 3,25 * hododi);
tohodono=(honorma * 3,75 * hodono);
todeve=(sue+atrans+toreno+tohodi+tohono+tohodo+tohododi+tohodono);
gotoxy(4,15);printf("SUELDO BASICO.....................: %11.2f",sueldo);
gotoxy(6,15);printf("AUXILIO DE TRANSPORTE.............: %9.2f",atrans);
gotoxy(8,15);printf("RECARGO NOCTURNO..................: %7.2f",toreno);
gotoxy(10,15);printf("HORAS EXTRAS DIURNAS.............: %7.2f",tohodi);
gotoxy(12,15);printf("HORAS EXTRAS NOCTURNAS...........: %7.2f",tohono);
gotoxy(14,15);printf("HORAS DOMINICALES................: %7.2f",tohodo);
gotoxy(16,15);printf("HORAS DOMINICALES DIURNAS........: %7.2f",tohododi);
gotoxy(18,15);printf("HORAS DOMINICALES NOCTURNAS......: %7.2f",tohodono);
gotoxy(22,15);printf("TOTAL DEVENGADO..................: %11.2f",todeve);
parada;
clrscr;
cuadro();
eps=(sue * 4)/100;
fope=(sue * 3,325)/100;
if(sue>400000)
{
rt=(sue * 3)/100;
if (sue>700000)
{
rt=(sue * 5)/100;
}
}
if (pres==s)
{
prest=10000;
}
gotoxy(4,20);printf("DESCUENTOS EN NOMINA");
gotoxy(8,10);printf("E.P.S. = %7.2f",eps);
gotoxy(10,10);printf("RETENCION FUENTE: %7.2f",rt);
gotoxy(12,10);printf("TOTAL PRESTAMO: %d",prest);
gotoxy(14,10);printf("FONDO DE PENSIONES: %5.2f",fope);
todes=(eps + rt + prest);
gotoxy(16,10);printf("TOTAL DESCUENTO: %5.2f",todes);
parada;
clrscr;
cuadro();
neapa=(todeve - todes);
gotoxy(13,35);printf("NETO A PAGAR : %7.2f",neapa);
parada;
}
vecin()
{
clrscr;
cuadro();
gotoxy(04,10);printf("DIGITE LOS NUMEROS DEL VECTOR: ");
c=10;
for(l=0;l<=9;l++)
{
gotoxy(13,c);scanf("%d",&a[l]);
c=c + 3;
}
for(l=0;l<=8;l++)
{
for(j=l + 1;j<=9;j++)
{
aux=a[l];
a[l]=a[j];
a[j]=aux;
}
}
c=10;
for(l=0;l<=9;l++)
{
gotoxy(15,c);printf("%d",a[l]);
c=c+3;
}
parada;
}
factu()
{
cuadro();

gotoxy(3,6);printf("COMPANIA FUREZAS LTDA.");
gotoxy(5,6);printf("CLIENTE: ");
scanf("%s",&nom);
gotoxy(8,06);printf("CANTIDAD");
gotoxy(8,26);printf("ARTICULOS");
gotoxy(8,49);printf("VR/UNIT");
gotoxy(8,62);printf("VR/TOTAL");
f=10;
for (n=1;n<=10;n++)
{
gotoxy(f,6);scanf("%d",&can);
gotoxy(f,26);scanf("%s",&art);
gotoxy(f,49);scanf("%d",&vunit);
vato=(can * vunit);
gotoxy(f,62);printf("%d",vato);
}
}
pirino()
{
}
caracol()
{
}
