#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<io.h>
void invertir();
void invertir()
{
int v[20],i,n,aux;
clrscr();
textcolor(15+129);
textbackground(3);
gotoxy(15,1);
gotoxy(4,4);
printf("DIGITE DIMENSION DEL VECTOR: ");
scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      scanf("%d",&v[i]);
    }
       printf("  ");
       printf("  ");
      for(i=1;i<=n;i++)
      {
       printf("  ");
       printf("%d",v[i]);
       }
       aux=0;
	 for(i=1;i<=n/2;i++)
	 {
	 aux=v[i];
	 v[i]=v[(n+1)-i];
	 v[(n+1)-i]=aux;
	 }
       
	 printf(" \n");
	 printf(" \n ");
	 printf("vector invertido==>");
	 printf("  ");
	 printf("  ");
	   for(i=1;i<=n;i++)
	   {
	   printf("  ");printf("%d \t",v[i]); 
	   }
	   textcolor(4+214);
	  gotoxy(18,25);printf("  ");
	   getch();
	 }

void palindrome();
void palindrome()
{
char v[10];
int i,lon,sw=0;
clrscr();
printf("digite una palabra : ");
gets(v);
lon=strlen(v);
lon=lon-1;
for(i=0;i<=lon;i++)
if(v[i]==v[lon-i])
sw=0;
else
{
sw=1;
break;
}
if(sw==0)
printf("la palabra es palindrome");
else
printf("la aploabra no es palindrome");
getch();
}
void ordenar();
void ordenar()
{
 
  int n,i,j,aux,v[10];
  clrscr();
  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   clrscr();
   gotoxy(2,3);
   for ( i=0;i<n;i++)
    {
     printf("%d \t",v[i]);
    }

   for(i=0;i<n;i++)
   {
       for(j=i+1;j<n;j++)
	{
	  if(v[i]>v[j])
	  {
	    aux=v[i];
	    v[i]=v[j];
	    v[j]=aux;
	  }
       }
    }
    gotoxy(2,5);
      for ( j=0;j<n;j++)
    {
     printf("%d \t",v[j]);
    }
getch();
}
void sumavec();
void sumavec()
{

  int i,v[10],n,suma=0;
  float j;
  clrscr();
  gotoxy(2,6);
  printf("Digite el tama§o del vector.... ");
  scanf("%d",&n);

  for ( i=0;i<n;i++)
    {
    printf("Digite la posici¢n [ %d %s",i+1," ] ...");
    scanf("%d",&v[i]);
       suma = suma + v[i];
    }
   
    clrscr();
    gotoxy(3,8);
    for ( i=0;i<n;i++)
    {
     printf("%d \t",v[i]);
    }
    gotoxy(6,12);
     printf("La sumatoria del vector es %d ",suma);
     getch();
 }

void dos();
void dos()

{
  int n,i,v[10],v2[10],v3[10];
  clrscr();
  gotoxy(2,3);
  printf("DIGITE EL TAMA•O DE LOS DOS VECTORES.... ");
  scanf("%d",&n);

  for ( i=0;i<n;i++)
    {
       printf("Digite la posici¢n [ %d %s",i+1," ] ...");
       scanf("%d",&v[i]);
    }
  for ( i=0;i<n;i++)
    {
       printf("Digite la posici¢n [ %d %s",i+1," ] ...");
       scanf("%d",&v2[i]);
    }
   for ( i=0;i<n;i++)
    {
      v3[i] = v[i] + v2[i];
    }
    clrscr();
    gotoxy(2,3);
    for ( i=0;i<n;i++)
    {
     printf("%d \t",v[i]);
    }
    gotoxy(2,5);
    for ( i=0;i<n;i++)
    {
     printf("%d \t",v2[i]);
    }
    gotoxy(2,7);
    for ( i=0;i<n;i++)
    {
     printf("%d \t",v3[i]);
    }
    getch(); 
}
 void pos();
 void pos()
 {
 int vec[10],n,f,x;
  clrscr();
   gotoxy(30,3);printf("PROGRAMA SUMA DE POSICIONES\n");
   printf("digiten los valores del vector\n");

   for(f=0;f<=9;f++)
   {
      scanf("%d",&n);
      vec[f]=n;
   }
    gotoxy(10,15); printf("LAS POSICIONES DE LOS NUMEROS PARES SON\n");
     for(f=0;f<=9;f++)
     {
       
       if((vec[f]%2)==0)
	{
	printf("%2d",f);
	}
	
     }
   gotoxy(10,21); printf("LAS POSICIONES DE LOS NUMEROS IMPARES SON\n");
     for(f=0;f<=9;f++)
     {
       if((vec[f]%2)!=0)
       {
	printf("%2d",f);
       }
     } 
    getch();

 }
void matrisum();
void matrisum()
{
int mat[10][10],sum,c,f;

   clrscr();
   printf("suma de matrises");
   for(c=0;c<=3;c++)
   {
      for(f=0;f<=3;f++)
      {

	 scanf("%d",&mat[c][f]);
	   sum=mat[c][f]+sum;
      }
    }
    for(c=0;c<=3;c++)
    {
      for(f=0;f<=3;f++)
      {
	printf("%4d",mat[c][f]);
	
      }
    }
     gotoxy(15,15); printf("la sumatoria de la matriz es: %d ",sum);
      getch();
}
void diagonal();
void diagonal()
{
int mat[4][4],f,c,sum;

   clrscr();
   gotoxy(30,3);printf("programa matriz\n");
   for(c=0;c<=3;c++)
   {
      for(f=0;f<=3;f++)
      {
	 scanf("%d",&mat[f][c]);
	 if(c==f)
	   sum=mat[c][f]+sum;
      }
    }
    for(c=0;c<=3;c++)
    {
      for(f=0;f<=3;f++)
      {
	printf("%4d",mat[c][f]);
	
      }
    }
     gotoxy(15,15); printf("la sumatoria de la diagonal es: %d ",sum);
      getch();
}
void superior();
void superior()
{
  int v[4][4];
int i,j,m,a,sum;
clrscr();
printf("INTRODUZCA VALORES DE LA  MATRIZ");

 for(i=1;i<=4;++i){
    for (j=1;j<=4;++j){
       gotoxy(j*4+3,i+5);
	 scanf("%d",&a);
	   gotoxy (j*3+4,i+5);
	 v[i][j]= a;

	 }
       }
    for (i=1;i<=4;++i){
	for (j=1;j<=4;++j){
	     if(i<j)
	       sum=sum+v[i][j];
	       }
	      }
	     gotoxy(20,20);printf("LA SUMA DE LA DIAG.SUPERIOR:%d",sum/2);
	     getche();
	     }
 void inferior();
 void inferior()
 {
int v[4][4];
int i,j,m,a,sum;
clrscr();

printf("INTRODUZCA VALORES DE LA  MATRIZ");

 for(i=1;i<=4;++i){
    for (j=1;j<=4;++j){
       gotoxy(j*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (j*3+4,i+5);
	 v[i][j]= a;
			   
	 }
       }
    for(i=1;i<= 4;++i){
	for(j=1;j<=4;++j){
	     if(i>j)
	       sum=sum+v[i][j];
	       }
	      }
	     gotoxy(30,4);printf("LA SUMA DE LA DIAG.INFERIOR:%d",sum);
	     getche();
	     }

/****************************MENU PRINCIPAL*****************************/
 void main()
{
 char op;
 clrscr();
  while(1)
  {
      clrscr();
     // marco(2,1,79,25);
      textcolor(15);textbackground(3);
      gotoxy(24,2);cprintf( "  M E N U   P R I N C I P A L     ");
      gotoxy(19,3);cprintf( "  **********************************     ");
      textcolor(12);
      gotoxy(22,5);cprintf (" EJERCICIOS UTILISANDO VECTORES      ");
      gotoxy(25,7);cprintf (" A... INVERTIR       ");
      gotoxy(25,8);cprintf (" B... PALINDROME   ");
      gotoxy(25,9);cprintf (" C... ORDENAR  ");
      gotoxy(25,10);cprintf(" D... SUMA DE LOS ELEMNTES DE UN VECTOR   ");
      gotoxy(25,11);cprintf(" E... SUMA DE DOS VECTORES  ");
      gotoxy(25,12);cprintf(" F... POSICIONES DE LOS PARES E INPARES  ");
      textcolor(8);
      gotoxy(15,13);cprintf(" ‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹");
      textcolor(9);
      gotoxy(28,15);cprintf(" EJERCICIOS UTILISANDO MATRICES  ");
      gotoxy(25,17);cprintf(" G... SUMA DE UNA MATRIZ");
      gotoxy(25,18);cprintf(" H... DIAGONAL   ");
      gotoxy(25,19);cprintf(" I... SUMA SUPERIOR DE LA MATRIZ ");
      gotoxy(25,20);cprintf(" J... SUMA INFERIOR DE LA MATRIZ  ");
      textcolor(4+BLINK);  
      gotoxy(20,24);cprintf(" *..... PRECIONE ESC SI DESEA RETORNAR AL PROGRAMA.....*   ");
      op=getche();     
       textcolor(4);  
      switch(op)
      {  case 'a':{clrscr(); invertir();sound(440);delay(500);nosound();break;}
	 case 'A':{clrscr(); invertir();sound(440);delay(500);nosound();break;}
	 case 'b':{clrscr(); palindrome();sound(440);delay(500);nosound();break;}
	 case 'B':{clrscr(); palindrome();sound(440);delay(500);nosound();break;}
	 case 'C':{clrscr(); ordenar();sound(440);delay(500);nosound();break;}
	 case 'c':{clrscr(); ordenar();sound(440);delay(500);nosound();break;}
	 case 'D':{clrscr(); sumavec();sound(440);delay(500);nosound();break;}
	 case 'd':{clrscr(); sumavec();sound(440);delay(500);nosound();break;}
	 case 'e':{clrscr(); dos();sound(440);delay(500);nosound();break;}
	 case 'E':{clrscr(); dos();sound(440);delay(500);nosound();break;} 
	 case 'F':{clrscr(); pos();sound(440);delay(500);nosound();break;} 
	 case 'f':{clrscr(); pos();sound(440);delay(500);nosound();break;}
	 case 'G':{clrscr(); matrisum();sound(440);delay(500);nosound();break;} 
	 case 'g':{clrscr(); matrisum();sound(440);delay(500);nosound();break;}
	 case 'H':{clrscr(); diagonal();sound(440);delay(500);nosound();break;}
	 case 'h':{clrscr(); diagonal();sound(440);delay(500);nosound();break;}
	 case 'i':{clrscr(); superior();sound(440);delay(500);nosound();break;}
	 case 'I':{clrscr(); superior();sound(440);delay(500);nosound();break;}
	 case 'J':{clrscr(); inferior();sound(440);delay(500);nosound();break;}
	 case 'j':{clrscr(); inferior();sound(440);delay(500);nosound();break;}
	 case  27:  sound(440);delay(300);nosound();  exit(0);
       }
   }

  }
