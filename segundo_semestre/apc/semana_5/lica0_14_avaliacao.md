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
  
   if ((((horse.x > rainbow.x) && ((horse.x - rainbow.x) < (horse.width/2 + rainbow.width/2))) || 
    ((horse.x < rainbow.x) && ((horse.x - rainbow.x) > - (horse.width/2 + rainbow.width/2))))) {

    //horse.velocityX = 0;
  //  rainbow.velocityX = 0;
   // horse.velocityX = 0;
    horse.setAnimation("unicorn");
  }
  
  drawSprites();
}

//Gostei bastante dos exercícios. O nível de dificuldade subiu de forma interessante, porém sem desestimular