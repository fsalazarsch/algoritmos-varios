#include"stdio.h"
#include"dos.h"
#include"conio.h"
#include<iostream.h>
main(){

int a,b,sw=0,n,m;
int mat[50][50];
clrscr();
gotoxy(5,4);cout<<"DIGITE DIMENCION :";
cin>>n;
clrscr();
gotoxy(3,2);cout<<"INGRESE LOS DATOS\n";
for (a=0;a<n;a++){
    for (b=0;b<n;b++){
gotoxy(b*n+3,a+5);
cin>>mat[a][b];
	 }
	  }
clrscr();
cout<<"MATRIZ EN ESTADO NORMAL\n";
for(a=0;a<n;a++){
  for(b=0;b<n;b++){
    cout<<"\t"<<mat[a][b];
    }
  cout<<"\n";
  }

    b=n-1;
cout<<"\n\nMATRIZ EN FORMA HORIZONTAL";
for(a=0;a<n;a++){
   sw=1;
   while(sw){

   if(b<0 || b>n-1){
	sw=0;
    if(a%2==0)
    b=0;
    else
    b=n-1;
    cout<<"\n\n";
    }
   else
   {delay(400);
   gotoxy(10+(b*6),15+(a*2));
   cprintf("%d\n",mat[a][b]);

   if(a%2==0)
	b--;
   else
	 b++;
    }
  }

}
 getch();
 }



