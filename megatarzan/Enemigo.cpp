#include "Enemigo.h"
CEnemigo::CEnemigo(int x, int y)
{
	this->x = x;
	this->y = y;
	yStart = y;
}


CEnemigo::~CEnemigo()
{
}
void CEnemigo::idleIZQ() // animacion de espera
{
	indiceY = 0;
	if (i == 1)
	{
		if (indiceX > 2)
			indiceX = 0;
		else
			indiceX++;
		i = 0;
	}
	else
		i++;
}
void CEnemigo::saltarIZQ() // animacion de salto + cambio en dx y dy
{
	indiceY = 2;
	if (indiceX > 2)
	{
		if (y == yStart)
		{
			dy = -20;
			dx = -10;
			y--;
		}
		else if (y > yStart)
		{
			y = yStart;
			contador++;
			indiceX = 0;
		}
	}
	else
		indiceX++;
}
void CEnemigo::ataqueIZQ(CArregloBalas *oArreglo) // animacion de ataque y creacion de un nuevo objeto CBala (en el penultimo fame para que aparezca en el ultimo frame)
{
	indiceY = 4;
	if (i == 1)
	{
		if (indiceX < 4)
			indiceX++;
		else
		{
			contador++;
		}
		i = 0;
		if (indiceX == 3)
			oArreglo->agregarElemento(x, y + 100, -1);
	}
	else
		i++;
}
void CEnemigo::idleDER() {
	indiceY = 1;
	if (i == 1)
	{
		if (indiceX > 2)
			indiceX = 0;
		else
			indiceX++;
		i = 0;
	}
	else
		i++;
}
void CEnemigo::saltarDER() {
	indiceY = 3;
	if (indiceX > 2)
	{
		if (y == yStart)
		{
			dy = -20;
			dx = 10;
			y--;
		}
		else if (y > yStart)
		{
			y = yStart;
			contador = 0;
			indiceX = 0;
		}
	}
	else
		indiceX++;
}
void CEnemigo::ataqueDER(CArregloBalas *oArreglo) {
	indiceY = 5;
	if (i == 1)
	{
		if (indiceX < 4)
			indiceX++;
		else
		{
			contador++;
		}
		i = 0;
		if (indiceX == 3)
			oArreglo->agregarElemento(x + ancho * 2, y + 100, 1);
	}
	else
		i++;
}

void CEnemigo::mover(BufferedGraphics ^buffer, Bitmap ^bmp, CArregloBalas *oArreglo, CStage *oPlataforma)
{
	if (contador < 20) // el contador va de 0 a 80 y determina cuanto tiempo tarda que estado
	{
		if (contador == 19)
			indiceX = 0;
		idleDER();
		contador++;
	}
	else if (contador == 20)
	{
		ataqueDER(oArreglo);
	}
	else if (contador < 40)
	{
		if (contador == 21 || contador == 39)
			indiceX = 0;
		idleDER();
		contador++;
	}
	else if (contador == 40) // el tiempo de salto es determinado por el tiempo que le toma regresar a yStart (el contador para por ese tiempo)
	{
		saltarIZQ();
	}
	else if (contador < 60)
	{
		if (contador == 41 || contador == 59)
			indiceX = 0;
		idleIZQ();
		contador++;
	}
	else if (contador == 60)
	{
		ataqueIZQ(oArreglo);
	}
	else if (contador < 80)
	{
		if (contador == 61 || contador == 79)
			indiceX = 0;
		idleIZQ();
		contador++;
	}
	else if (contador == 80)
	{
		saltarDER();
	}

	if (y >= yStart)
	{
		dx = 0;
		dy = 0;
		y = yStart;
	}
	else
		dy += 2;
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(ancho*indiceX, alto*indiceY, ancho, alto);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
	x += dx + oPlataforma->getDX();
	y += dy;
}
int CEnemigo::getCont() { return contador; }