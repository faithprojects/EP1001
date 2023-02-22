import processing.serial.*;

Serial port;                       // Create object from Serial class

void setup() {
  size(200, 200);
  noStroke();
  frameRate(10);
  // Open the port that the board is connected to and use the same speed (9600 bps)
  port = new Serial(this, "com3", 9600);
}

void draw() {
  background(255);
  if (mouseOverElli() == true)  {  // If mouse is over square,
    fill(255, 184, 76);                     // change color(Orange) and
    port.write('H');               // send an H to indicate mouse is over square
  } else {                         // If mouse is not over square,
    fill(241, 103, 103);                       // change color(Red) and
    port.write('L');               // send an L otherwise
  }
  ellipse(100, 100, 100, 100);          // Draw a square
}


boolean mouseOverElli() {        // Test if mouse is over ellipse
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
}
