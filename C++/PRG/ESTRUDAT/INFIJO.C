#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define  MAX 20
#define  MAXIMO 5
#define  crear (struct LIFO *) malloc(sizeof(struct LIFO))
struct LIFO{
    int t;
    char a[MAXIMO];
}*p;

struct expre{
       char op;
       double valor;
};

 init_pila(struct LIFO *p);
 pila_vacia(struct LIFO *p);
 ins_pila(struct LIFO *p,char s);
 ins_pil(struct LIFO *p);
 retira_pila(struct LIFO *p,char *s);
 ret_pil(struct LIFO *p);
 most_pil(struct LIFO *p);
 prioridad(char op1,char op2);
 cuadro(int fil1,int col1,int fil2,int col2,int caso);
 mostrar0(void);
 mostrar1(void);
 mostrar2(void);
 menu(void);
 char *s=' ';

/*			PROGRAMA PRINCIPAL   */


main()
{
    p=crear;
    init_pila(p);
    menu();

}

/*DEFINICION DE FUNCIONES*/
/*MENU PRINCIPAL*/

menu(void)
{
 char a;
 textcolor(7);textbackground(1);
 clrscr();
 cuadro(1,1,24,80,2);
 cuadro(5,10,17,70,2);
 cuadro(4,8,19,72,2);
 gotoxy(30,7);cprintf("PILAS Y CONVERSIONES");
 gotoxy(20,10);cprintf("1.  PILAS");
 gotoxy(20,11);cprintf("2.  INFIJO A POSFIJO");
 gotoxy(20,12);cprintf("3.  INFIJO A PREFIJO");
 gotoxy(20,13);cprintf("4.  SALIR");
 gotoxy(33,15);cprintf("INGRESE OPCION:  ");
 a=getch();
 if(a==0)a=getch();
 switch(a){
       case '1':  mostrar0();
		  break;
       case '2':  mostrar1();
		  break;
       case '3':  mostrar2();
		  break;
       case '4': exit(0);
    }
 }

cuadro(int fil1,int col1,int fil2,int col2,int caso)
{
 int i,j;
 char h,v,e1,e2,e3,e4;

 switch(caso){
	case 1: h='Í';v='Í';e1='Ì';e2='¹';e3='Ì';e4='¹';break;
	case 2: h='Í';v='º';e1='É';e2='»';e3='È';e4='¼';break;
	case 3: h='Í';v='º';e1='Ë';e2='Ë';e3='Ê';e4='Ê';
 }
 for(i=col1;i<=col2;i++){
	gotoxy(i,fil1);putchar(h);
	gotoxy(i,fil2);putchar(h);
 }
 for(i=fil1;i<=fil2;i++){
	gotoxy(col1,i);putchar(v);
	gotoxy(col2,i);putchar(v);
 }
 gotoxy(col1,fil1);putchar(e1);gotoxy(col2,fil1);putchar(e2);
 gotoxy(col1,fil2);putchar(e3);gotoxy(col2,fil2);putchar(e4);
}


/* MANEJO DE PILAS*/

mostrar0(void)
{
    char opc=' ';
    clrscr();
    cuadro(1,1,24,79,2);
    cuadro(4,8,19,72,2);
    cuadro(5,10,17,70,2);
    gotoxy(30,7);cprintf("MANEJO DE PILAS");
    gotoxy(20,10);cprintf("1.  INSERTAR ELEMENTO");
    gotoxy(20,11);cprintf("2.  RETIRAR ELEMENTO");
    gotoxy(20,12);cprintf("3.  MOSTRAR PILA");
    gotoxy(20,13);cprintf("4.  SALIR");
    gotoxy(33,15);cprintf("INGRESE OPCION:  ");
    opc=getch();
    if(opc==0)opc=getch();
    switch(opc){
       case '1':  ins_pil(p);
		  break;
       case '2':  ret_pil(p);
		  break;
       case '3':  most_pil(p);
		  break;
       case '4':  menu();
		  break;
    }
}


    tope(struct LIFO *p)
    {
	    return(p->a[p->t-1]);
    }

    init_pila(struct LIFO *p)
    {
	   int cnt=0;
	   p->t = 0;
	   while(cnt++<=MAXIMO) p->a[cnt]=0;
    }

    pila_vacia(struct LIFO *p)
    {
	   return(!p->t);
    }

    ins_pila(struct LIFO *p,char s)
    {
	   if(p->t == MAXIMO){
		gotoxy(20,10);printf("LA PILA NO SOPORTA MAS ELEMENTOS\n");
		delay(2000);
	   }
	   else{
		 p->t++;
		 p->a[p->t-1] = s;
	   }
    }

    ins_pil(struct LIFO *p)
    {
	   char s=' ';
	   clrscr();
	   cuadro(1,1,24,79,2);
	   cuadro(4,8,19,72,2);
	   cuadro(5,10,17,70,2);
	   gotoxy(20,10);
	   if(p->t == MAXIMO){
	       printf("LA PILA NO SOPORTA MAS ELEMENTOS\n");
	       delay(2000);
	   }
	   else{
		 p->t++;
		 printf("DIGITE LETRA A ALMACENAR:  ");
		 s=getch();
		 p->a[p->t-1] = s;
		 p->a[p->t] = ' ';
		 gotoxy(20,12);printf("A¥ADIDO ELEMENTO %c\n",s);
		 delay(1000);
	   }
	  mostrar0();
    }


    retira_pila(struct LIFO *p,char *s)
    {
	   if(pila_vacia(p)){
	      printf("LA PILA ESTA VACIA\n");
	      *s = NULL;
	   }
	   else{
		 *s = p->a[p->t-1];
		 p->t--;
	   }
    }

    ret_pil(struct LIFO *p)
    {

	   clrscr();
	   cuadro(1,1,24,79,2);
	   cuadro(4,8,19,72,2);
	   cuadro(5,10,17,70,2);
	   gotoxy(20,10);
	   if(pila_vacia(p)){
	      printf("LA PILA ESTA VACIA\n");
	      delay(500);
	   }
	   else{
		 *s = p->a[p->t-1];
		 p->a[p->t-1]=0;
		 p->t--;
		 printf("SE RETIRO ELEMENTO %c",*s);
		 delay(2000);
	   }
	   mostrar0();
    }

    most_pil(p)
    struct LIFO *p;
    {
	   int fil=8;
	   clrscr();
	   cuadro(1,1,24,79,2);
	   cuadro(4,8,19,72,2);
	   cuadro(5,10,17,70,2);
	   gotoxy(20,10);

	   if(pila_vacia(p)){
	      printf("LA PILA ESTA VACIA\n");
	   }
	   else	while(p->t>=0){
		gotoxy(20,fil++);printf("%c",p->a[p->t]);
		p->t--;
	   }
	   delay(2000);
	   mostrar0();
    }

/* CONVERSION DE INFIJO A POSFIJO */

mostrar1(void)
{
    int i;
    struct expre posfijo[MAX];
    char infijo[MAX],posfijo1[MAX],linea[100];
    char operan[MAX];
    clrscr();
    cuadro(1,1,24,79,2);
    cuadro(4,8,19,72,2);
    cuadro(5,10,17,70,2);
    for(i=0;i<MAX;i++){
       infijo[i] = ' ';
       linea[i] = ' ';
       operan[i] = 0;
       posfijo[i].op = ' ';
       posfijo[i].valor = 0;
    }
    gotoxy(12,6);printf("LEA EXPRESION SIN ESPACIOS Y ESCRITA CORRECTAMENTE\n");
    gotoxy(12,7);printf("ESTE PROGRAMA NO VALIDA LOS DATOS\n");
    gotoxy(12,8);printf("LA EXPRESION DEBE ESTAR EN NOTACION INFIJO SIN PARENTESIS\n");
    gotoxy(12,9);printf("--->");
    gets(linea);
    for(i=0;i<=strlen(linea);i++){
    infijo[i]=linea[i];
    }
    in_a_pos(infijo,posfijo1);
    getch();
    menu();
}

    in_a_pos(infijo,posfijo)
    char *infijo,*posfijo;
      {
	 struct LIFO pila;
	 int i,j;
	 char elemento;
	 i=0;
	 j=-1;

	 init_pila(&pila);
	 while(infijo[i]!=NULL){
	    if(operando(infijo[i]))
		posfijo[++j] = infijo[i++];
	    else{
	      while(!pila_vacia(&pila) && prioridad(tope(&pila),infijo[i])){
		  retira_pila(&pila,&elemento);
		  posfijo[++j] = elemento;
	      }
	      if(infijo[i]==')')
		  retira_pila(&pila,&elemento);
	      else ins_pila(&pila,infijo[i]);
	      i++;
	    }
	 }
	 while(!pila_vacia(&pila)){
		retira_pila(&pila,&elemento);
		posfijo[++j] = elemento;
	 }
	 posfijo[++j] = '\0';
	 gotoxy(12,12);printf("posfijo: ");
	 puts(posfijo);
	 getch();
	 menu();
    }

/*CENVERSION DE INFIJO A PREFIJO*/

   in_a_pre(infijo,prefijo)
    char *infijo,*prefijo;
      {
	 struct LIFO pila;
	 int i,j;
	 char elemento;
	 i=0;
	 j=-1;
	 init_pila(&pila);
	 while(infijo[i]!=NULL){
	    if(!operando(infijo[i]))
		prefijo[++j] = infijo[i++];
	    else{
	      while(!pila_vacia(&pila) || prioridad(tope(&pila), infijo[i])){
		  retira_pila(&pila,&elemento);
		  prefijo[++j] = elemento;
	      }
	      if(infijo[i]==')')
		  retira_pila(&pila,&elemento);
	      else ins_pila(&pila,infijo[i]);
	      i++;
	    }
	 }
	 while(!pila_vacia(&pila)){
		retira_pila(&pila,&elemento);
		prefijo[++j] = elemento;
	 }
	 prefijo[++j] = '\0';
	 gotoxy(12,12);printf("prefijo: ");
	 puts(prefijo);
	 getch();
	 menu();
    }

mostrar2(void)
{
    int i;
    struct expre prefijo[MAX];
    char infijo[MAX],prefijo1[MAX],linea[100];
    char operan[MAX];
    clrscr();
    cuadro(1,1,24,79,2);
    cuadro(4,8,19,72,2);
    cuadro(5,10,17,70,2);
    for(i=0;i<MAX;i++){
       infijo[i] = ' ';
       linea[i] = ' ';
       operan[i] = 0;
       prefijo[i].op = ' ';
       prefijo[i].valor = 0;
    }
    gotoxy(12,6);printf("LEA EXPRESION SIN ESPACIOS Y ESCRITA CORRECTAMENTE\n");
    gotoxy(12,7);printf("ESTE PROGRAMA NO VALIDA LOS DATOS\n");
    gotoxy(12,8);printf("LA EXPRESION DEBE ESTAR EN NOTACION INFIJO SIN PARENTESIS\n");
    gotoxy(12,9);printf("--->");
    gets(linea);
    for(i=0;i<=strlen(linea);i++){
    infijo[i]=linea[i];
    }
    in_a_pre(infijo,prefijo1);
    getch();
}

    operando(c)
    char c;
    {
	 return(c!='+' &&
		c!='-' &&
		c!='*' &&
		c!='/' &&
		c!='^' &&
		c!=')' &&
		c!='(' );
    }


    static int m[6][7] = {
	   {1,1,0,0,0,0,1},
	   {1,1,0,0,0,0,1},
	   {1,1,1,1,0,0,1},
	   {1,1,1,1,0,0,1},
	   {1,1,1,1,1,0,1},
	   {0,0,0,0,0,0,0}
    };


    prioridad(char op1,char op2)
    {
	   int i,j;
	   switch(op1){
		case'+': i = 0;break;
		case'-': i = 1;break;
		case'*': i = 2;break;
		case'/': i = 3;break;
		case'^': i = 4;break;
		case'(': i = 5;break;
	   }
	   switch(op2){
		case'+': j = 0;break;
		case'-': j = 1;break;
		case'*': j = 2;break;
		case'/': j = 3;break;
		case'^': j = 4;break;
		case'(': j = 5;break;
		case')': j = 6;break;
	   }
	   return(m[i][j]);
    }
