#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

static const int N = 3;
typedef std::vector<std::vector<char>> _2DVectorOfChars;

class Board
{
public:
	Board();
	~Board();
	void display();
	inline char getPosition(int x, int y);
	inline void addSymbol(int x, int y, char symbol);
	bool check(char symbol);

private:
	inline void reserve();
	inline void initialise();
	_2DVectorOfChars positions;

};

// reserve N size for 2D board
inline void Board::reserve() 
{
	// reserve N size for each row
	for_each(positions.begin(), positions.end(), [=](std::vector<char> row) {row.reserve(N); });
	// reserve N size for number of columns
	positions.reserve(N);
}

inline void Board::initialise()
{
	// create an empty board
	for (int i = 0; i < N; i++) // for each row
		positions.push_back({' ', ' ', ' '}); // add a row of empty spaces


}

inline char Board::getPosition(int x, int y)
{
	return positions.at(x).at(y);
}

inline void Board::addSymbol(int x, int y, char symbol)
{
	positions.at(x).at(y) = symbol;
}

