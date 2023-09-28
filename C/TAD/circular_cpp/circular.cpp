// Lista circular en C++
// (C) Agosto 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() { actual = NULL; }
    ~lista();
    
    void Insertar(int v);
    void Borrar(int v);
    bool ListaVacia() { return actual == NULL; }
    void Mostrar();
    void Siguiente();
    bool Actual() { return actual != NULL; }
    int ValorActual() { return actual->valor; }
    
   private:
    pnodo actual;
};

lista::~lista()
{
   pnodo nodo;

   // Mientras la lista tenga más de un nodo
   while(actual->siguiente != actual) {
      // Borrar el nodo siguiente al apuntado por lista
      nodo = actual->siguiente;
      actual->siguiente = nodo->siguiente;
      delete nodo;
   }
   // Y borrar el último nodo
   delete actual;
   actual = NULL;
}

void lista::Insertar(int v)
{
   pnodo Nodo;

   // Creamos un nodo para el nuevo valor a insertar
   Nodo = new nodo(v);

   // Si la lista está vacía, la lista será el nuevo nodo
   // Si no lo está, insertamos el nuevo nodo a continuación del apuntado
   // por lista
   if(actual == NULL) actual = Nodo;
   else Nodo->siguiente = actual->siguiente;
   // En cualquier caso, cerramos la lista circular
   actual->siguiente = Nodo;
}

void lista::Borrar(int v)
{
   pnodo nodo;

   nodo = actual;

   // Hacer que lista apunte al nodo anterior al de valor v
   do {
      if(actual->siguiente->valor != v) actual = actual->siguiente;
   } while(actual->siguiente->valor != v && actual != nodo);
   // Si existe un nodo con el valor v:
   if(actual->siguiente->valor == v) {
      // Y si la lista sólo tiene un nodo
      if(actual == actual->siguiente) {
         // Borrar toda la lista
         delete actual;
         actual = NULL;
      }
      else {
         // Si la lista tiene más de un nodo, borrar el nodo  de valor v
         nodo = actual->siguiente;
         actual->siguiente = nodo->siguiente;
         delete nodo;
      }
   }
}

void lista::Mostrar()
{
   pnodo nodo = actual;

   do {
      cout << nodo->valor << "-> ";
      nodo = nodo->siguiente;
   } while(nodo != actual);

   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

int main()
{
   lista Lista;
   
   Lista.Insertar(20);
   Lista.Insertar(10);
   Lista.Insertar(40);
   Lista.Insertar(30);
   Lista.Insertar(60);

   Lista.Mostrar();

   cout << "Lista de elementos:" << endl;
   Lista.Borrar(10);
   Lista.Borrar(30);

   Lista.Mostrar();

   cin.get();
   return 0;
}
