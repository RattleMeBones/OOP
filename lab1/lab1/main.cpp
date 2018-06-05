#include <cstdlib>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "figure.h"

int main(int argc, char** argv){
	std::cout << "Enter the sides of a rectangle: " << std::endl;
	figure *ptr_rec = new rectangle(std::cin);
	std::cout << "Enter the sides of a trapeze: " << std::endl;
	figure *ptr_trpz = new trapeze(std::cin);
	std::cout << "Enter the sides of a rhombus: " << std::endl;
	figure *ptr_rhmb = new rhombus(std::cin);
	std::cout << "Rectangle: " << std::endl; 
	ptr_rec -> Print(); 
	std::cout << "Square = " << ptr_rec -> Square() << std::endl;
	std::cout << "Trapeze: "  << std::endl;
	ptr_trpz -> Print();
	std::cout << "Square = " << ptr_trpz -> Square() << std::endl;
	std::cout << "Rhombus: " << std::endl;
	ptr_rhmb -> Print();
	std::cout << "Square = " <<  ptr_rhmb -> Square() << std::endl;
	delete ptr_rec;
	delete ptr_trpz;
	delete ptr_rhmb;
	system("pause");
	return 0;
}
