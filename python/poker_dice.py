import random 
from collections import Counter
'''
Escalera Real (Royal Flush): Una secuencia de 10, J, Q, K, A, todos del mismo palo.- 
Escalera de Color (Straight Flush): Cinco cartas consecutivas del mismo palo.-
Póquer (Four of a Kind): Cuatro cartas del mismo valor.-
Full House (Full House o Full): Tres cartas del mismo valor junto con dos cartas de otro valor. -
Color (Flush): Cinco cartas del mismo palo, no necesariamente en secuencia. -
Escalera (Straight): Cinco cartas consecutivas de diferentes palos. - 
Trío (Three of a Kind): Tres cartas del mismo valor.
Doble Pareja (Two Pair): Dos pares de cartas del mismo valor.
Pareja (One Pair): Dos cartas del mismo valor.
Carta Alta (High Card): La carta más alta en caso de que no haya ninguna combinación.
'''
dado_cartas = {
    1: ("9", "♥"),
    2: ("10", "♦"),
    3: ("J", "♣"),
    4: ("Q", "♠"),
    5: ("K", "★"),
    6: ("A", "★")
}

dado_cartas_2 = {
    1: ("A", "♥"),
    2: ("9", "♦"),
    3: ("10", "♣"),
    4: ("J", "♠"),
    5: ("Q", "★"),
    6: ("K", "♠")
}

dado_cartas_3= {
    1: ("K", "♥"),
    2: ("A", "♦"),
    3: ("9", "♣"),
    4: ("10", "♠"),
    5: ("J", "★"),
    6: ("Q", "♣")
}

dado_cartas_4 = {
    1: ("Q", "♥"),
    2: ("K", "♦"),
    3: ("A", "♣"),
    4: ("9", "♠"),
    5: ("10", "★"),
    6: ("J", "♦")
}

dado_cartas_5 = {
    1: ("J", "♥"),
    2: ("Q", "♦"),
    3: ("K", "♣"),
    4: ("A", "♠"),
    5: ("9", "★"),
    6: ("10", "♥")
}

def escalera_real(cartas):
  if escalera_color(cartas) == True:
    values = [t[0] for t in cartas]
    if set(["10", "J", "Q", "K", "A"]).issubset(values):
        return True
    else:
        return False
  else:
    return False

def escalera_color(cartas):
  if tiene_escalera(cartas) == True and misma_pinta(cartas) == True:
    return True
  else:
    return False


def tiene_poquer(cartas):
  if check_combinations(cartas, 4)[0] == True:
    return [True, check_combinations(cartas, 4)[1]]
  return [False, 0]

def tiene_full(cartas):
  if check_combinations(cartas, 3)[0] == True:
    trio_value = check_combinations(cartas, 3)[1] 
    aux = [tupla for tupla in cartas if tupla[0] != trio_value]
    if check_combinations(aux, 2)[0] == True:
      return [True, [ check_combinations(cartas, 3)[1], check_combinations(aux, 2)[1] ]]
  return [False, 0]

def misma_pinta(cartas):
  suits_set = set(t[1] for t in cartas)
  if len(suits_set) == 2 and '★' in suits_set:
    return True
  if len(suits_set) == 1:
    return True
  return False


def tiene_escalera(cartas): 
    value_order = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]
    values = [t[0] for t in cartas]
    if set(["A", "2", "3", "4", "5"]).issubset(values):
      return True
    values.sort(key=lambda x: value_order.index(x))
    #values = [t[0] for t in cartas]
    #unique_values = list(set(values))
    values.sort(key=lambda x: value_order.index(x))
    
    for i in range(len(values) - 1):
        if value_order.index(values[i+1]) - value_order.index(values[i]) != 1:
            return False
    return True


def tiene_trio(cartas):
  if check_combinations(cartas, 3)[0] == True:
    return [True, check_combinations(cartas, 3)[1]]
  return [False, 0]

def tiene_dos_pares(cartas):
  if check_combinations(cartas, 2)[0] == True:
    par_value = check_combinations(cartas, 2)[1] 
    aux = [tupla for tupla in cartas if tupla[0] != par_value]
    if check_combinations(aux, 2)[0] == True:
      return [True, [ check_combinations(cartas, 2)[1], check_combinations(aux, 2)[1] ]]
  return [False, 0]

def tiene_par(cartas):
  if check_combinations(cartas, 2)[0] == True:
    return [True, check_combinations(cartas, 2)[1]]
  return [False, 0]

def check_combinations(cartas, cont):
    values = [t[0] for t in cartas]
    suits = [t[1] for t in cartas]
    
    value_counts = Counter(values)
    suit_counts = Counter(suits)
    
    for value, count in value_counts.items():
        if count == cont:
            return [True, value]
    
    return [False, 0]

def definir_mano(cartas):
  mano = 1
  if escalera_real(cartas) == True:
    mano = 10
  else:
    if escalera_color(cartas) == True:
      mano = 9
    else:
      if tiene_poquer(cartas)[0] == True:
        mano = 8
      else:
        if tiene_full(cartas)[0] == True:
          mano = 7
        else:
          if misma_pinta(cartas) == True:
            mano = 6
          else:
            if tiene_escalera(cartas) == True:
              mano = 5
            else:
              if tiene_trio(cartas)[0] == True:
                mano = 4
              else:
                if tiene_dos_pares(cartas)[0] == True:
                  mano = 3
                else:
                  if tiene_par(cartas)[0] == True:
                    mano = 2
  return mano

def peso_mano(mano, jugador):
  print("Mano: " +str(mano))
  if mano == 9 or  mano == 6 or mano ==  5 or mano == 1:
    return carta_mas_alta(jugador)
  elif mano == 7:
    return tiene_full(jugador)[1]
  elif mano == 3:
    return tiene_dos_pares(jugador)[1]
  elif mano == 8:
    return tiene_poquer(jugador)[1]
  elif mano == 4:
    return tiene_trio(jugador)[1]
  elif mano == 2:
    return tiene_par(jugador)[1]
  else:
    pass

def parsear_mano(mano, jugador):
    aux = peso_mano(mano, jugador)
    parsed_aux = []

    for i in range(len(aux)):
        if aux[i] == "J":
            parsed_aux.append("11")
        elif aux[i] == "Q":
            parsed_aux.append("12")
        elif aux[i] == "K":
            parsed_aux.append("13")
        else:
            parsed_aux.append(aux[i])
    
    return parsed_aux

def carta_mas_alta(cartas):
    value_order = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]
    alta = max(cartas, key=lambda x: value_order.index(x[0]))
    return alta

def values(cartas, cartas2):
  values = [t[0] for t in cartas]
  values2 = [t[0] for t in cartas2]
  newval = []
  newval2 = []
  for i in range(len(values)):
    if values[i] == "J":
      newval.append("11")
    elif values[i] == "Q":
      newval.append("12")
    elif values[i] == "K":
      newval.append("13")
    else:
      newval.append(values[i])

    if values2[i] == "J":
      newval2.append("11")
    elif values2[i] == "Q":
      newval2.append("12")
    elif values2[i] == "K":
      newval2.append("13")
    else:
      newval2.append(values2[i])

  if newval2 > newval:
    print("Ganador jugador 2")
  elif newval2 < newval:
    print("Ganador jugador 1")
  else:
    print("Empate")
  pass

dados = [dado_cartas, dado_cartas_2, dado_cartas_3, dado_cartas_4, dado_cartas_5]

jugador = [random.choice(list(dado.values())) for dado in dados]
jugador2 = [random.choice(list(dado.values())) for dado in dados]

for i, tupla in enumerate(jugador, start=1):
    print(f"Dado {i}: {tupla}")

print("===========================")
for i, tupla in enumerate(jugador2, start=1):
    print(f"Dado {i}: {tupla}")

values(jugador, jugador2)

mano = definir_mano(jugador)
mano2 = definir_mano(jugador2)

print(mano)
print(mano2)
  
if mano2 > mano:
  print("Ganador jugador 2")
elif mano2 < mano:
  print("Ganador jugador 1")
else:
  submano = parsear_mano(mano, jugador)
  submano2 = parsear_mano(mano2, jugador2)
  if submano2 > submano:
    print("Ganador jugador 2")
  elif submano2 < submano:
    print("Ganador jugador 1")
  else:
    values(jugador, jugador2)
#DETERMINAR CUAL ES LA AMNO QUE MAS VALE

#print(resultado)
