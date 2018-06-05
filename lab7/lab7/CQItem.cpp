#include "CQItem.h"

template <class T> CQItem<T>::CQItem(T *fig) : value(fig), next(nullptr) {}

template <class T> void CQItem<T>::SetNext(std::shared_ptr<CQItem<T>> item) {
	next = item;
}

template <class T> std::shared_ptr<CQItem<T>> CQItem<T>::GetNext() {
	return next;
}

template <class T> std::shared_ptr<T> CQItem<T>::GetFigure() {
	return value;
}

template class CQItem<figure>;