#include <stdio.h>

int main() {
    char nachricht[1024];

    printf("Hier deine Nachricht eingeben: ");
    scanf("%s", nachricht); 

    printf("Die ASCII-Werte der Nachricht sind:\n");
    for (int i = 0; nachricht[i] != '\0'; i++) { // Schleife über die Zeichen
        printf("'%c' -> %d\n", nachricht[i], (int)nachricht[i]);
    }

    return 0;
}
