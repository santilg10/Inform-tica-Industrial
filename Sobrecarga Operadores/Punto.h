#pragma once
#include <iostream>

class Punto
{
public:
	Punto(double x, double y):x(x), y(y) {}
	Punto() :x(0.0), y(0.0) {};
	virtual ~Punto();
	double x, y;

	void print() { std::cout << "(" << x << "," << y << ")" << std::endl; }

	std::ostream& print(std::ostream& o)
	{
		o << "[" << this->x << "," << this->y << "]" << std::endl;
		return o;
	}

	friend Punto operator+(const Punto& p1, const Punto& p2) 
	{
		std::cout << "soy independiente" << std::endl;
		Punto res;
		res.x = p1.x + p2.x;
		res.y = p1.y + p2.y;
		return res;
	}

	Punto operator+(const Punto&rhs)
	{
		std::cout << "soy miembro" << std::endl;
		Punto res;
		res.x = x + rhs.x;
		res.y = y + rhs.y;
		return res;
	}

	bool operator!()
	{
		return (x == 0.0 && y == 0.0);
	}

	Punto operator+(float k)
	{
		Punto res(*this);
		res.x += k;
		res.y += k;
		return res;
	}
	Punto operator-(float k)
	{
		x -= k;
		y -= k;
		return *this;
	}

	//friend Punto operator+(Punto lhs, const Punto &p) 
	//{
	//	lhs +=rhs;
	//	return lhs;
	//}
};

