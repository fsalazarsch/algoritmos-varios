import random

def construir_modelo(texto, k=1):
    modelo = {}
    palabras = texto.split()
    
    for i in range(len(palabras) - k):
        estado = tuple(palabras[i:i + k])
        siguiente_palabra = palabras[i + k]
        if estado not in modelo:
            modelo[estado] = []
        modelo[estado].append(siguiente_palabra)
    
    return modelo

def generar_texto(modelo, longitud, k=1):

  estado_inicial = random.choice(list(modelo.keys()))
    resultado = list(estado_inicial)
    
    for _ in range(longitud - k):
        estado_actual = tuple(resultado[-k:])
        siguiente_palabra = random.choice(modelo.get(estado_actual, ['']))
        resultado.append(siguiente_palabra)
    
    return ' '.join(resultado)

if __name__ == "__main__":
    texto_de_entrada = """Este es un ejemplo de texto para construir una cadena de Markov.
    La cadena de Markov generará texto."""

    modelo_markov = construir_modelo(texto_de_entrada, k=2)
    texto_generado = generar_texto(modelo_markov, longitud=50, k=2)

    print(texto_generado)
