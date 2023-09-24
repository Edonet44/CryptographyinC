#include <stdio.h>
#include <stdlib.h>

int sommaBitaBit(int num1,int num2);

int main(){

    int num1, num2;
    printf("Inserisci il primo numero");

    scanf("%d",&num1);
    while (getchar() != '\n')
    {
        // Pulizia del buffer di input
    }
    printf("Inserisci il secondo numero");
    scanf("%d", &num2);

    int result = sommaBitaBit(num1, num2);

    printf("il risultato della somma e %d\n",result);
    return 0;
}

int sommaBitaBit(int num1, int num2)
{
    int result = num1 | num2;
    return result;
}