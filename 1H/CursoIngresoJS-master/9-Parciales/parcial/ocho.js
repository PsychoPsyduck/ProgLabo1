function Mostrar() {
    
    var numero;
    var totalNumero = 0;
    var cantNumero = 0;
    var cantNumeroPar = 0;
    var flag = 0;
    var numeroMaximo;
    var numeroMinimo;
    var respuesta;

    do{

        numero = parseInt(prompt("Ingrese un numero positivo "));

        while(numero < 0) {
            numero = parseInt(prompt("Error. Ingrese un numero positivo "));
        }

        if(numero % 2 == 0) {
            cantNumeroPar++
        }

        totalNumero = totalNumero + numero

        cantNumero++

        if(numero > numeroMaximo || flag == 0) {
            numeroMaximo = numero;
        }
        if(numero < numeroMinimo || flag == 0) {
            numeroMinimo = numero;
            flag = 1
        }

        respuesta = prompt("Desea continuar? s/n");

    }while(respuesta == 's');

    document.write("Cant numeros pares: " + cantNumeroPar + "<br>" + "Promedio de numeros " + totalNumero/cantNumero + "<br>" + "suma " + totalNumero + "<br>" + "num max" + numeroMaximo + " y minimo " + numeroMinimo);
}
