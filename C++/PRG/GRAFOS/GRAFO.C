#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<io.h>
#include<fcntl.h>
#include<stdlib.h>
#include<alloc.h>
#include<ctype.h>
#include<dos.h>
struct x
{ int dist;
  char sal[14]; char lleg[14];
  float cost_t;
	   };
struct y
{
  char ciudad[14];
  int temp; long nh;
};

struct n
{ struct a *ant;
  char ciudad[14];
  int temp; long nh;
  struct n *sig;
};

struct a
{ int dist;
  char sal[14]; char lleg[14];
  float cost_t;
  struct a *sig;
};


struct marca
{ char ciudad[14];
  struct marca *sig;
};

struct x buffer;
struct y nodo;
struct n ciud;
struct n *cab;
struct n *r;
struct n *pns;
struct a arist;
struct n *p1;
struct n *p2;
struct marca *marcados, *ultimo, *menor_distancia;
float  min_long, long_aux;
int i,j,fina,finb,b,cur,ent,entx,enty,ent1,c,da,dan,sw,num,ex,cm;
long d,rmc;
char valor[14],form[14],contg;

void captura();
void menuppal();
void salva_pant();
void cargar();
void salir();
void buscar();
void eliminarnd();
void buscarnd();
void insertarnd();
void insertarat();
void minsertar();
void meliminar();
void eliminarat();
void grabar();
validarl();
validarn();
void capturane();
void capturaia();
void kilometraje_minimo();
void listar1();
void validarat();
void cg();
void capturam();
void modificar();
void capturani();
void mvisualizar();
void ciudades();
void udes();


void main()
{
//  grabar();
   clrscr();
  cm=0;
  textbackground(1);
  udes();
  textbackground(1);
  cargar();
  menuppal();

}


void salva_pant()
{
 for(i=1;i<=25;i++)
   {
       textcolor(15);
       textbackground(1);
       gotoxy(j,i);
       cprintf("                                                                                ");

   }
 for(j=2;j<=79;j++)
 { gotoxy(j,1); printf("Õ"); gotoxy(j,5); printf("Õ");
   gotoxy(j,23);printf("Õ"); gotoxy(j,25); printf("Õ");  }


 gotoxy(25,3); printf("SISTEMA VIAL DEL VALLE DEL CAUCA");
 for(i=6;i<=22;i++)
 {
  gotoxy(1,i); cprintf("∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤∞≤");
 }
}


void menuppal() {
clrscr();
while(1) {
salva_pant();
_setcursortype(_NOCURSOR);
cur=0;c=0;
for(i=11;i<=20;i++){
  gotoxy(25,i);cprintf("                          ");
  if(i>11){
  textcolor(8);cprintf("≤");textcolor(7);} }

gotoxy(26,21);textcolor(8);;cprintf("≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤≤");textcolor(7);
gotoxy(27,13);printf("VISUALIZAR");
gotoxy(27,14);printf("INSERTAR");
gotoxy(27,15);printf("ELIMINAR");
gotoxy(27,16);printf("MODIFICAR");
gotoxy(27,17);printf("RECORIDO");
gotoxy(27,18);printf("GUARDAR ");
gotoxy(27,19);printf("SALIR");
																																																										   gotoxy(70,24);printf("CML");

fina=13; finb=19; b=fina;

 while(cur!=13){

   gotoxy(26,b); printf("%c",'');
   entx=wherex(); enty=wherey();
   ent1=wherey();
   textcolor(8);
   textbackground(3);gotoxy(3,24);cprintf("                                                                        ");
   if(ent1==12){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("CARGA EL ARCHIVO DE DATOS");}
   if(ent1==13){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("MUESTRA UN INFORME DE NODOS Y ARISTAS");}
   if(ent1==14){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("INSERTA UN NODO O UNA ARISTA");}
   if(ent1==15){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("ELIMINA UN NODO O UNA ARISTA");}
   if(ent1==16){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("MODIFICA UN CAMPO"); }
   if(ent1==17){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("MUESTRA EL GRADO DE UN NODO"); }
   if(ent1==18){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("MUESTRA RECORRIDO ENTRE CIUDADES"); }
   if(ent1==19){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("GUARDA EN ARCHIVO"); }
   if(ent1==20){ gotoxy(3,24);printf("                                      ");gotoxy(3,24); printf("SALIR DEL PROGRAMA"); }
   textcolor(15);
   gotoxy(entx,enty);
   cur=getch();
   if(cur==80){ gotoxy(26,b);printf(" "); b++; }
   if(cur==72) { gotoxy(26,b);printf(" "); b--; }
   if(b==fina-1) { b=finb; }

   if(b==finb+1) { b=fina; }




  }
 if(cur==13){

    _setcursortype(_NORMALCURSOR);

    switch (enty) {

	 case 13: mvisualizar(); break;
	 case 14: minsertar(); break;
	 case 15: meliminar(); break;
	 case 16: modificar();break;
	 case 17: kilometraje_minimo(); break;
	 case 18: grabar(); break;
	 case 19: cg();salir(); exit(1);
   }
  }
}
}
void salir(){
textmode(C40);
gotoxy(5,15);printf("GRACIAS POR USAR ESTA APLICACION");
textcolor(2);
gotoxy(3,23);cprintf("SoftCreation");
sound(1800); delay(400); nosound();delay(40); sound(1080); delay(180); nosound(); delay(50);
sound(1080); delay(180); nosound(); delay(29); sound(1200);delay(280);nosound();delay(70);
sound(1080); delay(350); nosound();delay(150); sound(1540); delay(300); nosound();delay(100);
sound(1800);  delay(400);
sound(1080); delay(180); nosound(); delay(29); sound(1200);delay(280);nosound();delay(70);
sound(1080); delay(350); nosound();delay(150); sound(1540); delay(300); nosound();delay(100);
sound(1800);  delay(400);
nosound();
}

void cg()
{ char resp;
  if(cm==1)
  {
     for(i=10;i<=20;i++){
      gotoxy(25,i);cprintf("                          "); }
      gotoxy(27,13);printf("GUARDAR LOS CAMBIOS ?");
      gotoxy(34,15); printf("(S/N) : ");
      resp=toupper(getch());
      if(resp=='S')
      {
	gotoxy(30,17);
	printf("GRABANDO...");
        grabar();
      }
  }
}


       /**************  Funcion cargar grafo de archivos  **************/

void cargar(){
 struct n *p;
 struct n *aux;
 struct a *q;
 struct a *auxa;
 struct n *r;

 int x,swg;
 c=0;
 clrscr();
 gotoxy(26,15);printf("CARGANDO GRAFO...");
 gotoxy(26,18);printf("DE GUSTAVO ARIZA");
 gotoxy(26,19);printf("FABIAN DIAZ");
 gotoxy(26,20);printf("LEONARD SOCARRAS");
 if((dan=_open("a:nodos.dat",1))==-1)
	{
	   clrscr();gotoxy(25,10);
	   printf("ERROR AL INTENTAR ABRIR ARCHIVO");
	   getch(); exit(1);
	}
     else{
     do{ c++;

	     if((b=_read(dan,&nodo,sizeof(nodo)))==-1)
	      { clrscr();gotoxy(25,10);
		printf("ERROR AL LEER REGISTRO"); getch(); exit(1);}
		aux=(malloc(sizeof(struct n)));
		strcpy(aux->ciudad,nodo.ciudad);
		aux->nh=nodo.nh;
		aux->temp=nodo.temp;
		aux->ant=NULL;  aux->sig=NULL;
		if(c==1){ cab=aux;  }
		else {p->sig=aux; }
		p=aux;


 }while(! eof(dan));
 }
close(dan);

if((da=_open("a:grafo.dat",1))==-1)
  {   clrscr();gotoxy(25,10);
      printf("ERROR AL INTENTAR ABRIR ARCHIVO");
      getch(); exit(1);
   }

     
     while( (x=_read(da,&buffer,sizeof(buffer)))!=0 )
	    {
	      if(x!= sizeof(buffer))
	       {clrscr();
		gotoxy(2,5);printf("ERROR SOLO PUDO LEER UNA PARTE ");
		getch();exit(1);
		}
	x=0;
	

	buscar(buffer.sal);

	if(sw!=1)
	{clrscr();gotoxy(20,10);
	  printf("ERROR AL RELACIONAR GRAFO,NODO INEXISTENTE ");
	  getch();close(da); exit(1);
	 }
	auxa=(malloc(sizeof(struct a)));
	strcpy(auxa->sal,buffer.sal);
	strcpy(auxa->lleg,buffer.lleg);
	auxa->dist=buffer.dist;
	auxa->cost_t=buffer.cost_t;
	auxa->sig=NULL;

	if(pns->ant!=NULL)
	{ q=pns->ant;
	  while(q->sig!=NULL)
	   { q=q->sig;  }
	     q->sig=auxa;
	 }
	 else { pns->ant=auxa; }

 }
 close(da);
 for(i=25;i<=50;i++)
 {  gotoxy(i,11);printf("Õ");gotoxy(i,13);printf("Õ");  }
 gotoxy(25,11); printf("…");  gotoxy(50,11); printf("ª");
 gotoxy(25,13); printf("»");  gotoxy(50,13); printf("º");
 gotoxy(25,12);printf("∫"); gotoxy(50,12); printf("∫");
 textbackground(5);
 _setcursortype(_NOCURSOR);
 for(i=26;i<=49;i++)
 {  gotoxy(i,12);cprintf(" ");  delay(80);
    if(i>32){  gotoxy(26,15); printf("RELACIONANDO RUTAS");  }
 }

 textbackground(1);


 gotoxy(26,15);printf("100% OPERACION COMPLETADA");delay(1500);
 _setcursortype(_NORMALCURSOR);
}

		      /********** RECORRIDOS Y FUNCIONES*********/


void marcar(char ciudad[30])
{
  struct marca *nuevo;

  nuevo=malloc(sizeof(struct marca));
  nuevo->sig=NULL;
  strcpy(nuevo->ciudad,ciudad);
  if (marcados==NULL)
    {
      marcados=nuevo;
      ultimo=nuevo;
    }
  else
   {
     ultimo->sig=nuevo;
     ultimo=nuevo;
   }
}

void borrar_marca()
{
  struct marca *aux;

  aux=marcados;
  if (marcados==ultimo)
    {
      marcados=NULL;
      ultimo=NULL;
    }
  else
   {
     while (aux->sig!=ultimo)
       aux=aux->sig;
     aux->sig=NULL;
     free(ultimo);
     ultimo=aux;
   }
}

esta_marcada(char ciudad[30])
{
 struct marca *aux;

 aux=marcados;
 while (aux!=NULL)
   {
     if (strcmp(aux->ciudad,ciudad)==0)
	 return(1);
     aux=aux->sig;
   }
 return(0);
}

void menor_dist()
{
  struct marca *aux, *nuevo, *aux2;

  aux=menor_distancia;
  while (menor_distancia!=NULL)
    {
      menor_distancia=menor_distancia->sig;
      free(aux);
      aux=menor_distancia;
    }

  aux2=marcados;
  while (aux2!=NULL)
    {
      nuevo=malloc(sizeof(struct marca));
      strcpy(nuevo->ciudad, aux2->ciudad);
      nuevo->sig=NULL;
      if (menor_distancia==NULL)
	 {
	   menor_distancia=nuevo;
	   aux=nuevo;
	 }
      else
	{
	  aux->sig=nuevo;
	  aux=nuevo;
	}
      aux2=aux2->sig;
    }
}

void imprime_marcados(struct marca *marc)
{
  struct marca *aux;

  aux=marc;
  while (aux!=NULL)
    {
      printf("%s   ",aux->ciudad);
      aux=aux->sig;
    }
}


void k_min(char ciudad1[30], char ciudad2[30])
{
  struct n *aux;
  struct a *aux2;

  if (strcmp(ciudad1, ciudad2)==0)
    {
      marcar(ciudad1);
      if (long_aux<min_long)
	{
	  min_long=long_aux;
	  menor_dist();
	}
       printf("\n");
      if(marcados==NULL)
      { gotoxy(25,18); printf("No existe  ruta");
      }
      imprime_marcados(marcados);  printf("Su Valor Es: %.1f \n ",long_aux);
    }
  else
    {
      aux=cab;
      while (strcmp(aux->ciudad,ciudad1)!=0)
	aux=aux->sig;
	aux2=aux->ant;
	marcar(ciudad1);
	while (aux2!=NULL)
	{
	  if (!esta_marcada(aux2->lleg))
	    {
	      long_aux=long_aux+aux2->dist;
	      k_min(aux2->lleg,ciudad2);
	      borrar_marca();
	      long_aux=long_aux-aux2->dist;
	    }
	  aux2=aux2->sig;
	}
    }
}

void kilometraje_minimo()
{
  char ciudad1[30], ciudad2[30];
  int c;
while(c!=27){
  captura();
  validarl(1,"");
  strcpy(ciudad1,valor);
  buscar(ciudad1);
  if(sw==1)
  {
    gotoxy(33,16);
    validarl(1,"");
    strcpy(ciudad2,valor);
    buscar(ciudad2);
    if(sw==1)
    {
      clrscr();
      gotoxy(27,10); printf("ESPERE UN MOMENTO...");
      clrscr();
      marcados=NULL; ultimo=NULL;
      menor_distancia=NULL;
      min_long=50000000;
      long_aux=0;
      k_min(ciudad1, ciudad2);
      if(min_long==50000000)
      {  gotoxy(15,20); printf("NO EXISTE CAMINO"); getch(); }
      else
      {
	printf("\n\n\nLa Ruta M†s Corta Es: \n\n");
	imprime_marcados(menor_distancia);
	printf("Su Distancia Es: %.2f  Km",min_long);
	getch();
      }
    }
    else { gotoxy(24,22); printf("CIUDAD INEXISTENTE"); getch();  }
  }
  else {  gotoxy(24,22); printf("CIUDAD INEXISTENTE"); getch();  }

gotoxy(38,23);printf("<ENTER> CONTINUAR   <ESC> SALIR");
c=getch();
}
}



		       /*********Funcion grabar********/

void grabar() {
struct n *c;
struct a *m;
c=cab;
 if((dan=_creat("a:nodos.dat",0))==-1)
  { printf("ERROR AL INTENTAR CREAR ARCHIVO NODOS");
    getch(); exit(1);
  }

  else{
    while(c!=NULL){

    strcpy(nodo.ciudad,c->ciudad);
    if((b=_write(dan,&nodo,sizeof(nodo)))==-1)
      { printf("ERROR AL GRABAR REGISTRO"); getch(); exit(1);
      }
      cm=0;

	if(b!=sizeof(nodo)){ printf("ERROR, Solo grabo una parte"); getch(); exit(1);}
	c=c->sig;
     }
     close(dan);
    }



    if((da=_creat("a:/grafo.dat",0))==-1)
     { printf("ERROR AL INTENTAR CREAR ARCHIVO");
       getch(); exit(1);
     }
    c=cab;
    while(c!=NULL){
    m=c->ant;
      while(m!=NULL){
       strcpy(buffer.sal,m->sal);
       strcpy(buffer.lleg,m->lleg);
       buffer.dist=m->dist;
       buffer.cost_t=m->cost_t;

       if((b=_write(da,&buffer,sizeof(buffer)))==-1)
	{ printf("ERROR AL GRABAR REGISTRO"); getch(); exit(1);
	}

	if(b!=sizeof(buffer)){ printf("ERROR, Solo grabo una parte"); getch(); exit(1);}
       m=m->sig;
    }
    c=c->sig;
    }
    close(da);


}

void mvisualizar(){
_setcursortype(_NOCURSOR);
gotoxy(wherex()-1,wherey()); printf(" ");
while(1){cur=0;
for(i=39;i<=46;i++) {  gotoxy(i,12);printf("Õ"); gotoxy(i,16);printf("Õ");  }
for(i=12;i<=16;i++) { gotoxy(38,i);printf("∫"); gotoxy(47,i);printf("∫");   }
gotoxy(38,12); printf("…");  gotoxy(47,12); printf("ª");
gotoxy(38,16); printf("»");  gotoxy(47,16); printf("º");
gotoxy(26,13);cprintf("Ø");
gotoxy(40,13);printf("RUTAS");
gotoxy(40,14);printf("CIUDAD");
gotoxy(40,15);printf("MENU");
gotoxy(39,13);printf("");
fina=13; finb=15;  b=fina;
while(cur!=13)
{ cur=getch();
  if(cur==80){ gotoxy(39,b); printf(" "); b++; }
  if(cur==72){ gotoxy(39,b); printf(" "); b--; }
  if(b==fina-1){ b=finb; }
  if(b==finb+1){ b=fina; }
  gotoxy(39,b); printf("");

}
   if(cur==13){
     ent=wherey();
     switch(ent){
      case 13: _setcursortype(_NORMALCURSOR);listar1(); break;
      case 14: _setcursortype(_NORMALCURSOR);ciudades(); break;
      case 15: break;
     }
     }

    if(cur==13) { break;}

}

}

void ciudades()
{ struct a *a;
  struct n *n;
  int t,y;
  t=5;
  n=cab;
  clrscr();
  _setcursortype(_NOCURSOR);
  for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
  for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
  gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
  gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");

  gotoxy(5,2);printf("   CIUDAD            NUMERO DE HABITANTES            TEMPERATURA ");
  while(n!=NULL)
  {  gotoxy(5,t); printf("%s",n->ciudad);
     y=wherey();    delay(45);


	gotoxy(38,y); printf("%ld ",n->nh);
	gotoxy(62,y); printf("%d ",n->temp);
	 y++; t++;
	if((y>=23)&&(t>=23))
	{  getch();
	   if(a->sig!=NULL)
	   { clrscr(); t=5;
	     for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
	     for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
	     gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
	     gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");
	     gotoxy(5,2);printf("   CIUDAD            NUMERO DE HABITANTES            TEMPERATURA ");
	     y=wherey();
	   }


     }
     if(t>=23)
	{  getch();
	   if(a->sig!=NULL)
	   { clrscr(); t=5;
	      for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
	      for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
	      gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
	      gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");
	      gotoxy(5,2);printf("   CIUDAD            NUMERO DE HABITANTES            TEMPERATURA ");

	   }
	}
     n=n->sig; t++;
  }
  getch();
  _setcursortype(_NORMALCURSOR);
}



void listar1()
{ struct a *a;
  struct n *n;
  int t,y;
  t=5;
  n=cab;
  clrscr();
  _setcursortype(_NOCURSOR);
  for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
  for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
  gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
  gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");

  gotoxy(5,2);printf("LA CIUDAD           SE COMUNICA CON         DISTANCIA(km)    COSTO");
  while(n!=NULL)
  {  gotoxy(5,t); printf("%s",n->ciudad);
     y=wherey(); a=n->ant;   delay(45);
     while(a!=NULL)
     {  gotoxy(28,y); printf("%s ",a->lleg);
	gotoxy(53,y); printf("%d ",a->dist);
	gotoxy(64,y); printf("%.2f ",a->cost_t);
	 y++; t++;
	if((y>=23)&&(t>=23))
	{  getch();
	   if(a->sig!=NULL)
	   { clrscr(); t=5;
	     for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
	     for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
	     gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
	     gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");
	     gotoxy(5,2);printf("LA CIUDAD           SE COMUNICA CON         DISTANCIA(km)    COSTO");
	     gotoxy(5,t);printf("%s",n->ciudad);
	     y=wherey();
	   }
	}
	a=a->sig;
     }
     if(t>=23)
	{  getch();
	   if(a->sig!=NULL)
	   { clrscr(); t=5;
	      for(i=3;i<=74;i++){ gotoxy(i,1);printf("Õ"); gotoxy(i,4);printf("Õ");  }
	      for(i=2;i<=3;i++){ gotoxy(3,i);printf("∫"); gotoxy(75,i); printf("∫");  }
	      gotoxy(3,1); printf("…");  gotoxy(75,1); printf("ª");
	      gotoxy(3,4); printf("»");  gotoxy(75,4); printf("º");
	      gotoxy(5,2);printf("LA CIUDAD           SE COMUNICA CON         DISTANCIA(km)    COSTO ");

	   }
	}
     n=n->sig; t++;
  }
  getch();
  _setcursortype(_NORMALCURSOR);
}



       /***********  Funcion que crea el submenu insertar ************/

void minsertar(){
_setcursortype(_NOCURSOR);
gotoxy(wherex()-1,wherey()); printf(" ");
while(1){cur=0;
for(i=39;i<=46;i++) {  gotoxy(i,13);printf("Õ"); gotoxy(i,17);printf("Õ");  }
for(i=13;i<=17;i++) { gotoxy(38,i);printf("∫"); gotoxy(47,i);printf("∫");   }
gotoxy(38,13); printf("…");  gotoxy(47,13); printf("ª");
gotoxy(38,17); printf("»");  gotoxy(47,17); printf("º");
gotoxy(26,14);cprintf("Ø");
gotoxy(40,14);printf("NODOS");
gotoxy(40,15);printf("ARISTAS");
gotoxy(40,16);printf("MENU");
gotoxy(39,14);printf("");
fina=14; finb=16;  b=fina;
while(cur!=13)
{ cur=getch();
  if(cur==80){ gotoxy(39,b); printf(" "); b++; }
  if(cur==72){ gotoxy(39,b); printf(" "); b--; }
  if(b==fina-1){ b=finb; }
  if(b==finb+1){ b=fina; }
  gotoxy(39,b); printf("");

}
   if(cur==13){
     ent=wherey();
     switch(ent){
      case 14: _setcursortype(_NORMALCURSOR);insertarnd(); break;
      case 15: _setcursortype(_NORMALCURSOR);insertarat(); break;
      case 16: break;
     }
     }

    if(cur==13) { break;}

}

}
	 /*********** Funcion que crea el submenu Eliminar ***********/

void meliminar(){

gotoxy(wherex()-1,wherey()); printf(" ");
while(1){cur=0;
for(i=39;i<=46;i++) {  gotoxy(i,14);printf("Õ"); gotoxy(i,18);printf("Õ");  }
for(i=15;i<=17;i++) { gotoxy(38,i);printf("∫"); gotoxy(47,i);printf("∫");   }
gotoxy(38,14); printf("…");  gotoxy(47,14); printf("ª");
gotoxy(38,18); printf("»");  gotoxy(47,18); printf("º");
_setcursortype(_NOCURSOR);
gotoxy(40,15);printf("NODOS");
gotoxy(40,16);printf("ARISTAS");
gotoxy(40,17);printf("MENU");
gotoxy(39,15);printf("");
gotoxy(26,15);cprintf("Ø");
fina=15; finb=17;  b=fina;
while(cur!=13)
{ cur=getch();
  if(cur==80){ gotoxy(39,b); printf(" "); b++; }
  if(cur==72){ gotoxy(39,b); printf(" "); b--; }
  if(b==fina-1){ b=finb; }
  if(b==finb+1){ b=fina; }
  gotoxy(39,b); printf("");

}
   if(cur==13){
     ent=wherey();
     switch(ent){
      case 15: _setcursortype(_NORMALCURSOR);eliminarnd(); break;
      case 16: _setcursortype(_NORMALCURSOR);eliminarat(); break;
      case 17: break;
     }
     }

    if(cur==13) { break;}

}

}
	   /********** Funcion que crea el submenu Grado **********/

void capturam() {
clrscr();
for(i=15;i<60;i++) {
   gotoxy(i,9);printf("Õ");gotoxy(i,19);printf("Õ");
   gotoxy(i,13);printf("Õ");gotoxy(i,11);printf("Õ");
   gotoxy(i,15);printf("Õ");  }
for(i=10;i<20;i++) {
   gotoxy(14,i);printf("∫");gotoxy(60,i);printf("∫"); }
gotoxy(14,9); printf("…");  gotoxy(60,9); printf("ª");
gotoxy(14,19);printf("»");  gotoxy(60,19);printf("º");
gotoxy(28,10);printf("CAPTURA DE DATOS");
gotoxy(17,12);printf("CIUDAD ORIGEN: ");
gotoxy(17,14);printf("CIUDAD DESTINO: ");
gotoxy(17,17);printf("NUEVO COSTO DE T.: ");
gotoxy(31,12);

}

void modificar()
{  struct n *p;
   struct n *q;
   struct a *a;
   char o[14],d[14]; float cost;
   capturam();
   validarl(1,"");
   buscar(valor);
   if(sw==1)
   {  p=pns;
      strcpy(o,valor);
      gotoxy(33,14); validarl(1,"");
      buscar(valor);
      strcpy(d,valor);
      if(sw==1)
      { q=pns;
	gotoxy(37,17); validarn(1,"");
	cost=num;
	a=p->ant;
	while(a!=NULL)
	{  if(strcmp(d,a->lleg)==0)
	   { a->cost_t=cost;
	   }
	   a=a->sig;
	}
	a=q->ant;
	while(a!=NULL)
	{  if(strcmp(o,a->lleg)==0)
	   { a->cost_t=cost;
	   }
	   a=a->sig;
	}
      }else{ gotoxy(20,21);printf("CIUDAD INEXISTENTE");getch(); }
   } else { gotoxy(20,21);printf("CIUDAD INEXISTENTE"); getch(); }

}





	/*********  Funcion Buscar y regrasa un apuntador  ***********/

void buscar(char ciu[14])
{ pns=cab;
  sw=0;
  while(pns!=NULL)
    {
    if(strcmp(ciu,pns->ciudad)==0)
       { sw=1;   break; }
       pns=pns->sig;
     }
}
	/******* Funcion Buscar que regrasa dos punteros *********/

void buscarnd(char var[14])
{ j=1;
  p1=cab; sw=0;
  if(p1!=NULL){
   do{
      if((strcmp(var,p1->ciudad))==0)
	{ sw=1; break; }
      p2=p1;j++;
      p1=p1->sig;
     } while(p1!=NULL);
    }

}
		    /******* F. Eliminar aristas *******/

void eliminarat(){
struct a *r1;
struct a *r2;
char salida[14],llegada[14];
int c,v;
clrscr();
captura();
validarl(1,"");
strcpy(salida,valor);
gotoxy(33,16);
validarl(1,"");
strcpy(llegada,valor);
v=0;
buscar(salida);
if(sw==0) v=0;
r1=pns->ant;
sw=0; c=0;
while(r1!=NULL)
{ c++;
  if(strcmp(llegada,r1->lleg)==0){
    sw=1;   }
   if(sw==1){
     if(c==1){
     pns->ant=r1->sig; free(r1);   }

     else{ r2->sig=r1->sig; free(r1);  }
     break;
   }

   r2=r1;
   r1=r1->sig;

}

buscar(llegada);
if(sw==0){  v=0; }
r1=pns->ant;
sw=0; c=0;
while(r1!=NULL)
{ c++;
  if(strcmp(salida,r1->lleg)==0){
    sw=1;   }
   if(sw==1){
     if(c==1){
     pns->ant=r1->sig; free(r1); v=1;   }

     else{ r2->sig=r1->sig; free(r1); v=1; }
     break;
   }

   r2=r1;
   r1=r1->sig;

}

if(v==1){   cm=1;
gotoxy(15,22);printf("ARISTA ELIMINADA"); }
if(v==0){ gotoxy(15,22);printf("LA ARISTA NO EXISTE");}
getch();
}
		      /********* F. Eliminar nodo ********/

void eliminarnd()
{ char nodo[14];
  struct a *r1;
  struct a *r2;
  clrscr();
  capturane();
  validarl(1,"");
   strcpy(nodo,valor);
  i=0;
  buscarnd(nodo);
  if(sw==0){ gotoxy(15,20);printf("LA CIUDAD NO EXISTE"); getch();  }
  else{
  while(p1->ant!=NULL)
  { r1=p1->ant;i=1;
    while(r1->sig!=NULL)
    { r2= r1; i++;
      r1=r1->sig;

    }
    free(r1);
    r2->sig=NULL;
    if(i==1){ p1->ant=NULL; }
  }
  if(j==1){ cab=p1->sig; }
  else{ p2->sig=p1->sig; }
  free(p1);
   cm=1;
   gotoxy(15,20);printf("LA CIUDAD HA SIDO ELIMINADA"); getch();
  p1=cab;
  while(p1!=NULL){
   if(p1->ant!=NULL){
     r1=p1->ant; j=1;
     while(r1!=NULL){
      if((strcmp(nodo,r1->lleg))==0){
	if(j==1){
	 p1->ant=r1->sig;
	 free(r1);
	 }
	 else{ r2->sig=r1->sig;free(r1); }
	 r2=r2->sig;
	 r1=r2->sig;
	}
	else{ r2=r1; r1=r1->sig; }
	j++;
      }
     }
    p1=p1->sig;
   }


  }
}
		     /******** F. insrtar nodo ********/

void insertarnd (){
struct n *aux;
char temp[14];
char nodo[14];
int c;
while(c!=27){
capturani();
validarl(1,"");
buscar(valor);
if(sw==0)
{
cm=1;
aux=malloc(sizeof(struct n));
strcpy(aux->ciudad,valor);
gotoxy(38,15); validarn(1,"");
aux->nh=num;
gotoxy(31,17); validarn(1,"");
aux->temp=num;
aux->ant=NULL;
aux->sig=cab;
cab=aux;
}
else{ gotoxy(23,20);printf("LA CIUDAD YA EXISTE"); }
gotoxy(38,23);printf("<ENTER> CONTINUAR   <ESC> SALIR");
c=getch();
}

}
       /*********  F. Insertar aristas **********/

void insertarat() {
struct a *aux;
struct a *aux2;
char o[14],d[14];
int c,cnt;
while(c!=27){
cnt=0;
capturaia();
validarl(1,"DIGITE la ciudad origen: ");
strcpy(o,valor);
gotoxy(32,10);
validarl(1,"DIGITE la ciudad destino: ");
strcpy(d,valor);
validarat(o,d);
if(ex==0)
{
  buscar(o);
  cnt=sw+cnt;
  buscar(d);
  cnt=sw+cnt;
  if(cnt==2)
  {  cm=1;
   aux=malloc(sizeof(struct a));
   aux2=malloc(sizeof(struct a));
   strcpy(aux->sal,o);
   strcpy(aux2->lleg,o);
   strcpy(aux->lleg,d);
   strcpy(aux2->sal,d);
   gotoxy(29,12);
   validarn(1,"");
   aux->dist=num;
   aux2->dist=num;
   gotoxy(37,14);
   validarn(1,"DIGITE el costo de transporte: ");
   aux->cost_t=num;
   aux2->cost_t=num;
   buscar(aux->sal);
   aux->sig=pns->ant; pns->ant=aux;
   buscar(aux2->sal);
   aux2->sig=pns->ant; pns->ant=aux2;
  }
   else
   { gotoxy(27,17);printf("CIUDAD INEXISTENTE"); getch(); }


}
if(ex==1) { gotoxy(26,17);printf("LA TRAYECTORIA YA EXISTE"); }
gotoxy(38,23);printf("<ENTER> CONTINUAR   <ESC> SALIR");
c=getch();
}





}

void validarat(char orig[14],char dest[14])
{ struct a *x;
  ex=0;
  buscar(orig);
  if(sw==1)
  { x=pns->ant;
    while(x!=NULL)
    {  if(strcmp(x->lleg,dest)==0)
       {   ex=1;
	   break;
       }
       x=x->sig;
    }
  }
  else
    {
      ex=0;
    }
}

void captura() {
clrscr();
for(i=15;i<60;i++) {
   gotoxy(i,9);printf("Õ");gotoxy(i,19);printf("Õ");
   gotoxy(i,15);printf("Õ");gotoxy(i,11);printf("Õ");  }
for(i=10;i<19;i++) {
   gotoxy(14,i);printf("∫");gotoxy(60,i);printf("∫"); }
gotoxy(14,9); printf("…");  gotoxy(60,9); printf("ª");
gotoxy(14,19);printf("»");  gotoxy(60,19);printf("º");
gotoxy(28,10);printf("CAPTURA DE DATOS");
gotoxy(17,12);printf("CIUDAD ORIGEN: ");
gotoxy(17,16);printf("CIUDAD DESTINO: ");
gotoxy(31,12);

}
void capturane(){
clrscr();
for(i=15;i<60;i++) {
   gotoxy(i,9);printf("Õ");
   gotoxy(i,15);printf("Õ");gotoxy(i,11);printf("Õ");  }
for(i=10;i<15;i++) {
   gotoxy(14,i);printf("∫");gotoxy(60,i);printf("∫"); }
gotoxy(14,9); printf("…");  gotoxy(60,9); printf("ª");
gotoxy(14,15);printf("»");  gotoxy(60,15);printf("º");
gotoxy(28,10);printf("CAPTURA DE DATOS");
gotoxy(17,13);printf("CIUDAD: ");
gotoxy(26,13);


}

void capturani(){
clrscr();
for(i=15;i<60;i++) {
   gotoxy(i,7);printf("Õ"); gotoxy(i,19);printf("Õ");
   gotoxy(i,13);printf("Õ");gotoxy(i,9);printf("Õ");  }
for(i=8;i<19;i++) {
gotoxy(14,i);printf("∫");gotoxy(60,i);printf("∫"); }
gotoxy(14,7); printf("…");  gotoxy(60,7); printf("ª");
gotoxy(14,19);printf("»");  gotoxy(60,19);printf("º");
gotoxy(28,8);printf("CAPTURA DE DATOS");
gotoxy(17,11);printf("CIUDAD: ");
gotoxy(17,15);printf("NUMERO DE HABITANTES: ");
gotoxy(17,17);printf("TEMPERATURA: ");
gotoxy(26,11);


}

void capturaia() {
clrscr();
for(i=15;i<60;i++) {
   gotoxy(i,5);printf("Õ");gotoxy(i,19);printf("Õ");
   gotoxy(i,9);printf("Õ");gotoxy(i,7);printf("Õ"); gotoxy(i,11);printf("Õ");
   gotoxy(i,13);printf("Õ"); }
for(i=6;i<19;i++) {
   gotoxy(14,i);printf("∫");gotoxy(60,i);printf("∫"); }
gotoxy(14,5); printf("…");  gotoxy(60,5); printf("ª");
gotoxy(14,19);printf("»");  gotoxy(60,19);printf("º");
gotoxy(28,6);printf("CAPTURA DE DATOS");
gotoxy(17,8);printf("CIUDAD ORIGEN: ");
gotoxy(17,10);printf("CIUDAD DESTINO: ");
gotoxy(17,12);printf("DISTANCIA: ");
gotoxy(17,14);printf("COSTO DE TRANSPORTE: ");
gotoxy(31,8);

}


validarl(int cont,char dato[30])
  { int i,lon,st,x,y;
   char valido;
       do
       {
	  x=wherex();
	  y=wherey();
	  valido='n';
	  if(cont==1){
	    scanf("\n"); gets(valor);strupr(valor);
	  }
	  if(cont==2){
	     printf("%s",dato);
	     scanf("\n"); gets(valor);strupr(valor);
	    }
	  lon = strlen(valor);
	  st=1;
	  for(i=0;i<=lon-1; i++)
	   {
	    if(st==1)
	      {
		if(valor[i]==' ')
		{
		 st=2;
		 i++;
		}
	      }
	    if(!(isalpha(valor[i])))
	    {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);printf("                         ");
	      gotoxy(x,y);printf("                    ");
	      gotoxy(x,y);
	      valido='m';
	      break;
	    }
	   }
       }while(valido=='m');
    return(0);
  }

validarn(int cont,char dato[35])
  {int i,lon,y,x;
   char valido,valorn[9];
	  do
	  {
	  valido='n';
	  x=wherex();
	  y=wherey();
	  if(cont==2){
	  printf("%s",dato);
	  scanf("\n"); gets(valorn);strupr(valorn);
	  }
	  if(cont==1){
	  scanf("\n"); gets(valorn);strupr(valorn);
	  }
	  lon = strlen(valorn);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isdigit(valorn[i])))
	     {
	      gotoxy(10,20);printf("...ERROR AL DIGITAR LOS DATOS !...");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      gotoxy(x,y);printf("                    ");
	      gotoxy(x,y);
	      valido='m'; 
	      break;
	    }
	  }
	 }while(valido=='m');
	num=atol(valorn);
    return(0);
  }

void udes()
{int m=10,k;window(1,1,80,25);textbackground(0);clrscr(); 
for(k=1;k<4;k++){
int i,a,b,c,d,e,f; a=21;b=22;c=23;d=24;e=25;
textcolor(m+3);
clrscr();
for(i=10;i<18;i++)
{
gotoxy(i,a);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");       
gotoxy(i,b);cprintf(" ≥€€€¿ƒƒŸ€€€≥ ≥€€€   €€≥");        
gotoxy(i,c);cprintf(" ≥€€€€€€€€€€≥ ≥€€€€€€ﬂﬂ≥");        
gotoxy(i,d);cprintf(" ¿ƒƒƒƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒƒŸ"); 
gotoxy(i,e);cprintf("                       ");
a--;b--;c--;d--;e--;delay(20);
}


a=3;b=4;c=5;d=6;e=7;f=8;
for(i=47;i>=42;i--)
{
gotoxy(i,a);cprintf("                    ");
gotoxy(i,b);cprintf("⁄ƒƒƒƒƒƒƒø ⁄ƒƒƒƒƒƒƒø ");
gotoxy(i,c);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");
gotoxy(i,d);cprintf("≥€€€⁄ƒƒƒŸ ≥€€€⁄ƒƒƒŸ "); 
gotoxy(i,e);cprintf("≥€€€¿ƒƒƒø ≥€€€¿ƒƒƒø "); 
gotoxy(i,f);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");  

a++;b++;c++;d++,e++;f++;                 
delay(20);
}
a=19;b=20;c=21;d=22;e=23;f=24;
for(i=47;i>=42;i--)
{
gotoxy(i,a);cprintf("≥€€€⁄ƒƒƒŸ ¿ƒƒƒø€€€≥ "); 
gotoxy(i,b);cprintf("≥€€€¿ƒƒƒø ⁄ƒƒƒŸ€€€≥ ");   
gotoxy(i,c);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");    
gotoxy(i,d);cprintf("¿ƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒŸ ");
gotoxy(i,e);cprintf("                    ");
a--;b--;c--;d--;e--;delay(20);
}
a=1;b=2;c=3;d=4;e=5;f=6;
for(i=10;i<18;i++)
{
gotoxy(i,a);cprintf("                        ");
gotoxy(i,b);cprintf(" ⁄ƒƒƒø  ⁄ƒƒƒø ⁄ƒƒƒƒƒƒƒƒø");  
gotoxy(i,c);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€€€€‹‹≥"); 
gotoxy(i,d);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€  ﬂ€€≥");    
gotoxy(i,e);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");    
gotoxy(i,f);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");
a++;b++;c++;d++,e++;f++;                 
delay(20);    
}
m++;
}
gotoxy(27,20);printf("Press any key to continue");
gotoxy(26,15);
getche();
}