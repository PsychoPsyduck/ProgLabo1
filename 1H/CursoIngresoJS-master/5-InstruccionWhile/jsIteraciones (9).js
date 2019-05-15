function Mostrar() {

	var numero;
	var respuesta='s';
	var menos;
	var mas;

	
	do {
		numero = parseInt(prompt("Ingrese un numero"));
		if(numero < menos){
			menos = numero;
			respuesta = prompt("Desea continuar?: s/n ");
		}
		else if(numero > mas){
				mas = numero;
				respuesta = prompt("Desea continuar?: s/n ");
		}
		else {
			mas = numero;
			menos = numero;
			respuesta = prompt("Desea continuar?: s/n ");
		}
	
	} while(respuesta != 'n')

	document.getElementById("maximo").value = mas
	document.getElementById("minimo").value = menos




}//FIN DE LA FUNCIÓN