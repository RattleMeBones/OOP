#ifndef STACK_H
#define STACK_H
#include "rectangle.h"
#include "item.h"

class Stack {
public:
	Stack();
	Stack(const Stack& orig);

	void push(Rectangle* rectangle);
	bool empty();
	Rectangle* pop();
	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
	virtual ~Stack();

private:
	stack_item *head;
};

#endif

