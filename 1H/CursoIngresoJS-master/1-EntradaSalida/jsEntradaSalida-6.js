/*Debemos lograr tomar Los numeros por ID ,
transformarlos a enteros (parseInt) y Sumarlos.
Mostar el resulto por medio de "ALERT"*/
function sumar()
{
    var num1 = parseInt(document.getElementById("numeroUno").value);
    var num2 = parseInt(document.getElementById("numeroDos").value);
    
    alert(num1 + num2);    
}

