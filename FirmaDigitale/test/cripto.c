#include <stdio.h>

// Funzione per eseguire XOR tra due blocchi di dati
void xorBlocks(unsigned char *block1, unsigned char *block2, int size)
{
    for (int i = 0; i < size; i++)
    {
        block1[i] ^= block2[i];
    }
}

int main()
{
    // Esempio 1: Esecuzione di XOR tra due blocchi di dati
    unsigned char block1[] = {0x12, 0x34, 0x56, 0x78};
    unsigned char block2[] = {0xAB, 0xCD, 0xEF, 0x01};
    int size = sizeof(block1);

    xorBlocks(block1, block2, size);

    printf("Risultato dell'XOR tra block1 e block2:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%02X ", block1[i]);
    }
    printf("\n");

    // Esempio 2: Decifratura di un messaggio cifrato utilizzando XOR
    unsigned char ciphertext[] = {0x3D, 0x39, 0x1F, 0x79};
    unsigned char key[] = {0xAB, 0xCD, 0xEF, 0x01};
    int msgSize = sizeof(ciphertext);

    xorBlocks(ciphertext, key, msgSize);

    printf("Messaggio decifrato:\n");
    for (int i = 0; i < msgSize; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
