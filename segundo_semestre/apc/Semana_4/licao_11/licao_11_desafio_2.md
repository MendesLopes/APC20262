var bug = createSprite(200, 200);
bug.setAnimation("fly");

function draw() {
  //Draw Background
  background("white");
  
  // Update Values
  if(keyDown("up")){
    bug.y = bug.y - 5;
    bug.setAnimation("bee")

  }
  if(keyDown("down")){
    bug.y = bug.y + 5;
    bug.setAnimation("fly")

  }
  if(keyDown("left")){
    bug.x = bug.x - 5;
    bug.setAnimation("bee")

  }
  if(keyDown("right")){
    bug.x = bug.x + 5;
    bug.setAnimation("ladybug")

  }

  //Draw Animations
  drawSprites();
}