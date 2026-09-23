var car = createSprite(200, 350);
car.setAnimation("car");

car.velocityY = -15;

function draw() {
  background("forestgreen");
  fill("gray");
  rect(150, 0, 100, 400);
  
  // Make the Y velocity more downward
  car.velocityY = car.velocityY +0.2;
  
  // Prevent the car from moving backwards
  if (car.velocityY > 0) {
    car.velocity = 0;
  }
  
  drawSprites();
}
