#include <stdlib.h>
#include <stdio.h>

//funzione con array e studio delle matrici e gestione della memoria
int main(){
    int i = 0;
    int dimension = 5;
    //alloca dinamicamente una matrice di 5 interi
    int **matrice = (int **)malloc(dimension *sizeof(int *));
    
    //verifica se l allocazione e riuscita
    if(matrice==NULL){
        perror("Errore allocazione di memoria");
        return 1;
    }
    
    for (i = 0; i < dimension; i++)
        
    {
        matrice[i] = (int *)malloc(sizeof(int));
//assegnazione elemento array
        *matrice[i] = i + 1;

        printf("Elemento %d: %d\n", i, *matrice[i]);
    }

    //deallocazione della memoria
    for (i = 0; i < dimension; i++)
    {
        free(matrice[i]);
    }
    return 0;
}