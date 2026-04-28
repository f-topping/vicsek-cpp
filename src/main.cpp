#include <iostream>
#include "system.h"

int main(){
	System mySystem (13, 100, 20.0, 0.5, 0.1); //instantiates a System object mySystem
	/*mySystem.updateRule();
	
	mySystem.randomStart();
	mySystem.saveConfig("init.conf");
	std::cout<<"The system has a simulation box of side"<<mySystem.simulationBox.getSidex()<<std::endl;
	std::cout<<mySystem.uniform(10,20)<<std::endl;
	*/

        mySystem.randomStart();
	mySystem.saveConfig("init.conf");

	std::string root = "frame";
	for (int i = 0; i < 1000; i++){
		mySystem.updateRule();
		mySystem.saveConfig(root+std::to_string(i));
	//	std::cout << "hi";

	}
	return 0;
}

