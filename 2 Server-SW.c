#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funktion zur Umwandlung eines Binärstrings in eine Ganzzahl
unsigned short binToDec(const char *bin) {
    unsigned short num = 0;  // Variable für die Ganzzahl initialisieren
    for (int i = 0; i < strlen(bin); i++) {  // Durchlaufe jeden Charakter im Binärstring
        if (bin[i] == '1') {  // Wenn der Charakter '1' ist
            num |= (1 << (strlen(bin) - 1 - i));  // Setze das entsprechende Bit in num
        }
    }
    return num;  // Rückgabe der Ganzzahl
}

// Funktion zur Entschlüsselung des Textes
void decrypt(const char *cipherTextBin, const char *keyBin) {
    int len = strlen(cipherTextBin) / 8;  // Anzahl der Zeichen im Binärstring (8 Bits pro Zeichen)
    int keyLen = strlen(keyBin);  // Länge des Schlüssels in Bits
    unsigned short key[keyLen / 8];  // Array zur Speicherung der Schlüssel-Bytes

    // Zerlege den Binärschlüssel in 8-Bit-Blöcke und wandle sie in Ganzzahlen um
    for (int i = 0; i < keyLen / 8; i++) {
        char keyChunk[9];  // Array für 8-Bit-Blöcke
        strncpy(keyChunk, keyBin + (i * 8), 8);  // Hole die nächsten 8 Bits
        keyChunk[8] = '\0';  // Nullterminierung
        key[i] = binToDec(keyChunk);  // Wandle in Ganzzahl um und speichere im Array
    }

    for (int i = 0; i < len; i++) {  // Schleife über alle Zeichen
        char currentCharBin[9];  // Array für den aktuellen 8-Bit-Binärstring eines Zeichens
        strncpy(currentCharBin, cipherTextBin + (i * 8), 8);  // Hole die nächsten 8 Bits
        currentCharBin[8] = '\0';  // Nullterminierung des Binärstrings

        unsigned char cipherChar = (unsigned char)binToDec(currentCharBin);  // Binärstring in Dezimalwert (ASCII) umwandeln
        unsigned char keyByte = key[i % (keyLen / 8)];  // Wiederhole den Schlüssel blockweise
        unsigned char decryptedChar = cipherChar ^ keyByte;  // Entschlüsselung durch XOR mit dem aktuellen Schlüssel-Byte

        printf("%c", (char)decryptedChar);  // Gib das entschlüsselte Zeichen aus
    }
    printf("\n");  // Neue Zeile nach der Ausgabe
}

int main() {
    char keyBin[65];  // Array für den Binärschlüssel (bis zu 64 Bits)
    printf("Bitte geben Sie den Binärschlüssel ein (Länge ein Vielfaches von 8): ");  // Eingabeaufforderung für den Schlüssel
    scanf("%64s", keyBin);  // Schlüssel einlesen (maximal 64 Zeichen)

    if (strlen(keyBin) % 8 != 0) {  // Prüfen, ob die Länge ein Vielfaches von 8 ist
        printf("Fehler: Der Schlüssel muss eine Länge haben, die ein Vielfaches von 8 ist.\n");  // Fehlermeldung
        return 1;  // Programm beenden
    }

    char cipherTextBin[1024];  // Array für den verschlüsselten Text als Binärstring
    printf("Bitte geben Sie den verschlüsselten Text in Binärform ein (zusammenhängend, ohne Leerzeichen): ");  // Eingabeaufforderung für den Text
    scanf("%1024s", cipherTextBin);  // Verschlüsselten Text einlesen (maximal 1024 Zeichen)

    if (strlen(cipherTextBin) % 8 != 0) {  // Prüfen, ob die Länge ein Vielfaches von 8 ist
        printf("Fehler: Der verschlüsselte Text muss eine Länge haben, die ein Vielfaches von 8 ist.\n");  // Fehlermeldung
        return 1;  // Programm beenden
    }

    printf("\nEntschlüsselter Text: ");  // Ausgabeüberschrift
    decrypt(cipherTextBin, keyBin);  // Entschlüsselung aufrufen

    return 0;  // Programm erfolgreich beenden
}
