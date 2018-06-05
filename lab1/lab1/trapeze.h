#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"


class trapeze : public figure{
	public:
		trapeze();
		trapeze(std::istream &is);
		trapeze(double i, double j, double h);
		trapeze(const trapeze& orig);
		
		double Square() override;
		void Print() override;
		
		virtual ~trapeze();
		
	private:
		double a;
		double b;
		double height;
		double c;
		double d;
};

#endif
