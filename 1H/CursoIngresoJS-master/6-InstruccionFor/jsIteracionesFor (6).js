function Mostrar() {

    var cantPares = 0;
    var numeroIngresado = parseInt(prompt("Ingrese un numero:"));

    for(var num = 1; num <= numeroIngresado; num ++) {
        if((num % 2) != 0) {
            continue;
        }
        cantPares++;
        console.log(num);
    }
    console.log("cantidad de numeros pares: " + cantPares);
}//FIN DE LA FUNCIÓN