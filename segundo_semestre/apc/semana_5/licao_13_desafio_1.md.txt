var fish = createSprite(200, 200);
fish.setAnimation("fishR");
fish.velocityX = 4;

function draw() {
  background("blue");
  //Use a the correct block inside each conditional statement to make the three following movements:
  //If the user presses the right arrow key, move the fish to the right.
    
  if (keyWentDown("right")) {
      
      fish.velocityX = 4;
      fish.setAnimation("fishR");
    }
  
  //If the fish gets to the right-hand side of the screen, move the fish to the left.
  if (fish.x > 400) {
    fish.velocityX = -4;
    fish.setAnimation("fishL");
  }
  
  //If the fish gets to the left-hand side of the screen, move the fish to the right.
  if (fish.x < 0) {
  fish.velocitX = -4;
  fish.setAnimation("fishL");

  }  

  //The fish should always be facing the same direction it's moving, so you will also need to
  //update the fish's animation inside each of the conditional statements.
  
  // Draw the fish.
  drawSprites();
}
