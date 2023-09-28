#include "stdio.h"
#include "fcntl.h"
#include "io.h"
#include "conio.h"
#include "string.h"
#include "dos.h"

struct
{ char cod[10];
  char nom[15];
  char ape[15];
}reg1;

/**********************************************************************/

struct
{  char cod2[11];
   float not1;
   float not2;
   float not3;
   float not4;
   float def;
}reg2;

/**********************************************************************/

void per_mat();

void escribe_menu();
void leer1();
void menu();
void crea1();
void evalua_codigo();
void crea2();
void vis_inf();
void eliminar();
leer(float a,int x1,int x2);

char op[8][35]={"","INTRODUCIR ESTUDIANTE   ","2_VISUALIZAR ESTUDIANTE ","3_ELIMINAR ESTUDIANTE   ","4_SALIR                "};
char cod[10],viejonom[15],nuevonom[15],c[2];
int id1,aux,sw,id2,id3,id4,n;

/**********************************************************************/

void m(char p[20])
	{window(2,23,79,23);
	      clrscr();textcolor(1+BLINK);
	      gotoxy(25,1);cprintf("%s",p);delay(1500);
	      clrscr();
	      window(2,8,79,23);  textcolor(1);
	 }


/**********************************************************************/

void crea1()
{
 if((id1=_open("a:\\datos.dat",2))==-1)
    if((id1=_creat("a:\\datos.dat",0))==-1)
	{ m("!ERROR EN CREACION 1!");menu();}

 _close(id1);
}

/**********************************************************************/

void crea2()
{ if((id2=_open("a:\\notas.dat",2))==-1)
    if((id2=_creat("a:\\notas.dat",0))==-1)
	{ m("!ERROR EN CREACION 2!");  menu();}
 _close(id2);
}
/**********************************************************************/

void evalua_codigo()
{  int i;
    do
    { do
       { window(2,8,79,23);
	 gotoxy(19,1);
	 clreol();
	 gets(cod);
	 if((n=strlen(cod))!=8) { m("!CODIGO ERRADO!");}
	}while(n!=8);sw=0;
      for(i=0;i<n;i++)
	if(isdigit(cod[i])==0) sw=1;
	if(sw==1) {  m("!CODIGO ERRADO!"); gotoxy(19,1);clreol(); }
    }while(sw==1);
    window(2,23,79,23);
    clrscr();
    window (2,8,79,23);

    sw=0;
    while(!eof(id1))
     { if(_read(id1,&(reg1.cod),sizeof(reg1.cod))!=sizeof(reg1.cod))
	 { m("!ERROR EN LECTURA!");
	   menu();
	 }
	 if(!strcmp(cod,reg1.cod))
	   {  sw=1; m("!EL CODIGO YA EXISTE!");
	      menu();
	   }
     }
     if(sw==0) strcpy(reg1.cod,cod);
}

/**********************************************************************/

void leer1()
{  if((id1=_open("a:\\datos.dat",O_RDWR))==-1)
      {  m("!ERROR EN APERTURA!");
	 menu();
      }
     if((id2=_open("a:\\notas.dat",O_RDWR))==-1)
      {  m("!ERROR EN APERTURA!");
	  menu();
      }
/* do
 {*/  lseek(id1,0l,0);
    lseek(id2,0l,0);
    clrscr();
   printf("digite el codigo: ");
   evalua_codigo();
   printf("\n digite el nombre: ");
   do
     { gotoxy(19,2);
       gets(reg1.nom);
	 if((n=strlen(reg1.nom))>15) { m("!NOMBRE FUERA DE RANGO!");gotoxy(19,2); clreol(); }
       }while(n>15);
   printf("digite el apellido: ");
   do
     { gotoxy(21,3);
       gets(reg1.ape);
	 if((n=strlen(reg1.ape))>15) { m("!APELLODO FUERA DE RANGO!");gotoxy(21,3); clreol(); }
       }while(n>15);
   printf("digite la primera nota: ");
   do
   {
    gotoxy(25,4);sw=0;
    scanf("%f",&reg2.not1);
    if((reg2.not1>5)||(reg2.not1<0))
      { m("!NOTA FUERA DE RANGO!"); gotoxy(25,4);clreol();sw=1; }
      else {gotoxy(25,4); clreol(); printf("%.2f",reg2.not1);}
   }while(sw==1);

   printf("\ndigite la segunda nota: ");
    do
   {
    gotoxy(25,5);sw=0;
    scanf("%f",&reg2.not2);
    if((reg2.not2>5)||(reg2.not2<0))
      { m("!NOTA FUERA DE RANGO!");gotoxy(25,5); clreol();sw=1; }
    else {gotoxy(25,5); clreol(); printf("%.2f",reg2.not2);}
   }while(sw==1);

   printf("\ndigite la tercera nota: ");
     do
   {
    gotoxy(25,6);sw=0;
    scanf("%f",&reg2.not3);
    if((reg2.not3>5)||(reg2.not3<0))
      { m("!NOTA FUERA DE RANGO!");gotoxy(25,6); clreol();sw=1; }
      else {gotoxy(25,6); clreol(); printf("%.2f",reg2.not3);}
   }while(sw==1);

    printf("\ndigite la cuarta nota: ");
     do
   {
    gotoxy(25,7);sw=0;
    scanf("%f",&reg2.not4);
    if((reg2.not4>5)||(reg2.not4<0))
      { m("!NOTA FUERA DE RANGO!");gotoxy(25,7); clreol();sw=1; }
      else {gotoxy(25,7); clreol(); printf("%.2f",reg2.not4);}
   }while(sw==1);

     reg2.def=(reg2.not1*.25+reg2.not2*.25+reg2.not3*.2+reg2.not4*.3);

     printf("\ndefinitiva: %.2f",reg2.def);
       strcpy(reg2.cod2,reg1.cod);

     if(_write(id1,&(reg1),sizeof(reg1))!=sizeof(reg1))
       { m("!ERROR EN GREBACION 1!");menu();}
     lseek(id2,0l,2);
     if(_write(id2,&(reg2),sizeof(reg2))!=sizeof(reg2))
      {  m("!ERROR EN GRABACION 2!");
	  menu();
      }
      _close(id1);
   _close(id2);
/*   printf("\ndesea ingresar otro estudiante [s/n]: ");scanf("\n");
   gets(c);

 }while(strcmp(strupr(c),"S")==0);
  */
 menu();
}

/**********************************************************************/

void vis_inf()
{   if((id1=_open("a:\\datos.dat",O_RDWR))==-1)
       {m("!ERROR EN APERTURA!");menu();}
    if ((id2=_open("a:\\notas.dat",O_RDWR))==-1)
       {m("!ERROR EN APERTURA!");menu();}
 do
 {  lseek(id1,0l,0);   sw=0;
    lseek(id2,0l,0);
    clrscr();
    printf("*digite codigo");  scanf("\n");
    gets(cod);
    if (eof(id1)) { m("!ARCHIVO VACIO!");break;menu();}
    while(!eof(id1))
    {
       if (_read(id1,&(reg1),sizeof(reg1))!=sizeof(reg1))
       {
	       m("!ERROR EN LECTURA!");break;menu();}
	if  (!strcmp(cod,reg1.cod))
	 {
	    clrscr();sw=1;
	    printf("COD: %s\n",reg1.cod);
	    printf("NOM(s): %s\n",reg1.nom);
	    printf("APE(s): %s\n",reg1.ape);

	  }
     } if(sw==0) { m("!CODIGO NO EXISTENTE!"); _close(id1);_close(id2);break; menu();}
     while(!eof(id2))
		 { if(_read(id2,&(reg2),sizeof(reg2))!=sizeof(reg2))
		   {  m("!ERROR EN LECTURA!");break;menu();
		   }
		   if(!strcmp(cod,reg2.cod2))
		     { printf("NOT 1: %.2f",reg2.not1);
		       printf("\n");
		       printf("NOT 2: %.2f",reg2.not2);
		       printf("\n");
		       printf("NOT 3: %.2f",reg2.not3);
		       printf("\n");
		       printf("NOT 4: %.2f",reg2.not4);
		       printf("\n");
		       printf("DEF: %.2f",reg2.def);
		       printf("\n");
		     }
     }
   printf("\nDESEA VISUALIZAR OTRO [s/n]: ");scanf("\n");
   gets(c);

 }while(strcmp(strupr(c),"S")==0);

_close(id1);_close(id2);
menu();
}

/**********************************************************************/

void eliminar()
{  do
     { sw=0;
       if((id3=_creat("a:\\aux1.dat",0))==-1)
	{ m("!ERROR EN CREACION 3!");break; menu();}
      if((id4=_creat("a:\\aux2.dat",0))==-1)
	{ m("!ERROR EN CREACION 4!");break;menu();}
      _close(id3);_close(id4);

       if((id1=_open("a:\\datos.dat",O_RDWR))==-1)
       {m("!ERROR EN APERTURA!");break;menu();}
      if ((id2=_open("a:\\notas.dat",O_RDWR))==-1)
      {  m("!ERROR EN APERTURA!");break;menu();}

       if((id3=_open("a:\\aux1.dat",O_RDWR))==-1)
       {m("!ERROR EN APERTURA!");break;menu();}
      if ((id4=_open("a:\\aux2.dat",O_RDWR))==-1)
      {  m("!ERROR EN APERTURA!");break;menu();}
     clrscr();
      printf("**digite el codigo: "); scanf("\n");gets(cod);
      if (eof(id1)) { m("!ARCHIVO VACIO!");break;  menu();}
      lseek(id1,0L,0);
      lseek(id2,0L,0);
    while(!eof(id1))
    {
       if (_read(id1,&(reg1),sizeof(reg1))!=sizeof(reg1))
       {
	       m("!ERROR EN LECTURA!");break; menu();
	}
	if  (strcmp(cod,reg1.cod)!=0)
	 {  if(_write(id3,&(reg1),sizeof(reg1))!=sizeof(reg1))
	     {  m("!ERROR EN GRABACION!");break;
	       menu();
	 }   }
	else sw=1;
     }  unlink("a:\\datos.dat");

     _close(id3);
     rename("a:\\aux1.dat","a:\\datos.dat");
     _close(id1);
     if(sw==0){ m("!NO ESTA EL CODIGO!"); unlink("a:\\aux2.dat"); _close(id2);break;
	      menu();}

     while(!eof(id2))
    {
       if (_read(id2,&(reg2),sizeof(reg2))!=sizeof(reg2))
       {   ("!ERROR EN LECTURA!"); menu();break;
	}
	if  (strcmp(cod,reg2.cod2)!=0)
	   if(_write(id4,&(reg2),sizeof(reg2))!=sizeof(reg2))
	     {  m("!ERROR EN GRABACION!");break;
		menu();
	     }
	}  if(unlink("a:\\notas.dat"))  m("!ALUMNO NO ELIMINADO!");
       else m("!ALUMNO ELIMINADO!");
		 _close(id4);
	 rename("a:\\aux2.dat","a:\\notas.dat");
	 printf("\ndesea eliminar otro [s/n]: ");scanf("\n");
   gets(c); _close(id2);

 }while(strcmp(strupr(c),"S")==0);
 menu();
}

/**********************************************************************/

void menu()
{ char c;
  int sw;
  do
   {
     sw=0;
     window(1,1,80,25);
     escribe_menu();
     c= getch();
     while ((c != '\x1B')&&(sw!=1))
     {
	   c = getch();
	   switch (c)
	   {
	     case 80 : {
			  piso_color (3,YELLOW);
			  cprintf("%s",op[wherey()]);
			  piso_color (YELLOW,3);
			  if (wherey() == 4)
			    gotoxy (3,1);
			  else gotoxy (3,wherey()+1);
			  cprintf ("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	     case 72 : {
			  piso_color(3,14);
			  cprintf("%s",op[wherey()]);
			  piso_color (14,3);
			  if (wherey() == 1) gotoxy (3,4);
			  else gotoxy (3,wherey()-1);
			  cprintf("%s",op[wherey()]);
			  gotoxy (3,wherey());
			  break;
		       }
	   }
	   c =getch();
	   if(c=='\r')
	   {
	       switch(wherey())
	       {
		 case 1:{
			 piso_color(3,1);
			 window(2,8,79,20); 
			 crea1();crea2();
			 leer1();
			 clrscr();
			 escribe_menu();
			  getch();break;
			}
		case 2:{
			 piso_color(3,1);
			 window(2,8,79,20); 
			 vis_inf();
			 clrscr();
			 escribe_menu();
			  getch();break;
		       }
		case 3:{
			piso_color(3,1);
			window(2,8,79,20); 
			eliminar();
			clrscr();
			escribe_menu();
			 getch();break;
		       }
		case 4:{
			 sw=1;
			 break;
		       }
	       }
	   }
     }
   }while (sw==0);
}

/**********************************************************************/

piso_color(int piso,int color)
{
   textbackground(piso);
   textcolor(color);
   return 0;
}

/**********************************************************************/

void escribe_menu()
{
     int i,u;
     marco(2,2,79,5);
     piso_color(1,15);
     clrscr();
     gotoxy(10,2);
     cprintf("  CORPORACION UNIVERSITARIA DE SANTANDER  U.D.E.S");
     gotoxy(12,3);
     printf("	LUIS FERNANDO ARDILA");
      piso_color(3,14);
     window(2,8,79,21);
     for (u=1;u<15;u++){delay(50);gotoxy(1,u); cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");}
     marco(2,8,79,20);
     marco(2,23,79,23);
     piso_color(7,1);
     clrscr();
     gotoxy(1,1);cprintf("Use las teclas del cursor");
     window(1,1,80,25);
     textbackground(3);
     window(22,10,53,16);
     textbackground(BLUE);
     clrscr();
     piso_color(3,1);
     marco(22,10,51,14);
     piso_color(3,14);
     window(22,10,51,14); clrscr();
     for(i=2;i<=6;i++)
     {gotoxy(1,i);cprintf("  ");
     cprintf("%s",op[i]);
     gotoxy(wherex(),i);cprintf("  ");
      }

     gotoxy(1,1);
     cprintf("  ");
     piso_color (14,3);
     cprintf("%s",op[1]);
     gotoxy(wherex(),wherey());
     piso_color (3,14);
     cprintf("  ");
     gotoxy (3,1);
}
void per_mat()
{  if((id1=_open("a:\\datos.dat",O_RDWR))==-1)
      {  printf("error en apertura");
	 getch();
	 exit(1);
      }
    if((id2=_open("a:\\notas.dat",O_RDWR))==-1)
      {  printf("error en apertura");
	 getch();
	 exit(1);
      }
    clrscr();
    marco(1,1,80,25);
    clrscr();
    if(eof(id1)) { printf("archivo vacio");  exit(1);}
    while(!eof(id1))
	{ if(_read(id1,&(reg1),sizeof(reg1))!=sizeof(reg1))
	    {  printf("error en lectura");
	       getch();
	       exit(1);
	    }
	  if(_read(id2,&(reg2),sizeof(reg2))!=sizeof(reg2))
	    {  printf("error en lectura");
	       getch();
	       exit(1);
	    }

	    if(((reg2.def)<3)&&(!strcmp(reg2.cod2,reg1.cod)))
		     {
		       printf("-%s  ",reg1.nom);
		       printf("%s  ",reg1.ape);
		       printf("%.2f\n",reg2.def);


		     }


    }
 _close (id1);
  _close (id2);
  getch();
  menu();
}

/**********************************************************************/

marco(int a,int b,int c,int d)
{
   int i;
  piso_color(3,1);
   window(1,1,80,25);
   gotoxy(a-1,b-1);
   cprintf("%c",'É');
   for (i=a;i<=c;i++ )
      cprintf("%c",'Í');
   cprintf("%c",'»');
   for (i=b;i<=d;i++)
   {
      gotoxy(c+1,i);
     cprintf("%c",'º');

   }
  gotoxy(a-1,d+1);
  cprintf("%c",'È');
  for (i=a;i<=c;i++)
     cprintf("%c",'Í');
 cprintf("%c",'¼');
  for (i=b;i<=d;i++ )
  {
     gotoxy(a-1,i);
     cprintf("%c",'º');
  }
  window(a,b,c,d);
  return ;
}

/**********************************************************************/

void main()
{ menu();
 clrscr();
 per_mat();

}