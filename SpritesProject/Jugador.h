#pragma once
using namespace System::Drawing;
enum Direcciones{Ninguna, Abajo, Arriba, Izquierda, Derecha};

ref class Jugador
{
private:
	int x, y, vx, vy, ancho, alto;
	int indiceX, indiceY;
	Direcciones ultimaTecla;
public:
	Jugador();
	Jugador(int x, int y);
	Direcciones direccion;
	~Jugador();
	void dibujar(BufferedGraphics^buffer, Bitmap^bmp); //Un bitmap es lo que va a capturar una imagen PNG
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp);
};