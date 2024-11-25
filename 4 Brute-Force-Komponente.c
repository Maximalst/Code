#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BLOCK_SIZE 1024

// Funktion zum Entschlüsseln mit XOR
void decrypt_xor(const unsigned char *ciphertext, unsigned char *plaintext, unsigned int key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ (key & 0xFF); // XOR mit den unteren 8 Bit des Schlüssels
    }
    plaintext[length] = '\0'; // Text beenden
}

int is_valid_text(const unsigned char *plaintext) {
    size_t i = 0;

    // Durchlaufe den Text, bis das Nullterminierungszeichen '\0' erreicht ist
    while (plaintext[i] != '\0') {
        i++;
    }

    // Überprüfe, ob das Nullterminierungszeichen erreicht wurde
    // Wenn der Text mit '\0' endet und mindestens ein Zeichen enthält, ist er gültig
    return (i > 0 && plaintext[i] == '\0');
}



int main() {
    unsigned char ciphertext[MAX_BLOCK_SIZE];
    unsigned char plaintext[MAX_BLOCK_SIZE];
    size_t length = 0;
    char line[256];

    printf("Geben Sie die verschlüsselten Binärzahlen ein: \n"); 
    printf("Beenden Sie die Eingabe mit einer Leerzeile.\n");

    // Lese die Binärwerte vom Benutzer
    while (length < MAX_BLOCK_SIZE) {
        // Lese eine Zeile
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break; // Eingabe beendet
        }

        // Entferne das abschließende Newline-Zeichen
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0) {
            break; // Leere Zeile beendet die Eingabe
        }

        // Konvertiere den Binärstring in ein Byte und speichere es
        unsigned char value = 0;
        for (size_t i = 0; i < 8 && line[i] != '\0'; i++) {
            value = (value << 1) | (line[i] - '0');
        }

        ciphertext[length++] = value;
    }

    printf("\nChiffrat gelesen (%zu Bytes).\n", length);

    // Brute-Force: Teste alle möglichen Schlüssel
    for (unsigned int key = 0; key <= 0xFFFF; key++) {
        decrypt_xor(ciphertext, plaintext, key, length); // Entschlüsseln
        if (is_valid_text(plaintext)) { // Prüfen, ob der Text gültig ist
            printf("Schlüssel gefunden: %u\n", key);
            printf("Entschlüsselter Text: %s\n", plaintext);
            return 0; // Programm beenden, da der Schlüssel gefunden wurde
        }
    }

    printf("Kein gültiger Schlüssel gefunden.\n");
    return 0;
}

