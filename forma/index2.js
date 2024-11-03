// Creazione della scena
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
const renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);

// Creazione di un cubo con materiali colorati
const geometry = new THREE.BoxGeometry();
const materials = [
    new THREE.MeshBasicMaterial({ color: 0xff0000 }), // Rosso
    new THREE.MeshBasicMaterial({ color: 0x00ff00 }), // Verde
    new THREE.MeshBasicMaterial({ color: 0x0000ff }), // Blu
    new THREE.MeshBasicMaterial({ color: 0xffff00 }), // Giallo
    new THREE.MeshBasicMaterial({ color: 0xff00ff }), // Magenta
    new THREE.MeshBasicMaterial({ color: 0x00ffff }), // Ciano
];

const cube = new THREE.Mesh(geometry, materials);
scene.add(cube);

// Posizionamento della telecamera
camera.position.z = 5;

// Funzione di animazione
function animate() {
    requestAnimationFrame(animate);
    renderer.render(scene, camera);
}
animate();

// Gestione del movimento del cursore
document.addEventListener('mousemove', (event) => {
    const mouseX = (event.clientX / window.innerWidth) * 2 - 1;
    const mouseY = -(event.clientY / window.innerHeight) * 2 + 1;

    cube.position.x = mouseX * 2; // Modifica la posizione del cubo in base alla posizione del mouse
    cube.position.y = mouseY * 2; // Modifica la posizione del cubo in base alla posizione del mouse
});

// Ridimensionamento della finestra
window.addEventListener('resize', () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});



