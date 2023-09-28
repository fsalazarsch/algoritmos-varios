#include"iostream.h"
#include"conio.h"
const int lon=20;
class carros{
private:
char marca[20];
unsigned long placa;
int modelo,i,j;
public:
void leerdato()
{
textcolor(4);
gotoxy(12,7);cout<<"\nIntroduzca la marca:";
cin>>marca;
gotoxy(12,8);cout<<"\nIntroduzca placa:";
cin>>placa;
gotoxy(12,9);cout<<"\nIntroduzca modelo:";
cin>>modelo;clrscr();
}
void escribirdato()
{
gotoxy(29,7);cout<<"\n marca:"<<marca;
gotoxy(29,8);cout<<"\n placa:"<<placa;
gotoxy(29,9);cout<<"\n modelo:"<< modelo;
}

};

class carros_lujo:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(12,10);cout<<"\nIntroduzca nombre del comprador:";
cin>>comprador;clrscr();
gotoxy(12,11);cout<<"\nIntroduzca Destino:";
cin>>destino;

}
void escribirdato()
{
carros::escribirdato();

gotoxy(29,10);cout<<"\n comprador:"<<comprador;
gotoxy(29,11);cout<<"\n destino:"<< destino;

}
};
class carros_servpublico:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(12,10);cout<<"Introduzca nombre del comprador:";
;cin>>comprador;clrscr();
gotoxy(12,11);cout<<"Introduzca destino de viaje :";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();

gotoxy(29,10);cout<<"\n comprador:"<<comprador;
gotoxy(29,11);cout<<"\n destino:"<< destino;

}
};
class camiones:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(12,11);cout<<"Introduzca nombre del comprador:";
cin>>comprador;clrscr();
gotoxy(12,12);cout<<"Introduzca empresa constructora compradora :";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();

gotoxy(29,10);cout<<"\n comprador:"<<comprador;
gotoxy(29,11);cout<<"\n destino:"<< destino;

}

};

void main()
{
clrscr();
carros_lujo cl1,cl2;
carros_servpublico csp1,csp2;
camiones cam1,cam2;
textcolor(35);
gotoxy(12,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJOSOS .1";
cl1.leerdato();
gotoxy(12,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJOSOS .2";
cl2.leerdato();
gotoxy(12,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO.1";
csp1.leerdato();
gotoxy(12,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO .2";
csp2.leerdato();
gotoxy(12,5);cout<<"\n INTRODUZCA      DATOS        CARGA PESADA       .1";
cam1.leerdato();
gotoxy(12,5);cout<<"\n INTRODUZCA      DATOS        CARGA PESADA       .2";
cam2.leerdato();
//***************pantalla****************//
clrscr();
gotoxy(12,3);cout<<"\n  DATOS     CARROS    DE    LUJOSOS    .1";
cl1.escribirdato();
getch();
gotoxy(12,3);cout<<"\n  DATOS     CARROS    DE    LUJOSOS    .2";
cl2.escribirdato();
getch();
gotoxy(12,3);cout<<"\n  DATOS CARROS DE  SERVICIO PUBLICO .1";
csp1.escribirdato();
getch();
gotoxy(12,3);cout<<"\n  DATOS CARROS DE SERVICIO PUBLICO . 2";
csp2.escribirdato();
getch();
gotoxy(12,3);cout<<"\n  DATOS         CARGA PESADA           .1";
cam1.escribirdato();
getch();
gotoxy(12,3);cout<<"\n  DATOS         CARGA PESADA            .2";
cam2.escribirdato();
getch();
}