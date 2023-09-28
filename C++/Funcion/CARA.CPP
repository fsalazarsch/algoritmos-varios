#include <iostream.h>
#include <conio.h>
#include <dos.h>

void MIS(int fili, int filf,int col);
void MES(int coli, int colf,int fil);
int main(void)
{
 int i,s=2000;
 int  f=9,col=31;
 int x,y,t,p,vec[4][4];
 textcolor(7); textbackground(BLACK);
 clrscr();
 gotoxy(25,5);cprintf("ASIGNAR VALORES A LA MATRIZ");
 textbackground(WHITE);
 for(i=8;i<=16;i+=2){
   MES(30,47,i);}
 for(i=30;i<=48;i+=4)  {
  MIS(8,16,i);}
 for(x=0;x<=3;x++)
 {
  for(y=0;y<=3;y++)
  {
  gotoxy(59,22);clreol();
 gotoxy(12,22);cout<<"Digite el Numero en la posicion "<<"<<"<<x<<">>"<<" "<<"<<"<<y<<">>  :";
 gotoxy(59,22);cin>>int(vec[x][y]);
 p=int(vec[x][y]);
 textbackground(BLACK);
 textcolor(RED);
 gotoxy(col,f);cprintf("%i",p);
 col+=4;
 }
col=31;
f+=2;
}
 gotoxy(12,22);clreol();
f=9;
col=31;
t=2;
x=y=0;
_setcursortype(_SOLIDCURSOR);
 textbackground(MAGENTA);
 for(i=8;i<=16;i+=2){
   MES(30,47,i);delay(100);}
 for(i=30;i<=48;i+=4)  {
  MIS(8,16,i);delay(100);}
 textbackground(BLACK);
 textcolor(GREEN);

do{
   textcolor(x);
   gotoxy(25,5);cprintf("RECORRIENDO LA MATRIZ EN << S >>");
   if(t%2==0){
    col=31;
    for(x=0;x<=3;x++)
    {
      textcolor(GREEN);
      gotoxy(col,f);cprintf("%i",vec[y][x]);
      delay(200);col+=4;
    }//for de x
   }//del if
   else{
     col=43;
     x=3;
     do{
     textcolor(GREEN);
      gotoxy(col,f);cprintf("%i",vec[y][x]);
      delay(200);col-=4;x--;
      }while(x>=0);
   }
t++;y++;f+=2;
}while(t<=5);

 for(i=8;i<=16;i+=2){
  MES(30,47,i);delay(100);}
 for(i=30;i<=48;i+=4)  {
  MIS(8,16,i);delay(100);}
 _setcursortype(_NOCURSOR);
 gotoxy(19,22);textcolor(7);cprintf("PRESIONE CUALQUIER TECLA PARA << SALIR >>");
 getch();
 window(1,1,80,24);clrscr();
}

void MES(int coli, int colf,int fil)
{
  int p;
for(p=coli;p<colf;p++){gotoxy(p,fil);cprintf(" ");}
}

void MIS(int fili, int filf,int col)
{
  int p;
for(p=fili;p<filf;p++){gotoxy(col,p);cprintf(" ");}
}
