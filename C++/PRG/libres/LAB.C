# include <stdio.h>
# include <conio.h>
# include <ctype.h>
int col=40;
int fil=10;
void movimiento (void);
void diseno(void);
void cuadro (void)
{
 int i;
 for (i=20;i<=60;i++){
    gotoxy (i,5);
    printf("�");
    gotoxy (i,15);
    printf("�");
    }
 for(i=5;i<=15;i++){
      gotoxy (20,i);
      printf("�");
      gotoxy (60,i);
      printf("�");
      }
      gotoxy (20,5);
      printf("�");
      gotoxy (60,5);
      printf("�");
      gotoxy (20,15);
      printf("�");
      gotoxy (60,15);
      printf("�");
      gotoxy (40,10);
      printf("�");
      diseno ();
}
void diseno (void){
gotoxy(41,11);
printf("�");
gotoxy (41,12);
printf("�");
gotoxy (39,11);
printf("�");
gotoxy(39,12);
printf("�");
gotoxy (39,13);
printf ("�");
gotoxy(40,13);
printf("����");
gotoxy(42,12);
printf("������");
movimiento ();
}
void abajo(void){
 gotoxy  (col,fil-1);
 printf(" ");
 gotoxy (col,fil);
 printf("�");
 fil=fil+1;
 }

void movimiento (void){
 int o;
 char op;
 do{
 gotoxy (col,fil);
 o=getch ();
 }while((o==2)||(o==4));
 switch(o){
 case 50:gotoxy(col,fil+1);
	op=getchar();
	if (op==' ')
	  abajo();
	  break;
   case 4:gotoxy (col,fil);
   }

}
void main (void){
clrscr ();
cuadro ();
getch ();
}