#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
char cad[40], cad1[40],cad3[40];
int j;  int sw=0;
int lon;
textcolor(9);
textbackground(8);
clrscr();
gotoxy(15,5);
printf("Digite una palabra ... ");
gets(cad);
lon=strlen(cad);
strcpy (cad1,cad);
strrev(cad1);

	 for(j=0;j<=lon-1;j++)
	 {
	    if(cad[j]==cad1[j]){

	       cad3[j]=cad1[j];}
	       else{
		if(cad[j]==cad1[j+1]){

		    cad3[j]=cad[j]; }
		    
		    else{
		      if(cad[j]==cad1[j+2]){

			  cad3[j]=cad[j]; }
			 
			 else{
			      cad3[j]=' ';
			      }
			   }
		       }
	 }


		  for(j=0;j<=lon-1;j++){
		  if(cad[j]==cad3[j]){
		      sw=1;}           
		      else{sw=0;}      }

		  if(sw == 1){
		  gotoxy(15,12);
		  cprintf("esta palabra es palindrome");}
		  else {
		  gotoxy(15,12);
		  cprintf("esta palabra no es palindrone\n\n");}
		  gotoxy(15,20);
		  printf("una palabra es  palindrome cuando tiene el mismo significado"); 
getch();
}