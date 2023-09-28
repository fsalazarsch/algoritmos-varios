#include "iostream.h"
#include "stdio.h"
#include "stdlib.h"
#include "alloc.h"
#include "string.h"
#include "ctype.h"
#include "conio.h"
#define MAX_MENU  10
void parcial();
void menu_est();
void menu_notas();
void menu_consul();
long leer_estudiante();
float leer_nota();
//-------------------------------------
class grupo {                  //declaraci¢n de la clase llamada grupo
   struct estudiante {
	long codigo;
	char nombre[20];
	char apellido[20];
	char sexo;
	struct notas *notas_est;
	struct estudiante *sig_est;
   };
//-------------------------------------
   struct notas {
	float nota;
	struct notas *sig_nota;
   };
//-------------------------------------
   public:
	  struct estudiante *curso;
	  int lm;
	  void adicionar_estudiante();
	  void modificar_estudiante();
	  void eliminar_estudiante();
	  void adicionar_notas();
	  void modificar_notas();
	  void listado_maestro();
}materia;

char pantalla[4090];
//-------------------------------------
void main()
{
  materia.curso=NULL;
  parcial();
}
//-------------------------------------
long leer_estudiante()
{
  long Ncodigo;
  char Scodigo[9], car;
  int i;

  for (i=0; i<9;)
    {
      car=getch();
      if ((i<8) && (car>='0') && (car<='9'))
	{
	   cout << car;
	   Scodigo[i]=car;
	   i++;
	}
      if (car=='\b' && i>0)
	{
	  cout << "\b \b";
	  i--;
	  Scodigo[i]='\0';
	}
      if ((i>=1) && (car=='\r'))
	{
	  Scodigo[i]='\0';
	  i=9;
	}
    }
  Ncodigo=atol(Scodigo);
  return(Ncodigo);
}
//-------------------------------------
float leer_nota()
{
  float Nnota;
  char  Snota[5], car;
  int i;

  for (i=0; i<5;)
    {
      car=getch();
      if (((i>1) && (i<4) && Snota[0]!='5' && (car>='0') && (car<='9')) || ((i==0) && (car>='0') && (car<='5')) || ((i==1) && (car=='.')) || ((i>1) && (i<4) && (Snota[0]=='5') && (car=='0')))
	{
	   cout << car;
	   Snota[i]=car;
	   i++;
	}
      if (car=='\b' && i>0)
	{
	  cout << "\b \b";
	  i--;
	  Snota[i]='\0';
	}
      if ((i>=1) && (car=='\r'))
	{
	  Snota[i]='\0';
	  i=5;
	}
    }
  Nnota=atof(Snota);      //aqu¡ convierto la cadena en un numero decimal
  return(Nnota);
}
//-------------------------------------
char leer_sexo()
 {
   char sexo[2], car;
   int i;

   for (i=0; i<2;)
    {
      car=toupper(getch());
      if ((i==0) && ((car=='F') || (car=='M')))
	{
	   cout << car;
	   sexo[i]=car;
	   i++;
	}
      if (car=='\b' && i>0)
	{
	  cout << "\b \b";
	  i--;
	  sexo[i]='\0';
	}
      if ((i==1) && (car=='\r'))
	{
	  sexo[i]='\0';
	  i=2;
	}
    }
    if (sexo[0]=='F')
       cout << "\bFemenino";
    else
       cout << "\bMasculino";
    return(sexo[0]);
 }
//-------------------------------------
leer_nnota()
 {
   char nnota[2], car;
   int i;

   for (i=0; i<2;)
    {
      car=getch();
      if ((i==0) && (car>='1') && (car<='4'))
	{
	   cout << car;
	   nnota[i]=car;
	   i++;
	}
      if (car=='\b' && i>0)
	{
	  cout << "\b \b";
	  i--;
	  nnota[i]='\0';
	}
      if ((i==1) && (car=='\r'))
	{
	  nnota[i]='\0';
	  i=2;
	}
    }
    return(atoi(nnota));
 }
//-------------------------------------
existe_codigo(long codigo)
{
  struct estudiante *aux;
  int existe;

  if (materia.curso==NULL)
     return(0);
  else
     {
       existe=0;
       aux=materia.curso;
       while (aux!=NULL && !existe)
	 {
	   if (aux->codigo==codigo)
	      {
		existe=1;
		aux=NULL;

	      }
	   else
	      aux=aux->sig_est;
	 }
       return(existe);
     }
}
//-------------------------------------
void clear_mensaje()
{
  gotoxy(3,24);
  cout << "		      							    ";
}
//-------------------------------------
void grupo::adicionar_estudiante()
{
  struct estudiante *nuevo, *aux;
  long codigo;

  do {
       gotoxy(27,2); cout << "ADICIONAR NUEVO ESTUDIANTE";
       gotoxy(5,6);  cout << "Codigo: "; codigo=leer_estudiante();
       if (!existe_codigo(codigo))
	{
	   nuevo=(struct estudiante *) malloc(sizeof(struct estudiante));
	   nuevo->codigo=codigo;
	   clear_mensaje();
	   gotoxy(5,8); cout << "Nombre: "; scanf("\n");  gets(nuevo->nombre);
	   clear_mensaje();
	   gotoxy(5,10); cout << "Apellido: "; scanf("\n"); gets(nuevo->apellido);
	   clear_mensaje();
	   gotoxy(5,12); cout << "Sexo: "; nuevo->sexo=leer_sexo();
	   nuevo->sig_est=NULL;
	   nuevo->notas_est=NULL;
	   if (curso==NULL)
	      {
		curso=nuevo;
	      }
	   else
	      {
		aux=curso;
		while (aux->sig_est!=NULL)
		   aux=aux->sig_est;
		aux->sig_est=nuevo;
	      }
	}
       else
	{
	  gotoxy(5,9);
	  cout << "El C¢digo Ya Existe . . .";
	}
       clear_mensaje(); gotoxy(35,24); cout << "¨Desea continuar (s/n)? ";
  }while(toupper(getch())!='N');
}
//-------------------------------------
void grupo::modificar_estudiante()
{
  struct estudiante *aux;
  long codigo;
  do {
       gotoxy(27,2); cout << "MODIFICAR ESTUDIANTE";
       gotoxy(5,6);  cout << "Codigo: "; codigo=leer_estudiante();
       if (existe_codigo(codigo))
	{
	   aux=materia.curso;
	   while (aux->codigo!=codigo)
	      aux=aux->sig_est;
	   gotoxy(5,8);  cout << "Nombre: " << aux->nombre;
	   gotoxy(5,10); cout << "Apellido: " << aux->apellido;
	   gotoxy(5,12); cout << "Sexo: " << aux->sexo;
	   clear_mensaje();
	   gotoxy(40,8);  cout << "Nombre: "; scanf("\n");  gets(aux->nombre);
	   clear_mensaje();
	   gotoxy(40,10);  cout << "Apellido: "; scanf("\n"); gets(aux->apellido);
	   clear_mensaje();
	   gotoxy(40,12); cout << "Sexo: "; aux->sexo=leer_sexo();
	}
       else
	{
	  gotoxy(5,9); cout << "El C¢digo est  Errado o No Existe . . .";
	}
       clear_mensaje(); gotoxy(35,24); cout << "¨Continua (s/n)? ";
  }while(toupper(getch())!='N');
}
//-------------------------------------
cuantas_notas(struct notas *not)
{
  int n;
  struct notas *aux;
  aux=not;
  n=0;
  while (aux!=NULL)
    {
      aux=aux->sig_nota;
      n++;
    }
  return(n);
}
//-------------------------------------
void elim_notas(struct notas *not)
{
  struct notas *aux1, *aux2;
  aux1=not;
  while (aux1!=NULL)
    {
      aux2=aux1;
      aux1=aux1->sig_nota;
      free(aux2);
    }
}
//-------------------------------------
void grupo::eliminar_estudiante()
{
  struct estudiante *aux, *aux2;
  long codigo;
  do {
       gotoxy(33,2); cout << "ELIMINAR ESTUDIANTE";
       gotoxy(5,6); cout << "Codigo: "; codigo=leer_estudiante();
       if (existe_codigo(codigo))
	{
	   if (curso->codigo==codigo)
	       {
		 elim_notas(curso->notas_est);
		 aux=curso;
		 curso=curso->sig_est;
		 free(aux);
	       }
	   else
	       {
		 aux2=curso;
		 aux=aux2->sig_est;
		 while (aux->codigo!=codigo)
		   {
		     aux=aux->sig_est;
		     aux2=aux2->sig_est;
		   }
		 aux2->sig_est=aux->sig_est;
		 elim_notas(aux->notas_est);
		 free(aux);
	       }
	   gotoxy(5,9); cout << "ESTUDIANTE ELIMINADO";
	}
       else
	{
	  gotoxy(5,9); cout << "Este C¢digo est  Errado ¢ No Existe . . .";
	}
       clear_mensaje(); gotoxy(35,24); cout << "¨Continua(s/n)? ";
  }while(toupper(getch())!='N');
}
//-------------------------------------
void grupo::adicionar_notas()
{
  struct estudiante *aux;
  struct notas *not, *nuevo;
  long codigo;
  int nnotas, cual, i;
  do {
       gotoxy(25,2); cout << "ADICIONAR NOTAS AL ESTUDIANTE";
       gotoxy(5,6);  cout << "Codigo: "; codigo=leer_estudiante();
       if (existe_codigo(codigo))
	{
	  aux=curso;
	  while (aux->codigo!=codigo)
	     aux=aux->sig_est;
	  nnotas=cuantas_notas(aux->notas_est);
	  if (nnotas==4){
	       gotoxy(5,9); cout << "Este Estudiante Tiene Registradas Todas Las Notas";
	     }
	  else
	     {
	       do {
		    gotoxy(5,8);   cout << "		     ";
		    gotoxy(5,10);  cout << "		     ";
		    gotoxy(5,15);  cout << "						     ";
		    clear_mensaje(); gotoxy(25,24); cout << "Mensaje: Nota >= 0.0 y Nota<=5.00";
		    gotoxy(5,8); cout << "Adici¢n Nota #" << nnotas+1 << ": ";
		    not=aux->notas_est;
		    nuevo=(struct notas *) malloc(sizeof(struct notas));
		    nuevo->sig_nota=NULL;
		    if (not!=NULL){
			 while (not->sig_nota!=NULL)
			    not=not->sig_nota;
			 not->sig_nota=nuevo;
		       }
		    else
		       aux->notas_est=nuevo;
		    nnotas++;
		    gotoxy(5,10); cout << "Nota #" << nnotas << ": ";
		    nuevo->nota=leer_nota();
		    gotoxy(5,15); cout << "Desea Continuar adicionando notas del codigo " << codigo << " (s/n)?";
	       }while(toupper(getch())!='N' && nnotas!=4);
	     }
	}
       else
	{
	  gotoxy(5,9); cout << "Este C¢digo est  Errado ¢ No Existe . . .";
	}
       clear_mensaje();  gotoxy(28,24); cout << "¨Desea continuar Con Otro Alumno(s/n)? ";
  }while(toupper(getch())!='N');
}
//-------------------------------------
void grupo::modificar_notas()
{
  struct estudiante *aux;
  struct notas *not;
  long codigo;
  int nnotas, cual, i;
  do {
       gotoxy(25,2); cout << "MODIFICAR NOTAS AL ESTUDIANTE";
       gotoxy(5,6);  cout << "Codigo: "; codigo=leer_estudiante();
       if (existe_codigo(codigo))
	{
	  aux=curso;
	  while (aux->codigo!=codigo)
	     aux=aux->sig_est;
	  nnotas=cuantas_notas(aux->notas_est);
	  do {
	       gotoxy(5,6);  cout << "				";
	       gotoxy(5,9);  cout << "				       ";
	       gotoxy(30,9); cout << "				";
	       gotoxy(5,17); cout << "						       ";
	       gotoxy(5,6); cout << "Qu‚ Nota Desea Cambiar o Modificar: ";
	       cual=leer_nnota();
	       if (cual > nnotas) {
		    gotoxy(5,9);
		    cout << " La Nota No Se Ha Registrado";
		  }
	       else
		  {
		    not=aux->notas_est;
		    for (i=1; i<cual; i++)
		      not=not->sig_nota;
		    clear_mensaje(); gotoxy(25,24); cout << "Mensaje: Nota >= 0.0 y Nota<=5.00";
		    gotoxy(5,9);  printf("Nota #%d es: %.2f",cual,not->nota);
		    gotoxy(30,9); cout << "Nueva Nota #" << cual < ": ";
		    not->nota=leer_nota();
		  }
	       gotoxy(5,17); cout << "Continua modificando notas del codigo " << codigo << " ?";
	  }while(toupper(getch())!='N');
	}
       else
	{
	  gotoxy(5,9); cout << "Este C¢digo est  Errado o No Existe . . .";
	}
       clear_mensaje();  gotoxy(28,24); cout << "¨Desea Continuar Con Otro Alumno(s/n)? ";
  }while(toupper(getch())!='N');
}
//-------------------------------------
float prom(struct notas *not)
{
  struct notas *aux;
  float  promedio, porcent;
  int  i;
  aux=not;
  promedio=0;
  i=1;
  while (aux!=NULL)
    {
      if (i==1 || i==2)
	 promedio=promedio+(aux->nota*0.25);
      if (i==3)
	 promedio=promedio+(aux->nota*0.20);
      if (i==4)
	 promedio=promedio+(aux->nota*0.30);
      aux=aux->sig_nota;
    }
  return(promedio);
} 
//-------------------------------------
void esquema()
{
  if (materia.lm==1) {
      gotoxy(20,2);   cout << " ALUMNOS QUE PERDIERON LA MATERIA";
    }
  else if (materia.lm==2) {
       gotoxy(17,2);   cout << "ALUMNOS QUE GANARON LA MATERIA";
    }
  else if (materia.lm==2) {
       gotoxy(17,2);   cout << "ALUMNOS QUE GANARON LA MATERIA";
    }
  else if (materia.lm==3){
       gotoxy(29,2);   cout << "LISTADO DE ALUMNOS GENERAL";
    }
  else if (materia.lm==4){
       clrscr();          }

   gotoxy(2,4);  cout << "CODIGO";
   gotoxy(12,4); cout << "NOMBRE";
   gotoxy(32,4); cout << "APELLIDO";
   gotoxy(52,4); cout << "SEX";
   gotoxy(56,4); cout << "NOT1";
   gotoxy(61,4); cout << "NOT2";
   gotoxy(66,4); cout << "NOT3";
   gotoxy(71,4); cout << "NOT4";
   gotoxy(76,4); cout << "PROM";

			     // Aqu¡ se realiza el cuadro
}
//-------------------------------------
void grupo::listado_maestro()
{
  struct estudiante *aux_est;
  struct notas *aux_not;
  int n,i;
  clrscr();
  esquema();
  n=0;
  aux_est=curso;
  while (aux_est!=NULL)
    {
      if (lm==0 || (lm==1 && prom(aux_est->notas_est)<3) || (lm==2 && prom(aux_est->notas_est)>=3 && aux_est->sexo=='F') || (lm==3 && prom(aux_est->notas_est)>=3 && aux_est->sexo=='M') || (lm==4 && prom(aux_est->notas_est)>=3.5))
	 {
	   n++;
	   gotoxy(2,5+n);   cout << aux_est->codigo;
	   gotoxy(12,5+n);  cout << aux_est->nombre;
	   gotoxy(32,5+n);  cout << aux_est->apellido;
	   gotoxy(53,5+n);  cout << aux_est->sexo << "\n";
	   aux_not=aux_est->notas_est;
	   i=0;
	   while (aux_not!=NULL)
	    {
	      gotoxy(56+i*5,5+n);
	      printf("%.2f\n",aux_not->nota);
	      aux_not=aux_not->sig_nota;
	      i++;
	    }
	   gotoxy(76,5+n);
	   printf("%.2f",prom(aux_est->notas_est));
	   if (n==18)
	     {
	       gotoxy(30,25);
	       cout << "M s...";
	       getch();
	       clrscr();
	       esquema();
	       n=0;
	     }
	 }
      aux_est=aux_est->sig_est;
    }
  gotoxy(15,25); cout << "Oprima cualquier tecla para regresar al menu principal";
  getch();
}
//-------------------------------------
void parcial()
{
  char menu [9][50], tecla;
  int  i, activa;
  clrscr();
  strcpy(menu[0], "         MENU        ");
  strcpy(menu[1], " 1. PROCESAR ESTUDIANTES");
  strcpy(menu[2], " 2. PROCESAR NOTAS");
  strcpy(menu[3], " 3. PROCESO DE CONSULTAS");
  strcpy(menu[4], " 4. TERMINAR");
  activa=1;
  do
     {
       clrscr();
       gotoxy(22,5);  cprintf(menu[0]);
       for (i=1;i<=4;i++)
	{
	  gotoxy(22,i+6); cprintf(menu[i]);
	}
       i=activa;
       gotoxy(22,i+6);    cprintf("%s",menu[i]);
       do
	 {
	   do
	     {
		tecla=getch();
	     }
	   while(!((tecla==80) || (tecla==72) || (tecla==13)));
	     /*  80=tecla abajo;  72=tecla arriba;  13=ENTER  */

	   if (tecla==80)
	     {
		gotoxy(22,i+6);   cprintf("%s",menu[i]);
		if (i<4)
		  i++;
		else
		  i=1;
		gotoxy(22,i+6);   cprintf("%s",menu[i]);
	     }
	   if (tecla==72)
	     {
		gotoxy(22,i+6);   cprintf("%s",menu[i]);
		if (i!=1)
		   i--;
		else
		   i=4;
		gotoxy(22,i+6);   cprintf("%s",menu[i]);
	     }
	 }
       while (tecla!=13);
       switch (i)
	{
	  case  1: menu_est(); break;clrscr();
	  case  2: menu_notas(); break;clrscr();
	  case  3: menu_consul(); break;clrscr();
	}
	activa=i;
      }
      while (i!=4);
      textbackground(0);
      clrscr();
}
//-------------------------------------
void menu_est()
{ clrscr();
  char menu [9][50], tecla;
  int  i, activa;
  strcpy(menu[0], "    PROCESAR ESTUDIANTES");
  strcpy(menu[1], " 1. ADICIONAR");
  strcpy(menu[2], " 2. MODIFICAR");
  strcpy(menu[3], " 3. ELIMINAR ");
  strcpy(menu[4], " 4. VOLVER AL MENU PRINCIPAL");
  activa=1;
  do
     {
       gotoxy(28,9);  cprintf(menu[0]);
       for (i=1;i<=4;i++)
	{
	  gotoxy(28,i+10); cprintf(menu[i]);
	}
       i=activa;
       gotoxy(28,i+10);    cprintf("%s",menu[i]);
       do
	 {
	   do
	     {
		tecla=getch();
	     }
	   while(!((tecla==80) || (tecla==72) || (tecla==13)));
	   /*  80=tecla abajo;  72=tecla arriba;  13=ENTER  */

	   if (tecla==80)
	     {
		gotoxy(28,i+10);   cprintf("%s",menu[i]);
		if (i<4)
		  i++;
		else
		  i=1;
		gotoxy(28,i+10);   cprintf("%s",menu[i]);
		textcolor(11);    textbackground(0);
	     }
	   if (tecla==72)
	     {
		gotoxy(28,i+10);   cprintf("%s",menu[i]);
		if (i!=1)
		   i--;
		else
		   i=4;
		gotoxy(28,i+10);   cprintf("%s",menu[i]);
	     }
	 }
       while (tecla!=13);
       gettext(1,1,80,25,pantalla);
       switch (i)
	{
	  case  1: materia.adicionar_estudiante(); break;
	  case  2: materia.modificar_estudiante(); break;
	  case  3: materia.eliminar_estudiante(); break;
	}
       //puttext(1,1,80,25,pantalla);
       activa=i;
      }
      while (i!=4);
}
//-------------------------------------
void menu_notas()
{ clrscr();
  char menu [9][50], tecla;
  int  i, activa;
  strcpy(menu[0], "       PROCESAR NOTAS");
  strcpy(menu[1], " 1. ADICIONAR  NOTAS");
  strcpy(menu[2], " 2. MODIFICAR  NOTAS");
  strcpy(menu[3], " 3. VOLVER AL MENU PRINCIPAL");
  activa=1;
  do
     {
       gotoxy(28,10); cprintf(menu[0]);
       for (i=1;i<=3;i++)
	{
	  gotoxy(28,i+11); cprintf(menu[i]);
	}
       i=activa;
       gotoxy(28,i+11);   cprintf("%s",menu[i]);
       do
	 {
	   do
	     {
		tecla=getch();
	     }
	   while(!((tecla==80) || (tecla==72) || (tecla==13)));
	   /*  80=tecla abajo;  72=tecla arriba;  13=ENTER  */
	   if (tecla==80)
	     {
		gotoxy(28,i+11);  cprintf("%s",menu[i]);
		if (i<3)
		  i++;
		else
		  i=1;
		gotoxy(28,i+11);  cprintf("%s",menu[i]);
	     }
	   if (tecla==72)
	     {
		gotoxy(28,i+11);  cprintf("%s",menu[i]);
		if (i!=1)
		   i--;
		else
		   i=3;
		gotoxy(28,i+11);  cprintf("%s",menu[i]);
	     }
	 }
       while (tecla!=13);
       gettext(1,1,80,25,pantalla);
       switch (i)
	{
	  case  1: materia.adicionar_notas(); break;
	  case  2: materia.modificar_notas(); break;
	}
      // puttext(1,1,80,25,pantalla);
       activa=i;
      }
      while (i!=3);
}
//-------------------------------------
void menu_consul()
{ clrscr();
  char menu [9][50], tecla;
  int  i, activa;
  strcpy(menu[0], "        CONSULTAR");
  strcpy(menu[1], " 1. QUIENES PERDIERON");
  strcpy(menu[2], " 2. ALUMNOS QUE GANARON");
  strcpy(menu[3], " 3. CONSULTA GENERAL");
  strcpy(menu[4], " 4. VOLVER AL MENU PRINCIPAL ");
  activa=1;
  do
     {
	 gotoxy(30,11);            
	 cprintf(menu[0]);
       for (i=1;i<=4;i++)
	{
	  gotoxy(30,i+12); cprintf(menu[i]);
	}
       i=activa;
       gotoxy(30,i+12);   cprintf("%s",menu[i]);
       do
	 {
	   do
	     {
		tecla=getch();
	     }
	   while(!((tecla==80) || (tecla==72) || (tecla==13)));
	   /*  80=tecla abajo;  72=tecla arriba;  13=ENTER  */

	   if (tecla==80)
	     {
		gotoxy(30,i+12);  cprintf("%s",menu[i]);
		if (i<4)
		  i++;
		else
		  i=1;
	      
		gotoxy(30,i+12);
		cprintf("%s",menu[i]);
	      
	     }
	   if (tecla==72)
	     {
	     
		gotoxy(30,i+12);  
		cprintf("%s",menu[i]);
		if (i!=1)
		   i--;
		else
		   i=3;
 
	     gotoxy(30,i+12); 
	     cprintf("%s",menu[i]);
	 
	     }
	 }
       while (tecla!=13);
       gettext(1,1,80,25,pantalla);
       switch (i)
	{
	  case  1: materia.lm=1; materia.listado_maestro(); break;
	  case  2: materia.lm=2; materia.listado_maestro(); break;
	  case  3: materia.lm=3; materia.listado_maestro(); break;
	}
	//puttext(10,10,80,25,pantalla);
	activa=i;
      }
      while (i!=4);
}