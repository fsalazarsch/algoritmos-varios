#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#include <iostream.h>
#include <graphics.h>
class marycarmen
{
 struct datos;
 struct valor
  {
   int ncaja;
   int  edad;
   char nom[20],ape[20],sexo[12];
   struct valor *sig;
   struct datos *ent;
   };
/**/
  struct datos
 {
  int ncaja;
  int cedu;
  char nomu[20],apeu[20];
  int ope;
  float val;
  struct datos *antu, *sigu;
 };
/**/
  struct auxiliar
  {
  int caj;
  int ce;
  char no[20],ap[20];
  long ope;
  float val;
  struct auxiliar *siga;
 };
/******************/
 public:
 int edad,sw,sw1;
 char ncaja;
 char nom[20],ape[20],sexo[9],op;
 char nomu[20],apeu[20],op2;
 int ope;
 int i,l,n;
 float val;
 int cedu;
 struct valor *nn,*sig,*p,*q,*ptr;
 struct datos *sigu,*antu,*nn2,*ent,*u,*q1,*q2;
 marycarmen(){ptr=NULL;ent=NULL;} //constructor
 void adicion();
 void ver();
// void adicion_u();
// void eliminar_u();
// void modificar_u();
 void mconsulta();
// void consultau();
 void consdatos();
// void modificar();
// void eliminar();
 void menudatos();
// void menuu();
 void menup();
 void mensaje(char t[20]);
long int val_oper(int y, int x);
 char *val_nom(int y,int x);
 char *val_nomu(int y,int x);
 char *val_ape(int y, int x);
 char *val_apeu(int y, int x);
 char *val_sexo(int y, int x);
 int val_edad(int y, int x);
 //int *val_ncaja(int y,int x);
 void ventana(int X, int Y1,int X2,int Y2);
};
//*************************************************/
void marycarmen::mensaje(char t[20])
{
   window(28,20,70,20);
   clrscr();textcolor(4+BLINK);
   gotoxy(18,20);cprintf("%s",t);delay(700);
   clrscr();
   window(1,1,80,25);textcolor(15);
}
/**************************************************/
/*int *clary::val_ncaja(int y, int x)
{
 int i;
 char cad[20];
 do
  {
   gets(cad);
   n=strlen(cad);
    for(i=0;i<n;i++)
	     if(!isalnum(cad[i])) {sw=1;mensaje("* * SEXO ERRADO * *");}

   }while(sw==1);
   return(cad);
}
//*************************************************/
char *marycarmen::val_nom(int y,int x)
{
  int i,n;
  char nom[20];
  do{
     gotoxy(y,x);sw=0;
     clreol();
     gets(nom);window(1,1,80,25);
     if ((n=strlen(nom))==0){sw=1;mensaje("* * DIGITE EL NOMBRE * *");}
      else
      {
       if((n=strlen(nom))>20) {sw=1;mensaje("* * NOMBRE FUERA DE RANGO * *");}
       else{
	    for(i=0;i<n;i++)
	     if(!isalpha(nom[i])) {sw=1;mensaje("* * NOMBRE ERRADO * *");}
	   }
      }
    }while(sw==1);
  return(strupr(nom));
}
//*************************************************/
char *marycarmen::val_nomu(int y,int x)
{
  int i,n;
  char nomu[20];
  do{
     gotoxy(y,x);sw=0;
     clreol();
     gets(nomu);window(1,1,80,25);
     if ((n=strlen(nomu))==0){sw=1;mensaje("** DIGITE EL NOMBRE ** ");}
      else
      {
       if((n=strlen(nomu))>20) {sw=1;mensaje("** NOMBRE FUERA DE RANGO **");}
       else{
	    for(i=0;i<n;i++)
	     if(!isalpha(nomu[i])) {sw=1;mensaje("** NOMBRE ERRADO **");}
	   }
      }
    }while(sw==1);
  return(strupr(nomu));
}

//*************************************************/
/*char *clary::val_apeu(int y, int x)
{
 int i, n; char apeu[20];
  do{
     gotoxy(y,x);sw=0;
     clreol();
     gets(apeu);window(1,1,80,25);
     gotoxy(30,20);
     if ((n=strlen(apeu))==0){sw=1;mensaje("** DIGITE EL APELLIDO **");}
      else
      {
       if((n=strlen(apeu))>20) {sw=1;mensaje("** APELLIDO FUERA DE RANGO **");}
	else{
	    for(i=0;i<n;i++)
	     if(!isalpha(apeu[i])) {sw=1;mensaje("** APELLIDO ERRADO **");}
	   }
      }
    }while(sw==1);
 return(strupr(apeu));
} */
//************/
/*long int clary::val_oper(int y, int x)
{
int n,i;
  char cad[14];
  do
  { gotoxy(y,x); clreol();
    gets(cad); sw=0;
    n=strlen(cad);
     if ((n=strlen(cad))==0){sw=1;mensaje("** DIGITE LA OPERACION **");}
      else
      {
       if(n>1){sw=1; mensaje("** OPERACION FUERA DE RANGO **");}
	for(i=0;i<n;i++)
	 if(!isdigit(cad[i]))
	  { sw=1; break; }
      }
  }while(sw==1);
  return(atoi(cad));
}
//******************************************/
char *marycarmen::val_ape(int y, int x)
{
 int i, n; char ape[20];
  do{
     gotoxy(y,x);sw=0;
     clreol();
     gets(ape);window(1,1,80,25);
     gotoxy(30,20);
     if ((n=strlen(ape))==0){sw=1;mensaje("** DIGITE EL APELLIDO **");}
      else
      {
       if((n=strlen(ape))>20) {sw=1;mensaje("** APELLIDO FUERA DE RANGO **");}
       else{
	    for(i=0;i<n;i++)
	     if(!isalpha(ape[i])) {sw=1;mensaje("** APELLIDO ERRADO **");}
	   }
      }
    }while(sw==1);
 return(strupr(ape));
}
//******************************************/
char *marycarmen::val_sexo(int y, int x)
{
int i, n; char sexo[12];
  do{
     gotoxy(y,x);sw=0;
  clreol();
     gets(sexo);window(1,1,80,25);
     if ((n=strlen(sexo))==0){sw=1;mensaje("** DIGITE EL SEXO **");}
      else
      {
       if((n=strlen(sexo))>9) {sw=1;mensaje("** SEXO FUERA DE RANGO **");}
       else{
	    for(i=0;i<n;i++)
	     if(!isalpha(sexo[i])) {sw=1;mensaje("** SEXO ERRADO **");}
	   }
      }
    }while(sw==1);
 return(strupr(sexo));
}
//*************************************************/
int marycarmen::val_edad(int x,int y)
{
int n,i;
  char cad[14];
  do
  { gotoxy(y,x); clreol();
    gets(cad); sw=0;
    n=strlen(cad);
     if ((n=strlen(cad))==0){sw=1;mensaje("** DIGITE LA EDAD **");}
      else
      {
       if(n>2){sw=1; mensaje("** EDAD FUERA DE RANGO **");}
	for(i=0;i<n;i++)
	 if(!isdigit(cad[i]))
	  { sw=1; break; }
      }
  }while(sw==1);
  return(atoi(cad));
}
//*************************************************/
void marycarmen::adicion()
{
 do
 {
  clrscr();
  ventana(20,5,60,22);
  gotoxy(25,6);cout<<("A D I C I O N  D E  C O D I G O S");
  gotoxy(22,9);cout<<"DIGITE EL CODIGO: ";
  cin>>ncaja;

  p=ptr;sw=0;
  while(p!=NULL)
  {
  if (p->ncaja==ncaja)
    { sw=1; break;
    }
    p=p->sig;
   }

  if (sw==1)
  {
   ventana(20,5,60,22);
   gotoxy(23,15);cout<<("     CODIGO EXISTENTE");
   gotoxy(23,16); cout<<("DESEA ADICIONAR OTRO? [S/N]");
  }
  else
  {
  /*
   gotoxy(22,10);cout<<("DIGITE EL NOMBRE: ");
   strcpy(nom,val_nom(40,10));
   gotoxy(22,11);printf("DIGITE EL APELLIDO: ");
   strcpy(ape,val_ape(41,11));
   gotoxy(22,12);printf("DIGITE EDAD: ");
   edad=(val_edad(34,12));
   gotoxy(22,13);printf("DIGITE SEXO: ");
   strcpy(sexo,val_sexo(34,13));
   */
   nn=new valor;
   nn->ncaja=ncaja;
   strcpy(nn->nom,nom);
   strcpy(nn->ape,ape);
   nn->edad=edad;
   strcpy(nn->sexo,sexo);
   nn->sig=NULL;
   nn->ent=NULL;
   if (ptr==NULL)
   {
    ptr=nn;
   }
   else
   {
    nn->sig=ptr;
    ptr=nn;
   }
   gotoxy(24,16);printf("       CODIGO ADICIONADO           ");
   gotoxy(23,17);cout<<("DESEA ADICIONAR OTRO CODIGO:[S/N]: ");
  }
  gotoxy(58,17);op=toupper(getche());
 }while(op=='S');
}
//******************************************
/*void clary::eliminar()
{
 do
 {
  clrscr();
  gotoxy(27,6);cout<<"ELIMINAR CAJEROS";
  if(ptr==NULL)
  {
   ventana(2,1,79,25);ventana(24,10,52,13);
   gotoxy(28,11);cout<<"..NO SE PUEDE ELIMINAR";
   gotoxy(29,12);cout<<"NO HAY CAJEROS...";}
  else
  {
   ventana(2,1,79,24);ventana(23,10,53,14);
   gotoxy(24,9);printf("DIGITE EL NUMERO DEL CAJERO ");
   cin>>ncaja;
//   strcpy(ncaja,val_caja(50,9));
   q=NULL;
   p=ptr;
   sw=0;
   while (p!=NULL && sw==0)
   {
    if (p->ncaja==ncaja)
	  // if ((!strcmp(ncaja,p->ncaja))
    {
     gotoxy(20,17);cout<<"NOMBRE:"<<p->nom;
     gotoxy(20,18);cout<<"APELLIDO:"<<p->ape;
     gotoxy(20,19);cout<<"EDAD:"<<p->edad;
     gotoxy(20,20);cout<<"SEXO:"<<p->sexo;
     gotoxy(20,21);cout<<"ESTA SEGURO QUE DESEA ELIMINAR? [S/N] ";
     op=toupper(getche());
     sw=1; break;
    }
    q=p;
    p=p->sig;
   }
   if (p->ent!=NULL)
     {
      gotoxy(28,11);textcolor(5);cprintf("NO SE PUEDE ELIMINAR");textcolor(15);
      gotoxy(28,12);textcolor(9);cout<<"CONTIENE USUARIOS";textcolor(15);
     }
     else
     {
      if(sw==1&&op=='S')
      {
       if (p==ptr)
	{
	ptr=ptr->sig;
	}
	else
	{
	if (p->sig==NULL)
	 { q->sig=NULL;}
	 else
	 { q->sig=p->sig;}
	}
	if (op=='S')
	{
	 p->sig=NULL;
	 delete(p);
	 clrscr();
	 ventana(2,1,79,24);ventana(23,10,53,14);
	 gotoxy(26,12);cout<<"  CAJERO ELIMINADO ";
	}
      }
      else
      {
       if (op=='S'|| sw==0)
	{
	 ventana(20,5,60,22);
	 gotoxy(27,12);cout<<("NO SE PUEDE ELIMINAR");
	 gotoxy(27,13);cout<<("  CAJERO NO EXISTE");
	}

      }
      }
  }
  gotoxy(25,22);cout<<"DESEA CONTINUAR ? [S/N]:";
  gotoxy(48,22);op=toupper(getche());
 }while(op=='S');
} */
//******************************************
/*void clary::modificar()
{
 do
 {
  clrscr();
  ventana(1,2,80,23);ventana(19,2,56,4);
  textbackground(9);
  gotoxy(30,3);cout<<"MODIFICAR CAJEROS";
  gotoxy(28,11);cout<<"DIGITE EL N� DE CAJA:";cin>>ncaja;
  p=ptr; sw=0;
  while(p!=NULL)
  {
   if (p->ncaja==ncaja)
   {
     sw=1;break;
   }
   p=p->sig;
  }
  if(sw==0)
  {
   clrscr();gotoxy(30,3);cout<<"MODIFICAR CAJEROS";
   ventana(1,2,80,23);ventana(19,2,56,4);
   gotoxy(30,16);cout<<("ESTA CAJA NO EXISTE"); }
 else
{
  do
  { gotoxy(20,15);cout<<"NOMBRE:"<<p->nom;
    gotoxy(20,15);textcolor(2);cprintf("N");textcolor(15);
    gotoxy(20,16);cout<<"APELLIDO:"<<p->ape;
    gotoxy(20,16);textcolor(2);cprintf("A");textcolor(15);
    gotoxy(20,17);cout<<"EDAD:"<<p->edad;
    gotoxy(20,17);textcolor(2);cprintf("E");textcolor(15);
    gotoxy(20,18);cout<<"SEXO:"<<p->sexo;
    gotoxy(20,18);textcolor(2);cprintf("S");textcolor(15);
    gotoxy(20,21);cout<<"DIGITE OPCION A MODIFICAR: ";textcolor(2);cout<<"DIGITE [X] PARA SALIR";textcolor(15);
    op=toupper(getche());
    switch(op)
    {
      case 'N':gotoxy(27,15);clreol();
	       gets(nom);strcpy(p->nom,nom);break;
      case 'A':gotoxy(29,16);clreol();
	       gets(ape);strcpy(p->ape,ape); break;
      case 'E':gotoxy(25,17);clreol();
	       cin>>edad;break;
      case 'S':gotoxy(25,18);clreol();
	       gets(sexo);strcpy(p->sexo,sexo);break;
     }
  }while(op!='X');
}
  getch();
  gotoxy(20,22);cout<<("DESEA MODIFICAR OTRO CAJERO: [S/N] : ");
  gotoxy(57,22);op=toupper(getche());
 }while(op=='S');
} */
//******************************************
void marycarmen::consdatos()
{
 do
 {
  clrscr();
  ventana(1,2,80,23);ventana(19,2,56,4);
  textbackground(9);
  gotoxy(24,3);cout<<"C O N S U L T A R  C O D I G O";
  gotoxy(28,11);cout<<"DIGITE EL CODIGO:";cin>>ncaja;
  p=ptr; sw=0;
  if (p==NULL)
  {gotoxy(25,18);cout<<"NO PUEDE CONSULTAR NO HAY CODIGOS";getch();}
  else
  {
    while(p!=NULL)
   {
    if (p->ncaja==ncaja)
    {
     sw=1;break;
    }
    p=p->sig;
   }
   if(sw==0)
   {
    clrscr();gotoxy(30,3);cout<<"CONSULTAR CODIGOS";
   ventana(1,2,80,23);ventana(19,2,56,4);
    gotoxy(30,16);cout<<("ESTE CODIGO NO EXISTE");
   }
   else
   {
    gotoxy(20,15);cout<<"NOMBRE:"<<p->nom;
    gotoxy(20,16);cout<<"APELLIDO:"<<p->ape;
    gotoxy(20,17);cout<<"EDAD:"<<p->edad;
    gotoxy(20,18);cout<<"SEXO:"<<p->sexo;
   }
  }
    gotoxy(20,22);cout<<("DESEA CONSULTAR OTRO CODIGO: [S/N] : ");
    gotoxy(57,22);op=toupper(getche());
 }while(op=='S');
}
//*****************************************/
/*void clary::adicion_u()
{
 do
  {
   clrscr();
   ventana(20,5,60,23);
   gotoxy(27,6);cout<<("ADICION DE USUARIOS");
   gotoxy(22,9);cout<<"DIGITE N� DEL CAJERO: ";cin>>(ncaja);
   //strcpy(ncaja,val_ncaja(43,9));
   p=ptr;sw=0,sw1=0;
   while(p!=NULL)
    {
    //if(strcmp(ncaja,p->ncaja)==0)
     if (p->ncaja==ncaja)
      {
       sw=1; break;
      }
      p=p->sig;
    }
    if (sw!=1)
     {
      clrscr();
      ventana(20,5,60,23);
      gotoxy(23,15);cout<<("ESTA CAJA NO EXISTE");
     }
    else
     {
      gotoxy(22,10);cout<<("DIGITE CEDULA: ");cin>>cedu;
      if (p->ent!=NULL)
      {u=p->ent;
       while(u!=NULL)
	 {
	//if(strcmp(ncaja,p->ncaja)==0)
	  if (u->cedu==cedu)
	  {
	    sw1=1;break;
	   }
	   u=u->sigu;
	  }
      }
       if (sw1==1)
	  {
	   ventana(20,5,60,23);
	   gotoxy(23,15);cout<<("ESTE USUARIO YA EXISTE");
	   //gotoxy(27,16); cout<<("DESEA ADICIONAR OTRO USUARIO [S/N]:");
	  }
	  else
	  {
	   gotoxy(22,11);printf("DIGITE NOMBRE: ");//gets(nomu);
	   strcpy(nomu,val_nomu(36,11));
	   gotoxy(22,12);printf("DIGITE APELLIDO: ");//gets(apeu);
	   strcpy(apeu,val_apeu(38,12));
	   gotoxy(22,13);printf("DIGITE VALOR: ");cin>>valor;
	   do{
	   gotoxy(22,14);printf("DIGITE OPERACION:[  ]");
	    ventana(43,15,60,19);
	    gotoxy(44,16);
	    printf("1. CONSIGNACION ");
	    gotoxy(44,17);
	    printf("2. PAGO");
	    gotoxy(44,18);
	    printf("3. RETIRO ");
	    ope=(val_oper(40,14));
	   }while(ope<1 || ope>3);
	   nn2=new usuario;
	   nn2->ncaja=ncaja;
	   nn2->cedu=cedu;
	   strcpy(nn2->nomu,nomu);
	   strcpy(nn2->apeu,apeu);
	   nn2->ope=ope;
	   nn2->valor=valor;
	   nn2->sigu=NULL;
	   nn2->antu=NULL;
	  if (p->ent==NULL)
	   {
	    p->ent=nn2;
	   }
	   else
	    {
	     u=p->ent;
	     while(u->sigu!=NULL)
	     {
	      u=u->sigu;
	     }
	    u->sigu=nn2;
	    nn2->antu=u;
	   }
	    gotoxy(30,20);printf("USUARIO ADICIONADO");
	  }
       gotoxy(27,21);cout<<("DESEA ADICIONAR OTRO USUARIO [S/N]:");
     }
   gotoxy(58,21);op=toupper(getche());
   }while(op=='S');
} */
//*****************************************/
/*void clary::eliminar_u()
{
 do
 {
  clrscr();
  ventana(2,1,79,25);ventana(24,10,52,15);
  gotoxy(30,6);cout<<"ELIMINAR USUARIOS";
  if(ptr==NULL)
  {
   gotoxy(28,11);cout<<"..NO SE PUEDE ELIMINAR";
   gotoxy(29,12);cout<<"NO HAY CAJEROS...";
  }
  else
  {
   p=ptr;sw=0,sw1=0;
   while(p!=NULL)
    {
    //if(strcmp(ncaja,p->ncaja)==0)
     if (p->ncaja==ncaja)
      {
       sw=1; break;
      }
      p=p->sig;
    }
    if (sw==1||op=='S')
    {
     gotoxy(24,9);printf("DIGITE CEDULA DEL USUARIO");
     cin>>cedu;
     // if ((!strcmp(cedu,p->cedu())
     u=p->ent;
     if(u!=NULL)
     {
      q1=NULL;
      sw1=0;
      while (u!=NULL && sw1==0)
      {
       if (u->cedu==cedu)
	  // if ((!strcmp(cedu,p->cedu())
	{
	 gotoxy(30,11);cout<<"NOMBRE:"<<u->nomu;
	 gotoxy(30,12);cout<<"APELLIDO:"<<u->apeu;
	 gotoxy(30,13);cout<<"OPERACION:"<<u->ope;
	 gotoxy(30,14);cout<<"VALOR:"<<u->valor;
	 gotoxy(30,20);cout<<"ESTA SEGURO QUE DESEA ELIMINAR? [S/N] ";
	 gotoxy(68,20);op=toupper(getche());
	 sw1=1; break;
	}
	 q1=u;
	 u=u->sigu;
      }
       if(sw1==1&&op=='S')
	{
	 if (u==p->ent)
	  {
	   p->ent=u->sigu;
	  }
	  else
	  {
	   if (u->sigu==NULL)
	    {
	     q1->sigu=NULL;
	    }
	    else
	    {
	     q2=u->sigu;
	     q1->sigu=u->sigu;
	     q2->antu=u->antu;
	    }
	  }
	   if (op=='S')
	    {
	     u->sigu=NULL;
	     delete(u);
	     clrscr();
	     ventana(2,1,79,24);ventana(24,10,52,15);
	     gotoxy(27,6);cout<<("ADICION DE USUARIOS");
	     gotoxy(26,12);cout<<"  USUARIO ELIMINADO ";getch();
	    }
	}
    }
    else
	 {
	  gotoxy(27,12);cout<<("NO SE PUEDE ELIMINAR");
	  gotoxy(27,13);cout<<("  USUARIO NO EXISTE");
	 }
    }
  }
  ventana(2,1,79,25);ventana(24,10,52,15);
  gotoxy(20,22);cout<<"DESEA CONTINUAR? [S/N]:";
  gotoxy(46,22);op=toupper(getche());
 }while(op=='S');
} */
//*****************************************/
/*void clary::modificar_u()
{
 do
 {
  clrscr();
  ventana(2,1,79,25);ventana(24,10,52,15);
  gotoxy(30,6);cout<<"MODIFICAR USUARIOS";
  if(ptr==NULL)
  {
   gotoxy(28,11);cout<<"..NO SE PUEDE MODIFICAR";
   gotoxy(29,12);cout<<"NO HAY CAJEROS...";
  }
  else
  {
   p=ptr;sw=0,sw1=0;
   while(p!=NULL)
    {
    //if(strcmp(ncaja,p->ncaja)==0)
     if (p->ncaja==ncaja)
      {
       sw=1; break;
      }
      p=p->sig;
    }
    if (sw==1)
    {
     gotoxy(24,9);printf("DIGITE CEDULA DEL USUARIO");
     cin>>cedu;
     // if ((!strcmp(cedu,p->cedu())
     u=p->ent;
     sw1=0;
  if (u!=NULL)
   {
    while (u!=NULL)
      {
       if (u->cedu==cedu)
	  // if ((!strcmp(cedu,p->cedu())
	{
	 sw1=1; break;
	}
	u=u->sigu;
      }
      if (sw!=1)
      {
      gotoxy(20,19);cout<<"NO EXISTE ESTA CEDULA";}
      else
      {
       do
	 {
	  gotoxy(30,11);cout<<"NOMBRE:"<<u->nomu;
	  gotoxy(30,11);textcolor(2);cprintf("N");textcolor(15);
	  gotoxy(30,12);cout<<"APELLIDO:"<<u->apeu;
	  gotoxy(30,12);textcolor(2);cprintf("A");textcolor(15);
	  gotoxy(30,13);cout<<"OPERACION:"<<u->ope;
	  gotoxy(30,13);textcolor(2);cprintf("O");textcolor(15);
	  gotoxy(30,14);cout<<"VALOR:"<<u->valor;
	  gotoxy(30,14);textcolor(2);cprintf("V");textcolor(15);
	  gotoxy(20,21);cout<<"DIGITE OPCION A MODIFICAR: ";textcolor(2);cout<<"DIGITE [X] PARA SALIR";textcolor(15);
	  gotoxy(68,21);op=toupper(getche());
	  switch(op)
	 {
	  case 'N':gotoxy(37,11);clreol();
	       gets(nomu);strcpy(u->nomu,nomu);break;
	  case 'A':gotoxy(39,12);clreol();
	       gets(apeu);strcpy(u->apeu,apeu); break;
	  case 'O':gotoxy(40,13);clreol();
	       cin>>ope;break;
	  case 'V':gotoxy(36,14);clreol();
	       cin>>valor;break;
	 }
      }while(op!='X');
     }
    }
   }
  }
  getch();
  gotoxy(20,22);cout<<("DESEA MODIFICAR OTRO USUARIO: [S/N] : ");
  gotoxy(57,22);op=toupper(getche());
 }while(op=='S');
}*/
//*****************************************/
/*void clary::consultau()
{
 do
  {
   clrscr();
   ventana(1,2,80,23);ventana(19,2,56,4);
   textbackground(9);
   gotoxy(30,3);cout<<"CONSULTADE USUARIOS";
   gotoxy(28,11);cout<<"DIGITE EL N� DE CAJA:";cin>>ncaja;
   p=ptr;sw=0;sw1=0;
   if (ptr==NULL)
    { gotoxy(25,19);cout<<"NO SE PUEDE CONSULTAR NO HAY CAJAS";}
    else
    {
     while(p!=NULL)
     {
      if (p->ncaja==ncaja)
      {
       sw=1;break;
      }
      p=p->sig;
     }
     if(sw==0)
      {
       clrscr();gotoxy(30,3);cout<<"CONSULTA DE USUARIOS";
       ventana(1,2,80,23);ventana(19,2,56,4);
       gotoxy(30,16);cout<<("ESTA CAJA NO EXISTE");
      }
     else
     {
	gotoxy(28,12);cout<<"DIGITE OPERACION:";cin>>(cedu);

	u=p->ent;
	if (u==NULL)
	{
	 gotoxy(25,19);cout<<"NO SE PUEDE CONSULTAR NO HAY USUARIOS";}
	 else
	 {
	  while(u!=NULL)
	  {
	   if (u->ope==ope)
	   {
	    sw1=1;break;
	   }
	   u=u->sigu;
	  }
	  if (sw1==1)
	   {


	   gotoxy(22,14);cout<<"CEDULA:"<<u->cedu;
	   gotoxy(22,15);cout<<"NOMBRE:"<<u->nomu;
	   gotoxy(22,16);cout<<"APELLIDO:"<<u->apeu;
	   gotoxy(22,17);cout<<"OPERACION:"<<u->ope;
	   gotoxy(22,18);cout<<"VALOR:"<<u->valor;
	   }
	  else
	  {
	   gotoxy(30,16);cout<<("ESTE USUARIO NO EXISTE");
	  }
	 }
     }
    }
  gotoxy(20,22);cout<<("DESEA CONSULTAR OTRO USUARIO [S/N]: ");//getch();
  gotoxy(56,22);op=toupper(getche());
 }while(op=='S');
} */
//*****************************************/
void marycarmen::ventana(int X1,int Y1,int X2,int Y2)
{
 int i;
 for(i=X1+1;i<X2;i++){
 gotoxy(i,Y1);textcolor(1);cprintf("@") /*cprintf("�")*/;textcolor(15);   // LIN. AR. HORTAL
 gotoxy(i,Y2);textcolor(1);cprintf("@") /*cprintf("�")*/;textcolor(15);}  // LIN. AB. HORTAL
 for(i=Y1+1;i<Y2;i++){
 gotoxy(X1,i);textcolor(1);cprintf("**");textcolor(15);    // LIN. IZQ. VERT.
 gotoxy(X2,i);textcolor(1);cprintf("**");textcolor(15);}   // LIN. DER. VERT
 gotoxy(X1,Y1);textcolor(1);cprintf("**");textcolor(15);
 gotoxy(X1,Y2);textcolor(1);cprintf("**");textcolor(15);
 gotoxy(X2,Y1);textcolor(1);cprintf("**");textcolor(15);
 gotoxy(X2,Y2);textcolor(1);cprintf("**");textcolor(15);
}
//*****************************************/
void marycarmen::menup()
{
 char op;
 do
 {
  clrscr();textbackground(9);
  ventana(4,4,76,24);
  gotoxy(29,8); cout<<"M E N U  P R I N C I P A L";
  gotoxy(32,10); cout<<"1. Codigos";
  gotoxy(32,11); cout<<"2. -------";
  gotoxy(32,12); cout<<"3. -------";
  gotoxy(32,13); cout<<"4. Consultar";
  gotoxy(32,14); cout<<"5. Salir";
  ventana(20,7,60,16);
  gotoxy(23,18); cout<<"DIGITE LA OPCION:   ";
  do
  {
   gotoxy(43,18); op=getche();
    }while(op<'1'||op>'5');
  switch(op)
  {
   case '1': menudatos();clrscr();break;
   case '2': ver();break;
   //case '3': menuoper();break;
   case '4': mconsulta();break;
   case '5': break;
  }
 }while(op!='5');
}
//*****************************************
void marycarmen::menudatos()
{
 char op;
 do
 {
  clrscr();
  ventana(20,7,60,16);
  textbackground(9);
  gotoxy(28,8); printf("M E N U   D E   C O D I G O");
  gotoxy(32,10); printf("1. Ingresar  Codigos");
  gotoxy(32,11); printf("2. Modificar Codigos");
  gotoxy(32,12); printf("3. Eliminar  Codigos");
  gotoxy(32,13); printf("4. Salir");
  gotoxy(28,18); printf("DIGITE LA OPCION:");
  do
  {
   gotoxy(46,18);op=getche();
  }while(op<'1'||op>'4');
  switch(op)
  {
   case '1': adicion();break;
  // case '2': modificar();break;
  // case '3': eliminar();break;
  // case '4': menup();break;
  }
 }while(op!='4');
}
//******************************************
/*void clary::menuu()
{
 char op2;
 do
 {
  clrscr();
  ventana(20,7,60,16);
  textbackground(9);
  gotoxy(30,8); printf("  MENU DE USUARIOS  ");
  gotoxy(32,10); printf("1. ADICIONAR USUARIOS");
  gotoxy(32,11); printf("2. MODIFICAR USUARIOS");
  gotoxy(32,12); printf("3. ELIMINAR USUARIOS");
  gotoxy(32,13); printf("4. SALIR");
  gotoxy(28,18); printf("DIGITE SU OPCION:");
  do
  {
   gotoxy(46,18);op=getche();
  }while(op<'1'||op>'4');
  switch(op)
  {
   case '1': adicion_u();break;
   case '2': modificar_u();break;
   case '3': eliminar_u();break;
   case '4': menup();break;
  } }while(op!='4');
} */
//******************************************
void marycarmen::mconsulta()
{
char op;
 do
 {
  clrscr();textbackground(9);
  ventana(4,4,76,24);
  gotoxy(26,8); cout<<"M E N U  C O N S U L T A S";
  gotoxy(32,10); cout<<"1. Por Codigos";
  gotoxy(32,11); cout<<"2. -----------";
  gotoxy(32,12); cout<<"3. Salir";
//  ventana(20,7,60,16);
  gotoxy(28,18); cout<<"DIGITE LA OPCION: ";
  do
  {
   gotoxy(46,18); op=getche();
    }while(op<'1'||op>'3');
  switch(op)
  {
   case '1':consdatos();break;
//   case '2': consultau();break;
   case '3':menup();break;
  }
 }while(op!='3');
}
//****************************************/
void  marycarmen::ver()

{
p=ptr;
  clrscr();
  while(p!=NULL)
  {
    gotoxy(20,10); cout<<p->ncaja;
     p=p->sig;
   }
   getchar();
}




void main()
{
 clrscr();
 marycarmen c;
 textbackground(9);textcolor(15);
 c.menup();
}
