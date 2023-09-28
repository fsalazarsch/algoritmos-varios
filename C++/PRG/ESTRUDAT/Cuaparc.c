#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#define x 300
void pswd(),eliminar(void),borrar (void);
//void copiar();
void men_listar(),nombre(),codigo(),curso(),encontrar();
void menu();
//void listar();
void buscar(),modificacion(),cuadro2(int x1, int y1, int x2, int y2);
void cedula();

cuadro(int x1, int y1, int x2, int y2);
void captura(),cap_pantalla1(void),borrar(void),pantalla1();
void crear_archivo(void),no_en();
busca_libre(void);
struct
{
  char nombre[50],direccion[30],ciudad[10],curso[3],carrera[20];
  char semestre;
  unsigned long int codigo,telefono,cedula,tm;
}inf_dat[x];
int c,r,a,sw,op,j,i;
char tecla,con[8];
void main()
{
textbackground(0);    
clrscr();
j=24;
gotoxy (24,10);textcolor(3);cprintf("DIGITE LA CONTRASE¥A\n");gotoxy(25,11);
   for (i=0;i<7;i++)
    { con[i]=getch();
      gotoxy(j,11); printf("*");
      a++; j++;
    }
   con[i+1]='\0';

  if(strcmp(con,"roberto=\'0'"))
			   

{
     clrscr();
      r=1;
      menu();
     }
    else
     {
      clrscr();j=j-7;
      gotoxy(10,5);printf("CLAVE NO VALIDA");
      if(c!=1)
       gotoxy(10,10);printf("INTENTA DE NUEVO");
       c--;
      if (c==1)
       gotoxy(10,11);printf("ULTIMA OPORTUNIDAD...");
       getch();
     }
  }
//pswd();
/*=============================================================*/
void crear_archivo(void)
{
 FILE *ro;
 char t,nom_arch[13],copi[13],*nom[9],*ext[4];
 int u;
 textcolor(5);
 clrscr();
 do
 {
 t='n';
 printf("digite el nombre del archivo  :  ");
 scanf("\n");
 gets(nom_arch);
 if (strlen(nom_arch)>12)
   {
    printf("nombre de archivo erroneo");
    t='s';
    getch();clrscr();
   }
 else
  {
   strcpy(copi,nom_arch);
   *nom=strtok(copi,".");
   if (strlen(*nom)>8)
     {
     printf("nombre del archivo erroneo");
      t='s' ;
     getch();clrscr();
     }
   *ext=strtok(NULL,".");
   if(strlen(*ext)>3)
     {
      printf("nombre de la extencion del archivo erronea");
      t='s';
     getch(); clrscr();}
   }
 }while(t=='s');
 if ((ro=fopen (nom_arch,"w"))==NULL)
     {	no_en();
     }
 else
 {
 cuadro(20,11,58,13);gotoxy(27,12);textcolor(11+128);
 printf(" EL ARCHIVO FUE CREADO  ");
 for (u=0;u<10;u++){
    delay(200);
    sound(800+random(800));}
 nosound();
  }
fclose(ro);
return ;
}


void borrar()
{
 textcolor(11);
 clrscr();

}
void no_en()
{
  clrscr();
  printf("NO SE PUEDE ABRIR EL ARCHIVO");exit(1);
}
busca_libre()
{
 register int t;
 for(t=0;inf_dat[t].codigo && t<x;t++);
 if (t==x) return -1;return t;
}
void pantalla1()
{textbackground(14);
 clrscr();
 cuadro(1,1,80,4);gotoxy(33,2);printf("CAPTURA DE DATOS");
 window(1,5,80,25);textbackground(0);textcolor(15);clrscr();cuadro(1,1,80,20);
 gotoxy(5,4);printf("NOMBRE............:");
 gotoxy(5,5);printf("CURSO.............:");
 gotoxy(5,6);printf("CARRERA...........:");
 gotoxy(5,7);printf("CODIGO............:");
 gotoxy(5,8);printf("TELEFONO..........:");
 gotoxy(5,9);printf("CEDULA............:");
 gotoxy(5,10);printf("LIBRETA MILITAR...:");

}
void cap_pantalla1(void)
{
 int sitio;
  sitio=busca_libre();
 if(sitio==-1)
{  clrscr();
   printf ("lista llena");getche();return; 
}
  gotoxy(25,4);scanf("\n"); gotoxy(25,4);gets(inf_dat[sitio].nombre);
  gotoxy(25,5);scanf("\n"); gets(inf_dat[sitio].curso);
  gotoxy(25,6);scanf("\n"); gets(inf_dat[sitio].carrera);
  gotoxy(25,7);scanf("\n");fscanf(stdin,"%ld",&inf_dat[sitio].codigo);
  gotoxy(25,8);scanf("\n"); fscanf(stdin,"%ld",&inf_dat[sitio].telefono);
  gotoxy(25,9);scanf("\n"); fscanf(stdin,"%ld",&inf_dat[sitio].cedula);
  gotoxy(25,10);scanf("\n"); fscanf(stdin,"%ld",&inf_dat[sitio].tm);

}

cuadro(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ß");
    gotoxy(i,y2); cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("Û");
    gotoxy(x2,i); cprintf("Û");
  }
}
 void cuadro2(int x1, int y1, int x2, int y2)
{
  int i;
  gotoxy(x1,y1); printf("Ú");
  gotoxy(x1,y2); printf("À");
  gotoxy(x2,y1); printf("¿");
  gotoxy(x2,y2); printf("Ù");
  for(i=x1+1;i<x2;i++)
  {
    gotoxy(i,y1); cprintf("Ä");
    gotoxy(i,y2); cprintf("Ä");
  }

  for(i=y1+1;i<y2;i++)
  {
    gotoxy(x1,i); cprintf("³");
    gotoxy(x2,i); cprintf("³");
  }
  //return 0;
}

void eliminar(void)
{ int u;
char nombre[10];
textcolor(13);
clrscr();
printf("introduzca el nombre del archivo a borrar:");
scanf("\n");
gets(nombre);
if(remove (nombre)){
 textcolor(4);
 clrscr();
 cuadro(20,11,58,14);gotoxy(30,12);textcolor(11+128);
printf("ARCHIVO NO EXISTENTE");gotoxy(25,13);printf("FUNCION DE BORRADO NO EJECUTADA");
for (u=0;u<10;u++){
    delay(200);
    sound(100+random(10000));}
 nosound();

}
else
 textcolor(11);
 clrscr();
 cuadro(20,11,58,13);gotoxy(27,12);textcolor(11+128);
printf("EL ARCHIVO FUE BORRADO ");
for (u=0;u<10;u++){
    delay(200);
    sound(800+random(800));}
 nosound();
}
void men_listar()
{
window(1,1,80,24);
textbackground(0);
clrscr();
//window(1,1,80,24);

  cuadro2(1,1,80,24);
  cuadro2(1,1,80,3);
  cuadro2(1,3,15,5);
  cuadro2(15,3,46,5);
  cuadro2(46,3,58,5);
  cuadro2(58,3,69,5);
  cuadro2(69,3,80,5);
  cuadro2(1,5,15,24);
  cuadro2(15,5,46,24);
  cuadro2(46,5,58,24);
  cuadro2(58,5,69,24);
  cuadro2(69,5,80,24);
  gotoxy(1,3); cprintf("Ã"); gotoxy(1,5); cprintf("Ã");
  gotoxy(80,3); cprintf("´"); gotoxy(80,5); cprintf("´");
  gotoxy(15,3); cprintf("Â"); gotoxy(15,5); cprintf("Å"); gotoxy(15,24); cprintf("Á");
  gotoxy(46,3); cprintf("Â"); gotoxy(46,5); cprintf("Å"); gotoxy(46,24); cprintf("Á");
  gotoxy(58,3); cprintf("Â"); gotoxy(58,5); cprintf("Å"); gotoxy(58,24); cprintf("Á");
  gotoxy(69,3); cprintf("Â"); gotoxy(69,5); cprintf("Å"); gotoxy(69,24); cprintf("Á");
  gotoxy(6,4);textcolor(11);cprintf("CODIGO");
  gotoxy(28,4); cprintf("NOMBRE");
  gotoxy(48,4); cprintf("TELEFONO");
  gotoxy(60,4);cprintf("CARRERA");
  gotoxy(72,4); cprintf("CEDULA");encontrar();


}



/*void copiar()
{FILE *ro;
int sitio;
  fputc(ro,inf_dat[sitio]->nombre);
  fputc(ro,inf_dat[sitio]->direccion);
  fputc(ro,inf_dat[sitio]->ciudad);
  fputc(ro,inf_dat[sitio]->curso);
  fputc(ro,inf_dat[sitio]->carrera);
  fputc(ro,inf_dat[sitio]->semestre);
  fputc(ro,inf_dat[sitio]->codigo);
  fputc(ro,inf_dat[sitio]->telefono);
  fputc(ro,inf_dat[sitio]->civil);
  fputc(ro,inf_dat[sitio]->cedula);
  fputc(ro,inf_dat[sitio]->tm);
}*/

/*void pswd()
{char a,b,c,d,e,f,g,h,i,j,m[8];
textcolor(0);
clrscr();
textcolor(11);cprintf("introduzca la contrase¤a :");
a=getch();textcolor(4);cprintf("*");
b=getch();textcolor(4);cprintf("*");
c=getch();textcolor(4);cprintf("*");
d=getch();textcolor(4);cprintf("*");
f=getch();textcolor(4);cprintf("*");
g=getch();textcolor(4);cprintf("*");
h=getch();textcolor(4);cprintf("*");
i=getch();textcolor(4);cprintf("*");
j=getch();textcolor(4);cprintf("*");getche();


}*/
void buscar(void)
{
 int sw,op,i;
char tecla;

  do
  {
     clrscr();
     textbackground(1);
textcolor(15);
clrscr();
gotoxy(32,1);printf(" B U S Q U E D A  ");
gotoxy(1,2);
for(i=1;i<=1840;++i)
printf("°");
window(22,8,60,18);textbackground(4);clrscr();

     textcolor(9);
     gotoxy(13,2);
     cprintf(" O P C I O N E S");
     textcolor(10);
     gotoxy(4,4);
     cprintf("1.  BUSCAR POR CEDULA");
     gotoxy(4,5);
     cprintf("2.  BUSCAR POR CODIGO");
     gotoxy(4,6);
     cprintf("3.  BUSCAR POR CURSO");
     gotoxy(4,7);
     cprintf("4.  LISTAR TODA LA LISTA ");

     gotoxy(4,8);
     cprintf("5.  REGRESAR AL MENU PRINCIPAL");

     gotoxy(3,4);
     textcolor(9);
     cprintf("%c",'');
     gotoxy(3,4);

	 do
      {tecla=getch();
       if(tecla==72)
       {
	 printf(" ");
	  if(wherey()==4)
	   { gotoxy(3,wherey()+4);
	     cprintf("");gotoxy(3,wherey());
	    }
	     else
	     {
	       gotoxy(3,wherey()-1);
	       cprintf("");gotoxy(3,wherey());
	     }
	 }
	  else
	  {
	   if(tecla==80)
	   {
	     printf(" ");
	      if(wherey()==8)
	       {
		 gotoxy(3,wherey()-4);
		 cprintf("");gotoxy(3,wherey());
		}
		 else
		  {
		   gotoxy(3,wherey()+1);
		   cprintf("");gotoxy(3,wherey());
		  }
	      }
	    }
      }while(tecla!=13);

   if(wherey()==4 )
     op=1;
   if(wherey()==5 )
    op=2;
   if(wherey()==6 )
    op=3;
   if(wherey()==7 )
    op=4;

   if(wherey()==8 )
    op=5;

    switch(op)
    {
      case 1:cedula();window(1,1,80,24);break;
      case 2:codigo();window(1,1,80,24);break;
      case 3:curso(); window(1,1,80,24);break;
      case 4:men_listar();window(1,1,80,24);break;
    }
  }while(op != 5);
}


void captura()
{
 char res;
 int sitio;
 FILE *ro;
char t,nom_arch[13],copi[13],*nom[9],*ext[4];
 textbackground(0);highvideo();textcolor(11);
 clrscr();
 if ((ro=fopen(nom_arch,"a"))==NULL)
  no_en();

  pantalla1();
   window(1,5,80,25);
  gotoxy(25,4);
  scanf("\n");
  cap_pantalla1();
  //copiar(); printf("desea continuar :");res=getchar();
  fclose(ro);
}
void nombre()
{
}
void codigo()
{ int s,j,i; unsigned long int co;
clrscr();
printf("digite el codigo a buscar : ");
scanf("%ld",&co);
while (co==0)
{clrscr();window(22,8,60,18);
printf("digite el codigo a buscar : ");
scanf("%ld",&co); }
window(1,1,80,24);
textbackground(0);
clrscr();
j=6;s=0;
for(i=0;i<=x;i++)
{
if(inf_dat[i].codigo==co)
{/*textbackground(0);clrscr();*/
s=1;
window(1,1,80,24);
cuadro2(1,1,80,24);
  cuadro2(1,1,80,3);
  cuadro2(1,3,15,5);
  cuadro2(15,3,46,5);
  cuadro2(46,3,58,5);
  cuadro2(58,3,69,5);
  cuadro2(69,3,80,5);
  cuadro2(1,5,15,24);
  cuadro2(15,5,46,24);
  cuadro2(46,5,58,24);
  cuadro2(58,5,69,24);
  cuadro2(69,5,80,24);
  gotoxy(1,3); cprintf("Ã"); gotoxy(1,5); cprintf("Ã");
  gotoxy(80,3); cprintf("´"); gotoxy(80,5); cprintf("´");
  gotoxy(15,3); cprintf("Â"); gotoxy(15,5); cprintf("Å"); gotoxy(15,24); cprintf("Á");
  gotoxy(46,3); cprintf("Â"); gotoxy(46,5); cprintf("Å"); gotoxy(46,24); cprintf("Á");
  gotoxy(58,3); cprintf("Â"); gotoxy(58,5); cprintf("Å"); gotoxy(58,24); cprintf("Á");
  gotoxy(69,3); cprintf("Â"); gotoxy(69,5); cprintf("Å"); gotoxy(69,24); cprintf("Á");
  gotoxy(6,4);textcolor(11);cprintf("CODIGO");
  gotoxy(28,4); cprintf("NOMBRE");
  gotoxy(48,4); cprintf("TELEFONO");
  gotoxy(60,4);cprintf("CARRERA");
  gotoxy(72,4); cprintf("CEDULA");
 gotoxy(3,j);printf("%ld",inf_dat[i].codigo);
 gotoxy(17,j);printf("%s",inf_dat[i].nombre);
 gotoxy(50,j);printf("%ld",inf_dat[i].telefono);
 gotoxy(60,j);printf("%s",inf_dat[i].carrera);
 gotoxy(70,j);printf("%ld",inf_dat[i].cedula);
j++;
}

 }

if (s==0) printf("codigo no encontrado");



getche();
}
void curso()
{ char cu[3];
int i,k;
clrscr();
printf("digite el curso  :");
gets(cu);
k=strlen(cu);
while(k>3)
{printf("digite el curso  :");
gets(cu);k=strlen(cu);}
for(i=0;i<=x;++i)
{ 
if (strcmp(inf_dat[i].curso,cu))
{printf("curso no encontrado");
getche();}
printf("hola");
getch ();
    }


/*{printf("%s",inf_dat[i].nombre); }}getche();*/



} 
void encontrar()
{
  register int j,t;

 j=6;
for(t=0;t<x;++t)
{if(inf_dat[t].nombre[0])
{
gotoxy(3,j);printf("%ld",inf_dat[t].codigo);
gotoxy(17,j);printf("%s",inf_dat[t].nombre);
gotoxy(50,j);printf("%ld",inf_dat[t].telefono);
gotoxy(60,j);printf("%s",inf_dat[t].carrera);

gotoxy(70,j);printf("%ld",inf_dat[t].cedula);
j++;
}
}getche();}
void menu()
{
 do
  {
     clrscr();
     textcolor(12);
     gotoxy(13,4);
     cprintf("%c",'É');
     gotoxy(13,18);
     cprintf("%c",'È');
     gotoxy(68,4);
     cprintf("%c",'»');
     gotoxy(68,18);
     cprintf("%c",'¼');
      for(i=14;i<68;i++)
      {
	gotoxy(i,4);
	cprintf("%c",'Í');
	gotoxy(i,18);
	cprintf("%c",'Í');
      }
     for(i=5;i<18;i++)
     {  textcolor(12);
	gotoxy(13,i);
	cprintf("%c",'º');
	gotoxy(68,i);
	cprintf("%c",'º');
     }
     textcolor(9);
     gotoxy(33,5);
     cprintf("MENU PRINCIPAL");
     textcolor(10);
     gotoxy(15,6);
     cprintf("1.  CREAR ARCHIVO");
     gotoxy(15,7);
     cprintf("2.  CAPTURAR DATOS");
     gotoxy(15,8);
     cprintf("4.  LISTAR DATOS ");
     gotoxy(15,9);
     cprintf("5.  ELIMINAR DATOS");
     gotoxy(15,10);
     cprintf("6.  ELIMNAR ARCHIVO");
     gotoxy(15,11);
     cprintf("7.  SALIR DEL PROGRAMA");
     
     gotoxy(14,6);
     textcolor(9);
     cprintf("%c",'');
     gotoxy(14,6);
     
	 do                                       
      {tecla=getch();
       if(tecla==72)
       { 
	 printf(" ");
	  if(wherey()==6)
	   { gotoxy(14,wherey()+5);
	     cprintf("");gotoxy(14,wherey());
	    }
	     else
	     {
	       gotoxy(14,wherey()-1);
	       cprintf("");gotoxy(14,wherey());
	     }
	 }
	  else
	  {
	   if(tecla==80)
	   {
	     printf(" ");
	      if(wherey()==11)
	       {
		 gotoxy(14,wherey()-5);
		 cprintf("");gotoxy(14,wherey());
		}
		 else
		  {
		   gotoxy(14,wherey()+1);
		   cprintf("");gotoxy(14,wherey());
		  }
	      }
	    }
      }while(tecla!=13);	

   if(wherey()==6 )
     op=1;
   if(wherey()==7 )
    op=2;
   if(wherey()==8 )
    op=3;
   if(wherey()==9 )
    op=4;
   if(wherey()==10 )
    op=5;
   if(wherey()==11 )
    op=6;

    switch(op)
    {
      case 1:crear_archivo();break;
      case 2:captura();window(1,1,80,24);clrscr();textbackground(0);break;
      case 3:buscar();window(1,1,80,24);textbackground(0);clrscr(); break;
      case 4:borrar();window(1,1,80,24);clrscr();textbackground(0);break;
      case 5:eliminar();break;
  }}while(op != 6);
}
void cedula()
{
unsigned long int ce;
int s;
clrscr();
printf("digite el numero de cedula a buscar : ");
scanf("%ld",&ce);
s=0;
window(1,1,80,24);textbackground(0);clrscr();
for(i=0;i<x;i++)
{if (inf_dat[i].cedula==ce)
{
printf("%s",inf_dat[i].nombre);
printf("%s",inf_dat[i].carrera);
printf("%s",inf_dat[i].curso);
printf("%ld",inf_dat[i].codigo);
printf("%ld",inf_dat[i].cedula);
printf("%ld",inf_dat[i].telefono);
printf("%ld",inf_dat[i].tm);
s=1;
}
}
if (s==0)
printf("EL ESTUDIANTE NO SE ENCUENTRA EN EL SISTEMA O DATO DE ENTRADA ERRONEO.");
getche();
}
