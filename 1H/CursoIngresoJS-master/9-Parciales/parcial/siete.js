function Mostrar() {

    var nota
    var sexo
    var totalNotas = 0
    var cantVarones = 0
    var notaMasBaja
    var flag = 0


    for(var i=0; i <=5; i++) {
        
        nota = parseInt(prompt("Ingrese la nota: "));

        while(nota < 0 || nota > 10) {
            nota = parseInt(prompt("Error. Vuelva a ingresar una nota valida: "));
        }

        sexo = prompt("Ingrese sexo: f/m");

        while(sexo != 'f' && sexo != 'm') {
            sexo = prompt("Error. Ingrese un sexo valido");
        }
        
        totalNotas = totalNotas + nota;

        if(nota < notaMasBaja || flag == 0) {
            notaMasBaja = nota;
        }

        if(nota >= 6 && sexo == 'm') {
            cantVarones++
        }

    }

    totalNotas = totalNotas / 5

    alert("A) El promedio de notas es " + totalNotas + ". B) La nota mas baja es: " + notaMasBaja + ". C) Cantidad de varones aprobados: " + cantVarones);


}
