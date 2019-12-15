using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StructDatos
{
    public class Pila
    {
        private static Stack PILA = new Stack();
        public Pila()
        {
            
        }
        public static void LIFO()
        {
            int opcion = -1;
            do
            {
                Console.Clear();
                Console.WriteLine("1. Agregar");
                Console.WriteLine("2. Eliminar");
                Console.WriteLine("3. Recorrer");
                Console.WriteLine("4. Buscar");
                Console.WriteLine("5. Volver al principal");
                Console.Write("Cual es tu opcion: ");
                opcion = int.Parse(Console.ReadLine());
                switch (opcion)
                {
                    case 1: Agregar_LIFO(); break;
                    case 2: Eliminar_LIFO(); break;
                    case 3: Recorrer_LIFO(); break;
                    case 4: Buscar_LIFO(); break;
                    case 5: Program.volver(); break;
                }
            } while (opcion != 0);
        }//fin
        private static void Agregar_LIFO()
        {
            Console.Clear();
            Console.Write("Valor a agregar en la pila: ");
            string ValorAgregar = Console.ReadLine();
            PILA.Push(ValorAgregar);
            Console.WriteLine("# de valores de la pila: {0}", PILA.Count);
            Console.WriteLine("Valor tope de la pila: {0}", PILA.Peek());
            Console.ReadKey();
            LIFO();
        }
        private static void Eliminar_LIFO()
        {
            Console.Clear();
            Console.Write("Eliminar {0} de la pila (Si 1, No 2): ",PILA.Peek());
            string OpcionEliminar = Console.ReadLine();
            if (int.Parse(OpcionEliminar) == 1)
            {
                PILA.Pop();
                if (PILA.Count > 0)
                {
                    Console.WriteLine("# de valores de la pila: {0}", PILA.Count);
                    Console.WriteLine("Valor tope de la pila: {0}", PILA.Peek());
                }
                else 
                {
                    Console.WriteLine("LA PILA NO TIENE VALORES");
                }
                Console.ReadKey();
                LIFO();
            }
            else
            {
                Console.WriteLine("# de valores de la pila: {0}", PILA.Count);
                Console.WriteLine("Valor tope de la pila: {0}", PILA.Peek());
                Console.ReadKey();
                LIFO();
            }
        }
        private static void Recorrer_LIFO()
        {
            Console.Clear();
            Stack PilaCopia = new Stack();
            PilaCopia = (Stack)PILA.Clone();
            if (PilaCopia.Count > 0)
            {
                for (int i = PILA.Count; i > 0; i--)
                {
                    Console.WriteLine("{0}. {1}",i,PilaCopia.Peek());
                    PilaCopia.Pop();
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LIFO();
        }
        private static void Buscar_LIFO()
        {
            Console.Clear();
            Stack PilaCopia = new Stack();
            PilaCopia = (Stack)PILA.Clone();
            Console.Write("Valor a buscar: ");
            string ValorBuscar = Console.ReadLine();
            if (PilaCopia.Count > 0)
            {
                for (int i = PILA.Count; i > 0; i--)
                {
                    if (PilaCopia.Peek().ToString() == ValorBuscar)
                    {
                        Console.WriteLine("Valor encontrado Posicion {0}, Valor {0}", i, PilaCopia.Peek());
                        i = 0;
                    }
                    PilaCopia.Pop();
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LIFO();
        }

    }
}
