#include "stack.h"

Stack::Stack() : head(nullptr) {}

Stack::Stack(const Stack& orig) {
	head = orig.head;
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
	stack_item *item = stack.head;
	while (item != nullptr) {
		os << *(item -> Get_Rectangle());
		item = item->Get_Next();
	}
	return os;
}

void Stack::push(Rectangle* rectangle) {
	stack_item *other = new stack_item(rectangle);
	other->Set_Next(head);
	head = other;
}

bool Stack::empty() {
	return head == nullptr;
}

Rectangle* Stack::pop() {
	Rectangle *result = nullptr;
	if (head != nullptr) {
		stack_item *old_head = head;
		head = head->Get_Next();
		result = old_head->Get_Rectangle();
		old_head->Set_Next(nullptr);
		delete old_head;
	}
	return result;
}

Stack::~Stack() {
	delete head;
}