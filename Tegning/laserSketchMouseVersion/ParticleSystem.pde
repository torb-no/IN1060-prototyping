class ParticleSystem {
  
  // Particel System specific to sparks

	Particle[] particles;

	ParticleSystem () {
		particles = new Particle[110];

    // Set up and all particles
    // Reuse same objects to avoid too
    // much garbage collection as that makes 
    // the animations choppy
    for (int i=0; i<particles.length; i++) {
      particles[i] = new Particle(); 
    }
	}

	void clear() {
		for (int i=0; i<particles.length; i++) {
			particles[i] = null;
		}
	}

	void emit(float x, float y, int addedCount) {
    // Add particles/sparks by reusing
    // dead objects
  
		int added = 0;
		for (int i = 0; i<particles.length; i++) {
			if (particles[i].energy <= 0) {
				particles[i].reset(x, y);
				added++;
			}
			if (added >= addedCount) break;
		}
	}

	void iterate() {
    // Iterate so all values are updated
  
		for (int i=0; i<particles.length; i++) {
			if (particles[i].energy > 0) {
				particles[i].iterate();
			}			
		}
	}

	void draw() {
    // Actually draw the particles on screen
  
		for (int i=0; i<particles.length; i++) {
			if (particles[i].energy > 0) {
				particles[i].draw();
			}
		}
	}

}