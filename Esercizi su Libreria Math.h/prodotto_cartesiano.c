/*
Prodotti Cartesiano in Insiemi:

Scrivi un programma che generi il prodotto cartesiano di due insiemi dati e lo visualizzi a schermo.
Gli insiemi possono essere rappresentati come array di interi o utilizzando altre strutture dati.
Utilizza cicli per iterare attraverso gli elementi dei due insiemi e visualizzare le coppie ordinate.

*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//char senza puntatore sta a significare un SOLO carattere
//
//array statici un puntatore char *testo={'esempio'}
// array dinamici ovvero con la capacita di aumentare o diminuire durante l esecuzione del programma hanno
//
//bisogno di doppio puntatore e realloc o malloc




int main(){

    char *squadra = {'Milan','Inter','Torino'};
    char *risultato = {'1','x','2'};
    char nuovo[100];

    int lnghtSQ = strlen(squadra) / sizeof(squadra[0]);
    int lnghtRS = strlen(risultato) / sizeof(risultato[0]);

    int i, k;
            for ( i = 0; i <lnghtSQ; i++)
                {
                   for (k = 0; k <lnghtRS; k++)
                   {
                    //funzione per formattare una stringa e salvaral in un array di caratteri
                       sprintf(nuovo, "%s - %s", squadra[i], risultato[k]);
                       printf("Stampa elenco delle squadre %s\n", nuovo);
                   }
                 
                }

                return 0;
            }