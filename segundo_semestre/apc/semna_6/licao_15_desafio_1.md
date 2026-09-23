var plane = createSprite(50, 350);
plane.setAnimation("plane");
var rock = createSprite(150, 350);
rock.setAnimation("rock");
var rockdown = createSprite(350, 100);
rockdown.setAnimation("rock_down");

// You might want to change these 
plane.velocityY = -9;
plane.velocityX = 3;

function draw() {
  background("lightblue");
  
  plane.velocityY = plane.velocityY + 0.2;
  plane.velocityX = plane.velocityX + 0.015;
  
  drawSprites();
}
