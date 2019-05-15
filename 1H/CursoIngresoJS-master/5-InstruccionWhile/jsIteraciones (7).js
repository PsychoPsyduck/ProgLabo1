function Mostrar(){

	var contador=0;
	var acumulador=0;
	var respuesta='s';

	while(respuesta == 's' || respuesta == 'S'){
		acumulador = acumulador + parseInt(prompt("Ingrese un numero: "));
		contador = contador + 1;
		respuesta = prompt("Desea continuar?: s/n");
	}
	document.getElementById("suma").value = acumulador;
	document.getElementById("promedio").value = acumulador/contador;

}//FIN DE LA FUNCIÓN