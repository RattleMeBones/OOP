#include "rectangle.h"
#include <iostream>
#include <cmath>

rectangle::rectangle() : rectangle(0,0){
}

rectangle::rectangle(double i, double j) : a(i), b(j){
}

rectangle::rectangle(std::istream &is){
	is >> a;
	is >> b;
	c = a;
	d = b;
}

rectangle::rectangle(const rectangle& orig){
	std::cout << "Rectangle copy has been created." << std::endl;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
}

double rectangle::Square(){
	double S = double(a * b);
	return S;
}

void rectangle::Print(){
	std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << "\nd = " << d << std::endl;
}

rectangle::~rectangle(){
	std::cout << "Rectangle has been deleted." << std::endl;
}
