#include"conio.h"
#include"stdlib.h"
#include"stdio.h"
#include"string.h"
#include"ctype.h"
struct Lista {
     char Prefijo[100];
     char Posfijo[100];
     struct Lista *sig;
	    };


class Prepo{
	char pila[100];
	int tope;
	char cola[100];
	int frente,final;
	struct Lista *Cab,*nn,*p;
	public:
	Prepo(){ printf("Construyendo");frente=-1;final=0;tope=0; Cab=NULL; };
	~Prepo(){printf("Destruyendo");Cab=NULL;};
	void substr(char s1[],int i,int j,char s2[]);
	void conv(char prefix[], char postfix[]);
	void RecorrerPila();
	void RecorrerCola();
	void Listas(char prefijo[],char posfijo[] );
	void RecorrerLista();
	 };

void Prepo::RecorrerLista(){

    p=Cab;
    clrscr();
    while(p!=NULL){
      clrscr();
      printf("\nExpresion En Prefijo: %s ",p->Prefijo);
      printf("\nExpresion En Posfijo: %s ",p->Posfijo);
      p=p->sig;
      getch();
		  }
			  }


void Prepo::RecorrerPila(){
printf("\nLos Operadores Son::> ");
 while(tope>-1)
     printf("%c",pila[tope--]);
		getch();
		tope=0;
			}


void Prepo::Listas(char prefijo[],char posfijo[] ){
	 nn=new Lista;
	 strcpy(nn->Prefijo,prefijo);
	 strcpy(nn->Posfijo,posfijo);
	 nn->sig=NULL;

	 if(Cab==NULL)
	     Cab=nn;
	  else{
	      p=Cab;
	      while(p->sig!=NULL)
		  p=p->sig;
	     p->sig=nn;
	     }                                 }


void Prepo::RecorrerCola(){
printf("\nLas Variables Son::> ");
 while(frente!=final)
     printf("%c",cola[frente++]);
		getch();
		frente=-1;
		final=0;
		}


void Prepo::conv(char prefix[], char postfix[])
  {
  char t1[100],t2[100];
  char first[2];

  first[0]=prefix[0];
  first[1]='\0';
  substr(prefix,1,strlen(prefix)-1,prefix);
	  if(first[0]== '+' || first[0]=='-' || first[0]=='*' || first[0]=='/'){
	      pila[tope]=first[0];
	      tope++;
	      conv(prefix,t1);
	      conv(prefix,t2);
	      strcat(t1,t2);
	      strcat(t1,first);
	      substr(t1,0,strlen(t1),postfix);
	      return;
	    }
	   cola[final]=first[0];
	   final++;
	   if(frente==-1)
	       frente=0;

	  postfix[0]=first[0];
	  postfix[1]='\0';
      }


void Prepo::substr(char s1[],int i,int j,char s2[])
   {
   int k,m;
   for(k=i,m=0;m<j;s2[m++]=s1[k++])
       ;
       s2[m]='\0';
    }



void main()
     {
	char prefix[100],postr[100], aux[100];
	Prepo Expre;
	int pos;

  do{
	clrscr();
	pos=0;
	printf("Digite Una Expresion en Prefijo ");
	while((prefix[pos++]=getchar())!='\n');

		       prefix[--pos]='\0';
		       printf("%s \n %s \n","La Expresion Prefija Original Es",prefix);
		       strcpy(aux,prefix);
		       Expre.conv(prefix,postr);
		       Expre.RecorrerPila();
		       Expre.RecorrerCola();
		       Expre.Listas(aux,postr);
		       printf("\nLa Expresion posfijo Es %s\n",postr);
		       printf("\nDesea Continuar S o N ");

   }while(toupper(getch())!='N');
   Expre.RecorrerLista();
 }

