/*
Struttura per la prenotazione di un cinema
Ecco un esercizio che coinvolge una struttura complessa con puntatori, l'allocazione dinamica di memoria e un problema con booleani e funzioni:

Supponiamo di voler gestire un sistema di prenotazioni per un cinema. Dobbiamo tenere traccia dei dettagli di ciascuna prenotazione, inclusi il nome del cliente, il numero di posti prenotati e se il pagamento è stato effettuato o meno.

    Definire una struttura  Prenotazione che rappresenti una prenotazione al cinema. La struttura dovrebbe contenere campi come:
        nomeCliente (puntatore a una stringa)
        numPosti (un intero)
        pagamentoEffettuato(un booleano)

    Scrivere una funzione  creaPrenotazione che accetti il nome del cliente, il numero di posti prenotati e un valore booleano per indicare se il pagamento è stato effettuato o meno.
 Questa funzione dovrebbe allocare dinamicamente la memoria per una nuova  Prenotazione, inizializzare i campi e restituire un puntatore alla prenotazione creata.

    Scrivere una funzione  stampaNomeCliente che accetti una prenotazione e stampi il nome del cliente.

    Scrivere una funzione  pagaPrenotazione che accetti una prenotazione e imposti il campo  pagamentoEffettuato su  true.

    Scrivere una funzione  annullaPrenotazione che accetti una prenotazione e liberi la memoria allocata per quella prenotazione.

    Nel  main, creare alcune prenotazioni, stamparne i dettagli e verificarne lo stato del pagamento. Puoi anche eseguire il pagamento per alcune prenotazioni e quindi verificare nuovamente lo stato del pagamento.

    Gestire la memoria in modo appropriato, assicurandosi di deallocare la memoria per le prenotazioni annullate e alla fine del programma.

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char nomeCliente[100];
    int numPosti[50];
    bool pagamentoEffettuato;
    char **ratingMovie;
    int dimensioneRatingMovie; // questa variabile e utile per rendere dinamico l array

} Prenotazione;
// crea la prenotazione
void creaPrenotazione(Prenotazione p)
{

    Prenotazione *p2;
    // char cliente = p.nomeCliente;
    // int posti = p.numPosti;
    // bool pagamento = p.pagamentoEffettuato;

    // alloco la memoria
    p2 = malloc(sizeof(Prenotazione));
    strcpy((*p2).nomeCliente, p.nomeCliente);
    strcpy((*p2).nomeCliente, p.numPosti);
    strcpy((*p2).nomeCliente, p.pagamentoEffettuato);
}
// funzione per stampare il nome cliente
void stampaNomeCliente(Prenotazione p)
{
    printf("il nome del cliente é: %s, il numero posti disponibili sono %d, il pagamento e %s\n", p.nomeCliente, p.numPosti, p.pagamentoEffettuato);
}
// funzione paga prenotazione
bool pagaPrenotazione(Prenotazione p)
{
    return p.pagamentoEffettuato;
}
// viene passato il puntatore perche deve essere deallocata la memoria
void annullaPrenotazione(Prenotazione *p)
{
    free(p);
}
// metodo per classificare i movie viene messo il puntatore perche deve allocare la memoria
// allocazionne di memoria
void ratingMovie(Prenotazione *p, int dimension)
{
    p->ratingMovie = (char **)malloc(dimension * sizeof(char *));
    // mettimi per ogni rating una dimensione nulla
    for (int i = 0; i < dimension; i++)
    {
        p->ratingMovie[i] = NULL; // inizializzato con valori null pre prendere spazio in memoria
    }
}
// aggiungi RatingMovie e rialloca la memoria per aggiungere il rating movie a lunghezza variabile
void aggiungiRatingMovie(Prenotazione *p, const char *film)
{
    int nuovaDimensione = p->dimensioneRatingMovie + 1;
    // rialloca la memoria per aggiungere spazio
    p->ratingMovie = (char **)realloc(p->ratingMovie, nuovaDimensione * sizeof(char *));
    if (p->ratingMovie != NULL)
    {
        // Alloca memoria per il nuovo rating
        p->ratingMovie[p->dimensioneRatingMovie] = strdup(film);
        p->dimensioneRatingMovie = nuovaDimensione; // Aggiorna la dimensione
    }
    else
    {
        printf("Errore durante l'allocazione di memoria per il nuovo rating.\n");
    }
}

// deallocazione di memoria
void deallocaRating(Prenotazione *p, int dimension)
{
    // dealloca le stringhe create
    for (int i = 0; i < dimension; i++)
    {
        free(p->ratingMovie[i]);
    }
    // dealloca il puntatore di puntatore
    free(p->ratingMovie);
    // lo setta su nullo
    p->ratingMovie = NULL;
}

int main()
{
    // creo l istanza
    Prenotazione prenotazione;
    int dimensioneRatingMovie = 10;

    char nomeCliente[50];
    int numPosti = 20;
    bool prenotato = false;

    printf("Inserisci nome cliente \n");

    scanf("%s", &nomeCliente);
    printf("Inserisci numero posti \n");

    //metodo per inizializzare l array di ratingmovie
    ratingMovie(&prenotazione, 10); // Inizialmente impostato a 10

    //metodo per aggiugner movie in grandezza variabile
    aggiungiRatingMovie(&prenotazione, "Oppenheimer");
    aggiungiRatingMovie(&prenotazione, "Barbie");
    aggiungiRatingMovie(&prenotazione, "Indiana Jones V");

    // Accedi ai valori all'interno dell'array e stampali
    for (int i = 0; i < prenotazione.dimensioneRatingMovie; i++)
    {
        if (prenotazione.ratingMovie[i] != NULL)
        {
            printf("Rating Movie %d: %s\n", i + 1, prenotazione.ratingMovie[i]);
        }
        else
        {
            printf("Rating Movie %d: Nessun rating disponibile\n", i + 1);
        }
    }

    // Quando hai finito, dealloca la memoria:
    deallocaRatingMovie(&prenotazione);

    return 0;
}