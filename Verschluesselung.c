
#include <stdio.h>

int main()
{
        /* Start Menü  */
    printf("     ________                   111       \n");    
    printf("    /     _/                   1111       \n");
    printf("   |    _/                  1111111       \n");
    printf("   |   /                   11111111       \n");
    printf("   |  |   ___      ____        1111       \n");
    printf("   |  |__|  |     |   /        1111       \n");
    printf("   |        |     |  |         1111       \n");
    printf("   |________|     |__|  *      1111       \n");
    printf("                                          \n");
    printf("                                          \n");    
    printf("   Bitte Wählen sie eine Aktion aus:      \n");
    printf("   [1]  Client-SW                         \n");
    printf("   [2]  Server-SW                         \n");
    printf("   [3]  Testumgebung                      \n");
    printf("   [4]  Brute-Force-Komponente            \n");

        /* Programm Auswählen und ausgabe Auswahl  */

    int eingabe;
    printf("Eingabe: ");

    scanf("%d", &eingabe);
    printf("Wilkommen in der");

    switch (eingabe) {
        case 1:
            printf(" Client-SW\n");
            break;
        case 2:
            printf("Server-SW\n");
            break;
        case 3:
            printf("Testumgebung\n");
            break;
        default:
            printf("Brute-Force-Komponente\n");
            break;
    }
        
        /**/
        printf ("%d", eingabe);


    
    return 0;
}
