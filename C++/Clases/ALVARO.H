#include <iostream.h>	// to get memcpy and NULL
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <stdio.h>

#define PR cout<<" "
#define PS(x) cprintf("%s",x)
int cont=0;

class alv
{
 public:
 void MENU(int,int,int,int);
 void MES(int,int,int);
 void CUADRO(int,int,int,int);
 void MIS(int,int,int);
 void BARRA(void);
 void MUERTE(void);
 void MUERTE1(void);
 void CLAV(void);
 void P_CLAVE(void);
 void UPC(void);
 void U(void);
 void P(void);
 void C(void);
 void U1(void);
 void U2(void);
 void BOTON(int,int,int,int,int,int,int,int,char tit[20]);
 void BORRAR(int,int,int,int);
 void cmas(void);
};

void alv::MENU(int tam,int fil,int filsig,int colfi)
{
   char ch[30];
   int col,j,k,TECLA,RETROCESO,s;
   textcolor(BLACK);
  gotoxy(29,fil);
  col=29;
  _setcursortype(_SOLIDCURSOR);
   k=0;
  for(j=0;j<=tam;j++)//CAMBIA EL TAMA•O DEL VECTOR
  {
  TECLA=getche();
   if(TECLA==27)
     exit(0);
    else if (TECLA==13)
  {
     gotoxy(29,filsig);
     break;
   }
  else if(TECLA==8)
      {
      if(wherex()==28) //CAMBIA LA COLUMNA INICIAL
      {gotoxy(29,fil);--j;}//CAMBIA LA COLUMNA +1
      else{--col;--j;k=1;}
      }
     else{ch[j]=TECLA;gotoxy(++col,fil);}
  if(k==1)
  {--j;k=0;}
  if(wherex()==colfi)//CAMBIA LA COLUMNA FINAL
  for(k=1;k<100;k++)
 {
   gotoxy(colfi-1,fil); //CAMBIA LA COLUMNA -1
   TECLA=getch();
   if(TECLA==27)
     exit(0);
   else if(TECLA==13)
   {k=2500;j=50;}
   else if(TECLA==8)
   {--col;--j;gotoxy(col,fil);k=140;}
 }
if (TECLA==13){
   gotoxy(29,filsig);
   break;}
}
}

void alv::MES(int coli, int colf,int fil)
{
  int p;
for(p=coli;p<colf;p++){gotoxy(p,fil);cprintf(" ");}
}

void alv::MIS(int fili, int filf,int col)
{
  int p;
for(p=fili;p<filf;p++){gotoxy(col,p);cprintf(" ");}
}

void alv::CUADRO(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Õ";
gotoxy(o,ff); cout<<"Õ";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"∫";
gotoxy(cf,o); cout<<"∫";
}
gotoxy(ci,fi); cout<<"…";
gotoxy(cf,fi); cout<<"ª";
gotoxy(ci,ff); cout<<"»";
gotoxy(cf,ff); cout<<"º";

}

void alv::BARRA(void)
{
int i;
alv CUA;
textbackground(BLACK);
clrscr();
window(1,1,78,25);textbackground(BLACK);clrscr();
gotoxy(29,12);textcolor(7);cprintf("PROCESANDO OPERACION...");
window(20,14,60,14);textbackground(7);clrscr();
_setcursortype(_NOCURSOR);
 for(i=1;i<=41;i++){sound(i+450);  gotoxy(i,14);textbackground(BLUE);cprintf(" ");
 delay(100);}nosound();
 gotoxy(35,20);textcolor(14);cprintf("           OPERACION EXITOSA...");getch();
 window(1,1,78,25);textbackground(BLACK);clrscr();
}




void alv::P_CLAVE () {
	int i;
	char pal [7],c,cla[7];
	int p,x;
	pal [0] = 'o';
	pal [1] = 'r';
	pal [2] = 'a';
	pal [3] = 'v';
	pal [4] = 'l';
	pal [5] = 'a';
	pal [6] = 13;
	gotoxy(20,20);x=500;
	for (i=0; i < 7;i++) {
	    cla[i] = c = getch();     /* No hace eco */
	     cla[i] = tolower(cla[i]);
	       sound(x);
		 delay(100);
		 nosound();
		  if (c==13){
		 sound(440);
		 delay(1000);
		 nosound();
		  goto p;}
		  x+=500;
		 printf ("*");
	       }
		p:
		if (cla [0] == 'o')
		  if (cla [1] == 'r')
		   if (cla [2] == 'a')
		    if (cla [3] == 'v')
		     if (cla [4] == 'l')
		      if (cla [5] == 'a')
		       if (cla [6] == 13)
			  {
			   textbackground(4);
			   gotoxy(5,2);cprintf ("Clave correcta. Acceso concedido...");
			   getch();cont=5;}
			   else
			   {
			   gotoxy(5,2);cprintf  ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			   gotoxy(5,2);cprintf  ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			   gotoxy(5,2);cprintf  ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			   gotoxy(5,2);cprintf   ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			   gotoxy(5,2);cprintf  ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			  gotoxy(5,2);cprintf  ("Clave erronea. Acceso denegado...");
			getch();
			CLAV();}

			else
			   {
			  gotoxy(5,2);cprintf  ("Clave erronea. Acceso deneado...");
			getch();
			CLAV();}

}



void alv::CLAV()
{
 int i;
 alv CUA;
 do{ window(1,1,80,25);textbackground(0);
 if(cont==3){window(20,11,60,13);textbackground(4);clrscr();
 gotoxy(1,2);cprintf("Acceso denegado. bay bay.. CARGANDO VIRUS");

//barra progresiva
 CUA.BARRA();
 gotoxy(27,1);cprintf("VIRUS INSTALADO, PREPARATE");
// textmode(C4350);

int j,r;
_setcursortype(_NOCURSOR);
for(j=1;j<=20;j++){CUA.MUERTE();CUA.MUERTE1();} //RISA
 getch();exit(0);}
  cont+=1;

       clrscr();
       window(20,12,60,14);textbackground(1);clrscr();
       window(20,10,60,12);textbackground(1);clrscr();
       gotoxy(14,1);textcolor(7);cprintf("DIGITA LA CLAVE");
       window(20,11,60,13);textbackground(4);clrscr();
       textcolor(4);
       gotoxy(5,2);textcolor(7);cprintf("CLAVE DE ACCESO:[       ]");
       textbackground(BLUE);
       CUA.MES(22,29,2);
       gotoxy(22,2);
       CUA.P_CLAVE();
 }while(cont<3);
   }




void alv::MUERTE(void)
{
gotoxy(35,2);cprintf("_.-------.,_");
gotoxy(31,3);cprintf(",;''            '';,");
gotoxy(29,4);cprintf(",;                    ;,");
gotoxy(28,5);cprintf(";                        ;");
gotoxy(27,6);cprintf(",'                        ',");
gotoxy(26,7);cprintf(",;                          ;,");
gotoxy(26,8);cprintf("; ;      .           .      ; ;");
gotoxy(26,9);cprintf("| ;   ______       ______   ; |");
gotoxy(26,10);cprintf("|    [~'     ' . '      '~]   |");
gotoxy(26,11);cprintf("|  ~  ,-~~~^~, | ,~^~~~-,  ~  |");
gotoxy(27,12);cprintf("|   |        }:{        |   |");
gotoxy(27,13);cprintf("|   l       /   /       l   |");
gotoxy(27,14);cprintf(".~  (__,.--'     '--.,__)  ~.");
gotoxy(27,15);cprintf("|     ---;'   ^   ';---     |");
gotoxy(28,16);cprintf("»__.       » l º      .__º                    ");
gotoxy(28,17);cprintf(" V| /                 / |V                    ");
gotoxy(28,18);cprintf(" | |T~/___!___!___/~T| |                      ");
gotoxy(29,19);cprintf("| |`IIII_I_I_I_IIII'| |                       ");
gotoxy(29,20);cprintf("|  /,III I I I III,/  |                       ");
gotoxy(29,21);cprintf(" »   `~~~~~~~~~~'    º                        ");
gotoxy(29,22);cprintf("   »   .       .   º                          ");
gotoxy(29,23);cprintf("     ».    ^    .º  ");
gotoxy(29,24);cprintf("       ^~~~^~~~^     ");
gotoxy(29,25);clreol();
delay(400);
}
void alv::MUERTE1(void)
{
sound(5000);
gotoxy(35,2);cprintf("_.-------.,_");
gotoxy(31,3);cprintf(",;''            '';,");
gotoxy(29,4);cprintf(",;                    ;,");
gotoxy(28,5);cprintf(";                        ;");
gotoxy(27,6);cprintf(",'                        ',");
gotoxy(26,7);cprintf(",;                          ;,");
gotoxy(26,8);cprintf("; ;      .           .      ; ;");
gotoxy(26,9);cprintf("| ;   ______       ______   ; |");
gotoxy(26,10);cprintf("|    [~'     ' . '      '~]   |");
gotoxy(26,11);cprintf("|  ~  ,-~~~^~, | ,~^~~~-,  ~  |");
gotoxy(27,12);cprintf("|   |        }:{        |   |");
gotoxy(27,13);cprintf("|   l       /   /       l   |");
gotoxy(27,14);cprintf(".~  (__,.--'     '--.,__)  ~.");
gotoxy(27,15);cprintf("|     ---;'   ^   ';---     |");
gotoxy(28,16);cprintf("»__.       » l º      .__º     ::::::::");
gotoxy(28,17);cprintf(" V| /                 / |V :::          :::");
gotoxy(28,18);cprintf(" | |T~/___!___!___/~T| |  ::              ::");
gotoxy(29,19);cprintf("| |`IIII_I_I_I_IIII'| |  :  --> IMB‘CIL..!  :");
gotoxy(29,20);cprintf("|                     |   ::   JA,JA...   ::");
gotoxy(29,21);cprintf("|  /,III I I I III,/  |    :::          :::");
gotoxy(29,22);cprintf(" »   `~~~~~~~~~~'   º          ::::::::: ");
gotoxy(29,23);cprintf("   »   .       .   º  ");
gotoxy(29,24);cprintf("     ».    ^    .º  ");
gotoxy(29,25);cprintf("       ^~~~^~~~^");
delay(400);
nosound();
}

void alv::UPC()
{
 gotoxy(18,6); cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(18,7); cprintf("∫   ⁄ƒƒƒø  ⁄ƒƒƒø   ⁄ƒƒƒƒƒƒƒƒƒø   ⁄ƒƒƒƒƒƒƒƒø   ∫");
 gotoxy(18,8); cprintf("∫   ≥€€€≥  ≥€€€≥   ≥€€€€€€€€€≥   ≥€€€€€€€€≥   ∫");
 gotoxy(18,9); cprintf("∫   ≥€€€≥  ≥€€€≥   ≥€€€   €€€≥   ≥€€€⁄ƒƒƒƒŸ   ∫");
 gotoxy(18,10);cprintf("∫   ≥€€€≥  ≥€€€≥   ≥€€€   €€€≥   ≥€€€≥        ∫");
 gotoxy(18,11);cprintf("∫   ≥€€€≥  ≥€€€≥   ≥€€€€€€€€€≥   ≥€€€≥        ∫");
 gotoxy(18,12);cprintf("∫   ≥€€€≥  ≥€€€≥   ≥€€€⁄ƒƒƒƒƒŸ   ≥€€€≥        ∫");
 gotoxy(18,13);cprintf("∫   ≥€€€¿ƒƒŸ€€€≥   ≥€€€≥         ≥€€€¿ƒƒƒƒø   ∫");
 gotoxy(18,14);cprintf("∫   ≥€€€€€€€€€€≥   ≥€€€≥         ≥€€€€€€€€≥   ∫");
 gotoxy(18,15);cprintf("∫   ¿ƒƒƒƒƒƒƒƒƒƒŸ   ¿ƒƒƒŸ         ¿ƒƒƒƒƒƒƒƒŸ   ∫");
 gotoxy(18,16);cprintf("∫    UNIVERSIDAD    POPULAR   DEL   CESAR     ∫");
 gotoxy(18,17);cprintf("∫          All Right Reserved © 2000          ∫");
 gotoxy(18,18);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 textcolor(15);gotoxy(29,23);printf("ALVARO A CARRILLO ARAUJO");
 delay(200);
}

void alv::U()
{
 gotoxy(18,6); cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(18,7); cprintf("∫   ⁄ƒƒƒø  ⁄ƒƒƒø                              ∫");
 gotoxy(18,8); cprintf("∫   ≥€€€≥  ≥€€€≥                              ∫");
 gotoxy(18,9); cprintf("∫   ≥€€€≥  ≥€€€≥                              ∫");
 gotoxy(18,10);cprintf("∫   ≥€€€≥  ≥€€€≥                              ∫");
 gotoxy(18,11);cprintf("∫   ≥€€€≥  ≥€€€≥                              ∫");
 gotoxy(18,12);cprintf("∫   ≥€€€≥  ≥€€€≥                              ∫");
 gotoxy(18,13);cprintf("∫   ≥€€€¿ƒƒŸ€€€≥                              ∫");
 gotoxy(18,14);cprintf("∫   ≥€€€€€€€€€€≥                              ∫");
 gotoxy(18,15);cprintf("∫   ¿ƒƒƒƒƒƒƒƒƒƒŸ                              ∫");
 gotoxy(18,16);cprintf("∫    UNIVERSIDAD    POPULAR   DEL   CESAR     ∫");
 gotoxy(18,17);cprintf("∫          All Right Reserved © 2000          ∫");
 gotoxy(18,18);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 textcolor(15);gotoxy(29,23);printf("ALVARO A CARRILLO ARAUJO");
 delay(200);
}


void alv::P()
{
 gotoxy(18,6); cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(18,7); cprintf("∫                  ⁄ƒƒƒƒƒƒƒƒƒø                ∫");
 gotoxy(18,8); cprintf("∫                  ≥€€€€€€€€€≥                ∫");
 gotoxy(18,9); cprintf("∫                  ≥€€€   €€€≥                ∫");
 gotoxy(18,10);cprintf("∫                  ≥€€€   €€€≥                ∫");
 gotoxy(18,11);cprintf("∫                  ≥€€€€€€€€€≥                ∫");
 gotoxy(18,12);cprintf("∫                  ≥€€€⁄ƒƒƒƒƒŸ                ∫");
 gotoxy(18,13);cprintf("∫                  ≥€€€≥                      ∫");
 gotoxy(18,14);cprintf("∫                  ≥€€€≥                      ∫");
 gotoxy(18,15);cprintf("∫                  ¿ƒƒƒŸ                      ∫");
 gotoxy(18,16);cprintf("∫    UNIVERSIDAD    POPULAR   DEL   CESAR     ∫");
 gotoxy(18,17);cprintf("∫          All Right Reserved © 2000          ∫");
 gotoxy(18,18);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 textcolor(15);gotoxy(29,23);printf("ALVARO A CARRILLO ARAUJO");
 delay(200);
}

void alv::C()
{
 gotoxy(18,6); cprintf("…ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕª");
 gotoxy(18,7); cprintf("∫                                ⁄ƒƒƒƒƒƒƒƒø   ∫");
 gotoxy(18,8); cprintf("∫                                ≥€€€€€€€€≥   ∫");
 gotoxy(18,9); cprintf("∫                                ≥€€€⁄ƒƒƒƒŸ   ∫");
 gotoxy(18,10);cprintf("∫                                ≥€€€≥        ∫");
 gotoxy(18,11);cprintf("∫                                ≥€€€≥        ∫");
 gotoxy(18,12);cprintf("∫                                ≥€€€≥        ∫");
 gotoxy(18,13);cprintf("∫                                ≥€€€¿ƒƒƒƒø   ∫");
 gotoxy(18,14);cprintf("∫                                ≥€€€€€€€€≥   ∫");
 gotoxy(18,15);cprintf("∫                                ¿ƒƒƒƒƒƒƒƒŸ   ∫");
 gotoxy(18,16);cprintf("∫    UNIVERSIDAD    POPULAR   DEL   CESAR     ∫");
 gotoxy(18,17);cprintf("∫          All Right Reserved © 2000          ∫");
 gotoxy(18,18);cprintf("»ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕº");
 textcolor(15);gotoxy(29,23);printf("ALVARO A CARRILLO ARAUJO");
 delay(200);
}


void alv::U1()
{
int x;
clrscr();

for(x=60;x>=12;x--){	               
gotoxy(x,5);cprintf("         ‹€           ");
gotoxy(x,6);cprintf("        €€€           ");
gotoxy(x,7);cprintf("   ‹€   €€€           ");
gotoxy(x,8);cprintf("  €€€   €€€           ");
gotoxy(x,9);cprintf("  €€€   €€€           ");
gotoxy(x,10);cprintf("  €€€ ‹€€€ﬂ          ");
gotoxy(x,11);cprintf("  €€€€€€ﬂ            ");
gotoxy(x,12);cprintf("  €€€€ﬂ              ");
gotoxy(x,13);cprintf("  €€ﬂ                ");
gotoxy(x,14);cprintf("  ﬂ                  ");
delay(20);
}


for(x=60;x>=23;x--){
gotoxy(x,5);cprintf("  €€‹            ");
gotoxy(x,6);cprintf("  €€€€‹          ");
gotoxy(x,7);cprintf("  €€€ ﬂ€‹        ");
gotoxy(x,8);cprintf("  €€€‹  ﬂ€‹      ");
gotoxy(x,9);cprintf("  €€€ﬂ€‹ €€€    ");
gotoxy(x,10);cprintf("  ﬂ€€  ﬂ€€€€    ");
gotoxy(x,11);cprintf("    ﬂ    ﬂ€€    ");
gotoxy(x,12);cprintf("           ﬂ    ");
delay(20);
} 
x=20;
gotoxy(21,x-9);cprintf(" ‹€‹ ");
gotoxy(20,x-8);cprintf("‹€€€€€‹             ");
gotoxy(18,x-7);cprintf("‹€€€€ﬂ€€€€‹           ");
gotoxy(16,x-6);cprintf("‹€€€€ﬂ   ﬂ€€€€‹         ");
gotoxy(14,x-5);cprintf("‹€€€€ﬂ       ﬂ€€€€‹        ");
gotoxy(14,x-4);cprintf("ﬂ€€€€‹          ﬂ€€€ﬂ      ");
gotoxy(15,x-3);cprintf("ﬂ€€€€‹          ﬂ        ");
gotoxy(17,x-2);cprintf("ﬂ€€€€‹                 ");
gotoxy(18,x-1);cprintf(" ﬂ€€€ﬂ                ");
gotoxy(20,x);cprintf(" ﬂ    ");
gotoxy(1,24);clreol();
gotoxy(1,23);clreol();
gotoxy(1,22);clreol();
gotoxy(1,21);clreol();
}

void alv::U2()
{
gotoxy(2,2);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");
gotoxy(2,3);cprintf("€€                                                                          €€");
gotoxy(2,4);cprintf("€€                                   FACULTAD DE CIENCIAS Y TECNOLOGIAS     €€");
gotoxy(2,5);cprintf("€€                  ‹ ‹                    INGENIERIA DE SISTEMAS           €€");
gotoxy(2,6);cprintf("€€                ‹€€ €€‹                       SEMESTRE   V-B              €€");
gotoxy(2,7);cprintf("€€                €€€ €€€€‹                                                 €€");
gotoxy(2,8);cprintf("€€           ‹€   €€€ €€€ ﬂ€‹                                               €€");
gotoxy(2,9);cprintf("€€          €€€   €€€ €€€‹  ﬂ€‹              PROGRAMACION                   €€");
gotoxy(2,10);cprintf("€€          €€€   €€€ €€€ﬂ€‹ €€€                                            €€");
gotoxy(2,11);cprintf("€€          €€€ ‹€€€ﬂ ﬂ€€  ﬂ€€€€                                            €€");
gotoxy(2,12);cprintf("€€          €€€€€€ﬂ ‹€‹ ﬂ    ﬂ€€                                            €€");
gotoxy(2,13);cprintf("€€          €€€€ﬂ ‹€€€€€‹      ﬂ                                            €€");
gotoxy(2,14);cprintf("€€          €€ﬂ ‹€€€€ﬂ€€€€‹                                                 €€");
gotoxy(2,15);cprintf("€€          ﬂ ‹€€€€ﬂ   ﬂ€€€€‹                                               €€");
gotoxy(2,16);cprintf("€€         ‹€€€€ﬂ       ﬂ€€€€‹                                              €€");
gotoxy(2,17);cprintf("€€         ﬂ€€€€‹          ﬂ€€€ﬂ                                            €€");
gotoxy(2,18);cprintf("€€           ﬂ€€€€‹          ﬂ                                              €€");
gotoxy(2,19);cprintf("€€             ﬂ€€€€‹                                                       €€");
gotoxy(2,20);cprintf("€€               ﬂ€€€ﬂ                                                      €€");
gotoxy(2,21);cprintf("€€                 ﬂ      !BIENVENIDO AL SISTEMA! PRESIONE <<ENTER>>        €€");
gotoxy(2,22);cprintf("€€                                                                          €€");
gotoxy(2,23);cprintf("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€");

getch();
}


void alv::BOTON(int z,int x,int x1,int y,int y1,int fon,int car,int fondo,char tit[20])
{
int tec,p,j,i,sw=0;
_setcursortype(_NOCURSOR);
if(z==0)
{
  window(x,x1,y,y1);
  textcolor(fon);
  for(j=x+1;j<=x1+1;j++){gotoxy(j,y+1);textcolor(fon);cprintf("ﬂ");}
  gotoxy(j-1,y);textcolor(fon);cprintf("‹");
  if (sw==0){
   for(j=x+1;j<=x1+1;j++){gotoxy(j,y+1);textcolor(fondo);cprintf("‹");}
   gotoxy(x1+1,y);textcolor(fondo);cprintf("ﬂ");sw=1;
  }
  textbackground(car);
  window(x,y,x1,y1);clreol();
  gotoxy(3,1);textcolor(0);cprintf("%s",tit);
  gotoxy(3,1);textcolor(RED);cprintf("%c",tit[0]);
  textcolor(0);
}
else{
 tec=getch();
  if((tec==0x1e)||(tec==13))//combinacion alt+a
  {
    for(j=x+1;j<=x1+1;j++){gotoxy(j,y+1);textcolor(fondo);cprintf("‹");}
  gotoxy(x1+1,y);textcolor(fondo);cprintf("ﬂ");
 // getch();
   //para borrar pantalla
  textbackground(fondo);
  window(x,y,x1,y1);gotoxy(x,x1);textcolor(fondo);cprintf("€");
//***************************************
   textbackground(car);
   window(x+1,y,x1+1,y1);clreol();
    gotoxy(2,1);textcolor(0);cprintf("%s",tit);
   window(1,1,80,25);gotoxy(x,y+1);textbackground(fondo);textcolor(fon);
   for(i=1;i<=y+1;i++)
     cprintf(" ");
   delay(500);}
   window(x,x1,y,y1);
  for(j=x+1;j<=x1+1;j++){gotoxy(j,y+1);textcolor(fon);cprintf("ﬂ");}
  gotoxy(j-1,y);textcolor(fon);cprintf("‹");
  textbackground(car);
  window(x,y,x1,y1);clreol();
  gotoxy(3,1);textcolor(0);cprintf("%s",tit);
  gotoxy(3,1);textcolor(RED);cprintf("%c",tit[0]);
 delay(500);
   }
window(1,1,80,25);
}
void alv::BORRAR(int ci,int cf,int fi,int ff)
{
 int i,j;
 for(j=fi;j<=ff;j++)
  for(i=ci;i<=cf;i++)
  cout<<" ";
}

void alv::cmas()
{
     delay(14);gotoxy(40,6);cprintf ("   ‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹   ");
     delay(14);gotoxy(40,7);cprintf ("   €€   €€ €€€ €€€€   ");
     delay(14);gotoxy(40,8);cprintf ("   €€ €€€   €   €€€   ");
     delay(14);gotoxy(40,9);cprintf ("   €€ €€€€ €€€ €€€€   ");
     delay(14);gotoxy(40,10);cprintf("   €€‹‹‹€€‹€€€‹€€€€   ");
     delay(14);gotoxy(40,11);cprintf("     €     €‹‹‹‹€     ");
     delay(14);gotoxy(40,12);cprintf("     €‹‹‹‹‹€‹‹‹‹€     ");
     delay(14);gotoxy(40,13);cprintf("                      ");
     getch();
}
