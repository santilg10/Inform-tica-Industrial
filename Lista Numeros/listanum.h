#pragma once
#define MAX_ELEM	100
#include <string>

class ListaNum {
private:
	int nElem;
	int lista[MAX_ELEM];
public:
	ListaNum(int nElementos = 0) { nElem = nElementos; }
	enum {EMPTY_POS=0xFFFFFF};
	typedef size_t npos;
	void add_elem(int dato);
	int get_elem(int pos);
	int get_size();
	void print();
/*
	//constructor apropiado
	void	push_back(int dato);
	int		at(int pos);
	npos	find(int elem);
	size_t	size();
	void	clear();
*/
	// I/O
	//string to_string();
	//ostream& print(ostream&);


};