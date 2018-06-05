#include "stack.h"

template <class T> Stack<T>::Stack() : head(nullptr) {}

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

template <class T> void Stack<T>::push(std::shared_ptr<T> item) {
	std::shared_ptr<stack_item<T>> other(new stack_item<T>(item));
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

template <class T> void Stack<T>::QuickSort() {
	if (this->empty()) {
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	std::shared_ptr<T> middle = pop();
	Stack<T> less, more;
	while (!this->empty()) {
		std::shared_ptr<T> item = this->pop();
		if (item->Square() < middle->Square()) {
			less.push(item);
		}else{
			more.push(item);
		}
	}

	less.QuickSort();
	more.QuickSort();

	Stack<T> temp;
	while (!less.empty()) {
		temp.push(less.pop());
	}
	while (!temp.empty()) {
		this->push(temp.pop());
	}
	this->push(middle);
	while (!more.empty()) {
		temp.push(more.pop());
	}
	while (!temp.empty()) {
		this->push(temp.pop());
	}
}

template <class T> void Stack<T>::ThrQuickSort() {
	if (this->empty()) {
		std::cout << "Stack is empty!" << std::endl;
		return;
	}
	std::shared_ptr<T> middle = pop();
	Stack<T> less, more;
	while (!this->empty()) {
		std::shared_ptr<T> item = this->pop();
		if (item->Square() < middle->Square()) {
			less.push(item);
		}else{
			more.push(item);
		}
	}

	std::thread less_thread(&Stack<T>::ThrQuickSort, &less);
	std::thread more_thread(&Stack<T>::ThrQuickSort, &more);
	less_thread.join();
	more_thread.join();

	Stack<T> temp;
	while (!less.empty()) {
		temp.push(less.pop());
	}
	while (!temp.empty()) {
		this->push(temp.pop());
	}
	this->push(middle);
	while (!more.empty()) {
		temp.push(more.pop());
	}
	while (!temp.empty()) {
		this->push(temp.pop());
	}
}

template class Stack<figure>;
template std::ostream& operator<<(std::ostream& os, Stack<figure>& stack);