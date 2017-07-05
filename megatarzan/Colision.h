#pragma once
#include "Jugador.h"
#include "Caminante.h"
#include "Nadador.h"
#include "Stage.h"
class CColision
{
private:
	int coordX[8] = { 0, 287, 384, 606, 770, 1053, 1186, 2000 };
	int coordY[7] = { 180, 213, 165, 194, 165, 194, 101 };
public:
	CColision();
	~CColision();
	//void getColision(CJugador *nJugador, CStage *nPlataforma);
};

