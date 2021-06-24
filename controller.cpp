#include "controller.h"
#include "computerPlayer.h"
#include "humanPlayer.h"

#include <iostream>

controller::controller() {
	int temp;
	std::cout << "Um gegen einen weiteren Spieler zu spielen gebe 1 ein. Um gegen einen Computer zu spielen geben 2 ein.." << std::endl;
	std::cin >> temp;
	p[0] = new humanPlayer();
	if (temp == 1)
		p[1] = new humanPlayer();
	else if (temp == 2)
		p[1] = new computerPlayer();
	f = field();
	r = renderer(&f);
	startGame();
}

void controller::startGame() {
	bool isWin = false;
	int freeCells = f.getCellCount();
	int nextPlayer = 0;
	cell* c;

	while (!isWin && freeCells > 0)
	{

		bool wrongMove = false;
		system("pause");
		//system("cls");

		do {
			if (!wrongMove) {
				if (p[nextPlayer % 2]->getIsHuman()) {
					std::cout << "";
				}
			}

			r.renderField();
			c = f.getEntry(p[nextPlayer % 2]->makeMove());

			wrongMove = true;
		} while (c == nullptr);

		f.makeEntry(c, nextPlayer);

		if (checkWin(c)) {
			isWin = true;
		}
		else {
			freeCells--;
			nextPlayer++;
		}
	}
}

bool controller::checkWin(cell* c)
{
	return c->checkWin();
}

