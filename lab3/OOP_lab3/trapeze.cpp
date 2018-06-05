#include "trapeze.h"
#include <iostream>
#include <cmath>

Trapeze::Trapeze() : Trapeze(0, 0, 0){
};

Trapeze::Trapeze(double i, double j, double h) : a(i), b(j), height(h){
	if (a > b){
		c = sqrt(pow(height, 2) + pow((a - b) / 2, 2));
	}else if(a < b){
		c = sqrt(pow(height, 2) + pow((b - a) / 2, 2));
	}
	d = c;
   std::cout << "Trapeze has been created." << a << ", " << b << ", " << c << ", " << d << ", " << height << std::endl;
}

Trapeze::Trapeze(std::istream &is){
	is >> a;
	is >> b;
	is >> height;
	if (a > b) {
		c = sqrt(pow(height, 2) + pow((a - b) / 2, 2));
	}
	else if (a < b) {
		c = sqrt(pow(height, 2) + pow((b - a) / 2, 2));
	}
	d = c;
}

/*trapeze::trapeze(const trapeze& orig){
	std::cout << "Trapeze copy has been created." << std::endl;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
	height = orig.height;
}*/

double Trapeze::Square(){
	return (a + b)/2 * height;
}

Trapeze::~Trapeze(){
	std::cout << "Trapeze has been deleted." << std::endl;
}

Trapeze& Trapeze::operator=(const Trapeze& right) {
	if (this == &right) {
		return *this;
	}
	//std::cout << "Trapeze copied." << std::endl;
	a = right.a;
	b = right.b;
	c = right.c;
	d = right.d;
	height = right.height;
	return *this;
}

bool Trapeze::operator==(const Trapeze& right) {
	return (height == right.height && a == right.a && b == right.b);
}

std::ostream& operator<<(std::ostream& os, Trapeze& obj) {
	os << "Figure: Trapeze.\nSides:" << std::endl;
	os << "Height: " << obj.height << "\na = " << obj.a << "\nb = " << obj.b << "\nc = d = " << obj.c << std::endl;
	//os << "Square: "<< obj.Square()  << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj) {
	is >> obj.a;
	is >> obj.b;
	is >> obj.height;
	if (obj.a > obj.b) {
		obj.c = sqrt(pow(obj.height, 2) + pow((obj.a - obj.b) / 2, 2));
	}
	else if (obj.a < obj.b) {
		obj.c = sqrt(pow(obj.height, 2) + pow((obj.b - obj.a) / 2, 2));
	}
	obj.d = obj.c;
	return is;
}