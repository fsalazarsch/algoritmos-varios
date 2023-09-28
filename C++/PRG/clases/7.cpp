#include"iostream.h"
#include"stdio.h"
#include"conio.h"
const int lon=20;

class toyota{ //una
	       private:
	       char marca[20];
	       char placa[20];
	       long modelo;
	 public:
void ventana(int X1,int Y1,int X2,int Y2);
void menu();
void panta();
void menu1();
char op;
/***************************************************************/
void leerdato()
{
textcolor(0);
textbackground(3);
gotoxy(10,8);
cprintf("ln\Introduzca la marca:  ");
cin>>marca;
gotoxy(10,10);
cprintf("ln\Introduzca la placa del carro :  ");
cin>>placa;
gotoxy(10,12);
cprintf("ln\Introduzca el modelo del carro:  ");
cin>>modelo;
}
/**********************************************************/
void escribirdato()
{
gotoxy(10,8);
cout<<"MARCA :  "<<marca<<endl;
gotoxy(10,10);
cout<<"PLACA :  "<<placa<<endl;
gotoxy(10,12);
cout<<"MODELO : "<<modelo<<endl;
getch();
}
};
/*************************************************************/
class vmw:public toyota//segunda
 {
   private:
    char year[lon];
    char fabrica[lon];
   public:
    void leerdato()
{
toyota::leerdato();
textcolor(0);
gotoxy(10,14);
cout<<"Introduzca el a¤o de salida:  ";
cin>>year;
gotoxy(10,16);
cout<<"Introduzca el nombre de la fabrica:  ";
cin>>fabrica;
}
void escribirdato()
{
toyota::escribirdato();
cout<<"\n year:"<<year;
cout<<"\n fabrica:"<< fabrica;
}
};
/*************************************************************/
class mazda:public toyota//tres
  {
  };
class mercedes_ven:public toyota
{
};
/************************************************************/
  void main()
{
clrscr();
toyota objeto,objeto2;
objeto.menu();

}

/**************************************************************/
void toyota::ventana(int X1,int Y1,int X2,int Y2)
{    int i;
 for(i=X1+1;i<X2;i++){
 gotoxy(i,Y1);cout<<"Í";   // LINEA ARRIBA HORIZONTAL
 gotoxy(i,Y2);cout<<"Í";}  // LINEA ABAJO HORIZONTAL
 for(i=Y1+1;i<Y2;i++){
 gotoxy(X1,i);cout<<"º";    // LINEA IZQUIERDA VERTICAL
 gotoxy(X2,i);cout<<"º";}   // LINEA DERECHA VERTICAL
 gotoxy(X1,Y1);cout<<"É";
 gotoxy(X1,Y2); cout<<"È";
 gotoxy(X2,Y1);cout<<"»";
 gotoxy(X2,Y2); cout<<"¼";
}
/*****************************************************************/
void toyota::menu()
{ do
  { clrscr();
    panta();
    ventana(28,6,54,18);
    gotoxy(30,8); printf("<<MENU LEE DATOS>>");
    gotoxy(30,10); printf("1.DATOS VMW 1");
    gotoxy(30,11); printf("2.DATOS VMW 2");
    gotoxy(30,12); printf("3.DATOS MAZDA 1");
    gotoxy(30,13); printf("4.DATOS MAZDA 2");
    gotoxy(30,14); printf("5.DATOS MERCEDES 1");
    gotoxy(30,15); printf("6.DATOS MERCEDES 2");
    gotoxy(30,16); printf("7.MENU VISUALIZAR");
    gotoxy(30,17); printf("8. SALIR");
    gotoxy(30,20); printf("Digite su opcion: ");
	 do{ gotoxy(48,20);  op=getche();
		}while(op<'1'||op>'8');
    switch(op)
	      {

	      case '1':{ vmw a1;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL VMW 1";
			 a1.leerdato(); break;
			}
		case '2':{vmw a2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL VMW 2";
			 a2.leerdato(); break;
			 }
		case '3':{mazda p1;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL MAZDA 1";
			 p1.leerdato(); break;}
		case '4':{mazda p2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL MAZDA 2";
			 p2.leerdato(); break;}
		case '5':{mercedes_ven auxi1;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL MERCEDES 1";
			 auxi1.leerdato();break;}
		case '6':{mercedes_ven auxi2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"INTRODUZCA DATOS DEL MERCEDES 2";
			 auxi2.leerdato();  break;}
		case '7':{ toyota objeto2;
			   objeto2.menu1();
			  break;}
	       }
  }while(op!='8');
}
/*****************************************************************/
void toyota::menu1()
{ do
  { clrscr();
    panta();
    ventana(28,6,55,18);
    gotoxy(30,8); printf("<<MENU VISUALIZA DATOS>>");
    gotoxy(30,10); printf("1.DATOS VMW 1");
    gotoxy(30,11); printf("2.DATOS VMW 2");
    gotoxy(30,12); printf("3.DATOS MAZDA 1");
    gotoxy(30,13); printf("4.DATOS MAZDA 2");
    gotoxy(30,14); printf("5.DATOS MERCEDES 1");
    gotoxy(30,15); printf("6.DATOS MERCEDES 2");
    gotoxy(30,16); printf("7.IR AL MENU LEER DATOS");
    gotoxy(30,17); printf("8. SALIR");
    gotoxy(30,20); printf("Digite su opcion: ");
	 do{ gotoxy(48,20);  op=getche();
		}while(op<'1'||op>'8');
    switch(op)
	      {

	      case '1':{ vmw a1;
			clrscr();
			ventana(1,2,79,25);
			gotoxy(30,4);cout<<"DATOS PARTICULARES DE VMW 1";
			a1.escribirdato(); break;
			}
		case '2':{vmw a2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"DATOS PARTICULARES DE VMW 2";
			 a2.escribirdato(); break;
			 }
		case '3':{mazda p1;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"DATOS PARTICULARES DE MAZDA 1";
			 p1.escribirdato(); break;}
		case '4':{mazda p2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"DATOS PARTICULARES DE MAZDA 2";
			 p2.escribirdato(); break;}
		case '5':{mercedes_ven auxi1;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"DATOS PARTICULARES DE MERCEDES 1";
			 auxi1.escribirdato();break;}
		case '6':{mercedes_ven auxi2;
			 clrscr();
			 ventana(1,2,79,25);
			 gotoxy(30,4);cout<<"DATOS PARTICULARES DE MERCEDES 2";
			 auxi2.escribirdato();  break;}
		case '7':{toyota objeto;
			  clrscr();
			  objeto.menu(); break;
			 }
	       }
  }while(op!='8');
}
/**********************************************************************************/
void toyota::panta()
{
 textcolor(13);
 ventana(20,3,60,22);
 ventana(15,2,65,24);
 ventana(10,1,70,25);
 textcolor(9);
}


/****************************************************************/






