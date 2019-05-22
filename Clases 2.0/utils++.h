//utils++.h: declaration of the class Graph

#ifndef _UTILS++_H
#define _UTILS++_H

#include <iostream>

/****************
* allocation utilities
*
****************/
namespace a309 {
	typedef unsigned char** mat;				//BYTE
	mat allocate_matrix(int N, int M);
	void free_matrix(mat, int N);
	std::ostream& print_matrix(mat m, int N, int M, std::ostream& o);
}

/****************
* class Graph
*
****************/
class Graph {
	int NV;										//numero de vertices
	a309::mat pg;								//matriz de adyacencia

public:
	Graph(int NV_out) :NV(NV_out), pg(NULL) {init_graph(NV) ; }
	int init_graph(int NV);						//alocate memory for empty graph of size NV
	void clear_graph();
////////////////7
	//utilidades



/////////////////
	//I-O
	std::ostream& print_header(std::ostream& o);
	std::ostream& print_edges(std::ostream& o);
};

#endif