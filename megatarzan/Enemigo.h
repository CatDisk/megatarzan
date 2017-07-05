#pragma once
#include "ArregloBalas.h"
#include "Stage.h"
using namespace System::Drawing;
using namespace std;
class CEnemigo
{
protected:
	int i = 0;
	int contador = 0;
	int dx = 0;
	int dy = 0;
	int ancho = 83;
	int alto = 88;
	int indiceX = 0;
	int indiceY = 0;
	int yStart;
public:
	int x;
	int y;
	CEnemigo(int x, int y);
	~CEnemigo();
	virtual void mover(BufferedGraphics ^buffer, Bitmap ^bmp, CArregloBalas *oArreglo, CStage *oPlataforma)abstract;
};

