#include "cont_queue.h"

template <class T> ContQueue<T>::ContQueue() {
	Begin = nullptr;
	back = nullptr;
	size = 0;
}

template <class T> bool ContQueue<T>::IsEmpty() {
	return Begin == nullptr;
}

template <class T> int ContQueue<T>::GetSize() {
	return size;
}

template <class T> void ContQueue<T>::CQPush(T *figure) {
	std::shared_ptr<CQItem<T>> item(new CQItem<T>(figure));
	if (Begin == nullptr){
		Begin = item;
		back = item;
	}else{
		if(item->GetFigure()->Square() <= Begin->GetFigure()->Square()){
			item->SetNext(Begin);
			Begin = item;
		}else{
			std::shared_ptr<CQItem<T>> tmp(Begin);
			while (tmp->GetNext() != nullptr && tmp->GetNext()->GetFigure()->Square() <= item->GetFigure()->Square()) {
				tmp = tmp->GetNext();
			}
			item->SetNext(tmp->GetNext());
			tmp->SetNext(item);
			if (back->GetNext() == item) {
				back = item;
			}
		}
	}
	size++;
}

template <class T> std::shared_ptr<T> ContQueue<T>::CQPop() {
	std::shared_ptr<T> figure(Begin->GetFigure());
	Begin = Begin->GetNext();
	size--;
	return figure;
}

template <class T> void ContQueue<T>::CQPop(int x) {
	int i = 0;
	std::shared_ptr<CQItem<T>> tmp = Begin;
	if (x == 0){
		Begin = Begin->GetNext();
	}else{
		while (tmp->GetNext() != nullptr && i != (x - 1)) {
			tmp = tmp->GetNext();
			i++;
		}
		if (i == (x - 1)){
			if (tmp->GetNext() == back){
				back = tmp;
			}else{
				tmp->SetNext(tmp->GetNext()->GetNext());
			}
		}
	}
	size--;
}

template <class T> std::ostream& operator<<(std::ostream& os, ContQueue<T> &s) {
	std::shared_ptr<CQItem<T>> item(s.Begin);
	while (item != nullptr) {
		(item->GetFigure())->Print();
		item = item->GetNext();
	}
	return os;
}

template <class T> Iterator<CQItem<T>, T> ContQueue<T>::begin() {
	return Iterator<CQItem<T>, T>(Begin);
}

template <class T> Iterator<CQItem<T>, T> ContQueue<T>::end() {
	return Iterator<CQItem<T>, T>(nullptr);
}

template <class T> ContQueue<T>::~ContQueue(){}

template class ContQueue<figure>;
template std::ostream& operator<<(std::ostream& os, ContQueue<figure> &s);