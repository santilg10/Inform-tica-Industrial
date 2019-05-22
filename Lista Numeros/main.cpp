#include "complex.h"
#include <iostream>
#include "listanum.h"

void main() {
	Complex miComplejo(1.0,1.0);	//constructor definido de una manera
	std::cout << miComplejo.modulo() << std::endl;
	miComplejo.set(4.0, 3.0);
	Complex miComplejo1;			//constructor definido sin argumentos
	std::cout << miComplejo.modulo() << std::endl;
	std::cout << miComplejo1.modulo() << std::endl << std::endl;
	


	std::cout << "--------------" << std::endl<< std::endl;

	Pareja par1(12, 32); //cuando se declara un objeto de una clase, se llama directamente al constructor
	int x, y;
	par1.lee(x, y);
	std::cout << "valor de par1.a:" << x << std::endl;
	std::cout << "valor de par1.b:" << y << std::endl;
	std::cout << "introduce valor de a:" << std::endl;
	std::cin >> x;
	std::cout << "introduce valor de b:" << std::endl;
	std::cin >> y;
	par1.guarda(x, y);
	par1.lee(x, y);
	std::cout << "valor de par1.a:" << x << std::endl;
	std::cout << "valor de par1.b:" << y << std::endl<< std::endl;

	std::cout << "--------------" << std::endl << std::endl;


	ListaNum lista(0); //nElem = 0
	lista.add_elem(3);
	lista.add_elem(87);
	lista.add_elem(9);
	lista.add_elem(1);
	lista.print();

}

int foo(const Esfera& e) {
	e.print(cout);
}