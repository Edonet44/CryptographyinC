/*
Crittografia simmetrica: Scrivi un programma per 
cifrare un messaggio di testo in chiaro utilizzando un algoritmo di crittografia 
simmetrica (ad esempio, AES). Utilizza 
variabili temporanee per memorizzare chiavi temporanee e dati intermedi durante il processo di cifratura.

*/

#include <stdlib.h>
#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <string.h>

int main()
{
    // Messaggio
    unsigned char plaintext[] = "Messaggio da cifrare";
    int plaintext_len = strlen((char *)plaintext);

    // Chiave
    unsigned char key[16]; // Chiave AES a 128 bit (16 byte)
    if (RAND_bytes(key, sizeof(key)) != 1)
    {
        fprintf(stderr, "Errore nella generazione della chiave.\n");
        return 1;
    }

    // Variabili temporanee per dati intermedi
    unsigned char ciphertext[plaintext_len + EVP_MAX_BLOCK_LENGTH]; // Per memorizzare il testo cifrato
    unsigned char decryptedtext[plaintext_len];                     // Per memorizzare il testo decifrato

    // Inizializzazione del contesto di crittografia
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    // Impostazione del cifrario AES a 128 bit in modalità CBC
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);

    // Cifratura del messaggio
    int len1 = 0;
    int len2 = 0;
    EVP_EncryptUpdate(ctx, ciphertext, &len1, plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + len1, &len2);

    // Stampa del risultato cifrato
    printf("Messaggio originale: %s\n", plaintext);
    printf("Messaggio cifrato: ");
    for (int i = 0; i < len1 + len2; i++)
    {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Impostazione del cifrario AES a 128 bit in modalità CBC per la decifratura
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);

    // Decifratura del messaggio
    int len3 = 0;
    int len4 = 0;
    EVP_DecryptUpdate(ctx, decryptedtext, &len3, ciphertext, len1 + len2);
    EVP_DecryptFinal_ex(ctx, decryptedtext + len3, &len4);

    // Stampa del risultato decifrato
    printf("Messaggio decifrato: %s\n", decryptedtext);

    // Pulizia delle risorse
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}
