using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StructDatos
{
    public static class Recursion
    {
        public static void Fibonacci()
        {
            Console.Write("Valor de Fibonacci: ");
            int Valor = int.Parse(Console.ReadLine());
            Console.WriteLine(CalcularFibonacci(Valor));
            Console.ReadKey();
            Program.volver();
        }
        /// <summary>
        /// Calcula fibonacci dado un número
        /// f(0) = f(1) = 1
        /// f(n) = f(n-1) + f(n-2)
        /// </summary>
        /// <param name="pNumero">Número de la posición que ocupa en fibonacci</param>
        private static int CalcularFibonacci(int pNumero)
        {
            if ((pNumero == 0) || (pNumero == 1))
                return 1;
            else
                return CalcularFibonacci(pNumero - 1) + CalcularFibonacci(pNumero - 2);
        }
    }
}
