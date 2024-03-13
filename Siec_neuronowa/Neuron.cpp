
#include "Neuron.h"

Neuron::Neuron(unsigned outputnumbers)
{
	for (unsigned c = 0; c < outputnumbers; c++)
	{
		cout << "waga drogi nr: " << c << " to ";
		outputweight.push_back(rand() / double(RAND_MAX));
		std::cout << outputweight[c] << endl;
	}
}

