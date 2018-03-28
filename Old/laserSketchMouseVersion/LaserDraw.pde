class LaserDraw implements IDrawer {
  
  // Positions
	float prevX, prevY;
	float currX, currY;

  // These in combination is the drawing itself
	PGraphics gFill;
	PGraphics gMask;

  // Images user for drawing highlight
	PImage innerLight;
	PImage outerLight;

  // Used to coordinate a flash effect
	int flash = 0;

  // Particle system used for sparks
	ParticleSystem ps;

	LaserDraw() {
		gFill = createGraphics(width, height);
		gFill.beginDraw();
			gFill.background(255, 1);
		gFill.endDraw();
		gMask = createGraphics(width, height);

		innerLight = loadImage("innerLight.png");
		outerLight = loadImage("outerLight.png");

		ps = new ParticleSystem();

    currX = width/2;
    currY = height/2;
    prevX = width/2;
    prevY = height/2;
	}

	void setPos(float x, float y) {
		prevX = currX;
		prevY = currY;

		currX = x * width;
		currY = y * height;
	}

	void clearCanvas() {
    // Use the flash variable to check if we
    // super recently did a canvas
		if (flash <= 0) {
			flash = 175; // flash itself is drawn in draw()

      // Flying sparks when you clear!
      for (int i=0; i<25; i++) {
        ps.emit(random(0,width), random(0,height), 1);
      }
      
      // Actually do the clearing of the canvas
			gMask.beginDraw();
				gMask.fill(0, 185);
				gMask.rect(0, 0, width, height);
			gMask.endDraw();
		}
		
	}

  // Draw could in theory be split into two functions: 
  // iterate() and draw(), but I wanted to keep IDrawer simple
  
	void draw() {
    // Clear background (for effects, etc...)
		background(0);
    
    // Distance between current and previous point
    // is used to calculate intensity of many effects
		float t = dist(prevX, prevY, currX, currY);


    // DRAWING CODE FOR THE ETCH
    // (INCLUDING SLOWLY FADING RED EFFECT)
    
    // Draw initial red (glowing hot) lines
		gFill.beginDraw();
      
			gFill.stroke(255, 0, 0);
			gFill.line(prevX, prevY, currX, currY);

      // Gradually fade it out to the regular color
			gFill.noStroke();
			gFill.fill(150, 10);
			gFill.rect(0, 0, width, height);
		gFill.endDraw();

    // Use a mask to make the whole red afterglow possible
		gMask.beginDraw();
			gMask.stroke(255);
			gMask.line(prevX, prevY, currX, currY);
		gMask.endDraw();

		gFill.mask(gMask);
		image(gFill, 0, 0);
    
    
    // SPECTACULAR YELLOW SHINE EFFECT
    for (float f = 0; f <= 1; f += 0.01) {
      float lx = lerp(prevX, currX, f);
      float ly = lerp(prevY, currY, f);
      
      // Pointer
      fill(37, 255, 230, 255);
      noStroke();
      ellipse(lx, ly, 2, 2);   
    }
    
    
    // LIGHT AND ILLUMINATION EFFECTS
    float shinyness = t * 1.5 + 20;
		imageMode(CENTER);
		float randomShimmer = random(0, 50);
		tint(255, shinyness + randomShimmer);
		image(outerLight, currX, currY);
		tint(255, shinyness + randomShimmer);
		image(innerLight, currX, currY);
		tint(255);
		imageMode(CORNERS);

		stroke(255, t + random(60, 150));
		point(currX, currY);
    
    
    // SPARK EFFECTS
    // Emit particles (sparks) based on speed
    if (t > 1) {
      // If moving emit alongside the movement
      float chanceOfParticle = t / 750;
      for (float f = 0; f <= 1; f += 0.1) {
        float lx = lerp(prevX, currX, f);
        float ly = lerp(prevY, currY, f);
  
        // Particles (sparks)
        if (chanceOfParticle > random(0, 1)) {
          ps.emit(lx, ly, 1);
        }
      }
    }
    else {
      // If standing still emit a few
      if (0.075 > random(0, 1)) {
        ps.emit(currX, currY, 1);
      }
    }
    ps.iterate();
    ps.draw();
	

    // FLASH EFFECT
		if (flash > 0) {
			flash -= 8;
			fill(255, flash);
			rect(0, 0, width, height);
		}
		
	}

}