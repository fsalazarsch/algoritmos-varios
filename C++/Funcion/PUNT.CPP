#include "stdio.h"
#include "ctype.h"
#include "conio.h"
#include "string.h"
#include "alvaro.h"
void main()  {

//para apuntar al primer elemento del vector
	char c[100],*p;
	int x,y,sw=1;
	clrscr();
	p=&c[0];
	printf ("Oprima un caracter..\n");
	gets(c);
	x=strlen(c);
	for(y=0;y<x;y++){
	if (isalpha (*p))
	   sw=0;
	 else
	  {sw=1;y=y+x;}
	p++;
	}
	if(sw==0)
	 printf ("Es alfabetico\n");
	else printf ("No es un caracter alfabetico\n");

	getch();

}



