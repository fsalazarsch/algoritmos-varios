# include<dos.h>
# include<conio.h>
# include<iostream.h>
#include "graphics.h"
#include "alloc.h"

#define quitar_mouse(x,y) {if(memo){putimage(x-13,y-3,memo,0);farfree(memo);}}
//SE LLAMA EN LA RUTIANA GUANTE PARA RELLENAR EL INTERIOR DEL DIBUJO
#define rellena_objeto(x,y,color,borde) {setfillstyle(1,color);floodfill(x,y,borde);}
void poner_mouse(int x,int y,int c);
void msinit(int xlo,int xhi,int ylo,int yhi);
void msread(int *px,int *py,int *pbuttons);
void mouse_cursor(int *px,int *py,int *pbut);
void guante(int x,int y);
char far *memo;

main()
{
int raton_x=100,raton_y=100,boton;
clrscr();
 int tecla;

  int unidad =DETECT,modo;
  initgraph (&unidad,&modo,"c:\\borlandc\\bgi");
  if (graphresult() != 0)
  {
   cout << "Error al tratar de pasar al modo grafico\n";
   getch();
  }


msinit(15,getmaxx()-15,25,getmaxy()-30);//COORDENADAS DE INICIALIZACION
tecla=13;
do{
/* regs.x.ax=1;
int86(0x33,&regs,&regs);*/
poner_mouse(raton_x,raton_y,15);//COLOCA EL MOUSE EN LAS COORDENADAS
mouse_cursor(&raton_x,&raton_y,&boton);
//tecla=getch();
}while(tecla != 27);
union REGS regs;
regs.x.ax=0;
int86(0x33,&regs,&regs);
 return(0);
}

void poner_mouse(int x,int y,int c)
{
 memo=(char far *)farmalloc(imagesize(x-13,y+26,x+6,y-3));
 if(memo)
 {
  getimage(x-13,y+26,x+6,y-3,memo);
  setcolor(c);setlinestyle(0,0,0);
  guante(x,y);
 }
}
//INDICA AL MOUSE DONDE DEBE POSICIONARSE INICIALMENTE
void msinit(int xlo,int xhi,int ylo,int yhi)
{
union REGS regs;
int retcode;
    //INDICA AL REGISTRO AX QUE ES PARA POSICIONARSE EN ESAS
    //COORDENADAS.
    regs.x.ax=7;//DEFINE LOS LIMITES HORIZONTALES DEL CURSOR
    //CX Y DX GUARDAN POSICIONES INICIALES DEL MOUSE
    regs.x.cx=xlo;
    regs.x.dx=xhi;
    int86(51, &regs, &regs);
    regs.x.ax=8;//DEFINE LOS LIMITES VERTICALES DEL CURSOR
    regs.x.cx=ylo;
    regs.x.dx=yhi;
    int86(51, &regs, &regs);
}
void msread(int *px,int *py,int *pbuttons)
{
union REGS regs;
static int x0=-10000, y0, but0;
int xnew, ynew;

    do {
       regs.x.ax=3;//REGS.X.AX =3 REGRESA LA POSICION DEL RATON Y EL ESTADO DE
		  //LOS BOTONES.
       //Y LEE EL BOTON QUE SE PULSO CLICK DERECHO ES 1
       //Y CLICK IZQUIERDO ES 2.

	regs.x.ax=3;//REGRESA LA POSICION DEL RATON Y EL ESTADO DE LOS BOTONES
	int86(51, &regs, &regs);
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	//*PBUTTONS ES EL APUNTADOR EN DONDE SE ALMACENA EL VALOR DEL
	//BOTON PULSADO, ALMACENADO EN EL REGISTRO BX.
	*pbuttons=regs.x.bx;
       //ESTE BUCLE VALIDA MIENTRAS NO SE PULSE NINGUN Y NO SE MUEVA EL MOUSE
       }while(xnew==x0 && ynew==y0 && *pbuttons==but0);
    *px=x0=xnew;
    *py=y0=ynew;
    but0=*pbuttons;
}
// ESTA RUTINA MUEVE LA POSICION DEL MOUSE, Y VA REEMPLAZANDO
//LAS FIGURAS DEL FONDO DEL VIDEO

// ESTA RUTINA MUEVE LA POSICION DEL MOUSE, Y VA REEMPLAZANDO
//LAS FIGURAS DEL FONDO DEL VIDEO
void mouse_cursor(int *px,int *py,int *pbut)
{
int xold=*px, yold=*py;

    msread(px, py, pbut);
       {
	quitar_mouse(xold, yold);
	poner_mouse(*px, *py,15);
       }
}
//ES EL DIBUJO DE LA GRAFICA QUE SIMULA EL CURSOR.
//DESPLAZANDOSE LAS COORDINADAS QUE GENERE EL MOVIMIENTO DEL MOUSE.
void guante(int x,int y)
{ int i=8,c=7;

  setcolor(i);
  arc(x,y,0,180,1);
  arc(x-4,y+6,0,180,1);
  arc(x-8,y+7,0,180,1);
  arc(x-11,y+11,0,180,1);
  arc(x+2,y+12,0,90,4);
  line(x+1,y+10,x+1,y+1);
  line(x-2,y+10,x-2,y+1);
  line(x-6,y+7,x-6,y+10);
  line(x-9,y+8,x-9,y+10);
  line(x-13,y+12,x-13,y+15);
  line(x+6,y+15,x+6,y+12);
  line(x+6,y+15,x+2,y+21);
  line(x+2,y+24,x+2,y+21);
  line(x-13,y+15,x-9,y+21);
  line(x-9,y+21,x-9,y+24);
  line(x-9,y+24,x+2,y+24);
  rellena_objeto(x,y,c,i);
}
