#include<stdio.h>
#include<dos.h>
#include <iostream.h>
#include<conio.h>

 caracol()
{ int mayor,menor,a,b,y,x,m;
  char mat[50][50];
  clrscr();
  printf("DIGITE EL LIMITE DE LA MATRIZ: ");
  scanf("%d",&mayor);
  menor=x=y=0;
  for(a=0;a<mayor;a++)
   for(b=0;b<mayor;b++)
    { printf("DIGITE LOS DATOS [%d,%d]: ",a+1,b+1);scanf("\n");
	 scanf("%c",&mat[a][b]);
    }
 clrscr();
  for(a=menor;a<m;a++)
  { for(b=menor;b<mayor;b++)
    { if(a%2==0)
	 { if(y==menor) x=b;
	else
	{ if(x==menor) break;
	  x--;
	}
	 }
	 else
	 { if(x==mayor-1)
	{ if(y==mayor-1) break;
	  y++;
	}
	else
	{ if(y==0+1) break;
	  y--;
	}
	 }
	 delay(400);
	 gotoxy(x*6+12,y+6); printf("%c",mat[y][x]);

	   }
    if((a+1)%4==0)
    { menor++; mayor--; }
  }
  getche();
}
main()
{
    caracol();
}

