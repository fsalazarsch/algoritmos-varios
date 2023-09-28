#include<stdio.h>
#include<conio.h>

void main()
{
int NAN[10],i,n,aux;
clrscr();
textcolor(15+129);
textbackground(3);
gotoxy(15,1);
cprintf("!*** GRACIAS POR ENTRAR***­");
gotoxy(48,5);
textcolor(4);
cprintf("HERNAN ACU¥A ROMERO");
gotoxy(51,6);cprintf("COD:96131065");

gotoxy(4,4);
printf("DIGITE DIMENSION DEL VECTOR: ");
scanf("%d",&n);
printf("\n");
   for(i=1;i<=n;i++){
   printf("%s%d%s","DIGITE EL NUMERO DEL VECTOR NAN[",i,"] : ");
   scanf("%d",&NAN[i]);
  }
  printf("\n");
  printf("\n");
   for(i=1;i<=n;i++){
   printf("%d\t",NAN[i]);
    } 
   aux=0;
  for(i=1;i<=n/2;i++){
  aux=NAN[i];
  NAN[i]=NAN[(n+1)-i];
  NAN[(n+1)-i]=aux;
  }
    printf("\n\n");
    printf("EL VECTOR INVERTIDO\n");
    printf("\n");
    for(i=1;i<=n;i++){
    printf("%d\t",NAN[i]);
  }
  textcolor(4+214); 
  gotoxy(18,25);cprintf("DIGITE <<ENTER>> PARA SALIR");
 getch();
 }
 


