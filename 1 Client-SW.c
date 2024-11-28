#include <stdio.h>
#include <string.h>  // Für strcat

int main() {
    char nachricht[1024];
    int asciiWerte[1024];
    char gesamterBinärCode[64 * 8 + 1] = ""; // Puffer für den gesamten Binärcode

    printf("Hier deine Nachricht eingeben: \n");
    fgets(nachricht, 1024, stdin); // fgets, weil sonst die Leerzeichen nicht gelesen werden

    // Entfernen des Zeilenumbruchs, der durch fgets am Ende der Eingabe eingefügt wird
    nachricht[strcspn(nachricht, "\n")] = '\0';

    printf("Die ASCII-Werte der Nachricht sind:\n");
    int i;
    for (i = 0; nachricht[i] != '\0'; i++) {
        asciiWerte[i] = (int)nachricht[i];
        printf("'%c' -> %d -> ", nachricht[i], asciiWerte[i]); // ASCII-Wert ausgeben

        // Berechnung der Binärdarstellung
        char binary[9]; // 8 Bits für ASCII + Nullterminator
        binary[8] = '\0'; // Nullterminator setzen
        
        int num = asciiWerte[i];
        for (int j = 7; j >= 0; j--) {
            binary[j] = (num & 1) ? '1' : '0'; // Prüfe das niedrigste Bit
            num >>= 1; // Schiebe die Bits nach rechts
        }

        printf("%s\n", binary); // Binärdarstellung ausgeben

        // Füge den Binärwert des aktuellen Zeichens zum gesamten Binärcode hinzu
        strcat(gesamterBinärCode, binary);
    }

    // Ausgabe des gesamten Binärcodes
    printf("\nDer gesamte Binärcode der Nachricht ist:\n");
    printf("%s\n\n", gesamterBinärCode);
    
    // Misst die Zifferanzahl des Binärcodes
    int ziffern = strlen(gesamterBinärCode);
    printf("Der Binärcode ist %d Ziffern groß.\n", ziffern);

    // Berechnung wie viele Ziffern mit 1 aufgefüllt werden soll
    int maxLength = 64 * 8; // Maximale länge des Binärcodes 512 bits
    if (ziffern < maxLength) {
        int fehlendeZiffern = maxLength - ziffern;
        for (int i = 0; i < fehlendeZiffern; i++) {
            strncat(gesamterBinärCode, "1", 1); //Hängt an restliche freie Stellen des Binärcodes 1 an
        }
        
    }
    
    // Ausgabe des aktualisierten Binärcodes
    printf("\nDer Binärcode nach dem Auffüllen mit '1':\n");
    printf("%s\n\n", gesamterBinärCode);
    
    // Misst die Zifferanzahl des Binärcodes
    int lol = strlen(gesamterBinärCode);
    printf("Der Binärcode ist %d Ziffern groß.\n\n", lol);

    return 0;
}



/////


#include <stdio.h>
#include <string.h>  // Für strcat
#include <time.h> // Für rand method

int main() {
    char nachricht[1024];
    int asciiWerte[1024];
    char gesamterBinärCode[64 * 8 + 1] = ""; // Puffer für den gesamten Binärcode

    printf("Hier deine Nachricht eingeben: \n");
    fgets(nachricht, 1024, stdin); // fgets, weil sonst die Leerzeichen nicht gelesen werden

    // Entfernen des Zeilenumbruchs, der durch fgets am Ende der Eingabe eingefügt wird
    nachricht[strcspn(nachricht, "\n")] = '\0';

    printf("Die ASCII-Werte der Nachricht sind:\n");
    int i;
    for (i = 0; nachricht[i] != '\0'; i++) {
        asciiWerte[i] = (int)nachricht[i];
        printf("'%c' -> %d -> ", nachricht[i], asciiWerte[i]); // ASCII-Wert ausgeben

        // Berechnung der Binärdarstellung
        char binary[9]; // 8 Bits für ASCII + Nullterminator
        binary[8] = '\0'; // Nullterminator setzen
        
        int num = asciiWerte[i];
        for (int j = 7; j >= 0; j--) {
            binary[j] = (num & 1) ? '1' : '0'; // Prüfe das niedrigste Bit
            num >>= 1; // Schiebe die Bits nach rechts
        }

        printf("%s\n", binary); // Binärdarstellung ausgeben

        // Füge den Binärwert des aktuellen Zeichens zum gesamten Binärcode hinzu
        strcat(gesamterBinärCode, binary);
    }

    // Ausgabe des gesamten Binärcodes
    printf("\nDer gesamte Binärcode der Nachricht ist:\n");
    printf("%s\n\n", gesamterBinärCode);
    
    // Misst die Zifferanzahl des Binärcodes
    int ziffern = strlen(gesamterBinärCode);
    printf("Der Binärcode ist %d Ziffern groß.\n", ziffern);

    // Berechnung wie viele Ziffern mit 1 aufgefüllt werden soll
    int maxLength = 64 * 8; // Maximale länge des Binärcodes 512 bits
    if (ziffern < maxLength) {
        int fehlendeZiffern = maxLength - ziffern;
        for (int i = 0; i < fehlendeZiffern; i++) {
            strncat(gesamterBinärCode, "1", 1); //Hängt an restliche freie Stellen des Binärcodes 1 an
        }
        
    }
    
    // Ausgabe des aktualisierten Binärcodes
    printf("\nDer Binärcode nach dem Auffüllen mit '1':\n");
    printf("%s\n\n", gesamterBinärCode);
    
    // Misst die Zifferanzahl des Binärcodes
    int lol = strlen(gesamterBinärCode);
    printf("Der Binärcode ist %d Ziffern groß.\n\n", lol);

    //Schluessel Erstellen
    srand(time(0));
    int randomZahl = (rand() % 65000) + 10; //Random Zahl von 10 - 65000 wird erstell
    printf("%d", randomZahl);

    return 0;
}

