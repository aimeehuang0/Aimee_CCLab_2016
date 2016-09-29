function AddBubble()
{
  var x = event.clientX; 
  var random = Math.random() + 0.4;
  var iDiv = document.createElement('div');
  iDiv.className = 'bubble b1';
  iDiv.style.left = x+"px";
  iDiv.style.transform = "scale("+random+")";
  iDiv.addEventListener('click', function(event) {
    iDiv.style.display ="none";
  });
  document.getElementsByClassName('bubbles')[0].appendChild(iDiv);
}
function changebgColor()
{
  var bx = event.clientY; 
  document.body.style.background = "linear-gradient("+bx+"deg, #00d2ff , #3a7bd5)";
}