#include "stack.h"

template <class T> Stack<T>::Stack() : head(nullptr) {}

/*Stack::Stack(const Stack& orig) {
	head = orig.head;
}*/

template <class T> std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
	std::shared_ptr<stack_item<T>> item = stack.head;
	int i = 1;
	while(item != nullptr) {
		os << "(" << i << ")" << *item << std::endl;
		i++;
		item = item->Get_Next();
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

template <class T> Stack<T>::~Stack() {
}

template class Stack<figure>;
template std::ostream& operator<<(std::ostream& os, const Stack<figure>& stack);