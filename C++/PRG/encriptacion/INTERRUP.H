union REGS inreg,outreg;
#define llamada_raton int86(0x33,&inreg,&outreg);

struct posicMouse
{
 int x1;
 int y1;
 int contador_boton;
 int estado;
 int color;
}mouse;




typedef struct
{
 unsigned int
 mascarapantalla[16],mascaracursor[16],
 xcor,ycor;
}g_cursor;



static g_cursor guante =
{
 0xF3FF, 0xE1FF, 0xE1FF, 0xE1FF,
 0xE1FF, 0xE049, 0xE000, 0x8000,
 0x0000, 0x0000, 0x07FC, 0x07F8,
 0x9FF9, 0x8FF1, 0xC003, 0xE007,

 0x0C00, 0x1200, 0x1200, 0x1200,
 0x1200, 0x13B6, 0x1249, 0x7249,
 0x9249, 0x9001, 0x9001, 0x8001,
 0x4002, 0x4002, 0x2004, 0x1FF8,
 4,      0
};



static g_cursor cruz =
{
 0xF01F, 0xE00F, 0xC007, 0x8003,
 0x0441, 0x0C61, 0x0381, 0x0381,
 0x0381, 0x0C61, 0x0441, 0x8003,
 0xC007, 0xE007, 0xF01F, 0xFFFF,

 0x0000, 0x07C0, 0x0920, 0x1110,
 0x2108, 0x4004, 0x4004, 0x783C,
 0x4004, 0x4004, 0x2108, 0x1110,
 0x0920, 0x07C0, 0x0000, 0x0000,
 7, 7
};


static g_cursor FLECHA = {
		{0x1FFF, 0x0FFF, 0x07FF, 0x03FF,    // Mascara de la
		0x01FF, 0x00FF, 0x007F, 0x003F,	    // Pantalla
		0x001F, 0x003F, 0x01FF, 0x01FF,
		0xE0FF, 0xF0FF, 0xF8FF, 0xF8FF},

		{0x0000, 0x4000, 0x6000, 0x7000,    // Mascara del Cursor
		0x7800, 0x7C00, 0x7E00, 0x7F00,
		0x7F80, 0x7C00, 0x4C00, 0x0600,
		0x0600, 0x0300, 0x0300, 0x0000},
		1,1 };                              // xcor, ycor

static g_cursor MARCA = {
		0xFFF0, 0xFFE0, 0xFFC0, 0xFF81,
		0xFF03, 0x0607, 0x000F, 0x001F,
		0x803F, 0xC07F, 0xE0FF, 0xF1FF,
		0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,

		0x0000, 0x0006, 0x000C, 0x0018,
		0x0030, 0x0060, 0x70C0, 0x3980,
		0x1F00, 0x0E00, 0x0400, 0x0000,
		0x0000, 0x0000, 0x0000, 0x0000,
		5,10 };


static g_cursor VIGA = {
		0xF3FF, 0xE1FF, 0xE1FF, 0xE1FF,
		0xE1FF, 0xE049, 0xE000, 0x8000,
		0x0000, 0x0000, 0x07FC, 0x07F8,
		0x9FF9, 0x8FF1, 0xC003, 0xE007,

		0x0C30, 0x0240, 0x0180, 0x0180,
		0x0180, 0x0180, 0x0180, 0x0180,
		0x0180, 0x0180, 0x0180, 0x0180,
		0x0180, 0x0180, 0x0240, 0x0C30,
		7,7 };



 void inicializa(void)
  {
     int gdriver, gmode,errorcode;
      gdriver=DETECT;
      initgraph(&gdriver,&gmode,"");
      errorcode=graphresult();
      if(errorcode!=grOk)
	{
	 printf("error de grafica:%s\n",grapherrormsg(errorcode));
	 printf("presione una tecla para seguir...");
	 exit(1);
	}
 }





 void rlimite(int min_1,int max_1,int servicio)
 {
  inreg.x.ax=servicio;
  inreg.x.cx=min_1;
  inreg.x.dx=max_1;
  llamada_raton;
 }


 void rmuestra(int servicio)
 {
  inreg.x.ax=servicio;
  llamada_raton;
 }



 void pon_Cursor2(int ejex, int ejey, unsigned Seg_mascara,
		unsigned Desp_mascara)
{
 struct SREGS seg;

 inreg.x.ax=9;
 inreg.x.bx=ejex;				// Coords. del punto de mira
 inreg.x.cx=ejey;
 inreg.x.dx=Desp_mascara;
 seg.es=Seg_mascara;
 int86x(0x33, &inreg, &outreg, &seg);
}


 void Pon_Cursor(g_cursor EsteCursor)
{
 pon_Cursor2(EsteCursor.xcor, EsteCursor.ycor, _DS,
	(unsigned)EsteCursor.mascarapantalla);
}





  void r_posicM(unsigned int servicio)
     {
      inreg.x.ax=servicio;
      llamada_raton;
      mouse.x1=outreg.x.cx;
      mouse.y1=outreg.x.dx;
      mouse.estado=outreg.x.bx;
     }


  void r_situaM(int ejex,int ejey)
  {
   inreg.x.ax=4;
   inreg.x.cx=ejex;
   inreg.x.dx=ejey;
   llamada_raton;
  }

  void r_pulsadoM(int boton,int servicio)
  {
   inreg.x.ax=servicio;
   inreg.x.bx=boton;
   llamada_raton;
   mouse.estado=outreg.x.ax;
   mouse.contador_boton=outreg.x.bx;
   mouse.x1=outreg.x.cx;
   mouse.y1=outreg.x.dx;
  }







 void reset_mouse(void)
 {
  inreg.x.ax=0;
  llamada_raton;
  mouse.estado=outreg.x.ax;
  mouse.contador_boton=outreg.x.bx;
 }




  void muestramouse(int servicio)
 {
  inreg.x.ax=servicio;
  llamada_raton;
 }





 void limite(int min, int max,int t_intr)
 {
  struct REGPACK reg;
  reg.r_ax=t_intr;
  reg.r_cx=min;
  reg.r_dx=max;
  intr(0x33,&reg);
 }
