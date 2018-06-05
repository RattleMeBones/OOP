#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream>
#include "figure.h"


class rhombus : public figure{
	public:
		rhombus();
		rhombus(std::istream &is);
		rhombus(double d_1, double d_2);
		rhombus(const rhombus& orig);
		
		double Square() override;
		void Print() override;
		
		virtual ~rhombus();
		
	private:
		double a;
		double b;
		double c;
		double d;
		double diag_1;
		double diag_2;
};

#endif
