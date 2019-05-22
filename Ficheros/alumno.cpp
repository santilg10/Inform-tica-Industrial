#include <string>
#include <iostream>
#include <fstream>
#include "alumno.h"

using namespace std;

void pide_datos(alumno &alum);	

void enseña_datos(alumno alum);

void guardar(string filename, alumno &alum);

void main(){
	alumno a;
	pide_datos(a);
	enseña_datos(a);
}

void pide_datos(alumno &alum) {
	cout << "Introduce nombre, asignatura, num matricula y grupo" << endl;
	cin >> alum.nombre >> alum.asignatura >> alum.id_mat >> alum.id_grupo;
}
void enseña_datos(alumno alum) {
	cout << "Nombre:" << alum.nombre << endl;
	cout << "Asignatura:" << alum.asignatura << endl;
	cout << "Num. Matricula:" << alum.id_mat << endl;
	cout << "Grupo:" << alum.id_grupo << endl;
}

void guardar(string filename, alumno &alum) {
	ofstream myfile;
	myfile.open(filename);
}