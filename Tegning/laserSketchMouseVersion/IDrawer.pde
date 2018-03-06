interface IDrawer {
	// Interface created in co-operation by Torbjørn and Eivind

	// Set where the drawing pointer currently is.
	// Range: 0-1.
	void setPos(float x, float y);  

	// Clears the canvas
	void clearCanvas();

	// All drawing/display code should be contained here
	// When using an object that implements IDrawer
	// draw() should be called in the draw() look
	// in Processing
	void draw();
}