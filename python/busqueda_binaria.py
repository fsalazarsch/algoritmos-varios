import unittest


def busqueda_binaria(lista, objetivo):
    inicio = 0
    fin = len(lista) - 1

    while inicio <= fin:
        medio = (inicio + fin) // 2
        if lista[medio] == objetivo:
            return medio
        elif lista[medio] < objetivo:
            inicio = medio + 1
        else:
            fin = medio - 1
    return -1



class TestBusquedaBinaria(unittest.TestCase):
    #resultado = busqueda_binaria(lista, objetivo)
    #if resultado != -1 --> existe
  
    def test_elemento_encontrado(self):
        lista = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
        self.assertEqual(busqueda_binaria(lista, 7), 3)
        self.assertEqual(busqueda_binaria(lista, 1), 0)
        self.assertEqual(busqueda_binaria(lista, 19), 9)

    def test_elemento_no_encontrado(self):
        lista = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
        self.assertEqual(busqueda_binaria(lista, 4), -1)
        self.assertEqual(busqueda_binaria(lista, 20), -1)
        self.assertEqual(busqueda_binaria(lista, -1), -1)

    def test_lista_vacia(self):
        lista = []
        self.assertEqual(busqueda_binaria(lista, 1), -1)

    def test_lista_un_elemento(self):
        lista = [5]
        self.assertEqual(busqueda_binaria(lista, 5), 0)
        self.assertEqual(busqueda_binaria(lista, 3), -1)

    def test_lista_elementos_repetidos(self):
        lista = [1, 3, 3, 3, 5, 7, 9]
        self.assertTrue(busqueda_binaria(lista, 3) in [1, 2, 3])  # Puede devolver cualquiera de los índices de 3
        self.assertEqual(busqueda_binaria(lista, 5), 4)

if __name__ == '__main__':
    unittest.main()



