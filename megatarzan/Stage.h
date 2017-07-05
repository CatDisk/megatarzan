#pragma once
using namespace System::Drawing;
class CStage
{
private:
	int x;
	int y;
	int alto;
	int ancho;
	int dx = 0;
	int dxInicial;
public:
	CStage(int x, int y, int alto, int ancho, int dx);
	~CStage();
	void dibujar(BufferedGraphics ^buffer, Bitmap ^bmp);
	void mover(BufferedGraphics ^buffer, Bitmap ^bmp, int pos, int nivel, int otherStageX);
	int getX();
	int getDX();
};

