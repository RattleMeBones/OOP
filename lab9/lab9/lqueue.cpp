#include "lqueue.h"

template <class T> LQueue<T>::LQueue() {
	begin = nullptr;
	tail = nullptr;
	size = 0;
}

template <class T> bool LQueue<T>::IsEmpty() {
	return begin == 0;
}

template <class T> int LQueue<T>::Size() {
	return size;
}

template <class T> void LQueue<T>::LPush(T *fig) {
	std::shared_ptr<stack_item<T>> item(new stack_item<T>(fig));
	if (begin == nullptr) {
		begin = item;
		tail = item;
	}else{
		tail->SetNext(item);
		tail = tail->GetNext();
	}
	size++;
}

template <class T> void LQueue<T>::LPush(std::shared_ptr<T> fig) {
	std::shared_ptr<stack_item<T>> item(new stack_item<T>(fig));
	if (begin == nullptr) {
		begin = item;
		tail = item;
	}else{
		tail->SetNext(item);
		tail = tail->GetNext();
	}
	size++;
}

template <class T> std::shared_ptr<T> LQueue<T>::LPop() {
	std::shared_ptr<T> item(begin->GetFigure());
	begin = begin->GetNext();
	size--;
	return item;
}

template <class T> std::ostream& operator<<(std::ostream& os, LQueue<T> &s) {
	std::shared_ptr<stack_item<T>> item(s.begin);
	while (item != nullptr) {
		(item->GetFigure())->Print();
		item = item->GetNext();
	}
	return os;
}

template <class T> Iterator<stack_item<T>, T> LQueue<T>::Begin() {
	return Iterator<stack_item<T>, T>(begin);
}

template <class T> Iterator<stack_item<T>, T> LQueue<T>::End() {
	return Iterator<stack_item<T>, T>(nullptr);
}

template <class T> LQueue<T>::~LQueue() {

}

template class LQueue<figure>;
template class LQueue<std::function<void(void)>>;
template std::ostream& operator<<(std::ostream& os, LQueue<figure> &s);