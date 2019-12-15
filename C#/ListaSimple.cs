using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StructDatos
{
    class Array_ListaSimple
    {
        private static ArrayList LISTA = new ArrayList();
        public Array_ListaSimple()
        {
            
        }
        public static void LISTA_SIMPLE()
        {
            int opcion = -1;
            do
            {
                Console.Clear();
                Console.WriteLine("1. Agregar");
                Console.WriteLine("2. Eliminar");
                Console.WriteLine("3. Recorrer lista primero al ultimo [Derecha]");
                Console.WriteLine("4. Recorrer ultimo al primero [izquierda]");
                Console.WriteLine("5. Buscar");
                Console.WriteLine("6. Volver al principal");
                Console.Write("Cual es tu opcion: ");
                opcion = int.Parse(Console.ReadLine());
                switch (opcion)
                {
                    case 1: Agregar_LISTA(); break;
                    case 2: Eliminar_LISTA(); break;
                    case 3: Recorrer_LISTA_PRIMERO_ULTIMO(); break;
                    case 4: Recorrer_LISTA_ULTIMO_PRIMERO(); break;
                    case 5: Buscar_LISTA(); break;
                    case 6: Program.volver(); break;
                }
            } while (opcion != 0);
        }//fin
        private static void Agregar_LISTA()
        {
            Console.Clear();
            Console.Write("Valor a agregar en la LISTA: ");
            string ValorAgregar = Console.ReadLine();
            LISTA.Add(ValorAgregar);
            Console.WriteLine("# de valores de la LISTA: {0}", LISTA.Count);
            Console.WriteLine("Valor tope de la LISTA: {0}", LISTA[LISTA.Count - 1]);
            Console.ReadKey();
            LISTA_SIMPLE();
        }
        private static void Eliminar_LISTA()
        {
            Console.Clear();
            Console.Write("Eliminar {0} de la LISTA (Si 1, No 2): ");
            if (LISTA.Count > 0)
            {
                Console.WriteLine("{Posicion}.       {Valor}");
                for (int i = 0; i < LISTA.Count; i++)
                {
                Console.WriteLine("  {0}.              {1}",i,LISTA[i].ToString());
                }
                Console.Write("Posicion que deseas eliminar: ");
                int posx = int.Parse(Console.ReadLine());
                if (posx >= 0 && posx <= LISTA.Count) LISTA.RemoveAt(posx);
                else { Console.WriteLine("VALOR NO VALIDO"); }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LISTA_SIMPLE();
        }
        private static void Recorrer_LISTA_ULTIMO_PRIMERO()
        {
            Console.Clear();
            if (LISTA.Count > 0)
            {
                for (int i = LISTA.Count -1; i >= 0; i--)
                {
                    Console.WriteLine(LISTA[i].ToString());
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LISTA_SIMPLE();
        }
        private static void Recorrer_LISTA_PRIMERO_ULTIMO()
        {
            Console.Clear();
            if (LISTA.Count > 0)
            {
                for (int i = 0; i < LISTA.Count; i++)
                {
                    Console.WriteLine(LISTA[i].ToString());
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LISTA_SIMPLE();
        }
        private static void Buscar_LISTA()
        {
            Console.Clear();
            Console.Write("Valor a buscar: ");
            string ValorBuscar = Console.ReadLine();
            if (LISTA.Count > 0)
            {
                for (int i = 0; i < LISTA.Count; i++)
                {
                    if (LISTA[i].ToString() == ValorBuscar)
                    {
                        Console.WriteLine("Valor encontrado Posicion {0}, Valor {0}", i, LISTA[i].ToString());
                        i = 0;
                    }
                }
            }
            else
            {
                Console.WriteLine("No tiene valores");
            }
            Console.ReadKey();
            LISTA_SIMPLE();
        }
    }
}
