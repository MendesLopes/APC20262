  var bee = createSprite(200,200);
  bee.setAnimation("bee");
  

function draw(){
  background("blue");
  bee.x = World.mouseX + randomNumber(-50,50);
  bee.y = World.mouseY + randomNumber(-50,50);


  drawSprites();
}