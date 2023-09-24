#include <stdio.h>
#include <string.h> // Per la funzione strcmp
int reverse_Table();
#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limit */
#define STEP 20   /* step size */
/* utilizzo di getchar e putchar*/
int copyfile();
int interfaccia_grafica();

int main()
{
    // int lower, upper, step;
    // float fahr, celsius;
    // lower = 0;
    // upper = 300;
    // step=20;
    // fahr = lower;

    // printf("Tabella Fahrenheit - Celsius\n");
    // while (fahr<=upper)

    // {
    //     celsius = (5.0/9.0)*(fahr-32.0);
    //     printf("%4.0f %6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // };

    // reverse_Table();
    // copyfile();
    interfaccia_grafica();

    return 0;
}


int reverse_Table(){
    float fahr2;
    printf("Tabella Fahrenheit - Celsius (inversa)\n");
    for (fahr2 = 300; fahr2 >= 0; fahr2 = fahr2 - 20)
        printf("%4.0f %6.1f\n", fahr2, (5.0 / 9.0) * (fahr2 - 32));
}
int copyfile(){
    int c;
    char input[50]; // Una stringa per accumulare i caratteri inseriti dall'utente
    int index = 0;  // Indice corrente della stringa
    printf("Digita 'exit' o 'EXIT' per uscire:\n");

    while ((c = getchar()) != EOF)
    {
        /* finche non e finito input del getchar */
        input[index++] = c;
        // Controlla se la stringa contiene "exit" o "EXIT"
        if (strstr(input, "exit") != NULL || strstr(input, "EXIT") != NULL)
        {
            printf("Uscita richiesta. Chiudo il programma.\n");
            break;
        }
        // Se l'indice supera la lunghezza massima della stringa, reimposta l'indice
        if (index >= sizeof(input) - 1)
        {
            index = 0;
        }

        putchar(c); // Stampa il carattere
    }

    return 0;
    }
    int interfaccia_grafica(){


#define IN 1  // Dentro una parola
#define OUT 0 // Fuori da una parola

    
        int c;
        int state = OUT;
        int word_length = 0;

        printf("Inserisci il testo e premi Ctrl+D per terminare l'input.\n");

        while ((c = getchar()) != EOF)
        {
            if (c == ' ' || c == '\t' || c == '\n')
            {
                // Carattere di spazio o nuova riga: la parola è terminata
                if (state == IN)
                {
                    state = OUT;
                    putchar('\n'); // Vai a capo per iniziare una nuova riga
                    // Stampa asterischi per la lunghezza della parola
                    for (int i = 0; i < word_length; i++)
                    {
                        putchar('*');
                    }
                    putchar('\n');   // Vai a capo alla fine dell'istogramma
                    word_length = 0; // Resetta la lunghezza della parola
                }
            }
            else
            {
                // Carattere di parola
                state = IN;
                word_length++;
            }
        }

        return 0;
    }
    
    Minus(){


        
    }
    
