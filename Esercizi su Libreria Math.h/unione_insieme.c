/*
Unione di Insiemi:

Scrivi un programma che accetti due insiemi dati come input e
 calcoli l'unione dei due insiemi. Utilizza puntatori o altre 
strutture dati per rappresentare gli insiemi e
 cicli per combinare gli elementi dei due insiemi senza duplicati.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    int i, k;
    char *automobili[] = {"bmw","fiat","audi"};
    char *moto[] = {"yahama", "bmw", "ducati"};
    char nuovoInsieme[300];
//calcola la lunghezza degli array
    int lenghtAuto = sizeof(automobili) / sizeof(automobili[0]);
    int lenghtMoto = sizeof(moto) / sizeof(moto[0]);


//popola il nuovoinsieme con automobili
    for (i = 0; i < lenghtAuto; i++)
    {
        nuovoInsieme[i] = automobili[i];
    }


    int nuovoInsiemeLen = lenghtAuto; // Tieni traccia della lunghezza del nuovo insieme

    for (k = 0; k < lenghtMoto; k++)
    {
        //crea un true o false
        int duplicato = 0; // Flag per verificare se l'elemento di moto è un duplicato

        // Verifica se l'elemento di moto è già presente nell'insieme di automobili
        for (i = 0; i < lenghtAuto; i++)
        {
            if (strcmp(moto[k], automobili[i]) == 0) //confronta le strighe e vede se sono ugali a 0 se cosi duplicato prende 1
            {
                duplicato = 1;
                break;
            }
        }

        // Se non è un duplicato, aggiungilo al nuovo insieme
        if (!duplicato)
        {
            nuovoInsieme[nuovoInsiemeLen] = moto[k];
            nuovoInsiemeLen++;
        }
    }

    return 0;
}
