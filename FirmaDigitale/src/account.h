// account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <stdio.h>
// Struttura data account utente

typedef struct 
{
    char username[64];
    char password[64];
} UserAccount;

    // Crud

    // Creazione utente
    int
    RegisterUser(const char *username, const char *password);
#endif