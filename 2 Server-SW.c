#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funktion zur Umwandlung eines Binärstrings in eine Ganzzahl (16 Bit)
unsigned short binToDec(const char *bin) {
    unsigned short num = 0;
    for (int i = 0; i < 16; i++) {
        if (bin[i] == '1') {
            num |= (1 << (15 - i));
        }
    }
    return num;
}

// Funktion zur Umwandlung einer Ganzzahl in einen Binärstring (16 Bits)
void decToBin(unsigned short num, char *bin) {
    for (int i = 0; i < 16; i++) {
        bin[i] = (num & (1 << (15 - i))) ? '1' : '0';
    }
    bin[16] = '\0';
}

// Funktion zur Entschlüsselung des Textes
void decrypt(const char *cipherTextBin, const char *keyBin) {
    int len = strlen(cipherTextBin);  // Länge des verschlüsselten Textes
    unsigned short key = binToDec(keyBin);  // Umwandeln des Schlüssels in Dezimal
    char decryptedCharBin[17];  // Binärrepräsentation des entschlüsselten Zeichens

    // Durchlaufe den verschlüsselten Text
    for (int i = 0; i < len; i++) {
        // Aktuelles Zeichen im verschlüsselten Text (in Binär)
        unsigned short cipherChar = binToDec(cipherTextBin + i);

        // XOR mit dem Schlüssel
        unsigned short decryptedChar = cipherChar ^ key;

        // Umwandeln des entschlüsselten Zeichens in Binär
        decToBin(decryptedChar, decryptedCharBin);

        // Ausgabe des entschlüsselten Zeichens als ASCII
        printf("%c", (char)decryptedChar);
    }
}

int main() {
    // Eingabe des 16-Bit langen Schlüssels
    char keyBin[17];
    printf("Bitte geben Sie den 16-Bit langen Schlüssel in Binärform ein: ");
    scanf("%16s", keyBin);

    // Prüfen, ob der Schlüssel genau 16 Bits lang ist
    if (strlen(keyBin) != 16) {
        printf("Fehler: Der Schlüssel muss genau 16 Bits lang sein.\n");
        return 1;
    }

    // Eingabe des verschlüsselten Textes als Binärstring (jeweils ein Zeichen als 8 Bits)
    char cipherTextBin[1024];
    printf("Bitte geben Sie den verschlüsselten Text in Binärform ein (jede 8-Bit für ein Zeichen): ");
    scanf("%1024s", cipherTextBin);

    // Entschlüsselung und Ausgabe des Ergebnisses
    printf("\nEntschlüsselter Text: ");
    decrypt(cipherTextBin, keyBin);
    printf("\n");

    return 0;
}
