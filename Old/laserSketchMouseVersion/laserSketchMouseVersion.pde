// This is a version that works without
// the Arduino and is steered using mouse
// instead.

IDrawer drawer;

void setup() {
	size(800, 800);
  //fullScreen();
	noSmooth();
	drawer = new LaserDraw();
	noCursor();
	colorMode(HSB, 255);
}

void draw() {
	drawer.setPos((float) mouseX/width, (float) mouseY/height);
	drawer.draw();
  if (keyPressed && key == 'c') {
    drawer.clearCanvas();
  }


}