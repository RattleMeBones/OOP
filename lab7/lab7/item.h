#ifndef STACK_ITEM_H
#define STACK_ITEM_H

#include <memory>


template <class T> class stack_item {
public:
	stack_item(T *fig): cur_item(fig), next(nullptr){}
	void SetNext(std::shared_ptr<stack_item<T>> item) {
		next = item;
	}
	std::shared_ptr<stack_item<T>> GetNext() {
		return next;
	}
	std::shared_ptr<T> GetFigure() {
		return cur_item;
	}

private:
	std::shared_ptr<T> cur_item;
	std::shared_ptr<stack_item<T>> next;
};

#endif