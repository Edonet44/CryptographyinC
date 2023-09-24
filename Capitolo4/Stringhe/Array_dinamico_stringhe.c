#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroStringhe = 3; // Il numero di stringhe che desideri memorizzare

    // Dichiarazione di un puntatore a un puntatore a carattere (array dinamico di stringhe)
    char **stringhe = NULL;

    // Alloca memoria per l'array dinamico di puntatori a carattere
    stringhe = (char **)malloc(numeroStringhe * sizeof(char *));

    // Alloca memoria per ciascuna stringa e assegna i valori
    stringhe[0] = "Prima stringa";
    stringhe[1] = "Seconda stringa";
    stringhe[2] = "Terza stringa";

    // Puoi ora accedere alle stringhe come stringhe[0], stringhe[1], ecc.

    // Libera la memoria allocata
    for (int i = 0; i < numeroStringhe; i++)
    {
        free(stringhe[i]);
    }
    free(stringhe);

    return 0;
}
