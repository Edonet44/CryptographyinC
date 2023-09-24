//account.c

#include "account.h"
#include <stdio.h>
//includo le librerie per la crittografia di windows
#include <windows.h>
#include <wincrypt.h>




//funzione per criptare password in chiave simmetrica AES
BOOL CriptaPass(const BYTE *plainText,DWORD plainTextSize,BYTE **testoCript,DWORD *sizeCript){
    // Questo oggetto rappresenta il contesto generale per le operazioni di crittografia e può essere visto come un "ambiente" o un "motore" che gestisce le operazioni di crittografia.
    HCRYPTPROV hProv = 0;
    // has  L'hash è un valore derivato dai dati originali e viene utilizzato per scopi di verifica dell'integrità dei dati
    HCRYPTHASH hHash = 0;
    // chiave Questo oggetto è utilizzato per crittografare o decrittografare i dati.
    HCRYPTKEY hKey = 0;

    // richiama la funzione  CryptAcquireContext #define CryptAcquireContext __MINGW_NAME_AW(CryptAcquireContext)
    // la specifica puo essere vista in CryptAcquireContext qui: https://docs.microsoft.com/en-us/windows/win32/api/wincrypt/nf-wincrypt-cryptacquirecontexta
    // come tipo viene utilizzato algoritmo AES
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
    {
        return FALSE;
    }
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash))
    {
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }
    if (!CryptHashData(hHash, plainText, plainTextSize, 0))
    {
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }

    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey))
    {
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }

    // Calcola la dimensione del buffer necessario
    if (!CryptEncrypt(hKey, 0, TRUE, 0, NULL, sizeCript, 0))
    {
        CryptDestroyKey(hKey);
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }

    *testoCript = (BYTE *)malloc(*sizeCript);
    if (*testoCript == NULL)
    {
        CryptDestroyKey(hKey);
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }

    // Cifra i dati
    if (!CryptEncrypt(hKey, 0, TRUE, 0, *testoCript, sizeCript, plainTextSize))
    {
        free(*testoCript);
        CryptDestroyKey(hKey);
        CryptDestroyHash(hHash);
        CryptReleaseContext(hProv, 0);
        return FALSE;
    }

    CryptDestroyKey(hKey);
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);

    return TRUE;
}

int RegisterUser(const char *username, const char *password){

    UserAccount newUser;
    
    // apro il fiel in modalita scrittura
    
    
}
