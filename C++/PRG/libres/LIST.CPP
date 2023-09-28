#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  NULL 0
struct listael{
	     ele[40];
	     sstruct lisatael *sig;
	     };
	     typedef struct listael nodo;//decla del tipo de estructura
	     int menu(void);            //protipo de funcion
	     void crear(nodo *pt);
	     nodo *inser(nodo *pt);
	     nodo *elimi(nodo *pt);
	     void mostrar(nodo *pt);
	     main()
	     nodo *prin;
	     int eleccion;
	     do {
		 eleccion= menu();
		 switch(eleccion)
		       {
		       case 1: //punt al prin de la list
		       int eleccion;
		       do

			{ eleccion= menu(),
			switch(eleccion) {
			case1:  //crear la lista enlazada*/
			    prin= (nodo *) malloc(sizeof(nodo)); //reserva de
								   espacio para
								   el    primer
								   nodo*/
			   crear(prin);
			   printf("/n");
			   continue;
		      case 2:  // a¤adir un componente //
			   prin= insertar (prin);
			   printf("/n");
			   mostrar (prin);
			   continue;

		      case 3:  // borrar un componente //
			   prin= eliminar (prin);
			   printf ("n/");
			   mostrar (prin);
			   continue;

		      default:  // finalizar//
			   printf ("Fin de las operaciones/n");
		      }
	      } while (eleccion != 4));
	   }

	   int menu(void)   //generar el menu principal//
	   {
	     int eleccion;
	     do {
		  printf("/nMenu principal: /n");
		  printf("  1 - CREAR la list enlazada/n");
		  printf("  2 - A¥ADIR un componente/n");
		  printf("  3 - BORRAR un componente/n");
		  printf("  4 - FIN/n");
		  printf("por favor, introduzca su eleccion (1,2,3 o 4) ->");
		  scanf("%d", &eleccion);
		  if (eleccion< 1   eleccion > 4)
		      printf("/nERROR - por favor,  intentelo de nuevo/n");
	      } while (eleccion < 1   eleccion >4);
	      PRINTF("/n");
	      return(eleccion);
	    }

	    void crear (nodo *registro)   //crear una list enlazada //

	    // el argumento apunta al nodo actual //
	    {
	    printf("Dato (escribir /'FIN/' para terminar) : ");
	    scanf("%[ /n]", registro-<elem);

	    if (strcmp(registro -<elem, "FIN") == 0 )
		registro -< sig = NULL;
	    else{
	       // reservar espacio para el sigte nodo//
	       registro-<sig = (nodo *)malloc(sizeof(nodo));

	       // crear el sgte nodo //
	       crear(registro-<sig);
	   }
	   return;
	 }

	 void mostrar (nodo *registro)  //mostrar la list enlazada //
	 // el argmto apunta al nodo actual //
	 {
	    if (registro-<sig != NULL) {
	       printf("%s/n", registro -<elem);  //mostrar este dato //
	       mostrar(registro-<sig);           //tomar el sgte elemento//
	    }
	    return;
	  }
	  nodo  *insertar (nodo *primero)  //a¤ade un componentea la list en-
					   lazada; devuelve un punte al prin-
					   cipio de la list modificada  //
	  // el argumento apunta al primer nodo  //
	  {
	    nodo *localizar (nodo *, char[]);  //declaracion de funcion//
	    nodo *nuevoregistro;               // puntero al nuevo nodo//
	    nodo *marca;                       // puntero al nodo anterior al
						  buscado//
	    char nuevodato[40];                // dato nuevo //
	    char objetivo[40];                 // dato  sgte a  la nueva
						  entrada //
	    printf("Nuevo dato: ");
	    scanf(" %[ /n]", nuevodato);
	    printf ("colocar delante de (escribir/ïFIN/ïsi es el ultimo):");
	    scanf(" % [ /n]",objetivo);
	    if (strcmp(primero-<elem, objetivo) ==o) {
	       //el nuevo nodoes el primero de la lista//
	       // reserva espacio para el nuevo nodo//
	       nuevoregistro = (nodo *) malloc(sizeof(nodo));

	       // asignar el nuevo dato a nuevoregistro-<elem); //
		  strcpy(nuevoregistro-<elem, nuevodato);

	       //asignar el puntero actual a nuevoregistro-<sig //
		nuevoregistro-< = primero;

	       // el nuevo puntero se convierte en el princpio de la list//
	       primero =nuevoregistro;
	   }

	   else





		      switch (eleccion) {





