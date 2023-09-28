#include <conio.h>
#include <stdio.h>
#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <string.h>
/********************************************************/
class cajero
{
 struct nodou
 {
  char cedula[9];
  char nom[20];
  char ape[20];   
  char ope[2];
  char valor[15];
  struct nodou *sig_u;
  struct nodou *ant_u;
 }nodo_u;
 struct nodoc
 {
  char nocaj[2];
  char cedula[9];
  char nom[20];
  char ape[20];   
  char edad[3];
  char sex[2];
  struct nodoc *sig_c;
  struct nodou *ent_u;
 }nodo_c;
public:
struct nodoc *ptr;
struct nodoc *p;
struct nodoc *q;
struct nodou *ptr2;
struct nodou *p2;
struct nodou *q2;
struct nodoc *nn;
struct nodou *nn2;
       void ini();
       void cuadro(int y1,int x1,int y2,int x2);
       int exi_c(char no_caj[]);
       void relleno(int a,int b,int c,int d);
       void relleno2(int a,int b,int c);
       void relleno3(int a,int b,int c);
       void cuadro2(int c1,int f1,int c2,int f2);
       void adi_c();
       void modificar();
       void captura(char a[],int t,int x,int y,int sw);
       void eliminacion(); 
       void adi_u();
       void mod_u();
       void elim_u();
};
/********************************************************/
/* void cajero::con_a_s()
 {
   int i,j;
   char op,op2,op3;
   clrscr();
   gotoxy(15,5);printf("É");
   gotoxy(2,6);printf("É");
   gotoxy(79,x6);printf("»");
   gotoxy(2,x2);printf("È");
   gotoxy(79,x2);printf("¼");
   gotoxy(y1,x1+3);printf("Ì"); 
   gotoxy(y2,x1+3);printf("¹");
    for(i=+1;i<x2;){
     gotoxy(2,i);printf("º");
     gotoxy(15,i);printf("º");i++;}
    for(j=y1+1;j<y2;){
     gotoxy(j,3);printf("Í");
     gotoxy(j,x1);printf("Í");
     gotoxy(j,x2);printf("Í");j++;}
}*/
/****************************************************/
void cajero::mod_u()
{
  char caja[2],c[9],n[21],a[21],o[2],v[15];
  int sw,sw2;
  char op,op2;
  do{
  sw2=0;
  relleno2(28,60,23);      														
  cuadro2(16,10,64,22);
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  captura(caja,2,36,11,1);
  sw=exi_c(caja);
  if(sw==0){
   gotoxy(33,15);printf("<ERROR> Caja no existe..");delay(500);
   relleno3(33,57,13);relleno3(36,60,11);gotoxy(36,11);}
  if((p->ent_u==NULL)&&(sw==1)){
    gotoxy(33,15);printf("No existe <COLA>..");delay(500);
    relleno3(33,63,15);relleno3(36,60,13);gotoxy(36,11);}
   if((sw==1)&&(p->ent_u!=NULL)){
       gotoxy(18,13);printf("þ_CEDULA..    >> [                          ]");
       captura(c,9,36,13,1);
       p2=ptr2;
       while(p2!=NULL){
        if(strcmp(p2->cedula,c)==0){
         sw2=1;
         break;}
        p2=p2->sig_u;}
       if(sw2==0){
         gotoxy(33,15);printf("<ERROR> C‚dula no existe..");delay(500);
         relleno3(33,59,15);relleno3(36,60,13);gotoxy(36,11);}
       if(sw2==1){
          gotoxy(18,15);printf("þ_NOMBRE..    >> [                          ]");
          gotoxy(18,17);printf("þ_APELLIDO..  >> [                          ]");
          gotoxy(18,19);printf("þ_OPERACION.. >> [                          ]");
          gotoxy(18,21);printf("þ_VALOR..     >> [                          ]");
          gotoxy(36,15);cout<< p2->nom;
          gotoxy(36,17);cout<< p2->ape;
          gotoxy(36,19);cout<< p2->ope;
          gotoxy(36,21);cout<<p2->valor;
          relleno3(30,60,23);
          gotoxy(30,23);printf("DESEA MODIFICAR [S][N]>>[ ]");
          gotoxy(55,23);op2=toupper(getch());
          if(op2=='S'){
            relleno3(36,60,15);captura(n,21,36,15,0);
            relleno3(36,60,17);captura(a,21,36,17,0);
            relleno3(36,60,19);captura(o,2,36,19,2);
            relleno3(36,60,21);captura(v,15,36,21,1);
            strcpy(p2->nom,n);
            strcpy(p2->ape,a);
            strcpy(p2->ope,o);
            strcpy(p2->valor,v);}
	  
        }
     }	   
  gotoxy(30,23);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,23);op=toupper(getch());
 }while(op!='N');
}

/*****************************************/
void cajero::adi_u()
{
  int sw;
  char op;
  do{
  relleno2(28,60,23);      														
  cuadro2(16,10,64,22);
  char caja[3],c[9],n[21],a[21],o[2],v[15];
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  captura(caja,3,36,11,1);
  sw=exi_c(caja);
  if(sw==0){
   gotoxy(33,15);printf("<ERROR> Caja no existe..");delay(500);
   relleno3(33,57,13);relleno3(36,60,11);gotoxy(36,11);}
   if(sw==1){
   gotoxy(18,13);printf("þ_CEDULA..    >> [                          ]");
   gotoxy(18,15);printf("þ_NOMBRE..    >> [                          ]");
   gotoxy(18,17);printf("þ_APELLIDO..  >> [                          ]");
   gotoxy(18,19);printf("þ_OPERACION.. >> [                          ]");
   gotoxy(18,21);printf("þ_VALOR..     >> [                          ]");
   captura(c,9,36,13,1);
   captura(n,21,36,15,0);
   captura(a,21,36,17,0);
   captura(o,2,36,19,3);
   captura(v,15,36,21,1);   
   nn2=new nodou;
   strcpy(nn2->cedula,c);
   strcpy(nn2->nom,n);
   strcpy(nn2->ape,a);
   strcpy(nn2->ope,o);
   strcpy(nn2->valor,v);
   nn2->sig_u=NULL;
   nn2->ant_u=NULL;
 if(p->ent_u==NULL){
  p->ent_u=nn2;
  ptr2=nn2;}
  else{
   p2=ptr2;
   while(p2!=NULL){
    q2=p2;
    p2=p2->sig_u;}
    nn2->ant_u=q2;
    q2->sig_u=nn2;
   }
 }
  gotoxy(30,23);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,23);op=toupper(getch());
 }while(op!='N');
}   
/************************************/
void cajero::elim_u()
{
  int sw,sw2;
  char op,op2;
  do{
  sw=0;
  sw2=0;
  cuadro2(16,10,64,22);
  char caja[3],c[9],n[21],a[21],o[2],v[15];
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  captura(caja,2,36,11,1);
  sw=exi_c(caja);
  if(sw==0){
   gotoxy(33,15);printf("<ERROR> Caja no existe..");delay(500);
   relleno3(33,57,13);relleno3(36,60,11);gotoxy(36,11);}
  if(p->ent_u==NULL){
   gotoxy(33,15);printf("COLA No existe..");delay(500);
   relleno3(33,57,13);relleno3(36,60,11);gotoxy(36,11);}
   if((sw==1)&&(p->ent_u!=NULL)){
     gotoxy(18,13);printf("þ_CEDULA..    >> [                          ]");
     captura(c,1,36,13,1);
      if(strcmp(ptr2->cedula,c)==0){
        sw2=1;}
       if(sw2==0){
         gotoxy(25,15);printf("<ERROR> Imposible eli..");delay(800);
         relleno3(25,57,15);relleno3(36,60,11);relleno3(18,60,13);gotoxy(36,11);}
       if(sw2==1){
         gotoxy(18,15);printf("þ_NOMBRE..    >> [                          ]");
         gotoxy(18,17);printf("þ_APELLIDO..  >> [                          ]");
         gotoxy(18,19);printf("þ_OPERACION.. >> [                          ]");
         gotoxy(18,21);printf("þ_VALOR..     >> [                          ]");
         gotoxy(36,15);cout<< ptr2->nom;
         gotoxy(36,17);cout<< ptr2->ape;
         gotoxy(36,19);cout<< ptr2->ope;
         gotoxy(36,21);cout<<ptr2->valor;
         gotoxy(30,23);printf("DESEA ELIMINAR [S][N]>>[ ]");
         gotoxy(55,23);op2=toupper(getch());
         if(op2=='S'){
           relleno2(28,60,23);
           cuadro2(16,10,64,22);
           p2=ptr2;
           ptr2=ptr2->sig_u;
           ptr2->ant_u=NULL;
           free(p2);}
        } 
       }
  gotoxy(30,15);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,15);op=toupper(getch());relleno2(28,60,23);
 }while(op!='N'); 
}

/**********************************************************/
void cajero::captura(char a[],int t,int y,int x,int sw)
{
int c;
int n_caracteres,aux;
  aux=y;
  n_caracteres=0;
  do{
   do{
     gotoxy(y,x);
     c=toupper(getche());y++;
    if(c==8){
      if(y-1>aux){
      gotoxy(y--,x);cprintf(" ");;
      gotoxy(y,x);
      n_caracteres--;}}
    if(c==13){
     if((c==13)&&(n_caracteres==0)){
       gotoxy(y,x);cprintf(" ");
       }
     if((c==13)&&(n_caracteres!=0)){
       a[n_caracteres]='\0';return;}}
   if(sw==1){
    if((c>48)&&(c<=57)){
       a[n_caracteres]=c;
       n_caracteres++;}
    else{ 
       gotoxy(y-1,x);cprintf(" ");y--;
       gotoxy(y,x);}}      
   if(sw==3){
    if((c=='P')||(c=='R')||(c=='C')){
      a[n_caracteres]=c;
      n_caracteres++;}
     else{ 
       gotoxy(y-1,x);cprintf(" ");y--;
       gotoxy(y,x);}}      
   if(sw==2){
    if((c=='F')||(c=='M')){
      a[n_caracteres]=c;
      n_caracteres++;}
     else{ 
       gotoxy(y-1,x);cprintf(" ");y--;
       gotoxy(y,x);}      
}
   if(sw==0){
    if(c==32){                  
       a[n_caracteres]=c;
       n_caracteres++;
       y++;}
    if((c>=65)&&(c<=90)){
       a[n_caracteres]=c;
       n_caracteres++;
       
       }
    else{ 
       gotoxy(y-1,x);cprintf(" ");y--;
       gotoxy(y,x);}}      
    if(n_caracteres==t-1)
    {
     a[n_caracteres]='\0';
     return;}
  }while(n_caracteres==0);
	 
 }while(c=13);
}

/****************************************/
void cajero::ini()
{
 ptr=NULL;
 p=NULL;
 q=NULL;
 ptr2=NULL;
 p2=NULL;
 q2=NULL;
}
/****************************************/
void cajero::eliminacion()
{
  int sw;
  char op,op2;
  do{
  sw=0;
  cuadro2(16,10,64,22);
  char caja[2],c[9],n[20],a[20],s[2],e[3];
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  captura(caja,1,36,11,1);
  p=ptr;
  q=ptr;
  while(p!=NULL){
  if(strcmp(p->nocaj,caja)==0){
   sw=1;
   gotoxy(18,13);printf("þ_CEDULA..    >> [                          ]");
   gotoxy(18,15);printf("þ_NOMBRE..    >> [                          ]");
   gotoxy(18,17);printf("þ_APELLIDO..  >> [                          ]");
   gotoxy(18,19);printf("þ_EDAD..      >> [                          ]");
   gotoxy(18,21);printf("þ_SEXO..      >> [                          ]");
   gotoxy(36,13);cout<< p->cedula ;
   gotoxy(36,15);cout<< p->nom;
   gotoxy(36,17);cout<< p->ape;
   gotoxy(36,19);cout<< p->edad;
   gotoxy(36,21);cout<<p->sex;
   break;
   }
   q=p;
  p=p->sig_c;}
  if(sw==0){
    gotoxy(33,15);printf("<ERROR> Caja no existe..");delay(800);
    relleno3(33,57,15);relleno3(36,60,11);gotoxy(36,11);}
  if(sw==1){
   gotoxy(30,23);printf("DESEA ELIMINAR [S][N]>>[ ]");
   gotoxy(55,23);op2=toupper(getch());
   if(op2=='S'){
    relleno2(28,60,23);
    cuadro2(16,10,64,22);
    if(p->ent_u==NULL){
     if(p==ptr){
       if(p->sig_c==NULL){
	 free(p);
	 free(ptr);
	 free(q);}
	else{
	   ptr=ptr->sig_c;
	   free(p);
	   free(q);}}
       else{
	 if(p->sig_c==NULL){
	   free(p);}
          else{

         q->sig_c=p;
	 free(p);}}}
       
  }}
  gotoxy(30,15);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,15);op=toupper(getch());
 }while(op!='N'); 
}
/***************************************/
void cajero::adi_c()

{
  int sw;
  char op;
  do{
  relleno2(28,60,23);      														
  cuadro2(16,10,64,22);
  char caja[2],c[9],n[20],a[20],s[2],e[3];
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  gotoxy(36,9);captura(caja,2,36,11,1);
  sw=exi_c(caja);
  if(sw==1){
   gotoxy(33,15);printf("<ERROR> Caja ya existe..");delay(500);
   relleno3(33,57,15);relleno3(36,60,11);gotoxy(36,9);}
  if(sw==0){
   gotoxy(18,13);printf("þ_CEDULA..    >> [                          ]");
   gotoxy(18,15);printf("þ_NOMBRE..    >> [                          ]");
   gotoxy(18,17);printf("þ_APELLIDO..  >> [                          ]");
   gotoxy(18,19);printf("þ_EDAD..      >> [                          ]");
   gotoxy(18,21);printf("þ_SEXO..      >> [                          ]");
   captura(c,9,36,13,1);
   captura(n,21,36,15,0);
   captura(a,21,36,17,0);
   captura(e,3,36,19,1);
   captura(s,2,36,21,2);
   nn=new nodoc;
   strcpy(nn->nocaj,caja);
   strcpy(nn->cedula,c);
   strcpy(nn->nom,n);
   strcpy(nn->ape,a);
   strcpy(nn->sex,s);
   strcpy(nn->edad,e);
   nn->sig_c=NULL;
   nn->ent_u=NULL;
 if(ptr==NULL){
  ptr=nn;}
  else{
   nn->sig_c=ptr;
   ptr=nn;}
 }
  gotoxy(30,23);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,23);op=toupper(getch());
 }while(op!='N');
}   
/*****************************************/
void cajero::modificar()
{
  int sw;
  char op,op2;
  do{
  sw=0;
  relleno2(28,60,23);      														
  cuadro2(16,10,64,22);
  char caja[2],c[9],n[20],a[20],s[2],e[3];
  gotoxy(18,11);printf("þ_NO DE CAJA..>> [                          ]");
  captura(caja,2,36,11,1);
  p=ptr;
  while(p!=NULL){
  if(strcmp(p->nocaj,caja)==0){
   sw=1;
   gotoxy(18,11);printf("þ_CEDULA..    >> [                          ]");
   gotoxy(18,13);printf("þ_NOMBRE..    >> [                          ]");
   gotoxy(18,15);printf("þ_APELLIDO..  >> [                          ]");
   gotoxy(18,17);printf("þ_EDAD..      >> [                          ]");
   gotoxy(18,19);printf("þ_SEXO..      >> [                          ]");
   gotoxy(36,11);cout<< p->cedula ;
   gotoxy(36,13);cout<< p->nom;
   gotoxy(36,15);cout<< p->ape;
   gotoxy(36,17);cout<< p->edad;
   gotoxy(36,19);cout<<p->sex;
   q=p;
   }
  p=p->sig_c;}
   if(sw==0){
   gotoxy(33,15);printf("<ERROR> Caja no existe..");delay(800);
   relleno3(33,57,15);relleno3(36,60,11);gotoxy(36,11);}
   if(sw==1){
   relleno3(30,60,23);
   gotoxy(30,23);printf("DESEA MODIFICAR [S][N]>>[ ]");
   gotoxy(55,23);op2=toupper(getch());
     if(op2=='S'){
      relleno3(36,60,11);captura(c,9,36,11,1);
      relleno3(36,60,13);captura(n,21,36,13,0);
      relleno3(36,60,15);captura(a,21,36,15,0);
      relleno3(36,60,17);captura(e,3,36,17,1);
      relleno3(36,60,19);captura(s,2,36,19,2);
      strcpy(q->nocaj,caja);
      strcpy(q->cedula,c);
      strcpy(q->nom,n);
      strcpy(q->ape,a);
      strcpy(q->sex,s);
      strcpy(q->edad,e); }}   
  gotoxy(30,23);printf("DESEA CONTINUAR [S][N]>>[ ]");
  gotoxy(55,23);op=toupper(getch());
 }while(op!='N');
 
}
/********************************************/
int cajero::exi_c(char no_caj[])
{
 p=ptr;
 while(p!=NULL){
  if(strcmp(p->nocaj,no_caj)==0){
    return(1);}
  p=p->sig_c;}
  return(0);
 }

/******************************************/
void cajero::relleno2(int a,int b,int c)
{
 int i;
 for(i=a;i<=b;){
  gotoxy(i,c);printf("°");
 i++;}
}
/******************************************/
void cajero::relleno3(int a,int b,int c)
{
 int i;
 for(i=a;i<=b;){
  gotoxy(i,c);printf(" ");
 i++;}
}
/******************************************/
void cajero::cuadro2(int c1,int f1,int c2,int f2)
{
 int i,j; 
 gotoxy(c1,f1);printf("É");
 gotoxy(c2,f1);printf("»");
 gotoxy(c1,f2);printf("È");
 gotoxy(c2,f2);printf("¼");
  for(i=c1+1;i<c2;){
   gotoxy(i,f1);printf("Í");
   gotoxy(i,f2);printf("Í");
   for(j=f1+1;j<f2;){
    gotoxy(c1,j);printf("º");
    gotoxy(c2,j);printf("º");
    gotoxy(i,j);printf(" ");j++;}
  i++;}

}
/*******************************************/
void cajero::relleno(int a,int b,int c,int d)
{
 int i,j; 
 for(i=a;i<=c;){
  for(j=b;j<=d;){
   gotoxy(i,j);printf("°");j++;}
 i++;}
}
/******************************************/
void cajero::cuadro(int y1,int x1,int y2,int x2)
{
 int i,j;
 char op,op2,op3;
 clrscr();
 gotoxy(y1,x1);printf("É");
 gotoxy(y2,x1);printf("»");
 gotoxy(y1,x2);printf("È");
 gotoxy(y2,x2);printf("¼");
 gotoxy(y1,x1+3);printf("Ì"); 
 gotoxy(y2,x1+3);printf("¹");
  for(i=x1+1;i<x2;){
   gotoxy(y1,i);printf("º");
   gotoxy(y2,i);printf("º");i++;}
  for(j=y1+1;j<y2;){
   gotoxy(j,3);printf("Í");
   gotoxy(j,x1);printf("Í");
   gotoxy(j,x2);printf("Í");j++;}
  relleno(y1+1,x1+3,y2-1,x2-1);
  gotoxy(4,2);printf("1. CAJA[ ]   2. USUARIO[ ]   3.OPERACION[ ]   4. CONSULTA[ ]   5.SALIR[ ] ");
  gotoxy(10,12);printf("ELIJA UNA OPCION  ACORDE AL NUMERO");
   do{
    gotoxy(44,12);
    op=getch();
    if((op=='1')||(op=='2')||(op=='2')||(op=='4')||(op=='5')){
		 relleno2(10,43,12);}
    switch(op){
    case '1': gotoxy(12,2);printf("þ");
	      gotoxy(3,4);printf("Adici¢n..");
              gotoxy(3,5);printf("Modifin..");
              gotoxy(3,6);printf("Elimina..");
              gotoxy(10,10);printf("ELIJA UNA OPCION  ACORDE A LA 1RA LETRA");
               do{
                op2=toupper(getch());
                 switch (op2){
                 case 'A':relleno2(10,48,10);gotoxy(12,4);printf(">>");gotoxy(33,9);printf("ADICION DE CAJA");delay(800);relleno(2,4,13,7);
			  adi_c();cuadro(1,1,80,24);break;
                 case 'M':relleno2(10,48,10);gotoxy(12,5);printf(">>");gotoxy(33,9);printf("MODIFICACION DE CAJA");delay(800);relleno(2,4,13,7);
                          modificar();cuadro(1,1,80,24);break;
		 case 'E':relleno2(10,48,10);gotoxy(12,6);printf(">>");gotoxy(33,9);printf("ELIMINACION DE CAJA");relleno(2,4,13,7);
			  eliminacion();cuadro(1,1,80,24);return;}
		}while((op2!='A')&&(op2!='M')&&(op2='E'));
	      break; 
    case '2': gotoxy(28,2);printf("þ");
	      gotoxy(18,4);printf("Adici¢n..");
              gotoxy(18,5);printf("Modifin..");
              gotoxy(18,6);printf("Elimina..");
              gotoxy(10,10);printf("ELIJA UNA OPCION  ACORDE A LA 1RA LETRA");
               do{
                op2=toupper(getch());
                 switch (op2){
                 case 'A':relleno2(10,48,10);gotoxy(27,4);printf(">>");gotoxy(30,9);printf("ADICION DE USUARIO");delay(800);relleno(2,4,13,7);
			  adi_u();cuadro(1,1,80,24);break;
                 case 'M':relleno2(10,48,10);gotoxy(27,5);printf(">>");gotoxy(27,9);printf("MODIFICACION DE USUARIO");delay(800);relleno(2,4,13,7);
                          mod_u();cuadro(1,1,80,24);break;
		 case 'E':relleno2(10,48,10);gotoxy(27,6);printf(">>");gotoxy(33,7);printf("ELIMINACION DE CAJA");relleno(2,4,13,7);
			  elim_u();cuadro(1,1,80,24);return;}
		}while((op2!='A')&&(op2!='M')&&(op2='E'));
	      break; break;
    case '3': break;  
    case '4': gotoxy(28,2);printf("þ");
	      gotoxy(50,4);printf("Ant y sig..");
              gotoxy(50,5);printf("Mayor con..");
              gotoxy(50,6);printf("QUIT       ");
              gotoxy(10,10);printf("ELIJA UNA OPCION  ACORDE A LA 1RA LETRA");
               do{
                op2=toupper(getch());
                 switch (op2){
                 case 'A':relleno2(10,48,10);gotoxy(61,4);printf(">>");relleno(49,4,65,7);gotoxy(25,4);printf("USARIO ANTERIOR Y SIGUIENTE");
			  getch();break;
                 case 'M':relleno2(10,48,10);gotoxy(61,5);printf(">>");gotoxy(27,9);printf("MODIFICACION DE USUARIO");delay(800);relleno(49,4,65,7);
                          mod_u();cuadro(1,1,80,24);break;
		 case 'Q':relleno2(10,48,10);gotoxy(61,6);printf(">>");gotoxy(33,9);printf("ELIMINACION DE CAJA");relleno(49,4,65,7);
			  elim_u();cuadro(1,1,80,24);return;}
		}while((op2!='A')&&(op2!='M')&&(op2='Q'));
	      break; break; 
    case '5': return;}
        														
  }while((op!='1')&&(op!='2')&&(op!='2')&&(op!='4')&&(op!='5'));
     
}                 
/******************************************/
void main()
{
 cajero obj;
 obj.ini();
 obj.cuadro(1,1,80,24);
}
