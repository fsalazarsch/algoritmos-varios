#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int main(void)
{
   textcolor(1);
   textbackground(BLACK);
   clrscr();
    textbackground(WHITE);
   char ch[30];
   int col,j,k,TECLA,RETROCESO,s,p;
   textbackground(WHITE);
  for(p=29;p<59;p++){gotoxy(p,20);cprintf(" ");}
  gotoxy(10,20);cout<<"Escriba su nombre:                                  ";
  gotoxy(35,3);cout<<"Esc ¯¯¯¯ SALIR";
  gotoxy(29,20);//CAMBIA LA COLUMNA
  col=29;
  _setcursortype(_SOLIDCURSOR);
  k=0;
  for(j=0;j<=29;j++)//CAMBIA EL TAMA¥O DEL VECTOR
  {
  TECLA=getche();
  if((TECLA==13) || (TECLA==27))
  {ch[j]='\0';break;}
  else if(TECLA==8)
      { 
      if(wherex()==28) //CAMBIA LA COLUMNA INICIAL
      {gotoxy(29,20);--j;}//CAMBIA LA COLUMNA +1
      else{--col;--j;k=1;}
      }
     else{ch[j]=TECLA;gotoxy(++col,20);}
  if(k==1)
  {--j;k=0;}
  if(wherex()==59)//CAMBIA LA COLUMNA FINAL
  for(k=1;k<100;k++)
 {
   gotoxy(58,20); //CAMBIA LA COLUMNA -1
   TECLA=getch();
   if((TECLA==13) || (TECLA==27))
   {k=2500;j=50;}
   else if(TECLA==8)
   {--col;--j;gotoxy(col,20);k=140;}
 }
 }
 gotoxy(21,22);cout<<ch;getch();
 return(0);
}

