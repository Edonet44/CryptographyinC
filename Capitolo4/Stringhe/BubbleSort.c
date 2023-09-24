#include <stdlib.h>
#include <stdio.h>

/*
Ordina una Stringa: Scrivi una funzione che accetta una stringa
come argomento e la ordina in ordine alfabetico.
Utilizza un ciclo for e un algoritmo di ordinamento come il Bubble Sort.

*/
void BubbleSort(char *input);

int main()
{

    char stringa[100];

    printf("scrivi una stringa di caratter");

    scanf("%s", stringa);

    BubbleSort(stringa);

    printf("Stringa ordinata %s\n", stringa);

    return 0;
}

void BubbleSort(char *input)
{
    int i, k;
    // stabilisco la lunghezza della stringa
    int lenght = strlen(input);

    for (i = 0; i < lenght - 1; i++)
    {
        for (k = 0; k < lenght - 1 - i; k++)
        {
            if (input[k] > input[k + 1])
            {
                // scambia i caratteri
                char temp = input[k];
                input[k] = input[k + 1];
                input[k + 1] = temp;
            }
        }
    }
}