#include <math.h>
#include <iostream>
//#define _USE_MATH_DEFINES		//para usar pi como M_PI	(se encuentra dentro de math.h)
#define PI 3.14159265358979323846

class Geom{
	const Cuadrado* pCu;		//puntero a un dato constante para que ese dato no se pueda modificar (se puede modificar el puntero)
	const Circulo* pCir;
	const Triangulo* pT;

/////////
//INTERFAZ
	Geom(Cuadrado* Cu) :pCu(Cu), pCir(NULL), pT(NULL) {}
	Geom(Circulo* Cir) :pCu(NULL), pCir(Cir), pT(NULL) {}
	Geom(Triangulo* T) :pCu(NULL), pCir(NULL), pT(T) {}
	double area();
};
double Geom::area() {			//es necesario que los métodos de área en cada clase sean const ya que los punteros son const tamnbien
	if (pCu != NULL) {pCu->area();}
	if (pCir != NULL) {pCir->area();}
	if (pT != NULL) {pT->area();}
}

class Cuadrado {
private:
	double lado;
public:
	Cuadrado(double l) :lado(l) {}
	double area() const {
		return lado*lado;
	}
};

class Triangulo {
private:
	double base;
	double altura;
public:
	Triangulo(double b, double h) :base(b), altura(h) {}
	double area() const {
		return base*altura / 2;
	}
};

class Circulo {
private:
	double radio;
public:
	Circulo(double r) :radio(r) {}
	double area() const { return PI*radio*radio; }
};


using namespace std;

int main() {
	Circulo c(10.09);
}