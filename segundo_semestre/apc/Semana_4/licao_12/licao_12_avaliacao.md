var backdrop = createSprite(200,200);
backdrop.setAnimation("sky");
var creature = createSprite(200,250);
creature.setAnimation("creature");
creature.scale = 0.2;
function draw() {
  //shake the sprite when the mouse is pressed
  if (mouseDown()) {
  creature.rotation = randomNumber(-5,5);
  drawSprites();
  } else {
  //display the text when the mouse is NOT pressed
  fill("black");
  textSize(40);
  text("Press the mouse to shake the creature.", 20, 50, 360, 100);
  }
}
