  var bee = createSprite(200,200);
  bee.setAnimation("bee");
  

function draw(){
  background("blue");
  bee.x = World.mouseX;
  bee.y = World.mouseY;


  drawSprites();
}