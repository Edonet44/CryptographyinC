#include <stdio.h>


int main(){
    size_t n = 0;
    unsigned int x = 10;

    while (x!=0)
    {
        n++;
        x = x << 1;
    }
    printf("Lunghezza della parola sulla tua macchina: %zu bit\n", n);
    return 0;
}