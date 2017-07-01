#pragma once
#include "Bala.h"

using namespace System::Drawing;

class CArregloBalas
{
private:
	CBala **arreglo;
	int cap;
public:
	CArregloBalas();
	~CArregloBalas();
	void agregarElemento(int x, int y, int dir);
	void moverBalas(BufferedGraphics ^buffer, Bitmap ^bmp);
};

