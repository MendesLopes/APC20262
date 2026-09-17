var backdrop = createSprite(200,200);
backdrop.setAnimation("rainbow");
var flyer = createSprite(200,200);
flyer.setAnimation("wing_bot");

function draw() {
  //move left when the left arrow is pressed
   if (keyDown("left")) {
     flyer.x = flyer.x - 3;
   } 
  
  //move right when the right arrow is pressed
  
  if (keyDown("right")) {
    flyer.x = flyer.x +3;
  }
    //move up when the up arrow is pressed
  if (keyDown("down")) {
    flyer.y = flyer.y + 3;
  }
    //move down when the down arrow is pressed
  
  if (keyDown("up")) {
    flyer.y = flyer.y - 3;
  }
  
  
  drawSprites();
}