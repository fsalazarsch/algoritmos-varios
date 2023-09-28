///                    SISTEMAS OPERACIONALES
//                     INGENIERO ROBERTO FERNANDEZ
//          INTEGRANTES
//          MARIA ISABEL BAUTISTA   COD 494256
//          JENNY FONSECA            COD 491778
//          YAZMIN LOMBANA          COD 494262
//                   OCTUBRE 23 DE 1.997

 #include<iostream.h>
 #include<graphics.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<stdio.h>
 #include<alloc.h>
 #include<dos.h>
 #include<c:\borlandc\prg\sis_op~1\manejo~1\bus.h>
 #include<c:\borlandc\prg\sis_op~1\manejo~1\guia.h>
 # define escriba(t,tm,c,x,y,cad) {setcolor(c);settextstyle(t,0,tm);outtextxy(x,y,cad) ;}

 class BUFFER

 {	char opc;
	unsigned userpart;
	int tamano1,tamano2,tamano3,tamano4;
	int a;
	public:
		void graficos();
		void menu();
		void definiciones();
		void simulacion();
		void salir();
		void *image1;
		void *image2;
		void *image3;
		void *image4;
  };

 //FUNCION PRINCIPAL DEL PROGRAMA
 void main (void)
 { 	BUFFER b,o;
	b.graficos();
	cleardevice();
	bus();
	cleardevice();
	o.menu();
	closegraph();
 }

 //MENU PRINCIPAL
 void BUFFER::menu()

{
cleardevice();
setbkcolor(1); //Color de fondo
setcolor(15);
setlinestyle(SOLID_LINE,userpart,3);
rectangle(0,0,getmaxx(),getmaxy());




// MENU DE OPCIONES
do{

setcolor(9);
rectangle(190,15,440,60);setfillstyle(1,9);floodfill(195,30,9);
rectangle(190,75,440,130);setfillstyle(1,9);floodfill(195,90,9);
rectangle(190,160,440,300);setfillstyle(1,9);floodfill(195,200,9);
rectangle(190,360,440,420);setfillstyle(1,9);floodfill(195,380,9);
escriba(1,4,14,210,15,"  BUFFER   ");
escriba(1,3,14,200,80,"  MENU PRINCIPAL");
escriba(1,3,14,230,180,"[1] DEFINICIONES");
escriba(1,3,14,230,220,"[2] SIMULACION");
escriba(1,3,14,230,260,"[3] SALIR");
escriba(1,3,14,200,380,"DIGITA TU OPCION: ");
  gotoxy(48,25); opc=getch();
    switch(opc){
       case '1':{ cleardevice();
	      sound(520);delay(300);nosound(); delay(300);
	      sound(520);delay(700);nosound();
	      definiciones();break;   }
       case '2':{cleardevice();
	      sound(520);delay(300);nosound(); delay(300);
	      sound(520);delay(700);nosound();
	      simulacion(); break; }
       case '3':{cleardevice();
	      sound(520);delay(300);nosound();delay(300);
	      sound(520);delay(700);nosound();salir();break;
	      }}}
	      while(opc!='3') ;

}


void BUFFER::graficos()
	  {
	    int error, tarjeta, modo;
	    detectgraph(&tarjeta,&modo);
	    initgraph(&tarjeta,&modo,"c:\\borlandc\\bgi");
	    error=graphresult();
	    if(error!=grOk)
	      {  printf("error grafico:%s\n",grapherrormsg(error));
		 exit(1);
	      }
	      }



 void BUFFER::definiciones()

  {


  char opc;
  setbkcolor(1);
  do
  {
  planti2();
  escriba(1,1,12,425,50,"DEFINICIONES");
  escriba(11,1,12,405,140,"[1].INTRODUCCION ");
  escriba(11,1,12,405,160,"[2].QUE ES EL BUFFER  ");
  escriba(11,1,12,405,180,"[3].BUFFER SIMPLE");
  escriba(11,1,12,405,200,"[4].BUFFER DOBLE");
  escriba(11,1,12,405,220,"[5].REGRESAR MENU PPAL. ");
  escriba(11,1,12,405,240,"[6].SALIR");
  escriba(11,6,15,200,415,"DIGITE SU OPCION....");
  opc=getche();
 switch(opc)
 {
   case '1':
	     defi1();
	     break;
   case '2':
	     defi2();
	     break;
   case '3':
	     defi3();
	     break;
   case '4':
	     defi4();
	     break;
   case '5': defi5();
	     break;
   case '6': cleardevice();
	     menu();
	     break;
 }
 }while(opc!='6');
}











//SIMULACION MANEJO DE UN BUFFER
void BUFFER::simulacion()
 {
  //graficos
  {
  cleardevice();
  setbkcolor(1); //Color de fondo
  setcolor(15);
  setlinestyle(SOLID_LINE,userpart,3);
  rectangle(0,0,getmaxx(),getmaxy());

  //cuadro entrada buffer
  escriba(1,1,14,60,20,"BUFFER:   ");
  setcolor(12);
  rectangle(50,50,270,170);setfillstyle(1,12);floodfill(70,110,12);

  //contornos negros buffer
  setcolor(8);
  rectangle(50,50,270,170);

  //cuadro procesador

  escriba(1,1,14,400,20,"PROCESADOR:   ");
  escriba(1,1,12,400,20,"              LIBRE   ");
  setcolor(15);
  rectangle(440,50,580,170);setfillstyle(1,15);floodfill(450,100,15);

  //contornos negros procesador
  setcolor(8);
  rectangle(440,50,580,170);


  setcolor(8);
  //canal buffer-procesador
  line(270,80,440,80); line(270,140,440,140);
  //canal entrada buffer
  line(70,170,70,300);
  line(140,170,140,300);
  //canal salida procesador
  line(480,170,480,300); line(550,170,550,300);

   //contornos canales
   setcolor(14);
   //canal buffer-procesador
   line(270,76,440,76); line(270,144,440,144);
   //canal entrada buffer
   line(68,170,68,300);  line(142,170,142,300);
   //canal salida procesador
   line(478,170,478,300); line(553,170,553,300);


  //***bloques de informacion***
  setlinestyle(SOLID_LINE,userpart,1);
  setcolor(10);
  rectangle(90,320,110,350);setfillstyle(1,10);floodfill(100,330,10);
  setcolor(5);
  rectangle(90,370,110,400);setfillstyle(1,5);floodfill(100,380,5);
  setcolor(6);
  rectangle(90,425,110,455);setfillstyle(1,6);floodfill(100,440,6);


  //contornos negros  bloques informacion
  setcolor(8);
  rectangle(90,320,110,350);
  rectangle(90,370,110,400);
  rectangle(90,425,110,455);



  //impresora
  setcolor(7);
  rectangle(240,420,340,450);
  setfillstyle(1,7);floodfill(280,430,7);
  setcolor(8);
  rectangle(340,430,345,440); //boton impresora
  setfillstyle(1,8);floodfill(342,435,8);
  rectangle(240,420,340,450);
  //papel
  setcolor(14);
  line(260,380,260,420); line(260,380,320,380); line(320,380,320,420);
  line(260,420,320,420); setfillstyle(1,14);floodfill(290,410,14);

  //terminal-monitor
  setcolor(7);
  rectangle(400,380,460,440);
  setfillstyle(1,7);floodfill(415,400,7);


  setcolor(11);
  rectangle(410,390,450,430);
  setfillstyle(1,11);floodfill(415,400,11);

  setcolor(7);
  line(400,380,410,370); line(410,370,470,370); line(470,370,460,380);
  setfillstyle(1,7);floodfill(430,375,7);
  line(470,370,470,430); line(470,430,460,440);
  setfillstyle(1,7);floodfill(465,400,7);


  rectangle(400,450,470,470);setfillstyle(1,7);floodfill(415,460,7);

  setcolor(8);
  line(400,450,410,440); line(470,450,480,440); line(480,440,460,440);
  line(400,450,470,450); line(410,440,470,440);
  setfillstyle(1,8);floodfill(420,445,8);

  setcolor(7);
  line(470,450,480,440);
  line(480,440,480,460); line(480,460,470,470);
  setfillstyle(1,7);floodfill(475,450,7);

  //cuadros remarcados
  setcolor(8);
  line(470,450,470,470);
  line(470,450,480,440);
  line(480,440,480,460); line(480,460,470,470);
  rectangle(400,450,470,470);
  rectangle(400,380,460,440);
  rectangle(410,390,450,430);
  line(400,380,410,370); line(410,370,470,370); line(470,370,460,380);
  line(470,370,470,430); line(470,430,460,440);
  rectangle(450,460,455,465);



  setcolor(14);
  line(410,460,430,460); line(410,465,430,465);

  //boton encendido
  setcolor(12);
  rectangle(450,460,455,465);setfillstyle(1,12);floodfill(452,462,12);


  //unidad de disco
  setcolor(12);
  rectangle(540,390,600,450); setfillstyle(1,12);floodfill(550,400,12);
  setcolor(8);
  circle(570,430,6);setfillstyle(1,8);floodfill(571,431,8);
  setcolor(7);
  rectangle(560,390,580,410); setfillstyle(1,7);floodfill(571,400,7);

  //contornos negros

  setcolor(8);
  rectangle(540,390,600,450);
  rectangle(560,390,580,410);

  }


  //movimiento graficos

  {

   tamano1=imagesize(88,310,115,362);
   image1=malloc(tamano1);
   getimage(88,310,115,362,image1);

   tamano2=imagesize(80,360,112,412);
   image2=malloc(tamano2);
   getimage(80,360,112,412,image2);

   tamano3=imagesize(88,423,115,460);
   image3=malloc(tamano3);
   getimage(88,423,115,460,image3);

   tamano4=imagesize(510,88,540,120);
   image4=malloc(tamano4);
   getimage(510,88,540,120,image4);


   {
    delay(2500);

  //1
    {for (a=0; a<=230;a++)
    putimage(88,310-a,image1,0);}

    {for (a=0; a<=210; a++)
    putimage(80,360-a,image2,0);}

 //1
    {for(a=0;  a<=110; a++)
    putimage(88+a,80,image1,0);}


  //2
    {for(a=0; a<=80; a++)
    putimage(80,160-a,image2,0);}

  //3

    {for (a=0; a<=320; a++)
    putimage(200+a,80,image1,0);}

    {for (a=0; a<=400; a++)
    putimage(80+a,80,image2,0);}



    // procesador activo
    {setcolor(12);
    rectangle(515,20,590,40); setfillstyle(1,12);floodfill(520,30,12);
    escriba(1,1,128,400,20,"              ACTIVO        ");
    sound(520);delay(100);sound(530);delay(200);sound(540);delay(300);
    sound(550);delay(400);sound(560);delay(500);sound(570);delay(600);
    sound(700);delay(800); nosound();}

    {for (a=0; a<=330; a++)
    putimage(88,423-a,image3,0);}


    //movimiento final

    { for (a=0; a<=220; a++)
     putimage(490,88+a,image2,0);
     }

    //salida del procesador a la impresora

    { for (a=0; a<=220; a++)
     putimage(490-a,310,image2,0);
     sound(1500);delay(100); sound(1000);delay (200); nosound();
     escriba(2,2,8,265,390,"P R I N T E R");
     sound(1500);delay(100); sound(1000);delay (200); nosound();
     escriba(2,2,8,265,399,"P R I N T E R");
    }

    //salida del procesador al dysplay

    { for (a=0; a<=220; a++)
    putimage(515,88+a,image1,0);
    }

   //procesador libre
   {
   setcolor(14);
   rectangle(515,20,590,40); setfillstyle(1,14);floodfill(520,30,14);
   escriba(1,1,8,400,20,"              LIBRE   ");
   sound(520);delay(100);sound(530);delay(200);sound(540);delay(300);
   sound(550);delay(400);sound(560);delay(500);sound(570);delay(600);
   nosound();
   setcolor(15);
   rectangle(440,50,580,170);setfillstyle(1,15);floodfill(450,100,15);
   //contornos negros procesador
   setcolor(8);
   rectangle(440,50,580,170);
   delay(100);
   }

   //2 salida del procesador al display

    { for (a=0; a<=100; a++)
     putimage(515-a,310,image1,0);
     sound(1500);delay(100); sound(1000);delay (200); nosound();
     escriba(2,2,8,415,399,"DISPLAY");
     sound(1500);delay(100); sound(1000);delay (200); nosound();
     escriba(2,2,8,415,405,"DYSPLAY");
    }

    //3 movimiento al procesador y salida al diskette

    {
    for (a=0; a<=420; a++)
    putimage(80+a,88,image3,0);
    setcolor(12);
    rectangle(515,20,590,40); setfillstyle(1,12);floodfill(520,30,12);
    escriba(1,1,128,400,20,"              ACTIVO        ");
    sound(520);delay(100);sound(530);delay(200);sound(540);delay(300);
    sound(550);delay(400);sound(560);delay(500);sound(570);delay(600);
    sound(700);delay(800); nosound();
    escriba(1,1,14,60,20,"BUFFER:   ");
    setcolor(14);
    rectangle(50,50,270,170);setfillstyle(1,14);floodfill(70,110,14);
    //contornos negros buffer
    setcolor(8);
    rectangle(50,50,270,170);
    }

    {for (a=0; a<=220; a++)
    putimage(500,88+a,image3,0);
    }

    { for (a=0; a<=50; a++)
    putimage(500+a,310,image3,0);
    sound(1500);delay(100); sound(1000);delay (200); nosound();
    escriba(2,2,8,550,370,"DISKETTE");

    //procesador libre
   {
   setcolor(14);
   rectangle(515,20,590,40); setfillstyle(1,14);floodfill(520,30,14);
   escriba(1,1,8,400,20,"              LIBRE   ");
   sound(520);delay(100);sound(530);delay(200);sound(540);delay(300);
   sound(550);delay(400);sound(560);delay(500);sound(570);delay(600);
   nosound();
   setcolor(15);
   rectangle(440,50,580,170);setfillstyle(1,15);floodfill(450,100,15);
   //contornos negros procesador
   setcolor(8);
   rectangle(440,50,580,170);
   delay(100);
   }
   getch();
   }


   }
   getch();
    }
   cleardevice();
   menu();
   }






  void BUFFER::salir()
    {
    char tec;
    cleardevice();
    setbkcolor(1);
    setcolor(15);
    rectangle(160,150,470,350);
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(170,180,"    ESTA OPCION  ");
    outtextxy(170,210," RETORNA AL D.O.S.");
    outtextxy(170,240," ESTA SEGURO S/N");
    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    rectangle(50,50,getmaxx()-50,getmaxy()-50);
    line(5,5,50,50);
    line(5,474,50,430);
    line(635,5,590,50);
    line(635,474,590,430);
    do
    tec=getch();
    while(tec!='s'&& tec!='S' &&  tec!='n'&& tec!='N');
    if(tec=='s' || tec== 'S')
      {
       cleardevice();
       setbkcolor(1);
       setcolor(15);
       rectangle(5,5,getmaxx()-5,getmaxy()-5);
       rectangle(50,50,getmaxx()-50,getmaxy()-50);
       line(5,5,50,50);
       line(5,474,50,430);
       line(635,5,590,50);
       line(635,474,590,430);
       settextstyle(DEFAULT_FONT,0,2);
       outtextxy(200,180,"ADIOS.......");
       settextstyle(DEFAULT_FONT,0,1);
       cleardevice();
       exit(1);
       }
     menu();
    }
