
#include "Neuron.h"

Neuron::Neuron(unsigned outputnumbers, unsigned myindex)
{
	for (unsigned c = 0; c < outputnumbers; c++)
	{
		outputweight.push_back(make_unique<Connection>());
		//std::cout << outputweight[c] << endl;
	}
	index = myindex;
}


void Neuron::feedforward(const vector<Neuron*> &prevLayer)
{
	double sum = 0;
	for (unsigned neuron = 0; neuron < prevLayer.size(); neuron++)
		sum += prevLayer[neuron]->get_output_val() * prevLayer[neuron]->outputweight[index]->weight;

	outputVal = tranfser_function(sum);
}

double Neuron::tranfser_function(double x)
{
	return tan(x);
}

double Neuron::transfer_function_derivative(double x)
{
	return 1 - (x * x);
}

