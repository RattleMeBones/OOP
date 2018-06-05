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
		void Print() override;
		double Square();
		friend std::ostream& operator<<(std::ostream& os, Rectangle& obj);
		friend std::istream& operator>>(std::istream& is, Rectangle& obj);
		int FigType();
		Rectangle& operator=(const Rectangle& right);
		bool Rectangle::operator==(const Rectangle& right);
		void *operator new(size_t size);
		void operator delete(void *mem_pointer);

		virtual ~Rectangle();
		
	private:
		double a;
		double b;
		double c;
		double d;
		static mem_block alloc;
};

#endif
