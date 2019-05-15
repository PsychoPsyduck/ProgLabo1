function Mostrar() {

    var importeDia;
    var minimo;
    var maximo;
    var flag = 0;

    for(var i=0; i<=24; i++) {
        importeDia = parseFloat(prompt("Ingrese el valor: "));

        while(importeDia <= 0) {
            importeDia = parseFloat(prompt("ERROR. Los valores de venta deben ser mayores a 0. Reingrese: "));
        }

        if(maximo < importeDia || flag == 0) {
            maximo = importeDia;
        }
        else if(minimo > importeDia || flag == 0) {
            minimo = importeDia;
            flag = 1;
        }
    }

    document.write("El mayor valor es " + maximo + " y el menor es " + minimo);
}
