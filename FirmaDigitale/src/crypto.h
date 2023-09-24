#ifndef CRYPTO_H
#define CRYPTO_H

#include <stdio.h>
#include <openssl/evp.h>

// file che permette di generare chiave pubblica e privata per Crittografia RSA
int generateRSAkeyPair(const char *privateKeyFile, const char *publicKeyFile, EVP_PKEY **privateKey, EVP_PKEY **publicKey);

#endif