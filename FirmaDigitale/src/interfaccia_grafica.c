#define _UNICODE
#define UNICODE

#include <windows.h>
#include <stdlib.h>
#include <commdlg.h>
#include "file_utils.h"
#include "crypto.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>

// Dichiarazione globale di inputBuffer
WCHAR inputBuffer[256] = {0}; // Inizializza il buffer a zero

// Dichiarazione della stringa wide per il nome della classe
WCHAR szClassName[] = L"MyApp";

// Dichiarazione delle procedure di gestione degli eventi
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void OnCifra(HWND hwnd);
void OnDecifra(HWND hwnd);

// Gestione dell'applicazione
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // bottone decifra disabilitato al caricamento
    BOOL isDecifraEnabled = FALSE;

    // istanzia la creazione della finestra windows
    WNDCLASSEXW wcex = {sizeof(WNDCLASSEX)};
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.lpszClassName = szClassName;

    if (!RegisterClassExW(&wcex))
    {
        // La registrazione della classe ha fallito
        MessageBox(NULL, L"La registrazione della classe ha fallito!", L"Errore", MB_ICONERROR);
        return -1;
    }

    // Creazione della finestra
    HWND hwnd;
    hwnd = CreateWindowExW(0, szClassName, L"Applicazione di Crittografia", WS_OVERLAPPEDWINDOW,
                           CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, NULL, NULL, hInstance, NULL);
    HWND hwndButtonCifra;
    HWND hwndButtonDecifra;
    HWND hwndTextBox;

    // Creazione della finestra di cifratura
    hwndButtonCifra = CreateWindow(
        L"BUTTON",                                             // Classe del controllo
        L"Cifra",                                              // Testo del pulsante
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Stili del controllo
        10, 10, 80, 30,                                        // Posizione e dimensioni
        hwnd,                                                  // Handle della finestra padre
        (HMENU)1,                                              // ID del controllo
        NULL,                                                  // Handle dell'istanza
        NULL                                                   // Parametri aggiuntivi
    );

    hwndButtonDecifra = CreateWindow(
        L"BUTTON",                                             // Classe del controllo
        L"Decifra",                                            // Testo del pulsante
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // Stili del controllo
        100, 10, 80, 30,                                       // Posizione e dimensioni
        hwnd,                                                  // Handle della finestra padre
        (HMENU)2,                                              // ID del controllo
        NULL,                                                  // Handle dell'istanza
        NULL                                                   // Parametri aggiuntivi
    );
    // disabilito all avvio il bottone decifra
    EnableWindow(hwndButtonDecifra, isDecifraEnabled);

    // Creazione del textbox
    hwndTextBox = CreateWindow(
        L"EDIT",                                            // Classe del controllo
        L"",                                                // Testo iniziale
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, // Stili del controllo
        10, 50, 300, 30,                                    // Posizione e dimensioni
        hwnd,                                               // Handle della finestra padre
        (HMENU)3,                                           // ID del controllo
        NULL,                                               // Handle dell'istanza
        NULL                                                // Parametri aggiuntivi
    );

    // Ignoriamo nCmdShow
    UNREFERENCED_PARAMETER(nCmdShow);
    // Visualizzazione della finestra
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    if (hwnd == NULL)
    {
        // La creazione della finestra ha fallito
        MessageBox(NULL, L"La creazione della finestra ha fallito!", L"Errore", MB_ICONERROR);
        return -1;
    }

    // Ciclo principale del messaggio
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

// Procedure di gestione degli eventi
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == 1) // ID del pulsante Cifra
        {
            OnCifra(hwnd);
        }
        else if (LOWORD(wParam) == 2) // ID del pulsante Decifra
        {
            OnDecifra(hwnd);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Gestione dell'evento di cifratura
void OnCifra(HWND hwnd)
{

    // Chiama la funzione per generare la coppia di chiavi RSA
    RSA *rsaPrivateKey = NULL;
    RSA *rsaPublicKey = NULL;

    EVP_PKEY *privateKey = NULL;
    EVP_PKEY *publicKey = NULL;

    // Dichiarazione di una struttura per la finestra di dialogo "Apri file"
    OPENFILENAME ofn;

    // Inizializza la struttura
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = inputBuffer; // Utilizza il buffer inputBuffer per memorizzare il percorso del file
    ofn.nMaxFile = sizeof(inputBuffer);
    ofn.lpstrFilter = L"Tutti i file\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Mostra la finestra di dialogo "Apri file"
    if (GetOpenFileName(&ofn) == TRUE)
    {
        // L'utente ha selezionato un file da aprire, il percorso del file è in inputBuffer.
        // Puoi ora eseguire le operazioni desiderate sul file aperto.
        long file_size;
        wchar_t *file_content = openAndReadFile(inputBuffer, &file_size);
        // creazione delle chiavi pubbliche e private
        if (generateRSAkeyPair("private_key.pem", "public_key.pem", &privateKey, &publicKey))
        {
            printf("Coppia di chiavi RSA generata con successo.\n");
           
        }
        else //errore generazione coppia chiavi pubblica e privata
        {
            // Gestisci l'errore se la generazione delle chiavi fallisce.
            MessageBox(hwnd, L"Errore nella generazione delle chiavi RSA", L"Errore", MB_ICONERROR);
        }

        // libero la memoria
        free(file_content);
    }
    else  //chiusura anticipata del file
    {
        // L'utente ha annullato l'apertura del file o si è verificato un errore.
        MessageBox(hwnd, L"Testo cifrato", L"Cifratura interotta", MB_OK | MB_ICONINFORMATION);
    }

    // Recupera il testo dalla casella di testo
    TCHAR inputBuffer[256];
    GetWindowText(GetDlgItem(hwnd, 1), inputBuffer, sizeof(inputBuffer));

   
    // Visualizza il risultato (per ora, visualizza solo una finestra di messaggio)
    MessageBox(hwnd, L"Testo cifrato", L"Cifratura", MB_OK | MB_ICONINFORMATION);
}

// Gestione dell'evento di decifratura
void OnDecifra(HWND hwnd)
{
    // Recupera il testo dalla casella di testo
    TCHAR inputBuffer[256];
    GetWindowText(GetDlgItem(hwnd, 1), inputBuffer, sizeof(inputBuffer));

    // Esegui la decifratura qui (assegna il risultato a 'testoDecifrato')
    // Sostituisci questo commento con la tua logica di decifratura.

    // Supponiamo che il risultato della decifratura sia stato assegnato a 'testoDecifrato'.
    TCHAR testoDecifrato[256]; // Dichiarazione della variabile 'testoDecifrato'.

    // Visualizza il risultato nella finestra di messaggio (per ora, visualizza solo una finestra di messaggio)
    MessageBox(hwnd, testoDecifrato, L"Decifratura", MB_OK | MB_ICONINFORMATION);
}
