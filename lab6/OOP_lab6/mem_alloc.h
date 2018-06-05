#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <iostream>
#include <cstdlib>
#include "queue.h"

class mem_block {
public:
	mem_block(size_t size, size_t count);
	void* allocate();
	void deallocate(void* pointer);
	bool has_free_blocks();

	~mem_block();

private:
	size_t size;
	size_t count;
	size_t free_count;
	char *active_blocks;
	queue<void *> free_blocks;
};
#endif