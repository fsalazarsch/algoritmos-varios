#include <stdio.h>
#include <string.h>

// Definición de la máquina Enigma
struct EnigmaMachine {
    char rotor1[27];
    char rotor2[27];
    char rotor3[27];
    char reflector[27];
};

// Función para encriptar un caracter con la máquina Enigma
char encriptar(struct EnigmaMachine *maquina, char c) {
    if (c >= 'A' && c <= 'Z') {
        // Paso 1: Paso a través de los rotores
        c = maquina->rotor1[c - 'A'];
        c = maquina->rotor2[c - 'A'];
        c = maquina->rotor3[c - 'A'];

        // Paso 2: Reflector
        c = maquina->reflector[c - 'A'];

        // Paso 3: Retroceso a través de los rotores
        for (int i = 0; i < 26; i++) {
            if (maquina->rotor3[i] == c) {
                c = 'A' + i;
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (maquina->rotor2[i] == c) {
                c = 'A' + i;
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (maquina->rotor1[i] == c) {
                c = 'A' + i;
                break;
            }
        }
        return c;
    } else {
        // Caracter no válido, se devuelve sin cambios
        return c;
    }
}

int main() {
    // Configuración de la máquina Enigma
    struct EnigmaMachine maquina;
    strcpy(maquina.rotor1, "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    strcpy(maquina.rotor2, "AJDKSIRUXBLHWTMCQGZNPYFVO");
    strcpy(maquina.rotor3, "BDFHJLCPRTXVZNYEIWGAKMUSQO");
    strcpy(maquina.reflector, "YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // Mensaje a encriptar
    char mensaje[] = "HOLA";
    printf("Mensaje original: %s\n", mensaje);

    // Encriptar el mensaje
    int longitud = strlen(mensaje);
    for (int i = 0; i < longitud; i++) {
        mensaje[i] = encriptar(&maquina, mensaje[i]);
    }

    printf("Mensaje encriptado: %s\n", mensaje);

    return 0;
}
