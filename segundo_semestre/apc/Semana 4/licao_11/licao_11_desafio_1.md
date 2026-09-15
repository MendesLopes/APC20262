var clicks = 0;

function draw() {
  // add clicks when the space bar is pressed
  if (keyWentDown("space")) {
      clicks = clicks + 1;
  }
  background("white");
  textSize(50);
  text(clicks, 165, 175, 70, 50);
}