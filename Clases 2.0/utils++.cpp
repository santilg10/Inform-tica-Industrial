//utils++.cpp : definitions of class Graph
#include "utils++.h"

using namespace std;		//en el archivo .h no se usa por higiene, pero aqui se puede usar libremente

namespace a309 {
	mat allocate_matrix(int N, int M) {
		mat m = new unsigned char*[N];
		for (int i = 0; i < N; i++) {
			m[i] = new unsigned char[M];
		}
		//checking: if(m==NULL){return NULL;}

		//initialization to empty matrix
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				m[i][j] = 0;
			}

		return m;
	}
	void free_matrix(mat m, int N) {
		for (int i = 0; i < N; i++) {
			delete[] m[i];
		}
		delete[] m;
		m = NULL;
	}
	ostream& print_matrix(mat m, int N, int M, ostream& o) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				o << static_cast<int>(m[i][j]) << " ";	//el static_cast convierte lo que hay a la derecha en lo que hay dentro del <...>
				//printf("%d ", m[i][j]);
			}
			o << endl;
		}
	}
}
void Graph::clear_graph() {
	a309::free_matrix(this->pg, NV);
	this->NV = 0;
}


int Graph::init_graph(int NV) {

	clear_graph();

	//reservo espacio en memoria e inicializo a 0
	this->NV = NV;
	pg = a309::allocate_matrix(this->NV, this->NV);
	return 0;	//OK
}
ostream& Graph::print_header(ostream& o) {
	o << "grafo con " << this->NV << " vertices" << endl;
	return o;  
}
ostream& Graph::print_edges(ostream& o) {
	for (int i = 0; i<this->NV - 1; i++) {
		for (int j = i + 1; j<this->NV; j++) {
			if (pg[i][j]==1) {
				o << "[" << i << "--" << j << "]" << endl;
			}
		}
	}
	return o;
}