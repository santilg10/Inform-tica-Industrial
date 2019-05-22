#include <iostream>
#include <string>
#define UNIT_TEST_PUNTO
#define UNIT_TEST_PUNTO_COL

using namespace std;

class _PuntoBase {
private:
	int id;
public:
	enum rep_t { CRUZ = 0, ESTRELLA, CIRCULO };
	enum color_t { AZUL = 0, BLANCO, NEGRO };
	static string to_string(rep_t);			//static para que dependa solo de la clase y no del objeto
	static string to_string(color_t);

	//////////////////
	//interfaz
	_PuntoBase(int id_out) :id(id_out) {};
	ostream& print(ostream& o = cout) const { o << "id: " << id << endl; return o; }
};

string _PuntoBase::to_string(rep_t r) {
	string res;
	switch (r) {
	case CRUZ:
		res = "CRUZ";
		break;
	case ESTRELLA:
		res = "ESTRELLA";
		break;
	case CIRCULO:
		res = "CIRCULO";
		break;
	}
	return res;
}
string _PuntoBase::to_string(color_t r) {
	string res;
	switch (r) {
	case AZUL:
		res = "AZUL";
		break;
	case BLANCO:
		res = "BLANCO";
		break;
	case NEGRO:
		res = "NEGRO";
		break;
	}
	return res;
}


class Punto : public _PuntoBase{
	double x;
	double y;

	//////////////
	//interfaz
public:
	Punto(double x = 0.0, double y = 0.0, int id = 1) :x(x), y(y), _PuntoBase(id) {};	//se necesita llamar al constructor de la clase _PuntoBase
																						//para el constructor de de la clase Punto
	Punto(const Punto& p, int id_out) :x(p.x), y(p.y), _PuntoBase(id_out) {};
	ostream& print(ostream& o = cout) const {
		_PuntoBase::print();
		o << "[ " << x << " , " << y << " ]" << endl;
		return o;
	};
}; 

class PuntoCol :public Punto {
	rep_t r;
	color_t col;

public:
	/////////
	//interfaz
	PuntoCol(rep_t r, color_t c, const Punto& p) :r(r), col(c), Punto(p) {};		//para este constructor solo necesito fijarme en el
																					//constructor de la clase inmediatamente anterior a esta
	ostream& print(ostream& o = cout) const {
		Punto::print(o);
		o << to_string(r) << " " << to_string(col) << endl;
		return o;
	};
};




void main() {
#ifdef UNIT_TEST_PUNTO
	Punto p(3.15, 7.45, 100);
	p.print();
#endif

#ifdef UNIT_TEST_PUNTO_COL
	PuntoCol pc(_PuntoBase::ESTRELLA, _PuntoBase::AZUL, Punto(10.0, 11.0, 110));
	pc.print();
	pc.Punto::print();
	pc._PuntoBase::print();
#endif
}

