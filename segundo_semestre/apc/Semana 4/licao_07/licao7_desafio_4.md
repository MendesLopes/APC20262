var light = createSprite(200,200);
light.setAnimation("lightning_1");

function draw() {
background("black");
light.x = randomNumber(200,210);
light.y = randomNumber(200,210);
light.setAnimation("lightning_1");
drawSprites();


}