#include<conio.h>
#include<string.h>
#include<stdio.h>


int QUE_LIO,x=0,a=0,za=0,b=0,op,pp,ll,aw=0,bq=0,as=0,bm=0,ch=0,chr=0,chl=0,chk=0,
chw=0,chtu=0,chtl=0,chts=0,cha=0,che=0,chi=0,chv=0,chb=0,chh=0,cht=0,au=0,
bk=0,ar=0,bz=0,ad=0,bf=0,an=0,be=0,at=0,bd=0,ay=0,bv=0,ax=0,bi=0,ag=0,bh=0,
ak=0,bb=0,sa=0,avv=0,h=0,avi=0,bag=0,agt=0,bfm=0;

double di[10][2],que[10][2],si[10][2],se[10][2],tra[10][2],ba[10][2],ja[10][2],
ob[10][2],te[10][2],ne[10][2],mos[10][2],un[10][2],bu[10][2],en[10][2],re[10][2],
sul,ta,doo,lt,el,zt,la,tu,to,es,zw,zs,lq,uh,hq,ji,th,hj,gt,ga,gh,rq,rs,ri,yu,
yv,yb,bn,bx,bc,fa,fe,fi,elu,zit,lat,rty,see,saa,eae,job,jib,boi,via,voo,oai;

main()
{
presentacion();
menu();
submenu();
while(QUE_LIO!=3);}
presentacion()
{
clrscr();
textbackground(1);
textcolor(15);
gotoxy(24,4);
textcolor(15);
cprintf("UNIVERSIDAD AUTONOMA DE COLOMBIA");
gotoxy(23,8);
textcolor(15);
cprintf("      CONTABILIDAD");
gotoxy(23,13);
textcolor(15);
cprintf(" PRESENTADO POR:");
gotoxy(23,14);
textcolor(15);
cprintf("               ROBERTO AUGUSTO FERNANDEZ");
gotoxy(23,15);
textcolor(15);
cprintf("                            CODIGO # 4109244");
gotoxy(24,20);
textcolor(15);
cprintf("      SANTA FE DE BOGOTA,D.C");
gotoxy(25,21);
textcolor(15);
cprintf("             1.994.   ");
delay (19000);
/*putchar(7);*/

menu();
getch();
return 0;
}

menu()
{
clrscr();
textbackground(1);
textcolor(15);
gotoxy(20,9);
textcolor(12);
cprintf("M E N U   P R I N C I P A L") ;
gotoxy(24,11);
textcolor(2);
cprintf(" 1. Cuentas T ");
textcolor(2);
gotoxy(24,12);
textcolor(2);
cprintf(" 2. Balance de Prueba ");
gotoxy(24,13);
textcolor(2);
cprintf(" 3. Salir ");
gotoxy(34,16);
textcolor(14);
cprintf("Digite su opcion porfavor ");
scanf("%d",&QUE_LIO);
if(QUE_LIO==1)
{
submenu();
menu();
}
if(QUE_LIO==2)
{
balance();
menu();

}
if(QUE_LIO==3);
{
exit ();
}
return 0;
}

submenu()
{
clrscr();
gotoxy(18,3);
textcolor(4);
cprintf("*****                                    *****");
gotoxy(23,3);
textcolor(3);
cprintf(" S U B M E N U   D E   C U E N T A S ");
textcolor(14);
gotoxy(28,6);
cprintf("1. CAJA");
textcolor(14);
gotoxy(28,7);
cprintf("2. BANCO");
textcolor(14);
gotoxy(28,8);
cprintf("3. CLIENTES");
textcolor(14);
gotoxy(28,9);
cprintf("4. ACCIONES");
textcolor(14);
gotoxy(28,10);
cprintf("5. APORTES");
textcolor(14);
gotoxy(28,11);
cprintf("6. COMP.MERCANCIA");
textcolor(14);
gotoxy(28,12);
cprintf("7. VENT.MERCANCIA");
textcolor(14);
gotoxy(28,13);
cprintf("8. TERRENO");
textcolor(14);
gotoxy(28,14);
cprintf("9. HIPOTECA");
textcolor(14);
gotoxy(28,15);
cprintf("10. MUEBLES");
textcolor(14);
gotoxy(28,16);
cprintf("11. CTAS*PAG ");
textcolor(14);
gotoxy(28,17);
cprintf("12. SUELDOS");
textcolor(14);
gotoxy(28,18);
cprintf("13. CTAS*COBR");
textcolor(14);
gotoxy(28,19);
cprintf("14. COMP.EDIFICIO");
textcolor(14);
gotoxy(28,20);
cprintf("15. GASTOS BANCARIOS");
textcolor(14);
gotoxy(28,21);
cprintf("16. SALIR");
textcolor(15);
gotoxy(42,23);
cprintf("Digite La Opcion Que Desees??  ");
/*putchar(7);  */
scanf("%d",&pp);
if(pp==1)
{
nuca();
}
if(pp==2)
{
nuca1();
}
if(pp==3)
{
nuca2();
}
if(pp==4)
{
nuca3();
}
if(pp==5)
{
nuca4();
}
if(pp==6)
{
nuca5();
}
if(pp==7)
{
nuca6();
}
if(pp==8)
{
nuca7();
}
if(pp==9)
{
nuca8();
}
if(pp==10)
{
nuca9();
}
if(pp==11)
{
nuca10();
}
if(pp==12)
{
nuca11();
}
if(pp==13)
{
nuca12();
}
if(pp==14)
{
nuca13();
}
if(pp==15)
{
nuca14();
}
if(pp==16)
{
menu();
}
getch();
}

/* PROCEDIMIENTOS DE LA CAJA */


nuca()
{
clrscr();
gotoxy(23,8);
textcolor(4);
cprintf("@@@ S U B M E N U   D E   C A J A @@@");
gotoxy(26,12);
textcolor(3);
cprintf("1. Ingresar datos");
gotoxy(26,13);
textcolor(3);
cprintf("2. Imprimir y Total");
gotoxy(26,14);
textcolor(3);
cprintf("3. Regresar a submenu");
gotoxy(45,17);
textcolor(14);
cprintf("Digite la opcion deseada ?  ");
scanf("%d",&ll);
if(ll==1)
{
caja();
nuca();
}
if(ll==2)
{
ipro();
nuca();
}
if(ll==3)
{
submenu();
}
}


caja()
{
int i;
doo=0,ta=0,sul=0;
clrscr();
gotoxy(26,4);printf("****  C  A  J  A  ****");
for(i=15;i<=60;i++)
{
gotoxy(i,6);
textcolor(0);
cprintf("Ä");
gotoxy(i,8);
textcolor(0);
cprintf("Ä"); }
for(i=3;i<=20;i++)
{
gotoxy(36,i+3);
textcolor(0);
cprintf("³");
gotoxy(36,6);
cprintf("Â");
}
gotoxy(19,7);
textcolor(4);
cprintf("       DEBE      ³        HABER");
gotoxy(40,23);
textcolor(10);
cprintf("Escoja si es DEBE 1, HABER 2 ____");
scanf("%d",&x);
for(i=0;i<a;i++)
{
gotoxy(16,i+9);printf("%ld",di[i][1]);   /*9*/
}
for(i=0;i<b;i++)
{
gotoxy(37,i+9);printf("%ld",di[i][2]);

}
if(x==1)
{
gotoxy(16,a+9);scanf("%ld",&di[a][1]);
a++;
}
else
{
gotoxy(37,b+9);scanf("%ld",&di[b][2]);
b++;
}
for(i=0;i<a;i++)
{
sul =sul+di[i][1];
}
for(i=0;i<b;i++)
{
ta = ta+di[i][2];
}
if(sul>=ta)
{
doo = sul-ta;
ch=0;
}
else
{
ch=1;
doo = ta-sul;
}
nuca();
}

ipro()
{
int i;
clrscr();
if(ch==1)
{
/*textcolor(128);clrscr(); */
gotoxy(40,22);printf("TOTAL HABER = %ld",doo);
gotoxy(40,23);printf("SALDO ROJO");
}
else
{
textcolor(1);
gotoxy(40,21);cprintf("TOTAL DEBE = %ld",doo);
}
/*textcolor (1); */
gotoxy(30,2);printf("****  C  A  J  A  ****");
for(i=15;i<=60;i++)
{
gotoxy(i,6);
textcolor(0);
cprintf("Ä");
gotoxy(i,8);
textcolor(0);
cprintf("Ä"); }
for(i=3;i<=20;i++)
{
gotoxy(36,i+3);
textcolor(0);
cprintf("³");
gotoxy(36,6);
cprintf("Â");
}
gotoxy(19,7);
textcolor(4);
cprintf("       DEBE      ³        HABER");
for(i=0;i<a;i++)
{
gotoxy(16,i+9);printf("%ld",di[i][1]);
}
for(i=0;i<b;i++)
{
gotoxy(37,i+9);printf("%ld",di[i][2]);
}
getch ();
submenu();
}






/* PROCEDIMIENTOS BANCOS */

nuca1()
{
clrscr();
gotoxy(23,8);
textcolor(4);
cprintf("@@@  S U B M E N U   D E   B A N C O  @@@");
gotoxy(26,12);
textcolor(3);
cprintf("1. Ingresar datos");
gotoxy(26,13);
textcolor(3);
cprintf("2. Imprimir y Total");
gotoxy(26,14);
textcolor(3);
cprintf("3. Regresar a submenu");
gotoxy(45,17);
textcolor(14);
cprintf("Digite la opcion deseada ?  ");
scanf("%d",&ll);
if(ll==1)
{
banco();
nuca1();
}
if(ll==2)
{
ipro1();
nuca1();
}
if(ll==3)
{
submenu();
}
}


banco()
{
int i;
el=0,zt=0,lt=0;
clrscr();
gotoxy(26,5);printf(" **** B A N C O S ****");
for(i=15;i<=60;i++)
{
gotoxy(i,6);
textcolor(0);
cprintf("Ä");
gotoxy(i,8);
textcolor(0);
cprintf("Ä"); }
for(i=3;i<=20;i++)
{
gotoxy(36,i+3);
textcolor(0);
cprintf("³");
gotoxy(36,6);
cprintf("Â");
}
gotoxy(19,7);
textcolor(4);
cprintf("       DEBE      ³        HABER");
gotoxy(40,23);
textcolor(10);
cprintf("Escoja si es DEBE 1, HABER 2 ____");
scanf("%d",&x);
for(i=0;i<aw;i++)
{
gotoxy(16,i+9);printf("%ld",que[i][1]);
}
for(i=0;i<bq;i++)
{
gotoxy(37,i+9);printf("%ld",que[i][2]);
}
if(x==1)
{
gotoxy(16,aw+9);scanf("%ld",&que[aw][1]);
aw++;
}
else
{
gotoxy(37,bq+9);scanf("%ld",&que[bq][2]);
bq++;
}
for(i=0;i<aw;i++)
{
el = el + que[i][1];
}
for(i=0;i<bq;i++)
{
zt = zt + que[i][2];
}
if(el>=zt)
{
lt = el-zt;
chr=0;
}
else
{
chr=1;
lt = zt-el;
}

nuca1();
}

ipro1()
{
int i;
clrscr();
if(chr==1)
{
gotoxy(40,22);printf("TOTAL HABER = %ld",lt);
gotoxy(40,23);printf("SALDO ROJO");
}
else
{
textcolor(4);
gotoxy(40,21);printf("TOTAL DEBE = %ld",lt);
}
textcolor(128);
gotoxy(30,2);cprintf("**** B A N C O S ****");
for(i=15;i<=60;i++)
{
gotoxy(i,6);
textcolor(0);
cprintf("Ä");
gotoxy(i,8);
textcolor(0);
cprintf("Ä"); }
for(i=3;i<=20;i++)
{
gotoxy(36,i+3);
textcolor(0);
cprintf("³");
gotoxy(36,6);
cprintf("Â");
}
gotoxy(19,7);
textcolor(4);
cprintf("       DEBE      ³        HABER");
for(i=0;i<aw;i++)
{
gotoxy(16,i+9);printf("%ld",que[i][1]);
}
for(i=0;i<bq;i++)
{
gotoxy(37,i+9);printf("%ld",que[i][2]);
}

getch ();
submenu();
}


/* PORCEDIMIENTOS DE CLIENTES */


nuca2()
{
clrscr();
gotoxy(23,8);
textcolor(4);
cprintf("@@@  S U B M E N U   D E   C L I E N T E S  @@@");
gotoxy(26,12);
textcolor(3);
cprintf("1. Ingresar datos");
gotoxy(26,13);
textcolor(3);
cprintf("2. Imprimir y Total");
gotoxy(26,14);
textcolor(3);
cprintf("3. Regresar a submenu");
gotoxy(45,17);
textcolor(14);
cprintf("Digite la opcion deseada ?  ");
scanf("%d",&ll);
if(ll==1)
{
clientes();
nuca2();
}
if(ll==2)
{
ipro2();
nuca2();
}
if(ll==3)
{
submenu();
}
}

clientes()
{
int i;
la=0,tu=0,to=0;
clrscr();
gotoxy(26,5);printf(" **** C L I E N T E S ****");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         