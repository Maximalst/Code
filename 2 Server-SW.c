#include <stdio.h>
#include <stdlib.h>

int main() {
    char dateiPfad[256];  // Puffer für den Dateipfad
    FILE *datei;

    // Benutzer auffordern, den Dateipfad einzugeben
    printf("Bitte geben Sie den Dateipfad ein: ");
    scanf("%255s", dateiPfad);  // Den Dateipfad vom Benutzer einlesen

    // Datei im Lese-Modus öffnen
    datei = fopen(dateiPfad, "r");

    // Überprüfen, ob die Datei erfolgreich geöffnet wurde
    if (datei == NULL) {
        perror("Fehler beim Öffnen der Datei");
        return 1;
    }

    printf("Datei erfolgreich geöffnet: %s\n", dateiPfad);

    // Hier kann weiter mit der Datei gearbeitet werden...

    // Datei schließen
    fclose(datei);

    return 0;
}
