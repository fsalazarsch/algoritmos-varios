#include <iostream.h>
#include <conio.h>
#include <string.h>
int Menu(char MenuOPC[][40],int FILA, int COLUMNA , int NUMOPC ,int LARGOOPC ,int TIPO,int eleccion);
int LeerTecla (void)   ;

void main (void)
{
int x,y;
char opc[10][40];
char opc2[10][40];
strcpy (opc[0]," Opcion uno       ");
strcpy (opc[1]," Opcion dos       ");
strcpy (opc[2]," Opcion tres      ");
strcpy (opc[3]," Opcion cuatro    ");
strcpy (opc[4]," Opcion cinco     ");
strcpy (opc[5]," Salir            ");

strcpy (opc2[0]," xxxxxxxxxx      ");
strcpy (opc2[1]," wwwwwwwwwww     ");
strcpy (opc2[2]," wwwwwwwwwwww    ");
strcpy (opc2[3]," eeeeeeeeeeeee   ");
strcpy (opc2[4]," eeeeeeeeeeeee   ");
strcpy (opc2[5]," opcittttttt     ");
x=1;
textbackground(BLACK);
clrscr();
while (x!=6)
{
x = Menu(opc,6,10 , 6 ,18 ,1,x)   ;
switch(x){
 case 1:y = Menu(opc2,6,29,5,17,0,1);break;
 case 2:y = Menu(opc2,7,29,5,17,0,1);break;
 case 3:y = Menu(opc2,8,29,5,17,0,1);break;
 case 4:y = Menu(opc2,9,29,5,17,0,1);break;
 case 5:y = Menu(opc2,10,29,5,17,0,1);break;
}
}
gotoxy(5,20);cout <<"Ha escogido la opcion " <<x <<endl <<y;
getch();
textbackground(BLACK);
clrscr();
}


int LeerTecla (void)
{
int Tecla1, Tecla2;
Tecla1=getch();
if (Tecla1==0){ Tecla2=getch();Tecla1=Tecla2+256;}
return Tecla1;
}

int Menu(char MenuOPC[][40],int FILA, int COLUMNA , int NUMOPC ,int LARGOOPC ,int TIPO,int eleccion)
{
int  tecla, I, J;
char buffer[4096];
tecla=0;
if (TIPO==0){ gettext(COLUMNA-1,FILA-1, COLUMNA+ LARGOOPC+1, FILA +NUMOPC+1, buffer);}

textcolor(YELLOW);
_setcursortype(_NOCURSOR);
do
{
textbackground(RED);   
  for(I=0;I<=NUMOPC-1;I++)
  {
  for(J=0;J<=LARGOOPC;J++)
    { gotoxy(COLUMNA+J-1,FILA+I);cprintf(" "); }
  for(J=0;J<=LARGOOPC;J++)
    {  gotoxy(COLUMNA+J,FILA+I);cout <<MenuOPC[I][J];    }
  }
textbackground(BLUE);
for(I=0;I<=LARGOOPC;I++)
    { gotoxy(COLUMNA+I-1,FILA + eleccion -1);cprintf(" ");  }

for(I=0;I<=LARGOOPC;I++)
    { gotoxy(COLUMNA+I,FILA + eleccion -1);cout <<MenuOPC[eleccion-1][I]; }
tecla=LeerTecla();
if (tecla==336) eleccion++;
if (tecla==328) eleccion--;
if (eleccion==0) eleccion=NUMOPC;
if (eleccion==NUMOPC+1) eleccion=1;

if (TIPO==0)
if (tecla == 27) { eleccion = 0; tecla=13;}

}
while(tecla != 13);

_setcursortype(_NORMALCURSOR);

if (TIPO==0){puttext(COLUMNA-1,FILA-1, COLUMNA+ LARGOOPC+1, FILA +NUMOPC+1, buffer);
	     buffer[0]=NULL;}

return(eleccion);
} /* Menu */

