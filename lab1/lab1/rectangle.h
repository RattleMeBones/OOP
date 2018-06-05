#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class rectangle : public figure{
	public:
		rectangle();
		rectangle(std::istream &is);
		rectangle(double i, double j);
		rectangle(const rectangle& orig);
		
		double Square() override;
		void Print() override;
		
		virtual ~rectangle();
		
	private:
		double a;
		double b;
		double c;
		double d;
};

#endif
