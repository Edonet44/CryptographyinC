#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>
#include <wchar.h>

/**
 * Apre un file specificato e ne legge il contenuto.
 *
 * @param file_name Il nome del file da aprire e leggere.
 * @param file_size Un puntatore a una variabile di tipo long in cui verrà
 *                  memorizzata la dimensione del file letto.
 * @return Un puntatore a una stringa che contiene il contenuto del file letto.
 *         È responsabilità del chiamante liberare la memoria allocata per questa stringa.
 *         In caso di errore nell'apertura o nella lettura del file, restituisce NULL.
 */
wchar_t *openAndReadFile(const wchar_t *file_name, long *file_size);

#endif
