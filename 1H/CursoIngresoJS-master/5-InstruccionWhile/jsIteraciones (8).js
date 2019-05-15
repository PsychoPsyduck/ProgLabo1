function Mostrar() {

	var numero
	var positivo=0;
	var negativo=1;	
	var respuesta='s';

	while(respuesta == 's' || respuesta == 'S') {
		numero = parseInt(prompt("Ingrese un numero: "))
		if(numero < 0) {
			negativo = negativo * numero;
		}
		else {
			positivo = positivo + numero;
		}
		respuesta = prompt("Desea continuar?: s/n");
	}

	document.getElementById('suma').value=positivo;
	document.getElementById('producto').value=negativo;

}//FIN DE LA FUNCIÓN