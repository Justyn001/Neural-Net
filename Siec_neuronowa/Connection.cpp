
#include <iostream>
#include <cstdlib>
#include "Connection.h"


Connection::Connection()
{
	weight = rand() / double(RAND_MAX);
	std::cout << "Wartosc drogi = " << weight << std::endl;
}
