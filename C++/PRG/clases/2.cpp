#include"iostream.h"
#include"conio.h"
void cuadro(int x1,int x2,int y1,int y2) ;
const int lon=20;
class automovil{
private:
char marcacarro[20];
unsigned long numero;
int clase;
public:
void capturadatos()
{

cout<<"\nIntroduzca la marca=====>";
cin>>marcacarro;
cout<<"\nIntroduzca placa=====>";
cin>>numero;
cout<<"\nIn
troduzca modelo=====>";
cin>>clase;
}
void imprimirdatos()
{

gotoxy(5,7);cout<<"\n marca:"<<marcacarro;
gotoxy(5,8);cout<<"\n placa:"<<numero;
gotoxy(5,9);cout<<"\n modelo:"<< clase;
}
};
void cuadro(int x1,int x2,int y1,int y2)
{
  int j,i,k;
     for(j=x1;j<=x2;j++)
       {textcolor(14);
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");

       }
     for(i=y1;i<=y2-1;i++)
       {
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
}


class carros_caros:public automovil
{
private:
char comp[lon];
char lugar[lon];
public:
void capturadatos()
{
automovil::capturadatos();
gotoxy(5,12);cout<<"\nIntroduzca nombre del comprador:";
cin>>comp;
gotoxy(5,14);cout<<"\nIntroduzca Destino:";
cin>>lugar;
}
void imprimirdatos()
{
automovil::imprimirdatos();
gotoxy(5,10);cout<<"\n comprador:"<<comp;
gotoxy(5,11);cout<<"\n destino:"<< lugar;
}
};
class carros_servicio:public automovil
{
private:
char comp[lon];
char lugar[lon];
public:
void capturadatos()
{
automovil::capturadatos();
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comp;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>lugar;
}
void imprimirdatos()
{
automovil::imprimirdatos();

gotoxy(5,10);cout<<"\n comprador:"<<comp;
gotoxy(5,11);cout<<"\n destino:"<< lugar;
}
};
class camiones:public automovil
{
private:
char comp[lon];
char lugar[lon];
public:
void capturadatos()
{
automovil::capturadatos();
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comp;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>lugar;
}
void imprimirdatos()
{
automovil::imprimirdatos();

gotoxy(5,10);cout<<"\n comprador:"<<comp;
gotoxy(5,11);cout<<"\n destino:"<< lugar;
}

};
void main()
{
clrscr();
carros_caros cl1,cl2;
carros_servicio csp1,csp2;
camiones cam1,cam2;



gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE CARRERA .1";
cl1.capturadatos();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE CARRERA .2";
cl2.capturadatos();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO.1";
csp1.capturadatos();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO .2";
csp2.capturadatos();
gotoxy(5,5);cout<<"\n INTRODUZCA  DATOS  CARGA  .1";
cam1.capturadatos();
gotoxy(5,5);cout<<"\n INTRODUZCA  DATOS   CARGA .2";
cam2.capturadatos();
//***************pantalla****************//
clrscr();
cuadro(5,46,2,4);
gotoxy(7,3);cout<<"  DATOS     CARROS    DE    LUJO    .1";
cl1.imprimirdatos();
getch();
gotoxy(7,3);cout<<"  DATOS     CARROS    DE    LUJO    .2";
cl2.imprimirdatos();
getch();
gotoxy(7,3);cout<<"  DATOS CARROS DE  SERVICIO PUBLICO .1";
csp1.imprimirdatos();
getch();
gotoxy(7,3);cout<<"  DATOS CARROS DE SERVICIO PUBLICO . 2";
csp2.imprimirdatos();
getch();
gotoxy(7,3);cout<<"  DATOS         CAMIONES            .1";
cam1.imprimirdatos();
getch();
gotoxy(7,3);cout<<"  DATOS         CAMIONES            .2";
cam2.imprimirdatos();
getch();
}