#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#define MAXIMO 100
#include"dos.h"

void main() /*INVERTIR LOS DATOS DE UN VECTOR*/
{
int vect[MAXIMO],i,n,pos1,pos2,aux=0;
clrscr();
printf("DIGITE LIMITE DEL VECTOR: ");
scanf("%d",&n);
printf("\n");
if(n>MAXIMO){
printf("DESBORDAMIENTO LIMITE DEL VECTOR \n");
getch();
exit(0);
}
 else
   {
   for(i=1;i<=n;i++){
   printf("%s%d%s","DIGITE VALOR DEL VECTOR EN LA POSICION [",i,"] :");
   scanf("%d",&vect[i]);
  }
  printf("\n");
  printf("EL VECTOR NORMAL\n");
  printf("\n");
   for(i=1;i<=n;i++){
   printf("%d\t",vect[i]);
  }
  getch();
 for(i=0;i<n;i++){

  aux=vect[i];
  vect[i]=vect[(n+1)-i];
  vect[(n+1)-i]=aux;
  }

	printf("\n\n");
	printf("EL VECTOR INVERTIDO\n");
	printf("\n");
	for(i=1;i<=n;i++){
	sound((i*652)/2);
	delay(170);
	//delay(1000);
	printf("%d\t",vect[i]);
  }
 nosound();
 gotoxy(6,22);
 textcolor(128+3);
 cprintf("GRACIAS POR OBSERVARLO");
 getch();
 }
 }


