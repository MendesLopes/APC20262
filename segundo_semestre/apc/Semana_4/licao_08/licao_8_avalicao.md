//1) Add the draw loop block to the bottom of this program.
//2) Move any blocks that need to be inside the draw loop.

var salt = createSprite(200,200);
salt.setAnimation("salt");

function draw() {
  background("skyblue");
  salt.y = randomNumber(200,210);
  salt.rotation = 180;
  drawSprites();
}

//Achei interessante o desafio. Levei algum tempo para entender como funciona, porém consegui resolver