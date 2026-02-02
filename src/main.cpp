#include <iostream>
#include "system.h"

int main(){
	System mySystem (100, 20.0, 0.5, 0.1); //instantiates a System object mySystem
	mySystem.updateRule();
	return 0;
}

