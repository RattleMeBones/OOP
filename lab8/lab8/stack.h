#ifndef STACK_H
#define STACK_H
#include <thread>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "item.h"
#include "iterator.h"

template <class T> class Stack {
public:
	Stack();

	void push(std::shared_ptr<T> item);
	bool empty();
	std::shared_ptr<T> pop();
	template <class A> friend std::ostream& operator<<(std::ostream& os, Stack<A>& stack);
	virtual ~Stack();
	Iterator<stack_item<T>, T> begin();
	Iterator<stack_item<T>, T> end();
	void QuickSort();
	void ThrQuickSort();

private:
	std::shared_ptr<stack_item<T>> head;
};

#endif

