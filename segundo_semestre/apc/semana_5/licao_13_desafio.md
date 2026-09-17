var alien = createSprite(50,200);
alien.setAnimation("alien");
alien.velocityX = 0;
alien.velocityY = -3;

function draw() {
  if (alien.y < 50) {
    alien.velocityY = 0;
    alien.velocityX = 3;
    
  }
  if (alien.x > 350) {
    alien.velocityX = 0;
    alien.velocityY = 3;

  }
  if (alien.y > 350) {
    alien.velocityY = 0;
    alien.velocity = -3;

  }
  if (alien.x < 50) {
    alien.velocityX = 0;
    alien.velocityY = -3;
  }
  
  drawSprites();
}

var space = createSprite(200, 200);
space.setAnimation("space");
var flag1 = createSprite(50, 50);
flag1.setAnimation("yellow_flag");
var flag2 = createSprite(350, 50);
flag2.setAnimation("yellow_flag");
var flag3 = createSprite(350, 350);
flag3.setAnimation("yellow_flag");
var flag4 = createSprite(50, 350);
flag4.setAnimation("yellow_flag");
alien.depth=7;