#pragma once
#include <iostream>
#include <string>

class Complex {
private:
	double i;
	double j;
public:
	void set(double i_out, double j_out);
	double modulo();
	Complex(double i, double j) {		//constructor se nombra con el mismo nombre que la clase
		Complex::i = i;
		Complex::j = j;
	}
	Complex();
	~Complex();
	void print() const;
};

class Pareja {
private:
	//datos miembro de la clase Pareja
	int a, b;
public:
	//constructor
	Pareja(int a2, int b2);
	//funciones miembro de la clase Pareja
	void lee(int &a2, int &b2);
	void guarda(int a2, int b2);
};

struct coord_t {
	double x;
	double y;
	double z;
	coord_t(double xo, double yo, double zo) :x(xo), y(yo), z(zo) { ; }
};

class Esfera {
	double r;
	coord_t c;
public:
	std::ostream& print(std::ostream& o) const;

};