#include "Bala.h"
CBala::CBala(int x, int y, int dir, tag personaje)
{
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->personaje = personaje;
}
CBala::~CBala()
{
}
void CBala::mover(BufferedGraphics ^buffer, Bitmap ^bmp) {
	if (personaje == enemigo)
	{
		dx = 15 * dir;
		if (dx < 0)
			indiceY = 0;
		else
			indiceY = 1;
		if (indiceX > 2)
			indiceX = 0;
		else
			indiceX++;
	}
	else if (personaje == jugador)
	{
		dx = 25 * dir;
		indiceX = 0;
		indiceY = 2;
	}
	
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(ancho*indiceX, alto*indiceY, ancho, alto);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
	x += dx;
}
int CBala::getX() { return x; }
void CBala::setX(int a) { x = a; }
tag CBala::getTag() { return personaje; }