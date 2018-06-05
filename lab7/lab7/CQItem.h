#ifndef CQITEM_H
#define CQITEM_H
#include <memory>
#include "figure.h"

template <class T> class CQItem {
public:
	CQItem(T *fig);
	void SetNext(std::shared_ptr<CQItem<T>> item);
	std::shared_ptr<CQItem<T>> GetNext();
	std::shared_ptr<T> GetFigure();

private:
	std::shared_ptr<T> value;
	std::shared_ptr<CQItem<T>> next;
};

#endif