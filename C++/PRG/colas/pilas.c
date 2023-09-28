	# include <stdio.h>
	# define localizar  (struct nodo*) malloc (sizeof(struct nodo))
	# define MAXIMO 20
	# define nodo_arbol (struct nodo*) malloc (sizeof (struct nodo))

struct nodo
{
 int info;
 struct nodo *izq;
 struct nodo *der;
};
struct elemento
{
	 char pre [13];
	 char in [13];
	 struct nodo *p;
};
struct LIFO
{
		int t;
		struct elemento a[MAXIMO];
};
struct lifo1
{
 int t;
 struct nodo *a[MAXIMO];
};
void init_pila(struct LIFO *p);
int pila_vacia(struct LIFO *p);
void ins_pila(struct LIFO *p,char *pre,char *in,struct nodo *s);
void retira_pila(struct LIFO*p,char *pre,char *in,struct nodo **s);
void ajustar(char *a,char *b);
void imp_inorden(struct nodo *p);
void imp_preorden(struct nodo *p);
void inicializa_pila(struct lifo1 *p);
int pil_vacia(struct lifo1 *p);
void inserte_pila(struct lifo1 *p, struct nodo *s);
void retire_pila(struct lifo1 *p,struct nodo **s);
void main(void)
{
 struct LIFO pila;
 int i,j,bandera;
 struct nodo *p,*q,*raiz;
 char pre[13],in[13];
 clrscr();
	gotoxy(3,5);printf(" DATOS EN PREORDEN:  ");
  gets(pre);
	gotoxy(40,5);printf("  DATOS EN INORDEN:  ");
  gets(in);

 init_pila(&pila);
 j=0;
 while (pre[0]!=in[j])
	j++;
 p=nodo_arbol;
 p->info=pre[0];
 p->izq=p->der=NULL;
 raiz=q=p;
 if(pre[j+1]){
	 ins_pila(&pila,pre+j+1,in+j+1,p);
   pre[j+1]=in[j+1]='\0';
 }
 ajustar(pre,in);
 while(!pila_vacia(&pila)|| pre[0]){
      bandera=0;
      if(pre[0]=='\0'){
	 retira_pila(&pila,pre,in,&q);
	 bandera=1;
       }
       j=0;
       while(pre[0]!=in[j])
	   j++;
			 p=nodo_arbol;
			 p->info=pre[0];
       p->izq=p->der=NULL;
       if(bandera)
	    q->der=p;
       else q->izq=p;
       q=p;
       if(pre[j+1]){
		ins_pila(&pila,pre+j+1,in+j+1,p);
	  pre[j+1]=in[j+1]='\0';
       }
       ajustar(pre,in);
     }
		 imp_inorden(raiz);
     printf("\n");
		 imp_preorden(raiz);
     getch();

}
void init_pila(struct LIFO *p)
{
 p->t=0;
}

int pila_vacia(struct LIFO *p)
{
  return(!p->t);
}

void ins_pila(struct LIFO *p,char *pre,char *in,struct nodo *s)
{
	if(p->t==MAXIMO) {
		gotoxy(8,15); printf("LA PILA NO SOPORTA MAS ELEMENTOS");
	 }
	 else{
			 p->t++;
			 p->a[p->t-1].p=s;
			 strcpy(p->a[p->t-1].pre,pre);
			 strcpy(p->a[p->t-1].in,in);
	}
}
void retira_pila(struct LIFO *p,char *pre,char *in,struct nodo **s)
{
 if(pila_vacia(p)){
 gotoxy(3,18);printf("PILA VACIA \n");
 *s='\0';
 }else{
    *s=p->a[p->t-1].p;
    strcpy(pre,p->a[p->t-1].pre);
    strcpy(in,p->a[p->t-1].in);
    p->t--;
  }
 }

void ajustar(char *a,char *b)
{
 int i;
 i=1;
 while(a[i]){
		a[i-1]=a[i];
		i++;
 }
 a[i-1]='\0';
 i=0;
 while(b[i])
	i++;
 b[i-1]='\0';
}
void imp_inorden(struct nodo *p)
{
 struct lifo1 pila;
 int col=70;
 inicializa_pila(&pila);
 while(p){
	inserte_pila(&pila,p);
	p=p->izq;
 }
 while(!pil_vacia(&pila)){
	retire_pila(&pila,&p);
	gotoxy(42,9);printf("LA IMPRESION EN INORDEN ES:");
	gotoxy(col,9);printf("%s",&p->info);
	p=p->der;
	col++;
	while(p){
	 inserte_pila(&pila,p);
	 p=p->izq;
	}
 }
 getch();
}
void inicializa_pila(struct lifo1 *p)
{
 p->t=0;
}
int pil_vacia(struct lifo1 *p)
{
 return(!p->t);
}
void inserte_pila(struct lifo1 *p, struct nodo *s)
{
 if(p->t == MAXIMO) {
 gotoxy(8,15);printf("\n LA PILA NO SOPORTA MAS ELEMENTOS");
 }
 else{
	p->t++;
	p->a[p->t-1]=s;
 }
}
void retire_pila(struct lifo1 *p, struct nodo **s)
{
 if(pil_vacia(p)){
	gotoxy(8,18);printf(" LA PILA ESTA VACIA");
	*s=NULL;
 }
 else{
	*s=p->a[p->t-1];
	p->t--;
 }
}
void imp_preorden(struct nodo *p)
{
 struct lifo1 pila;
 int col=31;
 inicializa_pila(&pila);
 while(p){
	gotoxy(3,9);printf("LA IMPRESION EN PREORDEN ES:");
	gotoxy(col,9);printf("%c",p->info);
	inserte_pila(&pila,p);
	p=p->izq;
	col++;

 }
 while(!pil_vacia(&pila)){
	retire_pila(&pila,&p);
	p=p->der;
	while(p){

	gotoxy(col,12); printf("%s",&p->info);
	 inserte_pila(&pila,p);
	 p=p->izq;
	 col++;
	}
 }
 getch();
}
