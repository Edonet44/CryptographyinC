#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
Concatenazione di stringhe

*/

int main(){

    char stringa1[100];
    char stringa2[100];
    char *nuova;

    printf("digita la prima stringa");

    scanf("%s", stringa1);

    printf("digita la seconda stringa");

    scanf("%s", stringa2);

    //calcola lunghezza stringhe
    int lughez1 = strlen(stringa1);
    int lughez2 = strlen(stringa2);

    nuova = (char *)malloc(lughez1 + lughez2 + 1);

    // Verifica se l'allocazione di memoria è riuscita
    if (nuova == NULL)
    {
        printf("Errore: impossibile allocare memoria.");
        return 1; // Uscita con errore
    }

    strcopy(nuova,stringa1);
    strcat(nuova, stringa2);
    puts(nuova);

    printf("Unione delle stringhe %s\n", nuova);

    free(nuova);
    return 0;
}