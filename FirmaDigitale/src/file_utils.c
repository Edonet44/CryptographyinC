
#include <wchar.h> // Per C
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

#define SEEK_END 2

// Apertura e lettura di un file
wchar_t *openAndReadFile(const wchar_t *file_name, long *file_size)
{
    FILE *file = _wfopen(file_name, L"rb");
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        *file_size = ftell(file); // Memorizza la dimensione del file nella variabile puntata da file_size
        fseek(file, 0, SEEK_SET);

        wchar_t *file_content = (wchar_t *)malloc((*file_size + 1) * sizeof(wchar_t));
        if (file_content != NULL)
        {
            fread(file_content, sizeof(wchar_t), *file_size, file);
            file_content[*file_size] = L'\0';

            // Ora 'file_content' contiene il contenuto del documento.

            fclose(file);
            return file_content; // Restituisce il puntatore al contenuto del file
        }
        else
        {
            // Errore nella lettura del documento.
            fclose(file);
            *file_size = -1; // Imposta *file_size a un valore speciale per indicare l'errore
            return NULL;
        }
    }
    else
    {
        // Errore nell'apertura del documento.
        *file_size = -1; // Imposta *file_size a un valore speciale per indicare l'errore
        return NULL;
    }
}
