# include <IOSTREAM.H>
# include <CONIO.H>
# include <DOS.H>
# include <TIME.H>
# include <STDIO.H>
# include <STDLIB.H>
# include <STRING.H>
#include <GRAPHICS.H>
#define  color(x,y) textcolor(x);textbackground(y)
void CUADROS();
void ENTER();
main()
{
//textbackground(0);
//textcolor(15);
color(15,0);
clrscr();
CUADROS();
 gotoxy(35,10);textcolor(WHITE);cprintf("BIENVENIDO");
 gotoxy(24,12);textcolor(WHITE);cprintf("PARA COMENZAR PRECIONE <<ENTER>>");
 _setcursortype(_NOCURSOR);
 ENTER();
}

void CUADROS()
{
int I,J;
gotoxy(5,24);textcolor(WHITE);cprintf("INICIO");
 for(I=3;I<=78;I++)
 {
  gotoxy(I,2); cprintf("Í");
 gotoxy(I,23); cout <<"Í";
 gotoxy(I,25); cout <<"Í";
 }

for(J=2;J<=25;J++)
 {
 gotoxy(13,24); cout <<"º";
 gotoxy(13,23); cout <<"»";
 gotoxy(13,25); cout <<"¼";
 gotoxy(2,2); cout <<"É";
 gotoxy(2,J); cout <<"º";
 gotoxy(2,25); cout <<"È";
 gotoxy(78,2); cout <<"»";
 gotoxy(78,J); cout <<"º";
 gotoxy(78,25); cout <<"¼";
 gotoxy(11,24); cout <<"³";
 gotoxy(4,24); cout <<"³";

 }
}
void ENTER()
{
  int x,y;
  char tecla;
  tecla=getch();
  clrscr();
  CUADROS();
  if(tecla==13)  {
    for(x=22;x>7;x--)
    {
    gotoxy(3,x); cout <<"º";
    gotoxy(21,x); cout <<"º";
    gotoxy(21,23); cout <<"¼";
    gotoxy(3,23); cout <<"È";
    delay(50);
   }

for(y=4;y<=20;y++)
  {
  gotoxy(y,7); cout <<"Í";
  gotoxy(3,7); cout <<"É";
  gotoxy(21,7); cout <<"»";
  }
}
gotoxy(7,8);textcolor(WHITE);cprintf("PRIMERO¯¯¯¯¯");
gotoxy(7,9);textcolor(WHITE);cprintf("SEGUNDO¯¯¯¯¯");
gotoxy(7,10);textcolor(WHITE);cprintf("TERCERO¯¯¯¯¯");
gotoxy(7,11);textcolor(WHITE);cprintf("CUARTOS¯¯¯¯¯");
gotoxy(7,12);textcolor(WHITE);cprintf("QUINTOS¯¯¯¯¯");
gotoxy(7,13);textcolor(WHITE);cprintf("SEXTOS¯¯¯¯¯¯");
gotoxy(7,14);textcolor(WHITE);cprintf("SEPTIMO¯¯¯¯¯");
gotoxy(7,15);textcolor(WHITE);cprintf("OCTAVOS¯¯¯¯¯");
gotoxy(7,16);textcolor(WHITE);cprintf("NOVENOS¯¯¯¯¯");
gotoxy(7,17);textcolor(WHITE);cprintf("DECIMOS¯¯¯¯¯");
gotoxy(7,18);textcolor(WHITE);cprintf("JUEGOS¯¯¯¯¯¯");
gotoxy(7,19);textcolor(WHITE);cprintf("CLASES¯¯¯¯¯¯");
gotoxy(7,20);textcolor(WHITE);cprintf("TECLAS¯¯¯¯¯¯");
gotoxy(7,21);textcolor(WHITE);cprintf("RATONES¯¯¯¯¯");
gotoxy(7,22);textcolor(WHITE);cprintf("PUERTOS¯¯¯¯¯");

	 textbackground(BLACK);
	 gotoxy(5,22);textcolor(RED);cprintf("");
	 textbackground(GREEN);
	 textcolor(BLACK);
	 gotoxy(7,22);cprintf("PUERTOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE); //coloca las letras rojas
	 gotoxy(7,21); cprintf("RATONES¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,20); cprintf("TECLAS¯¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,19); cprintf("CLASES¯¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,18); cprintf("JUEGOS¯¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE); //coloca las letras rojas
	 gotoxy(7,17); cprintf("DECIMOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,16); cprintf("NOVENOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,15); cprintf("OCTAVOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,14); cprintf("SEPTIMO¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,13); cprintf("SEXTOS¯¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE); //coloca las letras rojas
	 gotoxy(7,12); cprintf("QUINTOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,11); cprintf("CUARTOS¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,10); cprintf("TERCERO¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE);  //coloca las letras rojas
	 gotoxy(7,9); cprintf("SEGUNDO¯¯¯¯¯");

	 textbackground(BLACK);
	 textcolor(BLUE); //coloca las letras rojas
	 gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");

	 gotoxy(7,22);


  do{  tecla=getch();
      if (tecla==72)  // pregunta por la tecla de arriba
	   {
	    if(wherey()==22 && wherex()==7)
	       {
		 gotoxy(5,22);cout<<" ";
		textbackground(BLACK);


		textcolor(BLUE);
		gotoxy(7,22); cprintf("PUERTOS¯¯¯¯¯");
		gotoxy(5,21);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);
		gotoxy(7,21); cprintf("RATONES¯¯¯¯¯");
		gotoxy(7,21);
	       }

	      else if(wherey()==21 && wherex()==7)
	       {
		   gotoxy(5,21);cout<<"  ";
		  textbackground(BLACK);  // coloca el fondo blanco para 12
		  textcolor(BLUE);         // coloca las letras rojas para 12
		  gotoxy(7,21); cprintf("RATOSES¯¯¯¯¯");
		  gotoxy(5,20);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 10
		  textcolor(BLACK);        // coloca las letras negras para 10
		  gotoxy(7,20); cprintf("TECLAS¯¯¯¯¯¯");
		  gotoxy(7,19);

	       }


	     else  if(wherey()==19 && wherex()==7)
		 {
		   gotoxy(5,20);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,20); cprintf("TECLAS¯¯¯¯¯¯");
		  gotoxy(5,19);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,19); cprintf("CLASES¯¯¯¯¯¯");
		  gotoxy(7,18);

		 }
	       else  if(wherey()==18 && wherex()==7)
		 {
		 gotoxy(5,19);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,19); cprintf("CLASES¯¯¯¯¯¯");
		  gotoxy(5,18);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,18); cprintf("JUEGOS¯¯¯¯¯¯");
		  gotoxy(7,17);
		 }
	      else  if(wherey()==17 && wherex()==7)
		 {
		 gotoxy(5,18);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,18); cprintf("JUEGOS¯¯¯¯¯¯");
		  gotoxy(5,17);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,17); cprintf("DECIMOS¯¯¯¯¯");
		  gotoxy(7,16);
		 }
		else  if(wherey()==16 && wherex()==7)
		 {
		 gotoxy(5,17);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,17); cprintf("DECIMOS¯¯¯¯¯");
		  gotoxy(5,16);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,16); cprintf("NOVENOS¯¯¯¯¯");
		  gotoxy(7,15);
		 }
		else  if(wherey()==15 && wherex()==7)
		 {
		 gotoxy(5,16);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,16); cprintf("NOVENOS¯¯¯¯¯");
		  gotoxy(5,15);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,15); cprintf("OCTAVOS¯¯¯¯¯");
		  gotoxy(7,14);
		 }

		  else  if(wherey()==14 && wherex()==7)
		 {
		 gotoxy(5,15);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,15); cprintf("OCTAVOS¯¯¯¯¯");
		  gotoxy(5,14);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,14); cprintf("SEPTIMO¯¯¯¯¯");
		  gotoxy(7,13);
		 }
		  else  if(wherey()==13 && wherex()==7)
		 {
		 gotoxy(5,14);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,14); cprintf("SEPTIMO¯¯¯¯¯");
		  gotoxy(5,13);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,13); cprintf("SEXTOS¯¯¯¯¯¯");
		  gotoxy(7,12);
		 }
		  else  if(wherey()==12 && wherex()==7)
		 {
		 gotoxy(5,13);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,13); cprintf("SEXTOS¯¯¯¯¯¯");
		  gotoxy(5,12);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,12); cprintf("QUINTOS¯¯¯¯¯");
		  gotoxy(7,11);
		 }

		   else  if(wherey()==11 && wherex()==7)
		 {
		 gotoxy(5,12);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,12); cprintf("QUINTOS¯¯¯¯¯");
		  gotoxy(5,11);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,11); cprintf("CUARTOS¯¯¯¯¯");
		  gotoxy(7,10);
		 }
		else  if(wherey()==10 && wherex()==7)
		 {
		 gotoxy(5,11);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,11); cprintf("CUARTOS¯¯¯¯¯");
		  gotoxy(5,10);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,10); cprintf("TERCERO¯¯¯¯¯");
		  gotoxy(7,9);
		 }

		else  if(wherey()==9 && wherex()==7)
		 {
		 gotoxy(5,10);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,10); cprintf("TERCERO¯¯¯¯¯");
		  gotoxy(5,9);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,9); cprintf("SEGUNDO¯¯¯¯¯");
		  gotoxy(7,8);
		 }
		 else  if(wherey()==8 && wherex()==7)
		 {
		 gotoxy(5,9);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,9); cprintf("SEGUNDO¯¯¯¯¯");
		  gotoxy(5,8);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");
		  gotoxy(7,7);
		 }
	       else  if(wherey()==7 && wherex()==7)
		 {
		 gotoxy(5,8);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");
		  gotoxy(5,22);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,22); cprintf("PUERTOS¯¯¯¯¯");
		  gotoxy(7,22);
	       }
	     }
     else if(tecla==80)
       {
	  if(wherey()==22 && wherex()==7)
		 {
		 gotoxy(5,22);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,22); cprintf("PUERTOS¯¯¯¯¯");
		  gotoxy(5,8);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");
		  gotoxy(7,9);
	       }
		else if(wherey()==9 && wherex()==7)
		 {
		 gotoxy(5,8);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");
		  gotoxy(5,9);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,9); cprintf("SEGUNDO¯¯¯¯¯");
		  gotoxy(7,10);
	       }
	    else if(wherey()==10 && wherex()==7)
		 {
		 gotoxy(5,9);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,9); cprintf("SEGUNDO¯¯¯¯¯");
		  gotoxy(5,10);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,10); cprintf("TERCERO¯¯¯¯¯");
		  gotoxy(7,11);
	       }
	       else if(wherey()==11 && wherex()==7)
		 {
		 gotoxy(5,10);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,10); cprintf("TERCERO¯¯¯¯¯");
		  gotoxy(5,11);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,11); cprintf("CUARTOS¯¯¯¯¯");
		  gotoxy(7,12);
	       }

	       else if(wherey()==12 && wherex()==7)
		 {
		 gotoxy(5,11);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,11); cprintf("CUARTOS¯¯¯¯¯");
		  gotoxy(5,12);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,12); cprintf("QUINTOS¯¯¯¯¯");
		  gotoxy(7,13);
	       }
	       else if(wherey()==13 && wherex()==7)
		 {
		 gotoxy(5,12);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,12); cprintf("QUINTOS¯¯¯¯¯");
		  gotoxy(5,13);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,13); cprintf("SEXTOS¯¯¯¯¯¯");
		  gotoxy(7,14);
	       }
	       else if(wherey()==14 && wherex()==7)
		 {
		 gotoxy(5,13);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,13); cprintf("SEXTOS¯¯¯¯¯¯");
		  gotoxy(5,14);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,14); cprintf("SEPTIMO¯¯¯¯¯");
		  gotoxy(7,15);
	       }
	       else if(wherey()==15 && wherex()==7)
		 {
		 gotoxy(5,14);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,14); cprintf("SEPTIMO¯¯¯¯¯");
		  gotoxy(5,15);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,15); cprintf("OCTAVO¯¯¯¯¯¯");
		  gotoxy(7,16);
	       }
	     else if(wherey()==16 && wherex()==7)
		 {
		 gotoxy(5,15);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,15); cprintf("OCTAVO¯¯¯¯¯¯");
		  gotoxy(5,16);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,16); cprintf("NOVENO¯¯¯¯¯¯");
		  gotoxy(7,17);
	       }
	      else if(wherey()==17 && wherex()==7)
		 {
		 gotoxy(5,16);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,16); cprintf("NOVENO¯¯¯¯¯¯");
		  gotoxy(5,17);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,17); cprintf("DECIMO¯¯¯¯¯¯");
		  gotoxy(7,18);
	       }
	       else if(wherey()==18 && wherex()==7)
		 {
		 gotoxy(5,17);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,17); cprintf("DECIMO¯¯¯¯¯¯");
		  gotoxy(5,18);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,18); cprintf("JUEGOS¯¯¯¯¯¯");
		  gotoxy(7,19);
	       }
	      else if(wherey()==19 && wherex()==7)
		 {
		 gotoxy(5,18);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,18); cprintf("JUEGOS¯¯¯¯¯¯");
		  gotoxy(5,19);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,19); cprintf("CLASES¯¯¯¯¯¯");
		  gotoxy(7,20);
	       }
	     else if(wherey()==20 && wherex()==7)
		 {
		 gotoxy(5,19);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,19); cprintf("CLASES¯¯¯¯¯¯");
		  gotoxy(5,20);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,20); cprintf("TECLAS¯¯¯¯¯¯");
		  gotoxy(7,21);
	       }
	      else if(wherey()==21 && wherex()==7)
		 {
		 gotoxy(5,20);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,20); cprintf("TECLAS¯¯¯¯¯¯");
		  gotoxy(5,21);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,21); cprintf("RATONES¯¯¯¯¯");
		  gotoxy(7,23);
	       }
		 else if(wherey()==23 && wherex()==7)
		 {
		  gotoxy(5,21);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,21); cprintf("RATONES¯¯¯¯¯");
		  gotoxy(5,22);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,22); cprintf("PUERTOS¯¯¯¯¯");
		  gotoxy(7,7);

	       }
		else if(wherey()==7 && wherex()==7)
		 {
		  gotoxy(5,22);cout<<"  ";
		  textbackground(BLACK);
		  textcolor(BLUE);
		  gotoxy(7,22); cprintf("PUERTOS¯¯¯¯¯");
		  gotoxy(5,8);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);
		  gotoxy(7,8); cprintf("PRIMERO¯¯¯¯¯");
		  gotoxy(7,22);
		}
       }

} while(tecla!=27);

}
