function Mostrar()
{
	//Genero el número RANDOM entre 1 y 10 
	var nroRandom = parseInt(Math.floor((Math.random()*10)+1));
	
	if(nroRandom < 4) {
		alert("Sacaste " + nroRandom + ". Mejor suerte la proxima compa")
	}
	else if (4 <= nroRandom && nroRandom < 9) {
		alert("Sacaste " + nroRandom + ". Aprobaste ATR")
	}
	else {
		alert("Sacaste " + nroRandom + ". Excelente prodigio")
	}
}//FIN DE LA FUNCIÓN