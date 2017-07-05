#include "Jugador.h"
CJugador::CJugador(){}
CJugador::CJugador(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 10;
	ancho = 44;
	alto = 53;
	indiceX = 0;
	indiceY = 0;
}
CJugador::~CJugador() {}
void	CJugador::dibujar(BufferedGraphics ^buffer, Bitmap ^bmp) {
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(ancho*indiceX, alto*indiceY, ancho, alto);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
	x = dx + x;
	y = dy + y;
}


int CJugador::getX() { return x; }
int CJugador::getY() { return y; }
int CJugador::getAncho() { return ancho; }
int CJugador::getAlto() { return alto; }
int CJugador::getPies() { return y + (alto * 2); }
int CJugador::getDX() { return dx; }
void CJugador::setDY(int i) { dy = i; }
void CJugador::setX(int i) { x = i; }
void CJugador::setY(int i) { y = i; }