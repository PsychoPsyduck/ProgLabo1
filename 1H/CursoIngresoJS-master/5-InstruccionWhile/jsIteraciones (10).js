function Mostrar()
{
	//declarar contadores y variables 
	var numero
	var respuesta = 's';
	var sumaPositivos;
	var sumaNegativos;
	var cantPositivos = 0;
	var cantNegativos = 0;
	var cantPar = 0;
	var cantCero = 0;
	var promPositivos;
	var promNegativos;
	var difPosNeg;

	
	do {
		numero = parseInt(prompt("Ingrese un numero"));
		if (numero > 0) {
			cantPositivos ++;
			sumaPositivos = sumaPositivos + numero;
			respuesta = prompt("Desea continuar? s/n");
		}
		else if (numero < 0) {
			cantNegativos ++;
			sumaNegativos = sumaNegativos + numero;
			respuesta = prompt("Desea continuar? s/n");
		}
		else {
			cantCero ++;
		}
		if (numero % 2 == 2) {
			cantPar ++;
		}
	} while (respuesta! = 'n')

	promPositivos = sumaPositivos / cantPositivos;
	promNegativos = sumaNegativos / cantNegativos;
	difPosNeg = Math.abs(cantPositivos - cantNegativos);

	Document.write(sumaNegativos, sumaPositivos, cantPositivos, cantNegativos, CantPar,  )



}//FIN DE LA FUNCIÓN