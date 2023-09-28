# include <iostream.h>
# include <conio.h>
class autos{
private:
char marca[15];
char color[15];
char cap[15];
int  nllantas;
int  placa;
public:
void leerdato()
{
 textcolor(15);textbackground(4);
 gotoxy(10,5); cout<<"INTRODUZCA LA MARCA        :";
 gotoxy(10,6); cout<<"INTRODUZCA EL COLOR        :";
 gotoxy(10,7); cout<<"INTRODUZCA LA CAPACIDAD    :";
 gotoxy(10,8); cout<<"INTRODUZCA EL # DE PLACA   :";
 gotoxy(10,9); cout<<"INTRODUZCA EL # DE LLANTAS :";
 gotoxy(40,5);cin>>marca;
 gotoxy(40,6);cin>>color;
 gotoxy(40,7);cin>>cap;
 gotoxy(40,8);cin>>placa;
 gotoxy(40,9);cin>>nllantas;
 getch();
}
void escribirdato()
{
 gotoxy(10,5);cout<<"MARCA";
 gotoxy(10,6);cout<<"COLOR";
 gotoxy(10,7);cout<<"CAPACIDAD";
 gotoxy(10,8);cout<<"# DE PLACAS";
 gotoxy(10,9);cout<<"# DE LLANTAS";
 gotoxy(40,5);cout<<marca;
 gotoxy(40,6);cout<<color;
 gotoxy(40,7);cout<<cap;
 gotoxy(40,8);cout<<placa;
 gotoxy(40,9);cout<<nllantas;
 getch();
}
};
class automoviles:public autos
{
 private:
 char garan[10];
 char concesionario[20];
 public:
 void leerdato()
 {
  clrscr();
  autos::leerdato();
  gotoxy(20,3);cout<<"INTRODUZCA DATOS DEL AUTOMOVIL";
  gotoxy(10,10);cout<<"INTRODUZCA LA GARANTIA      :";
  gotoxy(10,11);cout<<"INTRODUZCA EL CONSECIONARIO :";
  gotoxy(40,10);cin>>garan;
  gotoxy(40,11);cin>>concesionario;
 }
 void escribirdato()
 {
  clrscr();
  autos::escribirdato();
  gotoxy(20,3);cout<<"VISUALICE DATOS AUTOMOVIL";
  gotoxy(10,10);cout<<"GARANTIA";
  gotoxy(10,11);cout<<"CONSECIONARIO";
  gotoxy(40,10);cout<<garan;
  gotoxy(40,11);cout<<concesionario;
  getch();
 }
 };
 class tractomulas:public autos
 {
  private:
  int modelo;
  char utilizacion[30];
  public:
  void leerdato()
  {
   clrscr();
   autos::leerdato();
   gotoxy(20,3);cout<<"INTRODUZCA DATOS DE TRACTOMULAS";
   gotoxy(10,10);cout<<"INTRODUZCA EL MODELO       :";
   gotoxy(10,11);cout<<"INTRODUZCA LA UTILIZACION  :";
   gotoxy(40,10);cin>>modelo;
   gotoxy(40,11);cin>>utilizacion;
  }
  void escribirdato()
 {
  clrscr();
  autos::escribirdato();
  gotoxy(20,3);cout<<"VISUALICE DATOS DE TRACTOMULAS";
  gotoxy(10,10);cout<<"MODELO:";
  gotoxy(10,11);cout<<"UTILIZACION:";
  gotoxy(40,10);cout<<modelo;
  gotoxy(40,11);cout<<utilizacion;
  getch();
 }
};
class carreras:public autos
{
 private:
 int kilometraje;
 char patrocinador[20];
 public:
 void leerdato()
 {
  clrscr();
  autos::leerdato();
  gotoxy(20,3);cout<<"INTRODUZCA DATOS DE AUTOS DE CARRERA";
  gotoxy(10,10);cout<<"INTRODUZCA EL KILOMETRAJE           :";
  gotoxy(10,11);cout<<"INTRODUZA PATROCINADOR DE CARRERAS  :";
  gotoxy(50,10);cin>>kilometraje;
  gotoxy(50,11);cin>>patrocinador;
 }
 void escribirdato()
 {
  clrscr();
  autos::escribirdato();
  gotoxy(20,3);cout<<"VISULICE DATOS AUTOS DE CARRERA";
  gotoxy(10,10);cout<<"KILOMETRAJE";
  gotoxy(10,11);cout<<"PATROCINADOR";
  gotoxy(40,10);cout<<kilometraje;
  gotoxy(40,11);cout<<patrocinador;
  getch();
 }
};
 void main()
 {
  clrscr();
  textcolor(15);textbackground(4);
  automoviles a1;
  tractomulas t1;
  carreras    c1;
  a1.leerdato();
  t1.leerdato();
  c1.leerdato();
  a1.escribirdato();
  t1.escribirdato();
  c1.escribirdato();
  getch();
}
