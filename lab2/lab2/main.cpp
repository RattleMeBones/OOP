#include <cstdlib>
#include <iostream>
#include "item.h"
#include "rectangle.h"
#include "stack.h"

int main() {
	Stack s;
	Rectangle *t1, *t2, *t3;
	int a = 0;
	int b = 0;
	std::cout << "Enter the amount of figures you want to create: " << std::endl;
	std::cin >> a;
	std::cout << "Enter " << a << " rectangles." << std::endl;
	while (b != a) {
		s.push(new Rectangle(std::cin));
		b++;
	}
	std::cout << s;
	while (b != 0) {
		t1 = s.pop();
		b--;
		if (b == 0) {
			std::cout << "This is the last rectangle." << std::endl;
			std::cout << *t1;
			break;
		}
		t2 = s.pop();
		b--;
		t3 = t1;
		std::cout <<"[" << *t3 << "]\n";
		if (*t1 == *t2) {
			std::cout << "Next 2 figures are same:" << std::endl;
		}
		std::cout << *t1;
		std::cout << *t2;
	}
	system("pause");
	return 0;
}