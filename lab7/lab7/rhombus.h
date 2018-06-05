#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream>
#include "figure.h"


class Rhombus : public figure{
	public:
		Rhombus();
		Rhombus(std::istream &is);
		Rhombus(double d_1, double d_2);
		//rhombus(const rhombus& orig);
		
		double Square() override;
		void Print() override;
		Rhombus& operator=(const Rhombus& right);
		bool Rhombus::operator==(const Rhombus& right);
		int FigType();
		friend std::ostream& operator<<(std::ostream& os, Rhombus& obj);
		friend std::istream& operator>>(std::istream& is, Rhombus& obj);
		void *operator new(size_t size);
		void operator delete(void *mem_pointer);
		
		virtual ~Rhombus();
		
	private:
		double a;
		double b;
		double c;
		double d;
		double diag_1;
		double diag_2;
		static mem_block alloc;
};

#endif
