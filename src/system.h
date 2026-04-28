#define SYSTEM_H

#include <random>
#include <vector>
#include <string>
#include <fstream>
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
		
		void randomStart();

		void saveConfig(const std::string &filename);		

		std::vector<double> new_theta(int particleNumber);
                int count;
		double dist;
		double Lx;
		double Ly;
                double cosineTheta;
                double sineTheta;
		double dx;
		double dy;
                double avg_theta;
};

//#endif

