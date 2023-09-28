#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

struct lista
{ int n;
  struct lista *sig;
}*ptr=NULL,*nn,*p,*pp;
int num,numero,sw;

void menu2(),menu();
void marco(int x1,int y1,int x2,int y2);
void adic_1(),adic_2(),adic_3(),adic_4();
void eliminar();
void visualizar();

void main()
{ menu();
}



void menu2()
{ char op;
  do
  { window(1,1,80,25);
    clrscr();
    marco(5,3,75,22);
    marco(10,5,70,20);
    marco(12,6,68,19);

    gotoxy(35,7);printf("  MENU 2");
    gotoxy(15,9);printf("1. Al principio");
    gotoxy(15,10);printf("2. Al final");
    gotoxy(15,11);printf("3. Despues de...");
    gotoxy(15,12);printf("4. Antes de...");
    gotoxy(15,13);printf("5. Regresar");
    gotoxy(22,15);printf("digite su opcion: [ ]" );
    do
    { window(41,15,41,15);clreol(); op=getch();
    }while((op>'5') ||(op<'1'));
    window(12,6,68,19);
    switch(op)
    { case'1':{ adic_1(); break; }
      case'2':{ adic_2(); break; } 
      case'3':{ adic_3(); break; } 
      case'4':{ adic_4(); break; } 
    }          
  }while(op!='5');
}

void menu()
{ char op;
  do
  { window(1,1,80,25);
    clrscr();
    marco(5,3,75,22);
    marco(10,5,70,20);
    marco(12,6,68,19);
    gotoxy(35,7);printf("  MENU  ");
    gotoxy(15,9);printf("1.INTRODUCIR");
    gotoxy(15,10);printf("2.VISUALIZAR");
    gotoxy(15,11);printf("3.ELIMINAR");
    gotoxy(15,12);printf("4.SALIR");
    gotoxy(22,14);printf("digite su opcion: [ ]" );
    do
    { window(41,14,41,14);clreol(); op=getch();
    }while((op>'4') ||(op<'1'));
    window(12,6,68,19);
    switch(op)
    { case'1':{ menu2(); break; }
      case'2':{ visualizar(); break; } 
      case'3':{ eliminar(); break; } 
    }          
  }while(op!='4');
}



void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);} 
  }

/****************************************************************/

void adic_1()
{ clrscr();
  printf("Digite un Numero: ");
  scanf("%d",&num);
  nn=new lista;
  nn->n=num;
  nn->sig=NULL;
  if(ptr==NULL)
   ptr=nn;
  else
  { nn->sig=ptr;
    ptr=nn;
  }
  printf("Numero insertado por el principio.");
  getche(); 
}


void adic_2()
{ clrscr();
  printf("Digite un Numero: ");
  scanf("%d",&num);
  nn=new lista;
  nn->n=num;
  nn->sig=NULL;
  if(ptr==NULL)
   ptr=nn;
  else
  { p=ptr;
    while(p->sig!=NULL) p=p->sig;
    p->sig=nn;
  }
  printf("Numero insertado por el final.");
  getche(); 
}



void adic_3()
{ clrscr();
  printf("Digite el numero despues de: ");
  scanf("%d",&num);
  p=ptr; sw=0;
  while(p!=NULL)
  { if(p->n==num)
    { sw=1; break; }
    p=p->sig;
  }
  if(sw==0) printf("\nEl elemento no existe");
  else
  { printf("Digite un Numero: ");
    scanf("%d",&numero);
    nn=new lista;
    nn->n=numero;
    nn->sig=p->sig;
    p->sig=nn;
    printf("\nNumero insertado despues de %d",num);
  }
  getche(); 
}


void adic_4()
{ clrscr();
  printf("Digite el numero antes de: ");
  scanf("%d",&num);
  p=ptr; sw=0;
  while(p!=NULL)
  { if(p->n==num)
    { sw=1; break; }
    pp=p;
    p=p->sig;
  }
  if(sw==0) printf("\nEl elemento no existe");
  else
  { printf("Digite un Numero: ");
    scanf("%d",&numero);
    nn=new lista;
    nn->n=numero;
    nn->sig=pp->sig;
    pp->sig=nn;
    printf("\nNumero insertado antes de %d",num);
  }
  getche(); 
}


void eliminar()
{ clrscr();
  printf("Digite un numero: ");
  scanf("%d",&num);
  p=ptr; sw=0;
  while(p!=NULL)
  { if(p->n==num)
    { sw=1; break; }
    pp=p;
    p=p->sig;
  }
  if(sw==0) printf("\nEl elemento no existe");
  else
  { pp->sig=p->sig;
    p->sig=NULL;
    free(p);
    printf("\nNumero Eliminado");
  }
  getche(); 
}


void visualizar()
{ clrscr();
  if(ptr==NULL) 
   printf("La lista esta Vacia");
  else
  { p=ptr;
    while(p!=NULL)
    { printf("  %d",p->n);
      p=p->sig;
    }
  }
  printf("\nVisualizacion Completada");
  getche();
}


