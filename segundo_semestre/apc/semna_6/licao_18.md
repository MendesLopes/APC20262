// Create your variables here
var score = 0;
var jogador = createSprite(200, 360, 10, 10);

jogador.setAnimation("retrocreature_09_1");
jogador.scale = 0.2;

var coracao = createSprite(randomNumber(50, 350), randomNumber(-30, -60));
coracao.setAnimation("retro_red_heart_1");
coracao.scale = 0.2;
coracao.velocityY = 2;


// Create your sprites here

function draw() {
  // draw background
  
if (score < 10) {
  background("blue");
  
} else if (score >= 10) {
  background("red");
}


if(coracao.isTouching(jogador)){
    score = score + 1;
  
}
   
  // update sprites

  drawSprites();
  
  drawScoreBoard(); 
  controlPlayer();
}

// Create your functions here

//Tenho que entender como fazer para o sprite mover para alguns aldos

function controlPlayer() {
  if(keyDown("up")){
   jogador.velocityY = -3;
  }
  if(keyDown("left")){
     jogador.x = jogador.x - 3;
  }
  if(keyDown("right")){
    jogador.x = jogador.x + 3;
  }
}


function drawScoreBoard() {
  fill("white");
  textSize(20);
  text("Pontos: " + score, 20, 30);
}

//Minhas maiores dificuldades são criar algo do zero
//as tarefas mais direcionadas são mais fáceis
