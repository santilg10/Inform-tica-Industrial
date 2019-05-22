#include <iostream>
#include "matrix.h"
#include <fstream>


using namespace std;

int referencia(int & a) {
	a += 1;
	return a;
}

void main() {
	/*int a = 5;
	referencia(a);
	cout << a << endl;*/
	Matrix matriz22;
	matriz22.rellenar(1);
	matriz22.print(cout);
	


	Matrix mimatriz(20, 20);
	mimatriz.rellenar(1);
	mimatriz.print(cout);
	ofstream mifichero("mifichero.txt");
	mimatriz.print(mifichero);

	return;
}