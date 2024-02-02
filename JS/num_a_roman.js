/*
<html lang="en">
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    <input id="number">
    <button id="convert-btn">
      Enviar
    </button>
    <div id="output"></div>
    <script src="./script.js"></script>
  </body>
</html>
*/

const button1 = document.querySelector('#convert-btn');
const inp1 = document.querySelector('#number');
const res = document.querySelector('#output');
button1.onclick = ver_valor;



function ver_valor() {
    if (inp1.value === "") {
      res.innerText = "Please enter a valid number";

    }
    else{
     if (inp1.value === "-1") {
      res.innerText = "Please enter a number greater than or equal to 1";

    } 
    else{
    if (inp1.value >= 4000) {
      res.innerText = "Please enter a number less than or equal to 3999";

    } 
    else{
      res.innerText = to_roman(inp1.value);
    }
    }


    }
  }

function to_roman(numero){
  var simbolos = {
      1000: 'M',
      900: 'CM',
      500: 'D',
      400: 'CD',
      100: 'C',
      90: 'XC',
      50: 'L',
      40: 'XL',
      10: 'X',
      9: 'IX',
      5: 'V',
      4: 'IV',
      1: 'I'
    }
 var res ="";
Object.entries(simbolos).reverse().forEach(([valor, simbolo]) => {
valor = parseInt(valor);
while (numero >= valor) {
res += simbolo;
numero -= valor;
        }
    });
  return res;
}
