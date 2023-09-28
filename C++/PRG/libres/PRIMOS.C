
#include<stdio.h>
#include<conio.h>
#include<math.h>
int p,i,n,cont,v,fil,col;
main()
{
clrscr();
for(fil=2;fil<=24;fil++){
gotoxy(2,fil);printf("*");
gotoxy(78,fil);printf("*");
}
for(col=2;col<=78;col++){
gotoxy(col,2);printf("*");
gotoxy(col,24);printf("*");
}
cont=0;
gotoxy(20,8);printf("HASTA QUE NUMERO DESEA LOS PRIMOS: ");
gotoxy(55,8);scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
    for(v=1;v<=i;v++)
    {
    p=i%v;
       if(p==0)
       {
       cont++;
       }
     }
   if(cont<=2)
   {
   printf("%4d",i);

   }
   cont=0;
}
getch();
}