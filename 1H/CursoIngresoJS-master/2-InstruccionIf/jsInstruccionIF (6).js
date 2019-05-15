function Mostrar()
{
//tomo la edad  
    var edad = parseInt(document.getElementById("edad").value);

    if(13 <= edad && edad < 18) {
        alert("Es adolescente");
    }
    else if(edad >=18) {
        alert("Es adulto")
    }
    else {
        alert("Es un niño")
    }
}//FIN DE LA FUNCIÓN