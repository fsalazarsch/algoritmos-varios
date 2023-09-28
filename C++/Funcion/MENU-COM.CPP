# include <iostream.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
main()
{
int j;
int TECLA;
clrscr();
textcolor(1);
textbackground(2);
for(j=0;j<=100;j++)//CAMBIA EL TAMA¥O DEL VECTOR
  {
  TECLA=getche();
   if(TECLA==27)
     exit(0);
   //pregunto por la tecla direccion
  else if (TECLA==9){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA DE DIRECCIO";}
   //pregunto por la tecla fin
   else if(TECLA=='O'){clrscr();gotoxy(29,10);cout<<"               ";gotoxy(29,10);cout<<"TECLA FIN";}
    //pregunto por la tecla av pagina
   else if(TECLA=='Q'){clrscr();gotoxy(29,10);cout<<"                ";gotoxy(29,10);cout<<"TECLA AV PAGINA";}
  //pregunto por la tecla re pagina
   else if(TECLA=='I'){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA RE PAGINA";}
   //pregunto por la tecla insert
   else if(TECLA=='R'){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA INSERT";}
  //pregunto por la tecla inicio
   else if(TECLA=='G'){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA INICIO";}
  //pregunto por la tecla SUPRIMIR
   else if(TECLA=='S'){clrscr();gotoxy(29,10);cout<<"TECLA SUPRIMIR";}
   //pregunto por la f7
   else if(TECLA=='A'){clrscr();gotoxy(29,10);cout<<"              ";gotoxy(29,10);cout<<"TECLA F7";}
    //pregunto por la f8
   else if(TECLA=='B'){clrscr();gotoxy(29,10);cout<<"              ";gotoxy(29,10);cout<<"TECLA F8";}
    //pregunto por la f9
   else if(TECLA=='C'){clrscr();gotoxy(29,10);cout<<"               ";gotoxy(29,10);cout<<"TECLA  F9";}
    //pregunto por la f10
   else if(TECLA=='D'){clrscr();gotoxy(29,10);cout<<"               ";gotoxy(29,10);cout<<"TECLA F10";}
   //pregunto por la f12 '†'
   else if(TECLA==134){clrscr();gotoxy(29,10);cout<<"               ";gotoxy(29,10);cout<<"TECLA F12";}
   //pregunto por la f11  '…'
    else if(TECLA==133){clrscr();gotoxy(29,10);cout<<"               ";gotoxy(29,10);cprintf("TECLA F11");}
   //pregunto por la f6   '@'
   else if(TECLA==64){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F6";}
  //pregunto por la f5    '?'
   else if(TECLA==63){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F5";}
   //pregunto por la f4   '>'
   else if(TECLA==62){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F4";}
   //pregunto por la f3   '='
   else if(TECLA==61){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F3";}
   //pregunto por la f2    '<'
   else if(TECLA==60){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F2";}
   //pregunto por la f1    ';'
   else if(TECLA==59){clrscr();gotoxy(29,10);cout<<"                 ";gotoxy(29,10);cout<<"TECLA F1";}
}
}