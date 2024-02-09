let scene;
let camera;
let renderer;

function main() {
    const canvas = document.querySelector('#c');

    scene = new THREE.Scene();

    camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.z = 2;
    scene.add(camera);

    renderer = new THREE.WebGLRenderer({ canvas: canvas, antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio(window.devicePixelRatio);

    renderer.autoClear = false;
    renderer.setClearColor(0x00000, 0.0);

    // create earth geometry
    const earthGeometry = new THREE.SphereGeometry(0.6, 32, 32);

    // create earth material with texture loading and error handling
    const earthMaterial = new THREE.MeshStandardMaterial({
        roughness: 1,
        metalness: 0
    });

    const earthMesh = new THREE.Mesh(earthGeometry, earthMaterial);
    scene.add(earthMesh);

    // set ambient light
    const ambientLight = new THREE.AmbientLight(0xffffff, 0.2);
    scene.add(ambientLight);

    // set point light
    const pointLight = new THREE.PointLight(0xffffff, 0.9);
    scene.add(pointLight)

    // set light position
    pointLight.position.set(5, 3, 5);
    scene.add(pointLight);

    // load earth texture with error handling
    const earthTexture = new THREE.TextureLoader();
    earthTexture.load(
        'texture/earthmap1k.jpg',
        function (texture) {
            earthMaterial.map = texture;
            console.log('texture loaded');
            render(); // render after texture is loaded
            console.log('loaded and rendered')
        },
        function (xhr) {
            console.log((xhr.loaded / xhr.total * 100) + '% loaded');
        },
        function (error) {
            console.error('An error occurred while loading the earth texture:', error);
        }
    );

    const animate = () => {
        requestAnimationFrame(animate);
        earthMesh.rotation.y -= 0.00015;
        render();
    };

    const render = () => {
        renderer.render(scene, camera);
    };

    animate();
}

window.onload = main;
