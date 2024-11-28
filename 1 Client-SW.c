#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char nachricht[1024];
    int asciiWerte[1024];
    char gesamterBinärCode[64 * 8 + 1] = ""; // Puffer für den gesamten Binärcode

    printf("Hier deine Nachricht eingeben: \n");
    fgets(nachricht, 1024, stdin);

    nachricht[strcspn(nachricht, "\n")] = '\0';

    printf("Die ASCII-Werte der Nachricht sind:\n");
    for (int i = 0; nachricht[i] != '\0'; i++) {
        asciiWerte[i] = (int)nachricht[i];
        printf("'%c' -> %d -> ", nachricht[i], asciiWerte[i]);

        char binary[9];
        binary[8] = '\0';

        int num = asciiWerte[i];
        for (int j = 7; j >= 0; j--) {
            binary[j] = (num & 1) ? '1' : '0';
            num >>= 1;
        }

        printf("%s\n", binary);
        strcat(gesamterBinärCode, binary);
    }

    printf("\nDer gesamte Binärcode der Nachricht ist:\n");
    printf("%s\n\n", gesamterBinärCode);

    int ziffern = strlen(gesamterBinärCode);
    printf("Der Binärcode ist %d Ziffern groß.\n", ziffern);

    // Auffüllen mit '1'
    int maxLength = 64 * 8;
    if (ziffern < maxLength) {
        int fehlendeZiffern = maxLength - ziffern;
        for (int i = 0; i < fehlendeZiffern; i++) {
            strncat(gesamterBinärCode, "1", 1);
        }
    }

    printf("\nDer Binärcode nach dem Auffüllen mit '1':\n");
    printf("%s\n\n", gesamterBinärCode);

    printf("Der Binärcode ist %lu Ziffern groß.\n\n", strlen(gesamterBinärCode));

    // Zufällige Zahl und Schlüsselberechnung
    srand(time(0));
    int randomZahl = (rand() % 65000) + 10;
    printf("Zufällige Zahl: %d\n", randomZahl);

    char key[17] = ""; // Platz für 16 Bits + Nullterminator
    for (int i = 15; i >= 0; i--) {
        key[i] = (randomZahl % 2) ? '1' : '0';
        randomZahl /= 2;
    }
    key[16] = '\0';

    printf("Binärschlüssel: %s\n\n", key);

    // Blocklänge in Binär
    int blocklength = ziffern / 8;
    printf("Die Blocklänge ist %d Ziffern Groß\n", blocklength);

    char blBinary[9] = "";
    for (int i = 7; i >= 0; i--)
    {
        blBinary[i] = (blocklength % 2) ? '1' : '0';
        blocklength /= 2;
    }
    blBinary[8] = '\0';

    printf("Blocklänge als Binär: %s", blBinary);

    return 0;
}
