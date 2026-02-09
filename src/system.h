#ifndef SYSTEM_H
#define SYSTEM_H

#include <random>
#include <vector>
#include "box.h"
#include "particle.h"

class System {
	public:
		System(int seed, int particleNumber, double sideLength, double timeStep, double noiseStrength);
		int seed;
		int particleNumber;
		double noiseStrength;
		double timeStep;
		double sideLength;

		Box simulationBox;
		std::vector<Particle> particles;

		void updateRule();

		std::mt19937 gen;
		std::uniform_real_distribution<double> uniformDist;
		double uniform(double min, double max);
		
};

#endif

