var goldCoin = createSprite(49,50);
goldCoin.setAnimation("gold_coin");
goldCoin.velocityX = 2;
goldCoin.velocityY = 2;
goldCoin.debug = true;
goldCoin.setCollider("circle");

var silverCoin = createSprite(350,350);
silverCoin.setAnimation("silver_coin");
silverCoin.velocityX = -2;
silverCoin.velocityY = -2;
silverCoin.debug = true;
silverCoin.setCollider("circle");

function draw() {
  goldCoin.bounce(silverCoin);
  
  background("darkgreen");
  drawSprites();
}

//achei interessante, pois não sabia que era assim que funcionava a delimitação da imagem