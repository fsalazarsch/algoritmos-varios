#include<dos.h>
#include<graphics.h>
#include<conio.h>

void presentacion();

void presentacion()
 {
 int i,bandera;
 cleardevice();
 setbkcolor(1);
 setcolor(11);
 for(i=0;i<=320;i++)
 {
 line(320,240,640-i*2,0);
 line(320,240,640-i*2,480);
 delay(3);
 }
 for(i=0;i<=140;i++)
 {
  line(320,240,640,240-i*2);
  line(320,240,640,240+i*2);
  line(320,240,0,240-i*2);
  line(320,240,0,240+i*2);
  delay(3);
  }
 setcolor(1);
 settextstyle(2,0,4);
 outtextxy(290,350,"PULSE UNA TECLA PARA CONTINUAR");

 settextstyle(1,0,4);
 setcolor(1);outtextxy(120,220,"TUTOR DE PROGRAMACION");
 i=bandera=0;
 do{
    if (bandera==1)
    {
     setrgbpalette(BLUE,5,i,4);
     i--;
     if (i==0)
      bandera=0;
    }
    if (bandera==0)
    { setrgbpalette(BLUE,5,i,4);i++; }
    if (i==40)
    { bandera=1; }
 }while(!kbhit());

 getch();
}