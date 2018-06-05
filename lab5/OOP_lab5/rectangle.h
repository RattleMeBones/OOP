#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"
#include <cstdlib>
#include <iostream>

class Rectangle : public figure{
	public:
		Rectangle();
		Rectangle(std::istream &is);
		Rectangle(double i, double j);
		//Rectangle(const Rectangle& orig);

		double Square();
		friend std::ostream& operator<<(std::ostream& os, Rectangle& obj);
		friend std::istream& operator>>(std::istream& is, Rectangle& obj);
		Rectangle& operator=(const Rectangle& right);
		bool Rectangle::operator==(const Rectangle& right);

		virtual ~Rectangle();
		
	private:
		double a;
		double b;
		double c;
		double d;
};

#endif
