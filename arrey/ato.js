// Lista di persone con date di nascita
const people = [
    { name: "Mario Rossi", birthdate: "10/04/1990" },
    { name: "Luigi Verdi", birthdate: "25/12/1985" },
    { name: "Anna Bianchi", birthdate: "15/08/2000" },
    { name: "Giulia Neri", birthdate: "01/01/1975" },
    { name: "Luca Gialli", birthdate: "30/09/1995" },
    { name: "Marco Blu", birthdate: "11/02/1987" },
    { name: "Sofia Viola", birthdate: "21/07/1999" },
    { name: "Elena Grigi", birthdate: "13/05/1980" },
    { name: "Federico Azzurri", birthdate: "08/11/1992" },
    { name: "Alessandro Rossi", birthdate: "02/03/1996" },
    { name: "Paola Verdi", birthdate: "05/10/1978" },
    { name: "Giovanni Bianchi", birthdate: "12/04/1982" },
    { name: "Francesca Neri", birthdate: "18/06/1990" },
    { name: "Matteo Gialli", birthdate: "24/08/2001" },
    { name: "Sara Blu", birthdate: "16/12/1976" },
    { name: "Davide Viola", birthdate: "04/09/1993" },
    { name: "Chiara Grigi", birthdate: "22/01/1988" },
    { name: "Valentina Azzurri", birthdate: "28/07/1994" },
    { name: "Stefano Rossi", birthdate: "09/05/1981" },
    { name: "Martina Verdi", birthdate: "17/03/1997" }
];

// Seleziona il contenitore nel DOM
const container = document.getElementById('birthdates-container');

// Aggiunge un bottone per ogni persona
people.forEach(person => {
    const button = document.createElement('button');
    button.textContent = person.name;
    button.classList.add('birthdate-button');
    container.appendChild(button);

    // Mostra l'alert con la data di nascita al click
    button.addEventListener('click', () => {
        alert(`Data di nascita di ${person.name}: ${person.birthdate}`);
    });
});
