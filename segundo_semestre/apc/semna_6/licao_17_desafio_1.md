function draw() {
  if(World.mouseY > 200){
    drawScene1();
  } else {
    drawScene2();
  }
    drawSprites();
}

function drawScene1() {

  fill("lightblue");
  rect(0, 0, 400, 400); 
  
  fill("yellow");
  ellipse(200, 80, 50);
  
  fill("green");
  arc(200, 400, 400, 200, 180, 360);
}


function drawScene2() {

  fill("black");
  rect(0, 0, 400, 400); 
  
  fill("gray");
  ellipse(200, 80, 50);
  

  fill("white");
  ellipse(50, 50, 5);
  ellipse(300, 100, 5);
  ellipse(100, 150, 5);
  ellipse(350, 200, 5);
}

//achei bem difícil esta tarefa. Tinha esquecido como desenhava a ellipese