class Particle {
  // One particle (spark) in the particle system
  
  // Vectors used for posisition and animation
	PVector prevPos, pos, vel, acc;

  // Energy represent how "alive" a particle is
	float ENERGY_MAX = 255;
	float energy;
	float energyFadeSpeed;

  // Range values for random generation
  // of velocities and accelerations
	float rangeVel = 0.8,
		    rangeAcc = 0.06;

	Particle () {
    // Initial values are "dead"
    // since the particles are added
    // visible on screen using the reset() function
    prevPos = new PVector(-1, -1);
		pos = new PVector(-1, -1);
    vel = new PVector();
    acc = new PVector();
    acc = new PVector();
    energy = 0;
		energyFadeSpeed = 5;
	}

  void reset(float x, float y) {
    // "Make alive" this particle for use by
    // the particle systm at specificed coordinates
    
    prevPos.set(x, y);
    pos.set(x, y);
    
    float velX = random(-rangeVel, rangeVel) * 2;
    float velY = random(-rangeVel*2, rangeVel) * 2;
    float accX = random(-rangeAcc, rangeAcc);
    float accY = random(-rangeAcc*2, rangeAcc);
    
    vel.set(velX, velY);
    acc.set(accX, accY);
    
    energy = random(ENERGY_MAX-150, ENERGY_MAX);
  }

	void iterate() {
    // Update positions and energy
    // (do this every draw() loop for animation)
  
		prevPos = pos.copy();
		acc.add(0, 0.035);
		vel.add(acc);
		vel.limit(3.5);
		pos.add(vel);
		energy -= energyFadeSpeed;
	}

	void draw() {
    // Actually display the particle
  
		colorMode(HSB, 255);
		strokeWeight(2);
		stroke(energy/7, 255, 255, energy*10);
		line(prevPos.x, prevPos.y, pos.x, pos.y);
	}

}