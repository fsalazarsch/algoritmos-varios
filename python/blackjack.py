from IPython.core import crashhandler
import random


def verificar_mano(jugador):
    tiene_as = False
    tiene_carta_mayor = False
    
    for carta, pinta in jugador:
        if carta == "A":
            tiene_as = True
        if carta in ["J", "Q", "K", "10"]:
            tiene_carta_mayor = True

    return tiene_as and tiene_carta_mayor

def calcular_puntaje(mano):
    puntaje = 0
    ases_contados = 0
    
    for carta in mano:
        valor_carta = carta
        if carta[0] in ["J", "Q", "K", "10"]:
            puntaje += 10
        elif carta[0] == "A":
            ases_contados += 1
            puntaje += 11
        else:
            puntaje += int(carta[0])
    
    while ases_contados > 0 and puntaje > 21:
        puntaje -= 10
        ases_contados -= 1
    
    return puntaje

def resultado(casa, jugador):
  while calcular_puntaje(casa) < 15 and calcular_puntaje(casa) >= 21:
    carta_extra = random.sample(cartas_disponibles, 1)[0]
    pinta_extra = random.choice(mazo_cartas[carta_extra])
    casa.append(carta_extra)
    print(carta_extra, pinta_extra)

  for carta, pinta in casa:
    print(f"Carta: {carta}, Pinta: {pinta}")  
  print("Puntaje casa:   "+str(calcular_puntaje(casa)))
  if calcular_puntaje(casa) > calcular_puntaje(jugador):
    print("Perdiste")
    return 0
  elif calcular_puntaje(casa) == calcular_puntaje(jugador):
    print("Empate")
    return opt_bet
  else:
    print("Ganaste")
    return (opt_bet*2)

global bet
bet = 1000

while bet > 0:
  continuar = "S"
  opt = 0
  opt_bet = 0
  while opt_bet > bet or  opt_bet < 1:
      opt_bet = int(input("Selecciona una apuesta (tienes "+str(bet)+"):\t"))
  bet -= opt_bet

  mazo_cartas = {
      "2": ("♠", "♣", "♦", "♥"),
      "3": ("♠", "♣", "♦", "♥"),
      "4": ("♠", "♣", "♦", "♥"),
      "5": ("♠", "♣", "♦", "♥"),
      "6": ("♠", "♣", "♦", "♥"),
      "7": ("♠", "♣", "♦", "♥"),
      "8": ("♠", "♣", "♦", "♥"),
      "9": ("♠", "♣", "♦", "♥"),
      "10": ("♠", "♣", "♦", "♥"),
      "J": ("♠", "♣", "♦", "♥"),
      "Q": ("♠", "♣", "♦", "♥"),
      "K": ("♠", "♣", "♦", "♥"),
      "A": ("♠", "♣", "♦", "♥")
  }

  perdiste = False
  # Sacar 4 cartas al azar
  cartas_disponibles = list(mazo_cartas.keys())
  cartas_sacadas = random.sample(cartas_disponibles, 4)

  casa = [(carta, random.choice(mazo_cartas[carta])) for carta in cartas_sacadas[:2]]
  jugador = [(carta, random.choice(mazo_cartas[carta])) for carta in cartas_sacadas[2:]]

  # Mostrar las cartas de cada jugador
  print("Casa:")
  print("La casa oculta sus cartas")
  #for carta, pinta in casa:
  #    print(f"Carta: {carta}, Pinta: {pinta}")
  #print("Puntaje casa:   "+str(calcular_puntaje(casa)))

  print("\nJugador:")
  for carta, pinta in jugador:
      print(f"Carta: {carta}, Pinta: {pinta}")
  print("Puntaje:   "+str(calcular_puntaje(jugador)))


  if verificar_mano(jugador) == True:
    print("Blackjack!!!!!")
    bet += opt_bet*2.5
  else:
    if verificar_mano(casa) == True:
      print("La casa tiene blackjack!!!!")
    else:
      while continuar == "S":
        continuar = input("Quieres otra carta? (S/N)")
        if continuar == "S":
          carta_extra = random.sample(cartas_disponibles, 1)[0]
          pinta_extra = random.choice(mazo_cartas[carta_extra])
          jugador.append(carta_extra)
          print(carta_extra, pinta_extra)
          print("Puntaje:   "+str(calcular_puntaje(jugador)))
          if calcular_puntaje(jugador) > 21:
            print("Perdiste....")
            continuar = "N"
            perdiste = True
            pass
          if calcular_puntaje(jugador) == 21:
            continuar = "N"
            perdiste = False
            bet += resultado(casa, jugador)
        else:
          if perdiste == True:
            pass
          else:
            print("==========\njuega la casa")

            bet += resultado(casa, jugador)

            pass

 
