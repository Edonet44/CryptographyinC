#include <stdio.h>


int main(){

    char messaggioCifrato1[] = "1001001111000";
    char messaggioChiaro[] = "1001001111001";

    int lenghtKey = sizeof(messaggioCifrato1) - 1;

    int bitDiversi = 0; // Contatore per bit diversi tra messaggio cifrato e messaggio in chiaro
    int i = 0;
    for (i = 0; i < lenghtKey;i++)

    {
if (messaggioCifrato1[i]!=messaggioChiaro[i]){
    bitDiversi++;
}
    }

    double probErrore = (double)bitDiversi / lenghtKey;
    printf("Bit diversi: %d\n", bitDiversi);
    printf("Lunghezza chiave %d\n", lenghtKey);
    printf("Probabiltà di errpe %lf\n",probErrore);
}