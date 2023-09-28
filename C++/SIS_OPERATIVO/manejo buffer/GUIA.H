void menu(void);
void planti2(void);
void defi(void);
void defi2(void);
void defi3(void);
void defi4(void);
void defi5(void);
void baby(void);
# define escriba(t,tm,c,x,y,cad) {setcolor(c);settextstyle(t,0,tm);outtextxy(x,y,cad) ;}



void planti2(void)
  {
    unsigned userpart=1;

    //RECUADROS EXTERNO E INTERNOS
	setcolor(15);
	setlinestyle(SOLID_LINE,userpart,3);
	rectangle(0,0,getmaxx(),getmaxy());
	rectangle(30,18,370,390); rectangle(390,18,610,390); //recuadros preventivas
	rectangle(170,400,470,450); //recuadro opcion

	rectangle(172,402,468,448); //recuadro opcion
    }

//OPCION 1, INTRODUCCION
void defi1(void)
 {
  baby();
  planti2();
  escriba(11,1,12,240,100,"INTRODUCION");
  escriba(11,6,15,40,200,"ESTE PROGRAMA  PLANTEA  LA SIMULACION ");
  escriba(11,6,15,40,210,"DEL  BUFFER  CON  EL  FIN DE  APORTAR ");
  escriba(11,6,15,40,220,"IDEAS  Y  CONCEPTOS AL  CAMPO  DE LOS ");
  escriba(11,6,15,40,230,"SISTEMAS OPERACIONALES. ");
  escriba(11,6,15,40,240,"SE   PROPORCIONA    UNA    FUENTE  DE ");
  escriba(11,6,15,40,250,"INFORMACION SOBRE  LA  SIMULACION  DEL");
  escriba(11,6,15,40,260,"BUFFER  PERMITIENDO  AL  USUARIO   UNA");
  escriba(11,6,15,40,270,"VISUALIZACION Y UNA RELACION CON  CADA");
  escriba(11,6,15,40,280,"UNO  DE  LOS PROCESOS.");
  escriba(11,6,12,35,380,"PRESIONE CUALQUIER TECLA PARA CONTINUAR...");
  getche();
  cleardevice();
  }
//OPCION 2, DEFINICION, BUFFER
void defi2(void)
 {
  planti2();
  baby();

  escriba(11,1,12,230,100,"   UTILIZACION");
  escriba(11,1,12,230,120,"      BUFFER  ");
  escriba(11,6,15,40,200,"ES UN AREA DE ALMACENAMIENTO  PRIMARIO,");
  escriba(11,6,15,40,210,"DESTINADA  A  CONTENER  DATOS  DURANTE ");
  escriba(11,6,15,40,220,"TRANSFERENCIAS DE E/S. CUANDO LA TRANS-");
  escriba(11,6,15,40,230,"FERENCIA  DE E/S ESTA EN CURSO SU VELO-");
  escriba(11,6,15,40,240,"CIDAD DEPENDE DE VARIOS FACTORES  RELA-");
  escriba(11,6,15,40,250,"CIONADOS CON EL HARDWARE DE E/S,  PERO ");
  escriba(11,6,15,40,260,"EN GENERAL NO ESTA RELACIONADA CON  LA ");
  escriba(11,6,15,40,270,"OPERACION DEL PROCESADOR");
  escriba(11,6,15,40,280,"POR EJEMPLO: DURANTE  LA  ENTRADA, LOS ");
  escriba(11,6,15,40,290,"DATOS SON COLOCADOS EN  EL BUFFER  POR ");
  escriba(11,6,15,40,300,"MEDIO  DE  UN  CANAL DE E/S; CUANDO LA ");
  escriba(11,6,15,40,310,"TRANSFERENCIA SE COMPLETA, LOS DATOS SE");
  escriba(11,6,15,40,320,"PUEDEN SER ADCEDIDOS POR EL PROCESADOR ");
  escriba(11,6,12,35,350,"PRESIONE CUALQUIER TECLA PARA CONTINUAR...");

  getche();
  cleardevice();
  }


//OPCION 3, DEFINICION, BUFFER SIMPLE
void defi3(void)
 {
  planti2();
  baby();
  escriba(11,1,12,240,100,"BUFFER");
  escriba(11,1,12,240,120,"SIMPLE");
  escriba(11,6,15,40,200,"EN ENTRADAS  DE  BUFFER  SIMPLE, EL CANAL");
  escriba(11,6,15,40,210,"DEPOSITA DATOS EN  EL  BUFFER, EL  PROCE-");
  escriba(11,6,15,40,220,"SADOR  PROCESA  ESTOS  DATOS,  EL  CANAL ");
  escriba(11,6,15,40,230,"DEPOSITA  NUEVOS  DATOS  ETC. MIENTRAS EL");
  escriba(11,6,15,40,240,"CANAL  DEPOSITE   DATOS  NO  PUEDE  TENER");
  escriba(11,6,15,40,250,"LUGAR NINGUN PROCESAMIENTO DE  ESOS  DATOS");
  escriba(11,6,15,40,260,"MIENTRAS LOS DATOS ESTAN SIENDO PROCESADOS");
  escriba(11,6,15,40,270,"NO PUEDEN SER DEPOSITADOS DATOS ADICIONALES");
  escriba(11,6,12,35,320,"PRESIONE CUALQUIER TECLA PARA CONTINUAR...");
  getche();
  cleardevice();
  }

//OPCION 4, DEFINICION, BUFFER DOBLE
void defi4(void)
 {
  planti2();
  baby();
  escriba(11,1,12,240,100,"BUFFER");
  escriba(11,1,12,240,120,"DOBLE");
  escriba(11,6,15,40,200,"PERMITE LA SOBREPOSICION DE LAS OPERACIO");
  escriba(11,6,15,40,210,"NES DE E/S CON EL PROCESAMIENTO MIENTRAS");
  escriba(11,6,15,40,220,"EL CANAL ESTA  DEPOSITANDO  DATOS EN UN ");
  escriba(11,6,15,40,230,"BUFFER EL PROCESADOR PUEDE ESTAR  PROCE-");
  escriba(11,6,15,40,240,"SANDO LOS DATOS DEL PRIMER BUFFER PUEDE ");
  escriba(11,6,15,40,250,"CONTINUAR CON LOS DATOS DEL SEGUNDO BUFFER");
  escriba(11,6,15,40,260,"MIENTRAS EL CANAL DEPOSITA NUEVOS DATOS EN");
  escriba(11,6,15,40,270,"EL PRIMER BUFFER.");
  escriba(11,6,12,35,320,"PRESIONE CUALQUIER TECLA PARA CONTINUAR...");
  getche();
  cleardevice();
  }
//OPCION 5, GUIA USUARIO, RETORNO AL MENU PRINCIPAL
void defi5(void)
 {
  planti2();
  baby();
  escriba(11,1,12,240,100,"RETORNO AL");
  escriba(11,1,12,240,120,"MENU PRINCIPAL");
  escriba(11,6,15,40,200,"ESTA OPCION RETORNA AL MENU  PRINCI-");
  escriba(11,6,15,40,210,"PAL,DONDE ENCUENTRA LA OPCIONA SALIR");
  escriba(11,6,15,40,220,"QUE  LLEVA  AL  SISTEMA  OPERATIVO Y");
  escriba(11,6,15,40,230,"TERMINA LA EJECUCION DEL PROGRAMA.  ");
  escriba(11,6,12,35,320,"PRESIONE CUALQUIER TECLA PARA CONTINUAR...");
  getche();
  cleardevice();
  }

void baby(void)
{
 setcolor(14);
 arc(120,120,0,360,40);
 setcolor(4);
 arc(120,120,170,370,15);
 circle(103,118,2);
 circle(137,118,2);
 setcolor(0);   /*nariz*/
 circle(120,90,4);
 setcolor(1);
 arc(100,80,360,230,15);
 arc(137,80,320,180,15);
 arc(137,80,320,180,10);
 arc(100,80,360,230,10);
 setcolor(11);
 circle(100,80,2);
 circle(137,80,2);
 setcolor(10);
 arc(99,70,340,150,20);
 arc(140,70,-300,-150,20);
 circle(80,60,2);
 circle(152,56,2);
 setcolor(14);
 line(158,110,180,130);
 line(180,130,200,110);
 line(190,100,210,120);
 line(80,120,60,99);
 line(60,99,60,80);
 line(45,70,70,85);
 setcolor(14);
 line(110,160,80,170);
 line(80,170,130,163);
 line(130,160,170,170);
 line(170,170,110,165);
 setcolor(15);
 setcolor(8);
 circle(120,40,2);
 circle(140,35,3);
 circle(160,32,4);
 circle(180,30,5);
 circle(200,28,6);
 circle(220,30,7);
 circle(250,32,8);
 circle(280,40,9);
 /*fin baby*/
}
