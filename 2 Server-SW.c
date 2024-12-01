#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024 // Maximale Blockgröße (2^10 Bits)

// Funktion zum Entschlüsseln eines Blocks
void decryptBlock(unsigned char *block, unsigned char *key, int blockSize) {
    for (int i = 0; i < blockSize; i++) {
        block[i] ^= key[i]; // XOR-Verschlüsselung rückgängig machen
    }
}

// Funktion zum Lesen der verschlüsselten Datei
void readEncryptedFile(const char *filename, unsigned char **encryptedData, unsigned char **key, int *blockSize, int *dataSize) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Fehler beim Öffnen der Datei");
        exit(EXIT_FAILURE);
    }

    // Schlüssel (16 Bit) lesen
    *key = (unsigned char *)malloc(2);
    fread(*key, 1, 2, file);

    // Blockgröße (8 Bit) lesen
    unsigned char blockSizeByte;
    fread(&blockSizeByte, 1, 1, file);
    *blockSize = 1 << blockSizeByte; // Blockgröße als Potenz von 2

    // Verschlüsselte Daten lesen
    fseek(file, 0, SEEK_END);
    *dataSize = ftell(file) - 3; // 3 Bytes für Schlüssel und Blockgröße
    rewind(file);
    fseek(file, 3, SEEK_SET); // Überspringe Schlüssel und Blockgröße

    *encryptedData = (unsigned char *)malloc(*dataSize);
    fread(*encryptedData, 1, *dataSize, file);
    fclose(file);
}

// Funktion zum Schreiben der entschlüsselten Nachricht
void writeDecryptedFile(const char *filename, unsigned char *data, int dataSize) {
    char outputFilename[256];
    snprintf(outputFilename, sizeof(outputFilename), "%s_dec.txt", filename);

    FILE *file = fopen(outputFilename, "w");
    if (!file) {
        perror("Fehler beim Schreiben der Datei");
        exit(EXIT_FAILURE);
    }

    fwrite(data, 1, dataSize, file); // Entschlüsselte Daten speichern
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Verwendung: %s <verschlüsselte Datei>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char *encryptedData = NULL;
    unsigned char *key = NULL;
    int blockSize = 0, dataSize = 0;

    // Verschlüsselte Datei lesen
    readEncryptedFile(argv[1], &encryptedData, &key, &blockSize, &dataSize);

    // Entschlüsselte Datenpuffer erstellen
    unsigned char *decryptedData = (unsigned char *)malloc(dataSize);

    // Blockweise entschlüsseln
    for (int i = 0; i < dataSize; i += blockSize) {
        int currentBlockSize = (i + blockSize <= dataSize) ? blockSize : dataSize - i;
        memcpy(decryptedData + i, encryptedData + i, currentBlockSize); // Kopiere aktuellen Block
        decryptBlock(decryptedData + i, key, currentBlockSize);         // Entschlüsseln
    }

    // Entschlüsselte Datei schreiben
    writeDecryptedFile(argv[1], decryptedData, dataSize);

    printf("Entschlüsselung abgeschlossen. Datei gespeichert.\n");

    // Speicher freigeben
    free(encryptedData);
    free(decryptedData);
    free(key);

    return EXIT_SUCCESS;
}
