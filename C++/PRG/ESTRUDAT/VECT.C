#include <stdio.h>
int v[15],i,j,aux;
void main()
{
clrscr();
for (i=1;i<=15;i++){
  printf("Digite la posicion %d   ",i);
  scanf ("%d",&v[i]);
}
 for (i=1;i<=15;i++){
  for (j=i+1;j<=15;j++){
     if (v[i] > v[j]) {
	aux=v[i];
	v[i]=v[j];
	v[j]=aux;
     }
  }
}
printf ("\n\nEste el el vector ordenado\n\n");
for (i=1;i<=15;i++)
  printf("%d  ",v[i]);
getche ();


}