#include<conio.h>
#include<stdio.h>
#define n  10
void main()
{
  int  aux=0,w=14,z=40;
    int i,j,vec[n];

   clrscr();
   textcolor(9);
  textbackground(5);
  printf("\n\n");
	for(i=1;i<=n;i++)
  {
	scanf("%d",&vec[i]);
	}
     gotoxy(z,13);  printf("**** VECTOR INICIAL***:> ");
  for(i=1;i<=n;i++)
  {
  gotoxy(z+24,10+i) ; printf("[%d]= %d",i,vec[i]);


   }

  for(i=1;i<=(n-1);i++)
  {
   for(j=1;j<=n-i;j++)
    if (vec[j]>vec[j+1])
    {
      aux=vec[j];
      vec[j]=vec[j+1];
       vec[j+1]=aux;

     }
  }
	gotoxy(2,13);
       printf("***EL VECTOR ORDENADO ES*:> ");
       printf("\n\n");
       for(i=1;i<=n;i++)
       {
       //printf("\t");
	gotoxy(w+15,10+i);printf("[%d]= %d",i,vec[i]);

       }
	getche();
}

