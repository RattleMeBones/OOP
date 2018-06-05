#ifndef POPCRIT_H
#define POPCRIT_H

#include "figure.h"

class PopCrit {
public:
	virtual bool isIt(figure *fig) = 0;
};

#endif