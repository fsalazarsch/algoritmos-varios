#include<stdio.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<io.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

char valido,cod[20];
int i;
int lon,st;
int sw,aux,aux2;
int ld1,ld2; /*******  Descriptores de archivo  *******/
long num;
float valor;
   int i,j,aux,n,a[50];
/**************************************************************************/
/****************  DECLARACION  DE  FUNCIONES *****************************/
/**************************************************************************/
void metodo_de_burbuja();
void metodo_de_insercion();
void el_shell_sort();
void el_quick_sort();
void el_radix_sort();
void captura();
//void elemento_mayor();
//void menu();
//void main()
//{
  //menu();
//}
/**************************************************************************/
/*********************  M E N U     P R I N C I P A L *********************/
/**************************************************************************/
void main()
{
 int op,i;
 char SALIR,tecla;
 do
 {
  SALIR='N';
  for(i=1;i<25;i++)
  {
   textcolor(15);
   gotoxy(4,i);cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл"); /** ALT 219 **/
  }
  textbackground(9);
  window(4,3,79,5);
  clrscr();
  textbackground(RED);
  window(2,2,77,4);
  clrscr();
  textcolor(15);
  gotoxy(24,2);cprintf("M E N U     P R I N C I P A L");
  textbackground(9);
  window(4,22,79,24);
  clrscr();
  textbackground(RED);
  window(2,21,77,23);
  clrscr();
  gotoxy(10,3);printf("UTILICE LAS TECLAS (%c%c) DEL CURSOR Y PRESIONE Ў ENTER Џ ",24,25);
  textbackground(9);
  window(24,9,59,18);
  clrscr();
  textbackground(RED);
  window(22,8,57,17);
  clrscr();
  gotoxy(4,2);cprintf("   METODOS DE ORDENAMIENTO ");
  gotoxy(4,4);cprintf("1. METODO DE CAPTURA ");
  gotoxy(4,5);cprintf("2. METODO DE BURBUJA ");
  gotoxy(4,6);cprintf("3. EL SHELL SORT ");
  gotoxy(4,7);cprintf("4. EL QUICK SORT ");
  gotoxy(4,8);cprintf("5. EL RADIX SORT ");
  gotoxy(4,9);cprintf("6. SALIR DEL MENU ");
//  gotoxy(4,9);cprintf("7. SALIR DEL MENU");
  textcolor(15);
  gotoxy(2,4);cprintf("%c",2);
  gotoxy(2,4);
  do
  {
   tecla=getch();
   if(tecla==72)
   {
    printf("  ");
    if(wherey()==3)
    {
     gotoxy(2,wherey()+6);
     cprintf("%c",2);
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()-1);cprintf("%c",2);
     gotoxy(2,wherey());
    }
   }
   if(tecla==80)
   {
    printf("  ");
    if(wherey()==9)
    {
     gotoxy(2,wherey()-6);cprintf("%c",2);
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()+1);
     cprintf("%c",2);
     gotoxy(2,wherey());
    }
  }
 } while(tecla!=13);

  op=wherey();
  if(op==9)
  {
   SALIR='S';
  }
  else
  {
   switch(op)
   {
    case 4:captura();break;
    case 6:metodo_de_burbuja();break;
    //case 3:{el shell sort();break();}
    //case 4:{el quick sort();break();}
    //case 5:{el radix sort();break();}
     case 7:exit(0);break;
    //  gotoxy(4,9);cprintf("7. SALIR DEL MENU");
    //textcolor(15);adicionar();break;}

   };
  }
 }while(SALIR!='S');
}

void captura(){ clrscr();
printf("DIGITE CANTIDAD DEL VECTOR::>");
scanf("%d",&n);

 for(i=1;i<=n;i++){
    printf("DIGITE UN NUMERO#::>");
    scanf("%d",&a[i]);
		  }
      getche();
 }
void metodo_de_burbuja(){
	   for(i=1;i<=n;i++)
	    i=1;
	   while(i<n){
	       j=i+1;
	     while(j<=n){
	       if (a[i] > a[j]){
		 aux=a[i];
		 a[i]=a[j];
		 a[j]=aux;
				}
		 j++;    }
		 i++; }
	 printf("VECTOR ORDENADO\n\n");
 for(i=1;i<=n;i++){
    printf("%d \n",a[i]);
		  }
}

