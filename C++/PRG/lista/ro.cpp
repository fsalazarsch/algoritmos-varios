#include<io.h>
#include<dos.h>
#include<math.h>
#include<stdio.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#define color(x,y)textcolor(x);textbackground(y)
/**********************************************************************/
class lis_dobl
{
 struct nodo
 {
  char nombre[45];
  char codigo[5];
  float valor;
  int cantidad;
  struct nodo*ant;
  struct nodo*sig;
 };struct nodo *p,*q,*r,*ptr,*nn;

 struct 
 {
  unsigned char  ti_min;
  unsigned char  ti_hour;
  unsigned char  ti_hund;
  unsigned char  ti_sec;
}t;

  public:
	lis_dobl(struct nodo *a){ptr=a;}
	void adicionar_nodo();
	void eliminar_nodo(); 
	void recorer_lista();
        void recorer_lista1();
	void consultar_codigo();
	void menu();
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * *   CUADRO    * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void cuadro(int ci,int cf,int fi,int ff)
{
 int i;
 for(i=ci;i<=cf;i++)
 {
  gotoxy(i,fi); cout<<"Э";  /** ALT 205 **/
  gotoxy(i,ff); cout<<"Э";
 }
 for(i=fi;i<=ff;i++)
 {
  gotoxy(ci,i); cout<<"К"; /** ALT 186 **/ 
  gotoxy(cf,i); cout<<"К";
 }
 gotoxy(ci,fi); cout<<"Щ";  /** ALT 201 **/
 gotoxy(ci,ff); cout<<"Ш";  /** ALT 200 **/
 gotoxy(cf,fi); cout<<"Л";  /** ALT 187 **/
 gotoxy(cf,ff); cout<<"М";  /** ALT 188 **/
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * *  RELLENAR  PANTALLA   * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void pantalla(int x1,int x2,int y1, int y2)
{
 int i,j;
 cuadro(1,80,2,24);
 for(i=3;i<=78;i++)
 {
  for(j=3;j<=22;j++)
  {
   if((i<x1 || i>x2) || (j<y1 || j>y2))
   {
    gotoxy(i,j);putchar('А');  /** ALT 176 **/
   }
  }
 }                
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * *  RELLENAR  CUADROS  * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void rellenar()
{
 int x,y;
 for(x=1;x<81;x++)
 {
  gotoxy(x,y);cout<<"В"; /** ALT 176 **/
  for(y=1;y<24;y++)
  { 
   gotoxy(x,y);cout<<"В"; 
  } 
 } 
} 
/*************************************************************************/
main()
{
 char op;
 clrscr();
 int cont;
 textcolor(15);
 textbackground(1);
 clrscr();
 textbackground(1);
 //cont=0;
 clrscr();
 lis_dobl obj(NULL);
 obj.menu();                              
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * *    MENU   PRINCIPAL   * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lis_dobl::menu()
{
 clrscr();
 ptr=NULL;
 ptr->sig=NULL;
 ptr->ant=NULL;
 int i;
 char op,SALIR,tecla;
 do
 {
  clrscr();
  window(1,1,80,25);
  textbackground(128);
  textcolor(1);
  clrscr();
  for(i=1;i<=25;i++)
  {
   textcolor(15);
   gotoxy(1,i);
   cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
  } 
  window(1,1,80,25);
  rellenar();
  textcolor(15);
  textbackground(0);
  window(4,3,79,5);
  clrscr();
  textbackground(CYAN);textcolor(0);
  window(2,2,77,4);
  textcolor(0);
  clrscr();
  gotoxy(24,2);cout<<"M E N U     P R I N C I P A L";
  textbackground(0);
  window(4,22,79,24);
  clrscr();
  textbackground(CYAN);
  window(2,21,77,23);
  clrscr();
  char t1=24,t2=25;
  gotoxy(12,2);cout<<"UTILICE LAS TECLAS DEL CURSOR "<<t1<<t2<<" Y PRESIONE Ў ENTER Џ ";  
  textbackground(0);                                
  window(24,9,59,18);
  clrscr();
  textbackground(CYAN);
  window(22,8,57,17);
  clrscr();
  gotoxy(4,3);cout<<"1. ADICIONAR UN NODO..";
  gotoxy(4,4);cout<<"2. ELIMINAR UN NODO.. ";
  gotoxy(4,5);cout<<"3. REC. LISTA -->-->..";
  gotoxy(4,6);cout<<"4. REC. LISTA <--<--..";
  gotoxy(4,7);cout<<"5. CONSULTAR..";
  gotoxy(4,8);cout<<"6. SALIR DEL PROGRAMA..";
  textcolor(15);
  char c=127;
  gotoxy(2,3);cout<<c;
  gotoxy(2,3);
  do
  {
   char c=127; 
   tecla=getch();
   if(tecla==72)  /**  TECLA QUE SUBE  **/
   {
    cout<<"  ";
    if(wherey()==3)
    {
     gotoxy(2,wherey()+5);
     cout<<c;
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()-1);printf("%c",127);
     gotoxy(2,wherey());
    }
   }
   if(tecla==80)  /** TECLA QUE BAJA **/
   {
    cout<<"  ";
    if(wherey()==8)
    {
     gotoxy(2,wherey()-5);printf("%c",127);
     gotoxy(2,wherey());
    }
    else
    {
     gotoxy(2,wherey()+1);
     cout<<c;
     gotoxy(2,wherey());
    }
   }
  } while(tecla!=13);
  op=wherey();
  if(op==8)
  {
   SALIR='S';
  }
  else
  {
   switch(op)
   {
    case 3:adicionar_nodo();break;
    case 4:eliminar_nodo();break;
    case 5:recorer_lista();break;
    case 6:recorer_lista1();break;
    case 7:consultar_codigo();break; 
    case 8:exit(0);break;
   }
  }
 } while(SALIR!='S');
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * *   ADICIONAR   NODO  * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */   
void lis_dobl::adicionar_nodo()
{
 char nombre[45];
 char codigo[5],auxcod[5]; 
 char tecla,op;
 float valor;
 int cantidad;
 
 int i,j,lon,sw,n;
 char valido,ced[20];

 clrscr();
 window(1,1,80,25);
 textbackground(128);
 textcolor(1);
 clrscr();
 for(i=1;i<=25;i++)
 {
  textcolor(15);
  gotoxy(1,i);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
 } 
 window(1,1,80,25);
 rellenar();
 textcolor(15);
 gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
 textbackground(0);
 window(35,7,53,9);
 textcolor(0);
 clrscr();
 textbackground(3);
 window(34,6,51,8);
 textcolor(0);
 clrscr();
 gotoxy(2,2);textcolor(0);
 gotoxy(4,4);cout<<"   ADICIONAR";
 textbackground(0);
 window(20,12,67,20);
 clrscr();
 textcolor(0);
 textbackground(3);
 window(19,11,65,19);
 clrscr();
 textcolor(0);
 n=0;
 do
 {
  clrscr();
  textcolor(0);
  gotoxy(37,5);cout<<"        ";
  valido='n';
  gotoxy(4,5);cout<<"INTRODUZCA CANTIDAD DE ELEMENTOS: ",n;
  gotoxy(37,5);scanf("%d",&n);gets(ced);
  lon = strlen(ced);
  for(j=0;j<=lon-1;j++)
  {
   if(!(isdigit(ced[j])))
   {
    valido='m';
    break;
   }
  }
  if(sw==1)
  {
   valido='m';
  }
 }while(valido=='m');
 for(i=0;i<n;i++)
 {
 do
 {
  clrscr();
  textbackground(0);
  textcolor(0);
  window(20,13,67,20);
  textcolor(0);
  textbackground(3);
  window(19,11,65,19);
  textcolor(0);
  valido='n';
  nn=new nodo;
  gotoxy(34,2);cout<<"           ";
  do
  {
   valido='n';
   gotoxy(3,2);cprintf("INTRODUZCA CODIGO DEL ARTICULO: ");
   gotoxy(34,2);gets(codigo);
   lon = strlen(codigo);
   if(lon==0)
   {
     valido='m';
     break;
   }
   if(lon>5)
   {
    clrscr();
    gotoxy(4,5);cout<<" .. SOBREPASA EL RANGO DE 5 CARACTERES ..";
    getche();
    valido='m';
    gotoxy(4,5);cout<<"                                         ";
    break;
   }
  }while(valido=='m');
  for(j=0;j<=lon-1;j++)
  {
   if(!(isdigit(codigo[j]))&&!(isalpha(codigo[j])))
   {
    valido='m';
    break;
   }
   else
   {
    p=ptr;
    while(p->sig!=ptr)
    {
     if(strcmp(p->codigo,codigo)==0)
     {
      clrscr();
      gotoxy(7,5);cout<<".. ESTE CODIGO YA EXISTE ..";
      valido='m';
      getch();
      gotoxy(7,5);cout<<"                           ";
      break;
     }
     p=p->sig;
    }
   }
  }
 }while(valido=='m');
 do
  {
   valido='n'; 
   nn=new nodo; 
   gotoxy(34,3);cout<<"              ";
   gotoxy(3,3);cprintf("INTRODUZCA NOMBRE DEL ARTICULO: ");
   gotoxy(34,3);gets(nombre);
   lon = strlen(nombre);
   if(lon==0)
   {
    valido='m';
    break;
   }
   if (lon>45)
   {
    clrscr();
    gotoxy(4,5);cout<<" .. SOBREPASA EL RANGO DE 45 CARACTERES ..";
    gotoxy(4,5);cout<<"                                          ";
    getche();
    valido='m';
    break;
   }
   for(j=0;j<=lon-1; j++)
   {
    if(!(isalpha(nombre[j])))
    {
     valido='m';
     textcolor(0);textbackground(3);
     textcolor(0);textbackground(3);
     break;
     textcolor(0);textbackground(3);
    }
    textcolor(0);textbackground(3);
   }
  }while(valido=='m');
  do 
  {
  valido='n';
  do
  {
   gotoxy(29,4);cout<<"                   ";
   valido='n';
   gotoxy(3,4);cprintf("DIGITE VALOR DEL ARTICULO:",n);
   gotoxy(29,4);scanf("%f",&valor);gets(ced);
   if ((valor<=0)||(valor>999999999))
    {
     gotoxy(4,7);cout<<" .. SOBREPASA EL RANGO DE 10 NUMEROS ..";
     getche();
     valido='m';
     gotoxy(4,7);cout<<"                                        ";
     break;                                                        
    }
  }while(valido=='m');
  lon = strlen(ced);
   for(j=0;j<=lon-1; j++)
   {
    if(!(isdigit(ced[j]))&&(!('.')))
    {
     valido='m';
     break;
    }
   } 
   if(sw==1)
   {
    valido='m';
    break;
   }
  }while(valido=='m');
  do
  {
   valido='n';
   do
   {
    gotoxy(32,5);cout<<"               ";
    valido='n';
    gotoxy(3,5);cprintf("DIGITE CANTIDAD DE ARTICULOS:");
    gotoxy(32,5);scanf("%d",&cantidad);gets(ced);
    if ((cantidad<=0)||(cantidad>9999))
    {
     gotoxy(4,7);cout<<" .. SOBREPASA EL RANGO DE 5 NUMEROS ..";
     getche();
     valido='m';
     gotoxy(4,7);cout<<"                                        ";
     break;                                                        
    }
   }while(valido=='m');
   lon = strlen(ced);
   for(j=0;j<=lon-1; j++)
   {
    if(!(isdigit(ced[j])))
    {
     valido='m';
     break;
    }
   }
   if(sw==1)
   {
    valido='m';
    break;
   }
   textcolor(0);textbackground(11);
  }while(valido=='m');
  strcpy(nn->nombre,nombre);
  strcpy(nn->codigo,codigo);
  nn->valor=valor;
  nn->cantidad=cantidad;
  nn->sig=NULL;
  nn->ant=NULL;
  if (ptr==NULL)
  {
   ptr=nn;
   ptr->sig=nn;
   ptr->ant=nn;
  }
  else
  {
   p=ptr;
   while(p->sig!=ptr)
   {
    p=p->sig;
   }
   p->sig=nn;
   nn->sig=ptr;        /* para que sea circular *->    y  <-*  */
   ptr->ant=nn;
   nn->ant=p;
  }
 }
 }
 
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * *   ELIMINAR  NODO  * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */   
void lis_dobl::eliminar_nodo() 
{
 int i,j;
 char valido,op,sw,codigo[10];
 long int lon;
 char nombre[45];
 char dato[45];
 char dependencia;
 char de;
 float valor;
 int cantidad;
 int n;
 clrscr();
 window(1,1,80,25);
 textbackground(128);
 textcolor(1);
 clrscr();
 for(i=1;i<=25;i++)
 {
  textcolor(15);
  gotoxy(1,i);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
 } 
 gotoxy(15,25);textcolor(15);
 window(1,1,80,25);
 rellenar();
 textcolor(15);
 gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
 textbackground(0);
 window(35,7,53,9);
 clrscr();
 textbackground(11);
 window(34,6,51,8);clrscr();
 textcolor(0);
 gotoxy(5,2);cprintf("ELIMINAR");
 textbackground(0);
 window(26,12,59,19);
 clrscr();
 textcolor(0);
 textbackground(11);
 window(25,11,57,18);
 clrscr();
 textcolor(0);
 if (ptr==NULL)
 {
  textcolor(0);
  gotoxy(2,4);cprintf("Ў LA LISTA SE ENCUENTRA VACIA Џ");
  getche();
  return;
 }

  do
  {
   clrscr();
   window(1,1,80,25);
   textbackground(128);
   textcolor(1);
   clrscr();
   for(i=1;i<=25;i++)
   {
    textcolor(15);
    gotoxy(1,i);
    cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
   }
   gotoxy(15,25);textcolor(15); 
   window(1,1,80,25);
   rellenar();
   textcolor(15);                                       
   gotoxy(25,25);cprintf("PRESIONE ЎЎ ENTER ЏЏ PARA CONTINUAR ");  
   textbackground(0);
   window(35,7,53,9);
   textcolor(0);
   clrscr();
   textbackground(3);
   window(34,6,51,8);
   textcolor(0);
   clrscr();
   gotoxy(2,2);textcolor(0);
   gotoxy(4,4);cout<<"   CONSULTAR";
   textbackground(0);
   window(21,11,66,21);
   clrscr();
   textcolor(0);
   textbackground(3);
   window(20,10,65,20);
   clrscr();
   do
   {
    clrscr();
    valido='n';
    gotoxy(3,2);cprintf("INTRODUZCA CODIGO DEL ARTICULO: ");
    gotoxy(34,2);scanf("\n");gets(codigo);
    lon = strlen(codigo);
    if(lon>5)
    {
     clrscr();
     gotoxy(4,5);cout<<" .. SOBREPASA EL RANGO DE 5 CARACTERES ..";
     getche();
     valido='m';
     gotoxy(4,5);cout<<"                                         ";
     break;
    }
   }while(valido=='m');
   for(j=0;j<=lon-1;j++)
   {
    if(!(isdigit(codigo[j]))&&!(isalpha(codigo[j])))
     {
      valido='m';
      break;
     }
    }
   p=ptr;
   do
   {
    if(strcmp(p->codigo,codigo)==0)
    {
     clrscr();
     window(1,1,80,25);
     textbackground(128);
     textcolor(1);
     clrscr();
     for(i=1;i<=25;i++)
     {
      textcolor(15);
      gotoxy(1,i);
      cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
     }
     gotoxy(15,25);textcolor(15); 
     window(1,1,80,25);
     rellenar();
     textcolor(15);
     gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
     textbackground(0);
     window(29,7,55,9);
     textcolor(0);
     clrscr();
     textbackground(3);
     window(28,6,54,8);
     textcolor(0);
     clrscr();
     gotoxy(2,2);textcolor(0);
     gotoxy(5,4);cout<<"   CONSULTA POR CODIGO";
     textbackground(0);
     window(26,12,59,19);
     clrscr();
     textcolor(0);
     textbackground(3);
     window(25,11,57,18);
     clrscr();
     textcolor(0);
     gotoxy(3,2);cout<<"CODIGO DEL ARTICULO:"<<p->codigo;
     gotoxy(3,3);cout<<"NOMBRE DEL ARTICULO:"<<p->nombre;
     gotoxy(3,4);cout<<"VALOR DEL ARTICULO:"<<p->valor;
     gotoxy(3,5);cout<<"CANTIDAD DEL ARTICULO:"<<p->cantidad;
     getche();
     q=p;
    } 
    
    p=p->sig;
   }while(p!=ptr); 
 if (q==NULL)
    {
     gotoxy(7,8);cout<<"CODIGO NO EXISTENTE";
     gotoxy(7,8);cout<<"                   ";
    //getche();
    }
 else
 {
  if((q->ant==q)&&(q->sig==q))
   {
    ptr=NULL;
    free(q);
   }
  else
   {
    q->ant->sig=q->sig;
    q->sig->ant=q->ant;
    if (q==ptr) ptr=q->sig;
    free(q);
   }
  textcolor(0);
  gotoxy(3,4);cprintf(" ... NODO ELIMINADO ... ");
  gotoxy(3,3);cprintf("                        ");
  gotoxy(3,2);cprintf("                        ");
  gotoxy(3,5);cprintf("                        ");
  gotoxy(3,6);cprintf("                        ");
  getche();
  }
   gotoxy(3,8);cout<<"DESEA ELIMINAR OTRO DATO (s/n): ";
   op=toupper(getch());
  }while(op!='N');
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * *   RECORRER   LISTA  * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */   
void lis_dobl::recorer_lista()
{  
 char nombre[45];
 char codigo[5];
 char dependencia;
 float valor;
 int cantidad;
 int i;
 int n;
 clrscr();
 window(1,1,80,25);
 textbackground(128);
 textcolor(1);
 clrscr();
 for(i=1;i<=25;i++)
 {
  textcolor(15);
  gotoxy(1,i);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
 } 
 window(1,1,80,25);
 rellenar();
 textcolor(15);
 gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
 textbackground(0);
 window(35,7,53,9);
 clrscr();
 textbackground(3);
 window(34,6,51,8);
 clrscr();
 textcolor(0);
 gotoxy(2,2);cprintf("RECORRER LISTA");
 textbackground(0);
 window(26,12,59,19);
 clrscr();
 textcolor(0);
 textbackground(3);
 window(25,11,57,18);
 clrscr();
 textcolor(0);
 if (ptr==NULL)
 {
  gotoxy(2,4);cprintf("Ў LA LISTA SE ENCUENTRA VACIA Џ");
  getche();
  return;
 }
 else
 {
  p=ptr;
  do
  {
   clrscr();
   gotoxy(3,2);cout<<"CODIGO DEL ARTICULO:"<<p->codigo;
   gotoxy(3,3);cout<<"NOMBRE DEL ARTICULO:"<<p->nombre;
   gotoxy(3,4);cout<<"VALOR DEL ARTICULO:"<<p->valor;
   gotoxy(3,5);cout<<"CANTIDAD DEL ARTICULO:"<<p->cantidad;
   q=p;
   p=p->sig;
   getche();
  }while(p!=ptr);
 }
} 

void lis_dobl::recorer_lista1()
{  
 char nombre[45];
 char codigo[5];
 char dependencia;
 float valor;
 int cantidad;
 int i;
 int n;
 clrscr();
 window(1,1,80,25);
 textbackground(128);
 textcolor(1);
 clrscr();
 for(i=1;i<=25;i++)
 {
  textcolor(15);
  gotoxy(1,i);
  cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
 } 
 window(1,1,80,25);
 rellenar();
 textcolor(15);
 gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
 textbackground(0);
 window(35,7,53,9);
 clrscr();
 textbackground(3);
 window(34,6,51,8);
 clrscr();
 textcolor(0);
 gotoxy(2,2);cprintf("RECORRER LISTA");
 textbackground(0);
 window(26,12,59,19);
 clrscr();
 textcolor(0);
 textbackground(3);
 window(25,11,57,18);
 clrscr();
 textcolor(0);
 if (ptr==NULL)
 {
  gotoxy(2,4);cprintf("Ў LA LISTA SE ENCUENTRA VACIA Џ");
  getche();
  return;
 }
 else
 {
  p=ptr;
  do
  {
   clrscr();
   gotoxy(3,2);cout<<"CODIGO DEL ARTICULO:"<<p->codigo;
   gotoxy(3,3);cout<<"NOMBRE DEL ARTICULO:"<<p->nombre;
   gotoxy(3,4);cout<<"VALOR DEL ARTICULO:"<<p->valor;
   gotoxy(3,5);cout<<"CANTIDAD DEL ARTICULO:"<<p->cantidad;
   q=p;
   p=p->ant;
   getche();
  }while(p!=ptr);
 }
} 


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void lis_dobl::consultar_codigo()
{
 int i,j;
 char valido,op,sw,codigo[10];
 long int lon;
 p=ptr;
 if(ptr==NULL)
 {
  clrscr();
  window(1,1,80,25);
  textbackground(128);
  textcolor(1);
  clrscr();
  for(i=1;i<=25;i++)
  {
   textcolor(15);
   gotoxy(1,i);
   cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
  }
  gotoxy(15,25);textcolor(15); 
  window(1,1,80,25);
  rellenar();
  textcolor(15);                                       
  gotoxy(25,25);cprintf("PRESIONE ЎЎ ENTER ЏЏ PARA CONTINUAR ");  
  textbackground(0);
  window(35,7,53,9);
  textcolor(0);
  clrscr();
  textbackground(3);
  window(34,6,51,8);
  textcolor(0);
  clrscr();
  gotoxy(2,2);textcolor(0);
  gotoxy(4,4);cout<<"   CONSULTAR";
  textbackground(0);
  window(21,12,66,19);
  clrscr();
  textcolor(0);
  textbackground(3);
  window(20,11,65,18);
  clrscr();
  gotoxy(1,5);textcolor(0);
  gotoxy(1,5);cout<<" ..NO EXISTE INFORMACION EN LA LISTA..";
  getche();
 }
 else
 {
  do
  {
   clrscr();
   window(1,1,80,25);
   textbackground(128);
   textcolor(1);
   clrscr();
   for(i=1;i<=25;i++)
   {
    textcolor(15);
    gotoxy(1,i);
    cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
   }
   gotoxy(15,25);textcolor(15); 
   window(1,1,80,25);
   rellenar();
   textcolor(15);                                       
   gotoxy(25,25);cprintf("PRESIONE ЎЎ ENTER ЏЏ PARA CONTINUAR ");  
   textbackground(0);
   window(35,7,53,9);
   textcolor(0);
   clrscr();
   textbackground(3);
   window(34,6,51,8);
   textcolor(0);
   clrscr();
   gotoxy(2,2);textcolor(0);
   gotoxy(4,4);cout<<"   CONSULTAR";
   textbackground(0);
   window(21,11,66,21);
   clrscr();
   textcolor(0);
   textbackground(3);
   window(20,10,65,20);
   clrscr();
   do
   {
    clrscr();
    valido='n';
    gotoxy(3,2);cprintf("INTRODUZCA CODIGO DEL ARTICULO: ");
    gotoxy(34,2);scanf("\n");gets(codigo);
    lon = strlen(codigo);
    if(lon>5)
    {
     clrscr();
     gotoxy(4,5);cout<<" .. SOBREPASA EL RANGO DE 5 CARACTERES ..";
     getche();
     valido='m';
     gotoxy(4,5);cout<<"                                         ";
     break;
    }
   }while(valido=='m');
   for(j=0;j<=lon-1;j++)
   {
    if(!(isdigit(codigo[j]))&&!(isalpha(codigo[j])))
     {
      valido='m';
      break;
     }
    }
   p=ptr;
   do
   {
    if(strcmp(p->codigo,codigo)==0)
    {
     clrscr();
     window(1,1,80,25);
     textbackground(128);
     textcolor(1);
     clrscr();
     for(i=1;i<=25;i++)
     {
      textcolor(15);
      gotoxy(1,i);
      cout<<"лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл";
     }
     gotoxy(15,25);textcolor(15); 
     window(1,1,80,25);
     rellenar();
     textcolor(15);
     gotoxy(23,25);cprintf("PRESIONE Ў ENTER Џ PARA CONTINUAR");  
     textbackground(0);
     window(29,7,55,9);
     textcolor(0);
     clrscr();
     textbackground(3);
     window(28,6,54,8);
     textcolor(0);
     clrscr();
     gotoxy(2,2);textcolor(0);
     gotoxy(5,4);cout<<"   CONSULTA POR CODIGO";
     textbackground(0);
     window(26,12,59,19);
     clrscr();
     textcolor(0);
     textbackground(3);
     window(25,11,57,18);
     clrscr();
     textcolor(0);
     gotoxy(3,2);cout<<"CODIGO DEL ARTICULO:"<<p->codigo;
     gotoxy(3,3);cout<<"NOMBRE DEL ARTICULO:"<<p->nombre;
     gotoxy(3,4);cout<<"VALOR DEL ARTICULO:"<<p->valor;
     gotoxy(3,5);cout<<"CANTIDAD DEL ARTICULO:"<<p->cantidad;
     getche();
    } 
    
    p=p->sig;
    if (p==NULL)
    {
     gotoxy(7,8);cout<<"CODIGO NO EXISTENTE";
     gotoxy(7,8);cout<<"                   ";
    //getche();
    }
   }while(p!=ptr); 
   
   gotoxy(3,8);cout<<"DESEA CONSULTAR OTRO DATO (s/n): ";
   op=toupper(getch());
  }while(op!='N'); 
 }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */	  
