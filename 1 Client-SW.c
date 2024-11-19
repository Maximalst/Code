#include <stdio.h>

int main() {
    char nachricht[1024];
    int asciiWerte[1024];

    printf("Hier deine Nachricht eingeben: \n");
    fgets(nachricht, 1024, stdin); //fgets weil sonst die Leerzeichen nicht gelesen werden

    printf("Die ASCII-Werte der Nachricht sind:\n");
    int i;
    for (i = 0; nachricht[i] != '\0'; i++) {
        asciiWerte[i] = (int)nachricht[i];
        printf("'%c' -> %d\n", nachricht[i], asciiWerte[i]); //speichert ASCII Werte in asciiWerte[]
    }
    return 0;
}
