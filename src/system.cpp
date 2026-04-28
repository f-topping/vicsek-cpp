#include "system.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

void System::updateRule(){
	// the Vicsek update rule...

	std::vector<double> new_theta(particleNumber);

	//gets length of x and y of box
	double Lx = this->simulationBox.getSidex();
	double Ly = this->simulationBox.getSidey();

	for (int i = 0; i < particleNumber; i++){
		int count = 1;
		
		double cosineTheta = std::cos(particles[i].theta);
		double sineTheta = std::sin(particles[i].theta);
	
		for (int j = 0; j < particleNumber; j++){
			if (i!=j){
				//calculate distance
				double dx = particles[j].x - particles[i].x;
				double dy = particles[j].y - particles[i].y;
			
				//periodic boundaries
				if(dx>Lx*0.5) dx-=Lx;
				if(dx<-Lx*0.5) dx+=Lx;
				if(dy>Ly*0.5) dy-=Ly;
				if(dy<-Ly*0.5) dy+=Ly;

				//calculate distance between the two particles
				double dist = std::sqrt(dx*dx + dy*dy);
				
				//check if the distance is below the interaction radius
				if(dist < particles[i].r){
					//calculate new orientation
					cosineTheta += std::cos(particles[j].theta);
					sineTheta += std::sin(particles[j].theta);
					count+=1;
				}
			}
		}
		//normalise sine and cosine to get the local average
		cosineTheta /= count;
		sineTheta /= count;

		//average + noise
		double avg_theta = std::atan2(sineTheta,cosineTheta);
		new_theta[i] = avg_theta + this->noiseStrength * this->uniform(-M_PI,M_PI);
	}
	//move the particles
	for (int i = 0; i < particleNumber; i++){
		particles[i].x += std::cos(new_theta[i])*particles[i].v* this->timeStep;
		particles[i].y += std::sin(new_theta[i])*particles[i].v* this->timeStep;
		particles[i].theta = new_theta[i];

		//periodic boundaries
		if (particles[i].x > Lx) particles[i].x -= Lx;
		if (particles[i].x <0) particles[i].x += Lx;
		if (particles[i].y > Ly) particles[i].y -= Ly;
		if (particles[i].y <0) particles[i].y += Ly;
	}

//	std::cout << "Updating the system..." << std::endl;
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

void System::randomStart(){
	for(Particle &p : this->particles){
		p.x = this->uniform(0,this->simulationBox.getSidex());
		p.y = this->uniform(0,this->simulationBox.getSidey());
		p.theta = this->uniform(-M_PI,M_PI); 
	}
}

void System::saveConfig(const std::string &filename)
{   
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return; // Exit if file cannot be opened
    }
    outFile << std::to_string(particles.size())+"\nParticles"<<std::endl;
    
    // Write particle properties to the file

    for (size_t i = 0; i < particles.size(); ++i) {
        outFile << i << " " << particles[i].x <<" "<<particles[i].y<<" "<<particles[i].theta << std::endl;
    }
    
    outFile.close(); // Close the file
}    
