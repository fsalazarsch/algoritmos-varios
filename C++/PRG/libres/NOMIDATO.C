#include<stdio.h>
#include<conio.h>
main()
{
int cod,i,vh,ch,sb,aux,dedu,deve,sn,sm,sm1,sm2;
sm=712000;
sm1=800000;
sm2=356000;
	for(i=0;i<=4;i++)
	{
	cod=0;vh=0;ch=0;sb=0;aux=0;dedu=0;deve=0;sn=0;
	clrscr();
	gotoxy(2,2); printf("*****************************************************");
	gotoxy(10,3); printf("            DATOS DE ENTRADA");
	gotoxy(10,6); printf("CODIGO             "); scanf("%d",&cod);
	gotoxy(10,8); printf("VALOR HORA         "); scanf("%d",&vh);
	gotoxy(10,10); printf("CANTIDAD HORAS    "); scanf("%d",&ch);
	gotoxy(2,12); printf("****************************************************");
	gotoxy(1,15); printf("COD.");
	gotoxy(8,15); printf("V.HORAS");
	gotoxy(20,15); printf("CANT.");
	gotoxy(30,15); printf("S.BRUTO");
	gotoxy(42,15); printf("DEVENG.");
	gotoxy(55,15); printf("DEDUC.");
	gotoxy(67,15); printf("NETO");
	sb=vh*ch;
	aux=(sb*12)/100;
	dedu=dedu+(sb-aux);
	if(sb>sm)
	{
		aux=0;
		aux=(sb*1)/100;
		dedu=dedu-aux;
	}
	if(sb>sm1)
	{
		aux=0;
		aux=(sb*2)/100;
		dedu=dedu-aux;
	}
	if(sb<sm2)
	{
		deve=deve+(sb+14000);
	}
	sn=(sb+deve)-dedu;
	gotoxy(1,17); printf("%d",cod);
	gotoxy(8,17); printf("%d",vh);
	gotoxy(20,17); printf("%d",ch);
	gotoxy(30,17); printf("%d",sb);
	gotoxy(42,17); printf("%d",deve);
	gotoxy(55,17); printf("%d",dedu);
	gotoxy(67,17); printf("%d",sn);
	getch();
 }
 }



