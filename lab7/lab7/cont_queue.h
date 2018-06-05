#ifndef CONT_QUEUE
#define CONT_QUEUE
#include <iostream>
#include <memory>
#include "figure.h"
#include "CQItem.h"
#include "iterator.h"

template <class T> class ContQueue {
public:
	ContQueue();
	bool IsEmpty();
	int GetSize();
	void CQPush(T *figure);
	std::shared_ptr<T> CQPop();
	void CQPop(int x);
	Iterator<CQItem<T>, T> begin();
	Iterator<CQItem<T>, T> end();
	template <class A> friend std::ostream& operator<<(std::ostream& os, ContQueue <A> &S);
	~ContQueue();
private:
	std::shared_ptr<CQItem<T>> Begin;
	std::shared_ptr<CQItem<T>> back;
	int size;
};
#endif