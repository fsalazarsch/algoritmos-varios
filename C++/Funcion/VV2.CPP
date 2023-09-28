# include<alvaro.h>
void CUADROS();
main()
 {
 char EC[5000];
 int col,fil,i,tec;
 fil=2,col=3;
 window(1,1,80,25); textbackground(0);clrscr();
 textcolor(1);//negro
 textbackground(1);//azul
 window(11,5,72,20);clrscr();//centro
 textbackground(3);
 window(10,4,71,19);clrscr();//centro
 CUADROS();
  _setcursortype(_SOLIDCURSOR);
 textcolor(RED);gotoxy(col,fil);// gets(EC);
 for(i=3;i<60;i++)
 {  
  gotoxy(++col,fil);  
  tec=getche();
  if(tec==13 && fil<15)
   {i=col=3;gotoxy(col,fil++);}//retorno de carro
  if(tec==13 && wherey()==15)exit(0);//salir de la —ltima lnea
  else if(wherex()==60)//columna final   
	if(wherey()==15)//fila final   	  
	 exit(0);
	else
	{col=3;gotoxy(col,++fil);i=3;}
       }               
 }

void CUADROS()
{
int I,J;
for(I=2;I<=60;I++)
 {
 gotoxy(I,1); cout <<"Í";
 gotoxy(I,16); cout <<"Í";
  _setcursortype(_NOCURSOR);
 }
for(J=1;J<=15;J++)
 {
 gotoxy(2,1); cout <<"É";
 gotoxy(2,J); cout <<"º";
 gotoxy(2,16); cout <<"È";
 gotoxy(61,1); cout <<"»";
 gotoxy(61,J); cout <<"º";
 gotoxy(61,16); cout <<"¼";
  _setcursortype(_NOCURSOR);
 }
}
