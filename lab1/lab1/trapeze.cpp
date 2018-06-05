#include "trapeze.h"
#include <iostream>
#include <cmath>

trapeze::trapeze() : trapeze(0, 0, 0){
};

trapeze::trapeze(double i, double j, double h) : a(i), b(j), height(h){
}

trapeze::trapeze(std::istream &is){
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

trapeze::trapeze(const trapeze& orig){
	std::cout << "Trapeze copy has been created." << std::endl;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
	height = orig.height;
}

double trapeze::Square(){
	return (a + b)/2 * height;
}

void trapeze::Print(){
	std::cout << "a = " << a << "\nb = " << b << "\nheight = " << height << "\nc = d = " << c << std::endl;
}

trapeze::~trapeze(){
	std::cout << "Trapeze has been deleted." << std::endl;
}
