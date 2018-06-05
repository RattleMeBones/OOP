#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <memory>
#include "figure.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "item.h"
#include "iterator.h"
#include "popcrit.h"
#include "cont_queue.h"

template <class T, class TSItem> class Stack {
public:
	Stack();
	
	void SPush(T *item);
	void SSubPush(TSItem *item);
	void SPopCrit(PopCrit *crit);
	bool SIsEmpty();
	Iterator<stack_item<T>, T> begin();
	Iterator<stack_item<T>, T> end();

	template <class A, class B> friend std::ostream& operator<<(std::ostream& os, Stack<A, B> &S);

	~Stack();
private:
	std::shared_ptr<stack_item<T>> head;
};

#endif

