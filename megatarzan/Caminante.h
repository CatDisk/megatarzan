#pragma once
#include "Jugador.h"
class CCaminante:public CJugador
{
private:
	bool piso = false;
	int nivelpiso;
public:
	CCaminante(int x, int y, int nivelpiso);
	~CCaminante();
	void mover(BufferedGraphics ^ buffer, Bitmap ^ bmp);
	void saltar();
	void disparar(CArregloBalas *oArregloBalas);
	bool getPiso();
	void setPiso(bool b);
};

