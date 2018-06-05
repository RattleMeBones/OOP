#ifndef STACK_ITEM_H
#define STACK_ITEM_H
#include <cstdlib>
#include <iostream>
#include "rectangle.h"
#include "rhombus.h"
#include "trapeze.h"
#include <memory>


class stack_item {
public:
	stack_item(const std::shared_ptr<figure>& figure);
	//stack_item(const stack_item& orig);
	friend std::ostream& operator<<(std::ostream& os, const stack_item& obj);

	std::shared_ptr<stack_item> Set_Next(std::shared_ptr<stack_item>& next);
	std::shared_ptr<stack_item> Get_Next();
	std::shared_ptr<figure> Get_Figure() const;
	virtual ~stack_item();
private:
	std::shared_ptr<figure> cur_figure;
	std::shared_ptr<stack_item> next;
};

#endif