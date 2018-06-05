#include "item.h"
#include <iostream>

template <class T> stack_item<T>::stack_item(T *fig) : CurItem(fig), Next(nullptr) {}

template <class T> stack_item<T>::stack_item(std::shared_ptr<T> fig) : CurItem(fig), Next(nullptr) {}
	
template <class T> void stack_item<T>::SetNext(std::shared_ptr<stack_item<T>> item) {
	Next = item;
}

template <class T> std::shared_ptr<stack_item<T>> stack_item<T>::GetNext(){
	return  Next;
}

template <class T> std::shared_ptr<T> stack_item<T>::GetFigure() {
	return CurItem;
}

template class stack_item<figure>;
template class stack_item<std::function<void(void)>>;