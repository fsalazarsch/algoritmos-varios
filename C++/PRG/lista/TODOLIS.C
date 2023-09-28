# include <stdio.h>
# include <conio.h>
# include <alloc.h>
# define esc 27
# define enter 13
/*=================================================================*/
/*======== ESTAS ESTRUCTURA SON UTILIZADAS PARA LISTAS SIMPLES ====*/  
/*=================================================================*/
# define localizar_simple (struct nodo_simple *)malloc (sizeof(struct nodo_simple))
  struct nodo_simple
   {
     int info_simple;
     struct nodo_simple *sig_simple;
   };
  struct nodo_simple *cab_simple, *q_simple, *p_simple, *nuevo_simple, *inicio_simple;
/*=================================================================*/
/*======== ESTAS ESTRUCTURA SON UTILIZADAS PARA LISTAS DOBLES  ====*/  
/*=================================================================*/
# define localizar_dobles (struct nodo_dobles *)malloc (sizeof(struct nodo_dobles))
  struct nodo_dobles
   {
     int info_dobles;
     struct nodo_dobles *sig_dobles, *ant_dobles;
   };
  struct nodo_dobles *cab_dobles, *q_dobles, *nuevo_dobles, *p_dobles, *inicio_dobles;
/*=================================================================*/
/*======== ESTAS ESTRUCTURA SON UTILIZADAS PARA LISTAS COLAS   ====*/  
/*=================================================================*/
# define localizar_colas (struct nodo_colas *)malloc (sizeof(struct nodo_colas))
  struct nodo_colas 
   {
     int info_colas;
     struct nodo_colas *sig_colas;
   };
  struct nodo_colas *cab1_colas, *cab2_colas, *guia1_colas, *guia2_colas, *p_colas, *nuevo_colas, 
   *q_colas, *aux_colas;
/*=================================================================*/
/*======== ESTAS ESTRUCTURA SON UTILIZADAS PARA LOS MENUS      ====*/  
/*=================================================================*/
int i = 0;
char *menu[] =   {"SIMPLES","DOBLES","CIRCULARES","DOBLES C.", "COLAS", "BICOLAS", "SALIR"};
int  columnas[]= {4,15,25,37,48,57,67};
char *orden[] =  {"CREA      ","INSERTAR  ","RETIRAR   ","LISTAR   " };
/*=================================================================*/
/*======== PROCEDIMIENTO DE MANEJO DE COLORES                  ====*/  
/*=================================================================*/
void color (int fondo, int letras)
 {
  textcolor (letras);
  textbackground (fondo);
 }
/*=================================================================*/
/*======== PROCEDIMIENTO DE MOSTRAR OPCIONES DEL MENU          ====*/  
/*=================================================================*/
void mostrar_opciones (void)
 {         
   gotoxy (21,2);
   color (3,1);
   cprintf ("MANEJADOR DE ESTRUCTURAS DE DATOS <MED>"); /*TITULO PROGRAMA*/
   gotoxy (5,21);
   color (2,1);
   cprintf ("    <- DESPLAZAMIENTO ->        <Ù CONFIRMA            < ESC > SALIR");
 }
/*=================================================================*/
/*======== REALIZA EL CUADRO CON PARAMETRO DE COL_INICIAL      ====*/
/*======== COL_FINAL, LINEA_INICIAL Y LINEA FINAL              ====*/   
/*=================================================================*/

void cuadro (int fi, int ci, int ff, int cf, char * caracteres)
  {
    for (i=fi + 1; i <=ff; i++)
      {
	gotoxy (ci, i);
	putchar (caracteres [3]);
	gotoxy (cf, i);
	putchar (caracteres [3]);
      }
    for (i =ci + 1;i<= cf ; i++)
      {
	gotoxy (i , fi);
	putchar (caracteres [1]);
	gotoxy (i , ff);
	putchar (caracteres [1]);
      }
    gotoxy (ci, fi);
    putchar (caracteres [0]);
    gotoxy (ci, ff);
    putchar (caracteres [8]);
    gotoxy (cf, fi);
    putchar (caracteres [2]);
    gotoxy (cf, ff);
    putchar (caracteres [6]);
  }
/*=================================================================*/
/*======== REALIZA EL CUADRO CON PARAMETRO DE MENU PRINCIPAL   ====*/
/*=================================================================*/
void pintar_pantalla (void)
 {
   clrscr ();
   color (0,1);
   cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");  /*CUADRO*/
   cuadro (3, 3, 5, 77, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");
   cuadro (20, 3, 23, 77, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");
   gotoxy (24,12);
   color (2,1);
   cprintf ("  MATERIA ESTRUCTURA DE DATOS  ");
   gotoxy (11,14);
   color (2,1);
   mostrar_opciones ();
 }
/*=================================================================*/
/*========     CAPTURA LAS OPCIONES DEL MENU PRINCIPAL         ====*/
/*=================================================================*/
 void aceptar (int *op, int *b)
 {
   int tecla;
   int error = 0;
   while (error == 0)
   {
     gotoxy (5,70);
     tecla = getch ();
     if (tecla == 0)
      {
       tecla = getch ();
       tecla = tecla + 256;
      }
     if (tecla == 328 || tecla == 331)
      {
	if (*op==0)
	   *op=6;
	else
	  --*op;
	break;
      }
     if (tecla == 336 || tecla == 333)
      {
	if (*op==6)
	   *op=0;
	else
	   ++*op;
	break;
      }
     if (tecla == 13 && *op == 6)
      {
	*b = 27;
	break;
      }
     if (tecla == 13 )
      {
	*b = 13;
	break;
      }
     if (tecla == 27 )
      {
	*b = 27;
	break;
      }
   }
 }
/*=================================================================*/
/*========     CAPTURA LAS OPCIONES DEL MENU DE CASCADA        ====*/
/*=================================================================*/
void aceptar2 (int *op, int *b)
  {
    int tecla;
    int error = 0;
    while (error == 0)
     {
       gotoxy (5,70);
       tecla = getch ();
       if (tecla == 0)
	{
	 tecla = getch ();
	 tecla = tecla + 256;
	}
       if (tecla == 328 || tecla == 331)
	{
	  if (*op==0)
	     *op=3;
	  else
	     --*op;
	  break;
	}
       if (tecla == 336 || tecla == 333)
	{
	  if (*op==3)
	     *op=0;
	  else
	     ++*op;
	  break;
	}
       if (tecla == 13 )
	{
	  *b = 13;
	  break;
	}
       if (tecla == 27 )
	{
	  *b = 27;
	  break;
	}
     }
  }
/*=================================================================*/
/*========  MUESTRA LAS OPCIONES DEL MENU PRINCIPAL Y RESALTA    ==*/        
/*========       LA OPCION QUE SE ENCUENTRA EN USO               ==*/
/*=================================================================*/
void visualizar (int a)
 {
   register int i;
   for (i =0; i<=6 ; i++)
       {
	 color (3,1);
	 gotoxy (columnas [i] , 4);
	 cprintf ("%s" , menu [i]);
       }
   color (2,1);
   gotoxy (columnas [a] , 4);
   cprintf ("%s" , menu [a]);
 }
/*----------------------- LISTAS  SIMPLES--------------------------*/
/*=================================================================*/
/*========   REALIZA LA CAPTURA INICIAL DE UNA LISTA SIMPLE      ==*/        
/*========          Y UNA LISTA  SIMPLE  CIRCULAR                ==*/
/*=================================================================*/
void crear_simple (void) 
  {
    int i, j=0;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("CREACION LISTAS SIMPLES<MED>");
    gotoxy (5,5); 
    color (3,1);
    cprintf ("DIGITE NO DE NODOS A CREAR:    ");           /*MENSAJE*/
    gotoxy (5,45);
    scanf ("%d", &i);                                      /*CAPTURA*/
    cab_simple = NULL;
    while (i>0)
    {
       q_simple = localizar_simple;                        /*CREACION*/
       if (j == 0)
       {
	 inicio_simple = q_simple;
	 j++;
       }
      gotoxy (5,8);
      color (3,1);
      cprintf("DIGITE EL CONTENIDO DEL NODO %d ->:  ",i);  /*MENSAJE*/
      gotoxy (45,8);
      scanf ("%d",&q_simple ->info_simple);                /*CAPTURA*/
      q_simple->sig_simple = cab_simple;
      cab_simple = q_simple;
      --i;
    }
  }
/*=================================================================*/
/*========   REALIZA LA IMPRESION DE UNA LISTA SIMPLE Y CIRC.    ==*/        
/*========   REALIZA IMPRESIONES DE 4 EN CUATRO POR RENGLON.     ==*/
/*=================================================================*/
 void listar_simple (void)
  {
    int i = 1, j=0, k=1, l=0;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    color (3,5);
    gotoxy (25,2); 
    cprintf (" IMPRESION DE LISTAS SIMPLES  <MED>");       /*MENSAJE*/
    q_simple = cab_simple;
    if (q_simple == NULL)
     {
       gotoxy  (35,20);
       color (3,1);
       cprintf ("LISTA VACIA");                            /*MENSAJE*/
     }
    else
     {
       p_simple = q_simple;
       while (p_simple->sig_simple != inicio_simple->sig_simple)
       {
	j = 1;
	l = (k * 4) + 2; 
	while ((j < 5) && (p_simple->sig_simple != inicio_simple->sig_simple))
	{ 
	   l = (k * 4) + 2;                                /*DIBUJO*/
	   gotoxy ((j * 14) - 6,l);
	   color (3,1); 
	   cprintf ("%c%d%c%d%c",'³', p_simple->info_simple,'³', p_simple->sig_simple,'³');
	   color (0,4);
	   cprintf ("--->");                               /*LINEA DIR.*/
	   gotoxy ((j * 14) - 6,l-1);                      /*DIBUJO*/
	   cprintf ("%d",p_simple);
	   p_simple = p_simple->sig_simple;
	   j++;                                            /*INCREMENTO FIL Y COL*/
	   i++;
	}
	 k++;
       }
       color (3,1); 
       gotoxy ((j * 14) - 6,l);
       cprintf ("%c%d%c%d%c",'³', p_simple->info_simple,'³', p_simple->sig_simple,'³');
       color (0,4);
       gotoxy ((j * 14) - 6,l-1);                          /*DIBUJO*/
       cprintf ("%d",p_simple);
       p_simple = p_simple->sig_simple;
     }
     getch ();
  }
/*=================================================================*/
/*========     REALIZA LA INSERCION DESPUES DE UN NODO DADO      ==*/        
/*========     RECORRIENDO LA LISTA HASTA ENCONTRAR EL NODO      ==*/
/*=================================================================*/
  void insertar_despues_simple  (nd, dt)
   {
     int i= nd;
     int j=1;
     int n = dt;
     p_simple = cab_simple;
     while (j != i)
      {
	p_simple = p_simple->sig_simple;                   /*RECORRIDO*/
	j++;
      }
     if (p_simple == NULL)
       {
	 color (3,1);
	 gotoxy (32,15);
	 cprintf ("NO SE PUEDE INSERTAR ");                /*MENSAJE*/
	 getch ();
       }
     else
       {
	 nuevo_simple = localizar_simple;
	 nuevo_simple->info_simple= n;
	 nuevo_simple->sig_simple = p_simple->sig_simple;  /*PROCESO*/
	 p_simple->sig_simple = nuevo_simple;
	 if (p_simple == inicio_simple)
	    inicio_simple = nuevo_simple;
       }
   }
/*=================================================================*/
/*========     REALIZA LA INSERCION ANTES  DE UN NODO DADO       ==*/        
/*========     RECORRIENDO LA LISTA HASTA ENCONTRAR EL NODO      ==*/
/*=================================================================*/
  void insertar_antes_simple (nd, dt)
   {
     int i;
     int j=0;
     int n;
     struct nodo_simple *r_simple;                         /*ESTRUCTURA*/
     i = nd;
     n = dt;
     p_simple = cab_simple;
     r_simple = cab_simple;
     while (j != (i - 1))
      {
	r_simple = p_simple;
	p_simple = p_simple->sig_simple;                   /*RECORRIDO*/
	j++;
      }
     if (p_simple == NULL)
      {
	color (3,1);
	cprintf ("NO SE PUEDE INSERTAR ");                 /*MENSAJE*/
	getch ();
      }
     else 
     if (p_simple == cab_simple)
      {
	 nuevo_simple = localizar_simple;
	 nuevo_simple->info_simple= n;
	 nuevo_simple->sig_simple = r_simple;              /*PROCESO*/
	 cab_simple = nuevo_simple;
      }
     else
      {
	 nuevo_simple = localizar_simple;
	 nuevo_simple->info_simple= n;
	 nuevo_simple->sig_simple = p_simple;
	 r_simple->sig_simple = nuevo_simple;              /*PROCESO*/
      }
   }
/*=================================================================*/
/*========     PREGUNTA DONDE DESEA HACER LA INSERCION           ==*/        
/*========        ANTES O DESPUES DE UN NODO DADO                ==*/
/*=================================================================*/
void insertar_simple(void)
 {
    int i, d, n;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("INSERCION LISTAS SIMPLES<MED>");
    gotoxy (5,5);
    color (3,1);
    cprintf ("INSERTAR 1.ANTES 2.DESPUES:  ");             /*MENSAJE*/
    gotoxy (35,5);
    scanf ("%d", &i);                                      /*CAPTURA*/
    gotoxy (5,7);
    color (3,1);
    cprintf ("EN EL NODO No:  ");                          /*MENSAJE*/
    gotoxy (30,7);
    scanf ("%d", &d);                                      /*CAPTURA*/
    gotoxy (5,9);
    color (3,1);
    cprintf ("DATO DE NODO: ");                            /*MENSAJE*/
    gotoxy (30,9);
    scanf ("%d", &n);
    if (i==1)                                              /*CAPTURA*/
      insertar_antes_simple (d, n);                        /*FUNCION*/
    else
    if (i==2)
      insertar_despues_simple (d , n);                     /*FUNCION*/
 }
/*=================================================================*/
/*========           RETIRAR UN NODO DADO                        ==*/        
/*========                                                       ==*/
/*=================================================================*/
void retirar_simple (void)
  {
     int h;
     int j = 1;
     int i;
     struct nodo_simple  *r_simple;                        /*ESTRUCTURA*/
     color (0,1);
     clrscr();
     cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");/*CUADRO*/
     gotoxy (30,2);
     color (3,1);
     cprintf ("RETIRO NODOS LISTAS SIMPLES<MED>");
     gotoxy (5,5);
     color (3,1);
     cprintf("DIGITE EL NUMERO DEL NODO A RETIRAR:");      /*MENSAJE*/
     gotoxy (45,5);
     scanf ("%d", &i);                                     /*CAPTURA*/
     p_simple = cab_simple;
     r_simple = NULL;
     while (j != i )
      {
	r_simple = p_simple;
	p_simple = p_simple->sig_simple;                   /*RECORRIDO*/
	j ++;
      }
     if(p_simple == NULL)
      {
	gotoxy (35,20);
	color (3,1);
	cprintf(" LISTA VACIA\n");                         /*MENSAJE*/
	getch();
      }
     else
     if (p_simple == cab_simple)
      {
	cab_simple = p_simple->sig_simple;
	/* h = p_simple->info_simple; */
	free (p_simple);                                   /*PROCESO*/
	if (cab_simple->sig_simple == cab_simple)
	 {
	   cab_simple = NULL;
	 } 
      }
     else
      {
	r_simple->sig_simple = p_simple->sig_simple;       /*PROCESO*/
	/* h = p_simple->info_simple; */
	if (p_simple == inicio_simple)
	   inicio_simple = r_simple;
	free (p_simple);
      }
  }
/*----------------------  LISTAS  DOBLES   ----------------------- */
/*=================================================================*/
/*========        CREA UN NODO EN UNA LISTA DOBLE                ==*/        
/*========      PREGUNTA CUANTOS NODOS DESEA CREAR               ==*/
/*=================================================================*/
void crear_dobles (void) 
  {
    int i;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("CREACION LISTAS DOBLES<MED>");
    gotoxy (5,5);
    color (3,1); 
    cprintf ("DIGITE NO DE NODOS A CREAR: ");             /*MENSAJE*/
    gotoxy (5,35);
    scanf ("%d", &i);                                      /*CAPTURA*/
    if (i < 1)
    {
       gotoxy ( 34,15);
       color (3,1);
       cprintf ("NO SE PUEDE CREAR LA LISTA ");            /*MENSAJE*/
    }
    else
    {
       cab_dobles = localizar_dobles;
       gotoxy (5,8);
       color (3,1);
       cprintf("DIGITE EL CONTENIDO DEL NODO %d ->:  ",i); /*MENSAJE*/
       gotoxy (45,8);
       scanf ("%d",&cab_dobles->info_dobles);              /*CAPTURA*/
       cab_dobles->sig_dobles = NULL;
       cab_dobles->ant_dobles = NULL;
       p_dobles = cab_dobles;
       while (i>1)
       { 
	  q_dobles = localizar_dobles;
	  gotoxy (5,8);
	  color(3,1);
	  cprintf("DIGITE EL CONTENIDO DEL NODO %d ->:  ",i);/*MENSAJE*/
	  gotoxy (45,8);
	  scanf ("%d",&q_dobles->info_dobles);             /*CAPTURA*/
	  p_dobles->sig_dobles = q_dobles;
	  q_dobles->ant_dobles = p_dobles;                 /*PROCESO*/
	  q_dobles->sig_dobles = NULL;
	  p_dobles = q_dobles;
	  inicio_dobles = p_dobles;
	  --i;
       }
    }
  }
/*=================================================================*/
/*========          IMPRESION DE UNA LISTA DOBLE                 ==*/        
/*========                                                       ==*/
/*=================================================================*/
void listar_dobles (void)
  {
      int i = 1,j,l,k=1;
      color (0,1);
      clrscr();
      cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");/*CUADRO*/
      color (3,5);
      gotoxy (25,2); 
      cprintf (" IMPRESION DE LISTAS DOBLES  <MED>");       /*MENSAJE*/
      p_dobles = cab_dobles;
      if (p_dobles == NULL)
       {
	 gotoxy (35,15);
	 color(3,1);
	 cprintf ("LISTA VACIA ");                         /*MENSAJE*/
       }
      else
       {
	 while (p_dobles->sig_dobles != inicio_dobles->sig_dobles)
	  {
	    j = 1;
	    l = (k * 4) + 1; 
	    while ((j < 5) && (p_dobles->sig_dobles!= inicio_dobles->sig_dobles))
	     {
	      gotoxy ((j * 17) - 7,l);
	      color (3,1);                                 /*DIBUJO*/
	      cprintf ("%c%d%c%d%c%d%c",'³',p_dobles->ant_dobles,'³',p_dobles->info_dobles,'³',p_dobles->sig_dobles,'³'); 
	      color (0,4);
	      cprintf ("--->");                            /*DIR.*/
	      gotoxy ((j * 17) - 7,l-1);
	      cprintf ("%d",p_dobles);
	      p_dobles = p_dobles->sig_dobles;
	      j++;
	      i++;
	     }
	    k++;
	  }
	 color (3,1);                                      /*BIBUJO*/
	 gotoxy ((j * 17) - 7,l);
	 cprintf ("%c%d%c%d%c%d%c",'³',p_dobles->ant_dobles,'³',p_dobles->info_dobles,'³',p_dobles->sig_dobles,'³'); 
	 color (0,4);
	 gotoxy ((j * 17) - 7,l-1);
	 cprintf ("%d",p_dobles);
	 p_dobles = p_dobles->sig_dobles;
       }
      getch();
  }
/*=================================================================*/
/*========      INSERTAR UN NODO EN UNA LISTA DOBLE              ==*/        
/*========            DESPUES DE UN NODO DADO                    ==*/
/*=================================================================*/
void insertar_despues_dobles  (nd, dt)
  {
     int i= nd;
     int j=1;
     int n = dt;
     p_dobles = cab_dobles;
     while (j != i)
      {
       p_dobles = p_dobles->sig_dobles;                    /*RECORRIDO*/
       j++;
      }
      if (p_dobles == NULL)
       {
	color (3,1);
	gotoxy (35,15);
	cprintf ("NO SE PUEDE INSERTAR ");                 /*MENSAJE*/
	getch ();
       }
      else
       {   
	nuevo_dobles = localizar_dobles;
	q_dobles = p_dobles ->sig_dobles;
	nuevo_dobles->info_dobles= n;                      /*PROCESO*/
	nuevo_dobles->ant_dobles = p_dobles;
	nuevo_dobles->sig_dobles = p_dobles->sig_dobles;
	p_dobles->sig_dobles = nuevo_dobles;
	if (p_dobles == inicio_dobles)
	   inicio_dobles = nuevo_dobles;
	if (q_dobles != NULL)
	   q_dobles->ant_dobles = nuevo_dobles;
       }
  }
/*=================================================================*/
/*========          INSERTAR UN NODO EN UNA LISTA DOBLE          ==*/        
/*========             INSERTA ANTES  DE UN NODO DADO            ==*/
/*=================================================================*/
void insertar_antes_dobles (nd, dt)
   {
      int i;
      int j=0;
      int n;
      i = nd;
      n = dt;
      p_dobles = cab_dobles;
      q_dobles = cab_dobles;
      while (j != (i - 1))
       {
	 q_dobles = p_dobles;
	 p_dobles = p_dobles->sig_dobles;                  /*RECORRIDO*/
	 j++;
       } 
      if (p_dobles == NULL)
       {
	 color (3,1);            
	 gotoxy (35,15);                                     
	 cprintf ("NO SE PUEDE INSERTAR ");                /*MENSAJE*/
	 getch ();
       }
      else
      if (p_dobles == cab_dobles)
       {
	 nuevo_dobles = localizar_dobles;
	 nuevo_dobles->info_dobles= n;                     /*PROCESO*/
	 nuevo_dobles->ant_dobles = inicio_dobles->sig_dobles;
	 nuevo_dobles->sig_dobles = p_dobles;
	 q_dobles->ant_dobles = nuevo_dobles;
	 cab_dobles = nuevo_dobles;
       }
      else
       {
	 nuevo_dobles = localizar_dobles;
	 nuevo_dobles->info_dobles= n;                     /*PROCESO*/
	 nuevo_dobles->ant_dobles = q_dobles;
	 q_dobles->sig_dobles = nuevo_dobles;
	 nuevo_dobles->sig_dobles = p_dobles;
	 p_dobles->ant_dobles = nuevo_dobles;
	 if (q_dobles != NULL)
	 q_dobles->ant_dobles = nuevo_dobles;
       }
   }
/*=================================================================*/
/*========   PREGUNTA SI SE QUIERE INSERTAR  ANTES O DEPUES DE   ==*/        
/*========   UN NODO DADO, ENVIANDO POR PARAMETRO EL CONTENIDO   ==*/
/*=================================================================*/
void insertar_dobles(void)
 {
   int i, d, n;
   color (0,1);
   clrscr();
   cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");  /*CUADRO*/
   gotoxy (30,2);
   color (3,1);
   cprintf ("INSERCION LISTAS DOBLES<MED>");
   gotoxy (5,5);
   color (3,1);
   cprintf ("INSERTAR 1.ANTES 2.DESPUES: ");               /*MENSAJE*/
   gotoxy (35,5);
   scanf ("%d", &i);                                       /*CAPTURA*/
   gotoxy (5,7);
   color (3,1);
   cprintf ("EN EL NODO No: ");                            /*MENSAJE*/
   gotoxy (30,7);
   scanf ("%d", &d);                                       /*CAPTURA*/
   gotoxy (5,9);
   color (3,1);
   cprintf ("DATO DE NODO: ");                             /*MENSAJE*/
   gotoxy (30,9);
   scanf ("%d", &n);                                       /*CAPTURA*/
   if (i==1)
      insertar_antes_dobles (d, n);                        /*FUNCION*/
   else
   if (i==2)
      insertar_despues_dobles (d , n);                     /*FUNCION*/
 }                                                        
/*=================================================================*/
/*========       RETIRA UN NODO DADO DE UNA LISTA DOBLE          ==*/        
/*========                                                       ==*/
/*=================================================================*/
void retirar_dobles (void)
  {
    /*int n;*/
    int j = 1;
    int i;
    struct nodo_dobles *r_dobles;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("RETIRAR LISTAS DOBLES<MED>");
    gotoxy (5,5);                                            
    color (3,1);
    cprintf("DIGITE EL NUMERO DEL NODO A RETIRAR:");       /*MENSAJE*/
    gotoxy (45,5);
    scanf ("%d", &i);                                      /*CAPTURA*/
    r_dobles = cab_dobles;
    p_dobles = cab_dobles;
    q_dobles = cab_dobles;
    while (j != i )
     {
       r_dobles = p_dobles;
       p_dobles = r_dobles->sig_dobles;                    /*RECORRIDO*/
       q_dobles = p_dobles->sig_dobles; 
       j ++;
     }
    if (r_dobles == NULL)
     {
       color (3,1);
       gotoxy (35,15);
       cprintf(" LISTA VACIA\n");                          /*MENSAJE*/
       getch();
     } 
    else
    if (p_dobles == cab_dobles)
     {
	 cab_dobles = p_dobles->sig_dobles;
	 cab_dobles->ant_dobles = r_dobles->ant_dobles;    /*PROCESO*/
	 free (p_dobles);
	 if (cab_dobles->sig_dobles == cab_dobles)
	  {
	    cab_dobles = NULL;
	  } 
     }
    else
    {
	 r_dobles->sig_dobles = q_dobles;
	 q_dobles->ant_dobles = r_dobles;                  /*MENSAJE*/
	 /*n = p_dobles->info_dobles;*/
	 free (p_dobles);
    }
  }
/*--------------------   SIMPLES CIRCULARES  --------------------- */
/*=================================================================*/
/*========  CREAR UNA LISTA SIMPLE CIRCULAR, UTILIZA EL PROCESO  ==*/        
/*========   DE UNA LISTA SIMPLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void crear_simples_circ(void) 
  {
    crear_simple ();                                       /*FUNCION*/
    inicio_simple->sig_simple = q_simple;                 /*CIRCULAR*/
  }
/*=================================================================*/
/*========   INSERTA EN UNA LISTA SIMPLE CIRCULAR, UTILIZA EL PRC==*/        
/*========   DE UNA LISTA SIMPLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void insertar_simple_circ(void)
{ 
  insertar_simple();                                       /*FUNCION*/
  if (p_simple->sig_simple == cab_simple)
      inicio_simple = p_simple;                            /*CIRCULAR*/
  if (cab_simple->sig_simple == p_simple)
     inicio_simple->sig_simple = cab_simple;
}
/*=================================================================*/
/*======== RETIRA DE UNA LISTA SIMPLE CIRCULAR, UTILIZA EL PROC  ==*/        
/*========   DE UNA LISTA SIMPLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void retirar_simple_circ(void)
{ 
  retirar_simple();                                        /*FUNCION*/
  if (cab_simple->sig_simple == cab_simple)
      inicio_simple = cab_simple;
  else
  if (inicio_simple->sig_simple != cab_simple)
      inicio_simple->sig_simple = cab_simple;

}                                            

/*-------------------  DOBLES CIRCULARES  ------------------------ */
/*=================================================================*/
/*========  CREAR UNA LISTA DOBLES CIRCULAR, UTILIZA EL PROCESO  ==*/        
/*========   DE UNA LISTA SIMPLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void crear_dobles_circ(void) 
  {
    crear_dobles();                                        /*FUNCION*/
    inicio_dobles->sig_dobles = cab_dobles;                /*CIRCULAR*/
    cab_dobles->ant_dobles = inicio_dobles;                /*CIRCULAR*/
  }
/*=================================================================*/
/*======== INSERTA EN UNA LISTA DOBLES CIRCULAR, UTILIZA EL PROC ==*/        
/*========    DE UNA LISTA DOBLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void insertar_dobles_circ(void)
 { 
  insertar_dobles();                                       /*FUNCION*/
  if (cab_dobles == nuevo_dobles)
   {
      inicio_dobles->sig_dobles = cab_dobles;              /*CIRCULAR*/
      cab_dobles->ant_dobles = inicio_dobles;              /*CIRCULAR*/
   }
 }
/*=================================================================*/
/*========  RETIRA EN UNA LISTA DOBLES CIRCULAR, UTILIZA EL PRC ==*/        
/*========   DE UNA LISTA DOBLE, ATANDO CAB_SIG CON EL FINAL    ==*/
/*=================================================================*/
void retirar_dobles_circ(void)
 { 
   retirar_dobles();                                       /*FUNCION*/
   if (cab_dobles->sig_dobles == cab_dobles)
       inicio_dobles = cab_dobles;
   else
   if (inicio_dobles->sig_dobles != cab_dobles)
      inicio_dobles->sig_dobles = cab_dobles;              /*CIRCULAR*/
 }
/*=================================================================*/
/*===== POR LO VISTO ANTERIORMENTE CON LAS LISTAS SE PUEDEN ARMAR==*/        
/*===== LISTAS CIRCULARES TENIENDO EN CUENTA QUE SIMPRE SE DEBE  ==*/
/*=====         ATAR LA CABEZA CON EL FINAL DE LISTA.            ==*/
/*=================================================================*/

/*--------------------- COLAS COMPUESTAS --------------------------*/
/*=================================================================*/
/*========   CREAR UNA COLA COMPUESTA, CON DOS ELEMENTOS QUE     ==*/        
/*======== CORRESPONDEN A GUIA1 Y GUIA2, NO CAPTURA NINGUN DATO  ==*/
/*=================================================================*/
void crear_colas(void) 
  {
     int i, n;
     color (0,1);
     clrscr();
     cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");/*CUADRO*/
     gotoxy (30,2);
     color (3,1);
     cprintf ("CREACION COLAS COMPUESTAS<MED>");
     gotoxy (5,5); 
     cab1_colas = localizar_colas;
     cab1_colas->info_colas = -1;
     cab2_colas = localizar_colas;                         /*CREACION*/
     cab2_colas->info_colas = -2;
     guia1_colas = cab1_colas;
     guia2_colas = cab2_colas;
     cab1_colas->sig_colas = guia2_colas;
     cab2_colas->sig_colas = guia1_colas;
  }
/*=================================================================*/
/*========     IMPRIME UNA COLA COMPUESTA, CON ELEMENTOS QUE     ==*/        
/*======== CORRESPONDEN A GUIA1 Y GUIA2, CUYA INFO ES MENOR A 1  ==*/
/*=================================================================*/
void listar_colas (void)
  {
    int i = 1;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("IMPRESION COLAS COMPUESTAS<MED>");
    q_colas = guia1_colas;
    if (q_colas == NULL)
      {
       color (3,1);                                        /*MENSAJE*/
       cprintf ("COLA VACIA");
      }
    else
    {
      p_colas = guia1_colas;
      while (p_colas->sig_colas != cab2_colas->sig_colas)
      {
	gotoxy (5,(i * 2)+ 4);
	color (3,1);
	cprintf ("Nodo %d -> contenido= %d direccion =  %d siguiente = %d \n" , i, p_colas->info_colas, p_colas, p_colas->sig_colas);
	p_colas = p_colas->sig_colas;
	i++;
      }    
     gotoxy (5,(i * 2)+ 4);
     color (3,1);
     cprintf ("Nodo %d -> contenido= %d direccion =  %d siguiente = %d \n" , i, p_colas->info_colas, p_colas, p_colas->sig_colas);
     p_colas = p_colas->sig_colas;
     i++;
    }
    getch();
  }
/*=================================================================*/
/*========  INSERTA UN NODO EN UNA COLA COMPUESTA, BIEN SEA POR  ==*/        
/*========            DERECHA O POR IZQUIERDA                    ==*/
/*=================================================================*/
void insertar_colas(void) 
  {
    int i, n, c=0;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("INSERCION COLAS COMPUESTAS<MED>");
    gotoxy (5,5); 
    gotoxy (5,5);
    color (3,1);
    cprintf ("DIGITE DIR. A INSERTAR CREAR: 1.IZQ  2. DER ");/*MENSAJE*/
    gotoxy (5,35);
    scanf ("%d", &i);                                      /*CAPTURA*/
    gotoxy (5,8);
    color (3,1);
    cprintf ("DIGITE VALOR DEL NODO");                     /*MENSAJE*/
    gotoxy (35,8);
    scanf ("%d", &n);
    if (i==1)
    {
      nuevo_colas = localizar_colas;
      cab1_colas->sig_colas = nuevo_colas;                 /*PROCESO*/
      cab1_colas = nuevo_colas;                            /*IZQ*/
      nuevo_colas->sig_colas = guia2_colas;
      nuevo_colas->info_colas = n;
      c++;
    }
    if (i==2)
    {
      nuevo_colas = localizar_colas;
      cab2_colas->sig_colas = nuevo_colas;                 /*PROCESO*/
      cab2_colas= nuevo_colas;                             /*DER*/
      nuevo_colas->sig_colas = guia1_colas;
      nuevo_colas->info_colas = n;
      c++;
    }
  }
/*=================================================================*/
/*========  RETIRA UN NODO EN UNA COLA COMPUESTA, BIEN SEA POR   ==*/        
/*========             DERECHA O POR IZQUIERDA                   ==*/
/*=================================================================*/
void retirar_colas(void) 
  {
    int i, /*n,*/ c=0;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("RETIRO COLAS COMPUESTAS<MED>");
    gotoxy (5,5); 
    color (3,1);
    cprintf ("DIGITE DIR. A RETIRAR CREAR: 1.IZQ  2. DER ");/*MENSAJE*/
    gotoxy (5,35);
    scanf ("%d", &i);                                       /*CAPTURA*/
    if ((i==1) &&( guia1_colas->sig_colas != guia2_colas))
    {
      p_colas = guia1_colas->sig_colas;
      /*n = p_colas->info_colas;*/
      guia1_colas->sig_colas = p_colas->sig_colas;         /*PROCESO*/
      free (p_colas);                                      /*IZQ*/
      c--;
    }
    if ((i==2) && (guia2_colas->sig_colas != guia1_colas))
    {
      p_colas = guia2_colas->sig_colas;                    /*PROCESO*/
      /*n = p_colas->info_colas;*/                         /*DER*/
      guia2_colas->sig_colas = p_colas->sig_colas;
      free (p_colas);
      c--;
    }
  }

/*------------------------- BICOLAS -------------------------------*/
/*=================================================================*/
/*========   CREAR UNA BICOLA, INDICANDO CUAL ES GUIA1 Y CABEZA  ==*/        
/*========           GUIA1 ES DEJADA CON UN INFO = -1            ==*/
/*=================================================================*/
void crear_bicolas(void) 
  {
    int i, n, c=0;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("CREACION BICOLAS<MED>");
    gotoxy (5,5); 
    cab1_colas = localizar_colas;
    cab1_colas->info_colas = -1;                           /*CREAR GUIA*/
    guia1_colas = cab1_colas;
    gotoxy (5,8);
    color (3,1);                                                      
    cprintf ("DIGITE VALOR DEL NODO");                     /*MENSAJE*/
    gotoxy (35,8);
    scanf ("%d", &n);                                      /*CAPTURA*/
    nuevo_colas = localizar_colas;
    nuevo_colas->sig_colas = guia1_colas;                  /*PROCESO*/
    nuevo_colas->info_colas = n;
    cab1_colas->sig_colas = nuevo_colas;
    cab1_colas= nuevo_colas; 
    c++;
  }
/*=================================================================*/
/*======== IMPRIME UNA BICOLA, INDICANDO CUAL ES GUIA1 Y CABEZA  ==*/        
/*========                                                       ==*/
/*=================================================================*/
 void listar_bicolas(void)
  {
    int i = 1;
    color (0,1);
    clrscr();
    cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
    gotoxy (30,2);
    color (3,1);
    cprintf ("IMPRESION BICOLAS<MED>");
    q_colas = guia1_colas;
    if (q_colas == NULL)
       printf ("COLA VACIA");                              /*MENSAJE*/
    else
     {
       p_colas = guia1_colas;
       while (p_colas->sig_colas != cab1_colas->sig_colas)
	{
	  gotoxy (5,(i * 2)+ 4);
	  color (3,1);
	  cprintf ("Nodo %d -> contenido= %d direccion =  %d siguiente = %d \n" , i, p_colas->info_colas, p_colas, p_colas->sig_colas);
	  p_colas = p_colas->sig_colas;
	  i++;
	}                                                  /*PROCESO*/
       gotoxy (5,(i * 2)+ 4);
       color (3,1);
       cprintf ("Nodo %d -> contenido= %d direccion =  %d siguiente = %d \n" , i, p_colas->info_colas, p_colas, p_colas->sig_colas);
       p_colas = p_colas->sig_colas;
       i++;
     }
    getch();
  }
/*=================================================================*/
/*========          INSERTA UN NODO EN UNA BICOLA                ==*/        
/*========                                                       ==*/
/*=================================================================*/
void insertar_bicolas(void) 
  {
     int i, n, c=0;
     color (0,1);
     clrscr();
     cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³"); /*CUADRO*/
     gotoxy (30,2);
     color (3,1);
     cprintf ("INSERCION BICOLAS<MED>");
     gotoxy (5,5); 
     color (3,1);
     cprintf ("DIGITE DIR. A INSERTAR CREAR: 1.IZQ  2. DER: ");/*MENSAJE*/
     gotoxy (5,35);
     scanf ("%d", &i);                                     /*CAPTURA*/
     gotoxy (5,8);
     color (3,1);
     cprintf ("DIGITE VALOR DEL NODO");                    /*MENSAJE*/
     gotoxy (35,8);
     scanf ("%d", &n);                                     /*CAPTURA*/
     if (i==1)
      {
	nuevo_colas = localizar_colas;
	nuevo_colas->sig_colas = guia1_colas->sig_colas;   /*PROCESO*/
	guia1_colas->sig_colas = nuevo_colas;              /*IZQ*/
	nuevo_colas->info_colas = n;
	c++;
      }
     if (i==2)
      {
	nuevo_colas = localizar_colas;
	nuevo_colas->sig_colas = cab1_colas->sig_colas;    /*PROCESO*/
	cab1_colas->sig_colas = nuevo_colas;               /*DER*/
	nuevo_colas->info_colas = n;
	cab1_colas = nuevo_colas;
	c++;
      }
  }
/*=================================================================*/
/*========        RETIRA UN ELEMENTO DE UNA BICOLA               ==*/        
/*========                   ATENDER                             ==*/
/*=================================================================*/
void retirar_bicolas(void) 
  {
     int i, /* n,*/ c=0;
     color (0,1);
     clrscr();
     cuadro (1, 1, 24, 80, "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");/*MENSAJE*/
     gotoxy (30,2);
     color (3,1);
     cprintf ("RETIRO BICOLAS<MED>");
     gotoxy (5,5); 
     color (3,1);
     cprintf ("DIGITE DIR. A RETIRAR: 1.IZQ  2. DER: ");   /*MENSAJE*/
     gotoxy (5,35);
     scanf ("%d", &i);
     if ((i==1) && (guia1_colas->sig_colas != guia1_colas))
      {
	p_colas = guia1_colas->sig_colas;                  /*PROCESO*/
	/*n = p_colas->info_colas;*/                       /*IZQ*/
	guia1_colas->sig_colas = p_colas->sig_colas;
	free (p_colas);
	c--;
      }
     if ((i==2) && (guia1_colas->sig_colas != guia1_colas))
      {
	p_colas = guia1_colas;                             /*PROCESO*/
	q_colas = guia1_colas;                             /*DER*/
	while (p_colas != cab1_colas)
	 {
	   q_colas = p_colas;
	   p_colas = p_colas->sig_colas;
	 }
	/*n = cab1_colas->info_colas;*/
	free (cab1_colas);
	q_colas->sig_colas = cab1_colas->sig_colas; 
	cab1_colas = q_colas;
	c--;
      }
  }
/*=================================================================*/
/*========   EJECUTA LOS PROCEDIMIENTOS QUE EL USUARIO ORDENA    ==*/        
/*========                                                       ==*/
/*=================================================================*/
void ejecuta_opciones_ordenar (rta, a)
 {
  switch (rta)
  {
    case 0:                                      /*OPCION CREAR*/
     {
       if (a == 0)                               /*LISTAS SIMPLES*/
	 crear_simple();
       if (a == 1)                               /*LISTAS DOBLES*/
	 crear_dobles();
       if (a==2)                                 /*LISTAS SIN CIR*/
	 crear_simples_circ();
       if (a==3)                                 /*LISTAS DOB CIR*/
	 crear_dobles_circ ();
       if (a==4)                                 /*COLAS*/
	 crear_colas();
       if (a==5)                                 /*BICOLAS*/
	 crear_bicolas();
       break;
     }                                                            
    case 1:                                      /*OPCION INSERTAR*/
     {
       if (a == 0)                               /*LISTAS SIMPLES*/
	 insertar_simple();
       if (a == 1)                               /*LISTAS DOBLES*/
	 insertar_dobles();
       if (a==2)                                 /*LISTAS SIM CIR*/
	 insertar_simple_circ ();
       if (a == 3)                               /*LISTAS DOB CIR*/
	 insertar_dobles_circ ();
       if (a==4)                                 /*COLAS*/
	 insertar_colas();
       if (a==5)                                 /*BICOLAS*/
	 insertar_bicolas();
       break;
     }
    case 2:                                     /*OPCION RETIRAR*/
     {
       if (a == 0)                              /*LISTAS SIMPLES*/
	 retirar_simple();
       if (a == 1)                              /*LISTAS DOBLES*/
	 retirar_dobles();
       if (a==2)                                /*LISTAS SIN CIR*/
	 retirar_simple_circ ();
       if (a==3)                                /*LISTAS DOB CIR*/
	 retirar_dobles_circ ();
       if (a==4)                                /*COLAS*/
	 retirar_colas(); 
       if (a==5)                                /*BICOLAS*/
	 retirar_bicolas();
       break;
     }
    case 3:                                     /*OPCION LISTAR*/
     {
       if (a == 0 || a== 2)                     /*LISTAS SIN,SIN CIR*/
	 listar_simple();
       if (a == 1|| a== 3)                      /*LISTAS DOB,DOB CIR*/
	 listar_dobles();
       if (a == 4)                              /*COLAS*/
	 listar_colas();
       if (a == 5)                              /*BICOLAS*/
	 listar_bicolas();
       break;
     }
  }
 }
/*=================================================================*/
/*========   PRESENTA LAS OPCIONES QUE EL USUARIO PUEDE ORDENAR  ==*/        
/*========                EN EL MENU DE CASCADA                  ==*/
/*=================================================================*/
void opciones_ordenar (a,col)
 {
    register int i;
    cuadro (5 ,col, 10, col + 11,  "Ú""Ä""¿""³""¿""³""Ù""Ä""À""³");
    color (0,1);
    for (i =0; i<=3 ; i++)
       {
	 gotoxy (col+ 1, i + 6);
	 cprintf ("%s" , orden [i]);
       }
    color (7,0);
    gotoxy (col + 1, a + 6);
    cprintf ("%s" , orden [a]);
 }
/*=================================================================*/
/*========         REALIZA LA CAPTURA DE LAS TECLAS              ==*/        
/*========                                                       ==*/
/*=================================================================*/
void menu_ordenamientos (a, col)
 {
   int opc=0;
   int tcl =0;
   while (tcl!= 27)
    {
      opciones_ordenar (opc, col);
      while (tcl!= 13 && tcl!= 27)
       {
	aceptar2 (&opc, &tcl);
	if (tcl !=13 && tcl!=27)
	 {
	   color (0,1);
	   opciones_ordenar (opc, col);
	 }
       }
      if (tcl==13)
       {
	 ejecuta_opciones_ordenar (opc, a);
	 color (0,1);
	 pintar_pantalla ();
	 visualizar (a);
	 tcl=0;
       }
    }
 }
/*=================================================================*/
/*========      EJECUTA LAS OPCIONES DEL MENU PRINCIPAL          ==*/        
/*========   ENVIANDO COMO PARAMETRO LA OPCION DEL MENU P/PAL    ==*/
/*=================================================================*/
void ejecutar_opciones (a)
 {
   switch (a)
   {
    case 0:
     {
	menu_ordenamientos (a, columnas [a]);
	break;
     }
    case 1:
     {
	menu_ordenamientos (a, columnas [a]);
	break;
     }
    case 2:
     {
	menu_ordenamientos (a, columnas [a]);
	break;
     }
    case 3:
     {
	menu_ordenamientos (a, columnas [a]);
	break;
     }
    case 4:
     {
	menu_ordenamientos (a, columnas [a]);
	break;
     }
    case 5:
     {
       menu_ordenamientos (a, columnas [a]);
       break;
     }
    case 6:
     {
       menu_ordenamientos (a, columnas [a]);
       break;
     }
    case 7:
     {
       break;
     }
   }
 }
/*=================================================================*/
/*========     ESTA RUTINA CORRESPONDE AL PROGRAMA PINCIPAL      ==*/        
/*========                 INICIO (MAIN)                         ==*/
/*=================================================================*/
void main (void)
 {
    int opc1=0;
    int tcl = 0;
    pintar_pantalla ();
    color (0,1);
    visualizar (opc1);
    while (tcl!= 27)
     {
      while (tcl!= 13 && tcl!= 27)
       {
	 aceptar (&opc1, &tcl);
	 if (tcl !=13 && tcl!=27)
	 { 
	   color (0,1);
	   visualizar (opc1);
	 }
       }
      if (tcl==13)
       {
	  ejecutar_opciones (opc1);
	  color (0,1);
	  pintar_pantalla ();
	  visualizar (opc1);
	  tcl=0;
       }
 }
 color(0,1);
 clrscr ();
}