#pragma once
using namespace System::Drawing;
class CBala
{
private:
	int x;
	int y;
	int ancho = 24;
	int alto = 28;
	int dx = 15;
	int indiceX = 0;
	int indiceY;
public:
	CBala(int x, int y, int dir);
	~CBala();
	void mover(BufferedGraphics ^buffer, Bitmap ^bmp);
	int getX();
	void setX(int a);
};

