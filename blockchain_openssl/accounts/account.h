#ifndef ACCOUNT_H
#define ACCOUNT_H

// Definizione della struttura dati per un account blockchain
typedef struct
{
    int account_number;   // Numero di conto univoco
    double balance;       // Saldo dell'account
    char public_key[64];  // Chiave pubblica
    char private_key[64]; // Chiave privata (da gestire con estrema sicurezza)
} BlockchainAccount;
// prototipi per le funzioni di blockchain
void createAccount(BlockchainAccount *account, int account_number, double initial_balance);
double getBalance(const BlockchainAccount *account);
void deposit(BlockchainAccount *account, double amount);
void withdraw(BlockchainAccount *account, double amount);

#endif;