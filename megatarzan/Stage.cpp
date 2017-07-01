#include "Stage.h"


CStage::CStage(int x, int y, int alto, int ancho, int dx)
{
	this->x = x;
	this->y = y;
	this->alto = alto;
	this->ancho = ancho;
	this->dxInicial = dx;
}

CStage::~CStage()
{
}
void CStage::dibujar(BufferedGraphics ^buffer, Bitmap ^bmp) {
	System::Drawing::Rectangle porcion = System::Drawing::Rectangle(0, 0, ancho, alto);
	System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho * 2, alto * 2);
	buffer->Graphics->DrawImage(bmp, aumento, porcion, System::Drawing::GraphicsUnit::Pixel);
}
void CStage::mover(BufferedGraphics ^buffer, Bitmap ^bmp, int pos, int dxJugador, int otherStageX) {

	if (dxJugador > 0)
		x -= 1;
	if (dxJugador < 0)
		x += 1;

	if (pos == 70)
	{
		if (dx != dxInicial)
			dx = dxInicial;
	}
	else
		dx = 0;
	if (pos == 800)
	{
		if (dx != -dxInicial)
			dx = -dxInicial;
	}
	else
		dx = 0;
	if (x <= -ancho * 2)
		x = otherStageX + (ancho * 2);
	if (x >= ancho * 2)
		x = otherStageX - (ancho * 2);
	x += dx;
	dibujar(buffer, bmp);
}
int CStage::getX() { return x; }
int CStage::getDX() { return dx; }
