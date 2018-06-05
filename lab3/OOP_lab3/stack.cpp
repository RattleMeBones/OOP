#include "stack.h"

Stack::Stack() : head(nullptr) {}

/*Stack::Stack(const Stack& orig) {
	head = orig.head;
}*/

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
	std::shared_ptr<stack_item> item = stack.head;
	int i = 1;
	while(item != nullptr) {
		os << "(" << i << ")" << *item << std::endl;
		i++;
		item = item->Get_Next();
	}
	return os;
}

void Stack::push(std::shared_ptr<figure> &&figure) {
	std::shared_ptr<stack_item> other (new stack_item(figure));
	other->Set_Next(head);
	head = other;
}

bool Stack::empty() {
	return head == nullptr;
}

std::shared_ptr<figure> Stack::pop() {
	std::shared_ptr<figure> result = nullptr;
	if (head != nullptr) {
		result = head->Get_Figure();
		head = head->Get_Next();
	}
	return result;
}

Stack::~Stack() {
}