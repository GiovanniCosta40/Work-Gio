let counter = 0;
let interval;

const counterDisplay = document.getElementById('counter');
const startButton = document.getElementById('startButton');
const stopButton = document.getElementById('stopButton');
const image = document.getElementById('Image');

startButton.addEventListener('click', () => {
    if (!interval) {
        interval = setInterval(() => {
            counter++;
            counterDisplay.textContent = counter;
            if (counter === 10) {
                image.style.display = 'block'; // Mostra l'immagine quando il contatore raggiunge 10
            }
        }, 1000); // Incrementa ogni secondo
    }
});

stopButton.addEventListener('click', () => {
    clearInterval(interval);
    interval = null;
});
