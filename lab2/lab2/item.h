#ifndef STACK_ITEM_H
#define STACK_ITEM_H
#include <cstdlib>
#include <iostream>
#include "rectangle.h"

class stack_item {
public:
	stack_item(Rectangle* rectangle);
	stack_item(const stack_item& orig);
	friend std::ostream& operator<<(std::ostream& os, const stack_item& obj);

	stack_item* Set_Next(stack_item* next);
	stack_item* Get_Next();
	Rectangle* Get_Rectangle() const;
	virtual ~stack_item();
private:
	Rectangle* ptr_rectangle;
	stack_item *next;
};

#endif