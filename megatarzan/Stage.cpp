#include "Stage.h"
#include <stdio.h>

CStage::CStage(int x, int y, int alto, int ancho, int dx)
{
	this->x = x;
	this->y = y;
	this->alto = alto;
	this->ancho = ancho;
	dxInicial = dx;
}

CStage::~CStage()
{
}
void CStage::dibujar(BufferedGraphics ^buffer, Bitmap ^bmp) {
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(0, 0, ancho, alto);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
}
void CStage::mover(BufferedGraphics ^buffer, Bitmap ^bmp, int pos, int nivel, int otherStageX) {

	if (pos == 600)
	{
			dx = dxInicial;
	}
	else if (pos == 800)
	{
			dx = -dxInicial;
	}
	else
		dx = 0;
	
	if (x <= -ancho * 2)
		x = otherStageX + (ancho * 2);
	if (x >= ancho * 2)
		x = otherStageX - (ancho * 2);

	if (nivel == 3)
		dx = dxInicial;

	x += dx;
	dibujar(buffer, bmp);
}
int CStage::getX() { return x; }
int CStage::getDX() { return dx; }
