/*
Esercizio su esponenziazione modulare

data la formula : c ≡ a^e (mod n)

Dove a è la base, e è l'esponente, n è il modulo e c è il risultato dell'esponenziazione modulare.


Scrivi una funzione che calcoli l'esponenziazione modulare di un numero a elevato a una potenza b modulo m.
 Utilizza cicli e l'aritmetica modulare per calcolare il risultato.






*/


#include <stdio.h>
#include <stdlib.h>

long long moduloEsp(long long base, long long esponente, long long modulo);

int main()
{

    int a, p, n;
    float result;
    
    printf("Dammi la base %d",a);
    scanf("%d", a);

    printf("Dammi la potenza %d", p);
    scanf("%d", p);

    printf("Dammi il modulo %d", p);
    scanf("%d", n);

    result = moduloEsp(a, p, n);

    printf("L esponeziazion modulare e:", result);

    return 0;
}
//a=base
//p=esponente
//n=modulo
// long long espMod(long long a, long long p, long long n){

//     long long risultato = 1;
//     // Calcola il resto di a diviso n e assegna il risultato ad a.
//     a = a % n;
//     // Inizia un ciclo while con b come condizione di uscita

//     //finche l esponente e maggiore di 0
//     while (p > 0)
//     {
//         result = ()
// }

long long moduloEsp(long long base, long long esponente, long long modulo)
{
    long long risultato = 1;
    // Calcola il resto di a diviso n e assegna il risultato ad a.
    base = base % modulo;
    // Inizia un ciclo while con b come condizione di uscita
    while (esponente > 0)
    {
        //verifica se esponente è dispari
        if (esponente % 2 == 1)
        {
            //risultato prende come valore risultato * base % modulo 
            risultato = (risultato * base) % modulo;
        }
        //se esponsnte e pari
        //base prende base * base % modulo
        base = (base * base) % modulo;
        //esponenete prende esponente /2
        esponente = esponente / 2;
    }

    return risultato;
}
