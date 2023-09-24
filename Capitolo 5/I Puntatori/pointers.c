#include <stdio.h>
#include <stdlib.h>

#define LNGTHARRAY 5

void scambia(int *a, int *b);
void copyString(char *dest, const char *src1, const char *src2);
int sommaArray(int *num);

//#define NULL 0
//funzone che riceve un puntatore e un intero
void esempio(int a, int *b);

int main()
{
    //     int i = 9;
    //     char c = 'a';

    //     int *pi;
    //     char *pc;

    //     printf("Char %lu byte - int %lu byte", sizeof(char *), sizeof(int *));

    //     pi = &i;
    //     pc = &c;

    //     printf("indirizzo di meomori di %p - indirizzo di memoria di c %p\n\n", pi, pc);
    //     printf("il valore di i %d= %d\n", i, *pi);
    //    // printf("il valore di %c= %c", c, *pc);

    //     i = 12;

    //     printf("il valore di i %d, il valore della cella puntata da pi= %d\n", i, *pi);

    //     *pi = 18;

    //     printf("il valore di i %d, il valore della cella puntata da pi= %d\n", i, *pi);

    // int x = 10;
    // int *ptr = &x;

    // printf("Il valore di x: %d\n", x);
    // printf("Il valore puntato da ptr: %d\n", *ptr);

    // *ptr = 20; // Modifica il valore a cui punta ptr
    // printf("Il nuovo valore di x: %d\n", x);

    // int x = 10;
    // int y = 20;

    // printf("Prima dello scambio x %d,y %d\n", x, y);
    // scambia(&x, &y);

    // printf("Dopo lo scambio x=%d, y=%d\n", x, y);

    // char s1[] = "stringa 1";
    // char s2[] = "stringa 2";
    // char destination[40];

    // copyString(destination,s1,s2);

    // printf("s1 %s\n", s1);
    // printf("s1 %s\n", s2);
    // printf("destination: %s\n",destination);


//dichiarazione per esplicito numeri interi in array
    // int numeri[LNGTHARRAY] = {33,34,65,456,77};
    // int result = sommaArray(numeri);

    // printf("il valore della somma %d",result);
    int *p;
    // se io voglio utilizzare un puntatore senza associare una variabile debbo utilizzare malloc per allocare lo spazio
//alloca una parte della memoria per il tipo intero e lo assegna a p
    p = malloc(sizeof(int));

    //controllo dell allocazione di memoria
    if (p == NULL)
    {
        printf("Non ho abbastanza memoria per l'allocazione\n");
        exit(1);
    }
//metto il valore
    *p = 12;
//aggiungo di uno
    (*p)++;
    printf("*p vale %d\n", *p);
    //------------------------------passaggio di puntatore a funzione
    /// http://www.diag.uniroma1.it/~liberato/struct/mempunt/passaggio.shtml
    int x;
    int y;
    int *z;

    x = 10;
    y = 43;
    z = &y;

    printf("Valori: x=%d y=%d z=%x\n", x, y, z);
//bisogna ricordare che nel primo caso cioe in x viene passato il valore, 
//mentre nel secondo caso cioe z  viene passato l indirizzo di y quindi avro una copia esatta della memoria
    esempio(x, z);

    printf("Valori: x=%d y=%d z=%x\n", x, y, z);

    /*


       1 quando si passa una variabile, il suo valore viene copiato, per cui le modifiche fatte all'interno della procedura non hanno effetto sulle variabili del programma principale;
       2 quando si passa un indirizzo, la funzione è in grado di modificare il contenuto della zona di memoria
         che parte da quell'indirizzo; le modifiche sono quindi modifiche a zone di memoria 
         in cui ci sono variabili del programma principale.


    */



//Puntatori di puntatori

    int a;
    int *t;
    int **tt;

    a = 9;

    t = &a;

    tt = &t;

    

    printf("Indirizzo di  a=%x, valore=%x\n", &a, a);
    printf("Indirizzo di  p=%x, valore=%x\n", &t, t);
    printf("Indirizzo di pp=%x, valore=%x\n", &tt, tt);

    return 0;
}

void scambia(int *a,int*b){
    int temp = *a;
    *a=*b;
    *b = temp;
}
void copyString(char *dest, const char *src1, const char *src2)
{

    while (*src1 != '\0')
    {
        *dest = *src1;
        src1++;
        dest++;
    }
    while (*src2 != '\0')
    {
        *dest = *src2;
        src2++;
        dest++;
    }
    *dest = '\0';
}


int sommaArray(int *num){

    int prodotto=1;
   // int sum=0;
    while (*num!=0){

        prodotto *= *num;

        num++;
}

return prodotto;
}
//intero e puntatore
void esempio(int a, int *b)
{
a = 12;

*b = 3;

b = NULL;
}