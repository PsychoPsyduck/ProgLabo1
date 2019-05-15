function Mostrar() {

    var diaDeLaSemana = prompt("Ingrese un dia de la semana: ");

    switch(diaDeLaSemana) {
        case "Sabado" :
        case "Domingo" :
            alert("Es fin de semana");
            break;
        default :
            alert("A trabajar!!");
            break;
    }
}
