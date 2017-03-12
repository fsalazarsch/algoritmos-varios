/*
Sistema experto basico de proposito general que ofrece multiples soluciones y ademas muestra el razonamiento seguido.
 Basado en el fuente incluido en el libro 'Utilizacion de C en inteligencia
  	artificial' de Herbert Schildt, y publicado por Osborne/McGrawHill

 EXPERTO
 */

#include "stdio.h"
#include "alloc.h"

#define MAX 100

struct atributo {
	char atrib [80];
	struct atributo *siguiente;
	} at;

struct objeto {
	char nombre [80];
	struct atributo *alista;	/* Apuntar a la lista de atributos */
	} ob;

struct objeto_rechazado {
	char nombre [80];
	char atrib [80];		/* Atributo que causo el rechazo */
	char condicion;			/* Era necesario o se descarto por
					   una deduccion previa */
	} rj;

struct objeto_rechazado r_base [MAX];
struct objeto base_c [MAX];		/* Base de conocimiento */

int n_pos = -1;				/* Posicion en la base de
					   conocimiento */
int r_pos = -1; 			/* Posicion en la lista de
					   rechazos */

struct atributo *si, *no;		/* listas de tiene y no tiene */
struct atributo	*siguientesi, *siguienteno;

main ()
{
	char ch;

	no=si=0x00;
	do {
		libera_lista();
		ch=menu();
		switch(ch) {
			case 'i': introduce();
				  break;
			case 'p': pregunta();
				  break;
			case 's': salva();
				  break;
			case 'c': carga();
				  break;
		}
	} while (ch != 'x');
}

libera_lista()
{
	struct atributo *p;

	while (si) {
		p = si -> siguiente;
		free (si);
		si = p;
	}

	while (no) {
		p = no -> siguiente;
		free (no);
		no = p;
	}
}

/*
 * Ahora codificamos la funcion encargada de crear la base de conocimiento
 */

introduce()
{
	int t;
	struct atributo *p, *anterior_p;

	for (;;) {
		t = obtiene_siguiente();
		if (t == -1) {
			printf ("Fuera de la lista.\n");
			return;
		}
		printf ("Nombre del objeto: ");
		gets (base_c[t].nombre);

		if (!*base_c[t].nombre) {
			n_pos--;
			break;
		}

		p = (struct atributo *) malloc(sizeof(at));
		if (p == 0x00) {
			printf ("No hay memoria suficiente.\n");
			return;
		}
		base_c[t].alista = p;
		printf ("Introduce los atributos del objeto. ENTER para salir\n");
		for (;;) {
			printf (">> ");
			gets (p->atrib);
			if (!p->atrib[0]) break;
			anterior_p = p;
			p->siguiente = (struct atributo *) malloc(sizeof(at));
			p = p->siguiente;
			p->siguiente = 0x00;
			if (p == 0x00) {
				printf ("No hay memoria suficiente.\n");
				return;
			}
		}
		anterior_p->siguiente = 0x00;
	}
}

/*
 * Ahora codificamos la funcion encargada de realizar las preguntas al
 * Sistema Experto.
 */

pregunta ()
{
	int t;
	char ch;
	struct atributo *p;

	for (t=0;t<=n_pos;t++) {
		p = base_c[t].alista;
		if (intenta(p, base_c[t].nombre)) {
			printf ("%s concuerda con la actual descripcion\n", base_c[t].nombre);
			printf ("sigo (S/N): ");
			ch = tolower(getche());
			printf ("\n");
			if (ch == 'n') return;
		}
	}
	printf ("No se ha(n) encontrado (mas) objeto(s)\n");
}

/*
 * Esta funcion se encarga de comprobar un objeto.
 */

intenta (struct atributo *p, char *ob)
{
	char respuesta;
	struct atributo *a, *t;

	if (!sigueno(p)) return 0;
	if (!siguesi(p)) return 0;

	while (p) {
		if (preg (p->atrib)) {
			printf ("es/ha/tiene %s? ", p->atrib);
			respuesta = tolower(getche());
			printf ("\n");

			a = (struct atributo *) malloc(sizeof(at));
			if (!a) {
				printf ("No hay memoria suficiente.\n");
				return;
			}
			a->siguiente = 0x00;
			switch(respuesta) {
				case 'n': strcpy (a->atrib, p->atrib);
					  if (!no) {
						no = a;
						siguienteno = no;
					  }
					  else {
						siguienteno->siguiente = a;
						siguienteno = a;
					  }
					  return 0;
				case 's': strcpy (a->atrib,p->atrib);
					  if (!si) {
						si = a;
						siguientesi = si;
					  }
					  else {
						siguientesi->siguiente = a;
						siguientesi = a;
					  }
					  p = p->siguiente;
					  break;
				case 'p': razonando (ob);
					  break;
			}
		}
		else p = p->siguiente;
	}
	return 1;
}

/*
 * Busca un atributo que no tenga el objeto y que este en la lista
 */


sigueno (struct atributo *p)
{
	struct atributo *a, *t;
	a = no;
	while (a) {
		t = p;
		while (t) {
			if (!strcmp(t->atrib,a->atrib))
				return 0;
			t = t->siguiente;
		}
		a = a->siguiente;
	}
	return 1;
}

/*
 * Comprueba que tenga los atributos seleccionados
 */

siguesi (struct atributo *p)
{
	struct atributo *a, *t;
	char ok;

	a = si;
	while (a) {
		ok = 0x00;
		t = p;
		while (t) {
			if (!strcmp(t->atrib,a->atrib))
				ok = 0x01;
			t = t->siguiente;
		}
		if (!ok) return 0;
		a = a->siguiente;
	}
	return 1;
}

/*
 * Comprueba si el atributo se pregunto con anterioridad
 */

preg (char *atrib)
{
	struct atributo *p;

	p = si;
	while (p && strcmp(atrib, p->atrib))
		p = p->siguiente;

	if (!p) return 1;
	else return 0;
}

/*
 * Esta funcion muestra el motivo por el que se sigue una determinada linea
 * de conocimiento.
 */

 razonando (char *ob)
 {
	struct atributo *t;
	int i;

	printf ("Intentando %s\n", ob);
	if (si)
		printf ("es/tiene/ha :\n");
	t = si;
	while (t) {
		printf ("%s\n", t->atrib);
		t = t->siguiente;
	}
	if (no)
		printf ("No es/tiene/ha :\n");
	t = no;
	while (t) {
		printf ("%s\n", t->atrib);
		t = t->siguiente;
	}

	for (i=0;i<=r_pos;i++) {
		printf ("%s rechazado porque ", r_base[i].nombre);
		if (r_base[i].condicion == 'n')
			printf ("%s no es un atributo.\n", r_base[i].atrib);
		else
			printf ("%s es un atributo requerido.\n", r_base[i].atrib);
	}
 }

 /*
  * Situar el objeto rechazado en la base de datos
  */

rechaza (char *ob, char *at, char cond)
{
	r_pos++;

	strcpy(r_base[r_pos].nombre, ob);
	strcpy(r_base[r_pos].atrib, at);
	r_base[r_pos].condicion = cond;
}

/*
 * Conseguir el siguiente indice libre del array de la base de conocimiento
 */

obtiene_siguiente()
{
	n_pos++;
	if (n_pos < MAX) return n_pos;
	else return -1;
}

/*
 * Aqui va la codificacion del menu de opciones
 */

menu()
{
	char ch;

	printf ("(I)ntroduce (P)regunta (S)alva (C)arga e(X)it\n");
	do {
		printf ("Selecciona una opcion: ");
		ch = tolower(getche());
	} while (!esta_en (ch, "ipscx"));
	printf ("\n");
	return ch;
}

/*
 * Salvar la base de conocimiento
 */

salva ()
{
	int t, x;
	struct atributo *p;
	FILE *fp;

	if ((fp = fopen("experto.dat", "w")) == 0) {
		printf ("No puedo crear el archivo\n");
		return;
	}
	printf ("Salvando la base de conocimientos\n");

	for (t=0;t<=n_pos;++t) {
		for (x=0;x<sizeof(base_c[t].nombre);x++)
			putc (base_c[t].nombre[x], fp);
		p = base_c[t].alista;
		while (p) {
			for (x=0;x<sizeof(p->atrib);x++)
				putc(p->atrib[x], fp);
			p = p->siguiente;
		}
		for (x=0;x<sizeof(p->atrib);x++)
			putc ('\0', fp);
	}
	putc (0, fp);
	fclose (fp);
}

/*
 * Cargar una base de conociminto previamente almacenada
 */

carga()
{
	int t, x;
	struct atributo *p, *anterior_p;
	FILE *fp;

	if ((fp = fopen("experto.dat", "r")) == 0) {
		printf ("No puedo abrir el archivo.\n");
		return;
	}
	printf ("Cargando la base de conocimientos\n");

	ini_basec();

	for (t=0;t<MAX;++t) {
		if ((base_c[t].nombre[0] = getc(fp)) == 0)
			break;
		for (x=1;x<sizeof(base_c[t].nombre);x++)
			base_c[t].nombre[x]=getc(fp);
		base_c[t].alista = (struct atributo *) malloc(sizeof(at));
		if (!base_c[t].alista) {
			printf ("No hay memoria suficiente.\n");
			break;
		}

		base_c[t].alista = (struct atributo *) malloc(sizeof(at));
		p = base_c[t].alista;
		if (!p) {
			printf ("No hay memoria suficiente.\n");
			return;
		}
		for (;;) {
			for (x=0;x<sizeof(p->atrib);x++)
				p->atrib[x]=getc(fp);

			if (!p->atrib[0]) {
				anterior_p->siguiente=0x00;
				break;
			}

			p->siguiente = (struct atributo *) malloc(sizeof(at));
			if (!p->siguiente) {
				printf ("No hay memoria suficiente.\n");
				break;
			}
			anterior_p = p;
			p = p->siguiente;
		}
	}
	fclose (fp);
	n_pos = t - 1;
}

/*
 * Funcion para inicializar la base de conocimiento
 */

ini_basec()
{
	int t;
	struct atributo *p, *p2;

	for (t=0;t<=n_pos;t++) {
		p = base_c[t].alista;
		while (p) {
			p2 = p;
			free (p);
			p = p2->siguiente;
		}
	}
}

esta_en (char ch, char *s)
{
	while (*s)
		if (ch == *s++)
			return 1;
	return 0;
}
