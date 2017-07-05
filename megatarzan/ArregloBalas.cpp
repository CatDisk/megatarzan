#include "ArregloBalas.h"

CArregloBalas::CArregloBalas()
{
}


CArregloBalas::~CArregloBalas()
{
}

void CArregloBalas::agregarElemento(int x, int y, int dir, tag personaje) {
	vectorBalas.push_back(CBala(x, y, dir, personaje));
}

void CArregloBalas::moverBalas(BufferedGraphics ^buffer, Bitmap ^bmp) {
	for (unsigned int i = 0; i < vectorBalas.size(); i++)
	{
		vectorBalas[i].mover(buffer, bmp);
		if (vectorBalas[i].getX() < 0 || vectorBalas[i].getX() > 1583) // verifica colisiones con los limites de la pantalla
		{
			vectorBalas.erase(vectorBalas.cbegin() + i);
		}
	}
}

