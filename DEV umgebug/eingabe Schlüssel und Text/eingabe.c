#include <stdio.h>

int main() {
    char binKey[1024];  // Array für den Binärschlüssel (max. 1024 Zeichen)
    char binText[1024];  // Array für den verschlüsselten Text
    
    // Lese den Schlüssel in Binärform ein
    printf("Geben Sie den Schlüssel in Binärform ein: ");
    scanf("%s", binKey);
    
    // Lese den verschlüsselten Text in Binärform ein
    printf("Geben Sie den verschlüsselten Text in Binärform ein: ");
    getchar(); // Puffer leeren, um das vorherige '\n' zu entfernen
    fgets(binText, sizeof(binText), stdin);
    
    // Ausgabe der eingegebenen Werte
    printf("\nEingegebener Binär-Schlüssel: %s\n", binKey);
    printf("Eingegebener verschlüsselter Text: %s\n", binText);
    
    return 0;
}
