#ifndef TYPEPOP_H
#define TYPEPOP_H

#include "popcrit.h"

class TypePop : public PopCrit {
public:
	TypePop(int type) {
		this->type = type;
	}
	bool isIt(figure *fig) override {
		if(fig->FigType() == type){
			return true;
		}else{
			return false;
		}
	}

private:
	int type;
};

#endif