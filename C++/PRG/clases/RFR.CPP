#include "stdio.h"
#include "conio.h"
#define limveC1 90
#define limveC2 70
#define limveC3 120
#define limveC4 150
#define multC1 1000
#define multC2 1200
#define multC3 14200
#define multC4 50000

int  cuad,limivec,totmulta,velvehi,scuad2=0,scuad3=0,scuad4=0,i=1;
int velocidad,cuadrante,valmul,regvehi,scuad1=0;
char res;
long int sum=0,sumC1,sumC2,sumC3,sumC4,smul1,mult,smul2,smul3,smul4;
void main()

 {
   clrscr();
   gotoxy(2,3);printf(" REG VEHI   VELOCIDAD   CUADRANTE     MULTA  "   );
   do
   { gotoxy(2,3+i);scanf ("%d",&regvehi);
     gotoxy(14,3+i);scanf("%d",&velvehi);
     gotoxy(24,3+i);scanf("%d",&cuad);



      if (cuad==1)
	{
	  if (limveC1<velvehi)
	    {
	      if(velvehi<limveC1)
		 mult=0;
		 else
		   {
		     mult=((velvehi-limveC1)* multC1);
		     scuad1=scuad1+1;
		     sumC1=sumC1+mult;
		    }
	    }
	}
      else
	{  if (cuad==2)
	     { if (limveC2<velvehi)

	       { mult=((velvehi-limveC2)* multC2);
		 scuad2=scuad2+1;
		 sumC2=sumC2+mult;
	       }
	     }
	    else

	     {
	       if (cuad==3)
		 {
		   if (limveC3<velvehi)
		   {
		     mult=((velvehi-limveC3)* multC3);
		     scuad3=scuad3+1;
		     sumC2=sumC2+mult;
		    }
		 }

	     else

		{
		  if (limveC4<velvehi)
		   {
		     mult=((velvehi-limveC4)* multC4);
		     scuad4=scuad4+1;
		     sumC4=sum+mult;
		    }
		}
	     }
	     }
		  gotoxy(40,10);printf("%ld",mult);

			   totmulta=(smul1+smul2+smul3+smul4);



	  gotoxy(2,24);printf("desea continuar s/n");
	  res=getch();
	  }
       while (res!='n');

	gotoxy(2,10);printf("LA INFRACCION  FUE LEVANTADA EN EL CUADRANTE: %d", cuad);
	gotoxy(2,11);printf("LAS INFRACCIONES EN EL CUADRANTE1 ES: %d", scuad1);
	gotoxy(2,12);printf(" LAS MULTAS DEL CUADRANTE1 ES: %d");
	gotoxy(2,13);printf("LAS INFRACCIONES DEL CUADRANTE2 ES: %d", scuad2);
	gotoxy(2,14);printf("LAS INFRACCIONES DEL CUADRANTE3 ES: %d", scuad3);
	gotoxy(2,15);printf("LAS INFRACCIONES DEL CUADRANTE4 ES : %d", scuad4);
	gotoxy(2,16);printf("EL TOTAL RECAUDADO DE LAS MULTAS ES: %d",totmulta);

	getch();


      }
