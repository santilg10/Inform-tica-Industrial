#pragma once
#include <iostream>
struct coord_t {
	double x;
	double y;
	double z;
	coord_t(double x, double y, double z) :x(x), y(y), z(z) {}
};

class Esfera {
	double radio;
	coord_t c;
public:
	Esfera(double radio, coord_t c) :c(c), radio(radio) {}
};

class Mundo {
	Esfera e;
public:
	Mundo(Esfera e_out) :e(e_out) {}
/////////////////////////////
//I-O
	std::ostream& print(std::ostream& o);
};

std::ostream& Mundo::print(std::ostream& o) {
	o << "soy un mundo cruel..." << std::endl;
	return o;
}