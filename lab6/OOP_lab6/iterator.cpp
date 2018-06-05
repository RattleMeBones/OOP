#include "iterator.h"
#include "item.h"
#include "figure.h"

template <class node, class T> Iterator<node, T>::Iterator(std::shared_ptr<node> n) {
	node_ptr = n;
}

template <class node, class T> std::shared_ptr<T> Iterator<node, T>::operator*() {
	return node_ptr->Get_Item();
}

template <class node, class T> std::shared_ptr<T> Iterator<node, T>::operator->() {
	return node_ptr->Get_Item();
}

template <class node, class T> Iterator<node, T> Iterator<node, T>::operator++(int) {
	Iterator iter(*this);
	++(*this);
	return iter;
}

template <class node, class T> void Iterator<node, T>::operator++() {
	node_ptr = node_ptr->Get_Next();
}

template <class node, class T> bool Iterator<node, T>::operator==(Iterator const& it){
	return node_ptr == it.node_ptr;
}

template <class node, class T> bool Iterator<node, T>::operator!=(Iterator const& it) {
	return node_ptr != it.node_ptr;
}

template class Iterator<stack_item<figure>, figure>;