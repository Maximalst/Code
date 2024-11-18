#include <stdio.h>

int main() {

    FILE *fOpen;
    int temp;

    fOpen = fopen("test.txt", "r");
    
    while ((temp = fgetc(fOpen))!= EOF)
    {
        printf("%c", temp);
    }
    fclose(fOpen);
}

