function Mostrar()
{
//tomo la edad  
    var edad = parseInt(document.getElementById("edad").value);

    if(13 <= edad && edad < 18) {
        alert("Es adolescente");
    }
}//FIN DE LA FUNCIÓN