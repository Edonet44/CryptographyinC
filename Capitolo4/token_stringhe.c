#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
tokenizzazione di stringhe

Tokenizzazione di una Stringa: Scrivi una funzione che accetta una stringa e un carattere delimitatore come argomenti e restituisce un array di 

puntatori alle sottostringhe separate dal delimitatore. 
Utilizza un ciclo while per suddividere la stringa.

*/
char **token(char *str, char crt,int *tokenCount);


int main(){

    char inputString[] = "Questo è un esempio di tokenizzazione";
    char delimiter = ' ';
    int tokenCount = 0;

    // Chiama la funzione per tokenizzare la stringa
    char **tokens = token(inputString, delimiter, &tokenCount);

    // Stampa i token
    for (int i = 0; i < tokenCount; i++)
    {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }

    // Libera la memoria allocata per gli array di puntatori
    for (int i = 0; i < tokenCount; i++)
    {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}


//nb se debbo creare un array che cambia il suo contenuto DEVO utilizzare un array dinamico
//quindi puntatore di puntatore e inizializzare con malloc oppure come in questo caso
//metto nullo e poi utilizzo il realloc
char **token(char *str, char crt, int *tokenCount)
{
    //inizializza a zero un array di puntatory dinamico
    char **tokens = NULL;

    // Conta il numero di token
    int count = 0;
//copia la stringa di input per modificarla altrimenti si crerebbe una modifica totale della stringa quando la passo a strtok
    char *inputcopy = strdup(str);

    // Verifica se la duplicazione è riuscita
    if (inputcopy == NULL)
    {
        return NULL;
    }

//inizia a fare la tokenizzazione cioe mette il carattere scelto 
    char *token = strtok(inputcopy, &crt);


while (token!=NULL)
{
        count++;
// Rialloca l'array di puntatori per includere il nuovo token
        tokens = (char **)realloc(tokens, sizeof(char *) * count);
        // Verifica se l'allocazione di memoria è riuscita
        if (tokens == NULL)
        {
            free(inputcopy);
            return NULL;
        }

        // Assegna il token all'array di puntatori
        tokens[count - 1] = token;

        // Ottieni il prossimo token
        token = strtok(NULL, &crt);
}

// Restituisci il numero di token trovati
*tokenCount = count;

// Libera la copia della stringa di input
free(inputcopy);

// Restituisci l'array di puntatori ai token
return tokens;
}