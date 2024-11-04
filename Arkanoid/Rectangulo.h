#pragma once
#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_
#include "Figura.h"

class Rectangulo : public Figura {
private:
	int ancho, alto;
public:
	Rectangulo() {
		x = 40;
		y = 300;
		vx = 10;
		ancho = 200;
		alto = 7;
	}
	~Rectangulo(){}
	void dibujar(Graphics^ g) {
		SolidBrush^ pintura = gcnew SolidBrush(Color::White);
		g->FillRectangle(pintura, x, y, ancho, alto); //pasamos el diametro para el ancho y alto
	}
	void mover(bool direccionMov, int maxFormX) { //direccionMov es la tecla que presionaremos: true si es derecha
		if (x + ancho < maxFormX && direccionMov) x += vx;
		if (x > 0 && !direccionMov) x -= vx;
	}
	int getTotalX() { return x + ancho; }
	void setY(int y) { this->y = y - 50; }
};

#endif // !_RECTANGULO_H_