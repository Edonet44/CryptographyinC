#include "boat.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Metodo per inserimento della nave

void creaNave(Boat *nave, char *nomeNave, float lunghezza, double stazza, int anno)
{
    char *nuovoArray[5];
    
    int i = 0;

    //associa i dati del nuovo array ad i dati passati dall utente
    snprintf(nuovoArray[i], sizeof(nuovoArray[i]), "Nome: %s", nomeNave);
    int posizioneNome = i; //variabile per tenere il posizionamento della stringa nomeNave
    i++;
    snprintf(nuovoArray[i], sizeof(nuovoArray[i]), "Lunghezza: %.2f metri", lunghezza);
    i++;
    snprintf(nuovoArray[i], sizeof(nuovoArray[i]), "Stazza: %.2lf", stazza);
    i++;
    snprintf(nuovoArray[i], sizeof(nuovoArray[i]), "Anno di costruzione: %d", anno);
    i++;

    int index = 0;
    //itera tutti gli elementi in maniera numerica perche ad associazione viene aggiunto un incremento ad i
    //finche e non arriva al 4 elemnto itera la condizione 
    while (index<i)
    {

        if (nuovoArray[index] == NULL || strlen(nuovoArray[index]) == 0)
        {
            printf("Errore: uno o più campi sono vuoti.\n");
            return; // Esci dalla funzione se un campo è vuoto
        }
        if (index == posizioneNome)//se sono nel nomeNave
        {
            //prende la lunghezza della parola immessa
            int lunghezzaNome = strlen(nomeNave); // Ora puoi verificare se il nomeNave contiene maiuscole
       //itera per tutte le lettere
        for (int j = 0; j < lunghezzaNome; j++)
        {
            //se trova una parola maiuscola la mette minuscola
            if (isupper(nomeNave[j])){
                nomeNave[j] = tolower(nomeNave[j]);
            }
        }
        
        }
        index++;
    }
    //se nome e maiuscolo modifica tutte le lettere in minuscolo tranne la prima
    
 
    

        // Inizializza i campi della nave con i nuovi dati forniti
        strcpy(nave->nomeNave, nomeNave);
    nave->lunghezzaNave = lunghezza;
    nave->stazzaNave = stazza;
    nave->annoNaveCostruzione = anno;
    nave->riparazioneNave = false;

    

}

void stampaNave(const Boat *nave)
{
    // Implementa la funzione qui
}

bool riparataNave(const Boat *nave)
{
    // Implementa la funzione qui
}

void ricercaNave(char *nome, Boat *nave)
{
    // Implementa la funzione qui
}

void eliminaNave(char *nome, Boat *nave)
{
    // Implementa la funzione qui
}

void salvaNavi(const char *filename, const Boat *nave, int numeroNavi)
{
    // Implementa la funzione qui
}

void caricaNavi(const char *filename, Boat **nave, int *numeroNavi)
{
    // Implementa la funzione qui
}