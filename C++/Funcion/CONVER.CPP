# include <IOSTREAM.H>
# include <CONIO.H>
# include <DOS.H>
# include <TIME.H>
# include <STDIO.H>
# include <STDLIB.H>
# include <STRING.H>
#include <GRAPHICS.H>
#define PIXEL_COUNT 1000
#define DELAY_TIME  100  /* in milliseconds */


void CUADROS();
void TITULOS();
void NUMEROS();
void TECLA();
void LINET();
void CLASES();

void main(void)
{
 
 clrscr();
 LINET();
 textcolor(RED);
 textbackground(BLUE);
 CLASES();
  CUADROS();
  TITULOS();
  NUMEROS();
  TECLA();
 _setcursortype(_NOCURSOR);
}

void CUADROS()
{

int I,J;
textbackground(WHITE);
for(I=2;I<=44;I++)
 {
 gotoxy(I,2);textcolor(RED);cprintf("Í");
 gotoxy(I,16);textcolor(RED);cprintf("Í"); 
  _setcursortype(_NOCURSOR);
 }
for(J=3;J<=15;J++)
 {
 gotoxy(2,2);textcolor(RED);cprintf("É");
 gotoxy(2,J);textcolor(RED);cprintf("º");
 gotoxy(2,16);textcolor(RED);cprintf("È");
 gotoxy(44,2);textcolor(RED);cprintf("»");
 gotoxy(44,J);textcolor(RED);cprintf("º");
 gotoxy(44,16);textcolor(RED);cprintf("¼");
  _setcursortype(_NOCURSOR);
   }
}

void TITULOS()
{
time_t fecha;
fecha=time(NULL);
gotoxy(8,4);textcolor(1+160);cprintf("UNIVERSIDAD POPULLAR DEL CESAR");
gotoxy(12,5);textcolor(2+156);cprintf("CONVERSIONES DE DATOS");
gotoxy(10,6);textcolor(6+156);cprintf(ctime(&fecha));
}

void NUMEROS()
{
gotoxy(5,8);textcolor(BLUE);cprintf("DESEA CONVERTIR DE:");
textcolor(RED);
textbackground(WHITE); 
gotoxy(12,10);cout<<" BINARIO A DECIMAL";
gotoxy(12,11);cout<<" BINARIO A HEXADECIMAL";
gotoxy(12,12);cout<<" SALIR DEL PROGRAMA";
}

void TECLA()
{
 int tecla,unda=0;
  int I,J;
       repite:  
	 textbackground(WHITE);
	 gotoxy(11,10);textcolor(RED);cprintf("");
	 textbackground(GREEN);
	 textcolor(BLACK);
	 gotoxy(13,10);cprintf("BINARIO A DECIMAL");
	 textcolor(BLACK); //coloca las letras negras
	 

	 textbackground(WHITE);
	 textcolor(RED); //coloca las letras rojas
	 gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");

	 textbackground(WHITE);
	 textcolor(RED);  //coloca las letras rojas
	 gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");

	 gotoxy(13,10); // para dejarlo en laposicion 13 con 10
 
	 textcolor(RED);
	 textbackground(WHITE);
	 
	 do {
	 tecla=getch();
	  if(tecla==80)  // pregunta por la tecla de abajo
	    {
	      if(wherey()==10 && wherex()==13)
	       {
		 gotoxy(11,13);cout<<"  ";
		textbackground(GREEN);   // coloca el fondo verde  para 10
		textcolor(BLACK);       // coloca las letras negras para 10
	       gotoxy(13,10);cprintf("BINARIO A DECIMAL");
		gotoxy(11,11);textcolor(RED);cprintf("");
		textbackground(WHITE); // coloca el fondo blanco para 11
		textcolor(RED);        // coloca las letras rojas para 11		
		gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");
		gotoxy(13,11);
		}
      
		if(wherey()==11 && wherex()==13)
		 {
		   gotoxy(11,10);cout<<"  ";
		  textbackground(WHITE); // coloca el fondo blanco para 10
		  textcolor(RED);        // coloca las letras rojas para 10
		  gotoxy(13,10); cprintf("BINARIO A DECIMAL");
		  gotoxy(11,11);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 11
		  textcolor(BLACK);       // coloca las letras negras para 11		  
		  gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");
		  gotoxy(13,12);
		 }
		else if(wherey()==12 && wherex()==13)
		 {
		   gotoxy(11,11);cout<<"  "; 
		  textbackground(WHITE); // coloca el fondo blanco para 11
		  textcolor(RED);        // coloca las letras rojas para 11
		  gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");
		  gotoxy(11,12); textcolor(RED);cprintf("");
		  textbackground(GREEN);  // coloca el fondo verde para 12
		  textcolor(BLACK);       // coloca las letras negras para 12		  
		  gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");
		  gotoxy(13,13);

	       } 	      
	      
	      else if(wherey()==13 && wherex()==13)
	       {  
		   gotoxy(11,12);cout<<"  ";
		  textbackground(WHITE);  // coloca el fondo blanco para 12
		  textcolor(RED);         // coloca las letras rojas para 12
		  gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");
		  gotoxy(11,10);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 10
		  textcolor(BLACK);        // coloca las letras negras para 10		  
		  gotoxy(13,10); cprintf("BINARIO A DECIMAL");
		  gotoxy(13,10);

	       } 	      
	     
	     }
	 else if (tecla==72)  // pregunta por la tecla de arriba
	   {
	    if(wherey()==10 && wherex()==13)
	       {
		 gotoxy(11,10);cout<<" ";
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(13,10); cprintf("BINARIO A DECIMAL");
		gotoxy(11,12);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);		
		gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");
		gotoxy(13,13);
	       }
	   
	      else if(wherey()==13 && wherex()==13)
	       {  
		   gotoxy(11,10);cout<<"  ";
		  textbackground(WHITE);  // coloca el fondo blanco para 12
		  textcolor(RED);         // coloca las letras rojas para 12
		  gotoxy(13,10); cprintf("BINARIO A DECIMAL");
		  gotoxy(11,12);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 10
		  textcolor(BLACK);        // coloca las letras negras para 10		  
		  gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");
		  gotoxy(13,12);

	       } 	      


	      else  if(wherey()==12 && wherex()==13)
		 {
		   gotoxy(11,12);cout<<"  ";
		  textbackground(WHITE);
		  textcolor(RED);
		  gotoxy(13,12); cprintf("SALIR DEL PROGRAMA");
                  gotoxy(11,11);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);		  
		  gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");
		  gotoxy(13,11);

		 }
	       else  if(wherey()==11 && wherex()==13)
		 {
		   gotoxy(11,11);cout<<"  ";
		  textbackground(WHITE);
		  textcolor(RED);
		  gotoxy(13,11); cprintf("BINARIO A HEXADECIMAL");
		  gotoxy(11,10);textcolor(RED);cprintf("");
		  textbackground(GREEN);
		  textcolor(BLACK);		  
		  gotoxy(13,10); cprintf("BINARIO A DECIMAL");
		  gotoxy(13,10);
		 }
	} 
   else if(tecla=='M')
     if(wherey()==10) 
	 {
	  unda=1;
	  textbackground(WHITE);
	  for(I=32;I<=42;I++)
	     {
	      gotoxy(I,9);textcolor(RED);cprintf("Í");
	      gotoxy(I,15);textcolor(RED);cprintf("Í");
	      _setcursortype(_NOCURSOR);
	     }
	  for(J=10;J<=14;J++)
	 {
	     gotoxy(32,9);textcolor(RED);cprintf("É");
	     gotoxy(32,J); textcolor(RED);cprintf("º");
	     gotoxy(32,15);textcolor(RED);cprintf("È");
	     gotoxy(42,9);textcolor(RED);cprintf("»");
	     gotoxy(42,J);textcolor(RED);cprintf("º");
	     gotoxy(42,15);textcolor(RED);cprintf("¼");
	    _setcursortype(_NOCURSOR);

	 }
	  gotoxy(10,10);cout<<"  ";
	   gotoxy(33,11);cout<<"  ";
	   gotoxy(33,11);textcolor(RED);cprintf("");

	   textbackground(GREEN);
	   gotoxy(35,11);textcolor(BLACK);cprintf("PRIMERO");
   
	   textbackground(WHITE);
	   gotoxy(35,12);textcolor(RED);cprintf("SEGUNDO");
 
	   textbackground(WHITE);
	   gotoxy(35,13);textcolor(RED);cprintf("TERCERO");  

	   textbackground(WHITE);
	   gotoxy(35,14);textcolor(RED);cprintf("CUARTOS");
	   gotoxy(35,11);
       }
       
	  if(tecla==80)  // pregunta por la tecla de abajo
	    {
	     unda=1;
	      if(wherey()==11 && wherex()==35)
	       {
		unda=1;
		gotoxy(33,11);cout<<"  ";
		textbackground(WHITE);   // coloca el fondo verde  para 10
		textcolor(RED);       // coloca las letras negras para 10
		gotoxy(35,11);cprintf("PRIMERO");
		gotoxy(33,12);textcolor(RED);cprintf("");
		textbackground(GREEN); // coloca el fondo blanco para 11
		textcolor(BLACK);        // coloca las letras rojas para 11		
		gotoxy(35,12); cprintf("SEGUNDO");
		gotoxy(35,12);
		}
      
	       else if(wherey()==12 && wherex()==35)
		 {
		   unda=1;
		   gotoxy(33,12);cout<<"  ";
		  textbackground(WHITE); // coloca el fondo blanco para 10
		  textcolor(RED);        // coloca las letras rojas para 10
		  gotoxy(35,12); cprintf("SEGUNDO");
		  gotoxy(33,13);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 11
		  textcolor(BLACK);       // coloca las letras negras para 11		 
		  gotoxy(35,13); cprintf("TERCERO");
		  gotoxy(35,14);
		 }
		else if(wherey()==13 && wherex()==35)
		 {
		   unda=1;
		   gotoxy(33,12);cout<<"  "; 
		  textbackground(WHITE); // coloca el fondo blanco para 11
		  textcolor(RED);        // coloca las letras rojas para 11
		  gotoxy(35,12); cprintf("SEGUNDO");
		  gotoxy(33,13);textcolor(RED);cprintf("");
		  textbackground(GREEN);  // coloca el fondo verde para 12
		  textcolor(BLACK);       // coloca las letras negras para 12		
		  gotoxy(35,13); cprintf("TERCERO");
		  gotoxy(35,14);

	       } 	      
	      
	      else if(wherey()==14 && wherex()==35)
	       {  
		   unda=1;
		   gotoxy(33,13);cout<<"  ";
		  textbackground(WHITE);  // coloca el fondo blanco para 12
		  textcolor(RED);         // coloca las letras rojas para 12
		  gotoxy(35,13); cprintf("TERCERO");
		  gotoxy(33,14);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 10
		  textcolor(BLACK);        // coloca las letras negras para 10		  
		  gotoxy(35,14); cprintf("CUARTOS");
		  gotoxy(35,15);

	       } 	      
	      else if(wherey()==15 && wherex()==35)
	       {  
		  unda=1;
		   gotoxy(33,14);cout<<"  ";
		  textbackground(WHITE);  // coloca el fondo blanco para 12
		  textcolor(RED);         // coloca las letras rojas para 12
		  gotoxy(35,14); cprintf("CUARTOS");
		  gotoxy(33,11);textcolor(RED);cprintf("");
		  textbackground(GREEN);   // coloca el fondo verde para 10
		  textcolor(BLACK);        // coloca las letras negras para 10
		  gotoxy(35,11); cprintf("PRIMERO");
		  gotoxy(35,11);

	       } 	      
		


	   }
       if(tecla==72)
       {
	if(wherey()==11 && wherex()==35)
	{
		gotoxy(33,11);cout<<" ";
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(35,11); cprintf("PRIMERO");
		gotoxy(33,14);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);
		gotoxy(35,14); cprintf("CUARTOS");
		gotoxy(35,14);   
	}
       else if(wherey()==14 && wherex()==35)
	{
		gotoxy(33,14);cout<<" ";
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(35,14); cprintf("CUARTOS");
		gotoxy(33,13);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);
		gotoxy(35,13); cprintf("TERCERO");
		gotoxy(35,13);   
	}
       else if(wherey()==13 && wherex()==35)
	{
		gotoxy(33,13);cout<<" ";
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(35,13); cprintf("TERCERO");
		gotoxy(33,12);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);
		gotoxy(35,12); cprintf("SEGUNDO");
		gotoxy(35,12);   
	}
       else if(wherey()==12 && wherex()==35)
	{
		gotoxy(33,12);cout<<" ";
		textbackground(WHITE);
		textcolor(RED);
		gotoxy(35,12); cprintf("SEGUNDO");
		gotoxy(33,11);textcolor(RED);cprintf("");
		textbackground(GREEN);
		textcolor(BLACK);
		gotoxy(35,11); cprintf("PRIMERO");
		gotoxy(35,11);   
	}
      
       }	    
       if(tecla=='K')
	 if(unda==1)
	  {
	  textcolor(RED);
	   textbackground(WHITE);
	 
       for(I=32;I<=42;I++)
	     {
	      gotoxy(I,9); cout <<"    ";
	      gotoxy(I,15); cout <<"    ";
	      _setcursortype(_NOCURSOR);
	     }
	  for(J=10;J<=14;J++)
	 {   
	     clrscr();
	     gotoxy(32,9); cout <<"  ";
	     gotoxy(32,J); cout <<"  ";
	     gotoxy(32,15); cout <<"  ";
	     gotoxy(42,9); cout <<"  ";
	     gotoxy(42,J); cout <<"  ";
	     gotoxy(42,15); cout <<"  ";
	    _setcursortype(_NOCURSOR);
	  }
	   gotoxy(30,10);cout<<"   ";
	   textbackground(WHITE);
	   gotoxy(35,10);cprintf("         ");
   
	   textbackground(WHITE);        
	   gotoxy(35,11);cprintf("         ");
 
	   textbackground(WHITE);
	   gotoxy(35,12);cprintf("         ");
  
	   textbackground(WHITE);
	   gotoxy(35,13);cprintf("         ");
  
	   textbackground(WHITE);
	   gotoxy(35,14);cprintf("         ");
	   CUADROS();
	   TITULOS();
	   NUMEROS();
	   unda=2;
	   goto repite;
     }
  }while(tecla !=27 && tecla!=13);
do{
   if(tecla==27)
   exit(0);

 if(wherey()==11 && wherex()==35)
   { 
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("PRIMERO");
    CUADROS();
    TITULOS();
    getch(); 
   }
 else if(wherey()==12 && wherex()==35)
   { 
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("SEGUNDO");
    CUADROS();
    TITULOS();
    getch(); 
   }
else if(wherey()==14 && wherex()==35)
   { 
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("TERCERO");
    CUADROS();
    TITULOS();
    getch(); 
   }
 else if(wherey()==15 && wherex()==35)
   { 
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("CUARTOS");
    CUADROS();
    TITULOS();
    getch(); 
   }

else if(wherey()==10 && wherex()==13)
   { 
    textbackground(WHITE);
    clrscr();    
    gotoxy(10,10);textcolor(5+128);cprintf("BINARIO A DECIMAL");
    CUADROS();
    TITULOS();
    getch(); 
   }

else if(wherey()==13 && wherex()==13)
   { 
    
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("SALIR DEL PROGRAMA ¯¯(fin)");
    CUADROS();
    TITULOS();
    getch(); 
   }
 else if(wherey()==12 && wherex()==13)
   { 
    textbackground(WHITE);
    clrscr();
    gotoxy(10,10);textcolor(5+128);cprintf("BINARIO A HEXADECIMAL");
    CUADROS();
    TITULOS();
    getch();  
   }
    textbackground(WHITE);
   clrscr();
   CUADROS();
   TITULOS();
   NUMEROS();
   goto repite;
}while(tecla !=27 && tecla !=13);
}


void LINET()
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   int i,k, x, y, color, maxx, maxy, maxcolor, seed;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "\\tc\\bgi\\");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   maxx = getmaxx() + 1;
   maxy = getmaxy() + 1;
   maxcolor = getmaxcolor() + 1;

  while (!kbhit())
  {
      /* seed the random number generator */
      seed = random(32767);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 putpixel(x, y, color);
	
      }

      delay(DELAY_TIME);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 if (color == getpixel(x, y))
	    putpixel(x, y, 0);
      }
    
   }

   /* clean up */

   closegraph();
  // return 0;
}

void CLASES()
{
clrscr();
 textcolor(RED);
 textbackground(BLACK);
 window(15,5,60,20);
 clrscr();
 gotoxy(3,1);textcolor(WHITE);cprintf("PRESIONE LAS TECLAS      PARA EL MENU Y"); 
 gotoxy(2,3);textcolor(WHITE);cprintf("E");
 gotoxy(2,4);textcolor(WHITE);cprintf("S");
 gotoxy(2,5);textcolor(WHITE);cprintf("C");
 gotoxy(2,6);textcolor(WHITE);cprintf(" ");
 gotoxy(2,7);textcolor(WHITE);cprintf("P");
 gotoxy(2,8);textcolor(WHITE);cprintf("A");
 gotoxy(2,9);textcolor(WHITE);cprintf("R");
 gotoxy(2,10);textcolor(WHITE);cprintf("A");
 gotoxy(2,11);textcolor(WHITE);cprintf(" ");
 gotoxy(2,12);textcolor(WHITE);cprintf("S");
 gotoxy(2,13);textcolor(WHITE);cprintf("A");
 gotoxy(2,14);textcolor(WHITE);cprintf("L");
 gotoxy(2,15);textcolor(WHITE);cprintf("I");
 gotoxy(2,16);textcolor(WHITE);cprintf("R");
 textbackground(WHITE);
window(17,6,62,21);
 clrscr();
}



