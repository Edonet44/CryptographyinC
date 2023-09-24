#include <stdlib.h>
#include <stdio.h>



int main(){

    int i = 0;
    int dimension = 0;
    int somma = 0;

    printf("Scrivi la dimensione dell array");

    scanf("%d",&dimension);

    int *arr = (int*) malloc(dimension * sizeof(int));

for (i = 0; i < dimension; i++)
{
    somma += arr[i] + 1;
    printf("Somma attuale %d : %d\n",i,somma);
}
free(arr);
return 0;
}