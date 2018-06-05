#include "item.h"
#include <iostream>

template <class T> stack_item<T>::stack_item(const std::shared_ptr<T>& item) {
	this->cur_item = item;
	std::cout << "Stack item has been created." << std::endl;
}

template <class T> std::shared_ptr<stack_item<T>> stack_item<T>::Set_Next(std::shared_ptr<stack_item<T>>& next) {
	std::shared_ptr<stack_item<T>> old = this->next;
	this->next = next;
	return old;
}

template <class T> std::shared_ptr<T> stack_item<T>::Get_Item() const {
	return this->cur_item;
}

template <class T> std::shared_ptr<stack_item<T>> stack_item<T>::Get_Next() {
	return this->next;
}

template <class T> stack_item<T>::~stack_item() {
}

template <class T> std::ostream& operator<<(std::ostream& os, const stack_item<T>& obj) {
	if (std::shared_ptr<Rectangle> rectangle = std::dynamic_pointer_cast<Rectangle>(obj.Get_Item())) {
		os << *rectangle;
	}else if(std::shared_ptr<Rhombus> rhombus = std::dynamic_pointer_cast<Rhombus>(obj.Get_Item())){
		os << *rhombus;
	}else if (std::shared_ptr<Trapeze> trapeze = std::dynamic_pointer_cast<Trapeze>(obj.Get_Item())) {
		os << *trapeze;
	}
	return os;
}

template class stack_item<figure>;
template std::ostream& operator<<(std::ostream& os, const stack_item<figure>& obj);