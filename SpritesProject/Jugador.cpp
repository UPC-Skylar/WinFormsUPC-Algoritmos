#include "Jugador.h"


Jugador::Jugador(){
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
	ultimaTecla = Direcciones::Abajo;
	direccion = Direcciones::Ninguna;
	ancho = 25;
	alto = 39;
	indiceX = 0;
	indiceY = 0;
}
Jugador::Jugador(int x, int y){
	this->x = x;
	this->y = y;
	vx = 0; //Esto es porq estara dentro de un timer y no debe moverse x defecto
	vy = 0;
	ultimaTecla = Direcciones::Abajo; //va a iniciar con goku mirando para abajo
	direccion = Direcciones::Ninguna;
	ancho = 25;
	alto = 39;
	indiceX = 0;
	indiceY = 0;
}
Jugador::~Jugador(){}
void Jugador::dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 1.5, alto * 1.5);
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionUsar, GraphicsUnit::Pixel);
	x += vx;
	y += vy;
} //Un bitmap es lo que va a capturar una imagen PNG
void Jugador::mover(BufferedGraphics^ buffer, Bitmap^ bmp){
	switch (direccion) {
	case Direcciones::Arriba: 
		indiceX = 2;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		vx = 0;
		vy = -10;
		ultimaTecla = Arriba;
		break;
	case Direcciones::Abajo:
		indiceX = 0;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		vx = 0;
		vy = 10;
		ultimaTecla = Abajo;
		break;
	case Direcciones::Izquierda:
		indiceX = 1;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		vx = -10;
		vy = 0;
		ultimaTecla = Izquierda;
		break;
	case Direcciones::Derecha:
		indiceX = 3;
		if (indiceY >= 0 && indiceY < 2)
			indiceY++;
		else
			indiceY = 0;
		vx = 10;
		vy = 0;
		ultimaTecla = Derecha;
		break;
	case Direcciones::Ninguna:
		vx = 0;
		vy = 0;
		switch (ultimaTecla) {
		case Direcciones::Abajo:
			indiceX = 0; indiceY = 0;
			break;
		case Direcciones::Derecha:
			indiceX = 3; indiceY = 0;
			break;
		case Direcciones::Arriba:
			indiceX = 2; indiceY = 0;
			break;
		case Direcciones::Izquierda:
			indiceX = 1; indiceY = 0;
			break;
		}
		break;
	}
	dibujar(buffer, bmp);
}