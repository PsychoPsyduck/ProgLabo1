function Mostrar()
{
//tomo la edad  
    var mesDelAño = document.getElementById('mes').value;

    switch(mesDelAño) {
        case "Enero":
            alert("Que comience bien el año");
            break;
        case "Marzo":
            alert("Buen comienzo de clases");
            break;
        case "Julio":
            alert("Se vienen las vacaciones");
            break;
        case "Diciembre":
            alert("Felices fiestas!");
            break;
    }

}//FIN DE LA FUNCIÓN