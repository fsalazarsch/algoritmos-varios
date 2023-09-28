#include<iostream.h>
#include<conio.h>
int i,j;
main(){
textcolor(9);
textbackground(15);
clrscr();

for(i=1;i<=10;i++){
for (j=1;j<=10;j++)

cout<<i<<"*"<<j<<"="<<i*j<<"\n";
getch();
}
getch();
}
