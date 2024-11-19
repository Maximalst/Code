
#include <stdio.h>

int main() {
    char nachricht[1024];
    int asciiWerte[1024];

    printf("Hier deine Nachricht eingeben: \n");
    scanf("%s", nachricht);

    printf("Die ASCII-Werte der Nachricht sind:\n");
    int i;
    for (i = 0; nachricht[i] != '\0'; i++) {
        asciiWerte[i] = (int)nachricht[i];
        printf("'%c' -> %d\n", nachricht[i], asciiWerte[i]); //ASCII Werte sind in asciiWerte[i] gespeichert
    }
    
    return 0;
}
