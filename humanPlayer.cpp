#include <iostream>

#include "humanPlayer.h"


int humanPlayer::makeMove()
{
	system("pause");
	//system("cls");

	int move;
	std::cout << "Please make your move: ";
	std::cin >> move;


	if (move > 0 && move <= 7)
		return move;

	std::cout << "\nYour move is invalid, select a number between 1 and 7: ";
	system("pause");


	makeMove();
}


humanPlayer::humanPlayer()
{
	std::cout << "Please enter your Name: ";
	std::cin >> this->name;
	this->isHuman = true;
}

