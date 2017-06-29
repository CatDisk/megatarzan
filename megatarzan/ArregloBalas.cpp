#include "ArregloBalas.h"

CArregloBalas::CArregloBalas()
{
	arreglo = nullptr;
	cap = 0;
}


CArregloBalas::~CArregloBalas()
{
}

void CArregloBalas::agregarElemento(int x, int y, int dir) {
	CBala **aux = new CBala *[cap + 1];
	for (int i = 0; i < cap; i++)
	{
		aux[i] = arreglo[i];
	}
	aux[cap] = new CBala(x, y, dir);
	delete[] arreglo;
	arreglo = aux;
	cap++;
}
void CArregloBalas::moverBalas(BufferedGraphics ^buffer, Bitmap ^bmp) {
	for (int i = 0; i < cap; i++)
	{
		arreglo[i]->mover(buffer, bmp);
	}
}
void CArregloBalas::eleminiarElemento() {
	for (int i = 0; i < cap; i++)
	{
		if (arreglo[i]->getX() < 10 || arreglo[i]->getX() > 400)
		{
			arreglo[i]->setX(100);
		}
	}
}

