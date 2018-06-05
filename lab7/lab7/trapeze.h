#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"


class Trapeze : public figure{
	public:
		Trapeze();
		Trapeze(std::istream &is);
		Trapeze(double i, double j, double h);
		//trapeze(const trapeze& orig);
		void Print() override;
		Trapeze& operator=(const Trapeze& right);
		bool Trapeze::operator==(const Trapeze& right);
		int FigType();
		friend std::ostream& operator<<(std::ostream& os, Trapeze& obj);
		friend std::istream& operator>>(std::istream& is, Trapeze& obj);
		void *operator new(size_t size);
		void operator delete(void *mem_pointer);

		double Square() override;
		
		virtual ~Trapeze();
		
	private:
		double a;
		double b;
		double c;
		double d;
		double height;
		static mem_block alloc;
};

#endif
