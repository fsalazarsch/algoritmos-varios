void reg_quirofano()
{
  struct quirofano temp;
  char c;
   do
  {
    textbackground(1);
    clrscr();
    cuadro(1,15,2,2,79,24);
    textcolor(15);
    gotoxy(30,3);cprintf("REGISTRO DE QUIROFANOS");
    gotoxy(10,6);cprintf("NUMERO DE QUIROFANO: ");
    gotoxy(33,6);scanf("%d",&temp.quirofano);
    gotoxy(10,10);cprintf("MAXIMO DE PACIENTES: ");
    gotoxy(31,10);scanf("%d",&temp.max_paci);
     gotoxy(10,21);cprintf("Desea seguir registrando quirofanos s/n:");
     insertar_quirofanos(temp);
     do
      {
      c=getche();
      c = toupper(c);
      }while((c=='S')&&(c=='N'));
      if(c=='N')c=27;

     }while(c!=27);
     gotoxy(18,23);cprintf("DIGITE CUALQUIER TECLA PARA SALIR AL MENU");

 }

void insertar_quirofanos(struct quirofano temp)
{
     struct quirofano *preg, *nuevo;
     preg = listaq;
     temp.cantidad_paci=0;
     if(preg == NULL)
      {
       nuevo =local;
       nuevo->quirofano=temp.quirofano;
       nuevo->max_paci=temp.max_paci;
       nuevo->cantidad_paci=temp.cantidad_paci;
       nuevo->siguiente = NULL;
       listaq=nuevo;
      }
      else
      {
	 while(preg->siguiente != NULL)
	 preg = preg->siguiente;
	 nuevo = local;
	 nuevo->quirofano=temp.quirofano;
	 nuevo->max_paci=temp.max_paci;
	 nuevo->cantidad_paci=temp.cantidad_paci;
	 nuevo->siguiente = NULL;
	 preg->siguiente = nuevo;
    }
}


