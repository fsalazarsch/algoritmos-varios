#include"iostream.h"
#include"conio.h"

  const int jd=20;
  class automovil{
    private:
     char marca[20];
     unsigned long placa;
     int model;
     public:

void lect_dat()
{
      /* window(10,10,40,11);
       textcolor(4);
       textbackground(12);
       cprintf("HERENCIA DE AUTOMOVILES\n");
       */

gotoxy(17,7);cout<<"\nDIGITE LA MARCA:";
gotoxy(17,8);cin>>marca;
gotoxy(17,9);cout<<"\nDIGITE PLACA:";
cin>>placa;
cout<<"\nDIGITE MODELO:";
cin>>model;
}

void escric_dat()
{

gotoxy(17,7);cout<<"\n MARCA:"<<marca;
gotoxy(17,8);cout<<"\n PLACA:"<<placa;
gotoxy(17,9);cout<<"\n MODELO:"<<model;
}
};


class automovil_lujo:public automovil
{
   private:
    char n_dueno[jd];
    char LUGAR[jd];
   public:

void lect_dat()
  {
     automovil::lect_dat();

gotoxy(15,12);cout<<"\nDIGITE NOMBRE  PROPIETARIO:";
cin>>n_dueno;
gotoxy(15,14);cout<<"\nDIGITE DESTINO            :";
cin>>LUGAR;
  }


void escric_dat()
  {
     automovil::escric_dat();

gotoxy(15,10);cout<<"\n PROPIETARIO:"<<n_dueno;
gotoxy(15,11);cout<<"\n DESTINO    :"<< LUGAR;
  }
  };


class automovil_publicos:public automovil
{
    private:
	char n_dueno[jd];
	char LUGAR[jd];
   public:


void lect_dat()
{
    automovil::lect_dat();

gotoxy(15,13);cout<<"DIGITE NOMBRE  PROPIETARIO:";
cin>>n_dueno;
gotoxy(15,15);cout<<"DIGITE DESTINO            :";
cin>>LUGAR;
}


void escric_dat()
{
     automovil::escric_dat();

gotoxy(15,10);cout<<"\n PROPIETARIO:"<<n_dueno;
gotoxy(15,11);cout<<"\n DESTINO    :"<< LUGAR;
}
};


class camiones:public automovil
{
private:
char n_dueno[jd];
char LUGAR[jd];
public:
void lect_dat()
{
    automovil::lect_dat();

       gotoxy(15,13);cout<<"DIGITE NOMBRE  PROPIETARIO:";
       cin>>n_dueno;
       gotoxy(15,15);cout<<"DIGITE LUGAR DESTINO      :";
       cin>>LUGAR;
}
void escric_dat()
{
    automovil::escric_dat();

       gotoxy(15,10);cout<<"\n PROPIETARIO:"<<n_dueno;
       gotoxy(15,11);cout<<"\n DESTINO    :"<< LUGAR;
}

};
void main()
{
clrscr();
    automovil_lujo dc1,dc2;
    automovil_publicos csp1,csp2;
    camiones cam1,cam2;
    textcolor(35);
      gotoxy(15,5);cout<<"\n DIGITE   VEHICULO  DE  LUJO .1";
      dc1.lect_dat();
      gotoxy(15,5);cout<<"\n DIGITE   VEHICULO  DE LUJO .2";
      dc2.lect_dat();
      gotoxy(15,5);cout<<"\n DIGITE DATOS VEHICULO PUBLICO.1";
      csp1.lect_dat();
      gotoxy(15,5);cout<<"\n DIGITE DATOS VEHICULO PUBLICO .2";
      csp2.lect_dat();
      gotoxy(10,5);cout<<"\n DIGITE     INFORMACION        CAMIONES       .1";
      cam1.lect_dat();
      gotoxy(15,5);cout<<"\n DIGITE     INFORMACION        CAMIONES       .2";
      cam2.lect_dat();

  clrscr();

      gotoxy(15,3);cout<<"\n  DATOS     VEHICULO    DE    LUJO    .1";
      dc1.escric_dat();
      getch();
      gotoxy(15,3);cout<<"\n  DATOS     VEHICULO    DE    LUJO    .2";
      dc2.escric_dat();
      getch();
      gotoxy(15,3);cout<<"\n  DATOS VEHICULO  PUBLICO .1";
      csp1.escric_dat();
      getch();
      gotoxy(15,3);cout<<"\n  DATOS VEHICULO  PUBLICO . 2";
      csp2.escric_dat();
      getch();
      gotoxy(15,3);cout<<"\n  DATOS         CAMIONES            .1";
      cam1.escric_dat();
      getch();
      gotoxy(15,3);cout<<"\n  DATOS         CAMIONES            .2";
      cam2.escric_dat();
      getch();




 }






