# include<dos.h>
# include<conio.h>
# include<iostream.h>
# include<ctype.h>
# include<graphics.h>
# include<stdlib.h>
int estado();
main()
{
clrscr();
_setcursortype(_NOCURSOR);
 union REGS regs,r;
 int tecla,p;
 regs.x.ax=1;//MOSTRAR ICONO EN PANTALLA
 int86(0x33,&regs,&regs);
 p=estado();
 if(p==1) cout<<"BOTON IZQUIERDO";
 else cout<<"BOTON derecho";
 delay(1000);
 regs.x.ax=0;//ESCONDER ICONO EN PANTALLA
 int86(0x33,&regs,&regs);
 return(0);
}
int estado(){
 union REGS r;
do{
 r.x.ax=0x03;
 int86(0x33,&r,&r);
 }while(r.x.bx==0);
 return (r.x.bx);
}
