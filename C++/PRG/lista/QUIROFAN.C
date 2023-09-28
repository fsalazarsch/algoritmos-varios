/*/Archivos de cabecera    */

#include <conio.h>
#include <alloc.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>

#define loc (struct paciente *)malloc(sizeof(struct paciente))
#define loc1 (struct quirofano *)malloc(sizeof (struct quirofano))
#define loc2 (struct consultorio *)malloc(sizeof(struct consultorio))
#define loc3 (struct cedulas *)malloc(sizeof(struct cedulas))

# define ESC   27
# define F1    59
# define F2    60

union k
{
  char c[2];
  int i;
} tecla;



/*/___________________________________________________________________*/

/*/Etructura que contiene los datos del paciente    */
 struct paciente {
  char nombre[30];
  char apellido[40];
  char cedula[10];
  char sitio[40];
  char fecha[20];
  char nacion[40];
  char eps[40];
  char empresa[45];
  char tipo[20];
  char enfermedad[20];
  int  cod;
  int prioridad;
  char interno[2];
  struct paciente *sig;
  struct paciente *ant;
}paciente;
/*---------------------------------------------------------------*/
struct cedulas{
   char cc[10];
   struct cedulas *sg;
   }ced;
/*---------------------------------------------------------------*/

struct quirofano {
    int numq;
    int max;
    int cant;
   struct quirofano *sigue;
   struct cedulas *abajo;
}quiro;
/*-----------------------------------------------------------------*/
 struct consultorio{
    char nomdoc[35];
    int numc;
    int ocupado;
    struct consultorio *siguiente;
    char ced[10];
    };

/*-----------------------------------------------------------------*/
struct historico{
 struct paciente enf;
 int num;
 char ndoctor[35];
};
/*----------------------------------------------------------------*/

/*Punteros a la estructura*/

struct paciente *cab1,*cab2 ;
struct quirofano *cabq;
struct consultorio *cabc;
struct cedulas *cabced;
struct historico his;
/*_________________________________________________________________-*/

/*Prototipos de funcion*/

void marco();
void menu();
void formulario(void);
void pacconsul();
void pacinter();
void atinterno();
void atconsul();
void inserconsulta();
void inserinterno();
void ordenar1();
void ordenar2( );
eliminar1();
eliminar2();
void imprimir1();
void imprimir2();
void registrando();
void formulario1(struct paciente *r,char cad[]);
void limpialine(int y);
void regisq();
void regisc();
void formq();
void formc();
void menuprinc();
void menu1();
void desocon();
void desocqui();
busquecon();
void busquequi();
void listqui();
void listcon();
void grabar(struct paciente *r);
validarnom();
void liberar();
void escape();


/*__________________________________________________________________*/

/*variables globales */
 char nom[30],ape[40],siti[40],dc[10],fc[20],nace[40],afil[40],emp[45],tip[20],enfer[32];
 char xx[2],nombredoc[35];
 int priori;
 int numero=0,maximo=0,numeroc=0;
 char cad1[]="a:\consultorio";
/* char cad2[]="a:\quirofano";*/
 /*--------------------------------------------------------------------*/

/*Funcion principal*/

void main()

 {
   cab1=NULL;
   cab2=NULL;
   cabq=NULL;
   cabc=NULL;
   cabced=NULL;
   menuprinc();
    }

 /*-----------------------------------------------------------------*/

  /*Esta funcion crea un marco en la pantalla activa */

void marco()
 {
   int x,y;
   clrscr();
   textbackground(WHITE);
    clrscr();
	for(x=2;x<=78;x++)
	 {
	   textbackground(WHITE);
	   textcolor(BLACK);
	   gotoxy(x,2); cprintf("Í");
	   gotoxy(x,23); cprintf("Í");
	 }

	gotoxy (2,2); cprintf("É");
	gotoxy (78,2); cprintf("»");
	gotoxy (2,23); cprintf("È");
	gotoxy (78,23); cprintf("¼");


       for(y=3; y<=22;y++)
	{
	  textbackground(WHITE);
	  textcolor(BLACK);
	  gotoxy (2,y); cprintf("º");
	  gotoxy (78,y); cprintf("º");

	}

}
/*------------------------------------------------------------------*/

void menuprinc(){
char s;
int i;
do
{
  clrscr();
  marco();
  gotoxy(25,7);cprintf("PRINCIPAL");
  gotoxy(20,10);cprintf("1.Supervisor.");
  gotoxy(20,12);cprintf("2.Operador.");
  gotoxy(20,14);cprintf("3.Salir.");
  gotoxy(34,24);cprintf("Digite cualquier tecla para aceptar.");
  gotoxy(20,16);cprintf("Digite opci¢n:  ");
  scanf("%d",&i);
  switch(i)
  {
     case 1:
	menu1();
	break;
     case 2:
	menu();
	break;
   }
}
while (i!=3);
}

/*------------------------------------------------------------------*/
void menu1(){
char  s2[1],sigue='s';
int a=0;
do
{
   marco();
   gotoxy(25,7);cprintf("SUPERVISOR");
   gotoxy(20,10);cprintf("1.Consultorio.");
   gotoxy(20,12);cprintf("2.Quir¢fano.");
   gotoxy(20,14);cprintf("3.Ver historioco.");
   gotoxy(20,16);cprintf("4.Salir");
   gotoxy(34,24);cprintf("Digite cualquier tecla para aceptar.");
   gotoxy(20,18);cprintf("Digite opci¢n:  ");
   scanf("%d",&a);
   switch(a)
   {
      case 1: do{
	       formc();
	       gotoxy(20,15);cprintf("DESEA SEGUIR REGISTRANDO(S/N)? ");
	       sigue=getch();
	       toupper(sigue);
	      } while(sigue !='n');
       	 break;
      case 2:
	      do{
		 formq();
		 gotoxy(10,15);cprintf("DESEA SEGUIR REGISTRANDO(S/N)? ");
		 sigue=getch();
		 toupper(sigue);
	      } while(sigue !='N');
	 break;
      case 3:
	  ver_archivo(cad1);
	  break;
     }
  }
  while (a!=4);
}
/*-------------------------------------------------------------------*/
void formc(){
  char i;
  clrscr();
  marco();
  gotoxy(20,7);cprintf("CONSULTORIOS");
  gotoxy(20,10);cprintf("Nombre del doctor:  ");
  gotoxy(20,12);cprintf("N£mero de consultorio:  ");
  gotoxy(41,10);scanf("%s",nombredoc);
  gotoxy(45,12);scanf("%d",&numeroc);
  gotoxy(34,24);cprintf("Digite Enter para aceptar o Esc para salir.");
  i=getch();
   switch(i){
    case 13:
	 regisc();
	 break;
    case 27:
	 break;
   }
}
/*-------------------------------------------------------------------*/
void formq(){
 char i;
 clrscr();
 marco();
 gotoxy(20,7);cprintf("QUIROFANO");
 gotoxy(10,10);cprintf("Numero de quirofano:  ");
 gotoxy(10,12);cprintf("Maximo de pacientes:  ");
 gotoxy(32,10);scanf("%d",&numero);
 gotoxy(32,12);scanf("%d",&maximo);
 gotoxy(24,24);cprintf("Digite Enter para aceptar o Esc para salir.");
 i=getch();
  switch(i){
   case 13:
      regisq();
      break;
   case 27:break;
  }
}

/*-------------------------------------------------------------------*/
void regisq(){
 struct quirofano *p,*nuevo;
 nuevo=loc1;
 if(nuevo!=NULL){
 nuevo->numq=numero;
 nuevo->max=maximo;
 nuevo->cant=0;
 nuevo->sigue=NULL;
 p=cabq;
 if(!p)
   cabq=nuevo;
 else{
   while(p->sigue)
     p=p->sigue;
   p->sigue=nuevo;
  }
 }
}
/*------------------------------------------------------------------*/
void regisc()
{
  struct consultorio *p,*nuevo;
  nuevo=loc2;
  if(nuevo){
  strcpy(nuevo->nomdoc,nombredoc);
  nuevo->numc=numeroc;
  nuevo->ocupado=0;
  nuevo->siguiente=NULL;
  p=cabc;
  if(!p)
   cabc=nuevo;
  else{
    while(p->siguiente)
      p=p->siguiente;
    p->siguiente=nuevo;
   }
  }
}
/*-------------------------------------------------------------------*/
/* Muestra las opciones del menu*/

void menu(){
    char op,sigue='s';

    int i = 0,x = 0;
      while(i!=10)
      {
      marco();
      gotoxy(35,5);cprintf("CONSULTORIO CLINICO");
      gotoxy(25,8);cprintf("1.REGISTRAR PACIENTE");
      gotoxy(25,9);cprintf("2.ATENDER CONSULTA");
      gotoxy(25,10);cprintf("3.ATENDER INTERNO");
      gotoxy(25,11);cprintf("4.PACIENTES A CONSULTA");
      gotoxy(25,12);cprintf("5.PACIENTES A INTERNAR");
      gotoxy(25,13);cprintf("6.DESOCUPAR CONSULTORIO");
      gotoxy(25,14);cprintf("7.DESOCUPAR QUIROFANO");
      gotoxy(25,15);cprintf("8.LISTA DE CONSULTORIOS");
      gotoxy(25,16);cprintf("9.LISTA DE QUIROFANOS");
      gotoxy(25,17);cprintf("10.SALIR");
      gotoxy(44,24);cprintf("Digite cualquier tecla para entrar.");
      gotoxy(25,19);cprintf("Digite su opci¢n:   ");
      gotoxy(25,37);scanf("%d",&x);
      switch(x){
       case 1: do
	       {
		  formulario();
		  gotoxy(20,21);cprintf("Desea seguir registrando(S/N)?");
		  sigue=getch();
		  toupper(sigue);
		} while (sigue != 'n');
		break;
       case 2:atconsul();
	       break;
       case 3:atinterno();
	       break;
       case 4:pacconsul();
	       break;
       case 5:pacinter();
	       break;
       case 6:desocon();
	       break;
       case 7:desocqui();
	       break;
       case 8:listcon();
	       break;
       case 9:listqui();
	       break;
       case 10:
	       liberar();
       i=10;
      }
      }
  }
/*-------------------------------------------------------------*/

/* La funcion donde el usuario registra el paciente*/

void formulario(void){
  char xx,ii ;
  marco();
   gotoxy(25,5);cprintf("HISTORIA CLINICA");
   gotoxy (10,8);cprintf("NOMBRE: ");
   gotoxy (10,9);cprintf("APELLIDOS: ");
   gotoxy (10,10);cprintf("DOCUMENTO DE IDENTIDAD: ");
   gotoxy (50,10);cprintf("DE: ");
   gotoxy (10,11);cprintf("FECHA DE NACIMIENTO: ");
   gotoxy (50,11);cprintf("EN: ");
   gotoxy (10,12);cprintf("EPS: ");
   gotoxy (10,13);cprintf("EMPRESA: ");
   gotoxy (37,13); cprintf("TIPO: ");
   gotoxy(10,14); cprintf("-------------------------------------------------") ;
   gotoxy (10,15);cprintf("ENFERMEDAD: ");
   gotoxy (37,15);cprintf("PRIORIDAD(1 a 5): ");
   gotoxy (10,16);cprintf("INTERNAR(S/N): "); escape();
   gotoxy (18,8);scanf("%s",nom);
   gotoxy (21,9); scanf("%s", ape);
   gotoxy (34,10); scanf("%s", dc);
   gotoxy (53,10); scanf("%s", siti);
   gotoxy (31,11); scanf("%s", fc);
   gotoxy (53,11); scanf("%s", nace);
   gotoxy (15,12); scanf("%s", afil);
   gotoxy (19,13); scanf("%s", emp);
   gotoxy (42,13); scanf("%s", tip);
   gotoxy (22,15); scanf("%s", enfer);
   gotoxy (55,15); scanf("%d", &priori);
   gotoxy (32,16); scanf("%s", &xx);
   gotoxy (10,24);
   cprintf("Digite Enter para aceptar el registro o Esc para salir al men£. ");
   ii=getch();
	     switch(ii){
		case 13: {
			    if ((xx=='s')||(xx=='S'))
		      inserinterno();
		    else if ((xx=='n')||(xx=='N'))
		       inserconsulta();
		    }
			  break;
		case 27: break;
		}

}

/*----------------------------------------------------------------------*/
void escape(){
  int tecla=0;
  /*tecla=getch();*/
  if(tecla==ESC)
      exit(1);
 }
/*----------------------------------------------------------------------*/
/*funcion que atiende un paciente a consulta*/

void atconsul()
{
   int ocupa;
   marco();
   ocupa=busquecon();
   if (ocupa==0)
   {
      ordenar1();
      eliminar1();
   }
   else
   {
       gotoxy(20,15);printf("Todos los consultorios ocupados. ");
       gotoxy(10,18);printf("Regrese al men£ y digite 6 para desocupar el consultorio que desea.");
   }
   getch();
}


/*-------------------------------------------------------------- */
void liberar(){
 struct paciente *temp,*temporal;
 struct quirofano *tempo;
 struct consultorio *y;
 temp=cab1;
 temporal=cab2;
 tempo=cabq;
 y=cabc;
 if(temp!=NULL){
    cab1=cab1->sig;
    temp->sig=NULL;
    free(temp);
  }
 if(temporal!=NULL){
    cab2=cab2->sig;
    temporal->sig=NULL;
    free(temporal);
    }
 if(tempo!=NULL){
    cabq=cabq->sigue;
    tempo->sigue=NULL;
    free(tempo);
   }
  if(y!=NULL){
    cabc=cabc->siguiente;
    y->siguiente=NULL;
    free(y);
   }
   temp=cab1;
   temporal=cab2;
   tempo=cabq;
   y=cabc;
}




/*_________________________________________________________________  */

/*funcion ordena la lista de consultas*/

void ordenar1(){
  struct  paciente *p1,*p2,*p3,tempo;
  int intercambio=0;
     p1=cab1;
     if(p1==NULL){
       gotoxy(25,15);cprintf("NO HAY PACIENTES");
      }

   else
     {
	while(p1)
	{
	    p2=p1->sig;
	    priori=p1->prioridad;
	    while(p2)
	       {
		  if((p2->prioridad) < priori)
		 {
		   priori=p2->prioridad;
		   p3=p2;
		   intercambio=1;
		 }
		   p2=p2->sig;
	       }
	  if (intercambio)
	  {
	    strcpy(tempo.nombre,p1->n
	 gotoxy(52,9+i);cprintf("%s",p->enfermedad);
	 gotoxy(73,9+i);cprintf("%d",p->prioridad);
	 i++;
	 if(i==23){
	  getch();
	  limpialine(i);
	  i=0;
	  }
	 p=p->sig;
    }
    gotoxy(34,24);cprintf("Digite cualquier tecla para salir al men£.");
    }
  }
/*--------------------------------------------------------------------*/
void pacinter(){
 clrscr();
 marco();
 imprimir2();
 getch();
}

/*//_______________________________________________________________ */

/*Imprime la lista de pacientes a consultar*/
void imprimir2(){
  struct paciente *p;
  int i=0;
  p=cab2;
  clrscr();
  marco();
  if(!p){
   gotoxy(20,10);cprintf("NO HAY PACIENTES EN ESPERA.");
   gotoxy(34,24);cprintf("Digite cualquier tecla para salir al men£.");
  }
  else{
   gotoxy(30,5);cprintf("PACIENTES A INTERNAR");
   gotoxy(9,7);
   cprintf("NOMBRE                APELLIDO             ENFERMEDAD      PRIORIDAD ") ;
   while(p!=NULL){
	 gotoxy(10,9+i); cprintf("%s" ,p->nombre);
	 gotoxy(32,9+i);cprintf("%s",p->apellido);
	 gotoxy(52,9+i);cprintf("%s",p->enfermedad);
	 gotoxy(73,9+i);cprintf("%d",p->prioridad);
	 i++;
	 if(i==23){
	  getch();
	  limpialine(i);
	  i=0;
	  }
	 p=p->sig;
    }
    gotoxy(34,24);cprintf("Digite cualquier tecla para salir al menu.");
    }
}
/*//________________________________________________________________  */

void inserconsulta(){
struct paciente *p,*nuevo;
nuevo=loc;
if(nuevo){
  strcpy(nuevo->nombre,nom);
  strcpy(nuevo->apellido,ape);
  strcpy(nuevo->cedula,dc);
  strcpy(nuevo->sitio,siti);
  strcpy(nuevo->fecha,fc);
  strcpy(nuevo->nacion,nace);
  strcpy(nuevo->eps,afil);
  strcpy(nuevo->empresa,emp);
  nuevo->prioridad=priori;
  strcpy(nuevo->interno,xx);
  nuevo->sig=NULL;
  p=cab1;
  if(!p)
   cab1=nuevo;
  else{
    while(p->sig)
      p=p->sig;
    p->sig=nuevo;
   }
  }
  }
/*--------------------------------------------------------------------*/
void desocon()
{
 struct consultorio *p;
 int i;
 p=cabc;
 marco();
 if(!p)
 {
   gotoxy(25,15);
   cprintf("NO HAY CONSULTORIOS A DESOCUPAR.");
   getch();
 }
 else
  {
     gotoxy(25,10);cprintf("DESOCUPAR CONSULTORIO");
     gotoxy(25,14);cprintf("Digite n£mero de consultorio: ");
     scanf("%d",&i);
     while (p!=NULL)
     {
       if ((p->numc==i) && (p->ocupado==1))
       {
	 p->ocupado=0;
	 getch();
       }
      p=p->siguiente;
   }
 }    gotoxy(20,34);cprintf("Digite cualquier tecla para regresar al men£");
}
/*---------                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
   while(p!=NULL){
    gotoxy(15,7+a);cprintf("%d",p->numc);
    gotoxy(41,7+a);cprintf("%s",p->nomdoc);
    gotoxy(67,7+a);cprintf("%d",p->ocupado);
    a++;
    if(a==22){
     getch();
     limpialine(a);
     a=0;
     } p=p->siguiente;
   }
}  getch();

}
/*---------------------------------------------------------------------*/

/*Funcion que inserta en la lista de interno*/

void inserinterno(){
    struct paciente  *q,*nuevo;
    nuevo=loc;
    if(nuevo){
     strcpy(nuevo->nombre,nom);
     strcpy(nuevo->apellido,ape);
     strcpy(nuevo->cedula,dc);
     strcpy( nuevo->sitio,siti);
     strcpy(nuevo->fecha,fc);
     strcpy(nuevo->eps,afil);
     strcpy(nuevo->empresa,emp);
     strcpy(nuevo->tipo,tip);
     strcpy(nuevo->enfermedad,enfer);
     nuevo->prioridad= priori;
     strcpy(nuevo->interno,xx);
     nuevo->sig=NULL;
     q=cab2;
     if(!q)
      cab2=nuevo;
    else{
      while(q->sig)
	 q=q->sig;
      q->sig=nuevo;
      }
    }

}


ver_archivo(cad)
char cad[];
{
  FILE *fp;
  struct paciente aux;
  clrscr();
  marco();

     if ((fp=fopen(cad,"rb"))==NULL)
	 {
	  printf("No se puede abrir el archivo de consultorios:");
	  getchar();
	  exit(1);
	 }
     else {
       do
	 {
	   fscanf(fp,"%s %s %s ",aux.nombre,aux.apellido,aux.cedula);
	   fscanf(fp,"%s %s %s ",aux.sitio,aux.fecha,aux.nacion);
	   fscanf(fp,"%s %s %s ",aux.eps,aux.empresa,aux.tipo);
	   fscanf(fp,"%s %d %s ",aux.enfermedad,aux.prioridad,aux.interno);
	   gotoxy(25,5);cprintf("ARCHIVO DE PACIENTES");
	   gotoxy(10,8);cprintf("NOMBRE:   %s",aux.nombre);
	   gotoxy(10,9);cprintf("APELLIDO:   %s",aux.apellido);
	   gotoxy(10,10);cprintf("CEDULA:   %s",aux.cedula);
	   gotoxy(50,10);cprintf("DE:   %s",aux.sitio);
	   gotoxy(10,11);cprintf("FECHA DE NACIMIENTO:   %s",aux.fecha);
	   gotoxy(50,11);cprintf("EN:   %s",aux.nacion);
	   gotoxy(10,12);cprintf("EPS:   %s",aux.eps);
	   gotoxy(10,13);cprintf("EMPRESA:   %s",aux.empresa);
	   gotoxy(37,13);cprintf("TIPO:   %s",aux.tipo);
	   gotoxy(10,15);cprintf("ENFERMEDAD:   %s",aux.enfermedad);
	   gotoxy(37,15);cprintf("PRIORIDAD:   %d",aux.prioridad);
	   gotoxy(10,17);cprintf("INTERNO:   %s",aux.interno);
	   gotoxy(34,24);cprintf("Digite Enter para continuar...");

	/*	cprintf("%s %s %s \n",aux.nombre,aux.apellido,aux.cedula);*/
	/*	getchar();                                                */
	     }  while(!feof(fp));
		 fclose(fp);
	  }      getch();
   }

void regisced(struct paciente datos ){
   struct cedulas *p,*new;
   new= loc3;
   if(new){
    strcpy(new->cc,datos.cedula);
    new->sg=NULL;
    p=cabced;
    if(!p)
       cabced=new;
    else{
      while(p->sg)
	 p=p->sg;
      p->sg=new;
    }
    }
  }