#include "cell.h"
cell::cell(cellState s)
{
	state = s;
}

bool cell::checkWin(){
	for (int i = 0; i < 4; i++) {
		int win = 1;
		win += this->checkNeighbour(i);
		win += checkNeighbour(i+4);
		if (win >= 4)
			return true;
	}
	return false;
}

int cell::checkNeighbour(int d)
{
	if (neighbours[d] != nullptr)
		if (this->state == neighbours.at(d)->state)
			return 1 + neighbours[d]->checkNeighbour(d);
	return 0;
}