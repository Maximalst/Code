#include <stdio.h>

// Funktionen starten
void Client_SW() {
    printf("Client-SW Startet\n");
}


void Server_SW() {
    printf("Server-SW\n");
}

void Testumgebung() {
    printf("Testumgebung\n");
}

void Brute_Force_Komponente() {
    printf("Brute-Force-Komponente\n");
}

// Menü-Funktion
int menü() 
{
    printf("                                           \n");   
    printf("     ________                              \n");    
    printf("    /     _/                  11111        \n");
    printf("   |    _/                   111111        \n");
    printf("   |   /                    1111111        \n");
    printf("   |  |   ___      ____    11111111        \n");
    printf("   |  |__|  |     |   /        1111        \n");
    printf("   |        |     |  |         1111        \n");
    printf("   |________|     |__|  *      1111        \n");
    printf("                                           \n");
    printf("                                           \n");    
    printf("   Bitte Wählen sie eine Aktion aus:       \n");
    printf("   [1]  Client-SW                          \n");
    printf("   [2]  Server-SW                          \n");
    printf("   [3]  Testumgebung                       \n");
    printf("   [4]  Brute-Force-Komponente             \n");

    // Benutzereingabe
    int eingabe;
    printf("Eingabe: ");
    scanf("%d", &eingabe);

    printf("Willkommen in der");

    // Auswahl basierend auf der Eingabe
    switch (eingabe) {
        case 1:
            printf(" Client-SW\n");
            Client_SW();
            break;
        case 2:
            printf(" Server-SW\n");
            Server_SW();
            break;
        case 3:
            printf(" Testumgebung\n");
            Testumgebung();
            break;
        case 4:
            printf(" Brute-Force-Komponente\n");
            Brute_Force_Komponente();
            break;
        default:
            printf(" Ungültige Auswahl\n");
            break;
    }

    return 0;
}

int main() {
    // Aufruf der Menü-Funktion
    menü();
    return 0;
}
