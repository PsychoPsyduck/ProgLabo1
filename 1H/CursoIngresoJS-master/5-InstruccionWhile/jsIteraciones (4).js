function Mostrar()
{

	var numero = prompt("Ingrese un número entre 0 y 10.");

    while(!(numero > 0 && numero < 10) || isNaN(numero)) {
        numero = prompt("Numero erroneo. Ingrese numero: ");
    }
    document.getElementById("Numero").value = numero;
}//FIN DE LA FUNCIÓN