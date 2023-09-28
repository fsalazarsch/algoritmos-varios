// Plantilla de Arbol AVL en C++
// (C) Mayo 2002, Salvador Pozo
// C con Clase: http://c.conclase.net

#include <iostream>
#include "CCadena.h"
using namespace std;

template<class DATO> class AVL;

// Clase Nodo de Arbol AVL:
template<class DATO>
class Nodo {
  public:
   // Constructor:
   Nodo(const DATO dat, Nodo<DATO> *pad=NULL,
        Nodo<DATO> *izq=NULL, Nodo<DATO> *der=NULL) :
     dato(dat), padre(pad), izquierdo(izq), derecho(der), FE(0) {}
   // Miembros:
   DATO dato;
   int FE;
   Nodo<DATO> *izquierdo;
   Nodo<DATO> *derecho;
   Nodo<DATO> *padre;
   friend class AVL<DATO>;
};

template<class DATO>
class AVL {
  private:
   enum {IZQUIERDO, DERECHO};
   // Punteros de la lista, para cabeza y nodo actual:
   Nodo<DATO> *raiz;
   Nodo<DATO> *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor b�sicos:
   AVL() : raiz(NULL), actual(NULL) {}
   ~AVL() { Podar(raiz); }
   // Insertar en �rbol ordenado:
   void Insertar(const DATO dat);
   // Borrar un elemento del �rbol:
   void Borrar(const DATO dat);
   // Funci�n de b�squeda:
   bool Buscar(const DATO dat);
   // Comprobar si el �rbol est� vac�o:
   bool Vacio(Nodo<DATO> *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo<DATO> *r) { return !r->derecho && !r->izquierdo; }
   // Contar n�mero de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un dato:
   int Altura(const DATO dat);
   // Devolver referencia al dato del nodo actual:
   DATO &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una funci�n a cada elemento del �rbol:
   void InOrden(void (*func)(DATO&, int) , Nodo<DATO> *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(DATO&, int) , Nodo<DATO> *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(DATO&, int) , Nodo<DATO> *nodo=NULL, bool r=true);
  private:
   // Funciones de equilibrado:
   void Equilibrar(Nodo<DATO> *nodo, int, bool);
   void RSI(Nodo<DATO>* nodo);
   void RSD(Nodo<DATO>* nodo);
   void RDI(Nodo<DATO>* nodo);
   void RDD(Nodo<DATO>* nodo);
   // Funciones auxiliares
   void Podar(Nodo<DATO>* &);
   void auxContador(Nodo<DATO>*);
   void auxAltura(Nodo<DATO>*, int);
};

// Poda: borrar todos los nodos a partir de uno, incluido
template<class DATO>
void AVL<DATO>::Podar(Nodo<DATO>* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un dato en el �rbol AVL
template<class DATO>
void AVL<DATO>::Insertar(const DATO dat)
{
   Nodo<DATO> *padre = NULL;

   cout << "Insertar: " << dat << endl;
   actual = raiz;
   // Buscar el dato en el �rbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo<DATO>(dat);
   // Si el dato es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) {
      padre->izquierdo = new Nodo<DATO>(dat, padre);
      Equilibrar(padre, IZQUIERDO, true);
   }
   // Si el dato es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) {
      padre->derecho = new Nodo<DATO>(dat, padre);
      Equilibrar(padre, DERECHO, true);
   }
}

// Equilibrar �rbol AVL partiendo del nodo nuevo
template<class DATO>
void AVL<DATO>::Equilibrar(Nodo<DATO> *nodo, int rama, bool nuevo)
{
   bool salir = false;

   // Recorrer camino inverso actualizando valores de FE:
   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; // Depende de si a�adimos ...
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; // ... o borramos
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = true; // La altura de las rama que
                                      // empieza en nodo no ha variado,
                                      // salir de Equilibrar
      else if(nodo->FE == -2) { // Rotar a derechas y salir:
         if(nodo->izquierdo->FE == 1) RDD(nodo); // Rotaci�n doble
         else RSD(nodo);                         // Rotaci�n simple
         salir = true;
      }
      else if(nodo->FE == 2) {  // Rotar a izquierdas y salir:
         if(nodo->derecho->FE == -1) RDI(nodo); // Rotaci�n doble
         else RSI(nodo);                        // Rotaci�n simple
         salir = true;
      }
      if(nodo->padre) 
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; // Calcular FE, siguiente nodo del camino.
   }   
}

// Rotaci�n doble a derechas
template<class DATO>
void AVL<DATO>::RDD(Nodo<DATO>* nodo)
{
   cout << "RDD" << endl;
   Nodo<DATO> *Padre = nodo->padre;
   Nodo<DATO> *P = nodo;
   Nodo<DATO> *Q = P->izquierdo;
   Nodo<DATO> *R = Q->derecho;
   Nodo<DATO> *B = R->izquierdo;
   Nodo<DATO> *C = R->derecho;

   if(Padre) 
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir �rbol:
   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;
   
   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

// Rotaci�n doble a izquierdas
template<class DATO>
void AVL<DATO>::RDI(Nodo<DATO>* nodo)
{
   cout << "RDI" << endl;
   Nodo<DATO> *Padre = nodo->padre;
   Nodo<DATO> *P = nodo;
   Nodo<DATO> *Q = P->derecho;
   Nodo<DATO> *R = Q->izquierdo;
   Nodo<DATO> *B = R->izquierdo;
   Nodo<DATO> *C = R->derecho;

   if(Padre) 
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else raiz = R;

   // Reconstruir �rbol:
   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;
   
   // Reasignar padres:
   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;

   // Ajustar valores de FE:
   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

// Rotaci�n simple a derechas
template<class DATO>
void AVL<DATO>::RSD(Nodo<DATO>* nodo)
{
   cout << "RSD" << endl;
   Nodo<DATO> *Padre = nodo->padre;
   Nodo<DATO> *P = nodo;
   Nodo<DATO> *Q = P->izquierdo;
   Nodo<DATO> *B = Q->derecho;

   if(Padre) 
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir �rbol:
   P->izquierdo = B;
   Q->derecho = P;
   
   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;

   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Rotaci�n simple a izquierdas
template<class DATO>
void AVL<DATO>::RSI(Nodo<DATO>* nodo)
{
   cout << "RSI" << endl;
   Nodo<DATO> *Padre = nodo->padre;
   Nodo<DATO> *P = nodo;
   Nodo<DATO> *Q = P->derecho;
   Nodo<DATO> *B = Q->izquierdo;

   if(Padre) 
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else raiz = Q;

   // Reconstruir �rbol:
   P->derecho = B;
   Q->izquierdo = P;
   
   // Reasignar padres:
   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;
   
   // Ajustar valores de FE:
   P->FE = 0;
   Q->FE = 0;
}

// Eliminar un elemento de un �rbol AVL
template<class DATO>
void AVL<DATO>::Borrar(const DATO dat)
{
   Nodo<DATO> *padre = NULL;
   Nodo<DATO> *nodo;
   DATO aux;
   
   actual = raiz;
   // Mientras sea posible que el valor est� en el �rbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor est� en el nodo actual
         if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            // El nodo padre del actual puede ser ahora un nodo hoja, por lo tanto su
            // FE es cero, pero debemos seguir el camino a partir de su padre, si existe.
            if((padre->derecho == actual && padre->FE == 1) ||
               (padre->izquierdo == actual && padre->FE == -1)) {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
               if(padre->derecho == actual) Equilibrar(padre, DERECHO, false);
               else                         Equilibrar(padre, IZQUIERDO, false);
            return;
         }
         else { // Si el valor est� en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo m�s izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo m�s derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que s�lo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class DATO>
void AVL<DATO>::InOrden(void (*func)(DATO&, int) , Nodo<DATO> *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato, nodo->FE);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class DATO>
void AVL<DATO>::PreOrden(void (*func)(DATO&, int), Nodo<DATO> *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato, nodo->FE);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
// el prototipo:
// template<class DATO> void func(DATO&);
template<class DATO>
void AVL<DATO>::PostOrden(void (*func)(DATO&, int), Nodo<DATO> *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato, nodo->FE);
}

// Buscar un valor en el �rbol
template<class DATO>
bool AVL<DATO>::Buscar(const DATO dat)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // dato encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No est� en �rbol
}

// Calcular la altura del nodo que contiene el dato dat
template<class DATO>
int AVL<DATO>::Altura(const DATO dat)
{
   int altura = 0;
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // dato encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
template<class DATO>
const int AVL<DATO>::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
template<class DATO>
void AVL<DATO>::auxContador(Nodo<DATO> *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
template<class DATO>
const int AVL<DATO>::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual
template<class DATO>
void AVL<DATO>::auxAltura(Nodo<DATO> *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // �rbol, actualizamos la altura actual del �rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Funci�n de prueba para recorridos del �rbol
template <class DATO>
void Mostrar(DATO &d, int FE)
{
   cout << d << "(" << FE << "),";
}

int main()
{
   // Un �rbol de enteros
   AVL<int> ArbolInt;

   // Inserci�n de nodos en �rbol:
/*   ArbolInt.Insertar(15);
   ArbolInt.Insertar(4);
   ArbolInt.Insertar(20);
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(25);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(8);*/
   ArbolInt.Insertar(1);
   ArbolInt.Insertar(2);
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(4);
   ArbolInt.Insertar(5);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(7);
   ArbolInt.Insertar(8);
   ArbolInt.Insertar(9);
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(11);
   ArbolInt.Insertar(12);
   ArbolInt.Insertar(13);
   ArbolInt.Insertar(14);
   ArbolInt.Insertar(15);
   ArbolInt.Insertar(16);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el �rbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   ArbolInt.Borrar(8);
   ArbolInt.Borrar(11);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el �rbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   cin.get();

   // Arbol de cadenas:
   AVL<Cadena> ArbolCad;

   // Inserci�n de valores:
   ArbolCad.Insertar("Hola");
   ArbolCad.Insertar(",");
   ArbolCad.Insertar("somos");
   ArbolCad.Insertar("buenos");
   ArbolCad.Insertar("programadores");

   // Mostrar en diferentes ordenes:
   cout << "InOrden: ";
   ArbolCad.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolCad.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolCad.PostOrden(Mostrar);
   cout << endl;

   // Borrar "buenos":
   ArbolCad.Borrar("buenos");
   cout << "Borrar 'buenos': ";
   ArbolCad.InOrden(Mostrar);
   cout << endl;
   cin.get();
   return 0;
}
