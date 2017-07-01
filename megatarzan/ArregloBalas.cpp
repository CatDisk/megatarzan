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
		if (arreglo[i]->getX() < 0 || arreglo[i]->getX() > 1583)
		{
			CBala **aux = new CBala *[cap - 1];
			int a = 0;
			for (int j = 0; j < cap - 1; j++)
			{
				aux[j] = arreglo[a];
				a++;
				if (j == i)
					a++;
			}
			delete[] arreglo;
			arreglo = aux;
			cap--;
		}
	}
}

