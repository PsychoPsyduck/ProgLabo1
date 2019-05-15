/*2.	Para el departamento de Construcción:
A.	 Mostrar la cantidad de alambre a comprar  si se ingresara el largo y el ancho de un terreno rectangular y se debe alambra con tres hilos de alambre.
B.	Mostrar la cantidad de alambre a comprar  si se ingresara el radio  de un terreno circular y se debe alambra con tres hilos de alambre.
C.	Para hacer un contrapiso de 1m x 1m se necesitan 2 bolsas de cemento y 3 de cal, debemos mostrar cuantas bolsas se necesitan de cada uno para las medidas que nos ingresen.
*/

function Rectangulo () 
{
    var largo = parseFloat(document.getElementById("Largo").value);
    var ancho = parseFloat(document.getElementById("Ancho").value);

    if(largo > 0 && ancho > 0) {
        alert("Se necesitan " + ((largo + ancho) * 6) + " metros de alambre")
    }
}
function Circulo () 
{
    var radio = parseFloat(document.getElementById("Radio").value);

    if(radio > 0) {
        alert("Se necesitan " + (((radio * 2) * 3.14) *3) + " metros de alambre")
    }
}
function Materiales () 
{
    var largo = parseFloat(document.getElementById("Largo").value);
    var ancho = parseFloat(document.getElementById("Ancho").value);
    var superficie = largo * ancho;

    if(largo > 0 && ancho > 0) {
        alert("Se necesitan " + (superficie * 2) + " bolsas de cemento y " + (superficie * 3) + " bolsas de cal")
    }
}