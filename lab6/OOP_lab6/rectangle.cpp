#include "rectangle.h"
#include <iostream>
#include <cmath>

mem_block Rectangle::alloc(sizeof(Rectangle), 20);

Rectangle::Rectangle() : a(0), b(0){
	c = a;
	d = b;
}

Rectangle::Rectangle(double i, double j) : a(i), b(j) {
	c = a;
	d = b;
}

Rectangle::Rectangle(std::istream &is){
	is >> a;
	is >> b;
	c = a;
	d = b;
	//std::cout << "Rectangle has been created.\n" << std::endl;
}

/*Rectangle::Rectangle(const Rectangle& orig){
	//std::cout << "Rectangle copy has been created." << std::endl;
	a = orig.a;
	b = orig.b;
	c = orig.c;
	d = orig.d;
}*/

double Rectangle::Square(){
	double S = double(a * b);
	return S;
}

void *Rectangle::operator new(size_t size){
	return alloc.allocate();
}

void Rectangle::operator delete(void *mem_ptr){
	return alloc.deallocate(mem_ptr);
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
	if (this == &right) {
		return *this;
	}
	//std::cout << "Rectangle copied." << std::endl;
	a = right.a;
	b = right.b;
	c = right.c;
	d = right.d;
	return *this;
}

bool Rectangle::operator==(const Rectangle& right) {
	return(a == right.a && b == right.b);
}

Rectangle::~Rectangle(){
	//std::cout << "Rectangle has been deleted." << std::endl;
}

std::ostream& operator<<(std::ostream& os, Rectangle& obj) {
	os << "Figure: Rectangle.\nSides:" << std::endl;
	os << "a = c = " << obj.a << "\nb = d = " << obj.b << std::endl;
	//os << "Square: "<< obj.Square()  << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
	is >> obj.a;
	is >> obj.b;
	obj.c = obj.a;
	obj.d = obj.b;
	return is;
}