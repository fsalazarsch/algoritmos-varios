#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdarg.h>

#define IZQUIERDO 1
#define DERECHO 2
#define AMBOSBOTONES 3

int i,por,rpg;

class RATON
{
 int inicializado;
 int desconectado;
 int NBotones;
 public:
	RATON(void);
	~RATON(void);
	int ExisteUnidad(void);
	void inicializar();
	int fini() {return inicializado; }
	int fdes() {return desconectado; }
	int NumBotones() {return NBotones; }
	void Mostrar();
	void Esconder();
	int Estado(int *Vertical, int *Horizontal);
	void Posicionar(int Vert,int Horiz);
	void Botoninfo(int Boton,int *Vert,int *Horiz,int *Estado,int *Veces);
	void BotonLib(int Boton,int *Vert,int *Horiz,int *Estado,int *Veces);
	void LimVert (int x, int x1);
	void LimHoriz (int y, int y1);
	void LibBotones();
	void CambioRaton(int *VErt, int *Horiz);
	void FormaCursor();
	void OprimirBoton();
	void VelocidadRaton(int x, int y);
	void AreaProtegida(int x, int y, int x1, int y1);
	void DoblaVelocidad(int VEloc);
	void VentActual(int *p, int *q, int *r, int *s);
	void Sensitividad(int *p, int *q);
	void RATON::DeterminaSensiti(int Vert, int Horiz);
	void Escribir (int Vert, int Horiz,...);
};

RATON::RATON()
{
 inicializado=0;
 desconectado=1;
}

int RATON::ExisteUnidad(void)
{
 void far *direccion;
 union REGS r;
 direccion=getvect(0x33);
 return(direccion != NULL && *(unsigned char *) direccion != 0xcf);
}

void RATON::inicializar()
{
 union REGS r;
 inicializado = ExisteUnidad();
 if(inicializado)
   {
    r.x.ax = 0x00;
    int86 (0x33, &r, &r);
    NBotones = r.x.bx;
    desconectado = 0;
   }
 else
   desconectado = 1;
}

RATON::~RATON(void) { }

void RATON::Mostrar()
{
 union REGS r;
 r.x.ax = 0x01;
 int86 (0x33,&r,&r);
}

void RATON::Esconder()
{
 union REGS r;
 r.x.ax = 0x02;
 int86 (0x33,&r,&r);
}

int RATON::Estado(int *Vertical,int *Horizontal)
{
 union REGS r;
 r.x.ax = 0x03;
 int86 (0x33,&r,&r);
 *Vertical = r.x.cx;
 *Horizontal= r.x.dx;
 return r.x.bx;
}

void RATON::Posicionar(int Vert, int Horiz)
{
 union REGS r;
 r.x.ax = 0x04;
 r.x.dx = Horiz;
 r.x.cx = Vert;

 int86 (0x33, &r,&r);
}

void RATON::Botoninfo (int Boton, int *Vert, int *Horiz, int *Estado, int *Veces)
{
 union REGS r;
 r.x.ax = 0x05;
 r.x.bx = Boton - 1;
 int86 (0x33, &r,&r);
 *Vert = r.x.cx;
 *Horiz = r.x.dx;
 *Estado = r.h.al;
 *Veces = r.x.bx;
}

void RATON::BotonLib (int Boton, int *Vert, int *Horiz, int *Estado, int *Veces)
{
 union REGS r;
 r.x.ax = 0x06;
 r.x.bx = Boton - 1;
 int86 (0x33, &r,&r);
 *Vert = r.x.cx;
 *Horiz = r.x.dx;
 *Estado = r.h.al;
 *Veces = r.x.bx;
}

void RATON::LimVert(int x, int x1)
{
 union REGS r;
 r.x.ax = 0x07;
 r.x.cx = x;
 r.x.dx = x1;
 int86 (0x33, &r,&r);
}


void RATON::LimHoriz(int y, int y1)
{
 union REGS r;
 r.x.ax = 0x08;
 r.x.cx = y;
 r.x.dx =y1;
 int86 (0x33, &r, &r);
}

void RATON::LibBotones()
{
 int Boton, Vert, Horiz;

 Boton = Estado (&Vert, &Horiz);
 while (Boton !=0)
	Boton = Estado (&Vert, &Horiz);
}

void RATON::CambioRaton (int *Vert, int *Horiz)
{
 union REGS r;
 r.x.ax = 0x0b;
 int86 (0x33, &r, &r);
 *Vert = r.x.cx;
 *Horiz = r.x.dx;
}

int fig[32] = {
0x3ff8, 0x1ff0, 0x0fe1, 0x87c3, 0xc387, 0xe10f, 0xf01f,0xf83f,
0xf83f, 0xf01f, 0xe10f, 0xc387, 0x87c3, 0x0fe1, 0x1ff0,0x3ff8,
0x8003, 0xc006, 0x600c, 0x3018, 0x1830, 0x0c60, 0x06c0,0x0380,
0x0380, 0x06c0, 0x0c60, 0x0830, 0x3018, 0x600c, 0xc006, 0x8003
};

void RATON::FormaCursor()
{
 union REGS r;
 struct SREGS s;
 r.x.ax = 0x09;
 r.x.bx = 7;
 r.x.cx = 7;
 s.es = FP_SEG (fig);
 r.x.dx = FP_OFF (fig);
 int86x (0x33, &r, &r, &s);
}

void RATON::OprimirBoton()
{
 int Vert, Horiz;
 while (Estado (&Vert,&Horiz)==0)
 ;
 LibBotones();
}

void RATON::VelocidadRaton(int x, int y)
{
 union REGS r;
 r.x.ax = 0x0f;
 r.x.cx = x;
 r.x.dx =y;
 int86 (0x33, &r, &r);
}

void RATON::DoblaVelocidad(int Veloc)
{
 union REGS r;
 r.x.ax = 0x13;
 r.x.dx = Veloc;
 int86 (0x33, &r, &r);
}

void RATON::AreaProtegida(int x, int y, int x1, int y1)
{
 union REGS r;
 r.x.ax = 0x10;
 r.x.cx = x;
 r.x.dx = y;
 r.x.si = x1;
 r.x.di = y1;
 int86 (0x33, &r, &r);
}

void RATON::Sensitividad(int *Vert, int *Horiz)
{
 union REGS r;
 r.x.ax = 0x1b;
 int86 (0x33, &r, &r);
 *Vert = r.x.cx;
 *Horiz = r.x.bx;
}

void RATON::DeterminaSensiti(int Vert, int Horiz)
{
 union REGS r;
 r.x.ax = 0x1a;
 int86 (0x33, &r, &r);
 r.x.cx = Vert;
 r.x.bx = Horiz;
}

void RATON::VentActual(int *p, int *q, int *rr, int *s)
{
 union REGS r;
 r.x.ax = 0x31;
 int86 (0x33, &r, &r);
 *p = r.x.bx;
 *q = r.x.ax;
 *rr = r.x.dx;
 *s = r.x.cx;
}

void RATON::Escribir(int Vert, int Horiz,...)
{
 va_list lista;
 char a[10];
 va_start(lista,msg);
 int numero = va_arg(lista, int);
 moveto(Vert,Horiz);
 while(numero != 999)
      {
       itoa(numero,a,10);
       outtext(a);
       outtext(" ");
       numero = va_arg(lista, int);
      }
 va_end (lista);
}

struct x
{
 int x, y;
};

struct x a[10]={8,8,85,8,2,8,1,8,10,8,20,8,30,8,32,32,40,40,50,50};

int main()
{
 int unidad = DETECT, modo,Vert, Horiz,Boton;
 char v[3],*rpg;
 RATON raton;
 raton.inicializar();
 initgraph(&unidad,&modo,"c;\\bc\\bgi");
 if(graphresult() != 0)
   {
    cout<<"ERROR...\n";
    getch();
    return 1;
}

cleardevice();
for(i=1;i<=10;i++)
   {
    cleardevice();
    por = i*10;
    rpg= itoa(por,v,10);
    outtextxy(100,200,"Cargando ");
    outtextxy(290,200,rpg);
    outtextxy(320,200,"%");
    rectangle(70,220,568,250);
    bar(70,220,(168 + (i *40)),250);
    delay(200);
   }
/*rectangle(10,8,632,470);*/
outtextxy(16,400,"<Use Cualquier Tecla  Haga clic con el boton derecho del raton>");
/*settextstyle(0,0,2);*/
/*outtextxy(40,50,"Implementaci¢n del Raton");*/
outtextxy(70,100,"EUCARDO PE¥ALOZA");
getch();
raton.Mostrar();
int i = 0;
raton.VelocidadRaton(a[i].x,a[i].y);
i++;
Boton = -1;
while (Boton != DERECHO && i < 10)
{
 Boton = raton.Estado(&Vert, &Horiz);
 if(Boton == IZQUIERDO)
 {
  raton.VelocidadRaton(a[i].x,a[i].y);
  i++;
  raton.LibBotones();
 }
}
closegraph();
return 0;
}