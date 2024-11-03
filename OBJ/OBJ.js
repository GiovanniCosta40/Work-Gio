// Array di formatori con 5 persone, compresi nome e cognome
let formatori = [
    { nome: "Giovanni", cognome: "Rossi", idade: 40, ano_de_nascimento: 1984 },
    { nome: "Maria", cognome: "Gois", idade: 30, ano_de_nascimento: 1994 },
    { nome: "Luca", cognome: "Bianchi", idade: 17, ano_de_nascimento: 2006 }, // Minorenne
    { nome: "Anna", cognome: "Neri", idade: 22, ano_de_nascimento: 2001 },
    { nome: "Marco", cognome: "Gialli", idade: 35, ano_de_nascimento: 1988 },
];

// Funzione per validare l'età
function validarIdade(idade) {
    return idade >= 18; // Restituisce true se l'età è maggiore o uguale a 18
}

// Seleziona l'elemento dove visualizzare le informazioni
let formatoriDiv = document.getElementById("formatori");

// Ciclo per ogni formatore e creazione del contenuto
formatori.forEach(persona => {
    // Creazione di un nuovo div per ogni persona
    let personaDiv = document.createElement("div");
    personaDiv.classList.add("persona"); // Aggiunge una classe per lo stile

    // Controllo se la persona è minorenne
    if (validarIdade(persona.idade)) {
        // Costruzione del contenuto se la persona è maggiorenne
        personaDiv.innerHTML = `
            <p><strong>Nome:</strong> ${persona.nome} ${persona.cognome}</p>
            <p><strong>Idade:</strong> ${persona.idade}</p>
            <p><strong>Ano de Nascimento:</strong> ${persona.ano_de_nascimento}</p>
            <p><strong>Validazione Età:</strong> ${persona.nome} è maggiorenne.</p>
        `;
    } else {
        // Messaggio per le persone minorenni
        personaDiv.innerHTML = `
            <p><strong>${persona.nome} ${persona.cognome}</strong> è minorenne. Dati non disponibili.</p>
        `;
    }

    // Aggiunge il div della persona al contenitore principale
    formatoriDiv.appendChild(personaDiv);
});


// URL dell'API da cui vogliamo recuperare dati
const url = 'https://jsonplaceholder.typicode.com/posts';

// Eseguiamo la richiesta GET
fetch(url)
    .then(response => {
        // Controlliamo se la risposta è stata ok (status 200-299)
        if (!response.ok) {
            throw new Error('Errore nella risposta della rete: ' + response.statusText);
        }
        // Convertiamo la risposta in formato JSON
        return response.json();
    })
    .then(data => {
        // Mostriamo i dati ricevuti nella console
        console.log(data);
    })
    .catch(error => {
        // Gestiamo eventuali errori
        console.error('Si è verificato un errore:', error);
    });
// Funzione per ottenere dati dai formatori tramite fetch
async function fetchFormatori() {
    try {
        // Simuliamo una chiamata a un'API
        const response = await fetch('https://api.example.com/formatori'); // Sostituisci con il tuo URL reale
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const formatori = await response.json(); // Assumiamo che i dati siano in formato JSON
        visualizzaFormatori(formatori); // Passiamo i dati alla funzione di visualizzazione
    } catch (error) {
        console.error('C\'è stato un problema con la fetch:', error);
    }
}

// Funzione per visualizzare i formatori
function visualizzaFormatori(formatatori) {
    let formatoriDiv = document.getElementById("formatori");
    formatoriDiv.innerHTML = ""; // Pulisce il contenuto precedente

    formatori.forEach(persona => {
        let personaDiv = document.createElement("div");
        personaDiv.classList.add("persona");

        if (validarIdade(persona.idade)) {
            personaDiv.innerHTML = `
                <p><strong>Nome:</strong> ${persona.nome} ${persona.cognome}</p>
                <p><strong>Idade:</strong> ${persona.idade}</p>
                <p><strong>Ano de Nascimento:</strong> ${persona.ano_de_nascimento}</p>
                <p><strong>Validazione Età:</strong> ${persona.nome} è maggiorenne.</p>
            `;
        } else {
            personaDiv.innerHTML = `
                <p><strong>${persona.nome} ${persona.cognome}</strong> è minorenne. Dati non disponibili.</p>
            `;
        }

        formatoriDiv.appendChild(personaDiv);
    });
}

// Funzione per validare l'età
function validarIdade(idade) {
    return idade >= 18; // Restituisce true se l'età è maggiore o uguale a 18
}

// Chiamata alla funzione fetch per ottenere i formatori
fetchFormatori();
// Funzione per ottenere dati dai formatori tramite fetch
async function fetchFormatori() {
    try {
        // Chiamata all'API JSONPlaceholder
        const response = await fetch('https://jsonplaceholder.typicode.com/users');
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const formatori = await response.json(); // Assumiamo che i dati siano in formato JSON

        // Trasformazione dei dati per adattarli al tuo formato
        const formatoriTrasformati = formatori.map(user => ({
            nome: user.name.split(' ')[0], // Prende il primo nome
            cognome: user.name.split(' ')[1] || '', // Prende il secondo nome se presente
            idade: Math.floor(Math.random() * (50 - 18 + 1)) + 18, // Genera un'età casuale tra 18 e 50
            ano_de_nascimento: new Date().getFullYear() - idade // Calcola l'anno di nascita
        }));

        visualizzaFormatori(formatoriTrasformati); // Passiamo i dati alla funzione di visualizzazione
    } catch (error) {
        console.error('C\'è stato un problema con la fetch:', error);
    }
}

// Funzione per visualizzare i formatori
function visualizzaFormatori(formatatori) {
    let formatoriDiv = document.getElementById("formatori");
    formatoriDiv.innerHTML = ""; // Pulisce il contenuto precedente

    formatori.forEach(persona => {
        let personaDiv = document.createElement("div");
        personaDiv.classList.add("persona");

        if (validarIdade(persona.idade)) {
            personaDiv.innerHTML = `
                <p><strong>Nome:</strong> ${persona.nome} ${persona.cognome}</p>
                <p><strong>Idade:</strong> ${persona.idade}</p>
                <p><strong>Ano de Nascimento:</strong> ${persona.ano_de_nascimento}</p>
                <p><strong>Validazione Età:</strong> ${persona.nome} è maggiorenne.</p>
            `;
        } else {
            personaDiv.innerHTML = `
                <p><strong>${persona.nome} ${persona.cognome}</strong> è minorenne. Dati non disponibili.</p>
            `;
        }

        formatoriDiv.appendChild(personaDiv);
    });
}

// Funzione per validare l'età
function validarIdade(idade) {
    return idade >= 18; // Restituisce true se l'età è maggiore o uguale a 18
}

// Chiamata alla funzione fetch per ottenere i formatori
fetchFormatori();// Funzione per ottenere dati dai formatori tramite fetch
async function fetchFormatori() {
    try {
        // Chiamata all'API JSONPlaceholder
        const response = await fetch('https://jsonplaceholder.typicode.com/users');
        if (!response.ok) {
            throw new Error('Network response was not ok');
        }
        const formatori = await response.json(); // Assumiamo che i dati siano in formato JSON

        // Trasformazione dei dati per adattarli al tuo formato
        const formatoriTrasformati = formatori.map(user => ({
            nome: user.name.split(' ')[0], // Prende il primo nome
            cognome: user.name.split(' ')[1] || '', // Prende il secondo nome se presente
            idade: Math.floor(Math.random() * (50 - 18 + 1)) + 18, // Genera un'età casuale tra 18 e 50
            ano_de_nascimento: new Date().getFullYear() - idade // Calcola l'anno di nascita
        }));

        visualizzaFormatori(formatoriTrasformati); // Passiamo i dati alla funzione di visualizzazione
    } catch (error) {
        console.error('C\'è stato un problema con la fetch:', error);
    }
}

// Funzione per visualizzare i formatori
function visualizzaFormatori(formatatori) {
    let formatoriDiv = document.getElementById("formatori");
    formatoriDiv.innerHTML = ""; // Pulisce il contenuto precedente

    formatori.forEach(persona => {
        let personaDiv = document.createElement("div");
        personaDiv.classList.add("persona");

        if (validarIdade(persona.idade)) {
            personaDiv.innerHTML = `
                <p><strong>Nome:</strong> ${persona.nome} ${persona.cognome}</p>
                <p><strong>Idade:</strong> ${persona.idade}</p>
                <p><strong>Ano de Nascimento:</strong> ${persona.ano_de_nascimento}</p>
                <p><strong>Validazione Età:</strong> ${persona.nome} è maggiorenne.</p>
            `;
        } else {
            personaDiv.innerHTML = `
                <p><strong>${persona.nome} ${persona.cognome}</strong> è minorenne. Dati non disponibili.</p>
            `;
        }

        formatoriDiv.appendChild(personaDiv);
    });
}

// Funzione per validare l'età
function validarIdade(idade) {
    return idade >= 18; // Restituisce true se l'età è maggiore o uguale a 18
}

// Chiamata alla funzione fetch per ottenere i formatori
fetchFormatori();

