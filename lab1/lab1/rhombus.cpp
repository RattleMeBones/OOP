#include "rhombus.h"
#include <iostream>
#include <cmath>

rhombus::rhombus() : rhombus(0, 0){
}

rhombus::rhombus(double d_1, double d_2) : diag_1(d_1), diag_2(d_2){
}

rhombus::rhombus(std::istream &is){
	is >> diag_1;
	is >> diag_2;
	a = sqrt(pow((diag_1 / 2), 2) + pow((diag_2 / 2), 2));
	b = a;
	c = a;
	d = a;
}

rhombus::rhombus(const rhombus& orig){
	std::cout << "Rhombus copy has been created." << std::endl;
	diag_1 = orig.diag_1;
	diag_2 = orig.diag_2;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
}

double rhombus::Square(){
	return (diag_1 * diag_2) / 2;
}

void rhombus::Print(){
	std::cout << "\ndiagonal 1 = " << diag_1 << "\ndiagonal 2 = " << diag_2 << "\na = b = c = d = " << a << std::endl;
}

rhombus::~rhombus(){
	std::cout << "Rhombus has been deleted." << std::endl;
}
