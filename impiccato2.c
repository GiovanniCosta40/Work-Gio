#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TENTATIVI 6
#define MAX_LUNGHEZZA_PAROLA 100

// Funzione per disegnare l'impiccato in base al numero di errori
void disegna_impiccato(int tentativi_errati) {
    switch (tentativi_errati) {
        case 1:
            printf("  |\n");
            break;
        case 2:
            printf("  |\n  |\n  |\n  |\n");
            break;
        case 3:
            printf("  ______\n  |    |\n  |\n  |\n  |\n");
            break;
        case 4:
            printf("  ______\n  |    |\n  |    O\n  |\n  |\n");
            break;
        case 5:
            printf("  ______\n  |    |\n  |    O\n  |    |\n  |\n");
            break;
        case 6:
            printf("  ______\n  |    |\n  |    O\n  |   /|\\\n  |\n");
            break;
        case 7:
            printf("  ______\n  |    |\n  |    O\n  |   /|\\\n  |   / \\\n");
            break;
    }
}

// Funzione per verificare se la parola è stata completata
int parola_completata(char parola[], char risposta[]) {
    return strcmp(parola, risposta) == 0;
}

// Funzione per mostrare lo stato attuale della parola con lettere indovinate
void mostra_stato_parola(char risposta[], int lunghezza) {
    for (int i = 0; i < lunghezza; i++) {
        printf("%c ", risposta[i]);
    }
    printf("\n");
}

// Funzione principale
int main() {
    char parola[MAX_LUNGHEZZA_PAROLA];
    char risposta[MAX_LUNGHEZZA_PAROLA];
    int lunghezza_parola;
    int tentativi_errati = 0;
    int tentativi_restanti = MAX_TENTATIVI;
    char lettera;

    printf("Benvenuto nel gioco dell'impiccato!\n");

    while (1) {
        // Inizializzazione per una nuova partita
        printf("\nInserisci una parola da indovinare: ");
        scanf("%s", parola);
        lunghezza_parola = strlen(parola);

        // Preparare la risposta con "_" per lettere non indovinate
        for (int i = 0; i < lunghezza_parola; i++) {
            risposta[i] = '_';
        }
        risposta[lunghezza_parola] = '\0';  // Terminatore di stringa

        tentativi_errati = 0;
        tentativi_restanti = MAX_TENTATIVI;

        // Ciclo di gioco
        while (tentativi_restanti > 0) {
            printf("\nHai %d tentativi rimasti.\n", tentativi_restanti);
            mostra_stato_parola(risposta, lunghezza_parola);

            printf("Scegli una lettera: ");
            scanf(" %c", &lettera);
            lettera = tolower(lettera);  // Convertire in minuscolo per evitare differenze

            // Verifica se la lettera è presente nella parola
            int indovinata = 0;
            for (int i = 0; i < lunghezza_parola; i++) {
                if (parola[i] == lettera) {
                    risposta[i] = lettera;  // Lettera indovinata
                    indovinata = 1;
                }
            }

            if (!indovinata) {
                tentativi_errati++;
                tentativi_restanti--;
                printf("Lettera errata!\n");
                disegna_impiccato(tentativi_errati);
            }

            // Verifica se la parola è stata completata
            if (parola_completata(parola, risposta)) {
                printf("\nComplimenti! Hai indovinato la parola: %s\n", parola);
                printf("YOU WIN!\n");
                break;
            }
        }

        if (tentativi_restanti == 0) {
            printf("\nGAME OVER! Hai finito i tentativi.\n");
            printf("La parola era: %s\n", parola);
            disegna_impiccato(7);  // Disegna l'impiccato completo in caso di sconfitta
        }

        // Chiedere se si vuole giocare di nuovo
        char scelta;
        printf("\nVuoi giocare di nuovo? (s/n): ");
        scanf(" %c", &scelta);

        if (tolower(scelta) != 's') {
            break;
        }
    }

    printf("Grazie per aver giocato!\n");
    return 0;
}
