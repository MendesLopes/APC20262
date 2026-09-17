var grass = createSprite(200,200);
grass.setAnimation("floating_grass");
var alien = createSprite(180,100);
alien.setAnimation("alien");
alien.scale = 1.3;
var robot = createSprite(300,300);
robot.setAnimation("robot");
robot.scale = 0.2;
drawSprites();



textSize(20);
fill("black");
stroke("blue");
text("eu estou codando muito! huhuhuhu... ", 30, 100);

textSize(30);
fill("black");
stroke("blue");
text("Como está aí? ", 180, 200);

//Achei o exercício interessante para aprender como funciona a parte dos e entender melhor como funciona