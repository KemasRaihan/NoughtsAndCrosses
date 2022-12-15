#pragma once
class Player
{
public:
	Player(char symbol);
	~Player();
	inline char getSymbol();

private:
	char symbol;
};


inline char Player::getSymbol()
{
	return symbol;
}

