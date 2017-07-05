#pragma once
#include "ArregloBalas.h"
using namespace System::Drawing;
enum dirs { none, up, down, left, right };
class CJugador
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int alto;
	int ancho;
	int indiceX;
	int indiceY;
	dirs ultima;
	int contador = 0;
public:
	dirs direccion;
	CJugador();
	CJugador(int x, int y);
	~CJugador();
	void dibujar(BufferedGraphics ^buffer, Bitmap ^bmp);
	virtual void mover(BufferedGraphics ^buffer, Bitmap ^bmp)abstract;
	virtual void saltar()abstract;
	virtual void disparar(CArregloBalas *oArregloBalas)abstract;
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	int getPies();
	int getDX();
	void setDY(int i);
	void setX(int i);
	void setY(int i);

};
