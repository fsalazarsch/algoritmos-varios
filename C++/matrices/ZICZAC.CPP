#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include<iostream.h>
void main(){

int i,j,sw=0,n,m;
int mat[30][30];
clrscr();
	 gotoxy(5,4);cout<<"DIGITE DIMENSION:";
	cin>>n;


 clrscr();
 gotoxy(3,2);cout<<"LLENE LA MATRIZ\n";
for (i =0 ; i <  n ; i++){

    for (j = 0 ;j<  n ; j++){

 gotoxy(j*n+3,i+5);
 cin>>mat[i][j];
	 }
	  }
clrscr();
cout<<"MAT-NORMAL\n";
for(i=0;i<n;i++){
  for(j=0;j<n;j++){
    cout<<"\t"<<mat[i][j];
    }
  cout<<"\n";
  }

    j=n-1;
cout<<"\n\nMAT-VERTICAL";
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



