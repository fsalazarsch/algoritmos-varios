/*
<html lang="en">
  <head>
    <meta charset="utf-8">
  </head>
  <body>
    <input id="text-input">
    <button id="check-btn" >Enviar</button>
    <div id="result"></div>
    <script src="./script.js"></script>
  </body>
</html>

*/


const button1 = document.querySelector('#check-btn');
const inp1 = document.querySelector('#text-input');
const res = document.querySelector('#result');
button1.onclick = ver_valor;



function ver_valor() {
    if (inp1.value === "") {
      alert("Please input a value.");
    }
    else{
      const aux = inp1.value.replace(/[ \/\.\\"'_,()\-]/g, '').toLowerCase();
const aux2 = aux.split('').reverse().join('');

    if ( aux == aux2){
    res.innerText = inp1.value+ " is a palindrome";
    }
    else{
    res.innerText = inp1.value+ " is not a palindrome";
    }
    }
  }
