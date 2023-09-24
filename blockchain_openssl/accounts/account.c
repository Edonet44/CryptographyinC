#include "account.h"

#include <string.h>
#include <unistd.h>

#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>


bool create(BlockchainAccount *user,char *name){
    EVP_PKEY *key = EVP_PKEY_new();
    EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    EVP_PKEY_keygen(ctx);
    EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 4096);
    EVP_PKEY_keygen(ctx, &key);

    char path[64] = {0};
    strcat
}
