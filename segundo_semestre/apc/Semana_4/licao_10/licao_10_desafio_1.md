var balloon = createSprite(200, 200);
balloon.setAnimation("balloon");
balloon.scale = 0.1;

var pop = createSprite(200,200);
pop.setAnimation("pop");
pop.visible = false;

function draw() {
  // Draw Background
  background("white");
  
  // Update Values
  balloon.scale = balloon.scale + 0.001;
  
  if (balloon.scale > 1) {
    balloon.visible = false;
    pop.visible = true;
  }

  // Draw Animations
  drawSprites();
}

#além de divertido, achei interessante como alterar a elementos para que a alteração ocorresse
