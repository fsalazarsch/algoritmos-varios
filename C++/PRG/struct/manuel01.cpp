
#include "stdio.h"
#include "conio.h"
#define forxn for(x=0;x<n;x++)
#define forjn for(j=0;j<n;j++)

void main(void)
{
int x,j,n,a[10][10];
clrscr();
gotoxy(12,1);
printf("********************************");
gotoxy(14,2);
printf("UNIVERSIDAD ANTONIO NARIÑO");
gotoxy(16,3);
printf("INGENIERIA DE SISTEMAS");
gotoxy(18,4);
printf("MANUEL GUERRA CHICA");
gotoxy(12,5);
printf("********************************");

gotoxy(12,8);
printf("INDIQUE EL TAMAÑO DE LA MATRIZ: ");
scanf("%d",&n);
printf("\n                INTRODUZCA LOS NUMEROS\n");
  forxn
     forjn
      {
       
       gotoxy(18+x*6,j+12);
       scanf("%d",&a[x][j]);
      }
}