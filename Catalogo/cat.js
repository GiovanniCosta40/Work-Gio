// Exibe a descrição com o preço ao clicar
document.querySelectorAll(".artigo").forEach((item) => {
    item.addEventListener("click", () => {
        alert("Descrição: " + item.getAttribute("data-descricao"));
    });
});

// Inicializa o total
let total = 0;

// Arraste e solte no cesto de compras
const cestino = document.getElementById("cestino");

document.querySelectorAll(".artigo").forEach((item) => {
    item.addEventListener("dragstart", (e) => {
        e.dataTransfer.setData("text/plain", item.id);
    });
});

cestino.addEventListener("dragover", (e) => {
    e.preventDefault();
    cestino.classList.add("over");
});

cestino.addEventListener("dragleave", () => {
    cestino.classList.remove("over");
});

cestino.addEventListener("drop", (e) => {
    e.preventDefault();
    const artigoId = e.dataTransfer.getData("text/plain");
    const artigo = document.getElementById(artigoId);
    if (artigo) {
        cestino.appendChild(artigo);
        const preco = parseFloat(artigo.getAttribute("data-preco"));
        total += preco;
        document.getElementById("total").textContent = "Total: " + total.toFixed(2) + " €";
        alert("Você adicionou " + artigo.textContent + " ao cesto.");
    }
    cestino.classList.remove("over");
});

// Simula il pagamento al clic del pulsante "Finaliza Compra"
document.getElementById("finaliza-compra").addEventListener("click", () => {
    if (total > 0) {
        // Simulazione della finestra di pagamento
        const conferma = confirm(`Il totale è di ${total.toFixed(2)} €. Vuoi procedere con il pagamento?`);
        if (conferma) {
            alert("Pagamento effettuato con successo! Grazie per il tuo acquisto.");
            // Resetta il carrello e il totale
            cestino.innerHTML = '<p>Arraste aqui os artigos que deseja adicionar ao cesto de compras.</p>';
            total = 0;
            document.getElementById("total").textContent = "Total: 0 €";
        }
    } else {
        alert("Il carrello è vuoto. Aggiungi almeno un articolo per procedere con il pagamento.");
    }
});
