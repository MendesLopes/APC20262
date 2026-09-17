var roller = createSprite(200, 200);
roller.scale = 2;
roller.setAnimation("roller_1");
// Use .setCollider() with all 6 parameters.
roller.debug = true;
drawSprites();

roller.setCollider("rectangle", 20, 20, 20, 80, 45);