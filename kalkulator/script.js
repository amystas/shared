var display = document.getElementById("display");
var digits = document.getElementById("digits");
var operations = document.getElementById("operations");
var result = document.getElementById("result");
var number1, current_operation, memory;
digits.addEventListener("click", writeDigit);
operations.addEventListener("click", doOperation);
result.addEventListener("click", showResult);
document.getElementById("memoryRead").addEventListener("click", writeDigit);
document.getElementById("memoryClean").addEventListener("click", cleanMemory);
document.getElementById("memoryPlus").addEventListener("click", addMemory);
document.getElementById("clean").addEventListener("click", cleanDisplay);
display.value = "0";
memory = 0;

function writeDigit(event) {
    if(event.target.value){
        if(event.target.value == ".") {
            if((display.value.indexOf(".")>-1) == false){
                display.value += event.target.value;
            }
        }
        else if(event.target.value == "MR") {
            display.value = memory;
        }
        else if(display.value == "0" && event.target.value != "MR") {
            display.value = event.target.value;
        }
        else {
            display.value += event.target.value;
        }
    }
}

function doOperation(event) {
    if(event.target.value) {
        number1 = parseFloat(display.value);
        display.value = "";
        current_operation = event.target.value;
    }
}

function showResult() {
    let number2 = parseFloat(display.value);
    if(current_operation == "+") {
        display.value = number1 + number2;
    }
    if(current_operation == "-") {
        display.value = number1 - number2;
    }
    if(current_operation == "x") {
        display.value = number1 * number2;
    }
    if(current_operation == "÷") {
        display.value = number1 / number2;
    }
    current_operation = "";
}     

function cleanDisplay() {
    display.value = "0";
    current_operation = "";
}

function cleanMemory() {
    memory = 0;
}

function addMemory() {
    memory = parseFloat(memory) + parseFloat(display.value);
}