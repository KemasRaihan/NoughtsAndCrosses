#pragma once
#include <Windows.h>

#include "Player.h"
#include "Board.h"
class Game
{
public:
	Game();
	~Game();
	void play();
	inline void result(bool win, int player);

private:
	Player** players;
	Board* board;
};

inline void Game::result(bool win, int player)
{
	if (win)
		std::cout << "\nPlayer " << (((player + 1) % 2) + 1) << " has won!\n";
	else
		std::cout << "\nIt's a draw!\n";
}

