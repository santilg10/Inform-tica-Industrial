#include <math.h>
#include "complex.h"

double Complex::modulo() {
	return sqrt(i*i + j*j);
}
void Complex::set(double i_out, double j_out) {	//llamada al constructor con argumentos variables
	i = i_out;
	j = j_out;
}
Complex::Complex() {	//llamada al constructor sin argumentos
	i = 0.0; j = 0.0;
}
//el constructor esta sobrecargado, puede iniciarse de dos maneras distintas
Complex::~Complex() {
	std::cout << "Llamada al destructor" << std::endl;
}
void Complex::print() const {
	std::cout << i << " " << j << std::endl;
}

Pareja::Pareja(int a2, int b2) {
	a = a2;
	b = b2;
}
//este constructor es equivalente a escribir:
//pareja::pareja(int a2, int b2) : a(a2), b(b2) {} 

void Pareja::lee(int &a2, int &b2) {
	a2 = a;
	b2 = b;
}
void Pareja::guarda(int a2, int b2) {
	a = a2;
	b = b2;
}

std::ostream& Esfera::print(std::ostream& o) const {
	o << "E:[" << "," << c.y << "," << c.z << "]" << std::endl;
	return o;
}