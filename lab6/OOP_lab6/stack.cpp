#include "stack.h"

template <class T> Stack<T>::Stack() : head(nullptr) {}

/*Stack::Stack(const Stack& orig) {
	head = orig.head;
}*/

template <class T> std::ostream& operator<<(std::ostream& os, Stack<T>& stack) {
	//std::shared_ptr<stack_item<T>> item = stack.head;
	int i = 1;
	for(std::shared_ptr<figure> it: stack) {
		stack_item<figure> tsi(it);
		os << "(" << i << ")" << tsi << std::endl;
		i++;
	}
	return os;
}

template <class T> void Stack<T>::push(std::shared_ptr<T> &&item) {
	std::shared_ptr<stack_item<T>> other (new stack_item<T>(item));
	other->Set_Next(head);
	head = other;
}

template <class T> bool Stack<T>::empty() {
	return head == nullptr;
}

template <class T> std::shared_ptr<T> Stack<T>::pop() {
	std::shared_ptr<T> result = nullptr;
	if (head != nullptr) {
		result = head->Get_Item();
		head = head->Get_Next();
	}
	return result;
}

template <class T> Iterator<stack_item<T>, T> Stack<T>::begin() {
	return Iterator<stack_item<T>, T>(head);
}

template <class T> Iterator<stack_item<T>, T> Stack<T>::end() {
	return Iterator<stack_item<T>, T>(nullptr);
}

template <class T> Stack<T>::~Stack() {
}

template class Stack<figure>;
template std::ostream& operator<<(std::ostream& os, Stack<figure>& stack);