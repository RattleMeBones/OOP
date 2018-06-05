#include "mem_alloc.h"
#include <memory>
#include <iostream>

mem_block::mem_block(size_t Size, size_t Count) {
	size = Size;
	count = Count;
	free_count = count;
	active_blocks = (char *)malloc(size * count);
	for(size_t i = 0; i < count; i++){
		free_blocks.Q_Push_Back(active_blocks + i * size);
	}
}

void *mem_block::allocate(){
	std::cout << "Starting to allocate memory..." << std::endl;
	if(free_count > 0){
		free_count--;
		return free_blocks.Q_Pop();
	}else{
		return nullptr;
	}
}

void mem_block::deallocate(void *mem_ptr) {
	std::cout << "Starting to free memory..." << std::endl;
	free_blocks.Q_Push_Back(mem_ptr);
	free_count++;
	return;
}

bool mem_block::has_free_blocks(){
	return (free_count > 0);
}

mem_block::~mem_block(){
	free(active_blocks);
}