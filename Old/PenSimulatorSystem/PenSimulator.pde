class PenSimulator {
  
  PImage penImage;
  PGraphics canvas;
  
  // Current positions
  float xPrev, yPrev;
  float xPos, yPos;
  final float divider = 100;
  
  void penBegin() {
    xPos = width / 2;
    yPos = height / 2;
    penImage = loadImage("red-marker.png");
    canvas = createGraphics(width, height);
    canvas.beginDraw();
      canvas.background(255);
      //canvas.noStroke();
      canvas.stroke(240, 0, 0);
      canvas.strokeWeight(5);
      //canvas.fill(240, 0, 0);
    canvas.endDraw();
  }
  
  void penMove(int xMove, int yMove) {
    xPrev = xPos;
    yPrev = yPos;
    xPos += (float) xMove / divider;
    yPos += (float) yMove / divider;
    
    if (xPos < 0) xPos = 0;
    if (xPos > width) xPos = width;
    
    if (yPos < 0) yPos = 0;
    if (yPos > height) yPos = height;
  }
  
  void draw() {
    canvas.beginDraw();
      //canvas.ellipse(xPos, yPos, 5, 5);
      canvas.line(xPrev, yPrev, xPos, yPos);
    canvas.endDraw();
    
    image(canvas, 0, 0);
    image(penImage, xPos, yPos-penImage.height);
  }
  
}