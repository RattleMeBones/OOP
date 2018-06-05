#include "item.h"
#include <iostream>

stack_item::stack_item(Rectangle* rectangle) {
	ptr_rectangle = rectangle;
	this->next = nullptr;
	//std::cout << "Stack item has been created." << std::endl;
}

stack_item::stack_item(const stack_item& orig) {
	ptr_rectangle = orig.ptr_rectangle;
	next = orig.next;
	//std::cout << "Stack item copy has been created." << std::endl;
}

stack_item* stack_item::Set_Next(stack_item* next) {
	stack_item* old = this->next;
	this->next = next;
	return old;
}

Rectangle* stack_item::Get_Rectangle() const {
	return ptr_rectangle;
}

stack_item* stack_item::Get_Next() {
	return this->next;
}

stack_item::~stack_item() {
	//std::cout << "Stack item has been deleted." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const stack_item& obj) {
	os << "[" << obj.ptr_rectangle << "]" << std::endl;
	return os;
}