var basketball = createSprite(100, 0);
basketball.setAnimation("basketball");
basketball.bounciness = 0.8;

var soccerball = createSprite(225, 0);
soccerball.setAnimation("soccerball");
basketball.bounciness = 0.6;

var poolball = createSprite(325, 0);
poolball.setAnimation("poolball");
poolball.bounciness = 0.4;

var wood = createSprite(200, 375);
wood.setAnimation("floor");


function draw() {
  background("skyblue");
  
  basketball.bounceOff(wood);
  soccerball.bounceOff(wood);
  poolball.bounceOff(wood);
  
  basketball.velocityY = basketball.velocityY + 0.2;
  soccerball.velocityY = soccerball.velocityY + 0.2;
  poolball.velocityY = poolball.velocityY + 0.2;
  
  drawSprites();
}

//Gostei da tarefa para entender diferentes velocidades em um mesmo contexto