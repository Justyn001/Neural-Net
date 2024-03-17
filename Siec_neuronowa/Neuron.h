#ifndef Neuron_H
#define Neuron_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <cmath>
#include "Connection.h"

using namespace std;

class Connection;

class Neuron
{
public:
	Neuron(unsigned numoutputs, unsigned myindex);
	~Neuron() {}
	void set_output_val(double x) { outputVal = x; }
	double get_output_val() { return outputVal; }
	void feedforward(const vector<Neuron*> &prevLayer);
	double tranfser_function(double x);
	double transfer_function_derivative(double x);
private:
	vector<unique_ptr<Connection>> outputweight;
	double outputVal;
	unsigned index;
};

#endif
