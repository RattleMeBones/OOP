#ifndef STACK_H
#define STACK_H
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "item.h"

class Stack {
public:
	Stack();
	//Stack(const Stack& orig);

	void push(std::shared_ptr<figure> &&figure);
	bool empty();
	std::shared_ptr<figure> pop();
	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
	virtual ~Stack();

private:
	std::shared_ptr<stack_item> head;
};

#endif

