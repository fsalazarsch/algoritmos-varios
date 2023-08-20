import random, os
from IPython.display import clear_output
import time

ruleta_americana = {
    "0": "V",
    "00": "V",
    "1": "R", "2": "N", "3": "R", "4": "N", "5": "R", "6": "N", "7": "R",
    "8": "N", "9": "R", "10": "N", "11": "N", "12": "R", "13": "N", "14": "R",
    "15": "N", "16": "R", "17": "N", "18": "R", "19": "R", "20": "N", "21": "R",
    "22": "N", "23": "R", "24": "N", "25": "R", "26": "N", "27": "R", "28": "N",
    "29": "N", "30": "R", "31": "N", "32": "R", "33": "N", "34": "R", "35": "N", "36": "R"
}

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')
    clear_output(wait=True)  # Borra la salida y contenido de la celda


def menu(opt):
    second_opt = 0
    while(not opt in range(1,10)):
        print("1) Casilla única: [X 36]\n")
        print("2) 2 Casillas: [X 17]\n")
        print("3) Fila (3 casillas): [X 11] \n")
        print("4) Cuadro (4 casillas): [X 6] \n")
        print("5) 6 casillas: [X 5] \n")
        print("6) Color: [X 1] \n")
        print("7) Par/Impar: [X 1] \n")
        print("8) Alto/Bajo: [X 1] \n")
        print("9) Docenas: [X 2] \n")
        print("10) Columans: [X 2]\n")

    #Apuesta a color (rojo/negro): Apostar a que la bola caerá en un número de un color específico. Pago: 1 a 1.
    #Apuesta a par/impar: Apostar a que la bola caerá en un número par o impar. Pago: 1 a 1.
    #Apuesta a alto/bajo: Apostar a que la bola caerá en un número alto (19-36) o bajo (1-18). Pago: 1 a 1.
    #Apuesta a docenas: Apostar a que la bola caerá en uno de los tres grupos de 12 números. Pago: 2 a 1.
        opt = int(input("Selecciona una opción:\t"))
    clear_screen()
    if opt == 1:
        while not numero_elegido in ruleta_americana:
            clear_screen()
            numero_elegido = input("Elige un número de la ruleta americana (0-36, 00): ")
            if numero_elegido in ruleta_americana:
                color = ruleta_americana[numero_elegido]
                print(f"El número {numero_elegido} es de color: {color}")
            else:
                print("Número no válido")
        return numero_elegido
            
    else:
        while(not second_opt in range(1,len(apuestas[opt-1])+1)):
            clear_screen()
            for index, item in enumerate(apuestas[opt-1]):
                print(str(index+1)+")"+str(item))
            second_opt = int(input("Selecciona una opción:\t"))

        return apuestas[opt-1][second_opt-1]



apuestas ={}
apuestas[1] = [
    "1-2", "2-3", "4-5", "5-6", "7-8", "8-9", "10-11", "11-12",
    "13-14", "14-15", "16-17", "17-18", "19-20", "20-21", "22-23",
    "23-24", "25-26", "26-27", "28-29", "29-30", "31-32", "32-33",
    "34-35", "35-36"
]
apuestas[2] = [
    "1-2-3", "4-5-6", "7-8-9", "10-11-12", "13-14-15", "16-17-18",
    "19-20-21", "22-23-24", "25-26-27", "28-29-30", "31-32-33", "34-35-36"
]
apuestas[3] = [
    "1-2-4-5", "2-3-5-6", "4-5-7-8", "5-6-8-9", "7-8-10-11", "8-9-11-12",
    "10-11-13-14", "11-12-14-15", "13-14-16-17", "14-15-17-18", "16-17-19-20",
    "17-18-20-21", "19-20-22-23", "20-21-23-24", "22-23-25-26", "23-24-26-27",
    "25-26-28-29", "26-27-29-30", "28-29-31-32", "29-30-32-33", "31-32-34-35", "32-33-35-36"
]
apuestas[4] = [
    "1-2-3-4-5-6", "4-5-6-7-8-9", "7-8-9-10-11-12", "10-11-12-13-14-15",
    "13-14-15-16-17-18", "16-17-18-19-20-21", "19-20-21-22-23-24",
    "22-23-24-25-26-27", "25-26-27-28-29-30", "28-29-30-31-32-33", "31-32-33-34-35-36"
]
apuestas[5] = ["Rojo", "Negro"]
apuestas[6] = ["Par", "Impar"]
apuestas[7] = ["1-18" , "19-36"]
apuestas[8] = ["1-12" , "13-24", "25-36"] #2
apuestas[9] = [
    "1-4-7-10-13-16-19-22-25-28-31-34",
    "2-5-8-11-14-17-20-23-26-29-32-35",
    "3-6-9-12-15-18-21-24-27-30-33-36"
]

multiplicador = [36, 17, 11, 6, 5, 1, 1, 1, 2, 2] 


clear_screen()
print(ruleta_americana)


bet = 1000
opt = 0

while not opt_bet in [1, bet]:
    opt_bet = int(input("Selecciona una opción:\t"))
    bet -= opt_bet




second_opt = menu(opt)


numero_aleatorio = random.choice(list(ruleta_americana.keys()))
color_aleatorio = ruleta_americana[numero_aleatorio]
print(f"Número aleatorio: {numero_aleatorio}, Color: {color_aleatorio}")

flag_win = False

if second_opt == "Rojo":
  if color_aleatorio == "R":
    flag_win = True
elif second_opt == "Negro":
  if color_aleatorio == "N":
    flag_win = True

elif second_opt == "Par":
  if not color_aleatorio == "V" and int(numero_aleatorio)%2 == 0:
    flag_win = True
elif second_opt == "Impar":
  if int(numero_aleatorio)%2 == 1:
    flag_win = True
elif second_opt == "1-18":
  if int(numero_aleatorio) >= 1 and int(numero_aleatorio) <= 18:
    flag_win = True
elif second_opt == "19-36":
  if int(numero_aleatorio) >= 19:
    flag_win = True

elif second_opt == "1-12":
  if int(numero_aleatorio) >= 1 and int(numero_aleatorio) <= 12:
    flag_win = True
elif second_opt == "13-24":
  if int(numero_aleatorio) >= 13 and int(numero_aleatorio) <= 24:
    flag_win = True
elif second_opt == "25-36":
  if int(numero_aleatorio) >= 25:
    flag_win = True
else:
  if numero_aleatorio in second_opt or numero_aleatorio == second_opt:
    flag_win = True

if flag_win == True:
  print("Ganaste: "+str(opt_bet * multiplicador[opt-1]))
  bet +=  opt_bet * multiplicador[opt-1]


