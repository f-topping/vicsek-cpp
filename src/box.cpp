#include "box.h"
#include <iostream>

Box::Box(){
        // Box creation no parameters
}

Box::Box(double lx, double ly, double x0, double y0){
	// Box creation all parameters
	this->sidex = lx;
	this->sidey = ly;
	this->x0 = x0;
	this->y0 = y0;
}

void Box::setSides(double lx, double ly){
	this->sidex = lx;
	this->sidey = ly;
}

void Box::setOrigin(double x, double y){
	this->x0 = x;
	this->y0 = y;
}

double Box::getSidex(){
	return this->sidex;
}

double Box::getSidey(){
	return this->sidey;
}
