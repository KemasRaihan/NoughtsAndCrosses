#include <iostream>
#include "Game.h"

int main()
{
#ifdef _DEBUG
	//  _CrtSetBreakAlloc(87);
	_onexit(_CrtDumpMemoryLeaks);
#endif

	Game game = Game();

	return 0;
}