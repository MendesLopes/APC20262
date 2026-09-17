var backdrop = createSprite(200,200);
backdrop.setAnimation("sci_fi");
var dinosaur = createSprite(200, 350);
dinosaur.scale = 0.2;
dinosaur.setAnimation("tyrannosaurus");

function draw() {
  //move the dinosaur up
  dinosaur.y = dinosaur.y - 5;

  //if it gets to the sky, turn it into a pterodactyl
  
  if ( dinosaur.y < 60) {
   dinosaur.setAnimation("pterodactyl");
  }

  //draw everything
  drawSprites();
}
