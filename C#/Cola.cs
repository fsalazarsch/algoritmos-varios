using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StructDatos
{
    public class Cola
    {
        private static Queue COLA_FIFO = new Queue();
        public Cola()
        {
            
        }
        public static void FIFO()
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
                    case 1: Agregar_FIFO(); break;
                    case 2: Eliminar_FIFO(); break;
                    case 3: Recorrer_FIFO(); break;
                    case 4: Buscar_FIFO(); break;
                    case 5: Program.volver(); break;
                }
            } while (opcion != 0);
        }//fin
        private static void Agregar_FIFO()
        {
            Console.Clear();
            Console.Write("Valor a agregar en la pila: ");
            string ValorAgregar = Console.ReadLine();
            COLA_FIFO.Enqueue(ValorAgregar);
            Console.WriteLine("# de valores de la pila: {0}", COLA_FIFO.Count);
            Console.WriteLine("Valor tope de la pila: {0}", COLA_FIFO.Peek());
            Console.ReadKey();
            FIFO();
        }
        private static void Eliminar_FIFO()
        {
            Console.Clear();
            Console.Write("Eliminar {0} de la pila (Si 1, No 2): ",COLA_FIFO.Peek());
            string OpcionEliminar = Console.ReadLine();
            if (int.Parse(OpcionEliminar) == 1)
            {
                COLA_FIFO.Dequeue();
                if (COLA_FIFO.Count > 0)
                {
                    Console.WriteLine("# de valores de la pila: {0}", COLA_FIFO.Count);
                    Console.WriteLine("Valor tope de la pila: {0}", COLA_FIFO.Peek());
                }
                else 
                {
                    Console.WriteLine("LA COLA NO TIENE VALORES");
                }
                Console.ReadKey();
                FIFO();
            }
            else
            {
                Console.WriteLine("# de valores de la pila: {0}", COLA_FIFO.Count);
                Console.WriteLine("Valor tope de la pila: {0}", COLA_FIFO.Peek());
                Console.ReadKey();
                FIFO();
            }
        }
        private static void Recorrer_FIFO()
        {
            Console.Clear();
            Queue ColaCopia = new Queue();
            ColaCopia = (Queue)COLA_FIFO.Clone();
            if (ColaCopia.Count > 0)
            {
                for (int i = ColaCopia.Count; i > 0; i--)
                {
                    Console.WriteLine("{0}. {1}", i, ColaCopia.Peek());
                    ColaCopia.Dequeue();
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            FIFO();
        }
        private static void Buscar_FIFO()
        {
            Console.Clear();
            Queue ColaCopia = new Queue();
            ColaCopia = (Queue)COLA_FIFO.Clone();
            Console.Write("Valor a buscar: ");
            string ValorBuscar = Console.ReadLine();
            if (ColaCopia.Count > 0)
            {
                for (int i = ColaCopia.Count; i > 0; i--)
                {
                    if (ColaCopia.Peek().ToString() == ValorBuscar)
                    {
                        Console.WriteLine("Valor encontrado Posicion {0}, Valor {0}", i, ColaCopia.Peek());
                        i = 0;
                    }
                    ColaCopia.Dequeue();
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            FIFO();
        }

    }
}
