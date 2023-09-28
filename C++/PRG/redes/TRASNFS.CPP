#include<stdio.h>
#include<string.h>
#include<io.h>
#include<bios.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>

#define SETTINGS ( 0x80 | 0x02 | 0x00 | 0x00)
char nombre[100]="";

void enviarCOM2()
{
	FILE *d;
	char car;
	if((d=fopen(nombre,"rt"))!=NULL)			
	{
		
		bioscom(1,'*',1);		
		while(!feof(d))
		{
		  fread(&car,1,1,d);
		  putchar(car);
		  bioscom(1,car,1);	
		}
		bioscom(1,'!',1);		
		fclose(d);
	}
	else bioscom(1,'?',1);
}

void enviarCOM1()
{
	FILE *d;
	char car;
	
	if((d=fopen(nombre,"rt"))!=NULL)			
	{
		
		delay(900);
		bioscom(1,'*',0);		
		while(!feof(d))
		{
		  fread(&car,1,1,d);
		  putchar(car);
		  bioscom(1,car,0);	
		}
		bioscom(1,'!',0);		
		fclose(d);
	}
	else bioscom(1,'?',0);
}


void main()
{
	int meternombre,i,salir;
	char car;
	int PUERTO1=0,PUERTO2=0;

	clrscr();
	bioscom(0,SETTINGS,0);		
	bioscom(0,SETTINGS,1);		
	do
	{
		i=0;
		salir=0;
		meternombre=0;
		PUERTO1=PUERTO2=0;
		if((bioscom(2,0,1) & 0x7F)==8)
		{
			PUERTO2=1;
			bioscom(1,8,1);
			printf("\nentro en PUERTO1");

		}
		else if((bioscom(2,0,0) & 0x7F)==8)
		{
			PUERTO1=1;
			bioscom(1,8,0);
			printf("\nentro en PUERTO2");
		}
		while(PUERTO2 && !salir && !kbhit())
		{
			car=bioscom(2,0,1) & 0x7F;		
			putchar(car);
			switch(car)
			{
				case '*':meternombre=1;continue;break;
				case '$':enviarCOM2();salir=1;break;
			}
			if(meternombre)
			{
				nombre[i++]=car;
				nombre[i]=0;
			}
		}
		while(PUERTO1 && !salir && !kbhit())
		{
			car=bioscom(2,0,0) & 0x7F;		
			putchar(car);
			switch(car)
			{
				case '*':meternombre=1;continue;break;
				case '$':enviarCOM1();salir=1;break;
			}
			if(meternombre)
			{
				nombre[i++]=car;
				nombre[i]=0;
			}
		}
	}while(!kbhit());
}