function Mostrar() {

    var cantDivisores = 0;
    var numeroIngresado = parseInt(prompt("Ingrese un numero:"));

    for(var num = 1; num <= numeroIngresado; num ++) {
        if((numeroIngresado % num) != 0) {
            continue;
        }
        cantDivisores++;
        console.log(num);
    }
    console.log("cantidad de divisores: " + cantDivisores);
}//FIN DE LA FUNCIÓN