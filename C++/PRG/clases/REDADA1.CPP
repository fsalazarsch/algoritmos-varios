

#include<graphics.h>
#include<stdio.h>
#include <time.h>
#include<process.h>
#include<conio.h>
#include<iostream.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#define IZQUIERDO 1
#define DERECHO 2
#define g (gotoxy)
#define z 400
#include<time.h>
void clave();
void main();
union REGS r;
void modo(),*imagen1;
unsigned int tamano1;
int boton=0;
int p=0,o=0,h=0;
int Vert,Horiz;
int wo=0;
//CLASE DE VENTANA//////////////////////////////////////////////////////////

class programa;
class programa1;
class punto
{
public:
void ventana(int x1,int y1,int x2,int y2);
};

void punto::ventana(int x1,int y1,int x2,int y2)
{
int a,b,c,d;
textcolor(4);
r.h.bh=0;
r.x.dx=y1;
r.x.cx=x1;r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
r.x.dx=y2;
r.x.cx=x1;r.x.cx=y2;r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
r.x.dx=y1;
r.x.cx=x2;r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
r.x.dx=y2;
r.x.cx=x2;r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
c=x1;
d=x2;
x1+=1;
x2-=1;
for(a=x1;a<x2;x1++)
  { r.x.dx=y1;
r.x.cx=x1;r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
r.x.dx=y2;
r.x.cx=x1; r.h.ah=0x0c;int86(0x10,&r,&r);textcolor(4);
    if(x1==x2)break;
  }
y1+=1;
y2-=1;
for(b=y1;b<y2;y1++)
  {    r.x.dx=y1;
       r.x.cx=c;r.h.ah=0x0c;int86(0x10,&r,&r);
   r.x.dx=y1;
   r.x.cx=d;
r.h.ah=0x0c;int86(0x10,&r,&r);

     if(y1==y2)break;
     }
}





//CLASE DEL MAOUSE//////////////////////////////////////////////////////////


class s{
public:void t();};

s lo;



class MOUSE{
int Inicializado, Desconectado,NBotones;
public:
void clave1();
void clave2();
void clave3();
void clave4();
//void red();
void servidor();
	void conectoruno();
	void conectordos();
	void conectortres();
	void conectorcuatro();
	void computadores();
	void cuadro(int i,int j,int k,int l);
	void menu();
	void red1();
	void red2();
	void red3();
	void red4();
	MOUSE(void);
	~MOUSE(void);
	int ExisteUnidad(void);
	void Inicializar(),Mostrar();
	int Estado (int *Vertical, int *Horizontal);
	void LimVert (int x, int x1),LimHoriz (int y, int y1);
};

//s lo;
MOUSE mouse;

punto uno;


class Tobjeto   {
public:
int valor;
char nombre[30];
virtual void imprimirse()=0;
};

class Tnodo:public Tobjeto  {
 public:Tobjeto *psiguiente;
	 void imprimirse();
	 Tnodo();
};

void Tnodo::imprimirse() {
cout<<valor;cout<<nombre;cout<<'\n'; }

Tnodo::Tnodo() { psiguiente=NULL;}

class Tcoleccion    {
public:
	virtual void menu()=0;
	virtual void llenar(Tnodo *p)=0;
	virtual void llenar()=0;
	virtual void borrar()=0;
	virtual void imprimir()=0;
};

class Tlista:public Tcoleccion
{
public: Tnodo *pcabeza;
	Tcoleccion *pcoleccion;
	virtual void menu();
	virtual void llenar(Tnodo *p);
	Tlista();
	    virtual void llenar();
	    virtual void borrar();
	    virtual void imprimir();
	    };

Tlista::Tlista() { pcabeza=NULL;}
void Tlista::menu()  {
char c;
  do {
     clrscr();
     g(35,5);cout<<"..LISTAS CON CLASES";
     g(23,10);cout<<"1..CREAR LISTA";
     g(23,12);cout<<"2..BORRAR ELEMENTO DE LA LISTA";
     g(23,14);cout<<"3..IMPRIMIR";
     g(23,16);cout<<"4..SALIR A MENU PRINCIPAL";
     g(23,20);cout<<"..DIGITE OPCION[ ]";
     g(39,20);cin>>c;
     switch(c)     {
       case '1':llenar();break;
       case '2':borrar();break;
       case '3':imprimir();
       }
}while(c!='4');
}

void Tlista::imprimir() {
char c;
clrscr();
Tnodo *p;
p=pcabeza;
while(p!=NULL)
{
  p->imprimirse();
  p=(Tnodo *)p->psiguiente;
  };
g(25,7);cout<<"DIGITE UNA TECLA Y ENTER";
g(51,7);cin>>c;
}


void Tlista::llenar()   {
	Tnodo *p;  char c;
	do {
		clrscr();
		p=new Tnodo;
	      g(23,5);cout<<"..PROGRAMACION ORIENTADA A OBJETO...";
	      g(23,9);cout<<"A..DIGITE LA CANTIDAD DEL PRODUCTO:"; g(59,9);cin>>p->valor;
	      g(23,15);cout<<"B..DIGITE EL NOMBRE DEL PRODUCTO:"; g(57,15);cin>>p->nombre;
		p->psiguiente=NULL;
		llenar(p);
		clrscr();   g(25,10);cout<<"DESEA  OTRO S o N:";  g(43,10);cin>>c;
	   } while(c!='n'&&c!='N');
}
void Tlista::llenar(Tnodo *p) {
      if(pcabeza==NULL) { pcabeza=p;   }
      else {  p->psiguiente=pcabeza; pcabeza=p; };
}
void Tlista::borrar() {
	int val;  Tnodo *a,*p;
	clrscr(); g(30,7);cout<<"BORRAR";
       g(23,15);cout<<"DIGITE EL VALOR A BORRAR:";g(49,15);cin>>val;
	p=a=pcabeza;
	while(p!=NULL && p->valor!=val) {  a=p; p=(Tnodo *)p->psiguiente;  }
	if(p==NULL) {g(23,17);cout<<"NO SE ENCONTRO EL PRODUCTO A BORRAR"; getch();}
	if(p!=NULL && p->valor==val) {
		a->psiguiente=p->psiguiente;
		p->psiguiente=NULL;
		pcoleccion->llenar(p);
	     }
}

class Tpila:public Tlista {
public: virtual void menu();

};

void Tpila::menu()
{
char c;
  do {
     clrscr();
    g(35,5); cout<<"..MENU PILA CON CLASES..";
    g(23,10); cout<<"1..CREAR UNA PILA";
    g(23,12); cout<<"2..IMPRIMIR UNA PILA";
    g(23,14); cout<<"3..SALIR AL MENU PRINCIPAL";
    g(32,19); cout<<"..DIGITE OPCION[ ]";
    g(48,19);cin>>c;
     switch(c)
     {
       case '1':llenar();break;
       case '2':imprimir();
       }
}while(c!='3');
}

class programa1{
public:void menu();};
programa1 los;
void programa1::menu()
{
clrscr();
textbackground(1);
textcolor(7);
char c; Tlista lista; Tpila pila;  lista.pcoleccion=&pila;
do  {
	clrscr();

       g(28,5);cout<<"...MENU PRINCIPAL";
      g(23,10); cout<<"1..PASAR AL MENU LISTA";
      g(23,12);	cout<<"2..PASAR AL MENU PILA";
      g(23,14);	cout<<"3..SALIR";
      g(23,16); cout<<"...DIGITE SU OPCION[ ]";
      g(43,16);	cin>>c;
	switch(c) {
	      case '1':lista.menu(); break;
	      case '2':pila.menu();
	      }
    }  while(c!='3');
}


















MOUSE::MOUSE() { Inicializado = 0;Desconectado = 1;}
MOUSE::~MOUSE(void) { }

int MOUSE::ExisteUnidad(void) {
	void far *direccion;
	direccion = getvect (0x33);
	return (direccion != NULL && *(unsigned char *)direccion != 0xcf);
};

void MOUSE::Inicializar () {
	Inicializado = ExisteUnidad();
	if (Inicializado )  {
		r.x.ax = 0x00;
		int86 (0x33,&r,&r);
		NBotones = r.x.bx;
		Desconectado = 0;
	}
	else Desconectado = 1;
}

void MOUSE::Mostrar() {	r.x.ax = 0x01;	int86 (0x33,&r,&r);
}

 void MOUSE::menu()
{
setfillstyle(1,3);//floodfill(311,374,15);
settextstyle(1,0,1);
setbkcolor(9);
setcolor(3);outtextxy(80,436,"PROGRAMA");

setcolor(1);outtextxy(80,439,"PROGRAMA");
setcolor(3);
outtextxy(410,434,"SALIR");
setcolor(1);
outtextxy(410,439,"SALIR");
setcolor(3);
outtextxy(190,70,"SISTEMAS OPERACIONALES ");
setcolor(1);
outtextxy(190,73,"SISTEMAS OPERACIONALES ");
setcolor(3);
outtextxy(140,95,"CONTROL DE ACCESO PARA CLASES DE USUARIO");
setcolor(1);
outtextxy(140,98,"CONTROL DE ACCESO PARA CLASES DE USUARIO");
setcolor(3);
outtextxy(100,150,"PRESENTADO AL PROFESOR:");
setcolor(1);
outtextxy(100,153,"PRESENTADO AL PROFESOR:");
setcolor(3);
outtextxy(190,190,"ROBERTO FERNADEZ");
setcolor(1);
outtextxy(190,193,"ROBERTO FERNADEZ");
setcolor(3);
outtextxy(100,260,"PRESENTADO POR:");
setcolor(1);
outtextxy(100,263,"PRESENTADO POR:");
setcolor(3);
outtextxy(180,289,"LUIS ENRIQUE MORALES(TOBY)COD 494396");
setcolor(1);
outtextxy(180,291,"LUIS ENRIQUE MORALES(TOBY)COD 494396");

setcolor(3);
outtextxy(60,310,"pw1=sistemas,pw2=ingenieria,pw3=toby,pw4=operativos");
setcolor(1);
outtextxy(60,313,"pw1=sistemas,pw2=ingenieria,pw3=toby,pw4=operativos");




}
///////////////////////


/*void presentacion(void)
{
inicializar();
setpalette(0,BLACK);
setpalette(15,MAGENTA);
delay(z);
settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
outtextxy(50,200,"LOCOS  SOFT CORP");
delay(z);
setpalette(15,GREEN);
delay(z);
setpalette(15,WHITE);
delay(z);
setpalette(15,CYAN);
delay(z);
setpalette(15,MAGENTA);
delay(z);
setpalette(15,YELLOW);
delay(z);
settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
outtextxy(280,300,"U:.A:.N:.");
delay(z);
settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
outtextxy(100,25,"INTERPOLACIONES");
delay(z);
setpalette(15,GREEN);
delay(z);
setpalette(15,WHITE);
delay(z);
setpalette(15,CYAN);
delay(z);
setpalette(15,MAGENTA);
delay(z);
setpalette(15,YELLOW);
delay(z);
settextstyle(2,HORIZ_DIR,0);
outtextxy(250,425,"All rights reserved LOCOS SOFT. CORP. 1997@");
outtextxy(250,435,"JOHN HENRY MARIN ARIAS     499515310");
outtextxy(250,445,"LUIS ENRIQUE MORALES       499424396");
delay(z*9);
closegraph();
}
*/











//////////////////

int MOUSE::Estado(int *Vertical, int *Horizontal) {
	r.x.ax = 0x03;
	int86 (0x33,&r,&r);
	*Vertical = r.x.cx;
	*Horizontal = r.x.dx;
	return r.x.bx;
}
void MOUSE::LimVert(int x, int x1) {
	r.x.ax = 0x07;
	r.x.cx = x;
	r.x.dx = x1;
	int86 (0x33,&r,&r);
}
void MOUSE::LimHoriz (int y, int y1) {
	r.x.ax = 0x08;	r.x.cx = y;r.x.dx = y1;	int86 (0x33,&r,&r);
}



void MOUSE::conectoruno()
{
closegraph();
mouse.clave1();
}
//clrscr();
void MOUSE::clave1()
{
clrscr();
int i;
char pal[7];
char c;
pal[0]='s';
pal[1]='i';
pal[2]='s';
pal[3]='t';
pal[4]='e';
pal[5]='m';
pal[6]='a';
pal[7]='s';
textbackground(1);
textcolor(15);
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(28,4);cout<<"TERMINAL NUMERO 1";
g(20,11);cout<<"DIGITE EL PASSWORD";
for(i=0;i<8;i++)
{
g(20+i,15);c=getch();
//clrscr();
g(20+i,15);cout<<"*";
if(c!=pal[i])
{
g(20,18);cout<<"CLAVE ERRADA";
getch();
clrscr();
mouse.clave1();
}
}
clrscr();
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(28,4);cout<<"CLAVE CORRECTA.";
time_t t;
t = time(NULL);
//printf("Current date is %s", ctime(&t));
t -= 24L*60L*60L;  /* Back up to same time previous day */
stime(&t);
g(15,9);printf("\LA HORA DE ESTA TERMINAL SON LAS %s", ctime(&t));
g(15,12);cout<<"EN ESTA TERMINAL USTED PUEDE GRAVAR Y ARCHIVAR ";
int matriz[4][4];
int numequ,numarch;
  randomize();
  for(int io=0;io<4;io++)
   for(int j=0;j<4;j++)
    matriz[i][j]=random(2);
  numequ=1;
  g(15,15);cout << "el numero del equipo 1: ";

  do
  {
  g(15,18);cout << "Digite el numero del archivo: ";
  cin >> numarch;

  }while(numarch > 4);
  if(matriz[numequ][numarch] == 1)
  {
   g(18,19);cout <<"No tiene acceso a este archivo";
   //cout <<"Ha accesado al archivo";
   getch();
   main();
  }
  else
  {
  g(18,21);cout <<"HA accesado al archivo";
 ////////////////////////////////////////////programa de archivo////////
  getch();
lo.t();
   getch();
  main();
  }
getch();
main();
}
///////////////////////////////////ojo archi
class Tfacultad {
	public:     void imprimirse();
		    void modificarse();
		    Tfacultad();
		    char nombre[30],duracion[20],materias[60];
		    char profesores[60],sedes[30],decano[30];
};

Tfacultad::Tfacultad(){
	*nombre='\0';	*duracion='\0';
	*materias='\0';	*profesores='\0';
	*sedes='\0';	*decano='\0';
}

void Tfacultad::imprimirse(){
	char c;      clrscr();
       g(28,6);cout<<"FACULTAD:"<< nombre<<'\n';
       g(25,9);cout<<"DURACION:"<< duracion<<'\n';
       g(25,11);cout<<"MATERIAS:"<< materias<<'\n';
       g(25,13);cout<<"PROFESORES:"<< profesores<<'\n';
       g(25,15);cout<<"SEDES:"<< sedes<<'\n';
       g(25,17);cout<<"DECANO:"<< decano<<'\n';
       g(23,20);cout<<"presione una tecla y enter para continuar[ ]";
       g(65,20);cin>>c;
}

void Tfacultad::modificarse(){
	clrscr();
	g(26,7);cout<<"DURACION:"; g(35,7);cin>>duracion;
       g(26,9);cout<<"MATERIAS:"; g(36,9);cin>>materias;
       g(26,11);cout<<"PROFESORES:";g(38,11);cin>>profesores;
       g(26,13);cout<<"SEDES:";g(33,13);cin>>sedes;
       g(26,15);cout<<"DECANO:";g(34,15);cin>>decano;
       g(28,19);cout<<"presione una tecla y enter para continuar[ ]";
	char c;       g(70,19); cin>>c;
}

class Tsistemas:public Tfacultad{ public: Tsistemas(); };
Tsistemas::Tsistemas() { strcpy(nombre,"SISTEMAS"); }

class Tcivil:public Tfacultad{ public: Tcivil(); };
Tcivil::Tcivil() { strcpy(nombre,"CIVIL"); }

class Teconomia:public Tfacultad{ public: Teconomia(); };
Teconomia::Teconomia() { strcpy(nombre,"ECONOMIA"); }

class Tindustrial:public Tfacultad{ public: Tindustrial(); };
Tindustrial::Tindustrial() { strcpy(nombre,"INDUSTRIAL"); }

char menu1(){
      clrscr();  char c;
       g(14,4);cout<<"UNIVERSIDAD ANTONIO NARI¥O FACULTADES QUE TENEMOS"<<'\n';
       g(20,8);cout<<"1..facultad de ingenieria de sistemas"<<'\n';
       g(20,10);cout<<"2..facultad de ingenieria industrial"<<'\n';
       g(20,12);cout<<"3..facultad de ingenieria civil"<<'\n';
		    g(20,14);cout<<"4..facultad de economia"<<'\n';
       g(20,16);cout<<"5..salir"<<'\n';
       g(18,20);cout<<"digite la faculta que desee[ ]"<<'\n';
       g(46,20);cin>>c;
	return c;
}

char menu2() {
	char c;		clrscr();
	g(25,5);cout<<"MENU DE ACCIONES"<<'\n';
	g(23,7);cout<<"1..ingresar imformacion"<<'\n';
	g(23,9);cout<<"2..imprimir"<<'\n';
	g(23,11);cout<<"3..salir al menu facultad"<<'\n';
	g(22,15);cout<<"..digite su opcion[ ]";
	g(41,15);cin>>c;         return c;
}



//class s{

//public:void t();};


void s::t()
{
	char c;
	textbackground(7);
	textcolor(8);
	Tsistemas sistemas;	Tindustrial industrial;
	Tcivil civil;           Teconomia economia;
	Tfacultad * r=&sistemas;
	while((c=menu1())!='6'){
		switch (c) {
			case '1':r=&sistemas;break;
			case '2':r=&industrial;break;
			case '3':r=&civil;break;
			case '4':r=&economia;break;
			case '5':main();
		};
		while((c=menu2())!='3'){
			switch (c) {
				case '1':r->modificarse();break;
				case '2':r->imprimirse();break;
			};
		};
	};
}

//s lo;

















//////////////////////ojo..............
void MOUSE::conectordos()
{
closegraph();
mouse.clave2();

}

void MOUSE::clave2()
{
clrscr();
int i;
char pal[9];
char c;
pal[0]='i';
pal[1]='n';
pal[2]='g';
pal[3]='e';
pal[4]='n';
pal[5]='i';
pal[6]='e';
pal[7]='r';
pal[8]='i';
pal[9]='a';
textbackground(5);
textcolor(15);
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(27,3);cout<<"SIMULACION DE UNA RED";
g(28,4);cout<<"TERMINAL NUMERO 2";
g(20,11);cout<<"DIGITE EL PASSWORD O CLAVE POR FAVOR";
for(i=0;i<10;i++)
{
g(20+i,15);c=getch();
//clrscr();
g(20+i,15);cout<<"*";
if(c!=pal[i])
{
g(20,18);cout<<"CLAVE ERRADA";
getch();
clrscr();
mouse.clave2();
}
}
clrscr();
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(27,3);cout<<"UNIVERSIDAD ANTONIO NARI¥O";
g(28,4);cout<<"CLAVE CORRECTA.";
time_t t;
t = time(NULL);
//printf("Current date is %s", ctime(&t));
t -= 24L*60L*60L;  /* Back up to same time previous day */
stime(&t);
g(15,9);printf("\LA HORA DE ESTA TERMINAL SON LAS %s", ctime(&t));
g(15,12);cout<<"EN ESTA TERMINAL USTED PUEDE GRAVAR Y ARCHIVAR ";
int matriz[4][4];
int numequ,numarch;
  randomize();
  for(int io=0;io<4;io++)
   for(int j=0;j<4;j++)
    matriz[i][j]=random(2);
//  do
 // {
  g(15,15);cout << "Terminal de la uan #2 ";
  numequ=2;
  /// cin >> numequ;
 // }while(numequ == 2);
  do
  {
  g(15,18);cout << "Digite el numero del archivo: ";
  cin >> numarch;

  }while(numarch > 4);
  if(matriz[numequ][numarch] == 1)
  {
   g(18,19);cout <<"No tiene acceso a este archivo";
   //cout <<"Ha accesado al archivo";
   getch();
   main();
  }
  else
  {
  g(18,21);cout <<"HA accesado al archivo";
 ////////////////////////////////////////////programa de archivo////////
getch();
los.menu();
//getch();
//los.menu();
   ///getch();
//  main();
  }
getch();
main();
}



void MOUSE::conectortres()
{
closegraph();
mouse.clave3();

}
void MOUSE::clave3()
{
clrscr();
int i;
char pal[3];
char c;
pal[0]='t';
pal[1]='o';
pal[2]='b';
pal[3]='y';
//pal[4]='e';
//pal[5]='m';
//pal[6]='a';
//pal[7]='s';
textbackground(4);
textcolor(15);
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(26,3);cout<<"UNIVERSIDAD ANTONIO NARI¥O";
g(28,4);cout<<"TERMINAL NUMERO 3";
g(20,11);cout<<"DIGITE EL PASSWORD";
for(i=0;i<4;i++)
{
g(20+i,15);c=getch();
//clrscr();
g(20+i,15);cout<<"*";
if(c!=pal[i])
{
g(20,18);cout<<"CLAVE ERRADA............. ";
getch();
clrscr();
mouse.clave3();
}
}
clrscr();
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(27,3);cout<<"RED MATRICIAL";
g(28,4);cout<<"CLAVE CORRECTA.";
time_t t;
t = time(NULL);
//printf("Current date is %s", ctime(&t));
t -= 24L*60L*60L;  /* Back up to same time previous day */
stime(&t);
g(15,9);printf("\LA HORA DE ESTA TERMINAL SON LAS %s", ctime(&t));
g(15,12);cout<<"EN ESTA TERMINAL USTED PUEDE GRAVAR Y ARCHIVAR ";
int matriz[6][6];
int numequ,numarch;
  randomize();
  for(int io=0;io<6;io++)
   for(int j=0;j<6;j++)
    matriz[i][j]=random(2);
  numequ=3;
  g(15,15);cout << "ha accesado a la terminal #3";
  do
  {
  g(15,18);cout << "Digite el numero del archivo: ";
  cin >> numarch;
  }while(numarch > 6);
  if(matriz[numequ][numarch] == 1)
  {
   g(18,19);cout <<"No tiene acceso a este archivo";
   //cout <<"Ha accesado al archivo";
   getch();
   main();
  }
  else
  {
  g(18,21);cout <<"HA accesado al archivo";
 ////////////////////////////////////////////programa de archivo////////
//lo.t();programa
   getch();
  main();
  }
getch();
main();
}
void MOUSE::conectorcuatro()
{
closegraph();
mouse.clave4();
}
void MOUSE::clave4()
{
clrscr();






int i;
char pal[9];
char c;
pal[0]='o';
pal[1]='p';
pal[2]='e';
pal[3]='r';
pal[4]='a';
pal[5]='t';
pal[6]='i';
pal[7]='v';
pal[8]='o';
pal[9]='s';
textbackground(7);
textcolor(15);
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(27,3);cout<<"SISTEMAS OPERATIVOS";
g(28,4);cout<<"TERMINAL NUMERO 4";
g(20,11);cout<<"DIGITE EL PASSWORD";
for(i=0;i<10;i++)
{
g(20+i,15);c=getch();
//clrscr();
g(20+i,15);cout<<"*";
if(c!=pal[i])
{
g(20,18);cout<<"CLAVE ERRADA";
getch();
clrscr();
mouse.clave4();
}
}
clrscr();
mouse.cuadro(2,2,75,5);
mouse.cuadro(2,6,75,24);
g(28,4);cout<<"CLAVE CORRECTA.";
time_t t;
t = time(NULL);
//printf("Current date is %s", ctime(&t));
t -= 24L*60L*60L;  /* Back up to same time previous day */
stime(&t);
g(15,9);printf("\LA HORA DE ESTA TERMINAL SON LAS %s", ctime(&t));
g(15,12);cout<<"EN ESTA TERMINAL USTED PUEDE GRAVAR Y ARCHIVAR ";
int matriz[4][4];
int numequ,numarch;
  randomize();
  for(int io=0;io<4;io++)
   for(int j=0;j<4;j++)
    matriz[i][j]=random(2);

  numequ=4;
  g(15,15);cout << "Bienvenidos a la terminal #4 ";

   do
  {
  g(15,18);cout << "Digite el numero del archivo: ";
  cin >> numarch;

  }while(numarch > 4);
  if(matriz[numequ][numarch] == 1)
  {
   g(18,19);cout <<"No tiene acceso a este archivo";
   //cout <<"Ha accesado al archivo";
   getch();
   main();
  }
  else
  {
  g(18,21);cout <<"HA accesado al archivo";
 ////////////////////////////////////////////programa de archivo////////
//lo.t(); programa
   getch();
  main();
  }
getch();
main();
}
void MOUSE::red1()
{
//outtextxy(200,20,"Terminal #1 en red");
setcolor(p);
outtextxy(280,160,"SERVIDOR");
outtextxy(45,35,"Terminal #1 en red");
if(p>15)
{p=0;}
line(110,120,270,240);
p++;
}
void MOUSE::red2()
{
setcolor(o);
outtextxy(280,160,"SERVIDOR");
outtextxy(410,35,"Terminal #2 en red");
if(o>15)
//outtextxy(45,35,"Terminal #1 en red");
{o=0;}
line(570,120,380,240);
o++;
}
void MOUSE::red3()
{
//outtextxy(45,35,"Terminal #1 en red");
setcolor(p);
outtextxy(280,160,"SERVIDOR");
outtextxy(45,250,"Terminal #3 en red");
if(p>15)
{p=0;}
line(110,360,270,240);
p++;

}

void MOUSE::red4()
{
setcolor(p);

outtextxy(280,160,"SERVIDOR");
outtextxy(410,250,"Terminal #4 en red");
if(p>15)
{p=0;}
line(510,350,380,240);
p++;
}

void MOUSE::servidor()
{
//setbkcolor(9);
setcolor(3);
settextstyle(1,0,1);
outtextxy(180,15,"SISTEMAS OPERATIVOS");
setcolor(1);
outtextxy(180,18,"SISTEMAS OPERATIVOS");
setcolor(3);
outtextxy(490,420,"'EXIT'");
setcolor(1);
outtextxy(490,423,"'EXIT'");
setbkcolor(9);
int midx, midy, i;
midx = getmaxx() / 2;
midy = getmaxy() / 2;
for (i=EMPTY_FILL; i<USER_FILL; i++)
{
setfillstyle(i, getmaxcolor());
bar3d(midx-50, midy-50, midx+50, midy+50, 10, 1);
getch();
//////////teclado del servidor//////
setcolor(1);
bar3d(200,300,420,305,15,6);
putpixel(220,290,14);
setfillstyle(9,1);
floodfill(220,290,1);

}
}


void MOUSE::computadores()
{
setcolor(1);
rectangle(60,60,100,100);
setfillstyle(2,1);
floodfill(63, 63,1);
rectangle(50,110,110,120);
//////////////computador#2
setcolor(1);
rectangle(520,60,560,100);
setfillstyle(6,1);
floodfill(523, 63,1);
rectangle(510,110,570,120);
///////(computador#3)
setcolor(1);
rectangle(60,300,100,340);
setfillstyle(9,1);
floodfill(63,303,1);
rectangle(50,350,110,360);
////////computador#4
setcolor(1);
rectangle(520,300,560,340);
setfillstyle(5,1);
floodfill(523, 303,1);
rectangle(510,350,570,360);
}




void MOUSE::cuadro(int i,int j,int k,int l)
{

int x,y;
 /* Ubicacion del primer punto */
   gotoxy(i,j);
   printf("%c",201);

 /* Imprime raya horizontal */
 for(x=i+1;x<=k-1;x++)
    printf("%c",205);
 printf("%c",187);

 /* Imprime rayas horizontales */
  for(y=j+1;y<=l-1;y++)
  {
    gotoxy(i,y);
    printf("%c",186);
    gotoxy(k,y);
    printf("%c",186);
  }
 /* Imprime raya horizontal */
 gotoxy(i,l);
   printf("%c",200);
 for(x=i+1;x<=k-1;x++)
    printf("%c",205);
    printf("%c",188);
}



















///getch();



//rectangle(100,50,10,50);
//}
///OBJETOS CREADOS POR LAS CLASES///////////////////////////////////////////
//MOUSE mouse;


//punto uno;


void main()
{
modo();
mouse.Inicializar();mouse.LimVert(40,600);mouse.LimHoriz(50,470);mouse.Mostrar();
while(wo==0)
{mouse.menu();
uno.ventana(40,40,590,380);
uno.ventana(37,37,587,377);
uno.ventana(1,410,630,460);
uno.ventana(1,407,627,457);
wo++;
}
while((boton=mouse.Estado(&Vert, &Horiz))!=DERECHO)
{if(boton==IZQUIERDO&& Vert>=80&&Vert<=490&&Horiz>=420&&Horiz<=460)
  { cleardevice();

uno.ventana(40,40,590,380);
uno.ventana(37,37,587,377);
uno.ventana(1,410,630,460);
uno.ventana(1,407,627,457);
mouse.servidor();
mouse.computadores();
}
if(boton==IZQUIERDO&& Vert>=60&&Vert<=100&&Horiz>=60&&Horiz<=100)
{///COMPUTADORESS//
mouse.conectoruno();
 }

if(boton==IZQUIERDO&& Vert>=520&&Vert<=560&&Horiz>=60&&Horiz<=100)
{///COMPUTADORESS//
mouse.conectordos();
 }

if(boton==IZQUIERDO&& Vert>=60&&Vert<=100&&Horiz>=300&&Horiz<=340)
{///COMPUTADORESS//
mouse.conectortres();
 }

 if(boton==IZQUIERDO&& Vert>=520&&Vert<=560&&Horiz>=300&&Horiz<=340)
{///COMPUTADORESS//
mouse.conectorcuatro();
 }
 //////////////comunicacion de la red////////////////

if(boton==IZQUIERDO&& Vert>=50&&Vert<=110&&Horiz>=110&&Horiz<=120)
{///COMPUTADORESS//
mouse.red1();
 }

if(boton==IZQUIERDO&& Vert>=510&&Vert<=570&&Horiz>=110&&Horiz<=120)
{///COMPUTADORESS//
mouse.red2();
 }

if(boton==IZQUIERDO&& Vert>=50&&Vert<=110&&Horiz>=350&&Horiz<=360)
{///COMPUTADORESS//
mouse.red3();
 }
 if(boton==IZQUIERDO&& Vert>=510&&Vert<=570&&Horiz>=350&&Horiz<=360)
{///COMPUTADORESS//
mouse.red4();
 }

if(boton==IZQUIERDO&& Vert>=500&&Vert<600&&Horiz>=420&&Horiz<=460)
{
 exit(1);
break;
 }







////////////////











    else
    {
     }
     }
closegraph();
};
void modo()
{int gd=DETECT,gm=0;initgraph(&gd,&gm,"c:\\lenguaje\\bgi");}







