#include <iostream>
#include "system.h"

int main(){
	System mySystem (100, 20.0, 0.5, 0.1); //instantiates a System object mySystem
	mySystem.updateRule();
	std::cout<<"The system has a simulation box of side"<<mySystem.simulationBox.getSidex()<<std::endl;

	return 0;
}

