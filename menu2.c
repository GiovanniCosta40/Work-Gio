#include <stdio.h>
#include <string.h>

void mostraLista(const char lista[][20], int n, const char *titolo);
void inserisciPazienti();
void programmaMenu();

void programmaMenu() {
    int scelta;

    // Mostra il menu all'utente
    do {
        printf("\nMenu Principale:\n");
        printf("1. Lista utenti per ordine alfabetico\n");
        printf("2. Lista medici di servizio\n");
        printf("3. Lista infermieri di servizio\n");
        printf("4. Inserisci pazienti per operazioni urgenti\n");
        printf("0. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        // Pulisce il buffer di input dopo scanf
        while (getchar() != '\n');

        switch (scelta) {
            case 1: {
                char utenti[][20] = {"Luca", "Anna", "Giovanni", "Maria", "Francesco"};
                int n = sizeof(utenti) / sizeof(utenti[0]);

                // Ordinamento della lista utenti in ordine alfabetico
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (strcmp(utenti[i], utenti[j]) > 0) {
                            char temp[20];
                            strcpy(temp, utenti[i]);
                            strcpy(utenti[i], utenti[j]);
                            strcpy(utenti[j], temp);
                        }
                    }
                }
                mostraLista(utenti, n, "Lista utenti in ordine alfabetico");
                break;
            }

            case 2: {
                char medici[][20] = {"Dr. Rossi", "Dr. Bianchi", "Dr. Verdi"};
                int n = sizeof(medici) / sizeof(medici[0]);
                mostraLista(medici, n, "Lista medici di servizio");
                break;
            }

            case 3: {
                char infermieri[][20] = {"Giulia Romano", "Marco Bianchi", "Sofia Conti"};
                int n = sizeof(infermieri) / sizeof(infermieri[0]);
                mostraLista(infermieri, n, "Lista infermieri di servizio");
                break;
            }

            case 4:
                inserisciPazienti();
                break;

            case 0:
                printf("Uscita dal programma.\n");
                break;

            default:
                printf("Opzione non valida! Riprova.\n");
        }
    } while (scelta != 0);  // Il menu continua finché l'utente non sceglie 0
}

void mostraLista(const char lista[][20], int n, const char *titolo) {
    char scelta;
    do {
        printf("\n%s:\n", titolo);
        for (int i = 0; i < n; i++) {
            printf("%s\n", lista[i]);
        }
        printf("Premi 'm' per tornare al menu principale: ");
        scanf(" %c", &scelta);
        // Pulisce il buffer di input dopo scanf
        while (getchar() != '\n');
    } while (scelta != 'm' && scelta != 'M');
}

void inserisciPazienti() {
    int n;
    printf("\nQuanti pazienti devono essere operati d'urgenza? ");
    scanf("%d", &n);
    // Pulisce il buffer di input dopo scanf
    while (getchar() != '\n');

    char pazienti[n][30];  // Array per memorizzare i nomi dei pazienti
    for (int i = 0; i < n; i++) {
        printf("Inserisci il nome del paziente %d: ", i + 1);
        fgets(pazienti[i], 30, stdin);
        pazienti[i][strcspn(pazienti[i], "\n")] = 0;  // Rimuove il carattere di nuova linea
    }

    char scelta;
    do {
        printf("\nPazienti da operare d'urgenza:\n");
        for (int i = 0; i < n; i++) {
            printf("%s\n", pazienti[i]);
        }
        printf("Premi 'm' per tornare al menu principale: ");
        scanf(" %c", &scelta);
        // Pulisce il buffer di input dopo scanf
        while (getchar() != '\n');
    } while (scelta != 'm' && scelta != 'M');
}

int main() {
    // Chiamata alla funzione programmaMenu che contiene tutto il programma
    programmaMenu();
    return 0;
}
