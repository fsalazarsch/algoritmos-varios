# include <stdio.h>
# include <conio.h>
int i,fil;
float subt;
struct cliente
{
char tel[30];
char dir[30];
char nom[30];
char fech[15];
};
struct factura
{
int cant,valor,sub;
char art[20];
char ref[5];
struct cliente clie;
}fac[3];

main()
{
clrscr();

gotoxy(3,7);puts("FECHA:    ");
gotoxy(3,8);puts("CLIENTE:  ");
gotoxy(3,9);puts("DIRECCION:");
gotoxy(48,9);puts("TELEFONO");
gotoxy(3,12);puts("REF");
gotoxy(15,12);puts("ARTICULO");
gotoxy(35,12);puts("CANTIDAD");
gotoxy(48,12);puts("VR UNIT");
gotoxy(61,12);puts("TOTAL");
for(i=0;i<=2;i++)
{
gotoxy(14,7);gets(fac[i].clie.fech);
gotoxy(14,8);gets(fac[i].clie.nom);
gotoxy(14,9);gets(fac[i].clie.dir);
gotoxy(60,9);gets(fac[i].clie.tel);
fil=14;
for(i=0;i<= 2;i++)
{
gotoxy(3,fil);gets(fac[i].ref);
gotoxy(15,fil);gets(fac[i].art);
gotoxy(35,fil);gets(fac[i].cant);
gotoxy(48,fil);gets(fac[i].valor);
fac[i].sub=fac[i].valor*fac[i].cant;
gotoxy(61,fil);printf("%d",fac[i].sub);
fil++;
}
getch();
}
clrscr();
gotoxy(3,7);puts("FECHA:    ");
gotoxy(3,8);puts("CLIENTE:  ");
gotoxy(3,9);puts("DIRECCION:");
gotoxy(45,9);puts("TELEFONO");
gotoxy(3,12);puts("REF");
gotoxy(10,12);puts("ARTICULO");
gotoxy(28,12);puts("CANTIDAD");
gotoxy(38,12);puts("VR  UNITARIO");
gotoxy(60,12);puts("TOTAL");
for(i=0;i<=2;i++)
{
gotoxy(14,7);printf("%s",fac[i].clie.fech);
gotoxy(14,8);printf("%s",fac[i].clie.nom);
gotoxy(14,9);printf("%s",fac[i].clie.dir);
gotoxy(60,9);printf("%s",fac[i].clie.tel);
fil=14;
for (i=0;i<=2;i++)
{
gotoxy(3,fil);printf("%s",fac[i].ref);
gotoxy(10,fil);printf("%s",fac[i].art);
gotoxy(28,fil);printf("%d",fac[i].cant);
gotoxy(38,fil);printf("%d",fac[i].valor);
fil++;
}
getch();
}
for (i=0;i<=2;i++)
{
subt=subt+fac[i].valor;
}
gotoxy(60,25);printf("%f",subt);

getch();
}
