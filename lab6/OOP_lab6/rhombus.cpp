#include "rhombus.h"
#include <iostream>
#include <cmath>

mem_block Rhombus::alloc(sizeof(Rhombus), 20);

Rhombus::Rhombus() : Rhombus(0, 0){
}

Rhombus::Rhombus(double d_1, double d_2) : diag_1(d_1), diag_2(d_2){
	a = sqrt(pow((diag_1 / 2), 2) + pow((diag_2 / 2), 2));
	b = a;
	c = a;
	d = a;
	std::cout << "Rhombus has been created." << a <<", " << b << ", " << c << ", " << d << std::endl;
}

Rhombus::Rhombus(std::istream &is){
	is >> diag_1;
	is >> diag_2;
	a = sqrt(pow((diag_1 / 2), 2) + pow((diag_2 / 2), 2));
	b = a;
	c = a;
	d = a;
}

/*rhombus::rhombus(const rhombus& orig){
	std::cout << "Rhombus copy has been created." << std::endl;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
	diag_1 = orig.diag_1;
	diag_2 = orig.diag_2;
}*/

double Rhombus::Square(){
	return (diag_1 * diag_2) / 2;
}


void *Rhombus::operator new(size_t size) {
	return alloc.allocate();
}

void Rhombus::operator delete(void *mem_ptr) {
	return alloc.deallocate(mem_ptr);
}

Rhombus& Rhombus::operator=(const Rhombus& right){
	if(this == &right){
		return *this;
	}
//std::cout << "Rhombus copied." << std::endl;
	a = right.a;
	b = right.b;
	c = right.c;
	d = right.d;
	diag_1 = right.diag_1;
	diag_2 = right.diag_2;
	return *this;
}

bool Rhombus::operator==(const Rhombus& right) {
	return(diag_1 == right.diag_1 && diag_2 == right.diag_2);
}

Rhombus::~Rhombus(){
	std::cout << "Rhombus has been deleted." << std::endl;
}

std::ostream& operator<<(std::ostream& os, Rhombus& obj) {
	os << "Figure: Rhombus.\nSides:" << std::endl;
	os << "diag 1: " << obj.diag_1 << "\ndiag 2 = " << obj.diag_2 << "\na = b = c = d = " << obj.a << std::endl;
	//os << "Square: "<< obj.Square()  << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rhombus& obj) {
	is >> obj.diag_1;
	is >> obj.diag_2;
	obj.a = sqrt(pow((obj.diag_1 / 2), 2) + pow((obj.diag_2 / 2), 2));
	obj.b = obj.a;
	obj.c = obj.a;
	obj.d = obj.a;
	return is;
}
