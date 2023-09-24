#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include "crypto.h"

int generateRSAkeyPair(const char *privateKeyFile, const char *publicKeyFile, EVP_PKEY **privateKey, EVP_PKEY **publicKey)
{
    // Inizializza OpenSSL
    OpenSSL_add_all_algorithms();

    // Crea una nuova chiave RSA
    EVP_PKEY *keyPair = EVP_PKEY_new();
    // RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();

    // Imposta l'esponente pubblico
    BN_set_word(e, RSA_F4);

    // Genera la coppia di chiavi
    // if (!RSA_generate_key_ex(rsa, 2048, e, NULL))
    // {
    //     printf("Errore nella generazione delle chiavi RSA\n");
    //     BN_free(e);
    //     RSA_free(rsa);
    //     EVP_PKEY_free(keyPair);
    //     return 0;
    // }

    // Imposta la chiave RSA come chiave privata
    // if (!EVP_PKEY_set1_RSA(keyPair, rsa))
    // {
    //     printf("Errore nell'impostare la chiave privata\n");
    //     RSA_free(rsa);
    //     EVP_PKEY_free(keyPair);
    //     return 0;
    // }

    // Salva la chiave privata su disco
    FILE *privateKeyFilePtr = fopen(privateKeyFile, "wb");
    if (!privateKeyFilePtr)
    {
        printf("Impossibile aprire il file della chiave privata\n");
        BN_free(e);
        //RSA_free(rsa);
        EVP_PKEY_free(keyPair);
        return 0;
    }

    if (!PEM_write_PrivateKey(privateKeyFilePtr, keyPair, NULL, NULL, 0, NULL, NULL))
    {
        printf("Errore nella scrittura della chiave privata\n");
        fclose(privateKeyFilePtr);
        BN_free(e);
       // RSA_free(rsa);
        EVP_PKEY_free(keyPair);
        return 0;
    }

    fclose(privateKeyFilePtr);

    // Ora, per generare la chiave pubblica, possiamo estrarre la parte pubblica dalla chiave privata
    EVP_PKEY *publicKeyExtracted = EVP_PKEY_new();
    if (!EVP_PKEY_copy_parameters(publicKeyExtracted, keyPair) || !EVP_PKEY_set1_RSA(publicKeyExtracted, RSA_new()))
    {
        printf("Errore nell'estrazione della chiave pubblica\n");
        BN_free(e);
       // RSA_free(rsa);
        EVP_PKEY_free(keyPair);
        EVP_PKEY_free(publicKeyExtracted);
        return 0;
    }

    // Salva la chiave pubblica su disco
    FILE *publicKeyFilePtr = fopen(publicKeyFile, "wb");
    if (!publicKeyFilePtr)
    {
        printf("Impossibile aprire il file della chiave pubblica\n");
        BN_free(e);
        //RSA_free(rsa);
        EVP_PKEY_free(keyPair);
        EVP_PKEY_free(publicKeyExtracted);
        return 0;
    }

    if (!PEM_write_PUBKEY(publicKeyFilePtr, publicKeyExtracted))
    {
        printf("Errore nella scrittura della chiave pubblica\n");
        fclose(publicKeyFilePtr);
        BN_free(e);
        //RSA_free(rsa);
        EVP_PKEY_free(keyPair);
        EVP_PKEY_free(publicKeyExtracted);
        return 0;
    }

    fclose(publicKeyFilePtr);

    // Assegna le chiavi pubbliche e private passate come argomento
    if (privateKey)
    {
        *privateKey = keyPair;
    }
    else
    {
        EVP_PKEY_free(keyPair);
    }

    if (publicKey)
    {
        *publicKey = publicKeyExtracted;
    }
    else
    {
        EVP_PKEY_free(publicKeyExtracted);
    }

    BN_free(e);
    //RSA_free(rsa);
    return 1; // Successo
}

// int main()
// {
//     const char *privateKeyFile = "private_key.pem";
//     const char *publicKeyFile = "public_key.pem";
//     EVP_PKEY *privateKey = NULL;
//     EVP_PKEY *publicKey = NULL;

//     if (generateRSAkeyPair(privateKeyFile, publicKeyFile, &privateKey, &publicKey))
//     {
//         printf("Coppia di chiavi RSA generata con successo!\n");
//     }
//     else
//     {
//         printf("Errore nella generazione della coppia di chiavi RSA.\n");
//     }

//     // Liberare le chiavi quando non sono più necessarie
//     if (privateKey)
//     {
//         EVP_PKEY_free(privateKey);
//     }

//     if (publicKey)
//     {
