#ifndef BOAT_H
#define BOAT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/*
Classe per la gestione delle navi del cantiere

*/

typedef struct 
{
    char nomeNave[20];
    float lunghezzaNave;
    double stazzaNave;
    int  annoNaveCostruzione;
    bool riparazioneNave;

} Boat;


//Metodo per la creazione della nave
void creaNave(Boat *nave, char *nomeNave, float lunghezza, double stazza, int anno);
//Metodo stampa singola nave
void stampaNave(const Boat *nave);
//Metodo che ritorna un valore true/false per riaparazion
bool riparataNave(const Boat *nave);
//Metodo ricerca e stampa
void ricercaNave(char *nome, Boat *nave);
//Metodo per eliminazione nave in base al nome
void eliminaNave(char *nome, Boat *nave);
//Salva su File
void salvaNave(const char *filename, const Boat *nave);
//Carica nave da file
void caricaNave(const char *filename, Boat **nave);

#endif