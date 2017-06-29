#include "Jugador.h"

CJugador::CJugador(int x, int y)
{
	this->x = x;
	this->y = y;
	dx = 0;
	dy = 10;
	direccion = dirs::none;
	ultima = dirs::right;
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
void	CJugador::mover(BufferedGraphics ^buffer, Bitmap ^bmp) {
	switch (direccion)
	{
	case dirs::down:
		break;
	case dirs::up:
		if (piso)
		{
			piso = false;
			dy = -40;
			ultima = up;
		}
		break;
	case dirs::right:
		indiceY = 0;
		if (indiceX > 0 && indiceX < 10)
			indiceX++;
		else
			indiceX = 1;
		if (x >= 620)
		{
			dx = 0;
			x = 620;
		}
		else
		{
			dx = 10;
		}
		ultima = right;
		break;
	case dirs::left:
		indiceY = 1;
		if (indiceX > 0 && indiceX < 10)
			indiceX++;
		else
			indiceX = 1;
		if (x <= 70)
		{
			dx = 0;
			x = 70;
		}
		else
		{
			dx = -10;
		}
		ultima = left;
		break;
	case dirs::none:
		dx = 0;
		switch (ultima)
		{
		case down:
			break;
		case left:
			if (x == 70)
				x++;
			indiceX = 0;
			indiceY = 1;
			break;
		case right:
			if (x == 620)
				x--;
			indiceX = 0;
			indiceY = 0;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

	if (piso)
	{
		dy = 0;
		y = 472;
	}
	else
		dy += 4;
	dibujar(buffer, bmp);
	if (y >= 472)
	{
		piso = true;
	}
}
int CJugador::getX() { return x; }
int CJugador::getY() { return y; }
int CJugador::getAncho() { return ancho; }
int CJugador::getAlto() { return alto; }
int CJugador::getPies() { return y + (alto * 2); }
bool CJugador::getPiso() { return piso; }
int CJugador::getDX() { return dx; }
void CJugador::setDY(int i) { dy = i; }
void CJugador::setX(int i) { x = i; }
void CJugador::setY(int i) { y = i; }
void CJugador::setPiso(bool b) { piso = b; }