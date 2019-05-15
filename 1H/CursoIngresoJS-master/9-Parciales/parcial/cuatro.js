function Mostrar() {

    var dato1 = parseInt(prompt("Ingrese el primer valor: "));
    var dato2 = parseInt(prompt("Ingrese el segundo valor: "));

    if(dato1 == dato2) {
        document.write("El resultado es: " + dato1*dato2);
    }
    else if(dato1 > dato2) {
        document.write("El resultado es: " + parseInt(dato1 - dato2));
    }
    else {
        document.write("El resultado es: " + parseInt(dato1 + dato2));
    }
}
