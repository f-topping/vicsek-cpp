#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>

class Particle {
        public:
		//constructor (default)
                Particle();

		double x; //coordinates
		double y;
		double theta; //angle
		double v; //velocity magnitude
		double r; //radius of interaction
                
};

#endif
