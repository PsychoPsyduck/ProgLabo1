/*1.	Para el departamento de facturación:
A.	Ingresar tres precios de productos y mostrar la suma de los mismos.
B.	Ingresar tres precios de productos y mostrar el promedio de los mismos.
C.	ingresar tres precios de productos  y mostrar precio final (más IVA 21%).
*/
function Sumar () 
{
	var prod1 = parseInt(document.getElementById("PrecioUno").value);
    var prod2 = parseInt(document.getElementById("PrecioDos").value);
    var prod3 = parseInt(document.getElementById("PrecioTres").value);

    alert("La suma de sus productos es: " + (prod1 + prod2 + prod3));
}
function Promedio () 
{
	var prod1 = parseInt(document.getElementById("PrecioUno").value);
    var prod2 = parseInt(document.getElementById("PrecioDos").value);
    var prod3 = parseInt(document.getElementById("PrecioTres").value);

    alert("El promedio de sus productos es: " + ((prod1 + prod2 + prod3) / 3));	
}
function PrecioFinal () 
{
	var prod1 = parseInt(document.getElementById("PrecioUno").value);
    var prod2 = parseInt(document.getElementById("PrecioDos").value);
    var prod3 = parseInt(document.getElementById("PrecioTres").value);

    alert("La precio final de sus productos es: " + ((prod1 + prod2 + prod3) * 1.21));
}