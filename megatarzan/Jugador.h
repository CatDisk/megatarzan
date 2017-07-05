#pragma once
#include "ArregloBalas.h"
using namespace System::Drawing;
enum dirs { none, up, down, left, right };
class CJugador
{
private:
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
	bool piso = false;
public:
	dirs direccion;
	CJugador(int x, int y);
	~CJugador();
	void dibujar(BufferedGraphics ^buffer, Bitmap ^bmp);
	void mover(BufferedGraphics ^buffer, Bitmap ^bmp);
	void saltar();
	void disparar(CArregloBalas *oArregloBalas);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	int getPies();
	bool getPiso();
	int getDX();
	void setDY(int i);
	void setX(int i);
	void setY(int i);
	void setPiso(bool b);

};
