#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <stdarg.h>

void presentacion();
void burbuja();


void presentacion()
{
	int unidad = DETECT, modo, codigo;
	initgraph(&unidad, &modo, "c:\\borlandc\\bgi");
	codigo = graphresult();
       //int mode;


	if (codigo != grOk)
	{
		printf("error en el gr…fico: %s\n", grapherrormsg(codigo));
		printf("presione cualquier tecla:");
		getch();
	}
	else
	{ clrscr();
		rectangle(0,0,getmaxx(),getmaxy());
		setfillstyle(9,BLUE);
		floodfill(20,20,WHITE);
		settextstyle(2,0,7);
		settextjustify(1,0);
		setcolor(YELLOW);


		outtextxy((getmaxx()-2)/2,30,"M O D E L O S  D E  P R O G R A M A C I O N  I ");
		outtextxy((getmaxx()-2)/2,60,"MANEJO DE GRAFICAS");
		settextstyle(2,0,5);
		settextjustify(0,0);
		setcolor(WHITE);
		outtextxy(100,130,"Alumno :");
		settextstyle(4,0,2);
		settextjustify(1,0);
		outtextxy((getmaxx()-2)/2,145,"  Cesar Leonardo Moreno");
		outtextxy((getmaxx()-2)/2,165,"  Cod 96132029");
		settextstyle(2,0,5);
		settextjustify(0,0);
		outtextxy(100,230,"Docente :");
		settextstyle(1,0,2);
		settextjustify(1,0);
		outtextxy((getmaxx()-2)/2,245,"Elder Rivero");
		settextstyle(2,0,5);
		settextjustify(0,0);
		outtextxy(100,290,"Curso :");
		settextstyle(4,0,2);
		settextjustify(1,0);
		outtextxy((getmaxx()-2)/2,305,"U D E S  S2A");
		outtextxy((getmaxx()-2)/2,420,"Corporacion Universitaria De Santander");
		outtextxy((getmaxx()-2)/2,450,"Facultad Ingenieria de Sistemas");
		outtextxy((getmaxx()-2)/2,475,"Valledupar");
		getch();
		clrscr();
		closegraph();

	}
	gotoxy(25,12);printf("Pulse una tecla para salir");
getch();

}


void burbuja()
{
	int gdriver = DETECT, stangle, midx, endangle,radius ,midy, gmode, errorcode,i;
	initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
	errorcode = graphresult();

	if (errorcode != grOk)
	{
		printf("Error al tratar de pasar al modo grafico: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); 
	} 


    setbkcolor(BLUE);
	 for(i=0;i<=getmaxx();i++)
	{ 
	sound(100); 
	delay(5);
	nosound();
	cleardevice();
		setcolor(14);
		rectangle(i-50,180,i-190,240); 
	  //arc(i-50,220,15,90,30);
	  sector(i-53,210,100,0,29,30);
	 // rectangle(i-50,210,i,240);				
	  line(i-50,210,i,216);
	  line(i,240,i,216);
	  line(i-50,240,i,240);
	  line(i-95,180,i-95,240);
	  line(i-95,210,i-30,210);
	  
	
				  setcolor(15);//line(i,200,i-190,210);
				  //line(i-190,211,i,205); 
	circle(i-50,258,13);
	circle(i-50,258,15);
	circle(i-50,258,17);
	circle(i-50,258,8);
	
    
	circle(i-150,258,13);
	circle(i-150,258,15);
	circle(i-150,258,17);
	circle(i-150,258,8);
	circle(i-150,258,8);
	settextstyle(0,i-150,HORIZ_DIR);	 
	outtextxy(i-150,215," TOYOTA");
	 }
	getch();	
	
	closegraph();
	//return 0;


}
void main()
{
 burbuja();
 presentacion();
}

