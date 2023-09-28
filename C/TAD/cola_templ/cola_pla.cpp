// Cola en C++ con palntillas
// (C) Mayo 2001, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
#include "CCadena.h"
using namespace std;

template<class TIPO> class cola;

template<class TIPO>
class nodo {
   public:
    nodo(TIPO v, nodo<TIPO> *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    TIPO valor;
    nodo<TIPO> *siguiente;

   friend class cola<TIPO>;
};

template<class TIPO>
class cola {
   public:
    cola() : primero(NULL), ultimo(NULL) {}
    ~cola();

    void Anadir(TIPO v);
    TIPO Leer();

   private:
    nodo<TIPO> *primero, *ultimo;
};

template<class TIPO>
cola<TIPO>::~cola()
{
   while(primero) Leer();
}

template<class TIPO>
void cola<TIPO>::Anadir(TIPO v)
{
   nodo<TIPO> *nuevo;

   /* Crear un nodo nuevo */
   /* Este ser� el �ltimo nodo, no debe tener siguiente */
   nuevo = new nodo<TIPO>(v);
   /* Si la cola no estaba vac�a, a�adimos el nuevo a continuaci�n de ultimo */
   if(ultimo) ultimo->siguiente = nuevo;
   /* Ahora, el �ltimo elemento de la cola es el nuevo nodo */
   ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo */
   if(!primero) primero = nuevo;
}

template<class TIPO>
TIPO cola<TIPO>::Leer()
{
   nodo<TIPO> *Nodo; /* variable auxiliar para manipular nodo */
   TIPO v;      /* variable auxiliar para retorno */

   /* Nodo apunta al primer elemento de la pila */
   Nodo = primero;
   if(!Nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la direcci�n del segundo nodo */
   primero = Nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = Nodo->valor;
   /* Borrar el nodo */
   delete Nodo;
   /* Si la cola qued� vac�a, ultimo debe ser NULL tambi�n*/
   if(!primero) ultimo = NULL;
   return v;
}

int main()
{
   cola<int> iCola;
   cola<float> fCola;
   cola<double> dCola;
   cola<char> cCola;
   cola<Cadena> sCola;

   // Prueba con <int>
   iCola.Anadir(20);
   cout << "A�adir(20)" << endl;
   iCola.Anadir(10);
   cout << "A�adir(10)" << endl;
   cout << "Leer: " << iCola.Leer() << endl;
   iCola.Anadir(40);
   cout << "A�adir(40)" << endl;
   iCola.Anadir(30);
   cout << "A�adir(30)" << endl;
   cout << "Leer: " << iCola.Leer() << endl;
   cout << "Leer: " << iCola.Leer() << endl;
   iCola.Anadir(90);
   cout << "A�adir(90)" << endl;
   cout << "Leer: " << iCola.Leer() << endl;
   cout << "Leer: " << iCola.Leer() << endl;

   // Prueba con <float>
   fCola.Anadir(20.01);
   cout << "A�adir(20.01)" << endl;
   fCola.Anadir(10.02);
   cout << "A�adir(10.02)" << endl;
   cout << "Leer: " << fCola.Leer() << endl;
   fCola.Anadir(40.03);
   cout << "A�adir(40.03)" << endl;
   fCola.Anadir(30.04);
   cout << "A�adir(30.04)" << endl;
   cout << "Leer: " << fCola.Leer() << endl;
   cout << "Leer: " << fCola.Leer() << endl;
   fCola.Anadir(90.05);
   cout << "A�adir(90.05)" << endl;
   cout << "Leer: " << fCola.Leer() << endl;
   cout << "Leer: " << fCola.Leer() << endl;

   // Prueba con <double>
   dCola.Anadir(0.0020);
   cout << "A�adir(0.0020)" << endl;
   dCola.Anadir(0.0010);
   cout << "A�adir(0.0010)" << endl;
   cout << "Leer: " << dCola.Leer() << endl;
   dCola.Anadir(0.0040);
   cout << "A�adir(0.0040)" << endl;
   dCola.Anadir(0.0030);
   cout << "A�adir(0.0030)" << endl;
   cout << "Leer: " << dCola.Leer() << endl;
   cout << "Leer: " << dCola.Leer() << endl;
   dCola.Anadir(0.0090);
   cout << "A�adir(0.0090)" << endl;
   cout << "Leer: " << dCola.Leer() << endl;
   cout << "Leer: " << dCola.Leer() << endl;

   // Prueba con <char>
   cCola.Anadir('x');
   cout << "A�adir(\'x\')" << endl;
   cCola.Anadir('y');
   cout << "A�adir(\'y\')" << endl;
   cout << "Leer: " << cCola.Leer() << endl;
   cCola.Anadir('a');
   cout << "A�adir(\'a\')" << endl;
   cCola.Anadir('b');
   cout << "A�adir(\'b\')" << endl;
   cout << "Leer: " << cCola.Leer() << endl;
   cout << "Leer: " << cCola.Leer() << endl;
   cCola.Anadir('m');
   cout << "A�adir(\'m\')" << endl;
   cout << "Leer: " << cCola.Leer() << endl;
   cout << "Leer: " << cCola.Leer() << endl;

   // Prueba con <Cadena>
   sCola.Anadir("Hola");
   cout << "A�adir(\"Hola\")" << endl;
   sCola.Anadir("somos");
   cout << "A�adir(\"somos\")" << endl;
   cout << "Leer: " << sCola.Leer() << endl;
   sCola.Anadir("programadores");
   cout << "A�adir(\"programadores\")" << endl;
   sCola.Anadir("buenos");
   cout << "A�adir(\"buenos\")" << endl;
   cout << "Leer: " << sCola.Leer() << endl;
   cout << "Leer: " << sCola.Leer() << endl;
   sCola.Anadir("!!!!");
   cout << "A�adir(\"!!!!\")" << endl;
   cout << "Leer: " << sCola.Leer() << endl;
   cout << "Leer: " << sCola.Leer() << endl;

   cin.get();
   return 0;
}

