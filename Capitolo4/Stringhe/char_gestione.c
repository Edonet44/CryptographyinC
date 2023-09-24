

#include <stdlib.h>
#include <stdio.h>


/*
Stampare stringa utilizzando un puntatore
*/


int main()
{

    char *nuova="edoardo stronzo";

while (*nuova!='\0')
{
    printf("%s", *nuova);
    nuova++;
}

return 0;
}