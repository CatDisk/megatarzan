#include "Colision.h"



CColision::CColision()
{
}


CColision::~CColision()
{
}

/*void CColision::getColision(CJugador *nJugador, CStage *nPlataforma)
{
	for (int i = 0; i < 7; i++)
	{
		if (!nJugador->getPiso())
		{
			if (nJugador->getX() < coordX[i + 1] * 2 && nJugador->getX() + 2 * nJugador->getAncho() > coordX[i])
			{
				if (nJugador->getPies() > coordY[i] * 2)
				{
					nJugador->setPiso(true);
					nJugador->setY(coordY[i] * 2 - nJugador->getAlto() * 2);
				}
				else
					nJugador->setPiso(false);
			}
		}
	}
}*/