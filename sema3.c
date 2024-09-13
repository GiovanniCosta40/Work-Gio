#include <stdio.h>
#include <unistd.h>  // Per la funzione sleep()

// Funzione per visualizzare lo stato del semaforo
void disegna_semaforo(const char* stato) {
    printf("\n-------------\n");
    printf("|           |\n");
    if (strcmp(stato, "VERDE") == 0) {
        printf("|   VERDE   |\n");
    } else {
        printf("|           |\n");
    }
    if (strcmp(stato, "ARANCIONE") == 0 || strcmp(stato, "LAMPEGGIANTE") == 0) {
        printf("|  ARANCIONE|\n");
    } else {
        printf("|           |\n");
    }
    if (strcmp(stato, "ROSSO") == 0) {
        printf("|   ROSSO   |\n");
    } else {
        printf("|           |\n");
    }
    printf("|           |\n");
    printf("-------------\n");
}

// Funzione per il contatore dei secondi
void contatore_secondi(int secondi, const char* colore) {
    for (int i = 1; i <= secondi; i++) {
        printf("%s - %d secondi\n", colore, i);
        sleep(1);  // Aspetta 1 secondo
    }
}

// Funzione per simulare il cambio di colore del semaforo
void cambia_colore_semaforo(const char* stato) {
    if (strcmp(stato, "ARANCIONE") == 0) {
        disegna_semaforo("ARANCIONE");
        contatore_secondi(5, "ARANCIONE");
    } else if (strcmp(stato, "ROSSO") == 0) {
        disegna_semaforo("ROSSO");
        contatore_secondi(10, "ROSSO");
    } else if (strcmp(stato, "VERDE") == 0) {
        disegna_semaforo("VERDE");
    }
}

// Funzione che simula il passaggio di un veicolo attraverso il sensore di velocità
void sensore_velocita(int velocita, int *cicli) {
    printf("Veicolo rilevato dal sensore con velocità: %d km/h\n", velocita);

    // Se la velocità del veicolo supera i 50 km/h, il semaforo cambia colore
    if (velocita > 50) {
        printf("Velocità oltre 50 km/h! Cambio semaforo in corso...\n");
        cambia_colore_semaforo("ARANCIONE");
        cambia_colore_semaforo("ROSSO");
        (*cicli)++;
    } else {
        printf("Velocità sotto il limite. Il semaforo rimane verde.\n");
        disegna_semaforo("VERDE");
    }
}

// Funzione per gestire la manutenzione del semaforo
void manutenzione_semaforo() {
    printf("Il semaforo è in manutenzione... (Arancione Lampeggiante per 10 secondi)\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            disegna_semaforo("LAMPEGGIANTE");
        } else {
            disegna_semaforo("");  // Semaforo spento durante il lampeggio
        }
        sleep(1);
    }
    printf("Manutenzione terminata. Il semaforo torna verde.\n");
    disegna_semaforo("VERDE");
}

int main() {
    int velocita;
    int cicli = 0;
    char scelta;

    // Semaforo inizialmente verde
    disegna_semaforo("VERDE");

    while (1) {  // Ciclo infinito per simulare un sistema sempre attivo
        // Controlla se bisogna spegnere il semaforo
        printf("\nPremi 's' per spegnere il semaforo o 'c' per continuare: ");
        scanf(" %c", &scelta);

        if (scelta == 's' || scelta == 'S') {
            printf("Semaforo spento.\n");
            break;
        }

        // Simulazione del sensore di velocità
        printf("Inserisci la velocità del veicolo (km/h): ");
        scanf("%d", &velocita);

        // Passaggio del veicolo attraverso il sensore di velocità
        sensore_velocita(velocita, &cicli);

        // Dopo 5 cicli, il semaforo entra in manutenzione
        if (cicli >= 5) {
            manutenzione_semaforo();
            cicli = 0;  // Resetta il contatore dei cicli
        }
    }

    return 0;
}
