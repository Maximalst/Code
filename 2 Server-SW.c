#include <stdio.h>

int main()
{
    char eingabe[1025];
    printf("Bitte gebe .txt inhalt ein!");// max 1024
    fgets(eingabe, sizeof(eingabe), stdin);

    FILE *datei = fopen("Key.txt", "w");
    if (datei == NULL)
    {
        printf("Fehler beim Erstellen der Datei!\n");
        return 1;
    }
    fprintf(datei, "%s", eingabe);
    fclose(datei);

    printf("Der eingegebene Key wurde in 'Key.txt' gespeichert (im aktuellen Ordner).\n");

    return 0;
}
