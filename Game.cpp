#include "Game.h"
Game::Game() : board(new Board())
{
	players = new Player * [2]; // create memory array of pointers to player objects
	players[0] = new Player('O'); // create player 1
	players[1] = new Player('X'); // create player 2
	play();
}
Game::~Game()
{
	// free memory of first player object
	delete players[0];

	// free memory of second player object
	delete players[1];

	// free memory of players array
	delete[] players;

	// free memory of board object
	delete board;
}

void Game::play()
{
	std::cout << "=================\n";
	std::cout << "NOUGHTS & CROSSES\n";
	std::cout << "=================\n";
	
	int n = 0;
	int numberOfTurns = 0;
	char symbol;
	bool playerHasWon = false;

	char posX, posY;
	int x, y;

	board->display();

	do {

		std::cout << "\nPlayer " << (n+1) << " turn\n";

		// allow user to x and y value for position
		std::cout << "\nEnter a position (x, y): ";

		std::cin >> posX >> posY; 

		// cast char to int
		x = (int)(posX - '0');
		y = (int)(posY - '0');

		// get player symbol
		symbol = players[n]->getSymbol();

		// choose valid position and check if the position is empty
		if ((x > 0 && x <= 3) && (y > 0 && y <= 3) && (board->getPosition(y - 1, x - 1) == ' '))
		{
			board->addSymbol(y - 1, x - 1, symbol); // let player add a symbol to board

			// check if the player has won
			playerHasWon = board->check(symbol);

			board->display();

			// update number of turns
			numberOfTurns++;

			// rotate player
			n = numberOfTurns % 2; 
		}
		else
		{
			std::cout << "\nInvalid position...\n\n";
			Sleep(500);
		}

	} while ((numberOfTurns < 9) && !playerHasWon); // keep playing until board is filled or if a player has won

	// print results
	result(playerHasWon, n);
}

