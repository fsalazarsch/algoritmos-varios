# include<alvaro.h>
main()
 {
 int tec,p;
 int x,y,x1,y1;
 x=20;y=5;x1=30;y1=5;
 textbackground(15);
 window(1,1,80,25);clrscr();
//**********************************************
p:
 textcolor(1);//negro
  textbackground(15);
  window(1,1,80,25);clrscr();

  textcolor(0);
  gotoxy(31,5);cprintf("Ü");
  gotoxy(21,6);cprintf("ßßßßßßßßßßß");
	
  textbackground(2); 
  window(x,y,x1,y1);clrscr();//centro 
  gotoxy(3,1);cprintf("ACEPTAR"); 
  textcolor(RED);gotoxy(3,1);cprintf("A");
  _setcursortype(_NOCURSOR);
do{
 tec=getch(); 
  if(tec==13){
   //para borrar pantalla
  textbackground(15);
  window(1,1,80,25);clrscr();
//***************************************
   textbackground(2);  
   window(x+1,y+1,x1+1,y1+1);clrscr();delay(150);goto p;}
 }while(tec!=27);
}



