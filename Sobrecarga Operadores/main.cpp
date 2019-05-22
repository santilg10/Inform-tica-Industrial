#include "Punto.h"

void main() {
	Punto p;
	Punto p1(5.0, 7.0), p3;

	//modo natural
	(p + p1).print(std::cout);

	//explicito
	operator+(p, p1).print();			//llama estrictamente a la funcion independiente (tiene dos entradas)
	p.operator+(p1).print();			//llama estrictamente a la funcion miembro
	if (!p) {
		std::cout << "estoy en el orgien" << std::endl;
	}

	//traslacion
	p3 = p3 + 17.5;
	p3.print();
	(p3 - 12.0).print();

	int l[20];
	int index = 10;
	int k1 = l[index++];
	int k2 = l[++index];
}