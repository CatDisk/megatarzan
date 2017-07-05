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
		break;
	case dirs::right:
		indiceY = 0;
		if (piso) // solamente si esta sobre el piso camina
		{
			if (indiceX > 0 && indiceX < 10) // loop para caminar
				indiceX++;
			else
				indiceX = 1;
			if (x >= 800) // limite de la pantalla
			{
				dx = 0;
				x = 800;
			}
			else
			{
				dx = 10; // velociadad del jugador
			}
		}
		ultima = right;
		break;
	case dirs::left:
		indiceY = 1;
		if (piso) // solamente si esta sobre el piso camina
		{
			if (indiceX > 0 && indiceX < 10)
				indiceX++;
			else
				indiceX = 1;
			if (x <= 600)
			{
				dx = 0;
				x = 600;
			}
			else
			{
				dx = -10;
			}
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
			if (x == 600)
				x++;
			indiceX = 0;
			indiceY = 1;
			break;
		case right:
			if (x == 800)
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

	if (piso) // variable que cancela la velocidad en y
	{
		dy = 0;
		y = 472;
	}
	else
		dy += 4; // 'gravedad'

	if (dy < 0) // animacion de salto para arriba
	{
		if (direccion == right || dx > 0)
		{
			indiceY = 2;
		}
		if (direccion == left || dx < 0)
		{
			indiceY = 3;
		}

		if (indiceX < 5)
			indiceX++;
	}
	if (dy >= 0 && !piso) // sprite de caida
	{
		if (ultima == right)
		{
			indiceY = 2;
		}
		if (ultima == left)
		{
			indiceY = 3;
		}
		indiceX = 5;
	}
	dibujar(buffer, bmp);
	if (y >= 472)
	{
		piso = true;
	}
	if (contador > 0) // controla el spam de balas :v
		contador--;
}
void CJugador::saltar() // funcion separada para que no interfiera con el movimiento en X
{
	if (piso)
	{
		piso = false;
		dy = -40;
		indiceX = 0;
	}
}
void CJugador::disparar(CArregloBalas *oArregloBalas) {
	int dir;
	if (contador == 0) // controla el spam de balas :v
	{
		if (ultima == right) // direccion de las balas
			dir = 1;
		else
			dir = -1;
		oArregloBalas->agregarElemento(x, y, dir, jugador);
		contador = 5;
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