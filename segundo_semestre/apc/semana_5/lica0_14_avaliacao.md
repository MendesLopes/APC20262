// create the sprites
var horse = createSprite(200, 150);
horse.setAnimation("horse");
var rainbow = createSprite(400, 370);
rainbow.setAnimation("rainbow");
rainbow.velocityX = -5;
rainbow.velocityY = -5;
rainbow.rotateToDirection = true;

function draw() {
  // draw the background
  background("skyblue");

  // change the horse to a unicorn when the rainbow touches it
  //Coloquei uma solução mais elegante
  
   if (horse.isTouching(rainbow)) {
    horse.setAnimation("unicorn");
  }

  
  drawSprites();
}

//pelo que entendi, isso que o sistema desejava