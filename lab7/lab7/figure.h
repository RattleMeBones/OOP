#ifndef FIGURE_H
#define FIGURE_H

#include "mem_alloc.h"

enum MyFigs{RECTANGLE, TRAPEZE, RHOMBUS};

class figure{
	public:
		virtual double Square() = 0;
		virtual int FigType() = 0;
		virtual void Print() = 0;
		virtual ~figure() {};
};

#endif
