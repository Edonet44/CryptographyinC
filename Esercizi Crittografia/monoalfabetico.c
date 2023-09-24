/*

Problema: Cifrario di Sostituzione Monoalfabetico

Nel cifrario di sostituzione monoalfabetico, ogni lettera del testo in chiaro viene sostituita da una lettera fissa del cifrario. Ad esempio, se si utilizza una sostituzione con uno spostamento di 3 posizioni, 
'A' diventa 'D', 'B' diventa 'E', ecc.
Scrivi un programma in linguaggio C che permetta all'utente di inserire una
 stringa di testo in chiaro e poi la cifri utilizzando un cifrario di sostituzione
  monoalfabetico. Il programma deve richiedere un intero (positivo o negativo)
   che rappresenta lo spostamento delle lettere. Ad esempio, uno spostamento 
   di 3 posizioni significherà che 'A' diventerà 'D', 'B' diventerà 'E', ecc.
*/


#include <stdio.h>
#include <stdlib.h>

 void monalfb(char t[]);

int main(){

    char t[100];

    printf("Inserisci il testo da cifrare");

    scanf("%s", t);
        
    monalfb(t);
    printf("Risultato del testo cifrato %s\n", t);
    return 0;
}

void monalfb(char t[]){

    int i, j;
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; t[i] != '\0'; i++)
    {
        //scorro carattere per carattere
        char carattere = t[i];
        
        //si utilizza questo metodo perche in Ascii ogni lettera corrispone ad un numero quindi
        // mettiamo il caso che la prima lettera è un 'C'
        /*
        Nell'alfabeto inglese, le lettere sono ordinate in modo sequenziale da 'A' a 'Z'. Quindi, 'A' è la prima lettera, 'B' è la seconda lettera, 'C' è la terza lettera, e così via. Quando si sottrae il valore numerico di 'A' da una lettera, si ottiene l'indice di quella lettera nell'alfabeto.

        Ecco un esempio:

            'B' - 'A' restituirà 1, perché 'B' è la seconda lettera nell'alfabeto inglese.
            'C' - 'A' restituirà 2, perché 'C' è la terza lettera nell'alfabeto.
            'D' - 'A' restituirà 3, perché 'D' è la quarta lettera nell'alfabeto, e così via.

        */
        // C-A quindi 3 (cioe la terza posizione in alfabeto)-1 dara come valore 2
        // calcolo la posizione nell alfabeto
        j = carattere - 'A';
        j = (j + 3) % 26;
        t[i] = alfabeto[j];
    }
    //termina la struttra dell array
    // nuova[i] = '\0';
    // return nuova;
}