#pragma once
#ifndef _FIGURA_H_
#define _FIGURA_H_
#include <iostream>
#include <ctime>
using namespace System::Drawing;

class Figura {
protected:
	int x, y, vx;
public:
	Figura() {
		srand(NULL());
		x = 0;
		y = 0;
		vx = 0;
	}
	~Figura(){}
	//El abstract porque se va a trabajar en las clase hijas
	virtual void dibujar(Graphics^ g) abstract;
	int getX() { return x; }
	int getY() { return y; }
};

#endif // !_FIGURA_H_