#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <memory>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "item.h"
#include "iterator.h"

template <class T> class Stack {
public:
	Stack();
	bool IsEmpty();
	void SPush(T *fig);
	void SPush(std::shared_ptr<T> fig);
	std::shared_ptr<T> SPop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, Stack<A> &S);
	Iterator<stack_item<T>, T> begin();
	Iterator<stack_item<T>, T> end();
	~Stack();
private:
	std::shared_ptr<stack_item<T>> head;
};

#endif

