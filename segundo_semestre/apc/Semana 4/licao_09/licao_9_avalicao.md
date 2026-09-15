var orangeFish = createSprite(400, randomNumber(0, 100));
orangeFish.setAnimation("orange_fish");
var blueFish = createSprite(250, randomNumber(0, 200));
blueFish.setAnimation("blue_fish");
var greenFish = createSprite(300, randomNumber(200, 300));
greenFish.setAnimation("green_fish");

function draw() {
  // Draw Background
  background("navy");
  
  // Update Values
  orangeFish.x = orangeFish.x - 2;
  blueFish.x = orangeFish.x - 4;
  greenFish.x = orangeFish.x - 1;
  
  
  // Draw Animations
  drawSprites();
}

//Desavio, de certo modo, simples, porém importante para entender como funciona diferentes deslocamentos