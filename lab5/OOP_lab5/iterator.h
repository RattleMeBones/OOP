#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>

template <class node, class T> class Iterator {
public:
	Iterator(std::shared_ptr<node> n);
	std::shared_ptr<T> operator*();
	std::shared_ptr<T> operator->();
	void operator++();
	Iterator operator++(int);
	bool operator==(Iterator const& it);
	bool operator!=(Iterator const& it);

private:
	std::shared_ptr<node> node_ptr;
};
#endif