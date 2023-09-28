#include<iostream.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<ctype.h>

#define new (nodo*)malloc(sizeof(nodo))
typedef struct nodo nodo;

class alumnos
{
 struct nodo
 {
  char nom[25],cod[10],mat[20],cur[5];
  float sum,suma,nota1,nota2,nota3,nota4,prom,promed;
  struct nodo*izd;
  struct nodo*der;

 };
 struct nodo *cab,*p,*ptr,*r,*q,nuevo,*raiz;

 public:
	alumnos(struct nodo *a){ptr=a;}
	void a_alumnos();
	void consulta();
	void modificar();
	void elim();
	void ordenar();
	void visualizar(nodo *b);
	void consultar_curso();
	void consultar_codigo();
	void consultar_materia();
	void menu();
	int su,sw;
};
char nom[45],cod[10],mat[15];
int cur;

/*************************************************************************/
/******************   FUNCION  FONDO CUADRO ******************************/
/*************************************************************************/
color(int prin,int fin,int fl,int cl,int co)
{
 int i,tem;
 tem=fl;
 for(i=prin;i<=fin;i++)
  {
    textbackground(co); gotoxy(i,fl); cprintf(" ");
    if(i==fin)
     {
       i=prin-1;
       tem++;
       fl++;
     }
    if(tem==cl)
     {
       i=85;
     }
  }
 return(0);
 }
/**************************************************************************/                                                                           
/****************************** FUNCION MARCOS ***************************/
/**************************************************************************/
marco(int prin,int fin,int fl,int cl,int co)
{
int i;
  for(i=prin;i<=fin;i++)
  {
    textcolor(co);
    gotoxy(i,fl);cprintf("Í");
    gotoxy(i,cl);cprintf("Í");
  }
  for(i=fl;i<=cl;i++)
  {
    textcolor(co);
    gotoxy(prin,i);cprintf("º");
    gotoxy(fin,i);cprintf("º");
  }
    gotoxy(prin,fl);cprintf("É");
    gotoxy(fin,fl);cprintf("»");
    gotoxy(prin,cl);cprintf("È");
    gotoxy(fin,cl);cprintf("¼");
  return(0);
}
/***************************************************************************/
/**************************  FUNCION ELIMINAR ******************************/
/***************************************************************************/
eliminando(int prin,int fin,int fl,int co,int co1)
{
  int i,v,c;
  v=7;
  c=56;
  textbackground(0);
  for(i=prin;i<=fin;i++)
   {
     textcolor(co);
     gotoxy(i,fl);cprintf("°");
   }
  for(i=prin;i<=fin;i++)
   {
     textcolor(co1);
     gotoxy(i,fl);cprintf("²");delay(50);
     gotoxy(c,12);cprintf("%d",v=v+3);
     gotoxy(58,12);cprintf("%");
     if(v==97)
       c--;
   }
  return(0);
}
/**************************************************************************/
/************************* VALIDAR NUMEROS ********************************/
/**************************************************************************/
digit(char dig[20],int pc,int pf)
{
  char continuar;
  int lon;
   do{
	continuar='n';
	gotoxy(pc,pf);clreol();scanf("\n");gets(dig);
	lon=strlen(dig);
	for(int i=0; i<=lon-1; i++)
	 {
	 if(!(isdigit(dig[i])))
	  {
	   continuar='s';
	  }
	 }
    }while (continuar=='s');
  return(0);
}
/***************************************************************************/
/**************************** VALIDAR LETRAS ******************************/
/***************************************************************************/
caract(char car[20],int pc,int pf)
{
  char continuar;
  int lon;
   do{
	continuar='n';
	gotoxy(pc,pf);clreol();scanf("\n");gets(car);
	lon=strlen(car);
	for(int i=0; i<=lon-1; i++)
	 {
	   if(car[i]==' ')
	    {
		i++;
	    }
	   if(!(isalpha(car[i])))
	    {
	      continuar='s';
	    }
	 }
    }while (continuar=='s');
  return(0);
}
/***************************************************************************/
/*************************** VALIDAR NOTAS ********************************/
/***************************************************************************/
num(float dig,int pc,int pf)
{
  char continuar;
  int lon;
   do{
       continuar='n';
       gotoxy(pc,pf);clreol();scanf("%f",&dig);
	   if((dig<0)||(dig>5))
	    {
	      continuar='s';
	    }
   }while (continuar=='s');
  return(0);
}
/***************************************************************************/
/****************************  ADICIONAR   *********************************/
/***************************************************************************/
void alumnos::a_alumnos()
{
  clrscr();
  char  cod[10],nom[25],mat[20];
  float n1,n2,n3,sum,n4,suma;
  int op,ex,cur;
  nodo *r;
  ex=0;
  suma=0;
  do
  {
  clrscr();
  color(1,80,1,25,1);
  color(25,55,4,6,1);
  marco(25,55,4,6,14);
  gotoxy(28,5);cprintf("ADICIONANDO ESTUDIANTES");
  gotoxy(10,8);cprintf("DIGITE CODIGO DEL ESTUDIANTE:");
  digit(cod,40,8);
  r=cab;
  if(r->der!=NULL)
   {
  while(r!=NULL)
   {
     if(strcmp(r->cod,cod)==0)
      {
	    gotoxy(20,12);textcolor(14);
	    gotoxy(20,12);cprintf(" ESTE CODIGO YA EXISTE ");getch();
	    ex=1;
      }


      r=r->der;
   }
  }
  if(ex==0)
  {
  gotoxy(10,9);cprintf("DIGITE NOMBRE DEL ESTUDIANTE:");
  caract(nom,40,9);
  gotoxy(10,10);cprintf("DIGITE MATERIA DEL ESTUDIANTE:");
  caract(mat,40,10);
  gotoxy(10,11);cprintf("DIGITE CURSO DEL ESTUDIANTE:");
 digit(cur,40,11);
  color(13,70,14,21,0);
  marco(13,70,14,21,14);
  gotoxy(18,15);cprintf("NOTAS     1ra        2da        3ra        4ta ");
  gotoxy(28,17);scanf("%f",&n1);
  gotoxy(39,17);scanf("%f",&n2);
  gotoxy(50,17);scanf("%f",&n3);
  gotoxy(61,17);scanf("%f",&n4);
  suma=((n1*0.25)+(n2*0.25)+(n3*0.20)+(n4*0.30));
  gotoxy(25,19);printf("PROMEDIO DEL ESTUDIANTE :%.2f",suma);
  if(su==1)
    {
      sum=0;
       q=new;
       strcpy(q->cod,cod);
       strcpy(q->nom,nom);
       strcpy(q->mat,mat);
       strcpy(q->cur,cur);
       q->nota1=n1;
       q->nota2=n2;
       q->nota3=n3;
       q->nota4=n4;
       sum=n1+n2+n3+n4;
       q->prom=sum/4;
       q->izd=p;
       q->der=NULL;
       p->der=q;
       p=p->der;
       
    }
  if(su==0)
   {
     sum=0;
     p=new;
     cab=p;
     strcpy(p->cod,cod);
     strcpy(p->nom,nom);
     strcpy(q->mat,mat);
     strcpy(q->cur,cur);
     p->nota1=n1;
     p->nota2=n2;
     p->nota3=n3;
     p->nota4=n4;
     sum=n1+n2+n3+n4;
     p->prom=sum/4;
     p->izd=NULL;
     p->der=NULL;
     su=1;
   }
  }
  ex=0;
  gotoxy(20,23);cprintf(" DESEA CONTINUAR ADICIONANDO S/N");
  op=toupper(getch());
  }while(op=='S'||op=='s');
}
/***************************************************************************/
/****************************  CONSULTA  ***********************************/
/**************************************************************************/
void alumnos::consulta()
{
 int f,c,tecla,l;
 char opcion[21][75];
 f=10;
 c=30;
 su=0;
 strcpy(opcion[10],"CONSULTAR POR CURSO");
 strcpy(opcion[11],"CONSULTAR POR MATERIAS");
 strcpy(opcion[12],"CONSULTAR POR CODIGO");
 strcpy(opcion[13],"SALIR");
 do
 {
  textcolor(14);textbackground(0);
  clrscr();
  color(1,80,1,25,1);
  color(20,57,4,5,0);
  marco(20,57,3,5,14);
  gotoxy(24,4);cprintf(" M E N U   C O N S U L T A R");
  color(20,57,9,15,0 );
  marco(20,57,9,15,14);
  for(l=10;l<=13;l=l+1)
  {
   gotoxy(c,l);cprintf("%s",opcion[l]);
  }
  textcolor(0);textbackground(7);
  gotoxy(c,f);cprintf("%s",opcion[f]);
  do
  {
   do
   {
    tecla=getch();
   }while((tecla==80)&&(tecla==72)&&(tecla==13));
   if(tecla==80)
   {
    textcolor(14);textbackground(0);
    gotoxy(c,f);cprintf("%s",opcion[f]);
    if(f!=13)
    {
     f=f+1;
     textcolor(0);textbackground(7);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     textcolor(14);textbackground(0);
    }
    else
    {
     f=10;
	textcolor(0);textbackground(7);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     textcolor(14);textbackground(0);
    }
   }
   if(tecla==72)
   {
    textcolor(14);textbackground(0);
    gotoxy(c,f);cprintf("%s",opcion[f]);
    if(f!=10)
    {
     f=f-1;
     textcolor(0);textbackground(7);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     textcolor(14);textbackground(0);
    }
    else
    {
     f=13;
     textcolor(0);textbackground(7);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     textcolor(14);textbackground(0);
    }
   }
  }while(tecla!=13);
  switch(f)
  {
	   case 10:consultar_curso();break;
	   case 11:consultar_materia();break;
	   case 12:consultar_codigo();break;
	   case 13:menu();
       }
   }while(f!=13);
}
/************************************************************************/
void alumnos::consultar_codigo()

{
  clrscr();
  char  op,cod[10],nomb[25],cur[10],mat[20];
  int sw;
  float suma,n1,n2,n3,n4;
  nodo *r,*p,*p1;
 do
  {
  clrscr();
  color(1,80,1,25,1);
  color(20,56,3,5,1);
  marco(20,57,3,5,14);
  gotoxy(28,4);cprintf("CONSULTAR ESTUDIANTES");
  if(r==NULL)
  {
   gotoxy(19,22); cout<<"lista vacia"; 
  }
  else
  {
   gotoxy(50,7);textcolor(14);
   r=cab;
   gotoxy(23,7);cprintf("DIGITE EL CODIGO A CONSULTAR:");scanf("\n");
   gets(cod);
   while(r!=NULL)
   {
    if(!strcmp(cod,r->cod))
    {
     sw=1;
     textcolor(14);textbackground(8);
     color(4,77,9,18,0);
     marco(4,77,9,18,14);
     gotoxy(9,11);cprintf("NOMBRE DEL ALUMNO: %s",r->nom);
     gotoxy(9,12);cprintf("MATERIA : %s",r->mat);
     gotoxy(9,13);cprintf("CURSO: %s",r->cur);
     gotoxy(9,15);cprintf("NOTAS     1ra        2da        3ra        4ta        Promedio");
     gotoxy(19,16);cprintf("%.2f",r->nota1);
     gotoxy(30,16);cprintf("%.2f",r->nota2);
     gotoxy(41,16);cprintf("%.2f",r->nota3);
     gotoxy(52,16);cprintf("%.2f",r->nota4);
     gotoxy(63,16);cprintf("%.2f",r->prom);
     break;
    }
     r=r->der;
   }
   getche();
   if(sw==0)
   {  
    textcolor(14);
    gotoxy(20,21);cprintf("CODIGO INEXISTENTE !!");
   }
  }  
  do

  {
   textcolor(14);
   gotoxy(19,22);cprintf("DESEA CONSULTAR OTRO ESTUDIANTE [S/N]");
   op=toupper(getch());
  }while((op!='N')&&(op!='S'));
}while(op!='N');
}
/************************************************************************/
void alumnos::consultar_curso()
{
  clrscr();
  char  op,cod[10],nomb[25],cur[10],mat[20];
  int sw;
  float suma,n1,n2,n3,n4;
  nodo *r,*p,*p1;
 do
  {
  clrscr();
  color(1,80,1,25,1);
  color(20,56,3,5,1);
  marco(20,57,3,5,14);
  gotoxy(28,4);cprintf("CONSULTAR ESTUDIANTES");
  if(r==NULL)
  {
   gotoxy(19,22); cout<<"lista vacia"; 
  }
  else
  {
   gotoxy(50,7);textcolor(14);
   r=cab;
   gotoxy(23,7);cprintf("DIGITE EL CURSO A CONSULTAR:");scanf("\n");
   gets(cur);
   while(r!=NULL)
   {
    if(!strcmp(cur,r->cur))
    {
     sw=1;
     textcolor(14);textbackground(8);
     color(4,77,9,18,0);
     marco(4,77,9,18,14);
     gotoxy(9,11);cprintf("NOMBRE DEL ALUMNO: %s",r->nom);
     gotoxy(9,12);cprintf("MATERIA : %s",r->mat);
     gotoxy(9,13);cprintf("CODIGO: %s",r->cod);
     gotoxy(9,15);cprintf("NOTAS     1ra        2da        3ra        4ta        Promedio");
     gotoxy(19,16);cprintf("%.2f",r->nota1);
     gotoxy(30,16);cprintf("%.2f",r->nota2);
     gotoxy(41,16);cprintf("%.2f",r->nota3);
     gotoxy(52,16);cprintf("%.2f",r->nota4);
     gotoxy(63,16);cprintf("%.2f",r->prom);
     break;
    }
     r=r->der;
   }


   getche();
   if(sw==0)
   {  

    textcolor(14);

    gotoxy(20,21);cprintf("CURSO INEXISTENTE !!");

   }
  }  
  do
  {
   textcolor(14);
   gotoxy(19,22);cprintf("DESEA CONSULTAR OTRO CURSO [S/N]");
   op=toupper(getch());
  }while((op!='N')&&(op!='S'));
}while(op!='N');
}
/************************************************************************/
void alumnos::consultar_materia()
{
  clrscr();
  char  op,cod[10],nomb[25],cur[10],mat[20];
  int sw;
  float suma,n1,n2,n3,n4;
  nodo *r,*p,*p1;
 do
  {
  clrscr();
  color(1,80,1,25,1);
  color(20,56,3,5,1);
  marco(20,57,3,5,14);
  gotoxy(28,4);cprintf("CONSULTAR ESTUDIANTES");
  if(r==NULL)
  {
   gotoxy(19,22); cout<<"lista vacia"; 
  }
  else
  {
   gotoxy(50,7);textcolor(14);
   r=cab;
   gotoxy(23,7);cprintf("DIGITE MATERIA A CONSULTAR:");scanf("\n");
   gets(mat);
   while(r!=NULL)
   {
    if(!strcmp(mat,r->mat))
    {
     sw=1;
     textcolor(14);textbackground(8);
     color(4,77,9,18,0);
     marco(4,77,9,18,14);
     gotoxy(9,11);cprintf("NOMBRE DEL ALUMNO: %s",r->nom);
     gotoxy(9,12);cprintf("CODIGO: %s",r->cod);
     gotoxy(9,13);cprintf("CURSO: %s",r->cur);
     gotoxy(9,15);cprintf("NOTAS     1ra        2da        3ra        4ta        Promedio");
     gotoxy(19,16);cprintf("%.2f",r->nota1);
     gotoxy(30,16);cprintf("%.2f",r->nota2);
     gotoxy(41,16);cprintf("%.2f",r->nota3);
     gotoxy(52,16);cprintf("%.2f",r->nota4);
     gotoxy(63,16);cprintf("%.2f",r->prom);
     break;
    }
     r=r->der;
   }
   getche();
   if(sw==0)
   {  
    textcolor(14);

    gotoxy(20,21);cprintf("MATERIA INEXISTENTE !!");

   }
  }  
  do
  {
   textcolor(14);
   gotoxy(19,22);cprintf("DESEA CONSULTAR OTRA MATERIA [S/N]");
   op=toupper(getch());
  }while((op!='N')&&(op!='S'));
}while(op!='N');
}
/***************************************************************************/
/****************************  MODIFICAR **********************************/
/**************************************************************************/
void alumnos::modificar()
{
 nodo *p;
 char elim[10],mo[10];
 int i,sw,op;
 float n1,n2,n3,n4;
 clrscr();
 color(1,80,1,25,1);
 color(20,56,3,5,1);
 marco(20,57,3,5,14);
 gotoxy(28,4);cprintf("MODIFICAR INFORMACION");
 color(1,80,7,9,3);textcolor(4);
 gotoxy(20,8);cprintf("DIGITE EL CODIGO A MODIFICAR:  ");digit(elim,50,8);
 p=cab;
  i=0;
  sw=0;
  while(p!=NULL)
   {
    i++;
    p=p->der;
   }
  p=cab;
  if(i==0)
   {
     sw=1;
     gotoxy(20,15);cprintf("NO EXISTEN ALUMNOS PARA MODIFICAR");getch();
   }
  else
   {
     while(p!=NULL)
      {
     if(strcmp(p->cod,elim)==0)
      {
	sw=1;
	color(1,80,1,25,3);
	color(18,55,3,6,1);
	marco(18,55,3,6,14);
	gotoxy(20,4);cprintf("MODIFICANDO DATOS DEL ESTUDIANTE");
	color(15,62,9,20,1);
	marco(15,62,9,20,14);
	gotoxy(20,10);cprintf("1  CODIGO  %s",p->cod);
	gotoxy(20,11);cprintf("2. NOMBRE  %s",p->nom);
	gotoxy(20,12);cprintf("3. MATERIA  %s",p->mat);
	gotoxy(20,13);cprintf("4. CURSO  %s",p->cur);
	gotoxy(20,14);cprintf("5. NOTA 1  %1.2f",p->nota1);
	gotoxy(20,15);cprintf("6. NOTA 2  %1.2f",p->nota2);
	gotoxy(20,16);cprintf("7. NOTA 3  %1.2f",p->nota3);
	gotoxy(20,17);cprintf("8. NOTA 4  %1.2f",p->nota4);
	gotoxy(20,18);cprintf("9. Salir ");
	gotoxy(20,22);cprintf("DIGITE LA OPCION A MODIFICAR  ");
	scanf("%d",&op);
	switch(op)
	 {
	   case 1:digit(mo,21,10);strcpy(p->cod,mo);break;
	   case 2:caract(mo,21,11);strcpy(p->nom,mo);break;
	   case 3:caract(mo,21,12);strcpy(p->mat,mo);break;
	   case 4:digit(mo,21,13);strcpy(p->cur,mo);break;
	   case 5:gotoxy(21,14);scanf("%f",&n1);p->nota1=n1;p->prom=(p->nota1+p->nota2+p->nota3+p->nota4) / 4; break;
	   case 6:gotoxy(21,15);scanf("%f",&n2);p->nota2=n2;p->prom=(p->nota1+p->nota2+p->nota3+p->nota4) / 4; break;
	   case 7:gotoxy(21,16);scanf("%f",&n3);p->nota3=n3;p->prom=(p->nota1+p->nota2+p->nota3+p->nota4) / 4; break;
	   case 8:gotoxy(21,17);scanf("%f",&n4);p->nota4=n4;p->prom=(p->nota1+p->nota2+p->nota3+p->nota4) / 4; break;
	   case 9:break;
	 }
	
	if(op!=9)
	{
	 gotoxy(20,19);cprintf("LA INFORMACION HA SIDO MODIFICADA");getch(); }
	}
        p=p->der;
      }
    
   }
  if(sw==0)
   {
     gotoxy(20,10);cprintf("EL CODIGO A MODIFICAR NO EXISTE");getch();
   }
 }

/**************************************************************************/
/*************************  ELIMINAR ESTUDIANTE ***************************/
/**************************************************************************/
void alumnos::elim()
{
  nodo *b,*d,*a,*c;
  int sw;
  char elim[10];
  clrscr();
  sw=0;
  clrscr();
  color(1,80,1,25,1);
  color(20,56,3,5,1);
  marco(20,57,3,5,14);
  gotoxy(28,4);cprintf("ELIMINAR ESTUDIANTES");
  color(1,80,8,11,3);
  gotoxy(20,9);cprintf("DIGITE EL CODIGO A ELIMINAR:");digit(elim,48,9);
  b=cab;
  while(b!=NULL)
   {
     d=b;
     a=d->izd;
     c=d->der;
     if(strcmp(d->cod,elim)==0)
      {
	sw=1;
	if(d->izd==NULL)
	 {
	   c->izd=NULL;
	   cab=c;
	 }
	else
	 {
	   a->der=c;
	 }
	c->izd=a;
	free(d);
	color(1,80,1,25,8);
	color(20,60,8,15,3);
	color(20,60,8,9,7);
	gotoxy(30,8);textbackground(7);textcolor(4);cprintf("Eliminando Estudiante");
	eliminando(23,53,12,9,14);
	delay(150);
      }
    b=b->der;
    }
  if(sw==0)
   {
     gotoxy(20,10);cprintf("EL CODIGO A ELIMINAR NO EXISTE");getch();
   }
}
/***************************************************************************/
/*************************  ORDENAR  **************************************/
/**************************************************************************/
void alumnos::ordenar()
{
    nodo *b;
  int pf,i,j,k,l;
  char ord[25][25],elem[25];
  clrscr();
  color(1,80,1,25,1);
  color(25,60,4,6,1);
  marco(25,60,4,6,14);
  gotoxy(28,5);cprintf("ORDENAR LISTA DE ESTUDIANTES");
  color(3,78,8,20,0);
  marco(3,78,8,20,14);
  i=0;l=0;
  b=cab;
  pf=11;
  while(b->der!=NULL)
   {
    l++;
    b=b->der;
   }
  b=cab;
  if(l==0)
   {
     gotoxy(20,10);cprintf("NO EXISTEN ALUMNOS PARA ORDENAR POR CODIGO");
   }
  else
  {
  while(b!=NULL)
   {
     i++;
     strcpy(ord[i],b->cod);
     b=b->der;
   }

  for(j=2; j<=i; j++)
   {
   for(k=i; k>=j; k--)
   {
     if(strcmp(ord[k-1],ord[k])>0)
      {
	strcpy(elem,ord[k-1]);
	strcpy(ord[k-1],ord[k]);
	strcpy(ord[k],elem);
      }
   }
  }
 for(j=1; j<=i; j++)
   {
     b=cab;
     while(b!=NULL)
      {
	if(strcmp(ord[j],b->cod)==0)
	 {
	gotoxy(5,9);cprintf("                                N O T A S");
	gotoxy(5,10);cprintf("COD      NOM       CURSO      MATERIA      1ra   2da   3ra   4ta   PROM");
	gotoxy(5,pf);cprintf("%s",b->cod);
	gotoxy(14,pf);cprintf("%s",b->nom);
	gotoxy(24,pf);cprintf("%s",b->cur);gotoxy(35,pf);cprintf("%s",b->mat);
	gotoxy(48,pf);cprintf("%1.2f",b->nota1);gotoxy(54,pf);printf("%1.2f",b->nota2);
	gotoxy(60,pf);cprintf("%1.2f",b->nota3);gotoxy(66,pf);printf("%1.2f",b->nota4);
	gotoxy(72,pf);cprintf("%1.2f",b->prom);
	pf++;
      }
      b=b->der;
     }
   }
  }
 getch();
}
/**************************************************************************/
/******************************  VISUALIZAR  ******************************/
/**************************************************************************/
void alumnos::visualizar(nodo *b)
{
  
  int pf,i;
  clrscr();
  b=cab;
  i=0;
  pf=11;
  clrscr();
  color(1,80,1,25,1);
  color(20,56,3,5,1);
  marco(20,57,3,5,14);
  gotoxy(28,4);cprintf(" LISTADO DE  ESTUDIANTES");
  color(3,78,8,20,0);
  marco(3,78,8,20,14);
  while(b->der!=NULL)
  {
   i++;
   b=b->der;
  }
  b=cab;
  if(i==0)
  {
   gotoxy(20,10);cprintf("NO EXISTEN ALUMNOS PARA VISUALIZAR");
  }
  else
  {
   if(i!=0)
   {
   while(b!=NULL)
   {
    gotoxy(5,10);cprintf("COD      NOM       CURSO      MATERIA      1ra   2da   3ra   4ta   PROM");
    gotoxy(5,pf);cprintf("%s",b->cod);
    gotoxy(14,pf);cprintf("%s",b->nom);
    gotoxy(24,pf);cprintf("%s",b->cur);gotoxy(35,pf);cprintf("%s",b->mat);
    gotoxy(48,pf);cprintf("%1.2f",b->nota1);gotoxy(54,pf);printf("%1.2f",b->nota2);
    gotoxy(60,pf);cprintf("%1.2f",b->nota3);gotoxy(66,pf);printf("%1.2f",b->nota4);
    gotoxy(72,pf);cprintf("%1.2f",b->prom);
    pf++;
    b=b->der;
   }
  }
  }
  getch();
}
/***************************************************************************/
/************************  MENU PRINCIPAL  *********************************/
/***************************************************************************/
void alumnos::menu()
{
  int f,c,tecla,l;
  char opcion[21][75];
  f=10;
  c=30;
  su=0;
  strcpy(opcion[10],"ADICIONAR ALUMNOS...");
  strcpy(opcion[11],"CONSULTAR ALUMNOS...");
  strcpy(opcion[12],"ELIMINAR  ALUMNOS...");
  strcpy(opcion[13],"MODIFICAR DATOS ....");
  strcpy(opcion[14],"VISUALIZAR .........");
  strcpy(opcion[15],"ORDENAR ............");
  strcpy(opcion[16],"SALIR ..............");
  do
  {
   textcolor(14);textbackground(0);
   clrscr();
   color(1,80,1,25,1);
   color(20,56,4,5,0);
   marco(19,57,3,5,14);
   gotoxy(24,4);cprintf(" M E N U   P R I N C I P A L");
   color(23,54,8,19,0 );
   marco(23,54,7,19,14);
   for(l=10;l<=16;l=l+1)
   {
    gotoxy(c,l);cprintf("%s",opcion[l]);
   }
   textcolor(0);textbackground(7);
   gotoxy(c,f);cprintf("%s",opcion[f]);
   textcolor(14);textbackground(0);
   color(1,80,24,25,7);
   gotoxy(1,24);textcolor(4);cprintf("Adiciona Informacion de Estudiantes .");
   do
   {
    do
    {
     tecla=getch();
    }while((tecla==80)&&(tecla==72)&&(tecla==13));
    if(tecla==80)
    {
     textcolor(14);textbackground(0);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     if(f!=16)
     {
      f=f+1;
      textcolor(0);textbackground(7);
      gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(14);textbackground(0);
		 if(f==11)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Consultas Promedio de notas, Materia y Curso de Estudiantes.");
		  }
		 if(f==13)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Modificar Datos.");
		  }
		 if(f==12)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Eliminaci¢n De Estudiantes.");
		  }
		 if(f==15)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Lista De Estudiantes Ordenada Por Codigo.");
		  }
		if(f==14)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Lista De Estudiantes Por Codigo y Nombre.");
		  }

		 if(f==16)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Salir del Programa.");
		  }
	       }
	       else
	       {
		 f=10;
		 color(1,80,24,25,7);textcolor(4);
		 gotoxy(1,24);textcolor(4);cprintf("Adiciona Estudiantes Con Sus Notas.");
		 textcolor(0);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(14);textbackground(0);
		}
	    }
	    if(tecla==72)
	    {
	      textcolor(14);textbackground(0);
	      gotoxy(c,f);cprintf("%s",opcion[f]);
	      if(f!=10)
	       {
		 f=f-1;
		 textcolor(0);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(14);textbackground(0);
		if(f==10)
		  {
		    color(1,80,24,25,7);textcolor(4);
			 gotoxy(1,24);textcolor(4);cprintf("Adiciona Estudiantes Con Sus Notas.");
		  }
		if(f==11)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Consultas Promedio de notas,Materia y Curso del Estudiante.");
		  }
		 if(f==13)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Modificaci¢n De Informacion.");
		  }

		 if(f==12)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Eliminaci¢n De Estudiantes.");
		  }
		 if(f==15)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Lista De Estudiantes Ordenada Por Codigo.");
		  }
		if(f==14)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Lista De Estudiantes Por Codigo y Nombre.");
		  }

		 if(f==16)
		  {
		    color(1,80,24,25,7);textcolor(4);
		    gotoxy(1,24);clreol();cprintf("Salir Al Entorno Dos.");
		  }

	       }
	       else
	       {
		 f=16;
		  color(1,80,24,25,7);textcolor(4);
		 gotoxy(1,24);clreol();cprintf("Salir del Programa.");
		 textcolor(0);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(14);textbackground(0);
		}
	    }
       }while(tecla!=13);
       switch(f)
       {
	 case 10:a_alumnos();break;
	 case 11:consulta();break;
	 case 13:modificar();break;
	 case 12:elim();break;
	 case 15:ordenar();break;
	 case 14:visualizar(cab);break;
	}
   }while(f!=16);
}

void main()
{
 clrscr();
 alumnos obj(NULL);
 obj.menu();
}