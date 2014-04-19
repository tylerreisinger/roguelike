#include <iostream>

#include "RoguelikeGame.h"

#include "Framework/LruCache.h"

int main(int argc, char** argv)
{
	RoguelikeGame game;
	rf::LruCache<std::string, int> cache(50);

	try
	{
		game.run();
	}
	catch(std::exception& ex)
	{
		std::cerr << "[FATAL] " << ex.what() << std::endl;
	}

	return 0;
}
