
/*Calcolo del Massimo Comun Divisore (MCD):

Scrivi una funzione che calcoli il massimo comun divisore di due numeri interi utilizzando l'algoritmo di Euclide. Utilizza cicli e aritmetica modulare per calcolare l'MCD.
*/

#include <stdlib.h>
#include <stdio.h>

int mcd(int a, int b);

int main()
{

    int a, b;

    printf("inserisci il primo numero");
    scanf("%d",&a);
    printf("inserisci il secondo numero");
    scanf("%d",&b);

    int result = mcd(a,b);
    printf("Il MCD e fra %d,%d, è: %d",a,b,result);
}

int mcd(int a, int b)
{
   
    int result;
    int resto;
    
    //se il valore di a e minore allora scambio il posto delle variabili
        if(a<b){
            //allora scambia b con a
            int temp = a;
            a = b;
            b = temp;
        }
        //se a e uguale a b allora l mcd e il valore di b
        if(a=b){
            result = b;
            return result;
        }
            while (b!=0)
            {
                resto = a % b;
                a = b;
                b = resto;
            }
    return result;
}