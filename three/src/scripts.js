import * as THREE from 'three'

const renderer = new THREE.WebGLRenderer();

renderer.setSize(window.innerWidth, window.innerHeight);

document.body.appendChild(renderer.domElement);

const scene = new THREE.scene

const camera = new THREE.PerspectiveCamera(
    75,
    windowinnerWidth/ windowinnerHeight,
    0.1,
    1000
);

new axesHelper = new THREE.AxesHelper(5);

renderer.render(camera, scene)