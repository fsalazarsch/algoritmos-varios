#include"stdio.h"
#include"conio.h"
#define C clrscr();
#define G gotoxy(15,12);
#define P(K,Q) printf("\n%s%d%s%c\n","tiene  ",K, "  vocal  ", Q);
#define L(w,v) case w: v++;break;
int a,b,c,x,m;
char l;
void cuadro(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     for(j=x1;j<=x2;j++)
       { delay(30);
       gotoxy(j,y1);printf("Í");
       gotoxy(j,y2);printf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       {  delay(30);
       gotoxy(x1,i);printf("º");
       gotoxy(x2,i);printf("º");
       }
     gotoxy(x1,y1);printf("É");
     gotoxy(x2,y1);printf("»");
     gotoxy(x1,y2);printf("È");
     gotoxy(x2,y2);printf("¼");
}
/********************************prog.1*************************/
void main(){
char K,l,c;
int v;
do{textcolor(9); C
cuadro(1,80,1,23);
gotoxy(12,5);  printf("LOS PROGRAMAS REALIZADOS A CONTINUACION FUERON ELABORADOS POR");
gotoxy(12,6);  printf("                      LOS ALUNNOS :\n\n\n");
gotoxy(12,9);  printf("               jose saurith pe¤aloza");
gotoxy(12,10); printf("                     cod:96131139");
gotoxy(12,11); printf("                  GUSTAVO GUTIERREZ");
gotoxy(12,12); printf("                     cod:96131156 ");
gotoxy(12,13); printf("                 BRESNEIDER NARVAEZ EL POLLO");
gotoxy(12,14); printf("                     cod:96131031");
gotoxy(12,15); printf("                OSWALDO RUEDA CARRE¥O");
gotoxy(12,16); printf("                     cod:96131011");
gotoxy(14,20); printf("       INGENIERIA DE SISTEMAS  II SEMESTRE  ");
gotoxy(14,21); printf("   CORPORACION UNIVERSITARIA DE SANTARDER -1996");
gotoxy(2,25);  printf(" DIGITE <0 Y ENTER> PARA CONTINUAR...");
scanf("%d",&v);
 }while(v!=0);
C

     //PROGRAMA QUE REALIZA TODO LOS PROGRAMAS
textcolor(4);C
cuadro(1,80,1,23);
gotoxy(30,4);printf("MENU TRABAJOS LUISA");
gotoxy(19,8);printf("1.  SERIE FIBONACCI");
gotoxy(19,9);printf("2.  SERIE YOVE");
gotoxy(19,10);printf("3.  NUMEROS PARES ENTRE N Y M");
gotoxy(19,11);printf("4.  NUMEROS PRIMOS");
gotoxy(19,12);printf("5.  NUMEROS PRIMOS POR COMPARACION LOGICA");
gotoxy(19,13);printf("6.  NUMEROS PERFECTOS");
gotoxy(19,14);printf("7.  CONTEO DE VOCALES DE UNA PALABRA");
gotoxy(5,24);printf("DIGITE <CUALQUIER LETRA Y ENTER> PARA SALIR");
gotoxy(15,21);printf("DIGITE LA OPCION REQUERIDA...");
scanf("%d",&l);
switch(l){

/********************************prog.1******************************************************/


case(1):
//ESTE PROGRAMA REALIZA LA SERIE FIBONACCI
textcolor(5); C
cuadro(25,53,10,15);gotoxy(32,13);printf("SERIE FIBONACCI...");delay(500);
{

long int p,u,c,k,x,i,n,z;
p=0;
z=0;
u=1;  textcolor(18); C
G printf("INGRESE LA CANTIDAD DE VECES QUE DESEA LA SERIE...");
scanf("%ld",&x);C
while(x>=47)
	  {C
	  G printf("LA SERIE FIBONACCI SE SALE DEL RANGO ESTIMADO....!");
	  delay(1000); C
	  G printf("INGRESE LA CANTIDAD DE VECES QUE DESEA LA SERIE...");
	      scanf("%ld\a",&x);}
	      gotoxy(26,6);printf("LOS NUMEROS DE FIBONACCI SON...\n\n");
for(i=1;i<=x;i++){k=k-50;
     printf("%ld\t",z);
     p=u;
     u=z;
     z=p+u;
     }
     getche();C


} ;break;

/********************************prog.2*******************************************************/


case(2): //ESTE REALIZA LA SERIE LUISA

{
int s,j,i,n;
textcolor(4);C cuadro(25,53,10,15);gotoxy(32,12);printf("CICLO DE LUISA...");delay(1000);C
gotoxy(15,14); printf("INGRESE EL NUMERO DE VECES QUE DESEA EL CICLO:  ");
scanf("%d",&n);
clrscr();
s=1;
j=0;delay(500);
while(j<n){i=1;
	     if(s==1)
		    {
		    while(i<=3){
		    j++;
		    if(j<=n)
		    printf("%20d%20d%20d\n\a",i,4-i,j);
			    i++;
			    }
			    s=s*(-1);}
		    else{
			while(i<=3){
				 j++;
				 if(j<=n)
					 printf("%20d%20d%20d\n\a",4-i,i,j);
					 i++;
					 }
					 s=s*(-1);
					 }
					 }
					 getche();

					 }


	break;

/********************************prog.3***************************************************/


case(3):    //ESTE REALIZA LOS NUMEROS PARES ENTRE n Y m
	{
int n,m;
char a;
n=m=0;
C
do{ cuadro(19,66,10,15);gotoxy(22,13);printf("NUMEROS PARES EXISTENTES ENTRE DOS NUMEROS");delay(1000);C
gotoxy(15,8);printf("DIGITE UN NUMERO  n...");

scanf("%d\n\a\t",&n);
gotoxy(15,11);printf("DIGITE UN NUMERO  m...");
scanf("%d\n\a\t",&m);
if((m==n) || m==(n+1) || n==(m+1)){ printf("no hay pares ");}
else if((m%2)==0 && (n%2)==0 && (n-m)==2) printf("no hay pares");
if((m%2)==0 && (n%2)==0 && (m-n)==2) printf("no hay pares");
if((n%2)!=0 && (m%2)!=0 && (m!=n)){
 /*in  in*/  		     while(n<m){ ++n;
				  printf("%d\t",n);++n;}

			    while(m<n){++m;
				    printf("%d\t",m);++m;}
				   }
if((n%2)==0 && (m%2)!=0 && (m!=n)){ --m;
 /*par in*/		       while(n<m){ n++;
				       if(m==n)break;
				   else printf("%d\t",++n);}

			    while(m<n){m=m+2;
				      if(m==n)break;

				  else printf("%d\t",m);}
				   }
if((n%2)!=0 && (m%2)==0 && (m!=n)){ --n;
 /* in par*/		    while(n<m){ n=n+2;
				       if(m==n)break;
				       printf("%d\t",n);}

			    while(m<n){m++;
				      if(m==n)break;
				      printf("%d\t",++m);}
				   }
if((n%2)==0 && (m%2)==0 && (m!=n)){
/*p p*/			    while(n<m){n=n+2;
				  if(m==n)break;
				  printf("%d\t",n);}

			    while(m<n){ m=m+2;
				if(m==n)break;
				printf("%d\t",m);}
				   }


printf("\n\n\nSi desea continuar ingrese la letra 's' sino  pulse otra  :  ");
a=getche();C

}
while(a=='s'|| a=='S');
}





break;

/********************************prog.4********************************************************/


case(4):
//ESTE REALIZA LOS NUMEROS PRIMOS HASTA ...n
       {int i,a,b,k,x;
C cuadro(25,53,10,15);gotoxy(32,13);printf("NUMEROS PRIMOS...");delay(1000);C
textcolor(4);gotoxy(14,15);printf("INGRESE HASTA DONDE QUIERE LOS NUMEROS PRIMOS...");
scanf("%d",&x);
clrscr();gotoxy(26,6);printf(" LOS NUMEROS PRIMOS SON...\n");delay(900);
i=2;
while (i<=x){
a=2;
b=0;
k=(i/2);
while ((k>=2) & (a<=k)){
      if (i%a==0){
      a=k+1;
      b=1;
}
a+=1;}
if (b==0) printf("%36d\n\a",i);
   i+=1;} printf("DIGITE <ENTER> PARA SALIR");
getche();
}break;
/************************************prog.5***********************************************/

case(5):
{
int a,x,n;n=1; // REALIZA LOS NUMEROS PRIMOS "POR COMPARACION LOGICA"
C cuadro(25,53,10,15);gotoxy(27,13);printf("PRIMOS COMPARACION LOGICA:");delay(1000);C
gotoxy(16,13);printf("INGRESE HASTA DONDE QUIERE LOS NUMEROS PRIMOS...");
scanf("%d",&x);
while(n<x){ n++;if(n==2 || n==3 || n==5 || n==7){ printf("%d\t",n);}
	  if((n%2)!=0 && (n%3)!=0 && (n%5)!=0 && (n%7)!=0){
			printf("%d\t",n);n++;}}
 getche();
	  }break;

/*************************************prog.6****************************************/



case(6):                          //ESTE REALIZA LOS NUMEROS PERFECTOS
{
int N,I,M,l,n,i,m,j,z;
 C cuadro(25,53,10,15);gotoxy(30,13);printf("NUMEROS PERFECTOS..");delay(1000);C
N=1;
  while (N<=1000)
  {I=1;
   M=0;
    while (I<N){
     l=(N%I);
      if (l==0)
       M+=I;
     I++;
    }

   if (M==N) {
       printf("\n");
       printf ("    %d\n", N );
       }N++;
  }
  getche();


}
break;
/************************************prog.8**************************************/
case(7):{


{
char c,nom[30];
int f,n,g,b,d,h;
n=g=b=d=h=0;
C cuadro(25,53,10,15);gotoxy(32,13);printf("CONTEO DE VOCALES...");delay(1000);C
gotoxy(20,13);printf("ESCRIBA EL NOMBRE....");
scanf("%s",&nom);
gets(nom);
for(f=0;f<=30;f++)
 {
    c=nom[f];
   switch(c){
  L('a',n)
  L('A',n)
  L('e',g)
  L('E',g)
  L('i',b)
  L('I',b)
  L('o',d)
  L('O',d)
  L('u',h)
  L('U',h)
  }
   }
  C
 textmode(1);
  textbackground(5);
 C printf("%s\n\n",nom);
  P(n,'a');
  P(g,'e');
  P(b,'i');
  P(d,'o');
  P(h,'u');
  getche();

}break;
}
}

}
