#pragma once
using namespace System::Drawing;
enum tag {jugador, enemigo};
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
	tag personaje; // determina quien disparo la bala (enemigo o jugador) para visualizar los sprites indicados y ver colisiones
public:
	CBala(int x, int y, int dir, tag personaje);
	~CBala();
	void mover(BufferedGraphics ^buffer, Bitmap ^bmp);
	int getX();
	void setX(int a);
	tag getTag();
};

