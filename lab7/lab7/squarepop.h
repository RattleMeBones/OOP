#ifndef SQUAREPOP_H
#define SQUAREPOP_H

#include "popcrit.h"

class SquarePop : public PopCrit {
public:
	SquarePop(double square) {
		this->square = square;
	}

	bool isIt(figure *fig) override {
		if(fig->Square() < square){
			return true;
		}else{
			return false;
		}
	}
private:
	double square;
};

#endif