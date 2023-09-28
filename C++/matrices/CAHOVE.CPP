#include<stdio.h>
#include<dos.h>
#include <iostream.h>
#include<conio.h>
int i,j,x,y,n;
int sw=0,m;
void horizontal ();
void vertical ();
void caracol ();
void menu ();
void main ()
{

 char op;
 textbackground(32);
 textcolor(20);
 clrscr();
 while(op!='4')
 {
 clrscr();

 gotoxy(25,12);cout<<"  M E N U  P R I N C I P A L"  ;
 gotoxy(30,15);cout<<  "1) HORIZONTAL";
 gotoxy(30,17);cout<<  "2) VERTICAL";
 gotoxy(30,19);cout<<  "3) CARACOL ";
 gotoxy(30,21);cout<<  "4) SALIR ";
 gotoxy(30,23);cout<<  "DIGITE UNA OPCION ::>  ";op=getchar();
 switch(op)
 {
	  case '1': horizontal();break;
	  case '2': vertical ();break;
	  case '3': caracol (); break;

 }
   }
	}
/*******************************CARACOL*************************************/
void caracol()
{
  int mayor,menor;
  char mat[10][10];
  clrscr();
  printf("DIGITE EL LIMITE DE LA MATRIZ: ");
  scanf("%d",&mayor);
  menor=y=x=0;
  for(i=0;i<mayor;i++)
   for(j=0;j<mayor;j++)
    { printf("DIGITE EL DATO: [%d,%d] ",i+1,j+1);scanf("\n");
	 scanf("%c",&mat[i][j]);
    }
 clrscr();
  for(i=menor;i<n;i++)
  { for(j=menor;j<mayor;j++)
    { if(i%2==0)
	 { if(x==menor) y=j;
	else
	{ if(y==menor) break;
	  y--;
	}


	 }
	 else
	 { if(y==mayor-1)
	{ if(x==mayor-1) break;
	  x++;
	}
	else
	{ if(x==0+1) break;
	  x--;
	}
	 }
	 delay(300);
	 gotoxy(y*6+12,x+6);
	  printf("%c",mat[x][y]);

	   }
    if((i+1)%4==0)
    { menor++; mayor--; }
  }
  getche();
}
/********************************VERTICAL************************************/
void vertical()
{
int mat[30][30];
clrscr();
	 gotoxy(3,2);cout<<"DIGITE LIMITE DE LA MATRIZ:";
	cin>>n;


 clrscr();
 gotoxy(4,2);cout<<"INGRESE DATOS\n";
for (i =0 ; i <  n ; i++){

    for (j = 0 ;j<  n ; j++){

 gotoxy(j*n+3,i+5);
 cin>>mat[i][j];
	 }
	  }
clrscr();
cout<<"MATRIZ EN ESTADO NORMAL\n";
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    cout<<"\t"<<mat[i][j];
    }
  cout<<"\n";
  }

    j=n-1;
cout<<"\n\nMATRIZ EN FORMA VERTICAL";
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
   {delay(300);
   gotoxy(10+(i*6),10+(j*2));
   cprintf("%d\n",mat[j][i]);

   if(i%2==0)
   j--;
   else
   j++;
   }
   }

  }
 getch();
 }
/*********************************HORIZONTAL*********************************/
void horizontal()
{
  int mat[30][30];
   clrscr();

   gotoxy(3,2);cout<<"DIGITE LIMITE DE LA MATRIZ :";
	cin>>x;

   clrscr();
 gotoxy(4,2);cout<<"INGRESE DATOS \n";
  for (i=0;i<x;i++){
    for (j=0;j<x;j++){

 gotoxy(j*x+3,i+5);
 cin>>mat[i][j];
	 }
	  }
clrscr();
cout<<"MATRIZ EN ESTADO NORMAL\n";
 for(i=0;i<x;i++){
   for(j=0;j<x;j++){
    cout<<"\t"<<mat[i][j];
    }
  cout<<"\n";
  }

    j=x-1;
cout<<"\n\nMATRIZ EN FORMA HORIZONTAL";
 for(i=0;i<x;i++){
   sw=1;
   while(sw){

   if(j<0 || j>x-1){
	sw=0;
    if(i%2==0)
    j=0;
    else
    j=x-1;
    cout<<"\n\n";
    }
   else
   {delay(300);
 gotoxy(10+(j*6),15+(i*2));
   cprintf("%d\n",mat[i][j]);

   if(i%2==0)
	 j--;
	 else
	  j++;
	 }
 }

 }
getche();
}
/*************************************FIN************************************/