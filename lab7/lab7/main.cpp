#include <cstdlib>
#include <iostream>
#include "item.h"
#include "rectangle.h"
#include "trapeze.h"
#include "rhombus.h"
#include "stack.h"
#include "cont_queue.h"
#include "iterator.h"
#include "popcrit.h"
#include "squarepop.h"
#include "typepop.h"

void Description() {
	std::cout << "Enter 0 to exit the program." << std::endl;
	std::cout << "Enter 1 to see the descriprion." << std::endl;
	std::cout << "Enter 2 to create a new queue." << std::endl;
	std::cout << "Enter 3 to add a figure to a queue." << std::endl;
	std::cout << "Enter 4 to delete a figure from a queue." << std::endl;
	std::cout << "Enter 5 to print the queue." << std::endl;
	std::cout << "Enter 6 to add a queue to stack." << std::endl;
	std::cout << "Enter 7 to add a figure to stack." << std::endl;
	std::cout << "Enter 8 to delete all figures of a certain type." << std::endl;
	std::cout << "Enter 9 to delete all figures of certain square." << std::endl;
	std::cout << "Enter 10 to print the stack." << std::endl;
}

int main() {
	Stack<ContQueue<figure>, figure> S;
	ContQueue<figure> *cq = nullptr;
	PopCrit *crit;
	Description();
	while (1) {
		int input_1;
		std::cout << "Enter a number a of command: ";
		std::cin >> input_1;
		switch (input_1) {
		case 1:
			Description();
			break;
		case 2:
			if (cq != nullptr) {
				delete cq;
			}
			cq = new ContQueue<figure>;
			break;
		case 3:
			int input_2;
			std::cout << "Enter 1 to add a rectangle.\nEnter 2 to add a rhombus.\nEnter 3 to add a trapeze." << std::endl;
			std::cin >> input_2;
			if (input_2 == 1) {
				std::cout << "Enter 2 sides of a rectangle: " << std::endl;
				cq->CQPush(new Rectangle(std::cin));
			}
			if (input_2 == 2) {
				std::cout << "Enter 2 diagonals of a rhombus: " << std::endl;
				cq->CQPush(new Rhombus(std::cin));
			}
			if (input_2 == 3) {
				std::cout << "Enter a height and 2 bases of trapeze: " << std::endl;
				cq->CQPush(new Trapeze(std::cin));
			}
			break;
		case 4:
			if (!(cq->IsEmpty())) {
				cq->CQPop();
			}else{
				std::cout << "Queue is empty." << std::endl;
			}
			break;
		case 5:
			std::cout << *cq;
			break;
		case 6:
			if (cq != nullptr) {
				S.SPush(cq);
				cq = nullptr;
			}
			break;
		case 7:
			std::cout << "Enter 1 to add a rectangle.\nEnter 2 to add a rhombus.\nEnter 3 to add a trapeze." << std::endl;
			std::cin >> input_2;
			if (input_2 == 1) {
				std::cout << "Enter 2 sides of a rectangle: " << std::endl;
				S.SSubPush(new Rectangle(std::cin));
			}
			if (input_2 == 2) {
				std::cout << "Enter 2 diagonals of a rhombus: " << std::endl;
				S.SSubPush(new Rhombus(std::cin));
			}
			if (input_2 == 3) {
				std::cout << "Enter a height and 2 bases of trapeze: " << std::endl;
				S.SSubPush(new Trapeze(std::cin));
			}
			break;
		case 8:
			std::cout << "Enter 1 to delete all rectangles.\nEnter 2 to delete all rhombuses.\nEnter 3 to delete all trapezes." << std::endl;
			int input_3;
			std::cin >> input_3;
			switch (input_3) {
			case 1:
				crit = new TypePop(RECTANGLE);
				S.SPopCrit(crit);
				delete crit;
				break;
			case 2:
				crit = new TypePop(RHOMBUS);
				S.SPopCrit(crit);
				delete crit;
				break;
			case 3:
				crit = new TypePop(TRAPEZE);
				S.SPopCrit(crit);
				delete crit;
				break;
			}
			break;
		case 9:
			std::cout << "Enter a square of figures you want to delete: ";
			double delSquare;
			std::cin >> delSquare;
			crit = new SquarePop(delSquare);
			S.SPopCrit(crit);
			delete crit;
			break;
		case 10:
			std::cout << S;
			break;
		case 0:
			return 0;
		}
	}
}