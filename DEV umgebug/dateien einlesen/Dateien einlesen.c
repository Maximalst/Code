#include <stdio.h>      // Standardbibliothek für Ein- und Ausgabe
#include <stdlib.h>     // Standardbibliothek für allgemeine Funktionen, z.B. Zufallszahlen
#include <string.h>     // Bibliothek für Zeichenketten (Strings) und deren Funktionen
#include <time.h>       // Bibliothek für Zeitfunktionen, z.B. für Zufallszahlen basierend auf der Uhrzeit

#define MAX_FILE_SIZE 1024  // Definiert eine Konstante für die maximale Dateigröße (1024 Bytes)

// Funktion zum Konvertieren einer Zahl in binär
void to_binary(int n, char *bin_str, int size) {
    for (int i = size - 1; i >= 0; i--) {  // Schleife von höchstem Bit (links) bis niedrigstem Bit (rechts)
        bin_str[size - 1 - i] = (n & (1 << i)) ? '1' : '0';  // Berechnet den Binärwert
    }
    bin_str[size] = '\0';  // Fügt den Null-Terminator hinzu, um den String zu beenden
}

int main() {
    FILE *file;        // Zeiger auf die Datei
    char filename[] = "_dec.txt";  // Der Name der zu öffnenden Datei
    char buffer[MAX_FILE_SIZE];    // Ein Array, um die Datei zu speichern
    int file_size;     // Variable für die Größe der Datei

    // Datei öffnen
    file = fopen(filename, "r");  // Versucht, die Datei im Lesemodus zu öffnen
    if (file == NULL) {  // Prüft, ob die Datei erfolgreich geöffnet wurde
        printf("Fehler: Datei _dec.txt konnte nicht geöffnet werden.\n");
        return 1;  // Beendet das Programm, wenn die Datei nicht geöffnet werden kann
    }

    // Datei einlesen
    fseek(file, 0, SEEK_END);  // Geht ans Ende der Datei
    file_size = ftell(file);   // Gibt die aktuelle Position der Datei (Größe) zurück
    fseek(file, 0, SEEK_SET);  // Geht wieder an den Anfang der Datei

    // Überprüft, ob die Datei zu groß ist
    if (file_size > MAX_FILE_SIZE) {
        printf("Fehler: Datei zu groß.\n");
        fclose(file);  // Schließt die Datei, wenn sie zu groß ist
        return 1;
    }

    // Liest die gesamte Datei in den Buffer
    fread(buffer, 1, file_size, file);  
    fclose(file);  // Schließt die Datei nach dem Lesen

    // Überprüft, ob die Datei genug Daten für Schlüssel und Blocklänge enthält
    if (file_size < 25) {  
        printf("Fehler: Datei enthält nicht genug Daten.\n");
        return 1;  // Beendet das Programm, wenn nicht genug Daten vorhanden sind
    }

    // Schlüssel: Erste 16 Bits (zufällig generiert)
    int key = rand() % (65000 - 10 + 1) + 10;  // Generiert eine Zufallszahl zwischen 10 und 65000
    char key_bin[17];  // Array für den Binärwert des Schlüssels
    to_binary(key, key_bin, 16);  // Wandelt die Zufallszahl in einen 16-Bit-Binärwert um
    printf("Schlüssel (16 Bits): %s\n", key_bin);  // Gibt den Schlüssel aus

    // Blocklänge: Nächste 8 Bits
    char block_length_bin[9];  
    strncpy(block_length_bin, &buffer[16], 8);  // Kopiert die Blocklänge (8 Bits) aus der Datei
    block_length_bin[8] = '\0';  // Nullterminierung des Strings
    int block_length = strtol(block_length_bin, NULL, 2);  // Wandelt die Binärblocklänge in eine Dezimalzahl um
    printf("Blocklänge (in Bits): %d (2^%d = %d Bits)\n", block_length, block_length, 1 << block_length);

    // Verschlüsselter Text (Rest der Datei)
    char encrypted_text[MAX_FILE_SIZE];
    int encrypted_text_length = file_size - 24;  // Bestimmt die Länge des verschlüsselten Texts
    strncpy(encrypted_text, &buffer[24], encrypted_text_length);  // Kopiert den verschlüsselten Text
    encrypted_text[encrypted_text_length] = '\0';  // Nullterminierung
    printf("Verschlüsselter Text: %s\n", encrypted_text);  // Gibt den verschlüsselten Text aus

    return 0;  // Erfolgreiches Ende des Programms
}
