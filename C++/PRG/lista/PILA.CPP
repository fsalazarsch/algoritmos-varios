#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>
char *val_letra(int x1,int y1);
char *val_num2(int x1,int y1);
char nu[1];char ls[1];
void cuadros(int x1,int x2,int y1,int y2);
char *val_num2(int x1,int y1)
{  int kt,l,sw;
   do{
       do{
	   gotoxy(x1,y1);
	   clreol();sw=0;
	   cin>>nu;
	   l=strlen(nu);
	   if(l!=1)
	    sw=1;
	 }while(l!=1);
	 sw=0;
	 for(kt=0;kt<l;kt++)
	 if(!isdigit(nu[kt]))
	 sw=1;
       }while(sw==1);
       return(nu);
}
//****************************
char *val_letra(int x1,int y1)
{  int ktt,ll,swt;
   do{
       do{
	   gotoxy(x1,y1);
	   clreol();swt=0;
	   cin>>ls;
	   ll=strlen(ls);
	   if(ll!=1)
	    swt=1;
	 }while(ll!=1);
	 swt=0;
	 for(ktt=0;ktt<ll;ktt++)
	 if(!isdigit(ls[ktt]))
	 swt=1;
       }while(swt==1);
       return(ls);
}


void main(int x1,int x2,int y1,int y2){

int n,tope,max,pila[12],k,t,tt;
  int j,i,c;

   
int p=0;
   clrscr();{
  textcolor(14);textbackground(3);   
   
   gotoxy(25,9);
     {
 do{   cout<<"INSERTE LA LONGITUD DE LA PILA..";
       val_num2(57,9);  //validacion del tama¤o de la pila
       t=atoi(nu);
       if (t<=11){max=atoi(nu);p=1;}
       else {p=0;clrscr();}
   }while(p==0);
       tope=1;
       while (tope<=max)
	 {
	   clrscr();
	   gotoxy(26,12);
	   cout<<"INGRESE EL DATO "<<tope<<":";
	 val_letra(44,12);  //llamado de la validacion dentro de la pila
	   tt=atoi(ls);
	   pila[tope]=tt;
	   tope+=1;
	  }
	  clrscr();
       tope=max;
      textcolor(4);
       gotoxy(10,11);
void cuadros(int x1,int x2,int y1,int y2);
textmode(4);
 textcolor(14);textbackground(3);
 gotoxy(12,10); cout<<" LA PILA GRAFICADA ES ... :    "; getche();
  gotoxy(22,12);
  cout<<"ÉÍÍÍ»\n";
  while(tope!=0)
    {
      printf("                     º");
      textcolor(2);
      cprintf("%d ",pila[tope]);
      printf(" º\n");
      if(tope!=1)
	{
	  printf("                     ÌÍÍÍ¹\n");
	 }
	 else
	   printf("                     ÈÍÍÍ¼");
	   tope-=1;
     }
   }
       getch();

}

}
/*******************************************************************/
void cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(1);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     textcolor(14);textbackground(1);
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");

}

