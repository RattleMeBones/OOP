#include <cstdlib>
#include <memory>
#include <iostream>
#include "item.h"
#include "rectangle.h"
#include "trapeze.h"
#include "rhombus.h"
#include "stack.h"
#include "lqueue.h"
#include "iterator.h"
#include <functional>
#include <random>

typedef std::function<void(void)> command;

int main() {
	Stack<figure> S;
	LQueue<command> LQ;
	std::default_random_engine gn;
	std::mt19937 mt(gn());

	command LPrint = [&S]() {
		std::cout << "Lambda Func Print:\n" << S;
	};
	command LGenerate = [&]() {
		std::cout << "Generating..." << std::endl;
		std::uniform_real_distribution<double> dis(1, 100);
		switch (int(dis(mt)) % 3) {
		case 0:
			S.SPush(new Rectangle(dis(mt), dis(mt)));
			break;
		case 1:
			S.SPush(new Rhombus(dis(mt), dis(mt)));
			break;
		case 2:
			S.SPush(new Trapeze(dis(mt), dis(mt), dis(mt)));
			break;
		}
	};
	command LRemove = [&]() {
		std::cout << "Removing..." << std::endl;
		Stack<figure> tmp;
		double sqr = 0;
		while (!S.IsEmpty()) {
			std::shared_ptr<figure> item = S.SPop();
			if (item->Square() > sqr) {
				sqr = item->Square();
			}
			tmp.SPush(item);
		}
		std::uniform_real_distribution<double> distr(0, sqr);
		sqr = distr(mt);
		std::cout << "Lamba remove figures by square: " << sqr << std::endl;
		while (!tmp.IsEmpty()) {
			std::shared_ptr<figure> item = tmp.SPop();
			if (item->Square() > sqr) {
				S.SPush(item);
			}
		}
	};
	LQ.LPush(std::shared_ptr<command>(&LGenerate, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LGenerate, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LGenerate, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LGenerate, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LGenerate, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LPrint, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LRemove, [](command*) {}));
	LQ.LPush(std::shared_ptr<command>(&LPrint, [](command*) {}));
	while (!LQ.IsEmpty()) {
		std::shared_ptr<command> cmd = LQ.LPop();
		(*cmd)();
		std::cout << '\n';
	}
	system("pause");
}