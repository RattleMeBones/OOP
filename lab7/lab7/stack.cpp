#include "stack.h"

template <class T, class TSItem> Stack<T, TSItem>::Stack() : head(nullptr) {}

template <class T, class TSItem> void Stack<T, TSItem>::SPush(T *item) {
	std::shared_ptr<stack_item<T>> elem(new stack_item<T>(item));
	elem->SetNext(head);
	head = elem;
}

template <class T, class TSItem> void Stack<T, TSItem>::SSubPush(TSItem *item) {
	bool pushed = false;
	if(head != nullptr){
		for(auto i : *this){
			if(i->GetSize() < 5){
				i->CQPush(item);
				pushed = true;
				break;
			}
		}
	}
	if(pushed == false){
		std::shared_ptr<stack_item<T>> elem(new stack_item<T>(new T));
		elem->GetFigure()->CQPush(item);
		elem->SetNext(head);
		head = elem;
	}
}

template <class T, class TSItem> void Stack<T, TSItem>::SPopCrit(PopCrit *crit) {
	for(auto queue : *this){
		int k = 0;
		for(auto i : *queue){
			if(crit->isIt(&(*i))){
				queue->CQPop(k);
				k--;
			}
			k++;
		}
	}
}

template <class T, class TSItem> std::ostream& operator<<(std::ostream& os, Stack<T, TSItem> &S) {
	int n = 1;
	for(auto i : S){
		os << "Item in " << n++ << '\n';
		os << *i;
	}
	return os;
}

template <class T, class TSItem> Iterator<stack_item<T>, T> Stack<T, TSItem>::begin() {
	return Iterator<stack_item<T>, T>(head);
}

template <class T, class TSItem> Iterator<stack_item<T>, T> Stack<T, TSItem>::end() {
	return Iterator<stack_item<T>, T>(nullptr);
}

template <class T, class TSItem> bool Stack<T, TSItem>::SIsEmpty() {
	return head == nullptr;
}

template <class T, class TSItem> Stack<T, TSItem>::~Stack() {}

template class Stack<ContQueue<figure>, figure>;
template std::ostream& operator<<(std::ostream& os, Stack<ContQueue<figure>, figure> &S);