# include "iostream.h"
# include "conio.h"
# include"dos.h"
# include"string.h"
# include"iomanip.h"
#include"ctype.h"
class  sali{

   char nom[20],ape[20],deta[30];
   int n_fac,cantidad,va_uni,valor,total;

    public:
    sali(void);//constructor
     void captura();
     void imprimir();
  ~sali(void);//destructor
   };
    int i;
    void limites(int ,int ,int, int,int,int);
    sali::sali(void)
    {
    strcpy(nom,"noname ");
    strcpy(ape,"noname ");
    n_fac=0;
    cantidad=999;
    va_uni=999;
    strcpy(deta,"ninguno ");
    valor=999;
    total=0;
    }
    void sali::captura()
    {
      char res,salir;
      int i=8;
       res='S';
       while(res=='S')
       {
	clrscr();
	limites(1,80,1,24,4,7);
	n_fac=n_fac+1;
	gotoxy(10,4);cout<<"Nombre  : ";
       gotoxy(10,5);cout<<"Apellido: ";
       gotoxy(40,3);cout<<"Numero de Factura: "<<n_fac;
       gotoxy(3,7);cout<<"Cantidad "<<"      DETALLE      "<<"       V. Unitario      "<<"    VALOR   ";
       gotoxy(20,4);cin>>nom;gotoxy(20,5);cin>>ape;
	while(res=='S')
	{
	 gotoxy(40,19);cout<<"TOTAL =="<<setprecision (7)<<total;
	 gotoxy(4,i);cin>>cantidad;
	 gotoxy(16,i);cin>>deta;
	 gotoxy(43,i);cin>>va_uni;
	 valor=cantidad*va_uni;gotoxy(60,i);cout<<setprecision(8)<<valor;
	 total=(total+valor);gotoxy(48,19);cout<<setprecision(6)<<total;
	 gotoxy(10,22);cout<<"Desea Comprar Otro articulo [S/N]    ";
	 gotoxy(49,22);cin>>res;res=toupper(res);
	 gotoxy(10,22);cout<<"                                              ";
	 i=i+1;
	}
       }
      clrscr();
     }
     void sali::imprimir()
     {
      int i;
      i=8;
       clrscr();
	limites(1,80,1,24,9,4);
	gotoxy(10,4);cout<<"Nombre  : ";
       gotoxy(10,5);cout<<"Apellido: ";
       gotoxy(40,3);cout<<"Numero de Factura: "<<n_fac;
       gotoxy(3,7);cout<<"Cantidad "<<"      DETALLE      "<<"       V. Unitario      "<<"    VALOR   ";
       gotoxy(20,4);cout<<nom;gotoxy(20,5);cout<<ape;
       gotoxy(4,i);cout<<cantidad;
       gotoxy(16,i);cout<<deta;
       gotoxy(43,i);cout<<setprecision(8)<<valor;
       gotoxy(48,19);cout<<"Total==>"<<setprecision(6)<<total;
	 i=i+1;
       getch();
     }
      sali::~sali(void)
      {
      strcpy(nom," ");
      strcpy(ape," ");
      n_fac=0;
      va_uni=0;
      strcpy(deta," ");
      total=0;
      valor=0;
      cantidad=0;
      }

void limites(int y,int y1,int x,int x1,int col,int fon)
{
 int co,fi;
 textcolor(col);
 textbackground(fon);
 _setcursortype(_NOCURSOR);
  for(co=y;co<=y1;co++)
    {
     gotoxy(co,x);cprintf("Í");
     gotoxy(co,x1);cprintf("Í");
     }
   for(fi=x;fi<=x1;fi++)
     {
      gotoxy(y,fi);cprintf("º");
      gotoxy(y1,fi);cprintf("º");
     }
  gotoxy(y,x);cprintf("É");
  gotoxy(y,x1);cprintf("È");
  gotoxy(y1,x);cprintf("»");
  gotoxy(y1,x1);cprintf("¼");
  normvideo();
  _setcursortype(_NORMALCURSOR);
}

   main()
      {
       clrscr();
       sali  empleado;
       empleado.captura();
       empleado.imprimir();
return 0;
}