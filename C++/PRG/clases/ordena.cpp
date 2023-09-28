# include <stdio.h>
# include <conio.h>
# define FORIN for(i=0;i<num;i++)
# define FORJN for(j=0;j<num;j++)
# define FORRN for(r=0;r<num;r++)
# define FORSN for(s=0;s<num;s++)

void main(void)
{
 /* Este programa realiza una ordenación ascendentemente en una matriz

 Defino Variables*/
 int i,j,r,s,num,aux,x,matriz[10][10];


 /*Cargo la Matriz*/
 clrscr();
 printf("INDIQUE EL TAMANO DE LA MATRIZ A ORDENAR ---> ");
 scanf("%d",&num);
 printf("\n DIGITE LOS VALORES DE LA MATRIZ :\n\n");
 FORIN
 FORJN
     {
     gotoxy(5*(j+1),(i+5)*2);
     scanf("%d",&matriz[i][j]);
      }

 /* Ordeno la Matriz*/
 FORIN
    {
   FORJN
     {
      FORRN
       {
	FORSN
	 {
	 if(matriz[r][s]>matriz[i][j])
	  {
	   aux=matriz[i][j];
	   matriz[i][j]=matriz[r][s]; 
	   matriz[r][s]=aux;
	   } 
         }
       }
     }
   }

   /*Imprimo la matriz*/
   printf("\n\n ESTA ES LA MATRIZ ORDENADA : ");
   FORIN
   FORJN
       {
       gotoxy(5*(j+1),(i+10)*2);
       printf("%d ",matriz[i][j]);
       }
   printf("\n\n Este programa ha terminado... ");
   printf ("\n Cierre la ventana por favor! ");

 }   