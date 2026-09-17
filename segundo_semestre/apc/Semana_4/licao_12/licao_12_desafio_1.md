var spiral = createSprite(100,200);
spiral.setAnimation("lollipop");
var spiral2 = createSprite(300,200);
spiral2.setAnimation("lollipop2");
function draw() {
 background("pink");
  
  if(mouseDown()) {
  spiral.scale = spiral.scale  / 1.01;
  spiral.rotation = spiral.rotation + 3;
  spiral2.scale = spiral2.scale  * 1.01;
  spiral2.rotation = spiral2.rotation - 3;
  drawSprites();
  }
}