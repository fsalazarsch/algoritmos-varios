// Cola doblemente enlazada en C++
// (C) Septiembre 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

class nodo {
   public:
    nodo(int v, nodo *sig = 0, nodo *ant = 0) :
       valor(v), siguiente(sig), anterior(ant) {}

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
        
   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
    lista() : plista(0) {}
    ~lista();
    
    void Insertar(int v);
    void Borrar(int v);
    bool ListaVacia() { return plista == 0; } 
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != 0; }
    int ValorActual() { return plista->valor; }
    
   private:
    pnodo plista;
};

lista::~lista()
{
   pnodo aux;
   
   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}

void lista::Insertar(int v)
{
   pnodo nuevo;
 
   Primero();
   // Si la lista est� vac�a
   if(ListaVacia() || plista->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodo(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el �ltimo elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
      // Creamos un nuevo nodo despu�s del nodo actual
      nuevo = new nodo(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void lista::Borrar(int v)
{
   pnodo nodo;
   
   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   if(!nodo || nodo->valor != v) return;
   // Borrar el nodo 
   
   if(nodo->anterior) // no es el primer elemento 
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el �ltimo nodo
      nodo->siguiente->anterior = nodo->anterior;
   
   if(nodo == plista) // Evitar borrar nodo de entrada
     if(plista->siguiente) plista = plista->siguiente;
     else if(plista->anterior) plista = plista->anterior;
     else plista = 0; // Estamos borrando el �nico nodo
   delete nodo;
}

void lista::Mostrar(int orden)
{
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->siguiente;
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(plista && plista->siguiente) plista = plista->siguiente;
}

void lista::Anterior()
{
   if(plista && plista->anterior) plista = plista->anterior;
}

void lista::Primero()
{
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo()
{
   while(plista && plista->siguiente) plista = plista->siguiente;
}

int main()
{
   lista Lista;
   
   Lista.Insertar(20);
   Lista.Insertar(10);
   Lista.Insertar(40);
   Lista.Insertar(30);
   Lista.Insertar(50);
   Lista.Insertar(60);

   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

   Lista.Primero();
   cout << "Primero: " << Lista.ValorActual() << endl;
   
   Lista.Ultimo();
   cout << "Ultimo: " << Lista.ValorActual() << endl;
   
   Lista.Borrar(20);
   Lista.Borrar(10);
   Lista.Borrar(15);
   Lista.Borrar(45);
   Lista.Borrar(60);
   Lista.Borrar(40);
   
   Lista.Mostrar(ASCENDENTE);
   Lista.Mostrar(DESCENDENTE);

   cin.get();
   return 0;
}
