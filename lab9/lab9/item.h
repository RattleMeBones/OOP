#ifndef STACK_ITEM_H
#define STACK_ITEM_H
#include <cstdlib>
#include <iostream>
#include <functional>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include "figure.h"
#include <memory>


template <class T> class stack_item {
public:
	stack_item(T *fig);
	stack_item(std::shared_ptr<T> fig);
	void SetNext(std::shared_ptr<stack_item<T>> item);
	std::shared_ptr<stack_item<T>> GetNext();
	std::shared_ptr<T> GetFigure();
private:
	std::shared_ptr<T> CurItem;
	std::shared_ptr<stack_item<T>> Next;
};

#endif