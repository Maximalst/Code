#include <stdio.h>

#define MAX_BLOCK_SIZE 1024

// Funktion zum Entschlüsseln mit XOR
void decrypt_xor(const unsigned char *ciphertext, unsigned char *plaintext, unsigned int key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ (key & 0xFF); // XOR mit den unteren 8 Bit des Schlüssels
    }
    plaintext[length] = '\0'; // Text beenden
}

// Funktion, um zu prüfen, ob der Text auf "_ende_" endet
int is_valid_text(const unsigned char *plaintext) {
    const char *end_marker = "_ende_";
    size_t i = 0;

    // Überprüfe, ob der Text das Ende "_ende_" enthält
    while (plaintext[i] != '\0') {
        if (plaintext[i] == '_' &&
            plaintext[i + 1] == 'e' &&
            plaintext[i + 2] == 'n' &&
            plaintext[i + 3] == 'd' &&
            plaintext[i + 4] == 'e' &&
            plaintext[i + 5] == '_') {
            return 1; // Text ist gültig
        }
        i++;
    }
    return 0; // Kein gültiges Ende gefunden
}

int main() {
    FILE *file = fopen("Name_enc.txt", "rb"); // Öffne die verschlüsselte Datei
    if (!file) {
        printf("Fehler: Datei konnte nicht geoeffnet werden.\n");
        return 1;
    }

    // Lese Schlüssel (16 Bit) und Blockgröße (8 Bit)
    unsigned int key_hint;
    unsigned char block_length;
    fread(&key_hint, sizeof(unsigned int), 1, file);
    fread(&block_length, sizeof(unsigned char), 1, file);

    // Lese den Chiffrat
    unsigned char ciphertext[MAX_BLOCK_SIZE];
    size_t ciphertext_length = fread(ciphertext, sizeof(unsigned char), block_length, file);
    fclose(file);

    // Brute-Force: Teste alle möglichen Schlüssel
    unsigned char plaintext[MAX_BLOCK_SIZE];
    for (unsigned int key = 0; key <= 0xFFFF; key++) {
        decrypt_xor(ciphertext, plaintext, key, ciphertext_length); // Entschlüsseln
        if (is_valid_text(plaintext)) { // Prüfen, ob der Text gültig ist
            printf("Schlüssel gefunden: %u\n", key);
            printf("Entschlüsselter Text: %s\n", plaintext);

            // Klartext speichern
            FILE *output = fopen("Name_dec.txt", "w");
            if (output) {
                fwrite(plaintext, sizeof(unsigned char), ciphertext_length, output);
                fclose(output);
                printf("Klartext wurde in 'Name_dec.txt' gespeichert.\n");
            }
            return 0; // Programm beenden, da der Schlüssel gefunden wurde
        }
    }

    printf("Kein gültiger Schlüssel gefunden.\n");
    return 0;
}

