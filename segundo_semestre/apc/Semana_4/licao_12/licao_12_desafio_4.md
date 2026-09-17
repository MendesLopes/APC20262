var salt = createSprite (200, 200);
salt.setAnimation("salt");
salt.rotation = 150;

function draw() {
  background("skyblue");
  
  // If mouseDidMove, rotate the salt shaker randomly to the left or right
  if (mouseDidMove()) {
    salt.rotation = randomNumber(80,-80);
  }
  
  drawSprites();
}