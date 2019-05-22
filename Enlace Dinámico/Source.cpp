#include <iostream>

using namespace std;

//virtual califica a las funciones miembro con enlace dinámico en la declaración de clase

class Objeto {
public:
	virtual ostream& print(ostream& o=cout) const {		//si no ponemos virtual aquí, al visualizar el resto de objetos
		o << "soy un objeto" << endl;					//se escribirá siempre "soy un objeto" sin especificar el tipo de objeto que es
		return o;
	}
	virtual ~Objeto() {									//vemos que con poner virtual aquí, el resto de clases derivadas llaman al
		cout << "Destructor Objeto";					//destructor de cada clase (en ausencia de ellas llaman a este)
	}

};
class Taza :public Objeto {
protected:
	virtual ostream& print(ostream& o=cout)const {		//no es necesario declararla como virtual porque ya está hecho 
		o << "soy una taza" << endl;					//en el nivel anterior (es un virtual meramente informativo)
		return o;										//tampoco hace falta en las clases derivadas
	}
};
class TazaGrande :public Taza {
private:
	virtual ostream& print(ostream& o = cout) const {
		o << "soy una taza grande" << endl;
		return o;
	}
};
class Tetera :public TazaGrande {
protected:
	virtual ostream& print(ostream& o = cout) const {
		o << "soy una tetera" << endl;
		return o;
	}
};
class TeteraMini :public Tetera {
private:
	virtual ostream& print(ostream& o = cout) const {		//vemos que el nivel de acceso de esta funcion no importa,
		o << "soy una tetera mini" << endl;					//la funcion de esta clase derivada es accesible dependiendo del
		return o;											//nivel de acceso de la clase base (la que contiene el virtual)
	}
public:
	~TeteraMini() {
		cout << "Destructor TeteraMini";
	}
};

//////////////////////////////////////////////////////////////////
//OTRO EJEMPLO
class Task {
public:
	virtual int run() = 0;			//clase abstracta que sirve para establecer el enlace dinámico
};


class PathFinding :public Task {

};
class Dijstra :public Task {		//algoritmo para buscar el camino óptimo entre dos puntos
	int run() {
		cout << "Path Finding Dijstra" << endl;
		return 0;
	}
};
class Bellman :public Task {		//algoritmo para buscar el camino óptimo entre dos puntos
	int run() {
		cout << "Path Finding Bellman" << endl;
		return 0;
	}
};


class Clique :public Task {

};
class SanSegundo :public Clique {
	int run() {
		cout << "Clique San Segundo" << endl;
		return 0;
	}
}; class Japones :public Clique {
	int run() {
		cout << "Clique Japones" << endl;
		return 0;
	}
};

//gestor de tareas
class TaskManager {
	Task* pt;

public:
	TaskManager(Task* pt_out) :pt(pt_out) {};
	int run() {
		return pt->run();
	}
};

//sobrecarga operador texto (<<)
ostream& operator <<(ostream& o, const Objeto& obj) {
	obj.print();
	return o;												//te permite escribir cout<<t para escribir "soy una taza" y demas...
}

//gestor de objetos
void visualizar_objetos(const Objeto& ob) {
	ob.print();
}

int main() {
	Taza t;
	Objeto o;
	TazaGrande tg;

	visualizar_objetos(o);
	visualizar_objetos(t);
	visualizar_objetos(tg);

//-------------------------------------------------------------------------------
//Ejemplo con otras clases derivadas
	Tetera tet;
	cout << tet;

	TeteraMini tetmini;
	cout << tetmini;

//-------------------------------------------------------------------------------
//Ejemplo con lista de objetos ->según Alberto se puede ver la potencia de esta herramienta
	Objeto* l[3];			//permite crear varios objetos más fácilmente
	l[0] = new Taza;
	l[1] = new Tetera;
	l[2] = new TeteraMini;
	for (int i = 0; i < 3; i++) {
		l[i]->print();
	}

//--------------------------------------------------------------------------------
//Ejemplo con el Task Manager
	Dijstra d;
	TaskManager tm(&d);
	tm.run();
	SanSegundo c;
	TaskManager tm2(&c);
	tm2.run();

	//liberar espacio de memoria
	for (int i = 0; i < 3; i++) {
		delete l[i];				//problema->solo llama al destructor base
									//solucion->es necesario llamar virtual al destructor
	}


}

/*	RESUMEN DEL FUNCIONAMIENTO DEL ENLACE DINÁMICO
		Un puntero o referencia declarada como base que recibe un puntero a
		una clase derivada ejecutará la función miembro virtual de la clase derivada.

		De no existir, ejecutará la primera especialización que encuentre aguas
		arriba en la jerarquía ó, en su defecto, la propia función de la clase base.

		La propiedad virtual se hereda siempre que la función tenga exactamente el mismo 
		tipo de argumentos y valor de retorno (en caso contrario no se considerará redefinida).

		Para acceder explícitamente a la función de la clase base se utiliza el operador "::".
*/