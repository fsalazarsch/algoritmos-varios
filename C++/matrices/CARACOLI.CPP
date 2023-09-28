#include<stdio.h>
#include<dos.h>
#include<conio.h>
//void multi::caracol()
void main()
{ int max,min,i,j,x,k,n;char matriz[100][100];
  clrscr();
  printf("\n     DIGITE EL ORDEN DE LA MATRIZ: ");
  scanf("%d",&max);
  min=k=x=0;
  for(i=min;i<max;i++)
   for(j=min;j<max;j++)
    { printf("      DIGITE EL ELEMENTO [%d,%d]: ",i+1,j+1);scanf("\n\n");
      scanf("%c",&matriz[i][j]);
    }
  n=max*2-1;
  clrscr();
  for(i=min;i<n;i++)
  { for(j=min;j<max;j++)
    { if(i%2==0)
      { if(x==min) k=j;
	else 
	{ if(k==min) break;
	  k--;
	}
      }
      else
      { if(k==max-1) 
	{ if(x==max-1) break;
	  x++;
	}
	else 
	{ if(x==min+1) break;
	  x--;
	}
      }
      delay(300);
      gotoxy(k*6+12,x+3); printf("%c",matriz[x][k]);
    }
    if((i+1)%4==0)
    { min++; max--; }
  }
  getche();
}
