#ifndef LQUEUE_H
#define LQUEUE_H

#include <iostream>
#include <memory>
#include <functional>
#include "figure.h"
#include "item.h"
#include "iterator.h"

template <class T> class LQueue {
public:
	LQueue();
	bool IsEmpty();
	int Size();
	void LPush(T *fig);
	void LPush(std::shared_ptr<T> fig);
	std::shared_ptr<T> LPop();
	Iterator<stack_item<T>, T> Begin();
	Iterator<stack_item<T>, T> End();
	template<class A> friend std::ostream& operator<<(std::ostream& os, LQueue<A> &s);
	~LQueue();

private:
	std::shared_ptr<stack_item<T>> begin;
	std::shared_ptr<stack_item<T>> tail;
	int size;
};

#endif