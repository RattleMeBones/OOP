#ifndef STACK_ITEM_H
#define STACK_ITEM_H
#include <cstdlib>
#include <iostream>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include <memory>


template <class T> class stack_item {
public:
	stack_item(const std::shared_ptr<T>& item);
	//stack_item(const stack_item& orig);
	template <class A> friend std::ostream& operator<<(std::ostream& os, const stack_item<A>& obj);

	std::shared_ptr<stack_item<T>> Set_Next(std::shared_ptr<stack_item<T>>& next);
	std::shared_ptr<stack_item<T>> Get_Next();
	std::shared_ptr<T> Get_Item() const;
	virtual ~stack_item();
private:
	std::shared_ptr<T> cur_item;
	std::shared_ptr<stack_item<T>> next;
};

#endif