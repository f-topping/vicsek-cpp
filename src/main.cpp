#include <iostream>
#include "system.h"

int main(){
	System mySystem (15, 100, 20.0, 0.5, 0.1); //instantiates a System object mySystem
	mySystem.updateRule();
	std::cout<<"The system has a simulation box of side"<<mySystem.simulationBox.getSidex()<<std::endl;
	std::cout<<mySystem.uniform(10,20)<<std::endl;
	return 0;
}

