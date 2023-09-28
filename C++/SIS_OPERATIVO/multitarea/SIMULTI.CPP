/***************************************************************************/
/*     PROGRAMA QUE REALIZA LA SIMULACION DE UN UN PROCESO MULTITAREA      */
/*     DICHA SIMULACION ES REALIZADA EN MODO GRAFICIO.                     */
/*            UNIVERSIDAD ANTONIO NARI¥O    SEDE    SUR                    */
/*	      MATERIA: SISTEMAS OPERATIVOS          			   */
/*	      PROFESOR: ROBERTO                                            */
/* 	      INTEGRANTES: MARILUZ SOLER               493442              */
/*			   ELSY ANGARITA               493134              */
/*			   MARIA DEL PILAR AVELLA      493190              */
/*                         CARLOS ARTURO DIAZ          493444	           */
/***************************************************************************/
#include "bios.h"
#include "alloc.h"
#include "math.h"
#include "iostream.h"
#include "dos.h"
#include "conio.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "graphics.h"
#include "stdarg.h"

#define IZQUIERDO 1
#define DERECHO 2
#define AMBOSBOTONES 3
//COLOCA LA IMAGEN QUE PREVIAMENTE SE HA SALVADO Y LIBERA MEMORIA
//QUITAR_MOUSE RETIRA EN LAS COORDENADAS X y Y LA FIGURA DEL MOUSE
//PUTIMAGE PEGA LA IMAGEN QUE PREVIAMENTE SE HA SALVADO
#define quitar_mouse(x,y) {if(memo){putimage(x-13,y-3,memo,0);farfree(memo);}}
//SE LLAMA EN LA RUTIANA GUANTE PARA RELLENAR EL INTERIOR DEL DIBUJO
#define rellena_objeto(x,y,color,borde) {setfillstyle(1,color);floodfill(x,y,borde);}
//DESCRIPSION DE LA FUNCION FARMALLOC
//ESTA FUNCION SE UTILIZA PARA ASIGNAR MEMORIA DINAMICA LEJANA
//LA FILOSOFIA DE LA RUTINA ES LA MISMA QUE PARA MALLOC, LA DIFERENCIA
//RADICA EN QUE MALLOC ASIGNA MEMORIA DINAMICA CERCANA.
//LA RUTINA FARMALLOC ASIGNA MEMORIA DINAMICA LEJANA, PUEDE LOCALIZAR
//BLOQUES DE MEMORIA LEJANA DE MAS DE 64000 BYTES LO QUE INDICA QUE
//EVENTUALMENTE PUEDE UTILIZAR TODA LA MEMORIR RAM DISPONIBLE.
union REGS regs;
char far *memo;
char *titulo;
void guante(int x,int y);
void defin();
int radio=10, raton_x=100, raton_y=100,mis=0;;
void botones(int,int,int,int,int,int,int,char a2[]);
struct nodo
{
char no_proceso;
int cuantum_tiempo;
int pos_proceso;
int long_proceso;
struct nodo *sig;
struct nodo *ant;
};
typedef struct nodo nodo;

class lista_procesos{
public:
lista_procesos(void);
int relleno(),graficar_memoria(),graficar_cpu();
int memoria_real(),ajustar_en_memoria(int),ordenar_memoria();
void listar(void),salidas_cpu(),listar_procesos_historicos();
int eliminar_procesos_memoria(),entradas_cpu(),de_cpu_a_memoria(),requerimientos(),eliminar(int),memoria_a_cpu();
int salidas_disp(),de_cpu_a_disp(),eliminar_proceso_disp(),eliminar_proceso_cpu(),crear(int);
int eliminar_lista_procesos(void),compactar_memoria();
};
int posicion=0,m=3,k=1,relleno(int,int,int,int);
void menu(),iniciar_modo_grafico(),explicar(),clases(),portada();
char prog2(void);

int numero = 12345,mayor=150;
char *u1,string[25];
int gw=0,sw,sw2,sw3,i,j,u,t,np,v,h;
double pos_proceso;
nodo *cab,*p,*q,*r,*cab1,*cab2,*cab3,*p3,*q3,*cab4,*p4,*q4,*r4,*t4;
lista_procesos z;
int lista_procesos::relleno()
{
 setlinestyle(0,0,0);
 for(int g=23;g<=325;g++)
 {
  setcolor(9);
  rectangle(g,353,g,419);
 }
 return 1;
}


int instalado_mouse()
{
int retcode;

    regs.x.ax = 0;     //AX LE ESTA INDICANDO AL PUERTO QUE SE DEBE INICIALIZAR
		       //REINICIA EL RATON Y REGRESA SU ESTADO
    //EL PROTOTIPO int86(int num_int, union REGS *REGS *regs_e, union REGS *regs_s)
    //SE ENCUENTRA EN DOS.H.
    //LA FUNCION INT86 SE UTILIZA PARA EJECUTAR UNA INTERRUPCION SOFTWARE ESPECIFICADA
    //POR NUM_INT.EL CONTENIDO DE LA FUNCION REGS_E SE COPIA PRIMERO EN LOS REGISTROS
    //DEL PROCESADOR Y DESPUES SE EJECUTA LA PROPIA INTERRUPCION. CUANDO SE VUELVE
    // LA UNION REGS_S CONTIENE LOS VALORES DE LOS REGISTROS DE LA CPU AL VOLVER DE LA
    //INTERRUPCION.SI EL INDICADOR DE ACARREO ESTA ACTIVADO, SIGNIFICA QUE SE HA PRODUCIDO
    //UN ERROR. SE DEVUELVE EL VALOR DEL REGISTRO AX.
    //LA UNION REGS ESTA DEFINIDA EN LA LIBRERIA DOS.H
    int86(51, &regs, &regs);
    retcode = regs.x.ax;
    //EN LA VARIABLE RETCODE QUEDA ALMACENDO EL VALOR DE ESTADO DEL PUERTO
    //SI ESTA INSTALADO RETORNA [-1] Y SI NO ESTA INSTALADO RETORNA [0].
    if(retcode == 0) return(0);
    else return(1);
}
//COLOCA EL CURSOR DEL MOUSE (GUANTESITO), Y VA SALVANDO LA IMAGEN DEL FONDO PARA COLOCARLA
//POSTERIORMENTE Y IR DESPLAZANDO EL MOUSE POR TODA LA PANTALLA.
//PONER_MOUSE LO COLOCA EN LA COORDENADA (X,Y) C ES COLOR DE RELLENO.
//CON FARMALLOC SE SOLICITA MEMORIA PARA SALVAR LA IMAGEN DEL FONDO DEL VIDEO, Y LA ALMACENA EN MEMO
//IMAGESIZE CALCULA LA LONGITUD DE MEMORIA REQUERIDA PARA SALVAR LA IMAGEN.
//SI HAY MEMORIA DISPONIBLE TOMA LA IMAGEN (GETIMAGE) Y LA ALMACENA EN MEMO
//Y LUEGO VA COLOCANDO EL DIBUJO DEL GUANTE SOBRE LA IMAGEN QUE PREVIAMENTE SE
//HA SALVADO.
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

/***************************************************************************/
/*                             RUTINA PRINCIPAL                            */
/***************************************************************************/
void botones(int ci,int fi,int cf,int ff,int fondo,int t1,int t2,char a2[])
{
  if(fondo==0)
  {
    setcolor(15);
    rectangle(ci,fi,cf,ff);
    setcolor(4);
    rectangle(ci+3,fi+3,cf-3,ff-3);
    relleno(ci+5,fi+5,1,4);
    setcolor(15);
    outtextxy(t1,t2,a2);
  }
  if(fondo==1)
  {
    relleno(ci+10,fi+10,9,4);
    setcolor(4);
    outtextxy(t1,t2,a2);
    delay(500);
  }
}
int relleno(int x,int y,int c,int l)
{
setfillstyle(1,c);
floodfill(x,y,l);
return 0;
}

void menu()
{
 cleardevice();
 settextjustify(1,1);
 settextstyle(1,0,1);
 setcolor(9);
 outtextxy(getmaxx()/2,40,"SIMULACION DE UN PROCESO MULTITAREA");
 settextjustify(0,0);
 settextstyle(2,0,4);
 setcolor(15);
 rectangle(4,4,getmaxx()-4,getmaxy()-4);
 rectangle(6,6,getmaxx()-6,getmaxy()-6);
 botones(60,80,300,130,0,96,93,"Integrantes");
 botones(60,180,300,230,0,96,193,"Qu‚ es un Sistema Operativo ?");
 botones(60,280,300,330,0,96,293,"Clases de Sistemas Operativos");
 botones(300,130,560,180,0,316,143,"Qu‚ es Procesamiento Multitarea ?");
 botones(300,230,560,280,0,316,243,"Simulaci¢n del procesamiento Multitarea ?");
 botones(300,330,560,380,0,316,343,"Salida");
}
void iniciar_modo_grafico()
{
  int unidad =DETECT,modo;
  initgraph (&unidad,&modo,"c:\\borlandc\\bgi");
  if (graphresult() != 0)
  {
   cout << "Error al tratar de pasar al modo grafico\n";
   getch();
  }
}

void main(void)
{
 int click,seguir=1,boton,color,st=1;
 int opc=1;
 iniciar_modo_grafico();
 portada();
 if(instalado_mouse())//ESTA PREGUNTA INDAGA SOBRE SI SE ENCUENTRA
		      //INSTALADO EL MOUSE RETORNA [1] SI ESTA INSTALADO
		      //Y [0] SI NO ESTA INSTALADO
 {
   msinit(15,getmaxx()-15,25,getmaxy()-30);//COORDENADAS DE INICIALIZACION
					   //DEL MOUSE
    menu();//DIBUJA EL MENU PRINCIPAL DE OPCIONES EN LA PANTALLA

   do//ESTE ES UN CICLO INFINITO, SOLAMENTE TERMINA CUANDO SE HACE
     //CLICK EN SALIDA. [CON EXIT(1)].
   {
    opc=0;
    poner_mouse(raton_x,raton_y,15);//COLOCA EL MOUSE EN LAS COORDENADAS
				      //POR LAS QUE SE VAYA DESPLAZANDO.
    mouse_cursor(&raton_x,&raton_y,&boton);
   //mouse_cursor : ESTA RUTINA MUEVE LA POSICION DEL MOUSE, Y VA REEMPLAZANDO
   //LAS FIGURAS DEL FONDO DEL VIDEO

    click = boton; //EN LA VARIABLE CLICK QUEDA ALMACENADO EL VALOR DEL
		   //BOTON QUE SE OPRIMIO [1] IZQUIERDO [2] DERECHO.
		   //EL VALOR DEL BOTON OPRIMIDO LO RETORNA LA FUNCION
		   //MOUSE_CURSOR.
    if(boton)//PREGUNTA SI PRESIONARON UN BOTON [1] IZQUIERDO
	     //[2] DERECHO.
    {
     switch(click)
     {
      //RATON_X ALMACENA EL VALOR DE LAS COORDENADAS EN X.
      //RATON_Y ALMACENA EL VALOR DE LAS COORDENADAS EN Y.
      case 1 :{
		opc=1;
		quitar_mouse(raton_x,raton_y);
	  if(raton_x >=80 && raton_x <= 300 && raton_y >= 80 && raton_y <= 130)
	  {
	   botones(60,80,300,130,1,96,93,"Integrantes");
	   portada();
	   menu();
	  }
	  if(raton_x >=300 && raton_x <= 520 && raton_y >= 330 && raton_y <= 380)
	  {
	   botones(300,330,560,380,1,316,343,"Salida");
	   closegraph();
	   exit(1);
	 }
	 if(raton_x >=300 && raton_x <= 520 && raton_y >= 230 && raton_y <= 280)
	 {
	   botones(300,230,560,280,1,316,243,"Simulaci¢n del Procesamiento Multitarea.");
	   settextjustify(0,2);
	   prog2();
	   closegraph();
	   exit(1);
	 }

	 if(raton_x >=300 && raton_x <= 560 && raton_y >= 130 && raton_y <= 180)
	 {
	   botones(300,130,560,180,1,316,143,"Qu‚ es Procesamiento Multitarea ?");
	   explicar();
	   cleardevice();
	   menu();
	 }


	 if(raton_x >=60 && raton_x <= 300 && raton_y >= 280 && raton_y <= 330)
	 {
	   botones(60,280,300,330,1,96,293,"Clases de Sistemas Operativos");
	   clases();
	   cleardevice();
	   menu();
	 }

	 if(raton_x >=60 && raton_x <= 300 && raton_y >= 180 && raton_y <= 238)
	 {
	   botones(60,180,300,230,1,96,193,"Qu‚ es un Sistema Operativo ?");
	   cleardevice();
	   defin();
	   menu();

	 }

	       }
	       st=0;//ESTE  ES UN SWITCH QUE VALIDA QUE SE DEBE ESTAR QUITANDO
		    //EL MOUSE DEL FONDO DE LA PANTALLA, DE MANERA QUE NO DEJE
		    //RASTRO DEL GUANTE.
	       if(!opc)//SI PRESIONO CLICK IZQUIERDO Y NO SELECCIONO LAS
	       //OPCIONES DE LAS VENTANAS DE LA PARTE SUPERIOR.
	       {
		setcolor(15);
		outtextxy(320,getmaxy()-15,"NO HA ELEGIDO NINGUNA OPCION");
		sound(880);
		delay(750);
		nosound();
		setcolor(11);
		outtextxy(320,getmaxy()-15,"NO HA ELEGIDO NINGUNA OPCION");
		st=1;
	       }
	       break;
      case 2 : setcolor(31);
	       //ESTE CASE 2 ES SI PRESIONO CLICK DERECHO

	       outtextxy(320,getmaxy()-15,"ERROR EN PULSACION");
	       sound(440);
	       delay(750);
	       nosound();
	       setcolor(11);
	       outtextxy(320,getmaxy()-15,"ERROR EN PULSACION");
	       break;
     }
    }
    if(st)
     {quitar_mouse(raton_x,raton_y);}//ESTE  ES UN SWITCH QUE VALIDA QUE SE DEBE ESTAR QUITANDO
		    //EL MOUSE DEL FONDO DE LA PANTALLA, DE MANERA QUE NO DEJE
		    //RASTRO DEL GUANTE.

    else
     st=1;
   }while(seguir);//LOOP INFINITO.
  }
 else// ES SI EL VALOR RETORNADO POR instalado_mouse() FUE [0] CERO
 //EN DICHO CASO NO ESTA INSTALADO MOUSE EN EL COM1 .
 {
  printf("\nRat¢n no instalado...\n\n");
  exit(0);//SALE DEL PROGRAMA
 }
closegraph();//CIERRA EL MODO GRAFICO.
}
char prog2(void)
{
 char s='s';
 t=0;
 cleardevice();
 settextstyle(2,0,4);
 setbkcolor(9);
 randomize();
 while(np >= 0 && np<=5)
   np=random(10);
 np+=6;
 v=1;
  for(int y=0;y<np;y++)
   z.crear(0);
 z.listar();
 z.graficar_memoria();
 do
 {
    switch(v){
		      case 0:{
		      z.crear(0); //SE CREAN LOS PROCESO EN MEMORIA
		      //z.ordenar_procesos();
		      z.graficar_memoria();
		      z.graficar_cpu();
		      settextstyle(2,0,4);
		      outtextxy(35,360,"Nuevo Ingreso a la lista de");
		      outtextxy(36,370,"Procesos en cola");
		      delay(1800);
		      z.compactar_memoria();//compactar espacios en la memoria
		      z.ajustar_en_memoria(3);
		      z.listar();//SE LISTAN POR PANTALLA
		      z.graficar_memoria();
		      z.graficar_cpu();
		      v=1;
		      break;
		  }
	   case 1: z.entradas_cpu();break;//entrar a cpu
	   }
 z.ordenar_memoria();
 setcolor(14);
 settextstyle(2,0,4);outtextxy(30,435,"Pulse ®Esc¯ para Terminar o ®Enter¯ para Continuar");
 }while((s=getche()) != 27);
z.listar_procesos_historicos();
z.eliminar_lista_procesos();
return s;
}

//ESTE ES EL CONSTRUCTOR DE LA CLASE, INICIALIZA LAS PRINCIPALES
//VARIABLES
lista_procesos::lista_procesos()
{
   sw3=sw2=pos_proceso=t=v=np=sw=i=j;
   cab=cab3=cab4=cab1=cab2=NULL;
}

int lista_procesos::crear(int h)
{
if(h==5)//CREA O ADICIONA UN NODO QUE NO CABE EN MEMORIA Y SALE DE DISP E/S
{
 if(cab==NULL)
 {
  cab=new nodo;
  cab->no_proceso=cab2->no_proceso;
  cab->long_proceso=cab2->long_proceso;//GENERA NUMERO RANDOMICO DE 0-1000
  cab->cuantum_tiempo=cab2->cuantum_tiempo;
  cab->sig=NULL;
  cab->ant=NULL;
 }
 else
 {
  while(p->sig != NULL)
   p=p->sig;
  q=new nodo;
  p->sig=q;
  q->ant=p;
  q->no_proceso=cab2->no_proceso;
  q->long_proceso=cab2->long_proceso;
  q->sig=NULL;
  p=q=cab;
 }
}

if(h==0)//CREA O ADICIONA UN NODO CONSECUTIVO EN LA LISTA DE PROCESOS EN ESPERA DE MEM0RIA
{
 t++;
 if(cab==NULL)
  sw=0;
 if(sw==1)//ESTO ES QUE VA ADICIONAR EN LA LISTA
 {
 while(p->sig != NULL)
  p=p->sig;
 q=new nodo;
 p->sig=q;
 q->ant=p;
 q->no_proceso=t;
 do{
  q->cuantum_tiempo=random(500);
 }while(q->cuantum_tiempo <100 ||  q->cuantum_tiempo >300);
 do
 {
 q->long_proceso=random(800);
 if(q->long_proceso > 40 && q->long_proceso <= mayor)
  break;
 }while(1);
 settextstyle(2,0,4);
 numero=(int)q->no_proceso;
 itoa(numero, string, 10);
 strcpy(u1,string);
 outtextxy(156,380,u1);
 outtextxy(35,380,"N§ Nuevo proceso ->");
 q->sig=NULL;
 p=q=cab;
 }
 if(sw==0)//ESTO QUIERE DECIR QUE VA CREAR LA LISTA
 {
 cab=new nodo;
 cab->no_proceso=t;
 do
 {
 cab->long_proceso=random(400);
 if(cab->long_proceso < mayor && cab->long_proceso > 100)
  break;
 }while(1);
 do{
  cab->cuantum_tiempo=random(300);
 }while(cab->cuantum_tiempo <100 ||  cab->cuantum_tiempo >300);

 cab->sig=NULL;
 cab->ant=NULL;
 sw=1;
 p=q=cab;
 }
}
else if(h==2)//TOMA EL DE La CPU Y LO ADICIONA EN MEMORIA
{
 if(cab==NULL)
  sw=0;
 if(sw==1)//ESTO ES QUE VA ADICIONAR EN LA LISTA
 {
 while(p->sig != NULL)
  p=p->sig;
 q=new nodo;
 p->sig=q;
 q->ant=p;
 q->no_proceso=cab1->no_proceso;
 q->cuantum_tiempo=cab1->cuantum_tiempo;
 q->long_proceso=cab1->long_proceso;
 settextstyle(2,0,4);
 numero=(int)q->no_proceso;
 itoa(numero, string, 10);
 strcpy(u1,string);
 outtextxy(156,380,u1);
 outtextxy(35,380,"N§ Nuevo proceso ->");
 q->sig=NULL;
 p=q=cab;
 }
 if(sw==0)//ESTO QUIERE DECIR QUE VA CREAR LA LISTA
 {
 cab=new nodo;
 cab->no_proceso=cab1->no_proceso;
 cab->cuantum_tiempo=cab1->cuantum_tiempo;
 cab->long_proceso=cab1->long_proceso;
 cab->sig=NULL;
 cab->ant=NULL;
 sw=1;
 p=q=cab;
 }

}
else if(h==3)//CREA O ADICIONA de UN NODO DE LA CPU Y LO ADICIONA EN LOS PROCESOS HISTORICOS
{
 if(sw2==1)//ESTO ES QUE VA ADICIONAR EN LA LISTA
 {
 while(p3->sig != NULL)
  p3=p3->sig;
 q3=new nodo;
 p3->sig=q3;
 q3->ant=p3;
 q3->no_proceso=cab1->no_proceso;
 q3->long_proceso=cab1->long_proceso;
 q3->pos_proceso=random(4);
 q3->sig=NULL;
 p3=q3=cab3;
 }
 if(sw2==0)//ESTO QUIERE DECIR QUE VA CREAR LA LISTA
 {
  cab3=new nodo;
  cab3->no_proceso=cab1->no_proceso;
  cab3->long_proceso=cab1->long_proceso;
  cab3->pos_proceso=random(4);
  cab3->sig=NULL;
  cab3->ant=NULL;
  sw2=1;
  p3=q3=cab3;
 }
}
else if(h==4)//CREA O ADICIONA UN NODO EN LA LISTA DE PROCESOS EN MEM0RIA
{
 if(sw3==1)//ESTO ES QUE VA ADICIONAR EN LA LISTA
 {
  while(p4->sig != NULL)
   p4=p4->sig;
  q4=new nodo;
  p4->sig=q4;
  q4->ant=p4;
  q4->no_proceso=p->no_proceso;
  q4->long_proceso=p->long_proceso;
  q4->cuantum_tiempo=p->cuantum_tiempo;
  q4->pos_proceso=p->pos_proceso;
  q4->sig=NULL;
  p4=q4=cab4;
 }
 if(sw3==0)//ESTO QUIERE DECIR QUE VA CREAR LA LISTA
 {
  cab4=new nodo;
  cab4->no_proceso=p->no_proceso;
  cab4->long_proceso=p->long_proceso;
  cab4->cuantum_tiempo=p->cuantum_tiempo;
  cab4->pos_proceso=p->pos_proceso;
  cab4->sig=NULL;
  cab4->ant=NULL;
  sw3=1;
  p4=q4=cab4;
 }
}
z.graficar_cpu();
return (1);
}
int lista_procesos::eliminar(int u)
{
 while(p->no_proceso != u)
  p =p->sig;
 if(cab->no_proceso == u && cab->sig == NULL)
 {
  free(cab);
  q=cab=p=NULL;
  return 0;
 }

 if(cab->no_proceso == u)
 {
  p=p->sig;
  free(cab);
  q=cab=p;
  return 0;
 }
 if(p->sig == NULL  && p->no_proceso == u)
 {
  q=p;
  p=p->ant;
  p->sig=NULL;
  free(q);
  q =p=cab;
  return 0;
  }
  if(p->sig == NULL  && p->no_proceso != u)
  {
   printf("%s\t"," INEXISTENTE");
   getch();
   return 0;
  }
  if(p->sig != NULL  && p->no_proceso == u)
  {
   q=r=p;
   q=q->ant;
   r=r->sig;
   q->sig=r;
   r->ant=q;
   free(p);
   q=p=cab;
   return 0;
   }
return 0;
}
/************DE MEMORIA A CPU********************/
int lista_procesos::memoria_a_cpu()//GENERA ALEATORIAMENTE UN PROCESO DE LA MEMORIA Y LO LLEVA A EL PROCESADOR
{
 int c=0,n=0,i;
  p4=cab4;
  while(p4 != NULL)//CUENTA LOS NODOS DE LA LISTA DE MEMORIA
  {
    c++;
    p4=p4->sig;
  }
  p4=cab4;
  while(n == 0)
  n=random(c);//GENERO UN RANDOMICO DE LA LISTA PREVIAMENTE RECORRIDA
  n+=1;
  i=1;
  while(p4 != NULL)
  {

    if(p4->no_proceso != 0 && n==i && p4->cuantum_tiempo != 0)
     break;
    if(p4->no_proceso == 0 && n==i)
    {
     i++;
     n=random(c);
     p4=cab4;
     i=1;
     continue;
    }
    p4=p4->sig;
    i++;
  }
  cab1=new nodo;//CREA LA NUEVA LISTA , LISTA PROCESOS CPU
  cab1->no_proceso=p4->no_proceso;
  cab1->cuantum_tiempo=p4->cuantum_tiempo;
  cab1->long_proceso=p4->long_proceso;
  cab1->sig=NULL;
  cab1->ant=NULL;
  p4->no_proceso=0;
  p4->cuantum_tiempo=0;
  p4=q4=cab4;
  z.relleno();
  settextstyle(2,0,4);
  setcolor(15);
  numero=(int)cab1->no_proceso;
  itoa(numero, string, 10);
  strcpy(u1,string);
  outtextxy(156,380,u1);
  outtextxy(35,370,"Ingresando a procesador");
  outtextxy(35,380,"N§ Nuevo proceso ->");
  z.graficar_cpu();
  delay(mis+2500);
  return 0;
}
void lista_procesos::listar()//LISTA LOS PROCESOS EN MEMORIA, CPU Y DISPOSITIVO E/S
{
int posicion2=0;
int f=70;
cleardevice();
setcolor(15);
settextstyle(1,0,1);
outtextxy(60,15,"Simulacion del Procesamiento Multitarea");
setlinestyle(0,0,3);
line(60,42,395,42);
setlinestyle(0,0,2);
line(60,46,395,46);
for(int u=1;u<=6;u++)
{
setcolor(u);
rectangle(u,u,getmaxx()-u,getmaxy()-u);
}
setcolor(14);
rectangle(u,u,getmaxx()-u,getmaxy()-u);
settextstyle(2,0,4);
setcolor(15);
settextstyle(2,0,4);
setlinestyle(0,0,3);
outtextxy(25,50,"®LISTA DE PROCESOS EN COLA¯");
line(25,65,181,65);
outtextxy(245,50,"®LISTA DE PROCESOS EN MEMORIA¯");
line(245,65,420,65);
outtextxy(25,310,"®DISPOSITIVO ENTRADA/SALIDA¯");
line(25,325,185,325);
outtextxy(295,310,"®PROCESADOR¯");
line(295,325,367,325);
p=q=cab;
//lista procesos en espera de memoria real
cab->ant=NULL;
while(p != NULL)
{
p->pos_proceso=posicion2;
f+=10;
outtextxy(25,70,"N§");
numero=(int )p->no_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(25,f,u1);

outtextxy(45,70,"Long");
numero=p->long_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(45,f,u1);

outtextxy(81,70,"Pos");
numero=p->pos_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(81,f,u1);

outtextxy(118,70,"Tiempo");
numero=p->cuantum_tiempo;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(118,f,u1);
posicion2=posicion2 + p->long_proceso;
if(p->cuantum_tiempo < 0)
  p->cuantum_tiempo = p->cuantum_tiempo * (-1);
p=p->sig;
}
p=q=cab;
posicion=0;
/*LISTA DE LA MEMORIA REAL*/
if(gw == 0)
{
z.memoria_real();
gw=1;
}
f=70;
z.ordenar_memoria();
while(p4 != NULL)
{
f+=10;
p4->pos_proceso=posicion;
outtextxy(245,70,"N§");
numero=(int )p4->no_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(245,f,u1);

outtextxy(265,70,"Long");
numero=p4->long_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(265,f,u1);

outtextxy(302,70,"Pos");
numero=p4->pos_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(302,f,u1);

outtextxy(338,70,"Tiempo");
numero=p4->cuantum_tiempo;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(338,f,u1);
posicion=posicion + p4->long_proceso;
if(p4->cuantum_tiempo < 0)
 p4->cuantum_tiempo = p4->cuantum_tiempo *  (-1);
if(p4->no_proceso== 0 || p4->no_proceso == '\x0')
 p4->cuantum_tiempo=0;

p4=p4->sig;
}

p4=q4=cab4;
//lista procesos en cpu
f=315;
if(cab1 == NULL)
{
cab1->no_proceso=0;
cab1->long_proceso=0;
cab1->cuantum_tiempo=0;
}
f+=25;
outtextxy(295,325,"N§");
numero=(int )cab1->no_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(295,f,u1);

outtextxy(315,325,"Long");
numero=cab1->long_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(315,f,u1);

cab1->cuantum_tiempo=cab1->cuantum_tiempo-15;
if(cab1->cuantum_tiempo < 0)
 cab1->cuantum_tiempo=0;

outtextxy(350,325,"Tiempo");
numero=cab1->cuantum_tiempo;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(350,f,u1);
/***************************************/
if(cab1->no_proceso != '0' && cab1->cuantum_tiempo == 0)
{
 outtextxy(25,350,"El proceso...");
 numero=(int )cab1->no_proceso;
 itoa(numero, string, 10);
 strcpy(u1,string);
 outtextxy(25,370,u1);
 outtextxy(25,390,"Ha terminado su ejecuci¢n, pasa a datos historicos");
 delay(mis+2500);
 z.crear(3);//CREA O ADICIONA EN LA LISTA DE DATOS HISTORICOS
 z.eliminar_proceso_cpu();//LO ELIMINA DE LA MEMORIA
 z.memoria_a_cpu();
 z.listar();
 z.graficar_memoria();
}
//lista de procesos en dispositivos e/s
//outtextxy(25,310,"®Dispositivo Entrada/Salida¯");
if(cab2 == NULL)
{
cab2->no_proceso=0;
cab2->long_proceso=0;
cab2->cuantum_tiempo=0;
}
f=315;
f+=25;
outtextxy(25,325,"N§");
numero=(int )cab2->no_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(25,f,u1);

outtextxy(45,325,"Long");
numero=cab2->long_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(45,f,u1);

outtextxy(90,325,"Tiempo");
numero=cab2->cuantum_tiempo;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(90,f,u1);

}
int lista_procesos::entradas_cpu()
{
if(cab1 != NULL)//se pregunta si existen procesos en cpu
{
 z.salidas_cpu();
 z.listar();
 z.graficar_memoria();
 z.graficar_cpu();
 delay(mis+2500);
 return 1;
}
else//CREA  EN CPU UN PROCESO
{
  z.relleno();
  setcolor(15);
  settextstyle(2,0,4);
  outtextxy(35,360,"Se dara Ingreso a un nuevo proceso");
  outtextxy(35,370,"dentro del procesador.");
  z.memoria_a_cpu();
  z.listar();
  z.graficar_memoria();
  z.graficar_cpu();
  delay(mis+2500);
  return 1;
}
}
void lista_procesos::salidas_cpu()
{
  setcolor(15);
  settextstyle(2,0,4);
  h=random(3);//MOTIVOS DE LA DESASIGNACION DE LA CPU
  switch(h){
	   case 0:{
		   outtextxy(35,360,"El proceso No...");
		   numero=(int )cab1->no_proceso;
		   itoa(numero, string, 10);
		   strcpy(u1,string);
		   outtextxy(35,370,u1);
		   outtextxy(35,380,"Solicito una intervenci¢n de E / S");
		   delay(mis+2500);
		   z.requerimientos();v=0;break;//requerimiento e/s
		  }
	   case 2:{
		   outtextxy(35,360,"El proceso...");
		   numero=(int )cab1->no_proceso;
		   itoa(numero, string, 10);
		   strcpy(u1,string);
		   outtextxy(35,370,u1);
		   outtextxy(35,380,"Ha Realizado un operaci¢n no valida");
		   outtextxy(35,390,"y se apagara.");
		   z.graficar_cpu();
		   delay(mis+2500);
		   z.crear(3);//CREA O ADICIONA EN LA LISTA DE DATOS HISTORICOS
		   z.eliminar_proceso_cpu();//LO ELIMINA DE LA CPU
		   v=1;break;
		  }
	   case 1:{
		   z.relleno();
		   setcolor(15);
		   outtextxy(35,360,"Por cuantum de Tiempo,  otro proceso");
		   outtextxy(35,370,"debe hacer uso del procesador ...");
		   delay(mis+2500);
		   z.de_cpu_a_memoria();v=0;break;}// SALE DE LA CPU POR CUANTUM DE TIEMPO Y VUELVE A MEMORIA
	   }
}

int lista_procesos::requerimientos()
{
 if(cab2 == NULL)
  cab2->no_proceso ='0';
 if(cab2->no_proceso != '0')//se pregunta si existen procesos en disp e/s
 {
  z.salidas_disp();
  z.de_cpu_a_disp();
  z.listar();
  z.graficar_memoria();
  z.graficar_cpu();
  delay(mis+2500);
  return 1;
 }
 else//CREA  nodo en disp e/s
 {
  z.de_cpu_a_disp();
  z.listar();
  z.graficar_memoria();
  z.graficar_cpu();
  return 1;
 }
}
int lista_procesos::de_cpu_a_disp()
{
  cab2=new nodo;
  cab2->no_proceso=cab1->no_proceso;
  cab2->cuantum_tiempo=cab1->cuantum_tiempo;
  cab2->long_proceso=cab1->long_proceso;
  cab2->sig=NULL;
  cab2->ant=NULL;
  z.relleno();
  z.eliminar_proceso_cpu();
  z.memoria_a_cpu();
return 0;
}
int lista_procesos::eliminar_proceso_cpu()
{
   setcolor(15);
   circle(520,400,55);
   setfillstyle(1,8);
   floodfill(535,415,15);
   free(cab1);
   cab1=NULL;
return 0;
}
int lista_procesos::de_cpu_a_memoria()
{
z.ajustar_en_memoria(1);//SACA DE LA CPU Y LO LLEVA A LA MEMORIA
z.eliminar_proceso_cpu();//LO ELIMINA DE LA MEMORIA
z.memoria_a_cpu();
return 0;
}
int lista_procesos::eliminar_procesos_memoria()
{
 while(p != NULL)
 {
  free(p);
  p=p->sig;
 }
return 1;
}
int lista_procesos::salidas_disp()
{
z.ajustar_en_memoria(2);//SACA DE LA DISP Y LO LLEVA A LA MEMORIA
z.eliminar_proceso_disp();//LO ELIMINA de la "cola" de disp e/s
return 0;
}
int lista_procesos::eliminar_proceso_disp()
{
   free(cab2);
   cab2=NULL;
return 0;
}
int lista_procesos::eliminar_lista_procesos(void)
{
  delete(cab1);
  delete(cab3);
  delete(cab4);
  while(p != NULL)
  {
   delete(p);
   p=p->sig;
  }
  while(p4 != NULL)
  {
   delete(p4);
   p4=p4->sig;
  }
  delete(cab2);
  delete(cab1);
  delete(cab3);
  delete(cab4);
  delete(cab);
  return 1;
}

void lista_procesos::listar_procesos_historicos()//LISTA LOS PROCESOS EN DATOS HISTORICOS
{
int f=80;
settextstyle(2,0,4);
pos_proceso=0;
cleardevice();
for(int u=1;u<=6;u++)
{
setcolor(u);
rectangle(u,u,getmaxx()-u,getmaxy()-u);
}
setcolor(14);
rectangle(u,u,getmaxx()-u,getmaxy()-u);

setcolor(15);
settextjustify(1,1);
outtextxy(getmaxx()/2,30,"LISTA DE PROCESOS HISTORICOS");
outtextxy(getmaxx()/2,50,"ESTADISTICA POR DIA");
outtextxy(getmaxx()/2,380,"®MOTIVOS DE ABANDONO DEL PROGRAMA¯");
outtextxy(getmaxx()/2,390,"[0] ® Desbordamiento. ¯");
outtextxy(getmaxx()/2,400,"[1] ® Divisi¢n por Cero. ¯");
outtextxy(getmaxx()/2,410,"[2] ® Error de protecci¢n en la memoria. ¯");
outtextxy(getmaxx()/2,420,"[3] ® Termino Satisfactoriamente por Cuantum de tiempo. ¯");

p3=q3=cab3;
//lista procesos en memoria real
while(p3 != NULL)
{
f+=10;
outtextxy(60,70,"N§ DEL PROCESO");
numero=(int )p3->no_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(80,f,u1);

outtextxy(200,70,"LONGITUD DEL PROCESO");
numero=p3->long_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(215,f,u1);

outtextxy(410,70,"MOTIVO DE SALIDA DEL PROCESADOR");
numero=p3->pos_proceso;
itoa(numero, string, 10);
strcpy(u1,string);
outtextxy(425,f,u1);


p3=p3->sig;
}
p3=q3=cab3;
getch();
f=getche();
}
int lista_procesos::ordenar_memoria()
{
int temp,temp2,n=0,i=0,j;
p4=cab4;
while(p4->sig != NULL)
{
 if(p4->no_proceso == 0 || p4->no_proceso == '\x0')
   p4->cuantum_tiempo=0;
 if(p4->cuantum_tiempo <= 0 && (p4->no_proceso != 0 || p4->no_proceso != '\x0'))
   p4->cuantum_tiempo=random(550);
 p4=p4->sig;
 n++;
}
p4=cab4;
mayor=p4->long_proceso;
for(i=0;i<=n-1;i++)
{
  for(j=0;j<=n-1;j++)
  {
   if(p4->long_proceso > p4->sig->long_proceso)
   {
    temp=p4->long_proceso;
    p4->long_proceso=p4->sig->long_proceso;
    p4->sig->long_proceso=temp;
    temp2=p4->no_proceso;
    p4->no_proceso=p4->sig->no_proceso;
    p4->sig->no_proceso=temp2;
   }
   if(mayor < p4->long_proceso)
    mayor=p4->long_proceso;
   p4=p4->sig;
  }
  p4=q4;
}
q4=p4=cab4;
return 0;
}
//PASA PROCESOS EN ESPERA DE MEMORIA A MEMORIA
int lista_procesos::memoria_real()
{
  int posicion=0;
  while(p != NULL)
  {
    posicion=posicion+p->long_proceso;
    if(posicion >= 1700)
     break;
    z.crear(4);
    eliminar(p->no_proceso);
  }
p=q=cab;
return 0;
}
int lista_procesos::ajustar_en_memoria(int u)
{
  int total=0,b;
  while(p4->sig != NULL)//CUENTO LOS NODOS DE LA LISTA DE MEMORIA
    p4=p4->sig;

 if(u==1)//AJUSTA EL PROCESO QUE TOME DEL PROCESADOR EN MEMORIA
 {
  while(p4->ant != NULL)
  {
    if(p4->long_proceso >= cab1->long_proceso)
     p4=p4->ant;
    else
    {
     p4=p4->sig;
     break;
    }
  }
  while(p4->sig != NULL)
  {
   if(p4->ant == NULL)
   p4=cab4;
   if(p4->no_proceso == 0 || p4->no_proceso =='\x0')
     break;
    p4=p4->sig;
   }
  if(p4->no_proceso == 0  && p4->cuantum_tiempo == 0)
  {
   p4->no_proceso=cab1->no_proceso;
   p4->long_proceso=cab1->long_proceso;
   p4->cuantum_tiempo=cab1->cuantum_tiempo;
   z.relleno();
   setcolor(15);
   settextstyle(2,0,4);
   outtextxy(35,370,"Se ajusto en memoria");
   numero=(int )p4->no_proceso;
   itoa(numero, string, 10);
   strcpy(u1,string);
   outtextxy(156,380,u1);
   outtextxy(35,380,"El  proceso ->");
   delay(mis+2500);
  }
  else
  {
     p4=cab4;
     while(p4->sig != NULL)
       p4=p4->sig;
     total=total+(p4->long_proceso + p4->pos_proceso + cab1->long_proceso);
     b = 1700 - total;
     if(b>=0)
     {
      while(p4->sig != NULL)
      p4=p4->sig;
      q4=new nodo;
      p4->sig=q4;
      q4->ant=p4;
      q4->no_proceso=cab1->no_proceso;
      q4->long_proceso=cab1->long_proceso;
      q4->cuantum_tiempo=cab1->cuantum_tiempo;
      q4->sig=NULL;
      if(q4->cuantum_tiempo < 0 )
       q4->cuantum_tiempo = q4->cuantum_tiempo * (-1);
      p4=q4=cab4;
      z.relleno();
      setcolor(15);
      settextstyle(2,0,4);
      outtextxy(35,370,"Se ajusto en memoria");
      numero=(int )cab1->no_proceso;
      itoa(numero, string, 10);
      strcpy(u1,string);
      outtextxy(156,380,u1);
      outtextxy(35,380,"El  proceso ->");
      delay(mis+2500);
     }
     else
     {
     z.relleno();
     z.crear(2);
     }
  }
  if(p4->ant == NULL)
   p4->pos_proceso=0;
  else
   p4->pos_proceso=p4->ant->long_proceso+p4->ant->pos_proceso;
  }
 if(u==2)//TOMA EL PROCESO DEL DISP Y LO UBICA EN LA MEMORIA O EN LA COLA
 {
   while(p4->ant != NULL)
  {
    if(p4->long_proceso >= cab2->long_proceso)
     p4=p4->ant;
    else
    {
     p4=p4->sig;
     break;
    }
  }
  while(p4->sig != NULL)
  {
   if(p4->ant == NULL)
   p4=cab4;
   if(p4->no_proceso == 0)
     break;
    p4=p4->sig;
   }
  if(p4->no_proceso == 0  && p4->cuantum_tiempo == 0)
  {
   p4->no_proceso=cab2->no_proceso;
   p4->long_proceso=cab2->long_proceso;
   p4->cuantum_tiempo=cab2->cuantum_tiempo;
   z.relleno();
   setcolor(15);
   settextstyle(2,0,4);
   outtextxy(35,370,"Se ajusto en memoria");
   numero=(int )p4->no_proceso;
   itoa(numero, string, 10);
   strcpy(u1,string);
   outtextxy(156,380,u1);
   outtextxy(35,380,"El  proceso ->");
   delay(mis+2500);
  }
  else
  {
     p4=cab4;
     while(p4->sig != NULL)
       p4=p4->sig;
     total=total+(p4->long_proceso + p4->pos_proceso + cab2->long_proceso);
     b = 1700 - total;
     if(b>=0)
     {
      while(p4->sig != NULL)
      p4=p4->sig;
      q4=new nodo;
      p4->sig=q4;
      q4->ant=p4;
      q4->no_proceso=cab2->no_proceso;
      q4->long_proceso=cab2->long_proceso;
      q4->cuantum_tiempo=cab2->cuantum_tiempo;
      q4->sig=NULL;
      if(q4->cuantum_tiempo < 0 )
       q4->cuantum_tiempo = q4->cuantum_tiempo * (-1);
      p4=q4=cab4;
      z.relleno();
      setcolor(15);
      settextstyle(2,0,4);
      outtextxy(35,370,"Se ajusto en memoria");
      numero=(int )cab2->no_proceso;
      itoa(numero, string, 10);
      strcpy(u1,string);
      outtextxy(156,380,u1);
      outtextxy(35,380,"El  proceso ->");
      delay(mis+2500);
     }
     else
     {
	z.crear(5);
     }
  }
  if(p4->ant == NULL)
   p4->pos_proceso=0;
  else
   p4->pos_proceso=p4->ant->long_proceso+p4->ant->pos_proceso;
  }
  if(u==3)//TOMA DE LA COLA DE PROCESOS Y LO ADICIONA EN MEMORIA
  {
  int l=1;
  p=cab;
  do
  {
   while(p4->ant != NULL)
   {
     if(p4->long_proceso >= p->long_proceso)
      p4=p4->ant;
     else
     {
      p4=p4->sig;
      break;
     }
   }
   while(p4 ->sig != NULL)
   {
     if( p4->ant == NULL)
      p4=cab4;
     if(p4->no_proceso == 0 || p4->no_proceso == '\x0')
       break;
     p4=p4->sig;
   }
    if(p4->no_proceso == 0 && p4->cuantum_tiempo == 0)
    {
     p4->no_proceso=p->no_proceso;
     p4->long_proceso=p->long_proceso;
     p4->cuantum_tiempo=p->cuantum_tiempo;
     z.relleno();
     setcolor(15);
     settextstyle(2,0,4);
     outtextxy(35,370,"Se ajusto en memoria");
     numero=(int )p4->no_proceso;
     itoa(numero, string, 10);
     strcpy(u1,string);
     outtextxy(156,380,u1);
     outtextxy(35,380,"El  proceso ->");
     eliminar(p->no_proceso);
     l=0;
     delay(mis+2500);
    }
    else
    {
     p4=cab4;
     while(p4->sig != NULL)
       p4=p4->sig;
     total=total+(p4->long_proceso + p4->pos_proceso + p->long_proceso);
     b = 1700 - total;
     if(b>=0)
     {
      while(p4->sig != NULL)
      p4=p4->sig;
      q4=new nodo;
      p4->sig=q4;
      q4->ant=p4;
      q4->no_proceso=p->no_proceso;
      q4->long_proceso=p->long_proceso;
      q4->cuantum_tiempo=p->cuantum_tiempo;
      q4->pos_proceso=p->pos_proceso;
      q4->sig=NULL;
      if(q4->cuantum_tiempo < 0 )
       q4->cuantum_tiempo = q4->cuantum_tiempo * (-1);
      p4=q4=cab4;
      z.relleno();
      setcolor(15);
      settextstyle(2,0,4);
      outtextxy(35,370,"Se ajusto en memoria");
      numero=(int )p->no_proceso;
      itoa(numero, string, 10);
      strcpy(u1,string);
      outtextxy(156,380,u1);
      outtextxy(35,380,"El  proceso ->");
      eliminar(p->no_proceso);
      l=0;
      delay(mis+2500);
     }
     else
     {
      if(p->sig == NULL)
       l=0;
      else
      p=p->sig;
     }
   }
   }while(l==1);


  if(p4->ant == NULL)
   p4->pos_proceso=0;
  else
   p4->pos_proceso=p4->ant->long_proceso+p4->ant->pos_proceso;
  }
p=cab;
p4=cab4;
return 0;
}
int lista_procesos::graficar_memoria()
{
 double r=0;
 int acum=0;
 settextstyle(2,2,4);
 outtextxy(605,150,"MEMORIA");
 settextstyle(2,0,4);
 setcolor(4);
 setlinestyle(0,0,0);
 if(cab1 == NULL)
 {
 outtextxy(494,396,"PROCESADOR");
 circle(520,400,55);
 setfillstyle(1,8);
 floodfill(525,405,4);
 }
 setcolor(15);
 rectangle(450,50,600,320);
 setfillstyle(1,8);
 floodfill(455,250,15);
 outtextxy(474,37,"Ilustraci¢n Memoria");
 setcolor(15);
 rectangle(450,50,600,320);
 setcolor(15);
 rectangle(450,10,470,20);
 setfillstyle(1,8);
 floodfill(455,18,15);
 outtextxy(475,10," ->¯ Espacio Disponible");
 rectangle(450,25,470,33);
 setfillstyle(m,14);
 floodfill(455,28,15);
 outtextxy(475,25," ->¯ Espacio Ocupado");
 p4=cab4;
 while(p4->sig != NULL)
 {
   m++;k++;
   if(m >= 10 )
    m=3;
   if(k == 15)
    k=1;
   if(k == 9)
    k=10;
    acum=acum+p4->long_proceso;
   r=(acum)*(0.1475);
   r=ceil(r);

   if(p4->no_proceso == 0 && p4->sig->no_proceso != 0)
   {
     setcolor(15);
     line(450,50+r,600,50+r);
   }
   else if(p4->no_proceso != 0 )
   {
     setcolor(15);
     line(450,50+r,600,50+r);
     setfillstyle(m,k);
     floodfill(455,(50+r)-3,15);
   }


   p4=p4->sig;
  }
  k++;
  if(m >= 10 )
   m=3;
  m++;
  if(k >= 15 )
   k=1;
  if(k == 9)
   k=10;
  r=(p4->pos_proceso+p4->long_proceso)*(0.1475);
  r=ceil(r);

  if(p4->no_proceso == 0)
  {
    setcolor(15);
    line(450,50+r,600,50+r);
  }
  else
  {
     setcolor(15);
     line(450,50+r,600,50+r);
     setfillstyle(m,k);
     floodfill(455,(50+r)-3,15);
  }
p4=cab4;
return 1;
}

int lista_procesos::graficar_cpu()
{
 static m2=3,k2=1;
 m2++;k2++;
 if(m2 >= 10 )
   m2=3;
 if(k2 == 15)
   k2=1;
 if(k2 == 9)
   k2=10;
 setlinestyle(0,0,0);
 setcolor(4);
 circle(520,400,55);
 setfillstyle(m2,k2);
 floodfill(535,415,4);
 setcolor(15);
 outtextxy(494,396,"Procesador");
 return 1;
}
void explicar()
{
     int h=0;
     cleardevice();
     setcolor(15);
     rectangle(20,20,getmaxx()/2,getmaxy()/2);
     rectangle(getmaxx()/2,getmaxy()/2,getmaxx()-20,getmaxy()-20);
     settextstyle(2,0,4);
     rectangle(4,4,getmaxx()-4,getmaxy()-4);
     rectangle(6,6,getmaxx()-6,getmaxy()-6);
     setcolor(10);
     setfillstyle(1,9);
     floodfill(500,100,15);
     floodfill(100,300,15);
     setcolor(4);
     outtextxy(25,40,"EL SISTEMA OPERATIVO EXPLICADO EN ESTE PROGRAMA ");
     outtextxy(25,60,"ES UN PROCESAMIENTO MULTITAREA.");
     setcolor(14);
     outtextxy(25,120,"LOS SISTEMAS OPERATIVOS SON LOS  ");
     outtextxy(25,140,"UTILIZADOS EN  LOS COMPUTADORES  ");
     outtextxy(25,160,"EJEMPLO EL DOS, WINDOWS 95, UNIX. ");
     setcolor(11);
     outtextxy(325,280,"SE SIMULA COMO SE COMPORTAN LOS PROCESOS     ");
     outtextxy(325,300,"MULTITAREA EN LA MEMORIA,  INDICANDO LAS     ");
     outtextxy(325,320,"OPERACIONES QUE SE VAN GENERANDO  Y  ASI MISMO");
     outtextxy(325,340,"EXPLICANDO GRAFICA Y TEORICAMENTE LA INSIDENCIA ");
     outtextxy(325,360,"DE LAS MISMAS DENTRO DEL SISTEMA. EL PROCESADOR ");
     outtextxy(325,380,"SE COMPARTE POR PERIODOS DE TIEMPO DETERMINADOS,");
     outtextxy(325,400,"DANDO INGRESO AL PROCESO EN MEMORIA  DE  MANERA");
     outtextxy(325,420,"QUE SEA EL QUE MAS SE AJUSTE.");
     setcolor(15);
     settextstyle(4,0,2);
     outtextxy(335,90,"SIMULACION DE UN");
     outtextxy(335,130,"  PROCESO MULTITAREA");
     outtextxy(35,320,"SISTEMAS");
     outtextxy(35,360,"        OPERATIVOS");
     settextstyle(2,0,4);
     do
     {
     setcolor(h++);
     outtextxy(55,420,"®Pulse cualquier tecla para continuar¯");
     if(h==15)
     h=1;
     delay(150);
     }while(!kbhit());
     getch();
}
void defin()
{
     int h=0;
     cleardevice();
     setcolor(15);
     rectangle(20,20,getmaxx()/2,getmaxy()/2);
     rectangle(getmaxx()/2,getmaxy()/2,getmaxx()-20,getmaxy()-20);
     settextstyle(2,0,4);
     rectangle(4,4,getmaxx()-4,getmaxy()-4);
     rectangle(6,6,getmaxx()-6,getmaxy()-6);
     setcolor(4);
     setfillstyle(1,9);
     floodfill(500,100,15);
     floodfill(100,300,15);
     setcolor(10);
     settextstyle(2,0,4);
     outtextxy(25,40,"               SISTEMA OPERATIVO");
     setcolor(15);
     outtextxy(32,100,"CONJUNTO DE PROGRAMAS QUE SIRVEN COMO INTERFAZ");
     outtextxy(32,120,"ENTRE EL USUARIO Y  LA MAQUINA  Y  ADEMAS COMO");
     outtextxy(32,140,"ADMINISTRADOR DE LOS RECURSOS DEL SISTEMA, ES");
     outtextxy(32,160,"DECIR  ADMINISTRADOR  DE  LOS  RECURSOS TANTO");
     outtextxy(32,180,"DEL HARDWARE COMO DEL SOFTWARE.");

     setcolor(11);
     outtextxy(322,250,"EJEMPLO DEL FUNCIONAMIENTO DE UN SISTEMA OPERATIVO ");
     outtextxy(325,270,"1.SE CREA EL ARCHIVO DEL PROGRAMA");
     outtextxy(325,280,"2.SE CONSTRUYE UN TRABAJO A PARTIR  DEL ARCHIVO");
     outtextxy(325,290,"  DEL PROGRAMA (JOB).");
     outtextxy(325,300,"3.EL PLANIFICADOR ASIGNA MEMORIA ");
     outtextxy(325,310,"4.EL DESPACHADOR LE ASIGNA PROCESADOR");
     outtextxy(325,320,"5.ENCOLA EN DISPOSITIVO DE MEMORIA  AUXILIAR SI ");
     outtextxy(325,330,"  EL PROCESO REQUIERE DATOS");
     outtextxy(325,340,"6.SE REALIZA LA  LECTURA VIRTUAL  Y  SE  ENCOLA ");
     outtextxy(325,350,"  EN PROCESOS ACTIVOS");
     outtextxy(325,360,"7.EL DESPACHADOR LE ASIGNA EL PROCESADOR");
     outtextxy(325,370,"8.SI NECESITA ESCRIBIR UNA LINEA ASIGNA IMPRESION");
     outtextxy(325,380,"  VIRTUAL.");
     outtextxy(325,390,"9.SE REALIZA LA  IMPRESION VIRTUAL Y   ENCOLA  EN");
     outtextxy(325,400,"  PROCESOS ACTIVOS.");
     outtextxy(325,410,"10.EL DESPACHADOR LE ASIGNA PROCESADOR");
     outtextxy(325,420,"11.EL PROCESO FINALIZA SU EJECUCION Y ES RETIRADO ");
     outtextxy(325,430,"   DE LA COLA DE PROCESOS ACTIVOS.");
     setcolor(15);
     settextstyle(4,0,2);
     outtextxy(335,90,"SIMULACION DE UN");
     outtextxy(335,130,"  PROCESO MULTITAREA");
     outtextxy(35,320,"SISTEMAS");
     outtextxy(35,360,"        OPERATIVOS");
     settextstyle(2,0,4);
     do
     {
     setcolor(h++);
     outtextxy(55,420,"®Pulse cualquier tecla para continuar¯");
     if(h==15)
     h=1;
     delay(150);
     }while(!kbhit());
     getch();

}
void clases()
{
     int h=0;
     cleardevice();
     setcolor(15);
     rectangle(20,20,getmaxx()/2,getmaxy()/2);
     rectangle(getmaxx()/2,getmaxy()/2,getmaxx()-20,getmaxy()-20);
     settextstyle(2,0,4);
     rectangle(4,4,getmaxx()-4,getmaxy()-4);
     rectangle(6,6,getmaxx()-6,getmaxy()-6);
     setcolor(4);
     setfillstyle(1,9);
     floodfill(500,100,15);
     floodfill(100,300,15);
     setcolor(10);
     settextstyle(2,0,4);
     outtextxy(24,40,"          CLASES DE SISTEMAS OPERATIVOS");
     setcolor(15);
     outtextxy(32,70,"LOS SISTEMAS OPERATIVOS PUEDEN SER:");
     outtextxy(32,90,"*) MONOPROGRMACION   (MONOUSUARIO).");
     outtextxy(32,100,"*) MULTITAREA      (MULTIUSUARIO).");
     setcolor(11);
     outtextxy(32,120,"LOS SISTEMAS OPERATIVOS MONOUSUARIO SON AQUELLOS");
     outtextxy(32,130,"MUY   UTILIZADOS    EN    LOS  MICROCOMPUTADORES");
     outtextxy(32,140,"TRADICIONALES. EJEMPLO: DOS ");
     setcolor(14);
     outtextxy(32,170,"LOS SISTEMAS  OPERATIVOS  MULTITARE ");
     outtextxy(32,180,"PERMITEN  EJECUTAR MAS DE UN PROGRAMA AL MISMO");
     outtextxy(32,190,"TIEMPO, LOS USUARIOSS PUEDEN CONMUTAR ENTRE");
     outtextxy(32,200,"APLICACIONES. EJEMPLO: OS/2, UNIX, WINDOWS 95.");
     setcolor(GREEN);
     outtextxy(325,260,"LOS   SISTEMAS    OPERATIVOS   MULTITAREA");
     outtextxy(325,280,"UTILIZAN  MAS EFICIENTEMENTE LA MEMORIA, QUE LOS");
     outtextxy(325,300,"SISTEMAS  OPERATIVOS MONOPROGRAMACION.");
     outtextxy(325,320,"LOS SISTEMAS OPERATIVOS MULTITAREA SON MAS");
     outtextxy(325,340,"SOFISTICADOS   Y   COMPLEJOS   QUE  LOS  SISTEMAS ");
     outtextxy(325,360,"OPERATIVOS  MONOPROGRAMACION,   PUESTO  QUE    LA");
     outtextxy(325,380,"COORDINACION DE LAS OPERACIONES ES MAS RIGUROSA Y");
     outtextxy(325,400,"SEGURA   QUE    EN   LOS    SISTEMAS   OPERATIVOS");
     outtextxy(325,420,"MONOPROGRAMACION.");
     setcolor(15);
     settextstyle(4,0,2);
     outtextxy(335,90,"SIMULACION DE UN");
     outtextxy(335,130,"  PROCESO MULTITAREA");
     outtextxy(35,320,"SISTEMAS");
     outtextxy(35,360,"        OPERATIVOS");
     settextstyle(2,0,4);
     do
     {
     setcolor(h++);
     outtextxy(55,420,"®Pulse cualquier tecla para continuar¯");
     if(h==15)
     h=1;
     delay(250);
     }while(!kbhit());
     getch();

}


void portada()
{
  int i=0;
  cleardevice();
  settextstyle(1,0,1);
  do
  {
   rectangle(1,1,getmaxx()-1,getmaxy()-1);
   rectangle(3,3,getmaxx()-3,getmaxy()-3);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   setcolor(i);
   settextstyle(1,0,4);
   outtextxy(getmaxx()/2,90,"UNIVERSIDAD ANTONIO NARI¥O");
   settextstyle(1,0,3);
   setcolor(i+6);
   outtextxy(getmaxx()/2,150,"FACULTAD DE INGENIERIA DE SISTEMAS");
   outtextxy(getmaxx()/2,430,"Presione Cualquier tecla para continuar...");

   i++;
   delay(261);
   settextstyle(1,0,3);
   setcolor(i);
   outtextxy(209,200,"SI");
   setcolor(i+1);
   outtextxy(235,200,"ST");
   setcolor(i+2);
   outtextxy(265,200,"EM");
   setcolor(i+3);
   outtextxy(294,200,"AS");
   setcolor(i+4);
   outtextxy(330,200,"OP");
   setcolor(i+5);
   outtextxy(362,200,"ER");
   setcolor(i+6);
   outtextxy(394,200,"ATI");
   setcolor(i);
   outtextxy(428,200,"VOS");
   settextstyle(1,0,1);
   setcolor(i);
   outtextxy(150,300,"MA");
   setcolor(i+1);
   outtextxy(175,300,"RI");
   setcolor(i+2);
   outtextxy(198,300,"LUZ");
   setcolor(i+3);
   outtextxy(227,300," SO");
   setcolor(i+4);
   outtextxy(249,300," LE");
   setcolor(i+5);
   outtextxy(272,300,"R");
   outtextxy(380+10,300,"49");
   setcolor(i);
   outtextxy(380+10,330,"49");
   setcolor(i+2);
   outtextxy(403+10,330,"31");
   setcolor(i+3);
   outtextxy(425+10,330,"90");
   setcolor(i+5);
   outtextxy(403+10,300,"34");
   setcolor(i+6);
   outtextxy(425+10,300,"42");
   outtextxy(380+10,360,"49");
   setcolor(i);
   outtextxy(380+10,390,"49");
   setcolor(i+2);
   outtextxy(403+10,390,"34");
   setcolor(i+3);
   outtextxy(425+10,390,"44");
   setcolor(i);
  setcolor(i+2);
   outtextxy(403+10,360,"31");
   setcolor(i+3);
   outtextxy(425+10,360,"34");
   setcolor(i+6);
   outtextxy(150,330,"PI");
   setcolor(i+5);
   outtextxy(175,330,"LA");
   setcolor(i+4);
   outtextxy(198,330,"R");
   setcolor(i+3);
   outtextxy(235,330,"AVE");
   setcolor(i+2);
   outtextxy(262,330,"LL");
   setcolor(i+2);
   outtextxy(272,330," A");
   setcolor(i);
   outtextxy(150,360,"EL");
   setcolor(i+2);
   outtextxy(175,360,"SY");
   setcolor(i);
   outtextxy(198,360,"  AN");
   setcolor(i+1);
   outtextxy(220,360,"  GA");
   setcolor(i+2);
   outtextxy(242,360,"  RI");
   setcolor(i+3);
   outtextxy(265,360,"  TA");
   setcolor(i+4);
   outtextxy(150,390,"CA");
   setcolor(i+5);
   outtextxy(175,390,"RL");
   setcolor(i+6);
   outtextxy(198,390,"OS");
   setcolor(i+6);
   outtextxy(220,390," DI");
   setcolor(i+2);
   outtextxy(242,390,"AZ");
   setcolor(i+6);
   }while(!kbhit());
   getch();
}
//COMPACTAR MEMORIA
int lista_procesos::compactar_memoria()
{
r4=p4=cab4;
while(p4->sig != NULL)
{
 if((p4->no_proceso == 0 || p4->no_proceso == '\x0')&&(p4->sig->no_proceso == 0 || p4->sig->no_proceso == '\x0'))
 {
  while(r4->sig != p4)
   r4=r4->sig;
  q4=new nodo;
  r4->sig=q4;
  q4->ant=r4;
  q4->no_proceso=0;
  q4->long_proceso=p4->long_proceso + p4->sig->long_proceso;
  q4->pos_proceso=p4->pos_proceso + p4->sig->pos_proceso;
  if(p4->sig->sig == NULL)
    q4->sig=NULL;
  else
   q4->sig = p4->sig->sig;
   r4=p4->sig;
  free(p4);
  free(r4);
  p4=q4=cab4;
  break;
 }
 else
  p4=p4->sig;
}
return 1;
}