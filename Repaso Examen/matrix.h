#pragma once
#include <iostream>

class Matrix {
private:
	int N;		//numero de filas
	int M;		//numero de columnas
	int** pm;	//puntero que apunta a punteros
public:
	Matrix(int Nfil, int Ncol);
	Matrix();
	~Matrix();
	std::ostream& print(std::ostream&);
	void rellenar(int);
};