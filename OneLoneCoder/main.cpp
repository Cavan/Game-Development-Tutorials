

#include <iostream>
#include "GameOfLife.h"
#include "FormulaOLC.h"

using namespace std;


int main(void)
{
	int choice = 0;

	// Seed random number generator
	srand(clock());

	//Get user's choice
	cout << "Please enter your choice" << endl;
	cout << "1. Game of Life" << endl;
	cout << "2. Retro Racer" << endl;

	cout << "---> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		// Create game object
		GameOfLIfe game;
		game.ConstructConsole(320, 200, 4, 4);
		game.Start();
		break;
	}
	case 2:
	{
		// Use olcConsoleGameEngine derived app
		FormulaOLC game;
		game.ConstructConsole(160, 100, 8, 8);
		game.Start();

		break;

	}
	default:
		break;
	}

	return 0;
}