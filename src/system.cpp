#include "system.h"
#include <iostream>

void System::updateRule(){
	// the Vicsek update rule...
	std::cout << "Updating the system..." << std::endl;
}

System::System(){
	// whatever we want to do as we instantiate the system
	std::cout <<  "I am constructing the System!" << std::endl;
}


