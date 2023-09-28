//***********MATRIZ**************************


# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# include <iomanip.h>
# include <time.h>
# include <dos.h>
void TITULOS();
int MENU();
void PANTALLAZO();
void CUADRO();
void PRES();
main()
{
 int mat[100][100],vector[100];
 int menu,c,f,I,J,p,m,k;
 char op='S';
  textcolor(2);
 textbackground(1);
 PANTALLAZO();
 CUADRO();
 PRES();
 TITULOS();
  while (op=='S')
  {
  do{
  TITULOS();
 gotoxy(25,8);cout  <<"1-ASIGNAR TAMA¥O A LAS MATRICES";
 gotoxy(25,9);cout  <<"2- ASIGNAR VALOR A LA MATRIZ";
 gotoxy(25,10);cout <<"3- SUMA DE LAS COLUMNAS DE LA MATRIZ";
 gotoxy(25,11);cout <<"4- VECTOR RESULTANTE DE LA MATRIZ"; 
 gotoxy(25,12);cout <<"5- SALIR DEL PROGRAMA";
 gotoxy(16,20);cout <<"seleccione una alternativa y presione <<enter>>";
 gotoxy(65,20);cin>>menu;
 } while ((menu < 1) || (menu > 5)); 
  switch(menu)
  {
   case 1:
   TITULOS();
   gotoxy(20,8);cout<<"digite el tama¤o de la fila de la matriz [__] ";
   gotoxy(20,9);cout<<"digite el tama¤o de la columna de la matriz [__] ";
   gotoxy(62,8);cin>>f;
   gotoxy(65,9);cin>>c;
    break;
    case 2:
    TITULOS();
    gotoxy(25,6);cout<<"ASIGNAR VALORES A LA MATRIZ";
    for(I=0;I<f;I++)
     for(J=0;J<c;J++)
     {
      gotoxy(20,8);cout<<"DIGITE VALORES PARA LAS COORDENADAS ["<< I << "][" << J <<"]  [  ] ";gotoxy(65,8);cin>>mat[J][I];
     }
    break;
    case 3:
    TITULOS();
      for(I=0;I<c;I++)
       {
	 p=0;
	 for(J=0;J<f;J++)
	 {
	  p=p + mat[I][J];
	  vector[I]=p;
	 }
       }
     break;
     case 4:
     TITULOS();
     m=8;
     for(I=0;I<f;I++)
      {
      gotoxy(30,m);
      for(J=0;J<c;J++)
       {
	cout<<setw(5)<< mat[J][I]<<"  ";
	getch();
       }
      m+=2;
      }
      gotoxy(11,22);cout<<"vector resultante: ";
      for(I=0;I<c;I++)
      {
      cout<<setw(5)<< vector[I]<<"  ";
      getch();
      }
      break;
      case 5:
      op='N';
      break;
   }
  }
} 
void TITULOS()
{
 clrscr();
 CUADRO();
 gotoxy(20,3);cout<<"SUMATORIA DE LAS COLUMNAS DE UNA MATRIZ";
 gotoxy(29,4);cout<<"VECTOR UNIDIMENCIONAL";
} 
 void PANTALLAZO()
 {
  int X,Y,J=80,K=24,T=0,L=2,M=79,H=24;
  clrscr();
  gotoxy(32,13);cout<<"PRESENTACION";
  while(T<12)
  {
   --J;
   for(X=2;X<=J;X++)   
   {
    gotoxy(X,L);cout<<"Û";          
    gotoxy(X,H);cout<<"Û";
    delay(5);
    }
   --K;
   for(Y=2;Y<=K;Y++)
   {
    gotoxy(L,Y);cout<<"Û";
    gotoxy(M,Y);cout<<"Û";
    delay(5);
    }
   delay(5);
   ++T,++L,--M,--H;
   }
   clrscr();
 }
void CUADRO()
{
  int x,y;
  for(x=2;x<=79;x++)
  {
   gotoxy(x,2);cout<<"Û";
   gotoxy(x,24);cout<<"Û";
   delay(10);
  }                                                                   
  for(y=2;y<=24;y++)
  {
   gotoxy(2,y);cout<<"Û";
   gotoxy(79,y);cout<<"Û";
   delay(10);
  }
}
void PRES()
{ 
 gotoxy(26,5);cout<<"PARCIAL FINAL DE PROGRAMACION";
 gotoxy(22,8);cout<<"Profesor: CARLOS EMILIANO O¥ATE GOMEZ";
 gotoxy(22,10);cout<<"Presentado por:";
 gotoxy(26,12);cout<<"ALVARO ALFONSO CARRILLO ARAUJO";
 gotoxy(26,13);cout<<"HUGO MACIAS DIAZ";
 gotoxy(30,15);cout<<"­ FUTUROS INGENIEROS !";
 gotoxy(32,22);cout<<"NOTA PARCIAL = 20%";
 delay(7000);
}   