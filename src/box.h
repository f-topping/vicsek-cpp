#ifndef BOX_H
#define BOX_H

#include <vector>


class Box{
	private:
		//variables
		double sidex;
                double sidey;
                double x0;
                double y0;
        public:
		//constructors
		Box();
                Box(double lx, double ly, double x0, double y0);

		//setters and getters
                void setSides(double lx, double ly);
		void setOrigin(double x, double y);
		double getSidex();
		double getSidey();
};

#endif
