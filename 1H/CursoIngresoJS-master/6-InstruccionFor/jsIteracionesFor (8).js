function Mostrar() {

    var cantDivisores = 0;
    var numeroIngresado = parseInt(prompt("Ingrese un numero: "));

    for(var num = 1; num <= numeroIngresado; num++) {

        if(cantDivisores != 2) {

            console.log(numeroIngresado + "no es primo")
        }
    }

    if(cantDivisores == 2) {
        
        console.log(numeroIngresado + "es primo")
    }

}//FIN DE LA FUNCIÓN