# include<alvaro.h>
void CUA(int ci,int fi,int cf,int ff);
main()
 {
 char EC[5000];
 int col,fil,i,tec;
 int x,y,x1,y1,der,izq,arr,aba;
 der=izq=arr=aba=0;
 fil=2,col=3;
 x=20;y=5;x1=40;y1=10;
 textbackground(0);
 window(1,1,80,25);clrscr();
do{
  tec=getch();
  if(tec=='M'){x++;x1++;}//derecha
  else if(tec=='K'){--x;--x1;}//izquierda
	else if(tec==72){--y;--y1;}//abajo
		else if(tec==80){y++;y1++;}//arriba
  textcolor(1);//negro
  textbackground(0);
  window(1,1,80,25);clrscr();
  textbackground(1);//azul  
  window(x+1,y+1,x1+1,y1+1);clrscr();//centro
  textbackground(3); 
  window(x,y,x1,y1);clrscr();//centro   
   CUA(2,20,1,6);
 }while(tec!=27);
}



void CUA(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Í";
gotoxy(o,ff); cout<<"Í";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"º";
gotoxy(cf,o); cout<<"º";
}
gotoxy(ci,fi); cout<<"É";
gotoxy(cf,fi); cout<<"»";
gotoxy(ci,ff); cout<<"È";
gotoxy(cf,ff); cout<<"¼";

}
