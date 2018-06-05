#include "stack.h"

template <class T> Stack<T>::Stack() {
	head = nullptr;
}

template <class T> bool Stack<T>::IsEmpty() {
	return head == nullptr;
}

template <class T> void Stack<T>::SPush(T *fig) {
	std::shared_ptr<stack_item<T>> item(new stack_item<T>(fig));
	item->SetNext(head);
	head = item;
}

template <class T> void Stack<T>::SPush(std::shared_ptr<T> fig) {
	std::shared_ptr<stack_item<T>> item(new stack_item<T>(fig));
	item->SetNext(head);
	head = item;
}

template <class T> std::shared_ptr<T> Stack<T>::SPop() {
	std::shared_ptr<T> item(head->GetFigure());
	head = head->GetNext();
	return item;
}

template <class T> std::ostream& operator<<(std::ostream& os, Stack<T> &S) {
	std::shared_ptr<stack_item<T>> item(S.head);
	while (item != nullptr) {
		(item->GetFigure())->Print();
		item = item->GetNext();
	}
	return os;
}

template <class T> Iterator<stack_item<T>, T> Stack<T>::begin() {
	return Iterator<stack_item<T>, T>(head);
}

template <class T> Iterator<stack_item<T>, T> Stack<T>::end() {
	return Iterator<stack_item<T>, T>(nullptr);
}

template <class T> Stack<T>::~Stack(){}

template class Stack<figure>;
template std::ostream& operator<<(std::ostream& os, Stack<figure> &S);