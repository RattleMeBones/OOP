#ifndef FIGURE_H
#define FIGURE_H

#include "mem_alloc.h"

class figure{
	public:
		virtual double Square() = 0;
		virtual ~figure() {};
		virtual void Print() = 0;
};

#endif
