#include <stdio.h>
#include <stdlib.h>
//dichiarazioni delle funzioni
//rimuove tutte le occorrenze del carattere c dalla stringa s
 void squeeze(char s[], char c);
 int any(char s1[], char s2[]);

 int main()
 {
    //richiamo funzione squeez
     // dichiaro le variabili c come string e s come array di stringhe
    //  char c, s[100];
    //  printf("Inserisci una stringa");
    //  // segnaposto per una stringa e suo valore
    //  scanf("%s", s);
    //  while ((getchar()) != '\n')
    //      ;
    //  printf("Inserisci il carattere da rimuovere");
    //  scanf("%c", &c);
    //  // rihciamo della funzione
    //  squeeze(s, c);
    //  printf("Stringa dopo la rimozione del carattere %s\n", s);

     char s1[100], s2[100];
     printf("Inserisci una stringa");
     // segnaposto per una stringa e suo valore
     scanf("%s", s1);
     while ((getchar()) != '\n')
         ;
     printf("Inserisci la parola da rimuovere");
     scanf("%s", s2);
     // rihciamo della funzione
     int result=any(s1, s2);
     if (result!=-1){
         printf("Il primo carattere di s2 si trova in posizione %d di s1.\n", result);
     }
     else
     {
         printf("Nessun carattere di s2 trovato in s1.\n");
     }
     

     return 0;
}

void squeeze(char s[],char c){

    {
        //variabili per i
        int i, j = 0;
        //for per iterare il mio array di caratteri
         for (i = 0; s[i] != '\0'; i++)
        {
            // se iterando i caratteri sono diversi da c
            if(s[i]!=c){
                //aggiunge ad un nuovo array il carattere della stringa
                s[j] = s[i];
                //incrementa
                j++;
            }
            }
                //fine dell array di stringhe
                s[j] = '\0';
    }
}

int any(char s1[],char s2[]){
    
    int i, j=0;

    for (i = 0; s1[i] != '\0';i++)
    {
                for (j = 0; s2[j] != '\0';j++)
                {
                    if(s1[i]==s2[j]){
                            return i;
                    }
                }
    }
    return -1;
}