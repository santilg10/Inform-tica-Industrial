#include <iostream>

class Mamifero {
public:
	enum { COMEN = 0, MAMAN, CORREN };
};
class Perro : public Mamifero {
	int patas;
public:
	Perro(int p) :patas(p) {}
	//void accion() { return };
};
class Caniche : public Perro{
	int pelo;
public:
	Caniche(int peludo, int patudo) :pelo(peludo), Perro(patudo){}
};