var rock = createSprite(200, 350);
rock.setAnimation("rock");
rock.velocityY =  -10;
rock.rotationSpeed = 2;

function draw() {
  background("skyblue");
  
  // update sprites
  rock.velocityY = rock.velocityY +0.16;
  
  drawSprites();
}
