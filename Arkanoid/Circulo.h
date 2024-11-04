#pragma once
#ifndef _CIRCULO_H_
#include "Figura.h"

class Circulo : public Figura {
private:
	int vy, d;
	int R, G, B;//diametr = ancho, alto
public:
	Circulo() {
		srand(NULL());
		x = rand() % 200 + 1;
		y = 1;
		vx = 15; 
		vy = 15;
		d = 30;
		R = rand() % 256;
		G = rand() % 256;
		B = rand() % 256;
	}
	~Circulo(){}
	void dibujar(Graphics^ g) {
		SolidBrush^ pintura = gcnew SolidBrush(Color::FromArgb(R,G,B));
		g->FillEllipse(pintura, x, y, d, d); //pasamos el diametro para el ancho y alto
	}
	void mover(int maxFormX, int rectanguloY, int inicialBarraX, int finalBarraX) {
		x += vx;
		y += vy;
		if (x <= 0 || x + d >= maxFormX) {
			vx *= -1;
			cambiarColor();
		}
		if (y <= 0 || (y + d >= rectanguloY && x > inicialBarraX && x < finalBarraX)) {
			vy *= -1;
			cambiarColor();
		}
		if (y + d > rectanguloY) {
			x = rand() % 200 + 1; y = 1; cambiarColor();
		}
	}
	void cambiarColor() {
		R = rand() % 256;
		G = rand() % 256;
		B = rand() % 256;
	}
	int getD();
};

#endif // !_CIRCULO_H_