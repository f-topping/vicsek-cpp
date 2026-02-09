#include "system.h"
#include <iostream>

void System::updateRule(){
	// the Vicsek update rule...
	std::cout << "Updating the system..." << std::endl;
}

System::System(int seed, int particleNumber,double sideLength, double timeStep,double noiseStrength){
	// whatever we want to do as we instantiate the system
	std::cout <<  "I am constructing the System!" << std::endl;
	
	this->particleNumber = particleNumber;
	this->sideLength = sideLength;
	this->timeStep = timeStep;
	this->noiseStrength = noiseStrength;
	this->seed = seed;

	this->simulationBox = Box(sideLength, sideLength, 0, 0);
	this->particles.resize(this->particleNumber);

	this->gen =std::mt19937(seed);
}

double System::uniform(double min, double max){
	return (max-min)*this->uniformDist(gen)+min;
}
