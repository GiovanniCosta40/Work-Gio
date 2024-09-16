#include <stdio.h>

// Sequenze ANSI per i colori
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

// Dichiarazione delle funzioni
void calcolatrice();

int main() {
    char stato;  // Per accendere o spegnere la calcolatrice

    do {
        // Visualizza l'opzione ON in blu e OFF in rosso
        printf("Vuoi accendere la calcolatrice? (%sO%s per ON, %sS%s per OFF): ", BLUE, RESET, RED, RESET);
        scanf(" %c", &stato);

        if (stato == 'O') {
            calcolatrice();  // Chiama la funzione per eseguire le operazioni
        } else if (stato == 'S') {
            printf("%sCalcolatrice spenta. Uscita dal programma.%s\n", RED, RESET);
        } else {
            printf("Opzione non valida. Riprovare.\n");
        }
    } while (stato != 'S');  // Continua fino a quando non si sceglie 'S'

    return 0;
}

// Funzione calcolatrice per eseguire le operazioni
void calcolatrice() {
    float num1, num2, result;
    char operatore;
    char scelta;

    do {
        // Menu di selezione dell'operazione
        printf("Scegli l'operazione (+, -, *, /) oppure 'q' per spegnere la calcolatrice: ");
        scanf(" %c", &operatore);

        // Se l'utente sceglie di uscire dalla calcolatrice
        if (operatore == 'q') {
            printf("%sSpegni la calcolatrice.%s\n", RED, RESET);
            break;
        }

        // Input dei numeri
        printf("Inserisci il primo numero: ");
        scanf("%f", &num1);
        
        printf("Inserisci il secondo numero: ");
        scanf("%f", &num2);

        // Switch per gestire le operazioni
        switch(operatore) {
            case '+':
                result = num1 + num2;
                printf("Risultato: %.2f\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Risultato: %.2f\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Risultato: %.2f\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Risultato: %.2f\n", result);
                } else {
                    printf("Errore: divisione per zero non consentita.\n");
                }
                break;
            default:
                printf("Operazione non valida.\n");
                break;
        }

        // Chiedi all'utente se vuole effettuare un'altra operazione
        printf("Vuoi effettuare un'altra operazione? (%sY%s per SI, %sN%s per NO): ", BLUE, RESET, RED, RESET);
        scanf(" %c", &scelta);

    } while (scelta == 'Y');

    printf("%sCalcolatrice spenta.%s\n", RED, RESET);
}
