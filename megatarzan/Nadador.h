#pragma once
#include"Jugador.h"
class CNadador: public CJugador
{
public:
	CNadador(int x, int y);
	~CNadador();
	void mover(BufferedGraphics ^buffer, Bitmap ^bmp);
	void saltar();
	void disparar(CArregloBalas *oArregloBalas);
};

