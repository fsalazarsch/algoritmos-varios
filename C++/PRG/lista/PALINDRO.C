#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
 void main()
{
char car[40], car1[40],car3[40];
int i;  int sui=0;
int lar;


clrscr();
gotoxy(5,2);printf("***************************************************************");
gotoxy(19,5);
printf("ESCRIBA UNA FRASE:.. ");
gets(car);
lar=strlen(car);
strcpy (car1,car);
strrev(car1);

	 for(i=0;i<=lar-1;i++)
	 {
	    if(car[i]==car1[i]){

	       car3[i]=car1[i];}
	       else{
		if(car[i]==car1[i+1]){

		    car3[i]=car[i]; }
		    
		    else{
		      if(car[i]==car1[i+2]){

			  car3[i]=car[i]; }
			 
			 else{
			      car3[i]=' ';
			      }
			   }
		       }
	 }


		  for(i=0;i<=lar-1;i++){
		  if(car[i]==car3[i]){
		      sui=1;}           
		      else{sui=0;}      }

		  if(sui == 1){
		  gotoxy(15,9);
		  
	 cprintf("**********");
		  cprintf("<<<ESTA FRASE ES PALINDOME>>>");
		  cprintf ("**********");
		  }
				     
		  else {
		  gotoxy(15,12);
		  
		  

			cprintf("<<< ESTA FRASE NO ES PALINDROME>>>"); }
		       gotoxy(25,3);
     cprintf( "************************************************************");
			
getch();}