#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>

using namespace std;

class Neuron
{
public:
	Neuron(unsigned numoutputs);
	~Neuron() {}
private:
	vector<double> outputweight;
};

#endif
