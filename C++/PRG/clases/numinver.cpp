#include<stdio.h>
#include<conio.h>
#include<varios.h>
int num,a,b,c,d;

//este programa invierte un número de tres dígitos.numinver.cpp
main()
{
  centrar(" DIGITE EL NUMERO  DE TRES DIGITOS===> :",6 );
  
  scanf("%d",&num);
  a=num/10;
  b=num%10;
  c=a/10;
  d=a%10;
  //clrscr();
  centrar(" EL NUMERO INVERTIDO  ES:====> ", 10);

  printf("%d%d%d",b,d,c);
  }
