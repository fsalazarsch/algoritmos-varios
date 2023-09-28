//***************VECTORES*********************


#include <iostream.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
void cuadro(int C1,int F1,int C2,int F2);
void cuadro(int C1,int F1,int C2,int F2)
{
  int i;
  for(i=C1+1;i<C2;i++){
  gotoxy(i,F1);cprintf("Í");delay(1.8);gotoxy(i,F2);cprintf("Í");delay(10.8);}
  for(i=F1+1;i<F2;i++){
  gotoxy(C1,i);cprintf("º");delay(1.8); gotoxy(C2,i);cprintf("º");delay(10.8);}
  gotoxy(C1,F1);cprintf("É");gotoxy(C1,F2);cprintf("È");
  gotoxy(C2,F1);cprintf("»");gotoxy(C2,F2);cprintf("¼");
 }

void TITULOS();
int i,j;
void inicio();
void main(void)
{
clrscr();
int I,N,J,M,e;
char OP = 's';
int VEC1[100];
int VEC2[100];
while (OP == 's')
   {
   inicio();
   TITULOS();
   cuadro(3,2,79,24);
    textcolor(YELLOW);
    textbackground(RED);
     gotoxy(15,9); cout << "INDIQUE LOS ELEMENTOS QUE TENDRA EL VECTOR [   ]";
     gotoxy(60,9); cin>>N;
      for (I=0;I<N;I++)
       {
	 gotoxy(22,10); cout << "DIGITE UN NUMERO EN LA POSICION " << I+1 << "  [     ] ";
	 gotoxy(58,10); cin>>VEC1[I];
       }
       TITULOS();
       cuadro(3,2,79,24);
       cuadro(8,4,74,20);
       textcolor(YELLOW);
       textbackground(RED);
	gotoxy(15,10); cout << "DIGITE UN NUMERO   ";cin>> M;
	e=0;
	 for (I=0;I<N;I++)
	 {
	   if (M == VEC1[I])
	  { e=VEC1[I];
	    gotoxy(27,15);cout<<"EL NUMERO " << e <<" ESTA EN EL VECTOR        " ;
	  }
	  else
	  { gotoxy(27,15);cout<<"EL NUMERO " << M <<" NO EXISTE EN EL VECTOR   ";}
	  }
	     do{
		gotoxy(35,17); cout <<" si desea continuar presione s/n " ;
		OP = getch();
		OP = tolower(OP);
	     } while ((OP != 's') && (OP != 'n'));

 }
}


void TITULOS()
  {
  clrscr();
  gotoxy(20,6); cout << " CAPTURA, CONSULTA Y SUMA DE DOS VECTORES ";
  gotoxy(26,7); cout << " UNIDIMENSIONALES - VECTOR ";
  }


void inicio()
{
int i,j;
clrscr();
 cuadro(3,2,79,24);
gotoxy(20,11);cout<<"PARCIAL FINAL DE PROGRAMACION DE COMPUTADORES";
gotoxy(21,13);cout<<"PRESENTADO AL PROFESOR CARLOS O¥ATE GOMES";
gotoxy(24,15);cout<<"LIBANNYS FRANCISCO ARGUELLES DAZA";
gotoxy(33,22);cout<<"favor presionar <enter> para continuar"; getch();
clrscr();
textcolor(15); textbackground(17);
for(i=1; i<26; i++)
{
for(j=1; j<81; j++)
{
delay(1);
gotoxy(j,i); cout<<"²°";

}

}
}

