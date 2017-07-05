#pragma once
#include "Bala.h"
#include <vector>
using namespace std;

using namespace System::Drawing;

class CArregloBalas
{
private:
	vector<CBala> vectorBalas;
public:
	CArregloBalas();
	~CArregloBalas();
	void agregarElemento(int x, int y, int dir, tag personaje);
	void moverBalas(BufferedGraphics ^buffer, Bitmap ^bmp);
};

