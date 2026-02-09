#include "system.h"
#include <iostream>

void System::updateRule(){
	// the Vicsek update rule...
	std::cout << "Updating the system..." << std::endl;
}

System::System(int particleNumber,double sideLength, double timeStep,double noiseStrength){
	// whatever we want to do as we instantiate the system
	this->particleNumber = particleNumber;
	this->sideLength = sideLength;
	this->timeStep = timeStep;
	this->noiseStrength = noiseStrength;
	std::cout <<  "I am constructing the System!" << std::endl;
	this->simulationBox = Box(sideLength, sideLength, 0, 0);
}


