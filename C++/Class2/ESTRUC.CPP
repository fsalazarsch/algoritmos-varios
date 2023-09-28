#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#include <iostream.h>
#include <iomanip.h>
class estudiantes{
		    struct notas{
				  char nom[20],ape[20],cod[10];
				  float n1,n2,n3,n4,def;
				  struct notas *sig;
				  struct notas *ant;
				 };

  public:
     char nom[20],ape[20],cod[10],op,*auxch;
     float n1,n2,n3,n4,def,auxnot;
     notas *nn,*p,*ptr,*q; int sw,x;
     void panta();void panta2();
     void f_l(int f,int l);
     void adicionar_inicio(),eliminar_inicio(),consultax_codigo();
     void visualizar_todo(),perdedores_gral(),perd_1_2notas();
     void ganadores_gral(),menu_prin(),menu_consulta();
     void cuad_general(),cuad_perd_gral(),blanco(),esc(char p[20]);
     estudiantes(notas *nulo){ptr=nulo;}//constructor.
     char *val_nom(int y, int x);
     char *val_cod(int y,int x);
     float val_nota(int y, int x);
     void ventana(int X1,int Y1,int X2,int Y2);
     void ordenar();
};
/***********************************************************/
void estudiantes::esc(char p[25])
{
   window(3,22,70,22);
   clrscr();f_l(1,5);
   gotoxy(25,1);cout<<p;delay(700);
   clrscr();
   window(1,1,80,25);f_l(1,14);
}
/**************VALIDACION PARA EL NOMBRE DEL ARTICULO*******************/
char *estudiantes::val_nom(int y, int x)
{
  int i, n; char nombre[20];
  do{
     gotoxy(y,x);sw=0;window(y,x,78,x);clreol();
     cin>>nombre;window(1,1,80,25);
     if((n=strlen(nombre))>20) {sw=1; esc("!!!NOMBRE FUERA DE RANGO!!!");}
     else{
	    for(i=0;i<n;i++)
	    if(!isalpha(nombre[i])) {sw=1; esc("!!!NOMBRE ERRADO!!!");}
	    }
    }while(sw==1);
     return(strupr(nombre));
}
/************************************************************/
char *estudiantes::val_cod(int y,int x)
{  int i,l;
   do{
       do{
	   gotoxy(y,x);window(y,x,78,x);clreol();sw=0;
	   cin>>cod;window(1,1,80,25);l=strlen(cod);
	   if(l!=8)
	   {sw=1; esc("!! CODIGO FUERA DE RANGO !!");}
	 }while(l!=8);
	 sw=0;
	 for(i=0;i<l;i++)
	 if(!isdigit(cod[i])){sw=1; esc("!! CODIGO ERRADO !!");}
       }while(sw==1);
       return(cod);
}
/************************************************************/
float estudiantes::val_nota(int y, int x)
{ int i,l; char nota[15]; float not;
  do{
	 do{
	    sw=0; gotoxy(y,x);window(y,x,78,x);clreol();
	    cin>>nota;window(1,1,80,25);
	    if(!isdigit(nota[0])){sw=1; esc("!!!NOTA ERRADA!!!");}
	    else{
		  l=strlen(nota)-1;
		  if((nota[1]!='.')&&(l>0))
		  { sw=1; esc("!!!NOTA ERRADA!!!");}
		  else{
		       l=strlen(nota);
		       if(l>1)
		       { for(i=2;i<l;i++) if(!isdigit(nota[i]))
			    { sw=1; esc("!!!NOTA ERRADA!!!");}
		       }
		      }
		}
	    }while(sw==1);
	    not=atof(nota);
	    if((not<0)||(not>5))
	    {sw=1; esc("!!NOTA FUERA DE RANGO!!");}
    }while(sw==1);
    return(not);
}
/***********************************************************/
void estudiantes::adicionar_inicio()
{  char p1e=17,p2e=191;
 do{       clrscr();
	    ventana(1,2,80,25);ventana(21,3,49,5);
	   gotoxy(22,4);cout<<"<< ADICION DE ESTUDIANTE >>";
	   gotoxy(10,6);cout<<"DIGITE EL CODIGO DEL ESTUDIANTE :";
	    strcpy(cod,val_cod(48,6));
	      p=ptr; sw=0;
	   while(p!=NULL)
	   { if(!strcmp(cod,p->cod)){sw=1;break;}
	     p=p->sig;
	   }
	  if(sw==1){
		   ventana(2,1,79,24);ventana(24,10,56,12);
		    gotoxy(25,11);cout<<"!!!...EL CODIGO YA EXISTE...!!!";
		    gotoxy(20,24);
	    cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
		    }
      else{
		 gotoxy(10,8);cout<<"DIGITE EL NOMBRE   :";
		 strcpy(nom,val_nom(38,8));
		 gotoxy(10,10);cout<<"DIGITE EL APELLIDO :";
		 strcpy(ape,val_nom(38,10));
		 gotoxy(10,12);cout<<"PRIMER PARCIAL    :";
		 n1=val_nota(38,12);
		 gotoxy(10,14);cout<<"SEGUNDO PARCIAL   :";
		 n2=val_nota(38,14);
		 gotoxy(10,16);cout<<"NOTA 20 %         :";
		 n3=val_nota(38,16);
		 gotoxy(10,18);cout<<"EXAMEN FINAL      :";
		 n4=val_nota(38,18);
		 nn=new notas;
		  strcpy(nn->cod,cod);
		  strcpy(nn->nom,nom);
		  strcpy(nn->ape,ape);
		  nn->n1=n1; nn->n2=n2; nn->n3=n3; nn->n4=n4;
		  def=((n1*.25)+(n2*.25)+(n3*.20)+(n4*.30));
		  nn->def=def;
		  nn->sig=nn->ant=NULL;
		  if(ptr==NULL)
		  { ptr=nn;
		   gotoxy(20,21);cout<<"!!!!...ALUMNO  ADICIONADO...!!!";
		  }
		  else{
			p=ptr; ptr=nn; ptr->sig=p;
		      gotoxy(20,21);cout<<"!!!!...ALUMNO  ADICIONADO...!!!";
		      }
	}
	gotoxy(16,23);cout<<"DESEA ADICIONAR OTRO ESTUDIANTE? [S/N]:";
	op=toupper(getche());
   }while(op=='S');
}
/**************************************************************/
void estudiantes::eliminar_inicio()
{   char p1e=17,p2e=191;
  do{
      clrscr();
      if(ptr==NULL)
      { ventana(2,1,79,25);ventana(24,10,52,13);
	gotoxy(28,11);cout<<"..NO SE PUEDE ELIMINAR";
	gotoxy(29,12);cout<<"NO HAY ESTUDIANTES...";op='N';
	 gotoxy(20,24);
	 cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
	getche();
      }
      else{
	    p=ptr;
	    ptr=p->sig;
	    ptr->ant=NULL;
	    p->sig=NULL;
	    delete(p);
	     ventana(2,1,79,24);ventana(23,10,53,14);
	     gotoxy(25,12);cout<<"!! ESTUDIANTE ELIMINADO !!";
	     gotoxy(25,22);cout<<"DESEA ELIMNAR OTRO? [S/N]:";
	     op=toupper(getche());
	   }
    }while(op=='S');
}
/**************************************************************/
void estudiantes::consultax_codigo()
{     char p1e=17,p2e=191;
  do{
       clrscr();
       ventana(1,2,80,25);
       ventana(19,2,56,4);
       gotoxy(24,3);
       cout<<"<<   CONSULTA POR CODIGO   >>";
       gotoxy(28,5);cout<<"DIGITE EL CODIGO:";
       strcpy(cod,val_cod(48,5));
       p=ptr; sw=0;
       while(p!=NULL)
       { if(!strcmp(cod,p->cod)){sw=1;break;}
	 p=p->sig;
       }
     if(sw==0) {clrscr();gotoxy(22,12);
     cout<<"... EL ESTUDIANTE NO EXISTE ...";
     ventana(1,2,80,25);ventana(20,10,56,12);
     gotoxy(20,23);
     cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
     getche();}
     else{
	   gotoxy(28,7);cout<<"NOMBRE      : "<<p->nom;
	   gotoxy(28,8);cout<<"APELLIDO    : "<<p->ape;
	   gotoxy(28,9);cout<<"NOTA 1      : "<<setprecision(1)<<p->n1;
	   gotoxy(28,10);cout<<"NOTA 2      : "<<setprecision(1)<<p->n2;
	   gotoxy(28,11);cout<<"NOTA 20%    : "<<setprecision(1)<<p->n3;
	   gotoxy(28,12);cout<<"EXAMEN      : "<<setprecision(1)<<p->n4;
	   gotoxy(28,13);cout<<"DEFINITIVA  : "<<setprecision(1)<<p->def;
	  }
	  gotoxy(18,18);cout<<"DESEA VISUALIZAR OTRO ESTUDIANTE? [S/N]:";
	  gotoxy(20,23);
	  cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
	    op=toupper(getche());
    }while(op=='S');
}
/**************************************************************/
void estudiantes::visualizar_todo()
{  sw=0; int fil=6;clrscr();char p1e=17,p2e=191;
   if(ptr==NULL)
   { clrscr();   ventana(2,1,79,25);ventana(23,9,53,14);
     gotoxy(25,11);cout<<"NO SE PUEDE VISUALIZAR...";
     gotoxy(27,12);cout<<"...NO HAY INFORMACION";
     gotoxy(20,24);
     cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
     }
    else{
	   p=ptr;
	  while(p!=NULL)
	  {  cuad_general();gotoxy(22,2);sw=1;
	     cout<<"LISTADO GENERAL DE ESTUDIANTES";
	     gotoxy(3,fil);cout<<p->cod;
	     gotoxy(13,fil);cout<<p->nom;
	     gotoxy(35,fil);cout<<p->ape;
	     gotoxy(60,fil);cout<<setprecision(1)<<p->n1;
	     gotoxy(64,fil);cout<<setprecision(1)<<p->n2;
	     gotoxy(68,fil);cout<<setprecision(1)<<p->n3;
	     gotoxy(72,fil);cout<<setprecision(1)<<p->n4;
	     gotoxy(76,fil);cout<<setprecision(1)<<p->def;
	      fil++;p=p->sig;
	    }
	} getche();
}
/**************************************************************/
void estudiantes::perdedores_gral()
{ int ctper=0,x=7;sw=0; char p1e=17,p2e=191;clrscr();
  p=ptr;
  while(p!=NULL)
  {    if(p->def<3)
	{  cuad_perd_gral();ctper++;sw=1;
	   gotoxy(26,3);cout<<"LISTADO ESTUDIANTES PERDEDORES";
	   gotoxy(36,23);cout<<"TOTAL PERDEDORES:";
	   gotoxy(9,x);cout<<p->cod;
	   gotoxy(18,x);cout<<p->nom;
	   gotoxy(39,x);cout<<p->ape;
	   gotoxy(69,x);cout<<setprecision(1)<<p->def;
	   gotoxy(55,23);cout<<ctper;x++;
	} p=p->sig;
  }
  if(sw==0){clrscr();ventana(2,1,79,25);ventana(21,10,59,14);
	    gotoxy(23,12);cout<<"!! NO HAY ESTUDIANTES PERDEDORES !!";
	    gotoxy(20,24);
	 cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
	    }
 getche();
 }
/**************************************************************/
void estudiantes::ganadores_gral()
{
   int ctgan=0,x=7;sw=0;char p1e=17,p2e=191;clrscr();
   p=ptr;
   while(p!=NULL)
   {
     if(p->def>=3)
     {  cuad_perd_gral(); ctgan++;sw=1;
	gotoxy(26,3);cout<<"LISTADO ESTUDIANTES GANADORES";
	gotoxy(36,23);cout<<"TOTAL GANADORES:";
	 gotoxy(9,x);cout<<p->cod;
	   gotoxy(18,x);cout<<p->nom;
	   gotoxy(39,x);cout<<p->ape;
	   gotoxy(69,x);cout<<setprecision(1)<<p->def;
	   gotoxy(55,23);cout<<ctgan;  x++;
	} p=p->sig;
     }
     if(sw==0){clrscr();ventana(2,1,79,25);ventana(21,10,55,14);
	    gotoxy(23,12);cout<<"NO HAY ESTUDIANTES GANADORES";
	    gotoxy(20,24);
	    cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
	    }
 getche();
 }
/**************************************************************/
void estudiantes::menu_prin()
{
  int tecla,f; char t1=24,t2=25;
 char opciones[9][70];
 do
 {
       strcpy(opciones[1], "1. ADICIONAR             ");
       strcpy(opciones[2], "2. ELIMINAR              ");
       strcpy(opciones[3], "3. CONSULTAR POR CODIGO  ");
       strcpy(opciones[4], "4. ORDENAR               ");
       strcpy(opciones[5], "5. VISUALIZAR            ");
       strcpy(opciones[6], "6. OTRAS CONSULTAS       ");
       strcpy(opciones[7], "7. SALIR                 ");
      clrscr();
     f_l(1,14);
      panta2(); ventana(25,4,48,6);
      gotoxy(27,5);cout<<"<< MENU PRINCIPAL >>";
      gotoxy(13,18);
    cout<<"!! UTILICE LAS TECLAS DEL CURSOR "<<t1<<t2<<" PARA DESPLAZARSE !!";
     gotoxy(15,22);
   cout<<"!! PULSE (ENTER) PARA ESCOGER LA OPCION QUE DESEE !!";
    ventana(24,7,50,15);    f_l(1,14);
      gotoxy(36,6);cout<<"Ë";
      gotoxy(36,7);cout<<"Ê";
    for(f=1;f<=7;f++) {gotoxy(25,f+7);cprintf("%s",opciones[f]);}
       f=1;   f_l(7,5);
     gotoxy(25,f+7);cprintf("%s",opciones[f]);
	      f_l(1,14);

  do
  {
	 do
	 {
	     tecla=getch();
	  }while((tecla==80)&&(tecla==72)&&(tecla==13));
   /********************************/
	if(tecla==80)
	{   f_l(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	       if (f!=7)
	      {   f++;   f_l(7,5);
		gotoxy(25,f+7);  cprintf("%s",opciones[f]);
		f_l(1,14);
	       }
	else
	   {
	      f=1;    f_l(7,5);
	      gotoxy(25,f+7);cprintf("%s",opciones[f]);  f_l(1,14);
	   }
   }
   /*************************/
	if(tecla == 72)
	 {  f_l(1,14);
	    gotoxy(25,f+7);cprintf("%s",opciones[f]);
	   if (f!=1)
	     {   f--;  f_l(7,5);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 f_l(1,14);
	      }
	       else
	      {  f=7;  f_l(7,5);
		 gotoxy(25,f+7); cprintf("%s",opciones[f]);
		 f_l(1,14);
	       }
	  }

  }while(tecla!=13);
  /********************************/
  switch(f)
	  {  case 1: adicionar_inicio();break;
	    case 2: eliminar_inicio();break;
	    case 3: consultax_codigo();break;
	    case 4: ordenar();break;
	    case 5: visualizar_todo();break;
	    case 6: menu_consulta();break;
	  }
 }while(f!=7);
}
/**************************************************************/
void estudiantes::perd_1_2notas()
{  clrscr(); char p1e=17,p2e=191;
 int perd=0,x=6;sw=0;
      p=ptr;
       while(p!=NULL)
      {     int ct1=0,ct2=0,ct3=0,ct4=0,conto=0;
	    if(p->n1<3)ct1++;
	    if(p->n2<3)ct2++;
	    if(p->n3<3)ct3++;
	    if(p->n4<3)ct4++;
	      conto=ct1+ct2+ct3+ct4;
	  if((conto>=1)&&(conto<=2))
	 {  sw=1; cuad_general();
	 perd++;window(64,2,78,2);clreol();
		window(1,1,80,25);gotoxy(12,2);
	 cout<<"ESTUDIANTES QUE PERDIERON A LO MAS 2 NOTAS PARCIALES: "<<perd;
		  if(ct1==1){gotoxy(3,x);cout<<p->cod;
			     gotoxy(12,x);cout<<p->nom;
			     gotoxy(29,x);cout<<p->ape;
			     gotoxy(60,x);cout<<setprecision(1)<<p->n1;
			     gotoxy(76,x);cout<<setprecision(1)<<p->def;}

		  if(ct2==1){gotoxy(3,x);cout<<p->cod;
			     gotoxy(12,x);cout<<p->nom;
			     gotoxy(29,x);cout<<p->ape;
			     gotoxy(64,x);cout<<setprecision(1)<<p->n2;
			     gotoxy(76,x);cout<<setprecision(1)<<p->def;}
		 if(ct3==1){gotoxy(3,x);cout<<p->cod;
			    gotoxy(12,x);cout<<p->nom;
			    gotoxy(29,x);cout<<p->ape;
			    gotoxy(68,x);cout<<setprecision(1)<<p->n3;
			    gotoxy(76,x);cout<<setprecision(1)<<p->def;}
		  if(ct4==1){gotoxy(3,x);cout<<p->cod;
			     gotoxy(12,x);cout<<p->nom;
			     gotoxy(29,x);cout<<p->ape;
			     gotoxy(72,x);cout<<setprecision(1)<<p->n4;
			    gotoxy(76,x);cout<<setprecision(1)<<p->def;}
			    x++;
	 }
			 p=p->sig;
       }
     if(sw==0){clrscr();ventana(2,1,79,25);ventana(21,10,55,14);
	    gotoxy(23,11);cout<<"NO HAY INFORMACION O NO......";
	    gotoxy(23,13);cout<<"......SE CUMPLE LA CONDICION";
	    gotoxy(20,24);
	 cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
	    }
  getche();
}

/**************************************************************/
void estudiantes::ordenar()
{ char p1e=17,p2e=191;
  if(ptr==NULL) { clrscr();ventana(2,1,79,25);ventana(25,10,52,14);
    gotoxy(27,11);cout<<"...NO HAY ESTUDIANTES...";
     gotoxy(26,13);cout<<"...NO SE PUEDE ORDENAR...";
     gotoxy(20,24);
     cout<<"!! OPRIMA  [ENTER] "<<p1e<<p2e<<" PARA TERMINAR !!";
     getche(); }
     else{
    clrscr();
    ventana(2,1,79,24);ventana(25,10,51,15);
    gotoxy(28,12);cout<<"!!!...ORDENANDO...!!!";
    gotoxy(28,13);cout<<"!!!.....ESPERE....!!!";
    delay(1000);
    clrscr();ventana(2,1,79,24);ventana(20,10,57,14);
     gotoxy(23,12);cout<<"!!!...LISTO..!!..ORDENADO....!!!";
     delay(600);
     p=ptr; q=p;
  while(p!=NULL)
  {
       while(q!=NULL)
       {  if(strcmp(p->cod,q->cod)>0)
	  {
	      strcpy(auxch,p->cod);
	      strcpy(p->cod,q->cod);
	      strcpy(q->cod,auxch);

	      strcpy(auxch,p->nom);
	      strcpy(p->nom,q->nom);
	      strcpy(q->nom,auxch);

	      strcpy(auxch,p->ape);
	      strcpy(p->ape,q->ape);
	      strcpy(q->ape,auxch);

	      auxnot=p->n1;
	      p->n1=q->n1;
	      q->n1=auxnot;

	      auxnot=p->n2;
	      p->n2=q->n2;
	      q->n2=auxnot;

	      auxnot=p->n3;
	      p->n3=q->n3;
	      q->n3=auxnot;

	      auxnot=p->n4;
	      p->n4=q->n4;
	      q->n4=auxnot;

	      auxnot=p->def;
	      p->def=q->def;
	      q->def=auxnot;
	  }
	      q=q->sig;
       }
       p=p->sig;  q=p;
  }
 }
}
/**************************************************************/
void estudiantes::menu_consulta()
{
  int tecla,f; char t1=24,t2=25;
 char opciones[10][70];
 do
 {
      strcpy(opciones[1], "1. ESTUDIANTES PERDEDORES  ");
      strcpy(opciones[2], "2. PERD A LO MAS 2 NOTAS   ");
      strcpy(opciones[3], "3. ESTUDIANTES GANADORES   ");
      strcpy(opciones[4], "4. PROCEDIMIENTO EN BLANCO ");
      strcpy(opciones[5], "5. VOLVER AL MENU PRINCIPAL");
      clrscr(); f_l(0,12); panta();
	    gotoxy(27,5);cout<<"<< MENU CONSULTAS >>";
      gotoxy(13,18);
    cout<<"!! UTILICE LAS TECLAS DEL CURSOR "<<t1<<t2<<" PARA DESPLAZARSE !!";
      gotoxy(15,19);
      cout<<"!! PULSE (ENTER) PARA ESCOGER LA OPCION QUE DESEE !!";
      ventana(24,8,52,14);    f_l(1,14);
      for(f=1;f<=5;f++) {gotoxy(25,f+8);cprintf("%s",opciones[f]);}
       /***********************/
       f=1;     f_l(1,11);
       gotoxy(25,f+8);cprintf("%s",opciones[f]);
       f_l(1,14);

  do
  {
	    do
	    {
	     tecla=getch();
	    }while((tecla==80)&&(tecla==72)&&(tecla==13));
	   /*************************/
	   if(tecla==80)
	 {
	    f_l(1,14);
	    gotoxy(25,f+8);cprintf("%s",opciones[f]);
	     if (f!=5)
	     {
	       f++;
		f_l(1,11);
	       gotoxy(25,f+8);  cprintf("%s",opciones[f]);
	       f_l(1,14);
	     }
	     else
	     {
	      f=1;
	      f_l(1,11);
	      gotoxy(25,f+8);cprintf("%s",opciones[f]);
	      f_l(1,14);
	  }
     }
    /************************/
       if(tecla == 72)
      {
	    f_l(1,14);
	     gotoxy(25,f+8);cprintf("%s",opciones[f]);
	    if (f!=1)
	    {
	       f--;
		f_l(1,11);
		gotoxy(25,f+8); cprintf("%s",opciones[f]);
	       f_l(1,14);
	    }
	    else
	   {
	     f=5;
	     f_l(1,11);
	     gotoxy(25,f+8); cprintf("%s",opciones[f]);
	     f_l(1,14);
	   }
      }
  }while(tecla!=13);
     /*********************************/
     switch(f)
	     {
	       case 1: perdedores_gral();break;
	       case 2: perd_1_2notas();break;
	       case 3: ganadores_gral();break;
	       case 4: blanco();break;
	      }
 }while(f!=5);
}

/**************************************************************/
void estudiantes::ventana(int X1,int Y1,int X2,int Y2)
{    int i;
 for(i=X1+1;i<X2;i++){
 gotoxy(i,Y1);cout<<"Í";   // LINEA ARRIBA HORIZONTAL
 gotoxy(i,Y2);cout<<"Í";}  // LINEA ABAJO HORIZONTAL
 for(i=Y1+1;i<Y2;i++){
 gotoxy(X1,i);cout<<"º";    // LINEA IZQUIERDA VERTICAL
 gotoxy(X2,i);cout<<"º";}   // LINEA DERECHA VERTICAL
 gotoxy(X1,Y1);cout<<"É";
 gotoxy(X1,Y2); cout<<"È";
 gotoxy(X2,Y1);cout<<"»";
 gotoxy(X2,Y2); cout<<"¼";
}
/**************************************************************************/
void estudiantes::cuad_perd_gral()
{ventana(8,2,72,22);ventana(8,2,72,4);ventana(8,2,72,24);ventana(8,4,72,6);
ventana(8,4,17,22);ventana(68,4,72,22);ventana(17,4,38,22);gotoxy(28,5);
cout<<"NOMBRE";gotoxy(10,5);cout<<"CODIGO";gotoxy(48,5);cout<<"APELLIDO";
gotoxy(69,5);cout<<"DEF";gotoxy(8,4);cout<<"Ì";gotoxy(72,4);cout<<"¹";
gotoxy(17,4);cout<<"Ë";gotoxy(38,4);cout<<"Ë";gotoxy(8,6);cout<<"Ì";
gotoxy(17,6);cout<<"Î";gotoxy(38,6);cout<<"Î";gotoxy(68,6);cout<<"Î";
gotoxy(72,6);cout<<"¹"; gotoxy(8,22);cout<<"Ì";gotoxy(17,22);cout<<"Ê";
gotoxy(38,22);cout<<"Ê";gotoxy(68,22);cout<<"Ê";gotoxy(72,22);cout<<"¹"; }
/**************************************************************************/
void estudiantes::cuad_general()
{   int x=3,i,j,k;ventana(2,1,79,25);ventana(2,1,79,3);
ventana(2,3,79,5);ventana(75,3,79,25);ventana(71,3,79,25);
ventana(67,3,71,25);ventana(63,3,67,25);ventana(59,3,63,25);
ventana(2,3,11,25);ventana(11,3,28,25); gotoxy(4,4);cout<<"CODIGO";
gotoxy(17,4);cout<<"NOMBRE";gotoxy(37,4);cout<<"APELLIDO";
gotoxy(60,4);cout<<"NT1";gotoxy(64,4);cout<<"NT2";
gotoxy(68,4);cout<<"NT3";gotoxy(72,4);cout<<"NT4";
gotoxy(76,4);cout<<"DEF";gotoxy(2,3);cout<<"Ì";
gotoxy(11,3);cout<<"Ë";gotoxy(28,3);cout<<"Ë";
for(i=59;i<=75;i+=4){ gotoxy(i,x);cout<<"Ë";}gotoxy(79,3);cout<<"¹";
gotoxy(2,5);cout<<"Ì";gotoxy(11,5);cout<<"Î";gotoxy(28,5);cout<<"Î";
gotoxy(28,5);cout<<"Î";
for(j=59;j<=75;j+=4){gotoxy(j,x+2);cout<<"Î";}gotoxy(79,5);cout<<"¹";
gotoxy(11,25);cout<<"Ê"; gotoxy(28,25);cout<<"Ê";
for(k=59;k<=75;k+=4){gotoxy(k,x+22);cout<<"Ê";}
}
/*********************************************************************/
 void main()
 { estudiantes objeto(NULL);
   objeto.menu_prin();
 }
/*********************************************************************/
void estudiantes::panta()
{ ventana(1,3,80,22);
  ventana(5,2,75,23);
  ventana(9,1,71,24);
}
/*********************************************************************/
void estudiantes::panta2()
{ ventana(1,1,80,3);/*cuadro de arriba*/
  ventana(1,20,80,24);/*abajo-grande*/
  ventana(6,21,75,23);/***abajo-peque**/
  ventana(1,1,80,24);/*mas grande*/
  }

/************** FONDO_LETRA *****************************************/
void estudiantes::f_l(int f,int l)
{  textbackground(f);
   textcolor(l);
}
/***************************************************************/
void estudiantes::blanco()
{  clrscr();
   gotoxy(25,10);cout<<"!!  OIGA ESTO ESTA EN BLANCO !!";
   gotoxy(15,12);cout<<"...ES PARA EL PROCEDIMIENTO QUE PIDA EL TEACHER!!";
   getche();
}
/**************************************************************/
