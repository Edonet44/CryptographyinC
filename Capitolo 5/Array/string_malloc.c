#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Esercizio 4: Allocazione dinamica di stringhe
Utilizza malloc per allocare dinamicamente una stringa in cui l'utente può inserire una frase.
Successivamente, utilizza strlen per calcolare la lunghezza della stringa e stampala.

*/

int main()
{

    char str[100];
    int lngth = 0;

    printf("Inserisci una stringa da allocare e vedrai la lunghezza");

    scanf("%s", str);
    // allocazione dinamica della stringa
    char *newString = (char *)malloc((strlen(str) + 1) * sizeof(char));
    // char *newString = (char *)malloc((strlen(input) + 1) * sizeof(char));

    if (newString == NULL)
    {
        perror("Errore di allocazione di memoria");
        return 1;
    }

    // questa parte e utile per poter inizializzare il contenuto di newstring con il contenuto di str
    strcpy(newString, str);
    lngth = strlen(newString);
    printf("Lunghezza stringa %d", lngth);

    // Liberiamo la memoria allocata dinamicamente
    free(newString);

    return 0;
}