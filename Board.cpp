#include "Board.h"

Board::Board()
{
	reserve();
	initialise();
}
Board::~Board()
{

}

void Board::display()
{
	for (int y = 0; y < N; y++)
		std::cout << "  " << (y + 1) << " ";
	std::cout << "\n";

	std::cout << "  ________\n";
	// print each row
	for (int x = 0; x < N; x++)
	{
		std::cout << (x + 1);
		// print each position
		for (int y = 0; y < N; y++)
			std::cout << "| " << positions.at(x).at(y); // display symbol
		std::cout << "|\n"; // print new line
		std::cout << "  ________\n";
	}
}

bool Board::check(char symbol)
{

	int rowCount;

	// check if row is filled with same symbol 
	for (int x = 0; x < N; x++) // check each row
	{
		rowCount = 0;

		for (int y = 0; y < N; y++)
			if (positions.at(x).at(y) == symbol) // check each position
				rowCount++;

		// if row is filled with symbol then row count is 3
		if (rowCount == 3) 
			return true;
	}

	int columnCount;

	// check if column is filled with same symbol 
	for (int y = 0; y < N; y++)
	{
		columnCount = 0;

		for (std::vector<char> row : positions)
			if (row.at(y) == symbol)
				columnCount++;

		// if column is filled with symbol then column count is 3
		if (columnCount == 3) 
			return true;
	}

	// check top to down diagonal

	int diagonalCount = 0;

	for (int i = 0; i < N; i++)
		if (positions.at(i).at(i) == symbol)
			diagonalCount++;

	if (diagonalCount == 3)
		return true;

	// check down to top diagonal

	diagonalCount = 0;

	for (int x = 0; x < N; x++)
		if(positions.at(x).at(N-(x+1)) == symbol)
			diagonalCount++;

	if (diagonalCount == 3)
		return true;

	return false; 
	
}


