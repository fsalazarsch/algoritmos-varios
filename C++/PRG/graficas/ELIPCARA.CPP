#include"conio.h"       
#include<stdlib.h>
#include"stdio.h"
#include"dos.h"
#include<iostream.h>
void elipse1();
 void elipse2();
void caracol();
void cuadro();
void menu();
/*******************************/
void main(){
  menu();
  clrscr();
  }
/*************E L I P S E . 1 **********/
void elipse1()
{
   int i,h=2,j,sw=0,n,m;
   int mat[30][30];
    clrscr();
     gotoxy(5,4);cout<<"DINENCION FILAS Y COLUMNAS:";
     cin>>n;
     clrscr();
     gotoxy(3,2);cout<<"DIGITE LA MATRIZ\n";
	for (i =0 ; i <  n ; i++)
	{

	 for (j = 0 ;j<  n ; j++)
	   {
	    gotoxy(j*n+3,i+5);
	    cin>>mat[i][j];
	   }
	 }
	 clrscr();
	 cout<<"MATRIZ NORMAL\n";
	 for(i=0;i<n;i++)
	 {
	 for(j=0;j<n;j++)
	  {
	   cout<<"\t"<<mat[i][j];
	  }
	  cout<<"\n";
	}

	  j=n-1;
       cout<<"\n\nRECORRIDO\n\n";
       for(i=0;i<n;i++)
       {
	 sw=1;
	 while(sw)
	 {

	if(j<0 || j >n-1)
	{
	 sw=0;
	 if(i%2==0)
	 j=0;
	   else
	 j=n-1;
	 cout<<"\n";
	 }
   else
   {
   delay(500);// PARA QUE IMPRIMA UN NUMERO Y LUEGO EL OTRO
   gotoxy(10+j*3,15+i);
   textcolor(h);// H REPRESENTA EL COLOR
   cprintf("%d\n",mat[j][i]); // IMPRIMO EL RECORRIDO

   if(i%2==0)
   j--;
   else
   j++;
   }
   }
   h++;// INCREMENTO H PARA CAMBIAR DE COLOR

  }
 // gotoxy(j*10+2,i+15);textcolor(h);  cout<<"PULCE <<ENTER>> PARA SALIR";

    getch();
 }
/*************C A R A C O L**************/
void caracol()
{
 int A,FC,i,j,x,k,n,h=2;   //FC REPRESENTAN FILAS Y COLUMNAS
  int matriz[50][50];
  clrscr();
  textcolor(1);
  cout<<"\n "<< " DIGITE EL TAMA¥O DE LA MATRIZ :  ";
  scanf("%d",&FC);
   clrscr();
  A=k=x=0;
  gotoxy(2,3);cout<<"DIGITE LA MATRIZ";
  for(i=A;i<FC;i++)
   for(j=A;j<FC;j++)
    {
     gotoxy(j*FC+3,i+5);
     scanf("\n\n");
     scanf("%c",&matriz[i][j]);
    }

  n=FC*2-1;
  clrscr();
  for(i=A;i<n;i++)
  { for(j=A;j<FC;j++)
    { if(i%2==0)
      { if(x==A)
       k=j;
	else
	{ if(k==A) break;
	  k--;
	}
      }
      else
      { if(k==FC-1)
	{ if(x==FC-1) break;
	  x++;
	}
	else
	{ if(x==A+1) break;
	  x--;
	}
      }
      delay(300);
      gotoxy(k*6+8,x+3);textcolor(h+1);cprintf("%c\n",matriz[x][k]);
    }  h++;
    if((i+1)%4==0)
    { A++;
    FC--; }
  }
       gotoxy(k*10+2,x+15);textcolor(h);  cout<<"PULCE <<ENTER>> PARA SALIR";
  getche();
}
/***********************************/
 void elipse2()
 {
 int i,h=2,j,sw=0,n,m;
int mat[30][30];
clrscr();
     gotoxy(22,2); cout<<" M A T R I Z  A";

   gotoxy(5,4);cout<<"DINENCION FILAS Y COLUMNAS:";
	cin>>n;


 clrscr();
 gotoxy(3,2);cout<<"LLene La Matriz \n";
for (i =0 ; i <  n ; i++){

    for (j = 0 ;j<  n ; j++){

 gotoxy(j*n+3,i+5);
 cin>>mat[i][j];
	 }
       }
clrscr();
cout<<"MATRIZ DIGITADA\n\n";
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    cout<<"\t"<<mat[i][j];
    }
  cout<<"\n";
  }

    j=n-1;
cout<<"\n\nRECORRIDO\n\n";
for(i=0;i<n;i++){
   sw=1;
   while(sw){

   if(j<0 || j >n-1){
	sw=0;
    if(i%2==0)
    j=0;
    else
    j=n-1;
    cout<<"\n";
    }
   else
   {delay(500);
   gotoxy(10+i*3,15+j);
   textcolor(h);cprintf("%d\n",mat[i][j]);

   if(i%2==0)
   j--;
   else
   j++;
       }
   } 
 h++;
  }
  gotoxy(j*10+2,i+15);textcolor(h);  cout<<"PULCE <<ENTER>> PARA SALIR";

 getch();
 }
/***************C U A D R O***********************************/
void cuadro(int x1,int x2,int y1,int y2)
{    int j,i,k;

		textbackground(0);
		textcolor(14);
     for(j=x1;j<=x2;j++)
       {
		 textcolor(9);delay(1);

		 gotoxy(j,y1);cprintf("*");
		 gotoxy(j,y2);cprintf("*");
		 }
	  for(i=y1;i<=y2-1;i++)
		 {
		 textcolor(9);delay(5);
		 gotoxy(x1,i);cprintf("*");
		 gotoxy(x2,i);cprintf("*");
		 }
	  textcolor(15);
	  gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
}

/**************************** ******************/
void menu()
{ char c;
   clrscr();
   while(1)
    {
	  cuadro(20,60,6,20);//TERCER CUADRO
	  cuadro(11,70,3,23);//primer cuadro
	  cuadro(15,65,5,21); // CUADRO DOS
	  cuadro(13,68,4,22);
	  cuadro(27,52,9,18);//CUARTO CUADRO
	  gotoxy(27,7);textcolor(3+129);cout<<" M E N U  P R I N C I P A L\n";
	  gotoxy(34,11);textcolor(9);delay(50);cout<<"É**********»";
	  gotoxy(34,12);textcolor(9);delay(50);cout<<"º1.CARACOL º";
	  gotoxy(34,13);textcolor(9);delay(50);cout<<"º2.ELIPSE 1º";
	  gotoxy(34,14);textcolor(9);delay(50);cout<<"º3.ELIPSE 2º";
	  gotoxy(34,15);textcolor(9);delay(50);cout<<"º4.SALIR   º";
	  gotoxy(34,16);textcolor(9);delay(50);cout<<"È**********¼";
	  gotoxy(30,18);textcolor(9+128);cout<<"DIGITE UNA OPCION:[ ] ";
	  gotoxy(30,20);textcolor(4);cout<<"**TATIANA QUINTERO**";
	  gotoxy(49,18);c=getche();

	  switch(c)
	  {
		case '1':caracol();clrscr();break;
		case '2':elipse1();clrscr();break;
		case '3':elipse2();clrscr();break;
		case '4':exit(0);
	   }

	}
}
/*******************************************************************/



