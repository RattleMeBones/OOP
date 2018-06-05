#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <iostream>
#include "iterator.h"

template <class T> class q_item {
public:
	q_item(T &val) {
		value = val;
		next = nullptr;
	}

	T Get_Figure() {
		return value;
	}
	void Set_Next(std::shared_ptr<q_item<T>> item) {
		next = item;
	}
	std::shared_ptr<q_item<T>> Get_Next() {
		return next;
	}

private:
	T value;
	std::shared_ptr<q_item<T>> next;
};

template <class T> class queue {
public:
	queue(){
		begin = nullptr;
		back = nullptr;
	}
	bool Is_Empty() {
		return begin == nullptr;
	}
	void Q_Push_Back(T figure) {
		std::shared_ptr<q_item<T>> item(new q_item<T>(figure));
		if(begin == nullptr){
			begin = item;
			back = item;
		}else{
			item->Set_Next(nullptr);
			back->Set_Next(item);
			back = item;
		}
	}
	T Q_Pop(){
		if (begin != nullptr) {
			T val = begin->Get_Figure();
			if (begin == back) {
				begin = nullptr;
				back = nullptr;
			}else{
				begin = begin->Get_Next();
			}
			return val;
		}else{
			return nullptr;
		}
	}

	Iterator<q_item<T>, T> Begin() {
		return begin;
	}
	Iterator<q_item<T>, T> Back() {
		return back;
	}

private:
	std::shared_ptr<q_item<T>> begin;
	std::shared_ptr<q_item<T>> back;
};

#endif