#include <cstdlib>
#include <iostream>
#include "item.h"
#include "rectangle.h"
#include "trapeze.h"
#include "rhombus.h"
#include "stack.h"

int main() {
	Stack<figure> S;
	while (1) {
		int input_1;
		std::cout << "Enter 1 to add a figure.\nEnter 2 to delete a figure.\nEnter 3 to print stack.\nEnter 4 to sort the stack\nEnter 0 to close the programm." << std::endl;
		std::cin >> input_1;
		if (input_1 == 1) {
			int input_2;
			std::cout << "Enter 1 to add a rectangle.\nEnter 2 to add a rhombus.\nEnter 3 to add a trapeze." << std::endl;
			std::cin >> input_2;
			if (input_2 == 1) {
				std::cout << "Enter 2 sides of a rectangle: " << std::endl;
				S.push(std::shared_ptr<figure>(new Rectangle(std::cin)));
			}
			if (input_2 == 2) {
				std::cout << "Enter 2 diagonals of a rhombus: " << std::endl;
				S.push(std::shared_ptr<figure>(new Rhombus(std::cin)));
			}
			if (input_2 == 3) {
				std::cout << "Enter a height and 2 bases of trapeze: " << std::endl;
				S.push(std::shared_ptr<figure>(new Trapeze(std::cin)));
			}
		}else if (input_1 == 2) {
			S.pop();
		}else if (input_1 == 3) {
			std::cout << S;
		}else if (input_1 == 4) {
			int input_3;
			std::cout << "Enter 1 if you want to do a regular quicksort or 2 if you want to do a multithreaded quicksort: ";
			std::cin >> input_3;
			if (input_3 == 1) {
				S.QuickSort();
			}else if (input_3 == 2) {
				S.ThrQuickSort();
			}else {
				std::cout << "Wrong command." << std::endl;
			}
		}else if(input_1 == 0){
			return 0;
		}
	}
}