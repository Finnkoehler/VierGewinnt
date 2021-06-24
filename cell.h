#pragma once
#include <array>
#include "utils.h"
class cell
{
public:
	std::array <cell*, 8> neighbours{ nullptr };
	cellState state;
	cell() {};
	cell(cellState s);
	bool checkWin();
	int checkNeighbour(int d);
};

