// + atributo publico
// - atributo privado
// # atributo protegido	-> es publico para la clase derivada pero privado para el resto de clases

#include <iostream>

using namespace std;
class Base {
public:
	int x;
	Base(int x=0) :x(x) {}		//este constructor va en pareja con el constructor igual de Derivada (*)
	Base(const Base& b) { cout << "llamada al constructor base" << endl; };	//este constructor va asociado a su pareja en Derivada (**)

	Base& operator = (const Base& rhs);
};

class Derivada : public Base {
public:
	int y;
	
	Derivada(int x) :Base(x) { y = 10; }		//(*)
	Derivada(const Derivada& d):Base(d) {y = d.y; }			//(**)

	Derivada& operator = (const Derivada& rhs);
};

//Base& Base::operator = (const Base& rhs)

Derivada& Derivada::operator = (const Derivada& rhs) {
	//me copio
	if (this != &rhs) {
		//copio la parte derivada
		this->y = rhs.y;
		//copio la parte base
		this->x = rhs.x;
		*static_cast<Base*>(this) = rhs;
	}
}

void main() {
	Derivada d(5);
	Derivada d1(d);
	d1 = d;
	cout << d1.x << " "<< d1.y << endl;

}