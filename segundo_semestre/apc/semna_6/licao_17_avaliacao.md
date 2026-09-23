var coin = createSprite(200,10);
coin.setAnimation("coin_gold_1");
setCoin();

var bunny = createSprite(200,350);
bunny.setAnimation("bunny1_ready_1");

var score = 0;

function draw() {
  background("white");
  
  if(keyDown("left")){
    bunny.x = bunny.x - 2;
  }
  
  if(keyDown("right")){
    bunny.x = bunny.x + 2;
  }
  
  if(coin.y > 400){
    setCoin();
  }
  
  textSize(20);
  text("Score: " + score, 10, 10, 100, 100);
  
  if(coin.isTouching(bunny)){
    score = score + 1; 
    setCoin();         
  }
  
  if(coin.y > 400){
    setCoin();
  }
  
  textSize(20);
  text("Score: " + score, 10, 10, 100, 100);
  
  drawSprites();
}

function setCoin(){
  
  coin.velocityY = 4;
  coin.y = 0;
  coin.x = randomNumber(0,400);

}
