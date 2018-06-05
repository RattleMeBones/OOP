#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

template <class Node, class T> class Iterator {
public:
	Iterator(std::shared_ptr<Node> node) {
		node_ptr = node;
	}
	std::shared_ptr<T> operator*() {
		return node_ptr->GetFigure();
	}
	std::shared_ptr<T> operator->() {
		return node_ptr->GetFigure()
	}
	Iterator& operator++() {
		node_ptr = node_ptr->GetNext();
		return *this;
	}
	bool operator!=(const Iterator& it) {
		return node_ptr != it.node_ptr;
	}

private:
	std::shared_ptr<Node> node_ptr;
};
#endif