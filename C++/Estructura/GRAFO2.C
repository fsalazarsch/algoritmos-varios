/***************************** INICIO DEL PROGRAMA ********************************/

/************************** DECLARACION DE LIBRERIAS ***************************/
      

#include <conio.h>   
#include <graphics.h>
#include <stdio.h>
#include <alloc.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <dos.h>
#include <io.h>
#include <ctype.h>
#include <stdlib.h>
#include <setjmp.h>


/******************************************************************************/

/************************** DECLARACION DE LOS PROCEDIMIENTOS *****************/


void piso_color(int piso,int color);
void eliminar_ultimo_lista();
struct arco *buscar_arco();
void ruta();
void ref1();
void ref2();
void clave();
void udes();
void marco();
void marco2();
void fondo();
void menu1();
void escribe_menu();
void escribe_menu2();
void escribe_menu4();
void escribe_menu5();
void menu2();
void menu3();
void menu4();
void escribe_menu3();
void ayuda();
void salir();
void imprimir();
void grado_int();
void grado_ext();
void imprimir_rutas();
void eliminar_rutas();

void adicionar_archivo_nodo(char origen[20],int estacionamiento);
void borrar_archivo_nodo(char origen[20]);
void modificar_ciudad(char origen[20],int estanco);
void adicionar_archivo_arista(char origen[20],char destino[20],int peaje,int kmts);
void modificar_arista(char origen[20],char destino[20],int costo,int distan);
void borrar_archivo_arcos(char origen[20],char destino[20]);


/******************************************************************************/

/*********************** ESTRUCTURAS , VARIABLES Y CONSTANTES *****************************/


const int val_peaje=600;
const int val_km=50;

 struct arch_nodo
 {
 char ciudad[20];
 int estacion;
 };

 struct arch_arista
 {
 char origen[20];
 char destino[20];
 int peaje;
 int distancia;
 };


 struct nodo 
      {
       char ciudad[20];
       int estacion;
       struct nodo *sig;
       struct arco *ady;
       };

 struct arco {
       int kmts;
       int peaje;
       struct arco *sig;
       struct nodo *dest;
       };

 struct lista_pri{
       char ciudad[20];
       long costo;
       struct listady *ady;
       struct lista_pri *sig;
       };

struct listady{
       char ciudad[20];
       long costo;
       struct listady *sig;
       };


 struct lista_pri  *listapri;
 struct listady *lista;

 struct nodo *mul;
 struct arch_nodo dato,auxdato;
 struct arch_arista arista,auxarista;
 int modo_recorrido,dno,dar,auxdno,auxdar,validacion;


char op2[5][20]={" ","Listado de Nodos","Listado de Aristas","Imprimir Grafo","Salir      "};
char op[8][15]={" ","Adicionar","Consultar","Eliminar","Modificar","Grado Interno","Grado Externo","Salir     "};
char op3[6][10]={" ","Adicionar","Consultar","Eliminar","Modificar","Salir "};
char op4[7][18]={" ","Ruta Mas Corta","Ruta Mas Larga","Ruta Mas Cara","Ruta Barata","Todas las Rutas","Salir    "};
int sw2,i,j,st,lon;

char origen[20],destino[20],ciud[20],valido;



/**********************************************************************************/


/***************************** PRESENTACIONES ***********************************/



//------------------------------------------------------------------------------/

void cuadros1(int x1,int x2,int y1,int y2)
  {
     int j,i,k,p,h,con;
     con=0; h=1; p=500;
     while(con<=1)
     {
     textcolor(h);textbackground(0);
     for(j=x1;j<=x2;j++)
       { delay (10);
       sound(p);gotoxy(j,y1);cprintf("&");
       h++;p=p+10;
       textcolor(h);textbackground(0);
       sound(p);gotoxy(j,y2);cprintf("&");
       if(h==15)
       {
       p=p-48;
       h=h-13;
       }
       } 
     for(i=y1;i<=y2-1;i++)
       { delay(10);
       sound(p);gotoxy(x1,i);cprintf("&");
       h++;p=p+10;
       textcolor(h);textbackground(0);
       sound(p);gotoxy(x2,i);cprintf("&");
       if(h==10)
       {
       p=p-48;
       h=h-8;
       }
       }
     gotoxy(x1,y1);cprintf("&");
     gotoxy(x2,y1);cprintf("&");
     gotoxy(x1,y2);cprintf("&");
     gotoxy(x2,y2);cprintf("&");
     textcolor(h);textbackground(0);
     con++;h--; p--;
     }
    nosound();
}




//------------------------------------------------------------------------------//


void ruta()
{
	
textcolor(4); textbackground(3);

gotoxy(16,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");	    
gotoxy(16,7); cprintf("º                                                  º");
gotoxy(16,8); cprintf("º ÛÛÛÛÛ     ÛÛ   ÛÛ   ÛÛÛÛÛÛÛÛ    ÛÛÛÛÛ     ÛÛÛÛ   º");
gotoxy(16,9); cprintf("º ÛÛ  ÛÛ    ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ   ÛÛ  ÛÛ  º");
gotoxy(16,10);cprintf("º ÛÛ  ÛÛ    ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ   ÛÛ      º");
gotoxy(16,11);cprintf("º ÛÛÛÛÛ     ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ   ÛÛ      º");
gotoxy(16,12);cprintf("º ÛÛÛÛ      ÛÛ   ÛÛ      ÛÛ      ÛÛÛÛÛÛÛ    ÛÛÛÛ   º");
gotoxy(16,13);cprintf("º ÛÛ ÛÛ     ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ      ÛÛÛ  º"); 
gotoxy(16,14);cprintf("º ÛÛ  ÛÛ    ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ        ÛÛ º");
gotoxy(16,15);cprintf("º ÛÛ   ÛÛ   ÛÛ   ÛÛ      ÛÛ      ÛÛ   ÛÛ        ÛÛ º");
gotoxy(16,16);cprintf("º ÛÛ   ÛÛ   ÛÛÛÛÛÛÛ      ÛÛ      ÛÛ   ÛÛ   ÛÛÛÛÛÛ  º");
gotoxy(16,17);cprintf("º                                                  º");
gotoxy(16,18);cprintf("º                                                  º");
gotoxy(16,19);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");	    						     
textcolor(0);
gotoxy(17,18);cprintf("Derechos Reservados");
}
									 
void udes()
 {
 clrscr();
 textbackground(0);
 for(i=0; i<=20; i++)
 {
 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º ÚÄÄÄ¿  ÚÄÄÄ¿ ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ º");
 gotoxy(18,8); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛÛÛÛÜÜ³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,9); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛÚ¿ßÛÛ³ ³ÛÛÛÚÄÄÄÙ ³ÛÛÛÚÄÄÄÙ º");
 gotoxy(18,10);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³À¿ÛÛ³ ³ÛÛÛÀÄÄÄ¿ ³ÛÛÛÀÄÄÄ¿ º");
 gotoxy(18,11);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³ ³ÛÛ³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,12);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³ÚÙÛÛ³ ³ÛÛÛÚÄÄÄÙ ÀÄÄÄ¿ÛÛÛ³ º");
 gotoxy(18,13);cprintf("º ³ÛÛÛÀÄÄÙÛÛÛ³ ³ÛÛÛÀÙÜÛÛ³ ³ÛÛÛÀÄÄÄ¿ ÚÄÄÄÙÛÛÛ³ º");
 gotoxy(18,14);cprintf("º ³ÛÛÛÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛßß³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,15);cprintf("º ÀÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÙ º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 gotoxy(14,23);printf("DERECHOS RESERVADOS ");
 textcolor(15);gotoxy(45,23);printf("UBALDO MURGAS GRANADOS");
 gotoxy(53,24);printf("S4A");
 }

 for(i=0; i<=50; i++)
 {
 delay(200);
 i++;  
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º ÚÄÄÄ¿  ÚÄÄÄ¿                                º");
 gotoxy(18,8); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,9); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,10);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,11);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,12);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,13);cprintf("º ³ÛÛÛÀÄÄÙÛÛÛ³                                º");
 gotoxy(18,14);cprintf("º ³ÛÛÛÛÛÛÛÛÛÛ³                                º");
 gotoxy(18,15);cprintf("º ÀÄÄÄÄÄÄÄÄÄÄÙ                                º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 gotoxy(14,23);printf("DERECHOS RESERVADOS DEL AUTOR:");
 textcolor(15);gotoxy(45,23);printf("UBALDO MURGAS GRANADOS");
 gotoxy(53,24);printf("S4A");

 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º              ÚÄÄÄÄÄÄÄÄ¿                     º");
 gotoxy(18,8); cprintf("º              ³ÛÛÛÛÛÛÜÜ³                     º");
 gotoxy(18,9); cprintf("º              ³ÛÛÛÚ¿ßÛÛ³                     º");
 gotoxy(18,10);cprintf("º              ³ÛÛÛ³À¿ÛÛ³                     º");
 gotoxy(18,11);cprintf("º              ³ÛÛÛ³ ³ÛÛ³                     º");
 gotoxy(18,12);cprintf("º              ³ÛÛÛ³ÚÙÛÛ³                     º");
 gotoxy(18,13);cprintf("º              ³ÛÛÛÀÙÜÛÛ³                     º");
 gotoxy(18,14);cprintf("º              ³ÛÛÛÛÛÛßß³                     º");
 gotoxy(18,15);cprintf("º              ÀÄÄÄÄÄÄÄÄÙ                     º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 gotoxy(14,23);printf("DERECHOS RESERVADOS DEL AUTOR:");
 textcolor(15);gotoxy(45,23);printf("UBALDO MURGAS GRANADOS");
 gotoxy(53,24);printf("S4A");



 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º                         ÚÄÄÄÄÄÄÄ¿           º");
 gotoxy(18,8); cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,9); cprintf("º                         ³ÛÛÛÚÄÄÄÙ           º");
 gotoxy(18,10);cprintf("º                         ³ÛÛÛÀÄÄÄ¿           º");
 gotoxy(18,11);cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,12);cprintf("º                         ³ÛÛÛÚÄÄÄÙ           º");
 gotoxy(18,13);cprintf("º                         ³ÛÛÛÀÄÄÄ¿           º");
 gotoxy(18,14);cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,15);cprintf("º                         ÀÄÄÄÄÄÄÄÙ           º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 

 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º                                   ÚÄÄÄÄÄÄÄ¿ º");
 gotoxy(18,8); cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,9); cprintf("º                                   ³ÛÛÛÚÄÄÄÙ º");
 gotoxy(18,10);cprintf("º                                   ³ÛÛÛÀÄÄÄ¿ º");
 gotoxy(18,11);cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,12);cprintf("º                                   ÀÄÄÄ¿ÛÛÛ³ º");
 gotoxy(18,13);cprintf("º                                   ÚÄÄÄÙÛÛÛ³ º");
 gotoxy(18,14);cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,15);cprintf("º                                   ÀÄÄÄÄÄÄÄÙ º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
  

 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º                                   ÚÄÄÄÄÄÄÄ¿ º");
 gotoxy(18,8); cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,9); cprintf("º                                   ³ÛÛÛÚÄÄÄÙ º");
 gotoxy(18,10);cprintf("º                                   ³ÛÛÛÀÄÄÄ¿ º");
 gotoxy(18,11);cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,12);cprintf("º                                   ÀÄÄÄ¿ÛÛÛ³ º");
 gotoxy(18,13);cprintf("º                                   ÚÄÄÄÙÛÛÛ³ º");
 gotoxy(18,14);cprintf("º                                   ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,15);cprintf("º                                   ÀÄÄÄÄÄÄÄÙ º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 
 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º                         ÚÄÄÄÄÄÄÄ¿           º");
 gotoxy(18,8); cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,9); cprintf("º                         ³ÛÛÛÚÄÄÄÙ           º");
 gotoxy(18,10);cprintf("º                         ³ÛÛÛÀÄÄÄ¿           º");
 gotoxy(18,11);cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,12);cprintf("º                         ³ÛÛÛÚÄÄÄÙ           º");
 gotoxy(18,13);cprintf("º                         ³ÛÛÛÀÄÄÄ¿           º");
 gotoxy(18,14);cprintf("º                         ³ÛÛÛÛÛÛÛ³           º");
 gotoxy(18,15);cprintf("º                         ÀÄÄÄÄÄÄÄÙ           º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 
 delay(200);
 i++;
 clrscr();
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º              ÚÄÄÄÄÄÄÄÄ¿                     º");
 gotoxy(18,8); cprintf("º              ³ÛÛÛÛÛÛÜÜ³                     º");
 gotoxy(18,9); cprintf("º              ³ÛÛÛÚ¿ßÛÛ³                     º");
 gotoxy(18,10);cprintf("º              ³ÛÛÛ³À¿ÛÛ³                     º");
 gotoxy(18,11);cprintf("º              ³ÛÛÛ³ ³ÛÛ³                     º");
 gotoxy(18,12);cprintf("º              ³ÛÛÛ³ÚÙÛÛ³                     º");
 gotoxy(18,13);cprintf("º              ³ÛÛÛÀÙÜÛÛ³                     º");
 gotoxy(18,14);cprintf("º              ³ÛÛÛÛÛÛßß³                     º");
 gotoxy(18,15);cprintf("º              ÀÄÄÄÄÄÄÄÄÙ                     º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 
 delay(200);
 i++;
 textcolor(i);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º ÚÄÄÄ¿  ÚÄÄÄ¿                                º");
 gotoxy(18,8); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,9); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,10);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,11);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,12);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³                                º");
 gotoxy(18,13);cprintf("º ³ÛÛÛÀÄÄÙÛÛÛ³                                º");
 gotoxy(18,14);cprintf("º ³ÛÛÛÛÛÛÛÛÛÛ³                                º");
 gotoxy(18,15);cprintf("º ÀÄÄÄÄÄÄÄÄÄÄÙ                                º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 }

 textbackground(0);
 for(i=10; i<=30;  i++)
 {
 textcolor(i);textbackground(1);
 delay(200);
 gotoxy(18,6); cprintf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
 gotoxy(18,7); cprintf("º ÚÄÄÄ¿  ÚÄÄÄ¿ ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄ¿ º");
 gotoxy(18,8); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛÛÛÛÜÜ³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,9); cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛÚ¿ßÛÛ³ ³ÛÛÛÚÄÄÄÙ ³ÛÛÛÚÄÄÄÙ º");
 gotoxy(18,10);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³À¿ÛÛ³ ³ÛÛÛÀÄÄÄ¿ ³ÛÛÛÀÄÄÄ¿ º");
 gotoxy(18,11);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³ ³ÛÛ³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,12);cprintf("º ³ÛÛÛ³  ³ÛÛÛ³ ³ÛÛÛ³ÚÙÛÛ³ ³ÛÛÛÚÄÄÄÙ ÀÄÄÄ¿ÛÛÛ³ º");
 gotoxy(18,13);cprintf("º ³ÛÛÛÀÄÄÙÛÛÛ³ ³ÛÛÛÀÙÜÛÛ³ ³ÛÛÛÀÄÄÄ¿ ÚÄÄÄÙÛÛÛ³ º");
 gotoxy(18,14);cprintf("º ³ÛÛÛÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛßß³ ³ÛÛÛÛÛÛÛ³ ³ÛÛÛÛÛÛÛ³ º");
 gotoxy(18,15);cprintf("º ÀÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÙ º");
 gotoxy(18,16);cprintf("º COORPORACION   UNIVERSITARIA  DE  SANTANDER º");
 gotoxy(18,17);cprintf("º       copyright (R) VALLEDUPAR (C) 1997     º");
 gotoxy(18,18);cprintf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
 } 
 getch();
}



//------------------------------------------------------------------------------

void clave()
{
 char cl[12],ceci[12],activa;
  int i,x,j ;
  textcolor(WHITE);textbackground(0);
  activa='n';
  strcpy(ceci,"98104026");
  x=1;
  clrscr();
  while((x<=3) && (activa=='n'))
  {
    j=45;
     clrscr();cuadros1(1,79,1,24);cuadros1(15,59,3,5);cuadros1(21,53,11,13);
     gotoxy(20,4);printf("OPCION:CLAVE DE ACCESO AL SISTEMA");
     gotoxy(22,12); printf("DIGITE CLAVE DE ACCESO:");
      for(i=0;i<8;i++)
	{
	 gotoxy(j,12);cl[i]=getch();
	 gotoxy(j,12);printf("*");
	  j++;
	}
	 cl[i]='\0';
	if(strcmp(cl,ceci)==0)
	  {
	    activa='s';
	    clrscr();
	    cuadros1(1,79,1,24);cuadros1(15,59,3,5);
	    gotoxy(20,4);printf("OPCION:CLAVE DE ACCESO AL SISTEMA");
	    gotoxy(29,12);printf("<<clave correcta>>");
	    gotoxy(15,23);printf("PULSE UNA TECLA PARA CONTINUAR.....");getch();
	
	  }
       else
       {
	  clrscr();
	  cuadros1(1,79,1,24);
	  cuadros1(28,49,11,13);
	  textcolor(WHITE+128);textbackground(0);
	  gotoxy(29,12);cprintf("<<clave incorrecta>>");
	  getch();
	  textcolor(WHITE);textbackground(0);
       }
     x++;
     }
      if(activa=='n')
      {
       clrscr();
       gotoxy(18,10);printf("    LA CLAVE NO FUE LA CORRECTA     ");
       gotoxy(15,23);printf(" PULSE UNA TECLA PARA CONTINUAR.....");
       getch();exit(1);
      } 
  }




//----------------------------------------------------------------------------------



void adverten()
 {
  int a,b,c,d,e,f,g,h,p;
  b=25; h=25; c=25; d=25; e=25; f=25; g=25; p=8000;
  clrscr();
  textcolor(15);textbackground(1);
  for(a=22; a>=5; a=a-2)
  {
   sound(p);
   gotoxy(30,a);printf("    ADVERTENCIA    ");

   if(a<=22)
   {
    gotoxy(5,b);printf("Este progama fue dise¤ado por el preingeniero: UBALDO MURGAS GRANADOS ");
    b=b-2;
   }

   if(a<=20)
   {
    gotoxy(5,c);printf(", con el fin obtener una muy buena nota en el tercer parcial  de ");
    c=c-2;
    }

   if(a<=18)
   {
    gotoxy(5,d);printf("de GRAFOS y a su vez prohibe la reproducci¢n y copia  del  mismo , como ");
    d=d-2;
    } 

   if(a<=16)
   {
    gotoxy(5,e);printf("seguridad tiene una clave de acceso que brinda tres oportunidades para ");
    e=e-2;
    }  

   if(a<=14)
   {
    gotoxy(5,f);printf("poder ingresar y aprovechar de su servicio , en caso de no  digitar la ");
    f=f-2;
    } 

   if(a<=12)
   {
    gotoxy(5,g);printf("clave correcta el programa automaticamente lo sacara del sistema y  lo ");
    g=g-2;
    }

   if(a<=10)
   {
    gotoxy(5,h);printf("mandara hacia la parte teor¡ca del programa. ");
    h=h-2;
    }   

  if(a>6)
  {
   delay(1000); 
   clrscr();
  }

  p=p+500;

  }
  nosound();
  getch();
}


//------------------------------------------------------------------------------


/********************************************************************************/

/***************************** PROCEDIMIENTOS DE NODO *****************************/



//--------------------------------------------------------------------------------


void adic_nodo()
{
  struct nodo *aux, *nuevo,*aux2,*ayu1;
  char continuar;
  int control,estacion;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
 do
 {
  clrscr();

   do
	{
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);

   ayu1=mul;
      while ((ayu1!=NULL)&&(strcmp(origen,ayu1->ciudad)!=0))
       ayu1=ayu1->sig;
	 if(ayu1!=NULL)
	  {
	   gotoxy(10,20);
	   printf(" ESTA CIUDAD YA EXISTE");
	   getch();
	  }
	  else
	  { 
	do
	{
	 valido='v';
	 gotoxy(35,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE VALOR DEL ESTACIONAMIENTO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isdigit(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 estacion=atoi(ciud);
	    nuevo=malloc(sizeof(struct nodo));
	    strcpy(nuevo->ciudad,origen);
	    nuevo->estacion=estacion;
	    nuevo->sig=NULL;
	    nuevo->ady=NULL;
	      if (mul==NULL)
		  mul=nuevo;
		   else
		      {  if (strcmp (nuevo->ciudad,mul->ciudad)<0)
			   {nuevo->sig=mul;
			    mul=nuevo;
			   }
			    else
			    {
			      aux2=mul;  control=0;
			       while ((aux2!=NULL)&&(control!=1))
				 { if (strcmp(nuevo->ciudad,aux2->ciudad)>0)
				   {aux=aux2;
				    aux2=aux2->sig;
				   }
				   else
				    control=1;
				 }
				if(aux2==NULL)
				 aux->sig=nuevo;
				 else
				  {aux->sig=nuevo;
				   nuevo->sig=aux2;
				  }

			    }

		       }

	adicionar_archivo_nodo(origen,estacion);
	  }
    clrscr();
    gotoxy(10,20);
    printf("DESEA CONTINUAR ...(S/N)");
    continuar=toupper(getch());
  }while(continuar!='N');

}



//--------------------------------------------------------------------------------



void adicionar_archivo_nodo(char origen[20],int estacionamiento)
 {
   char control;
   int au;

	  if ((dno=_open("a:ciudad.dat",4))==-1)
	    {
	     printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD...ffff ");
	     getch();exit(1);
	    }

	     control='N';
	     while(((au=_read(dno,&dato,sizeof(dato)))!=0)&&(control=='N'))
	       { 
		 if (au!=sizeof(dato))
		   {
		     printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
		     getch();exit(1);
		   }
		      
		   if (strcmp(dato.ciudad,origen)==0)
		      control='S';
	       }
	       if (control=='S')
		 printf("ESTA CIUDAD YA EXISTE ...");

		else
		 {
		  strcpy(dato.ciudad,origen);
		  dato.estacion=estacionamiento;
		   if ((au=_write(dno,&dato,sizeof(dato)))!=(sizeof(dato)))
		    {
		     printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
		     getch();exit(1);
		    }
		 }
	   close(dno);

     }



//--------------------------------------------------------------------------------



void consultar_nodo()
  {
   struct nodo *auxnodo;
   struct arco *auxarco;
   int con;
   char encontro;
   piso_color(1,WHITE);
   window(3,3,78,22);
   clrscr();
   do
     { 
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	if(mul==NULL)
	{ 
	gotoxy(10,20);printf("No se puede consultar");
	}
	else
	 {
	  auxnodo=mul;
	  con=0;  encontro='n';  i=8;
	  while((auxnodo!=NULL)&&(encontro=='n'))
	  {
	  if(strcmp(auxnodo->ciudad,ciud)==0)
	   {
	    encontro='s';
	    gotoxy(2,7);
	    printf("CIUDAD A CONSULTAR:%s  SUS ADYACENTES SON:",auxnodo->ciudad);
	    auxarco=auxnodo->ady;
	    while(auxarco!=NULL)
	    {
	     con++;
	     gotoxy(2,i);
	     printf("%s ESTACIONAMIENTO:%d",auxarco->dest->ciudad,auxarco->kmts);
	     i++;auxarco=auxarco->sig;
	     if(con==5)
	     {
	     getch();
	     }
	    }
	   }
	   auxnodo=auxnodo->sig;
	  }
	 }
	if(encontro=='n')
	 { gotoxy(10,20);
	  printf("LA CIUDAD A CONSULTAR NO EXISTE");
	 }
   getch();
  }



//--------------------------------------------------------------------------------



void actulizar_ciudad()
 {
  struct nodo *ayu1;
  char continuar;
  int control,estanco;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
 do
 {
  clrscr();
    do
     { 
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);

   ayu1=mul;
      while ((ayu1!=NULL)&&(strcmp(origen,ayu1->ciudad)!=0))
       ayu1=ayu1->sig;
	 if(ayu1!=NULL)
	  {
       do
	{
	 valido='v';
	 gotoxy(35,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE VALOR DEL ESTACIONAMIENTO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isdigit(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 estanco=atoi(ciud);
	   modificar_ciudad(origen,estanco);
	   ayu1->estacion=estanco;
	   modificar_ciudad(origen,estanco);  
	   }
	  else
	  {  
	   gotoxy(10,20);
	   printf("ESTA CIUDAD NO EXISTE ....");
	   getch();
	  }
    clrscr();
    gotoxy(10,20);
    printf("DESEA CONTINUAR ...(S/N)");
    continuar=toupper(getch());
  }while(continuar!='N');

}



//--------------------------------------------------------------------------------



void modificar_ciudad(char origen[20],int estanco)
   {
    char control;
    int aux,cont;

      if ((dno=_open("a:ciudad.dat",4))==-1)
	 {
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD...ffff ");
	  getch();exit(1);
	 }
	  control='N'; cont=0;
	     while(((aux=_read(dno,&dato,sizeof(dato)))!=0)&&(control=='N'))
	       {
		 if (aux!=sizeof(dato))
		   {
		    printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
		    getch();exit(1);
		   }
		      cont=cont+1;

		   if (strcmp(dato.ciudad,origen)==0)
		    {
		     control='S';
		     dato.estacion=estanco;
		     lseek(dno,(long)((cont-1)*(sizeof(dato))),0);
		       if ((aux=_write(dno,&dato,sizeof(dato)))!=(sizeof(dato)))
			{
			 printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
			 getch();exit(1);
			}
		     }
	       }
    close(dno);
  }	  



//--------------------------------------------------------------------------------



void elim_nodo()
{
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco, *auxarco2;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
	do
	{
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido=='f');
	 strupr(ciud);
	 strcpy(origen,ciud);
  if (mul==NULL)
     printf("NO SE PUEDE BORRAR");
  else
     {
       if (strcmp(mul->ciudad,origen)==0)
	  {
	    auxnodo=mul;
	    mul=mul->sig;
	  }
	  
       else
	  {
	    st=0;
	    auxnodo2=mul;
	    auxnodo=mul->sig;
	    while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	      {
	       auxnodo=auxnodo->sig;
	       auxnodo2=auxnodo2->sig;
	      }
	    if (auxnodo==NULL)
	      {
		gotoxy(10,20);
		printf("NO SE ENCONTRO LA CIUDAD A BORRAR ");
		st=1;
	      }
	    else
	      {
		auxnodo2->sig=auxnodo->sig;
	      }
	   }
	   if(st==0)
	   {
	   auxarco=auxnodo->ady;
	   auxarco2=auxarco;
	   while (auxarco!=NULL)
	     {
	       auxarco2=auxarco2->sig;
	       free(auxarco);
	       auxarco=auxarco2;
	     }
	   auxnodo2=mul;
	   while(auxnodo2!=NULL)
	     {
	       if (auxnodo2->ady!=NULL)
		 {
		   auxarco=auxnodo2->ady;
		   if (auxarco->dest==auxnodo)
		     {
		       auxnodo2->ady=auxarco->sig;
		       free(auxarco);
		     }
		   else
		     {
		       auxarco2=auxarco;
		       auxarco=auxarco->sig;
		       while ((auxarco!=NULL) && (auxarco->dest!=auxnodo))
			 {
			   auxarco=auxarco->sig;
			   auxarco2=auxarco2->sig;
			 }
		       if (auxarco!=NULL)
			 {
			   auxarco2->sig=auxarco->sig;
			   free(auxarco);
			 }
		     }
		 }
	       auxnodo2=auxnodo2->sig;
	     }
	   free(auxnodo);
	   borrar_archivo_nodo(origen);
	   gotoxy(10,20);
	   printf("CIUDAD ELIMINADA");
	   }
     }
    getch();
}



//--------------------------------------------------------------------------------



void borrar_archivo_nodo(char origen[20])
 { 
   int aux;
   char control;
     if((dno=_open("a:ciudad.dat",1))==-1)
       {
	printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	getch();exit(1);
       }

     if((auxdno=_creat("a:auxciud.dat",0))==-1)
       {
	printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR DE CIUDAD...");
	getch();exit(1);
       }

     if((auxdno=_open("a:auxciud.dat",2))==-1)
       {
	printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR CIUDAD ");
	getch();exit(1);
       }
     control='N';
	    while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
	     { 
	       if (aux!=sizeof(dato))
		{
		 printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ...");
		 getch();exit(1);
		}

	       if (strcmp(dato.ciudad,origen)!=0)
		  {
		   auxdato=dato;
		   if ((aux=_write(auxdno,&auxdato,sizeof(auxdato)))!=(sizeof(auxdato)))
		     {
		      printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
		      getch();exit(1);
		     }
		    control='S';
		   }
	     }   
	  close(dno);
	  close(auxdno);
	  unlink("a:ciudad.dat");
	  rename("a:auxciud.dat","a:ciudad.dat");

	  if(control=='N')
	     printf("CIUDAD A BORRAR NO EXISTIA EN ARCHIVO CIUDAD ");
	      else
		{
		  if((dar=_open("a:arcos.dat",1))==-1)
		    {
		     printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
		     getch();exit(1);
		    }

		  if ((auxdar=_creat("a:auxarco.dat",0))==-1)
		    {
		     printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
		     getch();exit(1);
		    }

		  if((auxdar=_open("a:auxarco.dat",2))==-1)
		    {
		     printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR ARCOS ");
		     getch();exit(1);
		    }

		   while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
		     {
		      if (aux!=sizeof(arista))
			{ 
			 printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
			 getch();exit(1);
			}

		       if ((strcmp(arista.origen,origen)!=0)&&(strcmp(arista.destino,origen)!=0))
			 {
			  auxarista=arista;
			   if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			     {
			      printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			      getch();exit(1);
			     }
			 }

		     }

		 close(dar);

		 close(auxdar);
		 unlink("a:arcos.dat");
		 rename("a:auxarco.dat","a:arcos.dat");

		}
  }



//--------------------------------------------------------------------------------



void grado_int()
{
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco, *auxarco2;
  int con;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
	do
	{
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido=='f');
	 strupr(ciud);
	 strcpy(origen,ciud);
  if (mul==NULL)
    {
     printf("NO SE PUEDE CONSULTAR");
    }

       else
	  {
	    st=2;
	    auxnodo=mul;
	    while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	      {
	       auxnodo=auxnodo->sig;
	      }
	    if (auxnodo==NULL)
	      {
		gotoxy(10,20);
		printf("NO EXISTE ESTA CIUDAD");
		st=1;
	      }
	    else
	     {
	 auxnodo=mul;
	 con=0;
	 while(auxnodo!=NULL)
	 {
	  auxarco=auxnodo->ady;
	  while(auxarco!=NULL)
	   {
	    if(strcmp(auxarco->dest->ciudad,origen)==0)
	     {
	      con++;
	     }
	     auxarco=auxarco->sig;
	   }
	   auxnodo=auxnodo->sig;
	 }
	}
       }
      if(st==2)
      {
      clrscr();
      gotoxy(3,3);printf("SU GRADO INTERNO ES:%d",con);
      }
      getch();

}



//--------------------------------------------------------------------------------



void grado_ext()
{
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco, *auxarco2;
  int con;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
	do
	{
	 valido='v';
	 gotoxy(29,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido=='f');
	 strupr(ciud);
	 strcpy(origen,ciud);
     auxnodo=mul;

     st=2;
     while((auxnodo!=NULL)&&(strcmp(auxnodo->ciudad,origen)!=0))
       auxnodo=auxnodo->sig;

	    if (auxnodo==NULL)
	      {
		gotoxy(10,20);
		printf("NO EXISTE ESTA CIUDAD");
		st=1;
	      }
	   
	  else	 
	  {
      con=0;
      auxarco=auxnodo->ady;

      while(auxarco!=NULL)
       {
	con++;
	auxarco=auxarco->sig;
       }
      }
     if(st==2)
      {
       clrscr();
       gotoxy(3,3);printf("SU GRADO EXTERNO ES:%d",con);
      }

getch();

}



//--------------------------------------------------------------------------------



void imprimir_archivo_ciudad()
  {
   int aux,i;
   piso_color(1,WHITE);
   window(3,3,78,22);
     clrscr();
     if((dno=_open("a:ciudad.dat",1))==-1)
       {
	printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	getch();exit(1);
       }

      i=4;
      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
       {
	if (aux!=sizeof(dato))
	  {
	   printf(" ERROR DE LECTURA EN ARCHIVO ciudad ..."); 
	   getch();exit(1);
	  }

	gotoxy(2,i);
	printf("CIUDAD :%s  ESTACIONAMIENTO :%d",dato.ciudad,dato.estacion);
	i++;
	if(i==20)
	{
	 getch();
	 clrscr();
	 i=4;
	}
       }

  getch();
  close(dno);
 } 


//--------------------------------------------------------------------------------



/**********************************************************************************/


/*************************** PROCEDIMIENTOS DE ARISTA *************************************/



//--------------------------------------------------------------------------------


void adic_arco()
{
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco, *nuevo;
  char continuar;
  int kmts,peajes;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
  do
  {
  clrscr();
  do
	{
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);


  auxnodo=mul;
  while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
      auxnodo=auxnodo->sig;

  if (auxnodo==NULL)
    {
      gotoxy(10,20);
      printf("CIUDAD ORIGEN : %s NO EXISTE",origen);
      getch();
    }
  else
    { 

	do
	{
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(destino,ciud);

	if (strcmp(origen,destino)==0)
	   {
	    gotoxy(10,20);
	    printf(" LA CIUDAD ORIGEN Y LA DESTINO SON IGUALES");
	    getch();
	   }

	else
	 {
      auxnodo2=mul;
      while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	  auxnodo2=auxnodo2->sig;

      if (auxnodo2==NULL)
	{ gotoxy(10,20);
	  printf("CIUDAD DESTINO : %s NO EXISTE",destino);
	  getch();
	}
      else
	{
	  auxarco=auxnodo->ady;
	    while ((auxarco!=NULL)&& (strcmp(auxarco->dest->ciudad,destino)!=0))
	       auxarco=auxarco->sig;

		 if (auxarco!=NULL)
		  {
		   gotoxy(10,20);
		   printf(" ESTA RUTA YA EXISTE..."); getch();
		  }
	       else
		 {
		do
		 {
		  valido='v';
		  gotoxy(31,7);
		  printf("               ");
		  gotoxy(2,7);
		  printf("DIGITE VALOR DE LA DISTANCIA:");
		  scanf("\n"); gets(ciud);
		  lon = strlen(ciud);
		  for(i=0;i<=lon-1; i++)
		   {
		    if(!(isdigit(ciud[i])))
		     {
		      gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
		      delay(1500);
		      gotoxy(10,20);
		      clreol();
		      valido='f';
		      break;
		     }
		    }
		  }while(valido!='v');
		kmts=atoi(ciud);

	do
	{
	 valido='v';
	 gotoxy(23,8);
	 printf("               ");
	 gotoxy(2,8);
	 printf("DIGITE EL TOTAL DE PEAJES:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isdigit(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 peajes=atoi(ciud);
		      nuevo=malloc(sizeof(struct arco));
		      nuevo->kmts=kmts;
		      nuevo->peaje=peajes;
		      nuevo->sig=NULL;
		      nuevo->dest=auxnodo2;
		       if(auxnodo->ady==NULL)
			{
			 auxnodo->ady=nuevo;
			}
			else
			 {
			   auxarco=auxnodo->ady;
			      while(auxarco->sig!=NULL)
				{
				 auxarco=auxarco->sig;
				}

			    auxarco->sig=nuevo;
			 }
		     
		      nuevo=malloc(sizeof(struct arco));
		      nuevo->kmts=kmts;
		      nuevo->peaje=peajes;
		      nuevo->sig=NULL;
		      nuevo->dest=auxnodo;
		       if(auxnodo2->ady==NULL)
			{
			 auxnodo2->ady=nuevo;
			}
			else
			 {
			    auxarco=auxnodo2->ady;
			      while(auxarco->sig!=NULL)
			       {
				auxarco=auxarco->sig;
			       }

			    auxarco->sig=nuevo;
			 }

		      adicionar_archivo_arista(origen,destino,kmts,peajes);
		    }
		}
	    }
	}
      clrscr();
     gotoxy(10,20);
   printf("DESEA CONTINUAR ...(S/N)");
   continuar=toupper(getch());
  }while(continuar!='N');
}


//--------------------------------------------------------------------------------



void adicionar_archivo_arista(char origen[20],char destino[20],int peaje,int kmts)
 {
  char auxor,auxdes,control;
  int aux;

	  if ((dar=_open("a:arcos.dat",4))==-1)
	   {
	    printf("ERROR AL INTENTAR ABRIR ARCHIVO ARCOS");
	    getch();exit(1);
	   } 
	   
	   control='F';
	     while(((aux=_read(dar,&arista,sizeof(arista)))!=0)&&(control=='F'))
	       {
		 if (aux!=sizeof(arista))
		   {
		     printf(" ERROR DE LECTURA EN ARCHIVO ARCOS ...");
		     getch();exit(1);
		    }
		      
		   if ((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		     {
		      control='V';
		     }
	       
		   if ((strcmp(arista.origen,destino)==0)&&(strcmp(arista.destino,origen)==0))
		    {
		     control='V';
		    }
	       }
	   
	      if (control=='V')
		{
		 printf("ESTA RUTA YA EXISTE ...");
		}

		else
		  {
		    auxor='F'; auxdes='F';
		     if((dno=_open("a:ciudad.dat",1))==-1)
		       {
			 printf("ERROR ALppppp INTENTAR ABRIR EL ARCHIVO CIUDAD ");
			 getch();exit(1);
		       }

		      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
			{
			  if (aux!=sizeof(dato))
			   {
			     printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD...");
			     getch();exit(1);
			   }

			  if (strcmp(dato.ciudad,origen)==0)
			   {
			    auxor='V';
			   }

			  if (strcmp(dato.ciudad,destino)==0)
			   {
			    auxdes='V';
			   }
			}

			if(auxor=='F')
			  {
			   printf("CIUDAD ORIGEN NO EXISTE...");
			  }
			  else
			    {
			     if(auxdes=='F')
			       {
				printf("CIUDAD DESTINO NO EXISTE...");
			       }
			     else
			     { 
			       strcpy(arista.origen,origen);
			       strcpy(arista.destino,destino);
			       arista.distancia=kmts;
			       arista.peaje=peaje;
				 if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				  {
				    printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				    getch();exit(1);
				  }
				  strcpy(arista.origen,destino);
				  strcpy(arista.destino,origen);
				  arista.peaje=peaje;
				  arista.distancia=kmts;
				 if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				  {
				    printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				    getch();exit(1);
				 }

			     }

			  }

		   close(dno);
		  }
	      close(dar);
 }



//--------------------------------------------------------------------------------


void consultar_arista()
  {
   struct nodo *auxnodo,*auxnodo2;
   struct arco *auxarco;
   char encontro;  int i,con;
   piso_color(1,WHITE);
   window(3,3,78,22);
   clrscr();
   if(mul==NULL)
   {
     gotoxy(10,20);
     printf("NO SE PUEDE CONSULTAR");
   }
   else
    {
   do
     { 
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);
	 auxnodo=mul;
	    while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	      {
	       auxnodo=auxnodo->sig;
	      }
	      
	    if (auxnodo==NULL)
	      {
	       gotoxy(10,20);
	       printf("NO EXISTE LA CIUDAD %s",origen);
	      }

       else
       {
       do
       {
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 strupr(ciud);
	 strcpy(destino,ciud);
	 }while(valido!='v');

	 if(strcmp(origen,destino)==0)
	   {
	     gotoxy(10,20);
	     printf("LA CIUDAD ORIGEN Y DESTINO SON IGUALES");
	   }
	 else

	 {
	 auxnodo2=mul;

	    while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	      {
	       auxnodo2=auxnodo2->sig;
	      }

	    if (auxnodo2==NULL)
	       {
		 gotoxy(10,20);
		 printf("NO EXISTE LA CUIDAD %s",destino);
	       }
	    else
	    {
	     encontro='n';
	     auxarco=auxnodo->ady;
	     con=0;  i=8;
	     while((auxarco!=NULL)&&(encontro=='n'))
	      {
	       if(auxarco->dest==auxnodo2)
		{
		 encontro='s';
		 gotoxy(2,i);printf("LA RUTA ENTRE  %s Y %s ES:",auxnodo->ciudad,auxnodo2->ciudad);
		 gotoxy(2,i+1);printf("LA DISTANCIA ES:%d Y PEAJES SON:%d",auxarco->kmts,auxarco->peaje);
		 i=i+3;
		 con++;
		 if(con==3)
		 {
		  con=0;
		  getch();
		 }
		}
	       auxarco=auxarco->sig;
	      } 
	    }

	    if(encontro=='n')
	     {
	      gotoxy(10,20);
	      printf("LA RUTA NO EXISTE");
	     }

	    }

	  }

	 }

   getch();
  }


//--------------------------------------------------------------------------------
  
      

void modificar_arco()
 {
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco;
  char continuar;
  int kmts,peajes;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
  do
	{
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);

  auxnodo=mul;
  while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
    {
     auxnodo=auxnodo->sig;
    }

  if (auxnodo==NULL)
    { gotoxy(10,20);
      printf("CIUDAD ORIGEN NO EXISTE");
      getch();
      
    }

 else
    {

      do
	{
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(destino,ciud);

	     if (strcmp(origen,destino)==0)
	       {
		printf(" LA CIUDAD ORIGEN Y LA DESTINO SON IGUALES");
		getch();
	       }
	    else
	    {

      auxnodo2=mul;


      while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	 {
	  auxnodo2=auxnodo2->sig;
	 }

      if (auxnodo2==NULL)
	{
	  gotoxy(10,20);
	  printf("CIUDAD DESTINO NO EXISTE");
	  getch();
	}
      else
	{
	    auxarco=auxnodo->ady;
	    while ((auxarco!=NULL)&& (strcmp(auxarco->dest->ciudad,destino)!=0))
	      {
	       auxarco=auxarco->sig;
	      }

	      if (auxarco!=NULL)
	       {   
		do
		{
		 valido='v';
		 gotoxy(31,7);
		 printf("               ");
		 gotoxy(2,7);
		 printf("DIGITE VALOR DE LA DISTANCIA:");
		 scanf("\n"); gets(ciud);
		 lon = strlen(ciud);
		 for(i=0;i<=lon-1; i++)
		 {
		  if(!(isdigit(ciud[i])))
		  {
		  gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
		  delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 kmts=atoi(ciud);
		 
	do
	{
	 valido='v';
	 gotoxy(23,8);
	 printf("               ");
	 gotoxy(2,8);
	 printf("DIGITE EL TOTAL DE PEAJES:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isdigit(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR VALOR...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 peajes=atoi(ciud);
		      auxarco->kmts=kmts;
		      auxarco->peaje=peajes;
		  
		    auxarco=auxnodo2->ady;
		    while ((auxarco!=NULL)&& (strcmp(auxarco->dest->ciudad,origen)!=0))
		      {
		       auxarco=auxarco->sig;
		      }

		      auxarco->kmts=kmts;
		      auxarco->peaje=peajes;
		     modificar_arista(origen,destino,kmts,peajes);
		  }         

	     }

	  }

       }

    }





//--------------------------------------------------------------------------------



void modificar_arista(char origen[20],char destino[20],int costo,int distan)
 {
  char control;
  int aux,cont,con1,con2;

	  if ((dar=_open("a:arcos.dat",4))==-1)
	   {
	    printf("ERROR AL INTENTAR ABRIR ARCHIVO ARCOS");
	    getch();exit(1);
	   } 
	   
	   control='F'; cont=0;
	     while(((aux=_read(dar,&arista,sizeof(arista)))!=0)&&(control=='F'))
	       {
		 if (aux!=sizeof(arista))
		   {
		     printf(" ERROR DE LECTURA EN ARCHIVO ARCOS ...");
		     getch();exit(1);
		    }
		    cont=cont+1;  

		   if ((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		    {
		      con1=1;
		      arista.distancia=distan;
		      arista.peaje=costo;

		       lseek(dar,(long)((cont-1)*(sizeof(arista))),0);
			 if((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
			    {
			      printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
			      getch();exit(1);
			    }

		    }
		    else
		      {
		       if ((strcmp(arista.origen,destino)==0)&&(strcmp(arista.destino,origen)==0))
			{
			  con2=1;
			  arista.distancia=distan;
			  arista.peaje=costo;
			  lseek(dar,(long)((cont-1)*(sizeof(arista))),0);
			   if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
			     {
			       printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
			       getch();exit(1);
			      }

			}
		      }
		      
		      if((con1==1)&&(con2==1))
		       {
			control='V';
		       }
			    
	       }
	   
	 close(dar);
 }



//--------------------------------------------------------------------------------



void elim_arco()
 {
  char origen[20], destino[20];
  struct nodo *auxnodo, *auxnodo2;
  struct arco *auxarco, *auxarco2;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
	do
	{
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);

  auxnodo=mul;
  while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
    {
     auxnodo=auxnodo->sig;
    }

  if (auxnodo==NULL)
      {
       gotoxy(10,20);
       printf("CIUDAD ORIGEN NO EXISTE");
       getch();
      }
  else
    { 
       auxnodo2=mul;

	do
	{
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(destino,ciud);

       if(strcmp(origen,destino)==0)
	{
	 gotoxy(10,20);
	 printf("LA CIUDAD ORIGEN ES IGUAL A LA DESTINO");
	 getch();
	}

      else
       {
	while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	  {
	   auxnodo2=auxnodo2->sig;
	  }

       if (auxnodo2==NULL)
	 {
	   gotoxy(10,20);
	   printf("CIUDAD DESTINO NO EXISTE");
	   getch();
	 }
       else
	 {  
	   auxarco=auxnodo->ady;
	   if (auxarco->dest==auxnodo2)
	     {
	       auxnodo->ady=auxarco->sig;
	       free(auxarco);
	     }
	   else
	     {
	       auxarco2=auxarco;
	       auxarco=auxarco->sig;
	       while ((auxarco!=NULL) && (auxarco->dest!=auxnodo2))
		  {
		     auxarco=auxarco->sig;
		     auxarco2=auxarco2->sig;
		   }
	       if (auxarco!=NULL)
		   {
		      auxarco2->sig=auxarco->sig;
		      free(auxarco);
		   }
	     }

	   auxarco=auxnodo2->ady;
	   if (auxarco->dest==auxnodo)
	     {
	       auxnodo2->ady=auxarco->sig;
	       free(auxarco);
	     }
	   else
	     {
	       auxarco2=auxarco;
	       auxarco=auxarco->sig;
	       while ((auxarco!=NULL) && (auxarco->dest!=auxnodo))
		  {
		     auxarco=auxarco->sig;
		     auxarco2=auxarco2->sig;
		   }
	       if (auxarco!=NULL)
		   {
		      auxarco2->sig=auxarco->sig;
		      free(auxarco);
		   }
	     }


	   borrar_archivo_arcos(origen,destino);
    
	  }
	}
    }
}


//--------------------------------------------------------------------------------


void borrar_archivo_arcos(char origen[20],char destino[20])
   {
    int aux;

       if((dar=_open("a:arcos.dat",1))==-1)
	 {
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	   getch();exit(1);
	 }

       if ((auxdar=_creat("a:auxarco.dat",0))==-1)
	 {
	   printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
	   getch();exit(1);
	 }

       if((auxdar=_open("a:auxarco.dat",2))==-1)
	 {
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO AUXILIAR ARCOS ");
	   getch();exit(1);
	 }
	
	
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   { 
	    if (aux!=sizeof(arista))
	       {
		 printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
	       }

	      if ((strcmp(arista.origen,origen)!=0)||(strcmp(arista.destino,destino)!=0))
	       {
		 if ((strcmp(arista.origen,destino)!=0)||(strcmp(arista.destino,origen)!=0))
		   {
		    auxarista=arista;
		      if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			{
			  printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			  getch();exit(1);
			}
		   }

	       }	

	   }

	   close(dar);
	   close(auxdar);
	   unlink("a:arcos.dat");
	   rename("a:auxarco.dat","a:arcos.dat");

 }


//--------------------------------------------------------------------------------   


void imprimir_archivo_arcos()
 {
  int aux;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();

    if((dar=_open("a:arcos.dat",1))==-1)
      { 
	clrscr();
	printf("ERROR AL INTENTAR LEER EL ARCHIVO  ARCOS ");
	getch();exit(1);
      }
	 i=4;
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   {
	     if (aux!=sizeof(arista))
	       { 
		 printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
		}
	   gotoxy(2,i); printf("ORIGEN : %s DESTINO : %s  PEAJES :  %d   DISTANCIA  :%d",arista.origen,arista.destino,arista.peaje,arista.distancia );
	   i++;
	   if(i==20)
	    {
	     getch();
	     clrscr();
	     i=4;
	    }

	   }
	   getch();

     close(dar);
   
 }


//--------------------------------------------------------------------------------


/*******************************************************************************/



/************************ PROCEDIMIENTOS DE RECORRIDOS *****************************/



//--------------------------------------------------------------------------------


void eliminar_ultimo_lista()
 {
   struct listady *lista1,*lista2;

   if (lista->sig==NULL)
    {
      lista2=lista;
      lista=lista->sig;
     }
      else
       {
	lista1=lista;
	lista2=lista->sig;
	  while(lista2->sig!=NULL)
	   {
	    lista1=lista1->sig;
	    lista2=lista2->sig;
	   }
	   lista1->sig=lista2->sig;
       }

    free(lista2);

  }


//--------------------------------------------------------------------------------


void meter_aux_lista2(struct nodo *ayuda)
  {
   
    struct listady *nuevo;
    nuevo=malloc(sizeof(struct listady));
    nuevo->costo=ayuda->estacion;
    strcpy(nuevo->ciudad,ayuda->ciudad);
    nuevo->sig=NULL;

    if (lista==NULL)
     {
      lista=nuevo;
     }

  }


//--------------------------------------------------------------------------------


void crear_listaux(struct nodo *entrada)
   {
    struct listady *nuevo,*aux,*lista1,*lista2;
    struct lista_pri *nuevo2,*aux2,*ayuda2;
    long auxcosto;
    int control;

     lista1=lista;
     lista2=NULL;
     auxcosto=0;
       while(lista1!=NULL)
	 {
	   nuevo=malloc(sizeof(struct listady));
	   strcpy(nuevo->ciudad,lista1->ciudad);
	   nuevo->costo=lista1->costo;
	   nuevo->sig=NULL;

	     if (lista2==NULL)
	       {
		lista2=nuevo;
	       }

	      else
		{
		  aux=lista2;
		    while(aux->sig!=NULL)
		     aux=aux->sig;

		    aux->sig=nuevo;
		 }
	       auxcosto=auxcosto+lista1->costo;
	       lista1=lista1->sig;
	 }	       	

	 nuevo2=malloc(sizeof(struct lista_pri));
	 strcpy(nuevo2->ciudad,entrada->ciudad);
	 nuevo2->costo=auxcosto;
	 nuevo2->ady=lista2;

	      if (listapri==NULL)
		{
		  nuevo2->sig=NULL;
		  listapri=nuevo2;
		 }
		 else
		  {
		   if ((nuevo2->costo) < (listapri->costo ))
		       {
			 nuevo2->sig=listapri;
			 listapri=nuevo2;
			}
		      else
			{
			  aux2=listapri; control=0;
			  while ((aux2!=NULL)&&(control!=1))
			    {
			     if ((nuevo2->costo) > (aux2->costo))
			      {
				ayuda2=aux2;
				aux2=aux2->sig;
			       }
			      else
			       {
				control=1;
			       }

			     }

			   if(aux2==NULL)
			      {
			       nuevo2->sig=NULL;
			       ayuda2->sig=nuevo2;
			      }
			    else
			      {
			       ayuda2->sig=nuevo2;
			       nuevo2->sig= aux2;
			      }

			 }


		   }


	}



//--------------------------------------------------------------------------------


void eliminar_rutas()
 {
  struct listady *auxlista,*auxlista1;
  struct lista_pri *auxpri,*auxpri1;

   auxpri=listapri;
   

     while(auxpri!=NULL)
     {
      auxlista=auxpri->ady;
      auxlista1=auxlista;
       while(auxlista!=NULL)
	{
	 auxlista1=auxlista1->sig;
	 free(auxlista);
	 auxlista=auxlista1;
	}
       listapri=listapri->sig;

       free(auxpri);
       auxpri=listapri;
     }

  }


//--------------------------------------------------------------------------------


void meter_lista2(struct arco *ayuda)
  {
   struct listady *nuevo,*aux;
   long auxcosto;

    auxcosto=((ayuda->dest->estacion)+((ayuda->kmts)*(val_km))+((ayuda->peaje)*(val_peaje)));
    nuevo=malloc(sizeof(struct listady));
    nuevo->sig=NULL;
    strcpy (nuevo->ciudad,ayuda->dest->ciudad);
    nuevo->costo=auxcosto;

     if (lista==NULL)
      {
       lista=nuevo;
      }
       else
	{
	 aux=lista;
	   while (aux->sig!=NULL)
	     {
	      aux=aux->sig;
	     }

	  aux->sig=nuevo;
	}
    }



//--------------------------------------------------------------------------------



int buscar_elemento(struct arco *ayuda)
   {
    struct listady *lista1;
    int valor;
    lista1=lista;

     while((lista1!=NULL)&&(strcmp(lista1->ciudad,ayuda->dest->ciudad)!=0))
       {
	lista1=lista1->sig;
       }

      if (lista1==NULL)
	{
	 valor=0;
	}

      else
       {
	valor=1;
       }

	return(valor);
     }


//--------------------------------------------------------------------------------


struct arco *buscar_arco()
	     {
	      struct nodo *aux;
	      struct arco *ayu1;
	      struct listady *lista1,*lista2;
	      lista1=lista;
	      lista2=lista;

	       if (lista2->sig !=NULL)
		{
		 lista2=lista2->sig;
		   while (lista2->sig!=NULL)
		    {
		      lista2=lista2->sig;
		      lista1=lista1->sig;
		     }
		     aux=mul;
		      while((aux!=NULL)&&(strcmp(aux->ciudad,lista1->ciudad)!=0))
			{
			 aux=aux->sig;
			}

			       ayu1=aux->ady;

		      while((ayu1!=NULL)&&(strcmp(ayu1->dest->ciudad,lista2->ciudad)!=0))
			 {
			  ayu1=ayu1->sig;
			 }

		       ayu1=ayu1->sig;

		 } 
		 else
		   {
		    ayu1=NULL;
		   }

	       return(ayu1);
	   }



//--------------------------------------------------------------------------------



void crear_listaux_corta(struct nodo *entrada)
   {
    struct listady *nuevo,*aux,*lista1,*lista2;
    struct lista_pri *nuevo2,*aux2,*ayuda2;
    long auxcosto;
    int control;

     lista1=lista;
     lista2=NULL;
     auxcosto=0;
       while(lista1!=NULL)
	 {
	   nuevo=malloc(sizeof(struct listady));
	   strcpy(nuevo->ciudad,lista1->ciudad);
	   nuevo->costo=lista1->costo;
	   nuevo->sig=NULL;

	     if (lista2==NULL)
	      lista2=nuevo;

	      else
	       {
		 aux=lista2;
		   while(aux->sig!=NULL)
		     aux=aux->sig;

		 aux->sig=nuevo;
	       }
	       auxcosto=auxcosto+1;
	       lista1=lista1->sig;
	 }	       	

	 nuevo2=malloc(sizeof(struct lista_pri));
	 strcpy(nuevo2->ciudad,entrada->ciudad);
	 nuevo2->costo=auxcosto;
	 nuevo2->ady=lista2;

	      if (listapri==NULL)
		{
		  nuevo2->sig=NULL;
		  listapri=nuevo2;
		}
	      else
		{
		 if ((nuevo2->costo) < (listapri->costo ))
		   {
		     nuevo2->sig=listapri;
		     listapri=nuevo2;
		   }
		 else
		   {
		    aux2=listapri; control=0;
		    while ((aux2!=NULL)&&(control!=1))
		      {
		       if ((nuevo2->costo) > (aux2->costo))
			 {
			  ayuda2=aux2;
			  aux2=aux2->sig;
			 }
		       else
			 control=1;

		      }
		    if(aux2==NULL)
		       {
			nuevo2->sig=NULL;
			ayuda2->sig=nuevo2;
		       }
		    else
		       {
			ayuda2->sig=nuevo2;
			nuevo2->sig= aux2;
		       }

		   }

	      }
	}


//--------------------------------------------------------------------------------


void ruta_cara_barata()
    {
     char origen[20], destino[20];
     struct nodo *auxnodo, *auxnodo2,*auxreco;
     struct arco *auxarco, *auxarco2;
     int control,estado;
     piso_color(1,WHITE);
     window(3,3,78,22);
     clrscr();
      do
	{
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);

       auxnodo=mul;
	while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	 auxnodo=auxnodo->sig;
	 if (auxnodo==NULL)
	  {
	     gotoxy(10,20);
	     printf("CIUDAD ORIGEN NO EXISTE");

	  }
       else
	{
	do
	{
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(destino,ciud);

	       if (strcmp(origen,destino)==0)
	       {
		gotoxy(10,20);
		printf(" LA CIUDAD ORIGEN Y LA DESTINO SON IGUALES");
	       }
	      else
	       {
	      auxnodo2=mul;
	      while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	      auxnodo2=auxnodo2->sig;
	       if (auxnodo2==NULL)
		  {
		    gotoxy(10,20);
		    printf("CIUDAD DESTINO NO EXISTE");
		  }
		  else
		   {

		     auxarco=auxnodo->ady;
		     if (auxarco==NULL)
		      {
		       gotoxy(10,20);
		       printf("NO EXISTE CAMINO ");
		      }	
		      
		       else
			{
			  estado=0;
			  meter_aux_lista2(auxnodo);
			   while(auxarco!=NULL)
			    {
			     if(auxarco->dest==auxnodo2)
			       {
				 meter_lista2(auxarco);
				 auxarco=auxarco->sig;
				 crear_listaux(auxnodo);
				 eliminar_ultimo_lista();
				 estado=1;
				}
			      else
			       {
				auxreco=auxarco->dest;
				if (auxreco->ady!=NULL)
				  {
				    meter_lista2(auxarco);
				    auxarco2=auxreco->ady;
				    while(auxarco2!=NULL)
				     {
				      if (auxarco2->dest==auxnodo2)
					{
					 estado=1;
					 meter_lista2(auxarco2);
					 crear_listaux(auxnodo);
					 do
					  {
					   auxarco2=buscar_arco();
					   eliminar_ultimo_lista();
					  }while ((auxarco2==NULL)&&(lista!=NULL));
					}
				      else
				       {
					if (auxarco2->dest==auxnodo)
					  {
					   auxarco2=auxarco2->sig;
					   if(auxarco2==NULL)
					    {
					     do
					      {
					       auxarco2=buscar_arco();
					       eliminar_ultimo_lista();
					      }while ((auxarco2==NULL)&&(lista!=NULL));
					    }
					}
					else
					 {
					  control=buscar_elemento(auxarco2);
					  if (control==0)
					   {
					     auxreco=auxarco2->dest;
					     if(auxreco->ady!=NULL)
					       {
						meter_lista2(auxarco2);
						auxarco2=auxreco->ady;
					       }
					     else
					       {
						do
						 {
						  auxarco2=buscar_arco();
						  eliminar_ultimo_lista();
						 }while ((auxarco2==NULL)&&(lista!=NULL));
					       }

					   }
					  else
					   {
					    meter_lista2(auxarco2);
					    do
					     {
					      auxarco2=buscar_arco();
					      eliminar_ultimo_lista();
					     }while ((auxarco2==NULL)&&(lista!=NULL));
					   }

					  }

					}
				       auxarco=auxarco2;
				      }

				     }

				    else
				     {
				      do
				       {
					auxarco=buscar_arco();
					eliminar_ultimo_lista();
				       }while ((auxarco==NULL)&&(lista!=NULL));

				     }

				  }

			       }

			   }

		      }

		  }

	       }

	    if (estado!=0)
	     {
	      imprimir_rutas();
	      eliminar_rutas();
	     }
	   else
	    {
	     gotoxy(10,20);
	     printf("...NO EXISTE RUTA PARA INGRESAR A ESTA CIUDAD...");
	    }


    getch();
   }


//--------------------------------------------------------------------------------


void ruta_corta_larga()
    {
     char origen[20], destino[20];
     struct nodo *auxnodo, *auxnodo2,*auxreco;
     struct arco *auxarco, *auxarco2;
     int control,estado;
     piso_color(1,WHITE);
     window(3,3,78,22);
      clrscr();
      do
	{
	 valido='v';
	 gotoxy(36,5);
	 printf("               ");
	 gotoxy(2,5);
	 printf("DIGITE NOMBRE DE LA CIUDAD ORIGEN:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(origen,ciud);
       auxnodo=mul;
	while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	 auxnodo=auxnodo->sig;
	 if (auxnodo==NULL)
	  {
	     gotoxy(10,20);
	     printf("CIUDAD ORIGEN NO EXISTE");
	     getch();
	     
	  }
	else
	 { 
	do
	{
	 valido='v';
	 gotoxy(37,6);
	 printf("               ");
	 gotoxy(2,6);
	 printf("DIGITE NOMBRE DE LA CIUDAD DESTINO:");
	 scanf("\n"); gets(ciud);
	 lon = strlen(ciud);
	 st=1;
	 for(i=0;i<=lon-1; i++)
	  {
	   if(st==1)
	   {
	     if(ciud[i]==' ')
	     {
	      st=2;
	      i++;
	     }
	   }
	   if(!(isalpha(ciud[i])))
	    {
	     gotoxy(10,20);printf("... ERROR AL DIGITAR NOMBRE ...!");
	     delay(1500); gotoxy(10,20);
	     clreol();
	     valido='f';
	     break;
	    }
	  }
	 }while(valido!='v');
	 strupr(ciud);
	 strcpy(destino,ciud);


	       if (strcmp(origen,destino)==0)
	       {
		gotoxy(10,20);
		printf(" LA CIUDAD ORIGEN Y LA DESTINO SON IGUALES");
		getch();
	       }
	      else
	       {
	      auxnodo2=mul;
	      while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	      auxnodo2=auxnodo2->sig;
	       if (auxnodo2==NULL)
		  {
		    printf("CIUDAD DESTINO NO EXISTE");
		    getch();

		  }
		  else
		   {

		     auxarco=auxnodo->ady;
		     if (auxarco==NULL)
		      {
		       printf("NO EXISTE CAMINO ");
		      }
		      
		     else
		      {
			estado=0;
			meter_aux_lista2(auxnodo);
			while(auxarco!=NULL)
			  {
			    if(auxarco->dest==auxnodo2)
			     {
			      meter_lista2(auxarco);
			      auxarco=auxarco->sig;
			      crear_listaux_corta(auxnodo);
			      eliminar_ultimo_lista();
			      estado=1;
			     }
			   else
			    {
			     auxreco=auxarco->dest;
			      if (auxreco->ady!=NULL)
			       {
				meter_lista2(auxarco);
				auxarco2=auxreco->ady;
				while(auxarco2!=NULL)
				 {
				  if (auxarco2->dest==auxnodo2)
				    {
				      estado=1;
				      meter_lista2(auxarco2);
				      crear_listaux_corta(auxnodo);
				      do
				       {
					auxarco2=buscar_arco();
					eliminar_ultimo_lista();
				       }while ((auxarco2==NULL)&&(lista!=NULL));
				     }
				   else
				     {
				      if (auxarco2->dest==auxnodo)
				       {
					auxarco2=auxarco2->sig;
					if(auxarco2==NULL)
					  {
					   do
					    {
					     auxarco2=buscar_arcol();
					     eliminar_ultimo_lista();
					    }while ((auxarco2==NULL)&&(lista!=NULL));
					  }
					}
				      else
					{
					 control=buscar_elemento(auxarco2);
					 if (control==0)
					  {
					   auxreco=auxarco2->dest;
					   if(auxreco->ady!=NULL)
					    {
					     meter_lista2(auxarco2);
					     auxarco2=auxreco->ady;
					    }
					   else
					    {
					     do
					      {
					       auxarco2=buscar_arco();
					       eliminar_ultimo_lista();
					      }while ((auxarco2==NULL)&&(lista!=NULL));
					    }
											   }
					  else
					    {
					      meter_lista2(auxarco2);
					       do
						{
						 auxarco2=buscar_arco();
						 eliminar_ultimo_lista();
						}while ((auxarco2==NULL)&&(lista!=NULL));
					     }
					   
					 }
				       
				     }
				    auxarco=auxarco2;
				   }

				  }
				else
				  {
				   do
				     {
				      auxarco=buscar_arco();
				      eliminar_ultimo_lista();
				     }while ((auxarco==NULL)&&(lista!=NULL));
				   }
					 
				 }

			    }

			}

		   }

		}

	     }

	   if (estado!=0)
	    {
	     imprimir_rutas();
	     eliminar_rutas();
	    }

	  else
	   {
	    gotoxy(10,20);
	    printf("NO EXISTE RUTA PARA INGRESAR A ESTA CIUDAD");
	   }

    getch();

  }


//--------------------------------------------------------------------------------


/********************************************************************************/
  

/************************** PROCEDIMIENTOS DE IMPRESION ***************************/


//--------------------------------------------------------------------------------


void imprimir()
 {
  struct nodo *auxnodo;
  struct arco *auxarco;
  int con;
  piso_color(1,WHITE);
  window(3,3,78,22);
  clrscr();
  con=0;
  auxnodo=mul;            i=3;
  while (auxnodo!=NULL)
    {
      con++;
      textcolor(10);
      gotoxy(2,i);cprintf("ORIGEN: %s  Y SUS ADYACENTES SON : ",auxnodo->ciudad);
      auxarco=auxnodo->ady;
      while (auxarco!=NULL)
	{
	 textcolor(15);
	 gotoxy(4,i+1); printf("  %s DISTANCIA : %d KMTS  PEAJES : %d ",auxarco->dest->ciudad,auxarco->kmts,auxarco->peaje);
	 auxarco=auxarco->sig;
	 i++;
	}
	textcolor(15);
     if(auxnodo->ady==NULL)
      {
       textcolor(YELLOW+128); cprintf("NULL");
       i=i+2;
      }
      
      
     else
      {
      textcolor(15);
      i=i+2;
      }
      textcolor(15);
      if(con==3)
       {
	getch();
	i=3;
	con=0;
	clrscr();
       }
      auxnodo=auxnodo->sig;
    }
  getch();

}



//--------------------------------------------------------------------------------



void imprimir_rutas()
{

 int i,con;
 struct lista_pri *auxpri;
 struct listady *auxlista,*controla;
 piso_color(1,WHITE);
 window(3,3,78,22);
 clrscr();
 auxpri=listapri;
 textcolor(15); textbackground(1);
 if(modo_recorrido==1)
  {
   con=0;
   while((auxpri!=NULL)&&(con==0))
   { auxlista=auxpri->ady;
     while(auxlista!=NULL)
      { 
	gotoxy(i,2);
	printf(" %s ",auxlista->ciudad);
	controla=auxlista;
	if(controla->sig!=NULL)
	{
	textcolor(10);
	cprintf("-->");
	}
	auxlista=auxlista->sig;
      }
     textcolor(15); textbackground(1);
     printf("  ");
     printf(" SU RUTAS SON :%ld", auxpri->costo-1);
     auxpri=auxpri->sig;
     con++;
     i=i+4;
   }
  }
 else
  {
   textcolor(15); textbackground(1);
   if(modo_recorrido==2)
    {
     while(auxpri!=NULL)
      {
       clrscr();
       auxlista=auxpri->ady;
       while(auxlista!=NULL)
       { 
	printf(" %s ",auxlista->ciudad);
	controla=auxlista;
	if(controla->sig!=NULL)
	{
	 textcolor(10);
	 cprintf("-->");
	}
	auxlista=auxlista->sig;
       }
      textcolor(15); textbackground(1);
      printf("  ");
      printf(" SU RUTAS SON :%ld", auxpri->costo-1);
      auxpri=auxpri->sig;
     }
    }
   else
    {
     textcolor(15); textbackground(1);
     if(modo_recorrido==3)
      {
       con=0;
       while((auxpri!=NULL)&&(con==0))
       {
	auxlista=auxpri->ady;
	while(auxlista!=NULL)
	 {
	  printf(" %s ",auxlista->ciudad);
	  controla=auxlista;
	  if(controla->sig!=NULL)
	   {
	    textcolor(10);
	    cprintf("-->");
	   }
	  auxlista=auxlista->sig;
	 }
	textcolor(15); textbackground(1);
	printf("  ");
	printf(" SU COSTO ES :%ld", auxpri->costo);
	auxpri=auxpri->sig;
	con++;
       }
      }
     else
      {
       textcolor(15); textbackground(1);
       if(modo_recorrido==4)
	{
	 while(auxpri!=NULL)
	  {
	   clrscr();
	   auxlista=auxpri->ady;
	   while(auxlista!=NULL)
	    {
	     printf(" %s ",auxlista->ciudad);
	     controla=auxlista;
	     if(controla->sig!=NULL)
	      {
	       textcolor(10);
	       cprintf("-->");
	      }
	     auxlista=auxlista->sig;
	    }
	   textcolor(15); textbackground(1);
	   printf("  ");
	   printf(" SU COSTO ES :%ld", auxpri->costo);
	   auxpri=auxpri->sig;
	  }
	}
       else
	{
	 i=2;con=0;
	 textcolor(15); textbackground(1);
	 while(auxpri!=NULL)
	  {
	   con++;
	   gotoxy(2,i);
	   auxlista=auxpri->ady;
	   while(auxlista!=NULL)
	    {
	     printf(" %s ",auxlista->ciudad);
	     controla=auxlista;
	     if(controla->sig!=NULL)
	      {
	       textcolor(10);
	       cprintf("-->");
	      }
	     auxlista=auxlista->sig;
	    }
	   textcolor(15); textbackground(1);
	   printf(" SU COSTO ES :%ld", auxpri->costo);
	   i=i+2;
	   if(con==3)
	   {
	    getch();
	    clrscr();
	    con=0;
	    i=2;
	   }
	   auxpri=auxpri->sig;

	  }

	}

      }

    }

  }

}


//--------------------------------------------------------------------------------


/******************************************************************************/


/********************* PROCEDIMIENTO DE CARGAR GRAFO ***************************/


//--------------------------------------------------------------------------------


void cargar_grafo()
  {
   struct nodo *aux, *nuevo,*aux2,*ayu1,*auxnodo,*auxnodo2;
   struct arco *auxarco,*nuevo1;
   int hj,control,aux1,kmts,peajes;
    clrscr(); hj=15;
    
    textbackground(1);
    textmode(C40);
    gotoxy(12,10);
    textcolor(hj+128);
    cprintf("CARGANDO GRAFO");
    hj++;

    if ((dno=_open("a:\\ciudad.dat",1))==-1)
      {
	printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD... ");
	getch();exit(1);
      }
	 
   while ((aux1=_read(dno,&dato,sizeof(dato)))!=0)
      { 
	     textmode(C40);
	     textcolor(hj);
	     gotoxy(12,10);
	     cprintf("CARGANDO GRAFO");
	     hj++;
	 if (aux1!=sizeof(dato))
	   {
	     printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ...");
	     getch();exit(1);
	   }
	 strcpy(origen,dato.ciudad);

	 

	 ayu1=mul;
	  while ((ayu1!=NULL)&&(strcmp(origen,ayu1->ciudad)!=0))
	    {
	     ayu1=ayu1->sig;
	    }

	     nuevo=malloc(sizeof(struct nodo));
	     strcpy(nuevo->ciudad,origen);
	     nuevo->estacion=dato.estacion;
	     nuevo->sig=NULL;
	     nuevo->ady=NULL;
	     textmode(C40);
	     textcolor(hj);
	     gotoxy(12,10);
	     cprintf("CARGANDO GRAFO");
	     hj++;
	       if (mul==NULL)
		 {
		  mul=nuevo;
		 }
		else
		  {
		   if (strcmp (nuevo->ciudad,mul->ciudad)<0)
		    {
		     nuevo->sig=mul;
		     mul=nuevo;
		    }
		  else
		    {
		     aux2=mul;  control=0;
		     while ((aux2!=NULL)&&(control!=1))
		      {
		       if (strcmp(nuevo->ciudad,aux2->ciudad)>0)
			 {
			  aux=aux2;
			  aux2=aux2->sig;
			 }
		       else
			 {
			  control=1;
			 }
		      }

		     if(aux2==NULL)
		      {
		       aux->sig=nuevo;
		      }
		     else
		       {
			aux->sig=nuevo;
			nuevo->sig=aux2;
		       }

		    }

	       }

      }

  close(dno); 

      textmode(C40);
      textcolor(YELLOW);
      gotoxy(12,10);
      cprintf("PREVENCION GRAFO");
      delay(800);

    if ((dar=_open("a:\\arcos.dat",1))==-1)
	{
	  clrscr();
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO ARCOS ");
	  getch();exit(1);
	 }
	
      while ((aux1=_read(dar,&arista,sizeof(arista)))!=0)
	{
	 if (aux1!=sizeof(arista))
	    {
	      printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
	      getch();exit(1);
	    }
	      strcpy(origen,arista.origen);
	      strcpy(destino,arista.destino);
	      kmts=arista.distancia;
	      peajes=arista.peaje;

	    auxnodo=mul;
	    while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	     {
	      auxnodo=auxnodo->sig;
	     }
	     auxnodo2=mul;
	     while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
	       {
		auxnodo2=auxnodo2->sig;
	       }

		  clrscr();
		  nuevo1=malloc(sizeof(struct arco));
		  nuevo1->kmts=kmts;
		  nuevo1->peaje=peajes;
		  nuevo1->sig=NULL;
		  nuevo1->dest=auxnodo2;
		  textmode(C40);
		  textcolor(4);
		  gotoxy(12,10);
		  cprintf("GRAFO CARGADO");
		  delay(50);
		    if (auxnodo->ady==NULL)
		     {
		      auxnodo->ady=nuevo1;
		     }
		    else
		     { auxarco=auxnodo->ady;
		      while (auxarco->sig!=NULL)
		       {
			 auxarco=auxarco->sig;
		       }
		      auxarco->sig=nuevo1;
		     }
	}

    close(dar);
    textmode(BW80);
 }


//--------------------------------------------------------------------------------


/******************************************************************************/
							      

/************************* PROCEMIENTOS DEL MENU ******************************/


//--------------------------------------------------------------------------------


void escribe_menu2()
   {
    int i;
    clrscr();
    textbackground(15);textcolor(1);
    for(i=1; i<=2000; i++)
    {
     cprintf("°");
    }
    window(1,1,80,25);
    gotoxy(1,1);
    fondo(2,81,LIGHTGRAY);
    piso_color(10,RED);
    gotoxy(8,1);
    cprintf("NODOS");
    piso_color(WHITE,RED);
    gotoxy(18,1);
    cprintf("ARISTAS");
    gotoxy(32,1);
    cprintf("LISTADOS");
    gotoxy(46,1);
    cprintf("RECORRIDOS");
    gotoxy(60,1);
    cprintf("AYUDA");
    gotoxy(70,1);
    cprintf("SALIR");
    ruta();
    piso_color(BLACK,WHITE);
    marco(2,3,78,22);
    gotoxy(1,24);
    fondo(1,159,LIGHTGRAY);
    piso_color(3,4);
    gotoxy(2,24);
    cprintf(" En este comando usted podra tener las facilidades de poder adicionar         ");
    gotoxy(2,25);
    cprintf(" consultar, modificar, eliminar, grado interno y externo de un NODO.          ");
    gotoxy(8,1);

}


//--------------------------------------------------------------------------------


void fondo(int a,int c,int color)
{
  int i;
  textcolor(color);
  for(i=a;i<=c;i++)
    {
     cprintf("%c",219);
    }
}


//--------------------------------------------------------------------------------


void marco(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'Ú');
   for (i=a;i<=c;i++ )
     {
       cprintf("%c",'Ä');
     }
   cprintf("%c",'¿');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'³');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
    {
      cprintf("%c",'Ä');
    }
  cprintf("%c",'Ù');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'³');
  }
}


//--------------------------------------------------------------------------------


void marco2(int a,int b,int c,int d)
{
   int i;
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'Ú');
   for (i=a;i<=c;i++ )
      {
       cprintf("%c",'Ä');
      }
   cprintf("%c",'¿');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
      cprintf("%c",'³');

   }              
  gotoxy(a-1,d+1);
  cprintf("%c",192);
  for (i=a;i<=c;i++)
    {
     cprintf("%c",'Ä');
    }
  cprintf("%c",'Ù');
  for (i=b;i<=d;i++ )
   {
     gotoxy(a-1,i);
     cprintf("%c",'³');
   }
  window(a,b,c,d);
}


//--------------------------------------------------------------------------------


void ref1(int n,int piso,int color,char s[])
{
   gotoxy(n,1);
   piso_color(piso,color);
   cprintf("%s",s);
}


//--------------------------------------------------------------------------------



void ref2(int n,int piso,int color,char s[])
{
  gotoxy(n,1);
  piso_color(piso,color);
  cprintf("%s",s);
  gotoxy(n,1);
}



//--------------------------------------------------------------------------------



void piso_color(int piso,int color)
{
   textbackground(piso);
   textcolor(color);
}



//--------------------------------------------------------------------------------


void menu1()
{
     int sw;
     char c;
     sw=0;
     piso_color(1,WHITE);
     escribe_menu();
     c = getch();
     while ((c != 27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 :
		       {
			  piso_color (1,WHITE);
			  cprintf("%s",op[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 7)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	     case 72 :
		       {
			  piso_color(1,WHITE);
			  cprintf("%s",op[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 1) gotoxy (3,7);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }

	   c=getch();

	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 adic_nodo();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
			}

		case 2:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 consultar_nodo();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }

		case 3:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 elim_nodo();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }

		case 4:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 actulizar_ciudad();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }

		case 5:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 grado_int();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }

		case 6:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 grado_ext();
			 clrscr();
			 escribe_menu();
			 getch();
			 break;
		       }

		case 7:
		       {
			 sw=1;
			 break;
		       }

		 }

	   }

     }

}


//--------------------------------------------------------------------------------


void escribe_menu()
{
     marco2(4,3,20,9);
     for(j=3; j<=9; j++)
     {
      for(i=4;i<=20;i++)
      {
       textcolor(0);textbackground(1);
       gotoxy(i,j);cprintf(" ");
      }
     }
     piso_color(1,WHITE);
     for(i=2;i<=8;i++)
      {
       gotoxy (3,i);
       cprintf("%s",op[i]);
      }
     piso_color (WHITE,1);
     gotoxy (3,1);
     cprintf("%s",op[1]);
     gotoxy (3,1);
}


//--------------------------------------------------------------------------------


void menu2()
{
     int sw;
     char c;
     sw=0;
     piso_color(1,WHITE);
     escribe_menu3();
     c = getch();
     while ((c != 27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 : 
		       {
			  piso_color (1,WHITE);
			  cprintf("%s",op3[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 5)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op3[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	     case 72 : 
		       {
			  piso_color(1,WHITE);
			  cprintf("%s",op3[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 1) gotoxy (3,5);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op3[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }

	   c=getch();
	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 adic_arco();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
			}

		case 2:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 consultar_arista();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }
			
		 case 3:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 elim_arco();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
			}

		case 4:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modificar_arco();
			 clrscr();
			 escribe_menu3();
			 getch();
			 break;
		       }

		 case 5:
			{
			 sw=1;
			 break;
			}

		 }

	   }

     }

}


//--------------------------------------------------------------------------------


void escribe_menu3()
{
      marco2(16,3,28,7);
      for(j=3; j<=7; j++)
      {
       for(i=16;i<=28;i++)
       {
	textcolor(0);textbackground(1);
	gotoxy(i,j);cprintf(" ");
       }
      }
      piso_color(1,WHITE);
      for(i=2;i<=5;i++)
      {
       gotoxy (3,i);
       cprintf("%s ",op3[i]);
      }
     piso_color (WHITE,1);
     gotoxy (3,1);
     cprintf("%s",op3[1]);
     gotoxy (3,1);
}


//--------------------------------------------------------------------------------


void menu4()
{
     int sw;
     char c;
     sw=0;
     piso_color(1,WHITE);
     escribe_menu5();
     c = getch();

     while ((c != 27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 : 
		       {
			  piso_color (1,WHITE);
			  cprintf("%s",op4[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 6)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op4[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	     case 72 : 
		       {
			  piso_color(1,WHITE);
			  cprintf("%s",op4[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 1) gotoxy (3,6);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op4[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }
	   c=getch();

	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modo_recorrido=1;
			 ruta_corta_larga();
			 clrscr();
			 escribe_menu5();
			 getch();
			 break;
			}

		case 2:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modo_recorrido=2;
			 ruta_corta_larga();
			 clrscr();
			 escribe_menu5();
			 getch();
			 break;
		       }

		case 3:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modo_recorrido=4;
			 ruta_cara_barata();
			 clrscr();
			 escribe_menu5();
			 getch();
			 break;
			}

		case 4:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modo_recorrido=3;
			 ruta_cara_barata();
			 clrscr();
			 escribe_menu5();
			 getch();
			 break;
		       }

		case 5:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 modo_recorrido=5;
			 ruta_cara_barata();
			 clrscr();
			 escribe_menu5();
			 getch();
			 break;
		       }

		case 6:
		       {
			 sw=1;
			 break;
		       }

		}

	   }

     }

}



//--------------------------------------------------------------------------------


void escribe_menu5()
{
     marco2(44,3,62,8);
     for(j=3; j<=8; j++)
     {
      for(i=44;i<=62;i++)
      {
       textcolor(0);textbackground(15);
       gotoxy(i,j);cprintf(" ");
      }
     }
      piso_color(1,WHITE);
      for(i=2;i<=6;i++)
      {
       gotoxy (3,i);
       cprintf("%s ",op4[i]);
      }
     piso_color (WHITE,1);
     gotoxy (3,1);
     cprintf("%s",op4[1]);
     gotoxy (3,1);
}


//--------------------------------------------------------------------------------



void menu3()
{
     int sw;
     char c;
     sw=0;
     piso_color(1,WHITE);
     escribe_menu4();
     c = getch();

     while ((c !=27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 :
		       {
			  piso_color (1,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 4)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	     case 72 :
		       {
			  piso_color(1,WHITE);
			  cprintf("%s",op2[wherey()]);
			  piso_color (WHITE,1);
			  if (wherey() == 1) gotoxy (3,4);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op2[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }

	   }

	   c=getch();

	   if(c==13)
	   {
	       switch(wherey())
	       {
		 case 1:
			{
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 imprimir_archivo_ciudad();
			 clrscr();
			 escribe_menu4();
			 getch();
			 break;
			}

		case 2:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 imprimir_archivo_arcos();
			 clrscr();
			 escribe_menu4();
			 getch();
			 break;
		       }

		case 3:
		       {
			 piso_color(1,WHITE);
			 window(1,1,80,25);
			 clrscr();
			 escribe_menu2();
			 imprimir();
			 clrscr();
			 escribe_menu4();
			 getch();
			 break;
		       }

		case 4:
		       {
			 sw=1;
			 break;
		       }

		 }


	   }

     }

}


//--------------------------------------------------------------------------------


void escribe_menu4()
{
     marco2(30,3,50,6);
     for(j=3; j<=6; j++)
     {
      for(i=30;i<=50;i++)
      {
       textcolor(0);textbackground(1);
       gotoxy(i,j);cprintf(" ");
      }
     }
     piso_color(1,WHITE);
     for(i=2;i<=4;i++)
      {
       gotoxy (3,i);
       cprintf("%s ",op2[i]);
      }
     piso_color (WHITE,1);
     gotoxy (3,1);
     cprintf("%s",op2[1]);
     gotoxy (3,1);
}


//--------------------------------------------------------------------------------


void ayuda()
{
   for(j=3; j<=12; j++)
    {
     for(i=45;i<=75;i++)
     {
      textcolor(0);textbackground(1);
      gotoxy(i,j);cprintf(" ");
     }
    }
   piso_color(1,WHITE);
   marco2(45,3,75,12);
   cprintf("%c Desplazamiento hacia arriba  ",24);
   cprintf("%c Desplazamiento hacia abajo   ",25);
   cprintf("%c Desplazamiento a la izquierda",27);
   cprintf("-> Desplazamiento a la derecha ");
   cprintf("ENTER para entrar a los menus. ");
   cprintf("colgantes.                     ");
   cprintf("ENTER en cada opcion ingresa a ");
   cprintf("el desarrollo de esta.         ");
   cprintf("ESC para salir de cada menu.   ");
   getch();
}


//--------------------------------------------------------------------------------



void salir()
{  
  sw2=1;
}



//--------------------------------------------------------------------------------


/******************************************************************************/


/********************** PROCEDIMIENTO PRINCIPAL DEL PROGRAMA *****************************************************/



//--------------------------------------------------------------------------------


void main()
{
char d;
textcolor(15);textbackground(1);
adverten();
clave();
udes();
textcolor(15);textbackground(1);
cargar_grafo();
escribe_menu2();

gotoxy(1,24);
fondo(1,159,LIGHTGRAY);
piso_color(3,4);
gotoxy(2,24);
cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
gotoxy(2,25);
cprintf(" consultar, modificar, eliminar, grado interno y externo de un NODO.         ");
gotoxy(8,1);

    sw2=0;
    d=getch();
    gotoxy(8,1);
    while ((d!=27)&&(sw2!=1))
    {
	  switch(d)
	  {
	     case 77:
		     {

		      switch(wherex())
			{
		      case 8:
			     {
			       ref1(8,WHITE,RED,"NODOS");
			       ref2(18,10,RED,"ARISTAS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
			       gotoxy(2,25);
			       cprintf(" consultar, modificar y eliminar a una ARISTA.                               ");
			       gotoxy(18,1);
			       break;
			     }

		     case 18:
			     {
			       ref1(18,WHITE,RED,"ARISTAS");
			       ref2(32,10,RED,"LISTADOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando existen las opciones que le permitiran al usuario poder     ");
			       gotoxy(2,25);
			       cprintf(" visualizar los nodos y aristas existentes y tambien visualizar el GRAFO.    ");
			       gotoxy(32,1);
			       break;
			     }

		     case 32:
			     {
			       ref1(32,WHITE,RED,"LISTADOS");
			       ref2(46,10,RED,"RECORRIDOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando existen las rutas mas corta, mas larga, mas cara, mas       ");
			       gotoxy(2,25);
			       cprintf(" barata y una opci¢n que le permitira ver todas las rutas existentes.        ");
			       gotoxy(46,1);                                                                       
			       break;
			     }

		     case 46:
			     {
			       ref1(46,WHITE,RED,"RECORRIDOS");
			       ref2(60,10,RED,"AYUDA");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando le mostrara un peque¤o resumen de como poder manejar los    ");
			       gotoxy(2,25);
			       cprintf(" menus colgantes y como escoger una opci¢n en cualquiera de ellos.           ");
			       gotoxy(60,1);
			       break;
			     }

		    case 60:
			     {
			       ref1(60,WHITE,RED,"AYUDA");
			       ref2(70,10,RED,"SALIR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" Copyrigth (c) 1997 UDES   Valledupar.   Derechos reservados del Autor       ");
			       gotoxy(2,25);
			       cprintf(" Unica Versi¢n  Dise¤o: HEYNER A. AROCA ARAUJO Cod: 95131119 Ing de Sistemas ");
			       gotoxy(70,1);
			       break;
			     }

		    case 70:
			     {
			       ref1(70,WHITE,RED,"SALIR");
			       ref2(8,10,RED,"NODOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
			       gotoxy(2,25);                                                                   
			       cprintf(" consultar, modificar, eliminar, grado interno y externo de un NODO.         ");
			       gotoxy(8,1);
			       break;
			     }
			      
			}

		     break;

		     }

	     case 75:
		      {
			switch(wherex())

			{
		      case 8:
			     {
			       ref1(8,WHITE,RED,"NODOS");
			       ref2(70,10,RED,"SALIR");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" Copyrigth (c) 1997 UDES   Valledupar.   Derechos reservados del Autor       ");
			       gotoxy(2,25);
			       cprintf(" Unica Versi¢n  Dise¤o: UBALDO MURGAS GRANADOS Cod: 95132031 Ing de Sistemas ");
			       gotoxy(70,1);
			       break;
			     }

		     case 18:
			     {
			       ref1(18,WHITE,RED,"ARISTAS");
			       ref2(8,10,RED,"NODOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
			       gotoxy(2,25);
			       cprintf(" consultar, modificar, eliminar, grado interno y externo de un NODO.         ");
			       gotoxy(8,1);
			       break;
			     }

		     case 32:{
			       ref1(32,WHITE,RED,"LISTADOS");
			       ref2(18,10,RED,"ARISTAS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando usted podra tener las facilidades de poder adicionar        ");
			       gotoxy(2,25);                                                                         
			       cprintf(" consultar, modificar y eliminar a una ARISTA.                               ");
			       gotoxy(18,1);
			       break;
			     }

		     case 46:
			     {
			       ref1(46,WHITE,RED,"RECORRIDOS");
			       ref2(32,10,RED,"LISTADOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando existen las opciones que le permitiran al usuario poder     ");
			       gotoxy(2,25);
			       cprintf(" visualizar los nodos y aristas existentes y tambien visualizar el GRAFO.    ");
			       gotoxy(32,1);
			       break;
			     }

		    case 60:
			     {
			       ref1(60,WHITE,RED,"AYUDA");
			       ref2(46,10,RED,"RECORRIDOS");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando existen las rutas mas corta, mas larga, mas cara, mas       ");
			       gotoxy(2,25);
			       cprintf(" barata y una opci¢n que le permitira ver todas las rutas existentes.        ");
			       gotoxy(46,1);
			       break;
			     }

		    case 70:
			     {
			       ref1(70,WHITE,RED,"SALIR");
			       ref2(60,10,RED,"AYUDA");
			       gotoxy(1,24);
			       fondo(1,159,LIGHTGRAY);
			       piso_color(3,4);
			       gotoxy(2,24);
			       cprintf(" En este comando le mostrara un peque¤o resumen de como poder manejar los    ");
			       gotoxy(2,25);                                                                        
			       cprintf(" menus colgantes y como escoger una opci¢n en cualquiera de ellos.           ");
			       gotoxy(60,1);
			       break;
			     }

			}

		    break;
		  }

		}

	  d=getch();

	  if(d==13)
	  {
	       switch(wherex())
	       {
		 case 8:
			 {
			   menu1();
			   window(1,1,80,25);
			   clrscr();
			   escribe_menu2();
			   break;
			 }

		 case 18:
			 {
			  menu2();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

		case 32:
			{
			  menu3();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

	       case 46:
			{
			  menu4();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

	       case 60:
			{
			  ayuda();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menu2();
			  break;
			}

		case 70:{
			  salir();
			  break;
			}

		 }

	  }

    }

}


/******************************************************************************/

/***************************** FINAL DEL PROGRAMA *****************************/

/******************************************************************************/		