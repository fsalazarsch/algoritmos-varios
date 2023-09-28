#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
int mu=0,md=256,pos=0;
int mu2=0,md2=384;
char op[5][17]={" ", "Insertar inicio ",
		     "Insertar medio  ",
		     "Insertar final  ",
						  };
struct nodo {
  char cod[9];
  char nom[20];
  struct nodo *sig;
}nodo,*ptr,*p,*q,*p1,*p2,*nn;
struct nodo *buscar(char inf[9],struct nodo *y),*lee();



void escribe_menup(),ref1(int n,int piso,int color,char s[]),
ref2(int n,int piso,int color,char s[]),fondo(int a,int c,int color),
apagar_c(),menu1(),escribe_menu1(),
ins_principio(struct nodo *),ins_medio(struct nodo *),ins_final(struct nodo *),acerca(), muestra(),borrar();


void piso_color(int,int),marco(int,int,int,int),menu(),le_cod(char *);
char error1(char a[]);

int i;

void menu(void)
{
	 int c;
	 textmode(2);
	 escribe_menup();
	 c=13;
	 gotoxy(4,1);
	 while (c!=45)
	 {
	  switch(c)
	  {
		  case 77:
		  {
			switch(wherex())
			{
				case 4:{
					 ref1(4,WHITE,BLACK,"Insercion");
					 ref2(18,GREEN,BLACK,"Visualizacion");
					 break;
				  }
			  case 18:{
					 ref1(18,WHITE,BLACK,"Visualizacion");
					 ref2(34,GREEN,BLACK,"Eliminar");
					 break;
				  }
			  case 34:{
					 ref1(34,WHITE,BLACK,"ELiminar");
					 ref2(46,GREEN,BLACK,"Salir");
					 break;
				  }
			  case 46:{
					 ref1(46,WHITE,BLACK,"Salir");
					 ref2(4,GREEN,BLACK,"Insercion");
					 break;
				  }
			}
			break;
		  }
		  case 75:
		  {
			switch(wherex())
			{
				case 4:{
					 ref1(4,WHITE,BLACK,"Insercion");
					 ref2(46,GREEN,BLACK,"Salir");
					 break;
				  }
			  case 46:{             
					 ref1(46,WHITE,BLACK,"Salir");
					 ref2(34,GREEN,BLACK,"Eliminar");
					 break;
				  }
			  case 34:{
					 ref1(34,WHITE,BLACK,"Eliminar");
					 ref2(18,GREEN,BLACK,"Visualizacion");
					 break;
				  }
			  case 18:{
					 ref1(18,WHITE,BLACK,"Visualizacion");
					 ref2(4,GREEN,BLACK,"Insercion");
					 break;
					}
			}
			break;
		  }
	  }
	  c=getch();
	  if((c==13)||(c==80))
	  {
	       switch(wherex())
	       {
		  case 4:{
				menu1();
				window(1,1,80,25);
				clrscr();
				escribe_menup();
				break;
			 }
		  case 18:{
			  muestra();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menup();
			  break;
			}
		 case 34:{
			  borrar();
			  window(1,1,80,25);
			  clrscr();
			  escribe_menup();
			  break;
			}

		case 46:{
				  if(c==13)
				  {
					window(1,1,80,25);
					piso_color(BLACK,WHITE);
					clrscr();
					exit(1);
				  }
				 }
			 }
	  }
    }
}
void escribe_menup()
{
	 window(1,1,80,25);
	 textbackground(BLACK);
	 clrscr();
	 gotoxy(1,1);
	 fondo(2,80,LIGHTGRAY);
	 gotoxy(1,25);
	 fondo(2,80,LIGHTGRAY);
	 piso_color(LIGHTGRAY,RED);
	 gotoxy(2,25);
	 cprintf("Alt X:");
	 piso_color(LIGHTGRAY,BLACK);
	 cprintf(" Salir");
	 piso_color(LIGHTGRAY,RED);
	 gotoxy(20,25);
	 cprintf("Esc:");
	 piso_color(LIGHTGRAY,BLACK);
	 cprintf(" Volver al Men£ Principal");
	 piso_color(GREEN,BLACK);
	 gotoxy(4,1);
	 cprintf("Insercion");
	 piso_color(WHITE,BLACK);
	 gotoxy(18,1);
	 cprintf("Visualizacion");
	 gotoxy(34,1);
	 cprintf("Eliminar");
	 gotoxy(46,1);
	 cprintf("Salir");
	 gotoxy(4,1);
	 piso_color(BLUE,WHITE);
	 marco(2,3,78,23);
	 window(1,1,80,25);
	 gotoxy(4,1);
}
void fondo(int a,int c,int color)
{
  int i;
  textcolor(color);
  for(i=a;i<=c;i++)
     cprintf("%c",219);
}

void ref1(int n,int piso,int color,char s[])
{
   gotoxy(n,1);
	piso_color(piso,color);
	
	cprintf("%s",s);
}
void ref2(int n,int piso,int color,char s[])
{
  gotoxy(n,1);
  piso_color(piso,color);
  cprintf("%s",s);
  gotoxy(n,1);
}

void acerca()
{
   window(1,1,80,25);
   piso_color(LIGHTGRAY,WHITE);
   marco(20,10,55,16);
   getch();
}
void menu1()
{
     int sw;
     int c;
     sw=0;
	  escribe_menu1();
	  c = 13;
     while ((c != 27)&&(sw!=1))
     {
	   switch (c)
	   {
	     case 80 : {
			  piso_color (LIGHTGRAY,BLACK);
			  cprintf("%s",op[wherey()]);
			  piso_color (GREEN,BLACK);
			  if (wherey() == 3)
				 gotoxy (2,1);
			  else gotoxy (2,wherey()+1);
			  cprintf ("%s",op[wherey()]);
			  gotoxy (2,wherey());
			  break;
		       }
	     case 72 : {
			  piso_color(LIGHTGRAY,BLACK);
			  cprintf("%s",op[wherey()]);
			  piso_color (GREEN,BLACK);
			  if (wherey() == 1) gotoxy (2,3);
			  else gotoxy (2,wherey()-1);
			  cprintf("%s",op[wherey()]);
			  gotoxy (2,wherey());
			  break;
				 }
	   }
	   c =getch();
	   if(c==13)
	   {
	       switch(wherey())
			 {
		case 1:{  
					 piso_color(BLUE,WHITE);
					 marco(2,3,78,23);
                                         clrscr();
                                         ins_principio(lee());
					 getch();
					 marco(2,3,78,23);
					 escribe_menu1();
					 break;
				 }
		case 2:{
					 piso_color(BLUE,WHITE);
					 marco(2,3,78,23);
                                         ins_medio(lee());
					 getch();
					 marco(2,3,78,23);
					 escribe_menu1();
					 break;
				 }
		case 3:{
					 piso_color(BLUE,WHITE);
					 marco(2,3,78,23);
                                         ins_final(lee());
					 getch();
					 marco(2,3,78,23);
					 escribe_menu1();
					 break;
				 }
	 
	       }
	   }
     }
}
void escribe_menu1()
{
	  int i;
	  piso_color(LIGHTGRAY,WHITE);
	  marco(3,3,20,5);
	  piso_color(LIGHTGRAY,BLACK);
	  for(i=2;i<=3;i++)
	  {
			gotoxy (2,i);
			cprintf("%s",op[i]);
	  }
	  piso_color(GREEN,BLACK);
	  gotoxy (2,1);
	  cprintf("%s",op[1]);
	  gotoxy (2,1);
}

void apagar_c()
{
	union REGS r,r1;
	r.h.ah=1;
	r.h.ch=32;
	int86(0x10,&r,&r1);
}
void le_cod(char cod[8])
{
 char t;
 int s;
do
  {
   t='n';
   piso_color(3,14);
   clrscr();
   cprintf("DIGITE CODIGO DEL ESTUDIANTE: ");
   gotoxy(34,wherey());
   piso_color(1,14);
   cprintf("        ");
   gotoxy(34,wherey());
   scanf("\n");
   gets(cod);
   s=strlen(cod);
   if (s>8)
    {
     t=error1("≠ CODIGO ERRONEO !");
     window(2,8,79,20);
	  clrscr();
     }
     else
     {
       i=0;
       do
       {
        t='n';
        if(!isdigit(cod[i]))
          {
     	    t=error1("≠ CODIGO ERRONEO !");
     	    window(2,8,79,20);
	    clrscr();
     	  }
        i++;
       }while((i<s)&&(t!='s'));
     }
   }while(t=='s');
 piso_color(3,14);
}

struct nodo *lee()
{
 char codigo[9],t;

 char nombre[20];
 le_cod(codigo);
 nn=(struct nodo *)malloc(sizeof(nodo));
       t='a';
      do {
       marco(2,23,78,23);
       clrscr();
       gotoxy(20,1);
       cprintf("INTRODUZCA EL DATO Y PRESIONE ENTER");
       window(2,10,79,20);
       piso_color(3,6);
       cprintf("DIGITE EL NOMBRE: ");
       t='n';
       gotoxy(30,wherey());
       piso_color(1,14);
       cprintf("                                      ");
       gotoxy(30,wherey());
       scanf("\n");
       gets (nombre);
       if (strlen(nombre)>40)
	{ 
	  t=error1("≠ NOMBRE ERRONEO O CADENA MUY LARGA !");
	  window(2,10,79,20);
	  clrscr();
	  }
      }while(t=='s');

 
  strcpy(nn->cod,codigo);
   nn->cod[8]='\x0';
  strcpy(nn->nom,nombre);
  nn->sig=NULL;
  return nn;
}
void muestra()
{
 p=ptr;
 marco(2,3,78,23);
 clrscr();
 gotoxy(4,5);
 while(p!=NULL)
 {
  gotoxy(4,wherey()+1);
  printf("estudiante: %s   %s",p->cod,p->nom);
  p=p->sig;
 }
 getch();
}

struct nodo *buscar(char inf[9],struct nodo *q)
{
   p1=ptr;
 q=p1;
 while(p1!=NULL)
 {
  if (strcmp(inf,p1->cod)==0)
  {
   return p1;
  }
  q=p1;
  p1=p1->sig;
 }
 return p1;

}

char error1(char a[80])
{
 cprintf("%c",7);
 marco(2,23,78,23);
 piso_color(4,14+128);clrscr();gotoxy(20,1);
 cprintf(a);
 delay(1000);
 clrscr();
 piso_color(3,14);
  return ('s');
}

void marco(int a,int b,int c,int d)
{
   int i;
  piso_color(3,1);
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'…');
   for (i=a;i<=c;i++ )
      cprintf("%c",'Õ');
   cprintf("%c",'ª');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
     cprintf("%c",'∫');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",'»');
  for (i=a;i<=c;i++)
     cprintf("%c",'Õ');
 cprintf("%c",'º');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'∫');
  }
  window(a,b,c,d);
}

void piso_color(int piso,int color)
{
   textbackground(piso);
   textcolor(color);
}


void borrar()
{
 char codigo[9];
 le_cod(codigo);
 p=NULL;
 q=NULL;
 p=ptr;
 q=p;
 while(p!=NULL)
 {
  if (strcmp(codigo,p->cod)==0)
  {
   break;
  }
  q=p;
  p=p->sig;
 }
  if (p==NULL)
     {
      error1("no se encontr¢ el codigo...");
     }
     else
     {
      gotoxy(4,5);
      printf("%s    %s",p->cod,p->nom);
 if(p==ptr)
 {
  gotoxy(4,8);
  printf("borrando el primero...");
  ptr=ptr->sig;
  free(p);
  delay(1000);
 }
 else
 {
   if(p->sig==NULL)
   {
    gotoxy(4,8);
    printf("borrando el ultimo...");
    q->sig=NULL;
    free(p);
    delay(300);
   }
   else
   {
     gotoxy(4,8);
      printf("borrando un dato intermedio...");
      q->sig=p->sig;
      free(p);
     delay(300);
     }
   }
 }

}

void ins_principio(struct nodo *n)
{
 n->sig=ptr;
 ptr=n;
}

void ins_final(struct nodo *n)
{
 if (ptr==NULL)
  {
   printf("se insertar† por el principio porque no hay nada en la lista");
   ins_principio(n);
  }
 else
 {

 p2=ptr;
 while(p2->sig!=NULL)
 {
  p2=p2->sig;
 }
 p2->sig=n;


 }

}
void ins_medio(struct nodo *n)
{
 int cont=0,i;
  if ((ptr==NULL)||(ptr->sig==NULL))
  {
   printf("se insertar† por el principio porque no se puede por el medio");
   ins_principio(n);
  }
 else
 {
 p2=ptr;

 while(p2!=NULL)
 {
  cont++;
  p2=p2->sig;
 }
 cont/=2;
 p2=ptr;
 p1=p2;
 i=0;
 while((i<cont)&&(p2->sig!=NULL))
 {
  i++;
  p1=p2;
  p2=p2->sig;
 }
  p1->sig=n;
  n->sig=p2;
 }
}

void main(void)
{
  int i;
 int cont=0;
 clrscr();
 apagar_c();
 textcolor(15);
 gotoxy(22,7);
 cprintf("CORPORACION UNIVERSITARIA DE SANTANDER");
 gotoxy(32,19);
 cprintf("Copyright (c) 1998");
 for(i=70;i>15;i--)
{ textcolor(i+1);

gotoxy(i,9); cprintf("    ⁄ƒƒƒø  ⁄ƒƒƒø  ");
gotoxy(i,10);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,11);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,12);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,13);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,14);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,15);cprintf("    ≥€€€¿ƒƒŸ€€€≥  ");
gotoxy(i,16);cprintf("    ≥€€€€€€€€€€≥  ");
gotoxy(i,17);cprintf("    ¿ƒƒƒƒƒƒƒƒƒƒŸ  ");
delay(10);
}

for(i=70;i>31;i--)
{ textcolor(i+5);
gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒƒø  ");
gotoxy(i,10); cprintf(" ≥€€€€€€‹‹≥  ");
gotoxy(i,11); cprintf(" ≥€€€  ﬂ€€≥  ");
gotoxy(i,12); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,13); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,14); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,15); cprintf(" ≥€€€  ‹€€≥  ");
gotoxy(i,16); cprintf(" ≥€€€€€€ﬂﬂ≥  ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒƒŸ  ");
delay(10);
}                                
for(i=70;i>42;i--)                   
{ textcolor(i+3);


gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒø   ");
gotoxy(i,10); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,11); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,12); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,13); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,14); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,15); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,16); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒŸ   ");
delay(10);
}

for(i=70;i>52;i--)
{ textcolor(i);

gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒø   ");
gotoxy(i,10); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,11); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,12); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,13); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,14); cprintf(" ¿ƒƒƒø€€€≥   ");
gotoxy(i,15); cprintf(" ⁄ƒƒƒŸ€€€≥   ");
gotoxy(i,16); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒŸ   ");
delay(10);
 //marco(17,6,64,21);
 window(1,1,80,25);
}
delay(500);
 clrscr();
 ptr=NULL;
 p1=NULL;
  p2=NULL;

  menu();


}


