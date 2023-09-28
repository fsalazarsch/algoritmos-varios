#include<stdio.h>
#include<dos.h>
#include <iostream.h>
#include<conio.h>
void caracol()
{ int may,men,i,j,x,y,n;
  char mat[10][10];
  clrscr();
  printf("DIGITE EL VALOR DE LA MATRIZ: ");
  scanf("%d",&may);
  men=y=x=0;
  for(i=0;i<may;i++)
   for(j=0;j<may;j++)
    { printf(" ",i+1,j+1);scanf("\n");
	 scanf("%c",&mat[i][j]);
    }
 clrscr();
  for(i=men;i<n;i++)
  { for(j=men;j<may;j++)
    { if(i%2==0)
	 { if(x==men) y=j;
	else
	{ if(y==men) break;
	  y--;
	}
	 }
	 else
	 { if(y==may-1)
	{ if(x==may-1) break;
	  x++;
	}
	else
	{ if(x==0+1) break;
	  x--;
	}
	 }
	 delay(300);
	 gotoxy(y*6+12,x+6);
	  printf("%c",mat[x][y]);

	   }
    if((i+1)%4==0)
    { men++; may--; }
  }
  getche();
}
void main()
{
    caracol();
}

