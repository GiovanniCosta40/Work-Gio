#include <stdio.h>
#include <stdbool.h>

int main() {
    int temperatura = 0;
    bool livello_acqua_ok = false;
    bool resistenze_attive = false;

    // Simulazione dell'inserimento del livello dell'acqua
    printf("Il livello dell'acqua è al limite consentito? (1 = sì, 0 = no): ");
    scanf("%d", &livello_acqua_ok);

    // Se il livello dell'acqua è sufficiente, possiamo iniziare il controllo della temperatura
    if (livello_acqua_ok) {
        printf("Accensione della caldaia...\n");

        while (1) {
            // Simula la lettura della temperatura
            printf("Inserisci la temperatura attuale dell'acqua (in gradi): ");
            scanf("%d", &temperatura);

            // Se la temperatura è inferiore a 50 gradi, attiviamo le resistenze
            if (temperatura < 50 && !resistenze_attive) {
                resistenze_attive = true;
                printf("Le resistenze sono state attivate per riscaldare l'acqua.\n");
            }

            // Se la temperatura raggiunge o supera i 75 gradi, disattiviamo le resistenze
            if (temperatura >= 75 && resistenze_attive) {
                resistenze_attive = false;
                printf("Le resistenze sono state disattivate. L'acqua è sufficientemente calda.\n");
            }

            // Informiamo l'utente dello stato corrente delle resistenze
            if (resistenze_attive) {
                printf("Le resistenze sono attive. L'acqua si sta riscaldando...\n");
            } else {
                printf("Le resistenze sono spente.\n");
            }
        }
    } else {
        printf("Errore: Il livello dell'acqua non è sufficiente. Non è possibile accendere la caldaia.\n");
    }

    return 0;
}
