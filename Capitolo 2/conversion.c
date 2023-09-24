#include <stdio.h>
#include <stdlib.h>

//dichiarazione delle funzioni che verranno utilizzate
//prototype
// funzione atois

int atois(char s[]);

int main() 
{
    //esempio di dichiarazione e differenze
    char t[] ="12645"; // qui assegna un array di caratteri
    char test = 'nome';

    // se voglio mettere un input da tastiera debbo prima dichiarare la grandezza del mio array di caratteri
    // creo un array di stringhe di 100 caratteri
    char s[100];
    printf("Inserisci una stringa");
    //segnaposto per una stringa e suo valore
    scanf("%s",s);
    int result = atois(s);
    printf("Il risultato della conversione è: %d\n", result);

    return 0;
}

//funzione che accetta un parametro di tipo stringa di numeri ovver char e restituisce una coversione
// da stringa a integer
int atois(char s[])
{
    int i, n;

    n = 0;

    for (i = 0;s[i]!='\0'; i++)
    {
        //la condizione dice se dentro l array ci sono numeri che vanno dallo 0 al 9 allora continua altrimenti esci
        if (s[i] >= '0' && s[i] <= '9')
        {
            n = 10 * n + s[i] - '0';
        }
        else if (s[i] == ','|| s[i]=='.')
        {

            break;
        }
        else
        {
            // La stringa contiene un carattere non numerico, usciamo e restituiamo 0
            printf("La stringa deve contenere numeri");
            return 0;
        }
}
return n;
}

float atofs(char s[])
{
int i;
float n = 0.0;
float decimalPlace = 1.0;
int isFractionalPart = 0; // Per gestire la parte decimale

// questo scorre la stringa fino alla fine ovvereo '\0'
for (i = 0; s[i] != '\0'; i++)
{
        if (s[i] >= '0' && s[i] <= '9')
        {

            //IF NOT parti decimali...
            if (!isFractionalPart)
            {
                n = 10.0 * n + (s[i] - '0');
            }
            else
            {
                decimalPlace /= 10.0;
                n += (s[i] - '0') * decimalPlace;
            }
        }
        else if (s[i] == ',' || s[i] == '.')
        {
            // Se la stringa contiene una virgola, passa alla parte decimale
            isFractionalPart = 1;
            printf("La stringa contiene una parte decimale\n");
        }
        else
        {
            // La stringa contiene un carattere non numerico, restituisci 0.0
            printf("La stringa deve contenere solo numeri o una virgola\n");
            return 0.0;
        }
}

return n;
}