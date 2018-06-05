#include "item.h"
#include <iostream>

stack_item::stack_item(const std::shared_ptr<figure>& figure) {
	this->cur_figure = figure;
	std::cout << "Stack item has been created." << std::endl;
}

/*stack_item::stack_item(const stack_item& orig) {
	ptr_rectangle = orig.ptr_rectangle;
	next = orig.next;
	//std::cout << "Stack item copy has been created." << std::endl;
}*/

std::shared_ptr<stack_item> stack_item::Set_Next(std::shared_ptr<stack_item>& next) {
	std::shared_ptr<stack_item> old = this->next;
	this->next = next;
	return old;
}

std::shared_ptr<figure> stack_item::Get_Figure() const {
	return this->cur_figure;
}

std::shared_ptr<stack_item> stack_item::Get_Next() {
	return this->next;
}

stack_item::~stack_item() {
	//std::cout << "Stack item has been deleted." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const stack_item& obj) {
	if (std::shared_ptr<Rectangle> rectangle = std::dynamic_pointer_cast<Rectangle>(obj.Get_Figure())) {
		os << *rectangle;
	}else if(std::shared_ptr<Rhombus> rhombus = std::dynamic_pointer_cast<Rhombus>(obj.Get_Figure())){
		os << *rhombus;
	}else if (std::shared_ptr<Trapeze> trapeze = std::dynamic_pointer_cast<Trapeze>(obj.Get_Figure())) {
		os << *trapeze;
	}
	return os;
}